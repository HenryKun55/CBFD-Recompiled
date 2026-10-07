#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// NON-MATCHING: exact 83/83 instruction match. Init function: calls
// three niladic setup routines, then zeroes a batch of otherwise-
// unrelated globals - some via unrolled 4-byte loops (matching target's
// pre-increment-then-negative-offset store idiom), some as a single
// fused loop advancing two independent pointers together (992A/993A),
// some as plain scalar/array stores, and exactly one real `bzero` call
// (the 5-byte D_800BE500 region - the only one target didn't inline).
// Tried literal `bzero()` calls for the other regions first; target
// inlines all but that one, so they had to become explicit stores/
// loops instead. The two inlined loops keep target's total size but
// differ in register scheduling for their base/sentinel setup (a
// `move`-from-base vs two independent symbol lookups) - tried using
// D_800E0964's own address as a second named end-sentinel to match
// target's two-independent-lookups form exactly, but a named external
// end pointer made IDO treat the trip count as unprovable and emit a
// defensive remainder-safe loop instead (`andi`+`beqz` guard), which
// is worse; the pointer-arithmetic end (`&base + N`) it is.
#pragma GLOBAL_ASM("asm/nonmatchings/game_3BA70/func_1500E5C0.s")
// extern s32 D_800D98D0;
// extern s32 D_800D9894;
// extern s32 D_80088870;
// extern u8 D_800D9950[3];
//
// void func_1500E5C0(void) {
//     func_15012470();
//     func_15008A10();
//     func_15012770();
//
//     {
//         u8 *p = &D_800E0950;
//         do {
//             p[0] = 0;
//             p[1] = 0;
//             p[2] = 0;
//             p[3] = 0;
//             p += 4;
//         } while (p != (&D_800E0950 + 0x14));
//     }
//
//     D_800D9921 = 0;
//     D_800D9920 = 0;
//     D_800D9928 = 0;
//     D_800D9938 = 0;
//     D_800D9929 = 0;
//     D_800D9939 = 0;
//     {
//         u8 *p0 = D_800D993A;
//         u8 *p1 = D_800D992A;
//         do {
//             p1[1] = 0;
//             p1[2] = 0;
//             p1[3] = 0;
//             p1 += 4;
//             p1[-4] = 0;
//             p0[0] = 0;
//             p0[1] = 0;
//             p0[2] = 0;
//             p0 += 4;
//             p0[-4] = 0;
//         } while (p0 != D_800D993A + 0xC);
//     }
//
//     D_800D9890 = 0;
//     D_800D9894 = 0;
//     *(s32 *) ((char *) &D_800D98D0 + 0x0) = 0;
//     *(s32 *) ((char *) &D_800D98D0 + 0x4) = 0;
//     *(s32 *) ((char *) &D_800D98D0 + 0x8) = 0;
//     *(s32 *) ((char *) &D_800D98D0 + 0xC) = 0;
//
//     D_80088870 = 0;
//     bzero(D_800BE500, 5);
//
//     D_800D9950[1] = 0;
//     D_800D9950[0] = 0;
//     D_800D9950[2] = 0;
//
//     D_80088980 = 0;
//     D_800D9AA0[0] = 0;
//     D_800D9AA0[1] = 0;
//     D_800D9AA0[2] = 0;
//
//     D_800BE4F0 = 0;
//     D_80088B40 = 0;
// }

void func_1500E70C(s32 arg0) {
    if (arg0 == 0x2B) {
        func_15011C70();
    }
}

extern u8 D_800DCA20;
extern f32 D_800DCA24;
extern u8 D_800DCA28;
extern f32 D_800DCA2C;

void func_1500E738(void) {
    switch (D_80082FA0) {
    case 0:
        D_800DCA20 = 0;
        D_800DCA24 = 1.0f;
        break;
    case 1:
        D_800DCA20 = 1;
        D_800DCA24 = 0.5f;
        break;
    case 2:
    case 3:
        D_800DCA20 = 2;
        D_800DCA24 = 0.25f;
        break;
    }
    switch (D_8008FD8C) {
    case 2:
        D_800DCA28 = 1;
        D_800DCA2C = 0.5f;
        return;
    case 3:
    case 4:
        D_800DCA28 = 2;
        D_800DCA2C = 0.25f;
        return;
    case 5: case 6: case 7: case 8:
        D_800DCA28 = 3;
        D_800DCA2C = 0.125f;
        return;
    case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
        D_800DCA28 = 4;
        D_800DCA2C = 0.0625f;
        return;
    case 1:
    default:
        D_800DCA28 = 0;
        D_800DCA2C = 1.0f;
        return;
    }
}

void func_1500E890(void) {
    func_15008E00();
    func_15008E10(0);
    func_15008E10(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_3BA70/func_1500E8C0.s")
// NON-MATCHING: fair bit to figure out
// void func_1500E8C0(void) {
//     struct145 tmp;
//     s32 phi_v0;
//
//     func_15195AA8(D_800B0E00[0], D_800902E8, 0, -1, 0, 0, 0, -6);
//     func_15195AA8(D_800B0E00[1], D_800902E8, 0, -1, 0, 1, 0, -6);
//     tmp.unk28 = D_80096210; // 0.2142857164144516
//     tmp.unk30 = 5.0f;
//     tmp.unk34 = 6.0f;
//     tmp.unk20 = 8.0f;
//     tmp.unk24 = 7.0f;
//     tmp.unk14 = 0.0f;
//     tmp.unk18 = 0.0f;
//     tmp.unk2C = 0.0f;
//     tmp.unk48 = 3;
//     tmp.unk4C = 2;
//     tmp.unk0 = 0x34;
//     tmp.unk2 = 0x12;
//     tmp.unk4 = -0x28;
//     tmp.unk6 = 0xF;
//     tmp.unk38 = 0x9B;
//     tmp.unk3A = 0x64;
//     tmp.unk44 = 0x29;
//     tmp.unk46 = 0x29;
//     tmp.unk10 = 400.0f;
//     tmp.unk1C = 900.0f - 400.0f;
//     tmp.unk3C = D_80096214; // 0.6000000238418579
//     tmp.unk40 = D_80096218;
//     tmp.unkC = D_8009621C;
//     tmp.unk8 = 800.0f;
//     func_15189900(&tmp, 1);
//     if (D_800BE9F0 == 6) {
//         phi_v0 = 52;
//     } else {
//         phi_v0 = 7;
//     }
//     func_1000FA64(1567, (s16)phi_v0, 0, 0, 12000, 1000, 400, func_1000EF40, 0, 0, 72, 0);
// }

void func_1500EAA0(void) {
    func_15195AA8(D_800B0E00[0], D_80090320, 0, -1, 0, 0, 0, -8);
    func_15195AA8(D_800B0E00[1], D_80090320, 0, -1, 0, 1, 0, -8);
}
