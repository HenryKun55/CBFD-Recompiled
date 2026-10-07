#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151D6970(s32 arg0, s32 arg1) {
    if ((D_800BE9F0 == 0x32) || (D_800BE9F0 == 0x33)) {
        func_150D6730(arg0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D69B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D6BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D6E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D7000.s")

void func_151D70CC(u8 *arg0, void *arg1, u8 arg2) {
    u8 *temp = *(u8 **)(arg0 + 0x48);
    func_15169850(arg1, arg2, temp, temp + 4, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D710C.s")
