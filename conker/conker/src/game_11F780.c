#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F22D0.s")

s32 func_150F237C(s32 arg0, s32 arg1) {
    return 0xE;
}

struct func_150F2390_s {
    u8 pad[0x1D4];
    void *unk1D4;
};
void func_150F22D0();

void func_150F2390(struct func_150F2390_s *arg0, u8 arg1, s32 arg2) {
    u8 sp1C[0xC];

    if (arg0->unk1D4 != NULL) {
        func_150F22D0(sp1C, arg0, arg1);
        func_151C329C(sp1C, 0xFF, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F23E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F25A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F26A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2994.s")
