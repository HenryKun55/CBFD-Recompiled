#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DF8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DF920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFCA8.s")

extern f32 D_800A0FB0;

void func_150DFDA4(void *arg0) {
    char *temp_v0;

    temp_v0 = *(char **)((char *)arg0 + 0x1D4) + 0x40;
    *(f32 *)(temp_v0 + 0x30) = *(f32 *)((char *)arg0 + 0x14);
    *(f32 *)(temp_v0 + 0x34) = D_800A0FB0;
    *(f32 *)(temp_v0 + 0x38) = *(f32 *)((char *)arg0 + 0x1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFDD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFEFC.s")

void func_150E02C0(s32 arg0, s32 arg1, u8 arg2) {
    func_15149514(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_150E0300(void) {
    if (D_80088980 == 0) {
        func_1515F170(6, 0);
        func_1513BAE8();
        D_80088980 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E0348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E03F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E05F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E06D8.s")
