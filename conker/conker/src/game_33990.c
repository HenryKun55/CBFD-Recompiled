#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_150064E0(void) {
    s32 i = 0;
    func_15017790();

    do {
        D_800C3A60[i++] = 0;
    } while (i < 69);

    D_800BE3DF = 24;
    D_800BE3E8 = 0;
    D_800D2E45 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_33990/func_15006590.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_33990/func_15006BEC.s")
// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Fills D_800BE358[0..8) with 0xFF, flushes the data cache,
// then (if a flag byte D_8002AC5C is clear) walks the 4 consecutive
// scalar globals D_800BE3D8..D_800BE3DB via pointer (each one already
// separately declared `s8` - not touching those declarations, since a
// real caller in this same file assigns `D_800BE3D8 = -1;` directly)
// looking for one equal to arg0; on a match, calls
// osEepromRead(&D_800BE900, (i<<4)+4, D_800BE358) and again with
// +5, both as byte values.
// 57 vs target's 59 instructions: content, control flow and the
// exact index-based-vs-pointer-walk choice for BOTH loops match
// target precisely (this took two iterations to find - writing the
// fill loop as `D_800BE358[i] = 0xFF` compiles to a pointer-walk that
// target doesn't use, while explicit pointer arithmetic
// `*((u8*)D_800BE358 + i)` reproduces target's index-recompute-each-
// iteration form exactly, letting the array's base address stay in
// one register shared by both loops instead of needing a second
// computation). The sole remaining gap is register-count padding:
// target's prologue/epilogue save $s0-$s7 (8 registers) even though
// only 6 are ever referenced in the body ($s1/$s3 are dead padding,
// an IDO convention of saving every register up to the highest one
// used) because target keeps arg0 in $s7, whereas this reconstruction
// packs every live value into $s0-$s6 (7 registers, none idle) and
// never needs an 8th - a genuine, source-invisible register
// allocation choice, not a logic difference.
// void func_1500707C(s32 arg0) {
//     s32 i;
//     s8 *p;
//     s32 v0;
//
//     for (i = 0; i < 8; i++) {
//         *((u8 *) D_800BE358 + i) = 0xFF;
//     }
//     osWritebackDCacheAll();
//
//     if (D_8002AC5C == 0) {
//         p = &D_800BE3D8;
//         for (i = 0; i != 4; i++) {
//             if (arg0 == *p) {
//                 v0 = (i << 4) + 4;
//                 osEepromRead(&D_800BE900, (u8) v0, D_800BE358);
//                 osEepromRead(&D_800BE900, (u8) (v0 + 1), D_800BE358);
//             }
//             p++;
//         }
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_33990/func_1500707C.s")
// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_33990/func_15007168.s")
struct func_1500727C_s {
    u16 sum;
    u8 data[0x6E];
};
extern struct func_1500727C_s D_800BE2F0;
s32 func_151DD3A0(OSMesgQueue *, s32, void *, s32);
void func_15007168(void);

// NOTE: the loop body must stay on the same line as the for() (-g3 line
// numbers change IDO's scheduling of the unrolled body otherwise).
void func_1500727C(void) {
    u16 sum;
    s32 i;

    func_151DD3A0(&D_800BE900, 0x44, &D_800BE2F0, 0x70);
    sum = 0xCC;
    for (i = 2; i < 0x68; i++) { sum += D_800BE2F0.data[i - 2] << (i & 3); }
    if (D_800BE2F0.sum != sum) {
        func_15007168();
    }
}
// NON-MATCHING: full semantics recovered and verified via isolated
// harness - a checksum/hash routine. Seeds an accumulator from two
// global bytes (D_800BE2F2<<2 + 0xCC + D_800BE2F3<<3), then walks a
// 100-byte table 4 bytes at a time, each byte left-shifted by its
// position mod 4 (0,1,2,3) and folded into the running 16-bit-masked
// sum, writes the result to D_800BE2F0, and conditionally calls
// func_151DCEF0(&D_800BE900, 0x44, 0x70) (an OSMesgQueue global) if a
// flag byte (D_8002AC5C) is zero.
// Key finding: this loop's trip count is a compile-time-KNOWN
// constant (25 iterations, both bounds are literals) and IDO -O2
// fully unrolls ANY plain for/while/do-while form of it by 4x
// (yielding ~130 instructions instead of target's clean single-body
// loop) - this is a DIFFERENT unroll trigger than the
// early-return-inside-loop case documented elsewhere in this project
// (the do-while-guard fix for THAT case does nothing here). Marking
// the loop counter itself `volatile` blocks the unroll but forces
// extra spill/reload traffic for every reference to it inside the
// loop body. The much better fix: make ONLY the loop's UPPER BOUND
// volatile (a separate local set to the literal once before the
// loop), leaving the counter itself a normal register variable -
// this defeats IDO's "known trip count" full-unroll analysis (since
// the bound is no longer provably constant) while keeping the counter
// register-resident like target's, getting down to 59 vs target's 56
// instructions (the remaining gap is just the volatile bound's own
// spill/reload, which target's plain immediate compare doesn't need
// at all).
// void func_15007360(void) {
//     s32 v0;
//     s32 v1;
//     volatile s32 bound;
//     u8 *a0;
//
//     v0 = (D_800BE2F2 * 4 + 0xCC + D_800BE2F3 * 8) & 0xFFFF;
//     a0 = D_800BE2F4;
//     bound = 0x68;
//     v1 = 4;
//     while (v1 != bound) {
//         v0 = (v0 + (a0[0] << (v1 & 3)) + (a0[1] << ((v1 + 1) & 3)) + (a0[2] << ((v1 + 2) & 3)) + (a0[3] << ((v1 + 3) & 3))) & 0xFFFF;
//         a0 += 4;
//         v1 += 4;
//     }
//     D_800BE2F0 = (s16) v0;
//
//     if (D_8002AC5C == 0) {
//         func_151DCEF0(&D_800BE900, 0x44, 0x70);
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_33990/func_15007360.s")
extern s8 D_800E0BE0[28];
extern s8 D_8008FE30;

