#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_15075400(s32 arg0) {
    s32 tmp;
    u8 i;

    if (arg0 < 247) {
        gCurrentObject->unk218 += arg0;
        return;
    }

    for (i = 0; i < 100; i++) {
        if (gCurrentObject->unk218->unk0 < 247) {
            gCurrentObject->unk218++;
        } else {
            tmp = gCurrentObject->unk218->unk0 & 0xFF;
            ((u8*)gCurrentObject->unk218) += 1;
            if (arg0 == tmp) {
                gCurrentObject->unk218 -= 1;
                return;
            }
        }
    }
}

void func_15075498(void) {
    s32 tmp = D_800D1893 & 0x7F;

    if (tmp != 0x7F) {
        gCurrentObject->unk244 = tmp;
    }
    gCurrentObject->unkF4 &= ~0x143E;
    if (D_800D1890 == 0xFA) {
        gCurrentObject->unkF4 |= 0x22;
    } else if (D_800D1890 == 0xFB) {
        gCurrentObject->unkF4 |= 4;
    }
    if ((D_800D1893 & 0x80) != 0) {
        gCurrentObject->unkF4 |= 16;
    }
}

void func_15075548(void) {
    f32 temp_f6;
    u8 temp_a0;

    gCurrentObject->unk223 = 0;
    gCurrentObject->unk21C = D_800D1890 * 100;
    temp_a0 = D_800D1892;
    if (temp_a0 != 0xFF) {
        temp_f6 = temp_a0;
        gCurrentObject->unk44 = temp_f6;
        if (gCurrentObject->unk44 == 1.0f) {
            gCurrentObject->unk44 = 0.5f;
        }
        if (D_800BE616 != 0) {
            if ((gCurrentObject->id == 40) && ((gCurrentObject->unk31C->unk128 & 1) != 0)) {
                gCurrentObject->unk44 *= D_8009A13C;
            }
        }
    }
    func_15075498();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15075650.s")
// NON-MATCHING: 95% there
// void func_15075650(void) {
//     u8 phi_a0;
//     u8 phi_a2;
//
//     phi_a0 = D_800D2108[gCurrentObject->unk13F] - 1;
//     if (gCurrentObject->unk21F != 0) {
//         phi_a0 = gCurrentObject->unk21F;
//     }
//     phi_a0 = phi_a0 - gCurrentObject->unk220;
//     if (D_800D1891 == 0xFF) { // -1
//         if (gCurrentObject->unk223 != 0xD) {
//             gCurrentObject->unk21E = (random_u32() % (u32) phi_a0) + gCurrentObject->unk220;
//         }
//     } else if (D_800D1891 == 0xFE) { // -2
//         if (gCurrentObject->unk223 != 0xD) {
//             phi_a2 = gCurrentObject->unk21E - 1;
//             if (gCurrentObject->unk21E <= gCurrentObject->unk220) {
//                 phi_a2 = phi_a0 - 1;
//             }
//             phi_a0 = (random_u32() % (u32) phi_a0) + gCurrentObject->unk220;
//             if (phi_a0 != phi_a2) {
//                 gCurrentObject->unk21E = phi_a0;
//             }
//         }
//     } else {
//         if (D_800D1891 == 0xFF) { // impossible?
//             gCurrentObject->unk21E = phi_a0 - 1;
//         } else {
//             gCurrentObject->unk21E = D_800D1891;
//         }
//     }
//
//     gCurrentObject->unk223 = 0;
//     gCurrentObject->unk21C = D_800D1890 * 0x64;
//
//     if (D_800D1892 != 0xFF) {
//         gCurrentObject->unk44 = D_800D1892;
//         if (gCurrentObject->unk44 == 1.0f) {
//             gCurrentObject->unk44 = 0.5f;
//         }
//     }
//
//     if (gCurrentObject->unk21E < gCurrentObject->unk220) {
//         gCurrentObject->unk21E = gCurrentObject->unk220;
//     }
//     func_15075498();
// }

struct func_15075884_s {
    u8 pad0[8];
    struct {
        s16 x;
        s16 unk2;
        s16 z;
        s16 unk6;
    } e[1];
};

void func_15075884(void) {
    f32 dx, dz, d;

    func_15075548();
    dx = ((struct func_15075884_s **)D_800D2104)[gCurrentObject->unk13F]->e[gCurrentObject->unk21E].x - gCurrentObject->x_position;
    dz = ((struct func_15075884_s **)D_800D2104)[gCurrentObject->unk13F]->e[gCurrentObject->unk21E].z - gCurrentObject->z_position;
    d = sqrtf((dx * dx) + (dz * dz));
    dx = D_800D1891;
    gCurrentObject->unk44 = 2.0f * (d / dx);
}
// NON-MATCHING: array index is wrong
// void func_15075884(void) {
//     f32 temp_f0;
//     f32 temp_f12;
//     f32 temp_f2;
//     struct169 *temp_v1;
//     f32 phi_f2;
//
//     func_15075548();
//     temp_v1 = D_800D2104[(gCurrentObject->unk13F) + (gCurrentObject->unk21E)];
//     temp_f2 = temp_v1->unk8 - gCurrentObject->x_position;
//     temp_f12 = temp_v1->unkC - gCurrentObject->z_position;
//     temp_f0 = sqrtf((temp_f2 * temp_f2) + (temp_f12 * temp_f12));
//     gCurrentObject->unk44 = 2.0f * (temp_f0 / D_800D1891);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15075938.s")
// NON-MATCHING: 2nd half ok, 1st is a mystery
// void func_15075938(void) {
//     u8 tmp;
//     u8 changed;
//     s32 temp_a0;
//     s32 phi_v1;
//     u8 temp_v0;
//
//     changed = 0;
//
//     temp_a0 = gCurrentObject->unk21E - gCurrentObject->unk221;
//     if (temp_a0 < 0) {
//         temp_v0 = gCurrentObject->unk13F + D_800D2108;
//         temp_a0 = (temp_a0 + temp_v0) - 1;
//     } else {
//         temp_v0 = gCurrentObject->unk13F + D_800D2108;
//         if ((temp_v0 - 1) <= temp_a0) {
//             temp_a0 = (temp_a0 - temp_v0) + 1;
//         }
//     }
//
//     if (D_800D1891 == 0xFF) {
//         phi_v1 = temp_v0 - 2;
//     } else {
//         phi_v1 = D_800D1891;
//     }
//
//     if (D_800D1892 == 0) {
//         if (phi_v1 == temp_a0) {
//             changed = 1;
//         }
//     } else if (D_800D1892 == 1) {
//         if (phi_v1 != temp_a0) {
//             changed = 1;
//         }
//     } else if (D_800D1892 == 2) {
//         if (phi_v1 < temp_a0) {
//             changed = 1;
//         }
//     } else {
//         if (phi_v1 > temp_a0) {
//             changed = 1;
//         }
//     }
//
//     if (changed) {
//         func_15075400(D_800D1890);
//     }
// }

void func_15075A50(void) {
    u8 temp_v0 = gCurrentObject->unk21E;
    if (((D_800D1892 == 0) && (D_800D1891 == temp_v0)) ||
       ((D_800D1892 == 1) && (D_800D1891 != temp_v0))) {
        func_15075400(D_800D1890);
    }
}

// NON-MATCHING: the old draft's indexing was wrong (D_800D2104[a+b] as a
// single-level sum) - raw-asm tracing shows two separate levels: first
// D_800D2104[gCurrentObject->unk13F] (4-byte-stride, same pointer-array
// use as func_15079A98 elsewhere in this file), THEN D_800D1891 indexes
// 8 bytes into *that* pointer's target (a small unk0/unk4 s16 pair, not
// struct169 - which is 0x16 bytes, too big for this stride). Corrected
// indexing verified in isolation to produce every non-fabsf instruction
// identical to target. Blocked on: target's abs.s here has NO cvt.d.s/
// cvt.s.d around it, but calling fabsf() in this codebase ALWAYS
// produces that round-trip regardless of source form - confirmed by
// checking the ALREADY-MATCHED func_15144C8C's own compiled bytes
// (game_16EE20.c), which uses fabsf() and does have the exact same
// round-trip at its linked address, proving it's a real, unavoidable
// property of this compiler's K&R-unprototyped fabsf intrinsic (its own
// error text confirms: "a float argument is promoted to a double when
// passed... to an unprototyped function"), not a source-phrasing issue.
// Since target's func_15075AAC has no such round-trip, its true source
// must compute this absolute value some other way than fabsf() - not
// yet identified (a hand ternary compiles to branches, not abs.s).
// void func_15075AAC(void) {
//     char *v0;
//     f32 a, b;
//
//     func_15075548();
//     v0 = (char *) D_800D2104[gCurrentObject->unk13F] + D_800D1891 * 8;
//     a = *(s16 *) (v0 + 0) - gCurrentObject->x_position;
//     b = *(s16 *) (v0 + 4) - gCurrentObject->z_position;
//     if (fabsf(a) + fabsf(b) < 40.0f) {
//         gCurrentObject->unk21C = 0;
//         gCurrentObject->xz_velocity = 0.0f;
//     }
// }
void func_15075AAC(void) {
    char *v0;
    f32 a, b;

    func_15075548();
    v0 = (char *) D_800D2104[gCurrentObject->unk13F] + D_800D1891 * 8;
    a = *(s16 *) (v0 + 0) - gCurrentObject->x_position;
    b = *(s16 *) (v0 + 4) - gCurrentObject->z_position;
    if (fabsf(a) + fabsf(b) < 40.0f) {
        gCurrentObject->unk21C = 0;
        gCurrentObject->xz_velocity = 0.0f;
    }
}

void func_15075B60(void) {
    func_15075548();
    gCurrentObject->unk223 = 10;
}

void func_15075B8C(void) {
    func_15075650();
    gCurrentObject->unk223 = 10;
}

void func_15075BB8(void) {
    func_15075548();
    gCurrentObject->unk22C |= 2;
}

void func_15075BE8(void) {
    if (D_800D1893 != 0) {
        gCurrentObject->unk22C |= 0x80;
    }
    gCurrentObject->unk233 = D_800D1890;
}

void func_15075C24(void) {
    if (D_800D1893 != 1) {
        gCurrentObject->y_velocity = (s16)((D_800D1892 << 8) | D_800D1890);
    }
    if (D_800D1893 != 2) {
        gCurrentObject->gravity = (s16)(s8)D_800D1891;
    }
}

void func_15075CA0(void) {
    func_15075548();
    gCurrentObject->unk223 = 1;
}

void func_15075CCC(void) {
    func_15075548();
    gCurrentObject->unk223 = 16;
    gCurrentObject->unk231 = D_800D1891;
}

void func_15075D0C(void) {
    func_15075548();
    gCurrentObject->unk223 = 15;
}

void func_15075D38(void) {
    func_15075CA0();
    gCurrentObject->unk223 = 14;
}

void func_15075D64(void) {
    func_15075548();
    gCurrentObject->unk223 = 12;
    gCurrentObject->unk222 = 0;
}

void func_15075D9C(void) {
    func_15075548();
    gCurrentObject->unk223 = 9;
}

void func_15075DC8(void) {
    func_15075CA0();
}

void func_15075DE8(void) {
    if (D_800D1891 == 0) {
        D_800D1891 = gCurrentObject->unk232;
    }
    if (D_800D1893 != 0) {
        gCurrentObject->unk232 = D_800D1893;
    }
    gCurrentObject->unk218 = func_1507BB28(0, D_800D1891);
    gCurrentObject->unk218 -= 1;
}

void func_15075E6C(void) {
    func_15075548();
    gCurrentObject->unk223 = 2;
}

void func_15075E98(void) {
    gCurrentObject->unk235 = D_800D1890;
}

void func_15075EB4(void) {
    if ((random_u32() % 0x64U) < D_800D1892) {
        func_15075400(D_800D1890);
    }
}

void func_15075F00(void) {
    gCurrentObject->unk234 = D_800D1890;
    gCurrentObject->unk236 = D_800D1891;
    gCurrentObject->unk237 = D_800D1892;
}

void func_15075F40(void) {
    func_15075548();
    gCurrentObject->unk223 = 3;
}

void func_15075F6C(void) {
    if (D_800D1890 != 0) {
        if (D_800D1892 == 0) {
            gCurrentObject->y_velocity = D_800D1890;
        } else {
            gCurrentObject->y_velocity = -D_800D1890;
        }
    }
    if (D_800D1891 != 0) {
        gCurrentObject->gravity = D_800D1891;
    }
    gCurrentObject->unk3A = D_800D1893;
}

struct func_1507602C_s {
    u8 pad0[8];
    struct {
        s16 x;
        s16 unk2;
        s16 z;
        s16 unk6;
    } e[1];
};

void func_1507602C(void) {
    f32 dx, dz, t;

    func_15075548();
    gCurrentObject->unk21E = D_800D1891;
    dx = ((struct func_1507602C_s **)D_800D2104)[gCurrentObject->unk13F]->e[D_800D1891].x - gCurrentObject->x_position;
    dz = ((struct func_1507602C_s **)D_800D2104)[gCurrentObject->unk13F]->e[D_800D1891].z - gCurrentObject->z_position;
    t = 2.0f * (sqrtf((dx * dx) + (dz * dz)) / gCurrentObject->unk44);
    if (t < 12.0f) {
        gCurrentObject->unk44 *= t * D_8009A140;
        t = 12.0f;
    }
    gCurrentObject->unk21C = t * 100.0f;
    gCurrentObject->y_velocity = gCurrentObject->gravity * t * 0.5f;
    gCurrentObject->unk223 = 4;
}
// NON-MATCHING: indexing is wrong
// void func_1507602C(void) {
//     f32 temp_f12;
//     f32 temp_f14;
//     f32 temp_f2;
//     struct169 *temp_v1;
//
//     func_15075548();
//     gCurrentObject->unk21E = D_800D1891;
//     temp_v1 = D_800D2104[gCurrentObject->unk13F + D_800D1891]; // wrong
//     temp_f2 = temp_v1->unk8 - gCurrentObject->x_position;
//     temp_f12 = temp_v1->unkC - gCurrentObject->z_position;
//     temp_f14 = 2.0f * (sqrtf((temp_f2 * temp_f2) + (temp_f12 * temp_f12)) / gCurrentObject->unk44);
//     if (temp_f14 < 12.0f) {
//         gCurrentObject->unk44 *= temp_f14 * D_8009A140;
//         temp_f14 = 12.0f;
//     }
//     gCurrentObject->unk21C = temp_f14 * 100.0f;
//     gCurrentObject->y_velocity = gCurrentObject->gravity * temp_f14 * 0.5f;
//     gCurrentObject->unk223 = 4;
// }

void func_150761C8(void) {
    func_15075650();
    gCurrentObject->unk223 = 5;
}

void func_150761F4(void) {

    gCurrentObject->unk223 = 6;
    gCurrentObject->unk22C &= 0xFFFE;
}

void func_15076220(void) {
    func_150761F4();
    gCurrentObject->unk22C |= 1;
}

void func_15076250(void) {
    s32 tmp = (D_800D1890 << 8) | D_800D1891;
    func_15060778(tmp, gCurrentObject, 0x7D00, -0x64, 0x1F4, 0x9C4, D_800D1892);
}

void func_150762B0(void) {
    func_1000CBA8(D_800D1890);
}

void func_151669A0(s32 arg0, s32 arg1, s32 arg2, f32 arg3, u8 arg4, s32 arg5);

void func_150762D4(void) {
    func_151669A0((s32) gCurrentObject->x_position, (s32) (gCurrentObject->y_position + 100.0f),
                  (s32) gCurrentObject->z_position, 0.45f, 0xFF, 0);
}

void func_15076340(void) {
    if (gCurrentObject->unk107 == 0) {
        func_15075400(D_800D1890);
    }
    if (D_800D1891 != 0) {
        gCurrentObject->unk107 = 0;
    }
}

void func_15076394(void) {
    gCurrentObject->unk236 = D_800D1890;
}

void func_150763B0(void) {

    if (D_800D1890 == 128) {
        gCurrentObject->unk1E5 = gCurrentObject->unk144->unkF;
    } else {
        gCurrentObject->unk1E5 = D_800D1890;
    }
    gCurrentObject->unk1E7 = 0;

    if (D_800D1892 != 0) {
        gCurrentObject->unk1E5 += (random_u32() % (u32) D_800D1892);
    }
    if (D_800D1893 == 1) {
        gCurrentObject->unk1E6 = 0;
        gCurrentObject->unk1E8 = 0;
        return;
    }
    if (D_800D1893 == 2) {
        gCurrentObject->unk1E6 = D_800D1891;
        gCurrentObject->unk1E8 = 0;
        return;
    }
    if (D_800D1891 == 0) {
        gCurrentObject->unk1E6 = gCurrentObject->unk1E5;
        gCurrentObject->unk1E8 = 0;
    }
}

void func_150764C8(void) {
    gCurrentObject->unk238 = D_800D1890;
}

void func_150764E4(void) {
    gCurrentObject->unk239 = D_800D1890;
}

void func_15076500(void) {
    gCurrentObject->unk22E = (D_800D1890 << 8) | D_800D1891;
}

void func_1507652C(void) {
    if (D_800D1891 != 0) {
        D_800CC3F5[gCurrentObject->unk124 * 0x32C] = D_800D1890;
    } else {
        gCurrentObject->immune = D_800D1890;
    }
}

void func_1507659C(void) {
    gCurrentObject->y_position = gCurrentObject->y_position + D_800D1890 * 100;
    if (D_800D1893 != 0) {
        gCurrentObject->y_position = 1800.0f;
    }
}

void func_15076600(void) {
}

void func_15076608(void) {
    gCurrentObject->unk24A = D_800D1890;
}

void func_15076624(void) {
    s32 tmp = (D_800D1890 << 0x18) | (D_800D1891 << 0x10) | (D_800D1892 << 8) | D_800D1893;
    gCurrentObject->unkF8 |= tmp;
}

s32 func_15076678(void) {
    s32 tmp = (D_800D1890 << 0x18) | (D_800D1891 << 0x10) | (D_800D1892 << 8) | D_800D1893;
    gCurrentObject->unkF8 &= ~tmp;
}

void func_150766D0(void) {
    if (((gCurrentObject->unk28 > 0.0f) && (D_800D1890 == 0)) ||
        (((D_800D1890 * 0x32) < gCurrentObject->unk28) && (D_800D1890 != 0))) {
        gCurrentObject->unk21C = 99;
        gCurrentObject->unk218 -= 1;
    }
}

void func_15076760(void) {
}

// ???
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Dispatches on
// D_800D1890: case 0 calls func_15197A7C(gCurrentObject); case 1
// builds a struct199 (unk24/28/2C = gCurrentObject's x/-390.0f/z,
// matching the already-confirmed func_15074C00's struct199 usage
// pattern), calls func_1504715C on it, then func_1514B364. A switch
// (not if/else-if) was needed to get the beqz/beq branch shape right,
// and the position fields must be written *before* the
// func_1504715C call in source (not after) to match target's actual
// read-then-build order. One gap left: target hoists the
// `lui a1,%hi(gCurrentObject)` for case 1's reload into the
// case-1-selecting beq's delay slot (empty/nop in every source form
// tried here), making this reconstruction exactly one instruction (4
// bytes) longer than target.
void func_15076768(void) {
    f32 pos[3];

    switch (D_800D1890) {
        case 0:
            func_15197A7C(gCurrentObject);
            break;
        case 1:
            pos[0] = gCurrentObject->x_position;
            pos[1] = -390.0f;
            pos[2] = gCurrentObject->z_position;
            {
                u8 tmp[0x24];
                func_1504715C(tmp, gCurrentObject);
                func_1514B364(pos, tmp, 0xFF, 0);
            }
            break;
    }
}
// void func_15076768(void) {
//     struct199 tmp;
//
//     switch (D_800D1890) {
//         case 0:
//             func_15197A7C(gCurrentObject);
//             break;
//         case 1:
//             tmp.unk24 = gCurrentObject->x_position;
//             tmp.unk28 = -390.0f;
//             tmp.unk2C = gCurrentObject->z_position;
//             func_1504715C(&tmp);
//             func_1514B364(&tmp.unk24, &tmp, 0xFF, 0);
//             break;
//     }
// }


struct func_150767F4_s {
    u16 unk0;
    u8 pad2[0x32A];
};

void func_150767F4(void) {
    struct127 *tmp = &gObjects[gCurrentObject->unk222];
    u16 tmp0 = func_1505A630(tmp->x_position - gCurrentObject->x_position, gCurrentObject->z_position - tmp->z_position, 0) >> 8;
    if (((tmp0 - (((struct func_150767F4_s *)D_800CC34A)[gCurrentObject->unk222].unk0 >> 8)) + D_800D1891 & 0xFF) < (D_800D1891 * 2)) {
        func_15075400(D_800D1890);
    }
}
// NON-MATCHING: JUSTREG
// void func_150767F4(void) {
//     struct127 *tmp = &gObjects[gCurrentObject->unk222]; // * 0x32C) ;
//
//     s32 tmp0 = func_1505A630(tmp->x_position - gCurrentObject->x_position, gCurrentObject->z_position - tmp->z_position, 0) >> 8;
//
//     if ((tmp0 + ((D_800CC34A[gCurrentObject->unk222 * 0x196] >> 8) - D_800D1891) & 0xFF) < (D_800D1891 * 2)) {
//         func_15075400(D_800D1890);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_150768DC.s")
// NON-MATCHING: almost JUSTREG
// void func_150768DC(void) {
//     u8 temp_s2;
//     f32 temp_f20;
//     s32 temp_fp;
//     struct127 *temp_v0;
//     struct127 *current;
//     f32 phi_f22;
//     s32 i;
//     u8 tmp0;
//     struct124 *foo;
//     u8 tmp1;
//
//
//     phi_f22 = D_800D1890 * 8;
//     gCurrentObject->unkA8 = 0;
//     temp_fp = ((s32)gCurrentObject - (s32)gObjects) / (s32)sizeof(struct127);
//
//     for (i = 0; i < 25; i++) {
//         current = &gObjects[i];
//         if ((current->unk0 != 0) && (current->health != 0) && ((current->unkF8 & 0x20) != 0) && (i != temp_fp)) {
//             if ((D_800D1891 != 0) || (gCurrentObject->id != current->id)) {
//                 if (!(fabsf(gCurrentObject->y_position - current->y_position) > 50.0f)) {
//                     temp_f20 = func_1505A72C(gCurrentObject, current);
//                     if (temp_f20 < phi_f22) {
//                         foo = D_800D1C90[gCurrentObject->id];
//                         temp_s2 = foo->unk17;
//                         tmp1 = func_1505A630(current->x_position - gCurrentObject->x_position, gCurrentObject->z_position - current->z_position, 0) >> 8;
//                         if ((((((gCurrentObject->unk76 >> 8) + gCurrentObject->unk2CA) - tmp1) + (temp_s2 / 2)) & 0xFF) < temp_s2) {
//                             gCurrentObject->unkA8 = i;
//                             phi_f22 = temp_f20;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//
//     if (gCurrentObject->unkA8 != 0) {
//         gCurrentObject->unk218 = func_1507BB28(0, D_800D1893);
//         gCurrentObject->unk218 -= 1;
//         tmp0 = D_800D1892;
//         if (tmp0 != 0) {
//             temp_v0 = &gObjects[gCurrentObject->unkA8 & 0x7F];
//             temp_v0->unk218 = 0;
//             temp_v0->unk232 = tmp0;
//             temp_v0->unk222 = temp_fp;
//         }
//     }
// }

void func_15076B5C(void) {
    gCurrentObject->unk222 = (gCurrentObject->unkA8 & 0x7F);
}

void func_15076B78(void) {
    gCurrentObject->unk5 = D_800D1890;
}

void func_15076B94(void) {
    s32 idx = ((s32)gCurrentObject - (s32)gObjects) / (s32)sizeof(struct127);

    if (D_800D1891) {
        idx = 25;
    }
    while (idx != 0) {
        if ((D_800D1890 == gObjects[idx-1].id) && (gObjects[idx-1].health != 0)) {
            func_15075548();
            gCurrentObject->unk223 = 9;
            gCurrentObject->unk222 = idx - 1;
            gCurrentObject->unk21C = 1000;
            return;
        }
        idx--;
    };
}

void func_15076C7C(void) {
    func_1506160C(gCurrentObject, 1, D_800D1890, 0, 0);
}

void func_15076CB4(void) {
    gCurrentObject->unk76 = gCurrentObject->unk78;
}

void func_15076CCC(void) {
    gCurrentObject->unk21C = 10000;
    func_15060F28(gCurrentObject, 1);
}

void func_15076D04(void) {
    gCurrentObject->xz_velocity = D_800D1890;
}

// NON-MATCHING: register-choice gap only, tied to a single persistent
// scheduling difference - 46 of 46 instructions match target in count,
// opcode, and operand structure, but target loads D_8009A144 into $f0
// as literally its 3rd/4th instructions (interleaved into the middle
// of computing &gCurrentObject: lui v0 / lui at+lwc1 f0 / addiu v0),
// while every source variant tried here (declaring the scale read
// first, last, mid-sequence, via an initializer, or through an
// explicit &gCurrentObject indirection) gets it scheduled right before
// its first use instead, shifting several $t-register assignments
// throughout without changing the instruction count. Also fixed two
// real bugs in the old draft: the call's first argument is
// gCurrentObject itself (the pointer value), not &gCurrentObject (the
// old draft's guess), and func_15062BDC's 2nd/3rd float args pass as
// raw bits through $a1/$a2 (per o32: only args 1-2 use $f12/$f14, and
// arg0 here is a pointer) matching its existing real prototype.
// void func_15076D3C(void) {
//     f32 scale = D_8009A144;
//     s32 tmp1;
//     s32 tmp2;
//
//     tmp1 = D_800D1890 | (D_800D1891 << 8);
//     tmp2 = D_800D1892 | (D_800D1893 << 8);
//     gCurrentObject->xz_scale = (s16) tmp1 * scale;
//     gCurrentObject->y_scale = (s16) tmp2 * scale;
//     gCurrentObject->unk154 = gCurrentObject->xz_scale;
//     gCurrentObject->unk158 = gCurrentObject->y_scale;
//     func_15062BDC(gCurrentObject, gCurrentObject->xz_scale, gCurrentObject->y_scale);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15076D3C.s")

void func_15076DF4(void) {
    gCurrentObject->interaction_state = D_800D1890;
}

void func_15076E10(void) {
    gCurrentObject->unk1D0 = D_800D1890;
    gCurrentObject->unk22C |= D_800D1891;
}

void func_15076E48(void) {
}

void func_15076E50(void) {
    func_15075548();
    gCurrentObject->y_velocity = ((f32) (u32) (random_u32() % 0x14U) + 55.0f);
    gCurrentObject->gravity = 2.0f;
    gCurrentObject->unk78 = random_u32() % 0xFFFFU;
    gCurrentObject->xz_velocity = (u32) ((random_u32() % 0x14U) + 0xF);
    gCurrentObject->unk44 = gCurrentObject->xz_velocity;
    gCurrentObject->unk223 = 7;
}

void func_15076F40(void) {
    gCurrentObject->unk21C = 1000;
    func_15060F28(gCurrentObject, 1);
}

void func_15076F78(void) {
    s8 tmp;
    tmp = D_800D1890;
    gCurrentObject->unkCC = tmp;
    tmp = D_800D1891;
    gCurrentObject->unkCE = tmp;
}

void func_15076FA8(void) {
    if (D_800D1893 == 0) {
        s16 tmp;
        tmp = (random_u32() % (u32) D_800D1890) - (D_800D1890 / 2);
        gCurrentObject->x_position += tmp * 3.0f;
        tmp = (random_u32() % (u32) D_800D1891) - (D_800D1891 / 2);
        gCurrentObject->z_position += tmp * 3.0f;
    } else {
        if (gCurrentObject->xz_velocity < D_800D1893) {
            gCurrentObject->xz_velocity = D_800D1893;
        }
    }
}

void func_150770E4(void) {
    if (((f32 (*)[203])D_800CC30C)[gCurrentObject->unk222][0] < D_800D1892) {
        func_15075400(D_800D1893);
    }
}
// NON-MATCHING: JUSTREG (?)
// void func_150770E4(void) {
//     // this can't be right?
//     if (D_800CC30C[gCurrentObject->unk222 * 203] < D_800D1892) {
//         func_15075400(D_800D1893);
//     }
// }

void func_15077174(void) {
    gCurrentObject->unk10E = D_800D1890;
}

void func_15077190(void) {
    s32 tmp0 = (D_800D1890 << 8) | D_800D1891;
    if (tmp0 != 0) {
        s32 tmp1 = D_800D1892 << 7;
        func_10010630(tmp0, gCurrentObject, tmp1, 0x1F4, 0x9C4);
    }
}

void func_150771F0(void) {
    s32 a2;
    s32 a3;

    if (D_800D1893 == 0) {
        a2 = D_800D1890;
        a3 = D_800D1891;
        func_1506160C(gCurrentObject, (D_800D1892 != 0) ? 1 : 2, a2, a3, 0);
    } else {
        if (D_800D1892 == 0) {
            func_1502EA60(gCurrentObject, D_800D1890);
        } else {
            func_1502EA7C(gCurrentObject, D_800D1890);
        }
    }
}
// NON-MATCHING: something isnt right...
// void func_150771F0(void) {
//     s32 phi_a1;
//
//     if (D_800D1893 == 0) {
//         phi_a1 = (D_800D1892 != 0) ? 1 : 2;
//         func_1506160C(gCurrentObject, phi_a1, D_800D1890, D_800D1891, 0);
//     } else {
//         if (D_800D1892 == 0) {
//             func_1502EA60(gCurrentObject, D_800D1890);
//         } else {
//             func_1502EA7C(gCurrentObject, D_800D1890);
//         }
//     }
// }

void func_15077294(void) {
    switch (D_800D1891) {
        case 0:
            gCurrentObject->health = D_800D1890;
            break;
        case 1:
            gCurrentObject->health--;
            break;
    }
}

void func_150772E8(void) {
    func_1503DE70(gCurrentObject, D_800D1890, -1);
}

void func_15077318(void) {
    if (D_800D1890 != 0) {
        gCurrentObject->unk101 |= 1;
    } else {
        gCurrentObject->unk101 &= 0xFFFE;
    }
}

void func_1507735C(void) {

}

void func_15077364(void) {
    if (D_800D1893 != 0) {
        D_800D1890 += random_u32() % (u32) D_800D1893;
    }
    gCurrentObject->unk246 = (u8) D_800D1890;
    gCurrentObject->unk249 = (u8) 0;
    gCurrentObject->unk247 = (u8) D_800D1891;
    gCurrentObject->unk248 = (u8) D_800D1892;
}

// NON-MATCHING: register-choice gap only, same class as func_15076D3C
// above - 44 of 44 instructions match target in count, opcode, and
// operand structure (including the guard-clause branch polarity, the
// multu selection for the s16*s32 product, and the bgezl clamp-to-zero
// shape), but target reloads gCurrentObject and reads its unk246 field
// very early (right after recomputing &gCurrentObject, interleaved
// with reading D_800D1891/D_800D1892), while every source variant
// tried here (one big expression, a separate early statement, a named
// "v1 = gCurrentObject" local reused for both field accesses) gets
// that reload+read scheduled right before its actual use in the final
// sum instead - IDO appears to defer this specific 3-instruction
// pointer-chain (recompute address, lw, lbu) as a latency-hiding
// choice regardless of where it appears in source, cascading into
// different $t-register numbers without changing the instruction
// count.
// void func_15077404(void) {
//     s32 masked;
//     s32 a0;
//     s16 t7;
//     s32 v0;
//     s32 t2;
//
//     if (D_800D1893 != 0) {
//         masked = (gCurrentObject->unk246 & 0x1F) << 8;
//         a0 = (D_800D1891 << 8) + D_800D1892;
//         t7 = (s16) a0;
//         v0 = masked + gCurrentObject->unk249 + (t7 * D_800BE9E4);
//         v0 = (s16) v0;
//         if (v0 < 0) {
//             v0 = 0;
//         }
//         t2 = v0 >> 8;
//         gCurrentObject->unk246 = t2 | 0x80;
//         gCurrentObject->unk249 = (u8) v0;
//     } else {
//         gCurrentObject->unk246 = D_800D1890;
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15077404.s")

void func_150774B4(void) {
    if ((gCurrentObject->unk20F == gCurrentObject->unk211) || (gCurrentObject->unk211 == 0xFF)) {
        gCurrentObject->unk25C |= 0x800;
        func_15075400(D_800D1890);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15077508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_150778F0.s")
// NON-MATCHING: close but not there yet
// void func_150778F0(void) {
//     u8 temp_t9;
//
//     temp_t9 = (u8)(D_800D2108 + gCurrentObject->unk13F) - 1;
//     if (gCurrentObject->unk21F != 0) {
//         temp_t9 = gCurrentObject->unk21F;
//     }
//     gCurrentObject->unk21E += gCurrentObject->unk221;
//     gCurrentObject->unk21E += temp_t9;
//     gCurrentObject->unk21E %= temp_t9;
//     if (gCurrentObject->unk21E < gCurrentObject->unk220) {
//         gCurrentObject->unk21E = gCurrentObject->unk220;
//     }
// }

void func_150779A8(void) {
    func_15075650();
    gCurrentObject->unk223 = 0xB;
}

void func_150779D4(void) {
    struct127 *tmp;
    u8 idx = 0;
    f32 d;

    if (D_800D1892 != 0) {
        idx = gCurrentObject->unk222;
    }
    tmp = &gObjects[idx];
    if ((gCurrentObjectIndex != idx) && ((tmp->interaction_state != 1) || (tmp->unk65 == 0))) {
        if (func_1505A6F8(gCurrentObject, tmp) < (d = D_800D1893 * 8)) {
             func_15075400(D_800D1890);
        }
    }
}
// NON-MATCHING: JUSTREG! using $f6 not $f2
// void func_150779D4(void) {
//     struct127 *tmp;
//     u8 idx = 0;
//
//     if (D_800D1892 != 0) {
//         idx = gCurrentObject->unk222;
//     }
//     tmp = &gObjects[idx];
//     if ((gCurrentObjectIndex != idx) && ((tmp->unk0 != 1) || (tmp->unk65 == 0))) {
//         if (func_1505A6F8(gCurrentObject, tmp) < (D_800D1893 * 8)) {
//              func_15075400(D_800D1890);
//         }
//     }
// }

void func_15077AA0(void) {
    gCurrentObject->unk239 = D_800D1890;
}

void func_15077ABC(void) {
    gCurrentObject->unk258 = D_800D1890;
    gCurrentObject->unk257 = D_800D1891;
    gCurrentObject->unk86 = random_u32() % 0xFFU;
}

void func_15077B14(void) {
    gCurrentObject->unk24C = D_800D1890;
    gCurrentObject->unk24D = D_800D1891;
}

void func_15077B44(void) {
    func_15060A30((D_800D1890 << 8) + D_800D1891, gCurrentObject);
}

void func_15077B80(void) {
    s32 tmp = (D_800D1890 << 8) + D_800D1891;
    gCurrentObject->unk25C |= tmp;
}

void func_15077BB4(void) {
    struct127 *tmp = func_1505F0AC(D_800D1891);
    tmp->unk218 = 0;
    tmp->unk232 = D_800D1890;
}

void func_15077BE4(void) {
    s32 tmp = ~((D_800D1890 << 8) + D_800D1891);
    gCurrentObject->unk25C &= tmp;
}

void func_15077C1C(void) {
    gCurrentObject->unk23D = D_800D1890;
}

void func_15077C38(void) {
    struct127 *phi_s0;
    f32 tmp0;
    f32 distance;
    s32 i;

    tmp0 = D_8009A148;
    gCurrentObject->unk222 = (u8)0;

    for (i = 0; i < 25; i++) {
        phi_s0 = &gObjects[i];
        if (((phi_s0->interaction_state != 0) && (phi_s0->health != 0)) &&
            ((phi_s0->immune == 0) || (phi_s0->immune == 0xFF)) &&
            ((phi_s0->unk65 == 0) || (D_800D1892 != 0)) &&
            ((phi_s0->id == D_800D1890) || ((phi_s0->interaction_state == D_800D1891) &&
            (phi_s0->stunned == 0)))) {
            if (D_800D1893 == 0) {
                gCurrentObject->unk222 = i;
                return;
            }
            distance = func_1505A72C(gCurrentObject, phi_s0);
            if (tmp0 > distance) {
                gCurrentObject->unk222 = i;
                tmp0 = distance;
            }
        }
    }
}

void func_15077DA0(void) {
    gCurrentObject->unk21E = D_800D1890;
}

struct func_15077DBC_s {
    u8 pad0[8];
    struct {
        s16 x;
        s16 y;
        s16 z;
        s16 w;
    } pts[1];
};

void func_15077DBC(void) {
    if (D_800D1890 != 0xFA) {
        gCurrentObject->unk21E = D_800D1890;
    }
    gCurrentObject->x_position = ((struct func_15077DBC_s **)D_800D2104)[gCurrentObject->unk13F]->pts[gCurrentObject->unk21E].x;
    gCurrentObject->y_position = ((struct func_15077DBC_s **)D_800D2104)[gCurrentObject->unk13F]->pts[gCurrentObject->unk21E].y;
    gCurrentObject->z_position = ((struct func_15077DBC_s **)D_800D2104)[gCurrentObject->unk13F]->pts[gCurrentObject->unk21E].z;
}
// ???
// void func_15077DBC(void) {
//     if (D_800D1890 != 0xFA) {
//         gCurrentObject->unk21E = D_800D1890;
//     }
//     gCurrentObject->x_position = D_800D2104[(gCurrentObject->unk13F) + (gCurrentObject->unk21E)]->unk8;
//     gCurrentObject->y_position = D_800D2104[(gCurrentObject->unk13F) + (gCurrentObject->unk21E)]->unkA;
//     gCurrentObject->z_position = D_800D2104[(gCurrentObject->unk13F) + (gCurrentObject->unk21E)]->unkC;
// }

void func_15077E9C(void) {
    s32 tmp = ((D_800D1890 << 8) + D_800D1891);
    func_10012718(tmp, gCurrentObject, 0x5DC0, 0x1F4, 0x9C4);
}

void func_15077EEC(void) {
    gCurrentObject->unk254 = D_800D1890;
}

void func_15077F08(void) {
    gCurrentObject->unk1EA = (D_800D1890 << 8) | D_800D1891;
}

void func_15077F34(void) {
    gCurrentObject->unk24F = D_800D1890;
    gCurrentObject->unk250 = D_800D1891;
}

void func_15056A00(s32, u8, u8);
void func_15077F64(void) {
    s32 pad2[2];
    u8 pad;
    u8 temp_t6;
    s16 *temp_v0;
    f32 dx;
    f32 dz;
    u8 a;

    temp_t6 = D_800D1890 - 1;
    temp_v0 = (s16 *)((u8 *)D_800D2104[gCurrentObject->unk13F] + (gCurrentObject->unk21E * 8));
    dx = temp_v0[4] - gCurrentObject->x_position;
    dz = gCurrentObject->z_position - temp_v0[6];
    gCurrentObject->unk78 = func_1505A630(dx, dz, 0);
    a = (gCurrentObject->unk78 - gCurrentObject->unk76) >> 8;
    if (a & 0x80) {
        a = -a;
    }
    if (((u8 *)D_80099A3C)[temp_t6 * 10] < a) {
        gCurrentObject->unk250 = D_800D1891;
        func_15056A00(gCurrentObject, a, temp_t6);
    }
}
// NON-MATCHING: what is D_800D2104 ???
// void func_15056A00(s32, s32, u8);
// void func_15077F64(void) {
//     u8 temp_t6;
//     struct169 *temp_v0;
//     s32 phi_a0;
//     s32 phi_a1;
//
//     temp_t6 = D_800D1890 - 1;
//     temp_v0 = D_800D2104[gCurrentObject->unk13F] + (gCurrentObject->unk21E);
//     gCurrentObject->unk78 = func_1505A630(temp_v0->unk8 - gCurrentObject->x_position, gCurrentObject->z_position - temp_v0->unkC, 0);
//     phi_a0 = phi_a1 = ((s32) (gCurrentObject->unk78 - gCurrentObject->unk76) >> 8) & 0xff;
//     if ((phi_a0 & 0x80) != 0) {
//         phi_a1 = phi_a0 = -phi_a0 & 0xFF;
//     }
//     if ((u8)D_80099A3C[temp_t6 * 0xA] < phi_a0) {
//         gCurrentObject->unk250 = (u8) D_800D1891;
//         func_15056A00(gCurrentObject, phi_a1, temp_t6);
//     }
// }

void func_15078074(void) {
    f32 temp_f20;
    struct127 *tmp;
    s32 i;

    temp_f20 = 8 * D_800D1893;

    for (i = 0; i < 25; i++) {
        tmp = &gObjects[i];
        if ((tmp->interaction_state != 0) && (gCurrentObjectIndex != i)) {
            if (func_1505A6F8(gCurrentObject, tmp) < temp_f20) {
                func_15075400(D_800D1890);
                return;
            }
        }
    }
}

void func_1507813C(void) {
    s32 idx = gCurrentObject->unk222;
    if (gObjects[idx].interaction_state == 0) {
        func_15075400(D_800D1890);
    }
}

void func_150781A4(void) {
    gCurrentObject->unk23F = D_800D1891;
    gCurrentObject->unk240 = D_800D1892;
    gCurrentObject->unk241 = D_800D1890;
    gCurrentObject->unk242 = D_800D1893;
}

// another function with D_800D2104
struct func_150781F4_s {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
};

void func_150781F4(void) {
    struct func_150781F4_s *pos;
    f32 dx, dz, dist;
    s32 idx;
    s32 flag;

    idx = D_800D1891 + 1;
    pos = &((struct func_150781F4_s **)D_800D2104)[gCurrentObject->unk13F][idx];
    dx = pos->x - gCurrentObject->x_position;
    dz = pos->z - gCurrentObject->z_position;
    dist = sqrtf(dx * dx + dz * dz);
    dx = D_800D1893 * 8;
    flag = D_800D1892;
    if (((flag == 0) && (dist < dx)) || ((flag != 0) && (dx < dist))) {
        func_15075400(D_800D1890);
    }
}

void func_150782CC(void) {
    gCurrentObject->unk23E = D_800D1890;
}

void func_150782E8(void) {
    if (((D_800D1892 == 0) && (gCurrentObject->unique_id == D_800D1891)) ||
        ((D_800D1892 == 1) && (gCurrentObject->unique_id != D_800D1891))) {
        func_15075400(D_800D1890);
    }
}

void func_15078358(void) {
    s32 tmp = func_15083FB0(D_800D1890);
    gCurrentObject->unk222 = tmp;
    if (tmp == -1) {
        gCurrentObject->unk222 = 0;
    }
}

void func_1507839C(void) {
    f32 phi_f0;
    f32 phi_f2;

    if (D_800D1892 == 0) {
        phi_f0 = func_1505A6F8(gCurrentObject, &gObjects[gCurrentObject->unk222]);
    } else if (D_800D1892 == 1) {
        phi_f0 = func_1505A72C(gCurrentObject, &gObjects[gCurrentObject->unk222]);
    } else {
        phi_f0 = fabsf(gCurrentObject->y_position - *(f32 *)((u8 *)D_800CC2E8 + gCurrentObject->unk222 * sizeof(struct127)));
    }

    phi_f2 = D_800D1893 * 8;
    if (D_800D1893 == 0xFF) {
        phi_f2 = gCurrentObject->unk23D * 8;
    }
    if (((D_800D1891 == 0) && (phi_f0 < phi_f2)) ||
        ((D_800D1891 == 1) && (phi_f2 < phi_f0))) {
        func_15075400(D_800D1890);
    }
}
// NON-MATCHING: JUSTREG
// void func_1507839C(void) {
//     struct127 *tmp;
//     f32 phi_f0;
//     f32 phi_f2;
//
//     if (D_800D1892 == 0) {
//         tmp = &gObjects[gCurrentObject->unk222];
//         phi_f0 = func_1505A6F8(gCurrentObject, tmp);
//     } else if (D_800D1892 == 1) {
//         tmp = &gObjects[gCurrentObject->unk222];
//         phi_f0 = func_1505A72C(gCurrentObject, tmp);
//     } else {
//         phi_f0 = fabsf(gCurrentObject->y_position - gObjects[gCurrentObject->unk222].y_position);
//     }
//
//     phi_f2 = D_800D1893 * 8;
//     if (D_800D1893 == 0xFF) {
//         phi_f2 = gCurrentObject->unk23D * 8;
//     }
//     if (((D_800D1891 == 0) && (phi_f0 > phi_f2)) ||
//         ((D_800D1891 == 1) && (phi_f0 > phi_f2))) {
//         func_15075400(D_800D1890);
//     }
// }

void func_15078520(void) {
    func_15075400(D_800D1890);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15078544.s")
struct func_1507879C_s {
    s32 unk0;
    s32 unk4;
    f32 unk8;
};

void func_1507879C(void) {
    struct func_1507879C_s *ptr = (struct func_1507879C_s *)D_800CC5A0[gCurrentObject->unk222].interaction_state;
    f32 temp_f0 = ptr->unk8;

    if (((D_800D1892 == 0) && (temp_f0 < (u32)D_800D1891)) ||
        ((D_800D1892 == 1) && (temp_f0 > (u32)D_800D1891))) {
        func_15075400(D_800D1890);
    }
}
// NON-MATCHING: D_800CC5A0 ???
// void func_1507879C(void) {
//     f32 temp_f0 =  D_800CC5A0[gCurrentObject->unk222].unk8;
//
//     if (((D_800D1892 == 0) && (temp_f0 < D_800D1891)) ||
//         ((D_800D1892 == 1) && (temp_f0 > D_800D1891))) {
//         func_15075400(D_800D1890);
//     }
// }

void func_15078874(void) {
    gCurrentObject->unk251 = D_800D1890;
}

void func_15078890(void) {
    if (((D_800D1892 == 0) && (gCurrentObject->unk251 == D_800D1891)) ||
        ((D_800D1892 == 1) && (gCurrentObject->unk251 != D_800D1891))) {
        func_15075400(D_800D1890);
    }
}

void func_15078900(void) {
    if (D_800D1893 != 0) {
        if (gCurrentObject->unk222 == 0) {
            func_15075400(D_800D1890);
        }
    } else {
        if (((D_800D1892 == 0) && (D_800D1891 == D_800CC521[gCurrentObject->unk222 * 0x32C])) ||
            ((D_800D1892 == 1) && (D_800D1891 != D_800CC521[gCurrentObject->unk222 * 0x32C]))) {
            func_15075400(D_800D1890);
        }
    }
}

void func_15078A08(void) {
    struct197 *temp_a0;
    struct197 *temp_v0;

    temp_v0 = gCurrentObject->unk2D0;
    temp_a0 = D_800CC5A0[gCurrentObject->unk222].interaction_state; // wtf
    temp_v0->unk8 = (f32) temp_a0->unk8;
    temp_v0->unkC = (f32) temp_a0->unkC;
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15078A60.s")

void func_1507900C(void) {
    if (func_15078A60(0) != 0) {
        func_15075400(D_800D1890);
    }
}

void func_1507903C(void) {
    if (func_15078A60(0) != 0) {
        gCurrentObject->unk218 = func_1507BB28(0, D_800D1890);
        gCurrentObject->unk218 -= 1;
    }
}

void func_15079090(void) {
    if (func_15078A60(gCurrentObjectIndex) != 0) {
        func_15075400(D_800D1890);
    }
}

void func_150790C4(void) {
    if (func_15078A60(gCurrentObjectIndex) != 0) {
        gCurrentObject->unk218 = func_1507BB28(0, D_800D1890);
        gCurrentObject->unk218 -= 1;
    }
}

u8 func_1507911C(void) {
    s16 temp_a2;
    s16 phi_a0;
    u8 idx;

    temp_a2 = (D_800D1891 << 8) | D_800D1892;
    idx =  D_800D1893 & 1;
    if (idx != 0) {
        idx = gCurrentObjectIndex;
    }
    phi_a0 = gObjects[idx].y_position;
    if ((D_800D1893 & 2) != 0) {
        phi_a0 = gObjects[idx].x_position;
    }
    if (phi_a0 < temp_a2) {
        func_15075400(D_800D1890);
    }
}

void func_150791F0(void) {
    if ((s32) gCurrentObject->unk2C9 < (s32) D_800D1890) {
        gCurrentObject->unk1C9 = (u8)0xFFU;
    } else {
        gCurrentObject->unk1C9 = D_800D1890;
    }
}

void func_15079228(void) {
    s16 *entry;
    f32 x;
    f32 z;
    u16 v0;
    s32 a2;

    // D_800D3098 is read here as a pointer to the 52-byte entries.
    entry = (s16 *) (*(char **) &D_800D3098 + gCurrentObject->unk251 * 52);
    x = entry[0];
    z = entry[2];
    v0 = func_1505A630(gCurrentObject->x_position - x, z - gCurrentObject->z_position, 0);
    a2 = v0 & 0xFFFF;
    if (v0 == 0) {
        a2 = 1;
    }
    func_1505D024(gCurrentObject, D_800D1890, a2, -1);
    gCurrentObject->unk218 -= 1;
    gCurrentObject->unk21C = 1;
}

void func_150792E0(void) {
    gCurrentObject->unk232 = D_800D1890;
}

void func_150792FC(void) {
    gCurrentObject->unk2F8 &= 0xFFF8;
    gCurrentObject->unk2F8 |= D_800D1890;
}

void func_15079334(void) {
    struct127 *tmp;

    if (gCurrentObject->unkA8 != 0) {
        tmp = &gObjects[gCurrentObject->unkA8 & 0x7F];
        tmp->unk218 = 0;
        tmp->unk232 = D_800D1890;
    }
}

void func_15079390(void) {
    u16 tmp0 = D_800D1890;
    u8 tmp1 = D_800D1891;
    u8 tmp2 = D_800D1892;

    func_1514D3B0(gCurrentObject, tmp0, tmp1, tmp2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_150793D8.s")

void func_15079570(void) {
    f32 temp_f2;

    temp_f2 = func_1505A6F8(gCurrentObject, &gObjects[gCurrentObject->unk222]);
    gCurrentObject->unk44 = gCurrentObject->xz_velocity;
    temp_f2 = 2.0f * (temp_f2 / gCurrentObject->unk44);
    gCurrentObject->y_velocity = gCurrentObject->gravity * temp_f2 * 0.5f;
    gCurrentObject->y_velocity += ((*(f32 *)((u8 *)D_800CC2E8 + gCurrentObject->unk222 * sizeof(struct127)) - gCurrentObject->y_position) / temp_f2) * 2.0f;
}
// NON-MATCHING: JUSTREG - t1 not t0
// void func_15079570(void) {
//     f32 temp_f2;
//
//     temp_f2 = func_1505A6F8(gCurrentObject, &gObjects[ gCurrentObject->unk222]);
//     gCurrentObject->unk44 = gCurrentObject->xz_velocity;
//     temp_f2 = 2.0f * (temp_f2 / gCurrentObject->unk44);
//     gCurrentObject->y_velocity = gCurrentObject->gravity * temp_f2 * 0.5f;
//     gCurrentObject->y_velocity += ((D_800CC2E8[gCurrentObject->unk222 * 203] - gCurrentObject->y_position) / temp_f2) * 2.0f;
// }

void func_1507965C(void) {
    s32 idx;
    struct127 *temp_v1;

    idx = func_15083FB0(D_800D1890);
    if (idx != -1) {
        temp_v1 = &gObjects[idx];
        temp_v1->unk232 = D_800D1891;
        temp_v1->unk218 = 0;
        temp_v1->unk23A = 0;
    }
}

void func_150796CC(void) {
    s32 idx = func_15083FB0(D_800D1890);
    if (D_800D1892 != 0) {
        if (idx != -1) {
            D_800CC3F5[idx * sizeof(struct127)] = D_800D1891;
        }
    } else if ((idx != -1) && (D_800CC3D4[idx * sizeof(struct127)] != 0)) {
        func_15075400(D_800D1891);
    }
}

void func_15079790(void) {
    s16 sp1E;
    s16 temp_t0;

    if (D_800D1892 != 0) {
        gCurrentObject->id = 0xFF;
    } else {
        gCurrentObject->id = 0x3A;
        sp1E = (func_150ADA20() % 500U) - 250;
        temp_t0 = (func_150ADA20() % 500U) - 250;
        gCurrentObject->x_position = ((s16 **)D_800D2104)[gCurrentObject->unk13F][0] + sp1E;
        gCurrentObject->z_position = ((s16 **)D_800D2104)[gCurrentObject->unk13F][2] + temp_t0;
    }
}
// seriously, D_800D2104?
// void func_15079790(void) {
//     s16 temp_t1;
//     s16 temp_t0;
//
//     if (D_800D1892 != 0) {
//         gCurrentObject->id = 0xFF;
//     } else {
//         gCurrentObject->id = 0x3A;
//         temp_t1 = (random_u32() % 0x1F4U) - 0xFA;
//         temp_t0 = (random_u32() % 0x1F4U) - 0xFA;
//         gCurrentObject->x_position = (s32)&D_800D2104[gCurrentObject->unk13F] + temp_t1;
//         gCurrentObject->z_position = (s32)&D_800D2104[gCurrentObject->unk13F + 1] + temp_t0;
//     }
// }

void func_15079880(void) {
    s32 tmp = D_800CC30C[0] + (s8)D_800D1892;

    if (tmp < D_800D1891) {
        tmp = D_800D1891;
    } else if (tmp >= 251) {
        tmp = 250;
    }
    D_800D1892 = tmp;
    func_15075548();
}

void func_150798F8(void) {
    D_800D1891 = gCurrentObject->unk21E;
    func_150781F4();
}

void func_15079928(void) {
    s32 phi_a3;

    phi_a3 = ((D_800D1891 << 0x10) + D_800D1892) & 0xFFFF;
    if (phi_a3 == 0) {
        phi_a3 = 0xFFFF;
    }
    func_1507E7E4(gCurrentObject, D_800D1890, D_800D1893, phi_a3, 0);
}

void func_15079988(void) {
    func_1507EB4C(gCurrentObject, D_800D1890);
}

void func_150799B4(void) {
    s32 temp_a0 = (D_800D1890 << 8) + D_800D1891;
    if (D_800D1892 != 0) {
        temp_a0 += random_u32() % (u32) D_800D1892;
    }
    func_15060A30(temp_a0, gCurrentObject);
}

void func_15079A28(void) {
    gCurrentObject->unk252 = D_800D1890;
    gCurrentObject->unk253 = D_800D1891;
}

void func_15079A58(void) {
    D_800D2110[gCurrentObject->unk13F] = (D_800D1890 << 8) + D_800D1891;
}

u16 func_15079A98(s32 arg0) {
    struct169 *v0 = (struct169 *) D_800D2104[gCurrentObject->unk13F];

    return func_1505A630((f32) v0->unk0 - gObjects[arg0].x_position,
                          gObjects[arg0].z_position - (f32) v0->unk4, 0);
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15079B30.s")

void func_15079F24(void) {
    gCurrentObject->unk48 = D_800D1898[D_800D1890];
}

void func_15079F50(void) {
    gCurrentObject->unk23B = D_800D1890;
}

// NON-MATCHING: JUSTREG. Every instruction matches target's content and
// order exactly, but the register allocation differs throughout (target
// uses $a0 for &gCurrentObject and a distinct $v0/$v1 pair per byte
// load's address-calc vs. loaded-value; this reconstruction gets $v0
// for the address and reuses one register per byte load for both the
// address calc and the value). Tried both a direct field-access form
// and an explicit struct127** alias for &gCurrentObject - both produced
// the identical (wrong) allocation.
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_15079F6C.s")
// void func_15079F6C(void) {
//     gCurrentObject->unk224 = (D_800D1890 << 8) | D_800D1891;
//     gCurrentObject->unk22B = D_800D1892;
//     gCurrentObject->unk226 = D_800D1893;
// }

void func_15079FBC(void) {
    s16 phi_v1;

    if ((gObjects->unk65 == 0) || (gObjects->unk44 < 5.0f)) {
        gCurrentObject->unk232 = D_800D1891;
        gCurrentObject->unk218 = (struct216 *)func_1507BB28(0, gCurrentObject->unk232);
        gCurrentObject->unk218 -= 1;
        return;
    }

    gCurrentObject->unk78 = gObjects->unk31C->unk4C;

    if (gObjects->unk31C->chased) {
        phi_v1 = gObjects->unk44;
    } else {
        phi_v1 = gObjects->unk44 * D_8009A1E4;
    }
    if (phi_v1 < 17) {
        D_800D1893 += 1;
        D_800D1890 = 8;
    }
    D_800D1892 = phi_v1;
    func_15075F40();
    gCurrentObject->unkF4 |= 0x40;
}
// NON-MATCHING: JUSTREG
// void func_15079FBC(void) {
//     s16 phi_v1;
//
//     if ((gObjects->unk65 == 0) || (gObjects->unk44 < 5.0f)) {
//         gCurrentObject->unk232 = D_800D1891;
//         gCurrentObject->unk218 = func_1507BB28(0, gCurrentObject->unk232, gCurrentObject);
//         gCurrentObject->unk218 -= 1;
//         return;
//     }
//
//     gCurrentObject->unk78 = gObjects->unk31C->unk4C;
//
//     if (gObjects->unk31C->unk4A) {
//         phi_v1 = gObjects->unk44;
//     } else {
//         phi_v1 = gObjects->unk44 * D_8009A1E4;
//     }
//     if (phi_v1 < 17) {
//         D_800D1893 += 1;
//         D_800D1890 = 8;
//     }
//     D_800D1892 = phi_v1;
//     func_15075F40();
//     gCurrentObject->unkF4 |= 0x40;
// }

// D_800D2104!
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Writes a packed
// (D_800D1892, D_800D1893) halfword into a nested lookup: base =
// D_800D2104[gCurrentObject->unk13F], offset by D_800D1890*8 +
// D_800D1891*2 + 8. Register allocation differs substantially from
// target throughout.
struct func_1507A100_s {
    u8 pad[8];
    s16 unk8[1][4];
};

void func_1507A100(void) {
    s32 val = ((s8)D_800D1892 << 8) | D_800D1893;
    ((struct func_1507A100_s *)D_800D2104[gCurrentObject->unk13F])->unk8[D_800D1890][D_800D1891] = val;
}
// void func_1507A100(void) {
//     void *base = (void *) D_800D2104[gCurrentObject->unk13F];
//     s16 packed = ((s8) D_800D1892 << 8) | D_800D1893;
//
//     *(s16 *) ((char *) base + D_800D1890 * 8 + D_800D1891 * 2 + 8) = packed;
// }

s32 func_1507A164(void) {
    s32 tmp = D_800CC30C[0] + (s8)D_800D1892;

    if (tmp < D_800D1891) {
        tmp = D_800D1891;
    } else if (tmp > D_800D1890) {
        tmp = D_800D1890;
    }
    gCurrentObject->unk44 = tmp;
    if (gCurrentObject->unk44 == 1.0f) {
        gCurrentObject->unk44 = 0.5f;
    }
}

void func_1507A210(void) {
    gCurrentObject->unk223 = 0;
    gCurrentObject->unk21C = D_800D1890 * 0x64;
    gCurrentObject->unk22C &= 0xFD;
    func_15075498();
}

void func_1507A270(void) {
    func_1503DE70(gCurrentObject, D_800D1890, (s8)D_800D1891);
}

void func_1507A2A4(void) {
    D_800D1893 = (random_u32() % (u32) D_800D1891) + D_800D1893;
    func_15075CA0();
}

void func_1507A2F8(void) {
    s32 i;
    u32 used;
    u8 sp1C[25];

    used = 0;
    for (i = 0; i < 25; i++) {
        if ((gObjects[i].interaction_state != 0) && (gObjects[i].id == D_800D1890)) {
            sp1C[used] = i;
            used++;
        }
    }
    if (used != 0) {
        i = random_u32();
        gCurrentObject->unkA8 = gCurrentObject->unk222;
        gCurrentObject->unk222 = sp1C[i % used];
    }
}

void func_1507A3B4(void) {
    gCurrentObject->unk222 = gCurrentObject->unkA8;
}

void func_1507A3CC(void) {
    gCurrentObject->unk229 = D_800D1890;
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Same packed-4-byte
// value as func_1507A428/func_1507A47C/func_1507A4D4 above, here just
// returned rather than stored anywhere. Same content and instruction
// count as target (16/16) but IDO schedules the four lui/lbu pairs and
// the three shifts/ors differently: target interleaves each byte's load
// with the running shift/or chain progressively, this reconstruction's
// source order gets batched into "all four loads, then all shifts" -
// 13/16 words differ despite identical semantics.
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_1507A3E8.s")
// s32 func_1507A3E8(void) {
//     return (D_800D1890 << 0x18) | (D_800D1891 << 0x10) | (D_800D1892 << 8) | D_800D1893;
// }

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Packs four global
// bytes into a 32-bit value, sets bit 0, inverts, and stores it to
// gCurrentObject->unk94. Register allocation for the four byte loads and
// shifts differs from target throughout.
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_1507A428.s")
// void func_1507A428(void) {
//     gCurrentObject->unk94 = ~(((D_800D1890 << 24) | (D_800D1891 << 16) | (D_800D1892 << 8) | D_800D1893) | 1);
// }
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Sibling of
// func_1507A428 above - ANDs gCurrentObject->unk94 with the inverse of
// the same packed 4 bytes, instead of assigning it. Same register-
// allocation mismatch as func_1507A428.
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_1507A47C.s")
// void func_1507A47C(void) {
//     gCurrentObject->unk94 &= ~((D_800D1890 << 24) | (D_800D1891 << 16) | (D_800D1892 << 8) | D_800D1893);
// }
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Third sibling of
// func_1507A428/func_1507A47C above - ORs gCurrentObject->unk94 with the
// same packed 4 bytes instead of assigning/ANDing. Same register-
// allocation mismatch as its siblings: target loads gCurrentObject
// itself only after the first two byte loads (interleaved differently
// throughout), while this reconstruction loads it first (19/21 words
// differ despite matching size).
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_1507A4D4.s")
// void func_1507A4D4(void) {
//     gCurrentObject->unk94 |= (D_800D1890 << 0x18) | (D_800D1891 << 0x10) | (D_800D1892 << 8) | D_800D1893;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_1507A528.s")
// NON-MATCHING: 99% there..
// void func_1507A528(void) {
//     s32 phi_a0;
//     s32 temp_a1;
//
//     if (D_800D1890 == 0) {
//         gCurrentObject->unk221 = D_800D1891;
//     } else if (D_800D1890 == 1) {
//         gCurrentObject->unk221 = -gCurrentObject->unk221;
//     } else if (D_800D1890 == 2) {
//         if (D_800D1892 != 0) {
//             phi_a0 = D_800D1892;
//         } else {
//             phi_a0 = (u8)(D_800D2108 + gCurrentObject->unk13F) - 1;
//         }
//         gCurrentObject->unk221 = -gCurrentObject->unk221;
//         temp_a1 = gCurrentObject->unk21E + gCurrentObject->unk221;
//         if (gCurrentObject->unk221 > 0) {
//             temp_a1 += D_800D1893;
//         } else {
//             temp_a1 -= D_800D1893;
//         }
//         if (temp_a1 >= phi_a0) {
//             temp_a1 = temp_a1 - phi_a0;
//         } else {
//             if (temp_a1 < 0) {
//                 temp_a1 = temp_a1 + phi_a0;
//             }
//         }
//         gCurrentObject->unk21E = temp_a1;
//     }
// }

void func_1507A620(void) {
    u8 idx;
    u16 tmp;

    idx = gCurrentObject->unk222;
    if (D_800D1891 != 0) {
        tmp = gCurrentObject->unk78 >> 8;
    } else {
        tmp = (gCurrentObject->unk7A - func_1505A630(gObjects[idx].x_position - gCurrentObject->x_position, gCurrentObject->z_position - gObjects[idx].z_position, 0)) >> 8;
    }
    if ((u8)(tmp - D_800D1892) < (u8)(D_800D1893 - D_800D1892)) {
        func_15075400(D_800D1890);
    }
}

s32 func_1507A6FC(s32 arg0) {
    // really??
    u32 tmp0 = (3 * arg0) & 0xFFFFFFFFFFFFFFFF;
    u32 tmp1 = tmp0 & 0xFFFFFFFFFFFFFFFF;
    return D_800BE748[tmp1 & 0xFFFFFFFFFFFFFFFF];
}

void func_1507A71C(void) {
    u16 tmp0 = func_1507A6FC(D_800D1890);
    u16 tmp1 = ((D_800D1891 << 8) | D_800D1892);

    if ((tmp0 & tmp1) == tmp1) {
        func_15075400(D_800D1893);
    }
}

void func_1507A774(void) {
    u16 temp_v0 = (D_800D1891 << 8) | D_800D1892;
    if (D_800BE9F0 == temp_v0) {
        func_15075400(D_800D1890);
    }
}

void func_1507A7C0(void) {
    gCurrentObject->disable_run = (u8) D_800D1890;
}

void func_1507A7DC(void) {
    func_150836CC(gCurrentObject, D_800D1890);
}

void func_1507A808(void) {
    gCurrentObject->unk22C = (gCurrentObject->unk22C & D_800D1890) | D_800D1891;
}

void func_1507A838(void) {
    if (gCurrentObject->health == D_800D1891) {
        func_15075400(D_800D1890);
    }
}

void func_1507A878(void) {
    func_1512D748(0, D_800D1890, D_800D1891);
}

void func_1507A8A8(void) {
    if ((D_800CC335 != 0) || (D_800BE616 != 0)) {
        func_15075400(D_800D1890);
    }
}

void func_1507A8EC(void) {
    if (D_800D1891 == D_800CC2D4[gCurrentObject->unk222 * sizeof(struct127)]) {
        D_800D1892 ^= 1;
    }
    if (D_800D1892 != 0) {
        func_15075400(D_800D1890);
    }
}

void func_1507A984(void) {
    s32 temp_v0;

    if (D_800D1890 != 0) {
        temp_v0 = func_15083E90(D_800D1890);
        if (temp_v0 != 0) {
            if (D_800D1892 == 0) {
                gCurrentObject->unk101 |= 4;
            }
            if (D_800D1893 != 0) {
                gCurrentObject->unk101 |= 0x40;
            }
            gCurrentObject->unk65 = ((s32) (temp_v0 - (s32)&gObjects) / 0x32C) + 1;
            gCurrentObject->unk5C = D_800D1891;
        }
    } else {
        gCurrentObject->unk65 = 0;
    }
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_A28B0/func_1507AA48.s")

void func_1507ACB0(void) {
    gCurrentObject->unk220 = D_800D1890;
    gCurrentObject->unk21F = D_800D1891;
}

void func_1507ACE0(void) {
    gCurrentObject->unk1E5 = D_800D1890;
    gCurrentObject->unk1E6 = D_800D1890;
    gCurrentObject->unk1E7 = D_800D1891;
    gCurrentObject->unk1E8 = D_800D1891;
}

void func_1507AD30(void) {
    gCurrentObject->unk255 = D_800D1890;
    gCurrentObject->unk256 = D_800D1891;
}

void func_1507AD60(void) {
    gCurrentObject->unk1E4 = D_800D1890;
}

void func_1507AD7C(void) {
    gCurrentObject->unkF4 |= func_1507A3E8();
}

void func_1507ADAC(void) {
    gCurrentObject->unkF4 &= ~func_1507A3E8();
}

void func_1507ADE0(void) {
    s32 res;
    s32 temp_lo;
    s32 b = gCurrentObject->unk7A;
    s32 a = gCurrentObject->unk78;

    res = a - b;
    if (res < 0) {
        res = -res;
    }
    if (res >= 32769) {
        res = res + 0xFFFF0000;
    }
    if (res < 0) {
        res = -res;
    }
    temp_lo = res / (s32)D_800D1890;
    gCurrentObject->unk1E6 = temp_lo >> 8;
    gCurrentObject->unk1E8 = temp_lo & 0xFF;
}

void func_1507AE78(void) {
    gCurrentObject->unk229 = D_800D1890;
}

void func_1507AE94(void) {
    gCurrentObject->unkD2 = (D_800D1890 << 8) | D_800D1891;
    gCurrentObject->unkD4 = (D_800D1892 << 8) | D_800D1893;
    gCurrentObject->unkD2 *= gCurrentObject->xz_scale;
    gCurrentObject->unkD4 *= gCurrentObject->y_scale;
}

void func_1507AF3C(void) {
    gCurrentObject->unkD6 = (D_800D1890 << 8) | D_800D1891;
    gCurrentObject->unkD6 *= gCurrentObject->y_scale;
}

void func_1507AF98(void) {
    gCurrentObject->unkD8 = (D_800D1890 << 8) | D_800D1891;
    gCurrentObject->unkDA = (D_800D1892 << 8) | D_800D1893;
    gCurrentObject->unkD8 *= gCurrentObject->xz_scale;
    gCurrentObject->unkDA *= gCurrentObject->xz_scale;
}

void func_1507B040(void) {
    gCurrentObject->unk76 = gCurrentObject->unk7A;
}

void func_1507B058(void) {
    struct127 *sp24 = gCurrentObject;
    s32 sp20 = gCurrentObjectIndex;

    gCurrentObject = func_15072208(gCurrentObject, 0);
    gCurrentObjectIndex = ((s32)gCurrentObject - (s32)&gObjects) / 0x32C;

    if (gCurrentObject != 0) {
        switch (D_800D1890) {
            case 0:
                func_1506160C(gCurrentObject, 1, D_800D1891, 0, 0);
                break;
            case 1:
                gCurrentObject->unk232 = D_800D1891;
            case 2:
                gCurrentObject->unk218 = func_1507BB28(0, D_800D1891);
                gCurrentObject->unk21C = 0;
        }
    }
    gCurrentObjectIndex = sp20;
    gCurrentObject = sp24;
}

void func_1507B15C(void) {
    gCurrentObject->disable_jump = D_800D1890;
}

void func_1507B178(void) {
    s16 tmp  = (D_800D1891 << 8) | D_800D1890;
    if (D_800D1893 == 2) {
        gCurrentObject->unkE8 = (s16) (tmp * gCurrentObject->y_scale);
    } else if (D_800D1893 == 1) {
        func_15062B50(gCurrentObject, tmp);
    } else {
        func_15062B1C(gCurrentObject, tmp);
    }
}

void func_1507B234(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(300, 1800);
    }
}

void func_1507B280(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(300, 3000);
    }
}

void func_1507B2CC(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(300, 1800);
    }
}

void func_1507B318(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(300, 0xBB8);
    }
}

void func_1507B364(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(0x2BC, 0xFA0);
    }
}

void func_1507B3B0(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(0x2BC, 0xFA0);
    }
}

void func_1507B3FC(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(0xBB8, 0x1F40);
    }
}

void func_1507B448(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(0xBE, 0x514);
    }
}

void func_1507B494(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(0xBE, 0x514);
    }
}

void func_1507B4E0(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(100, 800);
    }
}

