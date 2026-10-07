#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_15189FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A214.s")

struct func_1518A2E8_s {
    u8 pad0[0x58];
    s32 unk58;
    u8 pad5C[0x188 - 0x5C];
    u8 *unk188;
};

s32 func_1518A2E8(struct func_1518A2E8_s *arg0, u8 *arg1) {
    if (arg0->unk188[0x6A] != 0) {
        arg0->unk58 &= ~2;
        *arg1 = 0;
    } else {
        *arg1 = 1;
    }
    return 1;
}

s32 func_1518A324(u8 *arg0, u8 *arg1) {
    if (*(*(u8 **)(arg0 + 0x188) + 0x6F) == 0) {
        *(s32 *)(arg0 + 0x58) &= ~2;
        *arg1 = 0;
    } else {
        *arg1 = 1;
    }
    return 1;
}

struct func_1518A360_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_1518A360(u8 *arg0, struct func_1518A360_s *arg1, u8 arg2) {
    u8 *p = arg0 + 0x170;
    if (arg2 == 0x2D) {
        if (arg1->unk0 == *(s32 *)(p + 0x18)) {
            *(s32 *)(p + 0x18) = arg1->unk4;
            p[0x1D] = arg1->unk9;
        } else if (arg1->unk4 == *(s32 *)(p + 0x18)) {
            *(s32 *)(p + 0x18) = arg1->unk0;
            p[0x1D] = arg1->unk8;
        }
    }
}
