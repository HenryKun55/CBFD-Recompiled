#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2A60.s")

struct func_150F2C8C_s {
    void *unk0;
    u8 unk4;
    u8 unk5;
    f32 unk8;
    u8 unkC;
};

void func_150F2C8C(u8 *arg0) {
    struct func_150F2C8C_s sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = arg0[0x3B];
    sp38.unk5 = 0;
    sp38.unk8 = 0.0f;
    sp38.unkC = 0;
    temp_v0 = func_15149130(0x12C, -1, 0x5C, -1, 0, 0x44, (struct37 *)0x10, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp38, 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2D14.s")

void func_150F3194(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_150F31D4(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x110, arg0 + 0x114, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F3214.s")

void func_15140410();

void func_150F337C(u8 *arg0, s16 arg1) {
    func_15140410(arg0, arg0 + 0x12C, arg0 + 0x138, arg1);
}

struct func_150F33B0_s {
    u8 pad0[0x4F];
    u8 unk4F_pad : 7;
    u8 unk4F_0 : 1;
};

void func_150F33B0(struct func_150F33B0_s *arg0) {
    if (D_800DBFF0->unk300 < -2000.0f) {
        arg0->unk4F_0 = 0;
        return;
    }
    arg0->unk4F_0 = 1;
}

extern f32 D_800A1970;

void func_150F33F8(s32 arg0) {
    struct108 *temp_v0;

    temp_v0 = (struct108 *)((char *)D_800DBFF0 + arg0 * 0x9A0);
    if (temp_v0->unk300 < D_800A1970) {
        if (temp_v0->unk2FC > 840.0f) {
            *(s16 *)D_800D9A40 |= (1 << arg0);
            return;
        }
        *(s16 *)D_800D9A40 &= ~(1 << arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F43F0.s")
