#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0B10/func_15193660.s")

extern f32 D_800A81E4;
void *func_15134DAC();

struct func_151937F4_s {
    u8 unk0;
    u8 pad1[3];
    void *unk4;
    s8 unk8;
    u8 pad9[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s8 unk24;
    u8 pad25;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    u8 pad2C[2];
    s8 unk2E;
    s8 unk2F;
    s8 unk30;
    u8 pad31[3];
    f32 unk34;
    s8 unk38;
    s8 unk39;
    u8 pad3A[2];
};

void func_151937F4(void *arg0, s32 arg1, s32 arg2) {
    struct func_151937F4_s sp1C;

    if ((arg0 != NULL) && (*(s32 *)arg0 != 0)) {
        sp1C.unk0 = *((u8 *)arg0 + 0x3B);
        sp1C.unkC = -28.0f;
        sp1C.unk4 = arg0;
        sp1C.unk8 = 0;
        sp1C.unk24 = 2;
        sp1C.unk26 = 0x1E;
        sp1C.unk28 = 0x19;
        sp1C.unk2A = 0x2EE;
        sp1C.unk2E = 3;
        sp1C.unk2F = 3;
        sp1C.unk30 = -1;
        sp1C.unk38 = 4;
        sp1C.unk39 = -1;
        sp1C.unk10 = 6.0f;
        sp1C.unk14 = 1.0f;
        sp1C.unk18 = -58.0f;
        sp1C.unk1C = -3.0f;
        sp1C.unk20 = -31.0f;
        sp1C.unk34 = D_800A81E4;
        func_15134DAC(&sp1C, 0, arg0);
    }
}

extern f32 D_800A81E8;

s32 func_151938E4(void *arg0) {
    *(f32 *)((char *)arg0 + 0x74) = D_800A81E8;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0B10/func_151938FC.s")
