#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15191BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15191D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_1519203C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15192308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15192358.s")

u8 func_15192308(s32 arg0, s32 arg1);
u8 func_15192358(s32 arg0, s32 arg1);

u8 func_1519257C(s32 arg0, s32 arg1) {
    u8 ret;

    ret = func_15192308(arg0, arg1);
    if (ret) {
        ret = func_15192358(arg0, arg1);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_151925C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_1519277C.s")
