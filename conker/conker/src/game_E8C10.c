#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BB760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BBB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BC488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BCBBC.s")

extern f32 D_8009FEF8;

struct func_150BCFB8_s {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x3C - 0x18];
    f32 unk3C;
    u8 pad40[4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[4];
    s32 unk60;
};

s32 func_150BCFB8(struct func_150BCFB8_s *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    f32 temp_f2;

    arg0->unk3C = arg0->unk10 * D_8009FEF8 + arg4;
    if (arg0->unk48 > -2.0f) {
        arg0->unk44 = 0.0f;
        arg0->unk60 &= ~0x6F;
        arg0->unk48 = 0.0f;
        arg0->unk4C = 0.0f;
    } else {
        temp_f2 = arg0->unk14;
        arg0->unk44 *= temp_f2;
        arg0->unk48 = -arg0->unk48 * temp_f2;
        arg0->unk4C *= temp_f2;
        arg0->unk50 *= temp_f2;
        arg0->unk54 *= temp_f2;
        arg0->unk58 *= temp_f2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BD070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BD740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BD954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BDB3C.s")
