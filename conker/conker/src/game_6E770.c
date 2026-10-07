#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_80084930[];

Gfx *func_150412C0(Gfx *gdl) {
    gSPTexture(gdl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetCombine(gdl++, 0xFFFFFF, 0xFFFCF279);
    gDPSetOtherMode(gdl++, 0x002C0F, 0x0055204C);
    gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 64, D_80084930);
    gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_80084930);
    gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPLoadSync(gdl++);
    gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 0x7FF, 0x200);
    gDPPipeSync(gdl++);
    gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_4b, 4, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0xFC, 0x1FC);
    return gdl;
}

s32 func_15041480(u8 arg0);
void *func_15041508(void *arg0, void *arg1, s32 arg2, s32 arg3);

void *func_150413FC(void *arg0, u8 arg1[][8], s32 arg2, u8 *arg3) {
    s32 i = 0;
    while (arg3[i] != 0) {
        arg0 = func_15041508(arg0, arg1[i], arg2, func_15041480(arg3[i]));
        i++;
    }
    return arg0;
}

extern u8 D_800848D0[];

s32 func_15041480(u8 arg0) {
    s32 i;

    for (i = 0; i < 80; i++) {
        if (arg0 == D_800848D0[i]) {
            return i;
        }
    }
    return i;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_15041508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150415E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150417AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150428D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_15042C40.s")
