#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179FE0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517AA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517AB7C.s")
