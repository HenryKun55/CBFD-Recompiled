#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void *func_15147D64();

void func_1519CF70(u8 arg0) {
    u8 sp1C[4];

    sp1C[0] = arg0;
    func_15147D64(sp1C, 6);
}

struct func_1519CFA0_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    u8 *unk98;
};

void func_1519CFA0(struct func_1519CFA0_s *arg0) {
    u8 *temp_v0 = arg0->unk98;
    arg0->unk1E &= ~2;
    arg0->unk30 = 0;
    temp_v0[6] |= 1;
    temp_v0[6] |= 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519CFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E570.s")

void func_1519E61C(struct102 *arg0, s32 arg1, u8 arg2) {
    if ((arg2 == 0) || (arg2 == 9)) {
        func_1516972C(arg0);
    }
}

void func_1519E65C(s32 arg0) {
    func_1519CF70(3);
    func_1519CF70(4);
}

void func_1519E688(void) {
    func_1519CF70(3);
    func_1519CF70(4);
    func_15147D64(0, 9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E818.s")

struct func_1519E8CC_s {
    u8 pad0[0x28];
    s32 unk28;
};

void func_1514EDF0(struct func_1519E8CC_s *arg0, s32 arg1);

void func_1519E8CC(struct func_1519E8CC_s *arg0) {
    func_1514EDF0(arg0, arg0->unk28);
    func_1514933C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E8F8.s")

extern s32 D_800E0920;

void func_1519E924(s32 arg0) {
    D_800E0920 = 0;
    func_1514933C(arg0);
}

extern s32 D_800E0920;

void func_1519E948(void) {
    D_800E0920 = 0;
    func_15149368();
}
