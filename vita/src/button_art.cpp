// Vita button pictures drawn in code (see button_art.hpp): shapes as signed distances
// (anti-aliased by their coverage of each texel), letters from two small pixel fonts.

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

#include "button_art.hpp"

namespace conker::vita::button_art {
    namespace {
        struct V { float x, y; };
        V operator+(V a, V b) { return { a.x + b.x, a.y + b.y }; }
        V operator-(V a, V b) { return { a.x - b.x, a.y - b.y }; }
        V operator*(V a, float s) { return { a.x * s, a.y * s }; }
        float dot(V a, V b) { return a.x * b.x + a.y * b.y; }
        float len(V a) { return std::sqrt(dot(a, a)); }

        struct Rgb { float r, g, b; };
        Rgb mix(Rgb a, Rgb b, float t) { return { a.r + (b.r - a.r) * t, a.g + (b.g - a.g) * t, a.b + (b.b - a.b) * t }; }

        // Signed distances (negative inside), in texels.
        float sd_circle(V p, V c, float r) { return len(p - c) - r; }
        float sd_box(V p, V c, V half, float radius) {
            const float qx = std::fabs(p.x - c.x) - (half.x - radius), qy = std::fabs(p.y - c.y) - (half.y - radius);
            const float ox = std::max(qx, 0.0f), oy = std::max(qy, 0.0f);
            return std::sqrt(ox * ox + oy * oy) + std::min(std::max(qx, qy), 0.0f) - radius;
        }
        float sd_segment(V p, V a, V b, float width) {
            const V pa = p - a, ba = b - a;
            const float h = std::clamp(dot(pa, ba) / dot(ba, ba), 0.0f, 1.0f);
            return len(pa - ba * h) - width * 0.5f;
        }
        // A convex polygon, its corners in either order.
        float sd_polygon(V p, const V* v, int n) {
            float d = 1e9f;
            int inside_sign = 0;
            bool inside = true;
            for (int i = 0; i < n; i++) {
                const V a = v[i], b = v[(i + 1) % n];
                d = std::min(d, sd_segment(p, a, b, 0.0f));
                const float cross = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
                const int s = cross > 0 ? 1 : -1;
                if (inside_sign == 0) inside_sign = s;
                else if (s != inside_sign) inside = false;
            }
            return inside ? -d : d;
        }

        struct Canvas {
            int w, h;
            std::vector<float> r, g, b, a;
            Canvas(int w_, int h_) : w(w_), h(h_), r(w_ * h_), g(w_ * h_), b(w_ * h_), a(w_ * h_) {}

            // Paints where sd < 0 (coverage-weighted), colour by position, over what's there.
            template <typename Sd, typename Col>
            void paint(Sd sd, Col col, float alpha = 1.0f) {
                for (int y = 0; y < h; y++) {
                    for (int x = 0; x < w; x++) {
                        const V p{ x + 0.5f, y + 0.5f };
                        const float cov = std::clamp(0.5f - sd(p), 0.0f, 1.0f) * alpha;
                        if (cov <= 0.0f) continue;
                        const Rgb c = col(p);
                        const int i = y * w + x;
                        const float out_a = cov + a[i] * (1.0f - cov);
                        r[i] = (c.r * cov + r[i] * a[i] * (1.0f - cov)) / out_a;
                        g[i] = (c.g * cov + g[i] * a[i] * (1.0f - cov)) / out_a;
                        b[i] = (c.b * cov + b[i] * a[i] * (1.0f - cov)) / out_a;
                        a[i] = out_a;
                    }
                }
            }
            template <typename Sd>
            void fill(Sd sd, Rgb c, float alpha = 1.0f) { paint(sd, [c](V) { return c; }, alpha); }

            void pixel(int x, int y, Rgb c) {
                if (x < 0 || y < 0 || x >= w || y >= h) return;
                const int i = y * w + x;
                r[i] = c.r; g[i] = c.g; b[i] = c.b; a[i] = 1.0f;
            }

