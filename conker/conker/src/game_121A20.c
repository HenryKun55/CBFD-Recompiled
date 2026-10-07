#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4570.s")

void func_1514373C(f32, f32, f32 *, f32 *);

struct func_150F48D0_q {
    f32 timer;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

struct func_150F48D0_s {
    u8 pad0[0x20];
    f32 unk20[3];
    u8 pad2C[0x38 - 0x2C];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50[3];
    u8 pad5C[0x170 - 0x5C];
    struct func_150F48D0_q unk170;
};

s32 func_150F48D0(struct func_150F48D0_s *arg0) {
    struct func_150F48D0_q *q;
    f32 c;
    f32 s;

    q = &arg0->unk170;
    arg0->unk170.timer -= D_800BE9A4;
    if (arg0->unk170.timer <= 0.0f) {
        return 0;
    }
    func_1514373C(q->unk10, q->unk20, &s, &c);
    q->unk10 += q->unk14 * D_800BE9A4;
    q->unk4 += arg0->unk44 * D_800BE9A4;
    q->unk8 += arg0->unk48 * D_800BE9A4;
    q->unkC += arg0->unk4C * D_800BE9A4;
    arg0->unk38 = q->unk4 + s * q->unk18;
    arg0->unk3C = q->unk8 + c;
    arg0->unk40 = q->unkC - s * q->unk1C;
lbl:
    arg0->unk20[0] += arg0->unk50[0] * D_800BE9A4;
    arg0->unk20[1] += arg0->unk50[1] * D_800BE9A4;
    arg0->unk20[2] += arg0->unk50[2] * D_800BE9A4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4A38.s")

void func_150F4CFC(u8 *arg0, s32 arg1, u8 arg2) {
    u8 *p = arg0 + 0x170;

    if (arg2 == 0x4E) {
        arg0[0x71] = 0;
        p[0x24] |= 5;
    } else if (arg2 == 0x4F) {
        func_1516972C((struct102 *) arg0);
    }
}

struct func_150F4D5C_s {
    s32 unk0;
    f32 unk4;
    s8 unk8;
    u8 unk9;
};

void func_150F4D5C(s32 arg0, s8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    struct func_150F4D5C_s tmp;
    struct260 *temp_v0;

    tmp.unk0 = arg0;
    tmp.unk4 = 0.0f;
    tmp.unk8 = arg1;
    tmp.unk9 = arg2;
    temp_v0 = func_15149130(0x12C, -1, 0x56, -1, 0, 0, 0xC, arg3, arg4);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4DEC.s")
