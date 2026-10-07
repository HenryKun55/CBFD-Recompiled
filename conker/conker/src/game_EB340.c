#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150BDE90_s {
    s32 unk0;
    s16 unk4;
};

void func_150BDE90(s32 arg0, u8 arg1, s32 arg2) {
    struct func_150BDE90_s sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = 0;
    temp_v0 = func_15149130(0x12C, -1, 0x4F, -1, 0, 0x3C, (struct37 *)8, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp38, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BDF0C.s")

void func_150BE150(struct102 *arg0, s32 *arg1, u8 arg2) {
    s32 temp_v0;

    if (arg2 == 0x21) {
        if (*(s32 *)((u8 *)arg0 + 0x28) == *arg1) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0) {
        temp_v0 = *arg1;
        if (*(s32 *)((u8 *)arg0 + 0x28) == *(s32 *)(temp_v0 + 0x318)) {
            func_1516972C(arg0);
        }
    }
}

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
