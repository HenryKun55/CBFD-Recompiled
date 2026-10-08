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

struct func_151A24A8_s {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x2F - 0x18];
    u8 unk2F;
    u8 pad30[2];
    s16 unk32;
    s16 unk34[3];
    u8 pad3A[5];
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 pad43;
    u16 unk44;
    u8 pad46[0x50 - 0x46];
    s16 unk50[14];
};

void func_151A24A8(struct func_151A24A8_s *arg0) {
    s16 *p;

    p = arg0->unk50;
    if (p[2] < arg0->unk34[2]) {
        arg0->unk3F = p[0] * (p[1] - arg0->unk34[2]);
    }
    if (p[5] < arg0->unk34[2]) {
        arg0->unk34[0] = arg0->unk34[1] = p[3] * (p[4] - arg0->unk34[2]);
    }
    if (arg0->unk34[2] < p[8]) {
        arg0->unk3F = p[9] * arg0->unk34[2];
    }
    if (arg0->unk34[2] < p[10]) {
        s16 temp = p[11] * D_800BE9E4;

        arg0->unk34[0] += temp;
        arg0->unk34[1] += temp;
    }
    if (arg0->unk34[2] < p[6]) {
        arg0->unk2F = 0x13;
        arg0->unk44 |= 0x101;
        arg0->unk40 = arg0->unk41 = arg0->unk42 = p[7] * arg0->unk34[2];
        arg0->unk14 = 0x520003;
    }
    if (arg0->unk34[2] < p[12]) {
        arg0->unk32 = p[13];
        p[12] = -9999;
    }
}

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

typedef struct { f32 x, y, z; } func_151A2F0C_v3;
struct func_151A2F0C_s {
    s32 unk0;
    s32 unk4;
    func_151A2F0C_v3 pos;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s32 unk34;
    s32 unk38;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    u8 unk42;
    u8 unk43;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    u8 unk4B;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    u8 unk4F;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u8 unk58;
    s32 unk5C;
    s32 unk60;
    s16 unk64;
    s16 unk66;
    s16 unk68;
    u8 unk6A;
    f32 unk6C;
    s8 unk70;
    s8 unk71;
    s8 unk72;
    s8 unk73;
};
struct func_151A2F0C_obj {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x38 - 0xD];
    f32 unk38;
    f32 unk3C;
    func_151A2F0C_v3 unk40;
    func_151A2F0C_v3 unk4C;
    u8 pad58[0x68 - 0x58];
    s32 unk68;
};
extern f32 D_800A8D30;
extern f32 D_800A8D34;
extern f32 D_800A8D38;

void func_151A2F0C(struct func_151A2F0C_obj *arg0) {
    struct func_151A2F0C_s sp1C;

    sp1C.unk0 = 8;
    sp1C.unk4 = 6;
    sp1C.pos = arg0->unk40;
    if (arg0->unk68 & 0x1000) {
        sp1C.pos.x += arg0->unk4C.x;
        sp1C.pos.y += arg0->unk4C.y;
        sp1C.pos.z += arg0->unk4C.z;
    }
    sp1C.unk14 = (arg0->unk38 + arg0->unk3C) * 0.5f * D_800A8D30;
    sp1C.unk18 = (arg0->unk38 + arg0->unk3C) * 0.5f * D_800A8D34;
    sp1C.unk2E = 0xFF;
    sp1C.unk30 = -0x40;
    sp1C.unk32 = 0x56;
    sp1C.unk34 = 3;
    sp1C.unk38 = 1;
    sp1C.unk3C = 0x11;
    sp1C.unk3E = 0x12;
    sp1C.unk40 = 1;
    sp1C.unk42 = 4;
    sp1C.unk43 = 2;
    sp1C.unk44 = 3;
    sp1C.unk45 = 0xFF;
    sp1C.unk46 = 0xC8;
    sp1C.unk47 = 0xC8;
    sp1C.unk48 = 0xFF;
    sp1C.unk4A = 0x37;
    sp1C.unk4B = 0x37;
    sp1C.unk4D = 0xFF;
    sp1C.unk4E = 0xFF;
    sp1C.unk4F = 0xFF;
    sp1C.unk50 = 0xFF;
    sp1C.unk55 = 0xFF;
    sp1C.unk2C = 0;
    sp1C.unk49 = 0;
    sp1C.unk4C = 0;
    sp1C.unk51 = 0;
    sp1C.unk52 = 0;
    sp1C.unk53 = 0;
    sp1C.unk54 = 0;
    sp1C.unk56 = 0;
    sp1C.unk57 = 1;
    sp1C.unk58 = 0x24;
    sp1C.unk5C = 0x200005;
    sp1C.unk60 = 0x60600;
    sp1C.unk64 = 7;
    sp1C.unk66 = 0x24;
    sp1C.unk68 = 1;
    sp1C.unk6A = 0;
    sp1C.unk70 = -1;
    sp1C.unk71 = 0;
    sp1C.unk72 = -1;
    sp1C.unk73 = -1;
    sp1C.unk1C = D_800A8D38;
    sp1C.unk20 = 0.0f;
    sp1C.unk24 = 8.0f;
    sp1C.unk28 = 10.0f;
    sp1C.unk6C = 1.0f;
    func_15152B38(&sp1C, arg0->unkC, arg0->unk1, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A3150.s")
