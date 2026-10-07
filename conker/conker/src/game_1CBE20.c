#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1519E970_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 pad22;
    s32 unk24;
    u8 unk28;
};

void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

struct func_1519E970_s *func_1519E970(s16 arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4, u8 arg5, s32 arg6) {
    struct func_1519E970_s *v1;

    v1 = func_15167A68(0x26, arg6, 0x2C, 1, arg5, 1);
    if (v1 == NULL) {
        return NULL;
    }
    v1->unk18 = arg3;
    v1->unk1C = arg4;
    v1->unk20 = arg0;
    v1->unk28 = arg2;
    v1->unk24 = arg1;
    v1->unk10 = 1;
    v1->unk14 = 0;
    return v1;
}

struct func_1519EA04_t { u8 pad[0x30]; s32 unk30; };
struct func_1519EA04_s {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0xC];
    s16 unk20;
    u8 pad22[2];
    struct func_1519EA04_t *unk24;
    u8 unk28;
};

void func_1519EA04(struct func_1519EA04_s *arg0) {
    s32 var_v0;
    struct func_1519EA04_t *temp;

    if (arg0->unk10 & 1) {
        arg0->unk20 -= D_800BE9E4;
        var_v0 = 0;
        if (arg0->unk20 < 0) {
            var_v0 = 1;
        }
        if (var_v0) {
            if (arg0->unk28 == 0) {
                temp = arg0->unk24;
                temp->unk30 = 0;
            }
            func_1516972C((struct102 *)arg0);
        }
    }
}

struct func_1519EA78_v { s32 x[3]; };
struct func_1519EA78_s {
    s32 unk0;
    s32 unk4;
    struct func_1519EA78_v unk8;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    s16 unk2C;
    s16 unk2E;
    f32 unk30;
    f32 unk34;
    f32 unk38;
};
extern f32 D_800A8CC0;
extern f32 D_800A8CC4;
extern f32 D_800A8CC8;
extern f32 D_800A8CCC;
extern f32 D_800A8CD0;
void func_15152190(void *arg0, void *arg1, void *arg2, u32 arg3, f32 arg4, u8 arg5, u8 arg6, s32 arg7);

void func_1519EA78(struct func_1519EA78_v *arg0, u16 arg1, f32 arg2, u8 arg3, s32 arg4) {
    struct func_1519EA78_s sp34;
    s32 sp30;
    f32 sp2C;

    sp34.unk0 = 10;
    sp34.unk4 = 7;
    sp34.unk8 = *arg0;
    sp34.unk1C = 10.0f;
    sp34.unk20 = 8.0f;
    sp34.unk24 = D_800A8CC0;
    sp34.unk28 = D_800A8CC4;
    sp34.unk30 = D_800A8CC8;
    sp34.unk34 = D_800A8CCC;
    sp34.unk38 = D_800A8CD0;
    sp34.unk14 = 0;
    sp34.unk16 = 0xFF;
    sp34.unk18 = -0x35;
    sp34.unk1A = 0x18;
    sp34.unk2C = 0x32;
    sp34.unk2E = 0x14;
    sp2C = arg2;
    sp30 = arg1;
    func_15152190(&sp34, &sp30, &sp2C, 1, 0.0f, 0, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519EB8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519ED24.s")

struct func_1519ED84_s {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
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

void func_1519ED84(f32 *arg0, s32 arg1, s16 arg2, u8 arg3, s32 arg4) {
    struct func_1519ED84_s sp48;
    f32 *sp44;
    void *temp_v0;

    sp44 = arg0;
    sp48.unk0 = arg1;
    sp48.unk1 = 0;
    sp48.unk2 = 0x3B03;
    sp48.unk4 = arg2;
    sp48.unk8 = 0;
    sp48.unkC = 0;
    sp48.unk10 = 0xFF;
    sp48.unk11 = 0xFF;
    sp48.unk12 = 0xFF;
    sp48.unk13 = 0xFF;
    sp48.unk14 = arg0[6] * 10.0f;
    sp48.unk18 = arg0[7] * 10.0f;
    sp48.unk1C = arg0[0];
    sp48.unk20 = arg0[1];
    sp48.unk24 = arg0[2];
    sp48.unk28 = arg0[3];
    sp48.unk2C = arg0[4];
    sp48.unk30 = arg0[5];
    sp48.unk34 = 1.0f;
    sp48.unk38 = 1.0f;
    sp48.unk3C = 1.0f;
    sp48.unk40 = 0x045C0081;
    sp48.unk44 = 0xFF;
    sp48.unk45 = 0xFF;
    sp48.unk46 = 0;
    sp48.unk47 = 7;
    sp48.unk48 = 0;
    sp48.unk4C = 0xFF;
    sp48.unk50 = 0;
    sp48.unk54 = 1;
    sp48.unk56 = 0xFF;
    temp_v0 = func_1513D2F0(&sp48, &D_800A4AA0, 0x27, 0, 0, 0x17, 0, 3, 0xFF, 4, arg3, arg4);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x110, &sp44, 4);
    }
}

struct func_1519EF04_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

s32 func_1519EF04(u8 *arg0) {
    struct func_1519EF04_s *temp_v1;

    temp_v1 = *(struct func_1519EF04_s **)(arg0 + 0x110);
    *(f32 *)(arg0 + 0x2C) = temp_v1->unk18 * 10.0f;
    *(f32 *)(arg0 + 0x30) = temp_v1->unk1C * 10.0f;
    *(f32 *)(arg0 + 0x40) = temp_v1->unkC;
    *(f32 *)(arg0 + 0x44) = temp_v1->unk10;
    *(f32 *)(arg0 + 0x48) = temp_v1->unk14;
    *(f32 *)(arg0 + 0x34) = temp_v1->unk0;
    *(f32 *)(arg0 + 0x38) = temp_v1->unk4;
    *(f32 *)(arg0 + 0x3C) = temp_v1->unk8;
    return 1;
}
