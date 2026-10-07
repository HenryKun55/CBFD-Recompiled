#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E7380/func_150B9ED0.s")

struct func_150BA35C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0xA];
    u8 unk28;
};

s32 func_150BA35C(struct func_150BA35C_s *arg0) {
    if (arg0->unk1C < 0x40) {
        arg0->unk28 = arg0->unk1C * 4;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7380/func_150BA37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7380/func_150BA424.s")
