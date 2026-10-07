#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509E900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509ED74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509EFF0.s")

s32 func_1509F248(s32 arg0, s32 *arg1) {
    if (arg0 != 0) {
        func_100111C8((*arg1 & 0xFFFF0000) >> 16);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509F284.s")

s32 func_1509F33C(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509F354.s")

s32 func_151149AC(u8 arg0);
s32 func_1000F568(s32 arg0, u8 arg1);
void func_15114D24(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4, s32 arg5);

void func_1509F47C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s32 arg5) {
    s32 temp_v0;

    temp_v0 = func_151149AC(arg3);
    func_15114D24(temp_v0, func_1000F568(arg0, (arg1 - arg0) + 1), arg2, arg4, arg5, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509F4E8.s")

s32 func_1000F568(s32 arg0, u8 arg1);

void func_1509F5A8(s32 arg0, s32 arg1, u16 arg2) {
    func_10010F30(func_1000F568(arg0, (arg1 - arg0) + 1), arg2, 0x40, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509F5F4.s")

void func_1509F660(s32 arg0, s32 arg1) {
    s32 temp_v0 = func_1505EEF4(arg0);
    if (temp_v0 != 0) {
        if (arg1 != 0) {
            func_10010A3C(temp_v0);
        } else {
            func_100109D0(temp_v0);
        }
    }
}

void func_1509F6B0(s32 sound, s32 volume, s32 pitch, s32 pan) {
    func_10010F30(sound, volume, pan, pitch, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509F6E8.s")

void func_1509F77C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 *temp_v0 = (f32 *)func_1505EEF4(arg1);
    s32 x = temp_v0[5];
    s32 y = temp_v0[6];
    s32 z = temp_v0[7];
    func_1000F91C(arg0, 0x7FFF, arg2, 0, 0, x, y, z, arg3, arg4);
}

s32 func_1509F800(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBDB0/func_1509F818.s")
