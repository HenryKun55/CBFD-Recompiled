#include <ultra64.h>
#include "functions.h"
#include "variables.h"


u16 *func_150B58F0(u16 *arg0, s32 arg1) {
    if (D_800C35EA == 1) {
        return arg0;
    }
    arg0[0] = 0x1A;
    arg0[1] = *(u16 *)((u8 *)D_800CC34A + arg1 * 0x32C);
    return arg0 + 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B6000.s")

extern u8 D_8009FC30[];

struct func_150B60E0_s {
    u8 pad[0x1D4];
    s32 unk1D4;
};

void func_150B60E0(struct func_150B60E0_s *arg0, void *arg1) {
    func_15143134(D_8009FC30, arg1, arg0->unk1D4 + 0x140);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B6110.s")

void func_150B6450(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x4A) {
        func_1516972C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B648C.s")

struct func_150B66DC_s {
    u8 pad0[0x14];
    u8 *unk14;
    u8 *unk18;
};

s32 func_150B66DC(struct func_150B66DC_s *arg0) {
    u8 *p = arg0->unk18;

    switch (p[0x68] - 15) {
        case 0:
            arg0->unk14[9] = 1;
            break;
        case 1:
            arg0->unk14[9] = 0;
            arg0->unk14[0x2F] = 0x14;
            break;
        case 2:
        default:
            arg0->unk14[9] = 0;
            arg0->unk14[0x2F] = 0x28;
            break;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B6754.s")
