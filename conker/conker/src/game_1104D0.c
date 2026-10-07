#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3020.s")

s32 func_150AD9A0(s32, s32, s32);
void *func_150E3020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, s32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12, s16 arg13);

s32 func_150E3208(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u8 *temp_v0;

    temp_v0 = func_150E3020(arg0, arg1, arg2, arg3, arg4, arg5, arg6, (f32) func_150AD9A0(arg0 - arg3, arg1 - arg4, arg2 - arg5) / (f32) arg7, 0, 0.0f, 0.0f, 0.0f, 0, -0x63);
    if (temp_v0 != NULL) {
        return temp_v0[0x48] + 1;
    }
    return 0;
}

void *func_150E3020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, s32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12, s16 arg13);

s32 func_150E32D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    u8 *temp_v0;

    temp_v0 = func_150E3020(arg0, arg1, arg2, 0, 0, 0, arg4, arg5, arg3, 0.0f, 0.0f, 0.0f, 0, -0x63);
    if (temp_v0 != NULL) {
        return temp_v0[0x48] + 1;
    }
    return 0;
}

void *func_150E3020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, s32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12, s16 arg13);

void func_150E3340(f32 *arg0, s32 *arg1, s32 arg2, s16 arg3) {
    s32 a = arg1[0];
    s32 b = arg1[1];
    s32 c = arg1[2];
    func_150E3020(a, b, c, a, b, c, 0x1A, 10.0f, 0, arg0[0], arg0[1], arg0[2], arg2, arg3);
}

s32 func_150E33CC(s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    if (*arg2 == 0) {
        return 1;
    }
    func_1000E7A0(2, (u32)*arg2);
    return 0;
}

s32 func_150E3414(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8) {
    u8 *temp_v0;

    temp_v0 = func_150E3020(arg3, arg4, arg5, 0, 0, 0, arg7, arg8, arg6, arg0, arg1, arg2, 0, -0x63);
    if (temp_v0 != NULL) {
        *(u16 *)(temp_v0 + 0x4A) = func_1000FA64(0x2D0, arg0, arg1, arg2, 0x5DC0, 0x1770, 0x3E8, (s32)func_150E33CC, 0, 0, 0, 0);
        return temp_v0[0x48] + 1;
    }
    return 0;
}

struct func_150E3514_s {
    u8 pad0[0x28];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x14];
    u8 unk48;
    u8 pad49;
    u16 unk4A;
};

void func_150E3514(struct func_150E3514_s *arg0) {
    s32 idx = arg0->unk48;

    if (idx >= 0) {
        if (arg0 == (struct func_150E3514_s *)D_800D99D0[idx]) {
            D_800D99D0[idx] = 0;
        }
    }
    if (arg0->unk4A != 0) {
        func_100111C8(arg0->unk4A);
        arg0->unk4A = 0;
        func_10010F88(0x2D7, 0x5DC0, 0, 0, 0, arg0->unk28, arg0->unk2C, arg0->unk30, 1000, 6000);
    }
    func_1516972C((struct102 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E35DC.s")

void func_150E36BC(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u8 *temp_v0;

    arg0--;
    if ((arg0 >= 0) && (arg0 < 8)) {
        temp_v0 = (u8 *)D_800D99D0[arg0];
        if ((temp_v0 != NULL) && (*temp_v0 == 0x27)) {
            *arg1 = *(f32 *)(temp_v0 + 0x10);
            *arg2 = *(f32 *)(temp_v0 + 0x14);
            *arg3 = *(f32 *)(temp_v0 + 0x18);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3738.s")

extern f32 D_800A1050;
void func_1505D1C4(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6, s32 arg7);

void func_150E4010(u8 *arg0) {
    u8 *temp_v0 = arg0 + 0x110;

    if (*(s32 *)(arg0 + 0x1B4) != 0) {
        f32 temp_f0 = func_150484A0(*(f32 *)(temp_v0 + 0x60), *(f32 *)(temp_v0 + 0x64));
        func_1505D1C4(*(f32 *)(temp_v0 + 0x30), *(f32 *)(temp_v0 + 0x34), *(f32 *)(temp_v0 + 0x38),
                      *(s32 *)(temp_v0 + 0xA4) | 0x60000, -1, ((u16)(temp_f0 * D_800A1050) - 0x4000) | 1, 0, 0);
    }
}

extern f32 D_800A1054;
void func_151C3B0C(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6, u8 arg7);

void func_150E411C(void *arg0) {
    func_151C3B0C(arg0, 0.35200002789497375f, 0.7010000348091125f, 0.5660000443458557f, D_800A1054, 0xFF, 0xFF, 0xFF);
}

s32 func_150E4174(f32 *arg0) {
    arg0[11] += arg0[19] * D_800BE9A4;
    arg0[12] += arg0[21] * D_800BE9A4;
    return 1;
}
