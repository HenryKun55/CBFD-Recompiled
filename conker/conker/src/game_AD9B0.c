#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_150806A8.s")

void func_15080718(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg2 = 1 << (arg0 & 7);
    *arg1 = arg0 >> 3;
}

extern u8 D_800BE580[];
void func_15080718(s32 arg0, s32 *arg1, s32 *arg2);

s32 func_15080738(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    func_15080718(arg0, &sp1C, &sp18);
    if (D_800BE580[sp1C] & sp18) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080784.s")

void func_150807F4(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 == 0x20) {
        func_15080784();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080C64.s")

s32 func_15080CF4(void) {
    if (D_800D1941 == 0) {
        return 1;
    }
    return 0;
}
