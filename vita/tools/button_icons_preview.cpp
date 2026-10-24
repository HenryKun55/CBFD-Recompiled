// Draws every Vita button picture (vita/src/button_art.cpp) at the sizes of the N64 icons it
// replaces, onto a sheet (PPM), to look at them without the Vita:
//   c++ -std=c++17 -O2 -Ivita/src vita/tools/button_icons_preview.cpp vita/src/button_art.cpp -o /tmp/bp
//   /tmp/bp sheet.ppm [scale]
//   /tmp/bp --pads out.ppm scale <dir of debug_dump_icons dumps>  (every pad carved for every input)
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

#include "button_art.hpp"

using namespace conker::vita::button_art;

// The pads' carvings: every pad in button_art's pad_textures (read from the textures dumped by
// debug_dump_icons in dir: colour above, alpha below), as found and then carved for each Vita
// input B can be bound to (button_icons.cpp's picture()), in a row; below each, the same
// foreshortened (as on the ground, seen at an angle). The columns' inputs are printed.
struct PadInput { Art art; int dir; const char* name; };
static const PadInput pad_inputs[] = {
    { Art::Cross, 0, "Cross" }, { Art::Circle, 0, "Circle" }, { Art::Square, 0, "Square" }, { Art::Triangle, 0, "Triangle" },
    { Art::L, 0, "L" }, { Art::R, 0, "R" }, { Art::DPad, DirUp, "Up" }, { Art::DPad, DirDown, "Down" },
    { Art::DPad, DirLeft, "Left" }, { Art::DPad, DirRight, "Right" }, { Art::Start, 0, "Start" }, { Art::Select, 0, "Select" },
    { Art::L1, 0, "L1" }, { Art::R1, 0, "R1" }, { Art::L3, 0, "L3" }, { Art::R3, 0, "R3" },
    { Art::LStick, DirUp, "LS Up" }, { Art::LStick, DirDown, "LS Down" }, { Art::LStick, DirLeft, "LS Left" }, { Art::LStick, DirRight, "LS Right" },
    { Art::RStick, DirUp, "RS Up" }, { Art::RStick, DirDown, "RS Down" }, { Art::RStick, DirLeft, "RS Left" }, { Art::RStick, DirRight, "RS Right" },
    { Art::RearTouch, 1, "Rear TL" }, { Art::RearTouch, 2, "Rear TR" }, { Art::RearTouch, 3, "Rear BL" }, { Art::RearTouch, 4, "Rear BR" },
    { Art::FrontTouch, 1, "Front TL" }, { Art::FrontTouch, 2, "Front TR" }, { Art::FrontTouch, 3, "Front BL" }, { Art::FrontTouch, 4, "Front BR" },
};

static bool read_ppm(const char* in, int& w, int& h, std::vector<uint32_t>& px) {
    FILE* f = std::fopen(in, "rb");
    if (!f) return false;
    int h2, maxv;
    if (std::fscanf(f, "P6 %d %d %d", &w, &h2, &maxv) != 3) { std::fclose(f); return false; }
    std::fgetc(f);
    h = h2 / 2;
    std::vector<unsigned char> raw((size_t)w * h2 * 3);
    const bool ok = std::fread(raw.data(), 1, raw.size(), f) == raw.size();
    std::fclose(f);
    if (!ok) return false;
    px.resize((size_t)w * h);
    for (int i = 0; i < w * h; i++) {
        px[i] = raw[i * 3] | (raw[i * 3 + 1] << 8) | (raw[i * 3 + 2] << 16) | ((uint32_t)raw[(w * h + i) * 3] << 24);
    }
    return true;
}

// Bilinear sample (wrapping), alpha-blended over a grey ground.
static void sample(const std::vector<uint32_t>& px, int w, int h, float u, float v, unsigned char* o) {
    u -= 0.5f; v -= 0.5f;
    const int x0 = (int)std::floor(u), y0 = (int)std::floor(v);
    const float fx = u - x0, fy = v - y0;
    float acc[4] = {};
    for (int k = 0; k < 4; k++) {
        const int x = ((x0 + (k & 1)) % w + w) % w, y = ((y0 + (k >> 1)) % h + h) % h;
        const float wt = ((k & 1) ? fx : 1 - fx) * ((k >> 1) ? fy : 1 - fy);
        const uint32_t p = px[(size_t)y * w + x];
        for (int c = 0; c < 4; c++) acc[c] += wt * ((p >> (8 * c)) & 255);
    }
    const float a = acc[3] / 255.0f;
    const float ground[3] = { 70, 95, 50 };
    for (int c = 0; c < 3; c++) o[c] = (unsigned char)std::lround(acc[c] * a + ground[c] * (1 - a));
}

