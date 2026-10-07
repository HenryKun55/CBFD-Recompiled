#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0E60/func_151739B0.s")

void func_151739B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_15173C60(s32 arg0, s32 arg1) {
    func_151739B0(0, 0, arg0, arg1, 0);
}

struct131 *func_151149AC(u8 arg0);

void func_15173C90(s32 arg0, s32 arg1, s32 arg2) {
    struct131 *temp_v0;
    s32 a;

    temp_v0 = func_151149AC(arg2);
    if (temp_v0 != NULL) {
        a = *(u16 *)((u8 *)temp_v0 + 0x54) & ~0x8000;
        func_151739B0(a, 1, arg0, arg1, temp_v0 - D_800DBEF4);
    }
}
