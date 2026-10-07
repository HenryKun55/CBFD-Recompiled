#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B89E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B8F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9560.s")

struct func_150B95FC_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_150B95FC(struct func_150B95FC_s *arg0) {
    if (arg0->unk1C < 0x20) {
        arg0->unk5C = arg0->unk1C * 8;
    }
    return 1;
}

struct func_150B961C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150B961C(struct func_150B961C_s *arg0) {
    if (arg0->unk1C < 0x40) {
        arg0->unk28 = arg0->unk1C * 4;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B963C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9D8C.s")
