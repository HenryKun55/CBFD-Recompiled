#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514CA80.s")

extern void *func_15155FD4(s32 arg0);
extern void func_15155780(s32 arg0, s32 arg1);
extern u8 func_1514CA80(struct127 *arg0, s32 *arg1, s32 *arg2, s32 *arg3);
extern void (*D_8008AACC)(struct127 *);
extern void (*D_8008AA70[])(struct127 *);
extern u8 D_800A5ED8[];
extern u8 D_800A5EC0[];
extern u8 *D_8008AB90[];

s32 func_1514D15C(struct127 *arg0) {
    s32 sp44 = -1;
    s32 sp40 = -1;
    s32 sp3C = -1;
    u8 flags;
    s32 idx;
    void *p;
    void (*fn)(struct127 *);

    idx = arg0 - gObjects;
    if (*(s32 *)((u8 *)arg0 + 0x2F4) != 0) {
        return 0;
    }
    do {
        p = func_15155FD4(idx);
        if (p != NULL) {
            func_1516972C(p);
        }
    } while (p != NULL);
    if (idx == 0 && D_800BE616 == 0) {
        func_15155780(idx, 0xFF);
    }
    D_8008AACC(arg0);
    flags = func_1514CA80(arg0, &sp44, &sp40, &sp3C);
    if (flags == 0) {
        return 0;
    }
    if (flags & 4) {
        if (D_800A5ED8[sp3C] != 0) {
            D_8008AA70[D_800A5ED8[sp3C]](arg0);
        }
    }
    if (flags & 2) {
        if (D_800A5EC0[sp40] != 0) {
            D_8008AA70[D_800A5EC0[sp40]](arg0);
        }
    }
    if ((flags & 2) && (flags & 1)) {
        fn = D_8008AA70[D_8008AB90[sp40][sp44]];
        if (fn != NULL) {
            fn(arg0);
        }
    }
    return 1;
}

struct func_1514D310_s {
    u8 pad0[0x10];
    void *unk10;
    struct func_1514D310_s *unk14;
    u8 pad18[4];
    s16 unk1C;
};
extern s16 *D_8008ABE8[];
extern void (*D_8008AB58[])(void *);

