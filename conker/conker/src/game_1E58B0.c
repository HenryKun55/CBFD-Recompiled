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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E58B0/func_151B8908.s")
