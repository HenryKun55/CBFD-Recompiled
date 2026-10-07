#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150DE320(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE6D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE7C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DEACC.s")

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
