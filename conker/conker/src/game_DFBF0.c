#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B2740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B2EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B3188.s")

struct func_150B36AC_s {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x3C - 0x18];
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
    f32 unk170;
};

s32 func_150B36AC(struct func_150B36AC_s *arg0, void *arg1, void *arg2, void *arg3, f32 arg4) {
    arg0->unk3C = arg0->unk10 + arg4;
    if (arg0->unk170 < arg0->unk48) {
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

struct func_150B378C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x98 - 0x1E];
    u8 *unk98;
};

s32 func_150B378C(struct func_150B378C_s *arg0) {
    u8 *p;
    s32 v;
    p = arg0->unk98;
    v = arg0->unk1C * 16;
    if (v >= 256) {
        v = 255;
    }
    if (v < p[0x1B]) {
        p[0x1B] = v;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B37C8.s")
