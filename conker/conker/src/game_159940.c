#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512C490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D238.s")

void func_1512D2E4(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x850) = arg1;
    arg0[0x84D] = 1;
}

extern s32 D_800DC290[];

void func_1512D2F8(u8 *arg0) {
    switch (arg0[0x84D]) {
    case 1:
        arg0[0x84E] = 0;
        arg0[0x84D] = 2;
        break;
    case 2:
        arg0[0x84E] += D_800BE9E4;
        if (arg0[0x84E] >= D_800DC290[*(s32 *)(arg0 + 0x850)]) {
            arg0[0x84D] = 0;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D368.s")
