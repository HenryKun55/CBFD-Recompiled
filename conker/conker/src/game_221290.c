#include <ultra64.h>

#include "functions.h"
#include "variables.h"

extern f32 D_800B0C2C;
extern f32 D_800B0C30;
extern f32 D_800B0C34;
extern f32 D_800B0C38;
extern f32 D_800B0C3C;
extern f32 D_800B0C40;
extern f32 D_800B0C44;
extern f32 D_800B0C48;
s32 func_151F8960();
s32 func_151F78B4();
s32 func_151F6FD0();

extern s32 *D_800E0E20;
extern f32 *D_800E1078;
extern f32 D_800E0E38[];
extern f32 D_800E0EC8[];
extern f32 D_800E0FE8[];
extern s32 D_800E0E28;
extern s32 D_800E0E30;
extern f32 D_800E1080[];
extern f32 D_800E1480[];
extern s16 D_800AEB7C[];
extern f32 D_800B067C[];
extern f32 D_800B069C[];
extern s32 D_800E0E00;
extern u8 D_800E1880[];

// Scalefactor band boundary table: 23 long-block edges followed by 14
// short-block edges, one row per (sample rate, MPEG version) pair.
// splat named several interior elements as their own symbols -
// D_800AE99A is .l[1], D_800AE9A8 is .l[8], D_800AE9C6 is .s[0],
// D_800AE9C8 is .s[1] and D_800AE9CE is .s[4] - so those all
// disassemble back out of this one declaration.
typedef struct {
    s16 l[23];
    s16 s[14];
} SfBand;

// The 22-entry pre-emphasis table, copied wholesale onto the stack by
// func_151F42E8 (IDO expands the struct assignment into an inline
// 12-bytes-per-iteration copy loop).
typedef struct {
    s32 v[22];
} PreTab;

extern SfBand D_800AE998[];
extern PreTab D_800B0AB4;

// The MPEG-2 LSF scalefactor-length table: [preflag][region][window][4].
// func_151F578C copies the whole 288-byte table onto its stack (IDO
// expands the struct assignment into an inline copy loop) and then
// bcopy()s one 4-entry row out of the copy.
typedef struct {
    s32 v[2][3][3][4];
} SlenTab;

extern SlenTab D_800B0B0C;
f32 func_1504A400(f32, f32);


