// Native 60 Hz game logic: the menu's Picture > Frame rate "60" (Config::native60).
//
// How the game paces its frames (init_49E0.c, the scheduler thread, all on VI/SP/DP messages):
// - D_8003B238 (u8) counts VIs since the last graphics task started; func_10004F00 starts a
//   task (only ever from the VI handler, func_10004DB0), copies the count into D_800BE9E4
//   (s32, clamped to 2 when 255 or >= 11, >= 21 in cutscenes) and resets it to 0.
// - D_800BE9E4 is the frame's delta in VIs: ~680 uses in ~200 files scale timers, movement,
//   animation and particles by it (Perfect Dark's lvupdate60 equivalent). The object loop
//   turns it into D_800BE9A4 = delta / 2 and, per object, D_800D1550[0] = its time scale *
//   min(D_800BE9A4, 2): the time in "30 fps frames" the physics advance by.
// - func_10004FE0 (on RDP done, or on the next VI) only swaps the finished frame in when
//   D_8003B238 > 0, i.e. never in the VI its task started in; the next task starts on a VI after
//   that swap (its framebuffer must not be the one shown or about to be). A frame done within
//   one VI therefore waits for the next VI to swap and the one after to start: 2 VIs = 30 fps.
// At 60 the swap happens as soon as the frame is done (conker_native60_swap makes
// func_10004FE0 see D_8003B238 > 0), so a frame can start every VI and the game measures a
// delta of 1. Where the game can't hold 60 the delta is 2 again and it runs as at 30. Turned
// off, the hook does nothing and the 2-VI cap is back from the next frame.
//
// Places that don't scale with a delta of 1 are corrected below, each made to give over two
// 60 Hz frames what one 30 fps frame gives (nothing changes at 30, nor in a frame of 2 VIs):
// - animation events (func_1506AD30): run every other frame, as at 30 (Windy's leaping things
//   changed their gravity a VI later and leapt ~11% lower).
// - the title music's fade (func_1000BF60): counted (delta >> 1) * 4, nothing at 1: it never
//   ended.
// - objects' gravity sub-steps (func_1505A770): trunc(time / 0.1) a frame, the rest dropped.
// - counters moved by a fixed amount a frame: objects' stun time (func_150585F0), falling
//   drops' speed and fall (func_151934B4), moving scenery's step (func_15116BAC, func_151169B4).
//
// With ux0:data/conker/debug_native60 a line every 5 s goes to the log ([native60]): game
// frames, the VIs they covered, the deltas' histogram and the game thread's time from the
// scheduler's "go" message to the list's submission (logic + display list building).

#include <cstdint>
#include <cstdio>
#include <cstring>

#include <psp2/kernel/processmgr.h>

#include "recomp.h"
#include "controls.hpp"
#include "vita_platform.hpp"

namespace {
    bool on() { return conker::vita::controls::current().native60; }

    int log_enabled = -1;
    bool logging() {
        if (log_enabled < 0) {
            FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_native60", "r");
            log_enabled = f != nullptr;
            if (f != nullptr) std::fclose(f);
        }
        return log_enabled != 0;
    }

    float rd_float(uint8_t* rdram, uint32_t addr) {
        const int32_t w = MEM_W(0, (gpr)(int32_t)addr);
        float f;
        std::memcpy(&f, &w, 4);
        return f;
    }

    int32_t delta(uint8_t* rdram) { return MEM_W(0, (gpr)(int32_t)0x800BE9E4); }

    // Game frames (the game thread's "build the next frame" messages).
    uint32_t game_frame = 0;

    // The log's stats.
    uint64_t period_start = 0;
    uint32_t frames = 0, delta_sum = 0, hist[5] = {};
    uint64_t logic_us_sum = 0, logic_us_max = 0;
    uint32_t logic_n = 0;
    uint64_t frame_go = 0;

    // func_1000BF60's fade: the halved delta's remainder.
    int32_t fade_carry = 0;

    // func_1505A770's sub-steps, per object (gObjects, 25 of 0x32C at 0x800CC2D0): the first
    // frame of a pair (its game frame, its time, the sub-steps it took).
    constexpr uint32_t objects = 0x800CC2D0, object_size = 0x32C, object_count = 25;
    struct Half { uint32_t frame; float time; int32_t steps; bool pending; };
    Half halves[object_count] = {};

    // func_1506AD30's events, per object: the last frame they were looked at, and whether that
    // frame was skipped.
    struct EventGrid { uint32_t frame; bool skipped; bool valid; };
    EventGrid grids[object_count] = {};
    bool animation_call = false; // func_1507BDB0 calls func_1506AD30 after the advance

