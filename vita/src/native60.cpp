// EXPERIMENT (native 60 Hz game logic). Off unless ux0:data/conker/debug_native60 exists.
//
// How the game paces its frames (init_49E0.c, the scheduler thread, all on VI/SP/DP messages):
// - D_8003B238 (u8) counts VIs since the last graphics task started; func_10004F00 starts a
//   task (only ever from the VI handler, func_10004DB0), copies the count into D_800BE9E4
//   (s32, clamped to 2 when 255 or >= 11, >= 21 in cutscenes) and resets it to 0.
// - D_800BE9E4 is the frame's delta in VIs: ~680 uses in ~200 files scale timers, movement,
//   animation and particles by it (Perfect Dark's lvupdate60 equivalent).
// - func_10004FE0 (on RDP done, or on the next VI) only swaps the finished frame in when
//   D_8003B238 > 0, i.e. never in the VI its task started in; the next task starts on a VI after
//   that swap (its framebuffer must not be the one shown or about to be). A frame done within
//   one VI therefore waits for the next VI to swap and the one after to start: 2 VIs = 30 fps.
// With the switch on, the swap happens as soon as the frame is done (the hook below makes
// func_10004FE0 see D_8003B238 > 0), so a frame can start every VI and the game measures a
// delta of 1. Nothing else is changed: the delta is the game's own.
//
// The log ([native60], once a second): game frames, the VIs they covered (sum of deltas),
// the deltas' histogram, the game thread's time from the scheduler's "go" message to the
// list's submission (logic + display list building; Vita3K's CPU model), and player 1's
// position (gObjects[0] + 0x14) and distance moved in the second.

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include <psp2/kernel/processmgr.h>

#include "recomp.h"
#include "vita_platform.hpp"

namespace {
    int g_enabled = -1;
    uint32_t log_enabled = 0; // the log: with the switch file only
    bool trace = false;
    uint32_t last_scene = 0xFFFFFFFF;
    bool enabled() {
        if (g_enabled < 0) {
            g_enabled = 0;
            if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_native60", "r")) {
                // "0" in the file: only the log (the game's own 30 fps, for comparison).
                // A 't' after it: a line per frame too ([n60t]: time, delta, scene, player 1's
                // position, the camera's eye).
                const int c = std::fgetc(f);
                trace = std::fgetc(f) == 't';
                std::fclose(f);
                g_enabled = c == '0' ? 0 : 1;
                log_enabled = 1;
            }
            if (log_enabled) std::fprintf(stderr, "[native60] native 60 Hz logic %s (debug_native60)\n", g_enabled ? "ON" : "off");
        }
        return g_enabled == 1;
    }

    float rd_float(uint8_t* rdram, uint32_t addr) {
        const int32_t w = MEM_W(0, (gpr)(int32_t)addr);
        float f;
        std::memcpy(&f, &w, 4);
        return f;
    }

    // Per-second stats.
    uint64_t sec_start = 0;
    uint32_t frames = 0, delta_sum = 0, hist[5] = {};
    uint64_t logic_us_sum = 0, logic_us_max = 0;
    uint32_t logic_n = 0;
    uint64_t frame_go = 0;
    bool have_last = false;
    float last_x = 0, last_y = 0, last_z = 0, dist = 0, ylo = 1e9f, yhi = -1e9f;
}

// func_10004FE0 before 0x10004FF0: $t6 holds D_8003B238 (VIs since the task started).
extern "C" void conker_native60_swap(uint8_t* rdram, recomp_context* ctx) {
    if (enabled() && ctx->r14 == 0) {
        ctx->r14 = 1;
    }
}

