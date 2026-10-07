#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15187EC0_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 pad9[7];
    s32 unk10;
    f32 unk14;
    u8 unk18[0xC];
};
extern u8 D_800DF700[];
extern s32 D_800DF7B4;

#define E (*(struct func_15187EC0_s *)(D_800DF700 + D_800DF7B4 * 0x24))
s32 func_15187EC0(s32 arg0, f32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    if (D_800DF7B4 < 5) {
        E.unk14 = arg1;
        E.unk10 = arg0;
        E.unk0 = E.unk6 = arg2;
        E.unk1 = E.unk7 = arg3;
        E.unk2 = E.unk8 = arg4;
        E.unk3 = arg5;
        E.unk4 = arg6;
        E.unk5 = arg7;
        bzero(E.unk18, 0xC);
        D_800DF7B4++;
        return D_800DF7B4 - 1;
    }
    return -1;
}
#undef E

extern u8 D_800DF700[];
extern s32 D_800DF7B4;

void func_15187F90(void) {
    bzero(D_800DF700, 0xB4);
    D_800DF7B4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5370/func_15187FC0.s")

struct func_15188010_s {
    f32 unk0;
    u8 pad4[0x20];
};
extern struct func_15188010_s D_800DF70C[];
extern s32 D_800DF7B4;

void func_15188010(s32 arg0, f32 *arg1) {
    if ((arg0 < D_800DF7B4) && (arg0 >= 0)) {
        *arg1 = D_800DF70C[arg0].unk0;
    }
}

void func_1518804C(s32 arg0, f32 arg1) {
    if ((arg0 < D_800DF7B4) && (arg0 >= 0)) {
        if (arg1 > 1.0f) {
            arg1 = 1.0f;
        } else if (arg1 < 0.0f) {
            arg1 = 0.0f;
        }
        D_800DF70C[arg0].unk0 = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5370/func_151880C0.s")
