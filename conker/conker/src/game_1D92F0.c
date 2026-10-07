#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ABE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC078.s")

struct func_151AC3CC_s {
    u8 pad[0x1C];
    s16 unk1C;
    u8 pad2[0x98 - 0x1E];
    u8 *unk98;
};

s32 func_151AC3CC(struct func_151AC3CC_s *arg0) {
    u8 *p;
    s32 v;

    p = arg0->unk98;
    v = arg0->unk1C;
    v = v * 8;
    if (v >= 0x100) {
        v = 0xFF;
    }
    if (v < p[0x1B]) {
        p[0x1B] = v;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC810.s")

extern f32 D_800BE9A4;

s32 func_151AC9EC(f32 *arg0) {
    f32 t = arg0[19] * D_800BE9A4;
    arg0[11] += t;
    arg0[12] += t;
    return 1;
}

struct func_151ACA20_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_151ACA20(struct func_151ACA20_s *arg0) {
    s16 v = 0xFF;
    if (arg0->unk1C < 16) {
        v = arg0->unk1C << 4;
    }
    if (v < arg0->unk5C) {
        arg0->unk5C = v;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACA60.s")

s32 func_151ACB38(u8 *arg0, u8 *arg1) {
    s32 ret = 0;
    if (arg0[0x3B] == 1) {
        *arg1 = 1;
        ret = 1;
    }
    return ret;
}

void func_151AE3A8(void *arg0);

void func_151ACB60(void *arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)(*(s32 *)(*(s32 *)((u8 *)arg0 + 0x1C) + 0x31C) + 0x9C);
    if (temp_v0 != 0) {
        func_151AE3A8(arg0);
    }
    if (arg0) {}
}

void func_151ACB94(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x1C, arg0 + 0x20, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD92C.s")

void func_151AE0E4(u8 *arg0, u8 arg1);
void func_151AE264();

void func_151AE06C(u8 *arg0, u8 *arg1) {
    u8 sp1F;
    u8 new;

    if (func_151ACB38(arg0, &sp1F)) {
        new = arg1[0x1B];
        if ((*(u8 **)(arg0 + 0x31C))[0x98] == 0) {
            func_151AE0E4(arg0, new);
        } else if (new != (*(u8 **)(arg0 + 0x31C))[0x98]) {
            func_151AE264(arg0);
            func_151AE0E4(arg0, new);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE0E4.s")

extern f32 D_800A9294;

struct func_151AE264_s2 {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[4];
    f32 unk4C;
    s8 unk50;
    u8 unk51;
    s16 unk52;
};

struct func_151AE264_s1 {
    u8 pad0[0x98];
    s8 unk98;
    u8 pad99[3];
    struct func_151AE264_s2 *unk9C;
    u8 padA0[0xE];
    u8 unkAE;
};

struct func_151AE264_s {
    u8 pad0[0x3C];
    f32 unk3C;
    u8 pad40[0x36];
    u16 unk76;
    u8 pad78[0x31C - 0x78];
    struct func_151AE264_s1 *unk31C;
};

void func_151AE264(struct func_151AE264_s *arg0) {
    struct func_151AE264_s2 *temp_v0;
    f32 temp_f0;

    temp_f0 = arg0->unk3C * D_800A9294;
    temp_v0 = arg0->unk31C->unk9C;
    temp_v0->unk4C = temp_f0;
    temp_v0->unk50 = arg0->unk76 >> 8;
    temp_v0->unk51 = arg0->unk31C->unkAE;
    temp_v0->unk52 = 0x14;
    temp_v0->unk44 = 0;
    arg0->unk31C->unk98 = 0;
    arg0->unk31C->unk9C = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AEAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AECA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF270.s")

void func_151AF388(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4);

struct func_151AF338_s {
    u8 pad[0xC];
    u8 unkC;
};

void func_151AF338(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, struct func_151AF338_s *arg6) {
    f32 sp24[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp24[2] = arg2;
    func_151AF388(sp24, arg3, arg4, arg5, arg6->unkC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF4D0.s")