    // For counters the game moves by a fixed amount a frame: which half of a 30 fps frame this
    // 60 Hz frame is for one thing (a struct's address and the place, as the key). The first
    // frame it's seen in (or after a gap) is the first half, then they alternate.
    struct PairSlot { uint32_t key; uint32_t frame; bool second; };
    PairSlot pair_slots[128] = {};
    bool second_half(uint32_t key) {
        const uint32_t h = (key * 2654435761u) >> 25; // 0..127
        PairSlot* slot = nullptr;
        PairSlot* oldest = nullptr;
        for (uint32_t n = 0; n < 8; n++) {
            PairSlot& c = pair_slots[(h + n) & 127];
            if (c.key == key) { slot = &c; break; }
            if (oldest == nullptr || c.frame < oldest->frame) oldest = &c;
        }
        if (slot == nullptr) {
            slot = oldest;
            *slot = { key, 0, true }; // a frame long ago: the first half next
        }
        if (slot->frame != game_frame) {
            slot->second = slot->frame + 1 == game_frame && !slot->second;
            slot->frame = game_frame;
        }
        return slot->second;
    }
    // Whether the corrections apply: at 60, in a frame of one VI.
    bool halves_on(uint8_t* rdram) { return on() && delta(rdram) == 1; }
}

// func_10004FE0 before 0x10004FF0: $t6 holds D_8003B238 (VIs since the task started).
extern "C" void conker_native60_swap(uint8_t* rdram, recomp_context* ctx) {
    if (ctx->r14 == 0 && on()) {
        ctx->r14 = 1;
    }
}

// func_1000BF60 before 0x1000C2C4: $t6 = the fade's counter (bits 2..6), $t9 = the delta,
// $t1 = (delta >> 1) * 4, what's taken off it.
extern "C" void conker_native60_fade(uint8_t* rdram, recomp_context* ctx) {
    if (!on()) {
        fade_carry = 0;
        return;
    }
    const int32_t sum = (int32_t)ctx->r25 + fade_carry;
    const int32_t step = (sum >> 1) * 4;
    fade_carry = sum & 1;
    if ((int32_t)ctx->r14 - step <= 0) fade_carry = 0; // it ends: the next fade starts afresh
    ctx->r9 = (gpr)(int64_t)step;
}

// func_1505A770 before 0x1505A7C8 (an object's gravity): $a0 = the object, $f8 = its time
// (D_800D1550[0]), $f12 = a sub-step's (0.1), $f16 = trunc($f8 / $f12), the sub-steps it takes
// now, the rest of the time dropped. With a time just under 0.5 (or a time scale that isn't a
// multiple of 0.2) two 60 Hz frames took fewer than one 30 fps frame (4 + 5 for 10). The second
// frame of a pair takes what the pair's time gives in all, less what the first took.
extern "C" void conker_native60_substeps(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t o = (uint32_t)ctx->r4;
    const uint32_t i = (o - objects) / object_size;
    if (o < objects || i >= object_count || (o - objects) % object_size != 0) return;
    Half& h = halves[i];
    if (!halves_on(rdram)) {
        h.pending = false;
        return;
    }
    const int32_t steps = (int32_t)ctx->f16.u32l;
    if (h.pending && h.frame + 1 == game_frame) {
        // The pair's time divided as the game divides one frame's at 30.
        const float pair = (h.time + ctx->f8.fl) / ctx->f12.fl;
        int32_t rest = (int32_t)pair - h.steps;
        if (rest < 0) rest = 0;
        ctx->f16.u32l = (uint32_t)rest;
        h.pending = false;
    }
    else {
        h = { game_frame, ctx->f8.fl, steps, true };
    }
}

// func_1507BDB0 before 0x1507BF0C, its call of func_1506AD30 after the animation's advance:
// $s0 = the animation, $f12 = its new time. func_1506AD30 runs the animation's events (sounds,
// velocities, gravity, other animations...) whose time was reached. At 30 the time moves two
// VIs' worth a frame, so events land on every other VI; at 60 they're checked every VI, which
// moved some by one: Windy's leaping things changed their gravity a VI later and leapt ~11%
// lower. At 60 an object's events then run every other frame (the frame they last ran + 2),
// the 30 fps timing. Always run: a frame whose time went back (a loop or a new animation: the
// events' index is reset there), the last frame before the end (its events must run before the
// animation ends or loops), an animation playing backwards, and func_1506AD30's other callers
// (an object's death runs them all at once...).
extern "C" void conker_native60_animation_call(uint8_t* rdram, recomp_context* ctx) {
    const gpr a = ctx->r16;
    animation_call = rd_float(rdram, (uint32_t)a + 0x10) > 0.0f && ctx->f12.fl < rd_float(rdram, (uint32_t)a + 0x18) - 1.0f;
}

// func_1506AD30 at its start: $a0 = the object, $a1 = the time (a float's bits). True skips the
// call (it returns 0: no event).
extern "C" int conker_native60_events(uint8_t* rdram, recomp_context* ctx) {
    const bool regular = animation_call;
    animation_call = false;
    if (!regular) return 0;
    const uint32_t o = (uint32_t)ctx->r4;
    const uint32_t i = (o - objects) / object_size;
    if (o < objects || i >= object_count || (o - objects) % object_size != 0) return 0;
    EventGrid& g = grids[i];
    if (!halves_on(rdram)) {
        g.valid = false;
        return 0;
    }
    float t;
    const uint32_t bits = (uint32_t)ctx->r5;
    std::memcpy(&t, &bits, 4);
    const float prev = rd_float(rdram, o + 0xB4);
    if (g.valid && g.frame == game_frame) return 0; // a second call this frame (a new animation)
    const bool skip = g.valid && g.frame + 1 == game_frame && !g.skipped && t >= prev;
    g.valid = true;
    g.frame = game_frame;
    g.skipped = skip;
    return skip;
}

