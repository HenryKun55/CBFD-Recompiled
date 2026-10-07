#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15165F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15166118.s")

struct func_15166204_s {
    u8 pad0[0x92];
    u8 unk92;
    u8 pad93[3];
    s16 unk96;
    u8 pad98[6];
    s16 unk9E;
};

void func_15166204(struct func_15166204_s *arg0) {
    s32 temp;

    temp = arg0->unk92;
    arg0->unk9E += arg0->unk96 * D_800BE9E4;
    temp -= D_800BE9E4;
    if (temp <= 0) {
        func_1516972C((struct102 *)arg0);
    } else {
        arg0->unk92 = temp;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15166268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_151668B8.s")