void func_1507B52C(void) {
    D_800D1580 = func_1507A3E8();
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(100, 800);
    }
}

void func_1507B578(void) {
    gCurrentObject->unkD0 = D_800D1890;
    gCurrentObject->unk114 = D_800D1891;
}

void func_1507B5C4(void) {
    if (gCurrentObject->unk31C->unk75 == D_800D1891) {
        D_800D1892 ^= 1;
    }
    if (D_800D1892 != 0) {
        func_15075400(D_800D1890);
    }
}

void func_1507B630(void) {
    if ((gCurrentObject->disable_run == 0) && (gCurrentObject->unk28 == 0.0f)) {
        if (gCurrentObject->unk31C->unk78 != 0) {
            D_800D1890 ^= 1;
        }
        if (D_800D1890 != 0) {
            gCurrentObject->unk31C->unk8C |= 0x4000;
            gCurrentObject->unk31C->unk8F = 0;
        }
    } else {
        gCurrentObject->unk218 -= 1;
    }
    gCurrentObject->unk21C = 100;
}

void func_1507B6E0(void) {
    if ((gCurrentObject->disable_run != 0) || (gCurrentObject->unk28 > 5.0f)) {
        gCurrentObject->unk218 -= 1;
        gCurrentObject->unk21C = 0x64;
    }
}

