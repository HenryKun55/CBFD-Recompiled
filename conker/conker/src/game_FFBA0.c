#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150D26F0_s {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10[1];
};

void func_150D278C(s32, s32 *, u8, u8);

void func_150D26F0(u8 *arg0) {
    struct func_150D26F0_s *p = (struct func_150D26F0_s *)(arg0 + 0x28);

    if (arg0[0x78] & 1) {
        p->unkC -= D_800BE9E4;
        if (p->unkC < 0) {
            func_150D278C(p->unk0, p->unk10, arg0[0xC], arg0[1]);
            p->unkC = (func_150ADA20() % (p->unk8 + 1)) + p->unk4;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D278C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D2924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D2D6C.s")

struct func_150D317C_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
};

f32 sinf(f32);

s32 func_150D317C(u8 *arg0) {
    struct func_150D317C_s *p;

    *(f32 *)(arg0 + 0x128) += *(f32 *)(arg0 + 0x130) * D_800BE9A4;
    *(f32 *)(arg0 + 0x12C) += *(f32 *)(arg0 + 0x134) * D_800BE9A4;
    p = (struct func_150D317C_s *)(arg0 + 0x110);
    p->unk18 = func_15144B68(p->unk18);
    p->unk1C = func_15144B68(p->unk1C);
    p->unk0 = sinf(p->unk18) * p->unk10 + p->unk8;
    p->unk4 = sinf(p->unk1C) * p->unk14 + p->unkC;
    p->unk28 -= D_800BE9A4;
    arg0[0x5C] = p->unk2C * p->unk28;
    if (p->unk28 > 0.0f) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D32FC.s")
