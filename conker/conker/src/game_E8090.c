#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BABE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BAFEC.s")

struct func_150BB260_s {
    u8 pad0[0x58];
    f32 unk58;
    u8 pad5C[4];
    f32 unk60;
    u8 pad64[0xA8 - 0x64];
    f32 unkA8;
};

s32 func_150BB260(struct func_150BB260_s *arg0, s32 arg1) {
    s32 i;
    f32 *p = &arg0->unkA8;

    for (i = D_800BE9E4; i != 0; i--) {
        arg0->unk58 *= *p;
        arg0->unk60 *= *p;
    }
    return 1;
}

struct func_150BB408_s {
    u8 pad0[0x18];
    s32 unk18;
    s16 unk1C;
    u8 pad1E[0x81 - 0x1E];
    u8 unk81;
    u8 pad82[0xB0 - 0x82];
    s16 unkB0;
    s16 unkB2;
};

void func_1513F6C0(struct func_150BB408_s *arg0, u8 arg1, u8 arg2);

void func_150BB408(struct func_150BB408_s *arg0) {
    arg0->unk18 |= 1;
    arg0->unk1C = 50;
    arg0->unkB0 = arg0->unk1C;
    arg0->unkB2 = 5;
    func_1513F6C0(arg0, 6, arg0->unk81);
}

struct func_150BB450_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
    u8 pad29[0xB0 - 0x29];
    s16 unkB0;
    s16 unkB2;
};

s32 func_150BB450(struct func_150BB450_s *arg0) {
    s16 tmp;
    if (arg0->unk1C < arg0->unkB0) {
        tmp = arg0->unk1C * arg0->unkB2;
        if (tmp < arg0->unk28) {
            arg0->unk28 = tmp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BB498.s")
