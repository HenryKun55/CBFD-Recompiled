#include <ultra64.h>

#include "functions.h"
#include "variables.h"

void func_15169040(void *, u8);


// NON-MATCHING: corrects a wrong element count from an earlier
// attempt (the loop bound is genuinely 101 elements, confirmed by
// target's own `addiu $s2, $s0, 0x1484` - 0x1484 / sizeof(struct115)
// == 101 exactly - not 24 as previously assumed) and switches from
// index-based to pointer-based iteration to match target's actual
// shape (target compares two raw pointers, not an integer index
// against a struct-relative byte offset). 21 of 23 words now match.
// Remaining gap: target keeps THREE callee-saved registers alive
// ($s0/$s1/$s2 - one of which, $s1, is saved to the stack but never
// visibly used anywhere in the function), computing the end pointer
// as a simple offset add from the already-computed base address; this
// reconstruction only ever needs two locals (the walking pointer and
// the end pointer) and IDO computes the base address twice from
// scratch to fill both, regardless of whether the end pointer is
// written as `p + 101` (reusing `p`) or `D_8008B4A8 + 101` (a fresh
// global reference) - both produce identical output, so this is a
// scheduling/register-pressure artifact immune to the source change.
// NON-MATCHING (14 of 22 words): same shape as func_1516706C but over
// the struct115 array D_8008B4A8, calling unk18 on each of the 101
// entries (0x1484 bytes at 0x34 each).  Semantics are certain; the gap
// is register allocation - target reserves THREE saved registers (s0,
// s1, s2) and leaves s1 completely unused, using s0 for the cursor and
// s2 for the end pointer, which makes its frame 0x28 against 0x20 here
// and shifts every saved-register offset.  Deriving the end pointer
// from the cursor rather than from the array base did not reproduce the
// extra reservation.
// void func_15167010(void) {
//     struct115 *p;
//
//     p = D_8008B4A8;
//     do {
//         if (p->unk18 != NULL) {
//             ((void (*)(void)) p->unk18)();
//         }
//         p++;
//     } while (p < D_8008B4A8 + 101);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167010.s")
// void func_15167010(void) {
//     struct115 *p;
//     struct115 *end;
//     void (*func)(void);
//
//     p = D_8008B4A8;
//     end = p + 101;
//     do {
//         func = (void (*)(void)) p->unk18;
//         if (func != NULL) {
//             func();
//         }
//         p += 1;
//     } while (p < end);
// }

extern void (*D_8008CB64[])(void);
extern void (*D_8008CB70)(void);

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Walks the
// function-pointer table D_8008CB64..D_8008CB70, calling each non-null
// entry. Extremely close - identical byte-for-byte except the prologue's
// two `lui` instructions (computing D_8008CB64's and D_8008CB70's upper
// halves) are swapped relative to target (target: lui D_8008CB64, lui
// D_8008CB70, addiu D_8008CB70, addiu D_8008CB64). Tried declaring the
// end pointer first (fixed the `addiu` order but swapped the `lui`
// order instead) and a `for` loop (worse - different register entirely).
// No source order tried got both right simultaneously.
// NON-MATCHING (2 real words): calls every non-NULL entry of the
// function-pointer table running from D_8008CB64 to D_8008CB70.  The
// loop must be a do/while - a `for` emits an entry test target does not
// have - and with that the whole function matches except that target
// materialises the two table addresses as `lui s0; lui s1; addiu s1;
// addiu s0`, pairing the second `lui` with the first `addiu`.  Both
// source orderings of the two pointer initialisations were tried and
// each keeps the `addiu`s in its own order; this is the scheduler
// interleaving two independent address materialisations.
// void func_1516706C(void) {
//     void (**p)(void);
//
//     p = D_8008CB64;
//     do {
//         if (*p != NULL) {
//             (*p)();
//         }
//         p++;
//     } while (p != D_8008CB70);
// }
void func_1516706C(void) {
    s32 i;
    i = 0;
    do {
        if (D_8008CB64[i] != NULL) {
            D_8008CB64[i]();
        }
        i++;
    } while (&D_8008CB70 != &D_8008CB64[i]);
}
// void func_1516706C(void) {
//     void (**p)(void) = D_8008CB64;
//
//     do {
//         if (*p != 0) {
//             (*p)();
//         }
//         p++;
//     } while (p != &D_8008CB70);
// }
extern u8 D_800DCE50[];

void func_151670C0(void) {
    s32 i;
    s32 j;
    struct102 *p;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 101; j++) {
            if (D_8008B4A8[j].unk0 != NULL) {
                p = ((struct102 *(*)[0x68]) D_800DCE50)[i][j];
                D_800DD190++;
                while (p != NULL) {
                    ((struct102 **) D_800DD198)[D_800DD190] = ((struct102 **) p)[2];
                    D_8008B4A8[j].unk0(p);
                    p = ((struct102 **) D_800DD198)[D_800DD190];
                }
                D_800DD190--;
            }
        }
    }
}
extern u8 D_800DCE50[];
struct func_151671E8_s {
    u8 pad0[8];
    struct func_151671E8_s *unk8;
};

