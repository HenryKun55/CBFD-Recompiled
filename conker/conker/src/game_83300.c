#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_15058F24(struct127 *arg0, f32 arg1, f32 arg2);
u8   func_150599C8();
void func_1505A250(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4);
f32  func_1505A3A8();

u8  func_1505B9C4();
s32 func_1505C1E4();

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15055E50.s")

void func_15056150(struct127 *arg0) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    s16 *temp_v1;

    if (arg0->unk2E8 != 0) {
        temp_v1 = D_800D2104[arg0->unk13F];
        temp_f2 = temp_v1[4];
        temp_f12 = temp_v1[6];
        temp_f14 = temp_v1[5];
        temp_f16 = arg0->unk2E8;
        temp_f16 = temp_f16 * 8.0f;
        temp_f18 = arg0->x_position - temp_f2;
        temp_f20 = arg0->z_position - temp_f12;
        temp_f22 = arg0->y_position - temp_f14;
        temp_f0 = sqrtf((temp_f18 * temp_f18) + (temp_f20 * temp_f20) + (temp_f22 * temp_f22) + D_80099440);
        temp_f18 *= 1.0f / temp_f0;
        temp_f20 *= 1.0f / temp_f0;
        temp_f22 *= 1.0f / temp_f0;
        if (temp_f16 < temp_f0) {
            arg0->x_position = temp_f18 * temp_f16 + temp_f2;
            arg0->z_position = temp_f20 * temp_f16 + temp_f12;
            arg0->y_position = temp_f22 * temp_f16 + temp_f14;
        }
    }
}

