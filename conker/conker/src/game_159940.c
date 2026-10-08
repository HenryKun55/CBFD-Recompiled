#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512C490.s")

extern s32 func_150495B0(f32 *, f32, f32 *, f32, f32, f32);
extern f32 D_800A36C0;
extern f32 D_800A36C4;
extern f32 D_800A36C8;
extern f32 D_800A36CC;
extern f32 D_800A36D0;
extern f32 D_800A36D4;
extern f32 D_800A36D8;

void func_1512D070(u8 *arg0) {
    Mtx m;
    f32 mf[4][4];
    f32 f2;
    s32 flags;

    flags = *(s32 *)(arg0 + 0x2C);
    if (flags & 0x80000) {
        f2 = D_800A36C0;
    } else if (*(s16 *)(arg0 + 0x298) != 0) {
        f2 = D_800A36C4;
    } else {
        f2 = D_800A36C8;
    }
    if ((flags & 0x80000) || (*(s32 *)(arg0 + 0x5F0) & 1) ||
        ((flags != 0x40000) && (*(s32 *)(arg0 + 0x5F0) & 8))) {
        *(f32 *)(arg0 + 0x7B0) += D_800A36CC * D_800BE9E4;
        if (D_800A36D0 < *(f32 *)(arg0 + 0x7B0)) {
            *(f32 *)(arg0 + 0x7B0) -= D_800A36D4;
        }
    } else {
        f2 = 0.0f;
    }
    if ((*(u8 *)(arg0 + 0x23C) != 0) || (*(s32 *)(arg0 + 0x5F0) & 4)) {
        *(f32 *)(arg0 + 0x7DC) = f2;
    } else {
        func_150495B0((f32 *)(arg0 + 0x7DC), f2, (f32 *)(arg0 + 0x7D8), 0.2f, D_800A36D8, *(f32 *)(arg0 + 0x7B4));
    }
    guMtxIdentF(mf);
    mf[0][0] = 2.0f * *(f32 *)(arg0 + 0x7DC) + 2.0f * (*(f32 *)(arg0 + 0x7DC) * func_150AD78C(*(f32 *)(arg0 + 0x7B0))) + 1.0f;
    mf[1][1] = *(f32 *)(arg0 + 0x7DC) + *(f32 *)(arg0 + 0x7DC) * func_150AD780(*(f32 *)(arg0 + 0x7B0)) + 1.0f;
    guMtxF2L(mf, &m);
    guMtxCatL(*(u8 *)(arg0 + 0x23D) + ((Mtx **)&D_800DC2A0)[D_800BE9C0], &m, *(u8 *)(arg0 + 0x23D) + ((Mtx **)&D_800DC2A0)[D_800BE9C0]);
}

extern void *func_1502B5C8();
extern void *D_800DC280[];
extern s32 D_800DC290[];

void func_1512D238(void) {
    u32 size;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800DC280[i] = func_1502B5C8(&size, 2, 0x1B, i);
        D_800DC290[i] = size / 24;
    }
}

void func_1512D2E4(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x850) = arg1;
    arg0[0x84D] = 1;
}

extern s32 D_800DC290[];

void func_1512D2F8(u8 *arg0) {
    switch (arg0[0x84D]) {
    case 1:
        arg0[0x84E] = 0;
        arg0[0x84D] = 2;
        break;
    case 2:
        arg0[0x84E] += D_800BE9E4;
        if (arg0[0x84E] >= D_800DC290[*(s32 *)(arg0 + 0x850)]) {
            arg0[0x84D] = 0;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D368.s")
