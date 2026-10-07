#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D08C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D0E90.s")

struct func_150D10E4_s {
    u8 unk0;
    u8 pad1[3];
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
};
extern f32 D_800A0890;
void *func_15134DAC();

void func_150D10E4(u8 *arg0, u8 arg1) {
    struct func_150D10E4_s sp1C;

    sp1C.unk0 = arg0[0x3B];
    sp1C.unk4 = arg0;
    sp1C.unk8 = 0;
    sp1C.unkC = 0.0f;
    sp1C.unk10 = 0.0f;
    sp1C.unk14 = 0.0f;
    sp1C.unk18 = 0.0f;
    if (arg1) {
        sp1C.unk1C = -30.0f;
    } else {
        sp1C.unk1C = 30.0f;
    }
    sp1C.unk20 = 0.0f;
    sp1C.unk24 = 2;
    sp1C.unk26 = 0x32;
    sp1C.unk28 = 0x16;
    sp1C.unk2A = 0x7D0;
    sp1C.unk2C = 0;
    sp1C.unk2E = 6;
    sp1C.unk2F = 7;
    sp1C.unk30 = -1;
    sp1C.unk38 = 0;
    sp1C.unk39 = -1;
    sp1C.unk34 = D_800A0890;
    func_15134DAC(&sp1C, 0);
}

extern f32 D_800A0894;

s32 func_150D11B4(void *arg0) {
    *(f32 *)((char *) arg0 + 0x74) = (func_150ADA68() * 150.0f + 350.0f) * D_800A0894;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D1204.s")
