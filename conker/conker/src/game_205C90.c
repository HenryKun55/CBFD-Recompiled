#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_80084060[];

s32 func_151D87E0(u8 arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        if (arg0 & (1 << i)) {
            if (D_80084060[i] >= 4) {
                return 0;
            }
            if (D_800BE944[D_80084060[i]] != 0) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8868.s")

struct func_151D8A24_s {
    u8 pad0[0xE];
    u8 unkE;
    u8 padF;
    s16 unk10;
    u8 unk12;
    u8 unk13;
    s8 unk14;
    u8 pad15;
    u8 unk16;
};

extern void (*D_8008FCC0[])(struct func_151D8A24_s *);
void func_1501C17C(u8);
void func_1501C010(u8, u8);

void func_151D8A24(struct func_151D8A24_s *arg0) {
    s32 pad;
    u8 sp23;
    u8 i;

    sp23 = 0;
    if (arg0->unkE & 1) {
        arg0->unk10 -= D_800BE9E4;
        if (arg0->unk10 < 0) {
            sp23 = 1;
        }
    }
    if (arg0->unk14 != -1) {
        D_8008FCC0[arg0->unk14](arg0);
    }
    if (arg0->unk16 != arg0->unk12) {
        for (i = 0; i < 4; i++) {
            if (arg0->unk13 & (1 << i)) {
                func_1501C17C(i);
                func_1501C010(i, arg0->unk12);
            }
        }
        arg0->unk16 = arg0->unk12;
    }
    if (sp23) {
        func_1516972C(arg0);
    }
}

void func_1501C17C(u8);

void func_151D8B24(u8 *arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        if (arg0[0x13] & (1 << i)) {
            func_1501C17C(i);
        }
    }
}

void func_151D8B88(s32 arg0) {
    func_151D8B24(arg0);
    func_15169804(arg0);
}

void func_151D8BB4(s32 arg0) {
    func_151D8B24(arg0);
    func_15169824(arg0);
}

void func_151D8C00(u8 *arg0, u8 *arg1);

void func_151D8BE0(u8 *arg0) {
    func_151D8C00(arg0, arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8C00.s")

void func_151D8D5C(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x58) {
        func_1516972C(arg0);
    } else if (arg2 == 0x47) {
        func_1516972C(arg0);
    }
}

extern s32 D_800AB300;

void func_151D8DB4(void *arg0, u8 arg1) {
    func_15169260(&D_800AB300, 1, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8DE8.s")
