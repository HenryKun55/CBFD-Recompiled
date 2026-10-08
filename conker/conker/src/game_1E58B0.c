#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151B8400_v {
    f32 x, y, z;
};

struct func_151B8400_s {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    f32 unk18;
    struct func_151B8400_v unk1C;
    struct func_151B8400_v unk28;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    s32 unk40;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    s32 unk48;
    u8 unk4C;
    s32 unk50;
    s16 unk54;
    s16 unk56;
};

extern u8 D_800AA490[];

void *func_151B8400(u8 *arg0) {
    void *temp_v0;
    u8 *spA8;
    struct func_151B8400_s sp50;
    struct func_151B8400_v sp44;

    spA8 = arg0;
    sp50.unk0 = 0xFF;
    sp50.unk1 = 0;
    sp50.unk2 = 0x5901;
    sp50.unk4 = 0x32;
    sp50.unk8 = 0;
    sp50.unkC = 0;
    sp50.unk10 = 0xFF;
    sp50.unk11 = 0xE6;
    sp50.unk12 = 0xB6;
    sp50.unk13 = 0xFF;
    sp50.unk14 = 9.0f;
    sp50.unk18 = 1.0f;
    sp44 = *(struct func_151B8400_v *)(arg0 + 0x38);
    sp50.unk28 = sp44;
    sp50.unk1C = sp44;
    sp50.unk34 = *(f32 *)(arg0 + 0x44) * 0.25f;
    sp50.unk38 = *(f32 *)(arg0 + 0x48) * 0.25f;
    sp50.unk3C = *(f32 *)(arg0 + 0x4C) * 0.25f;
    sp50.unk40 = 0x0CCC0000;
    sp50.unk44 = 0xC8;
    sp50.unk45 = 0xFF;
    sp50.unk46 = 0;
    sp50.unk47 = 6;
    sp50.unk48 = 0;
    sp50.unk4C = 0xFF;
    sp50.unk50 = 0;
    sp50.unk54 = 0x32;
    sp50.unk56 = 5;
    temp_v0 = func_1513D2F0(&sp50, D_800AA490, 0x1B, 0, 0, 0x19, 0, 0, 0, 4, arg0[0xC], arg0[1]);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x110, &spA8, 4);
    }
    return temp_v0;
}

typedef struct func_151B85AC_v { f32 x, y, z; } func_151B85AC_v;

struct func_151B85AC_o {
    u8 pad0[0x34];
    func_151B85AC_v rot;
    f32 pos[3];
    f32 vel[3];
    s32 flags;
    u8 pad5C[0x110 - 0x5C];
    u8 *parent;
};

s32 func_151B85AC(struct func_151B85AC_o *arg0) {
    u8 *p = arg0->parent;
    if (p != NULL) {
        arg0->rot = *(func_151B85AC_v *)(p + 0x38);
        arg0->pos[0] += arg0->vel[0] * D_800BE9A4;
        arg0->pos[1] += arg0->vel[1] * D_800BE9A4;
        arg0->pos[2] += arg0->vel[2] * D_800BE9A4;
    } else {
        arg0->flags |= 1;
    }
    return 1;
}

void func_1513FA70(void *arg0, s16 arg1);

void func_151B863C(void *arg0, s16 arg1) {
    func_1513FA70(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E58B0/func_151B8668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E58B0/func_151B86F4.s")

struct func_151B8908_v { f32 x, y, z; };
struct func_151B8908_t { s32 c[4]; };

struct func_151B8908_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    struct func_151B8908_v unk30;
    struct func_151B8908_v unk3C;
    struct func_151B8908_v unk48;
    f32 unk54;
    s32 unk58;
    s32 unk5C;
    s8 unk60;
    s8 unk61;
    s8 unk62;
    s8 unk63;
    s8 unk64;
    s8 unk65;
    u8 unk66;
    u8 pad67[0xD];
};

extern struct func_151B8908_t D_800AA4B8;
s32 func_15130280(void *, s32, s32, s32, s32, s32);

void func_151B8908(u8 *arg0) {
    struct func_151B8908_s p;
    struct func_151B8908_t colors;
    s32 b;
    s32 a;

    colors = D_800AA4B8;
    p.unk1D = colors.c[func_150ADA20() & 3];
    p.unk8 = 0x1303;
    p.unk0 = 0x200005;
    p.unk4 = 0;
    p.unkA = 0x12C;
    p.unkC = 0;
    p.unk10 = 0;
    p.unk14 = 0xFF;
    p.unk15 = 0xFF;
    p.unk16 = 0xFF;
    p.unk17 = 0xFF;
    p.unk18 = 0xFF;
    p.unk19 = 0xFF;
    p.unk1A = 0xFF;
    p.unk1B = 0xFF;
    p.unk1C = 0xFF;
    p.unk28 = p.unk2C = (func_150ADA68() * 500.0f) + 900.0f;
    p.unk30 = *(struct func_151B8908_v *)(arg0 + 0x38);
    p.unk3C = *(struct func_151B8908_v *)&D_800A5480;
    p.unk48 = *(struct func_151B8908_v *)&D_800A5480;
    p.unk1E = 1;
    p.unk20 = 0xFF;
    p.unk22 = 1;
    p.unk54 = 0.0f;
    p.unk24 = 1.0f;
    if (func_150ADA20() & 1) {
        a = 0x40;
    } else {
        a = 0;
    }
    if (func_150ADA20() & 1) {
        b = 0x80;
    } else {
        b = 0;
    }
    p.unk58 = b | a | 0x4000 | 0x8000 | 0x40000 | 0x800000;
    p.unk60 = 6;
    p.unk61 = 5;
    p.unk62 = -1;
    p.unk63 = -1;
    p.unk64 = -1;
    p.unk65 = 0;
    p.unk5C = 0;
    p.unk66 = 0xFF;
    func_15130280(&p, 1, 0, 0, arg0[0xC], arg0[1]);
}
