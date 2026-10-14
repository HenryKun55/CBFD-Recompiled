/* PS Vita: checks GitHub for a newer release of the port, downloads it and hands over
 * to updater.bin (vita/updater) to install it.
 *
 * Runs on its own thread, so the boot screen (vita_bootui.c) keeps drawing. The release
 * is read from the GitHub API over HTTPS (certificates checked against app0:cacert.pem),
 * and the download is checked against the size and SHA-256 GitHub publishes for it.
 * Every failure keeps an English sentence and the technical detail (curl or Sce error
 * code, HTTP status), also written to ux0:data/conker/update/update.log.
 *
 * Ported from the author's OpenMoHAA Vita port (code/sys/vita_update.c there),
 * relicensed by its author under this repository's MIT license. */
#if defined(__vita__)
#include "vita_update.h"

#include <psp2/appmgr.h>
#include <psp2/io/devctl.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>
#include <psp2/net/net.h>
#include <psp2/net/netctl.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/sysmodule.h>

#include <curl/curl.h>
#include <openssl/sha.h>

#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef CONKER_PORT_VERSION
#    define CONKER_PORT_VERSION "0.0.0"
#endif
#ifndef CONKER_UPDATE_REPO
#    define CONKER_UPDATE_REPO "HenryKun55/conker-vita"
#endif
#define VITA_PORT_VERSION CONKER_PORT_VERSION

#define VPK_ASSET     "conker.vpk" /* the release asset (vita/RELEASE.md) */
#define DATA_DIR      "ux0:data/conker"
#define UPDATE_DIR    DATA_DIR "/update"
#define VPK_PATH      UPDATE_DIR "/" VPK_ASSET
#define PLAN_FILE     UPDATE_DIR "/plan.txt"
#define RESULT_FILE   UPDATE_DIR "/result.txt"
#define LOG_FILE      UPDATE_DIR "/update.log"
#define CA_FILE       "app0:cacert.pem"
#define USER_AGENT    "Conker-Vita/" VITA_PORT_VERSION
#define NET_POOL_SIZE (1024 * 1024)

typedef struct {
    char      name[64];
    char      url[512];
    char      sha256[65]; // "" when GitHub gave no digest
    long long size;
} asset_t;

static struct {
    volatile vitaUpdateState_t state;
    volatile int               cancel;
    volatile long long         done, total;

    char releaseUrl[256];
    char newVersion[32];
    char error[256];
    char detail[256];

    asset_t vpk;

    pthread_t thread;
    int       threadStarted;
} g_vu;

// ---------- log and errors ----------

