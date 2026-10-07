#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 func_151928B0(s32 arg0, s32 *arg1);
extern s32 func_1510F8CC(s32 arg0);
extern void (**D_8008F860[])(s32);

void func_15192800(s32 arg0, s32 arg1) {
    s32 sp2C;
    s32 pad[2];
    s32 idx;
    void (*fn)(s32);

    if (arg0 != 0) {
        if (func_151928B0(arg0, &sp2C) != 0) {
            switch (func_1510F8CC(*(s32 *)(arg0 + 0x184))) {
                default:
                    idx = 1;
                    break;
                case 5:
                    if (D_800BE9F0 == 20) {
                        idx = 2;
                    } else {
                        idx = 1;
                    }
                    break;
                case 6:
                    idx = 3;
                    break;
            }
            fn = D_8008F860[sp2C][idx];
            if (fn != NULL) {
                fn(arg0);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFCB0/func_151928B0.s")
