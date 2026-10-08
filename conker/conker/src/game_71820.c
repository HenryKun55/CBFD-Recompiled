#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800CBD9C;

void func_15044370(void) {
    D_800CBD9C = 0;
}

struct func_15044380_s {
    u8 pad0[0xF8];
    s32 unkF8;
    u8 padFC[0x275 - 0xFC];
    u8 unk275;
};
extern f32 D_800CBDF4;
extern f32 D_800CBDF8;
extern u8 D_800CBDD3;
extern u8 D_80089120[];
void func_15044660(struct func_15044380_s *, f32, f32, f32);
s32 func_150AB1F0(f32, f32, f32, struct func_15044380_s *, s32);
void func_150AC3E4(f32, f32, f32, struct func_15044380_s *, s32);

s32 func_15044380(f32 arg0, f32 arg1, f32 arg2, struct func_15044380_s *arg3, s32 arg4, s32 arg5) {
    s32 i;
    s32 sum;
    s32 saved;

    D_800CBDF4 = -32768.0f;
    D_800CBDF8 = -32768.0f;
    sum = 0;
    arg3->unk275 = 0;
    func_15044660(arg3, arg0, arg1, arg2);
    saved = D_800CBDD3;
    for (i = 3; i >= 0; i--) {
        if (D_80089120[i] != 1) continue;
        if ((i == 3) && (arg3->unkF8 & 0x200)) continue;
        func_1510F800(i);
        if (D_800DBE62) {
            sum += func_150AB1F0(arg0, arg1, arg2, arg3, arg4);
        }
    }
    if (arg5) {
        for (i = 0; i < 3; i++) {
            if (D_80089120[i] != 1) continue;
            func_1510F800(i);
            if (D_800DBE62) {
                func_150AC3E4(arg0, arg1, arg2, arg3, 0);
            }
        }
    }
    func_1510F800(0);
    D_800CBDD3 = saved;
    return sum;
}

void func_1504452C(u8 **arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    s32 i;
    f32 x, y, z;
    s16 *p;

    for (i = 0; i < 3; i++) {
        p = (s16 *)(arg0[i] + arg7);
        x = p[0] - arg4;
        y = p[1] - arg5;
        z = p[2] - arg6;
        arg1[i * 3 + 0] = (x * arg3) + (z * arg2);
        arg1[i * 3 + 1] = y;
        arg1[i * 3 + 2] = (z * arg3) - (x * arg2);
    }
}

