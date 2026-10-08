// Translated speech bubbles (the Vita build's Language setting; vita/translation/README.md).
//
// Every page a bubble shows comes from func_1516C878(message, page, kind): the message's text
// (a bank entry, D_800DD254/D_800DD258 by kind, or the script's own string), past `page` page
// breaks (0xBD, which func_1516A770 turned into NULs). The bubble's size, its typing out and
// its drawing all read the page through it. conker.toml calls this at the function's start:
// it finds the page the same way, and when the translation has one for it (keyed by the CRC32
// of the page's bytes, as vita/tools/text_dump.py lists them), it copies the translated page
// into RDRAM past the game's 8 MB and returns that instead.
//
// Translation files are UTF-8, one page per line: "<key> = <text>", "\n" for a new line,
// "<XX>" for one of the game's control codes (colours, button icons), and "{word}" for a swear
// word: written out, or with the Censorship setting as the game's own coloured symbols (the
// US text has only those).

#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unordered_map>

#include "recomp.h"

#include "conker.hpp"

namespace {
    constexpr gpr addr(uint32_t a) { return (gpr)(int32_t)a; }

    constexpr uint32_t text_bank_low = 0x800DD254;  // pages of messages 0..0xFF
    constexpr uint32_t text_bank_high = 0x800DD258; // and from 0x100
    // Translated pages live here (between the runtime's patch area and its mod heap).
    constexpr uint32_t text_area_start = 0x80A00000;
    constexpr uint32_t text_area_end = 0x80C00000;
    constexpr size_t max_page = 1024;

    // Control codes: 0xA1 resets the colour, 0xA2..0xA5 red, green, blue, yellow, 0xA6 makes
    // what follows pulse; 0xB2..0xB5 are the swearing symbols.
    constexpr uint8_t code_plain = 0xA1, code_pulse = 0xA6;

    uint32_t crc32(const uint8_t* p, size_t n) {
        static uint32_t table[256];
        if (table[1] == 0) {
            for (uint32_t i = 0; i < 256; i++) {
                uint32_t c = i;
                for (int k = 0; k < 8; k++) c = c & 1 ? 0xEDB88320u ^ (c >> 1) : c >> 1;
                table[i] = c;
            }
        }
        uint32_t c = 0xFFFFFFFFu;
        for (size_t i = 0; i < n; i++) c = table[(c ^ p[i]) & 0xFF] ^ (c >> 8);
        return c ^ 0xFFFFFFFFu;
    }

    // The font's letters (D_80085930) for Portuguese: the accents it lacks become the
    // nearest it has.
    void put_char(std::string& out, uint32_t cp) {
        switch (cp) {
            case 0xE1: case 0xE0: case 0xC1: case 0xC0: out += '\xC0'; return; // á à -> À
            case 0xE2: case 0xE3: case 0xC2: case 0xC3: out += '\xC2'; return; // â ã -> Â
            case 0xE7: case 0xC7: out += '\xC7'; return;                        // ç
            case 0xE9: case 0xC9: out += '\xC9'; return;                        // é
            case 0xEA: case 0xCA: out += '\xCA'; return;                        // ê
            case 0xED: case 0xCD: out += '\xCE'; return;                        // í -> Î
            case 0xF3: case 0xF4: case 0xF5: case 0xD3: case 0xD4: case 0xD5: out += '\xD4'; return; // ó ô õ -> Ô
            case 0xFA: case 0xDA: out += '\xDB'; return;                        // ú -> Û
            case 0xFC: case 0xDC: out += '\xDC'; return;                        // ü
        }
        if (cp >= 'A' && cp <= 'Z') cp += 'a' - 'A'; // the dialogue is written in lowercase
        out += cp < 0x80 ? (char)cp : '?';
    }

    // A swear word in the game's symbols: one per letter, in one colour, pulsing.
    void put_symbols(std::string& out, const std::string& word, uint32_t seed) {
        const uint8_t colour = 0xA2 + seed % 4;
        out += (char)code_pulse;
        int n = 0;
        for (char c : word) {
            if (c == ' ') { out += ' '; continue; }
            if ((uint8_t)c >= 0x80 && ((uint8_t)c & 0xC0) == 0x80) continue; // UTF-8 continuation
            out += (char)colour;
            out += (char)(0xB2 + (seed + n * 3) % 4);
            n++;
        }
        out += (char)code_plain;
    }

