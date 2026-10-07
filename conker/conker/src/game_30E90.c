#include <ultra64.h>

#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_30E90/func_150039E0.s")

// FIXME: matches but something isnt right
void func_15004574(void) {
    if (D_800DBF88 != 0xFF) {
        D_800DBF8C = D_800DBEF4[D_800DBF88].unk1C;
        D_800DBF90 = D_800DBEF4[D_800DBF88].unk28;
    }
}

void func_150045BC(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_30E90/func_150045C4.s")

// NON-MATCHING: full semantics + branch/block topology recovered and
// verified via isolated harness - walks 8-byte records starting at
// arg0 (each record: classifier byte at +0, subtype byte at +3,
// s32 accumulator at +4) until a -0x21 sentinel byte, adding arg1 into
// the accumulator when the classifier is 1 or 0xDE, or adding arg2
// when the classifier is -0x24 AND the subtype byte is 0xE. Getting
// the nested-if form right (test -0x24 first as `if (c != -0x24) {
// nested 1/0xDE checks } else { subtype check }`, not a flat
// else-if chain) was required to reproduce target's exact block
// order (the -0x24 case's code placed last, after 1 and 0xDE, despite
// being tested first) - once that matched, every branch opcode and
// block boundary lines up exactly. The one remaining gap: target
// relocates arg1/arg2 into $a3/$s0 right at entry (needing a stack
// frame purely to spill the now-callee-saved $s0), while every source
// form tried here keeps them in $a1/$a2 throughout and never needs a
// frame at all - a pure register-pressure allocation difference, not
// reproducible by only rephrasing the C.
#pragma GLOBAL_ASM("asm/nonmatchings/game_30E90/func_150049A4.s")
// void func_150049A4(s8 *arg0, s32 arg1, s32 arg2) {
//     s32 idx;
//     s8 *rec;
//     s8 c;
//
//     idx = 0;
//     rec = arg0;
//     c = *arg0;
//     if (c != -0x21) {
//         do {
//             idx += 1;
//             if (c != -0x24) {
//                 if (c != 1) {
//                     if (c == 0xDE) {
//                         *(s32 *) (rec + 4) += arg1;
//                     }
//                 } else {
//                     *(s32 *) (rec + 4) += arg1;
//                 }
//             } else {
//                 if (*(u8 *) (rec + 3) == 0xE) {
//                     *(s32 *) (rec + 4) += arg2;
//                 }
//             }
//             rec = arg0 + (idx << 3);
//             c = *rec;
//         } while (c != -0x21);
//     }
// }
void func_15004A4C(void) {
    s32 i;

    if (D_800DBEF0 > 0) {
        i = 0;
        do {
            (*(s32 **) D_800DBEF8)[i] = 0;
            (*(s8 **) D_800DBEFC)[i] = 0;
            i++;
        } while (i < D_800DBEF0);
    }
}

// NON-MATCHING: 82 vs target's 81 instructions. Scans an array of
// count(arg0->unk16) 16-byte records at arg0->unk28, each holding 3
// halfwords (offsets 4/0/2) scaled by arg0->unk34/0x2C/0x30
// respectively, tracking the largest squared "distance"
// (a^2+b^2+c^2). If nothing exceeded 0, returns immediately (no
// history fields touched). Otherwise takes the sqrt and either seeds
// both arg0->unk50/unk52 on first use (unk50==0), bumps D_800BE2A0 if
// the new distance beats either existing threshold, or bumps
// D_800BE2A4 otherwise. arg1 is spilled to its stack home and never
// read again, matching target's own dead store exactly. The gap is a
// stable bnez-vs-bnezl branch-type difference on the scan loop's own
// exit test (with a correspondingly rescheduled pointer increment) -
// tried do-while vs for, != vs < loop bounds (the latter blew up to
// 246 instructions and was reverted), and increment statement order,
// none changed it, consistent with this session's other likely-branch
// near-misses.
extern u16 D_800BE2A0;
extern u16 D_800BE2A2;
extern u16 D_800BE2A4;

struct func_15004AAC_s {
    s16 x, y, z;
    s16 pad[5];
};

struct func_15004AAC_s2 {
    u8 pad0[0x16];
    u16 count;
    u8 pad18[0x10];
    struct func_15004AAC_s *rec;
    f32 sx, sy, sz;
    u8 pad38[0x18];
    u16 unk50;
    u16 unk52;
};

void func_15004AAC(struct func_15004AAC_s2 *arg0, s32 arg1) {
    s32 max;
    s32 i;
    s32 v;

    max = 0;
    for (i = 0; i < arg0->count; i++) {
        v = (arg0->rec[i].x * arg0->sx) * (arg0->rec[i].x * arg0->sx)
          + (arg0->rec[i].y * arg0->sy) * (arg0->rec[i].y * arg0->sy)
          + (arg0->rec[i].z * arg0->sz) * (arg0->rec[i].z * arg0->sz);
        if (max < v) {
            max = v;
        }
    }
    if (max == 0) {
        return;
    }
    max = sqrtf(max);
    v = arg0->unk50;
    if (v == 0) {
        arg0->unk50 = max;
        arg0->unk52 = max;
        D_800BE2A2++;
        return;
    }
    if (v < max || arg0->unk52 < max) {
        D_800BE2A0++;
        return;
    }
    D_800BE2A4++;
}
// extern u16 D_800BE2A0;
// extern u16 D_800BE2A2;
// extern u16 D_800BE2A4;
//
// void func_15004AAC(void *arg0, s32 arg1) {
//     s16 count;
//     s32 maxDistSq;
//     s32 offset;
//     char *rec;
//     f32 scaleY, scaleZ, scaleX;
//     s32 dist;
//     u16 prev1;
//
//     count = *(s16 *) ((char *) arg0 + 0x16);
//     maxDistSq = 0;
//
//     if (count > 0) {
//         rec = *(char **) ((char *) arg0 + 0x28);
//         scaleX = *(f32 *) ((char *) arg0 + 0x34);
//         scaleY = *(f32 *) ((char *) arg0 + 0x2C);
//         scaleZ = *(f32 *) ((char *) arg0 + 0x30);
//
//         offset = 0;
//         do {
//             f32 a = (f32) *(s16 *) (rec + 4) * scaleX;
//             f32 b = (f32) *(s16 *) (rec + 0) * scaleY;
//             f32 c = (f32) *(s16 *) (rec + 2) * scaleZ;
//             s32 v = (s32) (a * a + (b * b + c * c));
//
//             if (maxDistSq < v) {
//                 maxDistSq = v;
//             }
//             rec += 0x10;
//             offset += 0x10;
//         } while (offset < (count << 4));
//     }
//
//     if (maxDistSq == 0) {
//         return;
//     }
//
//     dist = (s32) sqrtf((f32) maxDistSq);
//     prev1 = *(u16 *) ((char *) arg0 + 0x50);
//
//     if (prev1 == 0) {
//         *(u16 *) ((char *) arg0 + 0x50) = (u16) dist;
//         *(u16 *) ((char *) arg0 + 0x52) = (u16) dist;
//         D_800BE2A2++;
//         return;
//     }
//
//     if (prev1 < dist || *(u16 *) ((char *) arg0 + 0x52) < dist) {
//         D_800BE2A0++;
//         return;
//     }
//
//     D_800BE2A4++;
//     return;
// }
s32 func_15004BF0(s32 arg0) {
    s32 i;
    s32 v;

    if (arg0 == 0) {
        v = 1;
        for (i = arg0 = D_800DBF00; i < D_800DBEF0; i++) {
            if (v == D_800DBEF4[i].pad70[2]) {
                v++;
                i = arg0 - 1;
            }
            if (v >= 0x100) {
                v = 0xFF;
                break;
            }
        }
    } else {
        arg0 = 0xFF - D_800DBF00;
        v = arg0;
        for (i = 0; i < D_800DBEF0; i++) {
            if (v == D_800DBEF4[i].pad70[2]) {
                v--;
                i = -1;
            }
            if (v <= 0) {
                v = arg0;
                break;
            }
        }
    }
    return v;
}
// NON-MATCHING: register-choice gap only, logic and every instruction
// opcode/operand-value verified identical to target. Walks an array of
// 8-byte entries (s8 marker; pad[2]; u8 sub; s32 val;) starting at arg0,
// stopping at a marker==-33 terminator; for entries with marker==-36 and
// sub==14 whose val is non-negative (as an unsigned < 0x80000000 check),
// adds arg1 to val. Confirmed the instruction sequence is byte-identical
// to target (same opcodes, same branch shapes including the bnel/beqz
// pair, same operand constants) with ONLY the physical register numbers
// differing throughout (e.g. target's v0/v1/a1 for i/entry-ptr/marker
// vs this reconstruction's v1/a1/v0 for the same roles) - and that
// renaming is fully deterministic: do-while vs goto-based control flow,
// combining the three inner conditions into one && vs nested guard
// clauses, and local declaration order all produced byte-identical
// output, so this is not a source-phrasing issue reachable from here.
// void func_15004CE0(void *arg0, s32 arg1) {
//     s32 i;
//     void *v1;
//     s8 marker;
//
//     marker = *(s8 *) arg0;
//     if (marker == -33) {
//         return;
//     }
//     i = 0;
//     v1 = arg0;
//     do {
//         i++;
//         if (marker == -36 && *(u8 *) ((char *) v1 + 3) == 14 &&
//             (u32) *(s32 *) ((char *) v1 + 4) < 0x80000000) {
//             *(s32 *) ((char *) v1 + 4) += arg1;
//         }
//         v1 = (char *) arg0 + i * 8;
//         marker = *(s8 *) v1;
//     } while (marker != -33);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_30E90/func_15004CE0.s")
