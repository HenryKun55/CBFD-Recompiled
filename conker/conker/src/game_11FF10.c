#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2A60.s")

struct func_150F2C8C_s {
    void *unk0;
    u8 unk4;
    u8 unk5;
    f32 unk8;
    u8 unkC;
};

void func_150F2C8C(u8 *arg0) {
    struct func_150F2C8C_s sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = arg0[0x3B];
    sp38.unk5 = 0;
    sp38.unk8 = 0.0f;
    sp38.unkC = 0;
    temp_v0 = func_15149130(0x12C, -1, 0x5C, -1, 0, 0x44, (struct37 *)0x10, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp38, 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2D14.s")

void func_150F3194(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_150F31D4(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x110, arg0 + 0x114, arg0);
}

extern s32 D_800A1950;
float sqrtf(float);
#pragma intrinsic(sqrtf)

struct func_150F3214_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

s32 func_150F3214(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x110);
    struct func_150F3214_s *s = (struct func_150F3214_s *)(arg0 + 0x110);

    if (*(s32 *)p == 0 || s->unk4 != p[0x3B] || *(u8 **)(p + 0x1D4) == NULL) {
        return 0;
    }
    func_15143134(&D_800A1950, arg0 + 0x34, *(u8 **)(p + 0x1D4) + 0x3C0);
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x30) = sqrtf(s->unk8) * s->unk10;
    arg0[0x5C] = s->unk14 - s->unk18 * s->unk8 * s->unk8;
    s->unk8 += D_800BE9A4;
    if (s->unkC < s->unk8) {
        return 0;
    }
    return 1;
}

void func_15140410();

void func_150F337C(u8 *arg0, s16 arg1) {
    func_15140410(arg0, arg0 + 0x12C, arg0 + 0x138, arg1);
}

struct func_150F33B0_s {
    u8 pad0[0x4F];
    u8 unk4F_pad : 7;
    u8 unk4F_0 : 1;
};

void func_150F33B0(struct func_150F33B0_s *arg0) {
    if (D_800DBFF0->unk300 < -2000.0f) {
        arg0->unk4F_0 = 0;
        return;
    }
    arg0->unk4F_0 = 1;
}

extern f32 D_800A1970;

void func_150F33F8(s32 arg0) {
    struct108 *temp_v0;

    temp_v0 = (struct108 *)((char *)D_800DBFF0 + arg0 * 0x9A0);
    if (temp_v0->unk300 < D_800A1970) {
        if (temp_v0->unk2FC > 840.0f) {
            *(s16 *)D_800D9A40 |= (1 << arg0);
            return;
        }
        *(s16 *)D_800D9A40 &= ~(1 << arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34F4.s")

s32 func_1509BE40(s32, s32, s32, s32);

struct func_150F43F0_s {
    u8 pad0[0x2C];
    s32 unk2C;
    u8 pad30[0x84 - 0x30];
    s32 unk84;
    u8 pad88[0x134 - 0x88];
    s32 unk134;
    u8 pad138[0x190 - 0x138];
    f32 unk190;
    u8 pad194[0x1B4 - 0x194];
    s16 unk1B4;
    u8 pad1B6[0x1E0 - 0x1B6];
    s16 unk1E0;
    u8 pad1E2[0x23E - 0x1E2];
    u8 unk23E;
    u8 pad23F[0x348 - 0x23F];
    f32 unk348;
    f32 unk34C;
    u8 pad350[0x374 - 0x350];
    f32 unk374;
    u8 pad378[0x6C8 - 0x378];
    s32 unk6C8;
};

void func_150F43F0(struct func_150F43F0_s *arg0) {
    if (arg0->unk23E == 0x3B) {
        func_1509BFB0(0, 0x405C, 1);
        if ((arg0->unk2C != 0x100) && (arg0->unk6C8 == 0)) {
            if (func_15123934(arg0, 8, 0, 0, 0) != 0) {
                arg0->unk84 |= 0x300000;
                arg0->unk84 &= ~4;
                arg0->unk1B4 = 1;
                arg0->unk1E0 = 3;
                func_15124B18(arg0);
            }
            arg0->unk134 = 0;
            arg0->unk348 = 125.0f;
            arg0->unk34C = 125.0f;
            arg0->unk374 = 220.0f;
            arg0->unk190 = 30.0f;
        } else {
            arg0->unk190 = 0.0f;
        }
    } else if ((arg0->unk2C == 8) && (arg0->unk6C8 == 0)) {
        func_151239CC(arg0, 0);
        func_1509BFB0(0, 0x405C, 0);
    }
    if ((func_1509BE40(1, 0x4054, 6, 0x9000) != 0) && (func_1509BE40(1, 0x405E, 6, 0x9000) == 0)) {
        arg0->unk84 |= 0x80000000;
    } else {
        arg0->unk84 &= 0x7FFFFFFF;
    }
}
