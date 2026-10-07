#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517EE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517EF00.s")

s32 func_1517EFAC(void) {
    if (func_1517EF00() == 0xFF) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517EFDC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F4D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F564.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F9F4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15182670.s")

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
