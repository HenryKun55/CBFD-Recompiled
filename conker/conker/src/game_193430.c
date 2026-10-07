#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15165F80.s")

struct func_15166118_s {
    u8 pad0[0x10];
    Vtx vtx[2][4];
    u8 pad90[0x2];
    u8 unk92;
    u8 unk93;
    u8 unk94;
    u8 unk95;
    s16 unk96;
    s16 unk98;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    u8 unkA0;
    u8 unkA1;
};

extern struct func_15166118_s *func_15167A68(s32, s32, s32, s32, s32, s32);
void func_1517E05C(s32 arg0, s32 arg1, s32 arg2);

void func_15166118(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, s32 arg9) {
    struct func_15166118_s *p;
    s32 i;

    p = func_15167A68(4, arg9, 0xA8, 1, arg8, 1);
    if (p != NULL) {
        p->unk95 = 2;
        for (i = 0; i < 2; i++) {
            p->vtx[i][0].v.tc[0] = 0x2000;
            p->vtx[i][0].v.tc[1] = 0x2000;
            p->vtx[i][1].v.tc[0] = 0x2800;
            p->vtx[i][1].v.tc[1] = 0x2000;
            p->vtx[i][2].v.tc[0] = 0x2800;
            p->vtx[i][2].v.tc[1] = 0x2800;
            p->vtx[i][3].v.tc[0] = 0x2000;
            p->vtx[i][3].v.tc[1] = 0x2800;
        }
        p->unk9E = 1;
        p->unk92 = arg6;
        p->unk93 = arg6;
        p->unk98 = arg2;
        p->unk9A = arg3;
        p->unk9C = arg4;
        p->unk96 = arg5;
        p->unk94 = arg7;
        p->unkA0 = arg0;
        p->unkA1 = arg1;
        func_1517E05C(arg2, arg3, arg4);
    }
}

struct func_15166204_s {
    u8 pad0[0x92];
    u8 unk92;
    u8 pad93[3];
    s16 unk96;
    u8 pad98[6];
    s16 unk9E;
};

void func_15166204(struct func_15166204_s *arg0) {
    s32 temp;

    temp = arg0->unk92;
    arg0->unk9E += arg0->unk96 * D_800BE9E4;
    temp -= D_800BE9E4;
    if (temp <= 0) {
        func_1516972C((struct102 *)arg0);
    } else {
        arg0->unk92 = temp;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15166268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_151668B8.s")
