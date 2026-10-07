#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510CB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510CDB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510CE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D0EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D404.s")

void func_1510D608(s32 arg0, s32 arg1) {
    s8 *p = (s8 *)&D_800BC448[arg0];
    s8 v = *p;
    if (v != 0) {
        *p = (v & 0x40) | arg1;
    }
}

void func_1510D630(s16 *arg0) {
    s32 i;
    s32 count = arg0[0];
    for (i = 1; i <= count; i++) {
        func_1510D694(arg0[i]);
    }
    func_10004074(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D7AC.s")

extern u8 D_800D9ED0;

void func_1510D864(void) {
    D_800D9ED0 = 0;
}

struct func_1510D874_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    u8 padE[2];
};
extern u8 D_800D9ED0;
extern struct func_1510D874_s D_800D9ED8[];

void func_1510D874(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 n = D_800D9ED0;
    if (n < 8) {
        D_800D9ED8[n].unk0 = arg0;
        D_800D9ED8[n].unk4 = arg1;
        D_800D9ED8[n].unk8 = arg2;
        D_800D9ED8[n].unkC = arg3;
        D_800D9ED8[n].unkD = arg4;
        D_800D9ED0 = n + 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D8C0.s")
