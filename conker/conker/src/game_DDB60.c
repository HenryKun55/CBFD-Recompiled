#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DDB60/func_150B06B0.s")

extern f32 D_8009F870;

void func_150B0A60(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s16 *arg5) {
    f32 a;
    f32 b;
    f32 c;

    *arg5 = *(f32 *)(arg0 + 0x40) * D_8009F870 - 128.0f;
    a = func_150ADA68() * 248.0f;
    b = func_150ADA68() + -0.5f;
    if (a < 122.0f) {
        arg4[0] = arg2[0] * -31.5f + arg3[0] * b * 122.0f;
        arg4[1] = 0.0f;
        arg4[2] = arg2[1] * -31.5f + arg3[1] * b * 122.0f;
    } else {
        f32 k = 61.0f;

        a -= 122.0f;
        c = k;
        if (a < 63.0f) {
            c = -k;
            *arg5 += 64;
        } else {
            *arg5 -= 64;
        }
        arg4[0] = arg2[0] * 63.0f * b + arg3[0] * c;
        arg4[1] = 0.0f;
        arg4[2] = arg2[1] * 63.0f * b + arg3[1] * c;
    }
    arg4[0] += *(f32 *)(arg0 + 0x14);
    arg4[1] += *(f32 *)(arg1 + 0x118);
    arg4[2] += *(f32 *)(arg0 + 0x1C);
}

void func_150B0C58(s32 arg0, s32 arg1, s32 arg2);

void func_150B0C34(s32 arg0) {
    func_150B0C58(arg0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DDB60/func_150B0C58.s")

void func_150B0CE0(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DDB60/func_150B0D20.s")
