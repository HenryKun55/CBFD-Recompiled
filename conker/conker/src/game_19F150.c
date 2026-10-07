#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15171CA0_s {
    u8 pad0[0x16];
    s16 unk16;
    u8 pad18[0xE];
    s16 unk26;
    u8 pad28[0xE];
    s16 unk36;
    u8 pad38[0xE];
    s16 unk46;
    u8 pad48[0x8];
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;
    u8 unk58;
    u8 unk59;
};

extern struct func_15171CA0_s *func_15167A68(s32, s32, s32, s32, s32, s32);

struct func_15171CA0_s *func_15171CA0(s16 arg0, u16 arg1, u8 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6, s32 arg7) {
    struct func_15171CA0_s *v1;

    v1 = func_15167A68((arg5 == 0) ? 0xF : 0x43, arg7, 0x60, 1, arg6, 1);
    if (v1 == NULL) {
        return NULL;
    }
    v1->unk50 = arg0;
    v1->unk52 = 0;
    v1->unk54 = arg4;
    v1->unk56 = arg1;
    v1->unk58 = arg2;
    v1->unk59 = arg3;
    v1->unk16 = 0;
    v1->unk26 = 0;
    v1->unk36 = 0;
    v1->unk46 = 0;
    return v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_15171D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_15171F04.s")

struct func_15171FC0_s {
    u8 pad0[0x50];
    s16 unk50;
    s16 unk52;
    s16 unk54;
    u8 pad56[2];
    u8 unk58;
    u8 unk59;
};

typedef struct {
    u8 pad0[4];
    u8 unk4;
} func_15171FC0_t;

extern func_15171FC0_t *D_8008CA4C[];

void func_15171FC0(struct func_15171FC0_s *arg0) {
    s32 tmp;

    if (arg0->unk50 < -1) {
        arg0->unk50++;
        if (arg0->unk50 == -1) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg0->unk50 == 0) {
        arg0->unk50 = -3;
    } else if (arg0->unk50 != -1) {
        if (!(arg0->unk59 & 4)) {
            if (arg0->unk50 > D_800BE9E4) {
                arg0->unk50 -= D_800BE9E4;
            } else {
                arg0->unk50 = 0;
            }
        }
        arg0->unk52 += arg0->unk54;
        tmp = D_8008CA4C[arg0->unk58]->unk4;
        if ((arg0->unk52 / 256) >= tmp) {
            if (arg0->unk59 & 4) {
                arg0->unk50 = -3;
            } else {
                arg0->unk52 = (tmp << 8) - 0x100;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_151720C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_151725FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_15172B20.s")