            void store(uint32_t* px) const {
                for (int i = 0; i < w * h; i++) {
                    auto u8 = [](float v) { return (uint32_t)std::clamp((int)std::lround(v), 0, 255); };
                    // Clear texels keep a dark colour: bilinear filtering blends them into the edges.
                    const uint32_t alpha = u8(a[i] * 255.0f);
                    px[i] = alpha == 0 ? 0x00141418u : (alpha << 24) | (u8(b[i]) << 16) | (u8(g[i]) << 8) | u8(r[i]);
                }
            }
        };

        // Pixel fonts: rows top down, the leftmost column the highest bit.
        struct Glyph { char c; uint8_t rows[7]; };
        constexpr Glyph small_font[] = { // 3 x 5
            { 'A', { 2, 5, 7, 5, 5 } }, { 'B', { 6, 5, 6, 5, 6 } }, { 'C', { 3, 4, 4, 4, 3 } },
            { 'E', { 7, 4, 6, 4, 7 } }, { 'F', { 7, 4, 6, 4, 4 } }, { 'K', { 5, 5, 6, 5, 5 } },
            { 'L', { 4, 4, 4, 4, 7 } }, { 'N', { 5, 7, 7, 5, 5 } }, { 'O', { 2, 5, 5, 5, 2 } },
            { 'R', { 6, 5, 6, 5, 5 } }, { 'S', { 3, 4, 2, 1, 6 } }, { 'T', { 7, 2, 2, 2, 2 } },
            { '1', { 2, 6, 2, 2, 7 } }, { '2', { 6, 1, 2, 4, 7 } }, { '3', { 6, 1, 2, 1, 6 } },
        };
        constexpr Glyph big_font[] = { // 5 x 7
            { 'L', { 16, 16, 16, 16, 16, 16, 31 } }, { 'R', { 30, 17, 17, 30, 20, 18, 17 } },
            { '1', { 4, 12, 4, 4, 4, 4, 14 } }, { '2', { 14, 17, 1, 2, 4, 8, 31 } },
            { '3', { 30, 1, 1, 14, 1, 1, 30 } },
        };
        struct Font { const Glyph* glyphs; int count, w, h; };
        constexpr Font small{ small_font, (int)(sizeof(small_font) / sizeof(Glyph)), 3, 5 };
        constexpr Font big{ big_font, (int)(sizeof(big_font) / sizeof(Glyph)), 5, 7 };

        bool font_has(const Font& f, const char* s) {
            for (; *s; s++) {
                bool found = false;
                for (int i = 0; i < f.count; i++) found |= f.glyphs[i].c == *s;
                if (!found) return false;
            }
            return true;
        }
        int text_width(const Font& f, const char* s) {
            const int n = (int)std::strlen(s);
            return n ? n * (f.w + 1) - 1 : 0;
        }
        // Centred on c, on whole texels (crisp).
        void text(Canvas& cv, const Font& f, const char* s, V c, Rgb col) {
            int x = (int)std::floor(c.x - text_width(f, s) * 0.5f + 0.5f);
            const int y = (int)std::floor(c.y - f.h * 0.5f + 0.5f);
            for (; *s; s++, x += f.w + 1) {
                for (int i = 0; i < f.count; i++) {
                    if (f.glyphs[i].c != *s) continue;
                    for (int row = 0; row < f.h; row++) {
                        for (int col_i = 0; col_i < f.w; col_i++) {
                            if (f.glyphs[i].rows[row] & (1 << (f.w - 1 - col_i))) cv.pixel(x + col_i, y + row, col);
                        }
                    }
                }
            }
        }
        // The first label (and the biggest font) that fits in w x h.
        void label(Canvas& cv, const char* const* labels, int count, V c, float w, float h, Rgb col) {
            for (const Font* f : { &big, &small }) {
                for (int i = 0; i < count; i++) {
                    if (font_has(*f, labels[i]) && text_width(*f, labels[i]) <= w && f->h <= h) {
                        text(cv, *f, labels[i], c, col);
                        return;
                    }
                }
            }
        }

