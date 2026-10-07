#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B2740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B2EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B3188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B36AC.s")

struct func_150B378C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x98 - 0x1E];
    u8 *unk98;
};

s32 func_150B378C(struct func_150B378C_s *arg0) {
    u8 *p;
    s32 v;
    p = arg0->unk98;
    v = arg0->unk1C * 16;
    if (v >= 256) {
        v = 255;
    }
    if (v < p[0x1B]) {
        p[0x1B] = v;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B37C8.s")
