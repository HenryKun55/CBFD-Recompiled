/* PS Vita start-up screen: the port's version and the update check, drawn straight
 * into the boot picture's display buffer (platform_vita.c) before vitaGL and the game
 * start.
 *
 * The port's version goes in the bottom right corner and stays for as long as the boot
 * picture does. Then, unless conker.cfg says update_check=0, a check for a newer release
 * runs in the background (vita_update.c); a semi-transparent panel over the picture tells
 * what is going on: checking, a new version (X: install, O: skip), the download with a
 * progress bar, the installation, or what went wrong. When nothing is found within about
 * three seconds (no network, a slow one) the game starts as usual. After an update the
 * result that updater.bin left is shown once.
 *
 * Installing needs HENkaku's "Enable Unsafe Homebrew": without it a new version is only
 * announced, with how to turn it on. When the Vita refuses to start updater.bin, the game
 * says so and closes on a button press rather than starting in that state.
 *
 * Text: two sizes of Oswald (SIL Open Font License, vita/fonts), turned into
 * 8-bit alpha glyphs by tools/make_vita_boot_font.py and packed as app0:font/.
 *
 * Ported from the author's Project I.G.I. and OpenMoHAA Vita ports. */
#if defined(__vita__)
#include "vita_bootui.h"
#include "vita_update.h"
#include <png.h>
#include <psp2/kernel/sysmem.h>

#include <psp2/apputil.h>
#include <psp2/ctrl.h>
#include <psp2/system_param.h>
#include <psp2/display.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/kernel/threadmgr.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lines in the game's log (stderr goes to ux0:data/conker/log.txt). */
#define rt_log(...) (fprintf(stderr, "[boot] " __VA_ARGS__), fputc('\n', stderr))

#ifndef CONKER_PORT_VERSION
#define CONKER_PORT_VERSION "0.0.0"
#endif

#define FB_W 960
#define FB_H 544
#define PANEL_W 720
#define PANEL_X ((FB_W - PANEL_W) / 2)
#define PANEL_BOTTOM (FB_H - 36)
#define PAD 22
#define TEXT_W (PANEL_W - 2 * PAD)
#define CHECK_WAIT_MS 3000   /* the longest the boot waits for the check */
#define CFG_PATH "ux0:data/conker/conker.cfg"
#define LOG_PATH "ux0:data/conker/update/update.log"

#define ANY_BUTTON (SCE_CTRL_SELECT | SCE_CTRL_START | SCE_CTRL_UP | SCE_CTRL_RIGHT | SCE_CTRL_DOWN | SCE_CTRL_LEFT | \
                    SCE_CTRL_LTRIGGER | SCE_CTRL_RTRIGGER | SCE_CTRL_TRIANGLE | SCE_CTRL_CIRCLE | SCE_CTRL_CROSS | \
                    SCE_CTRL_SQUARE)
#define RGB(r, g, b) (0xFF000000u | (uint32_t)(b) << 16 | (uint32_t)(g) << 8 | (uint32_t)(r))
#define C_TEXT RGB(0xF2, 0xF2, 0xF2)
#define C_DIM RGB(0xA8, 0xAE, 0xB4)
#define C_ACCENT RGB(0xF0, 0xB0, 0x40)
#define C_ERROR RGB(0xFF, 0x80, 0x70)
#define C_OK RGB(0x80, 0xE0, 0x90)

typedef struct __attribute__((packed)) {   /* 14 bytes, as in the file */
    uint16_t w, h;
    int16_t x, y;
    uint16_t advance;
    uint32_t offset;
} Glyph;

typedef struct {
    Glyph glyph[224];
    unsigned char *bits;
    int line_h, ascent;
} Font;

static Font s_big, s_small;
static uint32_t *s_screen;   /* the picture on display */
static uint32_t *s_bg;       /* the picture without the panel */
static uint32_t *s_fb;       /* where the panel is put together, off screen */
static int s_dirty_y0 = FB_H, s_dirty_y1;   /* rows the panel covers on screen */

/* ---- font ---------------------------------------------------------------- */

