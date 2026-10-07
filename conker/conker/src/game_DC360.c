#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DC360/func_150AEEB0.s")

struct func_150AF1C0_s {
    u8 pad0[0x1B];
    u8 unk1B;
};

s32 func_150AF1C0(u8 *arg0) {
    struct func_150AF1C0_s *s = *(struct func_150AF1C0_s **)(arg0 + 0x98);
    s32 v = *(s16 *)(arg0 + 0x1C) << 5;
    if (v >= 0x100) {
        v = 0xFF;
    }
    s->unk1B = v;
    if ((u8)v < 0) {
        return 0;
    }
    return 1;
}
