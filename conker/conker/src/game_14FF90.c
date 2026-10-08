#include <ultra64.h>

#include "functions.h"
#include "variables.h"

extern f32 D_800A34B0[4][2];
extern f32 D_800A34D0;
extern f32 D_800A34D4;
extern f32 D_800A34D8;
extern f32 D_800A34DC;
extern f32 D_800A34E0;
extern f32 D_800A34E4;
extern f32 D_800A34E8;
extern f32 D_800A34EC;
extern f32 D_800A34F0;
extern f32 D_800A34F4;
extern f32 D_800A34F8;
extern f32 D_800A34FC;
extern f32 D_800A3500;
extern f32 D_800A3504;
extern f32 D_800A3508;
extern f32 D_800A350C;
extern f32 D_800A3510;
extern f32 D_800A3514;
extern f32 D_800A3518;
extern f32 D_800A351C;
extern f32 D_800A3520;
extern f32 D_800A3524;
extern f32 D_800A3528;
extern f32 D_800A352C;
extern f32 D_800A3530;
extern f32 D_800A3534;
extern f32 D_800A3538;
extern f32 D_800A353C;
extern f32 D_800A3540;
extern f32 D_800A3544;
extern f32 D_800A3548;
extern f32 D_800A354C;
extern f32 D_800A3550;
extern f32 D_800A3554;
extern f32 D_800A3558;
extern f32 D_800A355C;
extern f32 D_800A3560;
extern f32 D_800A3564;
extern f32 D_800A3568;
extern f32 D_800A356C;
extern f32 D_800A3570;
extern f32 D_800A3574;
extern f32 D_800A3578;
extern f32 D_800A357C;
extern f32 D_800A3580;
extern f32 D_800A3584;
extern f32 D_800A3588;
extern f32 D_800A358C;
extern f32 D_800A3590;
extern f32 D_800A3594;
extern f32 D_800A3598;
extern f32 D_800A359C;
extern f32 D_800A35A0;
extern f32 D_800A35A4;
extern f32 D_800A35A8;
extern f32 D_800A35AC;


#if 0
f32 D_800A34B0[4][2] = {
    { 267.0f, 100.0f },
    { 247.0f, 100.0f },
    { 370.0f, 185.0f },
    { 530.0f, 400.0f }
};

f32 D_800A34D0 = 0.01666666753590107f;
f32 D_800A34D4 = 0.10000000149011612f;
f32 D_800A34D8 = 999.0f;
f32 D_800A34DC = 0.01745329238474369f;
f32 D_800A34E0 = 0.01745329238474369f;
f32 D_800A34E4 = 0.01745329238474369f;
f32 D_800A34E8 = 0.01745329238474369f;
f32 D_800A34EC = 530.0f;
f32 D_800A34F0 = 3.1415927410125732f;
f32 D_800A34F4 = 3.1415927410125732f;
f32 D_800A34F8 = 0.3253220021724701f;
f32 D_800A34FC = 1.5707963705062866f;
f32 D_800A3500 = 1.5707963705062866f;
f32 D_800A3504 = 0.6499999761581421f;
f32 D_800A3508 = 0.550000011920929f;
f32 D_800A350C = 0.8999999761581421f;
f32 D_800A3510 = 0.8500000238418579f;
f32 D_800A3514 = -10000.0f;
f32 D_800A3518 = 0.0033333334140479565f;
f32 D_800A351C = 57.2957763671875f;
f32 D_800A3520 = 0.01745329238474369f;
f32 D_800A3524 = 0.01745329238474369f;
f32 D_800A3528 = 0.01745329238474369f;
f32 D_800A352C = 0.01745329238474369f;
f32 D_800A3530 = 0.01745329238474369f;
f32 D_800A3534 = 6.2831854820251465f;
f32 D_800A3538 = 0.01745329238474369f;
f32 D_800A353C = 0.03999999910593033f;
f32 D_800A3540 = 0.05000000074505806f;
f32 D_800A3544 = 0.07999999821186066f;
f32 D_800A3548 = 0.03999999910593033f;
f32 D_800A354C = 0.05000000074505806f;
f32 D_800A3550 = 0.01745329238474369f;
f32 D_800A3554 = 0.01745329238474369f;
f32 D_800A3558 = 0.019999999552965164f;
f32 D_800A355C = 0.01745329238474369f;
f32 D_800A3560 = 0.6000000238418579f;
f32 D_800A3564 = 10000.0f;
f32 D_800A3568 = 10000.0f;
f32 D_800A356C = -0.01745329238474369f;
f32 D_800A3570 = -0.01745329238474369f;
f32 D_800A3574 = -0.01745329238474369f;
f32 D_800A3578 = -0.01745329238474369f;
f32 D_800A357C = -0.9399999976158142f;
f32 D_800A3580 = -10000.0f;
f32 D_800A3584 = 0.01666666753590107f;
f32 D_800A3588 = 0.01745329238474369f;
f32 D_800A358C = 0.02500000037252903f;
f32 D_800A3590 = -0.01745329238474369f;
f32 D_800A3594 = -0.01745329238474369f;
f32 D_800A3598 = -0.01745329238474369f;
f32 D_800A359C = -0.01745329238474369f;
f32 D_800A35A0 = 999.0f;
f32 D_800A35A4 = 0.01745329238474369f;
f32 D_800A35A8 = 999.0f;
f32 D_800A35AC = 999.0f;
#endif

