#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6C960/func_1503F4B0.s")

void func_1505E0C4(s32, s32, void *, s32, s32, s32, s32, f32, f32, f32, f32, s32);

void func_1503F5B8(u8 *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    func_1505E0C4(0, 0, arg0, 0, arg1, arg2, arg0[0x3F5], arg3, arg4, 0.0f, 0.0f, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6C960/func_1503F62C.s")

void func_1503F7B8(u8 *arg0) {
    func_100043B4(*(void **)(arg0 + 0x3E8), 4);
    func_100043B4(*(void **)(arg0 + 0x3EC), 4);
    func_10004074(arg0);
}
