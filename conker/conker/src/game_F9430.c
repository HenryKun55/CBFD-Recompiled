#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CBF80.s")

struct func_150CC638_sub {
    s16 unk0;
    f32 unk4;
};

struct func_150CC638_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    u8 unk5C;
    u8 pad5D[0x128 - 0x5D];
    struct func_150CC638_sub unk128;
};

s32 func_150CC638(struct func_150CC638_s *arg0) {
    struct func_150CC638_sub *sub;
    f32 temp;
    s32 v;

    if (arg0->unk58 & 1) {
        sub = &arg0->unk128;
        if (arg0->unk1C < 0x20) {
            v = arg0->unk1C * 8;
            if (v < arg0->unk5C) {
                arg0->unk5C = v;
            }
        }
        if (sub->unk0 < arg0->unk1C) {
            temp = sub->unk4 * D_800BE9A4;
            arg0->unk2C += temp;
            arg0->unk30 += temp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CC6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CC8D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CCA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CCCB4.s")
