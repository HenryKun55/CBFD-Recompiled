#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A6F00.s")

struct func_151A73EC_s {
    u8 pad0[0x64];
    s16 unk64;
    u8 pad66[0x170 - 0x66];
    struct102 *unk170[2];
};

s32 func_151A73EC(struct func_151A73EC_s *arg0) {
    struct102 **w = arg0->unk170;
    if (arg0->unk64 < 0x20) {
        if (w[1] != NULL) {
            func_1516972C(w[1]);
            w[1] = NULL;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A743C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A7610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A77C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A787C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A7908.s")