// Builds the analysis/synthesis window tables and the cube-root lookup
// used by the codec: three sine-windowed ramps into D_800E0E38 /
// D_800E0EC8 / D_800E0FE8, a bias pass over D_800E0E20, then a
// Newton-Raphson solve of x^3 = i^4 for each of 0x2000 entries, and
// finally two geometric scale tables.
s32 func_151F3DE0(void) {
    s32 i;
    f32 x;
    f32 xx;
    f32 delta;
    f32 t;
    f32 eps;
    f32 c;
    f32 d;

    i = 0;
    do {
        D_800E0E38[i] = sinf(((f32) i + 0.5f) * D_800B0C2C);
    } while (++i < 0x24);

    i = 0;
    do {
        D_800E0EC8[i] = sinf(((f32) i + 0.5f) * D_800B0C30);
    } while (++i < 0x12);

    i = 0x12;
    do {
        D_800E0EC8[i] = 1.0f;
    } while (++i < 0x18);

    i = 0x18;
    do {
        D_800E0EC8[i] = sinf((((f32) i + 0.5f) - 18.0f) * D_800B0C34);
    } while (++i < 0x1E);

    i = 0x1E;
    do {
        D_800E0EC8[i] = 0.0f;
    } while (++i < 0x24);

    i = 0;
    do {
        D_800E0FE8[i] = 0.0f;
    } while (++i < 6);

    i = 6;
    do {
        D_800E0FE8[i] = sinf((((f32) i + 0.5f) - 6.0f) * D_800B0C38);
    } while (++i < 0xC);

    i = 0xC;
    do {
        D_800E0FE8[i] = 1.0f;
    } while (++i < 0x12);

    i = 0x12;
    do {
        D_800E0FE8[i] = sinf(((f32) i + 0.5f) * D_800B0C3C);
    } while (++i < 0x24);

    i = 1;
    do {
        D_800E0E20[i] += D_800E0E28;
    } while (++i < 0x22);

    D_800E1078 = (f32 *) D_800E0E30;
    if (D_800E1078 == 0) {
        return 0;
    }

    x = 1.0f;
    D_800E1078[0] = 0.0f;

    i = 1;
    do {
        t = (f32) i;
        t = t * t;
        eps = t * D_800B0C40;
        t = t * t;
        do {
            xx = x * x;
            delta = (xx * x - t) / (2.0f * xx);
            x = x - delta;
        } while (delta > eps || delta < -eps);
        D_800E1078[i] = x;
    } while (++i < 0x2000);

    c = D_800B0C44;
    d = 0.25f;
    D_800E1080[0] = 1.0f;
    D_800E1480[0] = 1.0f;

    i = 1;
    do {
        D_800E1080[i] = c;
        D_800E1480[i] = d;
        d = d * 0.25f;
        c = c * D_800B0C48;
    } while (++i < 0x100);

    return 1;
}
// Requantisation and reordering of one granule/channel: turns the
// decoded integer spectrum at unk3F94 into the float spectrum at
// unk4664, applying the global gain, the scalefactors and the sign
// bits, and switching between the long-block and short-block band
// layouts as it crosses unk3C98/unk3CA0/unk3CA8's window boundaries.
// Byte-perfect: 788 of 788 instructions, every non-relocation word
// identical to target (the remaining 52 differences are all %hi/%lo
// and jal sites, which resolve at link time).
//
// Five operand-order transpositions were needed, every one of them
// invisible to a register-normalised diff - the structure was already
// exact before any of them, and each was found by walking the
// field-wise encoding comparison to its FIRST differing word and
// fixing only that:
//   idx      -> unk3BA4 * 3 + unk3BB4, not unk3BB4 + unk3BA4 * 3
//   scalefac -> unk3CF0 * pretab[sb], not pretab[sb] * unk3CF0
//   sval     -> (gain * D_800E1480[sfs]) * D_800E1080[sfi]
//   the width clamp -> `next > cnt`, not `cnt < next`
//   the requantised sample -> D_800E1078[*isp++] * lval[sb]
// The last one alone moved 180 words: it was the innermost expression
// and its operand order set the temp-register numbering for the whole
// remaining two thirds of the function.  Work first-difference-first
// on a long function; a single early transposition masks everything
// after it.
//
// Three shapes also mattered:
//   - `sb * 4` is shared between pretab[sb] and the unk3D08 element,
//     so both must be spelled as SUBSCRIPTS for IDO to common them;
//     writing one as `+ sb * 4` inside a cast emits a second `sll`.
//   - `if (*sgn++)`, not `if (*sgn++ != 0)` - the explicit `!= 0`
//     makes IDO materialise a 0/1 boolean with `sltu`/`or` first.
//   - `*out++ = ... *isp++ ...` as one statement; separate `isp++;
//     out++;` statements emit load/add/store three times in sequence
//     instead of target's interleaved load, load, add, add, store,
//     store.
s32 func_151F42E8(void *arg0, s32 arg1, s32 arg2) {
    s32 idx;
    s32 next;
    s32 bandStart;
    s32 bandWidth;
    PreTab tbl;
    f32 lval[22];
    f32 sval[3][13];
    f32 gain;
    s32 sb;
    s32 win;
    s32 pre;
    s32 sfs;
    s32 sfi;
    s32 i;
    s32 cnt;
    f32 *out;
    s16 *isp;
    u8 *sgn;
    s32 flagA;
    s32 flagB;
    s32 mixed;
    s32 nextEdge;
    f32 *srow;

    tbl = D_800B0AB4;
    idx = *(s32 *) ((char *) arg0 + 0x3BA4) * 3 + *(s32 *) ((char *) arg0 + 0x3BB4);

    if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C98) != 0 &&
        *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 2) {
        if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA8) != 0) {
            next = D_800AE998[idx].l[1];
        } else {
            next = D_800AE998[idx].s[1] * 3;
            bandWidth = D_800AE998[idx].s[1];
            bandStart = 0;
        }
    } else {
        next = D_800AE998[idx].l[1];
    }

    gain = func_1504A400(2.0f,
        ((f32) *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C88) - 210.0f) * 0.25f);
    pre = *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CF8);

    for (sb = 0; sb < 0x16; sb++) {
        sfi = (((s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + 0x3D08))[sb]
               + *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CF0) * tbl.v[sb])
              * (pre + 1);
        lval[sb] = D_800E1080[sfi] * gain;
    }

    for (win = 0; win < 3; win++) {
        for (sb = 0; sb < 0xD; sb++) {
            sfs = *(s32 *) ((char *) arg0 + arg1 * 12 + arg2 * 12 + win * 4 + 0x3CC8);
            sfi = *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + win * 52 + sb * 4 + 0x3D64)
                  * (pre + 1);
            sval[win][sb] = (gain * D_800E1480[sfs]) * D_800E1080[sfi];
        }
    }

    sb = 0;
    i = 0;
    cnt = *(s32 *) ((char *) arg0 + arg2 * 4 + 0x465C);
    out = (f32 *) ((char *) arg0 + arg2 * 2304 + 0x4664);
    isp = (s16 *) ((char *) arg0 + arg2 * 1156 + 0x3F94);
    sgn = (u8 *) ((char *) arg0 + arg2 * 578 + 0x4418);

    flagA = *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 2 &&
            *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA8) == 0;
    flagB = *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 2 &&
            *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA8) != 0;
    mixed = *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C98);

    while (i < cnt) {
        if (next > cnt) {
            next = cnt;
        }
        if (mixed != 0 && (flagA != 0 || (flagB != 0 && i >= 0x24))) {
            win = (i - bandStart) / bandWidth;
            nextEdge = bandStart + bandWidth;
        }
        while (i < next) {
            if (mixed != 0 && (flagA != 0 || (flagB != 0 && i >= 0x24))) {
                if (i >= nextEdge) {
                    nextEdge += bandWidth;
                    win++;
                }
                srow = sval[win];
                if (*sgn++) {
                    *out++ = -(D_800E1078[*isp++] * srow[sb]);
                } else {
                    *out++ = D_800E1078[*isp++] * srow[sb];
                }
            } else {
                if (*sgn++) {
                    *out++ = -(D_800E1078[*isp++] * lval[sb]);
                } else {
                    *out++ = D_800E1078[*isp++] * lval[sb];
                }
            }
            i++;
        }
        if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C98) != 0 &&
            *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 2) {
            if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA8) != 0) {
                if (D_800AE998[idx].l[8] == i) {
                    next = D_800AE998[idx].s[4] * 3;
                    sb = 3;
                    bandWidth = D_800AE998[idx].s[sb + 1] - D_800AE998[idx].s[sb];
                    bandStart = D_800AE998[idx].s[sb] * 3;
                } else {
                    if (i < D_800AE998[idx].l[8]) {
                        next = D_800AE998[idx].l[++sb + 1];
                    } else {
                        next = D_800AE998[idx].s[++sb + 1] * 3;
                        bandWidth = D_800AE998[idx].s[sb + 1] - D_800AE998[idx].s[sb];
                        bandStart = D_800AE998[idx].s[sb] * 3;
                    }
                }
            } else {
                next = D_800AE998[idx].s[++sb + 1] * 3;
                bandWidth = D_800AE998[idx].s[sb + 1] - D_800AE998[idx].s[sb];
                bandStart = D_800AE998[idx].s[sb] * 3;
            }
        } else {
            next = D_800AE998[idx].l[++sb + 1];
        }
    }

    if (i < 0x240) {
        bzero(out, *(s32 *) ((char *) arg0 + arg2 * 4 + 0x4660) * 4);
        return 1;
    }
    return 1;
}
// NON-MATCHING (JUSTREG): scalefactor / bit-allocation decode.  The
// reconstruction below is structurally a 100% match - 533 of 533
// instructions, every opcode, immediate, stack offset, struct field
// offset and branch target identical to target; a register-normalised
// diff of the two disassemblies is empty.  407 words are already
// byte-identical, 25 more differ only in a relocated immediate (those
// resolve at link time), and 101 words carry a different register
// allocation.  That allocation difference is the whole remaining gap
// and it is not reachable from the source: target parks the two
// `k < 2 ? 0 : 1` temps in $s0/$s1 and keeps every other temp in
// $t-registers, while this build reuses $t0/$t8 (and later $t3/$t7,
// $t8/$t9) in a different order from the same instruction stream.
//
// Four source-shape findings were needed to get the structure exact,
// all of them re-usable:
//
//  1. D_800AEB5C is a two-dimensional u8[][16] bit-allocation table,
//     and D_800AEB6C is simply its row 1 - splat named the row starts
//     as separate symbols.  Declaring it `u8 D_800AEB5C[][16]` and
//     writing D_800AEB5C[0][v] / D_800AEB5C[1][v] reproduces target's
//     `lui %hi; addu idx; lbu %lo` and `%lo+0x10` forms exactly.  The
//     same applies to D_800AEB54: D_800AEB55 and D_800AEB5A are its
//     +1 and +6 elements, so `D_800AEB54[k + 1]` disassembles back as
//     `%lo(D_800AEB55)`.
//
//  2. The gated store must be a TERNARY, not an if/else.  Target reads
//     the table once, branches on it, and moves that same register into
//     $a2 for the call (`or $a2, $t1, $zero`), also keeping arg0's
//     loaded value alive across the branch.  Writing it as
//     `if (tbl[v]) { X = f(..., tbl[v]); } else { X = 0; }` re-emits
//     the entire address chain in the taken arm (+9 words per site);
//     assigning to a local instead spills it (`sw`/`lw`).  Only
//     `X = tbl[v] ? f(..., tbl[v]) : 0;` gives target's shape - IDO
//     folds the ternary back into two separate stores, each computing
//     its own destination address, which is exactly what target does.
//
//  3. The `k`-indexed row in the third loop nest needs POINTER form,
//     `*(D_800AEB5C[0] + k * 16 + v)`, not `D_800AEB5C[k][v]`.  The
//     subscript form folds %lo into the lbu and CSEs the whole read;
//     the pointer form materialises the base with `lui`+`addiu %lo`,
//     adds it last, and re-emits only `addu`/`addu`/`lbu` after the
//     branch - which is target's exact instruction sequence.
//
//  4. The loop bounds are an ASSIGNMENT INSIDE THE COMPARISON:
//     `if (tbl[k + 6] > (i = tbl[k + 5]))`.  Splitting it into two
//     statements makes IDO spill i and reload it before the `slt`,
//     which target does not do.  Transposing the comparison (putting
//     the assignment on the right of `>` rather than the left of `<`)
//     is what cut the register drift from 251 differing words to 126:
//     worth trying on any near-miss that is already structurally exact.
//
// Semantics: for slot (arg1, arg2) of arg0, when unk3C98 is set and
// unk3CA0 == 2, it pulls per-band bit counts out of the stream with
// func_151F8960 and writes them to the unk3D08 / unk3D64 tables - in
// stereo (unk3CA8 != 0) as a flat run of 8 plus two 3x subband nests,
// otherwise band-by-band over the two ranges named by D_800AEB54[5..7]
// - then clears the unk3D94 column.  When the slot is inactive it
// instead walks the four ranges D_800AEB54[0..4], either copying
// unk3D08 forward to unk3E00 (when unk3BF8 is set and arg1 != 0) or
// re-reading the bit counts, and finally clears unk3D60.
// s32 func_151F4F38(void *arg0, s32 arg1, s32 arg2) {
//     s32 k;
//     s32 i;
//     s32 j;
//
//     if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C98) != 0 &&
//         *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 2) {
//         if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA8) != 0) {
//             i = 0;
//             do {
//                 *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + i * 4 + 0x3D08) =
//                     D_800AEB5C[0][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)]
//                         ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020,
//                                         D_800AEB5C[0][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)])
//                         : 0;
//             } while (++i < 8);
//
//             i = 3;
//             do {
//                 j = 0;
//                 do {
//                     *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + j * 52 + i * 4 + 0x3D64) =
//                         D_800AEB5C[0][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)]
//                             ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020,
//                                             D_800AEB5C[0][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)])
//                             : 0;
//                 } while (++j < 3);
//             } while (++i < 6);
//
//             i = 6;
//             do {
//                 j = 0;
//                 do {
//                     *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + j * 52 + i * 4 + 0x3D64) =
//                         D_800AEB5C[1][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)]
//                             ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020,
//                                             D_800AEB5C[1][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)])
//                             : 0;
//                 } while (++j < 3);
//             } while (++i < 12);
//         } else {
//             k = 0;
//             do {
//                 if (D_800AEB54[k + 6] > (i = D_800AEB54[k + 5])) {
//                     do {
//                         j = 0;
//                         do {
//                             *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + j * 52 + i * 4 + 0x3D64) =
//                                 *(D_800AEB5C[0] + k * 16 + *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90))
//                                     ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020,
//                                                     *(D_800AEB5C[0] + k * 16 + *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)))
//                                     : 0;
//                         } while (++j < 3);
//                     } while (++i < D_800AEB54[k + 6]);
//                 }
//             } while (++k < 2);
//         }
//
//         j = 0;
//         do {
//             *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + j * 52 + 0x3D94) = 0;
//         } while (++j < 3);
//     } else {
//         k = 0;
//         do {
//             if (*(s32 *) ((char *) arg0 + arg2 * 128 + k * 4 + 0x3BF8) == 0 || arg1 == 0) {
//                 if (D_800AEB54[k + 1] > (i = D_800AEB54[k])) {
//                     do {
//                         *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + i * 4 + 0x3D08) =
//                             D_800AEB5C[k < 2 ? 0 : 1][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)]
//                                 ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020,
//                                                 D_800AEB5C[k < 2 ? 0 : 1][*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C90)])
//                                 : 0;
//                     } while (++i < D_800AEB54[k + 1]);
//                 }
//             } else {
//                 if (D_800AEB54[k + 1] > (i = D_800AEB54[k])) {
//                     do {
//                         *(s32 *) ((char *) arg0 + arg2 * 248 + i * 4 + 0x3E00) =
//                             *(s32 *) ((char *) arg0 + arg2 * 248 + i * 4 + 0x3D08);
//                     } while (++i < D_800AEB54[k + 1]);
//                 }
//             }
//         } while (++k < 4);
//
//         *(s32 *) ((char *) arg0 + arg1 * 248 + arg2 * 248 + 0x3D60) = 0;
//     }
//     return 1;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_221290/func_151F4F38.s")
// LSF (MPEG-2 low sample rate) scalefactor decode for one channel.
// Derives the four scalefactor bit lengths and the four band counts
// from unk3C90's scalefac_compress code - by a different range split
// depending on whether this is the second channel of an intensity-
// stereo pair - then reads the scalefactors themselves out of the
// bitstream into unk3D08 (long blocks) or unk3D64/unk3D98/unk3DCC
// (the three short windows), recording the per-band masks at unk3EFC /
// unk3F14 for the intensity-stereo pass.
//
// Byte-perfect: 782 of 782 instructions, 770 words identical and the
// remaining 12 differing only in a relocated immediate.  Matched on the
// first attempt, so nothing new had to be learned here - it is a clean
// application of rules already established on this file:
//   - the 288-byte inline copy loop at the top is a struct assignment,
//     `tbl = D_800B0B0C;`, not a memcpy;
//   - every `X = sl ? func_151F8960(...) : 0;` is a ternary, because
//     target loads `sl` once and moves it straight into $a2;
//   - local declaration order runs highest stack address first, which
//     puts the 288-byte table, then the 4-word slen array, then the
//     scalars, then the 4-word nr array, then the last three scalars.
//
// Two conditions genuinely re-test their first operand in the original
// source, and reproducing that redundancy is required.  The bitstream
// dispatch is `winSwitch == 0 || (winSwitch != 0 && blockType != 2)`,
// not the equivalent `!(winSwitch && blockType == 2)`: target emits
// THREE branches there, the middle one provably dead (a second `beqz`
// on a register already known non-zero).  The same shape appears again
// as the `blockType == 2` re-test at the head of the else arm.  A dead
// branch on an already-tested register is a reliable tell that the
// source repeated the operand - do not simplify it away.
s32 func_151F578C(void *arg0, s32 arg1, s32 arg2) {
    SlenTab tbl;
    s32 slen[4];
    s32 sfc;
    s32 *pre;
    s32 mixedFlag;
    s32 blockType;
    s32 winSwitch;
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    s32 half;
    s32 nr[4];
    s32 k;
    s32 sl;
    s32 mask;

    tbl = D_800B0B0C;
    sfc = *(s32 *) ((char *) arg0 + arg2 * 4 + 0x3C90);
    pre = (s32 *) ((char *) arg0 + arg2 * 4 + 0x3CF0);
    mixedFlag = *(s32 *) ((char *) arg0 + arg2 * 4 + 0x3CA8);
    blockType = *(s32 *) ((char *) arg0 + arg2 * 4 + 0x3CA0);
    winSwitch = *(s32 *) ((char *) arg0 + arg2 * 4 + 0x3C98);

    if ((*(s32 *) ((char *) arg0 + 0x3BC4) != 1 && *(s32 *) ((char *) arg0 + 0x3BC4) != 3) ||
        arg2 != 1) {
        a = 0;
        if (sfc < 0x190) {
            slen[0] = (sfc >> 4) / 5;
            slen[1] = (sfc >> 4) % 5;
            slen[2] = (sfc % 16) >> 2;
            slen[3] = sfc % 4;
            *pre = 0;
            b = 0;
        } else if (sfc >= 0x190 && sfc < 0x1F4) {
            slen[0] = ((sfc - 0x190) >> 2) / 5;
            slen[1] = ((sfc - 0x190) >> 2) % 5;
            slen[2] = (sfc - 0x190) % 4;
            slen[3] = 0;
            *pre = 0;
            b = 1;
        } else if (sfc >= 0x1F4 && sfc < 0x200) {
            slen[0] = (sfc - 0x1F4) / 3;
            slen[1] = (sfc - 0x1F4) % 3;
            slen[2] = 0;
            slen[3] = 0;
            *pre = 1;
            b = 2;
        }
    }

    if ((*(s32 *) ((char *) arg0 + 0x3BC4) == 1 || *(s32 *) ((char *) arg0 + 0x3BC4) == 3) &&
        arg2 == 1) {
        *(s32 *) ((char *) arg0 + 0x3EF8) = sfc % 2;
        half = sfc >> 1;
        a = 1;
        if (half < 0xB4) {
            slen[0] = half / 0x24;
            slen[1] = (half % 0x24) / 6;
            slen[2] = (half % 0x24) % 6;
            slen[3] = 0;
            *pre = 0;
            b = 0;
        } else if (half >= 0xB4 && half < 0xF4) {
            slen[0] = ((half - 0xB4) % 0x40) >> 4;
            slen[1] = ((half - 0xB4) % 16) >> 2;
            slen[2] = (half - 0xB4) % 4;
            slen[3] = 0;
            *pre = 0;
            b = 1;
        } else if (half >= 0xF4 && half < 0xFF) {
            slen[0] = (half - 0xF4) / 3;
            slen[1] = (half - 0xF4) % 3;
            slen[2] = 0;
            slen[3] = 0;
            *pre = 0;
            b = 2;
        }
    }

    if (winSwitch != 0 && blockType == 2) {
        bcopy(tbl.v[a][b][mixedFlag + 1], nr, 0x10);
    } else {
        bcopy(tbl.v[a][b][0], nr, 0x10);
    }

    k = 0;
    if (winSwitch == 0 || (winSwitch != 0 && blockType != 2)) {
        for (i = 0; i < 4; i++) {
            sl = slen[i];
            mask = (1 << sl) - 1;
            for (j = 0; j < nr[i]; j++) {
                *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3D08) =
                    sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                if (arg2 != 0) {
                    *(s32 *) ((char *) arg0 + k * 4 + 0x3EFC) = mask;
                }
                k++;
            }
        }
    } else {
        if (blockType == 2) {
            if (mixedFlag == 0) {
                for (i = 0; i < 4; i++) {
                    sl = slen[i];
                    mask = (1 << sl) - 1;
                    for (j = 0; j < nr[i]; j += 3) {
                        *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3D64) =
                            sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                        *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3D98) =
                            sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                        *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3DCC) =
                            sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                        if (arg2 != 0) {
                            *(s32 *) ((char *) arg0 + k * 4 + 0x3F14) = mask;
                        }
                        k++;
                    }
                }
            } else {
                sl = slen[0];
                mask = (1 << sl) - 1;
                for (j = 0; j < 6; j++) {
                    *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3D08) =
                        sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                    if (arg2 != 0) {
                        *(s32 *) ((char *) arg0 + k * 4 + 0x3EFC) = mask;
                    }
                    k++;
                }
                nr[0] -= 6;
                k = 3;
                for (i = 0; i < 4; i++) {
                    sl = slen[i];
                    mask = (1 << sl) - 1;
                    for (j = 0; j < nr[i]; j += 3) {
                        *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3D64) =
                            sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                        *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3D98) =
                            sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                        *(s32 *) ((char *) arg0 + arg2 * 248 + k * 4 + 0x3DCC) =
                            sl ? func_151F8960((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, sl) : 0;
                        if (arg2 != 0) {
                            *(s32 *) ((char *) arg0 + k * 4 + 0x3F14) = mask;
                        }
                        k++;
                    }
                }
            }
        }
    }
    return 1;
}
// NON-MATCHING (JUSTREG): 363/363 instructions and structurally an
// exact match - with register names normalized away, only SIX lines of
// the 363 differ, and four of those are relocation immediates. Decodes
// one granule: dispatches to the layer's side-info reader, works out
// the three scalefactor-band part boundaries from the D_800AE840 /
// D_800AE948 tables (clamped to the granule's bit budget), runs the
// three Huffman regions through func_151F8994 (zero-filling any region
// whose table is empty), then the count1 region through func_151F8B4C,
// and finally records how many samples were produced and zero-pads the
// remainder up to 0x240.
//
// The two genuine differences:
//   - register numbering diverges from the `if (limit < part[0])`
//     compare onward (target t8/t7/t1 where this build picks t7/t1/t8,
//     and every later use follows). Everything BEFORE that point is
//     register-for-register identical, and the local set provably
//     matches target's frame exactly (14 locals spanning 0x28..0x67,
//     same offsets), so this is allocator state rather than a source
//     difference.
//   - one swapped instruction pair in the `part[1] = limit; part[0] =
//     part[1];` arm, where target hoists the second `addiu &part`
//     above the first store and this build emits it after.
//
// Operand orders were already corrected per the reversal rules (the
// tbl1 index is written unk3CE0 + unk3CE8 so target loads unk3CE8
// first); that fix removed one real difference but did not move the
// register numbering.
#pragma GLOBAL_ASM("asm/nonmatchings/game_221290/func_151F63C4.s")
// s32 func_151F63C4(void *arg0, s32 arg1, s32 arg2) {
//     s32 savedBitPos;
//     s32 limit;
//     s32 part[3];
//     s16 *tbl1;
//     u8 *tbl2;
//     s32 pos;
//     s16 *outp;
//     u8 *outq;
//     s32 j;
//     s32 v;
//     s32 w;
//     s32 end;
//     s32 count;
//     s32 bitPos2;
//
//     savedBitPos = *(s32 *) ((char *) arg0 + 0x2020);
//
//     if (*(s32 *) ((char *) arg0 + 0x3BA4) != 0) {
//         func_151F4F38(arg0, arg1, arg2);
//     } else {
//         func_151F578C(arg0, arg1, arg2);
//     }
//
//     limit = *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C80) * 2;
//     tbl1 = (s16 *) ((char *) D_800AE840 + *(s32 *) ((char *) arg0 + 0x3BA4) * 132 +
//                     *(s32 *) ((char *) arg0 + 0x3BB4) * 44);
//     tbl2 = (u8 *) ((char *) D_800AE948 + *(s32 *) ((char *) arg0 + 0x3BA4) * 39 +
//                    *(s32 *) ((char *) arg0 + 0x3BB4) * 13);
//
//     if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C98) == 0 &&
//         *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 0) {
//         part[0] = tbl1[*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CE0)] + 1;
//         if (limit < part[0]) {
//             part[1] = limit;
//             part[0] = part[1];
//         } else {
//             part[1] = tbl1[*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CE0) +
//                            *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CE8) + 1] + 1;
//             if (limit < part[1]) {
//                 part[1] = limit;
//             }
//         }
//     } else {
//         if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 2 &&
//             *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA8) == 0) {
//             part[0] = tbl2[2] * 3 + 3;
//         } else {
//             part[0] = tbl1[7] + 1;
//         }
//         if (limit < part[0]) {
//             part[0] = limit;
//         }
//         part[1] = limit;
//     }
//
//     part[2] = limit;
//     pos = 0;
//     outp = (s16 *) ((char *) arg0 + arg2 * 1156 + 0x3F94);
//     outq = (u8 *) ((char *) arg0 + arg2 * 578 + 0x4418);
//
//     j = 0;
//     do {
//         v = *(s32 *) ((char *) arg0 + arg1 * 12 + arg2 * 12 + j * 4 + 0x3CB0);
//         w = D_800AE7B8[v];
//         end = part[j];
//         if (D_800E0E20[v] == 0) {
//             count = end - pos;
//             bzero(outp, count * 2);
//             outp += count;
//             outq += count;
//             pos = end;
//         } else {
//             pos = func_151F8994((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, v, pos,
//                                 w, end, &outp, &outq);
//         }
//     } while (++j < 3);
//
//     v = *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3D00) + 0x20;
//     bitPos2 = *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C78) + savedBitPos;
//     pos = func_151F8B4C((char *) arg0 + 0x1C, (char *) arg0 + 0x2020, v, pos,
//                         bitPos2, &outp, &outq);
//     *(s32 *) ((char *) arg0 + 0x2020) = bitPos2;
//
//     if (pos >= 0x241) {
//         *(s32 *) ((char *) arg0 + arg2 * 4 + 0x465C) = 0x240;
//     } else {
//         *(s32 *) ((char *) arg0 + arg2 * 4 + 0x465C) = pos;
//     }
//
//     if (pos < 0x240) {
//         *(s32 *) ((char *) arg0 + arg2 * 4 + 0x4660) = 0x240 - pos;
//         bzero(outp, *(s32 *) ((char *) arg0 + arg2 * 4 + 0x4660) * 2);
//     } else {
//         *(s32 *) ((char *) arg0 + arg2 * 4 + 0x4660) = 0;
//     }
//
//     return 1;
// }

