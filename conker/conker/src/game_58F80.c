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

struct func_1502C608_s {
    u8 pad0[4];
    u8 unk4;
};
extern struct func_1502C608_s *D_8008CA4C[];

void func_1502C608(s32 arg0) {
    s32 max;
    s16 a;
    s16 b;

    if (D_800BEAC0 == 0) {
        a = ((s16 *)&gObjects[arg0].unk60)[0];
        b = ((s16 *)&gObjects[arg0].unk60)[1];
        if (gObjects[arg0].unk7 != 0) {
            max = D_8008CA4C[func_1502C3BC(arg0)]->unk4 << 8;
            a += b;
            if (a >= max) {
                a -= max;
            } else if (a < 0) {
                a += max;
            }
            ((s16 *)&gObjects[arg0].unk60)[0] = a;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C974.s")

struct func_1502CC34_s {
    u8 pad0[0xA4];
    u8 unkA4;
};

void func_1502EC34(struct func_1502CC34_s *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);

void func_1502CC34(struct func_1502CC34_s *arg0, s32 arg1, s32 arg2, s32 *arg3,
                   s32 *arg4, s32 *arg5, s32 *arg6, s32 *arg7, s32 *arg8, s32 *arg9,
                   s32 *argA, s32 *argB, s32 *argC, s32 *argD) {
    *arg4 = D_800D9B68[arg1][0];
    *arg5 = D_800D9B68[arg1][1];
    *arg6 = D_800D9B68[arg1][2];
    *arg7 = D_800D9B78[arg1][0];
    *arg8 = D_800D9B78[arg1][1];
    *arg9 = D_800D9B78[arg1][2];
    *argA = 0;
    *argB = 0;
    *argC = 0;
    *argD = arg3[3];
    if (arg0->unkA4) {
        func_1502EC34(arg0, argA, argB, argC, argD);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CCFC.s")

void func_1502D54C(s32 arg0, s32 *arg1) {
    u8 *p = (u8 *)&gObjects[arg0];
    if ((p[0x66] & 0xC) == 4) {
        arg1[0] = (p[0x1E0] + p[0x1DD]) / 2;
        arg1[1] = (p[0x1E1] + p[0x1DE]) / 2;
        arg1[2] = (p[0x1E2] + p[0x1DF]) / 2;
        arg1[0] = 0xFF - arg1[0];
        arg1[1] = 0xFF - arg1[1];
        arg1[2] = 0xFF - arg1[2];
    } else {
        arg1[0] = arg1[1] = arg1[2] = 0xFF;
    }
}

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

extern void *allocate_memory(s32, s32, s32, s32);

struct func_1502F948_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0xF8 - 5];
    s32 unkF8;
    u8 padFC[0x1D4 - 0xFC];
    void *unk1D4;
    void *unk1D8;
    u8 pad1DC[0x264 - 0x1DC];
    s32 unk264;
};

void func_1502F948(struct func_1502F948_s *arg0) {
    s32 idx;

    if ((arg0->unkF8 & 0x4000) && (arg0->unk264 != 0) && (arg0->unk1D4 != NULL)) {
        idx = arg0->unk4;
        if (arg0->unk1D8 == NULL) {
            arg0->unk1D8 = allocate_memory(D_800C4ED0[idx] << 6, 1, 1, 2);
            if (arg0->unk1D8 == NULL) {
                return;
            }
        }
        bcopy(arg0->unk1D4, arg0->unk1D8, D_800C4ED0[idx] << 6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FD70.s")
