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

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108D24.s")

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
