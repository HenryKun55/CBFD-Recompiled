#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A09D0.s")

extern f32 D_8009F5A0;
extern f32 D_8009F5A4;

struct func_150A0D14_s {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x10];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
};

void func_150A0D14(struct func_150A0D14_s *arg0) {
    f32 temp;

    temp = arg0->unkC * D_8009F5A0;
    arg0->unk24 = func_150AD78C(temp);
    arg0->unk28 = func_150AD780(temp);
    temp = arg0->unk10 * D_8009F5A4;
    arg0->unk2C = func_150AD78C(temp);
    arg0->unk30 = func_150AD780(temp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A0D8C.s")

s32 func_150A1040(s32 arg0) {
    return arg0 + 0x400;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A104C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A11C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A1DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A23E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A24C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A25D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A278C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2864.s")

struct func_150A2940_s {
    u8 pad0[0x17];
    u8 unk17;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x14];
};

void func_150A2940(u32 arg0, s32 arg1, s32 arg2) {
    arg0 &= 0xFFF;
    if (arg0 < (u32)D_800D3094) {
        if (arg1 != -1) {
            (*(struct func_150A2940_s **)&D_800D3098)[arg0].unk18 = arg1;
        }
        if (arg2 != -1) {
            (*(struct func_150A2940_s **)&D_800D3098)[arg0].unk17 = arg2;
        }
        (*(struct func_150A2940_s **)&D_800D3098)[arg0].unk1C = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A29C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3194.s")

struct func_150A32B4_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0xC];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad38[0x180 - 0x38];
    f32 unk180;
    u8 pad184[0x32C - 0x184];
};

s32 func_150A1DA0(struct func_150A32B4_s *, s32, s32);

s32 func_150A32B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_150A32B4_s sp24;
    s32 pad[2];

    sp24.unk14 = sp24.unk2C = arg1;
    sp24.unk180 = sp24.unk18 = sp24.unk30 = arg2;
    sp24.unk1C = sp24.unk34 = arg3;
    if (func_150A1DA0(&sp24, arg0, 0) == 0) {
        return 1;
    }
    return 0;
}

void func_150A3330(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    *arg1 = *(u8 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x17);
    *arg2 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x18);
    *arg3 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x1C);
    *arg4 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3398.s")

void func_150A3444(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    *(s16 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x0) = arg1;
    *(s16 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x2) = arg2;
    *(s16 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x4) = arg3;
}

s32 func_150A3504(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

s32 func_150A34B0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0[0x14] == 1) {
        return 0;
    }
    if (!(arg0[0x15] & 3)) {
        return func_150A3504(arg0, arg1, arg2, arg3);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3504.s")
