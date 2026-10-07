#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080500.s")

extern u8 D_800CC5EC[];

void func_15080620(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 != 0) {
        arg2 |= 0x80;
    }
    if (arg1 == 0) {
        (*(u8 **)(D_800CC5EC + arg0 * 0x32C))[0x74] = arg2;
        return;
    }
    (*(u8 **)(D_800CC5EC + arg0 * 0x32C))[0x75] = arg2;
}

struct func_150806A8_s {
    u8 pad0[0x74];
    u8 unk74;
    u8 unk75;
};

void func_150806A8(s32 arg0) {
    struct127 *obj = &gObjects[arg0];

    if (((struct func_150806A8_s *)obj->unk31C)->unk74 && !(((struct func_150806A8_s *)obj->unk31C)->unk74 & 0x80)) {
        ((struct func_150806A8_s *)obj->unk31C)->unk74 = 0;
    }
    if (((struct func_150806A8_s *)obj->unk31C)->unk75 && !(((struct func_150806A8_s *)obj->unk31C)->unk75 & 0x80)) {
        ((struct func_150806A8_s *)obj->unk31C)->unk75 = 0;
    }
}

void func_15080718(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg2 = 1 << (arg0 & 7);
    *arg1 = arg0 >> 3;
}

extern u8 D_800BE580[];
void func_15080718(s32 arg0, s32 *arg1, s32 *arg2);

s32 func_15080738(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    func_15080718(arg0, &sp1C, &sp18);
    if (D_800BE580[sp1C] & sp18) {
        return 1;
    }
    return 0;
}

void func_15080784(void) {
    u16 *p = (u16 *)D_800D1998;
    if (p != NULL) {
        if (D_800D1994 != D_800D1995) {
            if (p[D_800D1994] != 0) {
                func_1001263C(p[D_800D1994], 0x7FFF, 0x40);
            }
            D_800D1994++;
        }
    }
}

void func_150807F4(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 == 0x20) {
        func_15080784();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD9B0/func_15080828.s")

void func_1516D2E0(s32);
void func_10004074(void *);
void func_151F2D6C(s32, s32);

void func_15080BE8(void) {
    D_800D1941 = 0;
    func_1516D2E0(D_800D1950);
    func_10004074((void *)D_800D1944);
    if (D_800D1948 != 0) {
        func_10004074((void *)D_800D1948);
        func_10004074((void *)D_800D194C);
        func_10004074((void *)D_800D1998);
        D_800D1948 = 0;
    }
    func_151F2D6C(0, 0x5622);
}

extern u8 *D_800D199C;

void func_15080C64(void) {
    if (D_800D1941 != 0) {
        if (((u8 *)D_800D1950)[0x15] == 0) {
            func_15080BE8();
            if (D_800BE9F0 != 0x29 && D_800BE9F0 != 0x2E) {
                D_800D2E60[8] |= 0x10;
            }
            if (D_800D199C != 0) {
                D_800D199C[0x14] = 1;
                D_800D199C = 0;
            }
        }
    }
}

s32 func_15080CF4(void) {
    if (D_800D1941 == 0) {
        return 1;
    }
    return 0;
}
