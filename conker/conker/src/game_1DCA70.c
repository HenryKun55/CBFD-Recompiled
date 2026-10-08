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

struct func_151AFC88_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14[4];
    u8 unk18[5];
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
    u8 pad5C[4];
    u8 unk60;
    u8 unk61;
    u8 unk62;
    s8 unk63;
    u8 pad64[0xC];
};

extern f32 D_800AA110;
extern f32 D_800AA114;
extern f32 D_800AA118;
extern f32 D_800AA11C;
void func_15143794(s16 arg0, s16 arg1, f32 arg2, void *arg3);
void *func_15130374(void *, s32, s32, u8, s32);

s32 func_151AFC88(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, u8 argE) {
    f32 temp_f2;
    struct func_151AFC88_s sp34;
    void *temp_v0;
    f32 sp2C;
    f32 temp_f0;
    u32 sp24;

    sp34.unk1D = 0x29;
    sp34.unk8 = 0xE03;
    sp34.unk0 = 0x200005;
    sp34.unk4 = 0;
    sp34.unkA = (func_150ADA20() & 0xF) + 0x19;
    sp34.unkC = 0;
    sp34.unk10 = 0;
    sp34.unk18[0] = 0xB0;
    sp34.unk18[1] = 0xA0;
    sp34.unk18[2] = 0x2A;
    sp34.unk14[0] = 0x40;
    sp34.unk14[1] = 0xB;
    sp34.unk14[2] = 0x6A;
    sp34.unk14[3] = 0xFF;
    sp34.unk18[3] = (func_150ADA20() % 156U) + 0x64;
    sp34.unk18[4] = 0xFF;
    sp34.unk60 = 3;
    sp34.unk61 = 3;
    temp_f2 = (func_150ADA68() * 202.0f) + 101.0f;
    sp34.unk28 = temp_f2;
    sp34.unk2C = temp_f2;
    sp34.unk30 = arg2;
    sp34.unk34 = arg3;
    sp34.unk38 = arg4;
    sp24 = func_150ADA20();
    temp_f0 = func_150ADA68();
    func_15143794(arg8, (sp24 % 21U) - 0x14, ((temp_f0 * D_800AA110) + 500.0f) * D_800AA114, &sp34.unk48);
    sp34.unk58 = 0xE05;
    sp34.unk54 = 0.0f;
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x40;
    }
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x80;
    }
    sp34.unk62 = 6;
    sp34.unk63 = -1;
    sp34.unk1E = 0xF;
    sp34.unk20 = 0x11;
    sp34.unk22 = 0x19;
    sp34.unk24 = D_800AA118;
    sp2C = D_800AA11C;
    temp_v0 = func_15130374(&sp34, 1, 4, argE, 1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0xA8, &sp2C, 4);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFEA4.s")