static void VU_Log(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
static void VU_Log(const char *fmt, ...)
{
    char      line[600];
    va_list   ap;
    FILE     *f;
    time_t    now = time(NULL);
    struct tm tmv;

    va_start(ap, fmt);
    vsnprintf(line, sizeof(line), fmt, ap);
    va_end(ap);
    sceIoMkdir(UPDATE_DIR, 0777);
    f = fopen(LOG_FILE, "a");
    if (f) {
        localtime_r(&now, &tmv);
        fprintf(f, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n", tmv.tm_year + 1900, tmv.tm_mon + 1, tmv.tm_mday,
                tmv.tm_hour, tmv.tm_min, tmv.tm_sec, line);
        fclose(f);
    }
}

// 'error' is the sentence shown, 'detail' the technical part under it.
static void VU_Fail(const char *error, const char *fmt, ...) __attribute__((format(printf, 2, 3)));
static void VU_Fail(const char *error, const char *fmt, ...)
{
    va_list ap;

    snprintf(g_vu.error, sizeof(g_vu.error), "%s", error);
    va_start(ap, fmt);
    vsnprintf(g_vu.detail, sizeof(g_vu.detail), fmt, ap);
    va_end(ap);
    VU_Log("ERROR: %s (%s)", g_vu.error, g_vu.detail);
    g_vu.state = VU_ERROR;
}

// ---------- network ----------

static void *s_netPool;

static int VU_NetUp(void)
{
    SceNetInitParam param;
    int             res, state = 0;

    res = sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
    if (res < 0 && res != (int)0x80800002 /* already loaded */) {
        VU_Fail("The Vita's network could not start.", "sceSysmoduleLoadModule(NET) = 0x%08X", (unsigned)res);
        return 0;
    }
    if (!s_netPool) {
        s_netPool = malloc(NET_POOL_SIZE);
        if (!s_netPool) {
            VU_Fail("Out of memory.", "network pool (%d KB)", NET_POOL_SIZE / 1024);
            return 0;
        }
        param.memory = s_netPool;
        param.size   = NET_POOL_SIZE;
        param.flags  = 0;
        res          = sceNetInit(&param);
        if (res < 0 && res != (int)0x80410110 /* already initialised */) {
            free(s_netPool);
            s_netPool = NULL;
            VU_Fail("The Vita's network could not start.", "sceNetInit = 0x%08X", (unsigned)res);
            return 0;
        }
    }
    res = sceNetCtlInit();
    if (res < 0 && res != (int)0x80412102 /* already initialised */) {
        VU_Fail("The Vita's network could not start.", "sceNetCtlInit = 0x%08X", (unsigned)res);
        return 0;
    }
    res = sceNetCtlInetGetState(&state);
    if (res < 0) {
        VU_Fail("The Vita's network could not start.", "sceNetCtlInetGetState = 0x%08X", (unsigned)res);
        return 0;
    }
    if (state != SCE_NETCTL_STATE_CONNECTED) {
        VU_Fail("The Vita is not connected to Wi-Fi.", "network state %d", state);
        return 0;
    }
    return 1;
}

// A curl failure, told as precisely as curl knows it.
static void VU_CurlFail(CURLcode code, const char *what, const char *errbuf)
{
    const char *error;

    switch (code) {
    case CURLE_COULDNT_RESOLVE_HOST:
        error = "Could not find GitHub: check that the Wi-Fi has internet access.";
        break;
    case CURLE_COULDNT_CONNECT:
        error = "Could not connect to GitHub.";
        break;
    case CURLE_OPERATION_TIMEDOUT:
        error = "GitHub did not answer in time. Try again.";
        break;
    case CURLE_PEER_FAILED_VERIFICATION:
        // an out-of-date clock makes every certificate look expired or not valid yet
        if (strstr(errbuf, "expired") || strstr(errbuf, "not yet valid")) {
            error = "The secure connection was refused. Check that the Vita's date and time are right.";
        } else {
            error = "GitHub's certificate could not be verified.";
        }
        break;
    case CURLE_SSL_CACERT_BADFILE:
    case CURLE_SSL_CERTPROBLEM:
        error = "The game's certificate list (cacert.pem) is missing or damaged: reinstall the .vpk.";
        break;
    case CURLE_SSL_CONNECT_ERROR:
        error = "The secure connection to GitHub failed.";
        break;
    case CURLE_PARTIAL_FILE:
    case CURLE_RECV_ERROR:
    case CURLE_GOT_NOTHING:
        error = "The download was cut off. Try again.";
        break;
    case CURLE_WRITE_ERROR:
        error = "Could not write the download to the memory card.";
        break;
    case CURLE_ABORTED_BY_CALLBACK:
        error = "Download cancelled.";
        break;
    case CURLE_OUT_OF_MEMORY:
        error = "Out of memory.";
        break;
    default:
        error = "The connection to GitHub failed.";
        break;
    }
    VU_Fail(error, "%s: curl %d, %s", what, (int)code, errbuf[0] ? errbuf : curl_easy_strerror(code));
}

typedef struct {
    char  *data;
    size_t len, cap;
} buffer_t;

static size_t VU_ToBuffer(void *ptr, size_t size, size_t n, void *user)
{
    buffer_t *b   = (buffer_t *)user;
    size_t    add = size * n;

    if (b->len + add + 1 > b->cap) {
        size_t cap  = (b->len + add + 1) * 2;
        char  *data = realloc(b->data, cap);
        if (!data) {
            return 0;
        }
        b->data = data;
        b->cap  = cap;
    }
    memcpy(b->data + b->len, ptr, add);
    b->len += add;
    b->data[b->len] = 0;
    return add;
}

typedef struct {
    long remaining; // X-RateLimit-Remaining, -1 when absent
    long reset;     // X-RateLimit-Reset (Unix time)
} rateLimit_t;

static size_t VU_Header(char *line, size_t size, size_t n, void *user)
{
    rateLimit_t *rl = (rateLimit_t *)user;

    if (!strncasecmp(line, "x-ratelimit-remaining:", 22)) {
        rl->remaining = strtol(line + 22, NULL, 10);
    } else if (!strncasecmp(line, "x-ratelimit-reset:", 18)) {
        rl->reset = strtol(line + 18, NULL, 10);
    }
    return size * n;
}

static CURL *VU_Curl(char *errbuf)
{
    CURL *c = curl_easy_init();

    if (!c) {
        return NULL;
    }
    errbuf[0] = 0;
    curl_easy_setopt(c, CURLOPT_ERRORBUFFER, errbuf);
    curl_easy_setopt(c, CURLOPT_USERAGENT, USER_AGENT);
    curl_easy_setopt(c, CURLOPT_CAINFO, CA_FILE);
    curl_easy_setopt(c, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(c, CURLOPT_SSL_VERIFYHOST, 2L);
    curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(c, CURLOPT_CONNECTTIMEOUT, 15L);
    // a stalled download (under 1 KB/s for 30 s) is dropped
    curl_easy_setopt(c, CURLOPT_LOW_SPEED_LIMIT, 1024L);
    curl_easy_setopt(c, CURLOPT_LOW_SPEED_TIME, 30L);
    curl_easy_setopt(c, CURLOPT_NOSIGNAL, 1L);
    return c;
}

// ---------- the release (GitHub API JSON) ----------

// Skips a JSON string starting at the opening quote; returns the char after it.
static const char *J_SkipString(const char *p)
{
    for (p++; *p && *p != '"'; p++) {
        if (*p == '\\' && p[1]) {
            p++;
        }
    }
    return *p ? p + 1 : p;
}

// End of the object or array starting at p ('{' or '['): the char after its closing one.
static const char *J_SkipBlock(const char *p)
{
    int depth = 0;

    while (*p) {
        if (*p == '"') {
            p = J_SkipString(p);
            continue;
        }
        if (*p == '{' || *p == '[') {
            depth++;
        } else if (*p == '}' || *p == ']') {
            if (--depth == 0) {
                return p + 1;
            }
        }
        p++;
    }
    return p;
}

// The value of "key" at the top level of the object [start, end): a pointer to it or NULL.
static const char *J_Find(const char *start, const char *end, const char *key)
{
    const char *p     = start + 1;
    size_t      klen  = strlen(key);

    while (p < end && *p) {
        if (*p == '"') {
            const char *s = p + 1, *e = J_SkipString(p);
            p             = e;
            while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t') {
                p++;
            }
            if (*p != ':') {
                continue; // a string value, not a key
            }
            p++;
            while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t') {
                p++;
            }
            if ((size_t)(e - 1 - s) == klen && !strncmp(s, key, klen)) {
                return p;
            }
            if (*p == '{' || *p == '[') {
                p = J_SkipBlock(p);
            }
            continue;
        }
        p++;
    }
    return NULL;
}