void func_1507B734(void) {
    u16 tmp = ((D_800D1890 << 8) | D_800D1891);
    if (D_800D1893 != 0) {
        gCurrentObject->unk31C->unk8C = tmp;
        gCurrentObject->unk31C->unk8F = D_800D1892;
    } else {
        gCurrentObject->unk31C->unk8A = tmp;
        gCurrentObject->unk31C->unk8E = D_800D1892;
    }
}

void func_1507B7BC(void) {
    func_15075548();
    gCurrentObject->unk223 = 17;
}

void func_1507B7E8(void) {
    struct127 *tmp = &gObjects[gCurrentObject->unk222];
    if ((tmp->stunned != 0) || (tmp->health == 0)) {
        D_800D1891 ^= 1;
    }
    if (D_800D1891 != 0) {
        func_15075400(D_800D1890);
    }
}

u8 func_1507B884(void) {
    s32 tmp0;
    s32 tmp1;
    u8 temp_v0;
    void (*func)(s32);

    temp_v0 = D_800D1890;
    func = D_80086150[temp_v0];
    if (func != 0) {
        tmp0 = gCurrentObject;
        tmp1 = gCurrentObjectIndex;
        func(temp_v0);
        gCurrentObject = tmp0;
        gCurrentObjectIndex = tmp1;
    }
}

