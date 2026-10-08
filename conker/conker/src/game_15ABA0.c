#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1512D6F0_s {
    u8 pad0[0x28];
    f32 unk28;
    f32 unk2C;
    u8 pad30[0x20];
    s32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    u8 pad64[4];
};
extern struct func_1512D6F0_s D_800DC2C0[];

void func_1512D6F0(u8 *arg0) {
    struct func_1512D6F0_s *temp_v0 = &D_800DC2C0[arg0[0x23D]];
    temp_v0->unk50 = 5;
    temp_v0->unk54 = 0.0f;
    temp_v0->unk58 = 0.0f;
    temp_v0->unk5C = 0.0f;
    temp_v0->unk60 = 0.0f;
    temp_v0->unk2C = 0.0f;
    temp_v0->unk28 = -1.0f;
}

struct func_1512D748_s {
    f32 unk0[10];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    s32 unk50;
    u8 pad54[0x10];
    s32 unk64;
};
extern u8 D_800895D0[][10];

void func_1512D748(u8 *arg0, s32 arg1, s32 arg2) {
    struct func_1512D748_s *v = &((struct func_1512D748_s *)D_800DC2C0)[arg0[0x23D]];
    u8 *t;
    f32 sp4;

    if ((*(u8 **)(arg0 + 0x3D4))[0x120] == 0) {
        f32 a, b, d, e, s34, s38;
        t = D_800895D0[arg1];
        v->unk0[0] = (u32)t[0];
        v->unk0[1] = (u32)t[1];
        v->unk0[2] = (u32)t[2];
        v->unk0[3] = (u32)t[3];
        v->unk0[4] = (u32)t[4];
        v->unk0[5] = (u32)t[5];
        v->unk0[6] = (u32)t[6];
        v->unk0[7] = (u32)t[7];
        v->unk0[8] = (u32)t[8];
        v->unk0[9] = (u32)t[9];
        a = v->unk0[4];
        b = v->unk0[5];
        s34 = b + a;
        s38 = v->unk0[6] + s34;
        d = v->unk0[7];
        e = v->unk0[8];
        v->unk30 = a;
        v->unk34 = s34;
        v->unk38 = s38;
        v->unk3C = d + s38;
        v->unk28 = 0.0f;
        v->unk2C = 0.0f;
        v->unk40 = e / a;
        sp4 = v->unk0[9];
        v->unk44 = (e - sp4) / b;
        v->unk48 = 0.0f;
        v->unk4C = sp4 / d;
        v->unk50 = 0;
        v->unk64 = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15ABA0/func_1512D980.s")