static int font_load(Font *f, const char *path)
{
    FILE *fp = fopen(path, "rb");
    unsigned char hdr[8];
    uint32_t size = 0;
    if (!fp)
        return 0;
    int ok = fread(hdr, 1, 8, fp) == 8 && !memcmp(hdr, "VBF1", 4) &&
             fread(f->glyph, sizeof(Glyph), 224, fp) == 224 && fread(&size, 4, 1, fp) == 1 &&
             (f->bits = malloc(size)) != NULL && fread(f->bits, 1, size, fp) == size;
    fclose(fp);
    if (!ok) {
        free(f->bits);
        f->bits = NULL;
        return 0;
    }
    f->line_h = hdr[4] | hdr[5] << 8;
    f->ascent = hdr[6] | hdr[7] << 8;
    return 1;
}

static int text_width(const Font *f, const char *s)
{
    int w = 0;
    for (; *s; s++) {
        unsigned c = (unsigned char)*s;
        if (c >= 32)
            w += f->glyph[c - 32].advance;
    }
    return w;
}

static uint32_t blend(uint32_t d, uint32_t c, int a)
{
    int dr = d & 0xFF, dg = d >> 8 & 0xFF, db = d >> 16 & 0xFF;
    int r = c & 0xFF, g = c >> 8 & 0xFF, b = c >> 16 & 0xFF;
    return RGB(dr + (r - dr) * a / 255, dg + (g - dg) * a / 255, db + (b - db) * a / 255);
}

/* Latin-1 text, alpha-blended into dst at x, y (top of the line). */
static void text_draw(uint32_t *dst, const Font *f, int x, int y, const char *s, uint32_t colour)
{
    for (; *s; s++) {
        unsigned c = (unsigned char)*s;
        if (c < 32)
            continue;
        const Glyph *g = &f->glyph[c - 32];
        for (int gy = 0; gy < g->h; gy++) {
            int py = y + g->y + gy;
            if (py < 0 || py >= FB_H)
                continue;
            for (int gx = 0; gx < g->w; gx++) {
                int px = x + g->x + gx, a = f->bits[g->offset + gy * g->w + gx];
                if (a && px >= 0 && px < FB_W)
                    dst[py * FB_W + px] = blend(dst[py * FB_W + px], colour, a);
            }
        }
        x += g->advance;
    }
}

/* Lines no wider than the panel, cut at spaces, centred. Returns the next y; draw = 0
 * only measures. */
static int text_wrapped(const Font *f, int y, const char *text, uint32_t colour, int draw)
{
    char line[256];
    while (*text) {
        int n = 0, cut = 0;
        while (text[n] && n < (int)sizeof(line) - 1) {
            line[n] = text[n];
            line[n + 1] = 0;
            if (text_width(f, line) > TEXT_W)
                break;
            if (text[n] == ' ')
                cut = n;
            n++;
        }
        if (text[n] && cut)
            n = cut;
        memcpy(line, text, (size_t)n);
        line[n] = 0;
        if (draw)
            text_draw(s_fb, f, (FB_W - text_width(f, line)) / 2, y, line, colour);
        y += f->line_h;
        text += n;
        while (*text == ' ')
            text++;
    }
    return y;
}

/* ---- screen -------------------------------------------------------------- */

/* A rounded rectangle, colour c at alpha a (0-255), blended into s_fb. */
static void panel_rect(int x0, int y0, int w, int h, uint32_t c, int a, int radius)
{
    for (int y = y0; y < y0 + h; y++) {
        int inset = 0;
        int dy = y < y0 + radius ? y0 + radius - y : y >= y0 + h - radius ? y - (y0 + h - radius - 1) : 0;
        if (dy > 0) {   /* the corners: skip the pixels outside the circle */
            while (inset < radius && (radius - inset) * (radius - inset) + dy * dy > radius * radius)
                inset++;
        }
        for (int x = x0 + inset; x < x0 + w - inset; x++)
            s_fb[y * FB_W + x] = blend(s_fb[y * FB_W + x], c, a);
    }
}

/* Puts the panel's rows of s_fb on screen right after the vertical blank, and the
 * picture back where an earlier, taller panel was. */
static void present(int y0, int y1)
{
    int from = y0 < s_dirty_y0 ? y0 : s_dirty_y0, to = y1 > s_dirty_y1 ? y1 : s_dirty_y1;
    sceDisplayWaitVblankStart();
    if (to > from)
        memcpy(s_screen + from * FB_W, s_fb + from * FB_W, (size_t)(to - from) * FB_W * 4);
    s_dirty_y0 = y0;
    s_dirty_y1 = y1;
}

