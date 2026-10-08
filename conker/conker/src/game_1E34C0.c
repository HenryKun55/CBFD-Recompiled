#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct { f32 x, y, z; } func_151B6010_v3;

struct func_151B6010_s {
    f32 unk0[4];
    func_151B6010_v3 unk10;
    f32 unk1C[3];
    func_151B6010_v3 unk28;
    func_151B6010_v3 unk34;
    func_151B6010_v3 unk40;
    f32 unk4C;
    s32 unk50;
    s16 unk54;
    s16 unk56;
    u8 unk58;
    s32 unk5C;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    s32 unk6C;
    u8 unk70;
    s16 unk72;
    s16 unk74;
    s32 unk78;
};

void *func_15132A4C(void *, s32, s32, s32, s32, s32);
extern f32 D_800AA450;

void *func_151B6010(func_151B6010_v3 *arg0, func_151B6010_v3 *arg1, f32 arg2, func_151B6010_v3 *arg3, func_151B6010_v3 *arg4, f32 arg5, s16 arg6, u8 arg7, s32 arg8, f32 arg9, u8 arg10, u8 arg11, u8 arg12, s32 arg13) {
    void *ret;
    struct func_151B6010_s s;
    f32 sp28[2];
    s32 v;

    sp28[1] = arg2;
    sp28[0] = 0.0f;
    s.unk0[0] = D_800AA450 * arg2;
    s.unk0[1] = arg9;
    s.unk0[3] = arg2;
    s.unk0[2] = arg2;
    s.unk10 = *arg3;
    s.unk1C[0] = 1.0f;
    s.unk1C[1] = 1.0f;
    s.unk1C[2] = 1.0f;
    s.unk28 = *arg0;
    s.unk50 = 0x3900;
    s.unk4C = arg5;
    if (arg6 == -1) {
        s.unk54 = 0x12C;
        v = 0x100 >> arg10;
    } else {
        v = 0x100 >> arg10;
        s.unk54 = arg6 + v;
        s.unk50 = 0x3980;
    }
    if (arg1 != NULL) {
        s.unk34 = *arg1;
        s.unk50 |= 0x20;
    } else {
        s.unk34.x = 0.0f;
        s.unk34.y = 0.0f;
        s.unk34.z = 0.0f;
    }
    if (arg4 != NULL) {
        s.unk40 = *arg4;
        s.unk50 |= 0x40;
    } else {
        s.unk40.x = 0.0f;
        s.unk40.y = 0.0f;
        s.unk40.z = 0.0f;
    }
    if (arg11) {
        s.unk50 |= 1;
    }
    s.unk56 = 3;
    s.unk58 = 0;
    s.unk5C = 0;
    s.unk60 = arg7;
    s.unk61 = 6;
    s.unk62 = 0;
    s.unk63 = 6;
    s.unk64 = 0;
    s.unk65 = 0;
    s.unk66 = 0;
    s.unk67 = 0;
    s.unk68 = 2;
    s.unk6A = 0;
    s.unk6C = 0;
    s.unk70 = 0;
    s.unk72 = v;
    s.unk74 = 0xFF / v;
    ret = func_15132A4C(&s, 3, 0xFF, 8, arg12, arg13);
    if (ret != NULL) {
        memcpy((u8 *)ret + 0x170, sp28, 8);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E34C0/func_151B6254.s")
