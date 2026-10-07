#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5420.s")

struct func_150F5590_s {
    u8 pad0[0x24];
    s16 unk24;
    u8 pad26[0x12];
    s16 unk38;
    s16 unk3A;
};

void func_150F55C8(struct func_150F5590_s *arg0);

void func_150F5590(struct func_150F5590_s *arg0) {
    s32 temp;

    temp = 0x1000 - arg0->unk24 * 4;
    arg0->unk38 = temp;
    arg0->unk3A = arg0->unk38;
    func_150F55C8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F55C8.s")

void func_150F568C(s32 arg0) {
    func_15179008(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F56B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5C98.s")

void func_150F6138(s32 arg0, s32 arg1, s32 arg2) {
    func_15149514(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F631C.s")

void func_150F631C(s32 arg0);

void func_150F6368(s32 arg0) {
    func_150F631C(arg0);
    func_1514933C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6394.s")

void func_150F63C0(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

struct func_150F6400_s {
    u8 pad0[0x28];
    struct { s32 unk0; s32 unk4; s32 unk8; } unk28;
};

void func_150F6400(struct { u8 pad[0x160]; union { s32 i; struct func_150F6400_s *p; } unk160; } *arg0) {
    s32 *temp;

    if (arg0->unk160.i != 0) {
        temp = (s32 *)&arg0->unk160.p->unk28;
        temp[2] = 0;
    }
}

void func_150F6420(s32 arg0) {
    func_150F6400(arg0);
    func_1513CA6C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F644C.s")

void func_150F6478(s32 arg0) {
}

void func_150F6484(s32 arg0) {
    func_150F6478(arg0);
    func_151411A4(arg0);
}

void func_150F6478(s32 arg0);

void func_150F64B0(s32 arg0) {
    func_150F6478(arg0);
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F64DC.s")

void func_150F6850(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F695C.s")
