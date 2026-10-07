#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15016850_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x2B];
};

extern u8 D_800BE590;
extern u16 D_800BE598[];
extern s32 D_800BE5A8[];
extern u8 D_800D2100;

void func_15016850(void) {
    s32 i;
    s32 j;
    s32 found;
    s32 sp50;
    s32 id;

    D_800BE590 = 0;
    sp50 = 0;
    for (i = 0; i < D_800D2100; i++) {
        id = ((struct func_15016850_s *)D_800D20FC)[i].unk4;
        found = 0;
        for (j = 0; j < D_800BE590; j++) {
            if (id == D_800BE598[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            continue;
        }
        if (id < 0xBB) {
            func_1502B7F0(&sp50, 2, 0x12, id);
        }
        if (sp50 != 0) {
            D_800BE5A8[D_800BE590] = sp50;
            D_800BE598[D_800BE590] = id;
            D_800BE590++;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_43D00/func_150169A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_43D00/func_15017114.s")