extern s32 *D_800E0E20;
extern f32 *D_800E1078;

// Copies 0x240 floats from the unk4664 scratch buffer into unk4F64.
// When the channel selected by arg1 is active (unk3C98 set) and in
// mode 2, the copy is scattered through a per-(unk3BA4, unk3BB4)
// permutation table in D_800AEB7C, optionally preceded by 0x24
// straight copies; otherwise it is a plain sequential copy.
s32 func_151F6970(void *arg0, s32 arg1) {
    s16 *tbl;
    f32 *dst;
    f32 *src;
    s32 i;

    tbl = (s16 *) ((char *) D_800AEB7C
                   + *(s32 *) ((char *) arg0 + 0x3BA4) * 3456
                   + *(s32 *) ((char *) arg0 + 0x3BB4) * 1152);
    dst = (f32 *) ((char *) arg0 + 0x4F64);
    src = (f32 *) ((char *) arg0 + 0x4664);
    i = 0;

    if (*(s32 *) ((char *) arg0 + arg1 * 4 + 0x3C98) != 0 &&
        *(s32 *) ((char *) arg0 + arg1 * 4 + 0x3CA0) == 2) {
        if (*(s32 *) ((char *) arg0 + arg1 * 4 + 0x3CA8) != 0) {
            while (i++ < 0x24) {
                *dst++ = *src++;
            }
        }
        while (i < 0x240) {
            dst[tbl[i++]] = *src++;
        }
    } else {
        while (i++ < 0x240) {
            *dst++ = *src++;
        }
    }

    return 1;
}
// In-place complex rotation over the 0x20 slot buffers: for each slot k
// it walks 8 conjugate pairs straddling the slot's base pointer and
// applies the twiddle from the D_800B067C / D_800B069C coefficient
// tables. Bails out early when the channel is already active in mode 2.
s32 func_151F6B28(void *arg0, s32 arg1, s32 arg2) {
    s32 k;
    f32 *p;
    f32 a;
    f32 b;

    if (*(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3C98) != 0 &&
        *(s32 *) ((char *) arg0 + arg1 * 4 + arg2 * 4 + 0x3CA0) == 2) {
        return 1;
    }

    k = 1;
    do {
        p = (f32 *) ((char *) arg0 + arg2 * 2304 + k * 72 + 0x4F64);

        a = p[0];
        b = p[-1];
        p[-1] = b * D_800B069C[0] - D_800B067C[0] * a;
        p[0] = a * D_800B069C[0] + D_800B067C[0] * b;

        a = p[1];
        b = p[-2];
        p[-2] = b * D_800B069C[1] - D_800B067C[1] * a;
        p[1] = a * D_800B069C[1] + D_800B067C[1] * b;

        a = p[2];
        b = p[-3];
        p[-3] = b * D_800B069C[2] - D_800B067C[2] * a;
        p[2] = a * D_800B069C[2] + D_800B067C[2] * b;

        a = p[3];
        b = p[-4];
        p[-4] = b * D_800B069C[3] - D_800B067C[3] * a;
        p[3] = a * D_800B069C[3] + D_800B067C[3] * b;

        a = p[4];
        b = p[-5];
        p[-5] = b * D_800B069C[4] - D_800B067C[4] * a;
        p[4] = a * D_800B069C[4] + D_800B067C[4] * b;

        a = p[5];
        b = p[-6];
        p[-6] = b * D_800B069C[5] - D_800B067C[5] * a;
        p[5] = a * D_800B069C[5] + D_800B067C[5] * b;

        a = p[6];
        b = p[-7];
        p[-7] = b * D_800B069C[6] - D_800B067C[6] * a;
        p[6] = a * D_800B069C[6] + D_800B067C[6] * b;

        a = p[7];
        b = p[-8];
        p[-8] = b * D_800B069C[7] - D_800B067C[7] * a;
        p[7] = a * D_800B069C[7] + D_800B067C[7] * b;
    } while (++k < 0x20);

    return 1;
}
// NON-MATCHING (ONE WORD): MPEG side-info / header parse for one frame.
// 569 of 569 instructions, and 568 of the 569 words are correct - 542
// already byte-identical and 26 more differing only in a relocated
// immediate (the func_151F8960 calls and the two table loads, all of
// which resolve at link time).  The single genuine difference is at
// 151F7060: target emits `addu $a1, $t9, $t0` (arg0 first) where this
// build emits `addu $a1, $t0, $t9` (the 0x2068 offset first) for the
// second argument of the indirect call.  Eight source spellings were
// tried - `(char *) arg0 + off + 0x2024`, `off + (char *) arg0 +
// 0x2024`, `(char *) arg0 + (off + 0x2024)`, `(char *) arg0 + 0x2024 +
// off`, `&((char *) arg0)[off] + 0x2024`, a u32-typed offset, a
// (u32)-cast integer add, and a `char *` parameter - and every one of
// them produces the offset-first order.  Routing the offset through a
// local does give arg0-first but spills it, costing three extra words.
// This is the already-recorded stop signal: a transposed pair of
// REGISTER operands on a single `addu` is not source-controllable.
//
// Three shapes were needed to reach this point, all of them the
// "one expression keeps its temps alive across the branch" rule that
// func_151F4F38 established, applied to a new case:
//
//  1. `X = cond ? A : B` rather than if/else, for the four sites that
//     store a constant into a field (unk206C twice, unk3F8C, unk3F90).
//     Target reuses the arg0 register loaded for the condition when it
//     stores in the fall-through arm; an if/else reloads arg0 there,
//     costing one word per site.  Note the taken (else) arm reloads in
//     both versions - only the fall-through arm is dominated by the
//     condition block, so only it can reuse.
//
//  2. A TERNARY USED AS A STATEMENT, with its value discarded, for the
//     two `unk3F8C == 1` sites that call func_151F8960 with a different
//     bit count in each arm:
//         cond ? f(a, b, 5) : f(a, b, 3);
//     This still emits two separate `jal`s, exactly like an if/else,
//     but it is one expression, so the fall-through arm reuses arg0.
//     Writing it as a plain if/else reloads arg0 and also flips the
//     argument-setup order (a2 first instead of a0/a1 first).  Worth
//     remembering: a ternary is usable purely for its codegen shape
//     even where nothing consumes the result.
//
//  3. Operand order on the final subtraction.  Target evaluates
//     unk206C before unk2068 inside the parenthesised sum, so the
//     source is `(unk206C + unk2068)`, not `(unk2068 + unk206C)` -
//     the usual right-operand-first rule for commutative `+`.
//
// D_800B06BC and D_800B0734 are two-dimensional s32 tables indexed
// [unk3BA4][unk3BB0] and [unk3BA4][unk3BB4], with 15 and 4 entries per
// row respectively; declaring them that way reproduces target's
// `*60 + *4` and `*16 + *4` address arithmetic exactly.
//
// Semantics: picks the header size from unk3BA4/unk3BC0 (0x11/0x20/9),
// pulls that many bytes through the indirect reader at arg0->unk4 and
// bails out returning 0 on a short read, then advances unk18, derives
// the channel count unk3F8C and granule count unk3F90, and walks the
// side info with func_151F8960 - main_data_begin into unk3BF4, private
// bits, the per-channel scfsi table at unk3BF8, then for every granule
// and channel the part2_3_length / big_values / global_gain /
// scalefac_compress / window_switching block at unk3C78..unk3D00.
// Finally it looks up the bitrate and sample-rate table entries into
// unk3F7C / unk3F80, computes the frame size (x144/x72 divided by the
// rate) into unk3F84, and leaves the remaining byte count in unk3F88.
// s32 func_151F6FD0(void *arg0) {
//     s32 n;
//     s32 ch;
//     s32 j;
//     s32 sfLen;
//     s32 gr;
//     s32 m;
//     s32 p;
//
//     if (*(s32 *) ((char *) arg0 + 0x3BA4) != 0) {
//         *(s32 *) ((char *) arg0 + 0x206C) = *(s32 *) ((char *) arg0 + 0x3BC0) == 3 ? 0x11 : 0x20;
//     } else {
//         *(s32 *) ((char *) arg0 + 0x206C) = *(s32 *) ((char *) arg0 + 0x3BC0) == 3 ? 9 : 0x11;
//     }
//
//     n = (*(s32 (**)(s32, void *, s32, s32)) ((char *) arg0 + 4))(
//             *(s32 *) arg0,
//             (char *) arg0 + *(s32 *) ((char *) arg0 + 0x2068) + 0x2024,
//             *(s32 *) ((char *) arg0 + 0x206C),
//             -1);
//     if (*(s32 *) ((char *) arg0 + 0x206C) != n) {
//         return 0;
//     }
//
//     *(s32 *) ((char *) arg0 + 0x18) += *(s32 *) ((char *) arg0 + 0x206C);
//
//     *(s32 *) ((char *) arg0 + 0x3F8C) = *(s32 *) ((char *) arg0 + 0x3BC0) == 3 ? 1 : 2;
//
//     *(s32 *) ((char *) arg0 + 0x3F90) = *(s32 *) ((char *) arg0 + 0x3BA4) != 0 ? 2 : 1;
//
//     if (*(s32 *) ((char *) arg0 + 0x3BA4) != 0) {
//         *(s32 *) ((char *) arg0 + 0x3BF4) =
//             func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 9);
//         *(s32 *) ((char *) arg0 + 0x3F8C) == 1
//             ? func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 5)
//             : func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 3);
//     } else {
//         *(s32 *) ((char *) arg0 + 0x3BF4) =
//             func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 8);
//         *(s32 *) ((char *) arg0 + 0x3F8C) == 1
//             ? func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1)
//             : func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 2);
//     }
//
//     if (*(s32 *) ((char *) arg0 + 0x3BA4) != 0) {
//         for (ch = 0; ch < *(s32 *) ((char *) arg0 + 0x3F8C); ch++) {
//             for (j = 0; j < 4; j++) {
//                 *(s32 *) ((char *) arg0 + ch * 128 + j * 4 + 0x3BF8) =
//                     func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
//             }
//         }
//     }
//
//     if (*(s32 *) ((char *) arg0 + 0x3BA4) != 0) {
//         sfLen = 4;
//     } else {
//         sfLen = 9;
//     }
//
//     for (gr = 0; gr < *(s32 *) ((char *) arg0 + 0x3F90); gr++) {
//         for (ch = 0; ch < *(s32 *) ((char *) arg0 + 0x3F8C); ch++) {
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C78) =
//                 func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 0xC);
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C80) =
//                 func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 9);
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C88) =
//                 func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 8);
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C90) =
//                 sfLen ? func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, sfLen) : 0;
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C98) =
//                 func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
//
//             if (*(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C98) != 0) {
//                 *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA0) =
//                     func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 2);
//                 *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA8) =
//                     func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
//                 for (m = 0; m < 2; m++) {
//                     *(s32 *) ((char *) arg0 + gr * 12 + ch * 12 + m * 4 + 0x3CB0) =
//                         func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 5);
//                 }
//                 *(s32 *) ((char *) arg0 + gr * 12 + ch * 12 + 0x3CB8) = 0;
//                 for (p = 0; p < 3; p++) {
//                     *(s32 *) ((char *) arg0 + gr * 12 + ch * 12 + p * 4 + 0x3CC8) =
//                         func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 3);
//                 }
//             } else {
//                 *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA0) = 0;
//                 *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA8) = 0;
//                 for (m = 0; m < 3; m++) {
//                     *(s32 *) ((char *) arg0 + gr * 12 + ch * 12 + m * 4 + 0x3CB0) =
//                         func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 5);
//                 }
//                 *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CE0) =
//                     func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 4);
//                 *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CE8) =
//                     func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 3);
//             }
//
//             if (*(s32 *) ((char *) arg0 + 0x3BA4) != 0) {
//                 *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CF0) =
//                     func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
//             }
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CF8) =
//                 func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3D00) =
//                 func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
//         }
//     }
//
//     *(s32 *) ((char *) arg0 + 0x3F7C) =
//         D_800B06BC[*(s32 *) ((char *) arg0 + 0x3BA4)][*(s32 *) ((char *) arg0 + 0x3BB0)];
//     *(s32 *) ((char *) arg0 + 0x3F80) =
//         D_800B0734[*(s32 *) ((char *) arg0 + 0x3BA4)][*(s32 *) ((char *) arg0 + 0x3BB4)];
//
//     if (*(s32 *) ((char *) arg0 + 0x3BA4) != 0) {
//         *(s32 *) ((char *) arg0 + 0x3F84) =
//             *(s32 *) ((char *) arg0 + 0x3F7C) * 144 / *(s32 *) ((char *) arg0 + 0x3F80);
//     } else {
//         *(s32 *) ((char *) arg0 + 0x3F84) =
//             *(s32 *) ((char *) arg0 + 0x3F7C) * 72 / *(s32 *) ((char *) arg0 + 0x3F80);
//     }
//
//     *(s32 *) ((char *) arg0 + 0x3F88) =
//         *(s32 *) ((char *) arg0 + 0x3F84) + *(s32 *) ((char *) arg0 + 0x3BB8) -
//         (*(s32 *) ((char *) arg0 + 0x206C) + *(s32 *) ((char *) arg0 + 0x2068));
//     return 1;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_221290/func_151F6FD0.s")
// NON-MATCHING (JUSTREG): 427/427 instructions and structurally an
// exact match - with register names normalized away only TWO of the 427
// lines differ, and both are the D_800E0E38 relocation immediate.
//
// Layer-3 frame decode: reads the frame via func_151F7F60, sets the bit
// cursor from the main_data offset, runs side-info + scalefactor decode
// per channel, applies stereo processing, then per channel does the
// alias reduction / IMDCT (func_151F9BF0 for short blocks, func_151F8CF0
// otherwise, the latter taking a window from D_800E0E38), carries the
// overlap halves forward, and emits the PCM block.
//
// The entire remaining difference is register numbering, all of it
// cascading from ONE instruction: target computes the initial `outp`
// address as `addu t9,t6,t8` (arg0 first) where this build emits
// `addu t9,t8,t6` (the scaled offset first). Writing the pointer
// arithmetic the other way round (`offset + (char *) arg0`) does not
// move it - that matches func_151F7F60 and func_151F86B0 in this same
// file, where the identical swapped-`addu` was also immune to every
// phrasing tried. Once that one register pairing differs, every later
// allocation follows it, which is why the raw word diff looks large
// while the normalized diff is two lines.
#pragma GLOBAL_ASM("asm/nonmatchings/game_221290/func_151F78B4.s")
// s32 func_151F78B4(void *arg0) {
//     s32 n;
//     s32 gr;
//     s32 ch;
//     s32 nbands;
//     s32 tmp;
//     s32 mode;
//     s32 i;
//     s32 k;
//     s16 *outp;
//     f32 buf[0x240];
//     f32 scale;
//     f32 inv;
//     f32 one;
//     s32 s;
//     s32 v;
//
//     gr = 0;
//     outp = (s16 *) ((char *) arg0 + *(s32 *) ((char *) arg0 + 0x3BA0) * 1160 + 0x2070);
//
//     n = func_151F7F60(arg0);
//     if (n == 0) {
//         return 0;
//     }
//
//     *(s32 *) ((char *) arg0 + 0x2020) = (n - *(s32 *) ((char *) arg0 + 0x3BF4)) * 8;
//     if (*(s32 *) ((char *) arg0 + 0x2020) < 0) {
//         return 1;
//     }
//
//     for (ch = 0; ch < *(s32 *) ((char *) arg0 + 0x3F8C); ch++) {
//         func_151F63C4(arg0, gr, ch);
//         func_151F42E8(arg0, gr, ch);
//     }
//
//     func_151F6970(arg0, gr);
//
//     if (*(s32 *) ((char *) arg0 + gr * 4 + 0x3C98) != 0 &&
//         *(s32 *) ((char *) arg0 + gr * 4 + 0x3CA0) == 2) {
//         nbands = 0x20;
//     } else {
//         tmp = (*(s32 *) ((char *) arg0 + 0x465C) - 1) / 0x12 + 1;
//         nbands = tmp;
//     }
//
//     for (ch = 0; ch < *(s32 *) ((char *) arg0 + 0x3F8C); ch++) {
//         func_151F6B28(arg0, gr, ch);
//
//         if (*(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C98) != 0 &&
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA0) == 2 &&
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA8) != 0) {
//             mode = 0;
//         } else if (*(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C98) == 0) {
//             mode = 0;
//         } else {
//             mode = *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA0);
//         }
//
//         if (mode == 2) {
//             for (i = 0; i < 2; i++) {
//                 func_151F9BF0((char *) arg0 + ch * 2304 + i * 72 + 0x4F64, i,
//                               (char *) buf + i * 72,
//                               (char *) arg0 + ch * 2304 + i * 72 + 0x6A64);
//             }
//         } else {
//             for (i = 0; i < 2; i++) {
//                 func_151F8CF0((char *) arg0 + ch * 2304 + i * 72 + 0x4F64, i,
//                               (char *) buf + i * 72,
//                               (char *) arg0 + ch * 2304 + i * 72 + 0x6A64,
//                               (char *) D_800E0E38 + mode * 144);
//             }
//         }
//
//         if (*(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3C98) != 0 &&
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA0) == 2 &&
//             *(s32 *) ((char *) arg0 + gr * 4 + ch * 4 + 0x3CA8) != 0) {
//             mode = 2;
//         }
//
//         if (mode == 2) {
//             for (i = 2; i < nbands; i++) {
//                 func_151F9BF0((char *) arg0 + ch * 2304 + i * 72 + 0x4F64, i,
//                               (char *) buf + i * 72,
//                               (char *) arg0 + ch * 2304 + i * 72 + 0x6A64);
//             }
//         } else {
//             for (i = 2; i < nbands; i++) {
//                 func_151F8CF0((char *) arg0 + ch * 2304 + i * 72 + 0x4F64, i,
//                               (char *) buf + i * 72,
//                               (char *) arg0 + ch * 2304 + i * 72 + 0x6A64,
//                               (char *) D_800E0E38 + mode * 144);
//             }
//         }
//
//         while (i < 0x20) {
//             bcopy((char *) arg0 + ch * 2304 + i * 72 + 0x6A64, (char *) buf + i * 72, 0x48);
//             bzero((char *) arg0 + ch * 2304 + i * 72 + 0x6A64, 0x48);
//             i++;
//         }
//
//         scale = 65536.0f;
//         one = 1.0f;
//         v = (s32) (scale * one * 16.0f);
//         *outp = v >> 16;
//         outp++;
//         *outp = v & 0xFFFF;
//         outp++;
//         v = -v;
//         *outp = v >> 16;
//         outp++;
//         *outp = v & 0xFFFF;
//         outp++;
//         inv = 2048.0f / one;
//
//         for (k = 0; k < 0x12; k++) {
//             for (i = 0; i < 0x20; i++) {
//                 s = (s32) (*(f32 *) ((char *) buf + i * 72 + k * 4) * inv);
//                 *outp = s;
//                 outp++;
//             }
//         }
//     }
//
//     return 1;
// }

