#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15184150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15184368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15184DF0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15185DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15185F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_1518652C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_15186794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B1600/func_151872B0.s")

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