static int J_String(const char *start, const char *end, const char *key, char *out, int outSize)
{
    const char *v = J_Find(start, end, key);
    int         n = 0;

    out[0] = 0;
    if (!v || *v != '"') {
        return 0;
    }
    for (v++; *v && *v != '"' && n < outSize - 1; v++) {
        if (*v == '\\' && v[1]) {
            v++;
        }
        out[n++] = *v;
    }
    out[n] = 0;
    return 1;
}

// "v0.3.1-vita" -> {0, 3, 1}; compares like version numbers.
static int VU_CompareVersions(const char *a, const char *b)
{
    for (;;) {
        long x = 0, y = 0;
        while (*a && (*a < '0' || *a > '9') && *a != '.') {
            if (*a == '-') {
                a = "";
                break;
            }
            a++;
        }
        while (*b && (*b < '0' || *b > '9') && *b != '.') {
            if (*b == '-') {
                b = "";
                break;
            }
            b++;
        }
        if (!*a && !*b) {
            return 0;
        }
        x = strtol(a, (char **)&a, 10);
        y = strtol(b, (char **)&b, 10);
        if (x != y) {
            return x < y ? -1 : 1;
        }
        if (*a == '.') {
            a++;
        }
        if (*b == '.') {
            b++;
        }
    }
}

