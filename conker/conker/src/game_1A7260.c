#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A1EC.s")

s32 func_1517A394(s32 arg0) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A84C.s")

extern s16 D_800DD450;
s32 func_1517A394(s32);

s32 func_1517A958(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800DD450 = -1;
    if ((arg1 == 12) || (arg1 == 89)) {
        arg0 = func_1517A394(arg0);
    }
    return arg0;
}

extern s32 D_80090614;
void *func_15094F70();
void *func_1517A9A8(void *arg0, s32 arg1) {
    s32 sp34[5];
    if (arg1 == D_800DD1B0) {
        goto end;
    }
    arg0 = func_15094F70(arg0, &D_80090614, arg1 << 8, sp34, 0, 0, 0, 2, 3);
    D_800DD1B0 = arg1;
end:
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517AA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517AB7C.s")