/* The panel: the version line, a title, an optional detail, a progress bar (progress < 0:
 * none) and a button hint. */
static void show(const char *title, uint32_t title_colour, const char *detail, float progress, const char *hint)
{
    static char last[1200];
    char key[1200];
    if (progress > 1.0f)
        progress = 1.0f;
    /* drawn again only when something changes (the bar: when it grows by a pixel) */
    snprintf(key, sizeof(key), "%s|%s|%d|%s", title ? title : "", detail ? detail : "",
             progress < 0.0f ? -1 : (int)(TEXT_W * progress), hint ? hint : "");
    if (!strcmp(key, last))
        return;
    snprintf(last, sizeof(last), "%s", key);

    int h = s_small.line_h + 6;
    if (title)
        h = text_wrapped(&s_big, h, title, 0, 0);
    if (detail && detail[0])
        h = text_wrapped(&s_small, h + 4, detail, 0, 0);
    if (progress >= 0.0f)
        h += 26;
    if (hint && hint[0])
        h += 10 + s_small.line_h;
    int top = PANEL_BOTTOM - h - 2 * PAD, y = top + PAD;

    memcpy(s_fb, s_bg, (size_t)FB_W * FB_H * 4);
    panel_rect(PANEL_X, top, PANEL_W, PANEL_BOTTOM - top, RGB(0x0A, 0x0D, 0x12), 200, 12);
    panel_rect(PANEL_X + 12, top, PANEL_W - 24, 3, C_ACCENT, 230, 0);

    char head[96];
    snprintf(head, sizeof(head), "Conker's Bad Fur Day for PS Vita  -  version %s", CONKER_PORT_VERSION);
    text_draw(s_fb, &s_small, (FB_W - text_width(&s_small, head)) / 2, y, head, C_DIM);
    y += s_small.line_h + 6;
    if (title)
        y = text_wrapped(&s_big, y, title, title_colour, 1);
    if (detail && detail[0])
        y = text_wrapped(&s_small, y + 4, detail, C_DIM, 1);
    if (progress >= 0.0f) {
        int x0 = PANEL_X + PAD, by = y + 10, done = (int)(TEXT_W * progress);
        panel_rect(x0, by, TEXT_W, 12, RGB(0x30, 0x34, 0x3A), 255, 6);
        if (done >= 12)
            panel_rect(x0, by, done, 12, C_ACCENT, 255, 6);
        y += 26;
    }
    if (hint && hint[0])
        text_draw(s_fb, &s_small, (FB_W - text_width(&s_small, hint)) / 2, y + 10, hint, C_ACCENT);
    present(top, PANEL_BOTTOM);
}

/* The picture as it was, the version in the corner included. */
static void hide(void)
{
    memcpy(s_fb, s_bg, (size_t)FB_W * FB_H * 4);
    present(FB_H, FB_H);
}

static unsigned buttons(void)
{
    SceCtrlData pad;
    memset(&pad, 0, sizeof(pad));
    sceCtrlPeekBufferPositive(0, &pad, 1);
    return pad.buttons;
}

/* Waits for one of the buttons in mask; returns it, or 0 after timeout_ms (0: no
 * timeout). A button still held from an earlier screen (X for "install") must be let go
 * first: only a new press counts. */
static unsigned wait_button(unsigned mask, int timeout_ms)
{
    for (int waited = 0; (buttons() & mask) && waited < 3000; waited += 16)
        sceKernelDelayThread(16 * 1000);
    unsigned prev = buttons();
    for (int waited = 0; !timeout_ms || waited < timeout_ms; waited += 16) {
        unsigned now = buttons(), pressed = now & ~prev & mask;
        if (pressed)
            return pressed;
        prev = now;
        sceKernelDelayThread(16 * 1000);
    }
    return 0;
}

/* key=value from conker.cfg, or def. */
static void cfg_value(const char *name, char *out, size_t out_size, const char *def)
{
    snprintf(out, out_size, "%s", def);
    FILE *f = fopen(CFG_PATH, "r");
    if (!f)
        return;
    char line[512];
    size_t n = strlen(name);
    while (fgets(line, sizeof(line), f)) {
        if (!strncmp(line, name, n) && line[n] == '=') {
            line[strcspn(line, "\r\n")] = 0;
            snprintf(out, out_size, "%s", line + n + 1);
        }
    }
    fclose(f);
}