        uint32_t blend(uint32_t a, uint32_t b, float t) {
            uint32_t out = 0;
            for (int k = 0; k < 4; k++) {
                const float va = (float)((a >> (8 * k)) & 255), vb = (float)((b >> (8 * k)) & 255);
                out |= (uint32_t)std::lround(va + (vb - va) * t) << (8 * k);
            }
            return out;
        }

        constexpr Rgb rim{ 20, 20, 24 };
        constexpr Rgb body_top{ 86, 86, 96 }, body_bottom{ 38, 38, 44 };
        constexpr Rgb white{ 242, 242, 246 };

        V dir_vector(int dir) {
            switch (dir) {
                case DirUp: return { 0, -1 };
                case DirDown: return { 0, 1 };
                case DirLeft: return { -1, 0 };
                case DirRight: return { 1, 0 };
            }
            return { 0, 0 };
        }

        // A triangle pointing along d, its tip at tip, size long.
        void arrow(Canvas& cv, V tip, V d, float size, Rgb col, bool outline) {
            const V n{ -d.y, d.x };
            const V base = tip - d * size;
            const V tri[3] = { tip, base + n * (size * 0.8f), base - n * (size * 0.8f) };
            if (outline) cv.fill([&](V p) { return sd_polygon(p, tri, 3) - 0.9f; }, rim);
            cv.fill([&](V p) { return sd_polygon(p, tri, 3); }, col);
        }

        void face_button(Canvas& cv, V c, float d, Art art) {
            const float r = d * 0.5f;
            cv.fill([&](V p) { return sd_circle(p, c, r); }, rim);
            cv.paint([&](V p) { return sd_circle(p, c, r - 1.0f); },
                [&](V p) { return mix(body_top, body_bottom, std::clamp((p.y - (c.y - r)) / d, 0.0f, 1.0f)); });
            const float t = std::max(1.5f, d * 0.11f);
            const float s = d * 0.24f;
            switch (art) {
                case Art::Cross: {
                    const Rgb col{ 125, 175, 240 };
                    cv.fill([&](V p) {
                        return std::min(sd_segment(p, c + V{ -s, -s }, c + V{ s, s }, t), sd_segment(p, c + V{ s, -s }, c + V{ -s, s }, t));
                    }, col);
                    break;
                }
                case Art::Circle: {
                    const Rgb col{ 245, 95, 105 };
                    cv.fill([&](V p) { return std::fabs(sd_circle(p, c, s * 1.05f)) - t * 0.5f; }, col);
                    break;
                }
                case Art::Square: {
                    const Rgb col{ 235, 145, 215 };
                    cv.fill([&](V p) { return std::fabs(sd_box(p, c, { s * 0.95f, s * 0.95f }, 0.6f)) - t * 0.5f; }, col);
                    break;
                }
                default: { // Triangle
                    const Rgb col{ 70, 215, 175 };
                    const float R = s * 1.2f;
                    const V k = c + V{ 0, R * 0.12f };
                    const V tri[3] = { k + V{ 0, -R }, k + V{ R * 0.866f, R * 0.5f }, k + V{ -R * 0.866f, R * 0.5f } };
                    cv.fill([&](V p) { return std::fabs(sd_polygon(p, tri, 3)) - t * 0.5f; }, col);
                    break;
                }
            }
        }

        void pill(Canvas& cv, V c, float w, float h, float radius, const char* const* labels, int count) {
            const V half{ w * 0.5f, h * 0.5f };
            cv.fill([&](V p) { return sd_box(p, c, half, radius); }, rim);
            cv.paint([&](V p) { return sd_box(p, c, half - V{ 1, 1 }, std::max(0.0f, radius - 1.0f)); },
                [&](V p) { return mix(body_top, body_bottom, std::clamp((p.y - (c.y - half.y)) / h, 0.0f, 1.0f)); });
            label(cv, labels, count, c, w - 4.0f, h - 3.0f, white);
        }

