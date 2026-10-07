#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void *allocate_memory(s32, s32, s32, s32);

struct func_1503B7C0_s {
    u8 pad0[0x44];
    f32 unk44;
    u8 pad48[4];
    s16 unk4C;
};

void func_1503B7C0(u8 *arg0) {
    (*(struct func_1503B7C0_s **)(*(u8 **)(arg0 + 0x31C) + 0x11C)) = allocate_memory(0x50, 1, 0, 0);
    bzero(*(struct func_1503B7C0_s **)(*(u8 **)(arg0 + 0x31C) + 0x11C), 0x50);
    (*(struct func_1503B7C0_s **)(*(u8 **)(arg0 + 0x31C) + 0x11C))->unk44 = 30.0f;
    (*(struct func_1503B7C0_s **)(*(u8 **)(arg0 + 0x31C) + 0x11C))->unk4C = (u32) func_150ADA20() % 30;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_68C70/func_1503B840.s")

extern u8 D_800CC5CB[];

s32 func_1503B95C(s32 arg0, u8 *arg1) {
    s32 temp_v0;

    temp_v0 = D_800CC5CB[arg0 * 0x32C];
    if (temp_v0 & 2) {
        arg1[0x4E] = 0;
        return 0;
    }
    if (temp_v0 & 1) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_68C70/func_1503B9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_68C70/func_1503CB98.s")
