#ifndef __CONKER_VITA_MENU_HPP__
#define __CONKER_VITA_MENU_HPP__

#include <cstdint>
#include <string>
#include <vector>

#include "controls.hpp"

// The compiled shaders on the memory card (by vitaGL build: another's binaries don't fit).
#define CONKER_SHADER_CACHE_DIR "shader_cache_v2"

// The in-game menu (START + SELECT): controls remapping, the stick's settings, a debug
// page, and quitting.
namespace conker::vita::menu {
    // Something to draw, in screen pixels (960x544).
    struct Item {
        enum Kind : uint8_t { Rect, Text } kind;
        float x, y, w, h;   // a rect's box; a text's position (w = scale)
        uint32_t color;     // 0xRRGGBBAA
        std::string text;
    };

    // From the input poll: updates the menu with the Vita's state. While it's open the
    // game sees no input.
    void update(const controls::VitaState& state);
    bool is_open();
    // Whether the player chose to quit.
    bool quit_requested();
    // The renderer's debug flags chosen on the Debug page (see vita_renderer.cpp).
    uint32_t debug_flags();
    // What to draw now (empty when closed).
    std::vector<Item> draw_list();
}

#endif
