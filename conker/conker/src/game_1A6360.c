#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800DD434;
extern u8 D_800DD446;
extern u8 D_800DD432;
extern u8 D_800DD433;
extern s16 D_800DD436;
extern s32 D_800DD440;

void func_15178EB0(void) {
    D_800DD434 = 0;
    D_800DD446 = 0;
    D_800DD444 = 600;
    D_800DD432 = 240;
    D_800DD433 = 20;
    D_800DD436 = 0;
    D_800DD440 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15178EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15179008.s")

extern s16 D_800DD438[3];

void func_151794C8(void) {
    s32 x;
    s32 y;
    s32 z;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 s;
    f32 c;
    f32 a;

    x = D_800DBFF0->unk2F8;
    y = D_800DBFF0->unk2FC;
    z = D_800DBFF0->unk300;
    a = D_800DBFF0->unk398;
    s = func_150AD78C(a);
    c = func_150AD780(a);
    vx = 0.0f;
    vy = 500.0f * s;
    vz = -500.0f * c;
    a = D_800DBFF0->unk3A0;
    s = func_150AD78C(a);
    c = func_150AD780(a);
    x += vx * c + vz * s;
    z += vz * c - vx * s;
    y += vy;
    D_800DD438[0] = x;
    D_800DD438[2] = z;
    D_800DD438[1] = y;
}

struct func_15179600_s {
    u8 pad0[0x80];
    s32 unk80;
    s16 unk84;
    u8 pad86[0x4];
    s16 unk8A;
    s16 unk8C;
    s16 unk8E;
    s16 unk90;
    s16 unk92;
    s16 unk94;
    u8 pad96[0x2];
    u16 unk98;
    u8 pad9A[0x2];
    s16 unk9C;
    s16 unk9E;
    s8 unkA0;
    s8 unkA1;
    s8 unkA2;
    u8 padA3[0x14];
};

void func_1516865C();
void *func_15168800();

void func_15179600(s32 arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 c;
    s32 x;
    s32 y;
    s32 z;
    struct func_15179600_s sp28;

    sp28.unkA0 = 0x11;
    sp28.unk8A = 0x33;
    sp28.unkA2 = 1;
    sp28.unk98 = 0;
    func_1516865C(&sp28, 0xFF, 0xFF, 0xFF, 0x50);
    x = D_800DBFF0->unk2F8;
    y = D_800DBFF0->unk2FC;
    z = D_800DBFF0->unk300;
    a = func_150ADA20() % 500 + x;
    c = func_150ADA20() % 500 + z;
    if (arg0 == 0) {
        b = y + 500;
    } else {
        b = func_150ADA20() % 500 + y;
    }
    x = (u32)func_150ADA20() % 10;
    sp28.unk9C = 0;
    sp28.unk9E = 0;
    sp28.unk8C = a;
    sp28.unk8E = b;
    sp28.unk90 = c;
    sp28.unk92 = 4;
    sp28.unk94 = x + 35;
    sp28.unk98 = 0x8C00;
    sp28.unkA1 = x + 10;
    sp28.unk80 = arg1;
    sp28.unk84 = D_800DD436;
    y = (s32)func_15168800(&sp28, 0xFF, 0);
    if (y != 0) {
        ((s32 *)D_800DD440)[D_800DD436] = y;
        D_800DD436++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_151797B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15179AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15179B14.s")

struct func_15179CB0_s {
    u8 pad0[0x9C];
    s16 unk9C;
    u8 pad9E[2];
    s16 unkA0;
    u8 padA2[0x12];
    u8 unkB4;
};

void func_15179CB0(struct func_15179CB0_s *arg0) {
    f32 dz = arg0->unkA0 - D_800DBFF0->unk300;
    f32 dx = arg0->unk9C - D_800DBFF0->unk2F8;
    f32 dist = sqrtf(dz * dz + dx * dx);
    arg0->unkB4 = 255.0f - (160.0f * dist) / 1000.0f;
}
