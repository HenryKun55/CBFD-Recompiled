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

struct func_150D7790_s {
    u8 pad0[0x124];
    u8 unk124;
    u8 pad125[0x12C - 0x125];
    s16 unk12C;
    u8 pad12E[0x1AE - 0x12E];
    s8 unk1AE;
    u8 pad1AF[0x221 - 0x1AF];
    s8 unk221;
};

struct func_150D7790_o {
    u8 pad0[0x40];
    f32 unk40;
    u8 pad44[0x31C - 0x44];
    struct func_150D7790_s *unk31C;
};

s32 func_1508855C(struct func_150D7790_o *, struct func_150D7790_s *);
s32 func_1508868C(struct func_150D7790_s *);
void func_150885EC(s32, s32);

void func_150D7790(struct func_150D7790_o *arg0, s32 arg1) {
    s32 n;
    s32 id;
    s32 big;
    struct func_150D7790_s *obj;

    big = 0;
    if ((arg0->unk31C != NULL) && (arg0->unk31C->unk1AE <= 0)) {
        return;
    }
    switch (arg1) {
    case 0x30:
    case 0x31:
        if (arg0->unk31C != NULL) {
            arg0->unk31C->unk12C = 0x78;
            arg0->unk31C->unk1AE--;
            func_10010154(0x628, arg0, 0x7FFF, 0x1F4, 0x3E8);
        }
        break;
    case 0x33:
        big = 1;
    case 0x32:
        n = big * 30 + 30;
        obj = (struct func_150D7790_s *)func_1506C460(arg0->unk40, 310.0f, 0.0f, 0.0f, n, 0xD, 0.0f, 1.0f, 0, 1, big == 0);
        if (obj != NULL) {
            obj->unk124 = gCurrentObjectIndex + 1;
        }
        if ((obj != NULL) && (n != 30)) {
            obj->unk221 = -1;
            id = func_1508855C(arg0, obj);
            if (id != -1) {
                n = func_1508868C(obj);
                if (n != -1) {
                    func_150885EC(id, n);
                }
            }
        }
        if (arg0->unk31C != NULL) {
            arg0->unk31C->unk1AE--;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1048D0/func_150D7928.s")
