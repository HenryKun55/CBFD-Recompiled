#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_203340/func_151D5E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203340/func_151D61B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203340/func_151D6418.s")

void func_151D66F0(s32 arg0, s32 arg1) {
    if ((D_800BE9F0 == 6) && (D_80038080 == 0)) {
        return;
    }
    if (arg1 == 0) {
        arg0 = 0;
    }
    D_800BE574 = arg0;
    if (arg0 != 0) {
        D_800BE575 = arg1;
    } else {
        D_800BE575 = 0;
    }
    if (arg0 == 0) {
        if (D_800BE570 != 0) {
            func_100043B4((void *)D_800BE570, 3);
            D_800BE570 = 0;
        }
    }
}

Gfx *func_151D6418(Gfx *, s32, s32, s32);

Gfx *func_151D6778(Gfx *gfx) {
    s32 mode;

    if ((D_800BE574 == 0 && D_800BE9F0 != 0x32 && D_800BE9F0 != 0x33) || D_800BEAC0 != 0) {
        return gfx;
    }
    mode = D_800BE574;
    if (mode != 0) {
        gDPPipeSync(gfx++);
        if (D_800BE570 != 0) {
            gfx = func_151D6418(gfx, D_800BE570, 0, mode);
        } else {
            D_800BE570 = allocate_memory(D_800BE620 * D_800BE624 * 2, 1, 3, 1);
            if (D_800BE570 == 0) {
                return gfx;
            }
        }
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800BE620, D_800BE570);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, D_800BE620, D_800BE624);
        gfx = func_151D5E90(gfx, D_8002AAE8[D_800BE9C0], 0, 4);
        gDPSetOtherMode(gfx++, 0x00082C3F, 0x00552230);
        gSPGeometryMode(gfx++, 0, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
        gfx = func_1501A680(gfx);
    }
    return gfx;
}
