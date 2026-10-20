// The PS Vita port's Extras (its menu): the PC build's Skip Intro and Cheats mods
// (mods/skip_intro, mods/cheats), which the Vita, without code mods, runs from hooks in
// conker.toml instead. The PC build's hooks do nothing (the mods do it there).
//
// Skip intro: the game boots through three scenes, 0x25 (the notices and logos), 0x21 (the
// chainsaw opening) and 0x1D (the bar, a button press from the main menu). A phase (D_800E0B94)
// picks what runs each frame; func_151DE6D4 counts the logos' frames and asks for 0x21 at 0x349.
// After its third frame (asked for on the first two, the bar never loads) the bar is asked for
// instead, and once it has loaded, what the opening's end (func_151DE85C) would have left behind
// is set. See mods/skip_intro/src/skip_intro.c.
//
// Cheats: player 1's health (gObjects[0]'s chocolate), lives and cash (the stats at D_800D2138),
// at the GameShark codes' addresses, rewritten every game frame (func_1501BBB8 reads the
// controllers once a frame). A health of 0 is a death under way: left alone.

#include <cstdint>
#include <cstring>

#include "recomp.h"

#include "conker.hpp"

extern "C" void func_1501C730(uint8_t* rdram, recomp_context* ctx);

namespace {
    constexpr gpr addr(uint32_t a) { return (gpr)(int32_t)a; }

    constexpr uint32_t health = 0x800CC49A, lives = 0x800D2144, cash = 0x800D2148;
    constexpr int max_health = 6, max_lives = 9;
    constexpr int32_t full_cash = 9999;

    constexpr uint32_t scene_bar = 0x1D;
    constexpr int32_t arm_frames = 10;
    constexpr uint32_t logo_frames = 0x800E0A90, scene_in_play = 0x800BE9F0, boot_phase = 0x800E0B94;
    constexpr uint32_t d_800D2E40 = 0x800D2E40, d_800E0B96 = 0x800E0B96, d_8008FD80 = 0x8008FD80;
    constexpr uint32_t d_8008FDA4 = 0x8008FDA4, d_8008FE28 = 0x8008FE28, game_state = 0x8008FDD4;

    bool bar_requested = false, bar_set_up = false;
}

// Before func_1501BBB8 returns.
extern "C" void conker_extras_frame(uint8_t* rdram, recomp_context* ctx) {
#if defined(__vita__)
    (void)ctx;
    if (conker::vita_cheat_health()) {
        const uint8_t h = (uint8_t)MEM_B(0, addr(health));
        if (h != 0 && h < max_health) MEM_B(0, addr(health)) = max_health;
    }
    if (conker::vita_cheat_lives() && (uint8_t)MEM_B(0, addr(lives)) < max_lives) {
        MEM_B(0, addr(lives)) = max_lives;
    }
    if (conker::vita_cheat_cash() && (int32_t)MEM_W(0, addr(cash)) < full_cash) {
        MEM_W(0, addr(cash)) = full_cash;
    }
#else
    (void)rdram; (void)ctx;
#endif
}

// Before func_151DE6D4 returns: the bar asked for in place of the chainsaw opening.
extern "C" void conker_skip_intro_logos(uint8_t* rdram, recomp_context* ctx) {
#if defined(__vita__)
    if (!conker::vita_skip_intro() || bar_requested || (int32_t)MEM_W(0, addr(logo_frames)) < arm_frames) {
        return;
    }
    bar_requested = true;
    MEM_B(0, addr(d_8008FE28)) = 2;
    MEM_B(0, addr(boot_phase)) = 1;
    MEM_B(0, addr(d_800D2E40)) = 0;
    // func_1501C730(6, SCENE_BAR, 0, 0, 1): the fifth argument on the stack, below a frame
    // of its own; everything the call changes in the context is put back after it.
    recomp_context saved;
    std::memcpy(&saved, ctx, sizeof(saved));
    ctx->r29 = saved.r29 - 0x20;
    ctx->r4 = 6;
    ctx->r5 = scene_bar;
    ctx->r6 = 0;
    ctx->r7 = 0;
    MEM_W(0x10, ctx->r29) = 1;
    func_1501C730(rdram, ctx);
    std::memcpy(ctx, &saved, sizeof(saved));
    MEM_B(0, addr(d_800E0B96)) = 0xFF;
#else
    (void)rdram; (void)ctx;
#endif
}

// Before func_15007A70 (a scene's loading) returns: once the bar is up, what the opening's end
// leaves behind.
extern "C" void conker_skip_intro_scene_load(uint8_t* rdram, recomp_context* ctx) {
#if defined(__vita__)
    (void)ctx;
    if (!bar_requested || bar_set_up || (uint32_t)MEM_W(0, addr(scene_in_play)) != scene_bar) {
        return;
    }
    bar_set_up = true;
    MEM_B(0, addr(d_800D2E40)) = 0;
    MEM_B(0, addr(boot_phase)) = 3;
    MEM_B(0, addr(d_8008FD80)) = 1;
    MEM_B(0, addr(d_8008FE28)) = 2;
    MEM_B(0, addr(d_8008FDA4)) = 0;
    const gpr state = (gpr)(int32_t)MEM_W(0, addr(game_state));
    if (state != 0) {
        MEM_B(0x3E, state) = 0;
        MEM_B(0x2B, state) = 5;
        MEM_B(0x2C, state) = MEM_B(0x2B, state);
    }
#else
    (void)rdram; (void)ctx;
#endif
}
