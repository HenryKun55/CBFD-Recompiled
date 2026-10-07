#ifndef __CONKER_VITA_CONTROLS_HPP__
#define __CONKER_VITA_CONTROLS_HPP__

#include <cstdint>
#include <string>

#include <psp2/ctrl.h>
#include <psp2/touch.h>

// Remappable controls: each N64 input takes up to two Vita inputs, and the N64's stick
// comes from either Vita stick. Kept in ux0:data/conker/controls.ini.
namespace conker::vita::controls {
    // What the Vita can press.
    enum class Input : uint8_t {
        None,
        Cross, Circle, Square, Triangle,
        L, R, Up, Down, Left, Right, Start, Select,
        L1, R1, L3, R3, // PlayStation TV with a DualShock (L/R are its L2/R2)
        LStickUp, LStickDown, LStickLeft, LStickRight,
        RStickUp, RStickDown, RStickLeft, RStickRight,
        RearTopLeft, RearTopRight, RearBottomLeft, RearBottomRight,
        FrontTopLeft, FrontTopRight, FrontBottomLeft, FrontBottomRight,
        Count
    };

    // What the N64 controller has (the stick aside).
    enum class N64 : uint8_t {
        A, B, Z, Start, L, R,
        CUp, CDown, CLeft, CRight,
        DUp, DDown, DLeft, DRight,
        Count
    };

    constexpr int bindings_per_input = 2;

    enum class StickSource : uint8_t { Left, Right, Count };

    struct Config {
        Input bindings[(int)N64::Count][bindings_per_input];
        StickSource stick = StickSource::Left;
        int deadzone = 12;      // percent of the stick's travel
        int sensitivity = 100;  // percent: above 100 reaches full tilt sooner
        bool invert_x = false;
        bool invert_y = false;
        int stick_threshold = 50; // percent of tilt for a stick direction to count as pressed
        bool widescreen = true;   // the 3D view widened to the Vita's 16:9 screen
    };

    // The state of the Vita's inputs at one poll.
    struct VitaState {
        SceCtrlData pad;
        SceTouchData front, back;
    };

    Config defaults();
    Config& current();
    void load();
    bool save();

    // Whether an input is held in a state.
    bool held(const Config& cfg, const VitaState& s, Input input);
    // The first input held in a state (for rebinding), or None.
    Input first_held(const Config& cfg, const VitaState& s);

    // The N64 controller's buttons and stick (-1..1) for a state.
    void to_n64(const Config& cfg, const VitaState& s, uint16_t* buttons, float* x, float* y);

    const char* input_name(Input input);
    const char* n64_name(N64 button);
    const char* stick_name(StickSource source);
}

#endif
