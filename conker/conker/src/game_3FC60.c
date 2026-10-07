#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_3FC60/func_150127B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_3FC60/func_15012C84.s")

extern u8 D_800BE530[][3];
extern s16 D_800BE550[];
extern u8 D_800BE564;

void func_15012ED8(u32 *arg0) {
    s32 i;
    s32 cmd;
    u32 *gfx;

    i = 0;
    cmd = (s8)(arg0[0] >> 24);
    gfx = arg0;
    while (cmd != -0x21) {
        if (cmd == -5) {
D_800BE550[D_800BE564] = i;
D_800BE530[D_800BE564][0] = (gfx[1] >> 24) & 0xFF;
D_800BE530[D_800BE564][1] = (gfx[1] >> 16) & 0xFF;
D_800BE530[D_800BE564][2] = (gfx[1] >> 8) & 0xFF;
D_800BE564++;
        }
        cmd = (s8)(gfx[2] >> 24);
        i++;
        gfx += 2;
    }
}

extern u8 D_800DF7D0;
extern u8 D_800DF7D1;
extern u8 D_800DF7D2;
extern u8 D_800DF7D3[];

void func_15012F90(void) {
    s32 i;
    D_800DF7D0 = 0;
    D_800DF7D1 = 0;
    for (i = 0, D_800DF7D2 = 0; i < 0x1E0; i++) {
        D_800DF7D3[i] = 0;
    }
}
