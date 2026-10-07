#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150412C0.s")

s32 func_15041480(u8 arg0);
void *func_15041508(void *arg0, void *arg1, s32 arg2, s32 arg3);

void *func_150413FC(void *arg0, u8 arg1[][8], s32 arg2, u8 *arg3) {
    s32 i = 0;
    while (arg3[i] != 0) {
        arg0 = func_15041508(arg0, arg1[i], arg2, func_15041480(arg3[i]));
        i++;
    }
    return arg0;
}

extern u8 D_800848D0[];

s32 func_15041480(u8 arg0) {
    s32 i;

    for (i = 0; i < 80; i++) {
        if (arg0 == D_800848D0[i]) {
            return i;
        }
    }
    return i;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_15041508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150415E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150417AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150428D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_15042C40.s")
