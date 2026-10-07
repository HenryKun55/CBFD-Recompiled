#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    f32 x, y, z;
} func_15191BE0_v;

struct func_15191BE0_s {
    u8 *unk0;
    u8 unk4;
    func_15191BE0_v unk8;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 unk24[0x24];
    f32 unk48;
    f32 unk4C;
    s16 unk50;
    s16 unk52;
    u8 unk54;
    u8 unk55;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    u8 unk64;
};

struct260 *func_15191BE0(u8 *arg0, func_15191BE0_v *arg1, u8 arg2, f32 arg3, f32 arg4, s16 arg5, f32 arg6, f32 arg7, s16 arg8, s16 arg9, u8 arg10, u8 arg11, f32 arg12, f32 arg13, f32 arg14, u8 arg15, u8 arg16, s32 arg17) {
    struct260 *ret;
    struct func_15191BE0_s s;

    if (arg0 == NULL) {
        return NULL;
    }
    s.unk0 = arg0;
    s.unk4 = arg0[0x3B];
    s.unk8 = *arg1;
    s.unk14 = arg2 << 6;
    s.unk1C = arg3;
    s.unk18 = 0.0f;
    s.unk20 = arg4;
    func_1504715C(s.unk24, arg0);
    s.unk48 = arg6;
    s.unk4C = arg7;
    s.unk50 = arg8;
    s.unk52 = arg9;
    s.unk54 = arg10;
    s.unk55 = arg11;
    s.unk58 = arg12;
    s.unk5C = arg13;
    s.unk60 = arg14;
    s.unk64 = arg15;
    ret = func_15149130((arg5 == -1) ? 300 : arg5, -1, 0x1D, -1, (arg5 == -1) ? 0 : 1, 0x1D, (struct37 *)0x68, arg16, arg17);
    if (ret != NULL) {
        memcpy((char *)ret + 0x28, &s, 0x68);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15191D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_1519203C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15192308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15192358.s")

u8 func_15192308(s32 arg0, s32 arg1);
u8 func_15192358(s32 arg0, s32 arg1);

u8 func_1519257C(s32 arg0, s32 arg1) {
    u8 ret;

    ret = func_15192308(arg0, arg1);
    if (ret) {
        ret = func_15192358(arg0, arg1);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_151925C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_1519277C.s")
