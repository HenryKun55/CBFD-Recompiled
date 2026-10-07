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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E3C4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E5D8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518EF54.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F384.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F7C4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518FC84.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151905BC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190F9C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151918BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191B8C.s")
