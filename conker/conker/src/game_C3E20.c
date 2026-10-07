#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800D2DC0[];

void func_15096970(void) {
    bzero(D_800D2DC0, 0x6C);
    D_800D2DB4 = 0;
}

struct func_150969A0_s {
    u8 unk0;
    u8 pad[0x23];
};

s32 func_150969A0(s32 arg0) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        if (((struct func_150969A0_s *)D_800D2DC0)[i].unk0 != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15096A68.s")

s32 func_15096A68(s32 arg0);

void func_15096D08(void) {
    s32 i;

    if (D_800C35EA != 1) {
        for (i = 0; i != 3; i++) {
            if (D_800D2DC0[i * 0x24] != 0) {
                if (func_15096A68(i) != 0) {
                    return;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15096D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_1509759C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15097798.s")