void func_15044658(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044660.s")

struct func_150448D0_s {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
    s32 unk18;
    s32 unk1C;
};

struct func_150448D0_s *func_15044964(s32, s32, s32, s32, s32, s32, s32, s32);

struct func_150448D0_s *func_150448D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    struct func_150448D0_s *temp_v0;

    temp_v0 = func_15044964(0x20, 1, arg0, arg1, arg2, 0, 0, 0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    temp_v0->unk10 = arg3;
    temp_v0->unk12 = arg4;
    temp_v0->unk14 = arg5;
    temp_v0->unk16 = arg6;
    temp_v0->unk18 = arg7;
    temp_v0->unk1C = arg8;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044964.s")

struct func_15044A28_s {
    struct func_15044A28_s *next;
    s16 unk4;
    u8 pad6[6];
    u8 unkC;
    u8 unkD;
    u8 unkE;
};

extern s32 (*D_80085E80[])(struct func_15044A28_s *);
extern void (*D_80085E8C[])(void);

void func_15044A28(void) {
    struct func_15044A28_s *prev;
    struct func_15044A28_s *p;
    struct func_15044A28_s *next;
    s32 t;
    s32 e;
    s32 c;

    prev = NULL;
    p = *(struct func_15044A28_s **)&D_800CBE00;
    while (p != NULL) {
        e = p->unkE;
        c = p->unkC;
        next = p->next;
        if (e == 0) {
            if (D_80085E80[c](p)) {
                D_80085E8C[p->unkD]();
            }
        } else {
            t = e - D_800BE9E4;
            if (t < 0) {
                t = 0;
            }
            p->unkE = t;
        }
        t = p->unk4;
        if (t != -1) {
            t = t - D_800BE9E4;
            if (t <= 0) {
                if (prev == NULL) {
                    *(struct func_15044A28_s **)&D_800CBE00 = p->next;
                } else {
                    prev->next = p->next;
                }
                func_100043B4(p, 2);
            } else {
                p->unk4 = t;
                prev = p;
            }
        } else {
            prev = p;
        }
        p = next;
    }
}

struct func_15044B78_s {
    u8 pad0[6];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
};

s32 func_15044B78(struct func_15044B78_s *arg0) {
    f32 pad2;
    f32 s;
    f32 c;
    f32 dx, dy, dz;
    f32 pad;
    f32 rz;
    struct126 *p;
    s32 h, w, d;

    p = gObjects[0].unk31C;
    h = (s16)p->unk114 >> 1;
    w = (s16)p->unk116;
    d = (s16)p->unk118;
    dx = gObjects[0].x_position - arg0->unk6;
    dy = (gObjects[0].y_position - arg0->unk8) + h;
    dz = gObjects[0].z_position - arg0->unkA;
    s = func_15048A40(arg0->unk16);
    c = func_150489B0(arg0->unk16);
    rz = (dz * c) + (dx * s);
    dx = (dx * c) - (dz * s);
    if (fabsf(dy) < arg0->unk14 + h && fabsf(dx) < arg0->unk12 + w && fabsf(rz) < arg0->unk10 + d) {
        return 1;
    }
    return 0;
}

struct func_15044CE4_s {
    u8 pad0[6];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[2];
    s16 *unk18;
    s16 *unk1C;
};

void func_15044CE4(struct func_15044CE4_s *arg0) {
    s16 temp;
    arg0->unk6 = arg0->unk18[0];
    arg0->unk8 = arg0->unk18[1];
    arg0->unkA = arg0->unk18[2];
    temp = arg0->unk1C[0] / 32;
    arg0->unk10 = temp;
    arg0->unk12 = temp;
    arg0->unk14 = temp;
    func_15044B78(arg0);
}

void func_1505D1C4(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6, s32 arg7);

s32 func_15044D40(s16 *arg0) {
    func_1505D1C4(arg0[3], arg0[4], arg0[5], arg0[8], 0xFF, 0, 0, 0);
    return 0;
}

void func_15044DA0(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0)) {
        func_1505D024(gObjects, 5, gObjects[0].unk7A, -1);
    }
}

void func_15044DE8(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0) && (D_800C35EA != 1)) {
        func_1505D024(&gObjects[0], 4, gObjects[0].unk7A, -1);
    }
}

void func_15044E40(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0)) {
        func_1505D024(gObjects, 0x40, gObjects[0].unk7A, -1);
    }
}