/* ---- the check ----------------------------------------------------------- */

/* What updater.bin did, once after an update. */
static void show_install_result(void)
{
    char version[32], error[256], detail[400], text[700];
    int r = VitaUpdate_TakeInstallResult(version, sizeof(version), error, sizeof(error), detail, sizeof(detail));
    if (r > 0) {
        rt_log("update: version %s installed", version);
        snprintf(text, sizeof(text), "Version %s is installed.", version);
        show(text, C_OK, "Settings, saves and game files were kept.", -1.0f, NULL);
        wait_button(ANY_BUTTON, 2500);
    } else if (r < 0) {
        rt_log("update: install failed: %s (%s)", error, detail);
        /* only a failure while files were replaced (step "install") can leave the game
         * incomplete, and then updater.bin's message says what to do */
        snprintf(text, sizeof(text), "%s. %sDetails: " LOG_PATH, detail,
                 strncmp(detail, "install", 7) ? "The installed game still works. " : "");
        show(error, C_ERROR, text, -1.0f, "Press any button to continue.");
        wait_button(ANY_BUTTON, 20000);
    }
}

/* updater.bin did not take over. Whether the Vita is still switching to it is unknown,
 * so the game does not go on starting in that state: it closes after a button press. */
static void launch_failed(void) __attribute__((noreturn));
static void launch_failed(void)
{
    char text[512];
    rt_log("update: %s (%s)", VitaUpdate_Error(), VitaUpdate_ErrorDetail());
    snprintf(text, sizeof(text), "%s. The installed game still works: close it and start it again.",
             VitaUpdate_ErrorDetail());
    show(VitaUpdate_Error(), C_ERROR, text, -1.0f, "Press any button to close the game.");
    wait_button(ANY_BUTTON, 0);
    rt_log("update: closing the game after the failed start of updater.bin");
    sceKernelExitProcess(0);
    for (;;)
        sceKernelDelayThread(1000 * 1000);
}

/* ---- notices --------------------------------------------------------------- */

/* What's new, told once (ux0:data/conker/notices.txt keeps the ones seen: the game's data
 * folder, which installing a vpk or an update leaves alone), in the Vita's language. Latin-1. */
#define NOTICES_PATH "ux0:data/conker/notices.txt"
#define NOTICE_ID "interpolation-1"
/* English, Portuguese, Spanish, French, German, Italian. */
static const char *const notice_text[6][3] = {
    { "New: up to 60 fps (interpolated)",
      "Turn it on in the game's menu: START + SELECT > Frame rate. It's off by default: shadows, footprints and dust still move at 30.",
      "Press any button to continue." },
    { "Novidade: at\351 60 fps (interpolado)",
      "Ative no menu do jogo: START + SELECT > Frame rate. Vem desligado porque sombras, pegadas e poeira ainda se mexem a 30.",
      "Aperte qualquer bot\343o para continuar." },
    { "Novedad: hasta 60 fps (interpolado)",
      "Act\355valo en el men\372 del juego: START + SELECT > Frame rate. Viene desactivado porque las sombras, las huellas y el polvo siguen a 30.",
      "Pulsa cualquier bot\363n para continuar." },
    { "Nouveau : jusqu'\340 60 fps (interpol\351)",
      "Active-le dans le menu du jeu : START + SELECT > Frame rate. Il est d\351sactiv\351 par d\351faut : les ombres, les traces de pas et la poussi\350re restent \340 30.",
      "Appuie sur un bouton pour continuer." },
    { "Neu: bis zu 60 fps (interpoliert)",
      "Im Spielmen\374 einschalten: START + SELECT > Frame rate. Standardm\344\337ig aus, weil Schatten, Fu\337spuren und Staub weiter mit 30 laufen.",
      "Beliebige Taste dr\374cken, um fortzufahren." },
    { "Novit\340: fino a 60 fps (interpolato)",
      "Attivalo nel menu del gioco: START + SELECT > Frame rate. \310 disattivato di default: ombre, impronte e polvere restano a 30.",
      "Premi un tasto qualsiasi per continuare." }
};

