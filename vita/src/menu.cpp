// The in-game menu (menu.hpp).
//
// It reads the Vita's buttons directly (not through the remapping), so it always works:
// D-pad or left stick to move, Cross to choose, Circle to go back, SELECT twice to
// open and close it.
//
// The main page leads to a page for each kind of setting (picture, buttons, sticks and aiming,
// the game, cheats, debug). Every page but the buttons' is a table of rows: a label, the value
// shown, and what Left/Right and Cross do.

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <filesystem>
#include <functional>
#include <mutex>

#include <psp2/kernel/processmgr.h>

#include "menu.hpp"
#include "vita_platform.hpp"

namespace conker::vita::menu {
    namespace {
        using namespace controls;

        enum class Page { Main, Display, Controls, Sticks, Game, Cheats, Debug, Count };

        std::mutex mutex;
        bool open = false;
        std::atomic<bool> quit{false};
        void set_status(const std::string& text);
        std::atomic<uint32_t> renderer_flags{0};
        std::atomic<bool> capture_requested{false}; // the Debug page's "Capture 5 seconds"
        int output_mode = 0; // 0 normal, 1 texture only, 2 shade only, 3 without the blender
        const char* const output_names[] = { "Normal", "Texture only", "Shade only", "No blender" };

        Page page = Page::Main;
        int cursor = 0;
        int slot = 0;            // the binding column on the controls page
        bool capturing = false;  // waiting for an input to bind
        bool capture_armed = false; // every input released since the capture started
        uint64_t capture_start = 0;
        std::string status;      // a line of feedback at the bottom
        uint64_t status_until = 0;
        uint32_t previous_buttons = 0;
        bool select_was_held = false;
        uint64_t last_select_us = 0;
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

        void set_flag(uint32_t bit, bool on) {
            uint32_t f = renderer_flags.load();
            renderer_flags = on ? (f | bit) : (f & ~bit);
        }
        void toggle_flag(uint32_t bit) { set_flag(bit, !(renderer_flags.load() & bit)); }
        void set_output(int mode) {
            output_mode = (mode + 4) % 4;
            uint32_t f = renderer_flags.load() & ~(32u | 64u | 128u);
            if (output_mode == 1) f |= 32;
            if (output_mode == 2) f |= 64;
            if (output_mode == 3) f |= 128;
            renderer_flags = f;
        }

        void close_menu() {
            open = false;
            capturing = false;
            if (!save()) {
                std::fprintf(stderr, "[menu] couldn't save the controls\n");
            }
        }

        // Back to the defaults: the buttons and the sticks (aiming included). The picture, the
        // game's settings and the cheats are kept.
        void reset_controls() {
            const Config kept = current();
            current() = defaults();
            current().widescreen = kept.widescreen;
            current().cutscene_4x3 = kept.cutscene_4x3;
            current().cutscene_skip = kept.cutscene_skip;
            current().language = kept.language;
            current().language_chosen = kept.language_chosen;
            current().censored = kept.censored;
            current().native60 = kept.native60;
            current().camera_avoid_walls = kept.camera_avoid_walls;
            current().skip_intro = kept.skip_intro;
            current().cheat_health = kept.cheat_health;
            current().cheat_lives = kept.cheat_lives;
            current().cheat_cash = kept.cheat_cash;
            save();
            set_status("Buttons and sticks reset to the defaults.");
        }

        std::string on_off(bool on) { return on ? "On" : "Off"; }
        std::string percent(int n) { char b[16]; std::snprintf(b, sizeof(b), "%d%%", n); return b; }

        // A row: its label, the value shown (none: an action or a page), and what Left/Right
        // (dir -1 or 1) and Cross (dir 0) do.
        struct Row {
            const char* label;
            std::function<std::string()> value;
            std::function<void(int dir)> change;
            bool opens_page = false; // shown with a ">"
        };

