#include <ultra64.h>

#include "functions.h"
#include "variables.h"

f32 random_float();                                /* extern */

u8 func_151D8E20(void) {
    if ((D_800BE9F0 == 0) && (func_150A29C8(0, 0x1C) == 0)) {
        return 10;
    }
    return D_800E0A10;
}

u8 func_151D8E6C(void) {
    u8 tmp[3] = D_800AB340;
    return tmp[(random_u32() % 3U)];
}

u8 func_151D8EB0(void) {
    return 117;
}

u8 func_151D8EBC(void) {
    return 29;
}

u8 func_151D8EC8(void) {
    s32 tmp;

    if (random_u32() & 1) {
        tmp = 17;
    } else {
        tmp = 147;
    }
    return tmp;
}

u8 func_151D8EFC(void) {
    s32 tmp;

    if (random_u32() & 1) {
        tmp = 90;
    } else {
        tmp = 91;
    }
    return tmp;
}

u8 func_151D8F30(void) {
    u8 tmp[5] = D_800AB344;
    return tmp[random_u32() % 5U];
}

u8 func_151D8F7C(void) {
    s32 tmp;

    if ((random_u32() & 1) != 0) {
        tmp = 102;
    } else {
        tmp = 103;
    }
    return tmp;
}

u8 func_151D8FB0(void) {
    return 149;
}

u8 func_151D8FBC(void) {
    return 159;
}

u8 func_151D8FC8(void) {
    return 179;
}

u8 func_151D8FD4(void) {
    return 117;
}

u8 func_151D8FE0(void) {
    u8 tmp[4] = D_800AB34C;
    return tmp[random_u32() & 3];
}

// big struct definition
// void func_151D9014(void *arg0, f32 *arg1, u8 arg2, f32 arg3, s16 arg4, u8 arg5, f32 arg6, u8 arg7, f32 arg8, f32 arg9, u8 argA, s32 argB, u8 argC, u8 argD, u8 argE, s32 argF);
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151D9014.s")

s32 func_151D93F4(void *arg0, void *arg1) {
    s32 res;

    if (func_151D9450(arg0, arg1) != 0) {
        if (func_151D9534(arg0, arg1) != 0) {
            res = 1;
        } else {
            res = 0;
        }
    } else {
        res = 0;
    }
    return res;
}

// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Returns 1 immediately if arg0's unk0C1 flag bit 0 is set.
// Otherwise, on a substruct at arg0+0xA8, updates two "accumulator"
// bytes (unk4 += unk6*D_800BE9E4, unk5 += unk7*D_800BE9E4 - the
// global genuinely re-read a second time with no intervening call,
// matching this codebase's established double-read idiom) and calls
// the already-real, already-prototyped func_151423D8 (a trig/table
// lookup confirmed via its real callers in game_16EE20.c) on each
// updated byte minus 0x40, writing arg0->unk38/unk3C as
// result*substructField + substructField0 - looks like advancing a
// 2D oscillation/wobble phase and re-deriving its x/y projection.
// Always returns 1 (both paths set v0=1 explicitly - the real
// caller's `!= 0` check in this file is apparently vestigial).
// 57 vs target's 57 instructions - exact count match. One remaining
// gap: target's top guard uses a plain (non-likely) `beqz` even
// though the delay-slot value (the +0xA8 substruct pointer) is only
// useful on the fallthrough path - every source form tried here
// either reproduces this exact "only-useful-on-one-path" pattern as a
// `beqzl` (branch-likely, the form this project's rule would predict)
// at the same total instruction count, or gets a plain `beqz` at the
// cost of one extra instruction elsewhere (a second arg0 reload) -
// so the two forms trade one specific difference for another; this
// version keeps the exact total-count match and accepts the
// likely-branch flag as the remaining gap.
// s32 func_151D9450(void *arg0, void *arg1) {
//     void *v1;
//     s32 t0;
//     s32 t5;
//     u8 b4;
//     u8 b5;
//     s8 b6;
//     s8 b7;
//     f32 r0;
//     f32 r1;
//
//     if ((*((u8 *) arg0 + 0xC1) & 1) != 0) {
//         return 1;
//     }
//
//     v1 = (char *) arg0 + 0xA8;
//
//     b6 = *((s8 *) v1 + 6);
//     b4 = *((u8 *) v1 + 4);
//     b7 = *((s8 *) v1 + 7);
//     t0 = b6 * (*(volatile s32 *) &D_800BE9E4);
//     b5 = *((u8 *) v1 + 5);
//     b4 = (u8) (b4 + t0);
//     *((u8 *) v1 + 4) = b4;
//     t5 = b7 * (*(volatile s32 *) &D_800BE9E4);
//     b5 = (u8) (b5 + t5);
//     *((u8 *) v1 + 5) = b5;
//
//     r0 = func_151423D8((u8) (b4 - 0x40));
//     *(f32 *) ((char *) arg0 + 0x38) = r0 * *(f32 *) ((char *) v1 + 8) + *(f32 *) v1;
//
//     b5 = *((u8 *) v1 + 5);
//     r1 = func_151423D8((u8) (b5 - 0x40));
//     *(f32 *) ((char *) arg0 + 0x3C) = r1 * *(f32 *) ((char *) v1 + 0xC) + *(f32 *) v1;
//
//     return 1;
// }
struct func_151D9450_sub {
    f32 unk0;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    s8 unk7;
    f32 unk8;
    f32 unkC;
};

