#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108AB4.s")

struct func_15108B80_s {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[4];
    s32 unk1C;
    u8 pad20[0x30];
    s32 unk50;
};

void func_15108B80(struct func_15108B80_s *arg0) {
    struct func_15108B80_s *p = (struct func_15108B80_s *)((u8 *)arg0 + arg0->unk50 + 0xF8);
    if (p->unk14 != 999) {
        p->unk1C -= D_800BE9E4;
        if (p->unk1C < 0) {
            p->unk14 = 999;
        }
    }
}

struct func_15108BC0_s {
    u8 pad0[0x10];
    f32 unk10;
    s32 unk14;
    u8 pad18[0x38];
    s32 unk50;
};
void func_15108BC0(struct func_15108BC0_s *arg0) {
    struct func_15108BC0_s *p = (struct func_15108BC0_s *)((u8 *)arg0 + arg0->unk50 + 0xF8);
    s32 i = p->unk14;
    if (i == 999) {
        p->unk10 = 226.0f;
    } else if (D_800C35EA == 1) {
        struct233 *s = (struct233 *)((u8 *)D_800C3958 + i * sizeof(struct233));
        p->unk10 = s->unk4;
    } else {
        p->unk10 = 226.0f;
    }
}

extern f32 D_800A2480;
extern f32 D_800A2484;
extern f32 D_800A2488;
extern f32 D_800A248C;

struct func_15108C38_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 pad10[0x2];
    u8 unk12;
    u8 pad13[0xD];
    u8 unk20;
    u8 pad21[0x2F];
    s32 unk50;
};

s32 func_15108C38(struct func_15108C38_s *arg0) {
    struct func_15108C38_s *p = (struct func_15108C38_s *)((u8 *)arg0 + arg0->unk50 + 0xF8);

    p->unk8 += D_800A2480 * D_800BE9A4;
    p->unkC += D_800A2484 * D_800BE9A4;
    p->unk8 = func_15144B68(p->unk8);
    p->unkC = func_15144B68(p->unkC);
    p->unk0 = sinf(p->unk8) * D_800A2488;
    p->unk4 = sinf(p->unkC) * D_800A248C;
    func_15108B80(arg0);
    func_15108BC0(arg0);
    if (p->unk20 != 0) {
        arg0->unk12 = 4;
    } else {
        arg0->unk12 = 2;
    }
    return 1;
}

extern f32 D_800A2490;

struct func_15108D24_s {
    f32 unk0;
    f32 unk4;
    u8 pad8[8];
    f32 unk10;
    u8 pad14[0x3C];
    s32 unk50;
};

s32 func_15108D24(struct func_15108D24_s *arg0, s32 arg1) {
    f32 mf[4][4];
    struct func_15108D24_s *p;

    p = (struct func_15108D24_s *)((s32)arg0 + arg0->unk50 + 0xF8);
    func_150A8050(mf, p->unk0, 0.0f, p->unk4);
    mf[3][1] = p->unk10;
    mf[0][0] *= D_800A2490;
    mf[0][1] *= D_800A2490;
    mf[0][2] *= D_800A2490;
    mf[1][0] *= D_800A2490;
    mf[1][1] *= D_800A2490;
    mf[1][2] *= D_800A2490;
    mf[2][0] *= D_800A2490;
    mf[2][1] *= D_800A2490;
    mf[2][2] *= D_800A2490;
    guMtxF2L(mf, (Mtx *)((u8 *)arg0 + D_800BE9C0 * 0x40 + 0x78));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108E10.s")

struct func_15108FFC_s {
    s32 a;
    s32 b;
};

extern struct func_15108FFC_s D_80088C50;

void func_15108FFC(s32 arg0, s32 arg1, u8 arg2) {
    struct {
        s32 a;
        s32 b;
        u8 c;
    } sp24;
    struct func_15108FFC_s sp1C;

    sp1C = D_80088C50;
    sp24.a = arg0;
    sp24.b = arg1;
    sp24.c = arg2;
    func_15169260(&sp1C, 2, &sp24, 0x1D);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15109064.s")

struct func_151090DC_s {
    s32 a;
    s32 b;
};
extern struct func_151090DC_s D_80088C58;

void func_151090DC(void) {
    struct func_151090DC_s sp18;

    sp18 = D_80088C58;
    func_15169260(&sp18, 2, 0, 0x1E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15109120.s")