        // Cross opens a page; Circle there comes back to the row that opened it.
        Row open_page(const char* label, Page to) {
            return { label, nullptr, [to](int dir) { if (dir == 0) { page = to; cursor = 0; slot = 0; } }, true };
        }
        // A setting: Cross and Left/Right both change it (dir 0 as forward), then it's saved.
        Row setting(const char* label, std::function<std::string()> value, std::function<void(int dir)> change) {
            return { label, std::move(value), [change](int dir) { change(dir == 0 ? 1 : dir); save(); } };
        }
        Row toggle(const char* label, bool Config::* field, const char* on = "On", const char* off = "Off") {
            return setting(label, [=] { return std::string(current().*field ? on : off); },
                           [=](int) { current().*field = !(current().*field); });
        }
        Row action(const char* label, std::function<void()> run) {
            return { label, nullptr, [run](int dir) { if (dir == 0) run(); } };
        }

        static const char* const language_names[] = { "English", "Portugues (Brasil)", "Espanol", "Francais", "Deutsch", "Italiano" };
        static const char* const skip_names[] = { "Watched ones (original)", "Any", "Any, even unskippable" };

        const std::vector<Row>& rows(Page p) {
            static const std::vector<Row> main_rows = {
                action("Resume", [] { close_menu(); }),
                open_page("Picture", Page::Display),
                open_page("Buttons", Page::Controls),
                open_page("Sticks and aiming", Page::Sticks),
                open_page("Game", Page::Game),
                open_page("Cheats", Page::Cheats),
                action("Reset buttons and sticks", [] { reset_controls(); }),
                open_page("Debug", Page::Debug),
                action("Quit game", [] { quit = true; }),
            };
            static const std::vector<Row> display_rows = {
                toggle("Widescreen", &Config::widescreen, "16:9", "4:3 (original)"),
                setting("Cutscenes", [] {
                    return std::string(!current().widescreen ? "4:3 (as the game)" : current().cutscene_4x3 ? "4:3 (original)" : "16:9");
                }, [](int) { current().cutscene_4x3 = !current().cutscene_4x3; }),
                toggle("Frame rate", &Config::native60, "60", "30 (original)"),
            };
            static const std::vector<Row> stick_rows = {
                setting("Movement stick", [] { return std::string(stick_name(current().stick)); },
                        [](int) { current().stick = current().stick == StickSource::Left ? StickSource::Right : StickSource::Left; }),
                setting("Dead zone", [] { return percent(current().deadzone); },
                        [](int dir) { current().deadzone = std::clamp(current().deadzone + dir * 2, 0, 60); }),
                setting("Sensitivity", [] { return percent(current().sensitivity); },
                        [](int dir) { current().sensitivity = std::clamp(current().sensitivity + dir * 5, 50, 200); }),
                toggle("Movement stick invert X", &Config::invert_x),
                toggle("Movement stick invert Y", &Config::invert_y),
                setting("Camera stick press at", [] { return percent(current().stick_threshold); },
                        [](int dir) { current().stick_threshold = std::clamp(current().stick_threshold + dir * 5, 20, 90); }),
                toggle("Camera stick invert X", &Config::invert_other_x),
                toggle("Camera stick invert Y", &Config::invert_other_y),
                toggle("Aim with the camera stick", &Config::aim_camera_stick, "On", "Off (original)"),
                toggle("Aiming left/right", &Config::aim_invert_x, "Inverted", "Normal (original)"),
                toggle("Aiming up/down", &Config::aim_invert_y, "Inverted (original)", "Normal"),
                toggle("Camera", &Config::camera_avoid_walls, "Avoids walls", "Original"),
            };
            static const std::vector<Row> game_rows = {
                setting("Language (text)", [] { return std::string(language_names[std::clamp(current().language, 0, 5)]); },
                        [](int dir) { current().language = (current().language + (dir < 0 ? 5 : 1)) % 6; current().language_chosen = true; }),
                toggle("Censorship", &Config::censored, "On (symbols)", "Off (swear words)"),
                setting("Skip cutscenes (L)", [] { return std::string(skip_names[current().cutscene_skip]); },
                        [](int dir) { current().cutscene_skip = (current().cutscene_skip + (dir < 0 ? 2 : 1)) % 3; }),
                toggle("Skip intro", &Config::skip_intro),
            };
            static const std::vector<Row> cheat_rows = {
                toggle("Infinite health", &Config::cheat_health),
                toggle("Infinite lives", &Config::cheat_lives),
                toggle("Max cash", &Config::cheat_cash),
            };
            static const std::vector<Row> debug_rows = {
                { "Depth test", [] { return std::string((renderer_flags.load() & 4) ? "Off" : "On"); }, [](int) { toggle_flag(4); } },
                { "Back-face culling", [] { return std::string((renderer_flags.load() & 2) ? "Off" : "On"); }, [](int) { toggle_flag(2); } },
                { "Colour output", [] { return std::string(output_names[output_mode]); }, [](int dir) { set_output(output_mode + (dir < 0 ? -1 : 1)); } },
                { "Wait for the GPU each frame", [] { return on_off(renderer_flags.load() & 256); }, [](int) { toggle_flag(256); } },
                { "Log the water (each frame)", [] { return on_off(renderer_flags.load() & 512); }, [](int) { toggle_flag(512); } },
                action("Capture 5 seconds (for Claude)", [] {
                    capture_requested = true;
                    set_status("Capturing 5 seconds once you close the menu...");
                }),
                action("Clear shader cache", [] {
                    std::error_code ec;
                    std::filesystem::remove_all(CONKER_VITA_DATA_DIR "/" CONKER_SHADER_CACHE_DIR, ec);
                    std::filesystem::remove_all(CONKER_VITA_DATA_DIR "/shader_cache", ec);
                    std::filesystem::remove_all(CONKER_VITA_DATA_DIR "/gxm_shader_cache", ec);
                    set_status("Shader cache cleared (rebuilt as shaders are needed).");
                }),
                { "Draw shadows", [] { return std::string((renderer_flags.load() & 131072) ? "Off" : "On"); }, [](int) { toggle_flag(131072); } },
                { "Decal depth bias", [] { return std::string((renderer_flags.load() & 262144) ? "Strong" : "Normal"); }, [](int) { toggle_flag(262144); } },
                { "Perf test: skip triangles", [] { return on_off(renderer_flags.load() & 524288); }, [](int) { toggle_flag(524288); } },
                { "Perf test: skip texture loads", [] { return on_off(renderer_flags.load() & 1048576); }, [](int) { toggle_flag(1048576); } },
            };
            static const std::vector<Row> none;
            switch (p) {
                case Page::Main: return main_rows;
                case Page::Display: return display_rows;
                case Page::Sticks: return stick_rows;
                case Page::Game: return game_rows;
                case Page::Cheats: return cheat_rows;
                case Page::Debug: return debug_rows;
                default: return none;
            }
        }

