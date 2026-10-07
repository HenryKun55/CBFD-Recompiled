#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Sets arg2's unk40 flag word (OR'd with 0x40400000, the
// same bit pattern used as a literal float argument to func_1505E650
// elsewhere in this codebase - likely 3.0f packed into that field)
// and arg2's unk1 byte to 3, then relays most of its own 10
// parameters into func_1513D524 (already given a real prototype
// elsewhere - arg1 doing double duty as both the memcpy size below
// AND func_1513D524's 7th positional arg). If that returns non-NULL,
// memcpy's (arg0, arg1 bytes) into the result+0x110, zeroes a field at
// +0x154, writes arg7 to +0x169, and - matching this codebase's
// "recompute rather than trust a still-live register across a call"
// pattern - increments a global counter (D_800DC9F0) once more before
// returning the same pointer.
// 49 vs target's 53 instructions: every source form tried here
// collapses target's two distinct convergence points (an early-exit
// path with its own `b`/delay-slot pair, then a second merge after
// the increment check) into a single shared branch target, which is
// genuinely shorter/smarter rather than wrong - same "IDO elides a
// redundant jump my C didn't ask for" pattern as func_15104FF8 and
// func_15008870 earlier this session. The instructions present also
// show pure register-renaming (t6/t8/t9 vs t7/t8/t9 etc.) immune to
// restructuring, consistent with the same unresolved category
// documented elsewhere in this project.
// void *func_151407D0(void *arg0, s32 arg1, void *arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, s8 arg7, u8 arg8, s32 arg9) {
//     void *v0;
//
//     *(u32 *) ((char *) arg2 + 0x40) |= 0x40400000;
//     *(u8 *) ((char *) arg2 + 0x1) = 3;
//
//     v0 = func_1513D524((s32) arg2, arg3, arg4, arg5, 1, arg6, arg1, arg8, arg9);
//     if (v0 != 0) {
//         memcpy((char *) v0 + 0x110, arg0, arg1);
//         *(s32 *) ((char *) v0 + 0x154) = 0;
//         *(u8 *) ((char *) v0 + 0x169) = (u8) arg7;
//         if (v0 != 0) {
//             D_800DC9F0 += 1;
//         }
//     }
//     return v0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151407D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151408A4.s")

void func_151411A4(struct210 *arg0) {
    func_1513CA6C(arg0);
}

void func_151411C4(struct210 *arg0) {
    func_1513CAA0(arg0);
}

void func_151411E4(struct210 *arg0) {
    struct210 *obj;

    obj = arg0;
    if (*(volatile s32 *) ((char *) obj + 0x154) != 0) {
        func_1517E134(*(volatile s32 *) ((char *) obj + 0x154));
    }
    D_800DC9F0 -= 1;
    D_80089F9C[*(u8 *) ((char *) obj + 0x168)](obj);
}