void func_15007440(void) {
    s32 i;
    u16 sum;
    s8 saved;

    func_151DD3A0(&D_800BE900, 0, D_800BE358, 0x20);
    sum = 0xCC;
    for (i = 2; i < 30; i++) { sum += D_800BE358[i] << (i & 3); }
    saved = D_800E0BE0[0x10];
    if (sum != *(u16 *)D_800BE358) {
        for (i = 0; i < 28; i++) { D_800E0BE0[i] = -1; }
    } else {
        for (i = 0; i < 28; i++) { D_800E0BE0[i] = D_800BE358[i + 2]; }
    }
    D_800E0BE0[0x10] = saved;
    func_151DD9E4();
    func_151E7EF8();
    D_8008FE30 = 1;
}
extern s8 D_800E0BE0[];

void func_15007558(void) {
    s32 i;
    volatile s32 unused;
    u16 sum;

    for (i = 0; i < 0x1C; i++) {
        D_800BE358[i + 2] = D_800E0BE0[i];
    }
    sum = 0xCC;
    for (i = 2; i != 0x1E; i++) { sum += D_800BE358[i] << (i & 3); }
    *(u16 *)D_800BE358 = sum;
    if (D_8002AC5C == 0) {
        unused = func_151DCEF0(&D_800BE900, 0, D_800BE358, 0x20);
    }
}

void func_15007644(void) {
}

void func_1500764C(void) {
    D_80082BB4 = (u8)6;
    D_800BE3EC = (u8)0;
}

void func_15007668(void) {
    D_80082BB4 = (u8)7;
    D_800BE3EC = (u8)0;
}

void func_15007684(void) {
    D_80082BB4 = (u8)4;
    D_800BE3EC = (u8)0;
}

void func_150076A0(void) {
    D_80082BB4 = (u8)5;
    D_800BE3EC = (u8)0;
}

void func_150076BC(s32 arg0) {
    if (arg0 < 0) {
        func_150064E0();
    }
    if ((arg0 >= 0) && (arg0 < 4) && (D_800BE616 == 0)) {
        D_80082BB4 = (u8)1;
        D_800BE3EC = arg0;
    }
}

void func_15007718(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 3) && (D_800BE616 == 0)) {
        D_80082BB4 = (u8)2;
        D_800BE3EC = arg0;
    }
}

void func_15007750(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 3)) {
        D_80082BB4 = (u8)3;
        D_800BE3EC = arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_33990/func_15007778.s")
// NON-MATCHING: should probably start over..
// void func_15007778(void) {
//     s32 phi_v0;
//
//     D_800BE3F8->unk8 = -1;
//     D_800BE3F8->unk18 = -1;
//     D_800BE3F8->unk28 = -1;
//     D_800BE3F8->unkE = -1;
//     D_800BE3F8->unk1E = -1;
//     D_800BE3F8->unk2E = -1;
//     D_800BE3DC = -1;
//     D_80082BC0 = 1;
//     D_800BE3DE = 0;
//
//     phi_v0 = 0;
//     do {
//         ((u8*)D_800D2E4C)[phi_v0++] = 0;
//     } while (phi_v0 < 27);
//
//     for (phi_v0 = 0; phi_v0 < 9; phi_v0++) {
//         D_800D2E60[phi_v0] = 0;
//     }
//
//     D_800BE3DB = -1;
//     D_800BE3DA = -1;
//     D_800BE3D9 = -1;
//     D_800BE3D8 = -1;
// }
