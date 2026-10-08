#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CBF80.s")

struct func_150CC638_sub {
    s16 unk0;
    f32 unk4;
};

struct func_150CC638_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    u8 unk5C;
    u8 pad5D[0x128 - 0x5D];
    struct func_150CC638_sub unk128;
};

s32 func_150CC638(struct func_150CC638_s *arg0) {
    struct func_150CC638_sub *sub;
    f32 temp;
    s32 v;

    if (arg0->unk58 & 1) {
        sub = &arg0->unk128;
        if (arg0->unk1C < 0x20) {
            v = arg0->unk1C * 8;
            if (v < arg0->unk5C) {
                arg0->unk5C = v;
            }
        }
        if (sub->unk0 < arg0->unk1C) {
            temp = sub->unk4 * D_800BE9A4;
            arg0->unk2C += temp;
            arg0->unk30 += temp;
        }
    }
    return 1;
}

extern f32 D_800A06CC;
extern f32 D_800A06D0;
extern f32 D_800A06D4;
extern f32 D_800A06D8;
void *memcpy(void *dst, const void *src, u32 size);
void func_15143794(s16 arg0, s16 arg1, f32 arg2, void *arg3);
u8 *func_15130374(void *, s32, s32, s32, s32);

struct func_150CC6B8_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    u8 pad3C[0x48 - 0x3C];
    u8 unk48[0x54 - 0x48];
    f32 unk54;
    s32 unk58;
    u8 pad5C[0x60 - 0x5C];
    u8 unk60;
    u8 unk61;
    u8 unk62;
    s8 unk63;
    u8 pad64[0x10];
};

s32 func_150CC6B8(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, u8 argE) {
    struct func_150CC6B8_s sp34;
    f32 temp;
    f32 sp2C;
    u8 *ret;
    u32 r;

    sp34.unk1D = 0x29;
    sp34.unk8 = 0xE03;
    sp34.unk0 = 0x200005;
    sp34.unk4 = 0;
    sp34.unkA = (func_150ADA20() & 0xF) + 0x14;
    sp34.unkC = 0;
    sp34.unk10 = 0;
    sp34.unk18 = 0xB0;
    sp34.unk19 = 0xA0;
    sp34.unk1A = 0x2A;
    sp34.unk14 = 0x40;
    sp34.unk15 = 0xB;
    sp34.unk16 = 0x6A;
    sp34.unk17 = 0xFF;
    sp34.unk1B = (func_150ADA20() % 156U) + 0x64;
    sp34.unk1C = 0xFF;
    sp34.unk60 = 3;
    sp34.unk61 = 3;
    temp = func_150ADA68() * D_800A06CC + 300.0f;
    sp34.unk30 = arg2;
    sp34.unk34 = arg3;
    sp34.unk38 = arg4;
    sp34.unk28 = temp;
    sp34.unk2C = temp;
    r = func_150ADA20();
    func_15143794(arg8, (r % 21U) - 0x19, ((func_150ADA68() * 200.0f) + 350.0f) * D_800A06D0, sp34.unk48);
    sp34.unk58 = 0xE05;
    sp34.unk54 = 0.0f;
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x40;
    }
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x80;
    }
    sp34.unk62 = 8;
    sp34.unk63 = -1;
    sp34.unk1E = 10;
    sp34.unk20 = 25;
    sp34.unk22 = 27;
    sp34.unk24 = D_800A06D4;
    sp2C = D_800A06D8;
    ret = func_15130374(&sp34, 1, 4, argE, 1);
    if (ret != NULL) {
        memcpy(ret + 0xA8, &sp2C, 4);
    }
    return 1;
}

struct func_150CC8D4_s {
    u8 pad0[0x58];
    f32 unk58;
    u8 pad5C[0x60 - 0x5C];
    f32 unk60;
    u8 pad64[0xA8 - 0x64];
    f32 unkA8;
};

s32 func_150CC8D4(struct func_150CC8D4_s *arg0, s32 arg1) {
    s32 i;
    f32 *p = &arg0->unkA8;

    for (i = D_800BE9E4; i != 0; i--) {
        arg0->unk58 *= *p;
        arg0->unk60 *= *p;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CCA7C.s")

struct func_150CCCB4_s {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0x38 - 0x2C];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
};

s32 func_150CCCB4(struct func_150CCCB4_s *arg0) {
    arg0->unk38 += arg0->unk44 * D_800BE9A4;
    arg0->unk3C += arg0->unk48 * D_800BE9A4 + arg0->unk5C * D_800BE9A4 * D_800BE9A4 * 0.5f;
    arg0->unk40 += arg0->unk4C * D_800BE9A4;
    arg0->unk48 += arg0->unk5C * D_800BE9A4;
    arg0->unk20 += arg0->unk50 * D_800BE9A4;
    arg0->unk24 += arg0->unk54 * D_800BE9A4;
    arg0->unk28 += arg0->unk58 * D_800BE9A4;
    return 1;
}
