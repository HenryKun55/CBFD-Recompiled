#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_15046C80(f32 *, s32, f32, void *);
extern s32 D_800AA0F0;
extern s32 D_800AA0FC;

s32 func_151AF5C0(f32 *arg0, void *arg1, void *arg2, u8 arg3) {
    f32 sp2C[3];
    void *var_a0;
    s32 var_a2;

    if ((arg3 != 1) && (arg3 != 2)) {
        return 0;
    }
    if (arg3 == 1) {
        var_a0 = &D_800AA0FC;
    } else {
        var_a0 = &D_800AA0F0;
    }
    if (arg3 == 1) {
        var_a2 = *(s32 *)((char *)arg1 + 0x1D4) + 0x800;
    } else {
        var_a2 = *(s32 *)((char *)arg1 + 0x1D4) + 0x640;
    }
    func_15143134(var_a0, arg0, var_a2);
    if (arg2 == NULL) {
        return 1;
    }
    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + 100.0f;
    sp2C[2] = arg0[2];
    func_1504715C(arg2, arg1);
    func_15046C80(sp2C, 0, arg0[1] - 500.0f, arg2);
}

s32 func_151AF6C0(s32 arg0, s32 arg1) {
    return 12;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF6D4.s")

struct func_151AFBD4_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_151AFBD4(struct func_151AFBD4_s *arg0) {
    if (arg0->unk1C < 32) {
        if ((arg0->unk1C * 8) < arg0->unk28) {
            arg0->unk28 = arg0->unk1C * 8;
        }
    }
    return 1;
}

struct func_151AFC08_sub {
    s16 unk0;
    f32 unk4;
};

struct func_151AFC08_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    volatile u8 unk5C;
    u8 pad5D[0x128 - 0x5D];
    struct func_151AFC08_sub unk128;
};

s32 func_151AFC08(struct func_151AFC08_s *arg0) {
    struct func_151AFC08_sub *sub = &arg0->unk128;
    f32 temp;
    if (arg0->unk58 & 1) {
        if (arg0->unk1C < 32) {
            if ((arg0->unk1C * 8) < arg0->unk5C) {
                arg0->unk5C = arg0->unk1C * 8;
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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFEA4.s")
