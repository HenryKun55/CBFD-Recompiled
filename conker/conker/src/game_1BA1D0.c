#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518CD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E298.s")

void func_1518E308(void *arg0) {
    s32 **p;
    s32 i;

    p = (s32 **)((char *)arg0 + 0x48);
    ((s32 *)arg0)[10] = 0;
    ((f32 *)arg0)[9] = 0.0f;
    for (i = 0; i != 100; i++) {
        if (*p != NULL) {
            func_1516972C(*p);
        }
        p += 6;
    }
    bzero((char *)arg0 + 0x48, 0x960);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E37C.s")

void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

void *func_1518E3C4(u8 **arg0, u8 arg1) {
    u8 *v;

    if (arg0[0][4] == 0x96) {
        return NULL;
    }
    v = func_15167A68(0x21, 1, 0x9EC, 1, arg1, 1);
    if (v == NULL) {
        return NULL;
    }
    memcpy(v + 0x18, arg0, 0xC);
    *(s32 *)(v + 0x28) = 0;
    *(f32 *)(v + 0x24) = 0.0f;
    v[0x2C] = 8;
    v[0x2D] = 4;
    *(s32 *)(v + 0x30) = 0;
    *(f32 *)(v + 0x38) = 0.0f;
    *(f32 *)(v + 0x3C) = 0.0f;
    *(f32 *)(v + 0x40) = 0.0f;
    *(s32 *)(v + 0x10) = 1;
    *(s32 *)(v + 0x14) = 0;
    *(f32 *)(v + 0x34) = 1.0f;
    bzero(v + 0x48, 0x960);
    return v;
}

void func_1518E308(void *);
void func_1514EDF0(void *, s32);

void func_1518E4A0(void *arg0) {
    func_1518E308(arg0);
    func_1514EDF0(arg0, *(s32 *)((char *)arg0 + 0x18));
}

void func_1518E4CC(s32 arg0) {
    func_1518E4A0(arg0);
    func_15169804(arg0);
}

void func_1518E4F8(s32 arg0) {
    func_1518E4A0(arg0);
    func_15169824(arg0);
}

void func_1518E524(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5, u16 *arg6) {
    *arg1 = 2;
    if (func_150ADA20() & 1) {
        *arg1 |= 1;
    }
    switch (func_150ADA20() & 1) {
    case 0:
        *arg0 = 0x13;
        break;
    case 1:
        *arg0 = 0x14;
        break;
    }
    *arg2 = 0;
    *arg3 = 0;
    *arg4 = 0;
    *arg5 = 0xFF;
    *arg6 = 0x301;
}

void func_151429E0(u8, s32, s32, s32);

void func_1518E5D8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5, s16 *arg6) {
    if (func_150ADA20() & 1) {
        *arg1 |= 1;
    }
    *arg0 = 0x16;
    func_151429E0((func_150ADA20() & 1) ? 3 : 4, arg2, arg3, arg4);
    *arg5 = 0xC8;
    *arg6 = 0x401;
}

s32 func_1518D1C0();
extern char D_800A7460[];

s32 func_1518E66C(u8 *arg0) {
    func_1518D1C0(*(s32 *)(arg0 + 0x18), 3, 0, 0, arg0[0xC], arg0[1], D_800A7460);
    *(s16 *)(arg0 + 0x1E) = 0x80;
    *(s8 *)(arg0 + 0x21) = -1;
    return 0;
}

struct func_1518E6D4_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xC - 0x2];
    u8 unkC;
    u8 padD[0x18 - 0xD];
    s32 unk18;
    u8 pad1C[0x1E - 0x1C];
    s16 unk1E;
    u8 pad20;
    s8 unk21;
};
extern u8 D_800A749C[];
s32 func_1518D1C0();

