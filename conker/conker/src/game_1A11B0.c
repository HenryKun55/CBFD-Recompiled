#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A11B0/func_15173D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A11B0/func_151742EC.s")

typedef struct {
    s32 w[9];
} func_151745F0_blk;

struct func_151745F0_s {
    f32 x;
    f32 y;
    f32 z;
    u8 state;
    u8 pad[3];
    func_151745F0_blk blk;
    s8 unk34;
    u8 pad35[3];
    s32 unk38;
};

extern struct func_151745F0_s D_800DD348[];

s32 func_151745F0(f32 arg0, f32 arg1, f32 arg2, func_151745F0_blk *arg3, s8 arg4, s32 arg5) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_800DD348[i].state == 0) {
            D_800DD348[i].x = arg0;
            D_800DD348[i].y = arg1;
            D_800DD348[i].state = 3;
            D_800DD348[i].z = arg2;
            D_800DD348[i].unk34 = arg4;
            D_800DD348[i].unk38 = arg5;
            if (arg3 != NULL) {
                D_800DD348[i].blk = *arg3;
            }
            return 0;
        }
    }
    return 1;
}
