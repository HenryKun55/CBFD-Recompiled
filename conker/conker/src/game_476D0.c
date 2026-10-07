#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_1501A220(s32 arg0, s32 arg1) {
    s32 n;
    s32 i;
    f32 temp_f0;
    f32 temp_f2;

    D_80082FA0 = arg0;

    if (D_80082FA0 == 0) {
        n = 1;
    } else {
        n = D_80082FA0 + 2;
    }
    D_800BE628 = allocate_memory(n * 0x180, 1, 1, 0);
    D_800BE62C = allocate_memory(n * 16, 1, 1, 0);
    if (D_80082FA0 == 1) {
        temp_f0 = D_800BE63C[0] - 2.0f;
        temp_f2 = temp_f0 * 0.8f;
        D_800BE6B8 = ((s32)temp_f2 - (s32)temp_f2 % 4) / temp_f0;
        if (temp_f2) {}
    }

    func_150006E0(D_800BE9F0);

    for (i = 0; i <= D_80082FA0; i++) {
        func_1501A8C0(i, D_80082FA0, 1023, 0);
    }
    if (D_80082FA0 != 0) {
        func_1501A8C0(i, 0, 1023, 0);
    }

    D_800BE617 = 1;
    D_800BE614 = 1;
    D_800BE635 = 0;
    func_1510B070(arg1);
}
// NON-MATCHING: 80% there
// void func_1501A220(s32 arg0, s32 arg1) {
//     s32 phi_s0;
//     s32 i;
//
//     f32 temp_f0;
//     s32 temp_f16;
//
//     D_80082FA0 = arg0;
//
//     if (arg0 == 0) {
//         phi_s0 = 1;
//     } else {
//         phi_s0 = arg0 + 2;
//     }
//     D_800BE628 = allocate_memory((phi_s0 * 3) << 7, 1, 1, 0);
//     D_800BE62C = allocate_memory(phi_s0 * 16, 1, 1, 0);
//     if (D_80082FA0 == 1) {
//         temp_f0 = D_800BE63C - 2.0f;
//         temp_f16 = temp_f0 * D_800968E0;
//         phi_s0 = temp_f16 & 3;
//         if ((temp_f16 < 0) && ((temp_f16 & 3) != 0)) {
//             phi_s0 -= 4;
//         }
//         D_800BE6B8 = (temp_f16 - phi_s0) / temp_f0;
//     }
//
//     func_150006E0(D_800BE9F0);
//
//     for(i = 0; i <= D_80082FA0; i++) {
//         func_1501A8C0(i, D_80082FA0, 1023, 0);
//     }
//     if (D_80082FA0 != 0) {
//         func_1501A8C0(i, 0, 1023, 0);
//     }
//
//     D_800BE617 = 1;
//     D_800BE614 = 1;
//     D_800BE635 = 0;
//     func_1510B070(arg1);
// }

extern Gfx *D_800BE9C8[];
extern Gfx D_8002C930[];

void func_1501A39C(void) {
    s32 i;
    Gfx *gfx;

    for (i = 0; i < 2; i++) {
        gfx = D_800BE9C8[i];
        gSPSegment(gfx++, 0x00, 0x00000000);
        gSPSegment(gfx++, 0x00, 0x00000000);
        gSPDisplayList(gfx++, D_8002C930);
        gDPSetDepthImage(gfx++, D_800BE9C4);
        gSPViewport(gfx++, 0x40 + D_800BE628 + i * 16);
        D_800BE9D8[i] = (s32)gfx;
    }
}
// NON-MATCHING: something along these lines
// extern Gfx* D_800BE9C8;
// extern s32 D_8002C930;
// Gfx *func_1501A39C(void) {
//     s32 i;
//     Gfx *tmp = D_800BE9C8;
//     for (i = 0; i < 3; i++) {
//         gSPSegment(tmp++, 0x00, 0x00000000);
//         gSPSegment(tmp++, 0x00, 0x00000000);
//         gSPDisplayList(tmp++, D_8002C930);
//         gDPSetDepthImage(tmp++, D_800BE9C4);
//         gSPViewport(tmp++, D_800BE628 + i + 0x40);
//     }
//     return tmp;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_476D0/func_1501A490.s")

Gfx *func_1501A680(Gfx *arg0) {
    gDPSetColorImage(arg0++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800BE620, D_8002AAE8[D_800BE9C0]);
    return arg0;
}

