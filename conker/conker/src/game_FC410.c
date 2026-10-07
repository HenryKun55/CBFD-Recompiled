#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FC410/func_150CEF60.s")

extern f32 D_800A0838;

f32 func_150CF040(s32 arg0, s32 arg1) {
    arg0 += 1;
    arg1 -= 44;
    return func_150484A0(arg0, arg1) * D_800A0838;
}

void func_150CF080(s32 arg0) {
    *(s32 *)(arg0 + 0x84) |= 0x4000;
}
