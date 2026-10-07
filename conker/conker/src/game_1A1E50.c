#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151749A0(s32 arg0, s32 arg1) {
    D_800DD406 += D_800BE9E4;
    if (arg0 < D_800DD406) {
        D_800DD405++;
        if (D_800DD405 >= arg1) {
            D_800DD405 = 0;
        }
        D_800DD406 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A1E50/func_151749F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A1E50/func_15174AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A1E50/func_15174B48.s")