s32 func_1518E6D4(struct func_1518E6D4_s *arg0) {
    func_1518D1C0(arg0->unk18, 4, 0, 0, arg0->unkC, arg0->unk1, D_800A749C);
    arg0->unk1E = 0x80;
    arg0->unk21 = -1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518EB10.s")

struct func_1518EF54_sub {
    u8 pad0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    u8 pad44[0x8];
    f32 unk4C;
};

struct func_1518EF54_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x110 - 0x4C];
    struct func_1518EF54_sub unk110;
};

s32 func_1518EF54(struct func_1518EF54_s *arg0) {
    struct func_1518EF54_sub *sub;
    f32 dx;
    f32 dy;
    f32 dz;

    sub = &arg0->unk110;
    sub->unk30 *= sub->unk40;
    sub->unk34 += sub->unk3C * D_800BE9A4;
    sub->unk38 *= sub->unk40;
    dx = sub->unk30 * D_800BE9A4;
    dy = sub->unk34 * D_800BE9A4;
    dz = sub->unk38 * D_800BE9A4;
    arg0->unk34 += dx;
    arg0->unk38 += dy;
    arg0->unk3C += dz;
    arg0->unk40 += dx;
    arg0->unk44 += dy;
    arg0->unk48 += dz;
    arg0->unk40 = arg0->unk34 + (arg0->unk40 - arg0->unk34) * sub->unk4C;
    arg0->unk44 = arg0->unk38 + (arg0->unk44 - arg0->unk38) * sub->unk4C;
    arg0->unk48 = arg0->unk3C + (arg0->unk48 - arg0->unk3C) * sub->unk4C;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F058.s")

struct func_1518F108_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x5C - 0x34];
    u8 unk5C;
    u8 pad5D[0x154 - 0x5D];
    f32 unk154;
    s16 unk158;
    s16 unk15A;
};

s32 func_1518F108(struct func_1518F108_s *arg0) {
    arg0->unk30 -= arg0->unk30 * arg0->unk154;
    arg0->unk2C -= arg0->unk2C * arg0->unk154;
    if (arg0->unk1C < arg0->unk158) {
        arg0->unk5C = arg0->unk1C * arg0->unk15A;
    }
    return 1;
}

struct func_1518F15C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x30 - 0x1E];
    f32 unk30;
    u8 pad34[0x5C - 0x34];
    u8 unk5C;
    u8 pad5D[0x154 - 0x5D];
    f32 unk154;
    s16 unk158;
    s16 unk15A;
};

s32 func_1518F15C(struct func_1518F15C_s *arg0) {
    arg0->unk30 -= arg0->unk30 * arg0->unk154;
    if (arg0->unk1C < arg0->unk158) {
        arg0->unk5C = arg0->unk1C * arg0->unk15A;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F1A0.s")

struct func_1518F384_sub {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
};

struct func_1518F384_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x110 - 0x34];
    struct func_1518F384_sub unk110;
};

extern f32 D_800A7B74;
extern f32 D_800A7B78;

s32 func_1518F384(struct func_1518F384_s *arg0) {
    struct func_1518F384_sub *p = &arg0->unk110;

    if (p->unk1C == 0) {
        p->unk8 = func_150ADA68() * (p->unk0 - p->unk4) + p->unk4;
        p->unk1C = 1;
    }
    if (p->unk1E == 0) {
        p->unk18 = func_150ADA68() * (p->unkC - p->unk10) + p->unk10;
        p->unk1E = 1;
    }
    arg0->unk30 += (p->unk18 - arg0->unk30) * D_800A7B74;
    arg0->unk2C += (p->unk8 - arg0->unk2C) * D_800A7B78;
    return 1;
}

struct func_1518F45C_s { s32 a; };
extern struct func_1518F45C_s D_800A74D4;
void func_1518F45C(void *arg0, u8 arg1) {
    struct func_1518F45C_s sp1C = D_800A74D4;
    func_15169260(&sp1C, 1, arg0, arg1);
}

