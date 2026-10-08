#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800C3E90;
extern s32 func_1502DB20(s32);

s32 func_15184150(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 id;
    struct127 *obj;
    s32 n;
    s32 i;
    f32 dx, dy, dz;
    f32 (*m)[4][4];

    obj = &gObjects[arg0];
    id = obj->id;
    *arg3 = 0.0f;
    *arg2 = 0.0f;
    *arg1 = 0.0f;
    if (obj->unk1D4 == NULL || D_800C3E90 != 0) {
        return 0;
    }
    n = func_1502DB20(id);
    for (i = 0; i < n; i++) {
        m = (f32 (*)[4][4])obj->unk1D4;
        dx = m[i][3][0];
        dy = m[i][3][1];
        dz = m[i][3][2];
        dx -= obj->x_position;
        dy -= obj->y_position;
        dz -= obj->z_position;
        if (dx < 0.0f) dx = -dx;
        if (*arg1 < dx) *arg1 = dx;
        if (dy < 0.0f) dy = -dy;
        if (*arg2 < dy) *arg2 = dy;
        if (dz < 0.0f) dz = -dz;
        if (*arg3 < dz) *arg3 = dz;
    }
    if (*arg1 == 0.0f || *arg2 == 0.0f || *arg3 == 0.0f) {
        dx = D_800D1C90[obj->id]->unk1A;
        dy = obj->xz_scale * dx;
        *arg3 = dy;
        *arg1 = dy;
        dx = D_800D1C90[obj->id]->unk1C + D_800D1C90[obj->id]->unk1E;
        *arg2 = obj->y_scale * dx;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15184368.s")

s32 func_150AD9A0(s32, s32, s32);
s32 func_15184150(s32, f32 *, f32 *, f32 *);
extern f32 D_800A7378;
extern f32 D_800D3688;
extern f32 D_800D368C;

s32 func_15184DF0(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 x, y, z;
    s32 dist;
    f32 scale;

    x = gObjects[arg0].x_position;
    y = gObjects[arg0].y_position;
    z = gObjects[arg0].z_position;
    dist = func_150AD9A0(x - D_800DBFF0[arg1].unk2F8, y - D_800DBFF0[arg1].unk2FC, z - D_800DBFF0[arg1].unk300);
    if (dist > 2000) {
        D_800D3688 = 0.0f;
        D_800D368C = D_800D3688;
        return 0;
    }
    func_15184150(arg0, arg2, arg3, arg4);
    scale = D_800A7378;
    *arg2 *= scale;
    *arg3 *= scale;
    *arg4 *= scale;
    if ((*arg2 == 0.0f) || (*arg3 == 0.0f) || (*arg4 == 0.0f)) {
        D_800D3688 = 0.0f;
        D_800D368C = D_800D3688;
        return 0;
    }
    return dist;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15184FA4.s")

struct func_15185454_s {
    f32 x, y, z;
    s16 c[3];
};

struct func_15185454_s *func_15185454(struct func_15185454_s *a, struct func_15185454_s *b, struct func_15185454_s *out) {
    f32 t = (a->z - a->y) / ((b->y - a->y) - (b->z - a->z));
    out->x = a->x + (b->x - a->x) * t;
    out->y = out->z = a->y + (b->y - a->y) * t;
    out->c[0] = (b->c[0] - a->c[0]) * t + a->c[0];
    out->c[1] = (b->c[1] - a->c[1]) * t + a->c[1];
    out->c[2] = (b->c[2] - a->c[2]) * t + a->c[2];
    return out + 1;
}

s32 func_15185554(f32 *arg0) {
    return arg0[2] < arg0[1];
}

struct func_1518557C_s {
    f32 x, y, z;
    s16 c[3];
};

struct func_1518557C_s *func_1518557C(struct func_1518557C_s *a, struct func_1518557C_s *b, struct func_1518557C_s *out) {
    f32 t = (a->z + a->x) / ((a->x - b->x) + (a->z - b->z));
    out->x = a->x + (b->x - a->x) * t;
    out->y = a->y + (b->y - a->y) * t;
    out->z = -out->x;
    out->c[0] = (b->c[0] - a->c[0]) * t + a->c[0];
    out->c[1] = (b->c[1] - a->c[1]) * t + a->c[1];
    out->c[2] = (b->c[2] - a->c[2]) * t + a->c[2];
    return out + 1;
}

s32 func_1518567C(f32 *arg0) {
    return arg0[0] < -arg0[2];
}

struct func_151856A8_s {
    f32 x;
    f32 y;
    f32 z;
    s16 s[3];
};

struct func_151856A8_s *func_151856A8(struct func_151856A8_s *a, struct func_151856A8_s *b, struct func_151856A8_s *out) {
    f32 t;

    t = (a->z + a->y) / ((a->y - b->y) + (a->z - b->z));
    out->x = a->x + (b->x - a->x) * t;
    out->y = a->y + (b->y - a->y) * t;
    out->z = -out->y;
    out->s[0] = (b->s[0] - a->s[0]) * t + a->s[0];
    out->s[1] = (b->s[1] - a->s[1]) * t + a->s[1];
    out->s[2] = (b->s[2] - a->s[2]) * t + a->s[2];
    return out + 1;
}

s32 func_151857B0(f32 *arg0) {
    return arg0[1] < -arg0[2];
}

struct func_151857DC_s {
    f32 x;
    f32 y;
    f32 z;
    s16 s0;
    s16 s1;
    s16 s2;
    s16 pad;
};

struct func_151857DC_s *func_151857DC(struct func_151857DC_s *arg0, struct func_151857DC_s *arg1, struct func_151857DC_s *arg2) {
    f32 t;

    t = (arg0->z - arg0->x) / ((arg1->x - arg0->x) - (arg1->z - arg0->z));
    arg2->x = arg0->x + (arg1->x - arg0->x) * t;
    arg2->y = arg0->y + (arg1->y - arg0->y) * t;
    arg2->z = arg2->x;
    arg2->s0 = arg0->s0 + (arg1->s0 - arg0->s0) * t;
    arg2->s1 = arg0->s1 + (arg1->s1 - arg0->s1) * t;
    arg2->s2 = arg0->s2 + (arg1->s2 - arg0->s2) * t;
    return arg2 + 1;
}

s32 func_151858D4(f32 *arg0) {
    return arg0[2] < arg0[0];
}

extern f32 D_800D3688;

struct func_151858FC_s {
    f32 x;
    f32 y;
    f32 z;
    s16 a;
    s16 b;
    s16 c;
    s16 pad;
};

struct func_151858FC_s *func_151858FC(struct func_151858FC_s *arg0, struct func_151858FC_s *arg1, struct func_151858FC_s *arg2) {
    f32 t;

    t = (D_800D3688 - arg0->z) / (arg1->z - arg0->z);
    arg2->x = arg0->x + (arg1->x - arg0->x) * t;
    arg2->y = arg0->y + (arg1->y - arg0->y) * t;
    arg2->z = D_800D3688;
    arg2->a = arg0->a + (arg1->a - arg0->a) * t;
    arg2->b = arg0->b + (arg1->b - arg0->b) * t;
    arg2->c = arg0->c + (arg1->c - arg0->c) * t;
    return arg2 + 1;
}

extern f32 D_800D3688;

s32 func_151859FC(f32 *arg0) {
    return D_800D3688 < arg0[2];
}

extern f32 D_800D368C;

struct func_15185A28_s {
    f32 x, y, z;
    s16 s0, s1, s2;
    s16 pad;
};

struct func_15185A28_s *func_15185A28(struct func_15185A28_s *a, struct func_15185A28_s *b, struct func_15185A28_s *out) {
    f32 t = (D_800D368C - a->z) / (b->z - a->z);
    out->x = a->x + (b->x - a->x) * t;
    out->y = a->y + (b->y - a->y) * t;
    out->z = D_800D368C;
    out->s0 = a->s0 + (b->s0 - a->s0) * t;
    out->s1 = a->s1 + (b->s1 - a->s1) * t;
    out->s2 = a->s2 + (b->s2 - a->s2) * t;
    return out + 1;
}

extern f32 D_800D368C;

s32 func_15185B28(f32 *arg0) {
    return arg0[2] < D_800D368C;
}

struct func_15185B54_s {
    f32 x, y, z;
    s16 s[3];
};

struct func_15185B54_s *func_15185B54(struct func_15185B54_s *a, struct func_15185B54_s *b, struct func_15185B54_s *out) {
    f32 t;

    t = a->x / (a->x - b->x);
    out->x = 0.0f;
    out->y = a->y + (b->y - a->y) * t;
    out->z = a->z + (b->z - a->z) * t;
    out->s[0] = (b->s[0] - a->s[0]) * t + a->s[0];
    out->s[1] = (b->s[1] - a->s[1]) * t + a->s[1];
    out->s[2] = (b->s[2] - a->s[2]) * t + a->s[2];
    return out + 1;
}

s32 func_15185C44(f32 *arg0) {
    return *arg0 <= 0.0f;
}

struct func_15185C6C_s {
    f32 x;
    f32 y;
    f32 z;
    s16 s[3];
    s16 pad;
};

struct func_15185C6C_s *func_15185C6C(struct func_15185C6C_s *a, struct func_15185C6C_s *b, struct func_15185C6C_s *out) {
    f32 t = a->y / (a->y - b->y);

    out->y = 0.0f;
    out->x = a->x + (b->x - a->x) * t;
    out->z = a->z + (b->z - a->z) * t;
    out->s[0] = (b->s[0] - a->s[0]) * t + a->s[0];
    out->s[1] = (b->s[1] - a->s[1]) * t + a->s[1];
    out->s[2] = (b->s[2] - a->s[2]) * t + a->s[2];
    return out + 1;
}

s32 func_15185D5C(f32 *arg0) {
    return arg0[1] <= 0.0f;
}

s32 func_15185D84(f32 *arg0) {
    return 0.0f < *arg0;
}

s32 func_15185DAC(f32 *arg0) {
    return 0.0f < arg0[1];
}

struct func_15185DD4_s {
    s32 w[5];
};

extern struct func_15185DD4_s *(*D_8008D498[])(struct func_15185DD4_s *, struct func_15185DD4_s *, struct func_15185DD4_s *);
extern s32 (*D_8008D4C0[])(struct func_15185DD4_s *);

struct func_15185DD4_s *func_15185DD4(struct func_15185DD4_s *in, s32 n, s32 plane, struct func_15185DD4_s *out) {
    struct func_15185DD4_s *(*clip)(struct func_15185DD4_s *, struct func_15185DD4_s *, struct func_15185DD4_s *);
    s32 (*test)(struct func_15185DD4_s *);
    struct func_15185DD4_s *prev;
    struct func_15185DD4_s *cur;
    s32 i;

    prev = &in[n - 1];
    clip = D_8008D498[plane];
    test = D_8008D4C0[plane];
    cur = in;
    for (i = 0; i < n; i++) {
        if (test(cur)) {
            if (test(prev)) {
                *out++ = *cur;
            } else {
                out = clip(prev, cur, out);
                *out++ = *cur;
            }
        } else if (test(prev)) {
            out = clip(prev, cur, out);
        }
        prev = cur;
        cur++;
    }
    return out;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15185F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_1518652C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15186794.s")

extern s32 D_800DE01C;
extern s32 D_800DE020;
extern s32 D_800DE024;
extern s32 D_800DE030;
extern s32 D_800DE034;
extern s32 D_800DE038;
extern f32 D_800DE03C;
extern u8 D_800DE040;
extern u8 D_800DE041;

void func_151872B0(s32 arg0) {
    D_800DE01C = 600;
    D_800DE020 = 180;
    D_800DE024 = 90;
    D_800DE030 = 1016;
    D_800DE034 = 0;
    D_800DE038 = 1;
    D_800DE03C = 1.0f;
    D_800DE040 = 1;
    D_800DE041 = 1;
    switch (arg0) {
    case 33:
        D_800DE01C = 4800;
        D_800DE020 = D_800DE01C - 1;
        D_800DE024 = D_800DE01C - 2;
        D_800DE030 = 1010;
        D_800DE034 = 1;
        D_800DE038 = 4;
        D_800DE040 = 0;
        break;
    case 34:
        D_800DE01C = 2400;
        D_800DE020 = D_800DE01C - 1;
        D_800DE024 = D_800DE01C - 2;
        D_800DE038 = 4;
        D_800DE040 = 0;
        break;
    case 20:
        D_800DE041 = 0;
        break;
    case 41:
        D_800DE01C = 1200;
        D_800DE020 = 600;
        D_800DE024 = 300;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_151873E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_151875E0.s")

struct func_15187978_e {
    u8 pad0[0x8C];
    f32 unk8C;
    f32 unk90;
    s16 unk94;
    s16 unk96;
    u8 pad98[0x8];
};

struct func_15187978_s {
    u8 pad0[0xA4];
    struct func_15187978_e *unkA4;
    s16 unkA8;
    s16 unkAA;
};

void func_10004074(void *);

void func_15187978(struct func_15187978_s *arg0) {
    s32 i;

    if (arg0->unkA8 < 0) {
        func_10004074(arg0->unkA4);
        func_1516972C((struct102 *)arg0);
        return;
    }
    arg0->unkA8 += D_800BE9E4;
    if (arg0->unkAA < arg0->unkA8) {
        arg0->unkA8 = -10;
    } else if (arg0->unkA8 >= 0) {
        for (i = 0; i < 12; i++) {
            if (arg0->unkA4[i].unk94 < arg0->unkA4[i].unk96) {
                arg0->unkA4[i].unk94 += D_800BE9E4;
                if (arg0->unkA4[i].unk96 < arg0->unkA4[i].unk94) {
                    arg0->unkA4[i].unk94 = arg0->unkA4[i].unk96;
                }
                arg0->unkA4[i].unk90 += arg0->unkA4[i].unk8C - ((arg0->unkA4[i].unk8C / 3.0f) * arg0->unkA4[i].unk94) / arg0->unkA4[i].unk96;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15187A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15187D6C.s")