struct func_151D9450_s {
    u8 pad0[0x38];
    f32 unk38;
    f32 unk3C;
    u8 pad40[0xA8 - 0x40];
    struct func_151D9450_sub unkA8;
    u8 padB8[0xC1 - 0xB8];
    u8 unkC1;
};

int func_151D9450(struct func_151D9450_s *arg0, void *arg1) {
    struct func_151D9450_sub *sub;

    sub = &arg0->unkA8;
    if (arg0->unkC1 & 1) {
        return 1;
    }
    sub->unk4 += sub->unk6 * D_800BE9E4;
    sub->unk5 += sub->unk7 * D_800BE9E4;
    arg0->unk38 = func_151423D8(sub->unk4 - 0x40) * sub->unk8 + sub->unk0;
    arg0->unk3C = func_151423D8(sub->unk5 - 0x40) * sub->unkC + sub->unk0;
    return 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151D9534.s")

u8 func_151D97A8(void) {
    s32 tmp[7] = D_800AB350;
    return tmp[random_u32() % 7U];
}

u8 func_151D9820(void) {
    s32 tmp[3] = D_800AB36C;
    return tmp[random_u32() % 3U];
}

u8 func_151D9878(void) {
    s32 tmp[3] = D_800AB378;
    return tmp[random_u32() % 3U];
}

u8 func_151D98D0(void) {
    s32 tmp[2] = D_800AB384;
    return tmp[random_u32() & 1];
}

u8 func_151D9918(void) {
    s32 tmp[2] = D_800AB38C;
    return tmp[random_u32() & 1];
}

u8 func_151D9960(void) {
    s32 tmp[5] = D_800AB394;
    return tmp[random_u32() % 5U];
}

u8 func_151D99C8(void) {
    s32 tmp[3] = D_800AB3A8;
    return tmp[random_u32() % 3U];
}

u8 func_151D9A20(void) {
    s32 tmp[2] = D_800AB3B4;
    return tmp[random_u32() & 1];
}

u8 func_151D9A68(void) {
    s32 tmp[3] = D_800AB3BC;
    return tmp[random_u32() % 3U];
}

u8 func_151D9AC0(void) {
    s32 tmp[1] = D_800AB3C8;
    return tmp[0];
}

u8 func_151D9ADC(void) {
    s32 tmp[3] = D_800AB3CC;
    return tmp[random_u32() % 3U];
}

u8 func_151D9B34(void) {
    s32 tmp[4] = D_800AB3D8;
    return tmp[random_u32() & 3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151D9B8C.s")

void func_151D9014(void *arg0, f32 *arg1, u8 arg2, f32 arg3, s16 arg4, u8 arg5, f32 arg6, u8 arg7, f32 arg8, f32 arg9, u8 argA, s32 argB, u8 argC, u8 argD, u8 argE, s32 argF);

struct func_151D9EB0_sub {
    s16 unk0;
    s16 pad2;
    f32 unk4;
    u8 unk8[0xC];
    u8 unk14;
    u8 unk15;
    u8 unk16;
};

struct func_151D9EB0_s {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1B];
    struct func_151D9EB0_sub unk28;
};

void func_151D9EB0(struct func_151D9EB0_s *arg0) {
    struct func_151D9EB0_sub *sub;

    arg0->unk28.unk0 -= D_800BE9E4;
    if (arg0->unk28.unk0 < 0) {
        sub = &arg0->unk28;
        func_151D9014(sub->unk8, &D_800A5480, sub->unk16, func_150ADA68() * D_800AB464 + D_800AB468,
                      (func_150ADA20() % 41U) + 0x23, sub->unk14, sub->unk4, 0, 1.0f, 1.0f,
                      sub->unk15, 0, 1, 0, arg0->unkC, arg0->unk1);
        sub->unk0 = (func_150ADA20() % 111U) + 0x1E;
    }
}

void func_151D9FC0(u8 arg0, f32 arg1, u8 arg2, s32 arg3, s32 arg4, u8 arg5, s32 arg6) {
    f32 temp_f8 = arg1 * 0.5f;
    func_151DBCBC(arg0, temp_f8, arg2, arg3, arg4, arg5, arg6);
    if ((arg0 != 5) && (arg0 != 2)) {
        func_151DA08C(arg0, arg1 * D_800AB46C, 1.01f, arg2, 100, arg3, arg4, arg5, arg6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DA08C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DA368.s")
// TODO when we know what arg0 is...
// NON-MATCHING: mips_to_c reconstruction, hand-typed. When
// arg0->unk58 & 1, multiplies arg0->unk138 (f32) by arg0->unk13C
// (D_800BE9E4 - 1) times. Target compiles this to a tight, un-unrolled
// loop (0x5C bytes total), but IDO -O2 unrolled this reconstruction's
// do-while by 4 into a much larger sequence (with an `andi ...,0x3`
// remainder-count prologue) - a real loop-unrolling-heuristic mismatch,
// not a simple register/ordering issue. Needs a source structure that
// discourages unrolling; didn't find one this round.
s32 func_151DA6A8(struct210 *arg0) {
    s32 count;
    f32 *p;

    if (arg0->unk58 & 1) {
        p = (f32 *) ((char *) arg0 + 0x128);
        count = D_800BE9E4;
        while (count--) {
            p[4] *= p[5];
        }
    }
    return 1;
}
// s32 func_151DA6A8(struct210 *arg0) {
//     s32 count;
//     f32 *unk138 = (f32 *) ((char *) arg0 + 0x138);
//     f32 unk13C;
//
//     if ((arg0->unk58 & 1) != 0) {
//         count = D_800BE9E4;
//         if (count != 0) {
//             unk13C = *(f32 *) ((char *) arg0 + 0x13C);
//             count--;
//             do {
//                 *unk138 *= unk13C;
//                 count--;
//             } while (count != 0);
//         }
//     }
//     return 1;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DA6F8.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DA938.s")
// NON-MATCHING: reads a 20-byte-stride record from a table at
// arg0->unk94 (indexed by the signed byte at arg0->unk2D, read twice -
// target's own genuine double-read, reproduced with a volatile second
// access), builds a local Vec3f-shaped {x,y,z} payload from that
// record's fields 0x0/0x8 plus the incoming float arg4, computes a
// scale factor from a second record at arg0->unk98 (unk0 * 11.0f *
// unk4C), then relays everything into func_151D9FC0 with several more
// byte fields pulled from arg0 and the second record, finally setting
// the second record's unk20 byte to 4.
// s32 func_151DAA88(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
//     struct { f32 unk0; f32 unk4; f32 unk8; } vec;
//     char *base = *(char **) ((char *) arg0 + 0x94);
//     char *rec = *(char **) ((char *) arg0 + 0x98);
//     s8 idx;
//     f32 computed;
//
//     idx = *(s8 *) ((char *) arg0 + 0x2D);
//     vec.unk0 = *(f32 *) (base + (u32) idx * 0x14);
//
//     idx = *(volatile s8 *) ((char *) arg0 + 0x2D);
//     vec.unk8 = *(f32 *) (base + (u32) idx * 0x14 + 8);
//
//     vec.unk4 = arg4;
//
//     computed = (*(f32 *) rec * 11.0f) * *(f32 *) (rec + 0x4C);
//
//     func_151D9FC0(
//         *(u8 *) (rec + 0x50),
//         computed,
//         *(u8 *) (rec + 0x1B),
//         arg5,
//         (s32) &vec,
//         *(u8 *) ((char *) arg0 + 0xC),
//         *(u8 *) ((char *) arg0 + 0x1)
//     );
//
//     *(u8 *) (rec + 0x20) = 4;
//     return 1;
// }
// Matches target's instruction count exactly (52/52), and every
// individual operation/offset/constant is present and correctly
// placed, but register allocation permutes (target: v0=base,
// v1=record, this: v1=base, t0=record, etc.) and the stack frame is
// 8 bytes larger (0x50 vs target's 0x48) for reasons not chased down
// further.
struct func_151DAA88_s { f32 x; f32 y; f32 z; s32 pad[2]; };
s32 func_151DAA88(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
    u8 *rec = *(u8 **) (arg0 + 0x98);
    struct func_151DAA88_s *base = *(struct func_151DAA88_s **) (arg0 + 0x94);
    f32 vec[3];

    vec[0] = base[*(s8 *) (arg0 + 0x2D)].x;
    vec[1] = arg4;
    vec[2] = base[*(s8 *) (arg0 + 0x2D)].z;
    func_151D9FC0(rec[0x50], *(f32 *) (rec + 0x4C) * (*(f32 *) rec * 11.0f), rec[0x1B], arg5, (s32) vec, arg0[0xC], arg0[0x1]);
    rec[0x20] = 4;
    return 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DAB58.s")
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Advances a
// counter byte at arg0->0x110 by (arg0->0x111 signed byte) *
// D_800BE9E4, calls func_151423D8 on (counter-0x40) & 0xFF and on the
// counter directly (a sine/cosine-style lookup, matching its
// established f32(u8) signature elsewhere), then writes two derived
// f32 fields via those two lookups. Two source-order fixes confirmed
// this round: D_800BE9E4 must be read *before* the two byte loads
// (matches target's lui/lw-then-lb/lbu order) to avoid a swapped
// prologue, and this cascades a new mismatch - target stores the
// updated counter to arg0->0x110 *before* computing counter-0x40, but
// every source form tried here (including an extra named byte temp)
// has IDO schedule the independent store and subtract in the opposite
// order regardless - same "trailing independent store gets freely
// reordered" category as the game_D5160/game_D5250 matrix-init
// near-misses. Also target has a dead `addiu v0,zero,1` with no
// corresponding source effect found.
extern f32 D_800AB4B0;

struct func_151DADA0_sub {
    u8 unk0;
    s8 unk1;
    u8 pad2[2];
    f32 unk4;
    f32 unk8;
};

struct func_151DADA0_s {
    u8 pad0[0x4C];
    f32 unk4C;
    f32 unk50;
    u8 pad54[0x110 - 0x54];
    struct func_151DADA0_sub unk110;
};

s32 func_151DADA0(struct func_151DADA0_s *arg0) {
    struct func_151DADA0_sub *sub;
    f32 f0;

    sub = &arg0->unk110;
    f0 = func_151423D8((sub->unk0 += sub->unk1 * D_800BE9E4) - 0x40);
    arg0->unk4C = sub->unk4 * f0 + 1.0f;
    arg0->unk50 = D_800AB4B0 - sub->unk8 * f0;
    return 1;
}
// void func_151DADA0(void *arg0) {
//     void *a1 = arg0;
//     s32 t7 = D_800BE9E4;
//     s8 t6 = *((s8 *) a1 + 0x111);
//     u8 t9 = *((u8 *) a1 + 0x110);
//     s32 a0 = t9 + t6 * t7;
//     f32 f0;
//     void *v1;
//
//     *((u8 *) a1 + 0x110) = (u8) a0;
//     a0 = a0 - 0x40;
//     f0 = func_151423D8((u8) a0);
//     v1 = (char *) a1 + 0x110;
//     *(f32 *) ((char *) a1 + 0x4C) = *(f32 *) ((char *) v1 + 4) * f0 + 1.0f;
//     *(f32 *) ((char *) a1 + 0x50) = D_800AB4B0 - *(f32 *) ((char *) v1 + 8) * f0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DAE28.s")

void func_151DB004(struct218 *arg0) {
    arg0->unk14 = (random_u32() % 0x38U) + 80;
    arg0->unk15 = 0;
    arg0->unk16 = 0;
    arg0->unk18 = (random_u32() % 0x2EU) + 180;
    arg0->unk19 = 0;
    arg0->unk1A = 0;
}

void func_151DB068(struct218 *arg0) {
    arg0->unk14 = arg0->unk15 = (random_u32() % 0x38U) + 100;
    arg0->unk16 = 0;
    arg0->unk18 = arg0->unk19 = (random_u32() % 0x2EU) + 180;
    arg0->unk1A = 0;
}

void func_151DB0CC(struct218 *arg0) {
    arg0->unk14 = (random_u32() % 0x38U) + 80;
    arg0->unk15 = (random_u32() % 0x38U) + 80;
    arg0->unk16 = 0;
    arg0->unk18 = (random_u32() % 0x2EU) + 180;
    arg0->unk19 = (random_u32() % 0x2EU) + 180;
    arg0->unk1A = 0;
}

void func_151DB15C(struct218 *arg0) {
    arg0->unk14 = (random_u32() % 0x38U) + 80;
    arg0->unk15 = (random_u32() % 0x38U) + 80;
    arg0->unk16 = 0;
    arg0->unk18 = (random_u32() % 0x2EU) + 180;
    arg0->unk19 = (random_u32() % 0x2EU) + 180;
    arg0->unk1A = 0;
}

void func_151DB1EC(struct218 *arg0) {
    arg0->unk14 = (random_u32() % 0x38U) + 80;
    arg0->unk15 = (random_u32() % 0x38U) + 80;
    arg0->unk16 = 0;
    arg0->unk18 = (random_u32() % 0x2EU) + 180;
    arg0->unk19 = (random_u32() % 0x2EU) + 180;
    arg0->unk1A = 0;
}

void func_151DB27C(struct218 *arg0) {
    arg0->unk14 = 0xFF;
    arg0->unk15 = 0xFF;
    arg0->unk16 = 0xFF;
    arg0->unk18 = 0xB4;
    arg0->unk19 = 0xC8;
    arg0->unk1A = 0xC8;
}

void func_151DB2A8(struct218 *arg0) {
    arg0->unk14 = 0;
    arg0->unk15 = 200;
    arg0->unk16 = 0;
    arg0->unk18 = 0;
    arg0->unk19 = 200;
    arg0->unk1A = 0;
}

void func_151DB2CC(struct218 *arg0) {
    arg0->unk14 = 0;
    arg0->unk15 = (random_u32() % 0x38U) + 80;
    arg0->unk16 = 0;
    arg0->unk18 = 0;
    arg0->unk19 = (random_u32() % 0x2EU) + 180;
    arg0->unk1A = 0;
}

void func_151DB330(struct218 *arg0) {
    arg0->unk14 = (random_u32() % 0x15U) + 95;
    arg0->unk15 = (random_u32() % 0x15U) + 95;
    arg0->unk16 = (random_u32() % 0xBU) + 45;
    arg0->unk18 = (random_u32() & 0xF) + 58;
    arg0->unk19 = (random_u32() & 0xF) + 60;
    arg0->unk1A = (random_u32() % 0xBU) + 25;
}

void func_151DB3D8(struct218 *arg0) {
    arg0->unk14 = 0;
    arg0->unk15 = arg0->unk16 = (random_u32() % 0x38U) + 80;
    arg0->unk18 = 0;
    arg0->unk19 = arg0->unk1A = (random_u32() % 0x2EU) + 180;
}

void func_151DB43C(struct218 *arg0) {
    arg0->unk14 = (random_u32() % 0x38U) + 80;
    arg0->unk15 = 0;
    arg0->unk16 = (random_u32() % 0x38U) + 80;
    arg0->unk18 = (random_u32() % 0x2EU) + 180;
    arg0->unk19 = 0;
    arg0->unk1A = (random_u32() % 0x2EU) + 180;
}

void func_151DB4CC(struct218 *arg0) {
    arg0->unk14 = (random_u32() % 56U) + 200;
    arg0->unk15 = (random_u32() % 56U) + 200;
    arg0->unk16 = (random_u32() % 56U) + 200;
    arg0->unk18 = (random_u32() % 56U) + 200;
    arg0->unk19 = (random_u32() % 56U) + 200;
    arg0->unk1A = (random_u32() % 56U) + 200;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DB5D0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DB97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DBAA8.s")

// typedef struct {
//     s16 unk0; // sp24
//     s16 unk2;
//     s16 unk4;
//     s16 unk6;
//     // s32 unk8[3]; // sp2C
//     s32 unk8;
//     s32 unkC;
//     s32 unk10;
//     f32 unk14;
//     f32 unk18;
//     f32 unk1C;
//     f32 unk20; // sp44
//     f32 unk24;
//     f32 unk28;
//     s16 unk2C; // sp50
//     s16 unk2E;
//     s16 unk30; // sp54
//     s16 unk32;
//     s16 unk34;
//     s16 unk36;
//     s16 unk38;
//     s16 unk3A;
//     s8  unk3C; // sp60
//     u8  pad3D[0x3];
//     f32 unk40; // sp64
//     s16 unk44;
//     s16 unk46;
//     s32 unk48;
// } struct218XXX;
//
// void func_15153F18(s32, s32, s32, u8, s32);
// void func_151DBAA8(struct00 *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4) {
//
//     struct218XXX tmp;
//
//     // tmp.unk8[0] = arg0->unk0;
//     // tmp.unk8[1] = arg0->unk4;
//     // tmp.unk8[2] = arg0->unk8;
//
//     tmp.unk2C = arg1;
//     tmp.unk3C = arg2;
//
//     tmp.unk0 = 0;
//     tmp.unk2 = 0xFF;
//     tmp.unk4 = -0x40;
//     tmp.unk6 = 0x2E;
//     tmp.unk8 = arg0->unk0;
//     tmp.unkC = arg0->unk4;
//     tmp.unk10 = arg0->unk8;
//
//     tmp.unk30 = 3;
//     tmp.unk2E = 0;
//     tmp.unk32 = 2;
//     tmp.unk34 = 0x1E;
//     tmp.unk36 = 0x1E;
//     tmp.unk38 = 0x9B;
//     tmp.unk14 = 5.5f;
//
//     tmp.unk18 = D_800AB4C0;
//     tmp.unk1C = D_800AB4C4;
//     tmp.unk20 = D_800AB4C8;
//     tmp.unk24 = 10.0f;
//     tmp.unk28 = D_800AB4CC;
//
//     tmp.unk3A = 0x64;
//     tmp.unk44 = 0x10;
//     tmp.unk46 = 0xF;
//     tmp.unk48 = 0;
//     tmp.unk40 = 0.5f;
//
//     func_15153F18(&tmp, &tmp.unk8, 0, arg3, arg4);
// }

void func_151DBBD4(struct17 *arg0, s32 arg1, u8 *arg2, u8 arg3, s32 arg4) {
    struct17 tmp;
    struct217 tmp2;

    tmp.unk0 = arg0->unk0;
    tmp.unk4 = arg0->unk4 + 5.0f;
    tmp.unk8 = arg0->unk8;

    tmp2.unkF = *arg2;
    tmp2.unk0 = random_float();
    tmp2.unk4 = random_u32();

    func_151D9B8C(tmp2.unkF, (tmp2.unk0 * 25.0f) + 10.0f, ((tmp2.unk4 % 0x38U) + 200), (void *) (arg1 + 4), &tmp, (random_u32() % 0x97U) + 150, 0, 1, 0, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DBCBC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DBE80.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DC034.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DC260.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_2062D0/func_151DC484.s")

// typedef struct {
//     s16 unk10; // sp24
//     s16 unk12; // sp26
//     s16 unk14;
//     s16 unk16; // sp2A
//     s32 unk18[3];
//     s16 unk24; // sp38;
//     s16 unk26; // sp3A
//     f32 unk28; // sp3C
//     f32 unk2C; // sp40
//     s16 unk30; // sp44
//     s16 unk32; // sp46
//     f32 unk34; // sp48;
//     f32 unk38; // sp4C;
//     s8  unk3C; // sp50;
//     s8  unk3D; // sp51;
//     u8  unk3E[2]; //
//     f32 unk40; // sp54
//     f32 unk44; // sp58
//     s8  unk48; // sp5C
//     u8  unk49; // sp5D
//     u8  unk4A[2];
//     f32 unk4C; // sp60
//     s8  unk50; // sp64
//     u8  pad51[3];
//     f32 unk54; // sp68
// } struct217;
//
// typedef struct {
//     s16 unk58; // sp6C
//     s16 unk5A; // sp6E
//     s16 unk5C; // sp70
//     s16 unk5E; // sp72
//     s32 unk60[3]; // sp74
//     f32 unk6C; // sp80
//     f32 unk70; // sp84
//     f32 unk74; // sp88
//     f32 unk78; // sp8C
//     f32 unk7C; // sp90
//     f32 unk80; // sp94
//     s16 unk84; // sp98
//     s16 unk86; // sp9A
//     s16 unk88; // sp9C
//     s16 unk8A; // sp9E
//     s16 unk8C; // spA0
//     s16 unk8E; // spA2
//     s16 unk90; // spA4
//     s16 unk92; // spA6
//     u8  unk94; // spA8;
//     u8  pad95[3];
//     f32 unk98; // spAC;
//     s16 unk9C; // spB0
//     s16 unk9E; // spB2
//     s32 unkA0; // spB4
// } struct218;
//
// void func_151DC484(struct00 *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4) {
//     struct218 tmp2;
//     struct217 tmp;
//
//     tmp2.unk60[0] = arg0->unk0; // sp74.unk0 = (s32) arg0->unk0;
//     tmp2.unk60[1] = arg0->unk4; // sp74.unk4 = (s32) arg0->unk4;
//     tmp2.unk60[2] = arg0->unk8; // sp74.unk8 = (s32) arg0->unk8;
//
//     tmp2.unk5A = 0xFF;   // sp6E = 0xFF;
//     tmp2.unk5C = -0x40;  // sp70 = -0x40;
//     tmp2.unk84 = 8;      // sp98 = 8;
//     tmp2.unk86 = 6;      // sp9A = 6;
//     tmp2.unk58 = 0;      // sp6C = 0;
//     tmp2.unk88 = 3;      // sp9C = 3;
//     tmp2.unk8A = 0;      // sp9E = 0;
//     tmp2.unk5E = 0x28;   // sp72 = 0x28;
//     tmp2.unk8C = 0x3C;   // spA0 = 0x3C;
//     tmp2.unk8E = 0x28;   // spA2 = 0x28;
//
//     tmp2.unk6C = 3.0f;   // sp80 = 3.0f;
//     tmp2.unk90 = 100;     // spA4 = 0x64;
//     tmp2.unk92 = 100;     // spA6 = 0x64;
//     tmp2.unk9C = 16;      // spB0 = 0x10;
//     tmp2.unk9E = 15;      // spB2 = 0xF;
//     tmp2.unk70 = 2.0f;       // sp84 = 2.0f;
//     tmp2.unk74 = D_800AB4E4; // sp88 = D_800AB4E4;
//     tmp2.unk78 = D_800AB4E8; // sp8C = D_800AB4E8;
//     tmp2.unk7C = 8.0f;       // sp90 = 8.0f;
//     tmp2.unk80 = 5.0f;       // sp94 = 5.0f;
//     tmp2.unk98 = 1.0f;       // spAC = 1.0f; 0x3f80
//     tmp2.unk94 = arg2;       // spA8 = arg2;
//     tmp2.unkA0 = 0;      // spB4 = 0;
//
//     // func_15153F18(&sp6C, &sp74, arg1, arg3, arg4);
//     func_15153F18(&tmp2, &tmp2, arg1, arg3, arg4);
//
//     tmp.unk18[0] = arg0->unk0; // sp2C.unk0 = (s32) arg0->unk0;
//     tmp.unk18[1] = arg0->unk4; // sp2C.unk4 = (s32) arg0->unk4;
//     tmp.unk18[2] = arg0->unk8; // sp2C.unk8 = (s32) arg0->unk8;
//
//     tmp.unk24 = 0xC; // sp38 = 0xC;
//     tmp.unk12 = 0xFF;   // sp26 = 0xFF;
//     tmp.unk26 = 6;      // sp3A = 6;
//     tmp.unk10 = 0;      // sp24 = 0;
//     tmp.unk14 = -0x40;  // sp28 = -0x40;
//     tmp.unk16 = 0x1A;   // sp2A = 0x1A;
//     tmp.unk30 = 0x23;   // sp44 = 0x23;
//     tmp.unk32 = 0xF;    // sp46 = 0xF;
//     tmp.unk3C = 0x9B;   // sp50 = 0x9B;
//     tmp.unk3D = 0x64;   // sp51 = 0x64;
//     tmp.unk40 = 59.0f;  // sp54 = 59.0f;
//     tmp.unk44 = 59.0f;  // sp58 = 59.0f;
//     tmp.unk48 = 1;      // sp5C = 1;
//     tmp.unk50 = 1;      // sp64 = 1;
//     tmp.unk54 = 0.0f;   // sp68 = 0.0f;
//     tmp.unk28 = 7.0f;   // sp3C = 7.0f;
//     tmp.unk2C = 3.0f;   // sp40 = 3.0f;
//     tmp.unk34 = D_800AB4EC; // sp48 = D_800AB4EC;
//     tmp.unk38 = D_800AB4F0; // sp4C = D_800AB4F0;
//     tmp.unk49 = arg2;       // sp5D = arg2;
//     tmp.unk4C = D_800AB4F4; // sp60 = D_800AB4F4;
//     // func_15150178(&sp24, &sp2C, arg1, arg3, arg4);
//     func_15150178(&tmp, &tmp.unk18, arg1, arg3, arg4);
// }
