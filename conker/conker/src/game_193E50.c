#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_151669A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_15166B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_15166D68.s")

void *func_15094F70();
extern s32 D_8009054C;
extern s32 D_800DD220;
extern s32 D_800DD224;
extern void *D_800DD228;
extern s32 D_800DD230;

void func_15166F6C(void *arg0, void *arg1, void *arg2, void *arg3) {
    func_15094F70(arg0, D_800DD228 = &D_8009054C, D_800DD220, &D_800DD230, 0, 0, 0, D_800DD224, 3);
}

extern Mtx D_80089470;

Gfx *func_15166FD8(Gfx *gdl, s32 arg1, s32 arg2) {
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gdl;
}
