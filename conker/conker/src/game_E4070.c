#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6C90.s")

struct func_150B6D34_s {
    u8 pad[0x20];
    s32 unk20;
};
extern struct func_150B6D34_s *D_800D9898[];

void func_150B6D34(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_800D9898[i + 5] != NULL) {
            D_800D9898[i + 5]->unk20 = 1;
        }
    }
    D_800D9890 = 3;
}

extern struct102 *D_800D9894;

void func_150B6D78(void) {
    s32 i;

    if (D_800D9894 != NULL) {
        func_1516972C(D_800D9894);
        D_800D9894 = NULL;
    }
    for (i = 0; i < 10; i++) {
        if (D_800D9898[i] != NULL) {
            func_1516972C((struct102 *)D_800D9898[i]);
            D_800D9898[i] = NULL;
        }
    }
    D_800D9890 = 3;
}

struct func_150B6DFC_s {
    u8 pad0[0x34];
    s16 unk34;
};

void func_150B6DFC(struct func_150B6DFC_s *arg0) {
    arg0->unk34 += D_800BE9E4 * 48;
    if (arg0->unk34 > 0x800) {
        arg0->unk34 = -0xC00;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B709C.s")

struct func_150B71A8_s {
    u8 pad0[0x38];
    s16 unk38;
    s16 unk3A;
};

void func_150B71A8(struct func_150B71A8_s *arg0) {
    if (arg0->unk38 != 0x1000) {
        arg0->unk38 += D_800BE9E4 << 8;
        if (arg0->unk38 > 0x1000) {
            arg0->unk38 = 0x1000;
        }
    } else if (arg0->unk3A != 0x1000) {
        arg0->unk3A += D_800BE9E4 << 8;
        if (arg0->unk3A > 0x1000) {
            arg0->unk3A = 0x1000;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B73F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7560.s")

void func_150B76BC(s32, s32);

void func_150B765C(void) {
    func_150B76BC(0x3C, 1);
    D_800D9890 = 3;
}

void func_150B76BC(s32 arg0, s32 arg1);

void func_150B768C(void) {
    func_150B76BC(0xE6, 2);
    D_800D9890 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B76BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B77A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B791C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B82D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B85C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B879C.s")
