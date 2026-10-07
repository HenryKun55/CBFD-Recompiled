#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB0E0.s")

s32 func_150CB1E0(s32 arg0, s32 arg1) {
    return 11;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB1F4.s")

struct func_150CB7CC_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150CB7CC(struct func_150CB7CC_s *arg0) {
    s32 tmp;
    if (arg0->unk1C < 32) {
        tmp = arg0->unk1C * 8;
        if (tmp < arg0->unk28) {
            arg0->unk28 = tmp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBF5C.s")
