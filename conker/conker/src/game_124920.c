#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F7470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F78B4.s")

extern f32 D_800A1BD8;

struct func_150F7E20_inner {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

struct func_150F7E20_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x5C - 0x34];
    u8 unk5C;
    u8 pad5D[0x110 - 0x5D];
    struct func_150F7E20_inner unk110;
};

s32 func_150F7E20(struct func_150F7E20_s *arg0) {
    struct func_150F7E20_inner *temp_v0;
    f32 temp_f2;

    temp_v0 = &arg0->unk110;
    arg0->unk5C = (u32)(temp_v0->unk18 * D_800A1BD8);
    temp_f2 = (sinf(temp_v0->unk1C) * temp_v0->unk28) + temp_v0->unk24;
    arg0->unk30 = temp_f2;
    arg0->unk2C = temp_f2;
    temp_v0->unk1C = func_15144B68(temp_v0->unk1C + (temp_v0->unk20 * D_800BE9A4));
    temp_v0->unk18 -= D_800BE9A4;
    if (temp_v0->unk18 < 0.0f) {
        return 0;
    }
    return 1;
}

void func_15140410();

void func_150F7F58(u8 *arg0, s16 arg1) {
    func_15140410(arg0, arg0 + 0x110, arg0 + 0x11C, arg1);
}

s32 func_151541B8(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, s32 arg6);
void func_151D3F14(void *, u8, s32);

void func_150F7F8C(void *arg0, u8 arg1, s32 arg2) {
    func_151541B8(arg0, func_150ADA68() * 3.0f + 9.0f, 0.51190501f, func_150ADA68() * 70.0f + 70.0f, 0.0f, arg1, arg2);
    func_151D3F14(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F802C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F81BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F85A0.s")

void func_150F884C(s32 arg0, s32 arg1) {
    s32 sp18[2];

    sp18[0] = arg1;
    func_151494E0((s32)sp18, 0x3F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F887C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F892C.s")

extern u8 D_800A1C40[][2];

struct func_150F9720_s {
    s32 unk0;
    u8 unk4;
};

void func_150F9720(u8 arg0) {
    struct func_150F9720_s sp20;

    sp20.unk0 = 0;
    sp20.unk4 = D_800A1C40[arg0][0];
    func_151494E0((s32)&sp20, 0x42);
    sp20.unk4 = D_800A1C40[arg0][1];
    func_151494E0((s32)&sp20, 0x42);
}

void func_150F9788(s32 arg0) {
}

void func_150F9794(s32 arg0) {
    func_150F9788(arg0);
    func_1514933C(arg0);
}

void func_150F97C0(s32 arg0) {
    func_150F9788(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F97EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F9950.s")
