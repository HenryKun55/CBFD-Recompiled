#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D3360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D3A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D3FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D4300.s")

struct func_150D49C0_s {
    u8 *unk0;
    u8 unk4;
    u8 pad5[3];
    struct126 *unk8;
};

struct func_150D49C0_a {
    u8 *unk0;
    u8 *unk4;
    u8 unk8;
    u8 unk9;
};

void func_150D49C0(struct102 *arg0, struct func_150D49C0_a *arg1, u8 arg2) {
    struct func_150D49C0_s *s = *(struct func_150D49C0_s **)((u8 *)arg0 + 0x98);
    u8 *p;

    if (arg2 == 0 || arg2 == 0x2E || arg2 == 3) {
        p = arg1->unk0;
        if (p == s->unk0 || ((struct func_150D49C0_s *)arg1)->unk4 == s->unk4) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (s->unk0 == arg1->unk0) {
            s->unk0 = arg1->unk4;
            s->unk4 = arg1->unk9;
            s->unk8 = func_1503195C(s->unk0, (s->unk0[4] == 0x48) ? 0x7A : 0x79, 0);
        } else if (s->unk0 == arg1->unk4) {
            s->unk0 = arg1->unk0;
            s->unk4 = arg1->unk8;
            s->unk8 = func_1503195C(s->unk0, (s->unk0[4] == 0x48) ? 0x7A : 0x79, 0);
        }
    }
}

extern s32 D_800A09D0;
extern s32 D_800A09DC;

s32 func_150D4AE0(f32 *arg0, f32 *arg1, u8 *arg2, s32 arg3) {
    void *sp30[2];
    f32 *sp28[2];

    if (*(s32 *)(arg2 + 0x1D4) != 0) {
        sp30[0] = &D_800A09D0;
        sp30[1] = &D_800A09DC;
        sp28[0] = arg0;
        sp28[1] = arg1;
        if (func_1514654C(arg2, arg3, 0, sp30, sp28, 2)) {
            return 1;
        }
        return 0;
    }
    arg0[0] = *(f32 *)(arg2 + 0x14);
    arg0[1] = *(f32 *)(arg2 + 0x18) + 100.0f;
    arg0[2] = *(f32 *)(arg2 + 0x1C);
    arg1[0] = *(f32 *)(arg2 + 0x14);
    arg1[1] = *(f32 *)(arg2 + 0x18) + 100.0f + 500.0f;
    arg1[2] = *(f32 *)(arg2 + 0x1C);
    return 2;
}

void func_150D4BD4(s32 arg0) {
    func_150D4C2C(arg0);
    func_151478F4(arg0);
}

void func_150D4C00(s32 arg0) {
    func_150D4C2C(arg0);
    func_15147928(arg0);
}

void func_150D5124(void);
void func_1000FD38();

struct func_150D4C2C_s {
    u8 pad0[0xC];
    struct102 *unkC;
    struct102 *unk10;
};

int func_150D4C2C(s32 arg0) {
    struct func_150D4C2C_s *s0 = *(struct func_150D4C2C_s **)(arg0 + 0x98);

    if (D_8008FD8C < 5) {
        func_1000FD38(func_150D5124, s0, 0x5B3);
    }
    func_1000FD38(func_150D5124, s0, 0x5B4);
    func_1000FD38(func_150D5124, s0, 0x5BC);
    if (s0->unkC != NULL) {
        func_1516972C(s0->unkC);
    }
    if (s0->unk10 != NULL) {
        func_1516972C(s0->unk10);
    }
}

extern s32 D_800A09C0[];
extern f32 D_800A0A14;

struct func_150D4CC4_sub {
    u8 pad0[0x48];
    f32 unk48;
    u8 pad4C[0x60 - 0x4C];
};

struct func_150D4CC4_s {
    u8 pad0[0x18];
    s8 unk18;
    u8 pad19[0x110 - 0x19];
    struct func_150D4CC4_sub sub;
    s16 unk170;
    u8 pad172[2];
    f32 unk174;
};

s32 func_150D4CC4(struct func_150D4CC4_s *arg0) {
    struct func_150D4CC4_sub *s;

    s = &arg0->sub;
    arg0->unk170 -= D_800BE9E4;
    if (arg0->unk170 < 0) {
        arg0->unk18 = D_800A09C0[func_150ADA20() & 3];
        arg0->unk170 = (func_150ADA20() & 7) + 3;
    }
    s->unk48 += (arg0->unk174 - s->unk48) * D_800A0A14;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D4D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D5124.s")
