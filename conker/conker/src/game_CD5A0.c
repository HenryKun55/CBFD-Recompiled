#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A00F0.s")

struct func_150A019C_s {
    u32 unk0_31 : 1;
    u32 unk0_30 : 1;
    u32 unk0_26 : 4;
    u32 unk0_rest : 26;
    u32 unk4;
    u32 unk8;
};
struct func_150A0264_s;
extern struct func_150A0264_s D_800D3010[];
extern u16 D_80088510[];
extern u16 D_8008851C[];
#define P ((struct func_150A019C_s *)D_800D3010)

void func_150A019C(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (P[i].unk0_31 && P[i].unk0_30 == 1) {
            P[i].unk8 += D_800BE9E4;
            if (P[i].unk8 >= D_80088510[P[i].unk0_26]) {
                P[i].unk8 -= D_80088510[P[i].unk0_26];
                P[i].unk4++;
                if (D_8008851C[P[i].unk0_26] != 0) {
                    P[i].unk4 %= D_8008851C[P[i].unk0_26];
                }
            }
        }
    }
}
#undef P

struct func_150A0264_s {
    u32 unk0_31 : 1;
    u32 unk0_30 : 1;
    u32 unk0_26 : 4;
    u32 unk0_rest : 26;
    s32 unk4;
    s32 unk8;
};
extern struct func_150A0264_s D_800D3010[];

s32 func_150A0264(s32 arg0, s32 *arg1) {
    struct func_150A0264_s *p = &D_800D3010[arg0];

    if (p->unk0_31) {
        return 0;
    }
    p->unk0_31 = 1;
    p->unk0_30 = 0;
    p->unk0_26 = arg1[1];
    p->unk4 = 0;
    return 1;
}

extern struct func_150A0374_s D_800D3014[];

s32 func_150A02D0(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {
        case 0:
            D_800D3010[arg0].unk0_30 = 1;
            return 1;
        case 1:
            D_800D3010[arg0].unk0_30 = 0;
            return 1;
        case 2:
            ((s32 (*)[3])D_800D3014)[arg0][0] = arg2[2];
            return 1;
    }
    return 0;
}

struct func_150A0374_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};
extern struct func_150A0374_s D_800D3014[];

s32 func_150A0374(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 3) {
        return D_800D3014[arg0].unk0;
    }
    return 0;
}
