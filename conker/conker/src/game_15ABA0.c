#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1512D6F0_s {
    u8 pad0[0x28];
    f32 unk28;
    f32 unk2C;
    u8 pad30[0x20];
    s32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    u8 pad64[4];
};
extern struct func_1512D6F0_s D_800DC2C0[];

void func_1512D6F0(u8 *arg0) {
    struct func_1512D6F0_s *temp_v0 = &D_800DC2C0[arg0[0x23D]];
    temp_v0->unk50 = 5;
    temp_v0->unk54 = 0.0f;
    temp_v0->unk58 = 0.0f;
    temp_v0->unk5C = 0.0f;
    temp_v0->unk60 = 0.0f;
    temp_v0->unk2C = 0.0f;
    temp_v0->unk28 = -1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15ABA0/func_1512D748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15ABA0/func_1512D980.s")
