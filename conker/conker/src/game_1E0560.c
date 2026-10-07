#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B30B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B32C8.s")

struct func_151B3A34_s {
    u8 pad0[0x44];
    u8 unk44;
};

extern void (*D_8008FB68[])(struct func_151B3A34_s *, s32, u8);

void func_151B3A34(struct func_151B3A34_s *arg0, s32 arg1, u8 arg2) {
    void (*func)(struct func_151B3A34_s *, s32, u8) = D_8008FB68[arg0->unk44];

    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B42A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B47D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B48DC.s")

s32 func_151B498C(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6, s32 *arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB, u8 *argC, u8 *argD) {
    *arg1 = 0x220005;
    *arg2 = 0x40600;
    *arg3 = 0xFF;
    *arg4 = 0xFF;
    *arg5 = 0xFF;
    *arg6 = 0xFF;
    *arg7 = 0xFF;
    *arg8 = 0xFF;
    *arg9 = 0xFF;
    *argA = 0xFF;
    *argB = 0;
    *argC = 5;
    *argD = 0x2B;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4B78.s")

void *func_151D5E30();
extern void (*D_8008FB70[])(void *);

void func_151B4C1C(u8 *arg0) {
    func_151D5E30(arg0 + 0x140, arg0);
    if (D_8008FB70[arg0[0x44]] != NULL) {
        D_8008FB70[arg0[0x44]](arg0);
    }
}

void func_151B4C6C(s32 arg0) {
    func_151B4C1C(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4C98.s")
