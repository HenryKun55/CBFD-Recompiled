// Remappable controls (controls.hpp).

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#include <psp2/apputil.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/system_param.h>

#include "controls.hpp"
#include "vita_platform.hpp"

namespace conker::vita::controls {
    namespace {
        Config config = defaults();

        const char* const input_names[] = {
            "None",
            "Cross", "Circle", "Square", "Triangle",
            "L", "R", "Up", "Down", "Left", "Right", "Start", "Select",
            "L1", "R1", "L3", "R3",
            "LStickUp", "LStickDown", "LStickLeft", "LStickRight",
            "RStickUp", "RStickDown", "RStickLeft", "RStickRight",
            "RearTopLeft", "RearTopRight", "RearBottomLeft", "RearBottomRight",
            "FrontTopLeft", "FrontTopRight", "FrontBottomLeft", "FrontBottomRight",
        };
        static_assert(sizeof(input_names) / sizeof(input_names[0]) == (size_t)Input::Count);

        const char* const n64_names[] = {
            "A", "B", "Z", "Start", "L", "R",
            "CUp", "CDown", "CLeft", "CRight",
            "DUp", "DDown", "DLeft", "DRight",
        };
        static_assert(sizeof(n64_names) / sizeof(n64_names[0]) == (size_t)N64::Count);

        const uint16_t n64_bits[] = {
            0x8000, 0x4000, 0x2000, 0x1000, 0x0020, 0x0010,
            0x0008, 0x0004, 0x0002, 0x0001,
            0x0800, 0x0400, 0x0200, 0x0100,
        };

        float axis(uint8_t value) {
            return std::clamp(((float)value - 128.0f) / 127.0f, -1.0f, 1.0f);
        }

        // A touch panel's quadrant: 0 top left, 1 top right, 2 bottom left, 3 bottom right.
        // Both panels report 1920 units across; the front 1088 high, the back 890 (offset 108).
        bool touch_in(const SceTouchData& t, int quadrant, bool back) {
            for (int i = 0; i < (int)t.reportNum; i++) {
                const int x = t.report[i].x;
                const int y = back ? t.report[i].y - 108 : t.report[i].y;
                const int mid_y = back ? 445 : 544;
                const int q = (x >= 960 ? 1 : 0) + (y >= mid_y ? 2 : 0);
                if (q == quadrant) return true;
            }
            return false;
        }

        uint32_t button_mask(Input input) {
            switch (input) {
                case Input::Cross: return SCE_CTRL_CROSS;
                case Input::Circle: return SCE_CTRL_CIRCLE;
                case Input::Square: return SCE_CTRL_SQUARE;
                case Input::Triangle: return SCE_CTRL_TRIANGLE;
                case Input::L: return SCE_CTRL_LTRIGGER;
                case Input::R: return SCE_CTRL_RTRIGGER;
                case Input::Up: return SCE_CTRL_UP;
                case Input::Down: return SCE_CTRL_DOWN;
                case Input::Left: return SCE_CTRL_LEFT;
                case Input::Right: return SCE_CTRL_RIGHT;
                case Input::Start: return SCE_CTRL_START;
                case Input::Select: return SCE_CTRL_SELECT;
                case Input::L1: return SCE_CTRL_L1;
                case Input::R1: return SCE_CTRL_R1;
                case Input::L3: return SCE_CTRL_L3;
                case Input::R3: return SCE_CTRL_R3;
                default: return 0;
            }
        }
    }

