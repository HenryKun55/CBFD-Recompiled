#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_21D1B0/guMtxF2L2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_21D1B0/func_151EFE00.s")

void func_151EFE88(Mtx *m) {
    f32 mf[4][4];
    func_151EFE00(mf);
    guMtxF2L2(mf, m);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_21D1B0/guMtxL2F.s")
