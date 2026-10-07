#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D2110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D21CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D227C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D22A8.s")

extern u8 D_800D9900;

void func_150D22D4(s32 arg0) {
    D_800D9900--;
}

void *func_1517F08C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void *func_150D22F4(void *arg0, u8 *arg1, s16 arg2) {
    if (arg1[0x28] == 1) {
        arg0 = func_1517F08C(arg0, arg1[0x3C], 0xFF, 0xFF, 0xFF, arg2);
    } else {
        arg0 = func_1517F08C(arg0, arg1[0x3D], 0, 0, 0, arg2);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D2374.s")
