#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510D970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510DA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510E120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510E388.s")

extern s32 D_80089470;

Gfx *func_1510E634(Gfx *gfx, s32 arg1, s32 arg2) {
    gSPMatrix(gfx++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gfx;
}
