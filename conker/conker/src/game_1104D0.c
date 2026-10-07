#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E32D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3340.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E36BC.s")

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
