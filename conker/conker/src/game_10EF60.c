#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E1AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E1D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E28DC.s")

s32 func_150E2DA4(s32 arg0, s32 arg1) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2DB4.s")

void func_150E1AB0(s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);

void func_150E2EA4(void *arg0, u8 arg1, s16 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, s16 arg10, s16 arg11, u16 arg12, f32 arg13, f32 arg14, u8 arg15, f32 arg16) {
    func_150E1AB0(0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, arg16, 0.0f, arg13, arg14, arg12, 0x27, 1, arg10, arg11, arg0, arg1, arg2, arg3, 0, arg15, arg4, arg5, arg6, arg7, arg8, arg9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2F90.s")

struct func_150E2FC0_s {
    u8 pad0[0xDA];
    u8 unkDA;
    u8 padDB;
    s32 unkDC;
};
struct func_150E2FC0_t {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_150E2FC0(struct func_150E2FC0_s *arg0, struct func_150E2FC0_t *arg1, u8 arg2) {
    if (arg2 == 0x2D) {
        if (arg0->unkDC == arg1->unk0) {
            arg0->unkDC = arg1->unk4;
            arg0->unkDA = arg1->unk9;
        } else if (arg0->unkDC == arg1->unk4) {
            arg0->unkDC = arg1->unk0;
            arg0->unkDA = arg1->unk8;
        }
    }
}