void func_1507B8F4(void) {

    if (D_800BE616 != 0) {
        if ((D_800D1891 != 0) || ((gCurrentObject->unk31C != 0) && (gCurrentObject->unk31C->unk84 != 0))) {
            func_15075400(D_800D1890);
        }
    }
}

void func_1507B958(void) {
    gCurrentObject->unkB0 = D_800D1890;
}

struct func_1507B974_s {
    u8 pad0[6];
    u16 unk6;
};

void func_1507B974(void) {
    struct127 *phi_v1;

    phi_v1 = gCurrentObject;
    if (gCurrentObject->unk65 != 0) {
        phi_v1 = &gObjects[gCurrentObject->unk65 - 1];
    }
    if (D_800D1891 == ((struct func_1507B974_s **)D_800D2104)[phi_v1->unk13F][phi_v1->unk21E + D_800D1893].unk6) {
        D_800D1892 ^= 1;
    }
    if (D_800D1892 != 0) {
        func_15075400(D_800D1890);
    }
}
// NON-MATCHING: dont think D_800D2104 is correct
// void func_1507B974(void) {
//     struct127 *phi_v1;
//     struct169 *foo;
//
//     phi_v1 = gCurrentObject;
//     if (gCurrentObject->unk65 != 0) {
//         phi_v1 = &gObjects[gCurrentObject->unk65 - 1];
//     }
//     foo = &D_800D2104[phi_v1->unk13F + phi_v1->unk21E + D_800D1893];
//     if (D_800D1891 == foo->unk0) {
//         D_800D1892 ^= 1;
//     }
//     if (D_800D1892 != 0) {
//         func_15075400(D_800D1890);
//     }
// }

