#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150BDE90_s {
    s32 unk0;
    s16 unk4;
};

void func_150BDE90(s32 arg0, u8 arg1, s32 arg2) {
    struct func_150BDE90_s sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = 0;
    temp_v0 = func_15149130(0x12C, -1, 0x4F, -1, 0, 0x3C, (struct37 *)8, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp38, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BDF0C.s")

void func_150BE150(struct102 *arg0, s32 *arg1, u8 arg2) {
    s32 temp_v0;

    if (arg2 == 0x21) {
        if (*(s32 *)((u8 *)arg0 + 0x28) == *arg1) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0) {
        temp_v0 = *arg1;
        if (*(s32 *)((u8 *)arg0 + 0x28) == *(s32 *)(temp_v0 + 0x318)) {
            func_1516972C(arg0);
        }
    }
}

struct func_150BE1C4_s {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[0x80 - 0x18];
    f32 unk80;
};

s32 func_150BE1C4(struct func_150BE1C4_s *arg0) {
    arg0->unk14 += arg0->unk80 * D_800BE9A4;
    if (arg0->unk14 > 120.0f) {
        return 0;
    }
    return 1;
}

struct func_150BE210_s {
    u8 pad0[0x4F];
    u8 unk4F;
    u8 pad50[0x64 - 0x50];
    f32 unk64;
    u8 pad68[0x73 - 0x68];
    u8 unk73;
    u16 unk74;
    u8 pad76[0x84 - 0x76];
    f32 unk84;
};

void func_1511650C(struct func_150BE210_s *, s32, s32, f32);

void func_150BE210(struct func_150BE210_s *arg0) {
    if ((arg0->unk73 & 3) != 3) {
        func_1511650C(arg0, 1, 0x62C, 500.0f);
        if (arg0->unk4F & 4) {
            arg0->unk84 += arg0->unk64;
        } else if (arg0->unk84 > 270.0f) {
            arg0->unk84 = 270.0f;
        }
        if (arg0->unk84 > 360.0f) {
            arg0->unk73 &= ~3;
            arg0->unk73 |= 3;
            arg0->unk64 = 0.0f;
            func_100111C8(arg0->unk74);
            arg0->unk74 = 0;
        }
    }
}

extern f32 D_800A0068;

struct func_150BE2E8_s {
    u8 pad0[0x10];
    s16 unk10[3];
    u8 pad16[0x3C - 0x16];
    s16 unk3C;
    s16 unk3E;
    u8 pad40[0x7C - 0x40];
    s16 unk7C[3];
    s16 unk82[3];
};

void func_150BE2E8(struct func_150BE2E8_s *arg0) {
    f32 x0, y0, z0, x1, y1, z1;
    f32 a, b;

    x0 = arg0->unk7C[0];
    y0 = arg0->unk7C[1];
    z0 = arg0->unk7C[2];
    x1 = arg0->unk82[0];
    y1 = arg0->unk82[1];
    z1 = arg0->unk82[2];
    a = arg0->unk3C * (1.0f / 16384.0f);
    b = arg0->unk3E * (1.0f / 16384.0f);
    a -= a * D_800A0068;
    b += a * D_800BE9E4;
    arg0->unk10[0] = (x1 - x0) * b + x0;
    arg0->unk10[1] = (y1 - y0) * b + y0;
    arg0->unk10[2] = (z1 - z0) * b + z0;
    if (b > 1.0f) {
        b = 1.0;
    }
    arg0->unk3C = a * 16384.0f;
    arg0->unk3E = b * 16384.0f;
}

s16 *func_150BE438(s16 *arg0, s32 arg1) {
    struct127 *obj;

    obj = &gObjects[arg1];
    arg0[0] = 0x68;
    arg0[1] = obj->unk2E8;
    arg0[2] = 0xE;
    arg0[3] = obj->unk2E4;
    return arg0 + 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE494.s")
