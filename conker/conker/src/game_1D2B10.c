#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5CEC.s")

void func_151A5D2C(u16 arg0) {
    func_100111C8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6600.s")

struct func_151A6AB8_s {
    u8 pad0[0x110];
    u8 *unk110;
    u8 pad114[0xC];
    struct102 *unk120;
};

void func_1000FD38();

void func_151A6AB8(struct func_151A6AB8_s *arg0) {
    arg0->unk110[0x14] = 1;
    func_1000FD38(func_1000EF40, arg0->unk110, 0);
    if (arg0->unk120 != NULL) {
        func_1516972C(arg0->unk120);
    }
}

void func_151A6B10(s32 arg0) {
    func_151A6AB8(arg0);
    func_1513CA6C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6C90.s")