// func_10004F00 before 0x10004FB4: a task started, $v0 = the delta just stored in D_800BE9E4.
extern "C" void conker_native60_task_start(uint8_t* rdram, recomp_context* ctx) {
    const bool on = enabled();
    if (log_enabled == 0) return;
    const uint64_t now = sceKernelGetProcessTimeWide();
    if (sec_start == 0) sec_start = now;
    const uint32_t d = (uint32_t)ctx->r2;
    frames++;
    delta_sum += d;
    hist[d < 4 ? d : 4]++;
    // Player 1 (gObjects[0] at 0x800CC2D0): x, y, z at +0x14.
    const float x = rd_float(rdram, 0x800CC2E4), y = rd_float(rdram, 0x800CC2E8), z = rd_float(rdram, 0x800CC2EC);
    if (have_last) {
        const float dx = x - last_x, dz = z - last_z;
        const float step = std::sqrt(dx * dx + dz * dz);
        if (step < 500.0f) dist += step; // not a warp
    }
    if (y < ylo) ylo = y;
    if (y > yhi) yhi = y;
    last_x = x; last_y = y; last_z = z; have_last = true;
    // The scene in play (D_800BE9F0) and the cutscene flag (D_800C35EA).
    const uint32_t scene = (uint32_t)MEM_W(0, (gpr)(int32_t)0x800BE9F0);
    if (scene != last_scene) {
        std::fprintf(stderr, "[native60] scene %X at %.3f s\n", scene, now / 1e6);
        last_scene = scene;
    }
    if (trace) {
        const uint32_t cam = (uint32_t)MEM_W(0, (gpr)(int32_t)0x800DBFF0);
        float ex = 0, ey = 0, ez = 0;
        if ((cam & 0xFF800000u) == 0x80000000u) {
            ex = rd_float(rdram, cam + 0x2F8); ey = rd_float(rdram, cam + 0x2FC); ez = rd_float(rdram, cam + 0x300);
        }
        std::fprintf(stderr, "[n60t] %.4f %u %X %u %.1f %.1f %.1f %.1f %.1f %.1f\n", now / 1e6, d, scene,
            (unsigned)MEM_BU(0, (gpr)(int32_t)0x800C35EA), x, y, z, ex, ey, ez);
        // The other game objects (gObjects[1..24], 0x32C each) with a position.
        for (uint32_t i = 1; i < 25; i++) {
            const uint32_t o = 0x800CC2D0 + i * 0x32C;
            const float ox = rd_float(rdram, o + 0x14), oy = rd_float(rdram, o + 0x18), oz = rd_float(rdram, o + 0x1C);
            if (ox == 0 && oy == 0 && oz == 0) continue;
            std::fprintf(stderr, "[n60o] %.4f %u %u %.1f %.1f %.1f\n", now / 1e6, i, (unsigned)MEM_BU(4, (gpr)(int32_t)o), ox, oy, oz);
        }
    }
    if (now - sec_start >= 1000000) {
        const double secs = (now - sec_start) / 1e6;
        std::fprintf(stderr,
            "[native60] %s %.2fs: %u frames, %u VIs of game time (%.1f/s), deltas 0:%u 1:%u 2:%u 3:%u 4+:%u, "
            "logic %.1f ms avg %.1f max (%u), pos %.0f %.0f %.0f, xz %.0f u/s, y %.0f..%.0f\n",
            on ? "ON" : "off", secs, frames, delta_sum, delta_sum / secs, hist[0], hist[1], hist[2], hist[3], hist[4],
            logic_n ? logic_us_sum / 1000.0 / logic_n : 0.0, logic_us_max / 1000.0, logic_n,
            x, y, z, dist / secs, ylo, yhi);
        sec_start = now;
        frames = delta_sum = 0;
        std::memset(hist, 0, sizeof(hist));
        logic_us_sum = logic_us_max = 0;
        logic_n = 0;
        dist = 0;
        ylo = 1e9f; yhi = -1e9f;
    }
}

// func_1501878C before 0x150187C0: the game thread got a message; type 1 (at *($sp + 0x64)) is
// the scheduler's "a task started, build the next frame".
extern "C" void conker_native60_frame_go(uint8_t* rdram, recomp_context* ctx) {
    enabled();
    if (log_enabled == 0) return;
    const gpr msg = (gpr)MEM_W(0x64, ctx->r29);
    if (msg != 0 && MEM_H(0, msg) == 1) {
        frame_go = sceKernelGetProcessTimeWide();
    }
}

// func_1501C880 at its start: the frame's list is being submitted.
extern "C" void conker_native60_submit(uint8_t* rdram, recomp_context* ctx) {
    if (frame_go == 0) return;
    const uint64_t us = sceKernelGetProcessTimeWide() - frame_go;
    frame_go = 0;
    logic_us_sum += us;
    if (us > logic_us_max) logic_us_max = us;
    logic_n++;
}
