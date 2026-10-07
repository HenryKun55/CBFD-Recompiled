#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FDDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FDF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FE0B8.s")

extern u8 D_80088B80;
extern s32 D_800A1F70;
void func_151D3E04(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 arg4);

void func_150FE248(void *arg0, s32 arg1, s32 arg2) {
    func_151D3E04(arg0, arg2, &D_800A1F70, D_80088B80, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FE288.s")
