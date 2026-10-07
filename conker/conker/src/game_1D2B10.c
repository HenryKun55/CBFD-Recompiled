#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5CEC.s")

void func_151A5D2C(u16 arg0) {
    func_100111C8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5D58.s")

struct func_151A5F70_s {
    u8 pad0[0x14];
    u8 unk14;
};

typedef struct {
    struct func_151A5F70_s *unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    u8 unkC;
    u8 padD[3];
    s32 unk10;
} func_151A5F70_sub;

typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1B];
    func_151A5F70_sub unk28;
} func_151A5F70_a0;

typedef struct {
    s32 count;
    u8 *list;
    s32 unk8;
} func_151A5F70_a1;

void func_151A6068(struct func_151A5F70_s *, s32, u8, u8, u8, u8);

void func_151A5F70(func_151A5F70_a0 *arg0, func_151A5F70_a1 *arg1, u8 arg2) {
    func_151A5F70_a1 *a1 = arg1;
    func_151A5F70_sub *sub = &arg0->unk28;
    s32 i;
    s32 found;

    if (arg2 != 0x35) {
        return;
    }
    i = 0;
    found = 0;
    while (i < a1->count && !found) {
        if (sub->unk4 == a1->list[i]) {
            found = 1;
        } else {
            i++;
        }
    }
    if (found) {
        if (sub->unk0->unk14 == 1) {
            func_151A6068(sub->unk0, sub->unk8, sub->unkC & 1, sub->unkC & 2, arg0->unkC, arg0->unk1);
            sub->unk0->unk14 = 0;
            sub->unk10 = a1->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6600.s")

struct func_151A6AB8_s {
    u8 pad0[0x110];
    u8 *unk110;
    u8 pad114[0xC];
    struct102 *unk120;
};

void func_1000FD38();

void func_151A6AB8(struct func_151A6AB8_s *arg0) {
    arg0->unk110[0x14] = 1;
    func_1000FD38(func_1000EF40, arg0->unk110, 0);
    if (arg0->unk120 != NULL) {
        func_1516972C(arg0->unk120);
    }
}

void func_151A6B10(s32 arg0) {
    func_151A6AB8(arg0);
    func_1513CA6C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6B3C.s")

void *func_151A6BD8(s32 arg0);

void func_151A6B68(struct127 *arg0, s32 arg1) {
    void *temp_v0;
    struct127 *obj = NULL;

    temp_v0 = func_151A6BD8(arg1);
    if (temp_v0 != NULL) {
        obj = *(struct127 **)((u8 *)temp_v0 + 0x38);
    }
    func_1505D024(arg0, 0x60034, arg0->unk7A, obj != NULL ? obj - gObjects : -1);
}

struct func_151A6BD8_s {
    u8 pad0[8];
    struct func_151A6BD8_s *unk8;
    u8 padC[7];
    u8 unk13;
    u8 pad14[0x14];
    s32 unk28;
};

extern struct func_151A6BD8_s *D_800DCE50[][0x68];

void *func_151A6BD8(s32 arg0) {
    u8 i;
    u8 j;
    struct func_151A6BD8_s *node;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            node = D_800DCE50[j][D_800A5770[i]];
            if (node != NULL) {
loop_3:
                if (node->unk13 == 0x2C && node->unk28 == arg0) {
                    return node;
                }
                node = node->unk8;
                if (node == NULL) {
                    continue;
                }
                goto loop_3;
            }
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6C90.s")
