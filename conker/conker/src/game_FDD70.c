#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D08C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D0E90.s")

struct func_150D10E4_s {
    u8 unk0;
    u8 pad1[3];
    void *unk4;
    s8 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s8 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s8 unk2E;
    s8 unk2F;
    s8 unk30;
    f32 unk34;
    s8 unk38;
    s8 unk39;
};
extern f32 D_800A0890;
void *func_15134DAC();

void func_150D10E4(u8 *arg0, u8 arg1) {
    struct func_150D10E4_s sp1C;

    sp1C.unk0 = arg0[0x3B];
    sp1C.unk4 = arg0;
    sp1C.unk8 = 0;
    sp1C.unkC = 0.0f;
    sp1C.unk10 = 0.0f;
    sp1C.unk14 = 0.0f;
    sp1C.unk18 = 0.0f;
    if (arg1) {
        sp1C.unk1C = -30.0f;
    } else {
        sp1C.unk1C = 30.0f;
    }
    sp1C.unk20 = 0.0f;
    sp1C.unk24 = 2;
    sp1C.unk26 = 0x32;
    sp1C.unk28 = 0x16;
    sp1C.unk2A = 0x7D0;
    sp1C.unk2C = 0;
    sp1C.unk2E = 6;
    sp1C.unk2F = 7;
    sp1C.unk30 = -1;
    sp1C.unk38 = 0;
    sp1C.unk39 = -1;
    sp1C.unk34 = D_800A0890;
    func_15134DAC(&sp1C, 0);
}

extern f32 D_800A0894;

s32 func_150D11B4(void *arg0) {
    *(f32 *)((char *) arg0 + 0x74) = (func_150ADA68() * 150.0f + 350.0f) * D_800A0894;
    return 1;
}

extern f32 D_800A0898;
extern f32 D_800A089C;
extern f32 D_800A08A0;
extern f32 D_800A08A4;
void func_151DB5D0(s32, f32 *, f32 *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32);

void func_150D1204(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4, u8 *arg5) {
    f32 sp6C[3];
    f32 x, y, z;
    f32 sp54[3];
    u32 sp50;
    u32 sp4C;
    f32 sp48;
    f32 sp44;

    sp6C[0] = arg2[0] * arg4 + arg0[0];
    sp6C[1] = arg2[1] * arg4 + arg0[1];
    sp6C[2] = arg2[2] * arg4 + arg0[2];
    x = arg3[0] * arg4 + arg1[0];
    y = arg3[1] * arg4 + arg1[1];
    z = arg3[2] * arg4 + arg1[2];
    sp54[0] = *(f32 *)(arg5 + 0x74) * (x - sp6C[0]);
    sp54[1] = *(f32 *)(arg5 + 0x74) * (y - sp6C[1]);
    sp54[2] = *(f32 *)(arg5 + 0x74) * (z - sp6C[2]);
    sp44 = func_150ADA68();
    sp48 = func_150ADA68();
    sp4C = func_150ADA20();
    sp50 = func_150ADA20();
    func_151DB5D0(0, sp6C, sp54, sp44 * 61.0f + 60.0f, D_800A0898, D_800A089C,
                  sp48 * D_800A08A0 + D_800A08A4, (sp4C & 0xF) + 0x23,
                  sp50 % 156 + 100, 30, 8, 0, arg5[0xC], arg5[1]);
}
