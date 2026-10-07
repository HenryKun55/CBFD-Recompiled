#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C4D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C4E9C.s")

extern struct102 *D_800D98D0[4];

void func_150C522C(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800D98D0[i] != NULL) {
            func_1516972C(D_800D98D0[i]);
        }
        D_800D98D0[i] = NULL;
    }
}

extern u8 D_800C35E8;
s32 func_150C5280(void) {
    if (D_800C35EA == 1) {
        if ((D_800C35E8 == 0xB) || (D_800C35E8 == 0xC) || (D_800C35E8 == 0xD)) {
            return 1;
        }
    }
    return 0;
}

extern s32 (*D_8008ADA8)(s32);
s32 func_150C5280(void);

s32 func_150C52CC(s32 arg0) {
    if (func_150C5280()) {
        return 0;
    }
    return D_8008ADA8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C5310.s")