// Reads the release's version and the assets this Vita needs.
static int VU_ParseRelease(const char *json)
{
    const char *end = json + strlen(json), *assets;
    char        tag[64];

    if (*json != '{' || !J_String(json, end, "tag_name", tag, sizeof(tag))) {
        VU_Fail("GitHub's answer could not be read.", "no tag_name in %.80s", json);
        return 0;
    }
    // "v0.1.0" -> "0.1.0"
    {
        const char *s = tag;
        int         n = 0;
        while (*s && (*s < '0' || *s > '9')) {
            s++;
        }
        while (*s && *s != '-' && n < (int)sizeof(g_vu.newVersion) - 1) {
            g_vu.newVersion[n++] = *s++;
        }
        g_vu.newVersion[n] = 0;
    }

    memset(&g_vu.vpk, 0, sizeof(g_vu.vpk));
    assets = J_Find(json, end, "assets");
    if (assets && *assets == '[') {
        const char *aend = J_SkipBlock(assets), *p = assets + 1;

        while (p < aend) {
            if (*p == '{') {
                const char *oend = J_SkipBlock(p), *size;
                asset_t     a;
                char        digest[80];

                memset(&a, 0, sizeof(a));
                J_String(p, oend, "name", a.name, sizeof(a.name));
                J_String(p, oend, "browser_download_url", a.url, sizeof(a.url));
                if (J_String(p, oend, "digest", digest, sizeof(digest)) && !strncmp(digest, "sha256:", 7)) {
                    snprintf(a.sha256, sizeof(a.sha256), "%.64s", digest + 7);
                }
                size = J_Find(p, oend, "size");
                if (size) {
                    a.size = strtoll(size, NULL, 10);
                }
                if (!strcmp(a.name, VPK_ASSET)) {
                    g_vu.vpk = a;
                }
                p = oend;
                continue;
            }
            p++;
        }
    }
    if (!g_vu.vpk.url[0] || g_vu.vpk.size <= 0) {
        VU_Fail("The latest release has no " VPK_ASSET ".", "release %s", tag);
        return 0;
    }
    VU_Log("latest release %s: vpk %lld bytes", tag, g_vu.vpk.size);
    return 1;
}

// ---------- check ----------

static void *VU_CheckThread(void *arg)
{
    char        errbuf[CURL_ERROR_SIZE], url[256];
    buffer_t    body = {0};
    rateLimit_t rl   = {-1, 0};
    CURL       *c;
    CURLcode    res;
    long        http = 0;

    (void)arg;
    VU_Log("checking for updates (this is %s)", VITA_PORT_VERSION);
    if (!VU_NetUp()) {
        return NULL;
    }
    c = VU_Curl(errbuf);
    if (!c) {
        VU_Fail("Out of memory.", "curl_easy_init");
        return NULL;
    }
    if (g_vu.releaseUrl[0]) {
        snprintf(url, sizeof(url), "%s", g_vu.releaseUrl);
    } else {
        snprintf(url, sizeof(url), "https://api.github.com/repos/" CONKER_UPDATE_REPO "/releases/latest");
    }
    curl_easy_setopt(c, CURLOPT_URL, url);
    curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, VU_ToBuffer);
    curl_easy_setopt(c, CURLOPT_WRITEDATA, &body);
    curl_easy_setopt(c, CURLOPT_HEADERFUNCTION, VU_Header);
    curl_easy_setopt(c, CURLOPT_HEADERDATA, &rl);
    curl_easy_setopt(c, CURLOPT_CONNECTTIMEOUT, 5L);
    curl_easy_setopt(c, CURLOPT_TIMEOUT, 15L);
    {
        struct curl_slist *h = curl_slist_append(NULL, "Accept: application/vnd.github+json");
        curl_easy_setopt(c, CURLOPT_HTTPHEADER, h);
        res = curl_easy_perform(c);
        curl_slist_free_all(h);
    }
    curl_easy_getinfo(c, CURLINFO_RESPONSE_CODE, &http);
    curl_easy_cleanup(c);

    if (res != CURLE_OK) {
        VU_CurlFail(res, "checking the latest release", errbuf);
    } else if ((http == 403 || http == 429) && rl.remaining == 0) {
        time_t    reset = (time_t)rl.reset;
        struct tm tmv;
        localtime_r(&reset, &tmv);
        VU_Fail("GitHub is limiting update checks from this network for a while. Try again later.",
                "HTTP %ld, allowed again at %02d:%02d", http, tmv.tm_hour, tmv.tm_min);
    } else if (http == 404) {
        VU_Fail("No release was found on GitHub.", "HTTP 404 for %s", url);
    } else if (http != 200) {
        VU_Fail("GitHub answered with an error. Try again later.", "HTTP %ld", http);
    } else if (!body.data) {
        VU_Fail("GitHub's answer could not be read.", "empty answer");
    } else if (VU_ParseRelease(body.data)) {
        if (VU_CompareVersions(g_vu.newVersion, VITA_PORT_VERSION) > 0) {
            VU_Log("version %s is available", g_vu.newVersion);
            g_vu.state = VU_AVAILABLE;
        } else {
            VU_Log("up to date");
            g_vu.state = VU_UPTODATE;
        }
    }
    free(body.data);
    return NULL;
}

