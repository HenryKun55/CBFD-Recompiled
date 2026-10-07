#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15033FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150341BC.s")

s16 *func_15034340(s16 *arg0, s32 arg1) {
    struct127 *obj = &gObjects[arg1];
    if (obj->unk1D1 != 0) {
        arg0[0] = 6;
        arg0[1] = obj->unk1D1 * 200;
        arg0 += 2;
    }
    return arg0;
}

s16 *func_150343B0(s16 *arg0, s32 arg1) {
    struct127 *obj = &gObjects[arg1];

    if (obj->unk1D1 != 0) {
        arg0[0] = 6;
        arg0[1] = obj->unk1D1 * 200;
        arg0 += 2;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15034420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150344A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_1503453C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150345E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15034728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150347E8.s")
