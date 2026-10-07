#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DDB60/func_150B06B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DDB60/func_150B0A60.s")

void func_150B0C58(s32 arg0, s32 arg1, s32 arg2);

void func_150B0C34(s32 arg0) {
    func_150B0C58(arg0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DDB60/func_150B0C58.s")

void func_150B0CE0(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DDB60/func_150B0D20.s")
