#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800D9900;

struct func_150D2110_s {
    u8 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 unk15;
};

void func_150D2110(s16 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6) {
    struct func_150D2110_s tmp;
    struct260 *temp_v0;

    D_800D9900++;
    tmp.unk8 = arg1;
    tmp.unkC = arg2;
    tmp.unk10 = arg1 + arg2;
    tmp.unk0 = 0;
    tmp.unk4 = 0.0f;
    tmp.unk14 = arg3;
    tmp.unk15 = arg4;
    temp_v0 = func_15149130(arg0, -1, 0x2F, 2, 1, 0x26, 0x18, arg5, arg6);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0x18);
    }
}

struct func_150D21CC_s {
    u8 flag;
    u8 pad1[3];
    f32 cur;
    f32 thresh;
    f32 unkC;
    f32 wrap;
};

void func_150D21CC(u8 *arg0) {
    struct func_150D21CC_s *s;

    s = (struct func_150D21CC_s *)(arg0 + 0x28);
    s->cur += D_800BE9A4;
    while (s->wrap < s->cur) {
        s->cur -= s->wrap;
    }
    if (s->cur <= s->thresh) {
        s->flag = 1;
        func_1515D4D4(0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        s->flag = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D227C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D22A8.s")

extern u8 D_800D9900;

void func_150D22D4(s32 arg0) {
    D_800D9900--;
}

void *func_1517F08C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void *func_150D22F4(void *arg0, u8 *arg1, s16 arg2) {
    if (arg1[0x28] == 1) {
        arg0 = func_1517F08C(arg0, arg1[0x3C], 0xFF, 0xFF, 0xFF, arg2);
    } else {
        arg0 = func_1517F08C(arg0, arg1[0x3D], 0, 0, 0, arg2);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D2374.s")
