#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F7470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F78B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124920/func_150F7E20.s")

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
