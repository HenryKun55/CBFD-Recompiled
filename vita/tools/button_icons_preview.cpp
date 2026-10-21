// Draws every Vita button picture (vita/src/button_art.cpp) at the sizes of the N64 icons it
// replaces, onto a sheet (PPM), to look at them without the Vita:
//   c++ -std=c++17 -O2 -Ivita/src vita/tools/button_icons_preview.cpp vita/src/button_art.cpp -o /tmp/bp
//   /tmp/bp sheet.ppm [scale]
//   /tmp/bp --pad pad.ppm out.ppm   (a B-pad texture dumped by debug_dump_icons, carved 4 ways)
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include "button_art.hpp"

using namespace conker::vita::button_art;

static int pad(const char* in, const char* out) {
    FILE* f = std::fopen(in, "rb");
    if (!f) return 1;
    int w, h2, maxv;
    if (std::fscanf(f, "P6 %d %d %d", &w, &h2, &maxv) != 3) return 1;
    std::fgetc(f);
    const int h = h2 / 2;
    std::vector<unsigned char> raw((size_t)w * h2 * 3);
    if (std::fread(raw.data(), 1, raw.size(), f) != raw.size()) return 1;
    std::fclose(f);
    std::vector<uint32_t> src((size_t)w * h);
    for (int i = 0; i < w * h; i++) {
        src[i] = raw[i * 3] | (raw[i * 3 + 1] << 8) | (raw[i * 3 + 2] << 16) | ((uint32_t)raw[(w * h + i) * 3] << 24);
    }
    const Art arts[] = { Art::Cross, Art::Circle, Art::Square, Art::Triangle };
    const int s = 4, W = w * 5 * s, H = h * s;
    std::vector<unsigned char> img((size_t)W * H * 3);
    for (int k = 0; k < 5; k++) {
        std::vector<uint32_t> px = src;
        if (k > 0) carve_pad(px.data(), w, h, arts[k - 1]);
        for (int y = 0; y < H; y++)
            for (int x = 0; x < w * s; x++)
                for (int c = 0; c < 3; c++) img[((size_t)y * W + k * w * s + x) * 3 + c] = (px[(y / s) * w + x / s] >> (8 * c)) & 255;
    }
    f = std::fopen(out, "wb");
    if (!f) return 1;
    std::fprintf(f, "P6\n%d %d\n255\n", W, H);
    std::fwrite(img.data(), 1, img.size(), f);
    std::fclose(f);
    return 0;
}

int main(int argc, char** argv) {
    if (argc > 3 && std::string(argv[1]) == "--pad") return pad(argv[2], argv[3]);
    if (argc < 2) return 1;
    const int scale = argc > 2 ? std::atoi(argv[2]) : 4;
    struct Slot { int w, h; Box box; };
    // A/B, the C-buttons and the stick, Z, L/R (the originals' own outlines).
    const Slot slots[] = { { 32, 32, { 4, 6, 28, 26 } }, { 32, 32, { 1, 1, 31, 31 } }, { 16, 32, { 0, 1, 16, 32 } }, { 32, 16, { 2, 1, 30, 15 } } };
    struct Item { Art art; int dir; };
    const Item items[] = {
        { Art::Cross, 0 }, { Art::Circle, 0 }, { Art::Square, 0 }, { Art::Triangle, 0 },
        { Art::L, 0 }, { Art::R, 0 }, { Art::L1, 0 }, { Art::Start, 0 }, { Art::Select, 0 },
        { Art::DPad, DirUp }, { Art::DPad, DirLeft }, { Art::LStick, 0 }, { Art::RStick, DirLeft }, { Art::RStick, DirDown },
        { Art::L3, 0 }, { Art::RearTouch, 3 }, { Art::FrontTouch, 2 },
    };
    const int cols = sizeof(items) / sizeof(items[0]), rows = sizeof(slots) / sizeof(slots[0]);
    const int cell = 34 * scale;
    const int W = cols * cell, H = rows * cell;
    std::vector<unsigned char> img((size_t)W * H * 3);
    for (int i = 0; i < W * H; i++) { img[i * 3] = 150; img[i * 3 + 1] = 120; img[i * 3 + 2] = 90; }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            const Slot& s = slots[r];
            std::vector<uint32_t> px((size_t)s.w * s.h);
            draw(px.data(), s.w, s.h, s.box, items[c].art, items[c].dir, 0.0f);
            for (int y = 0; y < s.h * scale; y++) {
                for (int x = 0; x < s.w * scale; x++) {
                    const uint32_t p = px[(y / scale) * s.w + x / scale];
                    const float a = (p >> 24) / 255.0f;
                    unsigned char* o = &img[(((size_t)(r * cell + y + scale)) * W + c * cell + x + scale) * 3];
                    for (int k = 0; k < 3; k++) o[k] = (unsigned char)(((p >> (8 * k)) & 255) * a + o[k] * (1 - a));
                }
            }
        }
    }
    FILE* f = std::fopen(argv[1], "wb");
    if (!f) return 1;
    std::fprintf(f, "P6\n%d %d\n255\n", W, H);
    std::fwrite(img.data(), 1, img.size(), f);
    std::fclose(f);
    return 0;
}
