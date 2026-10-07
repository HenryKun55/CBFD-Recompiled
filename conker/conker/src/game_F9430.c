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

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CC6B8.s")

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
