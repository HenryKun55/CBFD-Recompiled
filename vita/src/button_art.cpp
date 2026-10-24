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

    namespace {
        // ---- The pads' glyphs: one shape per input as a signed distance, in a box around c.

        // A stroke font for the pads (units: 4 wide, 6 tall, y down), each letter polylines.
        struct Stroke { int n; V p[12]; };
        struct StrokeGlyph { char c; int strokes; Stroke s[3]; };
        const StrokeGlyph stroke_font[] = {
            { 'L', 1, { { 3, { { 0, 0 }, { 0, 6 }, { 4, 6 } } } } },
            { 'R', 2, { { 7, { { 0, 6 }, { 0, 0 }, { 2.7f, 0 }, { 3.8f, 0.8f }, { 3.8f, 2.2f }, { 2.7f, 3 }, { 0, 3 } } },
                        { 2, { { 1.9f, 3 }, { 4, 6 } } } } },
            { 'S', 1, { { 12, { { 4, 0.9f }, { 3.1f, 0 }, { 0.9f, 0 }, { 0, 0.9f }, { 0, 2.1f }, { 0.9f, 2.95f }, { 3.1f, 3.05f },
                                { 4, 3.9f }, { 4, 5.1f }, { 3.1f, 6 }, { 0.9f, 6 }, { 0, 5.1f } } } } },
            { 'T', 2, { { 2, { { 0, 0 }, { 4, 0 } } }, { 2, { { 2, 0 }, { 2, 6 } } } } },
            { 'E', 2, { { 4, { { 4, 0 }, { 0, 0 }, { 0, 6 }, { 4, 6 } } }, { 2, { { 0, 3 }, { 3.2f, 3 } } } } },
            { 'U', 1, { { 6, { { 0, 0 }, { 0, 5 }, { 0.9f, 6 }, { 3.1f, 6 }, { 4, 5 }, { 4, 0 } } } } },
            { 'P', 1, { { 7, { { 0, 6 }, { 0, 0 }, { 2.9f, 0 }, { 4, 0.9f }, { 4, 2.1f }, { 2.9f, 3 }, { 0, 3 } } } } },
            { 'D', 1, { { 7, { { 0, 0 }, { 0, 6 }, { 2.3f, 6 }, { 4, 4.3f }, { 4, 1.7f }, { 2.3f, 0 }, { 0, 0 } } } } },
            { 'O', 1, { { 9, { { 0.9f, 0 }, { 3.1f, 0 }, { 4, 0.9f }, { 4, 5.1f }, { 3.1f, 6 }, { 0.9f, 6 }, { 0, 5.1f }, { 0, 0.9f }, { 0.9f, 0 } } } } },
            { 'W', 1, { { 5, { { 0, 0 }, { 0.8f, 6 }, { 2, 2.6f }, { 3.2f, 6 }, { 4, 0 } } } } },
            { 'N', 1, { { 4, { { 0, 6 }, { 0, 0 }, { 4, 6 }, { 4, 0 } } } } },
            { 'F', 2, { { 3, { { 4, 0 }, { 0, 0 }, { 0, 6 } } }, { 2, { { 0, 3 }, { 3.2f, 3 } } } } },
            { 'G', 1, { { 10, { { 4, 0.9f }, { 3.1f, 0 }, { 0.9f, 0 }, { 0, 0.9f }, { 0, 5.1f }, { 0.9f, 6 }, { 3.1f, 6 }, { 4, 5.1f }, { 4, 3.2f }, { 2.2f, 3.2f } } } } },
            { 'H', 3, { { 2, { { 0, 0 }, { 0, 6 } } }, { 2, { { 4, 0 }, { 4, 6 } } }, { 2, { { 0, 3 }, { 4, 3 } } } } },
            { 'I', 3, { { 2, { { 2, 0 }, { 2, 6 } } }, { 2, { { 0.9f, 0 }, { 3.1f, 0 } } }, { 2, { { 0.9f, 6 }, { 3.1f, 6 } } } } },
            { '1', 2, { { 3, { { 0.6f, 1.3f }, { 2.2f, 0 }, { 2.2f, 6 } } }, { 2, { { 0.6f, 6 }, { 3.8f, 6 } } } } },
            { '3', 2, { { 7, { { 0, 0.7f }, { 0.8f, 0 }, { 3.1f, 0 }, { 4, 0.8f }, { 4, 2.2f }, { 3.1f, 3 }, { 1.3f, 3 } } },
                        { 6, { { 3.1f, 3 }, { 4, 3.8f }, { 4, 5.2f }, { 3.1f, 6 }, { 0.8f, 6 }, { 0, 5.3f } } } } },
        };
        constexpr float stroke_gap = 1.7f;

        float stroke_text_width(const char* s) {
            const int n = (int)std::strlen(s);
            return n ? n * 4.0f + (n - 1) * stroke_gap : 0.0f;
        }
        // The distance to the strokes of s, centred on c, unit texels a font unit, stroke wide.
        float sd_text(V p, const char* s, V c, float unit, float stroke) {
            const float x0 = c.x - stroke_text_width(s) * unit * 0.5f, y0 = c.y - 3.0f * unit;
            float d = 1e9f;
            for (int k = 0; s[k]; k++) {
                const float gx = x0 + k * (4.0f + stroke_gap) * unit;
                for (const StrokeGlyph& g : stroke_font) {
                    if (g.c != s[k]) continue;
                    for (int j = 0; j < g.strokes; j++) {
                        const Stroke& st = g.s[j];
                        for (int i = 0; i + 1 < st.n; i++) {
                            const V a{ gx + st.p[i].x * unit, y0 + st.p[i].y * unit };
                            const V b{ gx + st.p[i + 1].x * unit, y0 + st.p[i + 1].y * unit };
                            d = std::min(d, sd_segment(p, a, b, stroke));
                        }
                    }
                }
            }
            return d;
        }
        // Text as big as fits in a box half wide x half high around c (strokes at least min_stroke).
        float sd_label(V p, const char* s, V c, float half_w, float half_h) {
            const float tw = stroke_text_width(s);
            const float unit = std::min(half_w * 2.0f / (tw + 1.2f), half_h * 2.0f / 7.2f);
            const float stroke = std::clamp(unit * 1.15f, 2.6f, 5.0f);
            return sd_text(p, s, c, unit, stroke);
        }

        // A word under a pad's symbol: thin strokes (it's small).
        float sd_word(V p, const char* s, V c, float half_w, float half_h) {
            const float tw = stroke_text_width(s);
            const float unit = std::min(half_w * 2.0f / (tw + 0.6f), half_h * 2.0f / 7.0f);
            return sd_text(p, s, c, unit, std::clamp(unit * 1.25f, 2.0f, 3.2f));
        }

        float sd_union(float a, float b) { return std::min(a, b); }
        float sd_ring(float sd, float width) { return std::fabs(sd) - width * 0.5f; }

        // The glyph for an input: a shape (negative inside) about 2 * half across, around c.
        // t: the groove's width.
        float sd_glyph(V p, Art art, int dir, V c, float half, float t) {
            const float s = half * 0.62f;
            switch (art) {
                case Art::Cross:
                    return sd_union(sd_segment(p, c + V{ -s, -s }, c + V{ s, s }, t), sd_segment(p, c + V{ s, -s }, c + V{ -s, s }, t));
                case Art::Circle:
                    return sd_ring(sd_circle(p, c, s * 1.12f), t);
                case Art::Square:
                    return sd_ring(sd_box(p, c, { s, s }, 1.0f), t);
                case Art::Triangle: {
                    const float R = s * 1.32f;
                    const V q = c + V{ 0, R * 0.15f };
                    const V tri[3] = { q + V{ 0, -R }, q + V{ R * 0.866f, R * 0.5f }, q + V{ -R * 0.866f, R * 0.5f } };
                    return sd_ring(sd_polygon(p, tri, 3), t);
                }
                case Art::L: return sd_label(p, "L", c, half * 0.7f, half);
                case Art::R: return sd_label(p, "R", c, half * 0.7f, half);
                case Art::L1: return sd_label(p, "L1", c, half, half * 0.8f);
                case Art::R1: return sd_label(p, "R1", c, half, half * 0.8f);
                case Art::Start: return sd_label(p, "ST", c, half, half * 0.75f);
                case Art::Select: return sd_label(p, "SEL", c, half * 1.08f, half * 0.6f);
                case Art::L3: return sd_label(p, "L3", c, half, half * 0.8f);
                case Art::R3: return sd_label(p, "R3", c, half, half * 0.8f);
                case Art::DPad: { // the cross's outline faint, the pressed arm filled and pointed
                    const float a = half * 0.36f, reach = half * 1.05f, line = std::max(2.0f, t * 0.4f);
                    const float cross = std::min(sd_box(p, c, { reach, a }, 1.5f), sd_box(p, c, { a, reach }, 1.5f));
                    float d = sd_ring(cross + line * 0.5f, line);
                    const V v = dir_vector(dir);
                    if (v.x != 0 || v.y != 0) {
                        const V n{ -v.y, v.x };
                        // The arm from the middle, its end an arrowhead past the cross's edge.
                        const V root = c - v * (a * 0.6f), shoulder = c + v * (reach - a * 0.9f), tip = c + v * (reach + a * 0.25f);
                        const V arm[4] = { root + n * a, shoulder + n * a, shoulder - n * a, root - n * a };
                        const V head[3] = { tip, shoulder + n * (a * 1.25f), shoulder - n * (a * 1.25f) };
                        d = sd_union(d, sd_union(sd_polygon(p, arm, 4), sd_polygon(p, head, 3)));
                    }
                    return d;
                }
                case Art::LStick: case Art::RStick: { // the stick (a ring, its name in it), a bold arrow out of it
                    const V v = dir_vector(dir);
                    const float line = std::max(2.2f, t * 0.42f);
                    const float r = half * 0.52f;
                    const V k = c - v * (half * 0.48f);
                    float d = sd_union(sd_ring(sd_circle(p, k, r - line * 0.5f), line),
                                       sd_label(p, art == Art::LStick ? "L" : "R", k, r * 0.5f, r * 0.6f));
                    if (v.x != 0 || v.y != 0) {
                        const V n{ -v.y, v.x };
                        const V tip = c + v * (half * 1.08f), neck = c + v * (half * 0.5f);
                        const V head[3] = { tip, neck + n * (half * 0.5f), neck - n * (half * 0.5f) };
                        d = sd_union(d, sd_union(sd_segment(p, k + v * (r - line), neck + v * 1.0f, std::max(3.0f, t * 0.6f)), sd_polygon(p, head, 3)));
                    }
                    return d;
                }
                case Art::RearTouch: case Art::FrontTouch: { // the panel, its touched corner filled
                    const bool rear = art == Art::RearTouch;
                    const V hb{ half * 1.05f, half * 0.72f };
                    const float rad = rear ? hb.y * 0.75f : 1.5f;
                    float d = sd_ring(sd_box(p, c, hb - V{ t * 0.4f, t * 0.4f }, std::max(0.0f, rad - t * 0.4f)), t * 0.8f);
                    if (dir >= 1 && dir <= 4) {
                        const float sx = (dir == 2 || dir == 4) ? 1.0f : -1.0f, sy = dir >= 3 ? 1.0f : -1.0f;
                        const V q = c + V{ sx * hb.x * 0.5f, sy * hb.y * 0.5f };
                        const V qh = hb * 0.5f;
                        d = sd_union(d, sd_box(p, q, qh, rear ? std::min(qh.y, rad * 0.8f) : 1.0f));
                    }
                    if (!rear) d = sd_union(d, sd_segment(p, c + V{ -hb.x * 0.25f, hb.y + t * 0.9f }, c + V{ hb.x * 0.25f, hb.y + t * 0.9f }, t * 0.7f)); // the stand: a screen
                    return d;
                }
                default:
                    return 1e9f;
            }
        }

        // Texels as floats (0..255), and back keeping the alpha.
        struct Texel { float r, g, b; };
        Texel texel(uint32_t p) { return { (float)(p & 255), (float)((p >> 8) & 255), (float)((p >> 16) & 255) }; }
        uint32_t pack(Texel t, uint32_t alpha_from) {
            auto u8 = [](float v) { return (uint32_t)std::clamp((int)std::lround(v), 0, 255); };
            return (alpha_from & 0xFF000000u) | (u8(t.b) << 16) | (u8(t.g) << 8) | u8(t.r);
        }
        Texel lerp(Texel a, Texel b, float t) { return { a.r + (b.r - a.r) * t, a.g + (b.g - a.g) * t, a.b + (b.b - a.b) * t }; }
        float luma(Texel t) { return t.r * 0.3f + t.g * 0.59f + t.b * 0.11f; }

        // A pad's glyph in three parts: main (the symbol, as the original letter), faint (cut or
        // raised a little: the d-pad's cross, the stick's ring), accent (painted bright, cut deep:
        // the pressed arm, the stick's leaning side).
        struct Layers { float main = 1e9f, faint = 1e9f, accent = 1e9f; };

        // The directions have no "up" on a pad on the ground, seen from anywhere: the symbol
        // goes above a word ("UP", "LEFT"...) whose reading fixes it.
        Layers pad_glyph(V p, Art art, int dir, V c, float half, float t) {
            Layers l;
            const bool directional = (art == Art::DPad || art == Art::LStick || art == Art::RStick) && dir != DirNone;
            if (!directional) {
                l.main = sd_glyph(p, art, dir, c, half, t);
                return l;
            }
            static const char* const words[] = { "", "UP", "DOWN", "LEFT", "RIGHT" };
            const V sc = c - V{ 0, half * 0.3f }; // the symbol
            const float sh = half * 0.66f;
            const V v = dir_vector(dir);
            l.main = sd_word(p, words[dir], c + V{ 0, half * 0.72f }, half * 0.96f, half * 0.27f);
            if (art == Art::DPad) {
                const float a = sh * 0.36f, line = 2.4f;
                const float cross = std::min(sd_box(p, sc, { sh, a }, 1.0f), sd_box(p, sc, { a, sh }, 1.0f));
                l.faint = sd_ring(cross + line * 0.5f, line);
                // The pressed arm, from the middle out to its end.
                const V n{ -v.y, v.x };
                const V mid = sc + v * (sh * 0.5f + a * 0.25f);
                const V halfs{ std::fabs(v.x) * (sh * 0.5f - a * 0.25f) + std::fabs(n.x) * a, std::fabs(v.y) * (sh * 0.5f - a * 0.25f) + std::fabs(n.y) * a };
                l.accent = sd_box(p, mid, halfs, 1.0f);
            }
            else {
                const float r = sh * 0.95f, line = 2.0f;
                l.faint = sd_ring(sd_circle(p, sc, r - line * 0.5f), line);
                l.main = sd_union(l.main, sd_label(p, art == Art::LStick ? "L" : "R", sc, r * 0.38f, r * 0.48f));
                // The side it leans to: the disc's cap past the letter.
                const float along = dot(p - sc, v);
                l.accent = std::max(sd_circle(p, sc, r - line * 0.5f), r * 0.5f - along);
            }
            return l;
        }

        // The wooden pads (a raised greenish letter on an octagon or hexagon of wood rings): finds
        // the letter and its carved shadow (inside the letter's box), fills them with wood from the
        // same ring around the pad's middle (ring_c, in this texture's texels).
        bool wood_letter(uint32_t* px, int w, int h, Box box, V ring_c, std::vector<uint8_t>& letter, std::vector<int>& letter_texels) {
            const int n = w * h;
            auto rgb = [&](int i, int k) { return (int)((px[i] >> (8 * k)) & 255); };
            auto in_box = [&](int x, int y) { return x + 0.5f >= box.x0 && x + 0.5f <= box.x1 && y + 0.5f >= box.y0 && y + 0.5f <= box.y1; };
            std::vector<uint8_t> shadow(n);
            letter.assign(n, 0);
            letter_texels.clear();
            for (int i = 0; i < n; i++) {
                const int r = rgb(i, 0), g = rgb(i, 1);
                if (in_box(i % w, i / w) && (r > 0x60 || g > 0x60) && g * 10 >= r * 8) { letter[i] = 1; letter_texels.push_back(i); }
            }
            if (letter_texels.size() < 24) return false;
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
            // The rings go round the middle (octagons, near enough): a texel's ring, and where on it it is.
            auto ring = [&](int x, int y) {
                const float dx = std::fabs(x + 0.5f - ring_c.x), dy = std::fabs(y + 0.5f - ring_c.y);
                return std::max({ dx, dy, (dx + dy) * 0.7071f });
            };
            auto angle = [&](int x, int y) { return std::atan2(y + 0.5f - ring_c.y, x + 0.5f - ring_c.x); };
            const std::vector<uint32_t> original(px, px + n);
            for (int i = 0; i < n; i++) {
                if (!letter[i] && !shadow[i]) continue;
                const float r0 = ring(i % w, i / w), a0 = angle(i % w, i / w);
                int best = -1;
                // The same ring if it shows anywhere (the middle's may not: then the nearest).
                for (float tolerance = 0.75f; best < 0 && tolerance < 64.0f; tolerance *= 2.0f) {
                    float best_d = 1e9f;
                    for (int j = 0; j < n; j++) {
                        if (letter[j] || shadow[j] || std::fabs(ring(j % w, j / w) - r0) > tolerance) continue;
                        if (rgb(j, 0) < 0x70) continue; // dark: the outer rim, carving
                        float d = std::fabs(angle(j % w, j / w) - a0);
                        d = std::min(d, 6.2832f - d) + std::fabs(ring(j % w, j / w) - r0);
                        if (d < best_d) { best_d = d; best = j; }
                    }
                }
                if (best >= 0) px[i] = original[best];
            }
            return true;
        }

        // The stone pad (a disc with the letter's outline cut in it as thin dark grooves, its
        // holes dark): the dark texels in the letter's box filled with stone from beside them.
        void stone_letter(uint32_t* px, int w, int h, Box box) {
            const int n = w * h;
            // A rounded box (|x|^3 + |y|^3 < 1): the letter's corners in, the disc's groove round it out.
            const V c{ (box.x0 + box.x1) * 0.5f, (box.y0 + box.y1) * 0.5f }, r{ (box.x1 - box.x0) * 0.5f, (box.y1 - box.y0) * 0.5f };
            auto in_box = [&](int x, int y) {
                const float u = std::fabs(x + 0.5f - c.x) / r.x, v = std::fabs(y + 0.5f - c.y) / r.y;
                return u * u * u + v * v * v < 1.0f;
            };
            std::vector<float> lum(n);
            std::vector<float> inside;
            for (int i = 0; i < n; i++) {
                lum[i] = luma(texel(px[i]));
                if (in_box(i % w, i / w)) inside.push_back(lum[i]);
            }
            if (inside.empty()) return;
            std::sort(inside.begin(), inside.end());
            const float median = inside[inside.size() / 2];
            // Dark (the grooves, the holes), with the texels next to them (their soft edges).
            std::vector<uint8_t> dark(n), hole(n);
            for (int i = 0; i < n; i++) dark[i] = in_box(i % w, i / w) && lum[i] < median * 0.86f;
            for (int i = 0; i < n; i++) {
                const int x = i % w, y = i / w;
                if (!in_box(x, y)) continue;
                for (int k = 0; k < 4 && !hole[i]; k++) {
                    const int xx = x + (k == 0) - (k == 1), yy = y + (k == 2) - (k == 3);
                    hole[i] = dark[i] || (xx >= 0 && yy >= 0 && xx < w && yy < h && dark[yy * w + xx] && lum[i] < median * 1.0f);
                }
            }
            // From the edges in: each takes a texel a few along from the nearest sound one.
            for (int pass = 0; pass < 64; pass++) {
                std::vector<int> fill;
                for (int i = 0; i < n; i++) {
                    if (!hole[i]) continue;
                    const int x = i % w, y = i / w;
                    int sound = 0;
                    for (int dy = -1; dy <= 1; dy++)
                        for (int dx = -1; dx <= 1; dx++) {
                            const int xx = x + dx, yy = y + dy;
                            sound += xx >= 0 && yy >= 0 && xx < w && yy < h && !hole[yy * w + xx];
                        }
                    if (sound) fill.push_back(i);
                }
                if (fill.empty()) break;
                std::vector<uint32_t> out(fill.size());
                for (size_t f = 0; f < fill.size(); f++) {
                    const int x = fill[f] % w, y = fill[f] / w;
                    Texel sum{ 0, 0, 0 };
                    float weight = 0;
                    for (int dy = -2; dy <= 2; dy++)
                        for (int dx = -2; dx <= 2; dx++) {
                            const int xx = x + dx, yy = y + dy;
                            if (xx < 0 || yy < 0 || xx >= w || yy >= h || hole[yy * w + xx]) continue;
                            const float wt = 1.0f / (dx * dx + dy * dy);
                            const Texel t = texel(px[yy * w + xx]);
                            sum = { sum.r + t.r * wt, sum.g + t.g * wt, sum.b + t.b * wt };
                            weight += wt;
                        }
                    out[f] = pack({ sum.r / weight, sum.g / weight, sum.b / weight }, px[fill[f]]);
                }
                for (size_t f = 0; f < fill.size(); f++) {
                    px[fill[f]] = out[f];
                    hole[fill[f]] = 0;
                }
            }
        }
    }

    // Found with debug_dump_icons (hashes of the decoded texels, as button_icons.cpp keeps them).
    const PadTexture pad_textures[] = {
        // The octagon of wood (Windy: by the river, ...).
        { 0x243528B3, 64, 64, { PadKind::Wood, 0, 0, 64, 64, { 12, 11, 53, 53 } } },
        // The hexagon of wood, its halves.
        { 0xAF8529B2, 32, 64, { PadKind::Wood, 0, 0, 64, 64, { 17, 12, 50, 50 } } },
        { 0x27FF7D3F, 32, 64, { PadKind::Wood, 32, 0, 64, 64, { 17, 12, 50, 50 } } },
        // The stone disc (Windy: on the grass by the cliff over the stream), its halves.
        { 0xBC73C4A5, 32, 64, { PadKind::Stone, 0, 0, 64, 64, { 12, 7, 54, 52 } } },
        { 0xF745F13D, 32, 64, { PadKind::Stone, 32, 0, 64, 64, { 12, 7, 54, 52 } } },
    };
    const int pad_texture_count = (int)(sizeof(pad_textures) / sizeof(pad_textures[0]));

    bool carve_pad(uint32_t* px, int w, int h, const PadPiece& pad, Art art, int dir) {
        if (art > Art::Count || w < 8 || h < 8) return false; // Count: the letter taken off only (button_icons_preview)
        const int n = w * h;
        const std::vector<uint32_t> original(px, px + n);
        // The pad's picture in this texture's texels.
        const V off{ -(float)pad.x, -(float)pad.y };
        const Box box{ pad.letter.x0 + off.x, pad.letter.y0 + off.y, pad.letter.x1 + off.x, pad.letter.y1 + off.y };
        const V c{ (box.x0 + box.x1) * 0.5f, (box.y0 + box.y1) * 0.5f };
        const float half = std::min(box.x1 - box.x0, box.y1 - box.y0) * 0.5f;
        const float t = half * 0.3f;
        auto cover = [](float sd) { return std::clamp(0.5f - sd, 0.0f, 1.0f); };
        auto layers = [&](V p) { return pad_glyph(p, art, dir, c, half, t); };
        // Raised or cut, the symbol: main and accent (faint has no walls).
        auto solid = [&](V p) { const Layers l = layers(p); return std::min(l.main, l.accent); };
        switch (pad.kind) {
            case PadKind::Wood: {
                std::vector<uint8_t> letter;
                std::vector<int> letter_texels;
                const V ring_c{ pad.pad_w * 0.5f + off.x, pad.pad_h * 0.5f + off.y };
                if (!wood_letter(px, w, h, box, ring_c, letter, letter_texels)) {
                    std::memcpy(px, original.data(), (size_t)n * 4);
                    return false;
                }
                // Raised like the letter: its own texels, a shadow cast to the lower left; the
                // accent painted light, its edge dark.
                const std::vector<uint32_t> wood(px, px + n);
                const uint32_t paint = 0xFF8CF0FAu; // light yellow (0xFAF08C)
                for (int y = 0; y < h; y++) {
                    for (int x = 0; x < w; x++) {
                        const int i = y * w + x;
                        const V p{ x + 0.5f, y + 0.5f };
                        const Layers l = layers(p);
                        const float cov = cover(l.main), faint = cover(l.faint), accent = cover(l.accent);
                        const float shade = cover(solid(p + V{ 1.5f, -1.0f })) * (1.0f - std::max(cov, accent));
                        const float rim = cover(l.accent - 1.2f) * (1.0f - accent);
                        uint32_t out = wood[i];
                        const uint32_t ink = letter[i] ? original[i] : original[letter_texels[(size_t)(x * 7 + y * 13) % letter_texels.size()]];
                        if (faint > 0.0f) out = blend(out, ink, faint * 0.8f);
                        if (shade > 0.0f) out = blend(out, 0xFF081831u, shade); // the original's carving shadow (0x311808)
                        if (rim > 0.0f) out = blend(out, 0xFF081831u, rim);
                        if (cov > 0.0f) out = blend(out, ink, cov);
                        if (accent > 0.0f) out = blend(out, blend(ink, paint, 0.75f), accent);
                        px[i] = (out & 0x00FFFFFFu) | (original[i] & 0xFF000000u);
                    }
                }
                return true;
            }
            case PadKind::Stone: {
                stone_letter(px, w, h, box);
                // Cut in: the floor darker and bluer, the wall the light comes over (upper left)
                // in shadow, the far one (lower right) catching it. Faint: a shallow cut; the
                // accent painted (the wood letter's yellow green), cut deep (a dark rim).
                const Texel groove{ 46, 50, 92 };
                const Texel light{ 236, 240, 252 };
                const Texel deep{ 20, 22, 48 };
                const Texel paint{ 214, 206, 70 };
                const std::vector<uint32_t> stone(px, px + n);
                for (int y = 0; y < h; y++) {
                    for (int x = 0; x < w; x++) {
                        const int i = y * w + x;
                        const V p{ x + 0.5f, y + 0.5f };
                        const Layers l = layers(p);
                        const float cov = cover(l.main), faint = cover(l.faint), accent = cover(l.accent);
                        const Texel base = texel(stone[i]);
                        Texel out = lerp(base, groove, faint * 0.45f);
                        // Just outside the far edge: the lip, lit.
                        const float lip = cover(solid(p + V{ -1.0f, -1.0f })) * (1.0f - std::max(cov, accent));
                        out = lerp(out, light, lip * 0.35f);
                        if (cov > 0.0f) {
                            const float near_wall = 1.0f - cover(layers(p + V{ -1.0f, -1.0f }).main);
                            const float far_wall = 1.0f - cover(layers(p + V{ 1.0f, 1.0f }).main);
                            Texel g = lerp(base, groove, 0.55f);
                            g = lerp(g, deep, near_wall * 0.7f);
                            g = lerp(g, lerp(base, groove, 0.2f), far_wall * 0.6f);
                            out = lerp(out, g, cov);
                        }
                        const float rim = cover(l.accent - 1.3f) * (1.0f - accent);
                        out = lerp(out, deep, rim * 0.85f);
                        if (accent > 0.0f) {
                            const float near_wall = 1.0f - cover(layers(p + V{ -1.0f, -1.0f }).accent);
                            Texel a = lerp(paint, base, 0.15f);
                            a = lerp(a, Texel{ 120, 110, 30 }, near_wall * 0.6f);
                            out = lerp(out, a, accent);
                        }
                        px[i] = pack(out, original[i]);
                    }
                }
                return true;
            }
            default:
                return false;
        }
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
