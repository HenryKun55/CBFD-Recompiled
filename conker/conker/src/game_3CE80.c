#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1500F9D0_s {
    u8 pad0[0x28];
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    u8 unk30;
};

void func_1500F9D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct func_1500F9D0_s *temp_v0;

    temp_v0 = (struct func_1500F9D0_s *)func_151491F4((func_150ADA20() & 0x7F) + 0xA, 1, -1, 1, 0, (struct37 *)0xA, 0xFF, 0);
    if (temp_v0 != NULL) {
        temp_v0->unk28 = arg0;
        temp_v0->unk2A = arg1;
        temp_v0->unk2C = arg2;
        temp_v0->unk2E = arg3;
        temp_v0->unk30 = arg4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_3CE80/func_1500FA64.s")
