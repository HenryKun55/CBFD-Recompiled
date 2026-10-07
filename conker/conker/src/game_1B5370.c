#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5370/func_15187EC0.s")

extern u8 D_800DF700[];
extern s32 D_800DF7B4;

void func_15187F90(void) {
    bzero(D_800DF700, 0xB4);
    D_800DF7B4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5370/func_15187FC0.s")

struct func_15188010_s {
    f32 unk0;
    u8 pad4[0x20];
};
extern struct func_15188010_s D_800DF70C[];
extern s32 D_800DF7B4;

void func_15188010(s32 arg0, f32 *arg1) {
    if ((arg0 < D_800DF7B4) && (arg0 >= 0)) {
        *arg1 = D_800DF70C[arg0].unk0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5370/func_1518804C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5370/func_151880C0.s")
