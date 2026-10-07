#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCBC0.s")

extern f32 D_800A1F2C;
f32 func_15165BB0(void *, f32 *, f32, f32, f32);

f32 func_150FCF1C(void *arg0) {
    struct134 *p = D_800D9AA0[0];
    f32 sp20[3];

    if (p == NULL) {
        return 1.0f;
    }
    sp20[0] = p->unk0;
    sp20[1] = (s16)p->unk2;
    sp20[2] = p->unk4;
    return func_15165BB0(arg0, sp20, 2007.0f, 9005.0f, D_800A1F2C);
}

void func_150FCFB0(s32 arg0) {
    func_15103828();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FD514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FDB0C.s")

struct func_150FDBA0_s {
    u8 pad0[0x124];
    f32 unk124;
    f32 unk128;
};

s32 func_150FDBA0(struct func_150FDBA0_s *arg0, s16 arg1) {
    s16 *v;

    v = (s16 *)func_1513EDE4((s32)arg0, arg1);
    if (v != NULL) {
        v[0x8 / 2] = arg0->unk124;
        v[0x18 / 2] = arg0->unk128;
        v[0x28 / 2] = arg0->unk128;
        v[0x38 / 2] = arg0->unk124;
    }
    return (s32)v;
}

struct func_150FDC2C_s {
    u8 pad0[0x24];
    struct102 *unk24;
    struct102 *unk28;
    u8 pad2C[0x54 - 0x2C];
    u16 unk54;
    u16 unk56;
};

struct func_150FDC2C_t {
    u8 pad0[0x110];
    struct func_150FDC2C_s unk110;
};

void func_150FDC2C(struct func_150FDC2C_t *arg0) {
    struct func_150FDC2C_s *s = &arg0->unk110;

    if (arg0->unk110.unk24 != NULL) {
        func_1516972C(s->unk24);
    }
    if (s->unk28 != NULL) {
        func_1516972C(s->unk28);
    }
    if (s->unk54 != 0) {
        func_100111C8(s->unk54);
    }
    if (s->unk56 != 0) {
        func_100111C8(s->unk56);
    }
}

void func_150FDCAC(s32 arg0) {
    func_150FDC2C(arg0);
    func_1513CA6C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FDCD8.s")
