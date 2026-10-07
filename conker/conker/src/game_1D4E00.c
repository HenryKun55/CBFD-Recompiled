#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8340.s")

void *func_151D5E30();

void func_151A8560(void *arg0) {
    func_151D5E30((char *)(arg0) + 0x6C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A85D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A87F8.s")

extern void (*D_8008F964[])(u8 *, s32, u8);

void func_151A8A20(u8 *arg0, s32 arg1, u8 arg2) {
    s32 idx = arg0[0x5C];
    void (*fn)(u8 *, s32, u8);

    if (idx >= 3) {
        idx = 0;
    }
    fn = D_8008F964[idx];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8CEC.s")

void func_151432BC(void *, f32 *, f32 *, f32 *, f32 *);

void func_151A8F1C(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    func_151432BC(*(void **)((char *)arg0 + 0x2C), arg1, arg1 + 2, arg2, arg3);
    arg1[1] = *arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8F6C.s")

void func_151A931C(u8 *arg0, s32 arg1, u8 arg2);

void func_151A9024(u8 *arg0, s32 arg1, u8 arg2) {
    if (arg0[0x4C] == 1) {
        func_151A931C(arg0, arg1, arg2);
    }
}

extern void (*D_8008F984[])(void *, s32);

s32 func_151A9060(u8 *arg0) {
    s32 idx;

    arg0[0x16] |= 4;
    idx = *(s32 *)(arg0 + 0x18);
    if (idx < 0 || idx >= 8) {
        return 1;
    }
    if (D_8008F984[idx] != NULL) {
        D_8008F984[idx](arg0, idx);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A90C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A91AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A931C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9834.s")
