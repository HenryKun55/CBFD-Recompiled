#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0100/func_15172C50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0100/func_15172CA8.s")

struct func_15172D28_s {
    u8 pad0[0x2F8];
    u16 unk2F8;
    u8 pad2FA[0x31C - 0x2FA];
    u8 *unk31C;
};

void func_15085430(struct func_15172D28_s *, s32, s32);

void func_15172D28(struct func_15172D28_s *arg0, s32 arg1) {
    func_15085430(arg0, arg1, 1);
    arg0->unk2F8 &= 0xFFEF;
    if (D_800BE9B4 == 0) {
        if (arg0->unk31C != NULL) {
            arg0->unk31C[0x56] = 3;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0100/func_15172D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0100/func_15172E7C.s")
