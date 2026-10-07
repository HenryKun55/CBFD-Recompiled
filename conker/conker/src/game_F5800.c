#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8350.s")

void func_150C84F4(s32 arg0) {
    if (arg0 == 0) {
        func_150C8350();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C851C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C88D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C99B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C9BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C9DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CA07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CA150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CA930.s")

struct func_150CA9D0_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150CA9D0(struct func_150CA9D0_s *arg0) {
    if (arg0->unk1C < 0x20) {
        if ((arg0->unk1C * 8) < arg0->unk28) {
            arg0->unk28 = arg0->unk1C * 8;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CAA04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CAC28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CADD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CB008.s")