        // Each page's title, the main page's row that opens it, and its notes at the bottom.
        struct PageInfo { const char* title; int main_row; const char* notes[2]; };
        const PageInfo page_info[(int)Page::Count] = {
            { "Conker's Bad Fur Day", 0, { "Cross: choose    Circle: back    SELECT twice: close",
                                           "Tip: pause the game (START) before changing settings." } },
            { "Picture", 1, { "Left/Right or Cross: change    Circle: back",
                              "Frame rate 60: where a scene is too heavy, it runs at 30." } },
            { "Buttons", 2, { "Cross: bind  Left/Right: column  Triangle: clear  Circle: back", nullptr } },
            { "Sticks and aiming", 3, { "Left/Right or Cross: change    Circle: back",
                                        "Aiming: hold R, the scope, the slingshot, the guns." } },
            { "Game", 4, { "Left/Right or Cross: change    Circle: back",
                           "Skip intro: from the next start, the game opens at the bar." } },
            { "Cheats", 5, { "Cross: on/off    Circle: back",
                             "Player 1's, as the PC version's Cheats mod." } },
            { "Debug", 7, { "Cross / Left/Right: change    Circle: back",
                            "For finding rendering problems; not saved." } },
        };

        int item_count() {
            return page == Page::Controls ? (int)N64::Count : (int)rows(page).size();
        }

