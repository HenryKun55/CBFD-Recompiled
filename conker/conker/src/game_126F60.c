#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150F9AB0_s {
    u8  unk0[0x24];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u8  unk34[0x14C];
};

void func_15110360(s32, Mtx *, s32, s32, f32);

void func_150F9AB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    Mtx sp38;
    Gfx *gfx;
    struct func_150F9AB0_s *cam;

    func_15110360(D_80082FA4, &sp38, arg4, arg5, arg6);
    cam = &((struct func_150F9AB0_s *)D_800BE628)[D_80082FA4];
    gfx = func_15110544(arg0, (s32)cam->unk2C, (s32)cam->unk24, (s32)(cam->unk30 - 1.0f), (s32)cam->unk28, 0, 0, 0);
    gfx->words.w0 = 0xE7000000;
    gfx->words.w1 = 0;
    gfx++;
    gDPSetOtherMode(gfx++, 0x002C0F, 0x0F0A4004);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, 0, PRIMITIVE, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, 0);
    func_150FB4C0(gfx, &sp38);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150F9BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA1B8.s")

struct func_150FA468_s {
    u8 pad[0x11];
    s8 unk11;
};

void func_150FA468(struct func_150FA468_s *arg0, s32 arg1, u8 arg2) {
    s32 temp = arg2;

    if (temp == 0x4C) {
        arg0->unk11 = -1;
        func_1515D4D4(0, 0, 0, 0xFF);
    } else if (temp == 0x4D) {
        arg0->unk11 = 0x1E;
    } else if (temp == 0x4E) {
        arg0->unk11 = -1;
    } else if (temp == 0x4F) {
        arg0->unk11 = -1;
        func_1515D4D4(0xFF, 0xFF, 0xFF, 0xFF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA520.s")

void func_150FAA40(u8 arg0, s32 arg1) {
    s32 tmp[3];
    struct260 *temp_v0;

    if (D_80088B60 == 0) {
        tmp[0] = *(s32 *)&D_800D3098 + 0x71C;
        tmp[1] = *(s32 *)&D_800D3098 + 0x6E8;
        *(f32 *)&tmp[2] = 0.0f;
        temp_v0 = func_15149130(0x12C, -1, 0x57, -1, 0, 0x46, 0xC, arg0, arg1);
        if (temp_v0 != NULL) {
            D_80088B60 = 1;
        }
        if (temp_v0 != NULL) {
            memcpy((char *) temp_v0 + 0x28, tmp, 0xC);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAAEC.s")

void func_150FACE4(struct102 *arg0, s32 arg1, u8 arg2) {
    if ((arg2 == 0x4E) || (arg2 == 0x4F)) {
        func_1516972C(arg0);
    }
}

void func_150FAD28(void) {
    func_1515F170(8, 0);
    func_1515F170(0xB, 1);
    func_151494E0(*(s32 *)&D_800D3098 + 0x514, 0x30);
    func_151494E0(0, 0x4D);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAD78.s")

void func_150FADC8(s32 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x53) {
        arg0[0x58 / 4] |= 2;
    } else if (arg2 == 0x54) {
        arg0[0x58 / 4] &= ~2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAE18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB188.s")

void func_150FB1E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_15157F80(func_151D710C(arg0, arg1, arg2, arg3, arg4), arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB240.s")

void func_150FB240(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

s32 func_150FB29C(s8 *arg0) {
    func_150FB240(arg0 + 0x43, *(s16 *)(arg0 + 0x16), *(s16 *)(arg0 + 0x120), *(s16 *)(arg0 + 0x64), *(s16 *)(arg0 + 0x66));
    return 1;
}

void func_150FB240(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

s32 func_150FB2E0(s8 *arg0) {
    func_150FB240(arg0 + 0x2E, *(s16 *)(arg0 + 0x22), *(s16 *)(arg0 + 0x70), *(s16 *)(arg0 + 0x26), *(s16 *)(arg0 + 0x28));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB324.s")