// ---------- download ----------

typedef struct {
    SceUID     fd;
    SHA256_CTX sha;
    int        writeFailed;
    long long  base; // bytes of the earlier files of this update
} download_t;

static size_t VU_ToFile(void *ptr, size_t size, size_t n, void *user)
{
    download_t *d   = (download_t *)user;
    int         len = (int)(size * n);

    if (sceIoWrite(d->fd, ptr, len) != len) {
        d->writeFailed = 1;
        return 0;
    }
    SHA256_Update(&d->sha, ptr, len);
    return len;
}

static int VU_Progress(void *user, curl_off_t total, curl_off_t now, curl_off_t ut, curl_off_t un)
{
    download_t *d = (download_t *)user;

    (void)total;
    (void)ut;
    (void)un;
    g_vu.done = d->base + now;
    return g_vu.cancel ? 1 : 0;
}

// Downloads one asset to 'path' and checks its size and SHA-256.
static int VU_DownloadAsset(const asset_t *a, const char *path, long long base)
{
    char          errbuf[CURL_ERROR_SIZE], part[300], hex[65];
    unsigned char hash[32];
    download_t    d;
    CURL         *c;
    CURLcode      res;
    long          http = 0;
    SceIoStat     st;

    snprintf(part, sizeof(part), "%s.part", path);
    memset(&d, 0, sizeof(d));
    d.base = base;
    d.fd   = sceIoOpen(part, SCE_O_WRONLY | SCE_O_CREAT | SCE_O_TRUNC, 0777);
    if (d.fd < 0) {
        VU_Fail("Could not write the download to the memory card.", "open %s = 0x%08X", part, (unsigned)d.fd);
        return 0;
    }
    SHA256_Init(&d.sha);

    c = VU_Curl(errbuf);
    if (!c) {
        sceIoClose(d.fd);
        VU_Fail("Out of memory.", "curl_easy_init");
        return 0;
    }
    VU_Log("downloading %s (%lld bytes)", a->name, a->size);
    curl_easy_setopt(c, CURLOPT_URL, a->url);
    curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, VU_ToFile);
    curl_easy_setopt(c, CURLOPT_WRITEDATA, &d);
    curl_easy_setopt(c, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(c, CURLOPT_XFERINFOFUNCTION, VU_Progress);
    curl_easy_setopt(c, CURLOPT_XFERINFODATA, &d);
    res = curl_easy_perform(c);
    curl_easy_getinfo(c, CURLINFO_RESPONSE_CODE, &http);
    curl_easy_cleanup(c);
    sceIoClose(d.fd);

    if (d.writeFailed) {
        sceIoRemove(part);
        VU_Fail("Could not write the download to the memory card.", "writing %s failed (memory card full?)", part);
        return 0;
    }
    if (res != CURLE_OK) {
        sceIoRemove(part);
        VU_CurlFail(res, a->name, errbuf);
        return 0;
    }
    if (http != 200) {
        sceIoRemove(part);
        VU_Fail("GitHub answered with an error. Try again later.", "HTTP %ld for %s", http, a->name);
        return 0;
    }
    if (sceIoGetstat(part, &st) < 0 || st.st_size != a->size) {
        sceIoRemove(part);
        VU_Fail("The download was cut off. Try again.", "%s: got %lld of %lld bytes", a->name,
                (long long)st.st_size, a->size);
        return 0;
    }
    SHA256_Final(hash, &d.sha);
    for (int i = 0; i < 32; i++) {
        snprintf(hex + i * 2, 3, "%02x", hash[i]);
    }
    if (a->sha256[0] && strcasecmp(hex, a->sha256)) {
        sceIoRemove(part);
        VU_Fail("The download is damaged (its SHA-256 does not match). Try again.", "%s: sha256 %s, expected %s",
                a->name, hex, a->sha256);
        return 0;
    }
    VU_Log("%s: %lld bytes, sha256 %s%s", a->name, a->size, hex, a->sha256[0] ? " (checked)" : " (not published)");
    sceIoRemove(path);
    if (sceIoRename(part, path) < 0) {
        VU_Fail("Could not write the download to the memory card.", "rename %s", part);
        return 0;
    }
    return 1;
}

