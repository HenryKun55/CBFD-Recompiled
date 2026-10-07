#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FB8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC818.s")

s32 func_150FC930(u8 *arg0, s32 arg1, s32 arg2) {
    switch (arg0[4]) {
    case 0x12:
    case 0x23:
    case 0x73:
    case 0x8A:
        return 0;
    }
    return 1;
}

struct func_150FC974_s {
    u8 pad[0x38];
    union {
        s32 i;
        struct102 *p;
    } unk38;
};

void func_150FC974(struct func_150FC974_s *arg0) {
    if (arg0->unk38.i != 0) {
        func_1516972C(arg0->unk38.p);
    }
}

void func_150FC9A4(s32 arg0) {
    func_150FC974(arg0);
    func_1514933C(arg0);
}

void func_150FC9D0(s32 arg0) {
    func_150FC974(arg0);
    func_15149368(arg0);
}