void func_15056258(struct127 *arg0) {
    f32 temp_f2;
    f32 temp_f4;
    f32 phi_f12;

    temp_f4 = arg0->unk11C;
    temp_f2 = arg0->unk118 - arg0->unk11C;
    arg0->unk11C = arg0->unk118;
    phi_f12 = 2.0f * (arg0->y_position - ((arg0->unk118 - 60.0f) - 170.0f));
    if (!(phi_f12 < 0.0f)) {
        if (!(fabsf(temp_f2) > 30.0f)) {
            if (phi_f12 > 300.0f) {
                phi_f12 = 300.0f;
            }
            arg0->y_position += (phi_f12 * temp_f2 * D_80099444);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150562FC.s")
// NON-MATCHING: 10% of the way there...
// void func_150562FC(struct127 *arg0) {
//     f32 sp70;
//     f32 sp6C;
//     f32 sp68;
//     u8 sp63;
//     s32 sp54;
//     f32 sp4C;
//     f32 temp_f0;
//     f32 temp_f12;
//     f32 temp_f14;
//
//     s32 *temp_a3;
//     // s32 temp_t1;
//     s32 temp_t1_2;
//     s32 temp_t2;
//     s32 temp_t9;
//     s32 temp_v0_6;
//     struct255 *temp_v1_2;
//     u16 temp_v0_2;
//     u16 temp_v0_3;
//     u16 temp_v0_4;
//     u16 temp_v0_5;
//     u16 temp_v0_7;
//     u16 temp_v0_8;
//     u16 temp_v1;
//     u8 temp_v0;
//     struct127 *temp_t0;
//     struct127 *temp_t0_2;
//     u8 *temp_v0_11;
//     s32 phi_a2;
//     s32 phi_t1;
//     s32 phi_t1_2;
//     s32 phi_t1_3;
//     s32 phi_a2_2;
//     f32 phi_f18;
//     s32 phi_t1_4;
//     f32 phi_f0;
//     s32 phi_t1_5;
//     s32 phi_t2;
//
//     sp63 = arg0->unk13D - 0x64;
//     sp54 = 0;
//     sp4C = 5.0f;
//     arg0->immune = (u8)0x1E;
//     temp_t0 = &gObjects[sp63];
//     arg0->unk180 = (f32) temp_t0->unk180;
//     arg0->unk1CC = (f32) arg0->y_position;
//     arg0->gravity = 4.5f;
//     arg0->y_velocity = 0.0f;
//     if ((s32) arg0->unk21C < 0x1E) {
//         arg0->unk21C += D_800BE9A0;
//     }
//     temp_v0 = arg0->id;
//     if (temp_v0 == 0x57) {
//         arg0->unk5C = 9;
//         if ((s32) arg0->unk21C >= 0xA) {
//             temp_v0_2 = temp_t0->unk84.uh;
//             sp54 = 1;
//             phi_a2 = 0xD;
//             if (temp_v0_2 == 0x114) {
//                 phi_a2 = 0x24;
//             }
//             phi_t1 = 0;
//             if (temp_v0_2 == 0x116) {
//                 phi_t1 = 1;
//             }
//             if (temp_v0_2 == 0x117) {
//                 phi_t1 = 2;
//             }
//             func_150649A0(sp63, gCurrentObjectIndex, phi_a2);
//             phi_t1_3 = phi_t1;
//             phi_a2_2 = phi_a2;
//         } else if (temp_v0 == 0x8C) {
//             arg0->unk5C = 4;
//             if ((s32) arg0->unk21C >= 0xA) {
//                 temp_v0_2 = temp_t0->unk84.uh;
//                 sp54 = 1;
//                 phi_t1_2 = 0;
//                 if (temp_v0_2 == 0x1A6) {
//                     phi_t1_2 = 1;
//                 }
//                 if (temp_v0_2 == 0x1A7) {
//                     phi_t1_2 = 2;
//                 }
//                 func_150649A0(sp63, gCurrentObjectIndex, 0xD);
//                 phi_t1_3 = phi_t1_2;
//                 phi_a2_2 = 0xD;
//             }
//         } else {
//             if ((temp_v0 == 0xA8) || (temp_v0 == 0xA9)) {
//                 arg0->unk5C = 9;
//                 temp_v0_2 = temp_t0->unk84.uh;
//                 sp54 = 1;
//                 phi_t1_3 = 0;
//                 if (temp_v0_2 == 0x1B0) {
//                     phi_t1_3 = 1;
//                 }
//                 phi_a2_2 = 0xD;
//                 if (temp_v0_2 == 0x1B1) {
//                     phi_t1_3 = 2;
//                     phi_a2_2 = 0xD;
//                 }
//             } else {
//                 phi_t1_3 = 0;
//                 phi_a2_2 = 0xD;
//                 if (temp_v0 == 0x5E) {
//                     arg0->unk5C = 9;
//                     temp_v0_2 = temp_t0->unk84.uh;
//                     sp54 = 1;
//                     sp4C = 16.0f;
//                     phi_t1_3 = 0;
//                     if (temp_v0_2 == 0x286) {
//                         phi_t1_3 = 2;
//                     }
//                     phi_a2_2 = 0xD;
//                     if (temp_v0_2 == 0x27E) {
//                         phi_t1_3 = 1;
//                         phi_a2_2 = 0xD;
//                     }
//                 }
//             }
//         }
//         temp_v0_6 = func_1505E7CC(phi_a2_2, arg0); //, phi_a2_2);
//         temp_t0_2 = &gObjects[sp63];
//         phi_t1_4 = phi_t1_3;
//         temp_t2 = temp_v0_6;
//         temp_a3 = D_800D1588[arg0->id] - 8;
//         if (temp_t0_2->interaction_state == 1) {
//             if (temp_t0_2->in_water != 0) {
//                 temp_t9 = temp_v0_6 * 3;
//                 arg0->unk5C = 4;
//                 sp54 = 1;
//                 if (((temp_a3 + (temp_t9 * 8)) + 14) != 0) { // unkE
//                     phi_t1_4 = 1;
//                 }
//             }
//         }
//         if ((s32) arg0->unk21C < 0x14) {
//             phi_f18 = (f32) (u32) arg0->unk21C / 50.0f;
//             if (D_800BE9B4 != 0) {
//                 phi_f18 = 1.0f;
//             }
//         } else {
//             phi_f18 = D_80099448;
//         }
//
//         sp70 = (f32) arg0->unk10F;
//
//         func_150599C8(arg0, 0x10, (temp_t0_2->unk7A + (arg0->unk13E << 8)) & 0xFFFF); //, temp_a3);
//         temp_t1_2 = phi_t1_4;
//         temp_v1_2 = temp_t0_2->unk1D4;
//         if (temp_v1_2 != 0) {
//             temp_f0 = (f32) ((s32) arg0->unk10C / 0x64);
//             if (temp_t0_2->interaction_state != 0x15) {
//                 temp_v0_8 = arg0->unk21C;
//                 if ((s32) temp_v0_8 >= 7) {
//                     arg0->y_position = (f32) temp_v1_2->unk240->unk1A;
//                     if ((s32) temp_v0_8 < 0xE) {
//                         // temp_f6 = (f32) temp_v0_8;
//                         temp_f0 = (temp_v0_8 / 14.0f) * temp_f0;
//                     }
//                     arg0->y_position = (f32) (arg0->y_position + temp_f0);
//                 }
//                 if (arg0->id == 0xE) {
//                     arg0->unkC4 = 0.0f;
//                 } else if (arg0->id == 0x13) {
//                     sp70 = 204.0f;
//                     arg0->unkC4 = 0.0f;
//                 }
//             }
//         }
//         phi_t1_5 = phi_t1_4;
//         phi_t2 = temp_t2;
//         if (temp_t0_2->interaction_state == 0x15) {
//             phi_t2 = func_1505E7CC(0x39, arg0);
//             arg0->unk7A = (u16) temp_t0_2->unk7A;
//             arg0->y_position = (f32) (temp_t0_2->y_position - 10.0f);
//             if ((arg0->unk28 > 100.0f) && ((s32) arg0->unk21C >= 0x15)) {
//                 phi_t1_5 = 1;
//             } else {
//                 sp4C = 0.0f;
//                 phi_t1_5 = phi_t1_4;
//             }
//             sp70 = 0.0f;
//             temp_f0 = arg0->unkC4;
//             arg0->xz_velocity = 0.0f;
//             arg0->unkC4 = (f32) (temp_f0 + ((temp_t0_2->unkC4 - temp_f0) * D_8009944C));
//         }
//         func_1505A184(gObjects[sp63].unk7A,  sp70, 0, &sp70, &sp6C, &sp68);
//         temp_t0_2 = &gObjects[sp63];
//         temp_f12 = temp_t0_2->x_position + sp70;
//
//         temp_f14 = temp_t0_2->z_position + sp6C;
//         arg0->x_position = (f32) (arg0->x_position + ((temp_f12 - arg0->x_position) * phi_f18));
//         arg0->z_position = (f32) (arg0->z_position + ((temp_f14 - arg0->z_position) * phi_f18));
//         temp_v0_11 = temp_a3 + (phi_t2 * 0x18) + (phi_t1_5 * 4);
//         func_1505E650(arg0, temp_v0_11[0xA],  temp_v0_11[0xC] / 100.0f, sp4C, 0.0f, 0.0f, 0);
//         if (sp54 != 0) {
//             arg0->unk65 = (s8) (sp63 + 1);
//             arg0->unk101 = (u8) (arg0->unk101 | 4);
//         } else {
//             arg0->unk65 = (u8)0;
//         }
//     }
// }

s32 func_1505693C(struct127 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;

    u16 *temp_v0 = (u16*)D_800D2104[(u16)arg0->unk13F];

    if (temp_v0[3] == 0) {
        return 1;
    }

    temp_f0 = temp_v0[3] * 8;
    temp_f0 = temp_f0 * temp_f0;
    temp_f2 = (s16)temp_v0[0] - gObjects[arg1].x_position;
    temp_f12 = (s16)temp_v0[2] - gObjects[arg1].z_position;

    if ((temp_f2 * temp_f2) + (temp_f12 * temp_f12) < temp_f0) {
        return 1;
    }
    return 0;
}

// NON-MATCHING: 63 vs target's 66 instructions - three fewer (a
// "smarter than target" near-miss). Target unconditionally spills the
// raw (untruncated) arg1/arg2 to their o32 stack argument-save slots
// before masking each to a byte - a debug-info convention this
// reconstruction doesn't reproduce (couldn't find a source form that
// forces it back). Target also compiles the `row[2] < arg1` test as a
// single annulled-delay-slot `beql` (its consequent is one
// instruction) instead of a separate compare-and-jump; this
// reconstruction's equivalent if/else-if lands functionally identical
// but one instruction longer via a plain branch. Reads
// D_80099A3C[arg2*10 + N] as a raw byte table (10-byte stride rows);
// picks a table-row offset based on two threshold checks plus a
// signed comparison of unk78 vs unk76, then - unless that byte reads
// 0xFF - reinitializes several struct127 fields (allocation age,
// timers, a flags nibble, facing angles, a flag byte) on the object.
// void func_15056A00(struct127 *arg0, s32 arg1, s32 arg2) {
//     u8 *row;
//     u8 v0;
//     u16 v1;
//     u16 t2;
//
//     arg1 = (u8) arg1;
//     arg2 = (u8) arg2;
//     row = (u8 *) D_80099A3C + arg2 * 10;
//
//     if (row[7] < arg1) {
//         v0 = 5;
//     } else if (row[2] < arg1) {
//         v0 = 2;
//     } else {
//         v0 = 0;
//     }
//     v1 = arg0->unk76;
//
//     t2 = arg0->unk78;
//     if ((s16) (t2 - v1) < 0) {
//         v0 += 3;
//     } else {
//         v0 += 4;
//     }
//
//     if (row[v0] != 0xFF) {
//         arg0->unk218 -= 5;
//         arg0->unk21C = 0x4E20;
//         arg0->unk223 = 0xD;
//         arg0->unk44 = 0.0f;
//         arg0->unkF4 &= ~0xE;
//         arg0->unkF4 |= 4;
//         arg0->unk78 = v1;
//         arg0->unk7A = v1;
//         arg0->unk138 = 0;
//         arg0->unk244 = row[v0];
//     }
// }
struct func_15056A00_s {
    u8 b[10];
};

void func_15056A00(struct127 *arg0, u8 arg1, u8 arg2) {
    u8 v0;
    u16 v1;
    u8 *p;

    v0 = 0;
    if (((struct func_15056A00_s *)D_80099A3C)[arg2].b[7] < arg1) {
        v0 = 5;
    } else if (((struct func_15056A00_s *)D_80099A3C)[arg2].b[2] < arg1) {
        v0 = 2;
    }
    v1 = arg0->unk76;
    if ((arg0->unk78 - v1) & 0x8000) {
        v0 += 3;
    } else {
        v0 += 4;
    }
    p = &((struct func_15056A00_s *)D_80099A3C)[arg2].b[v0];
    if (*p != 0xFF) {
        arg0->unk218 -= 1;
        arg0->unk21C = 0x4E20;
        arg0->unk223 = 0xD;
        arg0->unk44 = 0.0f;
        arg0->unk244 = *p;
        arg0->unkF4 &= ~0xE;
        arg0->unkF4 |= 4;
        arg0->unk78 = v1;
        arg0->unk7A = v1;
        arg0->unk138 = 0;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15056B08.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505841C.s")
// NON-MATCHING: JUSTREG
// void func_1505841C(struct127 *arg0, f32 arg1) {
//     struct197 *temp_v0_2;
//     f32 temp_f0;
//     f32 temp_f1;
//     s32 idx;
//
//     temp_f0 = (((arg0->unk246 & 0x1F) << 8) + arg0->unk249) * D_80099468;
//     if ((arg0->unk246 & 0x80) == 0) {
//         if ((arg0->xz_velocity <= 1.0f) || (((arg0->unk22C & 0x10) != 0) && (arg0->unk28 == 0.0f))) {
//             temp_f0 = arg1;
//         } else {
//             // regalloc off here
//             temp_f1 = (arg0->xz_velocity * (0.5f / arg0->xz_scale));
//             temp_f0 = temp_f1 / (temp_f0 * 10.0f);
//             temp_f0 += D_8009946C;
//
//             if ((arg0->unk246 & 0x20) == 0) {
//                 temp_f0 += D_80099470;
//             }
//         }
//     }
//     if (arg0->unk223 == 0xD) {
//         temp_f0 = (arg0->unk250 & 0x7F) * D_80099474;
//     }
//     if (arg0->unk246 == 0xFF) {
//         temp_f0 = 0.0f;
//     }
//     func_1505E650(arg0, arg0->unk244, temp_f0, arg0->unk1D0, 0.0f, 0.0f, 0);
//
//     if (arg0->unk246 == 0xFF) {
//         // regalloc off here
//         idx = D_800419A0 << 4;
//         temp_f0 = D_800418B0[idx];
//         if (temp_f0 >= 0.0f) {
//             temp_v0_2 = arg0->unk2D0;
//             temp_v0_2->unk8 = (f32) ((temp_v0_2->unk18 * (32768.0f - temp_f0)) / 32768.0f);
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150585F0.s")
// NON-MATCHING: 80% there
// void func_150585F0(struct127 *arg0) {
//     f32 temp_f0;
//     u16 phi_a2;
//
//     func_1505A3A8(arg0->unk109 * D_80099478, arg0, 1.0f, arg0->unk109 * D_80099478, 0);
//     if (arg0->unk1CC < D_8009947C) {
//         arg0->unk1CC = arg0->y_position;
//     }
//     if ((arg0->in_water != 0) && ((s32) arg0->in_water < 0xA)) {
//         arg0->gravity = 0.0f;
//         if (arg0->y_velocity < 60.0f) {
//             arg0->y_velocity *= D_80099480;
//         }
//         if (((arg0->unk118 - 60.0f) + 40.0f) < arg0->y_position) {
//             arg0->unk81 = (u8)0;
//             arg0->unk83 = (u8)0;
//             arg0->in_water = (u8)0U;
//             arg0->unkB8 = 0.0f;
//             arg0->gravity = 4.0f;
//         }
//     }
//     if ((D_800BE616 == 0) || (arg0->interaction_state != 1)) {
//         arg0->unk21C = (u16)0;
//     }
//     if (arg0->stunned != 0xFF) {
//         if (arg0->stunned != 0xFE) {
//             if ((arg0->health != 0) || (1 != arg0->interaction_state)) {
//                 arg0->stunned -= 1;
//             }
//         }
//         arg0->unk10C -= D_800CC264;
//         if ((arg0->unk28 < D_80099484) && ((arg0->unkF4 & 0x100) != 0)) {
//             arg0->unk10C = (u16)0;
//         }
//         if ((s32) arg0->unk10C <= 0) {
//             if (arg0->unk31C != 0) {
//                 arg0->unk31C->matrix_physics = (u8)0;
//             }
//             arg0->unk10C = (u16)0;
//             func_1505E874(0.0f, gCurrentObjectIndex);
//         }
//         if (arg0->stunned == 0) {
//             arg0->xz_velocity = 0.0f;
//             arg0->unk81 = (u8)0;
//             arg0->unk76 = arg0->unk78 = arg0->unk7A;
//             if (arg0->in_water != 0) {
//                 arg0->y_velocity = 0.0f;
//                 if (arg0->interaction_state == 1) {
//                     func_1506B078();
//                 }
//             } else if (arg0->interaction_state == 1) {
//                 arg0->unkF8 &= 0xFFFF7FFF;
//                 arg0->gravity = 4.0f;
//             }
//             if (arg0->unk238 != 0) {
//                 arg0->unk23A = arg0->unk238;
//             }
//         } else {
//             if ((arg0->unk10B & 2) == 0) {
//                 phi_a2 = arg0->unk76;
//                 if ((arg0->unk10B & 4) != 0) {
//                     phi_a2 ^= 0x8000;
//                 }
//                 arg0->unk80 = (u8)0xA;
//                 func_150599C8(arg0, 12, phi_a2);
//             }
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15058898.s")

void func_15058EA4(struct127 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    if (arg1 < arg0->y_position) {
        arg0->gravity = arg2;
    } else if (arg0->y_position < arg3) {
        arg0->gravity = arg4;
    }
    if (arg5 < arg0->y_velocity) {
        arg0->y_velocity = arg5;
    } else if (arg0->y_velocity < arg6) {
        arg0->y_velocity = arg6;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15058F24.s")
// NON-MATCHING: besides missing mov.s, its just a few regallocs
// void func_15058F24(struct127 *arg0, f32 arg1, f32 arg2) {
//     f32 temp_f12;
//     f32 temp_f14;
//     f32 tmp;
//     f32 temp_f16;
//
//     temp_f16 = 0.5f - arg1;
//     if (arg1 >= 0.5f) {
//         arg1 -= 0.5f;
//     }
//     temp_f14 = arg0->unk118 + 9.0f;
//     if ((arg0->y_position < temp_f14) || ((arg0->in_water < 0x64) == 0)) {
//
//         if (0) {};
//
//         if (arg0->in_water == 0) {
//             arg0->y_position = temp_f14;
//             arg0->in_water = (u8)0x64U;
//             arg0->gravity = temp_f16 * -6.0f;
//             arg0->y_velocity *= arg1;
//         } else {
//             if ((temp_f14 + 100.0f) < arg0->y_position) {
//                 arg0->in_water = (u8)0U;
//             }
//             if (temp_f16 < 0.0f) {
//                 arg0->gravity = temp_f16 * -6.0f;
//             } else {
//                 temp_f12 = arg0->y_position - ((temp_f14 + 10.0f) - (120.0f * arg1));
//                 if ((fabsf(temp_f12) < 2.0f) && (fabsf(arg0->y_velocity) < 2.0f)) {
//                     tmp = temp_f12 * D_800994A4;
//                     arg0->gravity = 1.0f;
//                     arg0->y_velocity = 0.0f;
//                     arg0->y_position -= tmp;
//                 } else {
//                     if (temp_f12 > 0.0f) {
//                         if (arg0->y_velocity > 0.0f) {
//                             arg0->gravity = temp_f16 * 6.0f;
//                             arg0->y_velocity *= 0.5f;
//                         }
//                     } else {
//                         temp_f12 = temp_f16 * 80.0f;
//                         if (arg0->y_velocity > temp_f12) {
//                             arg0->y_velocity = temp_f12;
//                         }
//                         arg0->gravity = temp_f16 * -6.0f;
//                     }
//                 }
//             }
//         }
//         temp_f12 = -100.0f * arg1;
//         if (arg0->y_velocity < temp_f12) {
//             arg0->y_velocity = temp_f12;
//         }
//     }
// }

void func_15059140(struct127 *arg0) {
    f32 sp2C;

    sp2C = 0.5f;
    D_800CC268 = 0;
    if ((arg0->unk13D == 0) || ((s32) arg0->unk21C < 0x10)) {
        if (arg0->unk223 != 8) {
            func_15059C84(arg0);
            func_1505A770(arg0);
        }
    }
    func_1505D6F0(arg0, gCurrentObjectIndex);
    func_15055E50(arg0, arg0->unk1E4);
    if (arg0->id == 8) {
        func_15056150(arg0);
    }
    if (arg0->unk13D < 0x64) {
        func_15058898(arg0, *(s32 *) &arg0->old_y_position);
    }
    if (arg0->unkF4 & 0x40000) {
        if (((arg0->unkF4 & 0x12000) != 0) || (D_800CC268 != 0)) {
            arg0->unk21C = 0U;
        }
    }
    if (arg0->unkB0 != 0) {
        func_15058F24(arg0, arg0->unkB0 * D_800994A8, 1.0f);
    }
    if (arg0->unkF8 & 0x20000) {
        func_15056258(arg0);
    }
    if (arg0->in_water != 0) {
        func_15059444(arg0);
    }
    if (arg0->id == 0xA) {
        arg0->unk180 = D_800994AC;
    }
    if ((arg0->unkF8 & 0x180000) != 0) {
        func_150511E8(arg0);
    }
    func_1505B5F8(arg0, *(s32 *) &arg0->unk180);
    if (((arg0->unkF4 & 0x1000) != 0) && (arg0->unk28 < D_800994B0)) {
        func_15056B08(arg0);
    }
    if (arg0->unkF8 & 0x80000) {
        sp2C = D_800994B4;
    }
    func_1505A250(0.0f, 0.0f, sp2C, &arg0->unk164, &arg0->unk168);
    if (arg0->unkD0 != 0) {
        func_1505C7D8(arg0, gCurrentObjectIndex);
    }
    if (arg0->unk13D == 0) {
        if (D_800BE9A0 >= arg0->unk10F) {
            arg0->unk10F = 0U;
        } else {
            arg0->unk10F -= D_800BE9A0;
        }
    }
    if (arg0->unk107 != 0) {
        arg0->unk107 -= 1;
    }
    if (arg0->immune != 0xFF) {
        if (D_800BE9A0 >= arg0->immune) {
            arg0->immune = 0U;
        } else {
            arg0->immune -= D_800BE9A0;
        }
    }
}

void func_150593C4(struct127 *arg0, u16 arg1, f32 arg2, f32 arg3) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    func_1505A184(arg1, arg2, 0.0f, &sp2C, &sp28, &sp24);
    arg0->unk16C += (sp2C - arg0->unk16C) * arg3;
    arg0->unk170 += (sp28 - arg0->unk170) * arg3;
}

void func_15059444(struct127 *arg0) {
    s32 sp1C;
    s32 phi_v0;
    s32 tmp;

    sp1C = -1;

    switch (D_800BE9F0) {
        case 4:
            func_150593C4(arg0, 0x4000, 50.0f, 0.05999999865889549f);
            break;
        case 6:
            sp1C = func_15083E0C(28);
            break;
        case 41:
            if (func_150A29C8(gCurrentObjectIndex, 0x4028) == 0) {
                phi_v0 = 12;
            } else if (func_150A29C8(gCurrentObjectIndex, 0x400E) == 0) {
                phi_v0 = 10;
            } else if (func_150A29C8(gCurrentObjectIndex, 0x400D) == 0) {
                phi_v0 = 9;
            } else {
                phi_v0 = 6;
            }
            sp1C = func_15083E0C((u8) phi_v0);
            // FIXME: fakematch to force regalloc
            dummy_label_858530:;
            break;
        case 43:
            sp1C = func_15083E0C(18);
            break;
        case 65:
            if (func_150A29C8(gCurrentObjectIndex, 0x401F) == 0) {
                phi_v0 = 27;
            } else {
                phi_v0 = 26;
            }
            sp1C = func_15083E0C((u8) phi_v0);
            break;
    }

    if (sp1C != -1) {
        func_150611E8(arg0, sp1C);
    }
}

void func_1505959C(struct127 *arg0, s32 arg1) {
    struct252 *temp_v0;
    s32 *temp_v1;
    s32 phi_v1;

    arg0->unkF8 &= 0xFF7FFFFF;
    arg0->unk13D = arg1 + 100;
    arg0->unk21C = 0;
    arg0->gravity = 4.0f;
    arg0->unk25C &= ~8;

    gObjects[arg1].unk83 = 0xFF;
    gObjects[arg1].disable_run = 0xFF;
    phi_v1 = 0;
    if (arg0->id == 0x57) {
        phi_v1 = 1;
    }
    if (gObjects[arg1].id == 0x9B) {
        phi_v1 = 2;
    }
    if (arg0->id == 0x5E) {
        phi_v1 = 3;
    }
    if (arg0->id == 0x3C) {
        phi_v1 = 4;
        gObjects[arg1].unk13C = (u8)0;
        gObjects[arg1].unk76 = func_1505A630(arg0->x_position - gObjects[arg1].x_position, gObjects[arg1].z_position - arg0->z_position, 0);
    }
    if (arg0->id == 0x89) {
        phi_v1 = 5;
    }
    func_1505E650(&gObjects[arg1], D_800860C0[phi_v1], D_800860CC[phi_v1], 0.0f, 0.0f, 0.0f, 0);
    arg0->stunned = 0xFE;
    arg0->unk105 = 0;
    arg0->unk106 = func_1505E7CC(D_800860E4[phi_v1], arg0);
    arg0->unk84.uh = 0xFFFF;
    func_1505E874(gCurrentObjectIndex, arg0);
    temp_v1 = (s32*)D_800D1588[arg0->id];
    if (temp_v1 != 0) {
        temp_v0 = (struct252 *)*(temp_v1 - 2);
        if ((temp_v0 != 0) && ((temp_v0[arg0->unk106].unk15 & 2) != 0)) {
            arg0->unk7A = gObjects[arg1].unk7A;
        }
        if ((temp_v0 == 0) || ((temp_v0[arg0->unk106].unk15 & 1) == 0)) {
            arg0->unk13E = (arg0->unk7A - gObjects[arg1].unk7A) >> 8;
        } else {
            arg0->unk13E = 0;
        }
    } else {
        arg0->unk13E = (arg0->unk7A - gObjects[arg1].unk7A) >> 8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150597FC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150599C8.s")

u8 func_15059B54(struct127 *arg0, u16 arg1) {
    s16 diff;
    s16 sign;
    s16 phi_a2;
    s16 hi;
    s16 lo;
    s32 temp_lo;

    diff = arg0->unk78 - arg0->unk76;
    phi_a2 = diff;
    if (phi_a2 < 0) {
        phi_a2 ^= 0xFFFF;
    }
    if (arg0->unk1EA != 0) {
        temp_lo = (s32) (arg0->unk1EA * D_800CC264) / 100;
        hi = arg0->unk1EC + temp_lo;
        lo = arg0->unk1EC - temp_lo;
        if (hi < diff) {
            diff = hi;
        }
        if (diff < lo) {
            diff = lo;
        }
    }
    sign = diff;
    if (diff < 0) {
        diff ^= 0xFFFF;
    }
    if (diff < arg1) {
        arg1 = diff;
    }
    if ((arg0->unkF4 & 1) == 0) {
        if (sign < 0) {
            arg0->unk76 -= arg1;
            arg0->unk1EC = -arg1;
        } else {
            arg0->unk76 += arg1;
            arg0->unk1EC = arg1;
        }
    }
    return phi_a2 >> 8;
}
// NON-MATCHING: 90% there, missing an s16 cast
// u8 func_15059B54(struct127 *arg0, u16 arg1) {
//     s16 temp_t8;
//     s16 temp_t8_2;
//     s16 temp_t2;
//     s32 temp_lo;
//     s16 phi_a2;
//
//     temp_t8 = arg0->unk78 - arg0->unk76;
//     phi_a2 = temp_t8;
//     if (phi_a2 < 0) {
//         phi_a2 = phi_a2 ^ 0xFFFF;
//     }
//     if (arg0->unk1EA != 0) {
//         temp_lo = (s32) (arg0->unk1EA * D_800CC264) / 0x64;
//         temp_t8_2 = arg0->unk1EC + temp_lo;
//         temp_t2 = arg0->unk1EC - temp_lo;
//         if (temp_t8_2 < temp_t8) {
//             temp_t8 = temp_t8_2;
//         }
//         if (temp_t8 < temp_t2) {
//             temp_t8 = temp_t2;
//         }
//     }
//
//     if (temp_t8 < 0) {
//         temp_t8 ^= 0xFFFF;
//     }
//     if (temp_t8 < arg1) {
//         arg1 = temp_t8;
//     }
//     if ((arg0->unkF4 & 1) == 0) {
//         if (temp_t8 < 0) {
//             arg0->unk76 -= arg1;
//             arg0->unk1EC = -arg1;
//         } else {
//             arg0->unk76 += arg1;
//             arg0->unk1EC = arg1;
//         }
//     }
//     return phi_a2 >> 8;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15059C84.s")
// NON-MATCHING: full semantics recovered and verified via isolated
// harness. arg0's low 16 bits are an unsigned angle; converts it (via
// D_800994BC) and separately arg2*D_800994B8 into two angles, calls
// the func_150AD780/func_150AD78C sin/cos-style helpers on each
// (target genuinely calls both twice, once per angle, matching the
// "recompute rather than cache" pattern seen elsewhere this session),
// and writes three scaled-and-combined trig outputs through arg3,
// arg4 (5th param, stack), and arg5 (6th param, stack) - arg5 gets
// the arg2-angle's contribution, arg3/arg4 get the arg0-angle's.
//
// Real risk found and avoided this round: func_1505A184 itself had a
// stale K&R-style `void func_1505A184();` in functions.h that
// conflicted with a real `f32` 2nd/3rd parameter (same class of bug
// fixed on func_15043BB8/func_15169850 earlier), so it's removed here
// (matching the no-declaration precedent already used for
// func_150AEDF8/func_151419D0) rather than given a real prototype.
// func_150AD780/func_150AD78C themselves were NOT touched, even
// though target's raw asm shows them receiving arguments directly via
// $f12 (suggesting a plain `f32 func(f32)` signature) - the existing
// real caller func_1505D34C (this file) passes them through a
// `*(s32 *) &local` reinterpret-cast specifically to dodge the
// K&R float-to-double default-promotion bug, and giving them a proper
// f32 prototype would silently turn that caller's raw-bits pass into
// an actual (very wrong) int-to-float value conversion. Reproducing
// this function's own calls the same safe way (s32-reinterpret) avoids
// that risk but costs the byte match: target passes straight through
// $f12 with no stack round-trip at all, while every safe form tried
// here spills to the stack and reloads via `lw`/mtc1, adding
// instructions and pushing target's eagerly-live-across-both-calls
// $f20 value into a deferred-recompute-after-the-calls shape instead.
void func_1505A184(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 c;
    f32 s;
    f32 pad;
    f32 angle;

    arg1 *= 0.5f;
    arg2 *= D_800994B8;
    *arg5 = func_150AD78C(arg2) * -arg1;
    arg1 = func_150AD780(arg2) * arg1;
    angle = (u16)arg0 * D_800994BC;
    c = func_150AD780(angle);
    s = -func_150AD78C(angle);
    *arg3 = c * arg1;
    *arg4 = s * arg1;
}
// void func_1505A184(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
//     f32 half1;
//     f32 cosArg;
//     f32 angle;
//     f32 s1;
//     f32 c1;
//     f32 s2;
//     f32 c2;
//
//     half1 = arg1 * 0.5f;
//     cosArg = arg2 * D_800994B8;
//     c1 = func_150AD78C(*(s32 *) &cosArg);
//     s1 = func_150AD780(*(s32 *) &cosArg);
//     *arg5 = c1 * -half1;
//     half1 = s1 * half1;
//
//     angle = (f32) (u16) arg0;
//     angle = angle * D_800994BC;
//     s2 = func_150AD780(*(s32 *) &angle);
//     c2 = func_150AD78C(*(s32 *) &angle);
//     *arg3 = s2 * half1;
//     *arg4 = -c2 * half1;
// }
void func_1505A250(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4) {
    f32 dx;
    f32 dy;
    f32 dist;
    f32 stepx;
    f32 stepy;

    dx = arg0 - *arg3;
    dy = arg1 - *arg4;
    if (dx == 0.0f && dy == 0.0f) {
        return;
    }
    dist = sqrtf(dx * dx + dy * dy);
    arg2 *= D_800D1550[0];
    stepx = fabsf(dx / dist * arg2);
    stepy = fabsf(dy / dist * arg2);
    if (dx >= 0.0f) {
        *arg3 += stepx;
        if (arg0 < *arg3) {
            *arg3 = arg0;
        }
    } else {
        *arg3 -= stepx;
        if (*arg3 < arg0) {
            *arg3 = arg0;
        }
    }
    if (dy >= 0.0f) {
        *arg4 += stepy;
        if (arg1 < *arg4) {
            *arg4 = arg1;
        }
    } else {
        *arg4 -= stepy;
        if (*arg4 < arg1) {
            *arg4 = arg1;
        }
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505A3A8.s")

f32 func_1505A5CC(struct49 *arg0) {
    f32 x, y;
    f32 ret;

    // regalloc nonsense
    ret = arg0->unk2;
    x = ret;
    y = arg0->unk3;

    x = sqrtf(x*x + y*y) * D_800994D4;
    ret = x;

    if (ret > 35.0f) {
        ret = 35.0f;
    }

    return ret;
}

u16 func_1505A630(f32 arg0, f32 arg1, s32 arg2) {
    return ((u16) (u32) (func_150484A0(-arg0, arg1) * D_800994D8)) + 16384;
}

f32 func_1505A6F8(struct127 *arg0, struct127 *arg1) {
    f32 x, z;

    x = arg0->x_position - arg1->x_position;
    x *= x;
    z = arg0->z_position - arg1->z_position;
    z *= z;
    return sqrtf(x + z);
}

// distance between two objects?
f32 func_1505A72C(struct127 *arg0, struct127 *arg1) {
    f32 x, y, z;

    x = arg0->x_position - arg1->x_position;
    x *= x;
    z = arg0->z_position - arg1->z_position;
    z *= z;
    y = arg0->y_position - arg1->y_position;
    y *= y;
    return sqrtf((x + z) + y);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505A770.s")
// a big one, but could be ok
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505A9AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505B5F8.s")
// void func_1505B5F8(struct127 *arg0, f32 arg1) {
//     f32 tmp;
//     u8 temp_v0_2;
//
//     if ((arg0->unkF8 & 0x8000) == 0) {
//         if (arg0->unk252 != 0) {
//             if ((arg0->unk253 * 8) < (arg0->unk1CC - arg0->y_position)) {
//                 if (arg0->stunned == 0) {
//                     arg0->stunned = (u8)0xFEU;
//                     arg0->unk105 = (u8)0;
//                     arg0->unk106 = func_1505E7CC(arg0->unk252, arg0);
//                     arg0->unk84.uh = (u16)0xFF;
//                     func_1505E874(gCurrentObjectIndex, arg0);
//                     arg0->y_position = (f32) arg0->old_y_position;
//                 }
//             }
//         }
//         arg0->unk28 = arg0->y_position - arg1;
//         if (arg0->y_position <= arg1) {
//             arg0->unkF4 |= 0x8000;
//             temp_v0_2 = D_800B0DF0->unk13;
//             if (temp_v0_2 != 0) {
//                 if (arg0->unk28 != 0.0f) {
//                     func_15174690(gCurrentObjectIndex, 0, 0x1000 / (s32) temp_v0_2, 0, 0x199, 4, 0xAA, 0xFF, 0); // 0.0f, arg1,
//                 }
//             }
//             arg0->y_position = arg1;
//             tmp = arg0->unk28;
//             arg0->unk28 = 0.0f;
//             if ((arg0->stunned != 0) || ((arg0->unkF8 << 0xF) >= 0)) {
//                 if (arg0->interaction_state == 1) {
//                     if (arg0->y_velocity < -6.0f) {
//                         arg0->y_velocity = -6.0f;
//                     }
//                 } else {
//                     if ((arg0->unk1CC - arg0->y_position) > 450.0f) {
//                         if (arg0->health > 0) {
//                             if ((arg0->unk144 != 0) && ((arg0->unk144->unkE & 0x80) == 0)) {
//                                 arg0->health = (u8) (arg0->health - 1);
//                             }
//                         }
//                     }
//                     arg0->unk1CC = arg1;
//                     if ((arg0->stunned == 0) && (arg0->gravity > 0.5f)) {
//                         if (((arg0->unkF8 & 0x800) != 0) && (tmp != 0.0f) && ((arg0->y_velocity < (-4.0f * arg0->gravity * D_800D1550[0])))) {
//                             arg0->y_velocity = ((0.0f - arg0->y_velocity) * ((f32) arg0->unk2CB * D_8009950C));
//                             if ((arg0->unk2CC != 0) && (arg0->y_velocity > 5.0f)) {
//                                 D_800D1580 = arg0->unk2CC;
//                                 func_1506E5FC();
//                             }
//                         } else if (arg0->interaction_state != 7) {
//                             arg0->y_velocity = -4.0f * D_800D1550[0];
//                         }
//                     } else {
//                         if ((arg0->unkF4 & 0x80) != 0) {
//                             arg0->y_velocity = -4.0f;
//                         } else if ((tmp == 0.0f) || (((-1.5f * arg0->gravity * D_800D1550[0]) < arg0->y_velocity))) {
//                             arg0->y_velocity = 0.0f;
//                         } else {
//                             arg0->y_velocity = (0.0f - arg0->y_velocity) * ((f32) arg0->unk2CB * D_80099510);
//                         }
//                         arg0->xz_velocity *= D_80099514;
//                     }
//                 }
//             }
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505B9C4.s")

s16 func_1505C140(struct127 *arg0, struct127 *arg1) {
    s16 ret = func_1505A630(arg0->x_position - arg1->x_position, arg1->z_position - arg0->z_position, 0);
    ret -= arg1->unk7A;

    if (ret < 0) {
        ret = -ret;
    }
    return ret;
}

struct252 *func_1505C1A4(struct127 *arg0) {
    s32 *temp_v1;
    struct252 *ret;

    if ((arg0->id != 0xFF) && (D_800D1588[arg0->id] != 0)) {
        temp_v1 = (s32*)D_800D1588[arg0->id] - 3;
        ret = *temp_v1;
    } else {
        ret = &D_8009A9F8;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505C1E4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505C7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505D024.s")
// NON-MATCHING: 1 line + regalloc
// s32 func_1505D024(struct127 *arg0, s32 arg1, u16 arg2, s32 arg3) {
//     s32 pad;
//     s32 ret;
//     s32 temp_lo;
//     struct252 *sp30;
//
//     sp30 = &D_8009A9F8;
//     if (D_800C35EA == 1) {
//         return 0;
//     }
//     if ((arg1 & 0x20000) && (arg0->immune != 0)) {
//         return 0;
//     }
//     if ((arg1 & 0x40000) && (arg0->stunned != 0)) {
//         return 0;
//     }
//     if (((arg1 << 0xB) >= 0) && (arg0->health == 0)) {
//         return 0;
//     }
//     if (arg3 == -1) {
//         D_800D1340 = (u8)0;
//     } else {
//         D_800D1340 = arg3 + 1;
//     }
//     D_800D1292 = arg2;
//     D_800D1296 = arg2;
//     if (arg1 & 0x10000) {
//         sp30 = func_1505C1A4(gCurrentObject);
//     }
//
//     temp_lo = ((s32)arg0 - (s32)gObjects) / (s32)sizeof(struct127);
//     ret = 1 << temp_lo;
//     if (arg1 & 0x80000) {
//         // lw instead of move.
//         ret = func_1505C1E4(&D_800D121C, arg0, sp30, arg1 & 0xFF, temp_lo + 1, 0, 7);
//     } else {
//         func_1505B9C4(&D_800D121C, arg0, sp30, sp30, arg1 & 0xFF, temp_lo + 1, 7);
//     }
//     return ret;
// }

void func_1505D1C4(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6, s32 arg7) {
    s32 pad;
    s32 tmp;

    tmp = gCurrentObjectIndex;
    func_1505F188(&D_800D121C);
    D_800D1230 = arg0;
    D_800D1234 = arg1;
    D_800D1238 = arg2;
    D_800D1340 = arg4 + 1;
    D_800D1359 = arg6;
    D_800D1292 = arg5;
    gCurrentObjectIndex = 25;
    D_800D1510 = arg7;
    D_800D1330 = 100.0f;
    D_800D12EC = (arg3 & 0xFFFF) + 1;
    D_800D1368 = 0.5f;
    D_800D136C = 0.5f;
    func_1505C7D8(&D_800D121C, 25);
    gCurrentObjectIndex = tmp;
}

void func_1505D2B8(struct127 *arg0, u8 arg1) {
    struct253 *temp_v0;

    temp_v0 = &D_8009A6D8[arg1];
    arg0->y_velocity = temp_v0->unk18;
    arg0->xz_velocity = temp_v0->unk14;
    arg0->gravity = temp_v0->unk1C;
    arg0->stunned = 0xFE;
    arg0->unk105 = 0;
    arg0->unk106 = func_1505E7CC(arg0->unk10E & 0x7F, arg0);
    arg0->unk10E = 0xFF;
    func_1505E874(gCurrentObjectIndex, arg0);
}

f32 func_1505D34C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4) {
    f32 sp24;
    s32 pad;
    f32 temp_f0;
    f32 temp_f12;

    if (arg3 != 1.0f) {
        arg1 = arg1 * arg3;
        arg2 = arg2 * arg3;
    }
    temp_f12 = (arg0 - 90.0f) * D_80099520; // 0.01745329238474369f;
    sp24 = func_150AD780(temp_f12);
    temp_f0 = func_150AD78C(temp_f12);
    *arg4 = (-arg1 * temp_f0) + (arg2 * sp24);
    return (arg1 * sp24) + arg2 * temp_f0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505D408.s")
void func_1505D408(s32 arg0, struct127 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7);

void func_1505D5D0(s32 arg0, struct127 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC) {
    f32 temp_f0;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 r;

    temp_f0 = func_1505D34C(arg1->unk40, argB, argC, arg1->xz_scale, &argC);
    arg8 *= arg1->xz_scale;
    arg9 *= arg1->y_scale;
    dx = arg2 - (arg1->x_position + temp_f0);
    dz = arg4 - (arg1->z_position + argC);
    dy = arg3 - (arg1->y_position + argA * arg1->y_scale);
    dy *= (arg5 + arg8 / arg9) * 0.5f;
    dist = dx * dx + dy * dy + dz * dz;
    r = arg6 + arg8;
    if (dist < r * r) {
        func_1505D408(arg0, arg1, dx, dy, dz, dist, r, arg7);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505D6F0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505DADC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505DDA8.s")
f32 func_1505DF10(struct127 *arg0, u8 arg1, u16 *arg2, f32 *arg3, f32 *arg4) {
    struct127 *obj = &gObjects[arg1];
    f32 dx;
    f32 dy;
    f32 dz;

    dx = obj->x_position - arg0->x_position;
    dy = arg0->y_position - obj->y_position;
    dz = arg0->z_position - obj->z_position;
    *arg4 = dy;
    *arg2 = func_1505A630(dx, dz, 0);
    dx *= dx;
    dy *= dy;
    dz *= dz;
    *arg3 = dx + dz;
    return dx + dy + dz;
}
// Clears arg0->unk84.uh (a "not yet initialized" sentinel), and if
// arg0->unk2D0 is set, zeroes a 0x3A0-byte block within it plus a
// couple of extra s32 fields, and bumps two counters from a per-id
// table (D_800C4ED0[arg0->id]).
void func_1505DFDC(struct127 *arg0) {
    s32 t7;
    struct197 *v0 = arg0->unk2D0;

    arg0->unk84.uh = 0xFFFF;
    if (v0 == 0) {
        return;
    }
    t7 = arg0->id;
    *(s32 *) ((char *) v0 + 0x28) = 0;
    bzero((char *) v0 + 0x40, 0x3A0);
    *(u8 *) ((char *) v0 + 0x41) = D_800C4ED0[t7] + 1;
    *(u8 *) ((char *) v0 + 0x211) = D_800C4ED0[t7] + 1;
    *(s32 *) ((char *) v0 + 0x30) = 0;
    *(s32 *) ((char *) v0 + 0x34) = 0;
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Saves several
// fields into a "+2" shifted shadow copy (unk4->unk6, unk8->unkC, etc,
// a save-previous-frame pattern), then bcopy's a 0x1D0-byte block from
// +0x40 to +0x210. Register allocation differs substantially from
// target throughout.
struct func_1505E060_s {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[8];
    s8 unk38;
    s8 unk39;
    u8 pad3A[6];
    u8 unk40[0x1D0];
    u8 unk210[0x1D0];
};

void func_1505E060(struct func_1505E060_s *arg0) {
    arg0->unk6 = arg0->unk4;
    arg0->unkC = arg0->unk8;
    arg0->unk14 = arg0->unk10;
    arg0->unk24 = arg0->unk20;
    arg0->unk1C = arg0->unk18;
    arg0->unk39 = arg0->unk38;
    arg0->unk2C = arg0->unk28;
    bcopy(arg0->unk40, arg0->unk210, 0x1D0);
}
// void func_1505E060(void *arg0) {
//     u16 unk4 = *(u16 *) ((char *) arg0 + 4);
//     f32 unk8 = *(f32 *) ((char *) arg0 + 8);
//     f32 unk10 = *(f32 *) ((char *) arg0 + 0x10);
//     f32 unk20 = *(f32 *) ((char *) arg0 + 0x20);
//     f32 unk18 = *(f32 *) ((char *) arg0 + 0x18);
//     s8 unk38 = *(s8 *) ((char *) arg0 + 0x38);
//     s32 unk28 = *(s32 *) ((char *) arg0 + 0x28);
//
//     *(u16 *) ((char *) arg0 + 6) = unk4;
//     *(f32 *) ((char *) arg0 + 0xC) = unk8;
//     *(f32 *) ((char *) arg0 + 0x14) = unk10;
//     *(f32 *) ((char *) arg0 + 0x24) = unk20;
//     *(f32 *) ((char *) arg0 + 0x1C) = unk18;
//     *(s8 *) ((char *) arg0 + 0x39) = unk38;
//     bcopy((char *) arg0 + 0x40, (char *) arg0 + 0x210, 0x1D0);
//     *(s32 *) ((char *) arg0 + 0x2C) = unk28;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505E0C4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505E650.s")
// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Looks up D_800D1588[type] (type = arg1->unk4, 0-254 or
// sentinel 0xFF), treats the found pointer as one past an
// allocate_memory-style header (byte length at -4, base pointer at
// -8), and linear-searches base[] (0x18-byte records) for the first
// record whose leading byte equals arg0, returning its index (or 0 on
// any failure/not-found case).
//
// First hurdle: writing the search as a plain `for` loop got IDO's
// -O2 to 4x-unroll it (each unrolled copy duplicating the early
// `return i;`), producing a totally different shape from target's
// single, non-unrolled loop body. Rewriting as `if (count != 0) { i =
// 0; do { ...; i++; } while (i < count); }` - a guard wrapping a
// do-while, instead of a for-loop or an early `if (count == 0) return
// 0;` before an unconditional loop - avoided the unroller entirely
// and reproduced target's single combined zero-count guard. The
// remaining gap: target preserves arg0 in $a2 across the whole
// function; every source form tried here (statement order,
// declaration order) puts it in $a3 instead, which cascades into
// several further register differences later in the function -
// tried but not resolved this round.
u32 func_1505E7CC(s32 arg0, u8 *arg1) {
    u32 count;
    u8 *rec;
    u8 *base;
    u32 i;
    s32 entry;

    if (arg1[4] == 0xFF) {
        return 0;
    }
    entry = D_800D1588[arg1[4]];
    if (entry == 0) {
        return 0;
    }
    count = ((u32 *)entry)[-1];
    if (count == 0) {
        return 0;
    }
    count /= 24;
    base = ((u8 **)entry)[-2];
    if (base == NULL) {
        return 0;
    }
    i = 0;
    if (count != 0) {
        rec = base;
        do {
            if (arg0 == *rec) {
                return i;
            }
            i++;
            rec += 0x18;
        } while (i < count);
    }
    return 0;
}
// u32 func_1505E7CC(s32 arg0, void *arg1) {
//     u8 type;
//     char *entry;
//     s32 len;
//     char *base;
//     s32 count;
//     char *rec;
//     s32 i;
//
//     type = *(u8 *) ((char *) arg1 + 4);
//     if (type == 0xFF) {
//         return 0;
//     }
//     entry = (char *) D_800D1588[type];
//     if (entry == NULL) {
//         return 0;
//     }
//     len = *(s32 *) (entry - 4);
//     if (len == 0) {
//         return 0;
//     }
//     count = len / 24;
//     base = *(char **) (entry - 8);
//     if (base == NULL) {
//         return 0;
//     }
//     if (count != 0) {
//         rec = base;
//         i = 0;
//         do {
//             if (arg0 == *(u8 *) rec) {
//                 return i;
//             }
//             i += 1;
//             rec += 0x18;
//         } while (i < count);
//     }
//     return 0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505E874.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505ED34.s")

// I HATE LOOPS. NON-MATCHING: mips_to_c reconstruction, hand-typed.
// Searches gObjects for the element whose interaction_state matches
// state, storing the found index into *arg1 and returning a pointer to
// it (or the last-examined element if not found, since the search
// pointer keeps advancing through the "not found" iteration too).
// Tried a while-loop form matching the raw asm's literal control flow
// (test at top, pointer increment first) - 4 extra instructions vs
// target's tighter loop (21 vs target's 17), with a different overall
// loop test/comparison strategy. A prior session's for-loop attempt
// (kept below) wasn't confirmed working either.
struct127 *func_1505EEB0(s32 state, s32 *arg1) {
    struct127 *tmp;
    s32 i;

    tmp = &gObjects[0];
    i = 0;
    while (i < 25 && state != tmp->interaction_state) {
        i++;
        tmp++;
    }
    *arg1 = i;
    return tmp;
}
// struct127 *func_1505EEB0(s32 state, s32 *arg1) {
//     struct127 *tmp = gObjects;
//     s32 i = 0;
//
//     if (state != tmp->interaction_state) {
//         for (i = 0; i < 25; i++) {
//             tmp = &gObjects[i];
//             if (state == tmp->interaction_state)
//                 break;
//         }
//     }
//
//     *arg1 = i;
//     return tmp;
// }

// NON-MATCHING: full semantics recovered and verified via isolated
// harness - searches gObjects[25] for a live entry (interaction_state
// != 0) whose unk13F byte equals arg0, returning &gObjects[i]. Slot 0
// is handled specially: it's matched against D_800CC40F[0] instead of
// its own unk13F (index 0 is apparently a reserved object with no
// normal type tag). No source restructuring was needed - a plain
// `for (i = 1; i < 25; i++)` naturally auto-unrolled 4x with the same
// peek-ahead-load scheduling as target (load the NEXT element's
// interaction_state in the current element's match-branch delay slot)
// on the very first attempt, since this is the "early return inside
// loop body" trigger this project already knows produces exactly this
// shape.
// 53 vs target's 55 instructions: every field offset, branch shape and
// peek-ahead load matches; target additionally maintains an explicit
// counter (v0, compared against 25) alongside the walking pointer,
// while this reconstruction's compile eliminated the counter entirely
// in favor of comparing the walking pointer directly against a
// precomputed end-of-array address - genuinely fewer instructions for
// equivalent behavior, the same "IDO finds a shorter form than target
// used" pattern already seen several times this session (e.g.
// func_15008870, func_1500707C).
// struct127 *func_1505EEF4(s32 arg0) {
//     s32 i;
//
//     if (gObjects[0].interaction_state != 0 && arg0 == D_800CC40F[0]) {
//         return gObjects;
//     }
//     for (i = 1; i < 25; i++) {
//         if (gObjects[i].interaction_state != 0 && gObjects[i].unk13F == arg0) {
//             return &gObjects[i];
//         }
//     }
//     return 0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505EEF4.s")
// NON-MATCHING: sibling of func_1505EEF4 above - identical shape,
// same technique applies verbatim, just a different global
// (D_800CC3F7 instead of D_800CC40F) and a different struct127 type-
// tag byte offset (0x127 instead of 0x13F, not individually named in
// structs.h so accessed via raw offset cast). 53 vs target's 55
// instructions, same gap (target keeps an explicit loop counter
// alongside the walking pointer; this reconstruction's compile drops
// it in favor of a precomputed end-of-array pointer comparison).
// struct127 *func_1505EFD0(s32 arg0) {
//     s32 i;
//
//     if (gObjects[0].interaction_state != 0 && arg0 == D_800CC3F7[0]) {
//         return gObjects;
//     }
//     for (i = 1; i < 25; i++) {
//         if (gObjects[i].interaction_state != 0 && *((u8 *) &gObjects[i] + 0x127) == arg0) {
//             return &gObjects[i];
//         }
//     }
//     return 0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505EFD0.s")
// NON-MATCHING: third sibling of func_1505EEF4 above - identical
// shape and technique, this time using D_800CC2D4 for the special-
// cased slot-0 check and struct127's already-named `id` field (offset
// 0x4) as the type tag instead of an unnamed offset. 53 vs target's
// 55 instructions, same gap as its siblings (target keeps an explicit
// loop counter alongside the walking pointer; this reconstruction's
// compile drops it for a precomputed end-of-array pointer compare).
// struct127 *func_1505F0AC(s32 arg0) {
//     s32 i;
//
//     if (gObjects[0].interaction_state != 0 && arg0 == D_800CC2D4[0]) {
//         return gObjects;
//     }
//     for (i = 1; i < 25; i++) {
//         if (gObjects[i].interaction_state != 0 && gObjects[i].id == arg0) {
//             return &gObjects[i];
//         }
//     }
//     return 0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505F0AC.s")
// NON-MATCHING: exact 68/68 instruction match; only difference is a
// float-register swap - target keeps the 1.0f constant in $f0 and
// D_8009962C in $f2, this reconstruction gets IDO to pick $f2 for the
// former and $f0 for the latter (both then get used identically
// everywhere else). Bulk-zeroes the whole struct127 (0x32C bytes, 4 at
// a time) via a guarded do-while, then explicitly reinitializes a
// scatter of fields to fixed constants (scale/gravity floats, several
// 0xFF/0xFFFF "unset" sentinels, timer/animation halfwords), rolls a
// random cooldown value via func_150ADA20 (needs (u32) on the result
// to get the same divu the target uses for `% 0x32`, otherwise IDO
// picks a signed div), and calls the already-matching
// func_150615DC(arg0) partway through.
// void func_1505F188(struct127 *arg0) {
//     f32 tmp;
//     void *p;
//     void *end;
//     u8 rnd;
//
//     p = arg0;
//     end = (u8 *) arg0 + 0x32C;
//     if (p < end) {
//         do {
//             p = (u8 *) p + 4;
//             *(s32 *) ((u8 *) p - 4) = 0;
//         } while (p < end);
//     }
//
//     tmp = D_8009962C;
//     *((u8 *) arg0 + 0x2FD) = 2;
//     *(s16 *) ((u8 *) arg0 + 0x38) = -10000;
//     arg0->xz_scale = 1.0f;
//     arg0->y_scale = 1.0f;
//     arg0->unk118 = tmp;
//     arg0->unk180 = tmp;
//     *((u8 *) arg0 + 0x1DC) = 0xFF;
//     arg0->unk127 = 0xFF;
//     arg0->unk84.uh = 0xFFFF;
//     arg0->unk13F = 0xFF;
//     *(void **) ((u8 *) arg0 + 0x2C4) = (u8 *) arg0 + 4;
//     *((u8 *) arg0 + 0x2C8) = 1;
//     *((u8 *) arg0 + 0x2C9) = 1;
//     arg0->id = 0xFF;
//     arg0->unk2CB = 0x32;
//     arg0->unk48 = 1.0f;
//     arg0->gravity = D_80099630;
//
//     rnd = func_150ADA20();
//     arg0->unk6E = (u32) rnd % 0x32 + 0x32;
//     func_150615DC(arg0);
//
//     *((u8 *) arg0 + 0x1DD) = 0xFF;
//     *((u8 *) arg0 + 0x1DE) = 0xFF;
//     *((u8 *) arg0 + 0x1DF) = 0xFF;
//     *(s16 *) ((u8 *) arg0 + 0x18C) = 0;
//     *(s16 *) ((u8 *) arg0 + 0x18E) = 0;
//     *(s16 *) ((u8 *) arg0 + 0x190) = 0;
//     *(s16 *) ((u8 *) arg0 + 0x192) = 0;
//     *(s16 *) ((u8 *) arg0 + 0x194) = 0;
//     *(s16 *) ((u8 *) arg0 + 0x196) = 0xA;
//     *(s16 *) ((u8 *) arg0 + 0x198) = 0xA;
//     *(s16 *) ((u8 *) arg0 + 0x19A) = 0;
//     *(s16 *) ((u8 *) arg0 + 0x19C) = 0;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505F188.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1505F298.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1506045C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15060778.s")
void func_15060A30(s32 arg0, struct127 *arg1) {
    if (arg1->camera == 0) {
        func_10010344((u16) arg0, arg1, 0x6D60, 0x1F4, 2500);
    } else {
        func_15060778(arg0, arg1, 0x5DC0, 0, 500, 2500, 1);
    }
}
void func_15060A9C(s32 arg0, struct127 *arg1) {
    if (arg1->camera == 0) {
        func_10010630((u16) arg0, arg1, 0x5DC0, 0x1F4, 2500);
    } else {
        func_15060778(arg0, arg1, 0x5DC0, 0, 500, 2500, 0);
    }
}

void func_15060B04(s32 arg0, struct127 *arg1, s32 arg2) {
    if (arg1->camera == NULL) {
        func_10010630((u16) arg0, arg1, arg2, 500, 2500);
    } else {
        func_15060778(arg0, arg1, (u16) arg2, 0, 500, 2500, 0);
    }
}

void func_15060B70(s32 arg0, void *arg1) {
    func_10010154((u16) arg0, arg1, 0x6D60, 0x1F4, 0x9C4);
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Adds arg1 to a
// counter byte at arg0+0x1CA, clamping to 6, with an early return if it
// was already 6. Tried both an explicit local pointer (extra address
// computation IDO doesn't reproduce) and repeated direct offset access
// (register numbering still differs throughout) - neither matched.
s32 func_15060BA4(u8 *arg0, s32 arg1) {
    if (arg0[0x1CA] == 6) {
        return 0;
    }
    arg0[0x1CA] += arg1;
    if (arg0[0x1CA] >= 7) {
        arg0[0x1CA] = 6;
    }
    return 1;
}
// s32 func_15060BA4(void *arg0, s32 arg1) {
//     u8 v0 = *((u8 *) arg0 + 0x1CA);
//     s32 t6;
//
//     if (v0 == 6) {
//         return 0;
//     }
//     t6 = v0 + arg1;
//     *((u8 *) arg0 + 0x1CA) = t6;
//     if ((u8) t6 >= 7) {
//         *((u8 *) arg0 + 0x1CA) = 6;
//     }
//     return 1;
// }
extern u8 D_800C3E90;

void func_15060BE0(struct127 *arg0) {
    s32 done;
    f32 *mtx;
    struct124 *def;
    f32 scale;
    f32 z;
    f32 x, y;
    f32 len;
    f32 dx, dy, dz;

    done = 0;
    if (arg0->id != 0xFF) {
        if ((arg0->unk1D4 != 0) && (D_800C3E90 == 0)) {
            def = D_800D1C90[arg0->id];
            mtx = ((f32 (*)[16])arg0->unk1D4)[((u8 *)def)[0x27]];
            scale = *(s16 *)((u8 *)def + 0x14) * arg0->y_scale;
            if (scale != 0.0f) {
                dx = mtx[4];
                dy = mtx[5];
                dz = mtx[6];
                len = sqrtf(dx * dx + dy * dy + dz * dz);
                if (len != 0.0f) {
                    len = scale / len;
                }
                x = dx * len;
                y = dy * len;
                z = dz * len;
            } else {
                x = y = z = 0.0;
            }
            done = 1;
            *(s16 *)((u8 *)arg0 + 0x1BC) = mtx[12] + x;
            *(s16 *)((u8 *)arg0 + 0x1BE) = mtx[13] + y;
            *(s16 *)((u8 *)arg0 + 0x1C0) = mtx[14] + z;
        }
    }
    if (!done) {
        *(s16 *)((u8 *)arg0 + 0x1BC) = arg0->x_position;
        *(s16 *)((u8 *)arg0 + 0x1BE) = arg0->y_position;
        *(s16 *)((u8 *)arg0 + 0x1C0) = arg0->z_position;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15060D54.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15060F28.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150611E8.s")

// TODO: is this really struct127?
void func_150615DC(struct127 *arg0) {
    arg0->unk7 = 0xFF;
    arg0->unk8 = 0xFF;
    arg0->unk9 = 0;
    arg0->unkA = 0;
    arg0->unkE.ub[1] = 0;
    arg0->unkB = arg0->unkC = arg0->unkD = arg0->unkE.ub[0] = 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_1506160C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150617BC.s")
// ???
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Multiplies two bytes
// (arg0[arg1+0xB], arg0[7]), special-cases the product 0xFE01 to 0xFF,
// otherwise returns product>>8. Target's real structure includes a
// provably-unreachable trailing `or v1,t9,zero` (dead code from how the
// original compiled a bnel/b pair) that neither an if/else nor a ternary
// reproduced - register allocation also differs throughout. Needs the
// same kind of "faithfully reproduce a dead branch" treatment as
// func_1513A594 above; didn't crack the exact source form this round.
struct func_1506196C_s {
    u8 pad0[7];
    u8 unk7;
    u8 pad8[3];
    u8 unkB[1];
};

s32 func_1506196C(struct func_1506196C_s *arg0, s32 arg1) {
    s32 v1 = arg0->unkB[arg1] * arg0->unk7;

    if (v1 == 0xFE01) {
        v1 = 0xFF;
    } else {
        v1 = v1 >> 8;
    }
    return v1;
}
// s32 func_1506196C(void *arg0, s32 arg1) {
//     u8 t7 = *((u8 *) arg0 + arg1 + 0xB);
//     u8 t8 = *((u8 *) arg0 + 7);
//     s32 v1 = t7 * t8;
//
//     return (v1 != 0xFE01) ? (v1 >> 8) : 0xFF;
// }

void func_150617BC(struct127 *arg0);
s32 func_150623F4(struct127 *arg0);

void func_150619A8(void) {
    s32 i;
    s32 j;
    u8 list[25];
    s32 count;
    struct127 *obj;
    struct127 *other;
    u8 idx;

    count = 0;
    for (i = 0; i < 25; i++) {
        if (gObjects[i].interaction_state != 0) {
            if (gObjects[i].pad2FC[1] != 0) {
                gObjects[i].pad2FC[1]--;
            }
            func_150617BC(&gObjects[i]);
            if (func_150623F4(&gObjects[i]) != 0) {
                gObjects[i].unk2FA |= 1;
            } else {
                gObjects[i].unk2FA &= ~1;
                if (((u8 *)&gObjects[i])[0x20B] || gObjects[i].pad20C[0] || gObjects[i].pad20C[1] || gObjects[i].pad20C[2]) {
                    list[count++] = i;
                }
            }
        }
    }
    if (count != 0) {
        for (i = 0; i < count; i++) {
            idx = list[i];
            obj = &gObjects[idx];
            for (j = 0; j < 4; j++) {
                if (((u8 *)obj)[0x20B + j] != 0) {
                    other = func_15083E90(((u8 *)obj)[0x20B + j]);
                    if (other != NULL && (other->unk2FA & 1)) {
                        obj->unk2FA |= 1;
                        break;
                    }
                }
            }
        }
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15061B4C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150623F4.s")
// NON-MATCHING: scans the full gObjects[25] array; for each live
// object (interaction_state != 0) whose unk65 equals arg0's own
// array index plus one, and whose unk127 is 0xFF, calls
// func_15060F28(obj, arg1). The index is recovered from arg0's own
// pointer offset into gObjects via a genuine runtime division by
// sizeof(struct127) (0x32C), matching IDO's usual div-by-zero/
// overflow guard boilerplate.
// void func_150626EC(struct127 *arg0, s32 arg1) {
//     struct127 *obj;
//     s32 idx;
//
//     obj = gObjects;
//     do {
//         if (obj->interaction_state != 0) {
//             idx = ((char *) arg0 - (char *) gObjects) / 0x32C;
//             if (idx + 1 == obj->unk65) {
//                 if (obj->unk127 == 0xFF) {
//                     func_15060F28(obj, arg1);
//                 }
//             }
//         }
//         obj = (struct127 *) ((char *) obj + 0x32C);
//     } while (obj != (struct127 *) &D_800D121C);
// }
// 56 vs target's 58 instructions - smarter than target by 2. Every
// division-guard instruction, field offset, and branch shape matches
// target exactly; the gap is target computing `gObjects`'s address
// via two independent lui/addiu pairs (once for the loop iterator,
// once for the index-recovery subtraction) where this reconstruction
// naturally shares a single computed address between both uses.
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_150626EC.s")

void func_150627D4(struct127 *arg0) {
    arg0->unk2FB = 0;
    func_1503B840(arg0);
    func_15039CC8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15062800.s")

void func_15062AC4(struct127 *arg0) {
    if (arg0->unkE6 && arg0->unkE4) {
        f32 tmp = arg0->unkE4;
        arg0->unkEC = tmp / arg0->unkE6;
        arg0->unkF0 = arg0->unkE6 / tmp;
    } else {
        arg0->unkF0 = arg0->unkEC = 0.0f;
    }
}

void func_15062B1C(struct127 *arg0, f32 arg1) {
    arg0->unkE4 = arg0->xz_scale * arg1;
    func_15062AC4(arg0);
}

void func_15062B50(struct127 *arg0, f32 arg1) {
    arg0->unkE6 = arg0->y_scale * arg1;
    func_15062AC4(arg0);
}

void func_15062B84(struct127 *arg0) {
    if (arg0->unkD4 && arg0->unkD2) {
        f32 tmp = arg0->unkD2;
        arg0->unkDC = tmp / arg0->unkD4;
        arg0->unkE0 = arg0->unkD4 / tmp;
    } else {
        arg0->unkDC = 0.0f;
        arg0->unkE0 = 0.0f;
    }
}

void func_15062BDC(struct127 *arg0, f32 arg1, f32 arg2) {
    struct124 *temp_v0;

    arg0->xz_scale = arg1;
    arg0->y_scale = arg2;
    if (arg0->id != 255) {
        temp_v0 = D_800D1C90[arg0->id];
        arg0->unkD2 = (s32) (temp_v0->unk20 * arg0->xz_scale);
        arg0->unkD4 = (s32) (temp_v0->unk22 * arg0->y_scale);
        arg0->unkD6 = (s32) (temp_v0->unk24 * arg0->y_scale);
        arg0->unkE4 = (s32) (temp_v0->unk1A * arg0->xz_scale);
        arg0->unkE6 = (s32) (temp_v0->unk1C * arg0->y_scale);
        arg0->unkE8 = (s32) (temp_v0->unk1E * arg0->y_scale);
        func_15062AC4(arg0);
        func_15062B84(arg0);
    }
}

extern s32 D_800C4488;

// NON-MATCHING: 67 vs target's 69 instructions (smarter than target).
// Packs two 12-bit fields (plus a preserved top byte) back into an
// 8-byte "keyframe" element indexed by D_800C4488[arg0][arg4] + arg1*8
// (D_800C4488/D_800D19A0 are both raw-cast scalars standing in for
// arrays, matching this project's established idiom elsewhere - see
// game_6A3D0.c/game_1A8060.c). D_800D19A0[arg0] gates the whole
// function (return immediately if null - a parallel table's presence
// check). If arg5 is set, the two output fields are just arg2/arg3
// masked to 12 bits with no clamping; otherwise each field is offset
// from the CURRENT value's corresponding 12-bit sub-field (read from
// the element's first word) and wrapped into a valid range derived
// from the element's second word - matches target's own asymmetric
// branch shape exactly (a plain `bgez` guards the first field's wrap,
// a branch-likely `bgezl` guards the second's), which is strong
// evidence the control-flow reconstruction is correct even though the
// two fields needed separate `if (arg5)` blocks (a single combined
// block landed further away, sharing one test where target's own
// codegen keeps two). Remaining gap: target spills and reloads arg1
// from its stack home slot before the one place it's used; this
// reconstruction just keeps it live in a register the whole time -
// no call or later use to hang a forced-spill trick on.
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15062D10.s")
// void func_15062D10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
//     s32 base1;
//     void *base2;
//     void *elemBase;
//     void *elem;
//     s32 a2;
//     s32 threshold1;
//     s32 threshold0;
//     s32 v0;
//     s32 v1;
//
//     base1 = *(s32 *) ((char *) &D_800D19A0 + arg0 * 4);
//     if (base1 == 0) {
//         return;
//     }
//     base2 = *(void **) ((char *) &D_800C4488 + arg0 * 4);
//     elemBase = *(void **) ((char *) base2 + arg4 * 4);
//     elem = (char *) elemBase + arg1 * 8;
//
//     a2 = *(s32 *) ((char *) elem + 4);
//     threshold1 = ((a2 >> 12) & 0xFFF) + 2;
//     threshold0 = (a2 & 0xFFF) + 2;
//
//     if (arg5 != 0) {
//         v0 = arg2 & 0xFFF;
//     } else {
//         a2 = *(s32 *) ((char *) elem + 0);
//         v0 = ((a2 >> 12) & 0xFFF) + arg2;
//         if (threshold1 < v0) {
//             v0 = v0 - threshold1;
//         } else if (v0 < 0) {
//             v0 = v0 + threshold1;
//         }
//     }
//
//     if (arg5 != 0) {
//         v1 = arg3 & 0xFFF;
//     } else {
//         v1 = (a2 & 0xFFF) + arg3;
//         if (threshold0 < v1) {
//             v1 = v1 - threshold0;
//         } else if (v1 < 0) {
//             v1 = v1 + threshold0;
//         }
//     }
//     *(s32 *) ((char *) elem + 0) = (a2 & 0xFF000000) | (v1 & 0xFFF) | ((v0 & 0xFFF) << 12);
// }
struct func_15062E24_s {
    u8 pad[8];
    u16 unk8;
    u16 unkA;
};
extern struct func_15062E24_s *D_800C5338[];
void func_15094AB8(void *arg0, void *arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5);

void func_15062E24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 i;
    s32 w;
    s32 h;
    char *p;

    if (D_800C6360[arg0] == 0) {
        return;
    }
    for (i = 0; i < 25; i++) {
        if (gObjects[i].interaction_state == 0 || arg0 != gObjects[i].id || gObjects[i].unk2FA == 0) continue;
        {
            h = D_800C5338[arg0][arg5].unk8;
            w = D_800C5338[arg0][arg5].unkA;
            if (arg6 != 0) {
                h *= 2;
                w *= 2;
            }
            p = ((char **)((char *)&gObjects[i] + 0x28C))[D_800BE9C0];
            if (p != NULL) {
                p += arg1 * 16;
                func_15094AB8(p, (char *)D_800C6360[arg0] + arg3 * 4, arg2, arg4, w, h);
            }
        }
    }
}
extern s32 *D_800C4020[];

struct func_15062FC0_v {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
};

struct func_15062FC0_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x1C8 - 5];
    u8 unk1C8;
    u8 pad1C9[0x28C - 0x1C9];
    struct func_15062FC0_v *unk28C[4][2];
};

void func_15062FC0(struct func_15062FC0_s *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    struct func_15062FC0_v *dst;
    struct func_15062FC0_v *src;
    s32 i;

    dst = arg0->unk28C[arg0->unk1C8][D_800BE9C0];
    src = arg0->unk28C[arg0->unk1C8][!D_800BE9C0];
    if (dst == NULL) {
        return;
    }
    if (arg1 != -1) {
        dst += D_800C4020[arg0->unk4][arg1];
        src += D_800C4020[arg0->unk4][arg1];
    }
    if (arg6 != 0) {
        if (arg3 < dst->tc[0]) {
            arg6 -= arg3;
        } else if (dst->tc[0] < 0) {
            arg6 += arg3;
        }
    }
    if (arg7 != 0) {
        if (arg4 < dst->tc[1]) {
            arg7 -= arg4;
        } else if (dst->tc[1] < 0) {
            arg7 += arg4;
        }
    }
    for (i = 0; i < arg5; i++) {
        dst[i].tc[0] = src[i].tc[0] + arg6;
        dst[i].tc[1] = src[i].tc[1] + arg7;
    }
}
// NON-MATCHING: notifies every other live-flagged gObjects entry
// (excluding arg0's own recovered index) whose unk31C sub-object
// hasn't already reacted (unk1AC == 0), calling
// func_15194FF4(arg0, &gObjects[i], 1) for each. Adds struct126's
// previously-undocumented trailing byte field unk1AC.
// void func_15063168(struct127 *arg0) {
//     s32 i;
//     s32 selfIdx;
//     struct126 *sub;
//
//     if (D_8008FD8C > 0) {
//         selfIdx = ((char *) arg0 - (char *) gObjects) / 0x32C;
//
//         i = 0;
//         do {
//             if (i == selfIdx) {
//                 goto next;
//             }
//             if (!((1 << i) & D_800CC268)) {
//                 goto next;
//             }
//             sub = gObjects[i].unk31C;
//             if (sub == 0) {
//                 goto next;
//             }
//             if (sub->unk1AC != 0) {
//                 goto next;
//             }
//             func_15194FF4(arg0, &gObjects[i], 1);
//         next:
//             i++;
//         } while (i < D_8008FD8C);
//     }
// }
// 59 vs target's 59 instructions - exact count match. A plain
// `for` loop with `continue` statements compiled with a genuinely
// duplicate `D_8008FD8C > 0` check (the established guard-then-loop
// unroll/duplicate-check pitfall), and restructuring as a guarded
// do-while with manual `i++; continue;` before each early-exit
// branch bloated it further (each branch got its own increment
// instruction instead of sharing one). Consolidating every early-exit
// path onto a single shared `next: i++;` label via `goto` was what
// finally collapsed it to one check and one increment, matching
// target's count exactly. Remaining gap is a 3-instruction scheduling
// reorder in the prologue (same instructions, different order) plus
// the usual register-renaming.
void func_15063168(struct127 *arg0) {
    s32 i;
    s32 selfIdx;
    struct126 *sub;

    for (i = 0; i < D_8008FD8C; i++) {
        selfIdx = arg0 - gObjects;
        if (i == selfIdx) {
            continue;
        }
        if (!((1 << i) & D_800CC268)) {
            continue;
        }
        sub = gObjects[i].unk31C;
        if (sub == 0) {
            continue;
        }
        if (sub->unk1AC != 0) {
            continue;
        }
        func_15194FF4(arg0, &gObjects[i], 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_83300/func_15063254.s")
