#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1517EE40_s {
    u8 a;
    u8 b;
    u8 c;
};
extern struct func_1517EE40_s D_800DDDA0[];
extern u8 D_800DDDC0[];

void func_1517EE40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4, s32 arg5) {
    s8 *p = &((s8 *)&D_800DDDAC)[arg5];

    if ((arg4 != *p) || ((&D_800DDDB0)[arg5] < (&D_800DDE28)[arg5]) || (D_800DDDC0[arg5] != 0)) {
        D_800DDDA0[arg5].b = arg1;
        D_800DDDA0[arg5].c = arg2;
        D_800DDDA0[arg5].a = arg0;
        (&D_800DDE28)[arg5] = arg3;
        (&D_800DDDB0)[arg5] = 0;
        *p = arg4;
        D_800DDDC0[arg5] = 0;
    }
}

extern u8 D_800DDDC0[];

s32 func_1517EF00(arg0)
    s32 arg0;
{
    s32 v;

    if (D_800DDDC0[arg0] != 0) {
        v = D_800DDDC0[arg0];
    } else {
        if ((&D_800DDE28)[arg0] != 0) {
            v = ((&D_800DDDB0)[arg0] * 255) / (&D_800DDE28)[arg0];
            if (v >= 256) {
                v = 255;
            }
        } else {
            v = 255;
        }
        if (((s8 *)&D_800DDDAC)[arg0] == 0) {
            v = 255 - v;
        }
    }
    return v;
}

s32 func_1517EFAC(void) {
    if (func_1517EF00() == 0xFF) {
        return 1;
    }
    return 0;
}

