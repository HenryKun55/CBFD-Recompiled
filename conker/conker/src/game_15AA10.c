#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_15AA10/func_1512D560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15AA10/func_1512D604.s")

void func_1512D66C(u8 *arg0) {
    *(s32 *)((u8 *)D_800DC2B0 + arg0[0x23D] * 0xB0 + 0xA8) = 0;
    *(s32 *)((u8 *)D_800DC2B0 + arg0[0x23D] * 0xB0 + 0xAC) = 0;
}

struct func_1512D6B0_s {
    u8 pad0[0xA8];
    s32 unkA8;
    s32 unkAC;
};

s32 func_1512D6B0(u8 *arg0) {
    return ((struct func_1512D6B0_s *)D_800DC2B0)[arg0[0x23D]].unkA8 == ((struct func_1512D6B0_s *)D_800DC2B0)[arg0[0x23D]].unkAC;
}
