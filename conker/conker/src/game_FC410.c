#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A0830;
extern f32 D_800A0834;
void *func_151149AC(s32);
void func_150A3444(s32, s16, s16, s16);
void func_151749A0(s32, s32);

void func_150CEF60(s32 arg0) {
    f32 pad0;
    f32 angle;
    f32 pad[6];
    f32 s;
    f32 c;
    f32 ox;
    f32 oy;
    f32 dx;
    f32 dy;

    angle = *(f32 *)((u8 *)func_151149AC(4) + 8) * D_800A0830;
    s = func_150AD78C(angle);
    c = func_150AD780(angle);
    ox = -1.0f;
    oy = 44.0f;
    dx = 76.0f - ox;
    dy = 241.0f - oy;
    func_150A3444(2, (dx * c - dy * s) + ox, (dx * s + dy * c) + oy, D_800A0834);
    func_151749A0(5, 3);
}

extern f32 D_800A0838;

f32 func_150CF040(s32 arg0, s32 arg1) {
    arg0 += 1;
    arg1 -= 44;
    return func_150484A0(arg0, arg1) * D_800A0838;
}

void func_150CF080(s32 arg0) {
    *(s32 *)(arg0 + 0x84) |= 0x4000;
}
