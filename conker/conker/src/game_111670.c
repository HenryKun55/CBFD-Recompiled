#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s16 D_800D99F0[3];

void func_150E41C0(void) {
    s32 x;
    s32 y;
    s32 z;
    f32 zero;
    f32 a;
    f32 b;
    f32 s;
    f32 c;
    f32 angle;

    x = D_800DBFF0->unk2F8;
    y = D_800DBFF0->unk2FC;
    z = D_800DBFF0->unk300;
    angle = D_800DBFF0->unk398;
    s = sinf(angle);
    c = cosf(angle);
    zero = 0.0f;
    a = 500.0f * s;
    b = -500.0f * c;
    angle = D_800DBFF0->unk3A0;
    s = sinf(angle);
    c = cosf(angle);
    x += zero + b * s;
    z += b * c - zero;
    y += a;
    D_800D99F0[0] = x;
    D_800D99F0[2] = z;
    D_800D99F0[1] = y;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E42F8.s")

void func_150E4514(s32 arg0) {
    func_150E41C0();
    func_150E42F8(arg0 / 30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E4550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E4928.s")

struct func_150E4CBC_s {
    u8 pad0[0x90];
    s32 unk90;
    s16 unk94;
    s16 unk96;
    s16 unk98;
    u8 pad9A[0xA2 - 0x9A];
    s16 unkA2;
    s16 unkA4;
    u8 padA6[0xB4 - 0xA6];
    u8 unkB4;
};

void func_150E4CBC(struct func_150E4CBC_s *arg0) {
    s32 t;
    if (arg0->unk90 < 9) {
        arg0->unkA4 = (((arg0->unk90 * 90) / 9) * arg0->unk96) * 0.00390625f;
    } else {
        arg0->unkA4 = ((90 - ((arg0->unk90 * 90) - 810) / 600) * arg0->unk96) * 0.00390625f;
        t = D_800BE9E4 * 17;
        if (t < arg0->unkB4) {
            arg0->unkB4 -= t;
        } else {
            arg0->unk98 = -1;
        }
    }
    arg0->unkA2 = (s32)(arg0->unk94 * 14.0f) >> 8;
    if (arg0->unk90 >= 0x261) {
        arg0->unk98 = -1;
    }
    arg0->unk90 += D_800BE9E4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E4E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E5558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E5810.s")
