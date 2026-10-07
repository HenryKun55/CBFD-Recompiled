#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519EF90.s")

struct func_1519F108_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_1519F108(void *arg0) {
    struct func_1519F108_s *p;
    u8 **q;

    q = *(u8 ***)((u8 *)arg0 + 0x98);
    if (*q != NULL) {
        p = (struct func_1519F108_s *)(*q + 0x58);
        if (*(s32 *)((u8 *)arg0 + 0x20) == 6) {
            p->unk0 = 0;
        }
        if (*(s32 *)((u8 *)arg0 + 0x20) == 7) {
            p->unk8 = 0;
        }
    }
    func_151478F4(arg0);
}

void func_15147928(void *arg0);

void func_1519F168(void *arg0) {
    s32 *v;
    s32 *p;

    v = *(s32 **)((u8 *)arg0 + 0x98);
    if (*v != 0) {
        p = (s32 *)(*v + 0x58);
        if (*(s32 *)((u8 *)arg0 + 0x20) == 6) {
            p[0] = 0;
        }
        if (*(s32 *)((u8 *)arg0 + 0x20) == 7) {
            p[2] = 0;
        }
    }
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F1C8.s")

struct func_1519F3B8_s {
    void *a;
    s32 b;
    void *c;
    s32 d;
};

void *func_1519F1C8(void *arg0, s32 arg1);

void func_1519F3B8(void *arg0) {
    struct func_1519F3B8_s *s;

    s = (struct func_1519F3B8_s *)((u8 *)arg0 + 0x58);
    s->a = func_1519F1C8(arg0, 6);
    s->b = 0;
    s->c = func_1519F1C8(arg0, 7);
    s->d = 0;
}

struct func_1519F400_s {
    void *a;
    void *b;
    void *c;
    void *d;
};

void func_1519F48C(u8 *arg0);
void func_151A0928(u8 *arg0);

void func_1519F400(void *arg0) {
    struct func_1519F400_s *s;

    s = (struct func_1519F400_s *)((u8 *)arg0 + 0x58);
    if (s->a != NULL) {
        func_1519F48C(s->a);
    }
    if (s->c != NULL) {
        func_1519F48C(s->c);
    }
    if (s->b != NULL) {
        func_151A0928(s->b);
        func_1516972C(s->b);
    }
    if (s->d != NULL) {
        func_151A0928(s->d);
        func_1516972C(s->d);
    }
}

struct func_1519F48C_s {
    struct func_1519F48C_s *unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    u8 padC[0x58 - 0xC];
};

void func_1519F48C(u8 *arg0) {
    struct func_1519F48C_s *temp_v0;
    struct func_1519F48C_s *temp_a1;

    temp_v0 = *(struct func_1519F48C_s **)(arg0 + 0x98);
    if (temp_v0->unk0 != NULL) {
        temp_a1 = temp_v0->unk0;
        temp_a1++;
        if (*(s32 *)(arg0 + 0x20) == 6) {
            temp_a1->unk0 = NULL;
        }
        if (*(s32 *)(arg0 + 0x20) == 7) {
            temp_a1->unk8 = 0;
        }
        temp_v0->unk0 = NULL;
    }
    *(u8 *)(arg0 + 0x30) = 0;
    *(u16 *)(arg0 + 0x1E) &= ~2;
    temp_v0->unk4 |= 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519FE6C.s")

void func_151A0928(u8 *arg0);

struct func_151A084C_s {
    u8 *unk0;
    u8 unk4;
};

void func_151A084C(u8 *arg0) {
    u8 *temp_v0;
    s32 *t;
    u8 *temp_a1;
    u8 flag;
    struct func_151A084C_s *p;

    temp_v0 = *(u8 **)(arg0 + 0x28);
    flag = 0;
    p = (struct func_151A084C_s *)(arg0 + 0x28);
    temp_a1 = *(u8 **)(temp_v0 + 0x18);
    t = (s32 *)(temp_v0 + 0x58);
    if (*(s32 *)temp_a1 == 0) {
        flag = 1;
    }
    if (p->unk0[0x1C] != temp_a1[0x3B]) {
        flag = 1;
    }
    if (flag) {
    } else if (*(s32 *)(temp_a1 + 0x1D4) != 0) {
        flag = 1;
        temp_v0 = func_1519F1C8(p->unk0, p->unk4);
        if (p->unk4 == 6) {
            t[0] = (s32)temp_v0;
        } else {
            t[2] = (s32)temp_v0;
        }
    }
    if (flag) {
        func_151A0928(arg0);
        *(s16 *)(arg0 + 0xE) = -1;
        arg0[0xD] |= 1;
    }
}

void func_151A0928(u8 *arg0) {
    s32 *p = (s32 *)(*(u8 **)(arg0 + 0x28) + 0x58);
    if (arg0[0x2C] == 6) {
        p[1] = 0;
    } else {
        p[3] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A09B4.s")

struct func_151A0A10_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    f32 unk10;
};

extern s32 func_1510F8CC(s32);
extern void *memcpy(void *, const void *, u32);

void func_151A0A10(u8 *arg0, s16 arg1, u8 arg2, s32 arg3) {
    u8 *temp_v0;
    struct func_151A0A10_s sp38;

    if (arg0 != NULL) {
        sp38.unk0 = *(f32 *)(arg0 + 0x14);
        sp38.unk8 = *(f32 *)(arg0 + 0x1C);
        if (D_800C35EA != 1) {
            sp38.unk4 = *(f32 *)(arg0 + 0x180);
            sp38.unk10 = 0.0f;
            switch (func_1510F8CC(*(s32 *)(arg0 + 0x184))) {
            case 10:
                sp38.unkC = 0;
                break;
            case 15:
            case 17:
                sp38.unkC = 1;
                break;
            default:
                sp38.unkC = 0;
                break;
            }
            temp_v0 = (u8 *)func_151491F4(arg1, -1, 1, 1, 0, (struct37 *)0x14, arg2, arg3);
            if (temp_v0 != NULL) {
                memcpy(temp_v0 + 0x28, &sp38, 0x14);
            }
        }
    }
}

extern f32 D_800A8D10;
void func_1514C678(f32, f32, f32, f32, s32, s32, s32, s32, s32, f32, s32, s32);

struct func_151A0AF8_sub {
    f32 x;
    f32 y;
    f32 z;
    u8 unkC;
    u8 padD[3];
    f32 unk10;
};

struct func_151A0AF8_s {
    u8 pad0[0xC];
    u8 unkC;
    u8 padD[0x28 - 0xD];
    struct func_151A0AF8_sub unk28;
};

void func_151A0AF8(struct func_151A0AF8_s *arg0) {
    struct func_151A0AF8_sub *p;

    arg0->unk28.unk10 += D_800A8D10 * D_800BE9A4;
    p = &arg0->unk28;
    while (p->unk10 > 1.0f) {
        func_1514C678(p->x, p->y, p->z, func_150ADA68() * 25.0f + 15.0f,
                      0, 0xFF, 5, 4, p->unkC, 0.0f, 0, arg0->unkC);
        p->unk10 -= 1.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1010.s")

void func_151A11CC(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A11E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A175C.s")

typedef struct { f32 x, y, z; } func_151A18DC_v3;
struct func_151A18DC_s {
    func_151A18DC_v3 pos;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
};

void func_151A18DC(u8 *arg0) {
    struct260 *temp_v0;
    struct func_151A18DC_s sp34;

    sp34.pos = *(func_151A18DC_v3 *)(arg0 + 0x28);
    sp34.unkC = *(f32 *)(arg0 + 0x34);
    sp34.unk10 = 0.0f;
    sp34.unk14 = *(f32 *)(arg0 + 0x38);
    sp34.unk18 = *(s16 *)(arg0 + 0x3E);
    sp34.unk1A = *(s16 *)(arg0 + 0x40);
    sp34.unk1C = *(s16 *)(arg0 + 0x42);
    sp34.unk1E = *(s16 *)(arg0 + 0x44);
    temp_v0 = func_151491F4(*(s16 *)(arg0 + 0x3C), -1, 3, 1, 0, (struct37 *)0x20, arg0[0xC], arg0[1]);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp34, 0x20);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A24A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A25E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A26EC.s")

struct func_151A2960_s {
    s16 unkB0;
    s16 unkB2;
    s16 unkB4;
    s8 unkB6;
};

extern void (*D_8008F8E0[])(u8 *, s32);

void func_151A2960(u8 *arg0, s32 arg1) {
    struct func_151A2960_s *s = (struct func_151A2960_s *)(arg0 + 0xB0);

    if (*(s16 *)(arg0 + 0x1A) < s->unkB0) {
        arg0[0x2C] = *(s16 *)(arg0 + 0x1A) * s->unkB2;
    }
    if (D_800BE616 == 0 && s->unkB4 != -1 && s->unkB6 != -1 && s->unkB4 >= *(s16 *)(arg0 + 0x1A)) {
        D_8008F8E0[s->unkB6](arg0, s->unkB4);
        s->unkB4 = -1;
    }
    func_1513170C(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2A14.s")

void func_151A2C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, s16 argC, s16 argD, s16 argE, s16 argF, s16 arg10, s16 arg11, s8 arg12, u8 arg13, s32 arg14, s32 arg15);

void func_151A2AD4(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, s16 arg9, s16 argA, s16 argB, s16 argC, s16 argD, s16 argE, s8 argF, u8 arg10, s32 arg11) {
    func_151A2C24(arg0, arg1, 0, 0, 0.0f, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, argD, argE, argF, arg10, arg11, 0);
}

void func_151A2B84(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5) {
    f32 t = 1.0f - arg4;
    arg5[0] = arg0[0] * t;
    arg5[1] = arg0[1] * t;
    arg5[2] = arg0[2] * t;
}

void func_15143794(s16 arg0, s16 arg1, f32 arg2, void *arg3);

void func_151A2BD0(s32 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, void *arg5) {
    func_15143794(arg1, arg2, (1.0f - arg4) * arg3, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A3150.s")
