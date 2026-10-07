#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void *func_1515D440(void) {
    void *ptr = allocate_memory(0x10, 1, 2, 0);
    bzero(ptr, 0x10);
    return ptr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D480.s")

extern u8 D_800DCD27;

void func_1515D4D4(arg0, arg1, arg2, arg3)
    s32 arg0; s32 arg1; s32 arg2; u8 arg3;
{
    if (arg3 >= D_800DCD27) {
        ((u8 *)&D_800DCD20)[0] = arg0;
        ((u8 *)&D_800DCD20)[1] = arg1;
        ((u8 *)&D_800DCD20)[2] = arg2;
        D_800DCD7C = 1;
        D_800DCD27 = arg3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D520.s")

void *func_1515D5F8();

void *func_1515D5AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, u8 arg9) {
    return func_1515D5F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D5F8.s")

struct func_1515D69C_s {
    struct func_1515D69C_s *next;
    u8 pad4[0x8];
    u8 unkC;
    u8 padD[0x23];
    u8 unk30;
};

void func_1515D69C(void) {
    struct func_1515D69C_s *p;

    for (p = (struct func_1515D69C_s *)D_800DCD78; p != NULL; p = p->next) {
        p->unkC = 0;
        p->unk30 = 0;
    }
}

void func_1515D6C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EF74.s")

f32 func_1515F008(s16 *arg0, s32 arg1) {
    s32 v;
    v = arg0[arg1];
    v = (v << 16) | ((u16 *)arg0)[arg1 + 16];
    return v * (1.0f / 65536.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F0AC.s")

void func_1515F10C(s32 *arg0) {
    s32 *cur;
    s32 *prev;

    cur = (s32 *)D_800DCD78;
    prev = NULL;
    while (cur != arg0) {
        prev = cur;
        cur = (s32 *)*cur;
    }
    if (prev != NULL) {
        *prev = *cur;
    } else {
        D_800DCD78 = *cur;
    }
    func_10004074(cur);
}

struct func_1515F170_s {
    struct func_1515F170_s *next;
    u8 pad4[5];
    u8 unk9;
    u8 padA;
    u8 unkB;
};

void func_1515F170(s32 arg0, u8 arg1) {
    struct func_1515F170_s *var_v0;

    for (var_v0 = (struct func_1515F170_s *)D_800DCD78; var_v0 != NULL; var_v0 = var_v0->next) {
        if (arg0 == var_v0->unkB) {
            var_v0->unk9 = arg1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F1B0.s")

struct func_1515F25C_s {
    s32 pad0[3];
    struct func_1515F25C_s *next;
};

void func_1515F25C(struct func_1515F25C_s **head, struct func_1515F25C_s *node) {
    node->next = *head;
    *head = node;
}

extern void (*D_8008B090[])(s32, s32 *);

void func_1515F270(s32 arg0, s32 *arg1) {
    s32 idx = arg1[6];

    if ((idx >= 0) && (idx < 12)) {
        if (D_8008B090[idx] != NULL) {
            D_8008B090[idx](arg0, arg1);
        }
    }
}

struct func_1515F2B8_s {
    u8 pad0[0x7A];
    u16 unk7A;
};

void func_1515F2B8(struct func_1515F2B8_s *arg0, s32 arg1) {
    func_1505D024(arg0, 0x6001D, arg0->unk7A, -1);
}

extern void (*D_8008B0C0[])(void *, void *);

void func_1515F2E8(u8 *arg0, u8 *arg1) {
    s32 idx;

    if (arg0[0x3B] == 1) {
        idx = *(s32 *)(arg1 + 0x1C);
        if (idx >= 0 && idx < 3) {
            D_8008B0C0[idx](arg0, arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F850.s")

struct func_1515FB70_s0 { u8 pad[0x3B]; u8 unk3B; };
struct func_1515FB70_s1 { u8 pad[0x1C]; s32 unk1C; };

void func_1515FB70(struct func_1515FB70_s0 *arg0, struct func_1515FB70_s1 *arg1) {
    if (arg0->unk3B == 1) {
        if (arg1->unk1C >= 0) {
            if (arg1->unk1C != 0) {
            }
        }
    }
}

void func_1515FB94(u8 *arg0, s32 arg1) {
    func_1505D024(arg0, 0x6002D, *(u16 *)(arg0 + 0x7A), -1);
}

extern void *func_15105C24();

void func_1515FBC4(u8 *arg0, s32 arg1) {
    u8 *t;
    struct127 *obj = NULL;

    t = func_15105C24(arg1);
    if (t != NULL) {
        obj = *(struct127 **)(t + 0x98);
    }
    func_1505D024(arg0, 0x6002E, *(u16 *)(arg0 + 0x7A), obj ? obj - gObjects : -1);
}

void func_1515FC34(s32 arg0, s32 arg1) {
    func_1505D024(arg0, 0x33, 0xC000, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515FC60.s")
