#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A0490;
void *func_15134DAC();
void func_1516962C();

struct func_150C7020_s {
    u8 unk0;
    void *unk4;
    s8 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s8 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s8 unk2E;
    s8 unk2F;
    s8 unk30;
    f32 unk34;
    s8 unk38;
    s8 unk39;
    u8 pad3A[2];
};

void func_150C7020(arg0, arg1, arg2, arg3)
    u8 *arg0;
    s16 arg1;
    s32 arg2;
    s32 arg3;
{
    struct func_150C7020_s sp1C;
    s32 pad;

    if (arg0 != NULL) {
        func_1516962C(0x29, arg0, 0x12);
        sp1C.unk0 = arg0[0x3B];
        sp1C.unk4 = arg0;
        sp1C.unk8 = 13;
        sp1C.unk10 = 0.0f;
        sp1C.unk1C = 0.0f;
        sp1C.unk14 = 34.0f;
        sp1C.unk20 = 34.0f;
        sp1C.unkC = 2.0f;
        sp1C.unk18 = -15.0f;
        sp1C.unk24 = 0;
        sp1C.unk2E = -1;
        sp1C.unk2F = 1;
        sp1C.unk30 = -1;
        sp1C.unk34 = D_800A0490;
        sp1C.unk38 = 2;
        sp1C.unk39 = -1;
        if (arg1 != 0) {
            sp1C.unk2A = arg1;
            sp1C.unk24 = 2;
        } else {
            sp1C.unk2A = 300;
        }
        sp1C.unk26 = func_150ADA20() % 66U + 35;
        sp1C.unk28 = func_150ADA20() % 26U + 25;
        func_15134DAC(&sp1C, 0);
        sp1C.unk8 = 12;
        sp1C.unk14 = 34.0f;
        sp1C.unk20 = 34.0f;
        sp1C.unkC = -2.0f;
        sp1C.unk10 = 0.0f;
        sp1C.unk1C = 0.0f;
        sp1C.unk18 = 15.0f;
        sp1C.unk26 = func_150ADA20() % 66U + 35;
        sp1C.unk28 = func_150ADA20() % 26U + 25;
        func_15134DAC(&sp1C, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F44D0/func_150C71C0.s")
