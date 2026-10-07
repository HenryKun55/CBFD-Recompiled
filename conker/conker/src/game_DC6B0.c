#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF200.s")

void func_151CF898(void *arg0, f32 arg1, f32 arg2);

void func_150AF2E0(void *arg0, s16 *arg1) {
    func_151CF898(arg0, arg1[4] + arg1[1], arg1[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF328.s")

void *func_15131828();
void *func_15131958();

s32 func_150AF6E4(u8 *arg0, s32 arg1) {
    u8 *temp_a2;

    temp_a2 = arg0 + 0xA8;
    func_15131828(arg0, arg0 + 0xAC, temp_a2, arg0 + 0xAA);
    func_15131958(arg0 + 0x58, *(s32 *)(temp_a2 + 0xC));
    return 1;
}

struct func_150AF738_s {
    u8 unk0;
    s8 unk1;
    u8 unk2;
    u8 pad3;
    s16 unk4;
    u8 unk6;
};

void *func_1515FF74(void *, s32, u8, s32);

void func_150AF738(s16 arg0, u8 arg1, s32 arg2) {
    struct func_150AF738_s sp18;

    sp18.unk0 = 1;
    sp18.unk1 = -1;
    sp18.unk2 = 2;
    sp18.unk6 = 0;
    sp18.unk4 = arg0;
    func_1515FF74(&sp18, 0, arg1, arg2);
}

void func_150B1DB0(u8 *arg0, u8 *arg1);

void func_150AF790(s32 arg0, u8 *arg1) {
    func_150B1DB0(arg1, arg1 + 0x1ECC0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF7C4.s")

struct func_150AFBF4_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

s32 func_150AFBF4(u8 *arg0) {
    struct func_150AFBF4_s *temp_v1;

    *(f32 *)(arg0 + 0x78) += *(f32 *)(arg0 + 0x7C) * D_800BE9A4;
    temp_v1 = (struct func_150AFBF4_s *)(arg0 + 0x70);
    temp_v1->unk8 = func_15144B68(*(f32 *)(arg0 + 0x78));
    *(f32 *)(arg0 + 0x10) = (sinf(temp_v1->unk8) * temp_v1->unk4) + temp_v1->unk0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFE64.s")

void func_15179008(s32);
void func_150AF200(s32, s32);

void func_150B003C(s32 arg0) {
    if (D_800BE9F0 == 6) {
        func_15179008(0);
        func_150AF200(0xE2, 0xE1);
    } else {
        func_150AF200(0xDF, 0xDE);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0094.s")

struct func_150B02C0_s {
    u8 pad0[0x170];
    union {
        s32 w;
        struct102 *p;
    } unk170;
};

void func_150B02C0(struct func_150B02C0_s *arg0) {
    if (arg0->unk170.w != 0) {
        func_1516972C(arg0->unk170.p);
    }
}

void func_150B02F0(s32 arg0) {
    func_150B02C0(arg0);
    func_15132570(arg0);
}

void func_150B031C(s32 arg0) {
    func_150B02C0(arg0);
    func_1513259C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B060C.s")
