#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F48D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4A38.s")

void func_150F4CFC(u8 *arg0, s32 arg1, u8 arg2) {
    u8 *p = arg0 + 0x170;

    if (arg2 == 0x4E) {
        arg0[0x71] = 0;
        p[0x24] |= 5;
    } else if (arg2 == 0x4F) {
        func_1516972C((struct102 *) arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4DEC.s")