        void press(uint32_t button) {
            const int count = item_count();
            const bool left_right = button == SCE_CTRL_LEFT || button == SCE_CTRL_RIGHT;
            if (button == SCE_CTRL_UP) cursor = (cursor + count - 1) % count;
            else if (button == SCE_CTRL_DOWN) cursor = (cursor + 1) % count;
            else if (button == SCE_CTRL_CIRCLE) {
                if (page == Page::Main) close_menu();
                else { cursor = page_info[(int)page].main_row; page = Page::Main; save(); }
            }
            else if (page == Page::Controls) {
                if (left_right) slot ^= 1;
                else if (button == SCE_CTRL_TRIANGLE) current().bindings[cursor][slot] = Input::None;
                else if (button == SCE_CTRL_CROSS) {
                    capturing = true;
                    capture_armed = false;
                    capture_start = now_us();
                }
            }
            else {
                const Row& row = rows(page)[cursor];
                // Left/Right only change values (not open pages or run actions).
                if (left_right && row.value) row.change(button == SCE_CTRL_LEFT ? -1 : 1);
                else if (button == SCE_CTRL_CROSS) row.change(0);
            }
        }
    }

    void update(const VitaState& state) {
        std::lock_guard lock{mutex};
        const uint32_t held_buttons = state.pad.buttons;
        // SELECT pressed twice (within 0.4 s) opens and closes it, as the author's other ports
        // do (START + SELECT pressed START on the way: the game paused).
        const bool select = (held_buttons & SCE_CTRL_SELECT) != 0;
        if (select && !select_was_held && !capturing) {
            const uint64_t t = now_us();
            if (t - last_select_us < 400000) {
                last_select_us = 0;
                if (open) {
                    close_menu();
                }
                else {
                    open = true;
                    page = Page::Main;
                    cursor = 0;
                }
                select_was_held = true;
                previous_buttons = menu_buttons(state);
                return;
            }
            last_select_us = t;
        }
        select_was_held = select;
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
        const PageInfo& info = page_info[(int)page];
        text(x0 + 24, y0 + 16, info.title, 0xFFC34DFF, 1.0f);

        // The rows share what's left between the title and the notes, at most 34 px each.
        const int count = item_count();
        const float list_y = y0 + (page == Page::Controls ? 82 : 62);
        const float list_bottom = y0 + h - (page == Page::Controls ? 40 : 110);
        const float row_h = std::min(34.0f, (list_bottom - list_y) / (float)std::max(count, 1));
        auto row_highlight = [&](int i) {
            items.push_back({ Item::Rect, x0 + 12, list_y + i * row_h - 3, w - 24, row_h, 0x3A3A55FF, "" });
        };

        if (page == Page::Controls) {
            const Config& c = current();
            text(x0 + 30, list_y - 24, "Game button (N64)", 0x8888A0FF, 0.62f);
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
            text(x0 + 24, y0 + h - 30, info.notes[0], 0x8888A0FF, 0.6f);
        }
        else {
            const std::vector<Row>& list = rows(page);
            for (int i = 0; i < count; i++) {
                const float y = list_y + i * row_h;
                const uint32_t col = i == cursor ? 0xFFFFFFFF : 0xB8B8C8FF;
                if (i == cursor) row_highlight(i);
                const Row& row = list[i];
                text(x0 + 30, y, row.opens_page ? std::string(row.label) + "  >" : row.label, col);
                if (row.value) text(x0 + 360, y, row.value(), col);
            }
            for (int k = 0; k < 2; k++) {
                if (info.notes[k]) text(x0 + 24, y0 + h - 70 + k * 26, info.notes[k], 0x8888A0FF, 0.62f);
            }
        }
        if (!status.empty() && now_us() < status_until) {
            text(x0 + 24, y0 + h - 100, status, 0x7CE38BFF, 0.7f);
        }
        return items;
    }
}
