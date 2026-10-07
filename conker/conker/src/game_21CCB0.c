#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151EF800(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale)
{
    int i, j;

    func_151EFE00(mf);

    mf[0][0] = 2 / (r - l);
    mf[1][1] = 2 / (t - b);
    mf[2][2] = -2 / (f - n);
    mf[3][0] = -(r + l) / (r - l);
    mf[3][1] = -(t + b) / (t - b);
    mf[3][2] = -(f + n) / (f - n);
    mf[3][3] = 1;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            mf[i][j] *= scale;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_21CCB0/func_151EF954.s")