        void dpad(Canvas& cv, V c, float d, int dir) {
            const float arm = d * 0.18f, reach = d * 0.5f;
            auto shape = [&](V p, float inset) {
                return std::min(sd_box(p, c, { reach - inset, arm - inset }, arm * 0.35f),
                                sd_box(p, c, { arm - inset, reach - inset }, arm * 0.35f));
            };
            cv.fill([&](V p) { return shape(p, 0.0f); }, rim);
            cv.paint([&](V p) { return shape(p, 1.0f); },
                [&](V p) { return mix(body_top, body_bottom, std::clamp((p.y - (c.y - reach)) / d, 0.0f, 1.0f)); });
            cv.fill([&](V p) { return sd_circle(p, c, arm * 0.45f); }, rim, 0.6f);
            if (dir != DirNone) {
                const V v = dir_vector(dir);
                arrow(cv, c + v * (reach - 1.5f), v, arm * 1.1f, white, false);
            }
        }

        void stick(Canvas& cv, V c, float d, const char* name, int dir, float knob, bool pressed) {
            const float r = d * 0.5f;
            const V v = dir_vector(dir);
            cv.fill([&](V p) { return sd_circle(p, c, r); }, rim);
            cv.fill([&](V p) { return sd_circle(p, c, r - 1.0f); }, { 34, 34, 40 });
            const float kr = d * (pressed ? 0.3f : 0.34f);
            const V k = c + v * (d * 0.07f) + V{ knob, 0 };
            cv.fill([&](V p) { return sd_circle(p, k + V{ 0, 1 }, kr); }, { 10, 10, 12 }, 0.8f);
            const Rgb top = pressed ? Rgb{ 70, 70, 78 } : Rgb{ 100, 100, 112 };
            cv.paint([&](V p) { return sd_circle(p, k, kr); },
                [&](V p) { return mix(top, body_bottom, std::clamp((p.y - (k.y - kr)) / (2 * kr), 0.0f, 1.0f)); });
            cv.fill([&](V p) { return std::fabs(sd_circle(p, k, kr * 0.68f)) - 0.5f; }, { 28, 28, 32 }, 0.7f);
            if (kr * 2.0f >= 9.0f) {
                const char* labels[1] = { name };
                label(cv, labels, 1, k, kr * 1.3f, kr * 1.3f, white);
            }
            if (dir != DirNone) {
                arrow(cv, c + v * (r - 0.5f), v, d * 0.17f, white, true);
            }
        }

        void touch(Canvas& cv, Box box, bool rear, int corner) {
            const float bw = box.x1 - box.x0, bh = box.y1 - box.y0;
            const char* name = rear ? "REAR" : "FRONT";
            float tw = std::min(bw, bh * 1.7f), th = tw / 1.7f;
            const bool labelled = bh - th >= 7.0f && text_width(small, name) <= bw;
            if (labelled) {
                th = std::min(th, bh - 7.0f);
                tw = std::min(tw, th * 1.7f);
            }
            const float total = th + (labelled ? 7.0f : 0.0f);
            const V c{ (box.x0 + box.x1) * 0.5f, (box.y0 + box.y1) * 0.5f - total * 0.5f + th * 0.5f };
            const V half{ tw * 0.5f, th * 0.5f };
            cv.fill([&](V p) { return sd_box(p, c, half, th * 0.3f); }, rim);
            cv.paint([&](V p) { return sd_box(p, c, half - V{ 1, 1 }, th * 0.3f - 1.0f); },
                [&](V p) { return mix(body_top, body_bottom, std::clamp((p.y - (c.y - half.y)) / th, 0.0f, 1.0f)); });
            // The pad (rear) or the screen (front), its touched quarter lit.
            const V pad_half = rear ? half - V{ tw * 0.12f, th * 0.18f } : half - V{ tw * 0.2f, th * 0.16f };
            cv.fill([&](V p) { return sd_box(p, c, pad_half, 1.0f); }, rear ? Rgb{ 58, 58, 66 } : Rgb{ 24, 34, 60 });
            if (corner >= 1 && corner <= 4) {
                const float sx = (corner == 2 || corner == 4) ? 1.0f : -1.0f, sy = corner >= 3 ? 1.0f : -1.0f;
                const V q = c + V{ sx * pad_half.x * 0.5f, sy * pad_half.y * 0.5f };
                cv.fill([&](V p) { return sd_box(p, q, pad_half * 0.5f - V{ 0.5f, 0.5f }, 0.8f); }, { 125, 175, 240 });
                cv.fill([&](V p) { return sd_circle(p, q, std::max(1.2f, pad_half.y * 0.32f)); }, white);
            }
            if (labelled) text(cv, small, name, { c.x, c.y + th * 0.5f + 4.0f }, white);
        }
    }

