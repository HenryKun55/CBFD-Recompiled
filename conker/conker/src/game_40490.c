#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_15012FE0(void) {
    D_800BE570 = 0;
    D_800BE574 = 0;
    D_800BE575 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013000.s")
// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_150130B4.s")

s32 func_1501370C(struct16 *arg0) {
    u8 idx = arg0->unk17;
    void (*func)(void) = D_80082EA0[idx];

    if (func != NULL) {
        func();
    }
    return 1;
}

s32 func_1501374C(struct16 *arg0) {
    arg0->unk16 |= 4;
    func_1515D088(arg0);
    return 1;
}

// fat struct definition:
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013778.s")

s32 func_1501396C(struct16 *arg0) {
    u8 idx = arg0->unk17;
    void (*func)(void) = D_80082ECC[idx];

    if (func != NULL) {
        func();
    }
    return 1;
}

// another struct
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_150139AC.s")

// NON-MATCHING: full semantics recovered and verified via isolated
// harness - a state-transition guard/dispatcher. Sets arg0's unk16
// flag bit 2, then returns 1 early if D_800D2E4C (a real struct102*
// global)'s unk11 byte has bit 2 set AND D_800BE9F0==0x13, or if
// D_800C35EA==1 and D_800C35E8 is 0xF/0x10/0x11 (all three, caught a
// real bug here: an earlier attempt only checked the first two and
// silently dropped the 0x11 case - fixed after noticing the isolated
// harness was 2 instructions short of a believable match). Otherwise,
// if arg0->unk18 is a valid index (<6) into the D_80082F28 function-
// pointer table and that slot is non-NULL, converts arg0->unk1C
// (treated as u32, not s32 - the classic bias-correct-if-negative
// idiom) to a float, scales it by D_80096650, and calls the pointer
// with (arg0, scaledValueAsRawBits).
// 64 vs target's 64 instructions - exact count match, and the vast
// majority of operations/offsets are identical. Two deliberate source
// choices were needed to get here: wrapping the final null-pointer
// check as `if (fn != 0) { ...; call(); } return 1;` instead of an
// early `if (fn == 0) return 1;` (the latter made IDO speculatively
// reload arg0->unk1C a second time after the branch, costing 2 extra
// instructions), and giving the scaled value its own local (`prod`)
// rather than reusing the unscaled one (reuse forced an unnecessary
// stack round-trip for the cross-branch float value; target's
// unscaled/scaled values also live in genuinely different physical
// registers, $f6 vs $f0). The one remaining gap is target moving the
// scaled result into $a1 via a single `mfc1` register-to-register
// instruction, where every form tried here does it via a swc1+lw
// stack round-trip instead - offset by this reconstruction saving an
// instruction elsewhere, so the total still lands exactly on 64.
// s32 func_15013C38(void *arg0) {
//     u8 flags;
//     struct102 *ptr;
//     s32 v1;
//     u8 v0;
//     void (*fn)(void *, s32);
//     s32 t4;
//     f32 val;
//     f32 prod;
//
//     flags = *((u8 *) arg0 + 0x16);
//     v1 = *(s32 *) ((char *) arg0 + 0x18);
//     *((u8 *) arg0 + 0x16) = flags | 4;
//     ptr = D_800D2E4C;
//     if ((*((u8 *) ptr + 0x11) & 4) != 0 && D_800BE9F0 == 0x13) {
//         return 1;
//     }
//     if (D_800C35EA == 1) {
//         v0 = D_800C35E8;
//         if (v0 == 0xF || v0 == 0x10 || v0 == 0x11) {
//             return 1;
//         }
//     }
//     if (v1 >= 6) {
//         return 1;
//     }
//
//     fn = D_80082F28[v1];
//     if (fn != 0) {
//         t4 = *(s32 *) ((char *) arg0 + 0x1C);
//         val = (f32) (u32) t4;
//         prod = val * D_80096650;
//
//         fn(arg0, *(s32 *) &prod);
//     }
//     return 1;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013D38.s")
// #NON-MATCHING: looks close but think its wrong
// s32 func_151BE850(struct17 *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);
// s32 func_15013D38(struct47 *arg0) {
//     s32 tmp1;
//     s32 tmp2;
//     s32 tmp3;
//     s32 tmp4;
//     struct17 *tmp;
//
//     arg0->unk16 |= 4;
//
//     tmp->unk0 = arg0->unk0;
//     tmp->unk4 = arg0->unk2;
//     tmp->unk8 = arg0->unk4;
//
//     tmp4 = 1;
//     tmp1 = arg0->unk18;
//     if (tmp1) {
//         tmp4 = tmp1;
//     }
//
//     tmp2 = arg0->unk10;
//     tmp3 = arg0->unk1F;
//
//     func_151BE850(tmp, tmp2, tmp4, tmp3, 0xff, 1, 1);
//     return 1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013DE8.s")

