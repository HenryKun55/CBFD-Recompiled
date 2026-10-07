#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6B40/func_151B9690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6B40/func_151B9964.s")

struct func_151B9BF0_s {
    u8 pad0[0x10];
    s32 unk10;
    u8 unk14;
    u8 unk15;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
};

struct func_151B9BF0_s *func_15167A68(s32, s32, s32, s32, u8, s32);

void func_151B9BF0(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, s16 argB, s16 argC, s32 argD, u8 argE, s32 argF) {
    struct func_151B9BF0_s *v0 = func_15167A68(7, argF, 0x2C, 0, argE, 1);

    if (v0 != NULL) {
        v0->unk14 = arg0;
        v0->unk15 = arg1;
        v0->unk16 = arg2;
        v0->unk18 = arg3;
        v0->unk1A = arg4;
        v0->unk1C = arg5;
        v0->unk1E = arg6;
        v0->unk20 = arg7;
        v0->unk22 = arg8;
        v0->unk24 = arg9;
        v0->unk26 = argA;
        v0->unk28 = argB;
        v0->unk2A = argC;
        v0->unk10 = argD;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6B40/func_151B9CB0.s")
