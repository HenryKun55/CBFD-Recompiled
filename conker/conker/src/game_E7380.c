#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E7380/func_150B9ED0.s")

struct func_150BA35C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0xA];
    u8 unk28;
};

s32 func_150BA35C(struct func_150BA35C_s *arg0) {
    if (arg0->unk1C < 0x40) {
        arg0->unk28 = arg0->unk1C * 4;
    }
    return 1;
}

extern f32 D_8009FE2C;

struct func_150BA37C_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    u8 pad48[0x110 - 0x48];
    f32 unk110;
    f32 unk114;
    f32 unk118;
    f32 unk11C;
    f32 unk120;
};

s32 func_150BA37C(struct func_150BA37C_s *arg0) {
    arg0->unk114 += D_8009FE2C * D_800BE9A4;
    arg0->unk34 += arg0->unk110 * D_800BE9A4;
    arg0->unk38 += arg0->unk114 * D_800BE9A4;
    arg0->unk3C += arg0->unk118 * D_800BE9A4;
    arg0->unk40 += arg0->unk11C * D_800BE9A4;
    arg0->unk44 += arg0->unk120 * D_800BE9A4;
    return 1;
}

struct func_150BA424_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x38 - 0x1E];
    f32 unk38;
    u8 pad3C[0x5C - 0x3C];
    u8 unk5C;
    u8 pad5D[0x124 - 0x5D];
    f32 unk124;
};

s32 func_150BA424(struct func_150BA424_s *arg0) {
    f32 d;
    s32 b;
    s32 a;

    d = arg0->unk38 - arg0->unk124;
    if (d < 0.0f) {
        return 0;
    }
    b = arg0->unk1C * 16;
    if (b >= 0x100) {
        b = 0xFF;
    }
    a = (s32)d * 4;
    if (a >= 0x100) {
        a = 0xFF;
    }
    if (a < b) {
        arg0->unk5C = a;
    } else {
        arg0->unk5C = b;
    }
    if (arg0->unk5C < 0) {
        return 0;
    }
    return 1;
}