Gfx *func_1501A6CC(Gfx *arg0, s32 a, s32 b, s32 c, s32 d) {
    if (a < 3) {
        a = 2;
    }
    if (b <= 0) {
        b = 0;
    }
    if (c >= (D_800BE620 - 2)) {
        c = D_800BE620 - 2;
    }
    if (d >= D_800BE624) {
        d = D_800BE624;
    }

    gDPFillRectangle(arg0++, a, b, c, d);
    return arg0;
}

void func_150A7A00(f32 arg0, f32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6, f32* arg7, f32* arg8, f32* arg9);
#pragma GLOBAL_ASM("asm/nonmatchings/game_476D0/func_1501A764.s")
// void func_1501A764(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
//     f32 sp34;
//     f32 sp30;
//     f32 sp2C;
//     f32 sp28;
//     struct140 *temp_v0_2;
//
//     func_150A7A00(arg1, arg2, &D_800D9D10 + (arg0 << 6), arg1, arg2, arg3, &sp34, &sp30, &sp2C, &sp28);
//     sp28 = 1.0f / sp28;
//     // temp_v1 = arg0 * 0x180;
//     temp_v0_2 = &D_800BE628[arg0];
//     // sp28 = temp_f8;
//     *arg4 = (((temp_v0_2->unkC + 5.0f) * sp34 * sp28) + temp_v0_2->unk34);
//     temp_v0_2 = &D_800BE628 [arg0];
//     *arg5 = (temp_v0_2->unk38 - ((temp_v0_2->unk10 + 5.0f) * sp30 * sp28));
//     temp_v0_2 = &D_800BE628[arg0].unk50[D_800BE9C0];  // (D_800BE9C0 * 0x10);
//     *arg6 = (((f32) temp_v0_2->unk4C + (sp2C * sp28 * (f32) temp_v0_2->unk44)) * 32.0f);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_476D0/func_1501A8C0.s")

// NON-MATCHING: full branch/block topology recovered and verified via
// isolated harness - the two OR-combined guard pairs
// (unk2C<2.0||delta<unk30, and unk24<0.0||f2<unk28) were required to
// reproduce target's shared-return-0 block structure (each pair's two
// checks jump into or fall into the SAME return-0 code, rather than
// each getting its own copy) and the exact bc1t/bc1fl polarity choice
// for every branch - writing them as four separate sequential ifs
// instead produced a completely different (still correct, but very
// differently scheduled) branch shape. Every opcode/operand/branch now
// matches except a register-permutation gap among the temps holding
// D_800BE628 (the record array base), D_800BE624, and the
// index*384 offset computation ($t7/$t8/$t9 in some order here vs
// target's own choice) - tried both statement order and declaration
// order for the three locals with no effect, matching the "immune to
// restructuring" register-choice class documented elsewhere. Reads
// D_800BE628[arg0] (a 0x180-byte record) at fields unk24/unk28/unk2C/
// unk30, gating on arg0's record having enough valid history (unk2C)
// and margin (unk30) against (D_800BE620-2), then a non-negative
// unk24 and enough margin (unk28) against D_800BE624.
s32 func_1501AE94(s32 arg0) {
    f32 delta;
    char *rec;
    f32 f2;

    delta = (f32) D_800BE620 - 2.0f;
    f2 = (f32) D_800BE624;
    rec = (char *) D_800BE628 + arg0 * 384;

    if (*(f32 *) (rec + 0x2C) < 2.0f || delta < *(f32 *) (rec + 0x30)) {
        return 0;
    }
    if (*(f32 *) (rec + 0x24) < 0.0f || f2 < *(f32 *) (rec + 0x28)) {
        return 0;
    }
    return 1;
}
// s32 func_1501AE94(s32 arg0) {
//     f32 delta;
//     char *rec;
//     f32 f2;
//
//     delta = (f32) D_800BE620 - 2.0f;
//     rec = (char *) D_800BE628 + arg0 * 384;
//     f2 = (f32) D_800BE624;
//
//     if (*(f32 *) (rec + 0x2C) < 2.0f || delta < *(f32 *) (rec + 0x30)) {
//         return 0;
//     }
//     if (*(f32 *) (rec + 0x24) < 0.0f || f2 < *(f32 *) (rec + 0x28)) {
//         return 0;
//     }
//     return 1;
// }