    // The text language matching the Vita's system language (English when there's none).
    int system_language() {
        int lang = SCE_SYSTEM_PARAM_LANG_ENGLISH_US;
        if (sceAppUtilSystemParamGetInt(SCE_SYSTEM_PARAM_ID_LANG, &lang) < 0) return 0;
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

    Config defaults() {
        Config c{};
        c.language = system_language();
        for (auto& b : c.bindings) {
            b[0] = b[1] = Input::None;
        }
        auto bind = [&](N64 n, Input a, Input b = Input::None) {
            c.bindings[(int)n][0] = a;
            c.bindings[(int)n][1] = b;
        };
        // The N64's layout: A and B on the bottom face buttons, the C-buttons on the
        // right stick (Triangle and Circle as C-Up and C-Right too, for menus), Z on L,
        // R on R, and the N64's L (rarely used) on Select.
        bind(N64::A, Input::Cross);
        bind(N64::B, Input::Square);
        bind(N64::Z, Input::L);
        bind(N64::Start, Input::Start);
        bind(N64::L, Input::Select);
        bind(N64::R, Input::R);
        bind(N64::CUp, Input::RStickUp, Input::Triangle);
        bind(N64::CDown, Input::RStickDown, Input::RearBottomRight);
        bind(N64::CLeft, Input::RStickLeft, Input::RearBottomLeft);
        bind(N64::CRight, Input::RStickRight, Input::Circle);
        bind(N64::DUp, Input::Up);
        bind(N64::DDown, Input::Down);
        bind(N64::DLeft, Input::Left);
        bind(N64::DRight, Input::Right);
        return c;
    }

    Config& current() {
        return config;
    }

    const char* input_name(Input input) { return input_names[(int)input]; }
    const char* n64_name(N64 button) { return n64_names[(int)button]; }
    const char* stick_name(StickSource source) { return source == StickSource::Left ? "Left stick" : "Right stick"; }

    namespace {
        // When player 1 last aimed (the game thread, each game frame while aiming), for the input
        // thread: aiming lasts a little over two game frames after, so one slow frame doesn't swap
        // the sticks back for a poll.
        std::atomic<uint64_t> last_aim_us{0};
        bool aiming_now() {
            const uint64_t t = last_aim_us.load(std::memory_order_relaxed);
            return t != 0 && sceKernelGetProcessTimeWide() - t < 120000;
        }
    }

    bool held(const Config& cfg, const VitaState& s, Input input) {
        const float t = cfg.stick_threshold / 100.0f;
        // The stick that isn't the N64's, turned around if set (Invert X/Y of the other stick).
        const bool other_left = cfg.stick == StickSource::Right;
        const Input first = other_left ? Input::LStickUp : Input::RStickUp; // Up, Down, Left, Right
        if (input >= first && input <= (Input)((int)first + 3)) {
            const int dir = (int)input - (int)first;
            if (cfg.invert_other_y && dir < 2) input = (Input)((int)first + (dir ^ 1));
            if (cfg.invert_other_x && dir >= 2) input = (Input)((int)first + 2 + ((dir - 2) ^ 1));
        }
        switch (input) {
            case Input::None: return false;
            case Input::LStickUp: return axis(s.pad.ly) < -t;
            case Input::LStickDown: return axis(s.pad.ly) > t;
            case Input::LStickLeft: return axis(s.pad.lx) < -t;
            case Input::LStickRight: return axis(s.pad.lx) > t;
            case Input::RStickUp: return axis(s.pad.ry) < -t;
            case Input::RStickDown: return axis(s.pad.ry) > t;
            case Input::RStickLeft: return axis(s.pad.rx) < -t;
            case Input::RStickRight: return axis(s.pad.rx) > t;
            case Input::RearTopLeft: return touch_in(s.back, 0, true);
            case Input::RearTopRight: return touch_in(s.back, 1, true);
            case Input::RearBottomLeft: return touch_in(s.back, 2, true);
            case Input::RearBottomRight: return touch_in(s.back, 3, true);
            case Input::FrontTopLeft: return touch_in(s.front, 0, false);
            case Input::FrontTopRight: return touch_in(s.front, 1, false);
            case Input::FrontBottomLeft: return touch_in(s.front, 2, false);
            case Input::FrontBottomRight: return touch_in(s.front, 3, false);
            default: return (s.pad.buttons & button_mask(input)) != 0;
        }
    }

    Input first_held(const Config& cfg, const VitaState& s) {
        for (int i = 1; i < (int)Input::Count; i++) {
            if (held(cfg, s, (Input)i)) return (Input)i;
        }
        return Input::None;
    }

    void to_n64(const Config& cfg, const VitaState& state, uint16_t* buttons, float* x, float* y) {
        // Aim with the camera stick: while player 1 aims, the two sticks are read the other way
        // round, so the camera stick drives the N64's stick (the aim) and the movement stick the
        // C-buttons (which move Conker while he aims).
        VitaState swapped;
        const bool swap = cfg.aim_camera_stick && aiming_now();
        if (swap) {
            swapped = state;
            std::swap(swapped.pad.lx, swapped.pad.rx);
            std::swap(swapped.pad.ly, swapped.pad.ry);
        }
        const VitaState& s = swap ? swapped : state;
        uint16_t b = 0;
        for (int n = 0; n < (int)N64::Count; n++) {
            for (int k = 0; k < bindings_per_input; k++) {
                const Input in = cfg.bindings[n][k];
                // A stick that drives the N64's stick presses no buttons with its directions.
                const bool from_stick_source =
                    (cfg.stick == StickSource::Left && in >= Input::LStickUp && in <= Input::LStickRight) ||
                    (cfg.stick == StickSource::Right && in >= Input::RStickUp && in <= Input::RStickRight);
                if (!from_stick_source && held(cfg, s, in)) {
                    b |= n64_bits[n];
                }
            }
        }

        float sx = cfg.stick == StickSource::Left ? axis(s.pad.lx) : axis(s.pad.rx);
        float sy = -(cfg.stick == StickSource::Left ? axis(s.pad.ly) : axis(s.pad.ry));
        const float magnitude = std::sqrt(sx * sx + sy * sy);
        const float dz = cfg.deadzone / 100.0f;
        if (magnitude <= dz) {
            sx = sy = 0.0f;
        }
        else {
            float scaled = (magnitude - dz) / (1.0f - dz) * (cfg.sensitivity / 100.0f);
            scaled = std::min(scaled, 1.0f);
            sx = sx / magnitude * scaled;
            sy = sy / magnitude * scaled;
        }
        if (cfg.invert_x) sx = -sx;
        if (cfg.invert_y) sy = -sy;
        *buttons = b;
        *x = sx;
        *y = sy;
    }

    // ------------------------------------------------------------ the file
    namespace {
        Input parse_input(const char* name) {
            for (int i = 0; i < (int)Input::Count; i++) {
                if (std::strcmp(name, input_names[i]) == 0) return (Input)i;
            }
            return Input::None;
        }
        const char* path = CONKER_VITA_DATA_DIR "/controls.ini";
    }

    void load() {
        config = defaults();
        // Language is only taken from the file once it was picked in the menu: 1.0.0 saved
        // its default (Portuguese) with any other setting.
        int file_language = -1;
        bool have_frame_rate = false, old_interpolation = false;
        FILE* f = std::fopen(path, "r");
        if (f == nullptr) {
            return;
        }
        char line[256];
        while (std::fgets(line, sizeof(line), f)) {
            char key[64] = {}, a[64] = {}, b[64] = {};
            const int n = std::sscanf(line, " %63[^= ] = %63[^, \r\n] , %63[^ \r\n]", key, a, b);
            if (n < 2 || key[0] == '#') continue;
            bool found = false;
            for (int i = 0; i < (int)N64::Count; i++) {
                if (std::strcmp(key, n64_names[i]) == 0) {
                    config.bindings[i][0] = parse_input(a);
                    config.bindings[i][1] = n >= 3 ? parse_input(b) : Input::None;
                    found = true;
                }
            }
            if (found) continue;
            if (!std::strcmp(key, "Stick")) config.stick = !std::strcmp(a, "Right") ? StickSource::Right : StickSource::Left;
            else if (!std::strcmp(key, "Deadzone")) config.deadzone = std::clamp(std::atoi(a), 0, 60);
            else if (!std::strcmp(key, "Sensitivity")) config.sensitivity = std::clamp(std::atoi(a), 50, 200);
            else if (!std::strcmp(key, "InvertX")) config.invert_x = std::atoi(a) != 0;
            else if (!std::strcmp(key, "InvertY")) config.invert_y = std::atoi(a) != 0;
            else if (!std::strcmp(key, "InvertOtherX")) config.invert_other_x = std::atoi(a) != 0;
            else if (!std::strcmp(key, "InvertOtherY")) config.invert_other_y = std::atoi(a) != 0;
            else if (!std::strcmp(key, "AimInvertX")) config.aim_invert_x = std::atoi(a) != 0;
            else if (!std::strcmp(key, "AimCameraStick")) config.aim_camera_stick = std::atoi(a) != 0;
            else if (!std::strcmp(key, "AimInvertY")) config.aim_invert_y = std::atoi(a) != 0;
            else if (!std::strcmp(key, "StickThreshold")) config.stick_threshold = std::clamp(std::atoi(a), 20, 90);
            else if (!std::strcmp(key, "Widescreen")) config.widescreen = std::atoi(a) != 0;
            else if (!std::strcmp(key, "Cutscene4x3")) config.cutscene_4x3 = std::atoi(a) != 0;
            else if (!std::strcmp(key, "Language")) file_language = std::clamp(std::atoi(a), 0, 5);
            else if (!std::strcmp(key, "LanguageChosen")) config.language_chosen = std::atoi(a) != 0;
            else if (!std::strcmp(key, "Censored")) config.censored = std::atoi(a) != 0;
            else if (!std::strcmp(key, "FrameRate60")) { config.native60 = std::atoi(a) != 0; have_frame_rate = true; }
            // Up to 1.x the Frame rate setting was frame interpolation: on there means 60 now.
            else if (!std::strcmp(key, "Interpolation")) old_interpolation = std::atoi(a) != 0;
            else if (!std::strcmp(key, "CameraAvoidWalls")) config.camera_avoid_walls = std::atoi(a) != 0;
            else if (!std::strcmp(key, "SkipIntro")) config.skip_intro = std::atoi(a) != 0;
            else if (!std::strcmp(key, "InfiniteHealth")) config.cheat_health = std::atoi(a) != 0;
            else if (!std::strcmp(key, "InfiniteLives")) config.cheat_lives = std::atoi(a) != 0;
            else if (!std::strcmp(key, "MaxCash")) config.cheat_cash = std::atoi(a) != 0;
            else if (!std::strcmp(key, "CutsceneSkip")) config.cutscene_skip = std::clamp(std::atoi(a), 0, 2);
        }
        std::fclose(f);
        if (config.language_chosen && file_language >= 0) config.language = file_language;
        if (!have_frame_rate && old_interpolation) config.native60 = true;
    }

    bool save() {
        std::remove(path); // Vita3K and the Vita keep a rewritten file's old tail
        FILE* f = std::fopen(path, "w");
        if (f == nullptr) {
            return false;
        }
        std::fprintf(f, "# Conker's Bad Fur Day: Recompiled (PS Vita) controls.\n"
                        "# N64 input = Vita input[, second Vita input]. Inputs: ");
        for (int i = 1; i < (int)Input::Count; i++) {
            std::fprintf(f, "%s%s", input_names[i], i + 1 < (int)Input::Count ? " " : "\n");
        }
        for (int i = 0; i < (int)N64::Count; i++) {
            const Input a = config.bindings[i][0], b = config.bindings[i][1];
            if (b != Input::None) std::fprintf(f, "%s = %s, %s\n", n64_names[i], input_names[(int)a], input_names[(int)b]);
            else std::fprintf(f, "%s = %s\n", n64_names[i], input_names[(int)a]);
        }
        std::fprintf(f, "Stick = %s\nDeadzone = %d\nSensitivity = %d\nInvertX = %d\nInvertY = %d\nInvertOtherX = %d\nInvertOtherY = %d\nStickThreshold = %d\nWidescreen = %d\nCutscene4x3 = %d\nCutsceneSkip = %d\nLanguage = %d\nLanguageChosen = %d\nCensored = %d\nFrameRate60 = %d\nSkipIntro = %d\nInfiniteHealth = %d\nInfiniteLives = %d\nMaxCash = %d\nAimInvertX = %d\nAimInvertY = %d\nAimCameraStick = %d\nCameraAvoidWalls = %d\n",
            config.stick == StickSource::Right ? "Right" : "Left", config.deadzone, config.sensitivity,
            config.invert_x ? 1 : 0, config.invert_y ? 1 : 0, config.invert_other_x ? 1 : 0, config.invert_other_y ? 1 : 0, config.stick_threshold, config.widescreen ? 1 : 0,
            config.cutscene_4x3 ? 1 : 0, config.cutscene_skip, config.language, config.language_chosen ? 1 : 0, config.censored ? 1 : 0, config.native60 ? 1 : 0,
            config.skip_intro ? 1 : 0, config.cheat_health ? 1 : 0, config.cheat_lives ? 1 : 0, config.cheat_cash ? 1 : 0,
            config.aim_invert_x ? 1 : 0, config.aim_invert_y ? 1 : 0, config.aim_camera_stick ? 1 : 0, config.camera_avoid_walls ? 1 : 0);
        std::fclose(f);
        return true;
    }
}

namespace conker {
    // The Vita's 960x544 over the N64's 4:3, when the widescreen setting is on.
    float vita_widescreen_ratio() {
        return vita::controls::current().widescreen ? (960.0f / 544.0f) / (4.0f / 3.0f) : 1.0f;
    }

