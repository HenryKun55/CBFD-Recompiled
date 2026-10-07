#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D08C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D0E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D10E4.s")

extern f32 D_800A0894;

s32 func_150D11B4(void *arg0) {
    *(f32 *)((char *) arg0 + 0x74) = (func_150ADA68() * 150.0f + 350.0f) * D_800A0894;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D1204.s")
