#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_151EF610();

struct func_1500F290_s {
    s32 unk0;
    s16 unk4;
    u8 unk6;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    s32 unk18;
    s32 pad1C[3];

};

void func_1500F290(f32 arg0, f32 arg1, f32 arg2) {
    struct func_1500F290_s sp48;
    s32 pad[2];

    sp48.unk6 = 0x38;
    sp48.unk8 = 0;
    sp48.unkC = (func_151EF610() % 4096) + 0x4000;
    sp48.unk0 = 0x20014;
    sp48.unk4 = 1;
    sp48.unk10 = 0xFF;
    sp48.unk11 = 0xFF;
    sp48.unk12 = 0;
    sp48.unk13 = 0;
    sp48.unk14 = 0;
    sp48.unk15 = 0xFF;
    sp48.unk18 = 0x30001;
    func_1513C5B0((s32)&sp48, 0, 0, 0, arg0, arg1, arg2, 110.0f, 110.0f, 0, 0, 0, 0xFF, 0);
}

struct func_1500F378_s {
    u8 pad0[0x28];
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    u8 unk30;
};

void func_1500F378(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_1500F378_s *temp_v0;

    temp_v0 = (struct func_1500F378_s *)func_151491F4((func_150ADA20() & 0x7F) + 0xA, 1, -1, 1, 0, (struct37 *)0xA, 0xFF, 0);
    if (temp_v0 != NULL) {
        temp_v0->unk28 = arg0;
        temp_v0->unk2A = arg1;
        temp_v0->unk2C = arg2;
        temp_v0->unk2E = arg3;
        temp_v0->unk30 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_3C740/func_1500F40C.s")
