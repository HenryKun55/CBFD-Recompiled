#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void guMtxF2L2(float mf[4][4], Mtx *m) {
    int i, j;
    int e1, e2;
    int *ai, *af;

    ai = (int *) &m->m[0][0];
    af = (int *) &m->m[2][0];

    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++) {
            e1 = (long)(mf[i][j * 2] * (float)0x00010000);
            e2 = (long)(mf[i][j * 2 + 1] * (float)0x00010000);
            *(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
            *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
        }
}

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