static int notice_language(void)
{
    int lang = SCE_SYSTEM_PARAM_LANG_ENGLISH_US;
    if (sceAppUtilSystemParamGetInt(SCE_SYSTEM_PARAM_ID_LANG, &lang) < 0)
        return 0;
    switch (lang) {
    case SCE_SYSTEM_PARAM_LANG_PORTUGUESE_BR:
    case SCE_SYSTEM_PARAM_LANG_PORTUGUESE_PT: return 1;
    case SCE_SYSTEM_PARAM_LANG_SPANISH: return 2;
    case SCE_SYSTEM_PARAM_LANG_FRENCH: return 3;
    case SCE_SYSTEM_PARAM_LANG_GERMAN: return 4;
    case SCE_SYSTEM_PARAM_LANG_ITALIAN: return 5;
    default: return 0;
    }
}

static void show_notice(void)
{
    char line[128];
    FILE *f = fopen(NOTICES_PATH, "r");
    if (f) {
        while (fgets(line, sizeof(line), f)) {
            line[strcspn(line, "\r\n")] = 0;
            if (!strcmp(line, NOTICE_ID)) {
                fclose(f);
                return;
            }
        }
        fclose(f);
    }
    const char *const *t = notice_text[notice_language()];
    rt_log("notice %s shown", NOTICE_ID);
    show(t[0], C_ACCENT, t[1], -1.0f, t[2]);
    wait_button(ANY_BUTTON, 0);
    f = fopen(NOTICES_PATH, "a");
    if (f) {
        fprintf(f, "%s\n", NOTICE_ID);
        fclose(f);
    }
}

static void run_check(void)
{
    char url[256], text[512];
    vitaUpdateState_t st;
    int shown = 0, installing = 0;

    cfg_value("update_url", url, sizeof(url), "");
    VitaUpdate_Check(url);
    /* no network: the check fails at once, nothing is shown */
    for (int t = 0; (st = VitaUpdate_State()) == VU_CHECKING && t < CHECK_WAIT_MS; t += 50) {
        if (t >= 250 && !shown) {
            show("Checking for updates...", C_TEXT, NULL, -1.0f, NULL);
            shown = 1;
        }
        sceKernelDelayThread(50 * 1000);
    }
    if (st == VU_CHECKING) {
        /* the answer comes too late: it is left to the next start */
        rt_log("update: no answer in %d ms, starting the game", CHECK_WAIT_MS);
        return;
    }
    if (st == VU_UPTODATE) {
        rt_log("update: version %s is the latest", CONKER_PORT_VERSION);
        if (shown) {
            show("This is the latest version.", C_OK, NULL, -1.0f, NULL);
            sceKernelDelayThread(700 * 1000);
        }
        return;
    }
    if (st == VU_AVAILABLE) {
        rt_log("update: version %s is available", VitaUpdate_NewVersion());
        snprintf(text, sizeof(text), "Version %s is available (you have %s).", VitaUpdate_NewVersion(),
                 VitaUpdate_CurrentVersion());
        if (!VitaUpdate_CanInstall()) {
            /* updater.bin could neither be started nor write the game's folder */
            rt_log("update: Unsafe Homebrew is off, the update is not offered");
            show(text, C_TEXT,
                 "Updates need \"Enable Unsafe Homebrew\" in Settings > HENkaku Settings. Turn it on and start "
                 "the game again to install.",
                 -1.0f, "Press any button to continue.");
            wait_button(ANY_BUTTON, 15000);
            return;
        }
        show(text, C_TEXT, "Settings, saves and game files are kept.", -1.0f, "X: install      O: skip");
        /* update_auto=1 (for testing) installs without asking */
        cfg_value("update_auto", url, sizeof(url), "0");
        if (atoi(url) != 0) {
            sceKernelDelayThread(1500 * 1000);
        } else if (wait_button(SCE_CTRL_CROSS | SCE_CTRL_CIRCLE, 0) != SCE_CTRL_CROSS) {
            rt_log("update: skipped");
            return;
        }
        installing = 1;
        VitaUpdate_Download();
        while ((st = VitaUpdate_State()) == VU_DOWNLOADING) {
            long long done, total;
            char amount[96];
            VitaUpdate_Progress(&done, &total);
            snprintf(text, sizeof(text), "Downloading version %s...", VitaUpdate_NewVersion());
            snprintf(amount, sizeof(amount), "%.1f of %.1f MB", (double)done / 1048576.0,
                     (double)total / 1048576.0);
            show(text, C_TEXT, amount, total > 0 ? (float)done / (float)total : 0.0f, "O: cancel");
            if (buttons() & SCE_CTRL_CIRCLE)
                VitaUpdate_Cancel();
            sceKernelDelayThread(100 * 1000);
        }
        if (st == VU_READY) {
            snprintf(text, sizeof(text), "Installing version %s...", VitaUpdate_NewVersion());
            show(text, C_TEXT, "The game closes, installs the new version and starts again.", 1.0f, NULL);
            sceKernelDelayThread(1200 * 1000);
            VitaUpdate_Launch();   /* returns only when the Vita refused */
            launch_failed();
        }
    }
    /* A failed check (no Wi-Fi, no internet, GitHub unreachable or without a release)
     * only goes to the log: the game just starts. Once the player chose to install,
     * every failure is told. */
    if (st == VU_ERROR) {
        rt_log("update: %s (%s)", VitaUpdate_Error(), VitaUpdate_ErrorDetail());
        if (installing) {
            snprintf(text, sizeof(text), "%s. The installed game still works.", VitaUpdate_ErrorDetail());
            show(VitaUpdate_Error(), C_ERROR, text, -1.0f, "Press any button to continue.");
            wait_button(ANY_BUTTON, 15000);   /* nobody looking: the game goes on by itself */
        }
    }
}

