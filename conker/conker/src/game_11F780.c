#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F22D0.s")

s32 func_150F237C(s32 arg0, s32 arg1) {
    return 0xE;
}

struct func_150F2390_s {
    u8 pad[0x1D4];
    void *unk1D4;
};
void func_150F22D0();

void func_150F2390(struct func_150F2390_s *arg0, u8 arg1, s32 arg2) {
    u8 sp1C[0xC];

    if (arg0->unk1D4 != NULL) {
        func_150F22D0(sp1C, arg0, arg1);
        func_151C329C(sp1C, 0xFF, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F23E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2480.s")

struct func_150F2518_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

struct func_150F2518_a {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[0x78 - 0x54];
    Mtx unk78[2];
    u8 unkF8[1];
};

s32 func_150F2518(struct func_150F2518_a *arg0, s32 arg1) {
    f32 mtx[4][4];
    struct func_150F2518_s *temp_v0;


    temp_v0 = (struct func_150F2518_s *) ((s32) arg0 + arg0->unk50 + 0xF8);
    func_150A8050(mtx, temp_v0->unk24, 0.0f, temp_v0->unk28);
    mtx[3][0] = temp_v0->unk18;
    mtx[3][1] = temp_v0->unk1C;
    mtx[3][2] = temp_v0->unk20;
    guMtxF2L(mtx, (Mtx *) ((s32) arg0 + (D_800BE9C0 << 6) + 0x78));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F25A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F26A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2994.s")
