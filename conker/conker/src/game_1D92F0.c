#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ABE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC078.s")

struct func_151AC3CC_s {
    u8 pad[0x1C];
    s16 unk1C;
    u8 pad2[0x98 - 0x1E];
    u8 *unk98;
};

s32 func_151AC3CC(struct func_151AC3CC_s *arg0) {
    u8 *p;
    s32 v;

    p = arg0->unk98;
    v = arg0->unk1C;
    v = v * 8;
    if (v >= 0x100) {
        v = 0xFF;
    }
    if (v < p[0x1B]) {
        p[0x1B] = v;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC408.s")

struct func_151AC550_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xC - 0x2];
    u8 unkC;
    u8 padD[0x2D - 0xD];
    s8 unk2D;
    u8 pad2E[0x94 - 0x2E];
    f32 (*unk94)[5];
    u8 *unk98;
};

extern s32 func_151D8E20(void);

s32 func_151AC550(struct func_151AC550_s *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, void *arg5) {
    u8 *sp44;
    f32 (*p)[5];
    f32 sp34[3];

    sp44 = arg0->unk98;
    p = arg0->unk94;
    sp34[0] = p[arg0->unk2D][0];
    sp34[1] = arg4;
    sp34[2] = p[arg0->unk2D][2];
    func_151DBCBC(func_151D8E20(), *(f32 *)sp44 * 7.0f, sp44[0x1B], arg5, sp34, arg0->unkC, arg0->unk1);
    sp44[0x20] = 4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC810.s")

extern f32 D_800BE9A4;

s32 func_151AC9EC(f32 *arg0) {
    f32 t = arg0[19] * D_800BE9A4;
    arg0[11] += t;
    arg0[12] += t;
    return 1;
}

struct func_151ACA20_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_151ACA20(struct func_151ACA20_s *arg0) {
    s16 v = 0xFF;
    if (arg0->unk1C < 16) {
        v = arg0->unk1C << 4;
    }
    if (v < arg0->unk5C) {
        arg0->unk5C = v;
    }
    return 1;
}

void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
s32 func_151ACB38(u8 *arg0, u8 *arg1);

struct func_151ACA60_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    u8 unk18;
    u8 pad19[3];
    struct127 *unk1C;
    u8 unk20;
    u8 pad21[3];
    s32 unk24;
    f32 unk28;
};

struct func_151ACA60_s *func_151ACA60(struct127 *arg0, f32 arg1, s32 arg2) {
    struct func_151ACA60_s *p;

    if (arg0 == NULL) {
        return NULL;
    }
    p = func_15167A68(0x30, 0, arg2 + 0x30, 1, 0xFF, 1);
    if (p == NULL) {
        return NULL;
    }
    if (func_151ACB38((u8 *)arg0, &p->unk18) == 0) {
        func_1516979C((struct102 *)p);
        return NULL;
    }
    p->unk1C = arg0;
    p->unk20 = ((u8 *)arg0)[0x3B];
    p->unk24 = arg0 - gObjects;
    p->unk28 = arg1;
    p->unk10 = 1;
    p->unk14 = 0;
    return p;
}

s32 func_151ACB38(u8 *arg0, u8 *arg1) {
    s32 ret = 0;
    if (arg0[0x3B] == 1) {
        *arg1 = 1;
        ret = 1;
    }
    return ret;
}

void func_151AE3A8(void *arg0);

void func_151ACB60(void *arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)(*(s32 *)(*(s32 *)((u8 *)arg0 + 0x1C) + 0x31C) + 0x9C);
    if (temp_v0 != 0) {
        func_151AE3A8(arg0);
    }
    if (arg0) {}
}

