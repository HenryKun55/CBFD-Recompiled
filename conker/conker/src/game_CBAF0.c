#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CBAF0/func_1509E640.s")

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
