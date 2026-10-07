#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800D1928;
extern s32 D_800D192C;
extern s32 D_800D1930;

void func_15080200(void) {
    s32 *a = &D_800D192C;
    s32 *b = &D_800D1928;

    *a = 0;
    *b = 0;
    D_800D1930 = 0;
    if (a == b) {
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD6B0/func_15080228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD6B0/func_15080348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD6B0/func_15080430.s")
