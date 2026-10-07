#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12B7D0/func_150FE320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B7D0/func_150FE49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B7D0/func_150FE604.s")

extern u8 D_80088B94;
extern s32 D_800A1FC8;
void *func_151D3E04(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 arg4);

void func_150FE794(void *arg0, void *arg1, s32 arg2) {
    func_151D3E04(arg0, arg2, &D_800A1FC8, D_80088B94, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B7D0/func_150FE7D4.s")
