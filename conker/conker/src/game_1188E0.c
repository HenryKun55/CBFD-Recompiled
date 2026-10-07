#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150EB430(f32 *arg0, f32 *arg1, s32 arg2) {
    f32 sp1C[3];

    sp1C[0] = arg1[0] + arg0[0];
    sp1C[1] = arg1[1] + arg0[1];
    sp1C[2] = arg1[2] + arg0[2];
    func_150EB484(arg0, sp1C, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1188E0/func_150EB484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1188E0/func_150EB614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1188E0/func_150EB8C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1188E0/func_150EBC80.s")