static void *VU_DownloadThread(void *arg)
{
    SceIoDevInfo info;
    long long    need, freeBytes;
    FILE        *plan;
    int          res;

    (void)arg;
    sceIoMkdir(UPDATE_DIR, 0777);
    // the .vpk, then unpacked by updater.bin (about 2.5 times its size)
    need = g_vu.vpk.size * 3 + 8 * 1024 * 1024;
    memset(&info, 0, sizeof(info));
    res = sceIoDevctl("ux0:", 0x3001, NULL, 0, &info, sizeof(info));
    if (res >= 0) {
        freeBytes = info.free_size;
        if (freeBytes < need) {
            VU_Fail("There is not enough free space on the memory card.", "needs %lld MB, %lld MB free",
                    need / (1024 * 1024) + 1, freeBytes / (1024 * 1024));
            return NULL;
        }
    } else {
        VU_Log("free space unknown (sceIoDevctl = 0x%08X)", (unsigned)res);
    }
    if (!VU_NetUp()) {
        return NULL;
    }

    g_vu.done  = 0;
    g_vu.total = g_vu.vpk.size;
    if (!VU_DownloadAsset(&g_vu.vpk, VPK_PATH, 0)) {
        return NULL;
    }

    // what updater.bin has to do
    plan = fopen(PLAN_FILE, "w");
    if (!plan) {
        VU_Fail("Could not write the download to the memory card.", "open %s", PLAN_FILE);
        return NULL;
    }
    fprintf(plan, "version=%s\nvpk=%s\n", g_vu.newVersion, VPK_PATH);
    fclose(plan);
    VU_Log("ready to install %s", g_vu.newVersion);
    g_vu.state = VU_READY;
    return NULL;
}

// ---------- API ----------

static int VU_Start(void *(*fn)(void *))
{
    pthread_attr_t attr;

    if (g_vu.threadStarted) {
        pthread_join(g_vu.thread, NULL);
        g_vu.threadStarted = 0;
    }
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, 512 * 1024); // TLS handshakes need a deep stack
    if (pthread_create(&g_vu.thread, &attr, fn, NULL)) {
        pthread_attr_destroy(&attr);
        VU_Fail("Out of memory.", "pthread_create");
        return 0;
    }
    pthread_attr_destroy(&attr);
    g_vu.threadStarted = 1;
    return 1;
}

void VitaUpdate_Check(const char *release_url)
{
    static int curlReady;

    if (g_vu.state == VU_CHECKING || g_vu.state == VU_DOWNLOADING) {
        return;
    }
    if (!curlReady) {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curlReady = 1;
    }
    snprintf(g_vu.releaseUrl, sizeof(g_vu.releaseUrl), "%s", release_url ? release_url : "");
    g_vu.error[0] = g_vu.detail[0] = 0;
    g_vu.state                     = VU_CHECKING;
    VU_Start(VU_CheckThread);
}

