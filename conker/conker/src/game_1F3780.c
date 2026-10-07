#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C62D0.s")

void func_151C6974(s32 arg0, s32 arg1, s32 arg2) {
    func_151C69CC(arg0, arg2, 0, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C69A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C69CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C6A28.s")

s32 func_15102B38(s32, s32, s32 *, s32 *, f32 *, s32, s32, f32, s32, s32, s32, s32, s32, s32); /* extern */
extern f32 D_800AAC10;
extern f32 D_800AAC14;
extern f32 D_800AAC18;
extern f32 D_800AAC1C;
extern f32 D_800AAC20;
extern u32 D_800AAB00[];
extern s32 D_800AAB08[][3];
extern s32 D_800AAB20[][3];

void func_151C6D70(s32 arg0, u8 arg1, s32 arg2, s16 arg3, u8 arg4, s32 arg5) {
    f32 sp50[2];
    f32 sp4C;
    s32 sp44[2];

    sp50[1] = (func_150ADA68() * D_800AAC10) + D_800AAC14;
    sp50[0] = (func_150ADA68() * D_800AAC18) + D_800AAC1C;
    sp44[0] = func_150ADA20();
    sp44[1] = func_150ADA20();
    sp4C = func_150ADA68();
    func_15102B38(arg0, (D_800AAB00[arg1] >> 6) & 0xFF, D_800AAB08[arg1], D_800AAB20[arg1], sp50, (sp44[0] & 3) + 6, 0xFF, (sp4C * 270.0f) + D_800AAC20, arg2, 0xFF, 0, arg3, arg4, arg5);
}

typedef struct { f32 x, y, z; } func_151C6EA0_v3;
struct func_151C6EA0_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    func_151C6EA0_v3 unk10;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    func_151C6EA0_v3 unk28;
    func_151C6EA0_v3 unk34;
    func_151C6EA0_v3 unk40;
    f32 unk4C;
    s32 unk50;
    s16 unk54;
    s16 unk56;
    u8 unk58;
    s32 unk5C;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    u8 unk68;
    s8 unk69;
    u8 unk6A;
    s32 unk6C;
    u8 unk70;
    s16 unk72;
    s16 unk74;
    s32 unk78;
};
s32 func_1513264C();

void func_151C6EA0(s32 arg0, u8 arg1, s32 arg2) {
    struct func_151C6EA0_s sp34;
    s8 sp30[4];
    s32 temp_v0;

    sp30[0] = 0;
    sp34.unk0 = 1.0f;
    sp34.unk4 = 1.0f;
    sp34.unkC = 1.0f;
    sp34.unk8 = 1.0f;
    sp34.unk10 = *(func_151C6EA0_v3 *)&D_800A5480;
    sp34.unk1C = 1.0f;
    sp34.unk20 = 1.0f;
    sp34.unk24 = 1.0f;
    sp34.unk28 = *(func_151C6EA0_v3 *)&D_800A5480;
    sp34.unk34 = *(func_151C6EA0_v3 *)&D_800A5480;
    sp34.unk40 = *(func_151C6EA0_v3 *)&D_800A5480;
    sp34.unk50 = 0x11900;
    sp34.unk54 = 0x12C;
    sp34.unk56 = 0xF;
    sp34.unk58 = 0;
    sp34.unk5C = 0;
    sp34.unk60 = 0x64;
    sp34.unk61 = 0x17;
    sp34.unk62 = 0;
    sp34.unk63 = 0;
    sp34.unk64 = 0;
    sp34.unk65 = 0;
    sp34.unk66 = 0;
    sp34.unk67 = 0;
    sp34.unk68 = 5;
    sp34.unk69 = -1;
    sp34.unk6A = 1;
    sp34.unk4C = 0.0f;
    sp34.unk6C = arg0;
    sp34.unk70 = *(u8 *)(arg0 + 0x3B);
    sp34.unk72 = 1;
    sp34.unk74 = 0xFF;
    sp34.unk78 = 0;
    temp_v0 = func_1513264C(&sp34, 3, 0xFF, 0, 1, arg1, arg2);
    if (temp_v0 != 0) {
        memcpy(temp_v0 + 0x170, sp30, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F3780/func_151C7038.s")
