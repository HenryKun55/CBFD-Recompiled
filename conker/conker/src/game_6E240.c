#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15040D90(s32 arg0) {

}

void func_15040D9C(s32 arg0) {
    u16 *p;
    u32 i;
    u32 j;

    p = (u16 *) D_8002AAE8[!D_800BE9C0];
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            (p + (arg0 + j))[D_800BE620 * (i + 225) + 200] = 0xF800;
            p = (u16 *) D_8002AAE8[D_800BE9C0];
            (p + (arg0 + j))[D_800BE620 * (i + 225) + 200] = 0xF800;
            p = (u16 *) D_800BE9C4;
            (p + (arg0 + j))[D_800BE620 * (i + 225) + 200] = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E240/func_15040FCC.s")

void func_1504129C(void) {
    s32 i = 0;
    do {} while (++i < 0x18000000);
}
