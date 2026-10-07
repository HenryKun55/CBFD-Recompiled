#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

void *func_1510D970(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *ret;
    s32 size = 0x128;
    s32 i;

    if (arg3 & 1) {
        size = 0x13A;
    }
    ret = func_15167A68(0x4B, 0, size, 1, 0xFF, 1);
    if (ret != NULL) {
        for (i = 0; i < 2; i++) {
            *(s16 *)(ret + i * 0x40 + 0x96) = 0;
            *(s16 *)(ret + i * 0x40 + 0x98) = 0x800;
            *(s16 *)(ret + i * 0x40 + 0x9A) = 0;
            *(s16 *)(ret + i * 0x40 + 0xA6) = 0;
            *(s16 *)(ret + i * 0x40 + 0xA8) = 0;
            *(s16 *)(ret + i * 0x40 + 0xAA) = 0;
            *(s16 *)(ret + i * 0x40 + 0xB6) = 0;
            *(s16 *)(ret + i * 0x40 + 0xB8) = 0;
            *(s16 *)(ret + i * 0x40 + 0xBA) = 0x800;
            *(s16 *)(ret + i * 0x40 + 0xC6) = 0;
            *(s16 *)(ret + i * 0x40 + 0xC8) = 0x800;
            *(s16 *)(ret + i * 0x40 + 0xCA) = 0x800;
        }
        ret[0x120] = arg0;
        *(s32 *)(ret + 0x110) = arg1;
        ret[0x121] = arg2;
        ret[0x124] = arg4;
        if (arg3 & 1) {
            for (i = 0; i < 9; i++) {
                *(s16 *)(ret + 0x128 + i * 2) = 0x7FFF;
            }
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510DA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510E120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510E388.s")

extern s32 D_80089470;

Gfx *func_1510E634(Gfx *gfx, s32 arg1, s32 arg2) {
    gSPMatrix(gfx++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gfx;
}
