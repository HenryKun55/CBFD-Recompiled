#ifndef __CONKER_VITA_BUTTON_ART_HPP__
#define __CONKER_VITA_BUTTON_ART_HPP__

#include <cstdint>

// Vita button pictures drawn in code (no image files): the face buttons in their symbol
// colours, L/R, START/SELECT, the d-pad, the sticks (with a direction) and the touch pads,
// at whatever size an N64 icon they stand in for has (button_icons.cpp). No platform
// dependencies, so vita/tools/button_icons_preview.cpp draws them on a desktop too.
namespace conker::vita::button_art {
    enum class Art : uint8_t {
        Cross, Circle, Square, Triangle,
        L, R, L1, R1, Start, Select,
        DPad,          // dir: the arm
        LStick, RStick, // dir: 0 the stick itself, else its direction
        L3, R3,        // a stick pressed in
        RearTouch, FrontTouch, // dir: the corner (1 top left, 2 top right, 3 bottom left, 4 bottom right)
        Count
    };
    enum Dir : uint8_t { DirNone, DirUp, DirDown, DirLeft, DirRight };

    // Where in the texture the picture goes (the original icon's own outline), in texels.
    struct Box { float x0, y0, x1, y1; };

    // Draws art into px (w x h, 0xAABBGGRR, cleared first). knob: a stick's knob pushed sideways
    // by that many texels (the N64 stick icon's animation).
    void draw(uint32_t* px, int w, int h, Box box, Art art, int dir, float knob = 0.0f);

    // The context-sensitive pads' wooden "B" (a raised greenish letter on an octagon of wood
    // rings, 64 x 64): the letter carved off (wood rings put back from the same ring) and a
    // face button's symbol raised in its place, in the letter's own texels. False (px kept)
    // for anything but a face button.
    bool carve_pad(uint32_t* px, int w, int h, Art art);
}

#endif
