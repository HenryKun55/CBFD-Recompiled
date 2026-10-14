// The in-game menu (menu.hpp).
//
// It reads the Vita's buttons directly (not through the remapping), so it always works:
// D-pad or left stick to move, Cross to choose, Circle to go back, START + SELECT to
// open and close it.

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <filesystem>
#include <mutex>

#include <psp2/kernel/processmgr.h>

#include "menu.hpp"
#include "vita_platform.hpp"

namespace conker::vita::menu {
    namespace {
        using namespace controls;

        enum class Page { Main, Controls, Stick, Debug };

        std::mutex mutex;
        bool open = false;
        std::atomic<bool> quit{false};
        void set_status(const std::string& text);
        std::atomic<uint32_t> renderer_flags{0};
        std::atomic<bool> capture_requested{false}; // the Debug page's "Capture 5 seconds"
        int output_mode = 0; // 0 normal, 1 texture only, 2 shade only, 3 without the blender
        const char* const output_names[] = { "Normal", "Texture only", "Shade only", "No blender" };
        constexpr int debug_count = 11;

        void set_flag(uint32_t bit, bool on) {
            uint32_t f = renderer_flags.load();
            renderer_flags = on ? (f | bit) : (f & ~bit);
        }
        void set_output(int mode) {
            output_mode = (mode + 4) % 4;
            uint32_t f = renderer_flags.load() & ~(32u | 64u | 128u);
            if (output_mode == 1) f |= 32;
            if (output_mode == 2) f |= 64;
            if (output_mode == 3) f |= 128;
            renderer_flags = f;
        }
        void debug_action(int item, int dir) {
            const uint32_t f = renderer_flags.load();
            switch (item) {
                case 0: set_flag(4, !(f & 4)); break;
                case 1: set_flag(2, !(f & 2)); break;
                case 2: set_output(output_mode + dir); break;
                case 3: set_flag(256, !(f & 256)); break;
                case 4: set_flag(512, !(f & 512)); break;
                case 7: set_flag(131072, !(f & 131072)); break;
                case 8: set_flag(262144, !(f & 262144)); break;
                case 9: set_flag(524288, !(f & 524288)); break;
                case 10: set_flag(1048576, !(f & 1048576)); break;
                case 5:
                    capture_requested = true;
                    set_status("Capturing 5 seconds once you close the menu...");
                    break;
                case 6: {
                    std::error_code ec;
                    std::filesystem::remove_all(CONKER_VITA_DATA_DIR "/" CONKER_SHADER_CACHE_DIR, ec);
                    std::filesystem::remove_all(CONKER_VITA_DATA_DIR "/shader_cache", ec);
                    std::filesystem::remove_all(CONKER_VITA_DATA_DIR "/gxm_shader_cache", ec);
                    set_status("Shader cache cleared (rebuilt as shaders are needed).");
                    break;
                }
            }
        }
        Page page = Page::Main;
        int cursor = 0;
        int slot = 0;            // the binding column on the controls page
        bool capturing = false;  // waiting for an input to bind
        bool capture_armed = false; // every input released since the capture started
        uint64_t capture_start = 0;
        std::string status;      // a line of feedback at the bottom
        uint64_t status_until = 0;
        uint32_t previous_buttons = 0;
        bool combo_was_held = false;
        uint64_t repeat_at = 0;
        uint32_t repeat_button = 0;

        uint64_t now_us() { return sceKernelGetProcessTimeWide(); }

        void set_status(const std::string& text) {
            status = text;
            status_until = now_us() + 3000000;
        }

        // The menu's own buttons, with the left stick acting as the D-pad and held
        // directions repeating.
        uint32_t menu_buttons(const VitaState& s) {
            uint32_t b = s.pad.buttons;
            if (s.pad.ly < 50) b |= SCE_CTRL_UP;
            if (s.pad.ly > 206) b |= SCE_CTRL_DOWN;
            if (s.pad.lx < 50) b |= SCE_CTRL_LEFT;
            if (s.pad.lx > 206) b |= SCE_CTRL_RIGHT;
            return b;
        }

        static const char* const language_names[] = { "English", "Portugues (Brasil)", "Espanol", "Francais", "Deutsch", "Italiano" };
        const char* main_items[] = { "Resume", "Controls", "Analog stick", "Widescreen", "Cutscenes", "Skip cutscenes (L)", "Language (text)", "Censorship", "Reset controls to defaults", "Debug", "Quit game" };
        constexpr int main_count = 11;
        const char* skip_names[] = { "Watched ones (original)", "Any", "Any, even unskippable" };
        constexpr int stick_count = 6;

