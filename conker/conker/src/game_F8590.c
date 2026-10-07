#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800A05E0[];
extern u8 D_800A05EC[];
s32 func_15046C80(f32 *, s32, f32, s32);

s32 func_150CB0E0(f32 *arg0, s32 arg1, s32 arg2, u8 arg3) {
    f32 sp2C[3];

    if ((arg3 != 1) && (arg3 != 2)) {
        return 0;
    }
    func_15143134((arg3 == 1) ? D_800A05EC : D_800A05E0, arg0,
                  (arg3 == 1) ? *(s32 *)(arg1 + 0x1D4) + 0xA00 : *(s32 *)(arg1 + 0x1D4) + 0xBC0);
    if (arg2 == 0) {
        return 1;
    }
    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + 100.0f;
    sp2C[2] = arg0[2];
    func_1504715C(arg2, arg1);
    return func_15046C80(sp2C, 0, arg0[1] - 500.0f, arg2);
}

s32 func_150CB1E0(s32 arg0, s32 arg1) {
    return 11;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB1F4.s")

struct func_150CB7CC_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150CB7CC(struct func_150CB7CC_s *arg0) {
    s32 tmp;
    if (arg0->unk1C < 32) {
        tmp = arg0->unk1C * 8;
        if (tmp < arg0->unk28) {
            arg0->unk28 = tmp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB800.s")

struct func_150CBA30_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    u8 unk5C;
    u8 pad5D[0x128 - 0x5D];
    s16 unk128;
    u8 pad12A[2];
    f32 unk12C;
};

s32 func_150CBA30(struct func_150CBA30_s *arg0) {
    s32 tmp;
    f32 f;

    arg0->unk128 -= D_800BE9E4;
    if (arg0->unk128 > 0) {
        f = arg0->unk12C * D_800BE9A4;
        arg0->unk2C += f;
        arg0->unk30 += f;
    }
    if (arg0->unk58 & 1) {
        if (arg0->unk1C < 32) {
            tmp = arg0->unk1C * 8;
            if (tmp < arg0->unk5C) {
                arg0->unk5C = tmp;
            }
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBABC.s")

s32 func_150CBCE0(f32 *arg0, s32 arg1) {
    s32 i;
    f32 *p = &arg0[0xA8 / 4];

    for (i = D_800BE9E4; i != 0; i--) {
        arg0[0x58 / 4] *= *p;
        arg0[0x60 / 4] *= *p;
    }
    return 1;
}

struct func_150CBE88_s {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
};

s32 func_150CBE88(struct func_150CBE88_s *arg0) {
    arg0->unk38 += arg0->unk44 * D_800BE9A4;
    arg0->unk3C += (arg0->unk48 * D_800BE9A4) + (arg0->unk5C * D_800BE9A4 * D_800BE9A4 * 0.5f);
    arg0->unk40 += arg0->unk4C * D_800BE9A4;
    arg0->unk48 += arg0->unk5C * D_800BE9A4;
    arg0->unk20 += arg0->unk50 * D_800BE9A4;
    arg0->unk24 += arg0->unk54 * D_800BE9A4;
    arg0->unk28 += arg0->unk58 * D_800BE9A4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBF5C.s")