    // Cutscenes in 4:3 (cutscene_aspect.cpp): the setting on, in widescreen.
    bool vita_cutscene_4x3() {
        return vita::controls::current().widescreen && vita::controls::current().cutscene_4x3;
    }

    int cutscene_skip_mode() {
        return vita::controls::current().cutscene_skip;
    }

    int text_language() {
        return vita::controls::current().language;
    }

    bool text_censored() {
        return vita::controls::current().censored;
    }

    // Frames drawn between the game's (vita_renderer.cpp): no longer in the menu (real 60,
    // native60.cpp, replaced it); only with ux0:data/conker/debug_interpolation, and only
    // while the game runs at 30.
    bool vita_interpolation() {
        static const bool debug = [] {
            FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_interpolation", "r");
            if (f != nullptr) std::fclose(f);
            return f != nullptr;
        }();
        return debug && !vita::controls::current().native60;
    }

    bool vita_skip_intro() { return vita::controls::current().skip_intro; }
    bool vita_cheat_health() { return vita::controls::current().cheat_health; }
    bool vita_cheat_lives() { return vita::controls::current().cheat_lives; }
    bool vita_cheat_cash() { return vita::controls::current().cheat_cash; }
    bool vita_aim_invert_x() { return vita::controls::current().aim_invert_x; }
    bool vita_aim_invert_y() { return vita::controls::current().aim_invert_y; }
    void vita_note_aiming() { vita::controls::last_aim_us.store(sceKernelGetProcessTimeWide(), std::memory_order_relaxed); }
}
