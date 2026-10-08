#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FB060/func_150CDBB0.s")

struct func_150CDCF4_s {
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
    f32 unk30;
    f32 unk34;
    f32 unk38;
    u8 pad3C[0xC];
    f32 unk48[3];
    f32 unk54;
    s32 unk58;
    u8 pad5C[4];
    s8 unk60;
    s8 unk61;
    s8 unk62;
    s8 unk63;
    u8 pad64[0x10];
};

void *func_15130374(struct func_150CDCF4_s *, s32, s32, u8, s32);
void func_15143794(s16, s16, f32, f32 *);
extern f32 D_800A07B4;
extern f32 D_800A07B8;
extern f32 D_800A07BC;
extern f32 D_800A07C0;

s32 func_150CDCF4(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, u8 arg14) {
    struct func_150CDCF4_s sp34;
    void *temp_v0;
    f32 sp2C;
    f32 temp_f2;
    u32 sp24;

    sp34.unk1D = 0x29;
    sp34.unk8 = 0xE03;
    sp34.unk0 = 0x200005;
    sp34.unk4 = 0;
    sp34.unkA = (func_150ADA20() % 41U) + 0x32;
    sp34.unkC = 0;
    sp34.unk10 = 0;
    sp34.unk18 = 0xB0;
    sp34.unk19 = 0xA0;
    sp34.unk1A = 0x2A;
    sp34.unk14 = 0x40;
    sp34.unk15 = 0xB;
    sp34.unk16 = 0x6A;
    sp34.unk17 = 0xFF;
    sp34.unk1B = (func_150ADA20() % 101U) + 0x64;
    sp34.unk1C = 0xFF;
    sp34.unk60 = 3;
    sp34.unk61 = 3;
    temp_f2 = (func_150ADA68() * D_800A07B4) + 404.0f;
    sp34.unk30 = arg2;
    sp34.unk34 = arg3;
    sp34.unk38 = arg4;
    sp34.unk28 = temp_f2;
    sp34.unk2C = temp_f2;
    sp24 = func_150ADA20();
    func_15143794(arg8, (sp24 % 20U) - 0x13, ((func_150ADA68() * 150.0f) + 150.0f) * D_800A07B8, sp34.unk48);
    sp34.unk58 = 0xE05;
    sp34.unk54 = 0.0f;
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x40;
    }
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x80;
    }
    sp34.unk62 = 0xA;
    sp34.unk63 = -1;
    sp34.unk1E = 0x1E;
    sp34.unk20 = 8;
    sp34.unk22 = 0x46;
    sp34.unk24 = D_800A07BC;
    sp2C = D_800A07C0;
    temp_v0 = func_15130374(&sp34, 1, 4, arg14, 1);
    if (temp_v0 != 0) {
        memcpy((u8 *)temp_v0 + 0xA8, &sp2C, 4);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FB060/func_150CDF10.s")
