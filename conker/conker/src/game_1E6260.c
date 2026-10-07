#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6260/func_151B8DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6260/func_151B9214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6260/func_151B9310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6260/func_151B9408.s")

extern f32 D_800AA56C;
extern f32 D_800AA570;

void func_151B9660(void *arg0) {
    *(f32 *)((char *)arg0 + 0x188) = 5.0f;
    *(f32 *)((char *)arg0 + 0x18C) = D_800AA56C;
    *(f32 *)((char *)arg0 + 0x190) = D_800AA570;
}
