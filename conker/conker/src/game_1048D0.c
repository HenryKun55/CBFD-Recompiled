#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150D7420_s {
    u8 pad0[0x28];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 pad2B[0x58 - 0x2B];
    s32 unk58;
};

void func_150D7420(struct func_150D7420_s *arg0, u8 *arg1, u8 arg2) {
    if (arg2 == 0x36) {
        switch (*arg1) {
        case 0:
            break;
        case 1:
            arg0->unk58 |= 2;
            arg0->unk28 = 0xFF;
            arg0->unk29 = 0;
            arg0->unk2A = 0;
            return;
        case 2:
            arg0->unk58 |= 2;
            arg0->unk28 = 0xFF;
            arg0->unk29 = 0;
            arg0->unk2A = 0;
            return;
        case 3:
            arg0->unk58 |= 2;
            arg0->unk28 = 0;
            arg0->unk29 = 0xFF;
            arg0->unk2A = 0;
            return;
        }
        arg0->unk58 &= ~2;
    }
}

struct func_150D74DC_s {
    u8 pad0[0x28];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 pad2B[0x58 - 0x2B];
    s32 unk58;
};

void func_150D74DC(struct func_150D74DC_s *arg0, u8 *arg1, u8 arg2) {
    if (arg2 == 0x36) {
        switch (*arg1) {
        case 1:
            arg0->unk58 &= ~2;
            break;
        case 2:
            arg0->unk58 |= 2;
            arg0->unk28 = 0xFF;
            arg0->unk29 = 0;
            arg0->unk2A = 0;
            break;
        case 3:
            arg0->unk58 |= 2;
            arg0->unk28 = 0;
            arg0->unk29 = 0xFF;
            arg0->unk2A = 0;
            break;
        case 0:
        default:
            arg0->unk58 &= ~2;
            break;
        }
    }
}

struct func_150D758C_s {
    u8 pad0[0x28];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 pad2B[0x58 - 0x2B];
    s32 unk58;
};

void func_150D758C(struct func_150D758C_s *arg0, u8 *arg1, u8 arg2) {
    if (arg2 == 0x36) {
        switch (*arg1) {
        case 1:
            arg0->unk58 &= ~2;
            return;
        case 2:
            arg0->unk58 &= ~2;
            return;
        case 3:
            arg0->unk58 |= 2;
            arg0->unk28 = 0;
            arg0->unk29 = 0xFF;
            arg0->unk2A = 0;
            return;
        case 0:
        default:
            arg0->unk58 &= ~2;
            break;
        }
    }
}

extern u16 D_800D9910;

void func_150D7630(s32 arg0) {
    if (arg0 == 0) {
        D_800D9910 += D_800BE9E4 << 6;
    }
}

struct func_150D765C_s {
    s32 *tbl[2];
};
extern struct func_150D765C_s D_80088900;
s32 func_1510D0EC(s32, void *, s32, s32);

Gfx *func_150D765C(Gfx *gdl) {
    s32 i;
    s32 set;
    s32 sp60[2];
    s32 idx;
    s32 seg;
    s32 base;
    struct func_150D765C_s tables;

    tables = D_80088900;
    set = 0;
    base = D_800D9910 >> 8;
    idx = base;
    for (i = 0; i < 6; i++) {
        if (i >= 4) {
            set = 1;
        }
        seg = func_1510D0EC(tables.tbl[set][idx % 5], sp60, 3, 0);
        gSPSegment(gdl++, i + 2, seg);
        idx += 13;
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1048D0/func_150D7790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1048D0/func_150D7928.s")
