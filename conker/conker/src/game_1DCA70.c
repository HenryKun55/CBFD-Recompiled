#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF5C0.s")

s32 func_151AF6C0(s32 arg0, s32 arg1) {
    return 12;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF6D4.s")

struct func_151AFBD4_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_151AFBD4(struct func_151AFBD4_s *arg0) {
    if (arg0->unk1C < 32) {
        if ((arg0->unk1C * 8) < arg0->unk28) {
            arg0->unk28 = arg0->unk1C * 8;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFEA4.s")
