#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6260/func_151B8DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6260/func_151B9214.s")

struct func_151B9310_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x38 - 0x20];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    u8 pad44[0x170 - 0x44];
    f32 unk170;
};

s32 func_151B9310(Mtx *arg0, struct func_151B9310_s *arg1) {
    f32 mf[4][4];
    s32 pad[2];

    func_150A8050(mf, 0.0f, 0.0f, arg1->unk170);
    mf[3][0] = arg1->unk38;
    mf[3][1] = arg1->unk3C;
    mf[3][2] = arg1->unk40;
    mf[0][0] *= arg1->unk18;
    mf[0][1] *= arg1->unk18;
    mf[0][2] *= arg1->unk18;
    mf[1][0] *= arg1->unk1C;
    mf[1][1] *= arg1->unk1C;
    mf[1][2] *= arg1->unk1C;
    mf[2][0] *= arg1->unk18;
    mf[2][1] *= arg1->unk18;
    mf[2][2] *= arg1->unk18;
    guMtxF2L(mf, arg0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6260/func_151B9408.s")

extern f32 D_800AA56C;
extern f32 D_800AA570;

void func_151B9660(void *arg0) {
    *(f32 *)((char *)arg0 + 0x188) = 5.0f;
    *(f32 *)((char *)arg0 + 0x18C) = D_800AA56C;
    *(f32 *)((char *)arg0 + 0x190) = D_800AA570;
}
