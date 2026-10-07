#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15193CA0.s")

void func_151942B0(s32 arg0, s32 arg1, s32 arg2) {
    func_15193CA0(arg1, 0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151942E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194408.s")

void func_150C7020(s32, s32, s32, s32);
void func_15194408(s32, s32);

void func_15194588(s32 arg0, s32 arg1, s32 arg2) {
    func_150C7020(arg0, 500, 0xFF, 1);
    func_15194408(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151945CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194810.s")

void func_151949E0(s32 arg0, s32 arg1, s32 arg2) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151949F4.s")

void func_15194A68(s32 arg0, s32 arg1, s32 arg2) {
    func_1507DE4C(arg1);
    func_15138BC0(arg1, 0xFF, 1);
    func_151949F4(0, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194BF0.s")

void func_15194FF4(s32 arg0, s32 arg1, s32 arg2);

void func_15194D80(s32 arg0, s32 arg1, s32 arg2) {
    func_15194FF4(arg0, arg1, 0);
}

void func_15194DA4(s32 arg0, s32 arg1, s32 arg2) {
    func_15194FF4(arg0, arg1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194DC8.s")

void func_150B06B0(void *arg0, void *arg1, s32 arg2, s32 arg3);

void func_15194E54(void *arg0, u8 *arg1, s32 arg2) {
    if ((arg1[4] == 0x3E) || (arg1[4] == 0xA6)) {
        func_150B06B0(arg1, arg0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151951E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195528.s")

void func_151B01B8();
s32 func_151B09BC();

void func_15195650(void *arg0, void *arg1, s32 arg2) {
    func_151B01B8(arg0, arg1);
    func_151B09BC(arg0, arg1, 0x3E8, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195738.s")
