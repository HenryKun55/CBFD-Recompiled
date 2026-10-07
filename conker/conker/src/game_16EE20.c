#include <ultra64.h>

#include "functions.h"
#include "variables.h"

f32 random_float();                                /* extern */

void func_15141970(struct37 *arg0) {
    func_1514EDF0(arg0, arg0->unk2C);
}

void func_15141990(void *arg0) {
    func_15141970(arg0);
}

void func_151419B0(void *arg0) {
    func_15141970(arg0);
}

// NON-MATCHING: same "cfg" merge pattern as func_150AEDF8/game_DBA60.c
// (recovered and hand-verified via isolated harness), just with the
// cfg record's fields shifted to +4/+8 instead of +0/+4, and the
// arg2==0/arg2==0x2D branches in the opposite order. Getting the
// initial `*(s32 *) arg1 == *(s32 *) (cfg + 4)` load order right
// (target reads arg1 before cfg+4) needed splitting both reads into
// separate named locals evaluated in that order - writing the
// comparison directly, in either operand order, made IDO load cfg+4
// first instead. Once load order matched, the remaining gap is a
// single register-choice difference ($a0 vs $t7 for the cfg+4 value)
// that cascades through every later temp register in both branches
// (their `bnel`/`lbu`/`sw` operands all shift by one register
// accordingly) - the same "immune to restructuring" register-choice
// class documented elsewhere this session, just with an unusually
// wide blast radius since so many instructions read that one value.
struct func_151419D0_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_151419D0(struct102 *arg0, struct func_151419D0_s *arg1, u8 arg2) {
    struct func_151419D0_s *cfg = (struct func_151419D0_s *) ((char *) arg0 + 0x28);
    s32 v1;

    if (arg2 == 0) {
        v1 = arg1->unk0;
        if (v1 == cfg->unk4 || cfg->unk8 == *(u8 *) &arg1->unk4) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (cfg->unk4 == arg1->unk0) {
            cfg->unk4 = arg1->unk4;
            cfg->unk8 = arg1->unk9;
        } else if (cfg->unk4 == arg1->unk4) {
            cfg->unk4 = arg1->unk0;
            cfg->unk8 = arg1->unk8;
        }
    }
}
// void func_151419D0(void *arg0, void *arg1, u8 arg2) {
//     char *cfg;
//     s32 v1;
//     s32 t7;
//
//     cfg = (char *) arg0 + 0x28;
//     if (arg2 == 0) {
//         v1 = *(s32 *) arg1;
//         t7 = *(s32 *) (cfg + 4);
//         if (v1 == t7 || *(u8 *) (cfg + 8) == *(u8 *) ((char *) arg1 + 4)) {
//             func_1516972C(arg0);
//         }
//         return;
//     }
//     if (arg2 == 0x2D) {
//         if (*(s32 *) arg1 == *(s32 *) (cfg + 4)) {
//             *(s32 *) (cfg + 4) = *(s32 *) ((char *) arg1 + 4);
//             *(u8 *) (cfg + 8) = *(u8 *) ((char *) arg1 + 9);
//             return;
//         }
//         if (*(s32 *) ((char *) arg1 + 4) == *(s32 *) (cfg + 4)) {
//             *(s32 *) (cfg + 4) = *(s32 *) arg1;
//             *(u8 *) (cfg + 8) = *(u8 *) ((char *) arg1 + 8);
//         }
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15141A7C.s")
// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15141C0C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15141CC0.s")

void func_15141DA4(void *arg0, s32 arg1, s32 arg2) {
    if ((arg1 < 12) && (arg1 >= 0) &&
        (arg2 < 20) && (arg2 >= 0) &&
        (D_800BE616 == 0) &&
        (D_8008A084[arg1] != 0) && (arg2 != -1)) {
        if ((D_8008A0B4[arg2].unk0 != 0) && (D_8008A0B4[arg2].unk4 > 0)) {
            func_15141E38(arg0, arg2);
        }
    }
}

// NON-MATCHING: 79 vs target's 80 instructions. Walks arg0's unk2F4
// linked list via the K&R func_1514ECE0(node, 0x1A, &out) iterator,
// and for any node whose unk10-owner's unk28 type-id matches arg1,
// records it as found and overwrites that owner's halfword field 0xE
// with D_8008A0B4[arg1].unk4. If nothing matched, allocates a new
// effect via func_15149130 (arg0->unk3B is loaded and stashed to the
// stack but never read again - matches the caller's own asm exactly,
// so kept as a genuine dead store) and links it in via func_1514EC1C.
// Semantics confirmed via the existing caller func_15141DA4, which
// already establishes arg1 as a D_8008A0B4 index and arg0 as a raw
// pointer. The one-instruction gap and 8-byte-larger stack frame are
// from the compiler's own scratch-slot ordering for the arg1/arg0/
// category snapshot preceding the allocator call, not a semantic
// difference - tweaking local declaration order shifted the slots but
// never closed the gap.
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15141E38.s")
// extern s32 func_1514ECE0();
// extern void *func_1514EC1C();
//
// void func_15141E38(void *arg0, s32 arg1) {
//     s32 buf;
//     void *found = 0;
//
//     buf = *(s32 *) ((char *) arg0 + 0x2F4);
//
//     if (func_1514ECE0(buf, 0x1A, &buf) != 0) {
//         do {
//             void *cur = (void *) buf;
//             void *type = *(void **) ((char *) cur + 0x10);
//
//             if (arg1 == *(s32 *) ((char *) type + 0x28)) {
//                 found = cur;
//                 *(s16 *) ((char *) type + 0xE) = (s16) D_8008A0B4[arg1].unk4;
//             }
//             buf = *(s32 *) ((char *) cur + 0x14);
//         } while (func_1514ECE0(buf, 0x1A, &buf) != 0);
//     }
//
//     if (found == 0) {
//         u8 snapshot[0xC];
//         volatile u8 category = *(u8 *) ((char *) arg0 + 0x3B);
//         void *newObj;
//
//         *(s32 *) snapshot = arg1;
//         *(s32 *) (snapshot + 4) = (s32) arg0;
//
//         newObj = func_15149130((s16) D_8008A0B4[arg1].unk4, -1, -1, -1, 1, 0x32,
//                                 (struct37 *) 0xC, 0xFF, 1);
//
//         if (newObj != 0) {
//             memcpy((char *) newObj + 0x28, snapshot, 0xC);
//             func_1514EC1C(newObj, arg0, 0x1A);
//         }
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15141F78.s")
// NON-MATCHING: need to determine arguments
// void func_1513C650(s32, s32, s32, u16, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32, u8, s32);
// s32 func_1513C650(s32 arg0, u8 arg1, u8 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, s32 argC, s32 argD, u8 argE, s32 argF);
// void func_15141F78(u8 arg0, struct157 *arg1, f32 arg2, s32 arg3, struct157 *arg4, u8 arg5) {
//     struct157 tmp;
//     f32 temp_f2;
//     s32 phi_v0;
//
//     tmp.unk6 = arg0;
//     tmp.unk7 = 0;
//     tmp.unk0 = 0x6F701;
//     tmp.unk4 = (random_u32() % 61U) + 100;
//     tmp.unk8 = 0;
//     tmp.unkC = 0;
//     tmp.unk10 = (random_u32() & 0x7F) + 128;
//     tmp.unk11 = 0xFF;
//     tmp.unk12 = 0xFF;
//     tmp.unk13 = 0xFF;
//     tmp.unk14 = 0xFF;
//     tmp.unk15 = 0xFF;
//     tmp.unk18 = 0x3B0002;
//     tmp.unk16 = 0;
//     tmp.unk17 = 7;
//     tmp.unk20 = 0xFF;
//     tmp.unk1C = arg1->unk18;
//     tmp.unk22 = 0x28;
//     tmp.unk24 = 6;
//     temp_f2 = ((random_float() * 5.0f) + 10.0f) * arg2;
//     // --- matching to here ---
//     if (arg5 == 2) {
//         phi_v0 = 1;
//     } else {
//         phi_v0 = 0;
//     }
//     func_1513C650(&tmp, 0, 0, arg1->unk4, arg4->unk0, arg1->unk0, arg4->unk8, temp_f2, temp_f2, arg3, phi_v0, 3, 1, 0, 0xFF, 1);
// }

// Copies the 6-entry D_800A5200 table into a local buffer and passes it
// (with arg0's index into gObjects) to func_150A2AEC.
s32 func_151420F8(struct127 *arg0) {
    struct261 tmp = D_800A5200;

    if (func_150A2AEC(arg0 - gObjects, 6, &tmp) == -1) {
        return 0;
    }
    return 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15142180.s")

s32 func_151422C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (arg3 + arg2) >> 1;
}

s32 func_151422DC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return arg4;
}

s32 func_151422F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return arg4;
}

