#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FED30.s")

extern s32 D_800A2050;
s32 func_1514654C(); /* extern */

void func_150FEFD0(u8 *arg0, s16 arg1, f32 *arg2) {
    void *sp34;
    f32 *sp30;
    struct126 *temp_v0;

    if (arg1 == -1) {
        arg2[0] = *(f32 *)(arg0 + 0x14);
        arg2[1] = *(f32 *)(arg0 + 0x18);
        arg2[2] = *(f32 *)(arg0 + 0x1C);
        return;
    }
    temp_v0 = func_1503195C(arg0, arg1, 0);
    if (temp_v0 == NULL) {
        arg2[0] = *(f32 *)(arg0 + 0x14);
        arg2[1] = *(f32 *)(arg0 + 0x18);
        arg2[2] = *(f32 *)(arg0 + 0x1C);
        return;
    }
    sp34 = &D_800A2050;
    sp30 = arg2;
    func_1514654C(arg0, temp_v0, 0, &sp34, &sp30, 1);
}

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

extern u8 D_800A2068;
extern u8 D_800A2074;
extern u8 D_800A205C;
extern f32 D_800A2080[2][6][3];

struct func_150FF6E0_s { f32 x, y, z; };
s32 func_150FF6E0(struct func_150FF6E0_s *arg0, void *arg1, f32 *arg2, f32 *arg3, void *arg4, s32 arg5, s32 arg6) {
    u8 r;
    void *sp5C[10];
    void *sp34[10];
    u8 i;

    r = func_150ADA20() & 1;
    sp5C[0] = &D_800A2050;
    sp5C[1] = &D_800A2068;
    sp5C[2] = &D_800A2074;
    sp5C[3] = &D_800A205C;
    for (i = 0; i < 6; i++) {
        sp5C[4 + i] = D_800A2080[r][i];
        sp34[4 + i] = &arg0[i];
    }
    sp34[0] = arg1;
    sp34[1] = arg2;
    sp34[2] = arg3;
    sp34[3] = arg4;
    if (func_1514654C(arg5, arg6, 0, sp5C, sp34, 10)) {
        arg3[0] -= arg2[0];
        arg3[1] -= arg2[1];
        arg3[2] -= arg2[2];
    } else {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF840.s")

void func_1505D1C4(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6, s32 arg7);

void func_150FFB6C(f32 *arg0, s32 arg1, struct127 *arg2, s32 arg3) {
    u16 temp = *(u16 *)((u8 *)arg2 + 0x7A);
    func_1505D1C4(arg0[0], arg0[1], arg0[2], arg3 | 0x60000, arg2 - gObjects, temp, 0, arg1);
}

extern u8 D_800A2130[];
void func_15145EA4();

void func_150FFBDC(s32 arg0, s32 arg1, s32 arg2) {
    void *sp1C[1];
    s32 sp18[1];

    sp1C[0] = D_800A2130;
    sp18[0] = arg2;
    func_15145EA4(sp1C, sp18, *(s32 *)(arg0 + 0x1D4) + (D_80088BB0 << 6), 1);
}

void func_150FFC3C(struct127 *arg0) {
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    if (arg0->camera == 0) {
        return;
    }
    local.f0 = 1;
    local.f2 = (u32) func_150ADA20() % 11 + 20;
    local.f5 = 1 << arg0->camera->unk23D;
    local.f4 = (func_150ADA20() & 1) + 7;
    local.f6 = -1;
    func_151D8868(&local, 0, 0xFF, 1);
}

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
