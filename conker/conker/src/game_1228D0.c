#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150F5420_s {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
};
extern u8 D_800917F8[];
extern u8 D_80091930[];
extern u8 D_8009193C[];
extern u8 D_80091948[];
void *func_15169968(struct func_150F5420_s *arg0);

void func_150F5420(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_150F5420_s sp24;
    s32 temp_v0;

    if (arg3 != 0) {
        if (arg3 == 2) {
            sp24.unk2C = 0xF0;
            sp24.unk2E = 0xBA;
            sp24.unk0 = D_80091948;
        } else {
            sp24.unk2C = 0x10E;
            sp24.unk2E = 0x7C;
            if (arg3 == 1) {
                sp24.unk0 = D_80091930;
            } else {
                sp24.unk0 = D_8009193C;
            }
        }
        sp24.unk30 = 9;
        sp24.unk39 = 0x10;
        sp24.unk28 = 0;
        sp24.unk2A = 0;
        sp24.unk36 = 8;
    } else {
        sp24.unk0 = D_800917F8;
        sp24.unk30 = 0xA;
        sp24.unk2C = 0xA0;
        sp24.unk2E = 0xC0;
        sp24.unk39 = 0x20;
        sp24.unk28 = 0x1000;
        sp24.unk2A = 0x1000;
        sp24.unk36 = 0x18;
    }
    sp24.unk8 = (arg0 << 0x10) | arg1;
    temp_v0 = arg0 + arg1 + arg2;
    sp24.unkC = (arg2 << 0x10) | temp_v0;
    sp24.unk10 = 0x2710;
    sp24.unk14 = temp_v0;
    sp24.unk18 = 0;
    sp24.unk24 = 0;
    sp24.unk26 = 0;
    sp24.unk31 = 1;
    sp24.unk32 = 0xFF;
    sp24.unk33 = 0xFF;
    sp24.unk34 = 0xFF;
    sp24.unk37 = 0x11;
    sp24.unk35 = 0;
    sp24.unk16 = 0;
    sp24.unk1C = 146.0f;
    sp24.unk20 = 100.0f;
    func_15169968(&sp24);
}

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

struct func_150F55C8_s {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
    u8 pad20[4];
    s16 unk24;
    u8 pad26[0x1F];
    u8 unk45;
};

void func_150F55C8(struct func_150F5590_s *arg0) {
    struct func_150F55C8_s *s = (struct func_150F55C8_s *)arg0;
    s32 lo = s->unk1C & 0xFFFF;
    s32 bhi = s->unk18 >> 16;
    s32 blo = s->unk18 & 0xFFFF;
    s32 ahi = s->unk1C >> 16;
    s32 d = lo - bhi;

    if (d < s->unk24) {
        s->unk45 = ((lo - s->unk24) * 255) / bhi;
    } else if (d - blo < s->unk24) {
        s->unk45 = 255;
    } else {
        s->unk45 = (s->unk24 * 255) / ahi;
    }
}

void func_150F568C(s32 arg0) {
    func_15179008(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F56B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5A54.s")

void func_150F5C08(u8 *arg0, s16 arg1, u8 arg2, s32 arg3) {
    u8 tmp[0xC];
    struct260 *temp_v0;

    *(u8 **) &tmp[0] = arg0;
    tmp[4] = arg0[0x3B];
    *(f32 *) &tmp[8] = 0.0f;
    temp_v0 = func_15149130(arg1, -1, 0x51, -1, 1, 0x3E, (struct37 *) 0xC, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, tmp, 0xC);
    }
}

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

extern f32 D_800A1B70;
void *func_15134DAC();

struct func_150F6890_s {
    u8 unk0;
    void *unk4;
    u8 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    u8 unk2E;
    u8 unk2F;
    s8 unk30;
    f32 unk34;
    u8 unk38;
    s8 unk39;
};

void func_150F6890(arg0, arg1, arg2, arg3)
    u8 *arg0;
    s16 arg1;
    s32 arg2;
    s32 arg3;
{
    struct func_150F6890_s sp1C;

    sp1C.unk0 = arg0[0x3B];
    sp1C.unk1C = D_800A1B70;
    sp1C.unk20 = 8.5f;
    sp1C.unk34 = 1.0f;
    sp1C.unk4 = arg0;
    sp1C.unk8 = 3;
    sp1C.unkC = 0.0f;
    sp1C.unk10 = 0.0f;
    sp1C.unk14 = 0.0f;
    sp1C.unk18 = 0.0f;
    sp1C.unk24 = 2;
    sp1C.unk26 = 0x28;
    sp1C.unk28 = 0x10;
    sp1C.unk2A = arg1;
    sp1C.unk2E = 5;
    sp1C.unk2F = 8;
    sp1C.unk30 = -1;
    sp1C.unk38 = 0;
    sp1C.unk39 = -1;
    sp1C.unk2C = 0;
    func_15134DAC(&sp1C, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F695C.s")
