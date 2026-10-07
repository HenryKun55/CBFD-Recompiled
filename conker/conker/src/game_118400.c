#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_118400/func_150EAF50.s")

s32 func_150EB030(s32 arg0, s32 arg1) {
    if (arg0 == 1) {
        if (D_800BE9F0 == 4) {
            if (func_151420F8(arg1)) {
                return 6;
            } else {
                return 3;
            }
        } else {
            return -1;
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_118400/func_150EB090.s")
