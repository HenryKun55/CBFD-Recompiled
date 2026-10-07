#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E1AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E1D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E28DC.s")

s32 func_150E2DA4(s32 arg0, s32 arg1) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2F90.s")

struct func_150E2FC0_s {
    u8 pad0[0xDA];
    u8 unkDA;
    u8 padDB;
    s32 unkDC;
};
struct func_150E2FC0_t {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_150E2FC0(struct func_150E2FC0_s *arg0, struct func_150E2FC0_t *arg1, u8 arg2) {
    if (arg2 == 0x2D) {
        if (arg0->unkDC == arg1->unk0) {
            arg0->unkDC = arg1->unk4;
            arg0->unkDA = arg1->unk9;
        } else if (arg0->unkDC == arg1->unk4) {
            arg0->unkDC = arg1->unk0;
            arg0->unkDA = arg1->unk8;
        }
    }
}
