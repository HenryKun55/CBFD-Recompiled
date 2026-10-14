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

    // The font's letters (D_80085930) for Portuguese (the ones it lacks: conker_font_patch).
    void put_char(std::string& out, uint32_t cp) {
        switch (cp) {
            case 0xE1: case 0xC1: out += '\xC1'; return; // á (conker_font_patch's glyph)
            case 0xE0: case 0xC0: out += '\xC0'; return; // à
            case 0xE2: case 0xC2: out += '\xC2'; return; // â
            case 0xE3: case 0xC3: out += '\xC3'; return; // ã (conker_font_patch's)
            case 0xE7: case 0xC7: out += '\xC7'; return; // ç
            case 0xE9: case 0xC9: out += '\xC9'; return; // é
            case 0xEA: case 0xCA: out += '\xCA'; return; // ê
            case 0xED: case 0xCD: out += '\xCD'; return; // í (conker_font_patch's)
            case 0xF3: case 0xD3: out += '\xD3'; return; // ó (conker_font_patch's)
            case 0xF4: case 0xD4: out += '\xD4'; return; // ô
            case 0xF5: case 0xD5: out += '\xD5'; return; // õ (conker_font_patch's)
            case 0xFA: case 0xDA: out += '\xDA'; return; // ú (conker_font_patch's)
            case 0xFC: case 0xDC: out += '\xDC'; return; // ü
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
namespace {
    void load_all(Language& lang) {
        load(lang, "pt_br.txt");
        lang.loaded = false;
        load(lang, "pt_br_ui.txt"); // menus and hints
    }

    // A translation's game bytes in RDRAM past the game's 8 MB (kept while there's room).
    uint32_t place(uint8_t* rdram, uint32_t key, const std::string& line, bool censored) {
        const std::string text = encode(line.c_str(), censored, key);
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
        return dest;
    }
}

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
        load_all(lang);
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

    ctx->r2 = addr(place(rdram, key, found->second, censored));
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
    const int language = 0;
    const bool censored = true;
#endif
    if (language <= 0 || language > 1) return;
    Language& lang = languages[language];
    if (!lang.loaded) load_all(lang);
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
    constexpr int g_a_grave = 70, g_a_circ = 72, g_e_acute = 76, g_i_circ = 84, g_o_circ = 88, g_u_circ = 90;
    struct NewGlyph { int slot; uint8_t code; int base; bool tilde; };
    constexpr NewGlyph new_glyphs[] = {
        { 63, 0xC1, g_a_grave, false }, // Á (in Ä's place)
        { 64, 0xC3, g_a_circ, true },   // Ã (ä)
        { 65, 0xCD, g_i_circ, false },  // Í (Ö)
        { 66, 0xD3, g_o_circ, false },  // Ó (ö)
        { 69, 0xD5, g_o_circ, true },   // Õ (ß)
        { 86, 0xDA, g_u_circ, false },  // Ú (Ï)
    };
}

extern "C" void conker_font_patch(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    // Done already (and the font not loaded again): the table points at the new glyphs.
    if ((uint8_t)MEM_B(new_glyphs[0].slot, addr(font_chars)) == new_glyphs[0].code) return;
    const uint32_t tex = (uint32_t)MEM_W(0, addr(font_textures));
    const uint32_t met = (uint32_t)MEM_W(0, addr(font_metrics));
    if ((tex >> 24) != 0x80 || (met >> 24) != 0x80) return;
    const Accent acute = cut_accent(read_glyph(rdram, tex, met, g_e_acute));
    // The ~ glyph squashed to the accent's three lines was a flat bar: a wave of our own.
    Accent tilde;
    {
        static const uint8_t wave[3][6] = {
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            { 0x30, 0xD0, 0xF0, 0x70, 0x30, 0xE0 },
            { 0xD0, 0x50, 0x30, 0xE0, 0xF0, 0x40 },
        };
        tilde.w = 6;
        for (int r = 0; r < 3; r++) for (int x = 0; x < 6; x++) tilde.px[r][x] = wave[r][x];
    }
    if (acute.w == 0 || tilde.w == 0) return;
    for (const NewGlyph& n : new_glyphs) {
        const Glyph G = with_accent(read_glyph(rdram, tex, met, n.base), n.tilde ? tilde : acute);
        write_glyph(rdram, tex, met, n.slot, G);
        MEM_B(n.slot, addr(font_chars)) = (int8_t)n.code;
    }
}