void func_1507BA48(void) {
    u16 tmp = ((D_800D1892 << 8) | D_800D1893);
    if (D_800D1890 != 0) {
        tmp += random_u32() % (u32) D_800D1890;
    }
    func_15060A9C(tmp, gCurrentObject);
}

void func_1507BAD0(void) {
    gCurrentObject->unkFC = func_1507A3E8();
}

void func_1507BAF8(void) {
    gCurrentObject->unk2CC = func_1507A3E8();
}

void func_1507BB20(void) {
}

// scary loops
struct func_1507BB28_s {
    struct216 *unk0;
    u8 unk4;
    u8 pad5[3];
};
extern struct216 D_8009A120;
extern struct func_1507BB28_s D_80086A88[];

int func_1507BB28(int arg0, int arg1) {
    struct func_1507BB28_s *arr;
    struct func_1507BB28_s *fb;
    s32 tmp;
    s32 i;

    tmp = D_800D1588[gCurrentObject->id];
    if (tmp == 0) {
        return (int)&D_8009A120;
    }
    arr = ((struct func_1507BB28_s **)tmp)[-4];
    if (arr == NULL) {
        return (int)&D_8009A120;
    }
    for (i = 0; arr[i].unk4 != arg1; i++) {
        if (arr[i].unk0 == NULL) {
            i = 0;
            fb = D_80086A88;
            for (; fb[i].unk4 != arg1; i++) {
                if (fb[i].unk0 == NULL) {
                    while (1);
                }
            }
            return (int)fb[i].unk0;
        }
    }
    return (int)arr[i].unk0;
}

