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

struct func_1515D520_s {
    struct func_1515D520_s *next;
};

void *func_1515D520(void) {
    struct func_1515D520_s *p = allocate_memory(0x34, 1, 2, 2);
    struct func_1515D520_s *q;

    if (p != NULL) {
        bzero(p, 0x34);
        if (*(struct func_1515D520_s **)&D_800DCD78 != NULL) {
            q = *(struct func_1515D520_s **)&D_800DCD78;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        } else {
            *(struct func_1515D520_s **)&D_800DCD78 = p;
        }
        p->next = NULL;
    }
    return p;
}

void *func_1515D5F8();

void *func_1515D5AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, u8 arg9) {
    return func_1515D5F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

struct func_1515D5F8_s {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 padC[2];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u8 pad14[0x18];
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
};

void *func_1515D5F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
    s32 arg0; s32 arg1; s32 arg2; s32 arg3; s32 arg4; s32 arg5; s32 arg6; s32 arg7; s32 arg8; u8 arg9;
{
    struct func_1515D5F8_s *p = func_1515D520();

    if (p != NULL) {
        p->unk4 = 0;
        p->unk5 = arg4;
        p->unk6 = arg5;
        p->unk7 = arg6;
        p->unk8 = arg7;
        p->unk9 = arg8;
        p->unkB = arg9;
        p->unkA = 0;
        p->unkE = arg0;
        p->unk10 = arg1;
        p->unk12 = arg2;
        p->unk2F = arg3;
        p->unk2C = 0x7F;
        p->unk2D = 0;
        p->unk2E = 0;
    }
    return p;
}

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

extern s32 D_800DCD10[];
void func_1515EF74();

#define S(v, s, w) (((v) & ((1 << (w)) - 1)) << (s))
#define INT(a, b) (((a >> 16) << 16) | (((b) >> 16) & 0xFFFF))
#define FRAC(a, b) ((((a) & 0xFFFF) << 16) | ((b) & 0xFFFF & 0xFFFF))
#define FRAC2(a, b) ((((a) & 0xFFFF) << 16) | ((b) & 0xFFFF & 0xFFFF))
#define FRAC3(a, b) ((((0) & 0xFFFF) << 16) | ((a) << 16))

void *func_1515D6D0(Gfx *gdl, s32 arg1) {
    gSPNumLights(gdl++, 0);
    gSPSetGeometryMode(gdl++, G_LIGHTING);
    func_1515EF74((u8 *)D_800BE628 + arg1 * 0x180 + (D_800BE9C0 << 6) + 0x100);
    gMoveWd(gdl++, 0x10, 0, INT(D_800DCD10[0], D_800DCD10[1]));
    gMoveWd(gdl++, 0x10, 8, INT(D_800DCD10[0], D_800DCD10[1]));
    gMoveWd(gdl++, 0x10, 4, INT(D_800DCD10[2], 0));
    gMoveWd(gdl++, 0x10, 0xC, INT(D_800DCD10[2], 0));
    gMoveWd(gdl++, 0x10, 0x10, FRAC(D_800DCD10[0], D_800DCD10[1]));
    gMoveWd(gdl++, 0x10, 0x18, FRAC(D_800DCD10[0], D_800DCD10[1]));
    gMoveWd(gdl++, 0x10, 0x14, FRAC2(D_800DCD10[2], 0));
    gMoveWd(gdl++, 0x10, 0x1C, FRAC2(D_800DCD10[2], 0));
    gMoveWd(gdl++, 0x10, 0x20, FRAC(0,0));
    gMoveWd(gdl++, 0x10, 0x24, FRAC3(D_800DCD10[3], 0));
    gMoveWd(gdl++, 0x10, 0x28, FRAC(0,0));
    gMoveWd(gdl++, 0x10, 0x2C, FRAC3(D_800DCD10[3], 0));
    return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E888.s")

struct func_1515EB84_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0xC];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad38[0x180 - 0x38];
    f32 unk180;
    u8 pad184[0x32C - 0x184];
};

struct func_1515EB84_obj {
    u8 pad0[0x14];
    u8 unk14;
    u8 unk15;
    u8 pad16[2];
    u32 unk18;
};

struct func_1515EB84_node {
    struct func_1515EB84_node *next;
    struct func_1515EB84_obj *obj;
};

s32 func_150A1DA0();

struct func_1515EB84_obj *func_1515EB84(s32 arg0, s32 arg1, s32 arg2, s32 arg3, struct func_1515EB84_node *arg4) {
    struct func_1515EB84_s sp34;
    s32 pad[2];

    sp34.unk14 = sp34.unk2C = arg0;
    sp34.unk180 = sp34.unk18 = sp34.unk30 = arg1;
    sp34.unk1C = sp34.unk34 = arg2;
    while (arg4 != NULL) {
        if (arg4->obj->unk14 == 0 &&
            (arg3 == 0 || ((arg4->obj->unk18 >> 24) & arg3)) &&
            ((arg4->obj->unk15 >> 2) == 0x18 || (arg4->obj->unk18 >> 31) == 0) &&
            func_150A1DA0(&sp34, arg4->obj, 0) == 0) {
            return arg4->obj;
        }
        arg4 = arg4->next;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EC78.s")

f32 func_1515F008(s16 *arg0, s32 arg1);
void func_1515F040(f32 arg0, s32 arg1);
void func_1515F0AC(f32 arg0, s32 arg1);

void func_1515EF74(s16 *arg0) {
    func_1515F040(1.0f / func_1515F008(arg0, 0), 0);
    func_1515F040(1.0f / func_1515F008(arg0, 5), 1);
    func_1515F040(1.0f / func_1515F008(arg0, 0xA), 2);
    func_1515F0AC(-func_1515F008(arg0, 0xE), 3);
}

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

struct func_1515F1B0_s {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
};

struct func_1515F1B0_s *func_1515F1B0(s32 arg0) {
    struct func_1515F1B0_s *p;

    p = (struct func_1515F1B0_s *)func_10003C6C(0x10, 1, 2, 0, 1);
    if (p == NULL) {
        return NULL;
    }
    p->unk0 = arg0;
    p->unk4 = arg0 ? func_1514462C(arg0) : 0.0f;
    p->unk8 = arg0 ? func_15144598(arg0) : 0.0f;
    p->unkC = 0;
    return p;
}

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
