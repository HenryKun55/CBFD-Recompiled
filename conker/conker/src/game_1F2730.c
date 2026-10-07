#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C56A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C577C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C61A0.s")

s32 func_151C6290(u8 *arg0, s32 arg1, s32 arg2) {
    switch (arg0[4]) {
    case 0x5A:
    case 0x74:
    case 0x7A:
        return 0;
    }
    return 1;
}
