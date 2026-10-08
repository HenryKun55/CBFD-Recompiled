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

void func_15143E94(s32, s32);
void func_1514C678(f32, f32, f32, f32, s32, s32, s32, s32, s32, f32, s32, s32);
void func_15165F80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7, s32 arg8);
extern f32 D_8009FE64;

void func_150BAA14(u8 *arg0, u8 arg1, s32 arg2) {
    f32 pos[3];
    u8 sp48[0x24];
    s32 sp44;
    u8 sp43;
    s16 pad1;
    u8 pad2;

    if (*(s32 *)(arg0 + 0x1D4) == 0) {
        return;
    }
    sp43 = func_150BA930(pos, arg0, (s32)sp48, arg1);
    func_151D5404(pos, 1307.0f, 2000.0f, 0.0005f, 0xC, 0xF, 0xFF, 0);
    func_15143E94(5, 0x4022);
    if (sp43 != 0) {
        sp44 = D_800DBFF0[D_80082FA4].unk380 * D_8009FE64;
        func_15165F80(-1, pos[0], pos[1] + 6.0f, pos[2], 0x19, 0x12, 0, 0xFF, 1);
        func_1514C678(pos[0], pos[1], pos[2], (func_150ADA68() * 50.0f) + 40.0f, sp44 + 0x3C, sp44 - 0x3C, (func_150ADA20() % 11U) + 0x1E, 5, 0, 0.0f, 0, 0xFF);
    }
}
