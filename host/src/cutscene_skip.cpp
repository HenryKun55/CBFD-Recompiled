// Skipping cutscenes with L, the first time they play too (the Vita build's setting).
//
// func_1501E05C decides each frame whether the playing cutscene should be skipped. For
// most cutscenes that's L, but only when func_1501D2C4 says the cutscene has been
// watched before; the opening (scene 0x21) takes Start, and only after a soft reset.
// Cutscenes whose script holds command 0x0E (D_800C3C9C, set by func_1501DAAC) are
// never skippable. This is the function without those conditions, as the PC's
// "Skip Any Cutscene" mod has it (mods/skip_cutscenes); conker.toml calls it at the
// function's start. The PC build loads the mod instead, so here it leaves the game's
// own decision (returns false) unless the Vita's setting is on.

#include <cstdint>

#include "recomp.h"

#include "conker.hpp"

namespace {
    constexpr uint16_t BUTTON_START = 0x1000;
    constexpr uint16_t BUTTON_L = 0x0020;

    // A game address as the recompiled code holds it (sign-extended).
    constexpr gpr addr(uint32_t a) { return (gpr)(int32_t)a; }
}

// True when it decided: $v0 holds the answer and func_1501E05C returns at once.
extern "C" int conker_cutscene_skip(uint8_t* rdram, recomp_context* ctx) {
#if defined(__vita__)
    const int mode = conker::cutscene_skip_mode();
#else
    const int mode = 0;
#endif
    if (mode == 0) {
        return 0;
    }
    const int32_t i = (int32_t)ctx->r4;
    const int32_t scene = MEM_W(0, addr(0x800BE9F0));
    const uint16_t pressed = MEM_HU(0, addr(0x800BE710));
    auto answer = [ctx](bool skip) {
        ctx->r2 = skip ? 1 : 0;
        return 1;
    };

    if (scene == 0x1D) {
        if (MEM_B(0, addr(0x8008FD84)) != 0) {
            MEM_B(0, addr(0x8008FD84)) = 0;
            return answer(true);
        }
        if (MEM_BU(0, addr(0x800C35E8)) != 5) {
            return answer(false);
        }
    }
    if (scene == 0x21) {
        // Originally also required osResetType == 1 (a soft reset).
        return answer((pressed & BUTTON_START) && MEM_W(0, addr(0x800C35B0)) >= 0x12D);
    }
    if (!(pressed & BUTTON_L)) {
        return answer(false);
    }
    // The scripts' unskippable ones (the opening in the throne room, the hangover):
    // only with the setting's second level.
    if (MEM_BU(0, addr(0x800C3C9C)) && mode < 2) {
        return answer(false);
    }
    if (MEM_BU(0, addr(0x800D2E40)) || MEM_BU(0, addr(0x800C3C99))) {
        return answer(true);
    }
    // Originally only cutscenes watched before could be skipped.
    return answer(MEM_W(i * 4, addr(0x800C35B0)) + 0x1E < MEM_W(i * 4, addr(0x800C3640)));
}
