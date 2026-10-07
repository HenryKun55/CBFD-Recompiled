#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146A98.s")

void func_15146BB8(s32 arg0, s32 arg1, s32 arg2) {
    func_15146BF8(arg0, arg1, arg2, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146E84.s")

void func_15146890(f32 *, s32, s32, u8);
void func_1514C678(f32, f32, f32, f32, s32, s32, s32, s32, s32, f32, s32, s32);

void func_15147040(s32 arg0, s32 arg1, s32 arg2) {
    f32 pos[3];
    s16 r;

    if (*(s32 *)(arg0 + 0x1D4) != 0) {
        func_15146890(pos, arg0, 0, arg1);
        r = (u32) func_150ADA20() % 11 + 5;
        func_1514C678(pos[0], pos[1], pos[2], func_150ADA68() * 11.0f, 0, 255, r, 22, 0, 0.0f, 0, 255);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_151470FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15147318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15147478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_151475D8.s")