void func_151ACB94(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x1C, arg0 + 0x20, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD92C.s")

void func_151AE0E4(u8 *arg0, u8 arg1);
void func_151AE264();

void func_151AE06C(u8 *arg0, u8 *arg1) {
    u8 sp1F;
    u8 new;

    if (func_151ACB38(arg0, &sp1F)) {
        new = arg1[0x1B];
        if ((*(u8 **)(arg0 + 0x31C))[0x98] == 0) {
            func_151AE0E4(arg0, new);
        } else if (new != (*(u8 **)(arg0 + 0x31C))[0x98]) {
            func_151AE264(arg0);
            func_151AE0E4(arg0, new);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE0E4.s")

extern f32 D_800A9294;

struct func_151AE264_s2 {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[4];
    f32 unk4C;
    s8 unk50;
    u8 unk51;
    s16 unk52;
};

struct func_151AE264_s1 {
    u8 pad0[0x98];
    s8 unk98;
    u8 pad99[3];
    struct func_151AE264_s2 *unk9C;
    u8 padA0[0xE];
    u8 unkAE;
};

struct func_151AE264_s {
    u8 pad0[0x3C];
    f32 unk3C;
    u8 pad40[0x36];
    u16 unk76;
    u8 pad78[0x31C - 0x78];
    struct func_151AE264_s1 *unk31C;
};

void func_151AE264(struct func_151AE264_s *arg0) {
    struct func_151AE264_s2 *temp_v0;
    f32 temp_f0;

    temp_f0 = arg0->unk3C * D_800A9294;
    temp_v0 = arg0->unk31C->unk9C;
    temp_v0->unk4C = temp_f0;
    temp_v0->unk50 = arg0->unk76 >> 8;
    temp_v0->unk51 = arg0->unk31C->unkAE;
    temp_v0->unk52 = 0x14;
    temp_v0->unk44 = 0;
    arg0->unk31C->unk98 = 0;
    arg0->unk31C->unk9C = NULL;
}

struct func_151AE2BC_e {
    f32 unk0;
    f32 unk4;
    u8 pad8[0x10];
};
struct func_151AE2BC_s {
    u8 pad0[0x38];
    struct func_151AE2BC_e *unk38;
    u8 pad3C[6];
    u8 unk42;
};

void func_151AE2BC(f32 *arg0, struct func_151AE2BC_s *arg1, s32 arg2, f32 arg3) {
    s32 n = arg1->unk42;
    s32 i;
    struct func_151AE2BC_e *p;
    f32 d;

    for (i = 0; i < n - 1; i++) {
        if (arg3 <= arg1->unk38[i].unk4) {
            break;
        }
    }
    if (i >= n - 2) {
        *arg0 = 1.0f;
    } else if (i == 0) {
        *arg0 = 0.0f;
    } else {
        f32 a, b;
        p = &arg1->unk38[i];
        d = p->unk4 - p[-1].unk4;
        a = i - 1;
        b = n - 3;
        if (d != 0.0f) {
            d = (arg3 - p[-1].unk4) / d;
        } else {
            d = 0.0f;
        }
        *arg0 = a / b + d / (f32)(n - 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE3A8.s")

struct func_151AE590_node {
    u8 pad0[8];
    struct func_151AE590_node *next;
    u8 padC[4];
    u8 unk10;
};

struct func_151AE590_s {
    struct func_151AE590_node *slots[0x68];
};

extern struct func_151AE590_s D_800DCE50[];
extern s32 D_800A9270[];

struct func_151AE590_node *func_151AE590(u8 arg0) {
    u8 i;
    u8 j;
    struct func_151AE590_node *n;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            n = D_800DCE50[j].slots[D_800A9270[i]];
            while (n != NULL) {
                struct func_151AE590_node *next = n->next;

                if (n->unk10 == arg0) {
                    return n;
                }
                n = next;
            }
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE640.s")

extern f32 D_800A9D70;
s32 func_15045800(f32 *, s32, f32, f32 *);
void func_151ABE40(f32 *, f32 *, s32, u8, u8);
void func_10010FFC(s32, s32, s32, s32, s32, void *);

struct func_151AE6B0_t {
    u8 pad0[0x14];
    f32 x, y, z;
    u8 pad20[0x118 - 0x20];
    f32 unk118;
};

struct func_151AE6B0_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xC - 0x2];
    u8 unkC;
    u8 padD[0x18 - 0xD];
    struct func_151AE6B0_t *unk18;
    u8 pad1C[0x34 - 0x1C];
    f32 unk34[3];
};

void func_151AE6B0(struct func_151AE6B0_s *arg0) {
    struct func_151AE6B0_t *p = arg0->unk18;
    struct { f32 x, y, z; } v;
    f32 *dst;

    dst = arg0->unk34;
lbl:
    v.x = p->x;
    if (D_800A9D70 < p->unk118) {
        v.y = p->unk118 + 100.0f;
    } else {
        v.y = p->y + 150.0f;
    }
    v.z = p->z;
    if (func_15045800(&v.x, 0, v.y - 300.0f, dst)) {
        v.y = arg0->unk34[0];
        func_151ABE40(&v.x, dst, 5, arg0->unkC, arg0->unk1);
        func_10010FFC(0, 0x11, 0x5208, 0, 0, p);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE7B0.s")

s32 func_151AE984(f32 *, s32, s32, s32, s32, s32);
s32 func_151AEAB4(f32 *, s32, u8);
extern f32 D_800A9D84;
extern f32 D_800A9D88;

void func_151AE890(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6) {
    f32 v[3];
    f32 r;
    s32 t;
    s32 t2;

    v[0] = arg0;
    v[1] = arg1;
    v[2] = arg2;
    r = func_150ADA68();
    if (r < D_800A9D84) {
        return;
    }
    if (r < 0.25f) {
        t2 = (func_150ADA68() > 0.0f) ? 1 : 0;
        func_151AEAB4(v, t2, arg6[0xC]);
    } else {
        t = (D_800A9D88 < func_150ADA68()) ? 1 : 0;
        func_151AE984(v, arg3, arg4, arg5, t, arg6[0xC]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AEAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AECA0.s")

extern f32 D_800A9DCC;
extern f32 D_800A9DD0;
void func_1516962C(s32 arg0, void *arg1, u8 arg2);
s32 func_1513418C(void *arg0, s32 arg1, u8 arg2, s32 arg3);

struct func_151AF270_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    void *unkC;
    s8 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s8 unk2A;
    s8 unk2B;
    s8 unk2C;
    s8 unk2D;
    u8 pad2E[6];
};

s32 func_151AF270(u8 *arg0, u8 arg1, s32 arg2) {
    struct func_151AF270_s s;

    if (arg0 == NULL) {
        return 0;
    }
    func_1516962C(0x28, arg0, 0x16);
    s.unk0 = 0;
    s.unk4 = 0;
    s.unk8 = arg0[0x3B];
    s.unkC = arg0;
    s.unk10 = 1;
    s.unk14 = 0.0f;
    s.unk18 = 0.0f;
    s.unk1C = 0.0f;
    s.unk20 = D_800A9DCC;
    s.unk24 = D_800A9DD0;
    s.unk2A = 6;
    s.unk28 = 0x140;
    s.unk2B = 0xA;
    s.unk2C = -1;
    s.unk2D = 9;
    return func_1513418C(&s, 0, arg1, arg2);
}

void func_151AF388(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4);

struct func_151AF338_s {
    u8 pad[0xC];
    u8 unkC;
};

void func_151AF338(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, struct func_151AF338_s *arg6) {
    f32 sp24[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp24[2] = arg2;
    func_151AF388(sp24, arg3, arg4, arg5, arg6->unkC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF4D0.s")
