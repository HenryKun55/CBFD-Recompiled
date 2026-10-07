#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BE50.s")

void func_1514EDF0(s32 arg0, s32 arg1);

void func_1515BF50(s32 *arg0) {
    func_1514EDF0(arg0, arg0[6]);
    func_15169804(arg0);
}

void func_1515BF7C(s32 *arg0) {
    func_1514EDF0(arg0, arg0[6]);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BFA8.s")

void func_1515C0B8(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x18, arg0 + 0x1C, arg0);
}

s32 func_1514ECE0();

s32 func_1515C0F8(s32 arg0, s32 *arg1) {
    s32 sp1C;
    s32 temp;

    if (arg0 == 0) {
        return 0;
    }
    if (func_1514ECE0(*(s32 *)(arg0 + 0x2F4), 0x16, &sp1C) != 0) {
        temp = *(s32 *)(sp1C + 0x10);
        *arg1 = temp + 0x38;
        return 1;
    }
    return 0;
}

struct func_1515C158_node {
    u8 pad0[8];
    struct func_1515C158_node *next;
    u8 padC[0x38];
    s32 unk44;
    s32 unk48;
};

struct func_1515C158_s {
    u8 pad0[0xC8];
    struct func_1515C158_node *head;
    u8 padCC[0x1A0 - 0xCC];
};

extern struct func_1515C158_s D_800DCE50[];

void func_1515C158(void) {
    s32 i;
    struct func_1515C158_node *n;

    for (i = 0; i < 2; i++) {
        for (n = D_800DCE50[i].head; n != NULL; n = n->next) {
            n->unk44 = 0;
            n->unk48 = -1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515C1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515C244.s")
