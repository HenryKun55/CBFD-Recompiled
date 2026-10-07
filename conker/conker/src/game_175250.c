#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct func_15147DA0_s {
    s32 w[8];
} func_15147DA0_s;

void *func_15147A80();

void *func_15147DA0(s32 *arg0, void *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, func_15147DA0_s *arg11, s32 arg12, u8 arg13, s32 arg14) {
    void *temp_v0;
    u8 *temp_a0;

    arg0[4] = 1;
    temp_v0 = func_15147A80(arg0, arg2 + 0x48, 0x14, 1, 0, 1, arg9, arg10, arg12, arg13, arg14);
    if (temp_v0 == NULL) {
        return NULL;
    }
    temp_a0 = *(u8 **)((u8 *)temp_v0 + 0x98);
    memcpy(temp_a0, arg1, 0x20);
    temp_a0[0x20] = arg3;
    temp_a0[0x21] = arg4;
    temp_a0[0x22] = arg5;
    temp_a0[0x23] = arg6;
    temp_a0[0x24] = arg7;
    temp_a0[0x25] = arg8;
    *(func_15147DA0_s *)(temp_a0 + 0x28) = *arg11;
    return temp_v0;
}

extern s32 (*D_8008A3E0[])();
extern s32 (*D_8008A3F8[])();
extern void (*D_8008A42C[])();

typedef struct { f32 x, y, z; } func_15147EB8_v;
typedef struct { func_15147EB8_v v; f32 pad[2]; } func_15147EB8_e;
typedef struct func_15147EB8_s {
    u8 pad0[0x18];
    u8 unk18;
    u8 pad19[2];
    u8 unk1B;
    s16 unk1C;
    s16 unk1E;
    u8 unk20;
    u8 unk21;
    u8 unk22;
} func_15147EB8_s;

s8 func_15147EB8(u8 *arg) {
    func_15147EB8_s *s;
    s8 fail;
    u8 *arg0;
    u8 *p;
    s16 v;
    s32 ok;
    s32 t;

    arg0 = arg;
    s = *(func_15147EB8_s **)(arg0 + 0x98);
    fail = 0;
    if (s->unk20 != 0) {
        if (D_8008A3E0[s->unk20]() == 0) {
            fail = 1;
        }
    }
    if (s->unk21 != 0 && !fail) {
        if (D_8008A3F8[s->unk21]() == 0) {
            fail = 1;
        }
    }
    if ((s->unk18 & 0x40) && !fail) {
        v = *(s16 *)(arg0 + 0x1C);
        if (v < s->unk1C) {
            t = v * s->unk1E;
            if (t < s->unk1B) {
                s->unk1B = t;
            }
        }
    }
    ok = (fail == 0);
    if (fail) {
        fail = 0;
        if (s->unk22 != 0) {
            D_8008A42C[s->unk22]();
        }
    }
    p = *(u8 **)(arg0 + 0x94);
    if (*(s8 *)(arg0 + 0x2C) > 0) {
        *(func_15147EB8_v *)(arg0 + 0x54) = ((func_15147EB8_e *)p)[*(s8 *)(arg0 + 0x2D)].v;
    } else {
        *(f32 *)(arg0 + 0x54) = 0.0f;
        *(f32 *)(arg0 + 0x58) = 0.0f;
        *(f32 *)(arg0 + 0x5C) = 0.0f;
    }
    return ok;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_1514803C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_151488C4.s")

struct func_15148AF4_e {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u8 pad10[4];
};
struct func_15148AF4_v {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    f32 unk10;
};
struct func_15148AF4_s {
    u8 pad0[0x25];
    u8 unk25;
    u8 pad26[7];
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x94 - 0x2F];
    struct func_15148AF4_e *unk94;
    struct func_15148AF4_v *unk98;
};