void func_151671E8(void) {
    s32 i;
    s32 j;
    struct func_151671E8_s *p;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 101; j++) {
            if (*(void **) ((u8 *) &D_8008B4A8[j] + 4) != NULL) {
                p = ((struct func_151671E8_s *(*)[0x68]) D_800DCE50)[i][j];
                D_800DD190++;
                while (p != NULL) {
                    ((struct func_151671E8_s **) D_800DD198)[D_800DD190] = p->unk8;
                    (*(void (**)(void *)) ((u8 *) &D_8008B4A8[j] + 4))(p);
                    p = ((struct func_151671E8_s **) D_800DD198)[D_800DD190];
                }
                D_800DD190--;
            }
        }
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167310.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_151674F8.s")
void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void *v0 = func_10003C6C(arg2, 1, arg3, 0, (u8) arg5);

    if (v0 != 0) {
        *((u8 *) v0 + 1) = (u8) arg1;
        func_15168A4C(v0, arg0);
        *((u8 *) v0 + 0xC) = arg4;
    }
    return v0;
}
void func_15167AD8(void *arg0, u8 arg1, s32 arg2) {
    void *v0 = func_15167A68(3, arg2, 0x28, 0, arg1, 1);

    if (v0 != 0) {
        bcopy(arg0, (char *) v0 + 0x10, 0x18);
        *((u8 *) v0 + 0x23) = 0xFF;
    }
}
// NON-MATCHING: dispatches through D_8008CA20[arg0->unk24] if
// nonzero, then updates a timer pair (unk14/unk16, an accumulator and
// its per-tick delta) gated on arg0->unk22's sign, comparing against
// a byte fetched through arg0->unk10, and finally notifies
// func_1516972C if the post-update accumulator (divided by 256, i.e.
// its high byte) reaches that same threshold byte.
// void func_15167B44(void *arg0) {
//     u8 dispatch = *(u8 *) ((char *) arg0 + 0x24);
//     s8 v1;
//
//     if (dispatch != 0) {
//         D_8008CA20[dispatch](arg0);
//     }
//
//     v1 = *(s8 *) ((char *) arg0 + 0x22);
//
//     if (v1 > 0) {
//         u8 v0 = *(u8 *) ((char *) arg0 + 0x23);
//         if (v1 < v0) {
//             *(u8 *) ((char *) arg0 + 0x23) = v0 - v1;
//         } else {
//             u8 otherByte = *(u8 *) (*(char **) ((char *) arg0 + 0x10) + 4);
//             *(s16 *) ((char *) arg0 + 0x14) = otherByte << 8;
//         }
//     } else if (v1 < 0) {
//         s16 a2 = *(s16 *) ((char *) arg0 + 0x14);
//         u8 t4 = *(u8 *) (*(char **) ((char *) arg0 + 0x10) + 4);
//         s32 t2 = a2 / 256;
//
//         if (t2 >= t4 - 1) {
//             u8 v0b = *(u8 *) ((char *) arg0 + 0x23);
//             s32 a1 = -v1;
//             if (a1 < v0b) {
//                 *(u8 *) ((char *) arg0 + 0x23) = v0b - a1;
//                 *(s16 *) ((char *) arg0 + 0x14) = a2 - *(s16 *) ((char *) arg0 + 0x16);
//             }
//         }
//     }
//
//     *(s16 *) ((char *) arg0 + 0x14) += *(s16 *) ((char *) arg0 + 0x16);
//     {
//         s16 t3 = *(s16 *) ((char *) arg0 + 0x14);
//         u8 t5 = *(u8 *) (*(char **) ((char *) arg0 + 0x10) + 4);
//         s32 t4b = t3 / 256;
//
//         if (t4b >= t5) {
//             func_1516972C(arg0);
//         }
//     }
// }
// 70 vs target's 69 instructions - off by one, with every section
// (the dispatch call, the branch tree, and the shared tail)
// independently matching target's instruction count exactly and
// every register playing the same role under consistent renaming.
// Two fixes got it this close: reading arg0->unk22 AFTER the dispatch
// call rather than before (reading it early forced it to be spilled
// across the call, costing 2 instructions target doesn't spend), and
// writing the `-v1 < v0b` comparison as plain signed s32 arithmetic
// rather than an explicit `s8`-then-`(u8)` round trip (which added
// spurious sign-extend/mask instructions and, separately, flipped the
// comparison to an unsigned `sltu` where target uses signed `slt`).
// The `/ 256` divisions correctly reproduce target's sign-correcting
// shift-by-8 idiom (IDO's standard lowering for signed division by a
// power of two) without writing the shift out by hand.
extern void (*D_8008CA20[])(void *);