        int item_count() {
            switch (page) {
                case Page::Main: return main_count;
                case Page::Controls: return (int)N64::Count;
                case Page::Stick: return stick_count;
                case Page::Debug: return debug_count;
            }
            return 0;
        }

        void close_menu() {
            open = false;
            capturing = false;
            if (!save()) {
                std::fprintf(stderr, "[menu] couldn't save the controls\n");
            }
        }

        void adjust_stick(int item, int dir) {
            Config& c = current();
            switch (item) {
                case 0: c.stick = c.stick == StickSource::Left ? StickSource::Right : StickSource::Left; break;
                case 1: c.deadzone = std::clamp(c.deadzone + dir * 2, 0, 60); break;
                case 2: c.sensitivity = std::clamp(c.sensitivity + dir * 5, 50, 200); break;
                case 3: c.invert_x = !c.invert_x; break;
                case 4: c.invert_y = !c.invert_y; break;
                case 5: c.stick_threshold = std::clamp(c.stick_threshold + dir * 5, 20, 90); break;
            }
        }

        void press(uint32_t button) {
            const int count = item_count();
            if (button == SCE_CTRL_UP) cursor = (cursor + count - 1) % count;
            else if (button == SCE_CTRL_DOWN) cursor = (cursor + 1) % count;
            else if (page == Page::Controls && (button == SCE_CTRL_LEFT || button == SCE_CTRL_RIGHT)) slot ^= 1;
            else if (page == Page::Stick && (button == SCE_CTRL_LEFT || button == SCE_CTRL_RIGHT)) adjust_stick(cursor, button == SCE_CTRL_LEFT ? -1 : 1);
            else if (page == Page::Main && cursor >= 4 && cursor <= 7 && (button == SCE_CTRL_LEFT || button == SCE_CTRL_RIGHT)) {
                if (cursor == 4) current().cutscene_4x3 = !current().cutscene_4x3;
                else if (cursor == 5) current().cutscene_skip = (current().cutscene_skip + (button == SCE_CTRL_LEFT ? 2 : 1)) % 3;
                else if (cursor == 6) current().language = (current().language + (button == SCE_CTRL_LEFT ? 5 : 1)) % 6;
                else current().censored = !current().censored;
                save();
            }
            else if (page == Page::Debug && (button == SCE_CTRL_LEFT || button == SCE_CTRL_RIGHT) && cursor != 5 && cursor != 6) debug_action(cursor, button == SCE_CTRL_LEFT ? -1 : 1);
            else if (button == SCE_CTRL_CIRCLE) {
                if (page == Page::Main) close_menu();
                else { cursor = page == Page::Controls ? 1 : page == Page::Stick ? 2 : 9; page = Page::Main; save(); }
            }
            else if (button == SCE_CTRL_TRIANGLE && page == Page::Controls) {
                current().bindings[cursor][slot] = Input::None;
            }
            else if (button == SCE_CTRL_CROSS) {
                if (page == Page::Main) {
                    switch (cursor) {
                        case 0: close_menu(); break;
                        case 1: page = Page::Controls; cursor = 0; slot = 0; break;
                        case 2: page = Page::Stick; cursor = 0; break;
                        case 3: current().widescreen = !current().widescreen; save(); break;
                        case 4: current().cutscene_4x3 = !current().cutscene_4x3; save(); break;
                        case 5: current().cutscene_skip = (current().cutscene_skip + 1) % 3; save(); break;
                        case 6: current().language = (current().language + 1) % 6; current().language_chosen = true; save(); break;
                        case 7: current().censored = !current().censored; save(); break;
                        case 8: {
                            const Config kept = current();
                            current() = defaults();
                            current().widescreen = kept.widescreen;
                            current().cutscene_4x3 = kept.cutscene_4x3;
                            current().cutscene_skip = kept.cutscene_skip;
                            current().language = kept.language;
                            current().language_chosen = kept.language_chosen;
                            current().censored = kept.censored;
                            save();
                            set_status("Controls reset to the defaults.");
                            break;
                        }
                        case 9: page = Page::Debug; cursor = 0; break;
                        case 10: quit = true; break;
                    }
                }
                else if (page == Page::Controls) {
                    capturing = true;
                    capture_armed = false;
                    capture_start = now_us();
                }
                else if (page == Page::Stick) {
                    adjust_stick(cursor, 1);
                }
                else if (page == Page::Debug) {
                    debug_action(cursor, 1);
                }
            }
        }

        std::string padded(const std::string& s, size_t n) {
            return s.size() >= n ? s : s + std::string(n - s.size(), ' ');
        }
    }

