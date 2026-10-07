#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BDE90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BDF0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE150.s")

struct func_150BE1C4_s {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[0x80 - 0x18];
    f32 unk80;
};

s32 func_150BE1C4(struct func_150BE1C4_s *arg0) {
    arg0->unk14 += arg0->unk80 * D_800BE9A4;
    if (arg0->unk14 > 120.0f) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE2E8.s")

s16 *func_150BE438(s16 *arg0, s32 arg1) {
    struct127 *obj;

    obj = &gObjects[arg1];
    arg0[0] = 0x68;
    arg0[1] = obj->unk2E8;
    arg0[2] = 0xE;
    arg0[3] = obj->unk2E4;
    return arg0 + 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE494.s")
