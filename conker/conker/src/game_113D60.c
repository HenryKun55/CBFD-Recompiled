#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E68B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6E34.s")

void func_150E6ED8(s32 arg0) {
    func_1514470C((&D_800D9A20)[func_150ADA20() & 1], arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6FAC.s")

void func_150E70CC(f32 *arg0, f32 *arg1) {
    arg0[0] = arg1[5];
    arg0[1] = arg1[6];
    arg0[2] = arg1[7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E70EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E71E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E75A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E76D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E81A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E83AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8470.s")

void func_15131828();

s32 func_150E8824(u8 *arg0, void *arg1) {
    func_15131828(arg0, arg0 + 0xAC, arg0 + 0xA8, arg0 + 0xAA);
    return 1;
}

void func_150E8854(void) {
    struct260 *result;
    f32 sp30;

    sp30 = 10.0f;
    result = func_15149130(300, -1, 0x35, -1, 0, 0, (struct37 *) 4, 0xFF, 1);
    if (result != 0) {
        memcpy((char *) result + 0x28, &sp30, 4);
    }
}

extern f32 D_800A1378;
void func_150E8930();

void func_150E88C0(u8 *arg0) {
    *(f32 *)(arg0 + 0x28) -= D_800BE9A4;
    if (*(f32 *)(arg0 + 0x28) < 0.0f) {
        *(f32 *)(arg0 + 0x28) = (func_150ADA68() * D_800A1378) + 201.0f;
        func_150E8930(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E90DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E9178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E93DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E971C.s")
