#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FED30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FEFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF084.s")

void func_150FF288(s32 arg0) {
    func_1503195C(arg0, 0x82, 0);
}

extern f32 D_800A211C;
void func_15145740(void *arg0, void *arg1, void *arg2, void *arg3, f32 arg4);

void func_150FF2AC(void *arg0, void *arg1, void *arg2, void *arg3) {
    func_15145740(arg0, arg1, arg2, arg3, D_800A211C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF2D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF474.s")

s32 func_150FF6B4(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0[4] == 0x98) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFB6C.s")

extern u8 D_800A2130[];
void func_15145EA4();

void func_150FFBDC(s32 arg0, s32 arg1, s32 arg2) {
    void *sp1C[1];
    s32 sp18[1];

    sp1C[0] = D_800A2130;
    sp18[0] = arg2;
    func_15145EA4(sp1C, sp18, *(s32 *)(arg0 + 0x1D4) + (D_80088BB0 << 6), 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFC3C.s")

extern s32 D_8008FC8C;
extern u8 *D_8008FC94;
void *func_151D5A18();
void *func_151D3E6C();

void func_150FFCC8(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    func_151D5A18(arg0, arg1, arg2, arg3, arg4, D_8008FC8C, *D_8008FC94);
    func_151D3E6C(arg0, arg1, arg1, 0x8003A);
}

struct func_150FFD2C_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x94 - 5];
    s32 unk94;
};

void func_15081E0C(struct func_150FFD2C_s *, s32, s32);

void func_150FFD2C(s32 arg0, struct func_150FFD2C_s *arg1, s32 arg2) {
    if ((arg1->unk4 == 0x9F) || (arg1->unk4 == 0xA0)) {
        if (!(arg1->unk94 & 0x80)) {
            func_15081E0C(arg1, 4, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFD84.s")
