#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15134070.s")

s32 func_1513416C(struct102 *arg0) {
    s16 temp_v0 = arg0->unk1C;
    if (temp_v0 < 32) {
        arg0->unk28 = temp_v0 * 8;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513418C.s")
// void *func_1513418C(s32 arg0, s32 arg1 /* size/offset */, u8 arg2, s32 arg3) {
//     void *sp24;
//     s32 temp_v1;
//     u8 temp_a0;
//     void *temp_ret;
//     void *temp_v0;
//     struct127 *temp_v0_2;
//
//     temp_ret = func_15167A68(0x28, arg3, arg1 + 0x58, 1, arg2, 1);
//     temp_v0 = temp_ret;
//     if (temp_v0 == 0) {
//         return NULL;
//     }
//     sp24 = temp_v0;
//     memcpy(&temp_v0->unk10, arg0, 0x30); //, temp_v0);
//     temp_a0 = temp_v0->unk3A;
//     if ((temp_a0 & 2) != 0) {
//         temp_v0_2 = temp_v0->unk1C;
//         if ((temp_v0_2->unk0 == 0) || (temp_v0->unk18 != temp_v0_2->unk3B)) {
//             func_1516972C(temp_v0);
//             return NULL;
//         }
//         temp_v1 = temp_v0_2->unk1D4;
//         if ((temp_v1 != 0) && ((temp_v0_2->unk74 & 0xF) != 0xF)) {
//             sp24 = temp_v0;
//             func_15143134(temp_v0->unk24, temp_v0->unk40, temp_v1 + (temp_v0->unk20 << 6), temp_v0);
//         } else {
//             temp_v0->unk3A = (u8) (temp_a0 | 8);
//         }
//     } else {
//         temp_v0->unk3A = (u8) (temp_a0 | 0x18);
//     }
//     temp_ret->unk50 = 0.0f;
//     temp_ret->unk4C = (f32) (1.0f / (2.0f * temp_ret->unk30));
//     return temp_ret;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_151342BC.s")

s32 func_151346D0(s32 arg0, struct102 *arg1, s32 arg2) {
    arg1->unk3A &= 0xFFEF;
    return arg0;
}

void func_151346EC(struct102 *arg0) {
    func_15169804(arg0);
}

void func_1513470C(struct102 *arg0) {
    func_15169824(arg0);
}

void func_1513472C(struct102 *arg0) {
    s32 idx = arg0->unk3D;
    if (idx < 0) {
        idx = 0;
    }
    if (idx >= 10) {
        idx = 0;
    }
    D_80089AAC[idx]();
}

void func_1513477C(struct102 *arg0) {
  s32 idx = arg0->unk3D;
  if (idx < 0) {
      idx = 0;
  }
  if (idx >= 10) {
      idx = 0;
  }
    D_80089AD4[idx]();
}

// NON-MATCHING: exact 73/73 instruction match, byte-identical at the
// real linked address except the 3 jal target placeholders (resolves
// once project-wide drift reaches zero) - an isolated single-file
// compile shows a handful of pure register-renaming diffs on top of
// that, but those vanish once actually linked into the project, so
// treat the isolated-harness numbers as pessimistic here. A 5-way
// dispatch on
// arg2's low byte - branch-chain compiled by target (not a jump
// table; writing this as a C switch DOES provoke a jump table here,
// so it must stay an if/else-if chain). Cases 0 and 3 share a body:
// compares arg0's unk1C (raw s32 cast - structs.h currently declares
// this s16, conflicting with the full-word read/write this function
// does; other real code in this file only ever reads it as s16, so
// the field is left un-renamed and accessed via a raw offset cast
// here rather than widening the shared struct) against arg1->unk0,
// OR'd with a byte compare between arg0->unk18 and arg1->unk4's byte
// view (struct223's union), calling the same func_1516972C(arg0)
// notify seen in the analogous near-miss func_151D2E5C just above in
// this file (same struct16/struct223 pair, same pattern, different
// field offsets - 0x1C/0x18 here vs 0x10/0x14 there). Case 0x11
// additionally gates on arg0->unk3D == 5 first. Case 0x16 compares
// arg1 itself (the pointer) against arg0's unk1C. Case 0x2D splices
// arg1 into arg0's unk1C/unk18 pair depending on which side matches.
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_151347CC.s")
// void func_151347CC(struct102 *arg0, struct223 *arg1, u8 arg2) {
//     s32 temp_v0;
//
//     if (arg2 == 0 || arg2 == 3) {
//         temp_v0 = *(s32 *) ((char *) arg0 + 0x1C);
//         if ((temp_v0 == arg1->unk0) || (arg1->unk4.ub == arg0->unk18)) {
//             func_1516972C(arg0);
//         }
//     } else if (arg2 == 0x11) {
//         if (arg0->unk3D == 5) {
//             temp_v0 = *(s32 *) ((char *) arg0 + 0x1C);
//             if ((temp_v0 == arg1->unk0) || (arg1->unk4.ub == arg0->unk18)) {
//                 func_1516972C(arg0);
//             }
//         }
//     } else if (arg2 == 0x16) {
//         if ((s32) arg1 == *(s32 *) ((char *) arg0 + 0x1C)) {
//             func_1516972C(arg0);
//         }
//     } else if (arg2 == 0x2D) {
//         temp_v0 = arg1->unk0;
//         if (temp_v0 == *(s32 *) ((char *) arg0 + 0x1C)) {
//             *(s32 *) ((char *) arg0 + 0x1C) = arg1->unk4.w;
//             arg0->unk18 = arg1->unk9;
//         } else if (arg1->unk4.w == *(s32 *) ((char *) arg0 + 0x1C)) {
//             *(s32 *) ((char *) arg0 + 0x1C) = temp_v0;
//             arg0->unk18 = arg1->unk8;
//         }
//     }
// }

void func_151348F0(f32 arg0, f32 arg1, s32 arg2, s32 arg3) {
}

// NON-MATCHING: full semantics recovered and verified via isolated
// harness. arg0 points to the same anonymous 0x1C-byte "template"
// struct literal-constructed by func_15136A50 in this file (f0/f4/f8
// s32, fC/f10 f32, f14 s16, f16/f17/f18 u8, f19 s8) - sets its unk16
// flags byte's bit 1, then relays type=0x2A plus its own arg1/arg2/
// arg3 into the already-real func_15167A68(s32,s32,s32,s32,u8,s32)
// (confirmed via its real prototype in game_1944C0.c and matching
// call shapes in game_18D770.c/game_1FFF60.c/game_169510.c). On
// success, memcpy's the template's 0x1C bytes into the new object at
// +0x10, then treats the first 3 copied words as f32 pointers,
// dereferences each into +0x2C/+0x30/+0x34, zeroes +0x3C, and stores
// 1/(2*copied_+0x1C_value) at +0x38 - looks like resolving a
// deferred-reference plane/axis setup (unk10/14/18 as pointers to
// caller-owned floats, resolved once into the object's own storage).
// 50 vs target's 50 instructions - branch structure, every store
// offset, and even 5 individual instructions (the guard/memcpy/
// prologue portion and 2 of the tail float stores) are byte-identical
// once the tail computation's statement order was rewritten to mirror
// target's exact load-then-defer-dereference interleaving (read t0,
// read t1, read the scale field, square it, store *t0, THEN read t2,
// compute the reciprocal, store *t1, zero +0x3C, store *t2, store the
// reciprocal last). What remains is pure float-register-numbering
// (target's $f0/$f4/$f6/$f8/$f10/$f16/$f18 vs whichever temps this
// compile picks) on instructions whose ORDER and OFFSETS already
// match exactly - the same "immune to restructuring" register-choice
// class documented elsewhere in this project.
// void *func_15134908(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
//     void *v1;
//     u8 flags;
//     void *v0;
//     f32 *t0;
//     f32 *t1;
//     f32 *t2;
//     f32 half;
//     f32 scale;
//
//     v1 = func_15167A68(0x2A, arg3, arg1 + 0x40, 1, (u8) arg2, 1);
//     if (v1 == 0) {
//         return 0;
//     }
//
//     flags = *((u8 *) arg0 + 0x16);
//     *((u8 *) arg0 + 0x16) = flags | 2;
//     memcpy((char *) v1 + 0x10, arg0, 0x1C);
//
//     v0 = v1;
//     t0 = *(f32 **) ((char *) v0 + 0x10);
//     t1 = *(f32 **) ((char *) v0 + 0x14);
//     half = *(f32 *) ((char *) v0 + 0x1C);
//     half = half + half;
//     *(f32 *) ((char *) v0 + 0x2C) = *t0;
//     t2 = *(f32 **) ((char *) v0 + 0x18);
//     scale = 1.0f / half;
//     *(f32 *) ((char *) v0 + 0x30) = *t1;
//     *(f32 *) ((char *) v0 + 0x3C) = 0.0f;
//     *(f32 *) ((char *) v0 + 0x34) = *t2;
//     *(f32 *) ((char *) v0 + 0x38) = scale;
//     return v1;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15134908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_151349D0.s")

void func_15134C98(struct102 *arg0, void *arg1, u8 arg2) {
    if (arg0->unk28 == 1) {
        func_151BC5A4(arg0, arg1, arg2);
    }
}
// NON-MATCHING: semantically correct and same compiled size (0x38 bytes),
// but IDO -O2 orders the ra/a2 prologue stores and the arg2-mask timing
// differently than target for every source variation tried (direct
// forward, redundant temp, s32-typed arg2 with explicit (u8) cast at the
// call site, hoisting the arg0->unk28 condition into a temp first).
// void func_15134C98(struct102 *arg0, void *arg1, u8 arg2) {
//     if (arg0->unk28 == 1) {
//         func_151BC5A4(arg0, arg1, arg2);
//     }
// }

void func_15134CD4(f32 arg0, f32 arg1, s32 arg2, s32 arg3) {
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Struct unidentified
// here - raw offset casts. Integrates two velocity fields into two
// position fields using the global timestep, fails (returns 0) if
// position unk14 exceeds 130.0, then decrements a counter and fails if
// it goes negative. Content and order are otherwise close (reading
// unk2E early, before the float math, matches target's instruction
// interleaving) but target's final decrement-and-check uses a
// branch-likely (bgezl) that this reconstruction doesn't reproduce -
// same unresolved category as func_15144B68 above.
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15134CEC.s")
// s32 func_15134CEC(void *arg0) {
//     s32 v1 = *((u8 *) arg0 + 0x2E);
//
//     *(f32 *) ((char *) arg0 + 0x70) += 0.125f * D_800BE9A4;
//     *(f32 *) ((char *) arg0 + 0x74) += D_800A45B0 * D_800BE9A4;
//     *(f32 *) ((char *) arg0 + 0x14) += *(f32 *) ((char *) arg0 + 0x70) * D_800BE9A4;
//     *(f32 *) ((char *) arg0 + 0x1C) += *(f32 *) ((char *) arg0 + 0x74) * D_800BE9A4;
//     if (*(f32 *) ((char *) arg0 + 0x14) > 130.0f) {
//         return 0;
//     }
//     v1 = v1 - D_800BE9E4 * 2;
//     *((u8 *) arg0 + 0x2E) = v1;
//     if (v1 < 0) {
//         return 0;
//     }
//     return 1;
// }

// NON-MATCHING: single-register gap only - 1 instruction out of 31
// differs, everything else (both branch guards, the memcpy call and
// its exact v1-spill stack offset, every subsequent field store and
// its order) verified instruction-for-instruction identical. Target
// loads arg0->unk28 (a s16 field) into $t9 right before negating it
// into $t0; every C form tried here (inline cast, a named "field28"
// intermediate, a (s16*) array-index cast, declaring the negation
// result before vs after the func_15167A68 call) puts that same load
// in $a0 instead - a spurious reuse of the function's own (long-dead
// at this point) first parameter register that never happens in
// target.
// void *func_15134DAC(void *arg0, s32 arg1) {
//     void *v1 = func_15167A68(0x29, 0, arg1 + 0x80, 1, 0xFF, 1);
//
//     if (v1 == 0) {
//         return v1;
//     }
//     memcpy((char *) v1 + 0x18, arg0, 0x3C);
//     *(s32 *) ((char *) v1 + 0x10) = 1;
//     *(s16 *) ((char *) v1 + 0x54) = -*(s16 *) ((char *) arg0 + 0x28);
//     *(s32 *) ((char *) v1 + 0x14) = 0;
//     *(f32 *) ((char *) v1 + 0x70) = 0.0f;
//     *(f32 *) ((char *) v1 + 0x74) = 0.0f;
//     *(f32 *) ((char *) v1 + 0x78) = 0.0f;
//     return v1;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15134DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15134E48.s")

void func_151352EC(struct102 *arg0) {
    func_15169804(arg0);
}

void func_1513530C(struct102 *arg0) {
    func_15169824(arg0);
}

// NON-MATCHING: semantics fully recovered and verified via isolated
// harness - dispatches through D_80089B70[idx](arg0), where idx is
// arg0->unk50 (u8) clamped to 0 if it's >= 6, first notifying
// func_100111C8 and clearing arg0->unk44 (u16) if it was non-zero.
// Yet another instance of the "unsigned byte tested as if signed"
// dead-branch family already seen 3 times this session
// (func_1506196C/func_150AED9C/func_150C251C) - target's clamp check
// decomposes into a genuinely-dead `bgez` (the lbu-loaded byte can
// never be negative) followed by the real `< 6` test, whereas every
// phrasing tried here (single `>= 6` guard, explicit `>= 0 && < 6`
// compound) either drops the dead check entirely or reproduces it with
// extra/wrong-polarity instructions. Splitting the clamped value into
// its own s32 `idx` (rather than reusing the byte-sized `v0`) did fix
// the cross-call spill from byte-sized to the correct word-sized
// sw/lw - closest variant is 30 instructions vs target's 31.
// void func_1513532C(void *arg0) {
//     void *a1 = arg0;
//     s8 v0 = *(u8 *) ((char *) a1 + 0x50);
//     s32 idx;
//     u16 val44;
//
//     if (v0 >= 6) {
//         idx = 0;
//     } else {
//         idx = v0;
//     }
//     val44 = *(u16 *) ((char *) a1 + 0x44);
//
//     if (val44 != 0) {
//         func_100111C8(val44);
//         *(u16 *) ((char *) a1 + 0x44) = 0;
//     }
//
//     D_80089B70[idx](a1);
// }
extern void (*D_80089B70[])(void *);

struct func_1513532C_s {
    u8 pad0[0x44];
    u16 unk44;
    u8 pad46[0xA];
    u8 unk50;
};

void func_1513532C(struct func_1513532C_s *arg0) {
    u16 val;
    s32 idx = arg0->unk50;

    if (idx < 0) {
        idx = 0;
    } else if (idx >= 6) {
        idx = 0;
    }
    val = arg0->unk44;
    if (val != 0) {
        func_100111C8(val);
        arg0->unk44 = 0;
    }
    D_80089B70[idx](arg0);
}

// NON-MATCHING: identical shape to func_1513532C above, just
// dispatching through D_80089B88 instead of D_80089B70 - same
// dead-branch family, same 30-vs-31-instruction gap.
// void func_151353A8(void *arg0) {
//     void *a1 = arg0;
//     s8 v0 = *(u8 *) ((char *) a1 + 0x50);
//     s32 idx;
//     u16 val44;
//
//     if (v0 >= 6) {
//         idx = 0;
//     } else {
//         idx = v0;
//     }
//     val44 = *(u16 *) ((char *) a1 + 0x44);
//
//     if (val44 != 0) {
//         func_100111C8(val44);
//         *(u16 *) ((char *) a1 + 0x44) = 0;
//     }
//
//     D_80089B88[idx](a1);
// }
extern void (*D_80089B88[])(void *);

void func_151353A8(void *arg0) {
    void *a1 = arg0;
    s32 idx = *(u8 *) ((char *) a1 + 0x50);

    if (idx < 0) {
        idx = 0;
    } else if (idx >= 6) {
        idx = 0;
    }
    if (*(u16 *) ((char *) a1 + 0x44) != 0) {
        func_100111C8(*(u16 *) ((char *) a1 + 0x44));
        *(u16 *) ((char *) a1 + 0x44) = 0;
    }
    D_80089B88[idx](a1);
}

void func_15135424(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 local1[2];
    s32 local2[2];

    local1[0] = arg1;
    local1[1] = arg2;
    local2[0] = arg3;
    local2[1] = arg4;
    func_15145EA4(local1, local2, arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15135480.s")

void func_1513555C(void *arg0, void *arg1, u8 arg2) {
    if (arg2 == 0 || arg2 == 0x12) {
        if (*(s32 *) arg1 == *(s32 *) ((char *) arg0 + 0x1C) || *((u8 *) arg1 + 4) == *((u8 *) arg0 + 0x18)) {
            func_1516972C((struct102 *) arg0);
        }
    }
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Sibling of
// func_1513555C above (same id/unique_id match guard on *arg1 vs arg0),
// but dispatches on arg2==0 (call func_1516972C) vs arg2==3 (clear bit
// 0 of arg0->unk10) separately instead of merging both trigger values
// into one action. Written as a switch (an if/else chain merges the two
// cases into an inverted single test that doesn't match), which gets
// the branch structure and almost the whole function right except one
// spot: target has a genuinely duplicated `sw` for the arg2==3 write
// (the `and` that computes the new value is shared/computed once, but
// the store appears twice, once per incoming control-flow edge into
// that point) - a merged `||` condition produces the store once (39/40
// instructions - missing the duplicate), while splitting it into an
// explicit if/else duplicates BOTH the `and` and the `sw` (44/40
// instructions - too much). Couldn't find a source form that
// duplicates only the store.
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_151355B8.s")
// void func_151355B8(void *arg0, void *arg1, u8 arg2) {
//     switch (arg2) {
//         case 0:
//             if (*(s32 *) arg1 == *(s32 *) ((char *) arg0 + 0x1C) || *((u8 *) arg1 + 4) == *((u8 *) arg0 + 0x18)) {
//                 func_1516972C((struct102 *) arg0);
//             }
//             break;
//         case 3:
//             if (*(s32 *) arg1 == *(s32 *) ((char *) arg0 + 0x1C) || *((u8 *) arg1 + 4) == *((u8 *) arg0 + 0x18)) {
//                 *(s32 *) ((char *) arg0 + 0x10) &= ~1;
//             }
//             break;
//     }
// }

s32 func_15135658(void *arg0) {
    *(f32 *) ((char *) arg0 + 0x74) = 1.0f;
    return 1;
}

f32 bloodEffectPower_15135670(s32 arg0) {
    // "power", "../Effects/Blood/blood.c"
    return func_151422DC(0, D_800A3FB4, 0, 2000, 1000, D_800A3FBC, 2938) * D_800A45B4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_151356D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15135BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15135DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15136404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15136698.s")

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Sibling of
// func_1513F6E8 above (same arg0->unk2C/unk30 += arg0->unk128 *
// D_800BE9A4 tail), gated by a clamp check on arg0->unk1C/unk5C first.
s32 func_151368A8(struct210 *arg0) {
    f32 *ptr = &arg0->unk128;
    s16 v0 = arg0->unk1C;

    if (v0 < 0x20) {
        s32 v1 = v0 * 8;
        if (v1 < arg0->unk5C) {
            arg0->unk5C = v1;
        }
    }
    arg0->unk2C += *ptr * D_800BE9A4;
    arg0->unk30 += *ptr * D_800BE9A4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15136918.s")

s32 func_15136A1C(struct102 *arg0) {
    s32 v1;

    if (arg0->unk1C < 0x20) {
        v1 = arg0->unk1C * 8;
        if (v1 < arg0->unk28) {
            arg0->unk28 = v1;
        }
    }
    return 1;
}

void func_15136A50(s32 arg0, s32 arg1, s32 arg2, s16 arg3, u8 arg4, s32 arg5) {
    struct {
        s32 f0; s32 f4; s32 f8; f32 fC; f32 f10; s16 f14;
        u8 f16; u8 f17; u8 f18; s8 f19;
    } local;
    local.f0 = arg0; local.f4 = arg1; local.f8 = arg2;
    local.fC = D_800A461C; local.f10 = D_800A4620;
    local.f14 = arg3;
    local.f16 = 5;
    local.f17 = 5;
    local.f18 = 2;
    local.f19 = -1;
    func_15134908(&local, 0, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15136AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15136C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15136F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15137610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513783C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15137C64.s")

// randomizes a timer/duration field (arg0->unk74) into roughly [580, 630),
// scaled by a global time factor. func_150ADA68 is a confirmed random-float-
// in-[0,1) generator (64-bit xorshift PRNG state at D_800885B0). Would-be
// name: setRandomTimer - not applied to the symbol because this function is
// referenced by name from asm/data/22E4E0.rodata.s, which is gitignored
// (regenerated by `make extract` from the ROM) and not committed, so a
// rename there wouldn't survive a fresh clone/re-extraction.
extern f32 D_800A4828;

s32 func_15137E10(void *arg0) {
    *(f32 *)((char *) arg0 + 0x74) = (func_150ADA68() * 50.0f + 580.0f) * D_800A4828;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15137E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15137F30.s")

// Struct unidentified here (sibling func_15137E10 above also uses raw
// casts) - raw offset casts. Fails if arg0->unk1D4 is 0, or if the low
// nibble of arg0->unk74 isn't 0xF; otherwise calls func_15143134 with a
// slot from D_800A3FD8 selected by arg1, arg2, arg0->unk1D4+0x300, and
// arg1 again.
s32 func_151380B4(void *arg0, s32 arg1, s32 arg2) {
    s32 v0 = *(s32 *) ((char *) arg0 + 0x1D4);

    if (v0 == 0) {
        return 0;
    }
    if ((*(u8 *) ((char *) arg0 + 0x74) & 0xF) == 0xF) {
        return 0;
    }
    func_15143134(D_800A3FD8 + arg1 * 16, arg2, v0 + 0x300, arg1);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15138120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_151382E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15138424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_151389A8.s")

// NON-MATCHING: state-transition coordinator built entirely from calls
// to sibling functions (func_15134070, func_151380B4 above, and the
// still-raw func_15138120/func_1504715C/func_151382E0/func_15138424) -
// gets a status code, bails early if it's 0x63, relays it through two
// more helpers with a pair of local scratch buffers (0x14 and 0x28
// bytes, matching target's own stack layout), then dispatches two more
// calls using arg1's low byte read twice (target itself reads this
// byte independently for each call - a genuine double-read, not a
// bug). 53 vs target's 48 instructions - the extra 5 come from IDO
// choosing to cache/spill the second `(u8) arg1` read across the
// intervening call (store+reload pair) instead of re-issuing target's
// second lbu directly, plus minor stack-frame sizing differences; both
// register-forcing tricks tried (reading via a volatile s32* then
// masking, and via a volatile u8* at a computed address) made it
// worse, so this is left as the closest natural form.
// s32 func_15138BC0(void *arg0, s32 arg1, s32 arg2) {
//     u8 buf50[0x14];
//     u8 buf28[0x28];
//     s32 status;
//     s32 result;
//     u8 savedByte;
//
//     status = func_15134070(arg0);
//     if (status == 0x63) {
//         return status;
//     }
//
//     savedByte = (u8) func_151380B4(arg0, status, (s32) buf50);
//     result = func_15138120(arg0, status, 1);
//     if (savedByte == 0) {
//         return result;
//     }
//
//     func_1504715C(buf28, arg0);
//     func_151382E0(buf50, status, buf28, (u8) arg1, arg2);
//     return func_15138424(arg0, buf50, status, buf28, (u8) arg1, arg2);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15138BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15138C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15138E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15139578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15139768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_15139D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513A24C.s")

// NON-MATCHING: builds the same kind of fixed-layout 0x3C-byte
// effect-params blob as func_1513A5E0 below (position copied from
// arg0, several hardcoded shorts and floats, plus
// D_800A4954/4958/495C/4950) and relays it into the same confirmed
// 8-arg func_15152190, this time alongside D_800A4260/D_800A4264.
// 64 vs target's 66 instructions - the identical 2-instruction gap
// func_1513A5E0 also lands at, with the same shape (target loads one
// of the float globals very early, right after the frame is
// allocated and before $ra is even saved; this reconstruction
// schedules it later) - looks like the same systematic near-miss
// inherent to this stack-blob-then-K&R-call pattern rather than
// anything fixable per-function.
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513A48C.s")
// void * func_15152190(); /* extern */
//
// void func_1513A48C(void *arg0, u8 arg1, s32 arg2) {
//     u8 buf[0x3C];
//     char *p = buf;
//
//     *(s32 *) (p + 0x0) = 8;
//     *(s32 *) (p + 0x4) = 4;
//     *(s32 *) (p + 0x8) = *(s32 *) arg0;
//     *(s32 *) (p + 0xC) = *(s32 *) ((char *) arg0 + 4);
//     *(s32 *) (p + 0x10) = *(s32 *) ((char *) arg0 + 8);
//     *(s16 *) (p + 0x14) = 0;
//     *(s16 *) (p + 0x16) = 0xFF;
//     *(s16 *) (p + 0x18) = -0x37;
//     *(s16 *) (p + 0x1A) = 0x20;
//     *(f32 *) (p + 0x1C) = 10.0f;
//     *(f32 *) (p + 0x20) = 9.0f;
//     *(f32 *) (p + 0x24) = D_800A4954;
//     *(f32 *) (p + 0x28) = D_800A4958;
//     *(s16 *) (p + 0x2C) = 0x28;
//     *(s16 *) (p + 0x2E) = 0x14;
//     *(f32 *) (p + 0x30) = D_800A4950;
//     *(f32 *) (p + 0x34) = D_800A4950;
//     *(f32 *) (p + 0x38) = D_800A495C;
//
//     func_15152190(buf, &D_800A4260, &D_800A4264, 1, 0, 1, arg1, arg2);
// }

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Two unresolved gaps:
// (1) target re-masks arg3 to u8 a second time at the func_1513A5E0 call
// site (andi a1,a3,0xff) even though it was already masked once in the
// prologue - every variation collapsed to a single mask, reused; (2) the
// arg0->unk1D4 check has a genuinely empty body in target (reads the field,
// branches, then falls through to the same epilogue either way) but IDO
// -O2 dead-code-eliminates the entire read+branch when the if-body is
// empty in source, unlike the tanf/func_151EF080 precedent where an empty
// body still got reproduced (that involved a real return, not a no-op).
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Two unresolved gaps:
// (1) target masks arg3 to u8 once in the prologue (spilled + andi) then
// re-masks it a second time at the func_1513A5E0 call site for the a1 slot
// (andi a1,a3,0xff) while implicitly forwarding the same masked value as
// a3 too - tried arg3 as u8 (single mask, reused, no re-mask), as s32 with
// one explicit (u8) cast (drops the prologue mask entirely, matches the
// call-site andi but not the early spill), and as s32 with two explicit
// (u8) casts (compiler switches to spilling+lbu instead of andi/move,
// worse). (2) the arg0->unk1D4 check has a genuinely empty body in target
// (reads the field, branches, falls through to the same epilogue either
// way) but IDO -O2 dead-code-eliminates the entire read+branch when the
// if-body is empty in source - unlike the tanf/func_151EF080 precedent
// (that involved a real return, not a no-op).
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513A594.s")
// void func_1513A594(struct127 *arg0, void *arg1, s32 arg2, u8 arg3, s32 arg4) {
//     func_1513A5E0(arg1, arg3, arg4);
//     if (arg0->unk1D4 != 0) {
//     }
// }

// NON-MATCHING: builds a fixed-layout 0x3C-byte effect-params blob on
// the stack (position copied from arg0, several hardcoded shorts and
// floats, plus D_800A4964/4968/496C/4960) and relays it into the
// confirmed 8-arg func_15152190 alongside D_800A4268/D_800A4270 and
// arg1/arg2. Declares the six previously-undocumented globals.
// void func_1513A5E0(void *arg0, u8 arg1, s32 arg2) {
//     u8 buf[0x3C];
//     char *p = buf;
//
//     *(s32 *) (p + 0x0) = 7;
//     *(s32 *) (p + 0x4) = 7;
//     *(s32 *) (p + 0x8) = *(s32 *) arg0;
//     *(s32 *) (p + 0xC) = *(s32 *) ((char *) arg0 + 4);
//     *(s32 *) (p + 0x10) = *(s32 *) ((char *) arg0 + 8);
//     *(s16 *) (p + 0x14) = 0;
//     *(s16 *) (p + 0x16) = 0xFF;
//     *(s16 *) (p + 0x18) = -0x32;
//     *(s16 *) (p + 0x1A) = 0x1B;
//     *(f32 *) (p + 0x1C) = 4.0f;
//     *(f32 *) (p + 0x20) = 4.0f;
//     *(f32 *) (p + 0x24) = D_800A4964;
//     *(f32 *) (p + 0x28) = D_800A4968;
//     *(s16 *) (p + 0x2C) = 0x19;
//     *(s16 *) (p + 0x2E) = 0x28;
//     *(f32 *) (p + 0x30) = D_800A4960;
//     *(f32 *) (p + 0x34) = D_800A4960;
//     *(f32 *) (p + 0x38) = D_800A496C;
//
//     func_15152190(buf, &D_800A4268, &D_800A4270, 2, 0, 1, arg1, arg2);
// }
// 62 vs target's 64 instructions. func_15152190 is a widely shared
// K&R-declared function (same class as func_1505E650) - passing its
// 5th argument as a literal `0.0f` triggers the K&R float-to-double
// promotion bug (compiles to an 8-byte `sdc1` instead of a 4-byte
// `swc1`, corrupting the rest of the stack-argument layout); passing
// the plain integer `0` instead (matching its real bit pattern
// without triggering promotion, since only genuine float/double
// values get promoted) fixed it.
#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513A5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513A6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513ABB8.s")

// Decrements a counter at arg0+0x170 when arg2==0x45, OR-ing a flag bit at
// arg0+0x60 if it goes negative. Target reads arg0+0x170 via plain `lw`
// (integer), which directly contradicts struct210's speculative `f32
// unk170` from the never-confirmed func_15141564 - used raw pointer casts
// here instead of asserting a struct210 field to avoid compounding that
// unresolved conflict. Matched by declaring the pointer UNCONDITIONALLY
// before the `if`, rather than inside it: IDO then folds the address
// computation into the branch's delay slot (matching target exactly)
// instead of recomputing/dropping it. See HANDOFF.md for the general
// pattern.
void func_1513B0B8(void *arg0, s32 arg1, u8 arg2) {
    s32 *p = (s32 *) ((char *) arg0 + 0x170);

    if (arg2 == 0x45) {
        *p -= 1;
        if (*p < 0) {
            *(s32 *) ((char *) arg0 + 0x60) |= 0x80;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_161520/func_1513B0F8.s")