    void update(const VitaState& state) {
        std::lock_guard lock{mutex};
        const uint32_t held_buttons = state.pad.buttons;
        const bool combo = (held_buttons & (SCE_CTRL_START | SCE_CTRL_SELECT)) == (SCE_CTRL_START | SCE_CTRL_SELECT);
        if (combo && !combo_was_held) {
            if (open) {
                close_menu();
            }
            else {
                open = true;
                page = Page::Main;
                cursor = 0;
            }
            combo_was_held = true;
            previous_buttons = menu_buttons(state);
            return;
        }
        combo_was_held = combo;
        if (!open) {
            return;
        }

        if (capturing) {
            // First everything must be let go (the Cross that started it), then the first
            // input pressed is bound. Nothing in 6 seconds cancels.
            const Input in = first_held(current(), state);
            if (!capture_armed) {
                capture_armed = in == Input::None;
            }
            else if (in != Input::None) {
                current().bindings[cursor][slot] = in;
                capturing = false;
                set_status(std::string(n64_name((N64)cursor)) + " is now " + input_name(in) + ".");
            }
            if (capturing && now_us() - capture_start > 6000000) {
                capturing = false;
                set_status("Nothing was pressed: unchanged.");
            }
            previous_buttons = menu_buttons(state);
            return;
        }

        const uint32_t buttons = menu_buttons(state);
        const uint32_t pressed = buttons & ~previous_buttons;
        previous_buttons = buttons;
        static const uint32_t order[] = { SCE_CTRL_UP, SCE_CTRL_DOWN, SCE_CTRL_LEFT, SCE_CTRL_RIGHT,
                                          SCE_CTRL_CROSS, SCE_CTRL_CIRCLE, SCE_CTRL_TRIANGLE };
        for (uint32_t b : order) {
            if (pressed & b) {
                press(b);
                repeat_button = b;
                repeat_at = now_us() + 400000;
            }
        }
        // Held directions repeat.
        if (repeat_button && (buttons & repeat_button) && repeat_button <= SCE_CTRL_LEFT && now_us() >= repeat_at) {
            press(repeat_button);
            repeat_at = now_us() + 90000;
        }
        if (!(buttons & repeat_button)) {
            repeat_button = 0;
        }
    }

    bool is_open() {
        std::lock_guard lock{mutex};
        return open;
    }

    bool quit_requested() {
        return quit.load();
    }

    uint32_t debug_flags() {
        return renderer_flags.load();
    }

    bool take_capture_request() {
        return capture_requested.exchange(false);
    }