// NON-MATCHING (one word): 74/74 instructions, and 73 of the 74 words
// are byte-identical to target. Operates on the same streaming buffer
// struct as func_151F85C4 below (fields unk18/unk1C/unk201C/unk2020/
// unk3F88, unk0/unk4 a callback userdata+fnptr pair). Compacts the
// window by discarding the first 0x1000 consumed bytes when
// unk201C+unk3F88 gets close to full, refills via the object's own
// fill callback, zero-pads any short read, then advances the position
// and byte-count fields and returns the old position.
//
// UPDATED 2026-09-22: the previous writeup here had this at 72 vs 74
// with `obj` marked `volatile` to force target's reload-heavy shape,
// and recorded several failed attempts to tune the reload density.
// None of that was the real issue - this file was simply being
// compiled with the wrong OPT_FLAGS. game_221290.c is the .game
// overlay's audio driver and was built UNOPTIMIZED (`-g`) in the
// original ROM, which is why target reloads everything from the stack;
// there is nothing to force with `volatile`. The Makefile now carries
// a `-g` override for this file, and the plain non-volatile source
// below matches. Two further operand-order fixes were needed once the
// flags were right: IDO emits a commutative `addu`/operand pair in the
// REVERSE of source order, so the `if` condition reads unk3F88 before
// unk201C to make target load unk201C first.
//
// The single remaining differing word is idx 35, `addu a1,t2,t4` where
// this build emits `addu a1,t4,t2` - the same commutative add with its
// two source registers swapped. Tried writing the address expression
// as `ptr + off`, `off + ptr`, and `&((char *) arg0)[off]`; all three
// produce the identical (reversed) operand order, so this is the
// established unfixable operand-order class rather than a phrasing
// problem. Everything else, including both jal sites, matches.
// s32 func_151F7F60(void *arg0) {
//     s32 shiftAmt = 0x1000;
//     s32 bytesRead;
//
//     if (*(s32 *) ((char *) arg0 + 0x3F88) + *(s32 *) ((char *) arg0 + 0x201C) >= 0x1FFC) {
//         bcopy((char *) arg0 + shiftAmt + 0x1C, (char *) arg0 + 0x1C, shiftAmt);
//         *(s32 *) ((char *) arg0 + 0x201C) -= shiftAmt;
//         *(s32 *) ((char *) arg0 + 0x2020) -= shiftAmt << 3;
//     }
//
//     bytesRead = ((s32 (*)(void *, void *, s32, s32)) (*(void **) ((char *) arg0 + 4)))(
//         *(void **) arg0,
//         (char *) arg0 + *(s32 *) ((char *) arg0 + 0x201C) + 0x1C,
//         *(s32 *) ((char *) arg0 + 0x3F88),
//         -1);
//
//     if (bytesRead < *(s32 *) ((char *) arg0 + 0x3F88)) {
//         bzero((char *) arg0 + bytesRead + 0x1C, *(s32 *) ((char *) arg0 + 0x3F88) - bytesRead);
//     }
//
//     *(s32 *) ((char *) arg0 + 0x18) += *(s32 *) ((char *) arg0 + 0x3F88);
//     *(s32 *) ((char *) arg0 + 0x201C) += *(s32 *) ((char *) arg0 + 0x3F88);
//
//     return *(s32 *) ((char *) arg0 + 0x201C) - *(s32 *) ((char *) arg0 + 0x3F88);
// }
struct func_151F7F60_s {
    void *unk0;
    s32 (*unk4)(void *, void *, s32, s32);
    char pad8[0x10];
    s32 unk18;
    u8 unk1C[0x2000];
    s32 unk201C;
    s32 unk2020;
    char pad2024[0x3F88 - 0x2024];
    s32 unk3F88;
};
s32 func_151F7F60(struct func_151F7F60_s *arg0) {
    s32 shiftAmt = 0x1000;
    s32 bytesRead;

    if (arg0->unk201C + arg0->unk3F88 >= 0x1FFC) {
        bcopy(&arg0->unk1C[shiftAmt], arg0->unk1C, shiftAmt);
        arg0->unk201C -= shiftAmt;
        arg0->unk2020 -= shiftAmt << 3;
    }

    bytesRead = arg0->unk4(arg0->unk0, &arg0->unk1C[arg0->unk201C], arg0->unk3F88, -1);

    if (bytesRead < arg0->unk3F88) {
        bzero(&arg0->unk1C[bytesRead], arg0->unk3F88 - bytesRead);
    }

    arg0->unk18 += arg0->unk3F88;
    arg0->unk201C += arg0->unk3F88;

    return arg0->unk201C - arg0->unk3F88;
}
// Frame sync + header parse. Scans the input stream a byte at a time for
// the 0xFF / 0xF0 sync pattern (resetting on any mismatch), reads the
// two header bytes, then pulls the twelve header bitfields into
// unk3BA4..unk3BD0. Re-syncs recursively on a reserved bitrate/sample
// rate, or when the header disagrees with the first one seen. Finally
// installs the per-layer decode hooks and runs the layer's own init.
s32 func_151F8088(void *arg0, s32 arg1) {
    s32 sync;
    s32 n;
    s32 r;
    u8 mask;

    if (arg1 != -1) {
        *(s32 *) ((char *) arg0 + 0x18) = arg1;
    }

    sync = arg1;
    n = 0;
    mask = 0xFF;

    for (;;) {
        r = ((s32 (*)(void *, void *, s32, s32)) *(void **) ((char *) arg0 + 4))(
                *(void **) arg0, (char *) arg0 + n + 0x2024, 1, sync);
        if (r <= 0) {
            return 0;
        }
        sync = -1;
        *(s32 *) ((char *) arg0 + 0x18) += 1;

        if (*(u8 *) ((char *) arg0 + n + 0x2024) != 0xFF &&
            *(u8 *) ((char *) arg0 + n + 0x2024) != 0xF3) {
            return 0;
        }

        if ((*(u8 *) ((char *) arg0 + n + 0x2024) & mask) != mask) {
            mask = 0xFF;
            n = 0;
            continue;
        }
        n++;
        if (mask == 0xF0) {
            break;
        }
        mask = 0xF0;
    }

    r = ((s32 (*)(void *, void *, s32, s32)) *(void **) ((char *) arg0 + 4))(
            *(void **) arg0, (char *) arg0 + 0x2026, 2, -1);
    if (r <= 0) {
        return 0;
    }
    *(s32 *) ((char *) arg0 + 0x18) += 2;
    *(s32 *) ((char *) arg0 + 0x2064) = 0xC;

    *(s32 *) ((char *) arg0 + 0x3BA4) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
    *(s32 *) ((char *) arg0 + 0x3BA8) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 2);
    *(s32 *) ((char *) arg0 + 0x3BAC) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
    *(s32 *) ((char *) arg0 + 0x3BB0) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 4);
    *(s32 *) ((char *) arg0 + 0x3BB4) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 2);
    *(s32 *) ((char *) arg0 + 0x3BB8) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
    *(s32 *) ((char *) arg0 + 0x3BBC) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
    *(s32 *) ((char *) arg0 + 0x3BC0) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 2);
    *(s32 *) ((char *) arg0 + 0x3BC4) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 2);
    *(s32 *) ((char *) arg0 + 0x3BC8) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
    *(s32 *) ((char *) arg0 + 0x3BCC) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 1);
    *(s32 *) ((char *) arg0 + 0x3BD0) = func_151F8960((char *) arg0 + 0x2024, (char *) arg0 + 0x2064, 2);

    if (*(s32 *) ((char *) arg0 + 0x3BB0) == 0xF ||
        *(s32 *) ((char *) arg0 + 0x3BB4) == 3) {
        return func_151F8088(arg0, -1);
    }

    if (*(s32 *) ((char *) arg0 + 0x3BD4) == 0) {
        *(s32 *) ((char *) arg0 + 0x3BD4) = 1;
        *(s32 *) ((char *) arg0 + 0x3BD8) = *(s32 *) ((char *) arg0 + 0x3BA4);
        *(s32 *) ((char *) arg0 + 0x3BDC) = *(s32 *) ((char *) arg0 + 0x3BA8);
        *(s32 *) ((char *) arg0 + 0x3BE0) = *(s32 *) ((char *) arg0 + 0x3BAC);
        *(s32 *) ((char *) arg0 + 0x3BE4) = *(s32 *) ((char *) arg0 + 0x3BB4);
        *(s32 *) ((char *) arg0 + 0x3BE8) = *(s32 *) ((char *) arg0 + 0x3BC0);
        *(s32 *) ((char *) arg0 + 0x3BEC) = *(s32 *) ((char *) arg0 + 0x3BC8);
        *(s32 *) ((char *) arg0 + 0x3BF0) = *(s32 *) ((char *) arg0 + 0x3BCC);
    } else if (*(s32 *) ((char *) arg0 + 0x3BD8) != *(s32 *) ((char *) arg0 + 0x3BA4) ||
               *(s32 *) ((char *) arg0 + 0x3BDC) != *(s32 *) ((char *) arg0 + 0x3BA8) ||
               *(s32 *) ((char *) arg0 + 0x3BE0) != *(s32 *) ((char *) arg0 + 0x3BAC) ||
               *(s32 *) ((char *) arg0 + 0x3BE4) != *(s32 *) ((char *) arg0 + 0x3BB4) ||
               *(s32 *) ((char *) arg0 + 0x3BE8) != *(s32 *) ((char *) arg0 + 0x3BC0) ||
               *(s32 *) ((char *) arg0 + 0x3BF0) != *(s32 *) ((char *) arg0 + 0x3BCC)) {
        return func_151F8088(arg0, -1);
    }

    *(s32 *) ((char *) arg0 + 0x2068) = 4;

    if (*(s32 *) ((char *) arg0 + 0x3BAC) == 0) {
        r = ((s32 (*)(void *, void *, s32, s32)) *(void **) ((char *) arg0 + 4))(
                *(void **) arg0, (char *) arg0 + 0x2028, 2, -1);
        if (r <= 0) {
            return 0;
        }
        *(s32 *) ((char *) arg0 + 0x18) += 2;
        *(s32 *) ((char *) arg0 + 0x2064) += 0x10;
        *(s32 *) ((char *) arg0 + 0x2068) = 6;
    }

    if (*(s32 *) ((char *) arg0 + 0x3BA8) == 1) {
        *(s32 *) ((char *) arg0 + 0x8478) = (s32) func_151F78B4;
        *(s32 *) ((char *) arg0 + 0x847C) = (s32) func_151F6FD0;
    } else if (*(s32 *) ((char *) arg0 + 0x3BA8) == 2) {
        return 0;
    } else if (*(s32 *) ((char *) arg0 + 0x3BA8) == 3) {
        return 0;
    }

    if (((s32 (*)(void *)) *(void **) ((char *) arg0 + 0x847C))(arg0) == 0) {
        return 0;
    }

    return 1;
}
// Init for the fixed-address global buffer D_800E1880: sets
// unkC/unk10/unk14 to -1, copies the 3 args into unk0/unk4/unk8, zeroes
// unk201C/unk2020/unk3BA0, bails if func_151F8088(ptr, 0) fails, then
// zeroes unk8474 and bzero's a 0x900-byte region at +0x6A64.

