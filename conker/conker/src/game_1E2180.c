#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B4CD0.s")

void func_151B4EA4(f32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_151B4E4C(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6) {
    f32 sp24[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp24[2] = arg2;
    func_151B4EA4(sp24, arg3, arg4, arg5, arg6[0x58], arg6[0xC]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B4EA4.s")

struct func_151B4FE0_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    void *unkC;
    s8 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s8 unk2A;
    s8 unk2B;
    s8 unk2C;
    s8 unk2D;
    s8 pad2E[6];
};

extern f32 D_800AA3E0;
extern f32 D_800AA3E4;
s32 func_1513418C();

s32 func_151B4FE0(u8 *arg0, u8 arg1, s32 arg2) {
    struct func_151B4FE0_s sp1C;

    if (arg0 == NULL) {
        return 0;
    }
    sp1C.unk0 = 0;
    sp1C.unk4 = 0;
    sp1C.unk8 = arg0[0x3B];
    sp1C.unk10 = 2;
    sp1C.unkC = arg0;
    sp1C.unk14 = 0.0f;
    sp1C.unk18 = -27.0f;
    sp1C.unk1C = 16.0f;
    sp1C.unk20 = D_800AA3E0;
    sp1C.unk24 = D_800AA3E4;
    sp1C.unk2A = 2;
    sp1C.unk28 = 300;
    sp1C.unk2B = 9;
    sp1C.unk2C = -1;
    sp1C.unk2D = 8;
    return func_1513418C(&sp1C, 0, arg1, arg2);
}

void func_151B50F4(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4);

struct func_151B50A4_s {
    u8 pad0[0xC];
    u8 unkC;
};

void func_151B50A4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, struct func_151B50A4_s *arg6) {
    f32 sp24[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp24[2] = arg2;
    func_151B50F4(sp24, arg3, arg4, arg5, arg6->unkC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B50F4.s")