struct func_15167B44_s {
    u8 pad0[0x10];
    u8 *unk10;
    s16 unk14;
    s16 unk16;
    u8 pad18[0x22 - 0x18];
    s8 unk22;
    u8 unk23;
    u8 unk24;
};

void func_15167B44(struct func_15167B44_s *arg0) {
    s8 v1;
    s32 neg;

    if (arg0->unk24 != 0) {
        D_8008CA20[arg0->unk24](arg0);
    }
    v1 = arg0->unk22;
    if (v1 > 0) {
        if (v1 < arg0->unk23) {
            arg0->unk23 -= v1;
        } else {
            arg0->unk14 = arg0->unk10[4] << 8;
        }
    } else if (v1 < 0) {
        neg = -v1;
        if (arg0->unk14 / 256 >= arg0->unk10[4] - 1) {
            if (neg < arg0->unk23) {
                arg0->unk23 -= neg;
                arg0->unk14 -= arg0->unk16;
            }
        }
    }
    arg0->unk14 += arg0->unk16;
    if (arg0->unk14 / 256 >= arg0->unk10[4]) {
        func_1516972C((struct102 *) arg0);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167C58.s")
void *func_15167D84(void *arg0, s32 arg1, s32 arg2, s8 arg3, u8 arg4, s32 arg5) {
    void *v1;
    s32 type;

    if (arg1 == 0) {
        type = 5;
    } else {
        type = 0x42;
    }
    v1 = func_15167A68(type, arg5, arg2 + 0x50, 0, arg4, 1);

    if (v1 == 0) {
        return v1;
    }
    bcopy(arg0, (char *) v1 + 0x10, 0x38);
    *((s8 *) v1 + 0x48) = arg3;
    return v1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167E0C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168118.s")
extern u16 *D_8008CA4C[];

struct func_1516865C_s {
    struct {
        s16 ob[3];
        u16 flag;
        s16 tc[2];
        u8 cn[4];
    } v[8];
    s16 unk80[4];
    s16 unk88;
    s16 unk8A[7];
    u16 unk98;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    u8 unkA0;
};

void func_1516865C(struct func_1516865C_s *arg0, u8 r, u8 g, u8 b, u8 a) {
    s32 i;
    s16 t1;
    s16 v0;
    s16 t2;
    s16 v1;

    v0 = 0x2000;
    v1 = (D_8008CA4C[arg0->unkA0][4] + 0x100) << 5;
    t1 = 0x2000;
    t2 = (D_8008CA4C[arg0->unkA0][3] + 0x100) << 5;
    for (i = 0; i < 2; i++) {
        arg0->v[i * 4 + 1].flag = 0;
        arg0->v[i * 4 + 1].cn[0] = r;
        arg0->v[i * 4 + 1].cn[1] = g;
        arg0->v[i * 4 + 1].cn[2] = b;
        arg0->v[i * 4 + 1].cn[3] = a;
        arg0->v[i * 4 + 2].flag = 0;
        arg0->v[i * 4 + 2].cn[0] = r;
        arg0->v[i * 4 + 2].cn[1] = g;
        arg0->v[i * 4 + 2].cn[2] = b;
        arg0->v[i * 4 + 2].cn[3] = a;
        arg0->v[i * 4 + 3].flag = 0;
        arg0->v[i * 4 + 3].cn[0] = r;
        arg0->v[i * 4 + 3].cn[1] = g;
        arg0->v[i * 4 + 3].cn[2] = b;
        arg0->v[i * 4 + 3].cn[3] = a;
        arg0->v[i * 4 + 0].flag = 0;
        arg0->v[i * 4 + 0].cn[0] = r;
        arg0->v[i * 4 + 0].cn[1] = g;
        arg0->v[i * 4 + 0].cn[2] = b;
        arg0->v[i * 4 + 0].cn[3] = a;
    }
    if (arg0->unk98 & 0x80) {
        v1 = 0x2000;
        v0 = (D_8008CA4C[arg0->unkA0][4] + 0x100) << 5;
    }
    if (arg0->unk98 & 0x100) {
        t2 = 0x2000;
        t1 = (D_8008CA4C[arg0->unkA0][3] + 0x100) << 5;
    }
    arg0->v[6].tc[0] = t1;
    arg0->v[7].tc[1] = v0;
    arg0->v[7].tc[0] = t2;
    arg0->v[5].tc[1] = v1;
    arg0->unk88 = 0;
    arg0->unk9C = 0;
    arg0->unk9E = 0;
    arg0->v[1].tc[0] = arg0->v[5].tc[0] = arg0->v[2].tc[0] = arg0->v[6].tc[0];
    arg0->v[2].tc[1] = arg0->v[6].tc[1] = arg0->v[3].tc[1] = arg0->v[7].tc[1];
    arg0->v[0].tc[0] = arg0->v[4].tc[0] = arg0->v[3].tc[0] = arg0->v[7].tc[0];
    arg0->v[0].tc[1] = arg0->v[4].tc[1] = arg0->v[1].tc[1] = arg0->v[5].tc[1];
}
void *func_15168800(void *arg0, u8 arg1, s32 arg2) {
    void *v1 = func_15167A68(0xE, arg2, 0xB8, 1, arg1, 1);

    if (v1 == 0) {
        return 0;
    }
    bcopy(arg0, (char *) v1 + 0x10, 0xA8);
    return v1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168870.s")
void func_15168B10(s32 arg0, s32 arg1);

void func_15168A2C(s32 arg0) {
    func_15168B10(arg0, 0);
}
extern u8 D_800DCE50[];

// NON-MATCHING: mips_to_c reconstruction, hand-typed. A bucket-list
// insert: computes a slot in D_800DCE50 (stride 0x1A0, matching
// func_15168A9C's comment above) indexed by arg0->unk1 and arg1,
// splices arg0 onto the front of that slot's linked list (unk8=old
// head, old head->unk4=arg0), then sets arg0->unk0=arg1, arg0->unk4=0.
// Two things confirmed this round via isolated harness: (1) arg1 must
// be s32, not u8 - target has zero masking instructions for it, and
// the u8-typed version added an unwanted andi/move prologue; (2) the
// beqz's delay slot holds `arg0->unk8 = t0` unconditionally - writing
// that field *before* the `if` (not inside it) reproduces target's
// exact instruction sequence and branch shape byte-for-byte. The one
// remaining gap: target keeps the loaded slot value in $t0, this
// reconstruction lands it in $a2 in every variant tried (original,
// separate slot/t0 locals, swapped declaration order) - same
// stubborn-register-choice category as func_15168A9C above.
struct func_15168A4C_s {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    struct func_15168A4C_s *unk4;
    struct func_15168A4C_s *unk8;
};

int func_15168A4C(struct func_15168A4C_s *arg0, s32 arg1) {
    u8 unk1 = arg0->unk1;
    struct func_15168A4C_s **slot = &((struct func_15168A4C_s *(*)[0x68]) D_800DCE50)[unk1][arg1];

    arg0->unk8 = *slot;
    if (arg0->unk8 != 0) {
        arg0->unk8->unk4 = arg0;
    }
    arg0->unk0 = arg1;
    arg0->unk4 = 0;
    *slot = arg0;
}
// void func_15168A4C(void *arg0, s32 arg1) {
//     u8 unk1 = *((u8 *) arg0 + 1);
//     void **slot = (void **) (D_800DCE50 + unk1 * 0x1A0 + arg1 * 4);
//     void *t0 = *slot;
//
//     *(void **) ((char *) arg0 + 8) = t0;
//     if (t0 != 0) {
//         *(void **) ((char *) t0 + 4) = arg0;
//     }
//     *((u8 *) arg0 + 0) = arg1;
//     *(s32 *) ((char *) arg0 + 4) = 0;
//     *slot = arg0;
// }
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Unlinks arg0 from
// a doubly-linked bucket list (the same D_800DCE50 table func_15168A4C
// above inserts into). Target mixes all three branch types for its
// three guard checks (bnel, beql, beqz) - confirmed this round that a
// straightforward reconstruction (single reused local, redundant
// reload of it right after each if-body, matching the "delay slot
// filled with a value that's about to be redundantly reloaded anyway"
// pattern from func_1505DFDC/HANDOFF.md) reproduces ALL THREE branch
// types exactly, in the right positions. The only remaining gap:
// target keeps this reused local in $v0 throughout (it's also the
// return value, so needs no final move), while every source form
// tried here (original declaration order, swapping which of
// unk0/unk1 loads first, splitting into a separate short-lived local
// for the first check) lands it in $v1 instead, adding one extra
// "move v0,v1" before the final return that target doesn't have.
struct func_15168A9C_s {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    struct func_15168A9C_s *unk4;
    struct func_15168A9C_s *unk8;
};

void func_15168A9C(struct func_15168A9C_s *arg0) {
    struct func_15168A9C_s **slot;
    u8 unk1 = arg0->unk1;
    u8 unk0 = arg0->unk0;

    slot = &((struct func_15168A9C_s *(*)[0x68]) D_800DCE50)[unk1][unk0];
    if (arg0 == *slot) {
        *slot = arg0->unk8;
    }
    if (arg0->unk8 != 0) {
        arg0->unk8->unk4 = arg0->unk4;
    }
    if (arg0->unk4 != 0) {
        arg0->unk4->unk8 = arg0->unk8;
    }
}
// void *func_15168A9C(struct12 *arg0) {
//     void *temp_a1;
//     void *temp_v0;
//     void *temp_v0_2;
//
//     temp_a1 = (arg0->unk1 * 0x1A0) + (arg0->unk0 * 4) + 0x800DCE50;
//     if (arg0 == *temp_a1) {
//         *temp_a1 = (void *) arg0->unk8;
//     }
//     temp_v0_2 = arg0->unk8;
//     if (temp_v0_2 != 0) {
//         temp_v0_2->unk4 = (void *) arg0->unk4;
//     }
//     temp_v0 = arg0->unk4;
//     if (temp_v0 != 0) {
//         temp_v0->unk8 = (void *) arg0->unk8;
//     }
//     return temp_v0;
// }


void func_15168B10(s32 arg0, s32 arg1) {
    func_15168A9C(arg0);
    func_15168A4C(arg0, arg1);
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. A packed 32-bit
// field at arg0+0x14 holds a lo16 countdown and a hi16 counter. If the
// lo16 is nonzero, decrement it (clearing then re-OR-ing into the same
// word) and set arg0->unk38=30; otherwise compare arg0->unk3F against
// the hi16 and either subtract or zero arg0->unk38. Target genuinely
// stores arg0->unk14 TWICE in the decrement path (first with just the
// hi16 half preserved/lo16 cleared, then again with the new lo16
// OR'd in) - this reconstruction's identical two-statement form gets
// the first store dead-code-eliminated by IDO since nothing reads it
// before the second store overwrites it. Same "double-store to the
// same word" dead-store-elimination category noted in HANDOFF.md;
// unlike the struct-bundling fix documented there (which relies on an
// intervening external call to force conservatism), there's no call
// between these two stores to exploit here.
// NON-MATCHING (24 of 26 words): a countdown on the two 16-bit halves
// of the word at unk14.  If the low half is non-zero it is decremented
// and unk38 is set to 0x1E; otherwise the high half is subtracted from
// the byte at unk3F when it fits, setting unk38 to 0x1E, and unk38 is
// cleared when it does not.  The blocker is that target writes the
// unk14 word TWICE - once with the low half cleared, then again with
// the new value OR'd in - which is the signature of a bitfield
// assignment.  Written as two explicit statements IDO folds them into a
// single store at -O2.
//
// UPDATED: the bitfield theory is RULED OUT.  Declaring unk14 as
// `u32 hi : 16; u32 lo : 16;` makes IDO narrow both accesses to
// `lhu`/`sh` on the half-word, which is FURTHER from target than the
// raw word casts - 21 of 21 words differing rather than 24 of 26.
// Writing the second statement as `|=` so that it READS the field,
// which should keep the first store live, does not help either: IDO
// still folds the pair into one `sw`.  Whatever produces two stores to
// the same word here is neither a plain bitfield nor a
// read-modify-write.
// s32 func_15168B44(void *arg0) {
//     s32 v1;
//     s32 v0;
//
//     v1 = *(s32 *) ((char *) arg0 + 0x14);
//     if ((v1 & 0xFFFF) != 0) {
//         v0 = (v1 & 0xFFFF) - 1;
//         *(s32 *) ((char *) arg0 + 0x14) = v1 & 0xFFFF0000;
//         *(s32 *) ((char *) arg0 + 0x14) = (v1 & 0xFFFF0000) | (v0 & 0xFFFF);
//         *(s16 *) ((char *) arg0 + 0x38) = 0x1E;
//         return v0;
//     }
//     v0 = v1 >> 16;
//     if ((v0 & 0xFFFF) < *(u8 *) ((char *) arg0 + 0x3F)) {
//         *(u8 *) ((char *) arg0 + 0x3F) -= v0 & 0xFFFF;
//         *(s16 *) ((char *) arg0 + 0x38) = 0x1E;
//         return v0;
//     }
//     *(s16 *) ((char *) arg0 + 0x38) = 0;
//     return v0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168B44.s")
// void func_15168B44(void *arg0) {
//     s32 v1 = *(s32 *) ((char *) arg0 + 0x14);
//     u16 lo = v1 & 0xFFFF;
//
//     if (lo != 0) {
//         s32 hi_cleared = v1 & 0xFFFF0000;
//         u16 new_lo = (lo - 1) & 0xFFFF;
//
//         *(s32 *) ((char *) arg0 + 0x14) = hi_cleared;
//         *(u16 *) ((char *) arg0 + 0x38) = 30;
//         *(s32 *) ((char *) arg0 + 0x14) = hi_cleared | new_lo;
//         return;
//     }
//     {
//         u8 a2 = *((u8 *) arg0 + 0x3F);
//         u16 hi = (v1 >> 16) & 0xFFFF;
//
//         if (hi < a2) {
//             *((u8 *) arg0 + 0x3F) = a2 - hi;
//             *(u16 *) ((char *) arg0 + 0x38) = 30;
//         } else {
//             *(u16 *) ((char *) arg0 + 0x38) = 0;
//         }
//     }
// }
extern void (*D_8008CA20[])(void *);

void func_15168BAC(void *arg0) {
    u8 idx = *(u8 *)((char *) arg0 + 0xE4);
    if (idx != 0) {
        D_8008CA20[idx](arg0);
    }
}
void func_15168BE4(void *arg0, u8 arg1, s32 arg2) {
    if (*(s32 *) ((char *) arg0 + 0x40) != 0) {
        void *v0 = func_15167A68(0x10, arg2, 0xF0, 1, arg1, 1);
        if (v0 != 0) {
            bcopy(arg0, (char *) v0 + 0x90, 0x60);
        }
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168C4C.s")
void func_15168E34(s32 *arg0, s32 arg1) {
    if ((*arg0 & 0xF000000) == 0) {
        *arg0 = *arg0 + arg1;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168E54.s")
// NON-MATCHING: full semantics recovered and verified via isolated
// harness - walks an array of 8-byte records starting at arg0 until a
// record whose first byte (tag) is the sentinel -0x21; for each record
// whose tag is 1, or whose tag is -0x24 AND whose byte-at-offset-3 is
// 14, masks the s32 field at offset+4 to its low 24 bits and adds the
// original arg1 to it. Reached 30 of target's 31 instructions -
// getting the initial `*(s8*)arg0` sentinel check and the loop's own
// `*(s8*)arg0` re-read to compile as two genuine `lb` instructions
// (matching target's own redundant reload) instead of one load with a
// bogus 24-bit-round-trip re-sign-extension needed a `volatile` cast
// on the first read only. Register roles for the pointer/index/saved-
// arg1 locals are consistently permuted from target throughout
// (immune to every declaration order tried); the one true instruction
// gap is that target makes an explicit, seemingly gratuitous copy of
// arg1 into its own register before the loop even though arg1 is never
// otherwise written, while IDO here always coalesces the two since
// nothing forces them apart (forcing it via `volatile` instead spills
// the copy to a brand-new stack frame - target has no frame at all -
// which is far worse than the 1-instruction gap it was meant to fix).
// void func_15168F08(void *arg0, s32 arg1) {
//     char *cur = arg0;
//     s32 origArg1 = arg1;
//     s32 idx;
//     s8 tag;
//
//     if (*(volatile s8 *) arg0 == -0x21) {
//         return;
//     }
//
//     idx = 0;
//     tag = *(s8 *) arg0;
//     do {
//         idx++;
//         if (tag == 1 || (tag == -0x24 && *(u8 *) (cur + 3) == 14)) {
//             s32 v = *(s32 *) (cur + 4);
//             v = (v & 0x00FFFFFF) + origArg1;
//             *(s32 *) (cur + 4) = v;
//         }
//         cur = (char *) arg0 + (idx << 3);
//         tag = *(s8 *) cur;
//     } while (tag != -0x21);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168F08.s")
void func_15168F84(s32 arg0, s32 *arg1, s32 *arg2) {
    if (arg0 == 0) {
        *arg1 = 1;
        *arg2 = 0x41;
    } else if (arg0 == 1) {
        *arg1 = 0x42;
        *arg2 = 0x4F;
    } else if (arg0 == 2) {
        *arg1 = 0x50;
        *arg2 = 0x58;
    } else if (arg0 == 3) {
        *arg1 = 0x59;
        *arg2 = 0x5C;
    } else if (arg0 == 5) {
        *arg1 = 0x61;
        *arg2 = 0x63;
    } else if (arg0 == 6) {
        *arg1 = 0x64;
        *arg2 = 0x65;
    } else {
        *arg1 = 0x5D;
        *arg2 = 0x60;
    }
}
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Thin wrapper
// forwarding arg0/(u8)arg1 to func_15169070 with two fixed leading
// args. Target computes the `arg1 & 0xFF` mask directly from the
// incoming register (andi) before the call-setup instructions; every
// source form tried here (u8 parameter, s32 parameter with an explicit
// cast at the call site, s32 parameter assigned to a named u8 local)
// instead spills arg1 to its stack slot at entry and reloads it via lbu
// right before the call - same content, just 4/12 words in a different
// order/form.
// NON-MATCHING (4 of 12 words): semantics recovered - it is a thin
// wrapper, `func_15169070(0, 0x68, arg0, arg1);` with arg1 a u8.
// Target homes arg1 to its caller slot and then masks it straight out
// of the register (`andi $a3, $a1, 0xFF`); every spelling tried here
// (plain `arg1`, `arg1 & 0xFF`, an explicit `(s32)` cast) homes it and
// then reloads it with `lbu` from the home slot instead, which also
// shifts the argument-setup order. The four differing words are that
// reload plus the resulting reordering.
// void func_15169040(void *arg0, u8 arg1) {
//     func_15169070(0, 0x68, arg0, arg1);
// }
void func_15169070(s32, s32, void *, u8);

void func_15169040(void *arg0, u8 arg1) {
    func_15169070(0, 0x68, arg0, arg1);
}
// void func_15169040(void *arg0, u8 arg1) {
//     func_15169070(0, 0x68, arg0, arg1);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15169070.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15169260.s")
void func_1516968C(struct102 *arg0, u8 *arg1, u8 arg2);
void func_1516944C(s32 arg0, void *arg1, u8 arg2) {
    s32 i;
    struct102 *p;
    void (*fn)(struct102 *, void *, u8);

    if (arg0 >= 0x68) {
        arg0 = 0x67;
    }
    for (i = 0; i < 2; i++) {
        if (*(void **) ((u8 *) &D_8008B4A8[arg0] + 0x1C) != NULL) {
            p = ((struct102 *(*)[0x68]) D_800DCE50)[i][arg0];
            D_800DD190++;
            while (p != NULL) {
                ((struct102 **) D_800DD198)[D_800DD190] = ((struct102 **) p)[2];
                func_1516968C(p, (u8 *) arg1, arg2);
                (*(void (**)(struct102 *, void *, u8)) ((u8 *) &D_8008B4A8[arg0] + 0x1C))(p, arg1, arg2);
                p = ((struct102 **) D_800DD198)[D_800DD190];
            }
            D_800DD190--;
        } else {
            p = ((struct102 *(*)[0x68]) D_800DCE50)[i][arg0];
            D_800DD190++;
            while (p != NULL) {
                ((struct102 **) D_800DD198)[D_800DD190] = ((struct102 **) p)[2];
                func_1516968C(p, (u8 *) arg1, arg2);
                p = ((struct102 **) D_800DD198)[D_800DD190];
            }
            D_800DD190--;
        }
    }
}
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Bundles arg0 and
// its unique_id byte into a local struct (same pattern as
// func_150717E0 above, to keep the dead-looking byte write) and
// forwards it plus (u8)arg1 to func_15169040. Target masks arg1 to a
// byte as its very first operation, before touching arg0 at all
// (matching the standard "andi tN,argX,0xff; or argX,tN,zero" u8-param
// prologue seen in several already-confirmed functions this session);
// this reconstruction's source order (using arg0 first for the tmp
// struct) gets the masking deferred to immediately before the call
// instead - same content, different instruction order/count. Adding an
// explicit early-masked local didn't change the ordering, only grew
// the frame with an unused extra slot.
void func_151695F0(void *arg0, u8 arg1) {
    struct {
        void *f0;
        u8 f4;
    } sp18;

    sp18.f0 = arg0;
    sp18.f4 = *(u8 *) ((char *) arg0 + 0x3B);
    func_15169040(&sp18, arg1);
}
// void func_151695F0(struct127 *arg0, u8 arg1) {
//     struct {
//         struct127 *ptr;
//         u8 id;
//     } tmp;
//
//     tmp.ptr = arg0;
//     tmp.id = arg0->unique_id;
//     func_15169040(&tmp, arg1);
// }
// NON-MATCHING: how the u8 3rd argument gets masked before the tail call
// differs. Confirmed via func_151616D0 (src/game_18D770.c) - a sibling
// call site to the same func_1516944C - that func_1516962C's own arg0 is
// a plain s32 selector (not a pointer) and that the local struct's shape
// (void* at +0, u8 at +4) is specific to this call, not struct234 (which
// func_151616D0 uses instead: s8 at +0, s32 at +4 - same callee, two
// different struct shapes selected by arg0). Everything else reconstructs
// exactly: the void*+u8 local, the addr-of-local as the new arg1, and the
// arg1->unk3B byte forwarded into the local's 2nd field. Target masks arg2
// as literally its first two instructions (andi then move, right after
// the sp adjust, before even saving $ra) and keeps the pre-mask value's
// own argument-save store; this reconstruction's u8-typed parameter gets
// its raw argument-save store too, but the actual masked-value use at the
// call site compiles to a single late lbu reload from that save slot
// instead of an early andi+move pair - one fewer instruction overall (14
// vs target's 15). Tried: u8 vs s32 parameter type, an explicit early
// self-mask statement (arg2 &= 0xFF placed first), an inline (u8)/(s32)
// cast at the call site, and a separate named local for the masked value
// - each either lost the argument-save store entirely or kept the late
// lbu reload.
// void func_1516962C(s32 arg0, void *arg1, u8 arg2) {
//     struct {
//         void *ptr;
//         u8 flag;
//     } local;
//
//     local.ptr = arg1;
//     local.flag = arg1->unk3B;
//     func_1516944C(arg0, &local, arg2);
// }
void func_1516962C(s32 arg0, void *arg1, u8 arg2) {
    struct {
        void *ptr;
        u8 flag;
    } local;

    local.ptr = arg1;
    local.flag = *(u8 *) ((char *) arg1 + 0x3B);
    func_1516944C(arg0, &local, arg2);
}
extern u8 D_800D2DAB;

void *func_15169668(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800D2DAB = 1;
    return arg0;
}
void func_1516968C(struct102 *arg0, u8 *arg1, u8 arg2) {
    if ((arg2 == 0xF || arg2 == 0x10) && (*arg1 == *((u8 *) arg0 + 0xC))) {
        func_1516972C(arg0);
    }
}
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Scans D_800DD198
// (a "*4" raw-index array per this codebase's established convention for
// it) for an entry matching arg0, replacing it with arg0->unk8 - but
// arg0 here is an IMPLICIT passthrough (both existing call sites, inside
// func_1516972C below, call func_151696DC() with zero explicit
// arguments; a0 is whatever the caller's own first parameter happens to
// be). Declaring a real `arg0` parameter here conflicts with those
// existing zero-arg call sites (yacc stack overflow at parse time) -
// fixing it properly would mean also touching those call sites, which
// is riskier than a single-function revert.
void func_151696DC(arg0)
    s32 *arg0;
{
    s8 i;

    for (i = 0; i < D_800DD190; i++) {
        if (arg0 == ((s32 **) D_800DD198)[i]) {
            ((s32 **) D_800DD198)[i] = (s32 *) arg0[2];
        }
    }
}
// s32 func_151696DC(void *arg0) {
//     s8 v0 = 0;
//     void *elem;
//
//     if (D_800DD190 > 0) {
//         do {
//             elem = (v0 * 4) + D_800DD198;
//             v0++;
//             if (arg0 == *(void **) elem) {
//                 *(s32 *) elem = *(s32 *) ((char *) arg0 + 8);
//             }
//         } while (v0 < D_800DD190);
//     }
//     return v0;
// }

// Target never sets $v0: effectively void, but the K&R s32 declaration in
// functions.h is kept because some src/game callers read the result.
s32 func_1516972C(struct102 *arg0) {
    void (*func)(struct102 *arg0);
    func_151696DC();

    if (arg0->unk0 >= 2) {
        func = D_8008B4D0[arg0->unk0].unk0;
        if (func != NULL) {
            func(arg0);
            return;
        }
        func_15169804(arg0);
    }
}

void func_1516979C(struct102 *arg0) {
    void (*func)(struct102 *arg0);

    func_151696DC();
    func = D_8008B4D4[arg0->unk0].unk0;
    if (func != NULL) {
        func(arg0);
        return;
    }
    func_15169824(arg0);
}

void func_15169804(struct102 *arg0) {
    func_15168B10(arg0, 1);
}

void func_15169824(struct102 *arg0) {
    func_15168A9C(arg0);
    func_10004074(arg0);
}

// NON-MATCHING: same "cfg" merge pattern as func_150AEDF8/func_151419D0
// this session, but with a genuine 5th argument passed on the stack
// (confirmed both by the raw asm's `lw $a0, 0x28($sp)` - the standard
// o32 5th-stack-arg slot just above the 4-register save area - and by
// every real call site in the unlinked src/game/ draft tree, all of
// which pass 5 arguments in exactly this shape). The functions.h
// prototype was previously the K&R-style `void func_15169850();`,
// which conflicts with a `u8` 2nd parameter in the real definition
// (same class of implicit-declaration/real-definition mismatch fixed
// on func_15043BB8 earlier in this project) - given a full typed
// prototype here. 34 of 39 real instructions (ignoring the jal's
// embedded target) are byte-identical; the remaining gap is a single
// $v0/$v1 register-pair swap in the second guard's two loads/compares/
// store, cascading into 5 instruction encodings - tried reversed
// comparison operand order and explicit named locals for both loaded
// values (in both declaration orders), none matched target's pairing.
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15169850.s")
// void func_15169850(void *arg0, u8 arg1, void *arg2, void *arg3, void *arg4) {
//     if (arg1 == 0) {
//         if (*(s32 *) arg0 == *(s32 *) arg2 || *(u8 *) ((char *) arg0 + 4) == *(u8 *) arg3) {
//             func_1516972C(arg4);
//         }
//         return;
//     }
//     if (arg1 == 0x2D) {
//         if (*(s32 *) arg0 == *(s32 *) arg2) {
//             *(s32 *) arg2 = *(s32 *) ((char *) arg0 + 4);
//             *(u8 *) arg3 = *(u8 *) ((char *) arg0 + 9);
//             return;
//         }
//         if (*(s32 *) ((char *) arg0 + 4) == *(s32 *) arg2) {
//             *(s32 *) arg2 = *(s32 *) arg0;
//             *(u8 *) arg3 = *(u8 *) ((char *) arg0 + 8);
//         }
//     }
// }
