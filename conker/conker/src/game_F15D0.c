#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F15D0/func_150C4120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F15D0/func_150C44A4.s")

struct func_150C4AD8_s {
    u8 pad[0x34];
    union {
        s32 w;
        struct102 *p;
    } unk34;
};

void func_150C4AD8(struct func_150C4AD8_s *arg0) {
    struct func_150C4AD8_s *temp = arg0;
    if (temp->unk34.w != 0) {
        func_1516972C(temp->unk34.p);
    }
}

void func_150C4B08(s32 arg0) {
    func_150C4AD8(arg0);
    func_1514933C(arg0);
}

void func_150C4B34(s32 arg0) {
    func_150C4AD8(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F15D0/func_150C4B60.s")