void func_1507BC14(struct127 *arg0) {

    if (arg0->unk21C != 0) {
        if (arg0->unk218 != 0) {
            if (arg0->unk21C != 25500) {
                arg0->unk21C = arg0->unk21C - D_800CC264;
            }
            if ((arg0->unk21C >= 50000) || (arg0->unk21C == 0)) {
                arg0->unk21C = 0;
                if ((arg0->unkF4 & 0x400) != 0) {
                    arg0->unk21C = 20000;
                    arg0->unkF4 &= ~0x400;
                    arg0->unkF4 |= 4;
                }
            } else {
                return;
            }
        }
    }

    if (arg0->unk218 == 0) {
        arg0->unk218 = func_1507BB28(0, arg0->unk232);
        arg0->unk21C = 0;
    }

    while (arg0->unk21C == 0) {
        if (arg0->unk218->unk0 >= 0xF7) {
            arg0->unk218 = (u8 *)(arg0->unk218) + 1;
        } else {
            D_800D1890 = arg0->unk218->unk1;
            D_800D1891 = arg0->unk218->unk2;
            D_800D1892 = arg0->unk218->unk3;
            D_800D1893 = arg0->unk218->unk4;
            D_80086730[arg0->unk218->unk0]();
            arg0->unk218 = (u8 *)(arg0->unk218) + 5;
        }
    }
}
