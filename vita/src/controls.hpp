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
        bool invert_other_x = false; // the other stick (the C-buttons' by default: the camera)
        bool invert_other_y = false;
        bool aim_invert_x = false;   // aiming (hold R, the scope, the slingshot...): left/right turned around
        bool aim_invert_y = true;    // up/down: inverted is the game's own (up looks down)
        bool aim_camera_stick = false; // while aiming the sticks swap: the camera stick aims, the movement stick moves
        int stick_threshold = 50; // percent of tilt for a stick direction to count as pressed
        bool widescreen = true;   // the 3D view widened to the Vita's 16:9 screen
        bool cutscene_4x3 = true; // in widescreen, cutscenes in the N64's 4:3 (black bars)
        int language = 0;         // text: 0 English, 1 Portuguese (Brazil), 2 Spanish, 3 French, 4 German, 5 Italian
        bool language_chosen = false; // picked in the menu (otherwise the Vita's system language)
        bool censored = false;    // translated swear words as the game's symbols (off: spelled out)
        int cutscene_skip = 1;    // L skips: 0 the game's rule (watched ones), 1 any, 2 also the unskippable
        bool skip_intro = false;   // Extras: boot to the bar, a press from the main menu
        bool cheat_health = false, cheat_lives = false, cheat_cash = false;
        bool native60 = false; // the game's logic run at 60 Hz where it has the time (native60.cpp; off: the original 30 fps cap)
        bool camera_avoid_walls = false; // the follow camera's view pulled in towards Conker where a wall is between them (off: the game's)
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
