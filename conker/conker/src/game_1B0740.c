#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_151838B0.s")

struct func_15183974_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_15183974(s32 arg0) {
    if (((struct func_15183974_s *)D_800DDE80)[arg0].unk0 == 0) {
        func_15183ACC(arg0);
    }
    if (((struct func_15183974_s *)D_800DDE80)[arg0 + 1].unk0 == 0) {
        func_15183ACC(arg0 + 1);
        ((struct func_15183974_s *)D_800DDE80)[arg0 + 1].unkC = ((struct func_15183974_s *)D_800DDE80)[arg0].unkC;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_151839F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183ACC.s")

extern u8 D_800A72D0[];

Gfx *func_15183BA4(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3) {
    s32 idx = -1;
    s32 i;

    for (i = 0; i < 11; i++) {
        if (arg1 == D_800A72D0[i]) {
            idx = i;
            break;
        }
    }
    if (idx != -1) {
        if (D_800DDF78[idx] != 0) {
            gSPDisplayList(gdl++, D_800DDF78[idx]);
        }
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15184118.s")
