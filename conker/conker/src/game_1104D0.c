#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3208.s")

void *func_150E3020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, s32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12, s16 arg13);

s32 func_150E32D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    u8 *temp_v0;

    temp_v0 = func_150E3020(arg0, arg1, arg2, 0, 0, 0, arg4, arg5, arg3, 0.0f, 0.0f, 0.0f, 0, -0x63);
    if (temp_v0 != NULL) {
        return temp_v0[0x48] + 1;
    }
    return 0;
}

void *func_150E3020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, s32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12, s16 arg13);

void func_150E3340(f32 *arg0, s32 *arg1, s32 arg2, s16 arg3) {
    s32 a = arg1[0];
    s32 b = arg1[1];
    s32 c = arg1[2];
    func_150E3020(a, b, c, a, b, c, 0x1A, 10.0f, 0, arg0[0], arg0[1], arg0[2], arg2, arg3);
}

s32 func_150E33CC(s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    if (*arg2 == 0) {
        return 1;
    }
    func_1000E7A0(2, (u32)*arg2);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E35DC.s")

void func_150E36BC(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u8 *temp_v0;

    arg0--;
    if ((arg0 >= 0) && (arg0 < 8)) {
        temp_v0 = (u8 *)D_800D99D0[arg0];
        if ((temp_v0 != NULL) && (*temp_v0 == 0x27)) {
            *arg1 = *(f32 *)(temp_v0 + 0x10);
            *arg2 = *(f32 *)(temp_v0 + 0x14);
            *arg3 = *(f32 *)(temp_v0 + 0x18);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E4010.s")

extern f32 D_800A1054;
void func_151C3B0C(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6, u8 arg7);

void func_150E411C(void *arg0) {
    func_151C3B0C(arg0, 0.35200002789497375f, 0.7010000348091125f, 0.5660000443458557f, D_800A1054, 0xFF, 0xFF, 0xFF);
}

s32 func_150E4174(f32 *arg0) {
    arg0[11] += arg0[19] * D_800BE9A4;
    arg0[12] += arg0[21] * D_800BE9A4;
    return 1;
}