// func_150585F0 before 0x1505873C (an object's physics): $v0 = its stun counter (0x104), $t1 =
// $v0 - 1, what's stored. It counts frames: at 60 it only counts in the second half of each
// pair (0 still goes on to 0xFF, "not stunned", at once: the recovery runs once).
extern "C" void conker_native60_stun(uint8_t* rdram, recomp_context* ctx) {
    if (!halves_on(rdram) || ctx->r2 == 0) return;
    if (!second_half((uint32_t)ctx->r16 * 8 + 1)) ctx->r9 = ctx->r2;
}

// func_151934B4 before 0x15193580 (a falling drop, a splash where it lands): $t5 = its speed
// (0x94) + 1, the speed counts frames up to 20; it falls by (speed * delta) >> 1 (before
// 0x151935B4: $t0, $v0 = the speed). At 60 the speed only goes up in a pair's first half and the
// fall is split over the pair, the 30 fps frame's in all.
extern "C" void conker_native60_drop_speed(uint8_t* rdram, recomp_context* ctx) {
    if (halves_on(rdram) && second_half((uint32_t)ctx->r16 * 8 + 2)) ctx->r13 = ctx->r12;
}

extern "C" void conker_native60_drop_fall(uint8_t* rdram, recomp_context* ctx) {
    if (halves_on(rdram) && second_half((uint32_t)ctx->r16 * 8 + 2)) {
        const int32_t v = (int32_t)ctx->r2;
        ctx->r8 = (gpr)(int64_t)(v - (v >> 1));
    }
}

// func_15116BAC before 0x15116C60 and func_151169B4 before 0x15116AA8 (moving parts of the
// scenery, s16 positions heading for a target): the step is (speed * delta) >> 1, with odd
// speeds a half lost each 60 Hz frame (a speed of 1 never moved). Split over a pair.
// func_15116BAC: $s0 = the part, $t1 = speed * delta, $t6 = the step.
extern "C" void conker_native60_mover_a(uint8_t* rdram, recomp_context* ctx) {
    if (halves_on(rdram) && second_half((uint32_t)ctx->r16 * 8 + 3)) {
        const int32_t v = (int32_t)ctx->r9;
        ctx->r14 = (gpr)(int64_t)(v - (v >> 1));
    }
}

// func_151169B4: $a0 = the part, $t0 = speed * delta, $t2 = the step.
extern "C" void conker_native60_mover_b(uint8_t* rdram, recomp_context* ctx) {
    if (halves_on(rdram) && second_half((uint32_t)ctx->r4 * 8 + 3)) {
        const int32_t v = (int32_t)ctx->r8;
        ctx->r10 = (gpr)(int64_t)(v - (v >> 1));
    }
}

// func_10004F00 before 0x10004FB4: a task started, $v0 = the delta just stored in D_800BE9E4.
extern "C" void conker_native60_task_start(uint8_t* rdram, recomp_context* ctx) {
    if (!logging()) return;
    const uint64_t now = sceKernelGetProcessTimeWide();
    if (period_start == 0) period_start = now;
    const uint32_t d = (uint32_t)ctx->r2;
    frames++;
    delta_sum += d;
    hist[d < 4 ? d : 4]++;
    if (now - period_start >= 5000000) {
        const double secs = (now - period_start) / 1e6;
        std::fprintf(stderr,
            "[native60] %s %.1fs: %.1f fps, %.1f VIs/s of game time, deltas 1:%u 2:%u 3:%u 4+:%u, logic %.1f ms avg %.1f max\n",
            on() ? "60" : "30", secs, frames / secs, delta_sum / secs, hist[1], hist[2], hist[3], hist[4],
            logic_n ? logic_us_sum / 1000.0 / logic_n : 0.0, logic_us_max / 1000.0);
        period_start = now;
        frames = delta_sum = 0;
        std::memset(hist, 0, sizeof(hist));
        logic_us_sum = logic_us_max = 0;
        logic_n = 0;
    }
}

// func_1501878C before 0x150187C0: the game thread got a message; type 1 (at *($sp + 0x64)) is
// the scheduler's "a task started, build the next frame".
extern "C" void conker_native60_frame_go(uint8_t* rdram, recomp_context* ctx) {
    const gpr msg = (gpr)MEM_W(0x64, ctx->r29);
    if (msg == 0 || MEM_H(0, msg) != 1) return;
    game_frame++;
    if (logging()) frame_go = sceKernelGetProcessTimeWide();
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
