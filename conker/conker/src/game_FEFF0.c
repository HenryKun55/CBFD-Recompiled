#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FEFF0/func_150D1B40.s")

void func_150D1BD0(s32 arg0) {
    if (func_1509BE40(1, 0x402C, 6, 0x2000)) {
        *(s32 *)(arg0 + 0x84) |= 0x10;
    } else {
        *(s32 *)(arg0 + 0x84) &= ~0x10;
    }
}
