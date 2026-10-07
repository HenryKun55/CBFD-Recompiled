#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A3460;
void func_15122980(struct108 *arg0);

void func_151220D0(struct108 *arg0) {
    struct17 tmp;

    if (!(*arg0->unk36C & 4)) {
        func_15048F90(&arg0->unk2F8, &arg0->unk2BC, &tmp);
        tmp.unk0 += *(f32 *)&arg0->unk2C8 - arg0->unk2BC;
        tmp.unk8 += *(f32 *)&arg0->unk2D0 - arg0->unk2C4;
        arg0->unk37C = func_15048FC8(&tmp);
        arg0->unk39C = arg0->unk37C * D_800A3460;
    }
    func_15122980(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14F580/func_15122170.s")
