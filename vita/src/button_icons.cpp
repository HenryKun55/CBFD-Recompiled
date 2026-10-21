// The N64 button icons redrawn as Vita buttons (see button_icons.hpp).
//
// The icons are sprites the text drawer (func_150417AC) picks by code from descriptors at
// D_800915DC.. (texture ids from the game's texture bank): 0xA8 A, 0xA9 B, 0xAA..0xAD
// C-left, C-right, C-up, C-down, 0xAE Z, 0xAF L, 0xB0 R, 0xB1 the stick (10 frames, 6
// pictures, its knob rocking). 0xB2..0xB5 are the swear symbols, 0xB6..0xB9 "st nd rd th",
// 0xBA the hint book's "more...", 0xBB a blinking box: not buttons, left alone.
// Each is recognised by a hash of its decoded texels (logged with debug_dump_icons) and
// redrawn, at its size and within its outline, as the first Vita input bound to that N64
// button (a button before a stick direction before a touch pad corner).
// The context-sensitive pads' carved "B" in the world (a 64 x 64 wood texture) gets the
// symbol of the face button bound to B carved instead.

#include <cstdio>
#include <cstring>
#include <filesystem>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define XXH_INLINE_ALL
#include "xxHash/xxhash.h"

#include "button_art.hpp"
#include "button_icons.hpp"
#include "controls.hpp"
#include "vita_platform.hpp"

namespace conker::vita::button_icons {
    namespace {
        using controls::Input;
        using controls::N64;
        using namespace button_art;

        // The stick icon stands for the N64 stick (the bound Vita stick).
        constexpr int stick_icon = (int)N64::Count;

        struct Original {
            uint32_t hash;
            uint8_t w, h;
            int button;     // N64 or stick_icon
            Box box;        // its picture's outline in the texture
            float knob;     // the stick's frames: where the N64 knob leans
            bool pad = false; // a context-sensitive pad's carved letter (button_art::carve_pad)
        };
        constexpr Box ab_box{ 4, 6, 28, 26 }, c_box{ 1, 1, 31, 31 }, z_box{ 0, 1, 16, 32 }, lr_box{ 2, 1, 30, 15 },
            stick_box{ 1, 1, 31, 31 };
        // The knob's lean: the N64 frames' light knob top (its centre, x 14..23) around 18.6.
        constexpr Original originals[] = {
            { 0x3E058993, 32, 32, (int)N64::A, ab_box, 0 },
            { 0xD1857AD7, 32, 32, (int)N64::B, ab_box, 0 },
            { 0xDBD0076F, 32, 32, (int)N64::CLeft, c_box, 0 },
            { 0xFA7F391B, 32, 32, (int)N64::CRight, c_box, 0 },
            { 0x2F32D040, 32, 32, (int)N64::CUp, c_box, 0 },
            { 0xB37872F0, 32, 32, (int)N64::CDown, c_box, 0 },
            { 0x9556F56E, 16, 32, (int)N64::Z, z_box, 0 },
            { 0x3E64DA4A, 32, 16, (int)N64::L, lr_box, 0 },
            { 0x4AE89806, 32, 16, (int)N64::R, lr_box, 0 },
            { 0x2EA79A50, 32, 32, stick_icon, stick_box, (14.2f - 18.6f) * 0.5f },
            { 0x8DB07165, 32, 32, stick_icon, stick_box, (15.1f - 18.6f) * 0.5f },
            { 0xB907ABE1, 32, 32, stick_icon, stick_box, (17.2f - 18.6f) * 0.5f },
            { 0x5A4C2EC3, 32, 32, stick_icon, stick_box, (19.8f - 18.6f) * 0.5f },
            { 0x87098D48, 32, 32, stick_icon, stick_box, (22.1f - 18.6f) * 0.5f },
            { 0x1706E512, 32, 32, stick_icon, stick_box, (23.0f - 18.6f) * 0.5f },
            // The B-pads on the ground ("seems to be another one of those B buttons!").
            { 0x243528B3, 64, 64, (int)N64::B, c_box, 0, true },
        };

        struct Pick { Art art; int dir; };

        // A Vita input's picture, and how good a stand-in it is (lower first; -1 none).
        int picture(Input in, Pick& out) {
            switch (in) {
                case Input::Cross: out = { Art::Cross, 0 }; return 0;
                case Input::Circle: out = { Art::Circle, 0 }; return 0;
                case Input::Square: out = { Art::Square, 0 }; return 0;
                case Input::Triangle: out = { Art::Triangle, 0 }; return 0;
                case Input::L: out = { Art::L, 0 }; return 0;
                case Input::R: out = { Art::R, 0 }; return 0;
                case Input::L1: out = { Art::L1, 0 }; return 0;
                case Input::R1: out = { Art::R1, 0 }; return 0;
                case Input::Start: out = { Art::Start, 0 }; return 0;
                case Input::Select: out = { Art::Select, 0 }; return 0;
                case Input::Up: out = { Art::DPad, DirUp }; return 0;
                case Input::Down: out = { Art::DPad, DirDown }; return 0;
                case Input::Left: out = { Art::DPad, DirLeft }; return 0;
                case Input::Right: out = { Art::DPad, DirRight }; return 0;
                case Input::L3: out = { Art::L3, 0 }; return 0;
                case Input::R3: out = { Art::R3, 0 }; return 0;
                case Input::LStickUp: out = { Art::LStick, DirUp }; return 1;
                case Input::LStickDown: out = { Art::LStick, DirDown }; return 1;
                case Input::LStickLeft: out = { Art::LStick, DirLeft }; return 1;
                case Input::LStickRight: out = { Art::LStick, DirRight }; return 1;
                case Input::RStickUp: out = { Art::RStick, DirUp }; return 1;
                case Input::RStickDown: out = { Art::RStick, DirDown }; return 1;
                case Input::RStickLeft: out = { Art::RStick, DirLeft }; return 1;
                case Input::RStickRight: out = { Art::RStick, DirRight }; return 1;
                case Input::RearTopLeft: out = { Art::RearTouch, 1 }; return 2;
                case Input::RearTopRight: out = { Art::RearTouch, 2 }; return 2;
                case Input::RearBottomLeft: out = { Art::RearTouch, 3 }; return 2;
                case Input::RearBottomRight: out = { Art::RearTouch, 4 }; return 2;
                case Input::FrontTopLeft: out = { Art::FrontTouch, 1 }; return 3;
                case Input::FrontTopRight: out = { Art::FrontTouch, 2 }; return 3;
                case Input::FrontBottomLeft: out = { Art::FrontTouch, 3 }; return 3;
                case Input::FrontBottomRight: out = { Art::FrontTouch, 4 }; return 3;
                default: return -1;
            }
        }

