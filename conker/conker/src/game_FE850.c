#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FE850/func_150D13A0.s")

void *func_151149AC();

void func_150D1410(struct127 *arg0) {
    u8 *temp_v0;

    temp_v0 = func_151149AC(0xF9);
    if (temp_v0 != NULL) {
        if ((arg0 - gObjects) == 0) {
            temp_v0[0x6E] = 1;
        } else {
            temp_v0[0x6E] = 0;
        }
    }
}

void *func_151149AC();

void func_150D146C(s32 arg0) {
    u8 *temp_v0;

    temp_v0 = func_151149AC(0xF9);
    if (temp_v0 != NULL) {
        temp_v0[0x6E] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FE850/func_150D149C.s")
