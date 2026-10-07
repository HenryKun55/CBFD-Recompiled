#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E68B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6B84.s")

extern f32 D_800A130C;
extern f32 *D_80088A3C;
extern f32 *D_80088A40;

void func_150E6E34(f32 *arg0) {
    f32 *p;
    f32 t;

    if (func_150ADA68() < D_800A130C) {
        p = D_80088A3C;
    } else {
        p = D_80088A40;
    }
    t = func_150ADA68();
    arg0[0] = p[0] + (p[3] - p[0]) * t;
    arg0[1] = p[1] + (p[4] - p[1]) * t;
    arg0[2] = p[2] + (p[5] - p[2]) * t;
}

void func_150E6ED8(s32 arg0) {
    func_1514470C((&D_800D9A20)[func_150ADA20() & 1], arg0);
}

extern f32 *D_80088A44[];

void func_150E6F18(f32 *arg0) {
    f32 *v = D_80088A44[func_150ADA20() % 6U];
    f32 t = func_150ADA68();

    arg0[0] = v[0] + ((v[3] - v[0]) * t);
    arg0[1] = v[1] + ((v[4] - v[1]) * t);
    arg0[2] = v[2] + ((v[5] - v[2]) * t);
}

extern s32 func_1514ECE0();

void func_150E6FAC(f32 *arg0, f32 *arg1) {
    u8 *sp34;

    if (func_1514ECE0(*(void **)((u8 *)arg1 + 0x2F4), 0x16, &sp34) != 0) {
        f32 *v0;
        f32 sp2C;
        s16 sp2A;
        f32 sp24;
        f32 c;

        sp2C = func_150ADA68() * 100.0f + 80.0f;
        sp2A = func_150ADA20() & 0xFF;
        sp24 = func_151423D8(sp2A - 64);
        c = func_151423D8(sp2A);
        v0 = *(f32 **)(sp34 + 0x10);
        arg0[0] = (v0[14] * -80.0f) + arg1[5] + sp24 * sp2C;
        arg0[1] = (v0[15] * -80.0f) + arg1[6] + 100.0f;
        arg0[2] = (v0[16] * -80.0f) + arg1[7] + c * sp2C;
    } else {
        arg0[0] = arg1[5];
        arg0[1] = arg1[6];
        arg0[2] = arg1[7];
    }
}

void func_150E70CC(f32 *arg0, f32 *arg1) {
    arg0[0] = arg1[5];
    arg0[1] = arg1[6];
    arg0[2] = arg1[7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E70EC.s")

extern f32 D_800A1324;
extern f32 D_800A1328;
extern f32 D_800A132C;
extern f32 D_800A1330;
extern f32 D_800A1334;
extern f32 D_800A1338;
extern f32 D_800A133C;

void func_150E71E4(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    arg3[0] = func_150484A0(arg2[0], arg2[2]);
    arg3[2] = D_800A1324;
    arg3[4] = func_150ADA68() * D_800A1328;
    arg3[6] = func_150ADA68() * D_800A132C;
    arg3[1] = D_800A1330;
    arg3[3] = D_800A1334;
    arg3[5] = func_150ADA68() * D_800A1338;
    arg3[7] = func_150ADA68() * D_800A133C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E75A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E76D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E81A8.s")

struct func_150E83AC_s {
    f32 x, y, z;
};

void func_150E83AC(struct func_150E83AC_s *arg0, s16 arg1, u8 arg2, s32 arg3) {
    struct {
        struct func_150E83AC_s v;
        f32 w;
    } sp40;
    struct260 *temp_v0;

    sp40.v = *arg0;
    sp40.w = 0.0f;
    temp_v0 = func_15149130((arg1 == -1) ? 300 : arg1, -1, 0x28, -1, (arg1 == -1) ? 0 : 1, 0, (struct37 *) 0x10, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((u8 *) temp_v0 + 0x28, &sp40, 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8470.s")

void func_15131828();

s32 func_150E8824(u8 *arg0, void *arg1) {
    func_15131828(arg0, arg0 + 0xAC, arg0 + 0xA8, arg0 + 0xAA);
    return 1;
}

void func_150E8854(void) {
    struct260 *result;
    f32 sp30;

    sp30 = 10.0f;
    result = func_15149130(300, -1, 0x35, -1, 0, 0, (struct37 *) 4, 0xFF, 1);
    if (result != 0) {
        memcpy((char *) result + 0x28, &sp30, 4);
    }
}

extern f32 D_800A1378;
void func_150E8930();

void func_150E88C0(u8 *arg0) {
    *(f32 *)(arg0 + 0x28) -= D_800BE9A4;
    if (*(f32 *)(arg0 + 0x28) < 0.0f) {
        *(f32 *)(arg0 + 0x28) = (func_150ADA68() * D_800A1378) + 201.0f;
        func_150E8930(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8930.s")

extern f32 D_800A137C;
extern f32 D_800A1380;

void func_150E8A80(void) {
    struct260 *result;
    f32 sp38[3];

    sp38[0] = D_800A137C;
    sp38[1] = D_800A1380;
    sp38[2] = 0.0f;
    result = func_15149130((func_150ADA20() % 41U) + 0x1E, -1, 0x33, -1, 1, 0, (struct37 *) 0xC, 0xFF, 1);
    if (result != 0) {
        memcpy((char *) result + 0x28, sp38, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8D5C.s")

extern f32 D_800A13B0;
extern f32 D_800A13B4;

void func_150E90DC(void) {
    struct260 *result;
    f32 sp38[3];

    sp38[0] = D_800A13B0;
    sp38[1] = D_800A13B4;
    sp38[2] = 0.0f;
    result = func_15149130((func_150ADA20() % 26U) + 5, -1, 0x36, -1, 1, 0, (struct37 *) 0xC, 0xFF, 1);
    if (result != 0) {
        memcpy((char *) result + 0x28, sp38, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E9178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E93DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E971C.s")