        // What an icon shows now; false: nothing bound (the N64 icon stays).
        bool pick(int button, Pick& out) {
            const controls::Config& cfg = controls::current();
            if (button == stick_icon) {
                out = { cfg.stick == controls::StickSource::Right ? Art::RStick : Art::LStick, 0 };
                return true;
            }
            int best = -1;
            for (int i = 0; i < controls::bindings_per_input; i++) {
                Pick p;
                const int rank = picture(cfg.bindings[button][i], p);
                if (rank >= 0 && (best < 0 || rank < best)) {
                    best = rank;
                    out = p;
                }
            }
            return best >= 0;
        }

        // Drawn pictures by original and pick.
        std::unordered_map<uint32_t, std::vector<uint32_t>> drawn;

        // Debug (ux0:data/conker/debug_dump_icons): every small texture decoded, once each, to
        // ux0:data/conker/icons/<hash>_<w>x<h>.ppm (colour above, alpha below).
        bool dump = [] {
            if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_dump_icons", "r")) {
                std::fclose(f);
                std::filesystem::create_directories(CONKER_VITA_DATA_DIR "/icons");
                return true;
            }
            return false;
        }();
        std::unordered_set<uint32_t> dumped;
        // Debug (ux0:data/conker/debug_n64_icons): the game's own N64 icons, for comparing.
        bool keep_n64 = [] {
            FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_n64_icons", "r");
            if (f) std::fclose(f);
            return f != nullptr;
        }();

        void dump_texture(const uint32_t* texels, uint32_t w, uint32_t h, uint32_t hash) {
            if (dumped.size() >= 1500 || !dumped.insert(hash).second) return;
            char path[160];
            std::snprintf(path, sizeof(path), CONKER_VITA_DATA_DIR "/icons/%08X_%ux%u.ppm", hash, w, h);
            if (FILE* f = std::fopen(path, "wb")) {
                std::fprintf(f, "P6\n%u %u\n255\n", w, h * 2);
                for (uint32_t i = 0; i < w * h; i++) std::fwrite(&texels[i], 1, 3, f);
                for (uint32_t i = 0; i < w * h; i++) {
                    const uint8_t a = texels[i] >> 24;
                    const uint8_t g[3] = { a, a, a };
                    std::fwrite(g, 1, 3, f);
                }
                std::fclose(f);
            }
        }

        uint32_t last_signature = 0;
        bool have_signature = false;
        uint32_t current_generation = 0;
    }

    bool replace(uint32_t* texels, uint32_t w, uint32_t h) {
        const bool icon_size = ((w == 32 || w == 16) && (h == 32 || h == 16)) || (w == 64 && h == 64);
        if (!icon_size && !dump) return false;
        if (w > 64 || h > 64) return false;
        const uint32_t hash = XXH32(texels, (size_t)w * h * 4, 0);
        if (dump) dump_texture(texels, w, h, hash);
        if (keep_n64) return false;
        for (int i = 0; i < (int)(sizeof(originals) / sizeof(originals[0])); i++) {
            const Original& o = originals[i];
            if (o.hash != hash || o.w != w || o.h != h) continue;
            Pick p;
            if (!pick(o.button, p)) return false;
            const uint32_t key = ((uint32_t)i << 16) | ((uint32_t)p.art << 8) | (uint32_t)p.dir;
            std::vector<uint32_t>& img = drawn[key];
            if (img.empty()) {
                if (o.pad) {
                    img.assign(texels, texels + (size_t)w * h);
                    if (!carve_pad(img.data(), (int)w, (int)h, p.art)) return false; // not a face button: the B stays
                }
                else {
                    img.resize((size_t)w * h);
                    draw(img.data(), (int)w, (int)h, o.box, p.art, p.dir, o.knob);
                }
            }
            std::memcpy(texels, img.data(), img.size() * 4);
            return true;
        }
        return false;
    }

    uint32_t generation() {
        // What each icon would show; a change makes the renderer decode (and redraw) again.
        uint32_t sig = 2166136261u;
        for (int b = 0; b <= stick_icon; b++) {
            Pick p{ Art::Count, 0 };
            if (b != stick_icon && b >= (int)N64::DUp) continue; // no icons for the d-pad / Start
            pick(b, p);
            sig = (sig ^ (((uint32_t)p.art << 4) | (uint32_t)p.dir)) * 16777619u;
        }
        if (!have_signature) {
            have_signature = true;
            last_signature = sig;
        }
        else if (sig != last_signature) {
            last_signature = sig;
            current_generation++;
        }
        return current_generation;
    }
}