// NON-MATCHING: exact 49/49 instruction count match, but a real branch-
// type difference remains - target compiles the D_800C3E90 test as a
// plain `beqz` because its delay slot holds the shared address
// computation `v0 = arg0 + (arg1<<6)`, useful on BOTH paths, so it
// never needs annulment. This reconstruction's compile instead settles
// on `beqzl` (branch-likely) with the else-branch's first field read
// in the delay slot, then still separately recomputes `v0` inside the
// if-taken path anyway - tried computing `v0` freshly inside each
// branch instead of once up front (matching target's "single shared
// computation" shape more literally in the source) and IDO produced
// byte-identical output either way, so this looks like a stable
// scheduling choice rather than something reachable from source
// phrasing. Every offset, arithmetic operation, and instruction TYPE
// otherwise matches target exactly, just reordered/reshuffled by the
// different branch form. Indexes a 0x40-byte-stride array by arg1;
// each element holds an integer/fractional Q16.16-style split pair at
// offsets 0x18/0x38, 0x1A/0x3A, 0x1C/0x3C (reconstructed as
// hi*65536+lo, scaled by 2^-16) when D_800C3E90 is set, or a plain
// vec3 f32 at 0x30/0x34/0x38 otherwise - note offset 0x38 is shared
// between the two representations (the low half of the third
// fixed-point pair and the third float's bytes overlap), so this is
// genuinely a union at that offset, not a struct layout error.
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15142314.s")
// void func_15142314(void *arg0, s32 arg1, f32 *arg2) {
//     void *v0;
//
//     v0 = (char *) arg0 + (arg1 << 6);
//     if (D_800C3E90 != 0) {
//         arg2[0] = ((f32) ((s32) (*(s16 *) ((char *) v0 + 0x18)) << 16) +
//                    (f32) (*(s16 *) ((char *) v0 + 0x38))) * (1.0f / 65536.0f);
//         arg2[1] = ((f32) ((s32) (*(s16 *) ((char *) v0 + 0x1A)) << 16) +
//                    (f32) (*(s16 *) ((char *) v0 + 0x3A))) * (1.0f / 65536.0f);
//         arg2[2] = ((f32) ((s32) (*(s16 *) ((char *) v0 + 0x1C)) << 16) +
//                    (f32) (*(s16 *) ((char *) v0 + 0x3C))) * (1.0f / 65536.0f);
//     } else {
//         arg2[0] = *(f32 *) ((char *) v0 + 0x30);
//         arg2[1] = *(f32 *) ((char *) v0 + 0x34);
//         arg2[2] = *(f32 *) ((char *) v0 + 0x38);
//     }
// }
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Wraps arg0 into a
// quarter-circle index [0,0x40) with mirroring, then looks up D_8009A220
// with a sign flip depending on which quadrant (top 2 bits of arg0) it
// came from - a sine-style lookup table. Content and structure are
// otherwise exact (confirmed against the real, already-matched callers
// in game_15F680.c/game_1DD500.c/game_E8C10.c: this really is
// f32 func_151423D8(u8 arg0)) but the quadrant mask (arg0 & 0xC0) lands
// in a reused $a0 instead of target's fresh $t0 - tried a separate
// hoisted alias variable, didn't change the allocation.
f32 func_151423D8(u8 arg0) {
    s32 idx;
    u8 q;

    if (arg0 & 0x40) {
        idx = 0x40 - (arg0 & 0x3F);
    } else {
        idx = arg0 & 0x3F;
    }
    q = arg0 & 0xC0;
    if (q == 0 || q == 0xC0) {
        return D_8009A220[idx];
    }
    return -D_8009A220[idx];
}
// f32 func_151423D8(u8 arg0) {
//     s32 idx;
//
//     if (arg0 & 0x40) {
//         idx = 0x40 - (arg0 & 0x3F);
//     } else {
//         idx = arg0 & 0x3F;
//     }
//     if ((arg0 & 0xC0) == 0 || (arg0 & 0xC0) == 0xC0) {
//         return D_8009A220[idx];
//     }
//     return -D_8009A220[idx];
// }
// NON-MATCHING: mips_to_c reconstruction, hand-typed. If arg0 is a real
// id (!=0xFF) and arg1 already matches it (non-null, alive, same
// unique_id), or arg0==0xFF (use arg1 as-is), returns arg1 when it's
// "ready" (unk1D4 set), else 0. Otherwise falls back to looking the
// object up fresh via func_15083E90(arg0). Logic and branch shapes
// (including the guard-chain "||"-to-search jumps) match target, but
// target hoists a v0=a0 alias unconditionally in the outer bne's delay
// slot and keeps arg0's masked value in $v0 throughout, while this
// reconstruction gets it allocated into $a2 instead - a pervasive
// register-choice difference (not just one instruction) that cascades
// through most of the function; didn't find a source form that steers
// IDO toward $v0 specifically.
struct127 *func_15142444(u8 arg0, struct127 *arg1) {
    struct127 *v0;

    if (arg0 == 0xFF) {
        if (arg1->unk1D4 != 0) {
            return arg1;
        }
        return 0;
    }
    if (arg1 != 0 && arg1->interaction_state != 0 && arg1->unique_id == arg0) {
        if (arg1->unk1D4 != 0) {
            return arg1;
        }
        return 0;
    }
    v0 = func_15083E90();
    if (v0 != 0 && v0->unk1D4 != 0) {
        return v0;
    }
    return 0;
}
// struct127 *func_15142444(u8 arg0, struct127 *arg1) {
//     struct127 *v0;
//
//     if (arg0 == 0xFF) {
//         if (arg1->unk1D4 == 0) {
//             return 0;
//         }
//         return arg1;
//     }
//     if (arg1 == 0 || arg1->interaction_state == 0 || arg0 != arg1->unique_id) {
//         goto search;
//     }
//     if (arg1->unk1D4 == 0) {
//         return 0;
//     }
//     return arg1;
//
// search:
//     v0 = func_15083E90(arg0);
//     if (v0 == 0) {
//         return 0;
//     }
//     if (v0->unk1D4 == 0) {
//         return 0;
//     }
//     return v0;
// }
void func_151424F4(Mtx *m, f32 scale02, f32 scale1, f32 rotX, f32 rotY, f32 rotZ, f32 scaleX, f32 scaleY, f32 scaleZ, f32 transX, f32 transY, f32 transZ) {
    f32 mtx[4][4];

    func_150A8050(&mtx, rotX, rotY, rotZ);
    mtx[3][0] = transX;
    mtx[3][1] = transY;
    mtx[3][2] = transZ;
    mtx[0][0] *= scaleX * scale02;
    mtx[0][1] *= scaleY * scale02;
    mtx[0][2] *= scaleZ * scale02;
    mtx[1][0] *= scaleX * scale1;
    mtx[1][1] *= scaleY * scale1;
    mtx[1][2] *= scaleZ * scale1;
    mtx[2][0] *= scaleX * scale02;
    mtx[2][1] *= scaleY * scale02;
    mtx[2][2] *= scaleZ * scale02;
    guMtxF2L(&mtx, m);
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15142600.s")
void func_15142838(Mtx *m, f32 scale02, f32 scale1, f32 rotX, f32 rotY, f32 rotZ, f32 transX, f32 transY, f32 transZ) {
    f32 mtx[4][4];

    func_150A8050(&mtx, rotX, rotY, rotZ);
    mtx[3][0] = transX;
    mtx[3][1] = transY;
    mtx[3][2] = transZ;
    mtx[0][0] *= scale02;
    mtx[0][1] *= scale02;
    mtx[0][2] *= scale02;
    mtx[1][0] *= scale1;
    mtx[1][1] *= scale1;
    mtx[1][2] *= scale1;
    mtx[2][0] *= scale02;
    mtx[2][1] *= scale02;
    mtx[2][2] *= scale02;
    guMtxF2L(&mtx, m);
}
void func_15142914(f32 mtx[4][4], f32 scale02, f32 scale1, f32 rotX, f32 rotY, f32 rotZ, f32 transX, f32 transY, f32 transZ) {
    func_150A8050(mtx, rotX, rotY, rotZ);
    mtx[3][0] = transX;
    mtx[3][1] = transY;
    mtx[3][2] = transZ;
    mtx[0][0] *= scale02;
    mtx[0][1] *= scale02;
    mtx[0][2] *= scale02;
    mtx[1][0] *= scale1;
    mtx[1][1] *= scale1;
    mtx[1][2] *= scale1;
    mtx[2][0] *= scale02;
    mtx[2][1] *= scale02;
    mtx[2][2] *= scale02;
}
// Looks up a packed RGB triplet from D_8008A160 (12 bytes per arg0,
// 4 sub-entries of 3 bytes each selected by func_150ADA20()&3) and
// unpacks it into *arg1/*arg2/*arg3.
void func_151429E0(u8 arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *entry = &D_8008A160[arg0 * 12 + (func_150ADA20() & 3) * 3];

    *arg1 = entry[0];
    *arg2 = entry[1];
    *arg3 = entry[2];
}
// Returns 1 if arg0->unk2D0->unk3C > 0, else 0 (unk2D0 is struct197*, but
// struct197 isn't currently mapped out to offset 0x3C, so used a raw
// pointer cast instead of extending it speculatively).
s32 func_15142A5C(struct127 *arg0) {
    void *v0 = arg0->unk2D0;

    if (*(s16 *) ((char *) v0 + 0x3C) > 0) {
        return 1;
    }
    return 0;
}
extern f32 D_800A5624;

f32 func_15142A80(f32 arg0) {
    return (1.0f - arg0) * (arg0 - 2.0f) * arg0 * D_800A5624;
}
f32 func_15142AC0(f32 arg0) {
    return (arg0 + 1.0f) * (arg0 - 1.0f) * (arg0 - 2.0f) * 0.5f;
}
f32 func_15142B04(f32 arg0) {
    return (2.0f - arg0) * (arg0 + 1.0f) * arg0 * 0.5f;
}
extern f32 D_800A5628;

f32 func_15142B44(f32 arg0) {
    return (arg0 + 1.0f) * (arg0 - 1.0f) * arg0 * D_800A5628;
}
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Writes up to two
// "othermode" gfx display-list commands into arg0's buffer, one per
// bitmask (arg2 against D_800DD200, arg1 against D_800DD1FC), only for
// bits not already set in the tracked global state, then updates that
// state. Returns the advanced write pointer. Content matches target
// exactly (including hoisting a "p = arg0" alias unconditionally before
// the first check, per the func_1513B0B8 pattern) but IDO schedules the
// store/increment/global-update triple within each block in a different
// relative order than source - same 3 instructions, just rotated.
Gfx *func_15142B7C(Gfx *gdl, u32 set, u32 clear) {
    if (~D_800DD200 & clear) {
        gSPClearGeometryMode(gdl++, clear);
        D_800DD200 |= clear;
    }
    if (~D_800DD1FC & set) {
        gSPSetGeometryMode(gdl++, set);
        D_800DD1FC |= set;
    }
    return gdl;
}
// void *func_15142B7C(void *arg0, s32 arg1, s32 arg2) {
//     void *p = arg0;
//
//     if ((~D_800DD200) & arg2) {
//         *(u32 *) p = 0xD9000000 | (~arg2 & 0xFFFFFF);
//         arg0 = (char *) arg0 + 8;
//         *(u32 *) ((char *) p + 4) = 0;
//         D_800DD200 |= arg2;
//     }
//     if ((~D_800DD1FC) & arg1) {
//         p = arg0;
//         arg0 = (char *) arg0 + 8;
//         *(u32 *) p = 0xD9FFFFFF;
//         *(u32 *) ((char *) p + 4) = arg1;
//         D_800DD1FC |= arg1;
//     }
//     return arg0;
// }
// NON-MATCHING: gfx-command-emission cache/diff wrapper, same family
// as func_15142B7C above but comparing 4 tracked VALUES (not bitmask
// bits) against cached shorts D_800DD1C8/CA/CC/CE. If any of
// arg1/arg2/arg3/arg4 differs from its cached counterpart: optionally
// emits a 0xE7000000 "reset" command (gated on a byte flag at *arg5,
// cleared afterward), then always emits a packed 0xFB000000 command
// whose second word is the 4 values packed into bytes (arg1<<24 |
// arg2<<16 | arg3<<8 | arg4), advances the buffer pointer by 8 for
// each command emitted, and updates all 4 cached shorts. Returns the
// unchanged pointer if all 4 already matched.
// extern s16 D_800DD1C8;
// extern s16 D_800DD1CA;
// extern s16 D_800DD1CC;
// extern s16 D_800DD1CE;
//
// void *func_15142C10(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
//     void *p;
//     u8 flag;
//
//     if (arg1 != D_800DD1C8 || arg2 != D_800DD1CA || arg3 != D_800DD1CC || arg4 != D_800DD1CE) {
//         flag = *(u8 *) arg5;
//         if (flag == 1) {
//             *(u32 *) arg0 = 0xE7000000;
//             *(u32 *) ((char *) arg0 + 4) = 0;
//             arg0 = (char *) arg0 + 8;
//             *(u8 *) arg5 = 0;
//         }
//         p = arg0;
//         *(u32 *) p = 0xFB000000;
//         *(u32 *) ((char *) p + 4) = ((arg1 & 0xFF) << 24) | ((arg2 & 0xFF) << 16) | ((arg3 & 0xFF) << 8) | (arg4 & 0xFF);
//         arg0 = (char *) arg0 + 8;
//         D_800DD1C8 = arg1;
//         D_800DD1CA = arg2;
//         D_800DD1CC = arg3;
//         D_800DD1CE = arg4;
//     }
//     return arg0;
// }
// 54 vs target's 56 instructions - two fewer (a "smarter than
// target" near-miss). Every instruction present corresponds 1:1 with
// a target instruction (same relocations, same shift/mask/or chain,
// same branch structure), just with consistently renamed registers
// (target keeps arg5's pointer in $v1 and the flag byte in $t1; this
// keeps them in $a0/$v1 respectively) - the established "pure
// register-renaming" near-miss category. The two missing instructions
// trace to target's own func_15142B7C-documented `p = arg0` alias
// idiom: target explicitly re-materializes `a0 = s0` right before the
// first (flag-gated) command write, keeping that alias as a genuinely
// separate register from the mutated `arg0`/buffer pointer. Adding an
// explicit `p = arg0` there (or hoisting it to the top of the
// function, matching the sibling's fix exactly) got optimized away or
// changed the register-allocation strategy entirely (dropped the
// $s0/stack-frame use altogether) rather than reproducing target's
// specific redundant move - left as the closest natural form.
extern s16 D_800DD1C8;
extern s16 D_800DD1CA;
extern s16 D_800DD1CC;
extern s16 D_800DD1CE;

Gfx *func_15142C10(Gfx *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5) {
    if (arg1 != D_800DD1C8 || arg2 != D_800DD1CA || arg3 != D_800DD1CC || arg4 != D_800DD1CE) {
        if (*arg5 == 1) {
            gDPPipeSync(arg0++);
            *arg5 = 0;
        }
        gDPSetEnvColor(arg0++, arg1, arg2, arg3, arg4);
        D_800DD1C8 = arg1;
        D_800DD1CA = arg2;
        D_800DD1CC = arg3;
        D_800DD1CE = arg4;
    }
    return arg0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15142CF0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15142E24.s")
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Skips (returns
// arg0 unchanged) if arg1/arg2 already match the cached
// D_800DD218/D_800DD21C values. Otherwise, if *arg3==1, emits a
// RDPPIPESYNC command and clears the flag; then always emits a "set"
// command carrying arg1 (rounded up to a multiple of 0x10, masked to 24
// bits) and arg2, and updates the cache. Returns the advanced pointer.
// Content matches for the first ~5 words, but target's second guard
// (arg2 == D_800DD21C) compiles to a direct beql-to-return, while every
// source form tried here (&&, nested if) instead compiles to a second
// bnel-to-skip matching the first guard's shape - possibly the same
// "IDO's branch-likely selection depends on more than the literal
// condition" issue documented for func_1516434C's investigation
// earlier in this project. Target's final write block also keeps a
// separate v0=arg0 alias for the two stores where this reconstruction
// gets CSE'd back down to using arg0 directly (same category as the
// func_15142B7C/func_1513B0B8-adjacent aliasing quirks).
Gfx *func_15142FBC(Gfx *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    if ((arg1 != D_800DD218) || (arg2 != D_800DD21C)) {
        if (*arg3 == 1) {
            gDPPipeSync(arg0++);
            *arg3 = 0;
        }
        gDPSetOtherMode(arg0++, arg1 | 0xF, arg2);
        D_800DD218 = arg1;
        D_800DD21C = arg2;
    }
    return arg0;
}
// void *func_15142FBC(void *arg0, s32 arg1, s32 arg2, u8 *arg3) {
//     void *v0;
//
//     if (arg1 == D_800DD218 && arg2 == D_800DD21C) {
//         return arg0;
//     }
//     if (*arg3 == 1) {
//         v0 = arg0;
//         arg0 = (char *) arg0 + 8;
//         *(u32 *) v0 = 0xE7000000;
//         *(u32 *) ((char *) v0 + 4) = 0;
//         *arg3 = 0;
//     }
//     v0 = arg0;
//     *(u32 *) v0 = 0xEF000000 | ((arg1 | 0xF) & 0xFFFFFF);
//     *(u32 *) ((char *) v0 + 4) = arg2;
//     arg0 = (char *) arg0 + 8;
//     D_800DD218 = arg1;
//     D_800DD21C = arg2;
//     return arg0;
// }
s16 func_15143044(u8 arg0, s32 arg1) {
    return 0x7FFF - arg0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_1514306C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15143134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_151432BC.s")

// void func_151432BC(struct208 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
//     struct209 tmp;
//     f32 temp_f2;
//     f32 temp_f6;
//     f32 temp_ret;
//     s32 temp_t6;
//     u8 temp_a0;
//
//     temp_t6 = (arg0->unk15) & 3;
//     if (temp_t6 == 0) {
//         tmp.unk1B = random_u32();
//         tmp.unk14 = func_151423D8((tmp.unk1B - 64) & 0xFF);
//         tmp.unk10 = func_151423D8(tmp.unk1B);
//         temp_ret = random_float();
//         temp_f2 = temp_ret * arg0->unk6;
//         *arg1 = (arg0->unk0 + (temp_f2 * tmp.unk10));
//         *arg2 = (arg0->unk4 - (temp_f2 * tmp.unk14));
//         *arg3 = (arg0->unk2 + arg0->unk8);
//         *arg4 = arg0->unk2;
//     } else if (temp_t6 != 1) {
//         if (temp_t6 == 2) {
//             tmp.unk2F = (u32) (arg0->unk10 * D_800A5644); // 0.7111111283302307
//             tmp.unk28 = func_151423D8((tmp.unk2F - 64));
//             tmp.unk24 = func_151423D8(tmp.unk2F);
//             tmp.unk20 = (random_float() * (2.0f * (f32) arg0->unk6)) + (f32) -(s32) arg0->unk6;
//             temp_f2 = (random_float() * (2.0f * (f32) arg0->unkA)) + (f32) -(s32) arg0->unkA;
//             temp_f6 = temp_f2 * tmp.unk24;
//             *arg1 = (arg0->unk0 + ((tmp.unk20 * tmp.unk24) + (temp_f2 * tmp.unk28)));
//             *arg2 = (arg0->unk4 + (temp_f6 - (tmp.unk20 * tmp.unk28)));
//             *arg3 = (arg0->unk2 + arg0->unk8);
//             *arg4 = arg0->unk2;
//         } else {
//             *arg1 = arg0->unk0;
//             *arg2 = arg0->unk4;
//             *arg3 = (arg0->unk2 + arg0->unk8);
//             *arg4 = (arg0->unk2 - arg0->unk8);
//         }
//     } else {
//         tmp.unkB = random_u32();
//         tmp.unk4 = func_151423D8((tmp.unkB - 64));
//         tmp.unk0 = func_151423D8(tmp.unkB);
//         temp_ret = random_float();
//         temp_f2 = temp_ret * (f32) arg0->unk6;
//         *arg1 = (arg0->unk0 + (temp_f2 * tmp.unk0));
//         *arg2 = (arg0->unk4 - (temp_f2 * tmp.unk4));
//         *arg3 = (arg0->unk2 + arg0->unk8);
//         *arg4 = (arg0->unk2 - arg0->unk8);
//     }
// }


void func_151436B4(f32 arg0, f32 arg1, f32 arg2, f32 *arg3) {
    f32 cos0 = cosf(arg0);
    f32 sin0 = sinf(arg0);
    f32 cos1 = cosf(arg1);
    f32 sin1 = sinf(arg1);
    f32 tmp = arg2 * cos1;

    arg3[0] = tmp * sin0;
    arg3[1] = -arg2 * sin1;
    arg3[2] = tmp * cos0;
}
void func_1514373C(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    f32 c = cosf(arg0);
    f32 s = sinf(arg0);

    *arg2 = arg1 * s;
    *arg3 = arg1 * c;
}
void func_15143794(s16 arg0, s16 arg1, f32 arg2, void *arg3) {
    f32 r1 = func_151423D8((u8) arg0);
    f32 r2 = func_151423D8((u8) (arg0 - 0x40));
    f32 r3 = func_151423D8((u8) arg1);
    f32 r4 = func_151423D8((u8) (arg1 - 0x40));
    f32 tmp = arg2 * r3;

    ((f32 *) arg3)[0] = tmp * r2;
    ((f32 *) arg3)[1] = -arg2 * r4;
    ((f32 *) arg3)[2] = tmp * r1;
}

void func_15143834(s16 arg0, s16 arg1, f32 arg2, void *arg3) {
    func_15143794(arg0, arg1, arg2, arg3);
}
void func_15143874(s16 arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    f32 sp1C = func_151423D8((u8) arg0);
    f32 sp18 = func_151423D8((u8) (arg0 - 0x40));

    *arg2 = arg1 * sp18;
    *arg3 = arg1 * sp1C;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_151438D8.s")
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Clamps *arg0/*arg1
// into range [arg2, arg3] (after ensuring arg2<=arg3 and *arg0<=*arg1
// via XOR swaps - confirmed genuine XOR swaps from the raw asm, not
// temp-based). Content matches exactly, but target keeps arg0/arg1 in
// callee-saved $s0/$s1 across the whole function (with the matching
// push/pop), while this reconstruction keeps them in $a0/$a1/$v0/$v1
// instead - same unresolved "why does target promote this pointer to a
// saved register" category as elsewhere in this file.
void func_15143D18(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    if (arg3 < arg2) {
        arg2 ^= arg3 ^= arg2 ^= arg3;
    }
    if (*arg1 < *arg0) {
        *arg0 ^= *arg1 ^= *arg0 ^= *arg1;
    }
    if (*arg0 < arg2) {
        *arg0 = arg2;
    }
    if (arg3 < *arg1) {
        *arg1 = arg3;
    }
}
// void func_15143D18(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
//     s32 v1;
//     s32 tmp;
//
//     if (arg3 < arg2) {
//         v1 = arg2 ^ arg3;
//         tmp = arg3 ^ v1;
//         arg3 = tmp;
//         arg2 = v1 ^ tmp;
//     }
//     if (*arg1 < *arg0) {
//         *arg0 ^= *arg1;
//         *arg1 ^= *arg0;
//         *arg0 ^= *arg1;
//     }
//     if (*arg0 < arg2) {
//         *arg0 = arg2;
//     }
//     if (arg3 < *arg1) {
//         *arg1 = arg3;
//     }
// }
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Clamps *arg0 into
// [min(arg1,arg2), max(arg1,arg2)], swapping arg1/arg2 first if needed
// (target genuinely uses an XOR swap, confirmed from the raw asm - tried
// matching it exactly, still didn't converge). Register allocation and
// a missing dead prologue spill differ from target throughout.
// NON-MATCHING (20 of 20 words): clamps *arg0 into the range spanned by
// arg1 and arg2, returning 1 if it was raised to the low bound, 2 if it
// was lowered to the high bound, and 0 if it was already inside.  The
// semantics are certain but the codegen is a long way off: target homes
// arg0 to 0x0($sp) with no frame and reloads it twice, and swaps arg1
// and arg2 with the three-XOR trick rather than through a temporary.
// This build keeps arg0 in $a0 throughout and swaps via $v0, which is
// what the obvious source produces.  -O1 and -g are both much worse
// (23 of 24), so the file's -O2 -g3 is right and this is an allocator
// difference, not a flag one.
// s32 func_15143DA8(s32 *arg0, s32 arg1, s32 arg2) {
//     s32 v0;
//     s32 t;
//
//     if (arg2 < arg1) {
//         t = arg1;
//         arg1 = arg2;
//         arg2 = t;
//     }
//     v0 = *arg0;
//     if (v0 < arg1) {
//         *arg0 = arg1;
//         return 1;
//     }
//     if (arg2 < v0) {
//         *arg0 = arg2;
//         return 2;
//     }
//     return 0;
// }
s32 func_15143DA8(s32 *arg0, s32 arg1, s32 arg2) {
    s32 **p = &arg0;
    if (arg2 < arg1) {
        arg1 ^= arg2 ^= arg1 ^= arg2;
    }
    if (**p < arg1) {
        **p = arg1;
        return 1;
    }
    if (arg2 < **p) {
        **p = arg2;
        return 2;
    }
    return 0;
}
// s32 func_15143DA8(s32 *arg0, s32 arg1, s32 arg2) {
//     s32 v0;
//     s32 tmp;
//
//     if (arg2 < arg1) {
//         tmp = arg1;
//         arg1 = arg2;
//         arg2 = tmp;
//     }
//     v0 = *arg0;
//     if (v0 < arg1) {
//         *arg0 = arg1;
//         return 1;
//     }
//     if (arg2 < v0) {
//         *arg0 = arg2;
//         return 2;
//     }
//     return 0;
// }

s32 func_15143E08(struct127 *arg0) {
    return (((s32) arg0->unk7A >> 8) + 64) & 0xFF;
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Sibling of
// func_15143E08 above - subtracts arg0->unk31C->unk12 from arg0->unk7A
// when unk31C is non-null, else just uses unk7A, then returns the result
// >>8. Target uses a branch-likely with the "else" value computed in the
// (nullified-when-taken) delay slot, funneling both paths through a
// shared >>8 epilogue; this reconstruction's if/else produced different
// register allocation and instruction count throughout.
s16 func_15143E24(void *arg0) {
    void *v1;

    v1 = *(void **) ((char *) arg0 + 0x31C);
    if (v1 != 0) {
        return (*(u16 *) ((char *) arg0 + 0x7A) - *(s16 *) ((char *) v1 + 0x12)) >> 8;
    }
    return *(u16 *) ((char *) arg0 + 0x7A) >> 8;
}
// s16 func_15143E24(struct127 *arg0) {
//     s32 v0;
//
//     if (arg0->unk31C != 0) {
//         v0 = arg0->unk7A - arg0->unk31C->unk12;
//     } else {
//         v0 = arg0->unk7A;
//     }
//     return v0 >> 8;
// }
f32 func_15143E64(vertex *arg0) {
    return sqrtf(arg0->x * arg0->x + arg0->y * arg0->y + arg0->z * arg0->z);
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15143E94.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_1514401C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_151441A4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_151442FC.s")
// NON-MATCHING: mips_to_c reconstruction, hand-typed. A wraparound-range
// clamp: subtracts (arg1-arg2+1) from arg0 while arg0>arg1, then adds it
// back while arg0<arg2. Matches target's control-flow shape (subtract-
// or-add once unconditionally, then loop) but compiles to noticeably
// more instructions than target throughout both loops - didn't find the
// exact source form this round.
s32 func_151444DC(s32 arg0, s32 arg1, s32 arg2) {
    s32 range;

    if (arg1 < arg0) {
        range = arg1 - arg2 + 1;
        do {
            arg0 -= range;
        } while (arg1 < arg0);
    }
    if (arg0 < arg2) {
        range = arg1 - arg2 + 1;
        do {
            arg0 += range;
        } while (arg0 < arg2);
    }
    return arg0;
}
// s32 func_151444DC(s32 arg0, s32 arg1, s32 arg2) {
//     s32 v0;
//
//     if (arg1 < arg0) {
//         v0 = arg1 - arg2 + 1;
//         arg0 -= v0;
//         while (arg1 < arg0) {
//             arg0 -= v0;
//         }
//     }
//     if (arg0 < arg2) {
//         v0 = arg1 - arg2 + 1;
//         arg0 += v0;
//         while (arg0 < arg2) {
//             arg0 += v0;
//         }
//     }
//     return arg0;
// }
f32 func_15144528(f32 arg0, f32 arg1, f32 arg2) {
    f32 range;

    if (arg1 < arg0) {
        range = arg1 - arg2;
        do {
            arg0 -= range;
        } while (arg1 < arg0);
    }
    if (arg0 < arg2) {
        range = arg1 - arg2;
        do {
            arg0 += range;
        } while (arg0 < arg2);
    }
    return arg0;
}
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Struct unidentified
// here - raw offset casts. Selects a computation based on arg0's unk15 &
// 3: cases 0 and 1 share the same tail (unk6^2 * D_800A5694), case 2
// returns 1.0f, case 3 returns unk6*unkA*4.0f. Target tests each case
// with its own independent branch (case 0 via beql, case 1 via a
// separate beq that falls into the same tail, case 2 via its own beq);
// both an if-elseif chain and a switch here get compiled into a
// different decision tree (testing sel!=0 first, then disambiguating)
// since IDO recognizes cases 0 and 1 produce the same result and merges
// the tests - didn't find a source form that keeps them separate.
f32 func_15144598(void *arg0) {
    f32 result;

    switch (*((u8 *) arg0 + 0x15) & 3) {
        default:
            result = 1.0f;
            break;
        case 2:
            result = (f32) (*(s16 *) ((char *) arg0 + 0xA) * *(s16 *) ((char *) arg0 + 0x6)) * 4.0f;
            break;
        case 1:
        case 0:
            result = (f32) (*(s16 *) ((char *) arg0 + 0x6) * *(s16 *) ((char *) arg0 + 0x6)) * D_800A5694;
            break;
    }
    return result;
}
// f32 func_15144598(void *arg0) {
//     s32 sel = *((u8 *) arg0 + 0x15) & 3;
//     s16 v0;
//
//     switch (sel) {
//         case 0:
//             v0 = *(s16 *) ((char *) arg0 + 0x6);
//             break;
//         case 1:
//             v0 = *(s16 *) ((char *) arg0 + 0x6);
//             break;
//         case 2:
//             return 1.0f;
//         default:
//             return (f32) (*(s16 *) ((char *) arg0 + 0x6) * *(s16 *) ((char *) arg0 + 0xA)) * 4.0f;
//     }
//     return (f32) (v0 * v0) * D_800A5694;
// }
// NON-MATCHING: same unk15&3 dispatch idiom as func_15144598 just
// above, but all four cases compute genuinely different values here
// (no case-merging): 0 -> unk6^2 * D_800A5698 * unk8, 1 -> unk6^3 *
// D_800A569C, 2 -> unk6*unk8*unkA, default -> 1.0f.
// f32 func_1514462C(void *arg0) {
//     s32 sel = *((u8 *) arg0 + 0x15) & 3;
//     s16 v0;
//     f32 x;
//     f32 result;
//
//     result = 1.0f;
//     if (sel == 0) {
//         v0 = *(s16 *) ((char *) arg0 + 0x6);
//         result = (f32) (v0 * v0) * D_800A5698 * (f32) (*(s16 *) ((char *) arg0 + 0x8));
//     }
//     if (sel == 1) {
//         x = (f32) *(s16 *) ((char *) arg0 + 0x6);
//         result = (x * D_800A569C) * x * x;
//     }
//     if (sel == 2) {
//         result = (f32) (*(s16 *) ((char *) arg0 + 0x6) * *(s16 *) ((char *) arg0 + 0x8) * *(s16 *) ((char *) arg0 + 0xA));
//     }
//     return result;
// }
// 55 vs target's 56 instructions - one fewer (a "smarter than target"
// near-miss), landed by giving `result` a default value up front and
// writing each case as an independent guard rather than a switch or
// if/else-if chain (both of those, like the sibling func_15144598
// just above, compiled to a noticeably different decision tree).
struct func_1514462C_s {
    u8 pad0[6];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[9];
    u8 unk15;
};

f32 func_1514462C(struct func_1514462C_s *arg0) {
    f32 result;
    f32 x;

    switch (arg0->unk15 & 3) {
        default:
            result = 1.0f;
            break;
        case 2:
            result = arg0->unk6 * arg0->unk8 * arg0->unkA;
            break;
        case 0:
            result = (f32) (arg0->unk6 * arg0->unk6) * D_800A5698 * arg0->unk8;
            break;
        case 1:
            x = arg0->unk6;
            result = x * D_800A569C * x * x;
            break;
    }
    return result;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_1514470C.s")
f32 func_15144A74(vertex *arg0, vertex *arg1) {
    return arg0->x * arg1->x + arg0->y * arg1->y + arg0->z * arg1->z;
}
f32 func_15144AA8(s32 arg0) {
    f32 v = *(f32 *) ((char *) D_800DBFF0 + arg0 * 2464 + 0x380);

    if (v > 360.0f) {
        do {
            v -= 360.0f;
        } while (v > 360.0f);
    }
    if (v < 0.0f) {
        do {
            v += 360.0f;
        } while (v < 0.0f);
    }
    return v;
}
// D_800DBFF0 is struct108[]; arg0 selects an element and this returns a
// pointer to its field at offset 0x2F8 (per func_151454BC below, that
// field is a struct17 - a vec3-like x/y/z position).
struct17 *func_15144B34(s32 arg0) {
    return (struct17 *) (arg0 * 2464 + (char *) D_800DBFF0 + 0x2F8);
}
// NON-MATCHING: 23 of 24 instructions byte-identical (confirmed via
// isolated harness) - assigning arg0 into a local `v` up front (rather
// than mutating arg0 in place) fixed the previously-documented $f2/
// $f12 register-allocation gap entirely; the same fix landed the
// identical-shape func_15144BC8 right below byte-perfect in one try
// (that one wraps into [0,360) via a literal constant; this one wraps
// into [0, D_800A56A4) - confirmed 6.283185482, i.e. 2*PI radians, not
// degrees - via its rodata value). The one remaining gap: target
// schedules `c.lt.s $f0,$f12` (the loop guard, depending on the
// just-loaded D_800A56A4) immediately after the `lwc1`, with
// `mov.s $f2,$f12` (the independent arg0->v copy) pushed one slot
// later; every source form tried here (original write order, reversed
// comparison operand order) schedules the independent mov.s first
// instead - a load-latency scheduling choice, immune to source
// reordering. Widely referenced (real prototype already in
// functions.h) - many other functions depend on its correct
// *behavior*, which this reconstruction now has exactly.
// NON-MATCHING (2 real words): wraps a float into [0, D_800A56A4) by
// repeated subtraction then repeated addition.  24 of 24 instructions,
// and only the first two differ - target emits `c.lt.s $f0, $f12`
// before `mov.s $f2, $f12`, this build emits them the other way round.
// Both orders are equivalent (the copy exists only because $f12 is then
// reused for the 0.0 constant), and dropping the local to work on arg0
// directly is much worse (15 of 24), so the schedule is IDO's.
// f32 func_15144B68(f32 arg0) {
//     f32 x;
//
//     x = arg0;
//     if (D_800A56A4 < x) {
//         do {
//             x -= D_800A56A4;
//         } while (D_800A56A4 < x);
//     }
//     if (x < 0.0f) {
//         do {
//             x += D_800A56A4;
//         } while (x < 0.0f);
//     }
//     return x;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15144B68.s")
// f32 func_15144B68(f32 arg0) {
//     f32 v = arg0;
//
//     while (v > D_800A56A4) {
//         v -= D_800A56A4;
//     }
//     while (v < 0.0f) {
//         v += D_800A56A4;
//     }
//     return v;
// }
f32 func_15144BC8(f32 arg0) {
    f32 v;

    v = arg0;
    while (v > 360.0f) {
        v -= 360.0f;
    }
    while (v < 0.0f) {
        v += 360.0f;
    }
    return v;
}

s32 func_15144C2C(s16 arg0) {
    s16 tmp1 = arg0;

    while (tmp1 >= 256)
    {
        tmp1 -= 255;
    }
    while (tmp1 < 0)
    {
        tmp1 += 255;
    }

    return tmp1;
}

f32 func_15144C8C(f32 arg0, f32 arg1) {
    f32 tmp;

    arg0 = func_15144B68(arg0);
    tmp = fabsf(arg0 - func_15144B68(arg1));
    if (D_800A56A8 < tmp) {
        tmp = D_800A56AC - tmp;
    }
    return tmp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15144CEC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15144E80.s")

void func_151450B4(struct17 *arg0, struct17 *arg1, struct17 *arg2) {
    arg2->unk0 = arg0->unk4 * arg1->unk8 - arg0->unk8 * arg1->unk4;
    arg2->unk4 = arg0->unk8 * arg1->unk0 - arg0->unk0 * arg1->unk8;
    arg2->unk8 = arg0->unk0 * arg1->unk4 - arg0->unk4 * arg1->unk0;
}

// NON-MATCHING: 47 of 50 words byte-identical (confirmed via isolated
// harness), including every branch, every float op, and even the
// duplicate sqrt.s target genuinely emits in the arg2!=NULL path.
// Vector-normalizes arg0 into arg1 via reciprocal magnitude: if arg3
// is NULL, redirects it to a local stack slot; computes
// mag2=x^2+y^2+z^2, returning 0 if it's exactly 0.0f; otherwise takes
// sqrtf(mag2), optionally writing it to *arg2 too, writes 1/mag to
// *arg3, then scales arg0 by *arg3 into arg1 and returns 1. The only
// gap is the stack frame: target reserves just 8 bytes (the single
// f32 local at offset 0), while every source form tried here reserves
// 16 bytes with the local at a nonzero offset - apparently caused by
// having 3 named f32 locals (the local itself, plus mag2 and mag),
// even though the other two live entirely in registers. Removing the
// named mag2/mag locals (relying on IDO's own CSE across three
// repeated inline expressions instead) does shrink the frame to 8
// bytes, but changes which physical registers the sum-of-squares
// computation uses, breaking several already-matching words - a net
// loss, so not applied.
s32 func_15145128(struct17 *arg0, struct17 *arg1, f32 *arg2, f32 *arg3) {
    f32 mag;
    f32 local;

    if (arg3 == NULL) {
        arg3 = &local;
    }
    mag = arg0->unk0 * arg0->unk0 + arg0->unk4 * arg0->unk4 + arg0->unk8 * arg0->unk8;
    if (mag == 0.0f) {
        return 0;
    }
    if (arg2 != NULL) {
        mag = sqrtf(mag);
        *arg2 = mag;
        *arg3 = 1.0f / mag;
    } else {
        mag = sqrtf(mag);
        *arg3 = 1.0f / mag;
    }
    arg1->unk0 = *arg3 * arg0->unk0;
    arg1->unk4 = *arg3 * arg0->unk4;
    arg1->unk8 = *arg3 * arg0->unk8;
    return 1;
}
// s32 func_15145128(struct17 *arg0, struct17 *arg1, f32 *arg2, f32 *arg3) {
//     f32 local;
//     f32 mag2;
//     f32 mag;
//
//     if (arg3 == NULL) {
//         arg3 = &local;
//     }
//     mag2 = arg0->unk0 * arg0->unk0 + arg0->unk4 * arg0->unk4 + arg0->unk8 * arg0->unk8;
//     if (mag2 == 0.0f) {
//         return 0;
//     }
//     if (arg2 != NULL) {
//         mag = sqrtf(mag2);
//         *arg2 = mag;
//         *arg3 = 1.0f / mag;
//     } else {
//         mag = sqrtf(mag2);
//         *arg3 = 1.0f / mag;
//     }
//     arg1->unk0 = *arg3 * arg0->unk0;
//     arg1->unk4 = *arg3 * arg0->unk4;
//     arg1->unk8 = *arg3 * arg0->unk8;
//     return 1;
// }
// NON-MATCHING: boolean range predicate. Calls func_151452C4 (still
// raw asm) relaying most of this function's own params straight
// through; bails false if it returns 0. Otherwise treats p8/p9 as
// f32* and does a short-circuit range check: false if both *p8 and
// *p9 are negative, true if *p8 is non-negative but *p9 is negative,
// otherwise falls through to a final *p8 < p5 comparison. Semantics
// fully traced instruction-by-instruction against target (including
// which comparisons short-circuit and reuse a still-live FP condition
// flag rather than recomputing it) and verified correct.
// s32 func_151451F0(s32 a0, s32 a1, s32 a2, f32 arg3, f32 p5, s32 p6, s32 p7, f32 *p8, f32 *p9) {
//     s32 v0 = func_151452C4(a0, a1, a2, arg3, p6, p7, p8, p9);
//
//     if (v0 == 0) {
//         return 0;
//     }
//     if (*p8 < 0.0f && *p9 < 0.0f) {
//         return 0;
//     }
//     if (*p8 < 0.0f) {
//         /* fall through to final comparison */
//     } else if (*p9 < 0.0f) {
//         return 1;
//     }
//     return (*p8 < p5) ? 1 : 0;
// }
// 53 vs target's 53 instructions - exact count match. Rewriting every
// comparison as a strict `< 0.0f` (matching target's raw c.lt.s
// instructions one-for-one, instead of the mathematically-equivalent
// `>= 0.0f` which compiled to c.le.s with swapped operands) closed
// most of the gap. What's left: the initial `v0 == 0` guard compiles
// inverted (bnez+forward-jump instead of target's direct beqz), the
// 0.0f-constant and *p8 value land in swapped float registers, and
// the third check's branch-likely polarity (bc1tl vs target's bc1fl)
// didn't flip no matter how the guard was phrased (De Morgan negation,
// if/else-if, and a fully nested if/else were all tried; the nested
// form also regressed to redundant reloads of *p9 and p5 in each
// branch, so was discarded). Same branch-polarity/register-numbering
// near-miss family documented elsewhere in this project.
s32 func_151452C4(s32 a0, s32 a1, s32 a2, f32 a3, s32 a4, s32 a5, f32 *a6, f32 *a7);

s32 func_151451F0(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4, s32 a5, s32 a6, f32 *a7, f32 *a8) {
    if (func_151452C4(a0, a1, a2, a3, a5, a6, a7, a8) != 0) {
        if (*a7 < 0.0f && *a8 < 0.0f) {
            return 0;
        }
        if (*a7 >= 0.0f && *a8 < 0.0f) {
            return 1;
        }
        if (*a7 < a4) {
            return 1;
        }
        return 0;
    }
    return 0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_151452C4.s")

s32 func_151454BC(u8 arg0, f32 arg1, struct17 *arg2) {
    f32 tmp1;
    f32 tmp2;
    f32 tmp3;
    struct17 *temp_v0;

    temp_v0 = func_15144B34(arg0);
    tmp1 = arg2->unk0 - temp_v0->unk0;
    tmp2 = arg2->unk4 - temp_v0->unk4;
    tmp3 = arg2->unk8 - temp_v0->unk8;

    if ((arg1 * arg1) < ((tmp1 * tmp1) + (tmp2 * tmp2) + (tmp3 * tmp3))) {
        return 0;
    }
    return 1;
}

// NON-MATCHING: relays through func_1514563C (defaulting arg4 to a
// local scratch float if null, matching the established "output
// pointer with a stack-local fallback" idiom), then copies arg0 into
// *arg3 verbatim if the call failed or the output threshold is
// negative, adds arg0+arg1 into *arg3 if the threshold exceeds 1.0,
// or leaves *arg3 untouched for a threshold in [0.0, 1.0].
// void func_15145548(struct17 *arg0, struct17 *arg1, struct17 *arg2, struct17 *arg3, f32 *arg4) {
//     f32 local;
//     f32 *ptr = arg4;
//     s32 result;
//
//     if (ptr == 0) {
//         ptr = &local;
//     }
//
//     result = func_1514563C(arg0, arg1, arg2, ptr);
//
//     if (result == 0) {
//         arg3->unk0 = arg0->unk0;
//         arg3->unk4 = arg0->unk4;
//         arg3->unk8 = arg0->unk8;
//     } else {
//         f32 threshold = *ptr;
//         if (threshold < 0.0f) {
//             arg3->unk0 = arg0->unk0;
//             arg3->unk4 = arg0->unk4;
//             arg3->unk8 = arg0->unk8;
//         } else if (threshold > 1.0f) {
//             arg3->unk0 = arg0->unk0 + arg1->unk0;
//             arg3->unk4 = arg0->unk4 + arg1->unk4;
//             arg3->unk8 = arg0->unk8 + arg1->unk8;
//         }
//     }
// }
// 61 vs target's 61 instructions - exact count match on the first
// attempt. The only structural difference is register allocation:
// target keeps arg3 alive across the func_1514563C call via a stack
// spill/reload pair instead of a callee-saved register (costing it a
// different, but equal-count, instruction mix), and correspondingly
// uses a smaller 0x28-byte frame versus this reconstruction's 0x30.
s32 func_1514563C(struct17 *a0, struct17 *a1, struct17 *a2, struct17 *a3, f32 *arg4);

void func_15145548(struct17 *arg0, struct17 *arg1, struct17 *arg2, struct17 *arg3, f32 *arg4) {
    f32 local;

    if (arg4 == NULL) {
        arg4 = &local;
    }
    if (func_1514563C(arg0, arg1, arg2, arg3, arg4) != 0) {
        if (*arg4 < 0.0f) {
            *arg3 = *arg0;
        } else if (*arg4 > 1.0f) {
            arg3->unk0 = arg0->unk0 + arg1->unk0;
            arg3->unk4 = arg0->unk4 + arg1->unk4;
            arg3->unk8 = arg0->unk8 + arg1->unk8;
        }
    } else {
        *arg3 = *arg0;
    }
}
// NON-MATCHING: closest-point-on-line-toward-target helper. Computes
// t = (dot(dir,a2) - dot(dir,a0)) / dot(dir,dir), returning 0 for a
// degenerate (zero-length) direction; otherwise writes t to *arg4
// (defaulting to a local scratch float if null, the same fallback
// idiom as the sibling func_15145548) and a0 + t*dir to *a3.
// s32 func_1514563C(struct17 *a0, struct17 *a1, struct17 *a2, struct17 *a3, f32 *arg4) {
//     f32 local;
//     f32 *tp = arg4;
//     f32 denom;
//     f32 t;
//     f32 dotA0, dotA2;
//
//     if (tp == 0) {
//         tp = &local;
//     }
//
//     denom = a1->unk0 * a1->unk0 + a1->unk4 * a1->unk4 + a1->unk8 * a1->unk8;
//
//     if (denom == 0.0f) {
//         return 0;
//     }
//
//     dotA0 = a1->unk0 * a0->unk0 + a1->unk4 * a0->unk4 + a1->unk8 * a0->unk8;
//     dotA2 = a1->unk0 * a2->unk0 + a1->unk4 * a2->unk4 + a1->unk8 * a2->unk8;
//     t = (dotA2 - dotA0) / denom;
//
//     *tp = t;
//
//     a3->unk0 = a0->unk0 + t * a1->unk0;
//     a3->unk4 = a0->unk4 + *tp * a1->unk4;
//     a3->unk8 = a0->unk8 + *tp * a1->unk8;
//
//     return 1;
// }
// 63 vs target's 65 instructions - smarter than target. Reproduced
// target's genuine double-read of *tp for the unk4/unk8 field writes
// (target re-reads the pointer rather than reusing the already-live
// `t` register there, matching the established double-read idiom),
// but target additionally reloads `t` from its own stack home for
// the FIRST field write too, where this reconstruction keeps it
// register-resident - a minor register-residency gap, not chased
// further after a reordering attempt made no difference.
s32 func_1514563C(struct17 *a0, struct17 *a1, struct17 *a2, struct17 *a3, f32 *arg4) {
    f32 denom;
    f32 dotA0;
    f32 dotA2;
    f32 local;
    if (arg4 == NULL) {
        arg4 = &local;
    }
    denom = a1->unk0 * a1->unk0 + a1->unk4 * a1->unk4 + a1->unk8 * a1->unk8;
    if (denom == 0.0f) {
        return 0;
    }
    dotA0 = a1->unk0 * a0->unk0 + a1->unk4 * a0->unk4 + a1->unk8 * a0->unk8;
    dotA2 = a1->unk0 * a2->unk0 + a1->unk4 * a2->unk4 + a1->unk8 * a2->unk8;
    *arg4 = (dotA2 - dotA0) / denom;
    a3->unk0 = *arg4 * a1->unk0 + a0->unk0;
    a3->unk4 = *arg4 * a1->unk4 + a0->unk4;
    a3->unk8 = *arg4 * a1->unk8 + a0->unk8;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15145740.s")
// NON-MATCHING: 90% there
// void func_15145740(struct127 *arg0, struct17 *arg1, struct17 *arg2, struct17 *arg3, f32 arg4) {
//     struct194 tmp;
//     f32 temp_f6;
//     s16 phi_v1;
//     s16 phi_t0;
//
//     if ((arg0->unk4 == 0x96) && ((arg0->unk31C->unk7D != 0))) {
//         phi_t0 = arg0->unk7A + arg0->unk31C->unk80;
//     } else {
//         if (arg0->unk31C != 0) {
//             phi_t0 = arg0->unk7A - arg0->unk31C->unk12;
//         } else {
//             phi_t0 = arg0->unk7A;
//         }
//     }
//     if ((arg0->unk4 == 0x96) && (arg0->unk31C->unk7D != 0)) {
//         phi_v1 = arg0->unk31C->unk82 + 1024;
//     } else {
//         phi_v1 = arg0->unk1D1 * 200;
//     }
//     tmp.unk14 = phi_t0;
//     tmp.unk10 = phi_v1 * 0.005493164f;
//     tmp.unk0 = tmp.unk10 * D_800A56B4;
//     func_1505A184(phi_t0, 2000.0f, tmp.unk10, &arg1->unk0, &arg1->unk8, &arg1->unk4);
//     if (arg2 != 0) {
//         arg2->unk4 = cosf(tmp.unk0) * 1000.0f;
//         temp_f6 = sinf(tmp.unk0) * 1000.0f;
//         tmp.unk8 = temp_f6;
//         tmp.unk4 = phi_t0 * D_800A56B8;
//         arg2->unk0 = cosf(tmp.unk4) * tmp.unk8;
//         arg2->unk8 = sinf(tmp.unk4) * -temp_f6;
//         if (arg3 != 0) {
//             tmp.unkC = tmp.unk0 + arg4;
//             arg3->unk4 = cosf(tmp.unkC) * 1000.0f;
//             tmp.unk8 = sinf(tmp.unkC) * 1000.0f;
//             arg3->unk0 = cosf(tmp.unk4) * tmp.unk8;
//             arg3->unk8 = sinf(tmp.unk4) * -tmp.unk8;
//         }
//     }
// }

void func_15145974(struct17 *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = func_150484A0(arg0->unk0, arg0->unk8) * D_800A56BC;
    if (arg2 != NULL) {
        *arg2 = (func_150484A0(sqrtf(arg0->unk0 * arg0->unk0 + arg0->unk8 * arg0->unk8), arg0->unk4) * D_800A56C0) - 90.0f;
    }
}

f32 func_15145A0C(f32 arg0, f32 arg1, f32 arg2) {
    return D_800A548C[(s32)(arg0 * arg2 * 100.0f)] * arg1;
}


void func_15145A50(struct127 *arg0) {
    arg0->unk5 = 3;
    if (D_800BE9F0 != 51) {
        if ((D_800BE616 != 0) || (arg0->interaction_state == 5) || (arg0->interaction_state == 1) || (arg0->interaction_state == 21)) {
            arg0->interaction_state = 5;
            if (arg0->unk31C != NULL) {
                arg0->unk31C->unk78 = 0;
            }
        } else {
            func_15053694(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15145AD8.s")

u8 func_15145C90(s32 arg0) {
    if (arg0 < 0) {
        return 1;
    } else {
        return (D_800DBEF4[arg0].unk6F & 0x80) == 0x80;
    }
}

// NON-MATCHING: batch vector-transform loop. Builds a local rotation
// matrix via func_150A8050 from arg0's first 3 words (raw-bit floats)
// then overwrites its translation row with arg0's s16 fields at
// 0x10/0x12/0x14 (converted to float). Loops arg3 times over parallel
// pointer arrays arg1[i] (source 3-float vector) and arg2[i]
// (destination, written as 3 separate float* outputs), calling
// func_150A7960(&mtx, x, y, z, &outX, &outY, &outZ) each iteration.
// extern void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);
//
// void func_15145CD0(void *arg0, void **arg1, void **arg2, s32 arg3) {
//     f32 mtx[4][4];
//
//     func_150A8050(&mtx, *(s32 *) arg0, *(s32 *) ((char *) arg0 + 4), *(s32 *) ((char *) arg0 + 8));
//     mtx[3][0] = (f32) *(s16 *) ((char *) arg0 + 0x10);
//     mtx[3][1] = (f32) *(s16 *) ((char *) arg0 + 0x12);
//     mtx[3][2] = (f32) *(s16 *) ((char *) arg0 + 0x14);
//
//     if (arg3 > 0) {
//         do {
//             char *src = (char *) *arg1;
//             char *dst = (char *) *arg2;
//             func_150A7960(&mtx, *(f32 *) src, *(f32 *) (src + 4), *(f32 *) (src + 8),
//                           (f32 *) dst, (f32 *) (dst + 4), (f32 *) (dst + 8));
//             arg1++;
//             arg2++;
//             arg3--;
//         } while (arg3 > 0);
//     }
// }
// 58 vs target's 57 instructions - one extra. Stack frame size,
// setup section, and loop body all match target exactly (same
// relocations, same offsets, same call argument marshalling); the
// gap is a single register-allocation quirk: target reuses the SAME
// register ($s1) sequentially for `arg0`'s config pointer during
// setup and then for the `arg1` array pointer during the loop (their
// live ranges don't overlap), needing only 4 callee-saved registers
// total, while this reconstruction's allocator gives them distinct
// registers (5 total, one extra save/restore pair). Also, target's
// loop-back branch is a plain `bgtz` with the second array pointer's
// increment in its delay slot, while this compiles to a `bgtzl`
// (branch-likely) with a speculative next-iteration reload in the
// delay slot instead - tried reordering the three post-body
// increment statements without effect.
extern void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);
struct func_15145CD0_s { f32 rx, ry, rz; s32 pad; s16 tx, ty, tz; };

void func_15145CD0(struct func_15145CD0_s *arg0, f32 **arg1, f32 **arg2, s32 arg3) {
    f32 mtx[4][4];
    s32 i;

    func_150A8050(mtx, arg0->rx, arg0->ry, arg0->rz);
    mtx[3][0] = arg0->tx;
    mtx[3][1] = arg0->ty;
    mtx[3][2] = arg0->tz;
    for (i = 0; arg3 > 0; i++, arg3--) {
        func_150A7960(mtx, arg1[i][0], arg1[i][1], arg1[i][2], &arg2[i][0], &arg2[i][1], &arg2[i][2]);
    }
}
// NON-MATCHING: batch vector-transform loop, same family as the
// near-miss func_15145CD0 just above but with contiguous 3-float
// array elements (not arrays of pointers) for both the source (arg1)
// and destination (arg2) arrays.
// extern void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);
//
// void func_15145DB4(void *arg0, void *arg1, void *arg2, s32 arg3) {
//     f32 mtx[4][4];
//
//     func_150A8050(&mtx, *(s32 *) arg0, *(s32 *) ((char *) arg0 + 4), *(s32 *) ((char *) arg0 + 8));
//     mtx[3][0] = (f32) *(s16 *) ((char *) arg0 + 0x10);
//     mtx[3][1] = (f32) *(s16 *) ((char *) arg0 + 0x12);
//     mtx[3][2] = (f32) *(s16 *) ((char *) arg0 + 0x14);
//
//     if (arg3 > 0) {
//         do {
//             func_150A7960(&mtx, *(f32 *) arg1, *(f32 *) ((char *) arg1 + 4), *(f32 *) ((char *) arg1 + 8),
//                           (f32 *) arg2, (f32 *) ((char *) arg2 + 4), (f32 *) ((char *) arg2 + 8));
//             arg1 = (char *) arg1 + 0xC;
//             arg2 = (char *) arg2 + 0xC;
//             arg3--;
//         } while (arg3 > 0);
//     }
// }
// 55 vs target's 60 instructions - smarter than target. Landed
// cleanly on the first attempt with the guarded do-while (natural
// plain `bgtz` loop-back, matching target exactly, no anti-unroll
// tricks needed) by mutating the arg1/arg2 parameters directly rather
// than introducing local pointer aliases. Target uses a noticeably
// larger stack frame (0x98 vs this reconstruction's 0x80) and more
// callee-saved registers overall - likely the same register-
// generation-reuse pattern documented on func_15145CD0 (keeping
// arg0's config pointer and the arg1 array pointer in the SAME
// physical register across their non-overlapping live ranges costs
// target extra spill bookkeeping this reconstruction doesn't need),
// though not confirmed instruction-by-instruction here.
extern void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);

void func_15145DB4(f32 *arg0, f32 arg1[][3], f32 arg2[][3], s32 arg3) {
    f32 mtx[4][4];
    s32 i;

    func_150A8050(mtx, arg0[0], arg0[1], arg0[2]);
    mtx[3][0] = ((s16 *) arg0)[8];
    mtx[3][1] = ((s16 *) arg0)[9];
    mtx[3][2] = ((s16 *) arg0)[10];
    i = 0;
    while (arg3 > 0) {
        func_150A7960(mtx, arg1[i][0], arg1[i][1], arg1[i][2], &arg2[i][0], &arg2[i][1], &arg2[i][2]);
        arg3--;
        i++;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15145EA4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_15146078.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_151462C8.s")
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Builds a bitmask
// of the low (D_80082FA0+1) bits (0 if D_80082FA0<0), then returns
// whether that mask has no bits in common with *(arg0+2) (s16). Tried
// referencing arg0 directly and through a local copy (matching target's
// early `or a2,a0,zero`) - the copy fixed the missing initial instruction
// but the final field-access register allocation still differs.
// NON-MATCHING (4 real words): builds a mask of the low
// D_80082FA0 + 1 bits and returns whether arg0's unk2 field has none of
// them set.  20 of 20 instructions; the remaining gap is the return
// tail, where target does `sltiu $t1, $a0, 1; andi $v0, $t1, 0xFF` and
// this build routes it through $v0 and back with an extra `move`.
// Neither an explicit `(u8)` cast nor a named u8 result variable
// changes that.
//
// Two shapes did land and are worth keeping.  The AND result must go
// into its own local (`x = ... & mask; return x == 0;`): folding it
// into the return expression costs 12 words, because target keeps arg0
// alive in $a2 and uses $a0 as the scratch for the AND, which only
// happens when the result is a named value.  And the loop counter must
// be initialised BEFORE the mask - `for (i = 0, mask = 0; ...)` rather
// than `mask = 0;` ahead of the loop - which fixes the order of the two
// `or $reg, $zero, $zero` instructions.
// u8 func_151464B8(void *arg0) {
//     s32 i;
//     s16 mask;
//     s32 x;
//
//     for (i = 0, mask = 0; i <= D_80082FA0; i++) {
//         mask = mask | (1 << i);
//     }
//     x = *(s16 *) ((char *) arg0 + 2) & mask;
//     return x == 0;
// }
u8 func_151464B8(void *arg0) {
    s32 i;
    s16 mask;
    s32 x;

    for (i = 0, mask = 0; i <= D_80082FA0; i++) {
        mask = mask | (1 << i);
    }
    x = (*(s16 *) ((char *) arg0 + 2) & mask) == 0;
    return x;
}
// s32 func_151464B8(void *arg0) {
//     s32 v0 = 0;
//     s32 v1 = 0;
//
//     if (D_80082FA0 >= 0) {
//         do {
//             v1 |= 1 << v0;
//             v0 += 1;
//             v1 = (s16) v1;
//         } while (v0 <= D_80082FA0);
//     }
//     return (*(s16 *) ((char *) arg0 + 2) & v1) < 1;
// }

void func_15146508(struct127 *arg0, struct127 *arg1) {
    struct193 tmp;

    tmp.unk0 = arg0;
    tmp.unk4 = arg1;
    tmp.unk8 = arg0->unique_id;
    tmp.unk9 = arg1->unique_id;
    func_15169040(&tmp, 45, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_1514654C.s")

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Bounding-volume
// check: fails if |x| or |z| exceed D_800A56C4, or if y is outside
// [D_800A56C8, D_800A56C4]. Target compiles fabsf() straight to a single
// abs.s with no argument-promotion round-trip, but calling fabsf() the
// normal way here always produces IDO's usual cvt.d.s/cvt.s.d dance
// around it (confirmed present even in already-matched fabsf() call
// sites elsewhere in this file, e.g. func_15144C8C) - so target's
// abs must come from a different source idiom than a plain fabsf()
// call; an explicit `if (x<0) x=-x;` branch was tried and made things
// worse (extra unwanted branches), reverted.
#pragma GLOBAL_ASM("asm/nonmatchings/game_16EE20/func_1514672C.s")
// s32 func_1514672C(struct17 *arg0) {
//     if (D_800A56C4 < fabsf(arg0->unk0) || D_800A56C4 < fabsf(arg0->unk8) || D_800A56C4 < arg0->unk4 || arg0->unk4 < D_800A56C8) {
//         return 0;
//     }
//     return 1;
// }

void func_151467A4(f32 *arg0, f32 arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 *arg7) {
    *arg0 = *arg0 - D_800BE9A4;
    if (*arg0 < 0.0f) {
        *arg0 = random_float() * arg1;
        if ((random_u32() & 3) != 0) {
            *arg2 = (random_float() * (arg4 - arg3)) + arg3;
        } else {
            *arg2 = (random_float() * (arg5 - arg4)) + arg4;
        }
    }
    *arg7 = ((*arg2 - *arg7) * arg6) + *arg7;
}
