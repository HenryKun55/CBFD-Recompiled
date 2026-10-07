#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A1B40/func_15174690.s")

struct func_15174920_s {
    u8 pad0[0x14];
    s32 unk14;
    u32 unk18;
    u8 pad1C[0x34 - 0x1C];
    s16 unk34;
    s16 unk36;
    s16 unk38;
    u8 pad3A[0x3F - 0x3A];
    u8 unk3F;
};

void func_15174920(struct func_15174920_s *arg0) {
    s32 v;

    v = arg0->unk3F;
    if (v > 200) {
        v = 200;
    }
    v -= D_800BE9E4 * arg0->unk18;
    if (v < 0) {
        arg0->unk38 = 0;
        return;
    }
    arg0->unk3F = v;
    arg0->unk34 += arg0->unk14;
    arg0->unk36 += (arg0->unk14 * 8) / 7;
}