/* sce_sys/pic0.png (960x544, the picture the Vita shows while the app starts) in a display
 * buffer of its own, on screen until the renderer shows its first frame. */
uint32_t *vita_boot_picture_show(void)
{
    SceUID block = sceKernelAllocMemBlock("boot_picture", SCE_KERNEL_MEMBLOCK_TYPE_USER_CDRAM_RW, 0x200000, NULL);
    void *base = NULL;
    if (block < 0 || sceKernelGetMemBlockBase(block, &base) < 0)
        return NULL;
    memset(base, 0, 0x200000);
    png_image image;
    memset(&image, 0, sizeof(image));
    image.version = PNG_IMAGE_VERSION;
    if (png_image_begin_read_from_file(&image, "app0:sce_sys/pic0.png")) {
        if (image.width == FB_W && image.height == FB_H) {
            image.format = PNG_FORMAT_RGBA;
            png_image_finish_read(&image, NULL, base, FB_W * 4, NULL);
        }
        png_image_free(&image);
    }
    SceDisplayFrameBuf fb;
    memset(&fb, 0, sizeof(fb));
    fb.size = sizeof(fb);
    fb.base = base;
    fb.pitch = FB_W;
    fb.pixelformat = SCE_DISPLAY_PIXELFORMAT_A8B8G8R8;
    fb.width = FB_W;
    fb.height = FB_H;
    sceDisplaySetFrameBuf(&fb, SCE_DISPLAY_SETBUF_NEXTFRAME);
    return base;
}

void vita_bootui_run(uint32_t *framebuffer)
{
    if (!framebuffer)
        return;
    if (!font_load(&s_big, "app0:font/boot.font") || !font_load(&s_small, "app0:font/boot_small.font")) {
        rt_log("boot screen: app0:font/boot*.font missing, no update check");
        goto out;
    }
    s_screen = framebuffer;
    s_bg = malloc((size_t)FB_W * FB_H * 4);
    s_fb = malloc((size_t)FB_W * FB_H * 4);
    if (!s_bg || !s_fb)
        goto out;

    /* the version, small, in the bottom right corner of the picture */
    char version[48];
    snprintf(version, sizeof(version), "v%s", CONKER_PORT_VERSION);
    int vx = FB_W - 14 - text_width(&s_small, version), vy = FB_H - 8 - s_small.line_h;
    text_draw(s_screen, &s_small, vx + 1, vy + 1, version, RGB(0, 0, 0));
    text_draw(s_screen, &s_small, vx, vy, version, C_DIM);
    memcpy(s_bg, s_screen, (size_t)FB_W * FB_H * 4);

    show_install_result();
    char check[16];
    cfg_value("update_check", check, sizeof(check), "1");
    if (atoi(check) != 0)
        run_check();
    else
        rt_log("update: check off (update_check=0)");
    show_notice();
    hide();
out:
    free(s_bg);
    free(s_fb);
    free(s_big.bits);
    free(s_small.bits);
    s_bg = s_fb = NULL;
    s_big.bits = s_small.bits = NULL;
}

#endif
