#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_21D1B0/guMtxF2L2.s")

void func_151EFE00(float mf[4][4]) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) {
                mf[i][j] = 1.0;
            } else {
                mf[i][j] = 0.0;
            }
        }
    }
}

void func_151EFE88(Mtx *m) {
    f32 mf[4][4];
    func_151EFE00(mf);
    guMtxF2L2(mf, m);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_21D1B0/guMtxL2F.s")
