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

    // The context-sensitive pads on the ground ("another one of those B buttons!"): what they're made of.
    enum class PadKind : uint8_t {
        Wood,  // a raised greenish "B" on wood rings (an octagon; a hexagon in two halves)
        Stone, // a disc with the "B" cut in its outline, grey-blue (in two halves)
        Count
    };
    // A texture that's (part of) a pad's picture.
    struct PadPiece {
        PadKind kind;
        int x, y;          // where the texture lies in the pad's picture
        int pad_w, pad_h;  // the whole picture
        Box letter;        // the "B"'s box in the picture
    };
    // A pad's "B" taken off (the material put back from around it) and the input's glyph
    // (art, dir as for draw) put in its place in the material's style: raised wood with its
    // shadow, or a groove cut in the stone. False (px kept) if the texture isn't as expected.
    bool carve_pad(uint32_t* px, int w, int h, const PadPiece& pad, Art art, int dir);

    // Every pad texture known: the hash of its decoded texels (button_icons.cpp), its size, its piece.
    struct PadTexture { uint32_t hash; int w, h; PadPiece piece; };
    extern const PadTexture pad_textures[];
    extern const int pad_texture_count;
}

#endif
