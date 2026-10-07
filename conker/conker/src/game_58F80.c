#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BAD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BD84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C1A4.s")

extern s32 D_800C3E88;
extern s32 D_800C3E8C;
extern s16 D_800C3E7A;

void func_1502C380(void) {
    D_800C3E8C = D_800C3E88 = (&D_800C3E80)[D_800BE9C0];
    D_800C3E7A = 0;
}

extern u8 D_800CC406[];

s32 func_1502C3BC(s32 arg0) {
    s32 v = D_800CC406[arg0 * 0x32C];
    if (v >= 0x46) {
        v = 0xB;
    }
    return v;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CCFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E4C4.s")

void func_1502E9FC(s32 arg0, s32 arg1) {
}

struct func_1502EA0C_s {
    u8 pad0[0xA0];
    s32 unkA0;
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
    u8 unkA7;
};

void func_1502EA0C(struct func_1502EA0C_s *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    arg0->unkA4 = 4;
    arg0->unkA5 = 0;
    arg0->unkA6 = arg5;
    arg0->unkA0 = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
    arg0->unkA7 = 0xFF;
}

void func_1502EA50(s32 arg0) {
    *(u8 *)(arg0 + 0xA4) = 5;
}

struct func_1502EA60_s {
    u8 pad0[0xA4];
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
};

void func_1502EA60(struct func_1502EA60_s *arg0, s32 arg1) {
    arg0->unkA4 = 2;
    arg0->unkA5 = 0xFF;
    arg0->unkA6 = arg1;
}

void func_1502EA7C(u8 *arg0, s32 arg1) {
    arg0[0xA4] = 3;
    arg0[0xA5] = 0xFF;
    arg0[0xA6] = arg1;
}

struct func_1502EA98_s {
    u8 pad0[0xA0];
    s32 unkA0;
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
};

void func_1502EA98(struct func_1502EA98_s *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if ((arg0->unkA4 != 6) && (arg0->unkA4 != 7)) {
        if (arg5) {
            arg0->unkA5 = 0xFF;
        } else {
            arg0->unkA5 = 0;
        }
        arg0->unkA0 = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
        arg0->unkA6 = arg6;
    }
    arg0->unkA4 = 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EAFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EC34.s")

extern u8 D_800CC33A[];
s32 func_1502EE8C(s32 arg0, s32 arg1) {
    s32 v = D_800CC33A[arg0 * 0x32C + arg1];
    s32 ret;
    if (v >= 2) { ret = (v >= 4) ? 2 : v - 2; } else { ret = v; }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FD70.s")
