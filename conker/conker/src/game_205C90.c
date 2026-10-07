#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D87E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8A24.s")

void func_1501C17C(u8);

void func_151D8B24(u8 *arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        if (arg0[0x13] & (1 << i)) {
            func_1501C17C(i);
        }
    }
}

void func_151D8B88(s32 arg0) {
    func_151D8B24(arg0);
    func_15169804(arg0);
}

void func_151D8BB4(s32 arg0) {
    func_151D8B24(arg0);
    func_15169824(arg0);
}

void func_151D8C00(u8 *arg0, u8 *arg1);

void func_151D8BE0(u8 *arg0) {
    func_151D8C00(arg0, arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8C00.s")

void func_151D8D5C(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x58) {
        func_1516972C(arg0);
    } else if (arg2 == 0x47) {
        func_1516972C(arg0);
    }
}

extern s32 D_800AB300;

void func_151D8DB4(void *arg0, u8 arg1) {
    func_15169260(&D_800AB300, 1, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8DE8.s")