void *func_151F85C4(s32 arg0, s32 arg1, s32 arg2) {
    void *obj = D_800E1880;

    if (obj == 0) {
        return 0;
    }

    *(s32 *) ((char *) obj + 0xC) = -1;
    *(s32 *) ((char *) obj + 0x10) = -1;
    *(s32 *) ((char *) obj + 0x14) = -1;
    *(s32 *) ((char *) obj + 0x0) = arg0;
    *(s32 *) ((char *) obj + 0x4) = arg1;
    *(s32 *) ((char *) obj + 0x8) = arg2;
    *(s32 *) ((char *) obj + 0x201C) = 0;
    *(s32 *) ((char *) obj + 0x2020) = 0;
    *(s32 *) ((char *) obj + 0x3BA0) = 0;

    if (func_151F8088(obj, 0) == 0) {
        return 0;
    }

    *(s32 *) ((char *) obj + 0x8474) = 0;
    bzero((char *) obj + 0x6A64, 0x900);

    return obj;
}

// NON-MATCHING (JUSTREG): 109/109 instructions, with only 5 of the 109
// words genuinely differing - the other 9 differences are relocation
// sites (jal func_151F8088, jal strlen, and the %hi/%lo pairs for
// D_800E0E04 and D_800E0E00). Advances the unk3BA0 slot cursor mod 6,
// re-arms the stream via func_151F8088, hands the caller the current
// slot buffer and unk3F8C, then if unk3BC8 is set reads a NUL-
// terminated string one byte at a time through the object's own
// unk4 reader and forwards it to the D_800E0E00 log hook.
//
// The 5 real differences are all commutative-operand / register-
// numbering choices with no source-level lever: one `addu t3,t0,t2`
// emitted with its operands swapped, and the loop body allocating t0
// and t2 to obj/i in the opposite order from target (every downstream
// use follows that one swap). Tried reordering the pointer arithmetic
// and the call's subexpressions; neither moves it.
//
// Everything structural does match, and four separate idioms were
// needed to get there under this file's `-g` build - all worth reusing
// on the remaining pragmas here:
//   - locals declared in descending stack-slot order (obj, ret, buf, i)
//   - the early exit written as `goto end;` rather than `return ret;`,
//     so it branches to the shared return stub instead of duplicating
//     the v0 load
//   - `while (buf[i++])` not `while (buf[i++] != 0)`; the explicit
//     comparison materializes a boolean via sltu+move before branching
//   - `u8 buf[]` not `char buf[]`, since target reads it with `lbu`
//     (this codebase compiles with -signed, so plain char gives `lb`)
struct func_151F86B0_s {
    void *handle;
    s32 (*read)(void *, u8 *, s32, s32);
    u8 pad8[0x2070 - 0x8];
    u8 slots[6][0x488];
    s32 idx; /* 3BA0 */
    u8 pad3BA4[0x3BC8 - 0x3BA4];
    s32 flag; /* 3BC8 */
    u8 pad3BCC[0x3F8C - 0x3BCC];
    s32 unk3F8C;
    u8 pad3F90[0x8474 - 0x3F90];
    s32 unk8474;
    s32 (*cb)(void *);
};

