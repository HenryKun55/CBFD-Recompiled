#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_151669A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_15166B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_15166D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_15166F6C.s")

extern Mtx D_80089470;

Gfx *func_15166FD8(Gfx *gdl, s32 arg1, s32 arg2) {
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gdl;
}
