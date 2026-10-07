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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B4FE0.s")

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
