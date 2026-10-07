#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151B2060_s {
    u8 *unk0;
    u8 unk4;
    struct127 *unk8;
    u8 unkC;
    u8 unkD;
    s32 unk10[3];
    s32 unk1C;
};

void func_151B2060(u8 *arg0) {
    struct260 *temp_v0;
    struct func_151B2060_s sp2C;

    if (arg0 == NULL) {
        return;
    }
    sp2C.unk0 = arg0;
    sp2C.unk4 = arg0[0x3B];
    sp2C.unk8 = func_15083E90(1);
    sp2C.unkC = 1;
    sp2C.unkD = 0;
    bzero(&sp2C.unk10, 0xC);
    sp2C.unk1C = 0;
    temp_v0 = func_151491F4(0x12C, -1, 0x16, 0, 0x12, (struct37 *)0x20, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->pad18[0x10], &sp2C, 0x20);
    }
}

struct func_151B2100_e {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x3B - 5];
    u8 unk3B;
};

struct func_151B2100_s {
    struct func_151B2100_e *unk0;
    u8 unk4;
    u8 pad5[3];
    struct func_151B2100_e *unk8;
    u8 unkC;
    u8 unkD;
};

void func_151B222C();
s32 func_151B22F4();
void func_151B2348();
void func_151B2690();

void func_151B2100(u8 *arg0) {
    struct func_151B2100_s *s = (struct func_151B2100_s *)(arg0 + 0x28);
    struct func_151B2100_e *a = s->unk0;
    struct func_151B2100_e *b = s->unk8;
    u8 old;

    if (a->unk0 == 0 || a->unk4 == 0xFF || a->unk3B != s->unk4 ||
        b->unk0 == 0 || b->unk4 == 0xFF || b->unk3B != s->unkC) {
        *(s16 *)(arg0 + 0xE) = -1;
        return;
    }
    old = s->unkD;
    s->unkD = func_151B22F4(arg0);
    if (s->unkD != old) {
        func_151B222C(arg0);
        if (s->unkD == 1) {
            func_151B2348(arg0);
        }
        if (s->unkD == 2 || s->unkD == 0) {
            func_151B2690(arg0);
        }
    }
}

void func_151B222C();

void func_151B220C(void) {
    func_151B222C();
}

struct func_151B222C_s {
    u8 pad0[0x10];
    struct102 *unk10[3];
    struct102 *unk1C;
};

void func_151B222C(u8 *arg0) {
    struct func_151B222C_s *s = (struct func_151B222C_s *)(arg0 + 0x28);
    u8 i;

    for (i = 0; i < 3; i++) {
        if (s->unk10[i] != NULL) {
            func_1516972C(s->unk10[i]);
        }
    }
    if (s->unk1C != NULL) {
        func_1516972C(s->unk1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B229C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B22C8.s")

struct func_151B22F4_s {
    u8 pad0[0x5C];
    s32 unk5C;
    u8 pad60[5];
    u8 unk65;
};

s32 func_151B22F4(struct127 **arg0) {
    struct127 *obj = arg0[10];
    struct func_151B22F4_s *p = (struct func_151B22F4_s *)arg0[12];
    s32 ret = 2;
    if ((p->unk65 == (obj - gObjects) + 1) && (p->unk5C == 1)) {
        return 1;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2690.s")

struct func_151B2950_s {
    u8 pad[0x178];
    s32 *unk178;
    u8 unk17C;
};

void func_151B2950(struct func_151B2950_s *arg0) {
    if (arg0->unk178 != NULL) {
        arg0->unk178[arg0->unk17C + 14] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2974.s")

void func_151B2EC4(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

struct func_151B2F04_s {
    s32 id;
    u8 b;
};

struct func_151B2F04_a1 {
    s32 x;
    s32 y;
    u8 bx;
    u8 by;
};

void func_151B2F04(void *arg0, struct func_151B2F04_a1 *arg1, u8 arg2) {
    struct func_151B2F04_s *p;

    p = (struct func_151B2F04_s *)((u8 *)arg0 + 0x28);
    if (arg2 == 0x2D) {
        if (p[0].id == arg1->x) {
            p[0].id = arg1->y;
            p[0].b = arg1->by;
        } else if (p[0].id == arg1->y) {
            p[0].id = arg1->x;
            p[0].b = arg1->bx;
        }
        if (p[1].id == arg1->x) {
            p[1].id = arg1->y;
            p[1].b = arg1->by;
        } else if (p[1].id == arg1->y) {
            p[1].id = arg1->x;
            p[1].b = arg1->bx;
        }
    }
}

void func_151B47D8(void *, void *, s32, u8);

void func_151B2FA0(u8 *arg0, s32 arg1, u8 arg2) {
    func_151B47D8(arg0, arg0 + 0x150, arg1, arg2);
}

struct func_151B2FD0_s {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0x4];
    struct func_151B2FD0_s *unk4C;
};
void func_151B2FD0(struct func_151B2FD0_s *arg0) {
    if (arg0->unk4C != NULL) {
        arg0->unk4C->unk44 = 0;
    }
}

void func_151B2FE8(s32 arg0) {
    func_151B2FD0(arg0);
    func_1514933C(arg0);
}

void func_151B3014(s32 arg0) {
    func_151B2FD0(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B3040.s")