s32 func_1514D310(u8 *arg0) {
    struct func_1514D310_s *cur;
    struct func_1514D310_s *next;

    cur = *(struct func_1514D310_s **)(arg0 + 0x2F4);
    while (cur != NULL) {
        next = cur->unk14;
        if (D_8008ABE8[cur->unk1C][1] != -1) {
            D_8008AB58[D_8008ABE8[cur->unk1C][1]](cur->unk10);
        }
        func_1516972C((struct102 *)cur);
        cur = next;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D64C.s")

void func_1514D96C(s32 arg0) {
}

s32 func_15158BD0(s32 arg0, s32 arg1, s32 arg2);
void func_1514EC1C(s32 arg0, s32 arg1, s32 arg2);
void *memcpy(void *dst, const void *src, size_t size);

struct func_1514D978_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

void func_1514D978(s32 arg0) {
    struct func_1514D978_s sp20;
    s32 temp_v0;

    sp20.unk0 = 0;
    sp20.unk4 = 0;
    sp20.unk8 = 0;
    sp20.unkC = 0;
    sp20.unk10 = 12.0f;
    sp20.unk14 = 0;
    sp20.unk18 = 0;
    sp20.unk1C = 0;
    temp_v0 = func_15158BD0(arg0, 1, 0x20);
    if (temp_v0 != 0) {
        memcpy((void *)(temp_v0 + 0x58), &sp20, 0x20);
        func_1514EC1C(temp_v0, arg0, 0x13);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D9F4.s")

s32 func_15158BD0(s32 arg0, s32 arg1, s32 arg2);
void func_1514EC1C(s32 arg0, s32 arg1, s32 arg2);

struct func_1514DA38_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_1514DA38(s32 arg0) {
    s32 temp_v0;
    struct func_1514DA38_s sp18;

    sp18.unk14 = 0;
    sp18.unk18 = 0;
    sp18.unk0 = 0;
    sp18.unk4 = 0;
    sp18.unk8 = 0;
    sp18.unkC = 0;
    temp_v0 = func_15158BD0(arg0, 1, 0x1C);
    if (temp_v0 != 0) {
        memcpy(temp_v0 + 0x58, &sp18, 0x1C);
        func_1514EC1C(temp_v0, arg0, 0x13);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DAA4.s")

s32 func_15158BD0(s32 arg0, s32 arg1, s32 arg2);
void func_1514EC1C(s32 arg0, s32 arg1, s32 arg2);

void func_1514DB18(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_15158BD0(arg0, 1, 0);
    if (temp_v0 != 0) {
        func_1514EC1C(temp_v0, arg0, 0x13);
    }
}

void func_1514DB58(s32 arg0) {
}

void func_1514DB64(void) {
    if (D_800BE9F0 == 20) {
        func_151B2060();
    }
}

void func_1514DB98(void) {
    func_1514F194();
}

extern u8 D_800A58A0[];
void *func_15160A58();

void func_1514DBB8(s32 arg0) {
    func_15160A58(arg0, 2, &D_800A58A0, 2, 0x12C, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0, -1, 0, 0, 0xFF, 1);
}

void func_1514DC38(struct127 *arg0) {
    func_1500EE18(arg0, 0xFF, 1);
}

void func_151D0F60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_1514DC5C(s32 arg0) {
    func_151D0F60(arg0, 0, 0xFF, 1);
}

void func_1514DC84(s32 arg0) {
    *(s32 *)(arg0 + 0x94) |= 2;
}

struct func_1514DC98_s {
    u8 pad0[0x94];
    s32 unk94;
};

void func_1514DC98(struct func_1514DC98_s *arg0) {
    arg0->unk94 |= 0x710;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DCAC.s")

void func_1514DCF4(struct127 *arg0) {
    if (arg0->unk31C != NULL) {
        arg0->unk31C->unk94 = 1;
    }
    func_15083568(arg0, 0x17, 0x3F800000, 0);
}

void func_1514DD2C(void) {
    func_1514DCAC();
}

void func_1514DD4C(void) {
    func_1514DCAC();
}

void func_1514DD6C(void) {
    func_1514DCAC();
}

void func_1514DD8C(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DDAC.s")

void func_1514DDCC(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DDEC.s")

void func_1514DE0C(void) {
    func_1514DCAC();
}

void func_1514DE2C(s32 arg0) {
}

void func_1514DE38(s32 arg0) {
}

void func_1514DE44(s32 arg0) {
}

void func_1514DE50(void) {
    if (((u8 *)&D_800D2E4C->unk10)[1] & 8) {
        func_1514DCAC();
    }
}

void func_1514DE88(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE94.s")

s32 func_15083FB0(s32);

struct func_1514DFD0_s {
    u8 pad0[0x65];
    u8 unk65;
    u8 pad66[0x101 - 0x66];
    u8 unk101;
};

void func_1514DFD0(struct func_1514DFD0_s *arg0) {
    arg0->unk65 = func_15083FB0(9) + 1;
    arg0->unk101 |= 0x34;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E00C.s")

s32 func_15189FF0(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_151D74B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 D_800A5E10;
extern f32 D_800A5E14;

struct func_1514E194_a {
    u8 unk0;
    u8 pad1;
    s16 unk2;
    s16 unk4;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 pad14[8];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u8 pad34[0xC];
    s32 unk40;
    u8 pad44;
    u8 unk45;
    u8 pad46[0x12];
};

struct func_1514E194_b {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 pad24[0x24];
    f32 unk48;
    u8 pad4C[8];
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    s32 unk58;
};

struct func_1514E194_c {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    s8 unk1E;
    u8 pad1F;
};

void func_1514E194(s32 arg0) {
    struct func_1514E194_b b;
    struct func_1514E194_a a;
    struct func_1514E194_c c;

    a.unk0 = 3;
    a.unk8 = 0;
    a.unkC = 0;
    a.unk40 = 0x12002;
    a.unk4 = 0;
    a.unk45 = 0xFF;
    a.unk10 = 0xFF;
    a.unk11 = 0x8E;
    a.unk12 = 0x19;
    a.unk13 = 0xFF;
    a.unk2 = 0x401;
    a.unk1C = 0.0f;
    a.unk20 = 0.0f;
    a.unk24 = 0.0f;
    a.unk28 = 0.0f;
    a.unk2C = 0.0f;
    a.unk30 = 0.0f;
    b.unk0 = 16.0f;
    b.unk4 = 16.0f;
    b.unk8 = 16.0f;
    b.unkC = 16.0f;
    b.unk10 = 0.0f;
    b.unk14 = 0.0f;
    b.unk18 = 0.5f;
    b.unk1C = 0.5f;
    b.unk20 = D_800A5E10;
    c.unk1D = ((u8 *)arg0)[0x3B];
    c.unk8 = 59.0f;
    c.unk14 = D_800A5E14;
    c.unk18 = arg0;
    b.unk48 = 1.0f;
    c.unk0 = 35.0f;
    c.unk4 = 27.0f;
    c.unkC = 35.0f;
    c.unk10 = 27.0f;
    c.unk1C = 6;
    b.unk54 = 0;
    b.unk55 = 0;
    b.unk56 = 0;
    b.unk57 = 0;
    c.unk1E = -1;
    func_1514EC1C(func_15189FF0(&a, &b, &c, 2, 0, 0, 0), arg0, 6);
    func_151D74B0((void *)arg0, 5, -1, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E718.s")

extern s32 D_800A5920;
s32 func_1518D1C0();
void func_1514EC1C();

void func_1514E7C8(s32 arg0) {
    func_1514EC1C(func_1518D1C0(arg0, 7, 0, 1, 0xFF, 1, &D_800A5920), arg0, 0xF);
}

void func_1514E824(s32 arg0) {
}

void func_1514E830(struct102 *arg0) {
    func_1516972C(arg0);
}

void func_1514E850(struct102 *arg0) {
    func_1518E308(arg0);
    func_1516972C(arg0);
}

void func_1514E87C(void) {
    func_1515F10C();
}

struct func_1514E89C_s {
    u8 pad[0x10];
    s32 unk10;
};

s32 func_1514E89C(arg0, arg1, arg2)
    struct func_1514E89C_s *arg0;
    s32 arg1;
    s32 arg2;
{
    switch (arg1) {
    case 0:
        if (arg0->unk10 & 1) {
            arg0->unk10 &= ~1;
        } else {
            arg0->unk10 |= 1;
        }
        break;
    case 2:
        arg0->unk10 &= ~1;
        break;
    case 1:
        arg0->unk10 |= 1;
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E920.s")

void func_1514E920(void);

void func_1514E9DC(void) {
    func_1514E920();
}

void func_1514E9FC(void) {
    func_1514E89C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EA1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EB6C.s")

s32 func_1514EB8C(s32 arg0, s32 arg1, s32 arg2) {
    return 1;
}

struct func_1514EBA4_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
};

void *func_15167A68(s32, s32, s32, s32, s32, s32);

struct func_1514EBA4_s *func_1514EBA4(s32 arg0, s16 arg1, s32 arg2) {
    struct func_1514EBA4_s *ret = func_15167A68(0x24, 1, arg2 + 0x20, 1, 0xFF, 1);
    if (ret == NULL) {
        return NULL;
    }
    ret->unk10 = arg0;
    ret->unk14 = 0;
    ret->unk18 = 0;
    ret->unk1C = arg1;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EC1C.s")

struct func_1514ECE0_s {
    u8 pad0[0x14];
    struct func_1514ECE0_s *next;
    u8 pad18[0x4];
    s16 id;
};

s32 func_1514ECE0(struct func_1514ECE0_s *arg0, s16 arg1, struct func_1514ECE0_s **arg2) {
    s32 found = 0;
    struct func_1514ECE0_s *p = arg0;

    while (p != NULL && !found) {
        arg0 = p->next;
        if (arg1 == p->id) {
            found = 1;
        } else {
            p = arg0;
        }
    }
    if (arg2 != NULL) {
        *arg2 = p;
    }
    return found;
}

struct func_1514ED3C_s {
    u8 pad0[0x10];
    s32 unk10;
    struct func_1514ED3C_s *next;
};

s32 func_1514ED3C(struct func_1514ED3C_s *arg0, s32 arg1, struct func_1514ED3C_s **arg2) {
    s32 found = 0;
    struct func_1514ED3C_s *p = arg0;
    struct func_1514ED3C_s *next;

    while (p != NULL && !found) {
        next = p->next;
        if (arg1 == p->unk10) {
            found = 1;
        } else {
            p = next;
        }
    }
    if (arg2 != NULL) {
        *arg2 = p;
    }
    return found;
}

struct func_1514ED8C_s {
    u8 pad0[0x10];
    s32 unk10;
    struct func_1514ED8C_s *next;
    struct func_1514ED8C_s *prev;
};

s32 func_1514ED8C(struct func_1514ED8C_s *arg0, u8 *arg1) {
    s32 ret;

    if (arg0 == *(struct func_1514ED8C_s **)(arg1 + 0x2F4)) {
        *(struct func_1514ED8C_s **)(arg1 + 0x2F4) = arg0->next;
    }
    if (arg0->next != NULL) {
        arg0->next->prev = arg0->prev;
    }
    if (arg0->prev != NULL) {
        arg0->prev->next = arg0->next;
    }
    ret = arg0->unk10;
    func_1516972C((struct102 *)arg0);
    return ret;
}

void func_1514EDF0(s32 arg0, u8 *arg1) {
    struct func_1514ED3C_s *p = *(struct func_1514ED3C_s **)(arg1 + 0x2F4);
    u8 f;
    struct func_1514ED3C_s *found = NULL;
    s32 r;

    do {
        r = func_1514ED3C(p, arg0, &found);
        f = r;
        if (r) {
            p = found->next;
            func_1514ED8C((struct func_1514ED8C_s *)found, arg1);
        }
    } while (f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EECC.s")

void func_1514F110(void) {
    func_1514F194();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F130.s")

extern u8 D_800A5958[];
extern u8 D_800A5964[];
void func_151BB044(s32 arg0);
void func_151BC074(s32 arg0);
void func_151BD2F8(s32 arg0, s32 arg1, s32 arg2);
void func_151B9F00(s32 arg0, s32 arg1, s32 arg2);

int func_1514F194(s32 arg0) {
    void *temp_v0;

    func_151D0F60(arg0, 1, 0xFF, 1);
    func_151D0F60(arg0, 2, 0xFF, 1);
    func_151BB044(arg0);
    if (D_800BE616 == 0) {
        func_151BC074(arg0);
    }
    func_151BD2F8(arg0, 0xFF, 1);
    func_151B9F00(arg0, 0xFF, 1);
    func_15160A58(arg0, 1, &D_800A5958, 2, 0x12C, 0xC, 0xFF, 0xFF, 0xFF, 2, 0, -1, 0, 0, 0xFF, 1);
    temp_v0 = func_15160A58(arg0, 1, &D_800A5964, 2, 0x12C, 0xF, 0xFF, 0, 0, 0xFF, 1, -1, 0, 0, 0xFF, 1);
    if (temp_v0 != 0) {
        func_1514EC1C(temp_v0, arg0, 0x19);
    }
}

struct func_1514F308_s {
    f32 x;
    f32 y;
    f32 z;
};

extern struct func_1514F308_s D_800A5970;
extern struct func_1514F308_s D_800A597C;
extern f32 D_800A5E58;
void func_15160CDC(s32 arg0, s32 arg1, struct func_1514F308_s *arg2, struct func_1514F308_s *arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, s32 argE, s32 argF);

void func_1514F308(s32 arg0) {
    struct func_1514F308_s sp54 = D_800A5970;
    struct func_1514F308_s sp48 = D_800A597C;

    func_15160CDC(arg0, 5, &sp54, &sp48, D_800A5E58, 2, 300, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0, 0, 0xFF, 1);
}

struct func_1514F3CC_s {
    struct127 *unk0;
    u8 unk4;
    f32 unk8;
};

void func_1514F3CC(struct127 *arg0) {
    struct func_1514F3CC_s tmp;
    struct260 *temp_v0;

    tmp.unk0 = arg0;
    tmp.unk4 = arg0->unique_id;
    tmp.unk8 = 0.0f;
    temp_v0 = func_15149130(300, -1, 58, -1, 0, 43, 12, 255, 1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, 12);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F44C.s")

void func_151D74B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_1514F4A8(void *arg0) {
    func_151D74B0(arg0, 1, -1, 0xFF, 1);
}

void func_151D74B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_1514F4D8(void *arg0) {
    func_151D74B0(arg0, 2, 1, 0xFF, 1);
}

void func_1514F508(s32 arg0) {
    func_151D74B0(arg0, 3, 0, 0xFF, 1);
}

void func_1514F538(void *arg0) {
    func_151D74B0(arg0, 4, -1, 0xFF, 1);
}

void func_150C4120(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_1514F568(s32 arg0) {
    func_150C4120(arg0, -1, 0xFF, 1);
}

void func_1514F590(s32 arg0) {
    func_1501175C(arg0, 0xFF, 1);
    func_15011A78(arg0, 0xFF, 1);
}

extern f32 D_800A5E5C;
void *func_150C0AC0(void *arg0, s32 arg1, s32 arg2);

struct func_1514F5CC_s {
    s32 unk0;
    f32 unk4;
    void *unk8;
    u8 unkC;
    f32 unk10;
    s16 unk14;
    s16 unk16;
    u8 unk18;
};

void func_1514F5CC(u8 *arg0) {
    struct func_1514F5CC_s sp1C;

    sp1C.unk0 = 0;
    sp1C.unk4 = 0.0f;
    sp1C.unk8 = arg0;
    sp1C.unkC = arg0[0x3B];
    sp1C.unk10 = D_800A5E5C;
    sp1C.unk14 = 0x14;
    sp1C.unk16 = 0x12C;
    sp1C.unk18 = 4;
    func_150C0AC0(&sp1C, 0xFF, 1);
}
