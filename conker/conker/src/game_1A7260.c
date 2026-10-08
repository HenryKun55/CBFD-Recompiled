#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179DB0.s")

extern void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern f32 D_800A7220;

struct func_15179FE0_s {
    u8 pad0[0x90];
    s16 unk90;
    s16 unk92;
    s16 unk94;
    s16 unk96;
    s16 unk98;
    s16 unk9A;
    s8 unk9C;
    s8 unk9D;
    s8 unk9E;
    u8 unk9F;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    u16 unkA6;
    f32 unkA8;
    u16 unkAC;
    s16 unkAE;
    u8 padB0[2];
    u8 unkB2;
    u8 unkB3;
};

void func_15179FE0(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s8 arg4, u16 arg5, u16 arg6, u8 arg7, u8 arg8, u8 arg9, s32 argA) {
    struct func_15179FE0_s *s;
    s32 pad;

    s = func_15167A68(argA, 0, 0xB8, 1, 0xFF, 1);
    if (s != NULL) {
        s->unk90 = arg1;
        s->unk92 = arg2;
        s->unk94 = arg3;
        s->unkA2 = arg4;
        s->unkA0 = ((u32)func_150ADA20() % arg7) - (arg7 >> 1);
        s->unkA4 = ((u32)func_150ADA20() % arg7) - (arg7 >> 1);
        if (arg6 == 5) {
            s->unk90 += s->unkA0 * 4;
            s->unk92 -= s->unkA2 * 4;
            s->unk94 += s->unkA4 * 4;
        }
        s->unk96 = 0;
        s->unk98 = 0;
        s->unk9A = 0;
        s->unk9C = ((u32)func_150ADA20() % arg8) - (arg8 >> 1);
        s->unk9D = ((u32)func_150ADA20() % arg8) - (arg8 >> 1);
        s->unk9E = ((u32)func_150ADA20() % arg8) - (arg8 >> 1);
        s->unkA8 = ((func_150ADA20() & 0x7F) + 0x8C) * D_800A7220;
        s->unkA6 = arg5;
        s->unk9F = arg0;
        s->unkAC = arg6;
        s->unkAE = arg9;
        s->unkB2 = 0;
        s->unkB3 = 0xFF;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A1EC.s")

s32 func_1517A394(s32 arg0) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A644.s")

struct func_1517A84C_s {
    u8 pad0[0x90];
    s16 unk90;
    s16 unk92;
    s16 unk94;
    s16 unk96;
    s16 unk98;
    s16 unk9A;
    s8 unk9C;
    s8 unk9D;
    s8 unk9E;
    u8 pad9F;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    u16 unkA6;
    u8 padA8[8];
    s16 unkB0;
    u8 padB2;
    s8 unkB3;
};

void func_1517A84C(struct func_1517A84C_s *arg0) {
    s32 temp;
    s16 y;

    temp = arg0->unkA6;
    if (temp == 0) {
        arg0->unk90 += arg0->unkA0;
        arg0->unk92 += arg0->unkA2;
        arg0->unk94 += arg0->unkA4;
        if (arg0->unkA2 > 0) {
            arg0->unkA2--;
            if (arg0->unkA2 <= 0) {
                arg0->unkA2 = -3;
            }
        }
        y = arg0->unkB0;
        temp = arg0->unk92 - y;
        if (temp <= 0) {
            arg0->unk96 = 0x5A;
            arg0->unk9A = 0;
            arg0->unkA6 = 60;
            arg0->unk92 = y;
        } else {
            arg0->unk96 += arg0->unk9C;
            arg0->unk98 += arg0->unk9D;
            arg0->unk9A += arg0->unk9E;
        }
    } else {
        temp -= D_800BE9E4;
        if (temp > 0) {
            arg0->unkA6 = temp;
            arg0->unkB3 = (temp << 8) / 60;
        } else {
            func_1516972C((struct102 *)arg0);
        }
    }
}

extern s16 D_800DD450;
s32 func_1517A394(s32);

s32 func_1517A958(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800DD450 = -1;
    if ((arg1 == 12) || (arg1 == 89)) {
        arg0 = func_1517A394(arg0);
    }
    return arg0;
}

extern s32 D_80090614;
void *func_15094F70();
void *func_1517A9A8(void *arg0, s32 arg1) {
    s32 sp34[5];
    if (arg1 == D_800DD1B0) {
        goto end;
    }
    arg0 = func_15094F70(arg0, &D_80090614, arg1 << 8, sp34, 0, 0, 0, 2, 3);
    D_800DD1B0 = arg1;
end:
    return arg0;
}

void func_1517A644(f32, s32, s16, s16, s32);

void func_1517AA20(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 x;
    s32 i;
    s32 y;
    s32 range;
    s32 z;
    f32 f;
    u8 r;

    if (arg0 < 12.0f) {
        return;
    }
    range = arg0 * 8.0f;
    arg0 *= 0.5f;
    z = (s16)arg2;
    for (i = 0; i < arg4; i++) {
        x = func_150ADA20() & 0x3F;
        y = func_150ADA20() & 0x3F;
        x -= 32;
        y -= 32;
        f = (f32)((u32)(func_150ADA20() % (u32)range) >> 4) + arg0;
        r = func_150ADA20();
        r &= 1;
        func_1517A644(f, r, arg1 + x, z, arg3 + y);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517AB7C.s")
