#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151B8B40_s {
    u8 pad0[0x20];
    f32 unk20;
    u8 pad24[0x28 - 0x24];
    f32 unk28;
    u8 pad2C[0x3C - 0x2C];
    f32 unk3C;
    u8 pad40[0x44 - 0x40];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    u8 pad54[0x58 - 0x54];
    f32 unk58;
    f32 unk5C;
};

f32 sinf(f32);

s32 func_151B8B40(struct func_151B8B40_s *arg0) {
    arg0->unk3C = (sinf(arg0->unk44) * arg0->unk5C) + arg0->unk48;
    arg0->unk44 = arg0->unk44 + (arg0->unk4C * D_800BE9A4);
    arg0->unk44 = func_15144B68(arg0->unk44);
    arg0->unk20 = arg0->unk20 + (arg0->unk50 * D_800BE9A4);
    arg0->unk28 = arg0->unk28 + (arg0->unk58 * D_800BE9A4);
    return 1;
}

struct func_151B8BE0_s {
    u8 pad0[0x44];
    f32 unk44;
    u8 pad48[0x58 - 0x48];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
};

f32 sinf(f32);
void func_151D9450(struct func_151B8BE0_s *arg0, s32 arg1);

void func_151B8BE0(struct func_151B8BE0_s *arg0, s32 arg1) {
    arg0->unk44 = (sinf(arg0->unk58) * arg0->unk64) + arg0->unk5C;
    arg0->unk58 = arg0->unk58 + (arg0->unk60 * D_800BE9A4);
    arg0->unk58 = func_15144B68(arg0->unk58);
    func_151D9450(arg0, arg1);
}

struct func_151B8C54_sub {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

struct func_151B8C54_s {
    u8 pad0[0x58];
    f32 unk58;
    u8 pad5C[0x120 - 0x5C];
    struct func_151B8C54_sub unk120;
};

s32 func_151B8C54(struct func_151B8C54_s *arg0) {
    struct func_151B8C54_sub *sub;

    sub = &arg0->unk120;
    arg0->unk58 = (sinf(sub->unk10) * sub->unk28) + sub->unk14;
    sub->unk10 = sub->unk10 + (sub->unk18 * D_800BE9A4);
    sub->unk10 = func_15144B68(sub->unk10);
    sub->unk0 = sub->unk0 + (sub->unk1C * D_800BE9A4);
    sub->unk8 = sub->unk8 + (sub->unk24 * D_800BE9A4);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E5FF0/func_151B8CFC.s")