void func_15122AE0(void) {
    struct108 *temp_s0;
    s16 i;
    f32 temp_f20;

    temp_f20 = D_800BEA08 * D_800A34D0;

    for (i = 0; i <= D_80082FA0; i++) {
        temp_s0 = &D_800DBFF0[i]; // ???
        if (func_150859AC(i, 0) || (i == 0)) {
            temp_s0->unk7B4 = temp_f20;
            if ((D_800BEAC0 == 0) || (D_800C35EA != 0) || (D_800D2DB4 != 0)) {
                func_151239CC(temp_s0, 5);
                func_15122C5C(temp_s0);
            } else {
                func_15123934(temp_s0, 8192, 0, temp_s0->unk134, 5);
                func_1512C490(temp_s0);
            }
        }
    }
    D_800894B0 += 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15122C5C.s")
// NON-MATCHING: 80% there
// void func_15122C5C(struct108 *arg0) {
//     f32 phi_f12;
//     u8 temp_v0_2;
//     struct167 *temp_a1;
//     struct167 *temp_a0;
//
//     if (arg0->unk23C) {
//         arg0->unk2E0 = arg0->unk2BC;
//         arg0->unk2E4 = arg0->unk2C0;
//         arg0->unk2F0 = arg0->unk2FC;
//
//         arg0->unk2EC = arg0->unk2F8;
//         arg0->unk2E8 = arg0->unk2C4;
//         arg0->unk2F4 = arg0->unk300;
//     }
//
//     temp_a0 = &arg0->unk2BC;
//     temp_a1 = &arg0->unk2F8;
//
//     if ((arg0->unk3D4 != NULL) && (arg0->unk73C != 3) && ((arg0->unk2C != 0x100) || (arg0->unk73C != 0))) {
//         arg0->unk23E = arg0->unk3D4->unk78;
//     }
//
//     temp_v0_2 = arg0->unk23D;
//
//     if (D_800DBFF4[temp_v0_2] != 4) {
//         arg0->unk5F0 &= -5;
//     }
//
//     if ((arg0->unk2C << 9) >= 0) {
//         temp_a0->unk0 = arg0->unk2E0;
//         temp_a0->unk4 = arg0->unk2E4;
//         temp_a0->unk8 = arg0->unk2E8;
//         temp_a1->unk0 = arg0->unk2EC;
//         temp_a1->unk4 = arg0->unk2F0;
//         temp_a1->unk8 = arg0->unk2F4;
//     }
//     // temp_v0_2 = arg0->unk23D;
//     arg0->unk36C = D_800BE728[temp_v0_2];
//     arg0->unk36A = D_800BE710[temp_v0_2];
//     arg0->unk304 = temp_a1->unk0;
//     arg0->unk308 = temp_a1->unk4;
//     arg0->unk358 = arg0->unk35C;
//     arg0->unk30C = temp_a1->unk8;
//     arg0->unk2C8 = temp_a0->unk0;
//     arg0->unk2CC = temp_a0->unk4;
//     arg0->unk2D0 = temp_a0->unk8;
//     if (arg0->unk23C != 0) {
//         arg0->unk19C = arg0->unk1A4;
//         arg0->unk1A0 = arg0->unk1A8;
//         // phi_f12 = *(s32*)&arg0; // unk0?
//     } else {
//         arg0->unk19C += (arg0->unk1A4 - arg0->unk19C) * D_800A34D4;
//         arg0->unk1A0 += (arg0->unk1A8 - arg0->unk1A0) * D_800A34D4;
//         phi_f12 = D_800A34D4;
//     }
//
//     func_1510B128(phi_f12, temp_v0_2, arg0->unk19C, arg0->unk1A0, D_800BE628[temp_v0_2].unk84, (arg0->unk2C & 0x100) ? 16.0f : 0.0f);
//     func_15097798(arg0->unk23D);
//     func_15125A6C(arg0);
//     func_15128CB0(arg0);
//     func_15125DB4(arg0);
//     if ((arg0->unk3D4->unk120 != 0) && (arg0->unk3D4->unk197 != 0)) {
//         func_15127EB8(arg0);
//     }
//     if (func_15128540(arg0) == 0) {
//         if (((arg0->unk84 * 0x10) < 0) && ((arg0->unk84 & 0x400) == 0)) {
//             func_1512E8E0(arg0);
//         }
//         func_15130230(arg0, D_800BE9F0);
//         func_15126138(arg0);
//         func_15125C40(arg0);
//         func_15128680(arg0);
//         func_1512317C(arg0);
//         func_15125394(arg0);
//         if (((arg0->unk84 * 16) >= 0) && ((arg0->unk84 & 0x400) == 0)) {
//             func_1512E8E0(arg0);
//         }
//         func_15123568(arg0);
//         func_1512C200(arg0);
//         func_15125924(arg0);
//         func_151283B8(arg0);
//         if (arg0->unk23C != 0) {
//             func_15125594(arg0);
//             func_15123070(arg0);
//             func_151283B8(arg0);
//             func_151283B8(arg0);
//         }
//         func_15123508(arg0);
//         if (((arg0->unk84 & 2) != 0) && (arg0->unk3D4->unk120 == 0)) {
//             func_1512D390(arg0);
//         }
//         func_15125594(arg0);
//         func_151256BC(arg0);
//         func_1512D980(arg0);
//         func_1512C068(arg0);
//         func_1512B100(arg0);
//         func_1512C20C(arg0);
//         func_1512BB10(arg0);
//         if (arg0->unk23C != 0) {
//             func_1512C068(arg0);
//             func_1512B100(arg0);
//             func_1512C20C(arg0);
//             func_1512BB10(arg0);
//         }
//         func_15125594(arg0);
//         func_15123070(arg0);
//         if (arg0->unk7F4 == 0) {
//             func_151287E0(arg0, 0, 0);
//         }
//         func_1512C150(arg0);
//         func_151284C4(arg0);
//     }
// }

void func_15123070(struct108 *arg0) {
    f32 temp_f0;

    if ((arg0->unk6C8 != 0) && ((arg0->unk6FC == 10) || (arg0->unk6FC == 14))) {
        struct17 tmp;
        func_15048F90(&arg0->unk618, &arg0->unk2A4, &tmp, arg0);
        arg0->unk390 = arg0->unk37C - func_15048FC8(&tmp);
    } else {
        temp_f0 = arg0->unk3D0->unk40 - arg0->unk37C - 180.0f;
        while (temp_f0 < 0.0f) {
            temp_f0 += 360.0f;
        }
        arg0->unk390 = temp_f0;
    }

    while (arg0->unk390 < -360.0f) {
        arg0->unk390 += 360.0f;
    }
}
// NON-MATCHING: 1 missing lui
// void func_15123070(struct108 *arg0) {
//     f32 temp_f0;
//     struct17 tmp;
//
//     if ((arg0->unk6C8 != 0) && ((arg0->unk6FC == 10) || (arg0->unk6FC == 14))) {
//         func_15048F90(&arg0->unk618, &arg0->unk2A4, &tmp, arg0);
//         arg0->unk390 = arg0->unk37C - func_15048FC8(&tmp);
//     } else {
//         temp_f0 = arg0->unk3D0->unk40 - arg0->unk37C - 180.0f;
//
//         while (temp_f0 < 0.0f) {
//             temp_f0 += 360.0f;
//         }
//
//         arg0->unk390 = temp_f0;
//     }
//
//     while (arg0->unk390 < -360.0f) {
//         arg0->unk390 += 360.0f;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_1512317C.s")

void func_15123508(struct108 *arg0) {
    if ((arg0->unk84 & 2) != 0) {
        if (((arg0->unk36A & 2) != 0) && (arg0->unk698 == 0)) {
            arg0->unk6B0 = -1;
        }
        if (((arg0->unk36A & 1) != 0) && (arg0->unk698 == 0)) {
            arg0->unk6B0 = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15123568.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_151236D0.s")
// Inverse of func_151239CC: saves arg0's "current" fields into the
// arg4'th slot of its internal 0x15-element history arrays (see the
// struct108 fix near func_151239CC above), then overwrites the current
// fields with arg1/arg2/arg3 and marks the slot occupied. Raw void*
// offset casts (not typed struct108* navigation) get IDO to emit the
// plain bnez target uses, same as func_151239CC's fix.
s32 func_15123934(struct108 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *v1 = (char *) arg0 + arg4 * 2;
    void *v0;

    if (*(s16 *) ((char *) v1 + 0x20C) == 0) {
        *(u16 *) ((char *) v1 + 0x2) = arg0->unk0;
        v0 = (char *) arg0 + arg4 * 4;
        *(s32 *) ((char *) v0 + 0x30) = arg0->unk2C;
        *(s32 *) ((char *) v0 + 0x88) = arg0->unk84;
        *(s32 *) ((char *) v0 + 0xE0) = arg0->unkDC;
        *(s32 *) ((char *) v0 + 0x138) = arg0->unk134;
        *(s16 *) ((char *) v1 + 0x1B6) = arg0->unk1B4;
        *(s16 *) ((char *) v1 + 0x1E2) = arg0->unk1E0;
        arg0->unk2C = arg1;
        arg0->unkDC = arg2;
        arg0->unk134 = arg3;
        *(s16 *) ((char *) v1 + 0x20C) = 1;
        func_15125394(arg0);
        return 1;
    }
    return 0;
}

// NON-MATCHING (extremely close - 2 words off out of 28, both the
// prologue/epilogue frame-size adjustment). arg1 selects a saved "slot"
// within arg0's internal 0x15-element history arrays (unk2/unk30/unk88/
// unkE0/unk138/unk1B6/unk1E2/unk20C - see the struct108 fix above,
// discovered from this function) and restores it into the "current"
// scalar fields; unk20C[arg1] doubles as an occupied flag, cleared after
// restoring. Getting here required two non-obvious fixes vs. the first
// attempt: (1) the call at the end is func_15124B18(arg0), NOT
// func_15124B18(v1) - $a0 is never touched before the jal and nothing
// after the call uses it, so it must be the call argument; passing v1
// instead forces an extra `move a2,a0` / register reshuffle throughout
// the whole function. (2) using struct108* (typed) pointer navigation
// for v1/v0 instead of raw void*/char* offset casts makes IDO emit a
// beql/bnel (branch-likely) guard instead of target's plain beqz - same
// "typed struct nav vs raw pointer cast changes branch-likely selection"
// lesson as elsewhere in this codebase; switching to raw casts fixes the
// branch type. With both fixed, EVERY instruction's content and order
// matches target exactly (including the v1 register choice, the a0/v1
// register split with no extra moves, and the v1 spill landing at the
// correct sp+0x1C) except the frame size itself: target is -0x28... no,
// target is -0x20 (32 bytes) with v1's spill still at 0x1C, but every
// source variant that gets the spill at the correct 0x1C also computes a
// frame of -0x28 (8 bytes too big); the one variant that shrinks the
// frame to the correct -0x20 moves the spill to 0x18 instead - the two
// seem coupled through the same unidentified IDO heuristic documented
// for func_15141564 above. Best candidate kept below for reference.
struct func_151239CC_s {
    /* 0x000 */ u16 unk0;
    /* 0x002 */ u16 unk2[0x15];
    /* 0x02C */ s32 unk2C[0x16];
    /* 0x084 */ s32 unk84[0x16];
    /* 0x0DC */ s32 unkDC[0x16];
    /* 0x134 */ s32 unk134[0x16];
    /* 0x18C */ u8 pad18C[0x1B4 - 0x18C];
    /* 0x1B4 */ s16 unk1B4[0x16];
    /* 0x1E0 */ s16 unk1E0[0x16];
    /* 0x20C */ s16 unk20C[0x16];
};

s32 func_151239CC(struct func_151239CC_s *arg0, s32 arg1) {
    if (arg0->unk20C[arg1] != 0) {
        arg0->unk0 = arg0->unk2[arg1];
        arg0->unk2C[0] = arg0->unk2C[arg1 + 1];
        arg0->unkDC[0] = arg0->unkDC[arg1 + 1];
        arg0->unk84[0] = arg0->unk84[arg1 + 1];
        arg0->unk134[0] = arg0->unk134[arg1 + 1];
        arg0->unk1B4[0] = arg0->unk1B4[arg1 + 1];
        arg0->unk1E0[0] = arg0->unk1E0[arg1 + 1];
        func_15124B18(arg0);
        arg0->unk20C[arg1] = 0;
        return 1;
    }
    return 0;
}
// s32 func_151239CC(struct108 *arg0, s32 arg1) {
//     void *v1 = (char *) arg0 + arg1 * 2;
//     void *v0;
//
//     if (*(s16 *) ((char *) v1 + 0x20C) != 0) {
//         arg0->unk0 = *(u16 *) ((char *) v1 + 0x2);
//         v0 = (char *) arg0 + arg1 * 4;
//         arg0->unk2C = *(s32 *) ((char *) v0 + 0x30);
//         arg0->unkDC = *(s32 *) ((char *) v0 + 0xE0);
//         arg0->unk84 = *(s32 *) ((char *) v0 + 0x88);
//         arg0->unk134 = *(s32 *) ((char *) v0 + 0x138);
//         arg0->unk1B4 = *(s16 *) ((char *) v1 + 0x1B6);
//         arg0->unk1E0 = *(s16 *) ((char *) v1 + 0x1E2);
//         func_15124B18(arg0);
//         *(s16 *) ((char *) v1 + 0x20C) = 0;
//         return 1;
//     }
//     return 0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15123A54.s")

void func_15124770(struct108 *arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk244 = arg1;
        arg0->unk248 = &gObjects[arg1];
    } else {
        arg0->unk244 = 0;
        arg0->unk248 = NULL;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_151247C0.s")

void func_15124AB4(struct108 *arg0) {
    arg0->unk668 = -sinf(arg0->unk398);
    arg0->unk66C = cosf(arg0->unk398);
    arg0->unk664 = sinf(arg0->unk39C) * arg0->unk66C;
    arg0->unk66C = cosf(arg0->unk39C) * arg0->unk66C;
}

void func_15124B18(struct108 *arg0) {
    s32 temp_t8;
    f32 *temp_v0;

    if (arg0->unk1B4 == 0) {
        arg0->unk1B4 = 4;
    }
    temp_t8 = arg0->unk2C & 0x80;
    if ((temp_t8 != 0) && ((*arg0->unk36C & 0x10) != 0)) {
        arg0->unk348 = 40.0f;
        arg0->unk34C = 40.0f;
        arg0->unk374 = 150.0f;
    } else if (temp_t8 != 0) {
        arg0->unk348 = (f32) (arg0->unk2FC - arg0->unk354);
    } else if ((temp_t8 != 0) && (arg0->unk3D0->unk102 == 0) && (D_800BE9F0 != 0x17)) {
        arg0->unk348 = 40.0f;
        arg0->unk34C = 40.0f;
        arg0->unk374 = 150.0f;
    } else if (arg0->unk3D0->unk102 != 0) {
        arg0->unk348 = 40.0f;
        arg0->unk34C = 40.0f;
        arg0->unk374 = 194.0f;
    } else {
        temp_v0 = D_800A34B0[arg0->unk1B4];
        arg0->unk374 = temp_v0[0]; //->unk0;
        arg0->unk348 = temp_v0[1]; //->unk4;
        arg0->unk34C = arg0->unk348;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15124C38.s")

void func_1512523C(struct108 *arg0) {
    f32 temp_f12;
    f32 temp_f2;
    f32 phi_f14;

    temp_f2 = arg0->unk2BC - arg0->unk2F8;
    temp_f12 = arg0->unk2C4 - arg0->unk300;
    temp_f12 = sqrtf((temp_f2 * temp_f2) + (temp_f12 * temp_f12));
    if (temp_f12 < 0.0f) {
        phi_f14 = -temp_f12;
    } else {
        phi_f14 = temp_f12;
    }
    temp_f2 = func_150484A0(arg0->unk2FC - arg0->unk2C0, phi_f14) * D_800A351C;
    arg0->unk388 = temp_f2;
    if (temp_f2 > 180.0f) {
        arg0->unk388 -= 360.0f;
    }
    arg0->unk388 = -arg0->unk388;
    arg0->unk388 -= arg0->unk3A8;
    arg0->unk388 += arg0->unk38C;
    arg0->unk398 = arg0->unk388 * D_800A3520;
}

void func_15125330(struct108 *arg0) {
    struct17 tmp;

    tmp.unk0 = arg0->unk2BC - arg0->unk2F8;
    tmp.unk4 = 0.0f;
    tmp.unk8 = arg0->unk2C4 - arg0->unk300;

    arg0->unk37C = func_15048FC8(&tmp);
    arg0->unk39C = arg0->unk37C * D_800A3524;
}

void func_15125394(struct108 *arg0) {
    s32 i = 0;

    while ((arg0->unk2C & (1 << i)) == 0) {
        i += 1;
    }
    arg0->unk0 = i;
}

s32 func_151253CC(struct108 *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    if (arg0->unk2C & 0x40000) {
        arg0->unk84 &= ~0x4F;
        arg0->unk84 |= 0x2680;
        arg0->unk3A8 = 0.0f;
        arg0->unk5E8 = 0.0f;
        arg0->unk38C = 0.0f;
        func_15125330(arg0);
        func_1512523C(arg0);
        temp_f0 = arg0->unk37C;
        temp_f2 = D_800A3528;
        arg0->unk380 = arg0->unk37C;
        arg0->unk3A0 = (f32) (temp_f0 * temp_f2);
        arg0->unk398 = (f32) (arg0->unk388 * temp_f2);
        func_15124AB4(arg0);
        if (arg0->unk3D4->unk197 != 0) {
            func_15127EB8(arg0);
        }
        func_1512C490(arg0);
        return 1;
    }
    return 0;
}

// no idea what going on here
// NON-MATCHING: semantics fully recovered and verified via isolated
// harness - reads arg0->unk3D0 (a pointer), returns 0 unless its
// byte at +0xAD is 1, then measures |unk18 - unk118| (both f32,
// truncated to int) against two thresholds: <100 -> 0, <301 -> the
// unk3D0 pointer itself (returned as-is, not coerced to a boolean -
// matches target literally), else 1. Blocked by the same fabsf()
// round-trip limitation already documented on func_1514672C in
// game_16EE20.c: target compiles the abs() straight to a single
// abs.s with no argument-promotion dance, but every source form of
// fabsf() in this codebase's IDO always produces a cvt.d.s/cvt.s.d
// round-trip around it - confirmed present here too. Every other
// branch/return shape (including the two dead-branch delay-slot
// duplicates and the raw-pointer return) already matches target
// exactly.
// s32 func_15125490(void *arg0) {
//     void *v0 = *(void **) ((char *) arg0 + 0x3D0);
//     s32 v1;
//
//     if (*(u8 *) ((char *) v0 + 0xAD) != 1) {
//         return 0;
//     }
//
//     v1 = (s32) fabsf(*(f32 *) ((char *) v0 + 0x18) - *(f32 *) ((char *) v0 + 0x118));
//
//     if (v1 < 0x64) {
//         return 0;
//     }
//     if (v1 < 0x12D) {
//         return (s32) v0;
//     }
//     return 1;
// }
s32 func_15125490(s32 arg0) {
    s32 v0 = *(s32 *) (arg0 + 0x3D0);
    s32 v1;

    if (*(u8 *) (v0 + 0xAD) == 1) {
        v1 = fabsf(*(f32 *) (v0 + 0x18) - *(f32 *) (v0 + 0x118));
        if (v1 < 100) {
            return 0;
        }
        if (v1 >= 301) {
            return 1;
        }
    } else {
        return 0;
    }
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Scales unk380/388
// into unk3A0/398 by D_800A352C, calls func_15124AB4 then
// func_151239CC(arg0, 1), clears arg0->unk3D4->unk198/unk73C/unk670,
// and points unk3D0 at gObjects[arg1]. Confirmed this round: naming
// D_800A352C's load as a single local (`f32 scale = D_800A352C;`)
// reused for both multiplies - not read twice - matches target's f0
// register reuse exactly, and every other instruction/offset in the
// function matches target byte-for-byte including the exact
// unk670-before-unk3D0 write order. The one remaining gap: target's
// prologue loads D_800A352C's address *before* spilling the incoming
// a0/a1 registers to their stack shadow slots; every source form
// tried here spills first, so the two instruction pairs land swapped.
#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_151254F4.s")
// void func_151254F4(struct108 *arg0, s32 arg1) {
//     f32 scale = D_800A352C;
//
//     arg0->unk3A0 = arg0->unk380 * scale;
//     arg0->unk398 = arg0->unk388 * scale;
//     func_15124AB4(arg0);
//     func_151239CC(arg0, 1);
//     arg0->unk3D4->unk198 = 0;
//     arg0->unk73C = 0;
//     arg0->unk670 = 0.0f;
//     arg0->unk3D0 = &gObjects[arg1];
// }

void func_15125594(struct108 *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    func_1512523C(arg0);
    func_15125330(arg0);

    temp_f0 = arg0->unk37C;
    temp_f2 = arg0->unk5E8;
    arg0->unk380 = temp_f0 - temp_f2;
    if (temp_f0 < temp_f2) {
        arg0->unk380 += 360.0f;
    }
    arg0->unk3A0 = arg0->unk380 * D_800A3530;
    func_15124AB4(arg0);
}


void func_15125608(struct108 *arg0) {
    arg0->unk24C = 3.0f;
    arg0->unk250 = 2.5f;
}

// D_800DBFF4..D_800DBFF6+1 are 4 consecutive bytes - a for-loop over
// them, fully unrolled by IDO -O2.
void func_15125628(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800DBFF4[i] != 0) {
            D_800DBFF4[i]--;
        }
    }
}

void func_15125690(struct108 *arg0, s32 arg1) {
    u8 *temp_v0 = &D_800DBFF4[arg0->unk23D];

    if (*temp_v0 < arg1) {
        *temp_v0 = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_151256BC.s")
void func_15125924(struct108 *arg0) {
    s32 var_v1;
    s32 var_a1;
    f32 temp_f0;
    s32 temp_v0_2;

    struct127 *temp_v0;

    if ((temp_v0 = arg0->unk3D4) != NULL) {
        var_v1 = *((u8 *) temp_v0 + 0x4E);
        var_a1 = temp_v0->z_position;
    } else {
        var_a1 = 0;
        var_v1 = 0;
    }
    if (arg0->unk2C & 0x40) {
        return;
    }
    if (!(arg0->unk84 & 0x4000) && (arg0->unk3D0->unk102 == 0)) {
        return;
    }
    if ((func_15125490((s32) arg0) != 0) && (var_v1 == 0) && (var_a1 == 0)) {
        if ((func_15123934(arg0, 0x80, 1, 1, 0xD) != 0) && (arg0->unk6C8 == 0)) {
            func_15124B18(arg0);
            arg0->unk5F0 |= 0x1000;
        }
    } else {
        if (arg0->unk2C & 0x80) {
            func_151239CC(arg0, 0xD);
            arg0->unk190 = 0.0f;
        }
        temp_v0_2 = arg0->unk5F0;
        if (temp_v0_2 & 0x1000) {
            temp_f0 = arg0->unk2FC - arg0->unk354;
            arg0->unk5F0 = temp_v0_2 & ~0x1000;
            *(f32 *) ((u8 *) arg0 + 0x344) = temp_f0;
            arg0->unk348 = temp_f0;
        }
    }
}
struct func_15125A6C_s {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    u8  unkC[0x8];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8  pad2C[0x30];
    u8  unk5C;
};

void func_15125A6C(struct108 *arg0) {
    f32 pad44;
    f32 pad40;
    f32 pad3C;
    f32 sp38;
    f32 pad34;
    f32 pad30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    struct func_15125A6C_s *s;
    u8 temp_v0;

    temp_v0 = arg0->unk23E;
    if (temp_v0 == 0x2A) {
        sp38 = arg0->unk3D0->unk40;
        if (arg0->unk2C != 0x40000) {
            func_1512D560(arg0, 5, 0);
            arg0->unk7E4 = 1;
        }
        D_800DBFF4[0] = 3;
        s = (struct func_15125A6C_s *)&D_800C3600;
        ((struct func_15125A6C_s *)&D_800C3600)->unk0 = 1;
        ((struct func_15125A6C_s *)&D_800C3600)->unk4 = 0;
        sp28 = sp38 * D_800A3550;
        sp2C = sinf(sp28);
        sp24 = (sp38 - 90.0f) * D_800A3554;
        s->unk14 = (sinf(sp24) * 46.0f) + (arg0->unk3D0->x_position + (138.0f * sp2C));
        s->unk18 = arg0->unk3D0->y_position + 96.0f;
        sp2C = cosf(sp28);
        s->unk1C = (cosf(sp24) * 46.0f) + (arg0->unk3D0->z_position + (138.0f * sp2C));
        ((struct func_15125A6C_s *)&D_800C3600)->unk20 = 0.0f;
        s->unk24 = -180.0f;
        ((struct func_15125A6C_s *)&D_800C3600)->unk8 = 0.0f;
        ((struct func_15125A6C_s *)&D_800C3600)->unk28 = sp38 - 180.0f;
        s->unk5C = 0;
        func_1512D560(arg0, 7, s);
        return;
    }

    if (arg0->unk7E4 != 0) {
        func_1512D560(arg0, 6, 0);
        arg0->unk7E4 = 0;
    }
}
// NON-MATCHING: miles away
// void func_15125A6C(struct108 *arg0) {
//     f32 pad3C;
//     f32 sp38;
//     f32 pad34;
//     f32 pad30;
//     f32 sp2C;
//     f32 sp28;
//     f32 sp24;
//
//     f32 temp_f12;
//     f32 temp_f12_2;
//
//     if (arg0->unk23E == 0x2A) {
//         sp38 = arg0->unk3D0->unk40;
//         if (arg0->unk2C != 0x40000) {
//             func_1512D560(arg0, 5, 0);
//             arg0->unk7E4 = 1U;
//         }
//         D_800DBFF4[0] = 3;
//         D_800C3600->unk0 = 1;
//         D_800C3600->unk4 = 0;
//         temp_f12 = sp38 * D_800A3550;
//         sp28 = temp_f12;
//         sp2C = sinf(temp_f12);
//         temp_f12_2 = (sp38 - 90.0f) * D_800A3554;
//         sp24 = temp_f12_2;
//         D_800C3600->unk14 = (sinf(temp_f12_2) * 46.0f) + (arg0->unk3D0->unk14 + (138.0f * sp2C));
//         D_800C3600->unk18 = arg0->unk3D0->unk18 + 96.0f;
//         sp2C = cosf(temp_f12);
//         D_800C3600->unk1C = (cosf(temp_f12_2) * 46.0f) + (arg0->unk3D0->unk1C + (138.0f * sp2C));
//         D_800C3600->unk20 = 0.0f;
//         D_800C3600->unk24 = -180.0f;
//         D_800C3600->unk8 = 0.0f;
//         D_800C3600->unk28 = sp38 - 180.0f;
//         D_800C3600->unk5C = 0;
//         func_1512D560(arg0, 7, D_800C3600);
//         return;
//     }
//
//     if (arg0->unk7E4 != 0) {
//         func_1512D560(arg0, 6, 0);
//         arg0->unk7E4 = 0U;
//     }
// }

void func_15125C40(struct108 *arg0) {
    s32 a;
    s32 b;
    s32 t;

    t = arg0->unk23E;
    a = (D_800D1940 == 0x42) && (t == 0x1A);
    b = (t == 3) || (t == 0x1A) || a;
    arg0->unk7CC--;
    if (b) {
        if (arg0->unk7CC == 0) {
            if (a) {
                func_1509BFB0(3, 0x9000, 0x18, (s32)arg0->unk3D0->unk40, 0, 250);
            } else if (t == 0x1A) {
                func_1509BFB0(3, 0x9000, 0x18, 0, 0, 250);
            }
            arg0->unk5F0 |= 2;
            *arg0->unk36C |= 0x10;
            arg0->unk36A |= 0x10;
            arg0->unk7CC = 1;
        }
    } else {
        if (arg0->unk5F0 & 2) {
            if (!b) {
                func_1509BFB0(1, 0x9000, 0x10, 0);
                func_1509BFB0(1, 0x9000, 0xF, 0);
                arg0->unk5F0 &= ~2;
            }
        }
        arg0->unk7CC = 2;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15125DB4.s")

void func_15126138(struct108 *arg0) {
    struct127 *temp_v0_2;
    struct108 *phi_a0;

    func_151247C0(arg0);

    temp_v0_2 = arg0->unk3D0;

    if (((temp_v0_2->x_position != arg0->unk2B0) ||
         (temp_v0_2->y_position != arg0->unk2B4) ||
         (temp_v0_2->z_position != arg0->unk2B8)) && ((arg0->unk2C & ~0x100) != 0)) {
        arg0->unk298 = 1;
        arg0->unk7E6 = 60;
        arg0->unk8ED = 0;
    } else {
        arg0->unk298 = 0;
    }

    if (arg0->unk84 & 0x200000) {
        temp_v0_2 = arg0->unk3D0; // again?!
        if (temp_v0_2->interaction_state != 0x1E) {
            if (temp_v0_2->unk102 == 0) {
                if ((*(arg0->unk36C) & 0xF) != 0) {
                    if ((arg0->unk2C & 0x40) == 0) {
                        func_151220D0(arg0);
                    }
                }
            }
        }
    }
    func_15124C38(arg0, 0);
}


struct func_1512623C_s {
    u8 pad0[0x14];
    f32 x;
    f32 y;
    f32 z;
    u8 pad20[0x1D4 - 0x20];
    u8 *unk1D4;
};

struct func_1512623C_t {
    u8 pad0[0x114];
    s16 unk114;
};

void func_1512623C(struct func_1512623C_s *arg0, struct func_1512623C_t *arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5, s32 arg6) {
    s32 ret = 1;
    f32 vec[3];
    f32 out[3];
    s32 idx;
    u8 *m;
    s32 pad;

    if (arg0->unk1D4 != NULL) {
        ret = 0;
        if (arg6 != 0) {
            idx = 3;
            vec[0] = 0.0f;
            vec[1] = 20.0f;
            vec[2] = 0.0f;
        } else if (arg2 == 0x1B) {
            idx = 4;
            vec[1] = 116.0f;
            vec[0] = 0.0f;
            vec[2] = 130.0f;
        } else {
            ret = 1;
        }
        if (ret == 0) {
            m = arg0->unk1D4;
            m += idx << 6;
            func_15143134(vec, out, m);
            *arg3 = out[0];
            *arg4 = out[1];
            *arg5 = out[2];
        }
    }
    if (ret != 0) {
        *arg3 = arg0->x;
        *arg4 = arg0->y + arg1->unk114 * 0.75f;
        *arg5 = arg0->z;
    }
}
// ooh mama
#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15126378.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15127520.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_151277B0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_151279A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15127EB8.s")
// NON-MATCHING: not too far away
// void func_15127EB8(struct108 *arg0) {
//     struct127 *phi_v0;
//
//     func_151239CC(arg0, 1);
//     arg0->unk3D4->unk197 = (u8)0;
//     func_151C9ED4(arg0);
//     arg0->unk19C = 0.0f;
//     arg0->unk1A0 = 0.0f;
//     arg0->unk1A4 = 0.0f;
//     arg0->unk1A8 = 0.0f;
//     func_1510B32C(arg0->unk23D, 0.0f, 0.0f, 1.0f);
//     D_800BE628[arg0->unk23D].unk84 = 1.0f;
//     func_150627D4(arg0->unk3D0);
//     D_800DBFF4[arg0->unk23D] = (u8)2;
//
//     phi_v0 = &arg0->unk3D0;
//     if (phi_v0->unk65 != 0) {
//         phi_v0 = &gObjects[phi_v0->unk65];
//     }
//
//     phi_v0->unk2FC &= ~(1 << arg0->unk23D);
//     phi_v0->unk74 &= ~(1 << arg0->unk23D);
//     arg0->unk23C = (u8)1;
// }

void func_15127FEC(struct108 *arg0, s32 arg1, s32 arg2) {
    arg0->unk7F4 = 1;
    arg0->unk7F8 = arg0->unk2A4;
    arg0->unk7FC = arg0->unk2A8;
    arg0->unk800 = *(f32*)&arg0->unk2AC;
    func_1512A390();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14FF90/func_15128030.s")
void func_15121C80(struct108 *arg0, f32 arg1);
void func_151283B8(struct108 *arg0) {
    switch (arg0->unk2C) {
    case 0x80:
        func_15122440(arg0);
        break;
    case 0x40:
        func_15129934(arg0);
        break;
    case 1:
        func_15122980(arg0);
        break;
    case 8:
        func_15121C80(arg0, 0.0f);
        break;
    case 2:
        func_151220D0(arg0);
        break;
    case 0x400:
        func_15122170(arg0);
        break;
    case 0x800:
        func_15122980(arg0);
        break;
    case 0x100:
        func_15120158(arg0);
        break;
    case 0x800000:
        func_1512DEA4(arg0);
        break;
    case 0x2000:
        break;
    }
}
// Copies the tracked object's (arg0->unk3D0) position into the camera's
// unk2B0/2B4/2B8, decrements a counter, and every ~60 frames (once
// unk5FE counts down to 0) re-triggers func_15128774 if flag 8 is set in
// unk84.
void func_151284C4(struct108 *arg0) {
    struct127 *v0;

    func_1512C490(arg0);
    v0 = arg0->unk3D0;
    arg0->unk2B0 = v0->x_position;
    arg0->unk2B4 = v0->y_position;
    arg0->unk2B8 = v0->z_position;
    if (arg0->unk23C != 0) {
        arg0->unk23C -= 1;
    }
    if ((arg0->unk84 & 8) != 0) {
        if (arg0->unk5FE <= 0) {
            arg0->unk5FE = 0x3C;
            func_15128774(arg0, arg0->unk3D0);
        }
    }
}
struct func_15128540_s {
    f32 x, y, z;
};

s32 func_15128540(struct108 *arg0) {
    if (func_151253CC(arg0)) {
        return 1;
    }
    if (func_15128030(arg0)) {
        return 0;
    }
    if (arg0->unk2C & 0x80000) {
        func_1512A360(arg0);
        *(struct func_15128540_s *)&arg0->unk2BC = *(struct func_15128540_s *)&arg0->unk2A4;
        func_151256BC(arg0);
        func_151236D0(arg0);
        func_151284C4(arg0);
        return 1;
    }
    if (arg0->unk2C & 0x100000) {
        func_1512E4B0(arg0);
        func_151236D0(arg0);
        func_151284C4(arg0);
        return 1;
    }
    if (arg0->unk2C & 0x200000) {
        func_151219D0(arg0);
        func_151236D0(arg0);
        func_151284C4(arg0);
        return 1;
    }
    if (arg0->unk2C & 0x400000) {
        func_1512D380(arg0);
        func_151236D0(arg0);
        func_151284C4(arg0);
        return 1;
    }
    if (func_15126378(arg0)) {
        func_151284C4(arg0);
        return 1;
    }
    return 0;
}

void func_15128680(struct108 *arg0) {
}

void func_1512868C(struct108 *arg0) {
    struct127 *temp_v1_2;
    u8 idx;
    s32 i;

    for (i = 0; i < 21; i++)
    {
        arg0->unk20C[i] = 0;
    }

    arg0->unk2C = 1;
    arg0->unkDC = 0;
    arg0->unk134 = 1;
    arg0->unk84 = 14;
    arg0->unk1B4 = 3;
    func_15124B18(arg0);
    idx = arg0->unk23D;
    arg0->unk3D0 = temp_v1_2 = &gObjects[idx];
    arg0->unk368 = arg0->unk3CC = idx;
    arg0->unk3D4 = temp_v1_2->unk31C;
    arg0->unk190 = 0.0f;
    arg0->unk198 = 0.0f;
    arg0->unk18C = 0.0f;
    arg0->unk194 = 0.0f;
    arg0->unk674 = 1.0f;
    arg0->unk3D4->unk198 = 0;
    arg0->unk73C = 0;
}

void func_15128774(struct108 *arg0, struct127 *arg1) {
    arg0->unk35C = arg1->unk180;
    arg0->unk304 = arg0->unk2F8 = arg1->x_position;
    arg0->unk308 = arg0->unk2FC = arg1->y_position;
    arg0->unk30C = arg0->unk300 = arg1->z_position;
    arg0->unk37C = arg0->unk3D0->unk40 - 180.0f;
    arg0->unk3D4->unk18C = D_800A35AC;
    arg0->unk23C = 1;
}
