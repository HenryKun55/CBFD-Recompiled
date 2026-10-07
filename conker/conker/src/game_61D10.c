#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034860.s")

extern s16 D_800C3EF0;
extern f32 D_80097D60;

struct func_15034EB4_e {
    u8 pad[0x34];
    f32 unk34;
    u8 pad2[0x8];
};

struct func_15034EB4_s {
    u8 pad[0x14C];
    f32 unk14C;
    u8 pad2[0x84];
    struct func_15034EB4_e *unk1D4;
};

void func_15034EB4(struct func_15034EB4_s *arg0, s32 arg1, s32 arg2) {
    f32 temp;
    s32 base;

    if (D_800C3EF0 != 0) {
        temp = D_800C3EF0 * D_80097D60 * arg0->unk14C;
        base = (s32)arg0->unk1D4;
        ((struct func_15034EB4_e *)((arg1 << 6) + base))->unk34 -= temp;
        if (arg2 != -1) {
            ((struct func_15034EB4_e *)((arg2 << 6) + base))->unk34 -= temp;
        }
    }
}

extern u8 D_800C3F00;

void func_15034F20(void) {
    D_800C3F00 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034F30.s")

struct func_150356C8_s {
    u8 pad[0xC];
};
extern u8 D_800C3F00;
extern struct func_150356C8_s D_800C3F08[];

void *func_150356C8(void) {
    if (D_800C3F00 == 15) {
        return NULL;
    }
    D_800C3F00++;
    return &D_800C3F08[D_800C3F00 - 1];
}

struct func_15035714_s {
    u8 pad[0xE];
    u16 unkE;
    s16 unk10;
};
struct func_15035714_a {
    u8 pad[4];
    u8 unk4;
    u8 pad5[0x13];
    f32 unk18;
    u8 pad1C[0x130];
    f32 unk14C;
    f32 unk150;
};
struct func_15035714_b {
    u8 pad[0x30];
    s32 unk30;
    u8 pad34[4];
    f32 unk38;
};
extern u8 D_800D9C10[];
extern f32 D_80097D70;
s32 func_150A6360(s32, void *, s32, f32, f32, f32, f32, f32);

s32 func_15035714(s32 arg0, struct func_15035714_a *arg1, struct func_15035714_b *arg2, f32 arg3) {
    s32 sp28[6];
    s32 idx;
    struct func_15035714_s *v;
    f32 f0;
    f32 f12;
    f32 pos;
    f32 a;
    f32 b;

    sp28[0] = D_800BE628;
    idx = arg1->unk4;
    v = (struct func_15035714_s *)D_800D1C90[idx];
    a = v->unkE * arg1->unk14C;
    b = v->unkE * arg1->unk150;
    f12 = v->unk10 * arg1->unk150;
    if (arg0 == 1 || arg0 == 0) {
        f0 = (arg1->unk18 + f12) - arg3;
        pos = arg3 - f0;
    } else {
        pos = arg1->unk18 + f12;
    }
    if (func_150A6360(sp28[0], D_800D9C10, arg2->unk30, pos, arg2->unk38, a, b, D_80097D70) == 0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15036148.s")