    bool carve_pad(uint32_t* px, int w, int h, Art art) {
        if (art != Art::Cross && art != Art::Circle && art != Art::Square && art != Art::Triangle) return false;
        const int n = w * h;
        auto rgb = [&](int i, int k) { return (int)((px[i] >> (8 * k)) & 255); };
        // The letter: greenish yellow (green near red); its carved shadow: dark texels by it.
        std::vector<uint8_t> letter(n), shadow(n);
        std::vector<int> letter_texels;
        for (int i = 0; i < n; i++) {
            const int r = rgb(i, 0), g = rgb(i, 1);
            if (r > 0x60 && g * 10 >= r * 8) { letter[i] = 1; letter_texels.push_back(i); }
        }
        if (letter_texels.size() < 64) return false;
        int x0 = w, y0 = h, x1 = 0, y1 = 0;
        for (int i : letter_texels) {
            x0 = std::min(x0, i % w); x1 = std::max(x1, i % w);
            y0 = std::min(y0, i / w); y1 = std::max(y1, i / w);
        }
        for (int y = std::max(0, y0 - 2); y <= std::min(h - 1, y1 + 2); y++) {
            for (int x = std::max(0, x0 - 3); x <= std::min(w - 1, x1 + 3); x++) {
                const int i = y * w + x;
                if (letter[i] || rgb(i, 0) >= 0x70) continue;
                bool near = false;
                for (int dy = -3; dy <= 3 && !near; dy++) {
                    for (int dx = -3; dx <= 3 && !near; dx++) {
                        const int xx = x + dx, yy = y + dy;
                        near = xx >= 0 && yy >= 0 && xx < w && yy < h && letter[yy * w + xx];
                    }
                }
                shadow[i] = near;
            }
        }
        // The rings are octagons around the middle: a texel's ring, and where on it it is.
        const V c{ w * 0.5f, h * 0.5f };
        auto ring = [&](int x, int y) {
            const float dx = std::fabs(x + 0.5f - c.x), dy = std::fabs(y + 0.5f - c.y);
            return std::max({ dx, dy, (dx + dy) * 0.7071f });
        };
        auto angle = [&](int x, int y) { return std::atan2(y + 0.5f - c.y, x + 0.5f - c.x); };
        const std::vector<uint32_t> original(px, px + n);
        for (int i = 0; i < n; i++) {
            if (!letter[i] && !shadow[i]) continue;
            const float r0 = ring(i % w, i / w), a0 = angle(i % w, i / w);
            int best = -1;
            float best_d = 1e9f;
            for (int j = 0; j < n; j++) {
                if (letter[j] || shadow[j] || std::fabs(ring(j % w, j / w) - r0) > 0.75f) continue;
                if (rgb(j, 0) < 0x70) continue; // dark: the outer rim, carving
                float d = std::fabs(angle(j % w, j / w) - a0);
                d = std::min(d, 6.2832f - d);
                if (d < best_d) { best_d = d; best = j; }
            }
            if (best >= 0) px[i] = original[best];
        }
        // The symbol, raised: the letter's own texels, a shadow cast to its lower left.
        const float s = (float)std::min(w, h) * 0.2f, t = (float)std::min(w, h) * 0.1f;
        const V k = c + V{ 0.5f, 0.0f };
        auto sd = [&](V p) {
            switch (art) {
                case Art::Cross:
                    return std::min(sd_segment(p, k + V{ -s, -s }, k + V{ s, s }, t), sd_segment(p, k + V{ s, -s }, k + V{ -s, s }, t));
                case Art::Circle:
                    return std::fabs(sd_circle(p, k, s * 1.1f)) - t * 0.5f;
                case Art::Square:
                    return std::fabs(sd_box(p, k, { s, s }, 1.0f)) - t * 0.5f;
                default: {
                    const float R = s * 1.3f;
                    const V q = k + V{ 0, R * 0.15f };
                    const V tri[3] = { q + V{ 0, -R }, q + V{ R * 0.866f, R * 0.5f }, q + V{ -R * 0.866f, R * 0.5f } };
                    return std::fabs(sd_polygon(p, tri, 3)) - t * 0.5f;
                }
            }
        };
        const std::vector<uint32_t> wood(px, px + n);
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                const int i = y * w + x;
                const V p{ x + 0.5f, y + 0.5f };
                const float cov = std::clamp(0.5f - sd(p), 0.0f, 1.0f);
                const float shade = std::clamp(0.5f - sd(p + V{ 1.5f, -1.0f }), 0.0f, 1.0f) * (1.0f - cov);
                uint32_t out = wood[i];
                if (shade > 0.0f) {
                    const uint32_t dark = 0xFF081831u; // the original's carving shadow (0x311808)
                    out = blend(out, dark, shade);
                }
                if (cov > 0.0f) {
                    const uint32_t ink = letter[i] ? original[i] : original[letter_texels[(size_t)(x * 7 + y * 13) % letter_texels.size()]];
                    out = blend(out, ink, cov);
                }
                px[i] = (out & 0x00FFFFFFu) | (original[i] & 0xFF000000u);
            }
        }
        return true;
    }

    void draw(uint32_t* px, int w, int h, Box box, Art art, int dir, float knob) {
        Canvas cv(w, h);
        const V c{ (box.x0 + box.x1) * 0.5f, (box.y0 + box.y1) * 0.5f };
        const float bw = box.x1 - box.x0, bh = box.y1 - box.y0;
        const float d = std::min(bw, bh);
        switch (art) {
            case Art::Cross: case Art::Circle: case Art::Square: case Art::Triangle:
                face_button(cv, c, d, art);
                break;
            case Art::L: case Art::R: case Art::L1: case Art::R1: {
                static const char* const names[] = { "L", "R", "L1", "R1" };
                const char* name = names[(int)art - (int)Art::L];
                const float ph = std::min(bh, std::max(bw * 0.6f, 12.0f));
                pill(cv, c, bw, std::min(ph, bh), std::min(bw, ph) * 0.32f, &name, 1);
                break;
            }
            case Art::Start: case Art::Select: {
                static const char* const start[] = { "START", "ST" };
                static const char* const select[] = { "SELECT", "SEL" };
                const float ph = std::min(bh, std::max(bw * 0.45f, 11.0f));
                pill(cv, c, bw, ph, ph * 0.5f, art == Art::Start ? start : select, 2);
                break;
            }
            case Art::DPad:
                dpad(cv, c, d, dir);
                break;
            case Art::LStick: case Art::RStick:
                stick(cv, c, d, art == Art::LStick ? "L" : "R", dir, knob, false);
                break;
            case Art::L3: case Art::R3:
                stick(cv, c, d, art == Art::L3 ? "L3" : "R3", DirNone, 0.0f, true);
                break;
            case Art::RearTouch: case Art::FrontTouch:
                touch(cv, box, art == Art::RearTouch, dir);
                break;
            default:
                break;
        }
        cv.store(px);
    }
}
