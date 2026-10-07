#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15147DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15147EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_1514803C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_151488C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148DE0.s")

struct func_15148EF8_s {
    u8 pad0[0x98];
    u8 *unk98;
};

s32 func_15148EF8(struct func_15148EF8_s *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_v1 = arg0->unk98;

    temp_v1[0x20] = 4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148F1C.s")

struct func_151490C8_s { u8 pad[0x1B]; u8 unk1B; };
s32 func_151490C8(u8 *arg0) {
    struct func_151490C8_s *temp_v0 = *(struct func_151490C8_s **)(arg0 + 0x98);
    s32 v = *(s16 *)(arg0 + 0x1C) * 8;
    u8 b;
    if (v >= 0x100) {
        v = 0xFF;
    }
    temp_v0->unk1B = b = v;
    if (b < 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15149104.s")
