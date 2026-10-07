#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B89E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B8F44.s")

extern f32 D_8009FDD4;
extern f32 D_8009FDD8;
extern f32 D_8009FDDC;

struct func_150B9560_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x38 - 0x34];
    f32 unk38;
    u8 pad3C[0x110 - 0x3C];
    f32 unk110;
};

s32 func_150B9560(struct func_150B9560_s *arg0) {
    f32 *p = &arg0->unk110;
    f32 temp;

    if (arg0->unk1C < 0x50) {
        *p += D_8009FDD4 * D_800BE9A4;
        arg0->unk38 -= *p;
    }
    if (arg0->unk1C >= 0x73) {
        temp = D_8009FDD8;
        arg0->unk2C *= temp;
        arg0->unk30 *= temp;
    } else if (arg0->unk1C < 0x41) {
        arg0->unk30 += D_8009FDDC;
    }
    return 1;
}

struct func_150B95FC_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_150B95FC(struct func_150B95FC_s *arg0) {
    if (arg0->unk1C < 0x20) {
        arg0->unk5C = arg0->unk1C * 8;
    }
    return 1;
}

struct func_150B961C_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150B961C(struct func_150B961C_s *arg0) {
    if (arg0->unk1C < 0x40) {
        arg0->unk28 = arg0->unk1C * 4;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B963C.s")

struct func_150B9D14_s {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    s32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

void func_15142600(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);

s32 func_150B9D14(s32 arg0, struct func_150B9D14_s *arg1) {
    func_15142600(arg0, arg1->unk18, arg1->unk1C, arg1->unk2C, arg1->unk30, arg1->unk34, arg1->unk38, arg1->unk3C, arg1->unk40, arg1->unk20, arg1->unk24, arg1->unk28);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9D8C.s")
