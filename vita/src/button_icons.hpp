#ifndef __CONKER_VITA_BUTTON_ICONS_HPP__
#define __CONKER_VITA_BUTTON_ICONS_HPP__

#include <cstdint>

// The game's N64 button icons (the A/B/Z/START/C/stick pictures in speech bubbles, the hint
// book and the menus: text codes 0xA8 and on, drawn as textures by func_150417AC) redrawn as
// the Vita buttons the player has bound to them. The renderer hands each texture it decodes
// to replace(); one whose texels are an original icon's is redrawn in place, same size.
namespace conker::vita::button_icons {
    // texels: w x h, 0xAABBGGRR. True when they were an icon's and now show the Vita button.
    bool replace(uint32_t* texels, uint32_t w, uint32_t h);
    // Changes when the bindings do (mixed into the texture cache's keys so icons are redrawn).
    uint32_t generation();
}

#endif
