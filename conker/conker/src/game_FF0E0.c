#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FF0E0/func_150D1C30.s")

struct func_150D1F6C_s {
    s32 x, y, z;
};

void func_150D1F6C(u8 *arg0, u8 *arg1, u8 arg2) {
    u8 *p = arg0 + 0x28;

    if (arg2 == 0x32) {
        *(struct func_150D1F6C_s *)(p + 0x18) = *(struct func_150D1F6C_s *)arg1;
        *(f32 *)(p + 0x3C) = *(f32 *)(arg1 + 0xC);
        goto L1;
L1:;
    } else if ((arg2 == 0x30) || (arg2 == 0x31)) {
        if (arg1 == *(u8 **)(p + 0x40)) {
            if (arg2 == 0x30) {
                p[0x44] |= 1;
            } else {
                p[0x44] &= ~1;
                goto L2;
L2:;
            }
        }
    } else if (arg2 == 0x4E) {
        *(struct func_150D1F6C_s *)(arg0 + 0x40) = *(struct func_150D1F6C_s *)&D_800A5480;
    } else if (arg2 == 0x4F) {
        func_1516972C((struct102 *)arg0);
    }
}

struct func_150D2054_s {
    u8 pad0[0x24];
    struct102 *unk24[6];
};

void func_150D2054(u8 *arg0) {
    u8 i;
    struct func_150D2054_s *s = (struct func_150D2054_s *)(arg0 + 0x28);

    for (i = 0; i < 6; i++) {
        if (s->unk24[i] != NULL) {
            func_1516972C(s->unk24[i]);
        }
    }
}

void func_150D20B0(s32 arg0) {
    func_150D2054(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF0E0/func_150D20DC.s")
