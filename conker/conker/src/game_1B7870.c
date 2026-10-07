#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7870/func_1518A3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7870/func_1518A5F4.s")

struct func_1518A914_s {
    u8 pad0[0x48];
    f32 pos[3];
    u8 pad54[0x100 - 0x54];
    f32 rot[3];
    f32 scale;
};

s32 func_1518A914(Mtx *arg0, struct func_1518A914_s *arg1) {
    f32 *r;
    f32 mf[4][4];

    r = arg1->rot;
    func_150A8050(mf, r[0], r[1], r[2]);
    mf[3][0] = arg1->pos[0];
    mf[3][1] = arg1->pos[1];
    mf[3][2] = arg1->pos[2];
    mf[0][0] *= r[3];
    mf[0][1] *= r[3];
    mf[0][2] *= r[3];
    mf[1][0] *= r[3];
    mf[1][1] *= r[3];
    mf[1][2] *= r[3];
    mf[2][0] *= r[3];
    mf[2][1] *= r[3];
    mf[2][2] *= r[3];
    guMtxF2L(mf, arg0);
    return 1;
}