s32 func_15148AF4(struct func_15148AF4_s *arg0) {
    struct func_15148AF4_e *arr = arg0->unk94;
    struct func_15148AF4_v *v = arg0->unk98;
    s32 i = arg0->unk2E;

    do {
        i--;
        if (i < 0) {
            i = arg0->unk25 - 1;
        }
        arr[i].w -= v->unk10 * D_800BE9A4;
        arr[i].x += v->unk4 * D_800BE9A4;
        arr[i].y += arr[i].w * D_800BE9A4;
        arr[i].z += v->unkC * D_800BE9A4;
    } while (i != arg0->unk2D);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148BA4.s")

struct func_15148DE0_e { u8 pad0[0x10]; u16 unk10; u8 pad12[2]; };
struct func_15148DE0_s {
    u8 pad0[0x25];
    u8 unk25;
    u8 pad26[6];
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x94 - 0x2F];
    struct func_15148DE0_e *unk94;
    u8 *unk98;
};

s32 func_15148DE0(struct func_15148DE0_s *arg0) {
    u8 *flags;
    struct func_15148DE0_e *ents;
    s32 i;
    u16 step;
    u16 v;

    if (arg0->unk2C >= 3) {
        arg0->unk2C--;
        ents = arg0->unk94;
        flags = arg0->unk98;
        i = arg0->unk2D;
        step = 0x1000 / arg0->unk2C;
        v = (flags[0x18] & 0x20) ? 0x1000 : 0;
        arg0->unk2E--;
        if (arg0->unk2E < 0) {
            arg0->unk2E = arg0->unk25 - 1;
        }
        while (i != arg0->unk2E) {
            ents[i].unk10 = v;
            if (flags[0x18] & 0x20) {
                v -= step;
            } else {
                v += step;
            }
            i++;
            if (i == arg0->unk25) {
                i = 0;
            }
        }
        return 1;
    }
    return 0;
}

struct func_15148EF8_s {
    u8 pad0[0x98];
    u8 *unk98;
};

s32 func_15148EF8(struct func_15148EF8_s *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_v1 = arg0->unk98;

    temp_v1[0x20] = 4;
    return 1;
}

struct func_15148F1C_s {
    f32 pos[3];
    s16 unk0C;
    s16 unk0E;
    s32 unk10;
    u8 pad14;
    u8 unk15;
};

struct func_15148F1C_s2 {
    f32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s32 unk1C;
};

void func_15148F1C(u8 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, s16 arg8, f32 arg9, f32 arg10, u8 arg11) {
    f32 d;
    struct func_15148F1C_s s1;
    struct func_15148F1C_s2 s2;
    f32 a;
    f32 b;
    f32 c;
    f32 t;
    func_15147DA0_s s3;

    a = func_151423D8(arg6);
    b = func_151423D8(arg6 - 0x40);
    c = func_151423D8(arg5);
    d = func_151423D8(arg5 - 0x40);
    s1.unk10 = 1;
    s1.unk0E = 1;
    s2.unk1A = 0xFF;
    s2.unk18 = 8;
    s2.unk19 = arg0;
    if (arg0 == 10) {
        s2.unk18 = 0x28;
    }
    t = arg7 * a;
    s1.pos[0] = arg1;
        s1.pos[1] = arg2;
s1.pos[2] = arg3;
    s2.unk00 = arg9;
    s2.unk10 = arg10;
    s2.unk1B = 0xFF;
    s1.unk15 = arg4 + 3;
    s1.unk0C = arg8;
    s2.unk04 = t * d;
    s2.unk08 = -arg7 * b;
    s2.unk0C = t * c;
    s3.w[0] = 0;
    s3.w[1] = 1;
    s3.w[2] = 0x160600;
    s3.w[3] = 3;
    s3.w[4] = 0x10;
    s3.w[5] = 0x80;
    s3.w[6] = 0x20;
    ((u8 *)&s3.w[7])[0] = 0;
    ((u8 *)&s3.w[7])[1] = 9;
    func_15147DA0((s32 *)&s1, &s2, NULL, 1, 0, 0, 0, 0, 0, 0, 0, &s3, 0, arg11, 1);
}

struct func_151490C8_s { u8 pad[0x1B]; u8 unk1B; };
s32 func_151490C8(u8 *arg0) {
    struct func_151490C8_s *temp_v0 = *(struct func_151490C8_s **)(arg0 + 0x98);
    s32 v = *(s16 *)(arg0 + 0x1C) * 8;
    u8 b;
    if (v >= 0x100) {
        v = 0xFF;
    }
    temp_v0->unk1B = b = v;
    if (b < 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15149104.s")
