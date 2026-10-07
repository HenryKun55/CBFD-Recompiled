#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A08B0;
extern f32 D_800A08B4;
extern f32 D_800A08B8;
void func_15059C84();

void func_150D13A0(u8 *arg0) {
    *(f32 *)(arg0 + 0xB8) += *(f32 *)(arg0 + 0xBC);
    *(f32 *)(arg0 + 0xBC) *= D_800A08B0;
    *(f32 *)(arg0 + 0x3C) *= D_800A08B4;
    *(f32 *)(arg0 + 0xC4) += *(f32 *)(arg0 + 0x148);
    *(f32 *)(arg0 + 0x148) *= D_800A08B8;
    func_15059C84(arg0);
}

void *func_151149AC();

void func_150D1410(struct127 *arg0) {
    u8 *temp_v0;

    temp_v0 = func_151149AC(0xF9);
    if (temp_v0 != NULL) {
        if ((arg0 - gObjects) == 0) {
            temp_v0[0x6E] = 1;
        } else {
            temp_v0[0x6E] = 0;
        }
    }
}

void *func_151149AC();

void func_150D146C(s32 arg0) {
    u8 *temp_v0;

    temp_v0 = func_151149AC(0xF9);
    if (temp_v0 != NULL) {
        temp_v0[0x6E] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FE850/func_150D149C.s")
