// The desktop build's mouse camera (host/src/mouse_camera.cpp) reads the mouse and SDL's
// events; the Vita has neither. Its hooks (conker.toml) serve the Vita's Camera: Avoids Walls
// setting instead (Sticks and aiming page, CameraAvoidWalls in controls.ini).
//
// The follow camera (struct108, D_800DBFF0 the one being played) looks at a point (+0x2BC)
// above Conker from an eye (+0x2F8). Each frame its collision (func_1512BB10) moves the eye
// from where it was last frame (+0x304) toward the one it wants with func_15044380: the game's
// sweep of an object through the level's collision, sliding along what it meets. For the camera
// the object is a sphere (type 0x2D, its size the camera's +0x95C and +0x960, 20 to 70 units),
// and the sweep only gathers the faces around where it starts (func_150A64C8), which is fine
// for the short moves it's made for. So the eye's sphere is kept off the walls on its way, but
// nothing keeps the line between Conker and the eye clear: the eye ends up past a corner, a
// pillar or a door Conker walks by. The sweep meets walls, not floors, slopes and ceilings (the
// eye is only kept 40 units above the floor under it, func_1510E8BC), and it's skipped in some
// states (+0x84 flags, +0x2C mode 0x40). And the near plane (40 units ahead, 23 to each side at
// 4:3) reaches 31 units to each side on the Vita's wide screen, past the sphere's 30.
//
// With the setting on, only the view is drawn from another eye: as func_151284C4 starts
// building the view, the line from the look-at point to the eye is checked with the game's own
// queries, and the eye is pulled in to where it stops being clear:
// - walls and objects: func_15044380, a small sphere marched along it in short steps (the
//   step it's stopped in bisected), set up as func_1512BB10 sets up the camera's;
// - floors, slopes and ceilings: the column query func_1510F8D8 uses (func_150A3A70: every
//   surface above and below a point), at points along it, none nearer than 30 units.
// Then it's moved sideways away from a wall at the side (or halfway between two), for the near
// plane's room at the screen's edges. The view is pulled in at once and eases back out. Once
// func_1512C490 has built the view, the game's own eye is put back (+0x2F8 and the copy each
// update starts from, +0x2EC), so the game's camera (its angle, distance, collision) carries
// on as it would. Only the follow camera in play: func_1512D390 (the C-buttons' turning) and
// its collision ran this frame, the look mode or aiming (func_15120158) didn't. Cutscenes and
// the other cameras are the game's.

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>

#include "recomp.h"

#include "conker.hpp"
#include "controls.hpp"

