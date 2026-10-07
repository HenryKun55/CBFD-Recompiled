#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E5FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E6230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E63A0.s")

struct func_150E679C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_150E679C(struct func_150E679C_s *arg0) {
    if (arg0->unk1C < 8) {
        if ((arg0->unk1C << 5) < arg0->unk5C) {
            arg0->unk5C = arg0->unk1C << 5;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E67D0.s")
