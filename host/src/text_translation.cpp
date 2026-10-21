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

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
    // What a speech bubble holds (vita/tools/check_bubbles.py derives these from the game's
    // sizing and checks every page against them, and that they're these). The game sizes a
    // bubble to its text (func_1516A7B0: (widest page + pad / 2) * 1.15 by (tallest + pad) * 1.04,
    // pad 18, or 25 with the message's flags & 2; drawn (2W + 1) * 0.575 wide by func_1516B6BC),
    // with no limit of its own. The limits: the bubble, with pad 25 and its shadow, inside the
    // 4:3 view (2..290, 4 pixels in; widescreen.cpp keeps it there): text 196 pixels wide by
    // func_150428D4's measure; text as tall as the English's tallest page (dialogue 5 lines,
    // 60 pixels; the hint book's 9 lines, 108); a line within func_1516C934's 84-byte buffer.
    constexpr int bubble_text_px = 196;
    constexpr int bubble_text_h_dialogue = 60;
    constexpr int bubble_text_h_hint = 108;
    constexpr size_t bubble_line_bytes = 83;
    // A censored swear word is at most this many symbols (the English's runs are 4 to 7; one a
    // letter made long words wider than their bubbles).
    constexpr int swear_symbols = 7;

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

    // The language whose text is being encoded (its font: conker_font_patch).
    int encoding_language = 1;

    // The font's letters (D_80085930): the original's accented capitals, less the ones a
    // language's own letters were drawn over (conker_font_patch), plus those.
    bool font_has(int language, uint32_t code) {
        switch (code) {
            case 0xC0: case 0xC2: case 0xC7: case 0xC9: case 0xC8: case 0xCA: case 0xCB:
            case 0xCE: case 0xD4: case 0xDB: case 0xD9: case 0xDC:
                return true;
            case 0xC4: case 0xD6: case 0xDF: case 0xCF: // Ä Ö ß Ï: drawn over by some
                return language != 1 && language != 2 && !(language == 5 && (code == 0xDF || code == 0xCF));
            case 0xC1: case 0xCD: case 0xD3: case 0xDA: return language == 1 || language == 2; // Á Í Ó Ú
            case 0xC3: case 0xD5: return language == 1;                                        // Ã Õ
            case 0xD1: case 0x81: case 0x82: return language == 2;                             // Ñ ¡ ¿
            case 0xCC: case 0xD2: return language == 5;                                        // Ì Ò
        }
        return false;
    }

    void put_char(std::string& out, uint32_t cp) {
        // Lowercase accented letters to their capitals (the font draws capitals).
        if ((cp >= 0xE0 && cp <= 0xFE && cp != 0xF7) && cp != 0xDF) cp -= 0x20;
        if (cp == 0xA1) cp = 0x81; // ¡ (0xA1 is the game's colour reset)
        if (cp == 0xBF) cp = 0x82; // ¿
        if (cp == 0x152 || cp == 0x153) { out += "oe"; return; } // œ
        if (cp == 0xC6) { out += "ae"; return; }                  // æ
        if (cp >= 0x80) {
            if (font_has(encoding_language, cp)) { out += (char)cp; return; }
            // Not in this language's font: the letter without its accent.
            static const char* const base = "AAAAAAACEEEEIIIIDNOOOOOxOUUUUYTs";
            if (cp >= 0xC0 && cp <= 0xDF) { out += (char)(base[cp - 0xC0] + ('a' - 'A') * (base[cp - 0xC0] >= 'A' && base[cp - 0xC0] <= 'Z')); return; }
            if (cp == 0x81) { out += '!'; return; }
            if (cp == 0x82) { out += '?'; return; }
            out += '?';
            return;
        }
        if (cp >= 'A' && cp <= 'Z') cp += 'a' - 'A'; // the dialogue is written in lowercase
        out += (char)cp;
    }

    // A swear word in the game's symbols: one per letter (swear_symbols a word at most), in one
    // colour, pulsing.
    void put_symbols(std::string& out, const std::string& word, uint32_t seed) {
        const uint8_t colour = 0xA2 + seed % 4;
        out += (char)code_pulse;
        int n = 0, in_word = 0;
        for (size_t i = 0; i < word.size(); i++) {
            const char c = word[i];
            if (c == ' ') { out += ' '; in_word = 0; continue; }
            // A swear across a line break keeps the break.
            if (c == '\\' && i + 1 < word.size() && word[i + 1] == 'n') { out += '\n'; in_word = 0; i++; continue; }
            if ((uint8_t)c >= 0x80 && ((uint8_t)c & 0xC0) == 0x80) continue; // UTF-8 continuation
            if (in_word >= swear_symbols) continue;
            out += (char)colour;
            out += (char)(0xB2 + (seed + n * 3) % 4);
            n++;
            in_word++;
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
        std::unordered_set<uint32_t> hints;               // the hint book's pages (assets1A)
    };
    // By conker::text_language(): 0 English (the game's; en.txt and en_ui.txt only change the
    // few lines the Vita words differently, its buttons), 1 Portuguese, 2 Spanish, 3 French,
    // 4 German, 5 Italian; files vita/translation/<name>.txt and <name>_ui.txt.
    constexpr int language_count = 6;
    const char* const language_files[language_count] = { "en", "pt_br", "es", "fr", "de", "it" };
    Language languages[language_count];

    void load(Language& lang, const char* name, bool ui) {
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
            bool hints = false; // in a _ui file, from a "# assets1A" comment to an "# assets1C" one
            while (std::fgets(line, sizeof line, f)) {
                size_t n = std::strlen(line);
                while (n && (line[n - 1] == '\n' || line[n - 1] == '\r')) line[--n] = 0;
                if (line[0] == '#') {
                    if (ui && std::strstr(line, "assets1A")) hints = true;
                    else if (ui && std::strstr(line, "assets1C")) hints = false;
                    continue;
                }
                // "<key> = <text>", or "<key> =" for a text left out (drawn as nothing).
                if (n < 10 || line[8] != ' ' || line[9] != '=' || (line[10] != ' ' && line[10] != 0)) continue;
                line[8] = 0;
                const uint32_t key = (uint32_t)std::strtoul(line, nullptr, 16);
                lang.pages[key] = line[10] ? line + 11 : "";
                if (hints) lang.hints.insert(key);
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
namespace {
    void load_all(Language& lang, int language) {
        const std::string name = language_files[language];
        load(lang, (name + ".txt").c_str(), false);
        lang.loaded = false;
        load(lang, (name + "_ui.txt").c_str(), true); // menus and hints
    }

    // A translation's game bytes in RDRAM past the game's 8 MB (kept while there's room).
    std::string fit_to_bubble(uint8_t* rdram, const std::string& text, int max_px, int max_h);

    // fit_h: a bubble's page, fitted to it (fit_to_bubble) with that much height at most.
    uint32_t place(uint8_t* rdram, uint32_t key, const std::string& line, bool censored, int fit_h = 0,
                   bool capital = false) {
        std::string text = encode(line.c_str(), censored, key);
        // A page the game wrote with a capital first (32 of them: Birdy's, the Professor's...)
        // is drawn from its second letter on unless the first is a capital too ("isso" showed
        // as "sso"): the translation's first letter is made one.
        if (capital) {
            for (char& c : text) {
                const uint8_t u = (uint8_t)c;
                if (u >= 'a' && u <= 'z') { c = (char)(u - ('a' - 'A')); break; }
                if (u >= 'A' && u <= 'Z') break;
                if (u >= 0xC0) break; // an accented letter: already a capital in the font
            }
        }
        if (fit_h > 0) text = fit_to_bubble(rdram, text, bubble_text_px, fit_h);
        const uint64_t slot = ((uint64_t)key << 4) | ((uint64_t)encoding_language << 1) | (censored ? 1 : 0);
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
        return dest;
    }
}

extern "C" int conker_translate_page(uint8_t* rdram, recomp_context* ctx) {
#if defined(__vita__)
    const int language = conker::text_language();
    const bool censored = conker::text_censored();
#else
    const int language = -1; // the game's own text
    const bool censored = true;
#endif
    if (language < 0 || language >= language_count) {
        return 0;
    }
    encoding_language = language;
    Language& lang = languages[language];
    if (!lang.loaded) {
        load_all(lang, language);
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
#if defined(__vita__)
    // Debug (ux0:data/conker/debug_text): each page asked for, its key, its kind and number, the
    // bytes before it and its first ones, and whether a translation answered (and its first bytes).
    static const bool text_log = [] {
        FILE* f = std::fopen("ux0:data/conker/debug_text", "r");
        if (f) std::fclose(f);
        return f != nullptr;
    }();
    if (text_log) {
        char before[40] = {}, first[40] = {};
        for (int i = -4; i < 0; i++) std::snprintf(before + std::strlen(before), 8, "%02X ", (uint8_t)MEM_B(i, s));
        for (size_t i = 0; i < 8 && i < n; i++) std::snprintf(first + std::strlen(first), 8, "%02X ", bytes[i]);
        std::fprintf(stderr, "[text] page key %08X kind %d page %d message %08X | before %s| first %s| %s\n",
            key, (int)kind, (int)page, (uint32_t)message, before, first, found == lang.pages.end() ? "untranslated" : "translated");
    }
#endif
    if (found == lang.pages.end()) {
        return 0;
    }

    const int fit_h = lang.hints.count(key) ? bubble_text_h_hint : bubble_text_h_dialogue;
    ctx->r2 = addr(place(rdram, key, found->second, censored, fit_h, bytes[0] >= 'A' && bytes[0] <= 'Z'));
    return 1;
}

// Menus, the start screens and the multiplayer's texts (vita/translation/pt_br_ui.txt, keyed by
// the CRC32 of the whole string as vita/tools/text_dump_ui.py lists them): func_15042D94 and its
// sibling format them (printf-like) through func_15042ECC, its format ($a0) and its arguments
// ($a1, a word each). This runs at its start: a translated format is put in its place, and so is
// each %s argument with a translation. The game's own strings are left as they are (cheat entry
// compares with them).
namespace {
    bool translate_string(uint8_t* rdram, Language& lang, bool censored, gpr s, uint32_t& out) {
        if ((uint32_t)s >> 24 != 0x80) return false;
        uint8_t bytes[max_page];
        size_t n = 0;
        while (n < max_page && (bytes[n] = (uint8_t)MEM_B(n, s)) != 0) n++;
        if (n == 0 || n == max_page) return false;
        const uint32_t key = crc32(bytes, n);
        auto found = lang.pages.find(key);
        if (found == lang.pages.end()) return false;
        out = place(rdram, key, found->second, censored);
        return true;
    }
}

extern "C" void conker_translate_ui(uint8_t* rdram, recomp_context* ctx) {
#if defined(__vita__)
    const int language = conker::text_language();
    const bool censored = conker::text_censored();
#else
    const int language = -1; // the game's own text
    const bool censored = true;
#endif
    if (language < 0 || language >= language_count) return;
    encoding_language = language;
    Language& lang = languages[language];
    if (!lang.loaded) load_all(lang, language);
    if (lang.pages.empty()) return;
    const gpr fmt = ctx->r4;
    if ((uint32_t)fmt >> 24 != 0x80) return;
    // The %s arguments first (from the game's format, which says where they are).
    int arg = 0;
    for (size_t i = 0; i < max_page; i++) {
        const uint8_t c = (uint8_t)MEM_B(i, fmt);
        if (c == 0) break;
        if (c != '%') continue;
        size_t j = i + 1;
        while (j < max_page) {
            const uint8_t d = (uint8_t)MEM_B(j, fmt);
            if (d == 0 || std::strchr("diouxXcspfeEgG%", d)) break;
            j++;
        }
        const uint8_t conv = (uint8_t)MEM_B(j, fmt);
        if (conv == 0) break;
        i = j;
        if (conv == '%') continue;
        if (conv == 'f' || conv == 'e' || conv == 'E' || conv == 'g' || conv == 'G') return; // doubles: not handled
        if (conv == 's' && arg < 16) {
            uint32_t to;
            if (translate_string(rdram, lang, censored, (gpr)MEM_W(arg * 4, ctx->r5), to)) {
                MEM_W(arg * 4, ctx->r5) = (int32_t)to;
            }
        }
        arg++;
    }
    uint32_t to;
    if (translate_string(rdram, lang, censored, fmt, to)) {
        ctx->r4 = addr(to);
    }
}

// The font's Portuguese capitals (Á Ã Í Ó Õ Ú, which it lacks): drawn into the glyphs of the
// German ones Portuguese never uses (Ä ä Ö ö ß Ï) in the font's own style, from its accented
// capitals (À Â Î Ô Û: their letters are squashed under the accent, lines 1-3 of 12) with the
// accent changed for É's acute or the ~ glyph's tilde, and the character table pointed at
// them (the codes put_char writes). Done when a glyph is first looked up (func_15042C40), and
// again if the font was loaded anew.
namespace {
    constexpr uint32_t font_chars = 0x80085930;     // D_80085930: a character per glyph (95)
    constexpr uint32_t font_textures = 0x80085990;  // per font: its glyphs, 224 bytes each (I8)
    constexpr uint32_t font_metrics = 0x80085994;   // per font: width, height, x and y offsets
    constexpr uint32_t glyph_bytes = 224;

    struct Glyph {
        uint8_t w = 0, h = 0, xoff = 0, yoff = 0;
        uint8_t px[14][16] = {};
    };

    // I8 rows of (w + 7) & ~7 bytes, odd rows with their 32-bit halves swapped (TMEM's order).
    Glyph read_glyph(uint8_t* rdram, uint32_t tex, uint32_t met, int g) {
        Glyph G;
        G.w = (uint8_t)MEM_B(g * 4 + 0, addr(met));
        G.h = (uint8_t)MEM_B(g * 4 + 1, addr(met));
        G.xoff = (uint8_t)MEM_B(g * 4 + 2, addr(met));
        G.yoff = (uint8_t)MEM_B(g * 4 + 3, addr(met));
        const uint32_t row = (G.w + 7u) & ~7u;
        for (int y = 0; y < G.h && y < 14; y++) {
            for (int x = 0; x < G.w && x < 16; x++) {
                const uint32_t i = ((uint32_t)y * row + (uint32_t)x) ^ ((y & 1) ? 4u : 0u);
                if (i < glyph_bytes) G.px[y][x] = (uint8_t)MEM_B(g * glyph_bytes + i, addr(tex));
            }
        }
        return G;
    }

    void write_glyph(uint8_t* rdram, uint32_t tex, uint32_t met, int g, const Glyph& G) {
        MEM_B(g * 4 + 0, addr(met)) = (int8_t)G.w;
        MEM_B(g * 4 + 1, addr(met)) = (int8_t)G.h;
        MEM_B(g * 4 + 2, addr(met)) = (int8_t)G.xoff;
        MEM_B(g * 4 + 3, addr(met)) = (int8_t)G.yoff;
        const uint32_t row = (G.w + 7u) & ~7u;
        for (uint32_t i = 0; i < glyph_bytes; i++) MEM_B(g * glyph_bytes + i, addr(tex)) = 0;
        for (int y = 0; y < G.h && y < 14; y++) {
            for (int x = 0; x < G.w && x < 16; x++) {
                const uint32_t i = ((uint32_t)y * row + (uint32_t)x) ^ ((y & 1) ? 4u : 0u);
                if (i < glyph_bytes) MEM_B(g * glyph_bytes + i, addr(tex)) = (int8_t)G.px[y][x];
            }
        }
    }

    // An accent: lines 1-3 of a glyph, cut to the columns it uses.
    struct Accent { int w = 0; uint8_t px[3][16] = {}; };
    Accent cut_accent(const Glyph& G) {
        Accent A;
        int lo = 16, hi = -1;
        for (int r = 1; r <= 3; r++) {
            for (int x = 0; x < G.w; x++) {
                if (G.px[r][x]) { lo = std::min(lo, x); hi = std::max(hi, x); }
            }
        }
        if (hi < lo) return A;
        A.w = hi - lo + 1;
        for (int r = 0; r < 3; r++) {
            for (int x = 0; x < A.w; x++) A.px[r][x] = G.px[r + 1][lo + x];
        }
        return A;
    }

    // An accented capital: lines 1-3 cleared and the accent put there, over the letter's middle.
    Glyph with_accent(Glyph G, const Accent& A) {
        int lo = 16, hi = -1;
        for (int r = 1; r <= 3; r++) for (int x = 0; x < 16; x++) G.px[r][x] = 0;
        for (int r = 4; r < G.h && r < 14; r++) {
            for (int x = 0; x < G.w; x++) {
                if (G.px[r][x]) { lo = std::min(lo, x); hi = std::max(hi, x); }
            }
        }
        if (hi < lo || A.w == 0) return G;
        const float centre = (lo + hi) * 0.5f;
        int left = (int)std::lround(centre - (A.w - 1) * 0.5f);
        left = std::max(0, std::min((int)G.w - A.w, left));
        for (int r = 0; r < 3; r++) {
            for (int x = 0; x < A.w; x++) {
                uint8_t& p = G.px[r + 1][left + x];
                p = std::max(p, A.px[r][x]);
            }
        }
        return G;
    }

    // Glyph indices in the character table.
    constexpr int g_n = 23, g_bang = 44, g_question = 55, g_a_grave = 70, g_a_circ = 72, g_e_acute = 76,
                  g_i_circ = 84, g_o_circ = 88, g_u_circ = 90;

    // A plain capital squashed into the accented ones' lines 4-11 (12 high), lines 1-3 left for
    // an accent, as the font's own accented capitals are.
    Glyph squashed(Glyph G) {
        int r0 = -1, r1 = -1;
        for (int r = 0; r < G.h && r < 14; r++) {
            for (int x = 0; x < G.w; x++) if (G.px[r][x]) { if (r0 < 0) r0 = r; r1 = r; break; }
        }
        Glyph out = G;
        out.h = 12;
        out.yoff = 0;
        for (auto& row : out.px) for (uint8_t& p : row) p = 0;
        if (r0 < 0) return out;
        const int n = r1 - r0 + 1;
        for (int t = 0; t < 8; t++) {
            const int a = r0 + t * n / 8, b = r0 + ((t + 1) * n - 1) / 8;
            for (int x = 0; x < G.w; x++) out.px[4 + t][x] = std::max(G.px[a][x], G.px[b][x]);
        }
        return out;
    }

    // Upside down (¿ from ?, ¡ from !).
    Glyph rotated(const Glyph& G) {
        Glyph out = G;
        for (int y = 0; y < G.h && y < 14; y++) {
            for (int x = 0; x < G.w; x++) out.px[y][x] = G.px[G.h - 1 - y][G.w - 1 - x];
        }
        return out;
    }

    enum class Make { Accent, Squash, Rotate };
    enum class Acc { Acute, Grave, Tilde, None };
    struct NewGlyph { int slot; uint8_t code; int base; Make make; Acc acc; };
    // Each language's letters, drawn over glyphs it never uses (Ä ä Ö ö ß Ï ï).
    constexpr NewGlyph portuguese[] = {
        { 63, 0xC1, g_a_grave, Make::Accent, Acc::Acute }, // Á
        { 64, 0xC3, g_a_circ, Make::Accent, Acc::Tilde },  // Ã
        { 65, 0xCD, g_i_circ, Make::Accent, Acc::Acute },  // Í
        { 66, 0xD3, g_o_circ, Make::Accent, Acc::Acute },  // Ó
        { 69, 0xD5, g_o_circ, Make::Accent, Acc::Tilde },  // Õ
        { 86, 0xDA, g_u_circ, Make::Accent, Acc::Acute },  // Ú
    };
    constexpr NewGlyph spanish[] = {
        { 63, 0xC1, g_a_grave, Make::Accent, Acc::Acute }, // Á
        { 64, 0xD1, g_n, Make::Squash, Acc::Tilde },       // Ñ
        { 65, 0xCD, g_i_circ, Make::Accent, Acc::Acute },  // Í
        { 66, 0xD3, g_o_circ, Make::Accent, Acc::Acute },  // Ó
        { 69, 0x82, g_question, Make::Rotate, Acc::None }, // ¿
        { 86, 0xDA, g_u_circ, Make::Accent, Acc::Acute },  // Ú
        { 87, 0x81, g_bang, Make::Rotate, Acc::None },     // ¡
    };
    constexpr NewGlyph italian[] = {
        { 69, 0xCC, g_i_circ, Make::Accent, Acc::Grave },  // Ì
        { 86, 0xD2, g_o_circ, Make::Accent, Acc::Grave },  // Ò
    };
    constexpr int touched_slots[] = { 63, 64, 65, 66, 69, 86, 87 };

    // The font as loaded, kept to put back when the language changes.
    struct FontBackup { bool taken = false; uint8_t chars[95]; Glyph glyphs[95]; };
    FontBackup original_font;
    int font_language = -1;      // whose letters the font has now (-1: as loaded)
    uint8_t font_marker = 0;     // the character table's slot 63 then (a reload changes it back)
}

extern "C" void conker_font_patch(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
#if defined(__vita__)
    const int language = conker::text_language();
#else
    const int language = 0;
#endif
    const uint8_t marker = (uint8_t)MEM_B(63, addr(font_chars));
    if (font_language >= 0 && marker != font_marker) font_language = -1; // loaded again: as the game has it
    if (language == font_language || (language == 0 && font_language < 0)) return;
    const uint32_t tex = (uint32_t)MEM_W(0, addr(font_textures));
    const uint32_t met = (uint32_t)MEM_W(0, addr(font_metrics));
    if ((tex >> 24) != 0x80 || (met >> 24) != 0x80) return;
    if (font_language < 0) {
        // As loaded: kept (again, if it was loaded anew).
        for (int i = 0; i < 95; i++) {
            original_font.chars[i] = (uint8_t)MEM_B(i, addr(font_chars));
            original_font.glyphs[i] = read_glyph(rdram, tex, met, i);
        }
        original_font.taken = true;
    }
    else {
        for (int slot : touched_slots) {
            write_glyph(rdram, tex, met, slot, original_font.glyphs[slot]);
            MEM_B(slot, addr(font_chars)) = (int8_t)original_font.chars[slot];
        }
    }
    const NewGlyph* set = nullptr;
    size_t count = 0;
    if (language == 1) { set = portuguese; count = std::size(portuguese); }
    else if (language == 2) { set = spanish; count = std::size(spanish); }
    else if (language == 5) { set = italian; count = std::size(italian); }
    if (count) {
        const Accent acute = cut_accent(original_font.glyphs[g_e_acute]);
        const Accent grave = cut_accent(original_font.glyphs[g_a_grave]);
        // The ~ glyph squashed to the accent's three lines was a flat bar: a wave of our own.
        Accent tilde;
        static const uint8_t wave[3][6] = {
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            { 0x30, 0xD0, 0xF0, 0x70, 0x30, 0xE0 },
            { 0xD0, 0x50, 0x30, 0xE0, 0xF0, 0x40 },
        };
        tilde.w = 6;
        for (int r = 0; r < 3; r++) for (int x = 0; x < 6; x++) tilde.px[r][x] = wave[r][x];
        for (size_t i = 0; i < count; i++) {
            const NewGlyph& n = set[i];
            const Glyph& base = original_font.glyphs[n.base];
            const Accent& acc = n.acc == Acc::Acute ? acute : n.acc == Acc::Grave ? grave : tilde;
            Glyph G;
            switch (n.make) {
                case Make::Accent:
                    G = with_accent(base, acc);
                    // Í: the font's I is a bare stroke, and squashed under an accent it read as ¡;
                    // a bar on top (as at its foot) makes it an I.
                    if (n.base == g_i_circ && G.h >= 12) {
                        for (int x = 0; x < G.w; x++) G.px[4][x] = G.px[11][x];
                    }
                    break;
                case Make::Squash: G = with_accent(squashed(base), acc); break;
                case Make::Rotate: G = rotated(base); break;
            }
            write_glyph(rdram, tex, met, n.slot, G);
            MEM_B(n.slot, addr(font_chars)) = (int8_t)n.code;
        }
    }
    font_language = language;
    font_marker = (uint8_t)MEM_B(63, addr(font_chars));
}

namespace {
    // A text's size as the game measures it, func_150428D4 (with the font as conker_font_patch
    // left it): a glyph advances its width + x offset - 1 and makes its line at least height +
    // y offset tall; a space 4, its line at least 12; colours nothing; a button icon or symbol
    // (0xA8 on, func_150415E0) its width times its scale; 0xBC skips itself and its argument;
    // a new line keeps the widest and adds the line's height (12 at least); the last line adds
    // its own (no minimum), an empty text is 12. False if the font isn't loaded.
    struct TextSize { int w = 0, h = 0; };

    // func_150415E0: a button icon's (or symbol's) width, height, baseline and scale.
    void icon_metrics(uint8_t c, int& w, int& h, float& baseline, float& scale) {
        scale = 1.0f;
        switch (c) {
            case 0xA8: case 0xA9: w = 32; h = 18; baseline = 3.1f; break;
            case 0xAA: case 0xAB: case 0xAC: case 0xAD: w = 32; h = 27; baseline = 2.0f; scale = 0.603f; break;
            case 0xAE: w = 16; h = 17; baseline = -1.6f; break;
            case 0xAF: case 0xB0: w = 46; h = 16; baseline = 2.0f; break;
            case 0xB6: case 0xB7: case 0xB8: case 0xB9: w = 16; h = 12; baseline = 2.0f; break;
            case 0xBA: w = 55; h = 12; baseline = 0.2f; break;
            case 0xB1: w = 38; h = 24; baseline = 2.0f; scale = 0.726f; break;
            default: w = 12; h = 16; baseline = 2.0f; break;
        }
    }

    // func_15042C40: the glyph of a character (0x60 a space, the byte itself if none).
    uint32_t glyph_of(uint8_t* rdram, uint8_t c) {
        const uint8_t u = (c >= 'a' && c <= 'z') ? (uint8_t)(c - 0x20) : c;
        if (c == ' ') return 0x60;
        for (uint32_t i = 0; i < 95; i++) {
            if ((uint8_t)MEM_B(i, addr(font_chars)) == u) return i;
        }
        return c;
    }

    bool measure_text(uint8_t* rdram, const std::string& s, TextSize& out) {
        const uint32_t met = (uint32_t)MEM_W(0, addr(font_metrics));
        if ((met >> 24) != 0x80) return false;
        int w = 0, h = 0, widest = 0, line_h = 0;
        if (s.empty()) h += 12;
        for (size_t i = 0; i < s.size(); i++) {
            const uint8_t c = (uint8_t)s[i];
            if (c == 0xBC) { i++; continue; }
            const uint32_t g = glyph_of(rdram, c);
            if (g == 0x60) {
                w += 4;
                line_h = std::max(line_h, 12);
            }
            else if (g >= 0xA1 && g < 0xA8) {
            }
            else if (g >= 0xA8) {
                int iw, ih;
                float baseline, scale;
                icon_metrics((uint8_t)g, iw, ih, baseline, scale);
                // Single-precision steps as the game's (volatile: no fused multiply-add).
                volatile float advance = (float)iw * scale;
                volatile float sum = (float)w + advance;
                w = (int)sum;
                volatile float scaled = (float)ih * scale;
                volatile float above = (float)(int)scaled - baseline;
                line_h = std::max(line_h, (int)above + 1);
            }
            else if (c == '\n') {
                widest = std::max(widest, w);
                w = 0;
                h += std::max(line_h, 12);
                line_h = 0;
            }
            else {
                // (A byte with no glyph reads past the 95 glyphs' metrics, as the game does.)
                w += (uint8_t)MEM_B(g * 4 + 0, addr(met)) + (uint8_t)MEM_B(g * 4 + 2, addr(met)) - 1;
                line_h = std::max(line_h, (int)(uint8_t)MEM_B(g * 4 + 1, addr(met)) + (uint8_t)MEM_B(g * 4 + 3, addr(met)));
            }
        }
        out.w = std::max(w, widest);
        out.h = h + line_h;
        return true;
    }

    std::vector<std::string> split(const std::string& s, char sep) {
        std::vector<std::string> out;
        size_t start = 0;
        while (true) {
            const size_t end = s.find(sep, start);
            if (end == std::string::npos) { out.push_back(s.substr(start)); return out; }
            out.push_back(s.substr(start, end - start));
            start = end + 1;
        }
    }

    std::string join(const std::vector<std::string>& parts, char sep) {
        std::string out;
        for (size_t i = 0; i < parts.size(); i++) {
            if (i) out += sep;
            out += parts[i];
        }
        return out;
    }

    bool line_fits(uint8_t* rdram, const std::string& line, int max_px) {
        TextSize size;
        return line.size() <= bubble_line_bytes && measure_text(rdram, line, size) && size.w <= max_px;
    }

    // A page's lines that don't fit (wider than max_px, or longer than the line buffer) broken
    // at spaces, before the word that would cross: its leading spaces stay on its first part,
    // the space at a break goes. A word too wide alone stays as it is.
    std::string wrap_lines(uint8_t* rdram, const std::string& text, int max_px) {
        std::vector<std::string> out;
        for (const std::string& line : split(text, '\n')) {
            if (line_fits(rdram, line, max_px)) {
                out.push_back(line);
                continue;
            }
            size_t lead = 0;
            while (lead < line.size() && line[lead] == ' ') lead++;
            std::string cur = line.substr(0, lead);
            bool first = true;
            for (const std::string& word : split(line.substr(lead), ' ')) {
                if (!first && !line_fits(rdram, cur + ' ' + word, max_px)) {
                    out.push_back(cur);
                    cur.clear();
                    first = true;
                }
                cur += first ? word : ' ' + word;
                first = false;
            }
            out.push_back(cur);
        }
        return join(out, '\n');
    }

    // A translated page fitted to its bubble (vita/tools/check_bubbles.py checks the result):
    // its lines wrapped at max_px; if it's still taller than max_h, it's flowed again as one
    // paragraph (its lines joined, their outer spaces and the empty ones dropped), kept if that
    // makes it shorter. The bubble grows to the page (func_1516A7B0), so a page within the
    // limits is a bubble within the view.
    std::string fit_to_bubble(uint8_t* rdram, const std::string& text, int max_px, int max_h) {
        conker_font_patch(rdram, nullptr); // the language's letters, as the page will be drawn
        TextSize size;
        if (!measure_text(rdram, text, size)) return text;
        const std::string page = wrap_lines(rdram, text, max_px);
        measure_text(rdram, page, size);
        if (size.h <= max_h) return page;
        std::vector<std::string> words;
        for (const std::string& line : split(text, '\n')) {
            const size_t a = line.find_first_not_of(' ');
            if (a == std::string::npos) continue;
            words.push_back(line.substr(a, line.find_last_not_of(' ') - a + 1));
        }
        const std::string flowed = wrap_lines(rdram, join(words, ' '), max_px);
        TextSize flowed_size;
        measure_text(rdram, flowed, flowed_size);
        return flowed_size.h < size.h ? flowed : page;
    }
}
