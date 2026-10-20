// Runs host/src/text_translation.cpp's page fitting on the host, for vita/tools/check_bubbles.py
// --cxx (which builds it next to a copy of text_translation.cpp and a stub conker.hpp): a fake
// RDRAM gets the game's font (character table and metrics, from the check's model), then each
// line of stdin, "<language> <censored> <key> <capital> <hint> <text>", is put through place()
// as conker_translate_page does, and the page it wrote is printed in hex, one a line.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "conker.hpp"

namespace harness {
    int language = 0;
    bool censored = false;
}

namespace conker {
    int text_language() { return harness::language; }
    bool text_censored() { return harness::censored; }
}

#include "text_translation.cpp"

int main(int argc, char** argv) {
    // argv[1]: the 95 character codes, argv[2]: the 95 glyphs' metrics (w,h,x,y each), in hex.
    if (argc < 3) return 2;
    std::vector<uint8_t> memory(0x1000000);
    uint8_t* rdram = memory.data();
    constexpr uint32_t tex = 0x800C68B0, met = 0x800CBBD0;
    MEM_W(0, addr(font_textures)) = (int32_t)tex;
    MEM_W(0, addr(font_metrics)) = (int32_t)met;
    auto hex = [](const char* s, size_t i) { char b[3] = { s[i * 2], s[i * 2 + 1], 0 }; return (uint8_t)std::strtoul(b, nullptr, 16); };
    for (size_t i = 0; i < 95; i++) MEM_B(i, addr(font_chars)) = (int8_t)hex(argv[1], i);
    for (size_t i = 0; i < 95 * 4; i++) MEM_B(i, addr(met)) = (int8_t)hex(argv[2], i);

    std::string line;
    while (std::getline(std::cin, line)) {
        int language, censored, capital, hint;
        unsigned key;
        int used = 0;
        if (std::sscanf(line.c_str(), "%d %d %x %d %d%n", &language, &censored, &key, &capital, &hint, &used) < 5) return 3;
        used++; // the space before the text (which may start with spaces)
        harness::language = language;
        encoding_language = language;
        const uint32_t at = place(rdram, key, line.substr(used), censored != 0,
                                  hint ? bubble_text_h_hint : bubble_text_h_dialogue, capital != 0);
        for (uint32_t i = 0;; i++) {
            const uint8_t c = (uint8_t)MEM_B(i, addr(at));
            if (!c) break;
            std::printf("%02x", c);
        }
        std::printf("\n");
    }
    return 0;
}
