#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12FDD0/func_15102920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12FDD0/func_15102B38.s")

void func_15102D50(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x110, arg0 + 0x114, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12FDD0/func_15102D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12FDD0/func_15102EB8.s")

s32 func_15130374(void *, s32, s32, u8, s32);
extern s32 D_80088BD0[];

struct func_15103254_vec { f32 x, y, z; };

struct func_15103254_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14[8];
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    struct func_15103254_vec unk30;
    f32 unk3C[7];
    s32 unk58;
    s32 unk5C;
    u8 unk60;
    u8 unk61;
    s8 unk62;
    s8 unk63;
    s8 unk64;
    u8 unk65;
    u8 unk66;
    u8 pad67[9];
};

void func_15103254(s16 arg0, u8 arg1, f32 arg2, struct func_15103254_vec *arg3, u8 arg4, u8 arg5, s32 arg6) {
    s32 var_v0;
    struct func_15103254_s sp2C;
    s32 pad2;
    s32 var_v1;

    sp2C.unk1D = D_80088BD0[func_150ADA20() & 3];
    sp2C.unk8 = 0x2203;
    sp2C.unk0 = 0x200005;
    sp2C.unk4 = 0x20000;
    sp2C.unkA = arg0 + 1;
    sp2C.unk14[0] = 0xFF;
    sp2C.unkC = 0;
    sp2C.unk10 = 0;
    sp2C.unk14[1] = 0xFF;
    sp2C.unk14[2] = 0xFF;
    sp2C.unk14[3] = 0xFF;
    sp2C.unk14[4] = 0xFF;
    sp2C.unk14[5] = 0xFF;
    sp2C.unk14[6] = 0xFF;
    sp2C.unk14[7] = arg1;
    sp2C.unk1C = 0xFF;
    sp2C.unk28 = sp2C.unk2C = arg2;
    sp2C.unk30 = *arg3;
    sp2C.unk1E = 3;
    sp2C.unk20 = 0x55;
    sp2C.unk22 = 1;
    sp2C.unk3C[0] = 0.0f;
    sp2C.unk3C[1] = 0.0f;
    sp2C.unk3C[2] = 0.0f;
    sp2C.unk3C[3] = 0.0f;
    sp2C.unk3C[4] = 0.0f;
    sp2C.unk3C[5] = 0.0f;
    sp2C.unk3C[6] = 0.0f;
    sp2C.unk24 = 1.0f;
    var_v1 = (func_150ADA20() & 1) ? 0x40 : 0;
    var_v0 = (func_150ADA20() & 1) ? 0x80 : 0;
    sp2C.unk58 = var_v0 | 1 | var_v1 | 0x4000 | 0x8000 | 0x200 | 0x40000 | 0x800000;
    sp2C.unk60 = 6;
    sp2C.unk61 = 8;
    sp2C.unk62 = -1;
    sp2C.unk63 = -1;
    sp2C.unk64 = -1;
    sp2C.unk65 = 0;
    sp2C.unk66 = arg4;
    func_15130374(&sp2C, 1, 0, arg5, arg6);
}