    std::vector<Item> draw_list() {
        std::lock_guard lock{mutex};
        std::vector<Item> items;
        if (!open) {
            return items;
        }
        const float x0 = 150, y0 = 40, w = 660, h = 464;
        items.push_back({ Item::Rect, 0, 0, 960, 544, 0x00000090, "" });
        items.push_back({ Item::Rect, x0, y0, w, h, 0x1A1A24F0, "" });
        auto text = [&](float x, float y, const std::string& s, uint32_t color, float scale = 0.8f) {
            items.push_back({ Item::Text, x, y, scale, 0, color, s });
        };
        const char* titles[] = { "Conker's Bad Fur Day", "Controls", "Analog stick", "Debug" };
        text(x0 + 24, y0 + 16, titles[(int)page], 0xFFC34DFF, 1.0f);

        const float row_h = page == Page::Controls ? 24.0f : (page == Page::Main || page == Page::Debug) ? 30.0f : 34.0f;
        const float list_y = y0 + (page == Page::Controls ? 82 : 62);
        auto row_highlight = [&](int i) {
            items.push_back({ Item::Rect, x0 + 12, list_y + i * row_h - 3, w - 24, row_h, 0x3A3A55FF, "" });
        };

        if (page == Page::Main) {
            for (int i = 0; i < main_count; i++) {
                if (i == cursor) row_highlight(i);
                text(x0 + 30, list_y + i * row_h, main_items[i], i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF);
                if (i == 3) {
                    text(x0 + 360, list_y + i * row_h, current().widescreen ? "16:9" : "4:3 (original)", i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF);
                }
                const char* value = i == 4 ? (!current().widescreen ? "4:3 (as the game)" : current().cutscene_4x3 ? "4:3 (original)" : "16:9")
                                  : i == 5 ? skip_names[current().cutscene_skip]
                                  : i == 6 ? language_names[std::clamp(current().language, 0, 5)]
                                  : i == 7 ? (current().censored ? "On (symbols)" : "Off (swear words)") : nullptr;
                if (value) {
                    text(x0 + 360, list_y + i * row_h, value, i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF);
                }
            }
            text(x0 + 24, y0 + h - 70, "Cross: choose    Circle: back    START+SELECT: close", 0x8888A0FF, 0.62f);
            text(x0 + 24, y0 + h - 44, "Tip: pause the game (START) before changing settings.", 0x8888A0FF, 0.62f);
        }
        else if (page == Page::Controls) {
            const Config& c = current();
            text(x0 + 30, list_y - 24, "N64", 0x8888A0FF, 0.62f);
            text(x0 + 200, list_y - 24, "Vita (1)", 0x8888A0FF, 0.62f);
            text(x0 + 420, list_y - 24, "Vita (2)", 0x8888A0FF, 0.62f);
            for (int i = 0; i < (int)N64::Count; i++) {
                const float y = list_y + i * row_h;
                if (i == cursor) {
                    row_highlight(i);
                    items.push_back({ Item::Rect, x0 + (slot == 0 ? 190 : 410), y - 3, 210, row_h, 0x5A5A90FF, "" });
                }
                const uint32_t col = i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF;
                text(x0 + 30, y, n64_name((N64)i), col, 0.68f);
                for (int k = 0; k < 2; k++) {
                    std::string name = c.bindings[i][k] == Input::None ? "-" : input_name(c.bindings[i][k]);
                    if (capturing && i == cursor && k == slot) name = "press...";
                    text(x0 + (k == 0 ? 200 : 420), y, name, col, 0.68f);
                }
            }
            text(x0 + 24, y0 + h - 30, "Cross: bind  Left/Right: column  Triangle: clear  Circle: back", 0x8888A0FF, 0.6f);
        }
        else if (page == Page::Debug) {
            const uint32_t f = renderer_flags.load();
            const std::string rows[debug_count][2] = {
                { "Depth test", (f & 4) ? "Off" : "On" },
                { "Back-face culling", (f & 2) ? "Off" : "On" },
                { "Colour output", output_names[output_mode] },
                { "Wait for the GPU each frame", (f & 256) ? "On" : "Off" },
                { "Log the water (each frame)", (f & 512) ? "On" : "Off" },
                { "Capture 5 seconds (for Claude)", "" },
                { "Clear shader cache", "" },
                { "Draw shadows", (f & 131072) ? "Off" : "On" },
                { "Decal depth bias", (f & 262144) ? "Strong" : "Normal" },
                { "Perf test: skip triangles", (f & 524288) ? "On" : "Off" },
                { "Perf test: skip texture loads", (f & 1048576) ? "On" : "Off" },
            };
            for (int i = 0; i < debug_count; i++) {
                if (i == cursor) row_highlight(i);
                const uint32_t col = i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF;
                text(x0 + 30, list_y + i * row_h, rows[i][0], col);
                text(x0 + 360, list_y + i * row_h, rows[i][1], col);
            }
            text(x0 + 24, y0 + h - 70, "Cross / Left/Right: change    Circle: back", 0x8888A0FF, 0.62f);
            text(x0 + 24, y0 + h - 44, "For finding rendering problems; not saved.", 0x8888A0FF, 0.62f);
        }
        else {
            const Config& c = current();
            char buf[64];
            std::string rows[stick_count];
            rows[0] = padded("N64 stick from", 22) + stick_name(c.stick);
            std::snprintf(buf, sizeof(buf), "%d%%", c.deadzone); rows[1] = padded("Dead zone", 22) + buf;
            std::snprintf(buf, sizeof(buf), "%d%%", c.sensitivity); rows[2] = padded("Sensitivity", 22) + buf;
            rows[3] = padded("Invert X", 22) + (c.invert_x ? "On" : "Off");
            rows[4] = padded("Invert Y", 22) + (c.invert_y ? "On" : "Off");
            std::snprintf(buf, sizeof(buf), "%d%%", c.stick_threshold); rows[5] = padded("Stick as buttons at", 22) + buf;
            for (int i = 0; i < stick_count; i++) {
                if (i == cursor) row_highlight(i);
                const size_t split = rows[i].find_first_not_of(' ', 22) == std::string::npos ? 22 : 22;
                text(x0 + 30, list_y + i * row_h, rows[i].substr(0, split), i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF);
                text(x0 + 360, list_y + i * row_h, rows[i].substr(split), i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF);
            }
            text(x0 + 24, y0 + h - 70, "Left/Right: change    Circle: back", 0x8888A0FF, 0.62f);
            text(x0 + 24, y0 + h - 44, "The other stick's directions can be bound to buttons.", 0x8888A0FF, 0.62f);
        }
        if (!status.empty() && now_us() < status_until) {
            text(x0 + 24, y0 + h - 100, status, 0x7CE38BFF, 0.7f);
        }
        return items;
    }
}
