#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0100/func_15172C50.s")

extern s8 D_800DD2B0[];
void func_1517EE40(s32, s32, s32, s32, s32, s32);

void func_15172CA8(s32 arg0) {
    if (D_800DD2B0[arg0] != -1) {
        D_800DD2B0[arg0] = -1;
        func_1517EE40(0, 0, 0, 0, 1, arg0);
        func_1517EE40(0, 0, 0, 0x32, 0, arg0);
    }
}

struct func_15172D28_s {
    u8 pad0[0x2F8];
    u16 unk2F8;
    u8 pad2FA[0x31C - 0x2FA];
    u8 *unk31C;
};

void func_15085430(struct func_15172D28_s *, s32, s32);

void func_15172D28(struct func_15172D28_s *arg0, s32 arg1) {
    func_15085430(arg0, arg1, 1);
    arg0->unk2F8 &= 0xFFEF;
    if (D_800BE9B4 == 0) {
        if (arg0->unk31C != NULL) {
            arg0->unk31C[0x56] = 3;
        }
    }
}

s32 func_1517F40C(s32);
void func_1501C730(s32, s32, s32, s32, s32);

void func_15172D80(s32 arg0) {
    if (D_800DD2B0[arg0] != -1) {
        if (gObjects[arg0].health == 0) {
            D_800DD2B0[arg0] = -1;
            func_1517EE40(0, 0, 0, 0x32, 0, arg0);
        }
        if (func_1517F40C(arg0) != 0) {
            if (D_800DD2B0[arg0] != D_800BE9F0) {
                func_1501C730(1, D_800DD2B0[arg0], 0, 0, 0);
            } else {
                func_15172CA8(arg0);
                func_15172D28((struct func_15172D28_s *)&gObjects[arg0], (&D_800DD2C0)[arg0]);
            }
        }
    }
}

struct func_15172E7C_s {
    u8 pad0[0x127];
    u8 unk127;
    u8 pad128[0x1CA - 0x128];
    u8 unk1CA;
    u8 pad1CB[0x2F8 - 0x1CB];
    u16 unk2F8;
    u8 pad2FA[0x318 - 0x2FA];
    s32 unk318;
    s8 *unk31C;
};

void func_15172E7C(struct func_15172E7C_s *arg0, s32 arg1, s32 arg2) {
    s32 idx = arg0->unk127;

    if (arg0->unk1CA == 0) {
        return;
    }
    if (arg0->unk31C != NULL && arg0->unk31C[0x23] > 0) {
        return;
    }
    if (arg0->unk318 != 0) {
        if (D_800DD2B0[idx] == -1) {
            func_1517EE40(0, 0, 0, 0xA, 1, idx);
            arg0->unk2F8 |= 0x10;
            D_800DD2B0[idx] = arg1;
            (&D_800DD2C0)[idx] = arg2;
        }
    } else if (arg1 == D_800BE9F0) {
        func_15172D28((struct func_15172D28_s *)arg0, arg2);
    }
}
