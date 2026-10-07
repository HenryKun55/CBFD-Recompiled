#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150C09B0(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x20, arg0 + 0x24, arg0);
}

void func_150C09F0(s32 arg0) {
    func_150C0A48(arg0);
    func_15169804(arg0);
}

void func_150C0A1C(s32 arg0) {
    func_150C0A48(arg0);
    func_15169824(arg0);
}

struct func_150C0A48_s {
    void *unk0;
    s16 unk4;
};

int func_150C0A48(s32 arg0) {
    s32 i;

    i = *(s16 *)(arg0 + 0x44);
    while (i != -1) {
        func_1516972C((struct102 *)(*(struct func_150C0A48_s **)(arg0 + 0x40))[i].unk0);
        i = (*(struct func_150C0A48_s **)(arg0 + 0x40))[i].unk4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C1198.s")
