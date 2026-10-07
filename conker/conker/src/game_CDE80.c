#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A09D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A0D14.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A29C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A32B4.s")

void func_150A3330(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    *arg1 = *(u8 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x17);
    *arg2 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x18);
    *arg3 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x1C);
    *arg4 = *(s32 *)(*(char **)&D_800D3098 + arg0 * 52 + 0x20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3444.s")

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
