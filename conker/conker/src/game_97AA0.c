#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A5F0.s")

void func_1506A6FC(s32 arg0, s32 arg1) {
    func_150E0348(arg0, 0xFF, 1);
}

extern f32 D_800D1560[];
extern u8 D_800D1570[];
void func_151BB61C(s32 arg0, f32 *arg1, void *arg2, s32 arg3, s32 arg4);

void func_1506A724(s32 arg0, s32 arg1) {
    func_151BB61C(arg0, D_800D1560, D_800D1570, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A79C.s")

void func_1506A83C(s32 arg0, s32 arg1) {
    func_151BC104(arg0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A968.s")

void func_151B7144(s32, s32, s32);
void func_151B6320(s32, s32, s32);

void func_1506AA08(s32 arg0, s32 arg1) {
    func_151B7144(arg0, 0xFF, 1);
    func_151B6320(arg0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506AA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506AAE0.s")

void func_15103E40(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_1506AB7C(s32 arg0, s32 *arg1) {
    func_15103E40(arg0, arg1[0], &arg1[1], 1, arg1[4], 0xFF, 1);
}

void func_15103E40(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_1506ABC4(s32 arg0, s32 *arg1) {
    func_15103E40(arg0, arg1[0], &arg1[1], 2, arg1[4], 0xFF, 1);
}

struct func_1506AC0C_s {
    void *ptr;
    u8 b;
};

void func_1506AC0C(void *arg0, void *arg1) {
    struct func_1506AC0C_s sp20;

    sp20.ptr = arg0;
    sp20.b = *((u8 *)arg0 + 0x3B);
    func_151B7328(&sp20, 0, 8, 0xFF, 1);
}

void func_1506AC58(s32 arg0, s32 arg1) {
    func_151CEAAC(arg0, 0, 1, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506AC8C.s")
