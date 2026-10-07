#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_119370/func_150EBEC0.s")

struct func_150EC3D4_s {
    s32 unk0;
    u8 unk4;
};

s32 func_150EC3D4(struct func_150EC3D4_s *arg0, struct func_150EC3D4_s *arg1) {
    if (arg0 == arg1) {
        return 0;
    }
    if (arg0->unk0 == 0) {
        return 0;
    }
    if (arg0->unk4 == 0xFF) {
        return 0;
    }
    if (arg0->unk4 == 0 || arg0->unk4 == 1 || arg0->unk4 == 2 || arg0->unk4 == 3 || arg0->unk4 == 4 || arg0->unk4 == 0x28 || arg0->unk4 == 0x77) {
        return 1;
    } else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_119370/func_150EC45C.s")
