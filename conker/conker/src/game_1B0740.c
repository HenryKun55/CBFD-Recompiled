#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183290.s")

struct func_151838B0_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 *unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern u8 D_800DDF69[];
s32 *func_1502B6BC(s32, s32, s32, s32, s32, s32);

void func_151838B0(s32 arg0) {
    s32 *temp_v0;

    if (((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unk0 == 0) {
        func_15183ACC(arg0);
    }
    if (((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unk14 == NULL) {
        temp_v0 = func_1502B6BC(0, 0, 0, 2, 9, arg0 + 0xAE);
        if (temp_v0 != NULL) {
            ((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unk14 = temp_v0;
            ((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unk18 = temp_v0[0];
            ((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unk1C = temp_v0[2];
            ((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unk20 = ((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unkC;
            ((struct func_151838B0_s *)((u8 *)D_800DDE80 + arg0 * 20))->unk24 = 0;
            D_800DDF69[arg0] = 1;
        }
    }
}

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

extern s8 D_800DDF70;
extern s8 D_800DDF71;
extern s32 D_800DDF20;
extern s32 D_800DDF98;
void func_1510D630(s32);
void func_10004074(void *);

void func_15183C28(s32 arg0) {
    if (((struct func_15183974_s *)D_800DDE80)[arg0].unk10 != 0) {
        func_1510D630(((struct func_15183974_s *)D_800DDE80)[arg0].unk10);
        ((struct func_15183974_s *)D_800DDE80)[arg0].unk10 = 0;
    }
    if (arg0 == 8) {
        if (D_800DDF71 != -2) {
            return;
        }
    } else if (arg0 == 9) {
        if (D_800DDF70 == -2) {
            if (D_800DDF20 != 0) {
                func_10004074((void *)D_800DDF20);
                D_800DDF20 = 0;
                D_800DDF98 = 0;
            }
        }
    }
    if (((struct func_15183974_s *)D_800DDE80)[arg0].unk0 != 0) {
        func_10004074((void *)((struct func_15183974_s *)D_800DDE80)[arg0].unk0);
        ((struct func_15183974_s *)D_800DDE80)[arg0].unk0 = 0;
        D_800DDF78[arg0] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15184118.s")