static int pads(const char* out, int scale, const char* dir) {
    // The pads, each put together from its pieces (consecutive in pad_textures).
    struct Piece { const PadTexture* tex; std::vector<uint32_t> px; };
    struct Pad { int w, h; std::vector<Piece> pieces; };
    std::vector<Pad> list;
    int covered = 0;
    for (int i = 0; i < pad_texture_count; i++) {
        const PadTexture& t = pad_textures[i];
        if (list.empty() || covered >= list.back().w * list.back().h) {
            list.push_back({ t.piece.pad_w, t.piece.pad_h, {} });
            covered = 0;
        }
        char path[512];
        std::snprintf(path, sizeof(path), "%s/%08X_%dx%d.ppm", dir, t.hash, t.w, t.h);
        Piece pc{ &t, {} };
        int w, h;
        if (!read_ppm(path, w, h, pc.px) || w != t.w || h != t.h) { std::fprintf(stderr, "can't read %s\n", path); return 1; }
        list.back().pieces.push_back(std::move(pc));
        covered += t.w * t.h;
    }
    const int cols = 1 + (int)(sizeof(pad_inputs) / sizeof(pad_inputs[0]));
    const int cell = 64 * scale + 8, flat = 64 * scale / 2 + 8;
    const int W = cols * cell, H = (int)list.size() * (cell + flat);
    std::vector<unsigned char> img((size_t)W * H * 3, 40);
    for (size_t r = 0; r < list.size(); r++) {
        const Pad& pd = list[r];
        for (int c = 0; c < cols; c++) {
            std::vector<uint32_t> px((size_t)pd.w * pd.h);
            for (const Piece& pc : pd.pieces) {
                std::vector<uint32_t> t = pc.px;
                const PadPiece& pp = pc.tex->piece;
                if (c > 0 && !carve_pad(t.data(), pc.tex->w, pc.tex->h, pp, pad_inputs[c - 1].art, pad_inputs[c - 1].dir)) {
                    std::fprintf(stderr, "%08X: %s not carved\n", pc.tex->hash, pad_inputs[c - 1].name);
                }
                for (int y = 0; y < pc.tex->h; y++)
                    for (int x = 0; x < pc.tex->w; x++) px[(size_t)(pp.y + y) * pd.w + pp.x + x] = t[(size_t)y * pc.tex->w + x];
            }
            const int s = 64 * scale / std::max(pd.w, pd.h);
            const int oy = (int)r * (cell + flat) + 4;
            for (int y = 0; y < pd.h * s; y++) {
                for (int x = 0; x < pd.w * s; x++) {
                    sample(px, pd.w, pd.h, (x + 0.5f) / s, (y + 0.5f) / s, &img[((size_t)(oy + y) * W + c * cell + 4 + x) * 3]);
                }
            }
            // Foreshortened: half the height, bilinear from the texture (the ground seen at ~30 degrees).
            for (int y = 0; y < pd.h * s / 2; y++) {
                for (int x = 0; x < pd.w * s; x++) {
                    sample(px, pd.w, pd.h, (x + 0.5f) / s, (y + 0.5f) * 2.0f / s, &img[((size_t)(oy + cell - 4 + y) * W + c * cell + 4 + x) * 3]);
                }
            }
        }
    }
    FILE* f = std::fopen(out, "wb");
    if (!f) return 1;
    std::fprintf(f, "P6\n%d %d\n255\n", W, H);
    std::fwrite(img.data(), 1, img.size(), f);
    std::fclose(f);
    for (int c = 1; c < cols; c++) std::printf("%s\n", pad_inputs[c - 1].name);
    return 0;
}

int main(int argc, char** argv) {
    if (argc > 4 && std::string(argv[1]) == "--pads") return pads(argv[2], std::atoi(argv[3]), argv[4]);
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
