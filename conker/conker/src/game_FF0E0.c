#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FF0E0/func_150D1C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF0E0/func_150D1F6C.s")

struct func_150D2054_s {
    u8 pad0[0x24];
    struct102 *unk24[6];
};

void func_150D2054(u8 *arg0) {
    u8 i;
    struct func_150D2054_s *s = (struct func_150D2054_s *)(arg0 + 0x28);

    for (i = 0; i < 6; i++) {
        if (s->unk24[i] != NULL) {
            func_1516972C(s->unk24[i]);
        }
    }
}

void func_150D20B0(s32 arg0) {
    func_150D2054(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF0E0/func_150D20DC.s")
