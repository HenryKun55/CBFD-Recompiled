#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_196DB0/func_15169900.s")

void func_15169900(s32 arg0, s32 arg1);

void func_15169968(s32 arg0) {
    func_15169900(arg0, 0xFF);
}

struct func_15169988_s {
    u8 pad0[0x24];
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 pad2A[0x16];
    s8 unk40;
    u8 unk41;
};

extern void (*D_8008CA20[])(struct func_15169988_s *);

void func_15169988(struct func_15169988_s *arg0) {
    s32 v;
    s32 t;

    if (arg0->unk40 != 0) {
        D_8008CA20[arg0->unk40](arg0);
    }
    v = arg0->unk26;
    v += arg0->unk28 * D_800BE9E4;
    t = arg0->unk41 << 8;
    if (v >= t) {
        v -= t;
    } else if (v < 0) {
        v += t;
    }
    arg0->unk26 = v;
    t = arg0->unk24;
    if (t != 0) {
        t -= D_800BE9E4;
        if (t <= 0) {
            func_1516972C((struct102 *)arg0);
        } else {
            arg0->unk24 = t;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_196DB0/func_15169A48.s")
