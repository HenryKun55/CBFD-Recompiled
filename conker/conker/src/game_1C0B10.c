#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0B10/func_15193660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0B10/func_151937F4.s")

extern f32 D_800A81E8;

s32 func_151938E4(void *arg0) {
    *(f32 *)((char *)arg0 + 0x74) = D_800A81E8;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0B10/func_151938FC.s")
