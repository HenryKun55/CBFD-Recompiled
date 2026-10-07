#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C62D0.s")

void func_151C6974(s32 arg0, s32 arg1, s32 arg2) {
    func_151C69CC(arg0, arg2, 0, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C69A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C69CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C6A28.s")

s32 func_15102B38(s32, s32, s32 *, s32 *, f32 *, s32, s32, f32, s32, s32, s32, s32, s32, s32); /* extern */
extern f32 D_800AAC10;
extern f32 D_800AAC14;
extern f32 D_800AAC18;
extern f32 D_800AAC1C;
extern f32 D_800AAC20;
extern u32 D_800AAB00[];
extern s32 D_800AAB08[][3];
extern s32 D_800AAB20[][3];

void func_151C6D70(s32 arg0, u8 arg1, s32 arg2, s16 arg3, u8 arg4, s32 arg5) {
    f32 sp50[2];
    f32 sp4C;
    s32 sp44[2];

    sp50[1] = (func_150ADA68() * D_800AAC10) + D_800AAC14;
    sp50[0] = (func_150ADA68() * D_800AAC18) + D_800AAC1C;
    sp44[0] = func_150ADA20();
    sp44[1] = func_150ADA20();
    sp4C = func_150ADA68();
    func_15102B38(arg0, (D_800AAB00[arg1] >> 6) & 0xFF, D_800AAB08[arg1], D_800AAB20[arg1], sp50, (sp44[0] & 3) + 6, 0xFF, (sp4C * 270.0f) + D_800AAC20, arg2, 0xFF, 0, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C6EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C7038.s")
