#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800D3840;
void func_151F2D6C(s32, s32);
void func_151F2BA8();

s32 func_1509E640(s32 arg0, s32 arg1, s32 *arg2) {
    s32 v;
    switch (arg1) {
    case 0:
        v = 0x7FFF;
        if (D_800D3840 >= 3) {
            v = arg2[2];
        }
        func_1001263C(arg0, v, 0x40);
        return 1;
    case 1:
    M:
        if (D_800D3840 != 4) goto L;
        func_151F2D6C(arg2[2], arg2[3]);
        return 1;
    L:
        func_151F2D6C(arg2[2], 0);
        return 1;
    case 2:
        func_151F2BA8();
        return 1;
    default:
        break;
    }
    return 0;
}

s32 func_151F2CDC();

s32 func_1509E6F0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 3) {
        return func_151F2CDC() == 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBAF0/func_1509E730.s")

u8 func_1000E8F0(s32 arg0);

s32 func_1509E8A0(s32 arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
    case 7:
        return func_1000E0F8(arg0);
    case 8:
        return func_1000E8F0(arg0);
    }
    return 0;
}