s32 func_15013F9C(s32 arg0) {
    func_151CD2C0(arg0, 0xFF, 1);
    return 1;
}

s32 func_15013FC4(struct133 *arg0) {
    u8 idx = arg0->unk1B;
    void (*func)(void) = D_80082F40[idx];

    if (func != NULL) {
        func();
    }
    return 1;
}

s32 func_15014004(struct134 *arg0) {
    s32 temp_v1 = arg0->unk1C;
    if (temp_v1 < 0) {
        return 1;
    }
    if (temp_v1 >= 6) {
        return 1;
    }
    D_800E0900[temp_v1] = arg0;
    return 1;
}

s32 func_15014040(struct134 *arg0) {
    s32 temp_v0 = arg0->unk18;
    arg0->unk16 |= 4;
    if (temp_v0 == 0) {
        D_800D9A20 = arg0;
    } else if (temp_v0 == 1) {
        D_800D9A24 = arg0;
    }
    return 1;
}

s32 func_1501407C(s32 arg0) {
    D_800D987C = (u8)0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15014094.s")
// NON-MATCHING: kinda right idea, but not executed correctly
// void func_15014094(struct134 *arg0) {
//     struct135 tmp;
//
//     tmp.unk0 = arg0;
//     // tmp.unk4 = tmp.unk0;
//     tmp.unk0->unk16 |= 4;
//     // tmp.unkC = tmp.unk0;
//     // arg0 = tmp.unk0;
//     tmp.unk10 = func_15144598(tmp.unk4); //, tmp.unk0);
//     tmp.unk14 = 0.0f;
//     func_1510F800(0);
//     tmp.unk18 = func_1510FD20(arg0->unk0, arg0->unk4, arg0);
//     tmp.unk1C = 0;
//     tmp.unk8 = func_15149130(0x12C, -1, 0x21, -1, 0, 0, 0x34, 0xFF, 1);
//     if (tmp.unk8 != 0) {
//         memcpy(tmp.unk8 + 0x28, &tmp, 0x34);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15014144.s")

// Sets flag 4 in unk16, then spawns a func_15149130 effect payload
// carrying {0.0f, arg0, 1} - same func_15149130/memcpy(&result->unk28,
// &tmp, N) pattern already established in func_15010538 (game_3D9A0.c)
// and its siblings.
s32 func_15014220(struct134 *arg0) {
    u8 tmp[0xC];
    struct260 *temp_v0;

    arg0->unk16 |= 4;
    *(f32 *) &tmp[0] = 0.0f;
    *(struct134 **) &tmp[4] = arg0;
    tmp[8] = 1;
    temp_v0 = func_15149130(0x12C, -1, 0x26, -1, 0, 0x24, 0xC, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, tmp, 0xC);
    }
    return 1;
}

// Sets flag 4 in unk16 unconditionally, then registers arg0 into
// D_800D9AA0[arg0's byte at +0x1B] if that index is in range [0,3).
s32 func_150142AC(struct134 *arg0) {
    s32 v1;

    arg0->unk16 |= 4;
    v1 = *((u8 *) arg0 + 0x1B);
    if (v1 < 0 || v1 >= 3) {
        return 1;
    }
    D_800D9AA0[v1] = arg0;
    return 1;
}