extern "C" void func_15044380(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_150A3A70(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_1510F800(uint8_t* rdram, recomp_context* ctx);

namespace {
    constexpr uint32_t current_camera = 0x800DBFF0;   // D_800DBFF0
    constexpr uint32_t sweep_is_camera = 0x800CBDD2;  // D_800CBDD2: set while the camera's sweep runs
    constexpr uint32_t sweep_flag_dd3 = 0x800CBDD3;   // D_800CBDD3
    constexpr uint32_t sweep_long_move = 0x800CBDD4;  // D_800CBDD4: 0 cuts the move to 60 units
    constexpr uint32_t sweep_outputs = 0x800CBDF4;    // D_800CBDF4, D_800CBDF8: set by the sweep
    constexpr uint32_t collision_layers = 0x80089120; // D_80089120: which of the four layers are on
    constexpr uint32_t current_scene = 0x800BE9F0;    // D_800BE9F0
    constexpr uint32_t column_list = 0x800D3300;      // D_800D3300: the column query's surfaces
    constexpr int column_list_size = 40;

    // The sphere swept from the look-at point, and how near the view may come to it.
    constexpr float cast_radius = 14.0f;
    constexpr float min_distance = 60.0f;
    // The sweep is cast in steps this long at least, up to this many for the whole way.
    constexpr float march_step = 40.0f;
    constexpr float max_march_steps = 16.0f;
    constexpr int bisection_steps = 4;
    // How far the view looks for walls to its sides: with the sphere's radius, the room the near
    // plane needs at the wide screen's edges.
    constexpr float side_probe = 36.0f;
    // Floors, slopes and ceilings: the line is checked at points this far apart at least, up to
    // this many, and stops at the first with one nearer than the margin above or below. Nearer
    // Conker than terrain_skip, the ground he stands or climbs on doesn't count.
    constexpr float terrain_step = 24.0f;
    constexpr int max_terrain_samples = 32;
    constexpr float terrain_margin = 30.0f;
    constexpr float terrain_skip = 72.0f;
    // How fast the view goes back out once clear (the fraction of the way each frame).
    constexpr float ease_out = 0.2f;

    struct CameraState {
        uint32_t camera = 0;
        bool follow_ran = false;  // func_1512D390 (the C-buttons' turning) ran this frame
        bool look_ran = false;    // func_15120158 (the look mode, aiming) ran this frame
        bool collided = false;    // func_1512BB10 swept the eye this frame
        bool pulled = false;      // distance holds the view's distance from the look-at point
        float distance = 0.0f;
        float side = 0.0f;        // how far the view is moved to its right
        bool swapped = false;     // +0x2F8 holds the view's eye until the view is built
        float eye[3] = {};        // the game's eye
        float drawn[3] = {};      // the view's
    };
    CameraState cameras[4];

    CameraState* state_for(uint32_t camera) {
        for (CameraState& s : cameras) {
            if (s.camera == camera) return &s;
        }
        for (CameraState& s : cameras) {
            if (s.camera == 0) { s.camera = camera; return &s; }
        }
        cameras[0] = CameraState{};
        cameras[0].camera = camera;
        return &cameras[0];
    }

    float read_float(uint8_t* rdram, gpr base, int32_t offset) {
        uint32_t word = (uint32_t)MEM_W(offset, base);
        float value;
        std::memcpy(&value, &word, sizeof(value));
        return value;
    }

    void write_float(uint8_t* rdram, gpr base, int32_t offset, float value) {
        uint32_t word;
        std::memcpy(&word, &value, sizeof(word));
        MEM_W(offset, base) = (int32_t)word;
    }

    gpr addr(uint32_t a) { return (gpr)(int32_t)a; }

    bool is_current(uint8_t* rdram, gpr camera) {
        return (uint32_t)camera == (uint32_t)MEM_W(0, addr(current_camera));
    }

    // The game's sweep (func_15044380) of a small sphere from `from` to `to`, set up as
    // func_1512BB10 sets up the camera's own (its object on the stack below ours, its flags and
    // layers), all put back after. True if anything stopped it.
    bool sweep_blocked(uint8_t* rdram, recomp_context* ctx, gpr camera, const float from[3], const float to[3]) {
        recomp_context saved;
        std::memcpy(&saved, ctx, sizeof(saved));
        const gpr sp = (gpr)(int32_t)(((uint32_t)saved.r29 - 0x3A8) & ~7u);
        const gpr object = sp + 0x74;
        for (int i = 0; i < 0x330; i += 4) {
            MEM_W(i, object) = 0;
        }
        MEM_W(0x0, object) = 0x2D;
        for (int i = 0; i < 3; i++) {
            write_float(rdram, object, 0x14 + i * 4, to[i]);
        }
        const float floor_y = read_float(rdram, camera, 0x354);
        write_float(rdram, object, 0x28, to[1] - floor_y);
        write_float(rdram, object, 0x40, read_float(rdram, camera, 0x37C));
        write_float(rdram, object, 0x180, floor_y);
        MEM_W(0x188, object) = MEM_W(0x644, camera);
        MEM_W(0x318, object) = (int32_t)camera;

        // The sphere's size is read from the camera (func_1507C3E0).
        const int32_t size_a = MEM_W(0x95C, camera), size_b = MEM_W(0x960, camera);
        write_float(rdram, camera, 0x95C, cast_radius);
        write_float(rdram, camera, 0x960, cast_radius);
        const uint8_t dd2 = MEM_BU(0, addr(sweep_is_camera)), dd3 = MEM_BU(0, addr(sweep_flag_dd3)), dd4 = MEM_BU(0, addr(sweep_long_move));
        const uint8_t layer1 = MEM_BU(1, addr(collision_layers)), layer2 = MEM_BU(2, addr(collision_layers));
        const int32_t out0 = MEM_W(0, addr(sweep_outputs)), out1 = MEM_W(4, addr(sweep_outputs));
        const uint32_t flags = (uint32_t)MEM_W(0x84, camera);
        if ((flags & 0x80000000u) || MEM_W(0, addr(current_scene)) == 0x37) MEM_B(2, addr(collision_layers)) = 0;
        if (flags & 0x10000u) MEM_B(1, addr(collision_layers)) = 0;
        MEM_B(0, addr(sweep_is_camera)) = 1;
        MEM_B(0, addr(sweep_flag_dd3)) = MEM_BU(0x102, (gpr)MEM_W(0x3D0, camera)) != 0 ? 1 : 0;
        MEM_B(0, addr(sweep_long_move)) = 1;

        ctx->r29 = sp;
        ctx->f12.fl = from[0];
        ctx->f14.fl = from[1];
        uint32_t z;
        std::memcpy(&z, &from[2], sizeof(z));
        ctx->r6 = (gpr)(int32_t)z;
        ctx->r7 = object;
        MEM_W(0x10, sp) = 0;
        MEM_W(0x14, sp) = 0;
        func_15044380(rdram, ctx);
        const int32_t hits = (int32_t)ctx->r2;

        // Where it got to (+0x14), against where it was sent.
        float gap = 0.0f;
        for (int i = 0; i < 3; i++) {
            const float d = read_float(rdram, object, 0x14 + i * 4) - to[i];
            gap += d * d;
        }

        MEM_W(0x95C, camera) = size_a;
        MEM_W(0x960, camera) = size_b;
        MEM_B(0, addr(sweep_is_camera)) = dd2;
        MEM_B(0, addr(sweep_flag_dd3)) = dd3;
        MEM_B(0, addr(sweep_long_move)) = dd4;
        MEM_B(1, addr(collision_layers)) = layer1;
        MEM_B(2, addr(collision_layers)) = layer2;
        MEM_W(0, addr(sweep_outputs)) = out0;
        MEM_W(4, addr(sweep_outputs)) = out1;
        std::memcpy(ctx, &saved, sizeof(saved));
        return hits != 0 || gap > 1.0f;
    }

    // How far along from -> to the sweep gets, in steps of step_len (the sweep only gathers the
    // faces around where it starts: one long move goes through walls), the step it's stopped in
    // bisected.
    float march(uint8_t* rdram, recomp_context* ctx, gpr camera, const float from[3], const float to[3], float step_len) {
        const float d[3] = { to[0] - from[0], to[1] - from[1], to[2] - from[2] };
        const float len = std::sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
        if (!(len > 0.0f)) return 0.0f;
        const int steps = std::max(1, (int)std::ceil(len / step_len));
        for (int k = 0; k < steps; k++) {
            const float t0 = (float)k / steps, t1 = (float)(k + 1) / steps;
            const float a[3] = { from[0] + d[0] * t0, from[1] + d[1] * t0, from[2] + d[2] * t0 };
            const float b[3] = { from[0] + d[0] * t1, from[1] + d[1] * t1, from[2] + d[2] * t1 };
            if (!sweep_blocked(rdram, ctx, camera, a, b)) continue;
            float lo = 0.0f, hi = 1.0f;
            for (int it = 0; it < bisection_steps; it++) {
                const float m = 0.5f * (lo + hi);
                const float c[3] = { a[0] + (b[0] - a[0]) * m, a[1] + (b[1] - a[1]) * m, a[2] + (b[2] - a[2]) * m };
                if (sweep_blocked(rdram, ctx, camera, a, c)) hi = m;
                else lo = m;
            }
            return (t0 + (t1 - t0) * lo) * len;
        }
        return len;
    }

    // The heights of the surfaces above and below (x, z), as func_1510F8D8 finds the floor:
    // func_1510F800(0), then func_150A3A70 lists them at D_800D3300 (16 bytes each, the height
    // first, in 1/256ths).
    int column(uint8_t* rdram, recomp_context* ctx, float x, float z, float* heights) {
        recomp_context saved;
        std::memcpy(&saved, ctx, sizeof(saved));
        const gpr sp = (gpr)(int32_t)(((uint32_t)saved.r29 - 0x40) & ~7u);
        ctx->r29 = sp;
        ctx->r4 = 0;
        func_1510F800(rdram, ctx);
        ctx->r29 = sp;
        ctx->r4 = (gpr)(int32_t)x;
        ctx->r5 = (gpr)(int32_t)z;
        func_150A3A70(rdram, ctx);
        const int n = std::clamp((int)(int32_t)ctx->r2, 0, column_list_size);
        std::memcpy(ctx, &saved, sizeof(saved));
        for (int i = 0; i < n; i++) {
            heights[i] = (int32_t)MEM_W(i * 16, addr(column_list)) / 256.0f;
        }
        return n;
    }

    // How far from -> to keeps clear of the floors, slopes and ceilings: up to the point before
    // the first (from terrain_skip on) with one nearer than terrain_margin above or below.
    float terrain_clear(uint8_t* rdram, recomp_context* ctx, const float from[3], const float to[3]) {
        const float d[3] = { to[0] - from[0], to[1] - from[1], to[2] - from[2] };
        const float len = std::sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
        const int count = std::max(1, std::min(max_terrain_samples, (int)std::ceil(len / terrain_step)));
        float heights[column_list_size];
        for (int k = 1; k <= count; k++) {
            const float t = (float)k / count;
            if (len * t < terrain_skip) continue;
            const float p[3] = { from[0] + d[0] * t, from[1] + d[1] * t, from[2] + d[2] * t };
            const int n = column(rdram, ctx, p[0], p[2], heights);
            for (int i = 0; i < n; i++) {
                if (std::fabs(heights[i] - p[1]) < terrain_margin) {
                    return len * (float)(k - 1) / count;
                }
            }
        }
        return len;
    }
}

bool conker::mouse_camera::stick_turns_camera() {
    return false;
}

bool conker::mouse_camera::normal_camera() {
    return false;
}

// func_1512D390 (the C-buttons' turning), before its last restore: $s0 is the camera.
extern "C" void conker_mouse_camera_follow(uint8_t* rdram, recomp_context* ctx) {
    if (is_current(rdram, ctx->r16)) {
        state_for((uint32_t)ctx->r16)->follow_ran = true;
    }
}

// func_15120158 (the look mode: hold R, aiming), after its first instruction.
extern "C" void conker_mouse_camera_look_mode(uint8_t* rdram, recomp_context*) {
    state_for((uint32_t)MEM_W(0, addr(current_camera)))->look_ran = true;
}

// func_1512BB10 (the camera's collision), after its first instruction: $a0 is the camera.
// Whether it sweeps the eye this time (the tests at its start, in its order).
extern "C" void conker_mouse_camera_collide(uint8_t* rdram, recomp_context* ctx) {
    const gpr camera = ctx->r4;
    if (!is_current(rdram, camera)) {
        return;
    }
    const uint32_t flags = (uint32_t)MEM_W(0x84, camera);
    const bool skipped = (flags & 0x40000u) || MEM_BU(0x95, (gpr)MEM_W(0x3D4, camera)) != 0 ||
                         MEM_W(0x2C, camera) == 0x40 || (flags & 0x280u);
    if (!skipped) {
        state_for((uint32_t)camera)->collided = true;
    }
}

// func_151284C4 (builds the view), after its first instruction: $a0 is the camera.
extern "C" void conker_mouse_camera(uint8_t* rdram, recomp_context* ctx) {
    const gpr camera = ctx->r4;
    if (!is_current(rdram, camera)) {
        return;
    }
    CameraState& s = *state_for((uint32_t)camera);
    const bool follow = s.follow_ran && !s.look_ran && s.collided;
    s.follow_ran = s.look_ran = s.collided = false;
    s.swapped = false;
    if (!follow || !conker::vita::controls::current().camera_avoid_walls) {
        s.pulled = false;
        s.side = 0.0f;
        return;
    }

    float look[3], eye[3], dir[3];
    float full = 0.0f;
    for (int i = 0; i < 3; i++) {
        look[i] = read_float(rdram, camera, 0x2BC + i * 4);
        eye[i] = read_float(rdram, camera, 0x2F8 + i * 4);
        dir[i] = eye[i] - look[i];
        full += dir[i] * dir[i];
    }
    full = std::sqrt(full);
    if (!(full > min_distance) || full > 5000.0f) {
        s.pulled = false;
        s.side = 0.0f;
        return;
    }

    // How far the line from the look-at point stays clear.
    const float step = std::max(march_step, full / max_march_steps);
    const float clear = std::min(march(rdram, ctx, camera, look, eye, step), terrain_clear(rdram, ctx, look, eye));
    const float wanted = std::max(clear, min_distance);

    // In at once, back out gradually.
    float distance = wanted;
    if (s.pulled && wanted > s.distance) {
        distance = s.distance + (wanted - s.distance) * ease_out;
        if (wanted - distance < 1.0f) distance = wanted;
    }
    distance = std::min(distance, full);
    s.distance = distance;
    s.pulled = distance < full;

    float drawn[3];
    for (int i = 0; i < 3; i++) {
        drawn[i] = look[i] + dir[i] * (distance / full);
    }

    // Room at the sides: away from a wall to one side, or halfway between walls on both. Away at
    // once, back gradually.
    const float horizontal = std::sqrt(dir[0] * dir[0] + dir[2] * dir[2]);
    float side = 0.0f;
    if (horizontal > 1.0f) {
        const float right[3] = { -dir[2] / horizontal, 0.0f, dir[0] / horizontal };
        const float to_right[3] = { drawn[0] + right[0] * side_probe, drawn[1], drawn[2] + right[2] * side_probe };
        const float to_left[3] = { drawn[0] - right[0] * side_probe, drawn[1], drawn[2] - right[2] * side_probe };
        const float room_right = march(rdram, ctx, camera, drawn, to_right, side_probe);
        const float room_left = march(rdram, ctx, camera, drawn, to_left, side_probe);
        if (room_right < side_probe && room_left < side_probe) side = 0.5f * (room_right - room_left);
        else if (room_right < side_probe) side = room_right - side_probe;
        else if (room_left < side_probe) side = side_probe - room_left;
        if (std::fabs(side) < std::fabs(s.side)) {
            side = s.side + (side - s.side) * ease_out;
            if (std::fabs(side) < 0.5f) side = 0.0f;
        }
        drawn[0] += right[0] * side;
        drawn[2] += right[2] * side;
    }
    s.side = side;
    if (!s.pulled && side == 0.0f) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        s.eye[i] = eye[i];
        s.drawn[i] = drawn[i];
        write_float(rdram, camera, 0x2F8 + i * 4, drawn[i]);
    }
    s.swapped = true;
}

// func_151284C4, once func_1512C490 has built the view ($a0 saved at $sp + 0x18): the game's
// eye back at +0x2F8, with whatever func_1512C490 added to the one it was given (its sway), and
// at +0x2EC, the copy it took, which the next update (func_15122C5C) starts from.
extern "C" void conker_camera_view_done(uint8_t* rdram, recomp_context* ctx) {
    const gpr camera = (gpr)MEM_W(0x18, ctx->r29);
    for (CameraState& s : cameras) {
        if (s.swapped && s.camera == (uint32_t)camera) {
            for (int i = 0; i < 3; i++) {
                const float added = read_float(rdram, camera, 0x2F8 + i * 4) - s.drawn[i];
                write_float(rdram, camera, 0x2F8 + i * 4, s.eye[i] + added);
                write_float(rdram, camera, 0x2EC + i * 4, s.eye[i]);
            }
            s.swapped = false;
        }
    }
}
