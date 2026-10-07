#include <ultra64.h>

#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C1F60.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C2290.s")
// TODO: figure out this struct!
// void func_150C2290(s32 arg0) {
//     s16 sp9A;
//     s16 sp98;
//     s8 sp95;
//     s8 sp94;
//     s32 sp90;
//     s32 sp8C;
//     s32 sp88;
//     s32 sp84;
//     s32 sp80;
//     s32 sp7C;
//     s32 sp78;
//     s32 sp74;
//     s32 sp70;
//     s8 sp6E;
//     s8 sp6D;
//     s8 sp6C;
//     s32 sp68;
//     s32 sp64;
//     s32 sp60;
//     s32 sp5C;
//     s32 sp58;
//     s32 sp54;
//     s8 sp52;
//     s8 sp51;
//     s8 sp50;
//     s16 sp4E;
//     s16 sp4C;
//     s16 sp4A;
//     s16 sp48;
//     s16 sp46;
//     s16 sp44;
//     s16 sp42;
//     s16 sp40;
//     s16 sp3E;
//     s16 sp3C;
//     f32 sp38;
//     f32 sp34;
//     f32 sp30;
//     f32 sp2C;
//     f32 sp28;
//     f32 sp24;
//     f32 sp20;
//     f32 sp1C;
//     f32 sp18;
//
//     sp18 = *(void *)0x800A0258;
//     sp1C = 40.0f;
//     sp3E = 3;
//     sp40 = -0x29;
//     sp44 = -0x16;
//     sp42 = 0x15;
//     sp46 = 0x16;
//     sp48 = 7;
//     sp4E = 0x15;
//     sp50 = 0xB;
//     sp20 = *(void *)0x800A025C;
//     sp3C = 2;
//     sp4C = 0x30;
//     sp52 = 0x28;
//     sp54 = 1;
//     sp58 = 4;
//     sp6C = 0xFF;
//     sp6D = 0xFF;
//     sp70 = 3;
//     sp4A = 0;
//     sp51 = 1;
//     sp5C = 0;
//     sp60 = 0;
//     sp64 = 0;
//     sp68 = 0;
//     sp6E = 0;
//     sp74 = 0xFF;
//     sp78 = 0;
//     sp7C = 0x220005;
//     sp80 = 0x1D0600;
//     sp84 = (s32) (u8)1;
//     sp88 = 0x3B;
//     sp8C = 0x80;
//     sp90 = 0x20;
//     sp94 = 0;
//     sp95 = 7;
//     sp98 = 0xC;
//     sp9A = 0x15;
//     sp34 = 100.0f;
//     sp38 = 57.5f;
//     sp24 = *(void *)0x800A0260;
//     sp28 = 39.0f;
//     sp2C = *(void *)0x800A0264;
//     sp30 = 1.0f;
//     func_15151A38(&sp18, arg0 & 0xFF, 1);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C2424.s")
// NON-MATCHING (JUSTREG): semantics fully recovered - clamps
// (arg0->unk1C << 3) to 0xFF, stores it as a byte into
// *(arg0->unk98 + 0x1B), then hits the same "unsigned byte tested as
// if signed" dead-branch pattern already seen in func_1506196C and
// func_150AED9C: target masks the clamped value to a byte and
// branches on it as if it could be negative (always false in
// practice, so the `return 0` arm is provably dead code), reproduced
// literally by the `if ((u8) v < 0) return 0;` below.
//
// UPDATED 2026-09-22: now an exact 15/15 match, every opcode, operand
// and offset identical to target; only two scratch register names
// differ (target's t6/t7 vs this build's a2/t6). The previously
// documented extra unconditional branch (16 vs 15 instructions) is
// GONE. The fix was the clamp's phrasing: the earlier attempt used
// `if (t6 < 0x100) { v1 = t6; } else { v1 = 0xFF; }`, and if/else,
// ternary and goto forms all emitted a branch to merge the two arms.
// Writing it instead as assign-then-conditionally-override -
// `v1 = t6; if (t6 >= 0x100) { v1 = 0xFF; }` - lets IDO put the
// common assignment in the compare's delay slot and let the override
// fall through, which is exactly how target merges the two cases.
// Worth trying this fourth form on any near-miss whose recorded gap
// is "one extra branch merging two assignment arms".
//
// This function emits zero relocations, so the isolated object is
// authoritative here - the remaining register difference will not
// change on linking.
// s32 func_150C251C(void *arg0) {
//     void *v0 = *(void **) ((char *) arg0 + 0x98);
//     s32 v1 = *(s16 *) ((char *) arg0 + 0x1C);
//     s32 t6 = v1 << 3;
//
//     v1 = t6;
//     if (t6 >= 0x100) {
//         v1 = 0xFF;
//     }
//
//     *(u8 *) ((char *) v0 + 0x1B) = (u8) v1;
//     if ((u8) v1 < 0) {
//         return 0;
//     }
//     return 1;
// }
s32 func_150C251C(void *arg0) {
    void *v0 = *(void **) ((char *) arg0 + 0x98);
    s32 v1 = *(s16 *) ((char *) arg0 + 0x1C);

    v1 = v1 << 3;
    if (v1 >= 0x100) {
        v1 = 0xFF;
    }

    *(u8 *) ((char *) v0 + 0x1B) = (u8) v1;
    if ((u8) v1 < 0) {
        return 0;
    }
    return 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C2558.s")
void func_15150178();
extern f32 D_800A0274;
extern f32 D_800A0278;
extern f32 D_800A027C;

struct func_150C2700_s {
    f32 x, y, z;
    s16 unkC;
    s16 unkE;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    s16 unk1A;
    f32 unk1C;
    f32 unk20;
    u8 unk24;
    u8 unk25;
    f32 unk28;
    f32 unk2C;
    u8 unk30;
    u8 unk31;
    f32 unk34;
    u8 unk38;
    f32 unk3C;
};

s32 func_150C2700(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, u8 arg14) {
    struct func_150C2700_s sp28;
    s16 sp20[4];

    sp28.x = arg2;
    sp28.y = arg3;
    sp28.unkC = 6;
    sp28.unkE = 5;
    sp20[0] = 0x6B;
    sp20[1] = 0x46;
    sp20[2] = -0x1F;
    sp20[3] = 0x2E;
    sp28.z = arg4;
    sp28.unk10 = 30.0f;
    sp28.unk14 = 35.0f;
    sp28.unk18 = 0x64;
    sp28.unk1A = 0;
    sp28.unk1C = D_800A0274;
    sp28.unk20 = D_800A0278;
    sp28.unk24 = 0x9B;
    sp28.unk25 = 0x64;
    sp28.unk28 = D_800A027C;
    sp28.unk2C = 0.0f;
    sp28.unk30 = 1;
    sp28.unk31 = 6;
    sp28.unk34 = 0.0f;
    sp28.unk38 = 1;
    sp28.unk3C = 0.0f;
    func_15150178(sp20, &sp28, 0, arg14, 1);
    return 1;
}
void func_150C2804(s32 arg0, s32 arg1, s32 arg2, s16 arg3, u8 arg4, s32 arg5) {
    struct {
        s32 f0;
        s32 f4;
        s32 f8;
        f32 fC;
        f32 f10;
        s16 f14;
        u8 f16;
        u8 f17;
        u8 f18;
        s8 f19;
    } local;

    local.f0 = arg0;
    local.f4 = arg1;
    local.f8 = arg2;
    local.fC = D_800A0280;
    local.f10 = D_800A0284;
    local.f14 = arg3;
    local.f16 = 5;
    local.f17 = 6;
    local.f18 = 3;
    local.f19 = -1;
    func_15134908(&local, 0, arg4, arg5);
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C2898.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C29F0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C2C00.s")
// Struct/type unidentified in this file (no callers decompiled yet) -
// raw void* offset casts. Simple physics-integration step: unk2C/unk30
// (velocity?) decay by a factor unk150, unk38 (position?) integrates
// unk50 (accel?) and unk4C via unk38 += unk50*D + 0.5*unk4C*D*D, unk50
// += unk4C*D, then returns whether both unk2C and unk30 stayed >= 10.0.
s32 func_150C2FCC(void *arg0) {
    *(f32 *) ((char *) arg0 + 0x2C) -= *(f32 *) ((char *) arg0 + 0x2C) * *(f32 *) ((char *) arg0 + 0x150);
    *(f32 *) ((char *) arg0 + 0x30) -= *(f32 *) ((char *) arg0 + 0x30) * *(f32 *) ((char *) arg0 + 0x150);
    *(f32 *) ((char *) arg0 + 0x38) += *(f32 *) ((char *) arg0 + 0x50) * D_800BE9A4 + 0.5f * *(f32 *) ((char *) arg0 + 0x4C) * D_800BE9A4 * D_800BE9A4;
    *(f32 *) ((char *) arg0 + 0x50) += *(f32 *) ((char *) arg0 + 0x4C) * D_800BE9A4;
    if (*(f32 *) ((char *) arg0 + 0x2C) < 10.0f || *(f32 *) ((char *) arg0 + 0x30) < 10.0f) {
        return 0;
    }
    return 1;
}
struct17 *func_15144B34(s32 arg0);

s32 func_150C308C(void *arg0) {
    u8 ret = 0;
    struct17 *v;
    f32 dist;

    if (*(s16 *) ((char *) arg0 + 0x1C) >= 6) {
        v = func_15144B34(D_80082FA4);
        dist = v->unk0 * v->unk0 + v->unk8 * v->unk8;
        if (dist < D_800A0310) {
            ret = 1;
        } else {
            dist = func_150484A0(v->unk0, v->unk8);
            if (func_15144C8C(dist, *(f32 *) ((char *) arg0 + 0x160)) > D_800A0314) {
                ret = 1;
            }
        }
    }
    if (ret) {
        *(s16 *) ((char *) arg0 + 0x1C) = 5;
    }
    return 1;
}
// ? func_150C308C(void *arg0) {
//     u8 sp1F;
//     f32 temp_f0;
//     f32 temp_f2;
//     u8 temp_a1;
//     void *temp_v0;
//     u8 phi_a1;
//
//     phi_a1 = (u8)0U;
//     if ((s32) arg0->unk1C >= 6) {
//         sp1F = 0;
//         temp_v0 = func_15144B34(D_80082FA4, (u8)0U);
//         temp_f0 = temp_v0->unk0;
//         temp_f2 = temp_v0->unk8;
//         temp_a1 = sp1F;
//         if (((temp_f0 * temp_f0) + (temp_f2 * temp_f2)) < D_800A0310) {
// block_4:
//             phi_a1 = (u8)1U;
//         } else {
//             sp1F = temp_a1;
//             phi_a1 = temp_a1;
//             if (D_800A0314 < func_15144C8C(func_150484A0(temp_v0->unk0, temp_v0->unk8, temp_a1), arg0->unk160)) {
//                 goto block_4;
//             }
//         }
//     }
//     if (phi_a1 != 0) {
//         arg0->unk1C = (u16)5;
//     }
//     return 1;
// }

// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Computes a pitch ratio from arg1's unk2E4/unk2E8 fields
// (defaulting to 1.0 when unk2E8 is 0 - getting target's exact
// `beqzl` branch polarity required initializing the default
// unconditionally before the guard, `ratio = 1.0f; if (unk2E8 != 0)
// ratio = ...;`, rather than an if/else with the zero-case inside the
// `if`, which instead compiled to the inverted `bnezl`), derives a
// truncated integer "period" from 500*(1-ratio)+2, updates
// arg1->unk2EC to period/3, normalizes (2 - old unk2EC) into a
// non-negative "phase" via a bltzl +0x40 loop, and packs
// (period&0xFFF)<<12 | 0xF2000000 | (phase&0xFFF) plus a fixed second
// word (0x041FE03E) into the two-word command written at arg0,
// returning arg0+8. Register roles differ throughout (this
// reconstruction runs 6 instructions shorter, 46 vs target's 52) -
// not otherwise investigated further this round.
struct func_150C3160_s {
    u8 pad[0x2E4];
    s32 unk2E4;
    s32 unk2E8;
    s32 unk2EC;
};

Gfx *func_150C3160(Gfx *gfx, struct func_150C3160_s *arg1) {
    f32 ratio;
    s32 period;
    s32 phase;

    if (arg1->unk2E8 != 0) {
        ratio = (f32) arg1->unk2E4 / (f32) arg1->unk2E8;
    } else {
        ratio = 1.0f;
    }
    ratio = 1.0f - ratio;
    period = 500.0f * ratio + 2.0f;
    phase = 2 - arg1->unk2EC;
    arg1->unk2EC = period / 3;
    while (phase < 0) {
        phase += 0x40;
    }
    gDPSetTileSize(gfx++, 4, period, phase, 0x1FE, 0x3E);
    return gfx;
}
// void *func_150C3160(void *arg0, void *arg1) {
//     void *out;
//     f32 ratio;
//     s32 rawPeriod;
//     s32 phase;
//     s32 cmd0;
//
//     out = arg0;
//     ratio = 1.0f;
//     if (*(s32 *) ((char *) arg1 + 0x2E8) != 0) {
//         ratio = (f32) *(s32 *) ((char *) arg1 + 0x2E4) / (f32) *(s32 *) ((char *) arg1 + 0x2E8);
//     }
//     rawPeriod = (s32) (500.0f * (1.0f - ratio) + 2.0f);
//     phase = 2 - *(s32 *) ((char *) arg1 + 0x2EC);
//     *(s32 *) ((char *) arg1 + 0x2EC) = rawPeriod / 3;
//     while (phase < 0) {
//         phase += 0x40;
//     }
//     cmd0 = ((rawPeriod & 0xFFF) << 12) | 0xF2000000 | (phase & 0xFFF);
//     *(s32 *) out = cmd0;
//     *(s32 *) ((char *) out + 4) = 0x041FE03E;
//     out = (char *) out + 8;
//     return out;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C3230.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C3574.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C3994.s")

s32 func_150C3D48(s32 arg0) {
    return arg0 + 0xEDCBA988;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EF410/func_150C3D5C.s")
