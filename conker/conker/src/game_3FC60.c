#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_3FC60/func_150127B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_3FC60/func_15012C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_3FC60/func_15012ED8.s")

extern u8 D_800DF7D0;
extern u8 D_800DF7D1;
extern u8 D_800DF7D2;
extern u8 D_800DF7D3[];

void func_15012F90(void) {
    s32 i;
    D_800DF7D0 = 0;
    D_800DF7D1 = 0;
    for (i = 0, D_800DF7D2 = 0; i < 0x1E0; i++) {
        D_800DF7D3[i] = 0;
    }
}
