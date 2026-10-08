#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    f32 x, y, z;
} func_1518A3C0_v3;

struct func_1518A3C0_s {
    func_1518A3C0_v3 a;
    f32 f0C;
    func_1518A3C0_v3 b;
    func_1518A3C0_v3 c;
    f32 f28;
    f32 f2C;
};

struct func_1518A3C0_p {
    u8 u0;
    u8 u1;
    u8 u2;
    u8 u3;
    s16 s4;
    u8 u6;
    s32 s8;
    s32 sC;
    s32 s10;
    s32 s14;
    s32 s18;
    s32 s1C;
    s32 s20;
    u8 u24;
    u8 u25;
    u8 u26;
    u8 u27;
    u8 u28;
    u8 u29;
    u8 u2A;
    u8 u2B;
    u8 u2C;
    u8 u2D;
    u8 u2E;
    u8 u2F;
    s32 s30;
    u8 u34;
    u8 u35;
    func_1518A3C0_v3 v38;
};

struct func_1518A3C0_q {
    s16 s0;
    s32 s4;
};

extern s32 D_8008D5B8[];
extern s32 D_8008D5B0[];
extern void *func_151580B0(struct func_1518A3C0_p *, s32, s32, s32, s32, u8, s32);

void *func_1518A3C0(func_1518A3C0_v3 *arg0, func_1518A3C0_v3 *arg1, f32 arg2, func_1518A3C0_v3 *arg3,
                    func_1518A3C0_v3 *arg4, f32 arg5, f32 arg6, u8 arg7, s16 arg8, u8 arg9, s32 argA, u8 argB,
                    s32 argC) {
    void *ret;
    struct func_1518A3C0_p p;
    struct func_1518A3C0_s s;
    struct func_1518A3C0_q q;

    s.a = *arg1;
    s.b = *arg3;
    s.c = *arg4;
    s.f0C = arg2;
    s.f28 = arg5;
    s.f2C = arg6;
    p.u0 = arg7;
    p.u2 = 1;
    p.u3 = 1;
    p.s4 = arg8;
    if (arg9) {
        p.u6 = D_8008D5B8[func_150ADA20() & 1];
    } else {
        p.u6 = D_8008D5B0[func_150ADA20() & 1];
    }
    p.sC = 0x220205;
    p.s10 = 0x40600;
    p.u25 = 7;
    p.s14 = 1;
    p.s18 = 0x4A;
    p.s1C = 0x80;
    p.s20 = 0x20;
    p.s8 = 0;
    p.u24 = 0;
    p.u1 = 1;
    p.u28 = 0xFF;
    p.u29 = 0xFF;
    p.u2A = 0xFF;
    p.u2B = 0xFF;
    p.u2C = 0xFF;
    p.u2D = 0xFF;
    p.u2E = 0xFF;
    p.u2F = 0xFF;
    p.s30 = 0;
    p.u34 = 0;
    p.u35 = 2;
    p.v38 = *arg0;
    q.s0 = 0xC;
    q.s4 = 0x15;
    ret = func_151580B0(&p, 3, 0xFF, 1, argA + 0x38, argB, argC);
    if (ret == NULL) {
        return NULL;
    }
    memcpy((u8 *)ret + 0xF8, &q, 8);
    memcpy((u8 *)ret + 0x100, &s, 0x30);
    return ret;
}

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
