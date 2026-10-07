#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150DE320(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE458.s")

extern f32 D_800A0D48;
extern f32 D_800A0D4C;
extern f32 D_800A0D50;
extern f32 D_800A0D54;

struct func_150DE6D8_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u8 pad14[0x7C - 0x14];
    s32 unk7C;
    s32 unk80;
    s32 unk84;
};

void func_150DE6D8(struct func_150DE6D8_s *arg0) {
    arg0->unk12 = (func_15048A40(arg0->unk7C >> 3) * D_800A0D48) + D_800A0D4C;
    arg0->unk0 = func_15048A40(arg0->unk80 >> 3) * D_800A0D50;
    arg0->unk8 = func_15048A40(arg0->unk84 >> 3) * D_800A0D54;
    arg0->unk7C += D_800BE9E4 * 12;
    arg0->unk80 += D_800BE9E4 * 16;
    arg0->unk84 += D_800BE9E4 * 24;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE7C0.s")

struct func_150DEACC_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    u8 pad40[0x110 - 0x40];
    f32 unk110;
    f32 unk114;
    f32 unk118;
    f32 unk11C;
};

s32 func_150DEACC(struct func_150DEACC_s *arg0) {
    arg0->unk34 += arg0->unk110 * D_800BE9A4;
    arg0->unk38 += arg0->unk114 * D_800BE9A4;
    arg0->unk3C += arg0->unk118 * D_800BE9A4;
    arg0->unk11C -= D_800BE9A4;
    if (arg0->unk11C < 0.0f) {
        return 0;
    }
    return 1;
}

s32 func_15140410(u8 *arg0, u8 *arg1, u8 *arg2, s16 arg3);

s32 func_150DEB58(u8 *arg0, s16 arg1) {
    if (D_800DBFF0[D_80082FA0].unk388 < 5.0f) {
        return 0;
    }
    return func_15140410(arg0, arg0 + 0x120, arg0 + 0x12C, arg1);
}

void func_150DEC28(u8 arg0, s32 arg1);

void func_150DEBE0(s32 arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        func_150DEC28(i, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DEC28.s")
