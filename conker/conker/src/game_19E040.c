#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15170B90.s")

void func_15170B90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

void func_15170EC4(s32 arg0, u8 arg1, s32 arg2) {
    switch (D_800BE9F0) {
    case 2:
        func_15170B90(arg0, 1, 1, 1, arg1, arg2);
        break;
    case 16:
        func_15170B90(arg0, 0xA9, 8, 0, arg1, arg2);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15170F4C.s")

void func_151711C4(u8 *arg0) {
    if (arg0[4] == 0x33) {
        func_150C3D5C();
    }
    func_15060F28(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171600.s")

void func_151700D8(f32 *arg0, f32 arg1, f32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, s32 arg9);

void func_151717FC(s16 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, f32 arg10, u8 arg11, s32 arg12) {
    f32 v[4][3];
    f32 x;
    f32 y;
    f32 z;

    x = arg0[8] + arg3;
    y = arg0[9] + arg4;
    z = arg0[10] + arg5;
    v[0][0] = arg1 + x;
    v[0][1] = y;
    v[0][2] = arg2 + z;
    v[1][0] = x - arg1;
    v[1][1] = y;
    v[1][2] = arg2 + z;
    v[2][0] = x - arg1;
    v[2][1] = y;
    v[2][2] = z - arg2;
    v[3][0] = arg1 + x;
    v[3][1] = y;
    v[3][2] = z - arg2;
    func_151700D8(v[0], x, z, arg7, arg10, arg6, arg8, arg9, arg11, arg12);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_151718F0.s")

void func_150AEEB0(u8 *arg0);
void func_150BD740(u8 *arg0, u8 arg1, s32 arg2);
void func_150CDBB0(u8 *arg0, u8 arg1, s32 arg2);

void func_15171BF4(u8 *arg0, u8 arg1) {
    switch (arg0[4]) {
    case 0x13:
    case 0x23:
        func_150AEEB0(arg0);
        func_10010154(0x69, arg0, 0x7D00, 0xC8, 2000);
        break;
    case 0x1E:
        func_150BD740(arg0, arg1, 1);
        break;
    case 0x54:
        func_150CDBB0(arg0, arg1, 1);
        break;
    }
}
