#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A6F00.s")

struct func_151A73EC_s {
    u8 pad0[0x64];
    s16 unk64;
    u8 pad66[0x170 - 0x66];
    struct102 *unk170[2];
};

s32 func_151A73EC(struct func_151A73EC_s *arg0) {
    struct102 **w = arg0->unk170;
    if (arg0->unk64 < 0x20) {
        if (w[1] != NULL) {
            func_1516972C(w[1]);
            w[1] = NULL;
        }
    }
    return 1;
}

void func_1514AB5C(f32, f32, f32, f32, s32, f32, f32, f32, f32, s32, s32, u8);

struct func_151A743C_sub {
    f32 unk0;
    struct102 *unk4;
    u8 unk8;
    u8 unk9;
    s16 unkA;
    s16 unkC;
};

struct func_151A743C_s {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8 pad1C[0x3C - 0x1C];
    f32 unk3C;
    u8 pad40[4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[4];
    s32 unk60;
    s16 unk64;
    u8 pad66[0x170 - 0x66];
    struct func_151A743C_sub unk170;
};

s32 func_151A743C(struct func_151A743C_s *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    struct func_151A743C_sub *s;
    u8 flag;
    s32 r;

    arg0->unk3C = arg0->unk10 + arg4;
    s = &arg0->unk170;
    if (s->unk4 != NULL) {
        func_1516972C(s->unk4);
        s->unk4 = NULL;
    }
    if (s->unk0 < arg0->unk48) {
        arg0->unk60 &= ~7;
        arg0->unk60 &= ~8;
        arg0->unk60 &= ~0x40;
        arg0->unk60 &= ~0x20;
        arg0->unk44 = 0.0f;
        arg0->unk48 = 0.0f;
        arg0->unk4C = 0.0f;
        if (arg0->unk64 > 0x20) {
            arg0->unk64 = 0x20;
        }
        if (s->unk8) {
            flag = 0;
            if (s->unk9) {
                flag = 1;
            }
            r = (func_150ADA20() % 3U) + 2;
            func_1514AB5C(arg1, arg4, arg3, arg0->unk18 * 35.0f, r, arg0->unk18, arg0->unk18 * 0.5f, arg0->unk18, arg0->unk18 * 0.5f, s->unkA, s->unkC, flag);
        }
    } else {
        arg0->unk44 *= arg0->unk14;
        arg0->unk48 = -arg0->unk48 * arg0->unk14;
        arg0->unk4C *= arg0->unk14;
        arg0->unk50 *= arg0->unk14;
        arg0->unk54 *= arg0->unk14;
        arg0->unk58 *= arg0->unk14;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A7610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A77C0.s")

struct func_151A787C_sub {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

struct func_151A787C_s {
    u8 pad0[0x34];
    s16 unk34[2];
    s16 unk38;
    u8 pad3A[0x3F - 0x3A];
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 pad43[0x50 - 0x43];
    struct func_151A787C_sub unk50;
};

void func_151A787C(struct func_151A787C_s *arg0) {
    struct func_151A787C_sub *s = &arg0->unk50;

    if (arg0->unk38 < arg0->unk50.unk4) {
        arg0->unk3F = arg0->unk38 * arg0->unk50.unk6;
    }
    if (arg0->unk38 < s->unk8) {
        s16 t = s->unkA * D_800BE9E4;
        arg0->unk34[0] += t;
        arg0->unk34[1] += t;
    }
    arg0->unk40 = arg0->unk41 = arg0->unk42 = arg0->unk38 * s->unk2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A7908.s")
