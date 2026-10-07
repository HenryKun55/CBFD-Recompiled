#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_1507EB80(u8 *buf, s32 *len, u8 c) {
    if (*len + 1 < 40) {
        buf[*len] = c;
        *len = *len + 1;
    }
}

extern u8 *D_80086C24[];
extern u8 D_8009BBF0[];

void func_1507EBB8(u8 *buf, s32 *len, s32 idx) {
    u8 *src = D_80086C24[idx];
    s32 n = D_8009BBF0[idx];

    if (*len + n < 40) {
        bcopy(src, buf + *len, n);
        *len += n;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EE58.s")

void func_1507EEB8(u8 arg0, u8 *arg1) {
    s32 i;
    for (i = 4; i > 0; i--) {
        arg1[i] = arg1[i - 1];
    }
    arg1[0] = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EEF4.s")

void func_1507EFA0(s32 arg0, u8 *arg1) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        if (arg0 == arg1[i]) {
            arg1[i] = 0;
            return;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EFD0.s")

extern u8 *D_80086BA0[];

s32 func_1507F454(void) {
    u8 *p = (u8 *)gCurrentObject->unk31C + 0x58;
    u8 c;

    if (p[4] == 0) {
        return 1;
    }
    p[5]++;
    c = *(p[5] + D_80086BA0[p[4]]);
    if (c == 0) {
        p[4] = 0;
        p[5] = 0;
        return 1;
    }
    return 0;
}

s32 func_1507F4C0(s32 arg0) {
    u32 ret;
    u32 base;
    u32 range;

    if (arg0 == 0) {
        base = 180;
        range = 60;
    } else if (D_800BE9F0 == 0x31) {
        return 0;
    } else if (arg0 == 1) {
        base = 60;
        range = 60;
    } else {
        base = 0;
        range = 30;
    }
    ret = (func_150ADA20() % range) + base;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FEA0.s")

struct func_1507FF94_s {
    struct127 *ptr;
    u8 id;
};

void func_1507FF94(struct127 *arg0) {
    struct func_1507FF94_s tmp;

    tmp.ptr = arg0;
    tmp.id = arg0->unique_id;
    // reusing the parameter as an integer-cast pointer makes IDO spill
    // &tmp across the first call instead of rematerialising it
    arg0 = (struct127 *)(s32)&tmp;
    func_15191B8C(arg0, 0xD);
    func_151494E0(arg0, 0xD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FFD8.s")
