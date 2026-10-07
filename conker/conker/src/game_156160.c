#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_156160/func_15128CB0.s")

struct func_151298C0_s {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
    u8 pad[0x24 - 0xC];
};
extern struct func_151298C0_s D_800DC028[];
extern f32 D_800A3610;

void func_151298C0(u8 *arg0, s32 arg1) {
    if (D_80089550 != 0) {
        D_800DC028[arg0[0x23D]].unk2 = 0;
        D_800DC028[arg0[0x23D]].unk4 = -1.0f;
        D_800DC028[arg0[0x23D]].unk8 = D_800A3610;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_156160/func_15129934.s")
