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

void func_150FE7D4(u8 *arg0) {
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    if (*(s32 *)(arg0 + 0x318) != 0) {
        local.f0 = 1;
        local.f2 = (u32) func_150ADA20() % 13 + 20;
        local.f5 = 1 << *(u8 *)(*(u8 **)(arg0 + 0x318) + 0x23D);
        func_150ADA20();
        local.f4 = 8;
        local.f6 = -1;
        func_151D8868(&local, 0, 0xFF, 1);
    }
}