    // One translation line's text to the game's bytes.
    std::string encode(const char* s, bool censored, uint32_t key) {
        std::string out;
        while (*s) {
            const uint8_t c = (uint8_t)*s;
            if (c == '\\' && s[1] == 'n') { out += '\n'; s += 2; continue; }
            if (c == '<' && std::isxdigit((uint8_t)s[1]) && std::isxdigit((uint8_t)s[2]) && s[3] == '>') {
                out += (char)std::strtoul(std::string(s + 1, 2).c_str(), nullptr, 16);
                s += 4;
                continue;
            }
            if (c == '{') {
                const char* end = std::strchr(s, '}');
                if (end) {
                    const std::string word(s + 1, end - s - 1);
                    if (censored) put_symbols(out, word, key);
                    else out += encode(word.c_str(), false, key);
                    s = end + 1;
                    continue;
                }
            }
            uint32_t cp = c;
            int extra = 0;
            if (c >= 0xF0) { cp = c & 0x07; extra = 3; }
            else if (c >= 0xE0) { cp = c & 0x0F; extra = 2; }
            else if (c >= 0xC0) { cp = c & 0x1F; extra = 1; }
            s++;
            for (; extra > 0 && ((uint8_t)*s & 0xC0) == 0x80; extra--) cp = (cp << 6) | ((uint8_t)*s++ & 0x3F);
            put_char(out, cp);
        }
        return out;
    }

    struct Language {
        bool loaded = false;
        std::unordered_map<uint32_t, std::string> pages; // key -> the line's text
    };
    Language languages[2]; // by conker::text_language(): 0 English (none), 1 Portuguese

    void load(Language& lang, const char* name) {
        lang.loaded = true;
        const std::string paths[] = {
#if defined(__vita__)
            std::string("ux0:data/conker/translation/") + name, // for trying changes without a new VPK
            std::string("app0:translation/") + name,
#else
            std::string("translation/") + name,
#endif
        };
        for (const std::string& path : paths) {
            FILE* f = std::fopen(path.c_str(), "r");
            if (!f) continue;
            char line[4096];
            while (std::fgets(line, sizeof line, f)) {
                size_t n = std::strlen(line);
                while (n && (line[n - 1] == '\n' || line[n - 1] == '\r')) line[--n] = 0;
                char* eq = std::strstr(line, " = ");
                if (line[0] == '#' || !eq || eq - line != 8) continue;
                *eq = 0;
                lang.pages[(uint32_t)std::strtoul(line, nullptr, 16)] = eq + 3;
            }
            std::fclose(f);
            std::fprintf(stderr, "[text] %s: %u pages\n", path.c_str(), (unsigned)lang.pages.size());
            return;
        }
        std::fprintf(stderr, "[text] no %s\n", name);
    }

    uint32_t text_area_next = text_area_start;
    // Where each translated page went, by key and censorship (the copy is rewritten each time).
    std::unordered_map<uint64_t, uint32_t> placed;
}

// True when it answered ($v0 = the translated page) and func_1516C878 returns at once.
extern "C" int conker_translate_page(uint8_t* rdram, recomp_context* ctx) {
#if defined(__vita__)
    const int language = conker::text_language();
    const bool censored = conker::text_censored();
#else
    const int language = 0;
    const bool censored = true;
#endif
    if (language <= 0 || language > 1) {
        return 0;
    }
    Language& lang = languages[language];
    if (!lang.loaded) {
        load(lang, "pt_br.txt");
    }
    if (lang.pages.empty()) {
        return 0;
    }

    // func_1516C878's own search for the page.
    const gpr message = ctx->r4;
    const int32_t page = (int32_t)ctx->r5;
    const int16_t kind = (int16_t)ctx->r6;
    gpr s;
    switch (kind) {
        case 0: s = MEM_W(MEM_W(4, message) * 8, MEM_W(0, addr(text_bank_low))); break;
        case 1: s = MEM_W(MEM_W(4, message) * 8, MEM_W(0, addr(text_bank_high))); break;
        case 2: s = MEM_W(4, message); break;
        default: return 0;
    }
    for (int32_t i = 0; i < page; i++) {
        while (MEM_B(0, s) != 0) s++;
        while (MEM_B(0, s) == 0) s++;
    }

    uint8_t bytes[max_page];
    size_t n = 0;
    while (n < max_page && (bytes[n] = (uint8_t)MEM_B(n, s)) != 0) n++;
    if (n == max_page) {
        return 0;
    }
    const uint32_t key = crc32(bytes, n);
    auto found = lang.pages.find(key);
    if (found == lang.pages.end()) {
        return 0;
    }

    const std::string text = encode(found->second.c_str(), censored, key);
    const uint64_t slot = ((uint64_t)key << 1) | (censored ? 1 : 0);
    auto at = placed.find(slot);
    uint32_t dest;
    if (at != placed.end()) {
        dest = at->second;
    }
    else {
        if (text_area_next + text.size() + 1 > text_area_end) {
            // Full: start over (pages shown long ago are rewritten when shown again).
            placed.clear();
            text_area_next = text_area_start;
        }
        dest = text_area_next;
        text_area_next = (text_area_next + (uint32_t)text.size() + 1 + 3) & ~3u;
        placed[slot] = dest;
    }
    for (size_t i = 0; i < text.size(); i++) {
        MEM_B(i, addr(dest)) = (int8_t)text[i];
    }
    MEM_B(text.size(), addr(dest)) = 0;
    ctx->r2 = addr(dest);
    return 1;
}