struct func_1518F49C_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 unk1C;
};
struct func_1518F49C_s2 {
    s32 unk0;
    u8 unk4;
};
void func_1518F49C(struct func_1518F49C_s *arg0, struct func_1518F49C_s2 *arg1, u8 arg2) {
    s32 a;
    s32 b;
    u8 c;
    u8 d;

    func_15169850(arg1, arg2, &arg0->unk18, &arg0->unk1C, arg0);
    if (arg2 == 0x49) {
        a = arg0->unk18;
        b = arg1->unk0;
        c = arg0->unk1C;
        d = arg1->unk4;
        if (a == b || c == d) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

extern u8 *D_8008D630[];
s32 func_1518FDC4(void *, u8 *, u8);
s32 func_1518F5D0(void *, u8 *, s16, s8, s8, s8, u8, s32, u8, s32);

s32 func_1518F51C(void *arg0, u8 arg1, s16 arg2, s8 arg3, s8 arg4, s8 arg5, u8 arg6, s32 arg7, u8 arg8, s32 arg9) {
    s32 pad;
    u8 sp33;

    if (arg0 == NULL) {
        return 0;
    }
    if (func_1518FDC4(arg0, &sp33, arg1) == 0) {
        return 0;
    }
    return func_1518F5D0(arg0, D_8008D630[sp33] + arg1 * 0x50, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F5D0.s")

struct func_1518F7C4_sub {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x58 - 0xC];
    s8 unk58;
};

struct func_1518F7C4_s {
    u8 pad0[0x30];
    struct func_1518F7C4_sub unk30;
};

void func_1518F8E0(void *arg0);
extern s32 (*D_8008D67C[])(struct func_1518F7C4_s *);

s32 func_1518F7C4(struct func_1518F7C4_s *arg0) {
    struct func_1518F7C4_sub *p = &arg0->unk30;

    p->unk0 += (p->unk4 + func_150ADA68() * p->unk8) * D_800BE9A4;
    func_1518F8E0(arg0);
    if (p->unk58 != -1) {
        return D_8008D67C[p->unk58](arg0);
    }
    return 1;
}

struct func_1518F858_s {
    u8 pad[0x89];
    volatile s8 unk89;
};

extern void (*D_8008D680[])(struct func_1518F858_s *);

void func_1518F858(struct func_1518F858_s *arg0) {
    if (arg0->unk89 != -1) {
        D_8008D680[arg0->unk89](arg0);
    }
}

void func_1518F8E0(void *arg0);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} func_1518F89C_sub;

struct func_1518F89C_s {
    u8 pad0[0x30];
    func_1518F89C_sub unk30;
};

void func_1518F89C(struct func_1518F89C_s *arg0) {
    func_1518F89C_sub *p = &arg0->unk30;

    p->unk0 = func_150ADA68() * p->unk10 + p->unkC;
    func_1518F8E0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F8E0.s")

struct func_1518FC04_s {
    f32 x, y, z;
};

void func_1514BE20(void *arg0);

s32 func_1518FC04(void *arg0, struct func_1518FC04_s *arg1) {
    u8 *obj = *(u8 **)((u8 *)arg0 + 0x2C);
    *(struct func_1518FC04_s *)(obj + 0x34) = *arg1;
    func_1514BE20(obj);
    return 1;
}

struct func_1518FC44_s {
    f32 x, y, z;
};

void func_1514BF50(void *arg0);

s32 func_1518FC44(void *arg0, struct func_1518FC44_s *arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x2C);
    *(struct func_1518FC44_s *)(p + 0x34) = *arg1;
    func_1514BF50(p);
    return 1;
}

struct func_1518FC84_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u8 pad48[4];
    u8 unk4C;
};

void func_1518FC84(u8 *arg0, f32 *arg1) {
    u8 *obj;
    struct func_1518FC84_s *s;
    u8 *p;
    u8 *v0;

    obj = *(u8 **)(arg0 + 0x2C);
    if (*(u8 **)(arg0 + 0x30) == NULL) {
        func_1516972C((struct102 *)obj);
    } else {
        v0 = *(u8 **)(arg0 + 0x30);
        *(f32 *)(obj + 0x148) = *(f32 *)(v0 + 0x60) * (arg1[0] - *(f32 *)(arg0 + 0x34));
        *(f32 *)(obj + 0x14C) = *(f32 *)(v0 + 0x60) * (arg1[1] - *(f32 *)(arg0 + 0x38));
        *(f32 *)(obj + 0x150) = *(f32 *)(v0 + 0x60) * (arg1[2] - *(f32 *)(arg0 + 0x3C));
        s = (struct func_1518FC84_s *)(v0 + 0x30);
        p = obj + 0x110;
        *(f32 *)(p + 0x44) = func_150ADA68() * s->unk38 + s->unk34;
        *(f32 *)(p + 0x48) = s->unk3C;
        *(s16 *)(obj + 0x6C) = s->unk40;
        *(s16 *)(obj + 0x6E) = s->unk42;
        *(s16 *)(obj + 0x1C) = (u32)func_150ADA20() % (u32)(s->unk46 + 1) + s->unk44;
        if (s->unk4C & 1) {
            *(u8 *)(obj + 0x70) = 0x21;
        } else {
            *(u8 *)(obj + 0x70) = 0x20;
        }
        *(u8 *)(obj + 0x71) = 0x24;
        *(s32 *)(obj + 0x58) |= 0x08000001;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518FDC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519003C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519021C.s")

void func_15163DEC(void *, void *);
void func_15163F50(void *, void *);

void func_151903D0(u8 *arg0) {
    func_15163DEC(arg0, arg0 + 0x20);
    func_15163F50(arg0, arg0 + 0x18);
}

struct func_15190400_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 unk1C;
};

struct func_15190400_s2 {
    s32 unk0;
    u8 unk4;
};

void func_15190400(struct func_15190400_s *arg0, struct func_15190400_s2 *arg1, u8 arg2) {
    s32 a;
    s32 b;
    u8 c;
    u8 d;

    if (arg2 == 0) {
        a = arg0->unk18;
        b = arg1->unk0;
        c = arg0->unk1C;
        d = arg1->unk4;
        if ((a == b) || (c == d)) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

void func_15190454(s32 arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0x40);
    *(s32 *)(temp_v0 + 0x84) = 0;
}

void func_15190464(s32 arg0) {
    func_15190454(arg0);
    func_151617C4(arg0);
}

void func_15190490(s32 arg0) {
    func_15190454(arg0);
    func_151617E4(arg0);
}

struct func_151904BC_inner {
    u8 pad0[0x48];
    s32 unk48;
    u8 pad4C[0x54 - 0x4C];
    struct102 *unk54;
};
struct func_151904BC_s {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x30 - 0x14];
    struct func_151904BC_inner unk30;
};
void func_1518E298();
void func_1000FD38(void (*)(), struct func_151904BC_s *, s32);
void func_151D2B4C(s32);

void func_151904BC(struct func_151904BC_s *arg0) {
    struct func_151904BC_inner *sp18 = &arg0->unk30;

    if (sp18->unk54 != NULL) {
        func_1516972C(sp18->unk54);
    }
    func_1000FD38(func_1518E298, arg0, arg0->unk10);
    func_151D2B4C(sp18->unk48);
}

void func_15190518(void *arg0) {
    struct {
        void *ptr;
        u8 flag;
    } local;

    local.ptr = arg0;
    local.flag = *(u8 *) ((char *) arg0 + 0x3B);
    func_1516944C(0x3E, &local, 0x2A);
}

struct func_15190550_s {
    u8 pad[0x8A];
    u8 unk8A;
};
extern void (*D_8008D684[])(struct func_15190550_s *, s32, u8);
void func_151D33FC();

void func_15190550(struct func_15190550_s *arg0, s32 arg1, u8 arg2) {
    void (*fn)(struct func_15190550_s *, s32, u8);
    if (arg2 == 0x2A) {
        func_151D33FC(arg0, arg1);
    }
    fn = D_8008D684[arg0->unk8A];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

struct func_151905BC_t {
    s32 unk0;
    s32 unk4;
    struct127 *unk8;
};
struct func_151905BC_u {
    u8 pad0[0x46];
    s16 unk46;
    u8 pad48[0x84 - 0x48];
    u8 unk84;
};
struct func_151905BC_s {
    u8 pad0[0x10];
    u8 *unk10;
    u8 pad14[0x90 - 0x14];
    struct func_151905BC_t unk90;
};

s32 func_151905BC(struct func_151905BC_s *arg0) {
    struct func_151905BC_t *p = &arg0->unk90;
    struct func_151905BC_u *t;

    if ((arg0->unk90.unk4 += D_800BE9E4) >= arg0->unk90.unk0) {
        do {
            func_1505D024(arg0->unk10, 0x60021, 0, p->unk8 - gObjects);
        } while ((p->unk4 -= p->unk0) >= p->unk0);
    }
    t = *(struct func_151905BC_u **)(arg0->unk10 + 0x31C);
    if (t != NULL && t->unk84 == 0) {
        t->unk46 = 1000;
    }
    return 1;
}

void func_151906C4(s32 arg0) {
    s32 temp_v0 = *(s32 *)(*(s32 *)(arg0 + 0x10) + 0x31C);

    if (temp_v0 != 0) {
        *(u8 *)(temp_v0 + 0x1AC) = 0;
    }
}

void func_151906E0(void *arg0, s32 *arg1, u8 arg2) {
    void *temp_v0;

    temp_v0 = (char *)arg0 + 0x90;
    if (arg2 == 0x2D) {
        if (arg1[0] == *(s32 *)((char *)temp_v0 + 8)) {
            *(s32 *)((char *)temp_v0 + 8) = arg1[1];
        } else if (arg1[1] == *(s32 *)((char *)temp_v0 + 8)) {
            *(s32 *)((char *)temp_v0 + 8) = arg1[0];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519072C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190770.s")

void func_15191400(s32 arg0);

void func_15190840(s32 arg0) {
    func_15191400(arg0);
    func_15169804(arg0);
}

void func_15191400(s32 arg0);

void func_1519086C(s32 arg0) {
    func_15191400(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190898.s")

struct func_15190F9C_sub {
    u8 pad0[0x21];
    u8 unk21;
    u8 unk22;
    s8 unk23;
    s8 unk24;
    u8 pad25[0x28 - 0x25];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
};

struct func_15190F9C_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x110 - 0x34];
    struct func_15190F9C_sub unk110;
};

s32 func_15190F9C(struct func_15190F9C_s *arg0) {
    f32 f2;
    s32 pad;
    f32 f1;
    struct func_15190F9C_sub *p;

    p = &arg0->unk110;
    p->unk21 += p->unk23 * D_800BE9E4;
    p->unk22 += p->unk24 * D_800BE9E4;
    f1 = func_151423D8(p->unk21 - 0x40);
    f2 = func_151423D8(p->unk22 - 0x40);
    arg0->unk2C += ((p->unk28 + p->unk30 * f1) - arg0->unk2C) * 0.5f;
    arg0->unk30 += ((p->unk2C + p->unk34 * f2) - arg0->unk30) * 0.5f;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519108C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191520.s")

struct func_1519187C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
    u8 pad5D[0x124 - 0x5D];
    s16 unk124;
    s16 unk126;
};

s32 func_1519187C(struct func_1519187C_s *arg0) {
    s32 temp;

    if (arg0->unk1C < arg0->unk124) {
        temp = arg0->unk1C * arg0->unk126;
        if (temp < arg0->unk5C) {
            arg0->unk5C = temp;
        }
    }
    return 1;
}

struct func_151918BC_t {
    s32 unk0;
    u8 pad4[0x3B - 0x4];
    u8 unk3B;
    u8 pad3C[0x1D4 - 0x3C];
    s32 unk1D4;
};

struct func_151918BC_sub {
    struct func_151918BC_t *unk0;
    u8 unk4;
    u8 pad5;
    s16 unk6;
    u8 unk8;
};

struct func_151918BC_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xC - 0x2];
    u8 unkC;
    u8 unkD;
    s16 unkE;
    u8 pad10[0x28 - 0x10];
    struct func_151918BC_sub unk28;
    u8 pad34[0x2C - 0x34 + 0x8];
};

void func_15190770(struct func_151918BC_sub *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_151918BC(struct func_151918BC_s *arg0) {
    struct func_151918BC_sub *sub = &arg0->unk28;
    struct func_151918BC_t *t = sub->unk0;
    u8 done = 0;

    if (t->unk0 == 0) {
        done = 1;
    } else if (t->unk3B != sub->unk4) {
        done = 1;
    }
    if (!done && t->unk1D4 != 0) {
        if (arg0->unkD & 1) {
            sub->unk6 = arg0->unkE;
            sub->unk8 |= 1;
        } else {
            sub->unk6 = 300;
        }
        done = 1;
        func_15190770(sub, 0, arg0->unkC, arg0->unk1);
    }
    if (done) {
        func_1516972C((struct102 *)arg0);
    }
}

struct func_15191980_s {
    u8 pad0[0x10];
    s32 unk10;
    u8 unk14;
    u8 pad15;
    s16 unk16;
    u8 unk18;
};
struct func_15191980_s2 {
    s32 unk0;
    u8 unk4;
};
void func_15191980(struct func_15191980_s *arg0, struct func_15191980_s2 *arg1, u8 arg2) {
    if (arg2 == 0xD) {
        if (arg1->unk0 == arg0->unk10) goto a;
        if (arg1->unk4 != arg0->unk14) goto end;
    a:
        arg0->unk18 |= 1;
        arg0->unk16 = 100;
    end:;
    } else if (arg2 == 0xC || arg2 == 0x50 || arg2 == 0xE) {
        if (arg1->unk0 == arg0->unk10) goto b;
        if (arg1->unk4 == arg0->unk14) {
        b:
            func_1516972C((struct102 *) arg0);
        }
    } else if (arg2 == 0x4E) {
        func_1516972C((struct102 *) arg0);
    } else {
        func_15169850(arg1, arg2, &arg0->unk10, &arg0->unk14, arg0);
    }
}

typedef struct {
    s32 unk0;
    u8 unk4;
} func_15191A84_id;

struct func_15191A84_s {
    u8 pad0[0xD];
    u8 unkD;
    s16 unkE;
    u8 pad10[0x18];
    func_15191A84_id unk28;
};

void func_15191A84(struct func_15191A84_s *arg0, func_15191A84_id *arg1, u8 arg2) {
    func_15191A84_id *p = &arg0->unk28;

    if (arg2 == 0xC || arg2 == 0xE || arg2 == 0x50) {
        if (arg1->unk0 == p->unk0) {
            goto kill;
        }
        if (arg1->unk4 == p->unk4) {
kill:
            func_1516972C((struct102 *) arg0);
        }
        return;
    }
    if (arg2 == 0x4E) {
        func_1516972C((struct102 *) arg0);
        return;
    }
    if (arg2 == 0xD) {
        if (arg1->unk0 == p->unk0) {
            goto set;
        }
        if (arg1->unk4 != p->unk4) {
            goto end;
        }
set:
        arg0->unkD |= 1;
        arg0->unkE = 100;
end:
        return;
    }
    func_15169850(arg1, arg2, p, &p->unk4, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191B8C.s")
