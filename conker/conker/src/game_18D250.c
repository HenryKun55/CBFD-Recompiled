#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_1515FDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_1515FF74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_1515FFEC.s")

extern void (*D_8008B0E4[])(void *, s32, u8);

void func_15160090(u8 *arg0, s32 arg1, u8 arg2) {
    void (*fn)(void *, s32, u8) = D_8008B0E4[arg0[0x14]];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_151600D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_15160274.s")