// Clamps a screen rectangle (upper-left and lower-right corners, in pixels) to the
// frame: x to [2, width - 2], leaving the same 2-pixel side borders as the 3D view's
// scissor, and y to [0, height]. D_800BE620 and D_800BE624 are the frame's width
// and height (292 x 216 in play).
void func_1501AF44(f32 *ulx, f32 *uly, f32 *lrx, f32 *lry) {
    f32 ulxValue;
    f32 lrxValue;
    f32 ulyValue;
    f32 lryValue;
    f32 ulxMax;
    f32 lrxMax;
    f32 ulyMax;
    f32 lryMax;
    f32 ulxClamped;
    f32 lrxClamped;
    f32 ulyClamped;
    f32 lryClamped;

    ulxValue = *ulx;
    if (ulxValue < 2.0f) {
        *ulx = 2.0f;
    } else {
        ulxMax = (f32) D_800BE620 - 2.0f;
        if (ulxMax < ulxValue) {
            ulxClamped = ulxMax;
        } else {
            ulxClamped = ulxValue;
        }
        *ulx = ulxClamped;
    }
    lrxValue = *lrx;
    if (lrxValue < 2.0f) {
        *lrx = 2.0f;
    } else {
        lrxMax = (f32) D_800BE620 - 2.0f;
        if (lrxMax < lrxValue) {
            lrxClamped = lrxMax;
        } else {
            lrxClamped = lrxValue;
        }
        *lrx = lrxClamped;
    }
    ulyValue = *uly;
    if (ulyValue < 0.0f) {
        *uly = 0.0f;
    } else {
        ulyMax = (f32) D_800BE624;
        if (ulyMax < ulyValue) {
            ulyClamped = ulyMax;
        } else {
            ulyClamped = ulyValue;
        }
        *uly = ulyClamped;
    }
    lryValue = *lry;
    if (lryValue < 0.0f) {
        *lry = 0.0f;
        return;
    }
    lryMax = (f32) D_800BE624;
    if (lryMax < lryValue) {
        lryClamped = lryMax;
    } else {
        lryClamped = lryValue;
    }
    *lry = lryClamped;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_476D0/func_1501B0A0.s")

// Camera frustum side planes: from the camera's horizontal and vertical fields
// of view (fovX and fovY, in degrees), writes the view-space normals of the
// four side planes that world and object culling test against:
//   unk88..unk90 (cos h, 0, -sin h) and unk94..unk9C (-cos h, 0, -sin h),
//   unkA0..unkA8 (0, -cos v, -sin v) and unkAC..unkB4 (0, cos v, -sin v),
// where h and v are the half angles. D_80096900/D_80096904 are pi/180.
// arg0 is the camera's index in D_800BE628 (0x180-byte cameras). The
// recompiled PC port hooks the end of it to widen the left/right pair for
// widescreen (host/src/widescreen.cpp).
// Would-be name: updateFrustumPlanes_1501B22C.
//
// NON-MATCHING (57 of 61 words; 2026-09-27): the version below matches every
// instruction and register except four stack offsets. The pointer has to be
// written `arg0 * 0x180 + (char *) D_800BE628` (index first) to get target's
// t6/t7 roles. Separate single-use temps are required: any variable that lives
// across both halves (angle, cosine, or both, with or without its own sine
// variable) makes IDO keep it in a callee-saved $f20/$f22 instead of spilling.
// But target spills BOTH halves' angle into 0x24(sp) and BOTH cosines into
// 0x34(sp), while distinct variables get distinct homes (declaration order
// only picks which half lands at 0x24/0x34; the other gets 0x20/0x30).
// Block-scoped temps per half don't share homes either (and cost a nop).
// Not tried yet: a 2-iteration loop IDO unrolls, or an inlined helper.
// void func_1501B22C(s32 arg0) {
//     struct259 *rec = (struct259 *) (arg0 * 0x180 + (char *) D_800BE628);
//     f32 tmp0, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
//
//     tmp0 = rec->fovX * 0.5f;
//     tmp7 = -tmp0;
//     tmp5 = rec->fovY * 0.5f;
//     tmp7 *= D_80096900;
//     tmp3 = cosf(tmp7);
//     tmp7 = sinf(tmp7);
//     rec->unk9C = tmp7;
//     rec->unk90 = tmp7;
//     tmp3 = -tmp3;
//     rec->unk88 = -tmp3;
//     rec->unk94 = tmp3;
//     rec->unk98 = 0.0f;
//     rec->unk8C = 0.0f;
//     tmp6 = tmp5 * D_80096904;
//     tmp2 = cosf(tmp6);
//     tmp0 = sinf(tmp6);
//     tmp4 = -tmp2;
//     tmp0 = -tmp0;
//     rec->unkA0 = 0.0f;
//     rec->unkB0 = -tmp4;
//     rec->unkA8 = tmp0;
//     rec->unkB4 = tmp0;
//     rec->unkAC = 0.0f;
//     rec->unkA4 = tmp4;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_476D0/func_1501B22C.s")