s32 func_1517EFDC(void) {
    s32 count;
    s32 i;

    count = -1;
    for (i = 0; i <= D_80082FA0; i++) {
        if ((func_1517EF00(i) > 0) || ((&D_800DDDC8)[i] > 0.0f)) {
            count++;
        }
    }
    if (count == D_80082FA0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F3A0.s")

s32 func_1517F40C(s32 arg0) {
    s32 ret = 0;
    if ((&D_800DDDB0)[arg0] >= (&D_800DDE28)[arg0]) {
        return 1;
    }
    return ret;
}

void func_1517F448(s32 arg0) {
    if ((&D_800DDDB0)[arg0] != (&D_800DDE28)[arg0]) {
        (&D_800DDDB0)[arg0] += D_800BE9E4;
    }
}

extern u8 D_800DDD90[][3];
extern u8 D_800DDD9C[];
extern s16 D_800DDE10[];

void func_1517F488(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 *p = D_800DDD90[arg5];
    p[0] = arg0;
    p[1] = arg1;
    p[2] = arg2;
    D_800DDD9C[arg5] = arg3;
    D_800DDE10[arg5] = arg4;
}

s32 func_1517F08C(s32, s32, s32, s32, s32, s32);

s32 func_1517F4D8(s32 arg0, s32 arg1) {
    u8 *p;
    if ((u16)D_800DDE10[arg1] == 0) {
        return arg0;
    }
    if (D_800DDD9C[arg1] == 0) {
        return arg0;
    }
    p = D_800DDD90[arg1];
    return func_1517F08C(arg0, D_800DDD9C[arg1], p[0], p[1], p[2], arg1);
}

extern u8 D_800DDD89;
extern u8 D_800DDD8A;
extern u8 D_800DDD8B;
extern u8 D_800DDD8C;
extern u8 D_8008D010[][6];

s32 func_1517F564(s32 arg0) {
    s32 pad[3]; f32 t;
    s32 v;
    u8 *p;
    f32 s;
    s32 r, g, b;

    if (D_800DDE08 == 0) {
        return arg0;
    }
    if (D_800DDD8B == 0) {
        return arg0;
    }
    if (D_800DDD8C) {
        s = (func_15048A40(D_800DDD89) + 1.0f) * 0.5f;
        v = D_800DDD8B * s;
        t = 0.0f;
    } else {
        v = D_800DDD8B;
    }
    p = D_8008D010[D_800DDD8A];
    r = p[0] + (p[3] - p[0]) * t;
    g = p[1] + (p[4] - p[1]) * t;
    b = p[2] + (p[5] - p[2]) * t;
    return func_1517F08C(arg0, v, r, g, b, 0);
}

extern u8 D_800DDD88;
extern u8 D_800DDD89;
extern u8 D_800DDD8A;
extern u8 D_800DDD8B;
extern u8 D_800DDD8C;

void func_1517F720(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_800DDE08 = arg1;
    D_800DDD88 = arg2;
    D_800DDD89 = 0;
    D_800DDD8A = arg0;
    D_800DDD8B = arg3;
    D_800DDD8C = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F75C.s")

extern u8 D_800DDD88;
extern u8 D_800DDD89;

void func_1517F7B4(s32 arg0) {
    if (D_800DDE08 != 0) {
        if (D_800DDE08 > D_800BE9E4) {
            D_800DDE08 -= D_800BE9E4;
        } else {
            D_800DDE08 = 0;
        }
        D_800DDD89 += D_800DDD88 * D_800BE9E4;
    }
    if (arg0) {}
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F814.s")

Gfx *func_1517F9F4(Gfx *gfx, s32 x0, s32 y0, s32 x1, s32 y1, s32 cam) {
    s32 t;
    s32 tmp;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;

    if (x1 < x0) {
        tmp = x0;
        x0 = x1;
        x1 = tmp;
    }
    if (y1 < y0) {
        tmp = y0;
        y0 = y1;
        y1 = tmp;
    }
    left = ((f32 *)((char *)D_800BE628 + cam * 0x180))[0x2C / 4];
    top = ((f32 *)((char *)D_800BE628 + cam * 0x180))[0x24 / 4];
    right = ((f32 *)((char *)D_800BE628 + cam * 0x180))[0x30 / 4];
    bottom = ((f32 *)((char *)D_800BE628 + cam * 0x180))[0x28 / 4];
    if (!((y0 < bottom) && (top < y1) && (x0 < right) && (left < x1))) {
        return gfx;
    }
    t = (x0 < left) ? left : ((right < x0) ? right : x0);
    x0 = t;
    t = (y0 < top) ? top : ((bottom < y0) ? bottom : y0);
    y0 = t;
    t = (x1 < left) ? left : ((right < x1) ? right : x1);
    x1 = t;
    t = (y1 < top) ? top : ((bottom < y1) ? bottom : y1);
    y1 = t;
    gDPFillRectangle(gfx++, x0, y0, x1, y1);
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517FB9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15180580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_151814FC.s")

s32 func_15181CC8(s32 arg0) {
    if ((&D_800DDDC8)[arg0] == 0.0f) {
        return 1;
    }
    return 0;
}

extern f32 D_800A72AC;
struct func_15181DC8_s;
extern struct func_15181DC8_s D_800DDDE8[];
struct func_15181D00_s { f32 x; f32 y; };

void func_15181D00(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        (&D_800DDDC8)[arg0] = 0.0f;
    } else {
        (&D_800DDDD8)[arg0] = 0.0f;
        (&D_800DDDC8)[arg0] = D_800A72AC;
        ((struct func_15181D00_s *)D_800DDDE8)[arg0].x = 0.0f;
        ((struct func_15181D00_s *)D_800DDDE8)[arg0].y = 0.0f;
    }
    (&D_800DDE1C)[arg0] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181D70.s")

struct func_15181DC8_s { f32 x; f32 y; };
extern struct func_15181DC8_s D_800DDDE8[];

void func_15181DC8(s32 arg0) {
    (&D_800DDDD8)[arg0] = 0;
    (&D_800DDDC8)[arg0] = 0.0f;
    D_800DDDE8[arg0].x = 0.0f;
    D_800DDDE8[arg0].y = 0.0f;
    (&D_800DDE20)[arg0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181EE0.s")

struct func_15182670_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 pad5;
    s16 unk6;
};

void func_15182670(u8 arg0, u8 arg1, u8 arg2, u8 arg3, volatile s16 arg4, u8 arg5, u8 arg6, s32 arg7) {
    struct37 *temp_v0;
    struct func_15182670_s tmp;

    if (arg4 > 0) {
        tmp.unk0 = arg0;
        tmp.unk1 = arg1;
        tmp.unk2 = arg2;
        tmp.unk3 = arg3;
        tmp.unk4 = arg5;
        tmp.unk6 = arg3 / arg4;
        temp_v0 = func_15149130(arg4, -1, 0x39, 3, 1, 0, (struct37 *)8, arg6, arg7);
        if (temp_v0 != NULL) {
            memcpy(&temp_v0->unk28, &tmp, 8);
        }
    }
}

struct func_15182748_s {
    u8 pad0[0xE];
    s16 unkE;
    u8 pad10[0x2B - 0x10];
    u8 unk2B;
    u8 pad2C[2];
    s16 unk2E;
};

void func_15182748(struct func_15182748_s *arg0) {
    arg0->unk2B = arg0->unk2E * arg0->unkE;
}

struct func_15182768_s {
    u8 pad0[0x28];
    u8 unk28[5];
};

s32 func_1517F08C(s32, s32, s32, s32, s32, s32);

s32 func_15182768(s32 arg0, struct func_15182768_s *arg1, s16 arg2) {
    u8 *p = arg1->unk28;
    if (arg2 == p[4]) {
        arg0 = func_1517F08C(arg0, p[3], p[0], p[1], p[2], p[4]);
    }
    return arg0;
}