s32 func_151F86B0(void *arg0, void *arg1, void *arg2) {
    struct func_151F86B0_s *obj;
    s32 ret;
    u8 buf[0x100];
    s32 i;

    obj = arg0;
    obj->idx += 1;
    if (obj->idx >= 6) {
        obj->idx = 0;
    }

    if (func_151F8088(obj, obj->unk8474) == 0) {
        D_800E0E04 = 3;
        return 0;
    }

    obj->unk8474 = -1;
    ret = obj->cb(obj);

    if (ret == 0) {
        goto end;
    }

    *(u8 **) arg1 = obj->slots[obj->idx];
    *(s32 *) arg2 = obj->unk3F8C;

    if (obj->flag != 0) {
        i = 0;
        do {
            if (obj->read(obj->handle, &buf[i], 1, -1) == 0) {
                break;
            }
        } while (buf[i++]);

        if (D_800E0E00 != 0) {
            ((void (*)(s32, char *, s32)) D_800E0E00)(0, (char *) buf, strlen((char *) buf) + 1);
        }
    }

end:
    return ret;
}
// s32 func_151F86B0(void *arg0, void *arg1, void *arg2) {
//     void *obj;
//     s32 ret;
//     u8 buf[0x100];
//     s32 i;
//
//     obj = arg0;
//     *(s32 *) ((char *) obj + 0x3BA0) += 1;
//     if (*(s32 *) ((char *) obj + 0x3BA0) >= 6) {
//         *(s32 *) ((char *) obj + 0x3BA0) = 0;
//     }
//
//     if (func_151F8088(obj, *(s32 *) ((char *) obj + 0x8474)) == 0) {
//         D_800E0E04 = 3;
//         return 0;
//     }
//
//     *(s32 *) ((char *) obj + 0x8474) = -1;
//     ret = ((s32 (*)(void *)) *(void **) ((char *) obj + 0x8478))(obj);
//
//     if (ret == 0) {
//         goto end;
//     }
//
//     *(s32 *) arg1 = (s32) ((char *) obj + *(s32 *) ((char *) obj + 0x3BA0) * 1160 + 0x2070);
//     *(s32 *) arg2 = *(s32 *) ((char *) obj + 0x3F8C);
//
//     if (*(s32 *) ((char *) obj + 0x3BC8) != 0) {
//         i = 0;
//         do {
//             if (((s32 (*)(void *, u8 *, s32, s32)) *(void **) ((char *) obj + 4))(
//                     *(void **) obj, &buf[i], 1, -1) == 0) {
//                 break;
//             }
//         } while (buf[i++]);
//
//         if (D_800E0E00 != 0) {
//             ((void (*)(s32, char *, s32)) D_800E0E00)(0, (char *) buf, strlen((char *) buf) + 1);
//         }
//     }
//
// end:
//     return ret;
// }