void func_15141250(struct210 *arg0) {
    struct210 *obj;

    obj = arg0;
    if (*(volatile s32 *) ((char *) obj + 0x154) != 0) {
        func_1517E134(*(volatile s32 *) ((char *) obj + 0x154));
    }
    D_800DC9F0 -= 1;
    D_80089FE4[*(u8 *) ((char *) obj + 0x168)](obj);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151412BC.s")

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Copies (unk34,
// unk38, unk3C) into *unk154's (x, y, z) when unk154 is non-null. Target
// reads unk3C via lwc1 (as f32) but struct210's unk3C is already
// established as s32 elsewhere in this codebase - either arg0 isn't really
// struct210 here, or unk3C is a union of s32/f32 depending on caller;
// didn't resolve which this round, so raw f32 casts were used instead.
// Isolated via scratch harness this round: with `void *v0 = arg0+0x110;`
// as a raw-cast local declared unconditionally *before* the `if` (the
// usual intermediate-pointer-hoisting fix), IDO does keep `addiu
// v0,a0,0x110` materialized as a real register (rather than
// constant-folding it into direct `arg0+0x154` offsets, which happens
// if declared *inside* the if with no other use), but positions it
// *before* the guard branch instead of as the guard's first
// true-branch instruction, and reuses one register for all three
// `v0+0x44` reloads instead of target's three distinct temps
// (t7/t8/t9). Declaring the guard flag as a separate local read first
// (`s32 flag = arg0->unk154; ...; if (flag != 0) {...}`) does get IDO
// to schedule `addiu v0,a0,0x110` into the branch's own delay slot
// (better shape than target, which leaves that slot as `nop`) with
// three distinct destination registers for the reloads - but that's a
// 1-instruction-shorter function than target (IDO fills the slot
// target leaves empty), so still not byte-perfect. Whatever the real
// source form is, it must produce a "wasted" nop in the delay slot
// that these reconstructions won't reproduce.
struct func_1514143C_s { char pad[0x44]; f32 *p; };
void func_1514143C(struct210 *arg0) {
    struct func_1514143C_s *s;
    if (*(s32 *)((char *)arg0 + 0x154) != 0) {
L:
        s = (struct func_1514143C_s *)((char *)arg0 + 0x110);
        goto M;
M:
        s->p[0] = *(f32 *)((char *)arg0 + 0x34);
        s->p[1] = *(f32 *)((char *)arg0 + 0x38);
        s->p[2] = *(f32 *)((char *)arg0 + 0x3C);
    }
}
// void func_1514143C(struct210 *arg0) {
//     if (arg0->unk154 != 0) {
//         arg0->unk154->x = arg0->unk34;
//         arg0->unk154->y = arg0->unk38;
//         arg0->unk154->z = arg0->unk3C;
//     }
// }

s32 func_15141478(struct210 *arg0) {
    f32 *q = (f32 *)((char *)arg0 + 0x110);
    f32 *p = &arg0->unk170;

    arg0->unk180 -= D_800BE9A4;
    if (arg0->unk180 < 0.0f) {
        p[4] = p[5] * func_150ADA68();
        if (func_150ADA20() & 3) {
            p[3] = p[1] + (p[0] - p[1]) * func_150ADA68();
        } else {
            p[3] = p[0] + (p[2] - p[0]) * func_150ADA68();
        }
    }
    q[0x12] += (p[3] - q[0x12]) * p[6];
    return 1;
}

// NON-MATCHING (extremely close - 2 words off out of 28). Applying the
// func_1513B0B8 intermediate-pointer fix here (hoist `f32 *p =
// &arg0->unk170;` to the top, use p[0..3] consistently instead of direct
// arg0-> field access) plus reordering both additions as `mult_term +
// plain_term` (matching target's operand register order) gets the frame
// size (-0x28), EVERY individual instruction's content, and instruction
// order exactly right - except the `v1` spill/reload around the
// func_15144B68 call lands at sp+0x1C here vs target's sp+0x18. Tried 8+
// source variants (operand order in the add, operand order in the
// multiply, explicit named temps for the mult and/or sinf results,
// separate vs combined pointer-assignment statement); every variant that
// achieves the correct -0x28 frame size also lands the spill at 0x1C, and
// every variant that gets 0x18 regresses to a wrong (-0x20) frame size -
// the two seem coupled through some IDO register-allocation heuristic
// this session couldn't isolate further. Best candidate kept below for
// reference; not activated since it isn't byte-perfect.
s32 func_15141564(struct210 *arg0) {
    f32 *p = &arg0->unk170;
    f32 *q = p;

    arg0->unk158 = p[1] * sinf(arg0->unk178) + p[0];
    q[2] = q[3] * D_800BE9A4 + q[2];
    q[2] = func_15144B68(q[2]);
    return 1;
}
// s32 func_15141564(struct210 *arg0) {
//     f32 *p = &arg0->unk170;
//
//     arg0->unk158 = p[1] * sinf(arg0->unk178) + p[0];
//     p[2] = p[3] * D_800BE9A4 + p[2];
//     p[2] = func_15144B68(p[2]);
//     return 1;
// }

// NON-MATCHING: 4-way threshold interpolation into arg0->unk158
// based on where arg0->unk17C falls among unk180/unk184/unk188 (a
// piecewise ease-in/ease-out curve using unk170/unk174/unk178/unk190
// as the curve's endpoints/rate), then advances the phase unk17C by
// D_800BE9A4 and wraps it back down against unk18C in a do-while.
// Extends struct210 with five previously-undocumented trailing f32
// fields (unk180-unk190).
// s32 func_151415D4(struct210 *arg0) {
//     if (arg0->unk17C < arg0->unk180) {
//         arg0->unk158 = arg0->unk174;
//     } else if (arg0->unk17C < arg0->unk184) {
//         arg0->unk158 = arg0->unk174 + arg0->unk178 * ((arg0->unk17C - arg0->unk180) * arg0->unk190);
//     } else if (arg0->unk17C < arg0->unk188) {
//         arg0->unk158 = arg0->unk170;
//     } else {
//         arg0->unk158 = arg0->unk174 + arg0->unk178 * (1.0f - (arg0->unk17C - arg0->unk188) * arg0->unk190);
//     }
//
//     arg0->unk17C += D_800BE9A4;
//     if (arg0->unk18C < arg0->unk17C) {
//         do {
//             arg0->unk17C -= arg0->unk18C;
//         } while (arg0->unk18C < arg0->unk17C);
//     }
//
//     return 1;
// }
// 65 vs target's 69 instructions - smarter than target. Target keeps
// a pointer to arg0->unk170 in a register and addresses every field
// through it, re-reading several fields a second time rather than
// reusing an already-live value (the genuine double-read idiom,
// naturally reproduced here via direct struct field access without
// needing any special tricks); this reconstruction is a few
// instructions leaner overall, most likely from not needing the
// extra pointer-materialization step target's addressing style costs.
s32 func_151415D4(struct210 *arg0) {
    f32 *p = &arg0->unk170;
    f32 t;
    f32 m;

    if (arg0->unk17C < arg0->unk180) {
        arg0->unk158 = p[1];
    } else {
        if (p[3] < p[5]) {
            t = p[8] * (p[3] - p[4]);
            arg0->unk158 = p[2] * t + p[1];
        lbl:;
        } else {
            if (p[3] < p[6]) {
                arg0->unk158 = p[0];
            } else {
                t = 1.0f - p[8] * (p[3] - p[6]);
                arg0->unk158 = p[2] * t + p[1];
            }
        }
    }
    p[3] += D_800BE9A4;
    m = p[7];
    if (m < p[3]) {
        do {
            p[3] -= m;
        } while (m < p[3]);
    }
    return 1;
}

struct func_151416E8_sub {
    u8 pad0[0x58];
    u8 unk58;
    s8 unk59;
};

struct func_151416E8_s {
    u8 pad0[0x110];
    struct func_151416E8_sub unk110;
};

extern void (*D_8008A02C[])(struct func_151416E8_s *, u8 *, u8);

void func_151416E8(struct func_151416E8_s *arg0, u8 *arg1, u8 arg2) {
    struct func_151416E8_sub *sub = &arg0->unk110;

    if (D_8008A02C[sub->unk58] != NULL) {
        D_8008A02C[sub->unk58](arg0, arg1, arg2);
    }
    if ((arg2 != 0x22) && (arg2 != 0x24) && (arg2 != 0x25)) {
        return;
    }
    if (*arg1 != (*sub).unk58) {
        return;
    }
    switch (arg2) {
        case 0x22:
            func_1516972C((struct102 *)arg0);
            break;
        case 0x24:
            sub->unk59 = -1;
            break;
        case 0x25:
            sub->unk59 = 2;
            break;
    }
}

// ???
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Copies D_8008A074
// (s32[2]) into a stack-local, sets a stack-local byte to arg0's low byte,
// then calls func_15169260(&local1, 2, &local2, arg1). Target's actual
// register allocation is substantially different (loads both D_8008A074
// words into scratch registers first, spills them to different stack
// offsets, and computes the arg0-byte address differently) - this wasn't
// close enough to be a simple ordering tweak, needs a fresh look.
struct func_151417C4_s {
    s32 a[2];
};

void func_151417C4(u8 arg0, u8 arg1) {
    u8 local2[4];
    struct func_151417C4_s local1;

    local1 = *(struct func_151417C4_s *)D_8008A074;
    local2[0] = arg0;
    func_15169260(&local1, 2, local2, arg1);
}
// void func_151417C4(s32 arg0, u8 arg1) {
//     s32 local1[2];
//     u8 local2;
//
//     local1[0] = D_8008A074[0];
//     local1[1] = D_8008A074[1];
//     local2 = (u8) arg0;
//     func_15169260(local1, 2, &local2, arg1);
// }

s32 func_15141818(s32 arg0, s32 arg1) {
    return 0;
}

// NON-MATCHING: independently re-verified the stale reconstruction
// below (it's correct against the raw asm), but fixed its two type
// errors against the confirmed real caller's forward declaration
// (func_15141928 two functions below): the shared signature declares
// this `void`-returning with `s32 arg3` (not `f32`/non-void as the
// stale header claimed), even though arg3's raw bits are genuinely
// used as a float in the body - reinterpret-cast rather than retype,
// matching this codebase's established convention for exactly this
// caller/callee type-mismatch shape. The trailing "return temp_f0"
// in the original comment was also wrong for a void function - target
// just happens to still have arg0->unk34 sitting in $f0 at exit as a
// side effect of the computation, not a real return; the caller
// (func_15141928) never uses the value either way.
// void func_1514182C(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
//     f32 mtx[4][4];
//     f32 f0, f2, f12;
//     f32 realArg3 = *(f32 *) &arg3;
//
//     func_150A8050(&mtx, *(s32 *) &arg4, 0, *(s32 *) &arg5);
//
//     func_150A7960(&mtx, 0.0f, arg2, 0.0f,
//                   (f32 *) ((char *) arg0 + 0x34), (f32 *) ((char *) arg0 + 0x38), (f32 *) ((char *) arg0 + 0x3C));
//
//     f0 = *(f32 *) ((char *) arg0 + 0x34);
//     f2 = *(f32 *) ((char *) arg0 + 0x38);
//     f12 = *(f32 *) ((char *) arg0 + 0x3C);
//
//     *(f32 *) ((char *) arg0 + 0x40) = f0 + ((f0 - *(f32 *) arg1) * realArg3 * 500.0f);
//     *(f32 *) ((char *) arg0 + 0x44) = f2 + ((f2 - *(f32 *) ((char *) arg1 + 4)) * realArg3 * 500.0f);
//     *(f32 *) ((char *) arg0 + 0x48) = f12 + ((f12 - *(f32 *) ((char *) arg1 + 8)) * realArg3 * 500.0f);
// }
// 61 vs target's 63 instructions - smarter than target. Target
// rematerializes the 500.0f constant into three separate float
// registers (one per field's multiply) instead of reusing a single
// loaded copy across all three, a well-established "target
// redundantly recomputes a constant" gap seen throughout this
// project that hasn't proven reliably forceable via source
// restructuring.
#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_1514182C.s")

void func_1514182C(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);

s32 func_15141928(void *arg0) {
    void *v0 = *(void **) ((char *) arg0 + 0x178);

    func_1514182C(arg0, (char *) arg0 + 0x17C, *(s32 *) ((char *) arg0 + 0x170),
                  *(s32 *) ((char *) arg0 + 0x174), *(f32 *) v0, *(f32 *) ((char *) v0 + 8));
    return 1;
}
