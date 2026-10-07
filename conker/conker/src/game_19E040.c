#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15170B90.s")

void func_15170B90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

void func_15170EC4(s32 arg0, u8 arg1, s32 arg2) {
    switch (D_800BE9F0) {
    case 2:
        func_15170B90(arg0, 1, 1, 1, arg1, arg2);
        break;
    case 16:
        func_15170B90(arg0, 0xA9, 8, 0, arg1, arg2);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15170F4C.s")

void func_151711C4(u8 *arg0) {
    if (arg0[4] == 0x33) {
        func_150C3D5C();
    }
    func_15060F28(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_151717FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_151718F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171BF4.s")
