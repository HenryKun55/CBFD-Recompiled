#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12BD10/func_150FE860.s")

extern u8 D_80088BA0;
extern u8 D_800A2000[];
void *func_15145EA4();

void func_150FEBC8(s32 arg0, s32 arg1, s32 arg2) {
    void *sp20[2];
    s32 sp1C;
    s32 temp;

    temp = (*(s32 *)((char *)(arg0) + 0x1D4)) + (D_80088BA0 << 6);
    sp20[0] = &D_800A2000;
    sp1C = arg2;
    func_15145EA4(sp20, &sp1C, temp, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12BD10/func_150FEC28.s")