void func_15044E88(void) {
    if ((gObjects->stunned == 0) && (gObjects->immune == 0)) {
        func_1505D024(gObjects, 1, gObjects->unk7A, -1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150450CC.s")

s32 func_1504530C(s32 arg0, s32 arg1, s32 arg2) {
    switch (func_150470B0(arg0, arg1, arg2)) {
    case 0:
        return func_15044ED0(arg0, arg1, arg2);
    case 1:
        return 0;
    case 2:
        return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045384.s")

s32 func_150A4FA0(s32, s32);
extern f32 D_80098D4C;

struct func_1504554C_s {
    s32 unk0;
    s32 *unk4;
    s32 unk8;
    s32 padC;
};

typedef struct {
    s16 x, y, z;
} func_1504554C_v;

typedef struct {
    f32 unk0;
    func_1504554C_v unk4[3];
    u8 pad16[2];
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    s32 unk20;
} func_1504554C_t;

s32 func_1504554C(f32 *arg0, f32 arg1, func_1504554C_t *arg2) {
    s32 *p;
    s32 found;
    func_1504554C_v *v;
    f32 h;
    s32 i;
    s32 j;
    s32 n;
    s32 base;

    if (arg0[1] < arg1) {
        arg2->unk1C &= ~2;
        return 0;
    }
    arg2->unk0 = D_80098D4C;
    found = -1;
    func_1510F800(3);
    n = func_150A4FA0(arg0[0], arg0[2]);
    for (i = 0; i < n; i++) {
        h = ((struct func_1504554C_s *)&D_800D3300)[i].unk0 * 0.00390625f;
        if (h <= arg0[1] && arg2->unk0 < h) {
            found = i;
            arg2->unk0 = h;
        }
    }
    if (found != -1) {
        p = ((struct func_1504554C_s *)&D_800D3300)[found].unk4;
        base = ((struct func_1504554C_s *)&D_800D3300)[found].unk8;
        for (j = 0; j < 3; j++) {
            v = (func_1504554C_v *)(p[j] + base);
            {
                func_1504554C_v *d = &arg2->unk4[j];
                d->x = v->x;
                d->y = v->y;
                d->z = v->z;
            }
        }
        arg2->unk18 = 0;
        arg2->unk1C |= 6;
        arg2->unk1D = 4;
        arg2->unk20 = 0;
        if (arg1 <= arg2->unk0) {
            arg2->unk1C |= 2;
            return 1;
        }
        return 0;
    }
    arg2->unk1C &= ~2;
    return 0;
}

s32 func_150A6500(s16 arg0, s16 arg1, s32 arg2, u16 arg3);

void func_15045714(f32 *arg0, u16 arg1, s32 *arg2, s32 arg3) {
    func_1510F800(2);
    *arg2 = func_150A6500(arg0[0], arg0[2], arg3, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045780.s")

u8 func_15047004(void *arg0, f32 arg1, f32 *arg2);
u8 func_15045780(void *arg0, u16 arg1, f32 arg2, f32 *arg3);

u8 func_15045800(void *arg0, u16 arg1, f32 arg2, f32 *arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_15045780(arg0, arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150461D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150466F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504697C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046D00.s")

u8 func_15047004(void *arg0, f32 arg1, f32 *arg2);
u8 func_15046D00(void *arg0, u16 arg1, f32 arg2, f32 *arg3);

u8 func_15046F84(void *arg0, u16 arg1, f32 arg2, f32 *arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_15046D00(arg0, arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    }
}

s32 func_150A3FC4(f32, f32, s32, f32 *, f32 *);

u8 func_15047004(void *arg0, f32 arg1, f32 *arg2) {
    f32 sp24;

    if ((((u8 *)arg2)[0x1C] & 4) && func_150A3FC4(((f32 *)arg0)[0], ((f32 *)arg0)[2], 0, arg2 + 1, &sp24)) {
        if (arg1 <= sp24 && sp24 <= ((f32 *)arg0)[1]) {
            arg2[0] = sp24;
            ((u8 *)arg2)[0x1C] |= 2;
            return 2;
        }
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150470B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504715C.s")

struct func_150472C0_s18 { s16 v[9]; };
struct func_150472C0_dst {
    f32 unk0;
    struct func_150472C0_s18 unk4;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    s32 unk20;
};
struct func_150472C0_src {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10[0x34];
    struct func_150472C0_s18 unk44;
    u8 pad56[3];
    u8 unk59;
    s32 unk5C;
    s32 unk60;
};

void func_150472C0(struct func_150472C0_dst *arg0, struct func_150472C0_src *arg1) {
    arg0->unk0 = arg1->unkC;
    arg0->unk4 = arg1->unk44;
    arg0->unk18 = arg1->unk60;
    arg0->unk1C = ((arg1->unk59 == 1) ? 1 : 0) | ((arg1->unk59 == 1) ? 2 : 0) | ((arg1->unk59 == 1) ? 4 : 0);
    arg0->unk1D = (arg1->unk59 == 1) ? 1 : 0;
    arg0->unk20 = arg1->unk5C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047390.s")

void func_15047390(float mf[4][4], float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp);

void func_15047688(Mtx *m, float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp) {
    float mf[4][4];

    func_15047390(mf, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp);
    guMtxF2L(mf, m);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047B80.s")
