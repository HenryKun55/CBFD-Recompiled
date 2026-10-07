#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150F9AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150F9BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA1B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAA40.s")

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
