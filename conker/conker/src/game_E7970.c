#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150BA4C0_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
};

void func_150BA4C0(u8 *arg0, u8 arg1, s32 arg2) {
    struct func_150BA4C0_s tmp;
    struct260 *temp_v0;

    tmp.unk0 = arg0;
    tmp.unk4 = arg0[0x3B];
    tmp.unk8 = 0.0f;
    temp_v0 = func_15149130((func_150ADA20() % 9U) + 15, -1, 0x52, -1, 1, 0x3F, 0xC, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BA55C.s")

void func_150BA8F0(s32 arg0, s32 arg1, u8 arg2) {
    func_15149514(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

extern f32 D_8009FE60;
s32 func_15046C80(f32 *arg0, s32 arg1, f32 arg2, s32 arg3);

s32 func_150BA930(f32 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    f32 sp24[3];

    arg0[0] = *(f32 *)(arg1 + 0x14);
    if (D_8009FE60 < *(f32 *)(arg1 + 0x180)) {
        arg0[1] = *(f32 *)(arg1 + 0x180);
    } else {
        arg0[1] = *(f32 *)(arg1 + 0x18);
    }
    arg0[2] = *(f32 *)(arg1 + 0x1C);
    if (arg2 == 0) {
        return 1;
    }
    sp24[0] = arg0[0];
    sp24[1] = arg0[1] + 100.0f;
    sp24[2] = arg0[2];
    func_1504715C(arg2);
    return func_15046C80(sp24, 0, arg0[1] - 100.0f, arg2);
}

s32 func_150BAA00(s32 arg0, s32 arg1) {
    return 9;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BAA14.s")