struct func_150142EC_s {
    struct134 *unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

s32 func_150142EC(struct134 *arg0) {
    struct func_150142EC_s tmp;
    struct260 *temp_v0;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 scale;

    arg0->unk16 |= 4;
    if (D_80082FA0 >= 2) {
        return 1;
    }
    if ((*((u8 *) D_800D2E4C + 0x11) & 4) && (D_800BE9F0 == 0x13)) {
        return 1;
    }
    a = (u32) (arg0->unk1C & 0xFFFF) * 0.001f;
    b = (u32) (((u32) arg0->unk1C >> 16) & 0xFFFF) * 0.001f;
    c = (u32) (arg0->unk20 & 0xFFFF) * 0.001f;
    d = (u32) (((u32) arg0->unk20 >> 16) & 0xFFFF) * 0.001f;
    scale = func_1514462C(arg0);
    tmp.unk0 = arg0;
    tmp.unk4 = a * scale * 1.271516e-10f;
    tmp.unk8 = b * scale * 1.271516e-10f;
    tmp.unkC = c;
    tmp.unk10 = d;
    tmp.unk14 = 0.0f;
    temp_v0 = func_15149130(0x12C, -1, 0x29, -1, 0, 0, 0x18, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0x18);
    }
    return 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_150144B8.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_1501474C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15014B60.s")
// NON-MATCHING: exact 78/78 instruction match. Sibling of
// func_150151D4 below - sets the same unk16 flag bit, then builds an
// 0x54-byte spawn descriptor: a flag byte from unk1C's low bit, the
// two halves of unk18 split into separate words, a random value in
// [low, low+high] via func_150ADA20() % (high + 1), a block filled by
// func_150A8050(), and the unk0/unk2/unk4 shorts as floats. Reading
// unk18 as u32 (not s32) is required - a signed read gives `sra`
// where target has `srl`, and makes the `%` a signed `div`, which
// drags in IDO's 6-instruction signed-overflow check that target
// doesn't have. The flag needs an explicit if/else (both arms
// assigning) to reproduce target's beqz/nop/b join; the `flag = 0;`
// + bare `if` form collapses to a `beqzl` likely-branch instead.
// Remaining diffs are the usual unlinked jal/branch placeholders, a
// register permutation in the modulo block, and `move a3,zero` where
// target materializes the same zero as `li a3,0` (tried a null
// pointer cast, no effect).
s32 func_15014F6C(void *arg0) {
    u8 buf[0x54];
    s32 flag;
    void *obj;

    *(u8 *) ((char *) arg0 + 0x16) |= 4;
    *(u8 *) (buf + 0x51) = *(s32 *) ((char *) arg0 + 0x20);

    if (*(s32 *) ((char *) arg0 + 0x1C) & 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    *(u8 *) (buf + 0x50) = flag;

    *(s32 *) (buf + 0x0) = (s32) arg0;
    *(s32 *) (buf + 0x4) = *(u32 *) ((char *) arg0 + 0x18) & 0xFFFF;
    *(s32 *) (buf + 0x8) = (*(u32 *) ((char *) arg0 + 0x18) >> 16) & 0xFFFF;
    *(s32 *) (buf + 0xC) =
        *(u32 *) (buf + 0x4) + (func_150ADA20() % (*(u32 *) (buf + 0x8) + 1));

    func_150A8050(buf + 0x10, *(f32 *) ((char *) arg0 + 0xC),
                  *(f32 *) ((char *) arg0 + 0x10), 0.0f);

    *(f32 *) (buf + 0x40) = (f32) *(s16 *) ((char *) arg0 + 0x0);
    *(f32 *) (buf + 0x44) = (f32) *(s16 *) ((char *) arg0 + 0x2);
    *(f32 *) (buf + 0x48) = (f32) *(s16 *) ((char *) arg0 + 0x4);

    obj = func_15149130(300, -1, 0x31, -1, 0, 0x2A, (struct37 *) 0x54, 0xFF, 0);

    if (obj != 0) {
        memcpy((char *) obj + 0x28, buf, 0x54);
    }

    return 1;
}
// s32 func_15014F6C(void *arg0) {
//     u8 buf[0x54];
//     s32 flag;
//     void *obj;
//
//     *(u8 *) ((char *) arg0 + 0x16) |= 4;
//     *(u8 *) (buf + 0x51) = *(s32 *) ((char *) arg0 + 0x20);
//
//     if (*(s32 *) ((char *) arg0 + 0x1C) & 1) {
//         flag = 1;
//     } else {
//         flag = 0;
//     }
//     *(u8 *) (buf + 0x50) = flag;
//
//     *(s32 *) (buf + 0x0) = (s32) arg0;
//     *(s32 *) (buf + 0x4) = *(u32 *) ((char *) arg0 + 0x18) & 0xFFFF;
//     *(s32 *) (buf + 0x8) = (*(u32 *) ((char *) arg0 + 0x18) >> 16) & 0xFFFF;
//     *(s32 *) (buf + 0xC) =
//         (func_150ADA20() % (*(u32 *) (buf + 0x8) + 1)) + *(u32 *) (buf + 0x4);
//
//     func_150A8050(buf + 0x10, *(s32 *) ((char *) arg0 + 0xC),
//                   *(s32 *) ((char *) arg0 + 0x10), 0);
//
//     *(f32 *) (buf + 0x40) = (f32) *(s16 *) ((char *) arg0 + 0x0);
//     *(f32 *) (buf + 0x44) = (f32) *(s16 *) ((char *) arg0 + 0x2);
//     *(f32 *) (buf + 0x48) = (f32) *(s16 *) ((char *) arg0 + 0x4);
//
//     obj = func_15149130(300, -1, 0x31, -1, 0, 0x2A, (struct37 *) 0x54, 0xFF, 0);
//
//     if (obj != 0) {
//         memcpy((char *) obj + 0x28, buf, 0x54);
//     }
//
//     return 1;
// }

s32 func_150150A4(void) {
    struct17 *temp_v0 = func_1515F1B0();
    if (temp_v0 == NULL) {
        return 1;
    }

    func_1515F25C(&D_800DCDC4, temp_v0);
    D_800DCD90 += temp_v0->unk8;
    return 1;
}

typedef struct {
    void *unk0;
    u8 unk4;
    s32 unk8;
    u8 unkC;
    s32 unk10;
} EffectData;

s32 func_15015104(struct134 *arg0) {
    EffectData header;
    s32 fdResult;
    struct260 *result;

    *((u8 *) arg0 + 0x14) = 1;

    header.unk0 = arg0;
    header.unk4 = (u8) arg0->unk1C;

    func_1510F800(0);

    fdResult = (s32) func_1510FD20(arg0->unk0, arg0->unk4);
    header.unk8 = fdResult;

    header.unkC = (arg0->unk20 ? 1 : 0) | (arg0->unk20 ? 2 : 0);
    header.unk10 = 0;

    result = func_15149130(300, -1, -1, -1, 0, 0x2C, (struct37 *) 0x14, 0xFF, 0);
    if (result != 0) {
        memcpy((char *) result + 0x28, &header, 0x14);
    }
    return 1;
}
// NON-MATCHING: exact 75/75 instruction match. Sets two flag fields on
// arg0, builds a spawn-effect descriptor blob from arg0's position
// fields (converted short->float) plus a global float constant, calls
// two simple K&R helpers, allocates via the established func_15149130,
// and memcpy's the blob into the new object before returning 1. Every
// field/offset and statement order verified against target instruction
// for instruction; the only differences are within-frame layout (this
// reconstruction's scratch buffer lands 4 bytes earlier in the 128-byte
// frame than target's, an unexplained but harmless compiler layout
// choice) and one store IDO pushed inside the `if (v0 != 0)` branch
// where target keeps it unconditional right after the allocator call -
// tried marking the buffer volatile to force the unconditional store,
// no effect, consistent with other near-misses this session where a
// similar single-store reordering wasn't reachable from source.
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_150151D4.s")
// extern f32 D_800966B4;
//
// s32 func_150151D4(void *arg0) {
//     void *a2 = arg0;
//     u8 buf[0x48];
//     void *v0;
//
//     *(u8 *) ((char *) a2 + 0x16) |= 4;
//     *(u8 *) ((char *) a2 + 0x14) = 1;
//
//     *(s32 *) (buf + 0x0) = (s32) a2;
//     *(f32 *) (buf + 0x4) = 0.0f;
//     *(s16 *) (buf + 0x8) = -1;
//     *(f32 *) (buf + 0xC) = (f32) *(s16 *) ((char *) a2 + 0x0);
//     *(f32 *) (buf + 0x10) = (f32) *(s16 *) ((char *) a2 + 0x2);
//     *(f32 *) (buf + 0x14) = (f32) *(s16 *) ((char *) a2 + 0x4);
//     *(f32 *) (buf + 0x18) = (f32) *(s16 *) ((char *) a2 + 0x6);
//     *(s32 *) (buf + 0x40) = 0;
//     *(u8 *) (buf + 0x3D) = 0;
//     *(f32 *) (buf + 0x1C) = (f32) *(s16 *) ((char *) a2 + 0x8);
//     *(u8 *) (buf + 0x3C) = 0;
//     *(s32 *) (buf + 0x38) = 0;
//     *(f32 *) (buf + 0x20) = D_800966B4;
//
//     func_1510F800(0);
//
//     func_1510FD20(*(s16 *) ((char *) a2 + 0x0), *(s16 *) ((char *) a2 + 0x4));
//
//     v0 = func_15149130(300, -1, 60, -1, 0, 45, (struct37 *) 72, 0xFF, 0);
//     *(s32 *) (buf + 0x44) = (s32) v0;
//
//     if (v0 != 0) {
//         memcpy((char *) v0 + 0x28, buf, 0x48);
//     }
//
//     return 1;
// }

s32 func_15015300(struct134 *arg0) {
    void (*func)(void);
    s32 idx = arg0->unk1C;

    if ((idx < 0) || (idx >= 2)) {
        return 1;
    }

    func = D_80082F70[idx];
    if (func != NULL) {
        func();
    }

    return 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15015354.s")
s32 func_15015644(void *arg0) {
    struct {
        void *f0;
        f32 f4;
        void *f8;
        u8 fC;
    } local;
    void *v0;

    *(u8 *) ((char *) arg0 + 0x16) |= 4;
    *(u8 *) ((char *) arg0 + 0x14) = 1;
    local.f0 = arg0;
    local.f4 = func_15144598(arg0);
    func_1510F800(0);
    local.f8 = func_1510FD20(*(s16 *) ((char *) arg0 + 0x0), *(s16 *) ((char *) arg0 + 0x4));
    local.fC = 0;
    v0 = func_15149130(300, -1, 0x44, -1, 0, 0x2F, (struct37 *) 0x10, 0xFF, 0);
    if (v0 != 0) {
        memcpy((char *) v0 + 0x28, &local, 0x10);
    }
    return 1;
}
void func_150A7960(f32 m[4][4], f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz);
void func_151ACBD4(void *arg0, s32 arg1);

struct func_150156F4_s {
    s16 x;
    s16 y;
    s16 z;
    s16 pad6;
    s16 h;
    s16 padA;
    f32 rx;
    f32 ry;
    s32 pad14;
    s32 type;
};

typedef struct {
    f32 x, y, z;
} func_150156F4_v;

s32 func_150156F4(struct func_150156F4_s *arg0) {
    func_150156F4_v pts[2];
    f32 mtx[4][4];
    struct {
        u8 type;
        func_150156F4_v lo;
        func_150156F4_v hi;
        f32 dist;
        u8 f20;
    } info;

    if (D_800BE9F0 == 0xB) {
        if ((u32) arg0->type < 6) {
            return 1;
        }
    } else if (D_800BE9F0 == 0x2C) {
        if ((u32) arg0->type < 7) {
            return 1;
        }
    } else if (D_800BE9F0 == 0x26) {
        if ((u32) arg0->type < 2) {
            return 1;
        }
    }
    func_150A8050(mtx, arg0->rx, arg0->ry, 0.0f);
    mtx[3][0] = arg0->x;
    mtx[3][1] = arg0->y;
    mtx[3][2] = arg0->z;
    func_150A7960(mtx, 0.0f, arg0->h, 0.0f, &pts[1].x, &pts[1].y, &pts[1].z);
    pts[0].x = arg0->x;
    pts[0].y = arg0->y;
    pts[0].z = arg0->z;
    info.type = arg0->type;
    info.lo = pts[pts[0].y < pts[1].y];
    info.hi = pts[pts[1].y < pts[0].y];
    info.dist = fabsf(pts[1].y - pts[0].y);
    info.f20 = 0;
    func_151ACBD4(&info, 0);
    return 1;
}