void VitaUpdate_Download(void)
{
    if (g_vu.state != VU_AVAILABLE && !(g_vu.state == VU_ERROR && g_vu.vpk.url[0])) {
        return;
    }
    g_vu.cancel   = 0;
    g_vu.error[0] = g_vu.detail[0] = 0;
    g_vu.state                     = VU_DOWNLOADING;
    VU_Start(VU_DownloadThread);
}

void VitaUpdate_Cancel(void)
{
    g_vu.cancel = 1;
}

int VitaUpdate_CanInstall(void)
{
    // Safe homebrew get this error for the memory card's device control, which VitaShell
    // and PKGj use to tell the two modes apart; anything else (unsafe mode, Vita3K) can.
    int res = sceIoDevctl("ux0:", 0x3001, NULL, 0, NULL, 0);
    VU_Log("unsafe homebrew check: sceIoDevctl = 0x%08X", (unsigned)res);
    return res != (int)0x80010030;
}

void VitaUpdate_Launch(void)
{
    int res;

    if (g_vu.state != VU_READY) {
        return;
    }
    VU_Log("starting updater.bin");
    remove(RESULT_FILE);
    res = sceAppMgrLoadExec("app0:updater.bin", NULL, NULL);
    // Returns only when the Vita refused; an accepted call may still return first (as in
    // Vita3K) while the switch is under way: give it time before calling it a failure.
    for (int i = 0; res >= 0 && i < 50; i++) {
        sceKernelDelayThread(100 * 1000);
    }
    VU_Fail("The installer could not start. Enable Unsafe Homebrew in Settings > HENkaku Settings and try again.",
            "sceAppMgrLoadExec = 0x%08X", (unsigned)res);
}

vitaUpdateState_t VitaUpdate_State(void)
{
    return g_vu.state;
}

const char *VitaUpdate_CurrentVersion(void)
{
    return VITA_PORT_VERSION;
}

const char *VitaUpdate_NewVersion(void)
{
    return g_vu.newVersion;
}

void VitaUpdate_Progress(long long *done, long long *total)
{
    *done  = g_vu.done;
    *total = g_vu.total;
}

const char *VitaUpdate_Error(void)
{
    return g_vu.error;
}

const char *VitaUpdate_ErrorDetail(void)
{
    return g_vu.detail;
}

int VitaUpdate_TakeInstallResult(char *version, int versionSize, char *error, int errorSize, char *detail,
                                 int detailSize)
{
    FILE *f = fopen(RESULT_FILE, "r");
    char  line[512], status[16] = "", step[32] = "", code[16] = "", det[400] = "";

    if (!f) {
        return 0;
    }
    version[0] = error[0] = detail[0] = 0;
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = 0;
        if (!strncmp(line, "status=", 7)) {
            snprintf(status, sizeof(status), "%.15s", line + 7);
        } else if (!strncmp(line, "version=", 8)) {
            snprintf(version, versionSize, "%s", line + 8);
        } else if (!strncmp(line, "step=", 5)) {
            snprintf(step, sizeof(step), "%.31s", line + 5);
        } else if (!strncmp(line, "code=", 5)) {
            snprintf(code, sizeof(code), "%.15s", line + 5);
        } else if (!strncmp(line, "detail=", 7)) {
            snprintf(det, sizeof(det), "%.399s", line + 7);
        }
    }
    fclose(f);
    remove(RESULT_FILE);

    if (!strcmp(status, "ok")) {
        VU_Log("installed %s (reported by updater.bin)", version);
        return 1;
    }
    if (!strcmp(step, "plan")) {
        snprintf(error, errorSize, "The installer found nothing to install.");
    } else if (!strcmp(step, "extract")) {
        snprintf(error, errorSize, "The installer could not unpack the new version.");
    } else {
        snprintf(error, errorSize, "The new version could not be installed.");
    }
    snprintf(detail, detailSize, "%s (%s) %s", step, code, det);
    return -1;
}

#endif
