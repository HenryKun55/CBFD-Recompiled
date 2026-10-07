#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B81D0/func_1518AD20.s")

s32 func_1518B1AC(void *arg0) {
    if (*(f32 *)((char *)arg0 + 0x3C) < *(f32 *)((char *)arg0 + 0x170)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B81D0/func_1518B1D8.s")

void func_1518B2A8(void *arg0, f32 arg1, f32 arg2, s32 arg3, u16 arg4, u8 arg5, u8 arg6);

void func_1518B264(void *arg0, f32 arg1, f32 arg2, s32 arg3, u8 arg4) {
    func_1518B2A8(arg0, arg1, arg2, arg3, 4, 0xFF, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B81D0/func_1518B2A8.s")
