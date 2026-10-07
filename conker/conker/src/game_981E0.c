#include <ultra64.h>

#include "functions.h"
#include "variables.h"

f32 random_float();                                /* extern */

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506AD30.s")

void func_1506AF74(void) {
    if ((gCurrentObject->unk100 & 8) != 0) {
        gCurrentObject->unk100 |= 4;
    }
    gCurrentObject->unk100 &= 0xF7;
    func_1505E650(gCurrentObject, 0x38, 1.0f, 5.0f, 0.0f, 0.0f, 0);
}

void func_1506AFE0(void) {
    func_1505E650(gCurrentObject, 0x48, 1.0f, 5.0f, 0.0f, 0.0f, 0);
}

void func_1506B020(void) {
    gCurrentObject->unk1CB = (u8)1;
    func_1505E650(gCurrentObject, 0x39, 1.0f, 5.0f, 0.0f, 0.0f, 0);
}

void func_1506B070(void) {
}

void func_1506B078(void) {
    f32 tmp = (gCurrentObject->y_position - (gCurrentObject->unk118 - 150.0f)) * D_80099C34;

    if (tmp < 0.0f) {
        tmp = 1.0f;
    } else {
        tmp +=  1.0f;
    }
    func_1506B100(0xD1, tmp, 4.0f);
}

// triggered when entering water?
void func_1506B100(s32 arg0, f32 arg1, f32 arg2) {
    func_1505E650(gCurrentObject, arg0, arg1, arg2, 0.0f, 0.0f, 0);
}

void func_1506B14C(void) {
    func_1505E650(gCurrentObject, (u16) (gCurrentObject->unk84.uh + 1), gCurrentObject->animation_speed, 3.0f, 0.0f, 0.0f, 0);
}

void func_1506B198(void) {
    func_1505E650(gCurrentObject, (u16) (gCurrentObject->unk84.uh + 1), gCurrentObject->animation_speed, 3.0f, 0.0f, 0.0f, 1);
}

void func_1506B1E8(void) {
    func_1505E650(gCurrentObject, 0x3C, 1.0f, 3.0f, 0.0f, 0.0f, 0);
}

void func_1506B228(void) {
    func_1505E650(gCurrentObject, 0x54, 1.0f, 3.0f, 0.0f, 0.0f, 0);
}

void func_1506B268(void) {
    gCurrentObject->unk83 = 0;
    gCurrentObject->disable_run = 0;
    func_1505E650(gCurrentObject, 0xF, 1.0f, 6.0f, 0.0f, 0.0f, 0);
}

void func_1506B2BC(void) {
    struct127 *temp_v0 = func_150721E8(gCurrentObject);
    if ((temp_v0 != 0) && (((((s32)temp_v0 - (s32)&gObjects) / 0x32C) + 1) == gObjects[0].unk274)) {
        gCurrentObject->unk218 = 0;
        gCurrentObject->unk232 = (u8)4;
    }
}

void func_1506B328(void) {
    func_1505E650(gCurrentObject, 0x3E, 1.0f, 5.0f, 0.0f, 0.0f, 0);
}

void func_1506B368(void) {
}

void func_1506B370(void) {
    // return index of gCurrentObject in structs array
    func_1507D4F8(((s32)gCurrentObject - (s32)gObjects) / (s32)sizeof(struct127));
}

void func_1506B3B0(void) {
}

void func_1506B3B8(void) {
    struct127 *obj;
    s16 diff;
    u8 idx;
    u8 mag;

    idx = 0;
    diff = (gCurrentObject->unk7A + (gCurrentObject->unk1FD << 8)) - func_1505A630(gObjects[0].x_position - gCurrentObject->x_position, gCurrentObject->z_position - gObjects[0].z_position, 0);
    mag = diff >> 8;
    if (mag & 0x80) {
        mag = -mag;
    }
    if (mag < ((u8 *)D_80099A3C)[idx]) {
        idx = 1;
    } else {
        if (D_80099A43 < mag) {
            idx = 5;
        } else if (*(u8 *)&D_80099A3E < mag) {
            idx = 2;
        }
        if (diff < 0) {
            idx += 4;
        } else {
            idx += 3;
        }
    }
    gCurrentObject->unk138 = 0;
    gCurrentObject->unk244 = ((u8 *)D_80099A3C)[idx];
    gCurrentObject->unk21C = 20000;
}
// NON-MATCHING: 5% there...
// void func_1506B3B8(void) {
//     u8 sp19;
//     s16 temp_t0;
//     s32 temp_a3;
//     s32 temp_v0;
//     s32 temp_v1;
//     struct127 *temp_a1;
//     struct127 *temp_a1_2;
//     s32 phi_a2;
//     s32 phi_a0;
//     u8 phi_a0_2;
//
//     temp_a1 = gCurrentObject;
//     sp19 = 0;
//     temp_a1_2 = gCurrentObject;
//     temp_t0 = (temp_a1_2->unk7A + (temp_a1_2->unk1FD << 8)) - func_1505A630(gObjects[0].x_position - temp_a1->x_position, temp_a1->z_position - gObjects[0].z_position, temp_a1);
//     temp_v1 = (s32) temp_t0 >> 8;
//     temp_a3 = temp_v1 & 0xFF;
//     phi_a2 = temp_v1 & 0xFF;
//     if ((temp_a3 & 0x80) != 0) {
//         phi_a2 = -temp_a3 & 0xFF;
//     }
//     temp_v0 = phi_a2;
//     if (phi_a2 < (s32) D_80099A3C) {
//         phi_a0 = 1;
//     } else {
//         if ((s32) D_80099A43 < temp_v0) {
//             phi_a0_2 = (u8)5U;
//         } else {
//             phi_a0_2 = sp19;
//             if ((s32) D_80099A3E < temp_v0) {
//                 phi_a0_2 = (u8)2U;
//             }
//         }
//         if ((s32) temp_t0 < 0) {
//             phi_a0 = (phi_a0_2 + 4) & 0xFF;
//         } else {
//             phi_a0 = (phi_a0_2 + 3) & 0xFF;
//         }
//     }
//     temp_a1_2->unk138 = (u8)0;
//     gCurrentObject->unk244 = (s16) D_80099A3C[phi_a0]; // + 0x800A0000)->unk-65C4;
//     gCurrentObject->unk21C = (u16)0x4E20;
// }

void func_1506B4EC(void) {
    func_1506B3B8();
}

void func_1506B50C(void) {
    gCurrentObject->unk21C = 0;
}

void func_1506B520(void) {
    s32 tmp;

    if (gCurrentObject->health != 0) {
        if ((gCurrentObject->unk31C != 0) && (gCurrentObject->unk31C->unk78 == 0x25)) {
            tmp = 427;
        } else {
            tmp = 240;
        }
        func_1505E650(gCurrentObject, tmp, 1.5f, 3.0f, 0.0f, 0.0f, 0);
    } else {
        func_1507CD64(gCurrentObject, 1);
    }
}

void func_1506B5A4(void) {
}

void func_1506B5AC(void) {
}

void func_1506B5B4(void) {
    gCurrentObject->unk1CB = (u8)1;
}

void func_1506B5CC(void) {
    gCurrentObject->unk1CB = (u8)1;
}

void func_1506B5E4(void) {
    func_1506160C(gCurrentObject, 2, 7, 8, 0);
    gCurrentObject->animation_speed = 0.0f;
    gCurrentObject->unk2D0->unk10 = 0.0f;
}

void func_1506B634(u8 arg0) {
    u8 idx;
    struct126 *s;

    idx = (u32)func_150ADA20() % arg0;
    s = gCurrentObject->unk31C;
    if (s->unk16 != 0) {
        if ((D_800BE9F0 == 0x29) && (idx == 7)) {
            idx = 0;
        }
        s->unkE = ((u8 *)D_80099ABC)[idx];
    } else {
        s->unkE = ((u8 *)D_80099AB4)[idx];
    }
    if (gCurrentObject->unk31C->unkE == 0xA7) {
        D_800D1580 = 0xFF020144;
        gCurrentObject->unk31C->unkC = ((u32)func_150ADA20() % 3) + 2;
        func_1506E8D8();
        gCurrentObject->xz_velocity *= D_80099C38;
    }
}
// NON-MATCHING: miles away
// void func_1506B634(u8 arg0) {
//     s32 temp_a0;
//     u32 temp_hi;
//     struct126 *temp_a1;
//     s32 phi_a0;
//     s32 phi_a0_2;
//
//     temp_hi = random_u32() % (u32) arg0;
//     temp_a0 = temp_hi & 0xFF;
//     temp_a1 = gCurrentObject->unk31C;
//     if (temp_a1->unk16 != 0) {
//         phi_a0 = temp_a0;
//         if (D_800BE9F0 == 0x29) {
//             phi_a0 = temp_a0;
//             if ((temp_hi & 0xFF) == 7) {
//                 phi_a0 = 0;
//             }
//         }
//         temp_a1->unkE = (s16) D_80099ABC[phi_a0]; // + 0x800A0000)->unk-6544;
//         phi_a0_2 = phi_a0;
//     } else {
//         temp_a1->unkE = (s16) D_80099AB4[(temp_hi & 0xFF)]; // + 0x800A0000)->unk-654C;
//         phi_a0_2 = temp_a0;
//     }
//     if (gCurrentObject->unk31C->unkE == 0xA7) {
//         D_800D1580 = 0xFF020144; // 4278321476
//         gCurrentObject->unk31C->unkC = (random_u32(phi_a0_2, temp_a1, &gCurrentObject) % 3U) + 2;
//         func_1506E8D8();
//         gCurrentObject->xz_velocity = (f32) (gCurrentObject->xz_velocity * D_80099C38);
//     }
// }

void func_1506B740(void) {
    u8 res = random_u32() & 0xFF;

    if ((D_80099C3C != gCurrentObject->unk118) && (gCurrentObject->y_position < gCurrentObject->unk118)) {
        gCurrentObject->unk31C->unkE = 0x2D0;
    } else {
        if (gCurrentObject->unk84.uh == 0xA7) {
            if (gCurrentObject->unk31C->unkC == 0) {
                res = 0;
            } else {
                gCurrentObject->unk31C->unkC--;
                res = 0xFF;
            }
        }
        if (res < 0x80) {
            func_1506B634(8);
        }
    }
}

void func_1506B7F4(void) {
    gCurrentObject->disable_run = 0;
    gCurrentObject->unk83 = 0;
    func_1506B634(2);
}

void func_1506B82C(void) {
    gCurrentObject->disable_run = 0;
    gCurrentObject->unk83 = 0;
    func_1507F640();
}

void func_1506B860(void) {
    func_1506B100(181, 0.6299999952316284f, 5.0f);
}

void func_1506B88C(void) {
    func_1506B100(182, 1.0f, 4.0f);
}

void func_1506B8B4(void) {
    gCurrentObject->unk31C->unk78 = (u8)0;
    gCurrentObject->disable_run = (u8)0;
    gCurrentObject->unk83 = (u8)0;
    func_1507F640();
}

void func_1506B8F4(void) {
    func_1506B100(222, 0.75f, 4.0f);
}

void func_1506B91C(void) {
    func_1506B100(191, 1.0f, 4.0f);
}

void func_1506B944(void) {
    gCurrentObject->disable_run = (u8)0;
    gCurrentObject->unk83 = (u8)0;
    func_1506B100(0xC5, 1.0f, 4.0f);
}

void func_1506B984(void) {
    func_1506B100(0xAF, 1.0f, 4.0f);
}

void func_1506B9AC(void) {
    gCurrentObject->unk244 = (u16)0;
}

void func_1506B9C0(void) {
    struct126 *temp_a0;

    D_800BE720[gCurrentObjectIndex] |= 0x4000;
    temp_a0 = gCurrentObject->unk31C;
    if (temp_a0 != 0) {
        temp_a0->unk78 = 0;
        D_800D2E60[D_800D1940 >> 3] |=  (1 << (D_800D1940 & 7));
    }
    func_1507F640(temp_a0);
}

void func_1506BA4C(s32 arg0, s32 arg1) {
    if (D_800D1580 == 0) {
        func_100109D0(gCurrentObject);
    } else {
        if (gCurrentObject->camera == 0) {
            func_10010154(D_800D1580, gCurrentObject, 28000, arg0, arg1);
        } else {
            func_10010154(D_800D1580, gCurrentObject, 24000, 500, 2500);
        }
    }
}

void func_1506BAD8(s32 arg0, s32 arg1) {
    if (D_800D1580 == 0) {
        func_10010A3C(gCurrentObject);
    } else {
        if (gCurrentObject->camera == 0) {
            func_10010344(D_800D1580, gCurrentObject, 28000, arg0, arg1);
        } else {
            func_10010344(D_800D1580, gCurrentObject, 24000, 500, 2500);
        }
    }
}

void func_1506BB64(s32 arg0, s32 arg1) {
    func_10012718(D_800D1582, gCurrentObject, 28000, arg0, arg1);
}

void func_1506BBA8(s32 arg0, s32 arg1) {
    if (gCurrentObject->camera == 0) {
        func_10010154(D_800D1582, gCurrentObject, 14000, arg0, arg1);
    } else {
        func_10010154(D_800D1582, gCurrentObject, 12000, 500, 2500);
    }
}

void func_1506BC24(s32 arg0, s32 arg1) {
    if (gCurrentObject->camera == 0) {
        func_10010344(D_800D1582, gCurrentObject, 0x36B0, arg0, arg1);
    } else {
        func_10010344(D_800D1582, gCurrentObject, 0x2EE0, 0x1F4, 0x9C4);
    }
}

void func_1506BCA0(void) {
    gCurrentObject->y_velocity = D_800D1580;
}

// ???
s32 func_151EF610();

void func_1506BCC8(void) {
    f32 diff;

    if (gCurrentObject->interaction_state == 0x16) {
        if (gCurrentObject->y_position == gCurrentObject->unk180) {
            gCurrentObject->y_velocity = (func_151EF610() % 8) + D_800D1580;
            if (gCurrentObject->xz_velocity != 0.0f) {
                gCurrentObject->y_velocity = gCurrentObject->y_velocity * (gCurrentObject->xz_velocity / 40.0f);
            } else {
                gCurrentObject->y_velocity = 0.0f;
            }
        }
    } else {
        diff = gCurrentObject->y_position - gCurrentObject->unk180;
        if ((-5.0f < diff) && (diff < 5.0f)) {
            gCurrentObject->y_velocity = D_800D1580;
        }
    }
}

void func_1506BDE8(void) {
    if (gCurrentObject->y_position < D_80099C40) {
        gCurrentObject->y_velocity = (f32) D_800D1580;
    }
}

void func_1506BE2C(void) {
    gCurrentObject->gravity = D_800D1580;
}

void func_1506BE54(void) {
    gCurrentObject->gravity = D_800D1580 * D_80099C44;
}

void func_1506BE84(void) {
    gCurrentObject->disable_run = 0;
}

void func_1506BE98(void) {
    gCurrentObject->target_speed = D_800D1580;
}

void func_1506BEC0(void) {
    gCurrentObject->disable_run = D_800D1580;
}

void func_1506BEDC(void) {
    gCurrentObject->unkD0 = D_800D1580;
    gCurrentObject->unk114 = (f32) ((s32) D_800D1580 >> 8);
}

void func_1506BF1C(void) {
    if (gCurrentObject->unk118 <= gCurrentObject->y_position) {
        func_1506BF5C();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506BF5C.s")
// NON-MATCHING: decrements the ring-buffer counter D_800D187C
// (bailing if already 0), unpacks D_800D1580 into three 11-bit
// fields (bits 0-10, 11-21, 22-32) alongside the decremented
// counter's own low 11 bits, picks a selector 0/2/3/4 by which
// packed field (checked highest-to-lowest) is first nonzero, and
// (for a nonzero selector) relays through func_1000F568 before
// picking a slot from the same 4-word local buffer via a runtime
// byte offset. If the picked value is nonzero, clears bit 16 and the
// low 11 bits of D_800D187C, ORs the picked value back in, writes it
// to D_800D1580, and calls func_1506BF5C().
// void func_1506C32C(void) {
//     s32 fields[4];
//     s32 counter;
//     s32 packed;
//     s32 sel;
//     s32 idx;
//     s32 chosen;
//
//     counter = D_800D187C;
//     if (counter == 0) {
//         return;
//     }
//
//     counter--;
//     D_800D187C = counter;
//     packed = D_800D1580;
//
//     fields[0] = counter & 0x7FF;
//     fields[1] = packed & 0x7FF;
//     fields[2] = (packed >> 11) & 0x7FF;
//     fields[3] = (packed >> 22) & 0x7FF;
//
//     if (fields[3] != 0) {
//         sel = 4;
//     } else if (fields[2] != 0) {
//         sel = 3;
//     } else if (fields[1] != 0) {
//         sel = 2;
//     } else {
//         sel = 0;
//     }
//
//     if (sel == 0) {
//         idx = 0;
//     } else {
//         func_1000F568(fields[0], sel);
//         idx = packed - fields[0];
//     }
//
//     chosen = *(s32 *) ((char *) fields + idx * 4);
//
//     if (chosen != 0) {
//         s32 masked = D_800D187C & 0xFFFEF800;
//         D_800D187C = masked;
//         D_800D1580 = chosen | masked;
//         func_1506BF5C();
//     }
// }
// 62 vs target's 59 instructions. Keeping `packed` as a local
// variable (letting IDO spill/reload it across the func_1000F568
// call as needed) landed closer than re-reading D_800D1580 a second
// time after the call, which needed an extra address computation and
// came out worse (65 instructions) - tried and reverted.
s32 func_1000F568(s32 arg0, s32 arg1);

void func_1506C32C(void) {
    s32 sel;
    s32 fields[4];

    if (D_800D187C == 0) {
        return;
    }
    D_800D187C--;
    fields[0] = D_800D187C & 0x7FF;
    fields[1] = D_800D1580 & 0x7FF;
    fields[2] = (D_800D1580 >> 11) & 0x7FF;
    fields[3] = (D_800D1580 >> 22) & 0x7FF;

    if (fields[3] != 0) {
        sel = 4;
    } else if (fields[2] != 0) {
        sel = 3;
    } else if (fields[1] != 0) {
        sel = 2;
    } else {
        sel = 0;
    }
    if (sel != 0) {
        sel = func_1000F568(fields[0], sel) - fields[0];
    }
    if (fields[sel] != 0) {
        D_800D187C &= 0xFFFEF800;
        D_800D1580 = fields[sel] | D_800D187C;
        func_1506BF5C();
    }
}

void func_1506C418(void) {
    func_10010A3C(gCurrentObject);
}

void func_1506C43C(void) {
    func_100109D0(gCurrentObject);
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506C460.s")
// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506CE6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506D2E8.s")
// NON-MATCHING: plenty to figure out here
// void func_1506D2E8(void) {
//     f32 sp40;
//     f32 sp3C;
//     f32 sp38;
//     f32 sp2C;
//     u16 temp_v0_2;
//     struct127 *temp_s0;
//     f32 phi_f0;
//
//     temp_s0 = func_1505EEF4(func_15083E0C(D_800D1580 & 0xFF));
//     if (temp_s0 != NULL) {
//         sp2C = 0.0f;
//         func_151A3390(temp_s0, 0xFF);
//         phi_f0 = 0.0f;
//         if ((D_800D1580 & 0xFF00) != 0) {
//             phi_f0 = gCurrentObject->camera->unk780 - 15.0f;
//         }
//         temp_v0_2 = gCurrentObject->unk7A;
//         temp_s0->unk78 = temp_v0_2;
//         temp_s0->unk7A = temp_v0_2;
//         temp_s0->unk76 = temp_v0_2;
//         func_1505A184(temp_v0_2, 5000.0f, phi_f0, &sp40, &sp3C, &sp38);
//         D_800D2104[temp_s0->unk13F]->unk8 = (s16) (s32) (gCurrentObject->x_position + sp40);
//         D_800D2104[temp_s0->unk13F]->unkC = (s16) (s32) (gCurrentObject->z_position + sp3C);
//         D_800D2104[temp_s0->unk13F]->unkA = (s16) (s32) (gCurrentObject->y_position + sp38);
//         temp_s0->unk65 = (u8)0;
//         temp_s0->unk218 = 0;
//         if ((D_800D1580 & 0xFF00) != 0) {
//             temp_s0->unk232 = (u8)4;
//             temp_s0->unk14C = 0.25f;
//             temp_s0->unk150 = 0.25f;
//             temp_s0->y_position = (f32) (gCurrentObject->y_position + 70.0f);
//         } else {
//             temp_s0->unk232 = (u8)2;
//             temp_s0->xz_velocity = -15.0f;
//             temp_s0->y_velocity = 34.0f;
//             temp_s0->unk14C = 0.5f;
//             temp_s0->unk150 = 0.5f;
//             temp_s0->gravity = (f32) D_80099D44;
//         }
//     }
// }

void func_1506D4F4(void) {
    func_1505E650(gCurrentObject, gCurrentObject->unk84.uh, 0.01f, 0.0f, 0.0f, 0.0f, 0);
}

void func_1506D538(void) {
    if (D_800C35EA != 1) {
        func_1507D4F8(gCurrentObjectIndex);
    }
}

void func_1506D570(void) {
    gCurrentObject->unk6E = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506D584.s")
// ???
// NON-MATCHING: register-choice gap in the last 4 instructions only -
// everything else verified instruction-for-instruction identical,
// including both bc1tl early-return guards, the health-based ternary
// needing its true-value (0x29) set unconditionally first with the
// false-value (0x2C) as the bnez-delay override (same "value computed
// first, conditionally overwritten" shape as func_15043B70), and the
// &D_800D1580 address computation landing at the exact same hoisted
// position as target (right after the unk1A6 load, well before its
// use). Only the final "reload D_800D1580, shift v0<<24, mask low
// 16 bits, OR together, store back" sequence differs: target uses
// $t0/$t9/$t1/$t2 for load/shift/andi/or, every C form tried here
// (both `&` operand orders, a named intermediate "cur" local forcing
// an early hoist, a (u16) cast instead of `& 0xFFFF` - which changed
// the instruction count instead) lands on $t9/$t8/$t0/$t1, a
// consistent one-register-down shift of the same four-register window.
// void func_1506D6B4(void) {
//     s32 v0;
//
//     if (gCurrentObject->unk118 == D_80099D4C) {
//         return;
//     }
//     if (gCurrentObject->unk118 < (f32) gCurrentObject->unk1A6) {
//         return;
//     }
//     v0 = (gCurrentObject->health >= 2) ? 0x2C : 0x29;
//     D_800D1580 = (v0 << 24) | (D_800D1580 & 0xFFFF);
//     func_1506D584();
// }
void func_1506D6B4(void) {
    s32 v0;
    if (gCurrentObject->unk118 == D_80099D4C) {
        return;
    }
    if (gCurrentObject->unk118 < (f32) gCurrentObject->unk1A6) {
        return;
    }
    v0 = (gCurrentObject->health >= 2) ? 0x2C : 0x29;
    D_800D1580 = ((v0 & 0xFF) << 24) | (D_800D1580 & 0xFFFF);
    func_1506D584();
}
// Handler 22 of the table at D_800863FC, which func_1506AD30 calls with D_800D1580
// set to a value from the entry that triggered it. For the current object: unless
// it's in water, sets its gravity to 5 and stops its vertical speed; raises it 70
// units; clears the byte at 0x137 and disable_run; moves it D_800D1580 units along
// its angle unk76 (func_1505A184 turns an angle and a distance into x/z offsets);
// calls func_1505E650(object, 15, 1.0f, ...) (what 15 selects isn't identified
// yet); and sets unk100 bit 1, unk28 = 0, unk83 = 20 and two fields of unk31C.
void func_1506D74C(void) {
    f32 dx;
    f32 dz;
    f32 dy;

    if (gCurrentObject->in_water == 0) {
        gCurrentObject->gravity = 5.0f;
        gCurrentObject->y_velocity = 0.0f;
    }
    gCurrentObject->y_position += 70.0f;
    (*(s8 *)((char *)(gCurrentObject) + 0x137)) = 0;
    gCurrentObject->disable_run = 0;
    func_1505A184((s32) gCurrentObject->unk76, (f32) D_800D1580, 0.0f, &dx, &dz, &dy);
    func_1505E650(gCurrentObject, 0xFU, 1.0f, 0.0f, 0.0f, 0.0f, 0);
    gCurrentObject->x_position += dx;
    gCurrentObject->z_position += dz;
    gCurrentObject->unk100 |= 2;
    gCurrentObject->unk28 = 0.0f;
    gCurrentObject->unk83 = 0x14;
    gCurrentObject->unk31C->unk44 = 0xC;
    gCurrentObject->unk31C->unk54 = 0xA;
}

void func_1506D898(void) {
    gCurrentObject->y_position -= 80.0f;
    func_1505E650(gCurrentObject, 663, 1.0f, 0.0f, 0.0f, 0.0f, 0);
    gCurrentObject->unk100 &= 0xFFDF;
    gCurrentObject->unk83 = 0;
    gCurrentObject->disable_run = 0;
    gCurrentObject->unk31C->unk97 = 0;
    gCurrentObject->unk31C->unk44 = 12;
}

void func_1506D934(void) {
    gCurrentObject->unk103 = D_800D1580;
}

void func_1506D950(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506D958.s")

void func_1506DA78(void) {
    gCurrentObject->immune = D_800D1580;
}

void func_1506DA94(void) {
    if (D_800D1580 != 0) {
        if ((gCurrentObject->unk44 > 20.0f) && (gCurrentObject->xz_velocity > 20.0f)) {
            gCurrentObject->unk83 = (u8)0;
        }
    }
    func_15174690(gCurrentObjectIndex, 0, 24, 0, 409, 4, 170, 0xFF, 0);
}

void func_1506DB30(void) {
    D_800D1890 = (s8) D_800D1580;
    func_15076760();
}

void func_1506DB5C(void) {
    gCurrentObject->xz_velocity = (f32) D_800D1580;
}

void func_1506DB84(void) {
    gCurrentObject->unk239 = (s8) D_800D1580;
}

void func_1506DBA0(void) {
    gCurrentObject->unk1E5 = D_800D1580 & 0xff;
    gCurrentObject->unk1E6 = (D_800D1580 >> 8) & 0xff;
}

void func_1506DBD4(void) {
    struct127 *temp_v0 = func_15072208(gCurrentObject, 0);
    if (temp_v0 != NULL) {
        func_15054A5C(temp_v0, gCurrentObject);
    }
}

void func_1506DC10(void) {
    s32 a0;
    s32 v1;

    if (gCurrentObject->unk118 - 60.0f < gCurrentObject->y_position ||
        gCurrentObject->unk118 == D_80099D50) {
        v1 = func_150ADA20() & 3;
        a0 = (v1 >= 2) ? (v1 + 0x612) : (v1 + 0x8F);
    } else {
        a0 = 9;
    }
    func_15060A9C(a0, gCurrentObject);
}

void func_1506DCA4(void) {
    gCurrentObject->unk2E8 = D_800D1580;
}

void func_1506DCC0(void) {
    gCurrentObject->unk2EC = (s32) D_800D1580;
}

void func_1506DCDC(void) {
    gCurrentObject->health = (s8) D_800D1580;
}

void func_1506DCF8(void) {
}

void func_1506DD00(void) {
    struct127 *temp_v1;

    if (D_800D1580 == 0) {
        temp_v1 = gCurrentObject;
        temp_v1->unkF8 = (s32) temp_v1->unk144->unk18;
    } else {
        temp_v1 = gCurrentObject;
        temp_v1->unkF8 |= D_800D1580;
    }
}

void func_1506DD44(void) {
    gCurrentObject->unkF8 &= ~D_800D1580;
}

void func_1506DD6C(void) {
    if (gCurrentObject->unk31C != 0) {
        gCurrentObject->unk31C->matrix_physics = D_800D1580 & 0x7F;
    }
    if (D_800D1580 == 0) {
        gCurrentObject->unk76 = gCurrentObject->unk7A;
    }
}

void func_1506DDB8(void) {
}

void func_1506DDC0(void) {
    if (func_15178E50(D_800BE9F0) != 0) {
        func_1516EED4(gCurrentObjectIndex, D_800D1580, 0xFF, 0);
    }
}

void func_1506DE04(void) {
    s32 i;
    for(i = 0; i < 2; i++) {
        func_15174690(gCurrentObjectIndex, 10, 18, 12, 0x199, 4, 0xAA, 0xFF, 0);
    }
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506DE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506E0EC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506E2CC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506E46C.s")

void func_1506E5FC(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(300, 1800);
    }
}

void func_1506E63C(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(100, 800);
    }
}

void func_1506E67C(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(190, 1300);
    }
}

void func_1506E6BC(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(300, 3000);
    }
}

void func_1506E6FC(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(700, 4000);
    }
}

void func_1506E73C(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BA4C(3000, 8000);
    }
}

void func_1506E77C(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BBA8(300, 1800);
    }
}

void func_1506E7BC(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) {
        func_1506BBA8(300, 3000);
    }
}

void func_1506E7FC(void) {
    if (gCurrentObject->unk28 == 0.0f) {
        if (gCurrentObject->unk107 == 0) {
            func_1506E5FC();
        }
    }
}

void func_1506E848(void) {
    if ((func_1506E46C(gCurrentObject, &D_800D1580, 0) != 0) && (func_1000F4D8((u16)D_800D1582) == 0)) {
        func_1506BA4C(0x50, 800);
    }
}

void func_1506E898(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 2) != 0) {
        func_1506BB64(300, 1800);
    }
}

void func_1506E8D8(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(300, 1800);
    }
}

void func_1506E918(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(100, 800);
    }
}

void func_1506E958(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(190, 1300);
    }
}

void func_1506E998(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(300, 3000);
    }
}

void func_1506E9D8(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(700, 4000);
    }
}

void func_1506EA18(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BAD8(3000, 8000);
    }
}

void func_1506EA58(void) {
    if (func_1506E46C(gCurrentObject, &D_800D1580, 1) != 0) {
        func_1506BC24(300, 3000);
    }
}

void func_1506EA98(void) {
    u8 temp_t6;
    struct127 *temp_a1;

    temp_t6 = (gCurrentObject->unk13C - 100);
    if (gCurrentObject->unk13C != 0) {
        temp_a1 = &gObjects[temp_t6];
        if (gObjects[temp_t6].unk13D >= 100) {
            gObjects[temp_t6].unk13D = (u8)0U;
            gObjects[temp_t6].xz_velocity = 18.0f;
            gObjects[temp_t6].y_velocity = 40.0f;
            gObjects[temp_t6].gravity = 6.0f;
            gObjects[temp_t6].unk76 = (u16) gCurrentObject->unk7A;
            gObjects[temp_t6].unk65 = (u8)0;
            if (gObjects[temp_t6].id  == 0x20) {
                gObjects[temp_t6].unkF8 |= 0x200;
                gObjects[temp_t6].y_velocity = 0.0f;
                gObjects[temp_t6].gravity = 0.0f;
                gObjects[temp_t6].xz_velocity = 0.0f;
            }
            gObjects[temp_t6].stunned = (u8)0xFE;
            gObjects[temp_t6].unk105 = (u8)0;
            gObjects[temp_t6].unk106 = func_1505E7CC(0xC, temp_a1); //, temp_t6);
            gObjects[temp_t6].unk84.uh = (u16)0xFFFF;
            gObjects[temp_t6].unk1CC = (f32) D_80099DA0;
            func_1505E874(temp_t6, temp_a1);
            gObjects[temp_t6].unk25C |= 0x40;
        }
        gCurrentObject->unk13C = (u8)0;
    }
}

void func_1506EBC0(void) {
    u8 temp_v0 = (u8)(gCurrentObject->unk13C - 100);

    if (gCurrentObject->unk13C) {
        if ((s32) gObjects[temp_v0].unk13D >= 0x64) {
            gObjects[temp_v0].unk65 = 0;
            gObjects[temp_v0].unk13D = (u8)0U;
            gObjects[temp_v0].xz_velocity = 0.0f;
            gObjects[temp_v0].y_velocity = 0.0f;
            gObjects[temp_v0].gravity = 6.0f;
            gObjects[temp_v0].unk1CC = D_80099DA4; // 1000000.0
        }
        gCurrentObject->unk13C = 0U;
    }
}

void func_1506EC50(void) {
    if (D_80099DA8 < gCurrentObject->unk28) {
        if (((D_800D1580 & 0x8000) == 0) || (D_800CC2E8[0] < gCurrentObject->y_position)) {
            D_800D1878 = D_800D1580 & 0xFF;
            D_800D1880 = 0;
            gCurrentObject->unk138 -= 1;
        }
    }
}

void func_1506ECD0(void) {
    gCurrentObject->unk2D0->unk4 |= 0x8000;
}

void func_1506ECF0(void) {
    gCurrentObject->unk3A = (s8) D_800D1580;
}

void func_1506ED0C(void) {
    gCurrentObject->unk83 = (s8) D_800D1580;
    gCurrentObject->unk100 |= 0x10;
    gCurrentObject->unk31C->unk31 = (u8)1;
}

void func_1506ED4C(void) {
    gCurrentObject->unk100 = (s8) D_800D1580;
}

void func_1506ED68(void) {
    gCurrentObject->unkA9 = (u8)5;
    gCurrentObject->unk31C->unk31 = (u8)0;
}

void func_1506ED90(void) {
    gCurrentObject->unk21C = (s16) D_800D1580;
}

void func_1506EDAC(void) {
    gCurrentObject->unkF4 = (s32) D_800D1580;
}

void func_1506EDC8(void) {
    gCurrentObject->unkF4 &= ~D_800D1580;
}

void func_1506EDF0(void) {
    gCurrentObject->unkF4 |= D_800D1580;
}

void func_1506EE14(void) {
    gCurrentObject->unk25C |= D_800D1580;
}

void func_1506EE38(void) {
    gCurrentObject->unk25C &= ~D_800D1580;
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Dispatches to
// func_15188810(gCurrentObject, D_800D1580&0xFFFF, D_800D1580>>16) if
// D_800D1580 is nonzero, else func_15188A9C(gCurrentObject,
// D_800D1580&0xFFFF) - the prior draft's "gCurrentObject.unk0" /
// "gCurrentObject.unk154C" were m2c artifacts (gCurrentObject's own
// address, 0x800D154C, misread as a fake struct field on it), fixed to
// plain gCurrentObject. Content otherwise matches, but target's
// `v0 & 0xFFFF` (computed once, in the outer beqz's delay slot, since
// it's needed on both the taken and fallthrough paths) gets reused
// as-is for the func_15188810 call in target, while this reconstruction
// recomputes it a second time right before that call regardless of
// whether it's written as a shared local or inlined at each use site -
// IDO isn't reusing the delay-slot value across to the call here.
void func_1506EE60(void) {
    s32 v0;

    v0 = D_800D1580;
    if (v0 != 0) {
        func_15188810(gCurrentObject, v0 & 0xFFFF, v0 >> 16);
    } else {
        func_15188A9C(gCurrentObject);
    }
}
// void func_1506EE60(void) {
//     s32 temp_v0 = D_800D1580;
//
//     if (temp_v0 != 0) {
//         func_15188810(gCurrentObject, temp_v0 & 0xFFFF, temp_v0 >> 0x10);
//         return;
//     }
//     func_15188A9C(gCurrentObject, temp_v0 & 0xFFFF);
// }

void func_1506EEAC(void) {
    func_151898C0(gCurrentObject, D_800D1580);
}

void func_1506EED8(void) {
    gCurrentObject->unk24E = (s8) D_800D1580;
}

void func_1506EEF4(void) {
    gCurrentObject->unk276 = (D_800D1580 >> 16) & 0xFFFF;
    gCurrentObject->unk278 = (D_800D1580 >> 24) & 0xFF;
    gCurrentObject->unk282 = D_800D1580 & 0xFFFF;
    gCurrentObject->unk284 = 0;
    gCurrentObject->unk285 = 0;
    gCurrentObject->unk286 = 0;
    gCurrentObject->unk287 = 0;
}

// TBD whats goins on here
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Sets
// gCurrentObject->unk282 (u16) and unk276 (u8), then unpacks two bytes of
// D_800D1580 (the packed-color global from func_150721A4/func_15072DA0
// earlier this session) into a 2-byte slot at unk284, indexed by the
// color's high byte doubled. Register allocation substantially different
// from target throughout, particularly the repeated gCurrentObject
// pointer reloads.
// NON-MATCHING (JUSTREG): semantics fully recovered and the
// instruction stream is exact - 22 of 22 words, same opcodes, same
// offsets, same constants.  Every difference is a register name.
// Target parks the materialised &gCurrentObject in $a2 and the
// D_800D1580 value in $t1 (with the lui landing in $v1); this build
// uses $a0 and reuses $v0 for both the lui and the load.  Reading
// D_800D1580 inline at each use instead of into a local, and giving the
// function one or two unused parameters to push allocation off $a0,
// both made it worse (22 of 22 rather than 20).
//
// One real fix did land and is worth keeping: the 0x282 store is to a
// u16, not an s16.  With s16 IDO narrows the constant and emits
// `li $t6, -1`; with u16 it emits `ori $t, $zero, 0xFFFF` exactly as
// target does.
// void func_1506EF5C(void) {
//     s32 v;
//
//     v = D_800D1580;
//     *(u16 *) ((char *) gCurrentObject + 0x282) = 0xFFFF;
//     *(u8 *) ((char *) gCurrentObject + 0x276) = 5;
//     *(u8 *) ((char *) gCurrentObject + ((v >> 16) & 0xFF) * 2 + 0x284) = v >> 8;
//     *(u8 *) ((char *) gCurrentObject + ((v >> 16) & 0xFF) * 2 + 0x285) = v;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506EF5C.s")
// void func_1506EF5C(void) {
//     s32 idx;
//
//     *(u16 *) ((char *) gCurrentObject + 0x282) = 0xFFFF;
//     *(u8 *) ((char *) gCurrentObject + 0x276) = 5;
//     idx = (u8) (D_800D1580 >> 16) << 1;
//     *(u8 *) ((char *) gCurrentObject + 0x284 + idx) = D_800D1580 >> 8;
//     *(u8 *) ((char *) gCurrentObject + 0x285 + idx) = D_800D1580;
// }

void func_1506EFB4(void) {
    gCurrentObject->unk282 = (u16)0;
}

void func_1506EFC8(s32 arg0) {
    if (gCurrentObject->id != 0x8C) {
        func_150BB760(gCurrentObject);
    }
}

void func_1506F004(s32 arg0) {
    func_150BCBBC(gCurrentObject);
}

void func_1506F02C(s32 arg0) {
    func_150BA4C0(gCurrentObject, 0xFF, 0);
}

void func_1506F05C(s32 arg0) {
    func_151925C4(gCurrentObject, 0x32, 0xFF, 1);
}

void func_1506F090(s32 arg0) {
    func_151925C4(gCurrentObject, -1, 0xFF, 1);
}

void func_1506F0C4(s32 arg0) {
    func_150C1260(gCurrentObject, 0);
}

void func_1506F0F0(s32 arg0) {
    func_150C1260(gCurrentObject, 1);
}

void func_1506F11C(s32 arg0) {
    func_150BABE0(gCurrentObject, 0, 0xFF);
}

void func_1506F14C(s32 arg0) {
    func_150BABE0(gCurrentObject, 1, 0xFF);
}

void func_1506F17C(s32 arg0) {
    func_150AEEB0(gCurrentObject, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506F1A8.s")

void func_1506F524(s32 arg0) {
    func_15197A7C(gCurrentObject);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1506F54C.s")

void func_1506F8C0(s32 arg0) {
    func_1519EF70(gCurrentObject, 0, 0);
}

void func_1506F8F0(s32 arg0) {
    struct127* a0;
    func_150E2EA4(a0 = gCurrentObject, a0->unique_id, 0x14, -1, 482.0f, -127.0f, -45.0f, D_80099E98, -211.0f, -114.0f, 3, 3, 5, 20.0f, (random_float() * 10.0f) + 40.0f, 0, 0.0f);
}

void func_1506F9C0(s32 arg0) {
    struct127* a0;
    func_150E2EA4(a0 = gCurrentObject, a0->unique_id, 0x14, -1, 241.0f, -127.0f, -45.0f, 418.0f, -211.0f, -114.0f, 3, 3, 5, 20.0f, (random_float() * 10.0f) + 40.0f, 0, 0.0f);
}

void func_1506FA90(s32 arg0) {
    struct127* a0;
    func_150E2EA4(a0 = gCurrentObject, a0->unique_id, 0x1A, -1, -181.0f, -218.0f, -1.0f, D_80099E9C, -584.0f, -2.0f, 3, 3, 5, 20.0f, (random_float() * 10.0f) + 40.0f, 0, 0.0f);
}

void func_1506FB60(s32 arg0) {
    if (func_151044F4() != 0) {
        func_151C6A28(gCurrentObject, (arg0 - 0x13) & 0xFF, 0xFF, 0);
    } else {
        func_151C62D0(gCurrentObject, (arg0 - 0x13) & 0xFF, 0, 0, -1, 0xFF, 0);
    }
}

void func_1506FBE8(s32 arg0) {
    func_151A0A10(gCurrentObject, 0x46, 0xFF, 0);
}

void func_1506FC1C(s32 arg0) {
    func_151A0A10(gCurrentObject, 0x28, 0xFF, 0);
}

void func_1506FC50(s32 arg0) {
    func_1519E688();
}

void func_1506FC74(s32 arg0) {
    func_1519E6BC(gCurrentObject);
}

void func_1506FC9C(s32 arg0) {
    func_150B3AB0(gCurrentObject, 0xFF);
}

void func_1506FCC8(s32 arg0) {
    func_15196438(gCurrentObject, 6, 0xFF, 0);
}

void func_1506FCFC(s32 arg0) {
    func_15196438(gCurrentObject, 5, 0xFF, 0);
}

// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Randomizes one float parameter (func_150ADA68()*10.0f +
// 40.0f) and passes it, along with gCurrentObject, its unk3B byte
// field, and a fixed set of otherwise-constant arguments, into the
// already-real, already-prototyped 17-parameter effect/particle
// spawner func_150E2EA4 (matches its real prototype exactly, param
// for param). arg0 (this function's own parameter) is spilled per
// this codebase's usual K&R boilerplate but never actually read -
// gCurrentObject is used directly instead.
// 47 vs target's 48 instructions - every constant (414.0f, 20.0f,
// 10.0f, 40.0f, 50.0f, 3, 3, 5, 1, -1, 1) lands in the exact right
// argument slot. The one gap: target constructs 0.0f into two
// separate float registers ($f2 and $f12) for the four zero-valued
// arguments, while this reconstruction's compile recognizes all four
// can share one already-materialized zero register - one fewer
// instruction for identical behavior.
// void func_1506FD30(void *arg0) {
//     f32 rnd;
//     f32 scaled;
//
//     rnd = func_150ADA68();
//     scaled = rnd * 10.0f + 40.0f;
//
//     func_150E2EA4(gCurrentObject, *((u8 *) gCurrentObject + 0x3B), 1, -1,
//                   0.0f, 0.0f, D_80099EA0, 0.0f, 0.0f, 414.0f,
//                   3, 3, 5, 20.0f, scaled, 1, 50.0f);
// }
extern f32 D_80099EA0;
void func_1506FD30(s32 arg0) {
    struct127 *a0;
    func_150E2EA4(a0 = gCurrentObject, a0->unique_id, 1, -1, 0.0f, 0, D_80099EA0, 0.0f, 0, 414.0f, 3, 3, 5, 20.0f, (func_150ADA68() * 10.0f) + 40.0f, 1, 50.0f);
}

void func_1506FDF0(s32 arg0) {
    func_151AABC4(gCurrentObject, 0);
}

void func_1506FE1C(s32 arg0) {
    func_151AABC4(gCurrentObject, 1);
}

void func_1506FE48(s32 arg0) {
    func_151AABC4(gCurrentObject, 0);
}

void func_1506FE74(s32 arg0) {
    func_151AABC4(gCurrentObject, 1);
}

void func_1506FEA0(s32 arg0) {
    func_151AABC4(gCurrentObject, 2);
}

void func_1506FECC(s32 arg0) {
    func_151AABC4(gCurrentObject, 3);
}

void func_1506FEF8(s32 arg0) {
    func_151AB920(gCurrentObject, 0);
}

void func_1506FF24(s32 arg0) {
    func_151AB920(gCurrentObject, 1);
}

void func_1506FF50(s32 arg0) {
    func_151AB930(gCurrentObject);
}

void func_1506FF78(s32 arg0) {
    func_150CBF80(gCurrentObject, 0, 1, 0xFF);
}

void func_1506FFAC(s32 arg0) {
    func_150CBF80(gCurrentObject, 1, 1, 0xFF);
}

void func_1506FFE0(s32 arg0) {
    func_150CBF80(gCurrentObject, 2, 1, 0xFF);
}

void func_15070014(s32 arg0) {
    func_150CA150(gCurrentObject);
}

void func_1507003C(s32 arg0) {
    func_151B01B8(gCurrentObject, 0);
    func_151B09BC(gCurrentObject, 0, 0x3E8, 0xFF, 0);
}

void func_15070084(s32 arg0) {
    func_151AECA0(gCurrentObject, 0xFF, 1);
}

void func_150700B4(s32 arg0) {
    func_151B03B8(gCurrentObject, 0xFF, 1);
}

void func_150700E4(s32 arg0) {
    func_15193660(gCurrentObject, 0xFF, 1);
}

void func_15070114(s32 arg0) {
    func_151937F4(gCurrentObject, 0xFF, 1);
}

void func_15070144(s32 arg0) {
    struct198 tmp;
    s32 tmp0;

    tmp.unk0 = 1;
    tmp.unk8 = 0;
    tmp.unkC = 0;
    tmp.unk4 = gCurrentObject;

    if (D_800BE9F0 == 0x2B) {
        tmp0 = 3;
    } else {
        tmp0 = 0;
    }
    func_151C0698(gCurrentObject, 0, &tmp, tmp0 & 0xFF, 0xFF, 1);
    func_151C1FB8(gCurrentObject);
}

void func_150701C4(s32 arg0) {
    func_151C5280(gCurrentObject, 0xFF, 1);
}

void func_150701F4(s32 arg0) {
    func_151C9740(gCurrentObject, 0xFF, 1);
}

struct225 *func_151602C0(Header *header, Header2 *header2, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 offset, s32 arg9, s32 argA);

struct225 *func_15070224(void *arg0) {
    Header header;
    Header2 header2;
    u8 rand1;
    u8 rand2;

    header.unk0 = 3;
    header.unk1 = -1;

    rand1 = func_150ADA20();
    header.unk2 = ((u32) rand1 % 5) + 4;

    header.unk4 = 0;

    header2.unk0 = (s32) gCurrentObject->x_position;
    header2.unk4 = (s32) gCurrentObject->y_position;
    header2.unk8 = (s32) gCurrentObject->z_position;

    rand2 = func_150ADA20();

    return func_151602C0(&header, &header2, ((u32) rand2 % 3) + 4, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0xFF, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15070300.s")

void func_15070690(s32 arg0) {
    func_150EEE00(gCurrentObject, (arg0 - 0x3E) & 0xFF, arg0);
}

void func_150706C4(s32 arg0) {
    func_150EEF40(gCurrentObject, (arg0 - 0x3E) & 0xFF, arg0);
}

void func_150706F8(s32 arg0) {
    if ((gCurrentObject->unk94 & 0x10) == 0) {
        func_150F03F8(gCurrentObject, 0, 0xFF, 1);
    }
    if ((gCurrentObject->unk94 & 8) == 0) {
        func_150F03F8(gCurrentObject, 1, 0xFF, 1);
    }
}

void func_15070760(s32 arg0) {
    func_150EBEC0(gCurrentObject, 0, 0xFF, 1);
}

void func_15070794(s32 arg0) {
    func_150EBEC0(gCurrentObject, 1, 0xFF, 1);
}

void func_150707C8(s32 arg0) {
    func_150FDDA0(gCurrentObject, 0xFF, 1);
}

void func_150707F8(s32 arg0) {
    func_150FDF38(gCurrentObject, 0xFF, 1, 0, 0);
}

void func_15070830(s32 arg0) {
    func_150FE320(gCurrentObject, 0xFF, 1);
}

void func_15070860(s32 arg0) {
    func_150FE49C(gCurrentObject, 0xFF, 1, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15070898.s")

void func_15070C18(s32 arg0) {
    func_15199834(gCurrentObject);
}

void func_15103E40(struct127 *, struct127 *, struct17 *, u8, s32, s32, s32);

void func_15070C40(u8 arg0) {
    struct17 tmp;
    struct127 *obj;
    struct127 *target;

    obj = gCurrentObject;
    tmp.unk0 = obj->x_position;
    tmp.unk4 = obj->y_position;
    tmp.unk8 = obj->z_position;
    if (obj->unk124) {
        target = &gObjects[obj->unk124 - 1];
    } else {
        target = obj;
    }
    func_15103E40(target, obj, &tmp, arg0, 0, 0xFF, 0);
}
// NON-MATCHING: missing a move and a branch
// void func_15103E40(s32, s32, s32, u8, u8, u8, u8);
// void func_15070C40(u8 arg0) {
//     struct17 tmp;
//     struct127 *temp_a1;
//     struct127 *phi_a0;
//
//     phi_a0 = temp_a1 = gCurrentObject;
//     tmp.unk0 = temp_a1->x_position;
//     tmp.unk4 = temp_a1->y_position;
//     tmp.unk8 = temp_a1->z_position;
//
//     if (temp_a1->unk124) {
//         phi_a0 = &gObjects[temp_a1->unk124 - 1];
//         func_15103E40(phi_a0, temp_a1, &tmp, arg0, 0, 0xFF, 0);
//     }
// }

void func_15070CDC(s32 arg0) {
    func_15070C40(1);
}

void func_15070D00(s32 arg0) {
    func_15070C40(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15070D24.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15070F60.s")
void func_15071230(s32 arg0) {
    func_15070F60(0);
}

void func_15071254(s32 arg0) {
    func_15070F60(1);
}

void func_15071278(s32 arg0) {
    func_150FC438(gCurrentObject, 0, 1, gCurrentObject->unk84.ub[1]);
}

void func_150712AC(s32 arg0) {
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    func_150FE860(gCurrentObject, 0xFF, 1);
    if (gCurrentObject->camera == 0) {
        return;
    }
    local.f0 = 1;
    local.f2 = (u32) func_150ADA20() % 7 + 10;
    local.f5 = 1 << gCurrentObject->camera->unk23D;
    local.f4 = (u32) func_150ADA20() % 7 + 2;
    local.f6 = -1;
    func_151D8868(&local, 0, 0xFF, 1);
}
void func_15071360(s32 arg0) {
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    if (func_151044F4()) {
        func_150FF084(gCurrentObject, 0xFF, 1);
    } else {
        func_150FED30(gCurrentObject, 0xFF, 1);
    }
    if (gCurrentObject->camera == 0) {
        return;
    }
    local.f0 = 1;
    local.f2 = (u32) func_150ADA20() % 5 + 15;
    local.f5 = 1 << gCurrentObject->camera->unk23D;
    local.f4 = (func_150ADA20() & 3) + 3;
    local.f6 = -1;
    func_151D8868(&local, 0, 0xFF, 1);
}

void func_15071434(s32 arg0) {
    func_150FF840(gCurrentObject, 1, 0, 0xFF, 1);
}

void func_15071470(s32 arg0) {
    func_150FF840(gCurrentObject, 0, 0, 0xFF, 1);
}

void func_150714AC(s32 arg0) {
    func_150FF840(gCurrentObject, 0, 1, 0xFF, 1);
}

void func_150714E8(s32 arg0) {
    func_151D5714(gCurrentObject, &D_800A2148, &D_800A2154, D_80088BB0, 1.0f, 0xFF, 1);
}

void func_15071544(s32 arg0) {
    func_151D4668(gCurrentObject);
    func_151D469C(gCurrentObject, 4, 0x78, 0xFF, 1);
}

void func_1507158C(s32 arg0) {
    func_151D4668(gCurrentObject);
    func_151D469C(gCurrentObject, 2, 0x78, 0xFF, 1);
}

void func_150715D4(s32 arg0) {
    func_151D4668(gCurrentObject);
    func_151D469C(gCurrentObject, 3, 0x78, 0xFF, 1);
}

void func_1507161C(s32 arg0) {

}

void func_15071628(s32 arg0) {
    func_151D0058(gCurrentObject, (arg0 - 0x55) & 0xFF, 0xFF, 1);
}

void func_15071668(s32 arg0) {
    func_151D0024(gCurrentObject);
}

void func_15071690(s32 arg0) {
    struct127 *temp_a0;
    s32 pad0;
    s32 sp1C;

    temp_a0 = gCurrentObject;
    if ((temp_a0->unk1D4 != 0) && ((temp_a0->unk74 & 0xF) != 0xF)) {
        func_150B60E0(temp_a0, &sp1C);
        func_150B5C38(&sp1C, 0xFF, 1);
    }
}

void func_150716EC(s32 arg0) {
    struct17 tmp;
    struct127 *temp_v0;

    temp_v0 = gCurrentObject;
    tmp.unk0 = temp_v0->x_position;
    tmp.unk4 = temp_v0->y_position;
    tmp.unk8 = temp_v0->z_position;
    func_151D5404(&tmp, 1502.0f, 3000.0f, 0.0003333333333333333f, 0xC, 0xF, 0xFF, 0);
}

void func_15071764(s32 arg0) {
    struct127 *sp34 = func_15083E90(18);
    if (sp34 != NULL) {
        func_150F0BEC(sp34);
        func_150F10D4(sp34);
        func_15161E24(sp34, 1, 2, 300, 70, 255, 130, 0, 255, 1);
    }
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Fetches a
// struct127 by id 0x12, and if found, passes its pointer plus its
// unique_id byte (bundled into a local 2-field struct so the compiler
// doesn't eliminate the byte write as dead - both fields' addresses
// need to be exposed) to two calls. Content, frame size, and struct
// layout all match target exactly except one instruction: target saves
// the tmp address to a second stack slot before the first call and
// reloads it for the second, while IDO here (correctly, in isolation)
// just recomputes the cheap `addiu` a second time instead - couldn't
// find a source form that forces the more expensive save/reload IDO
// apparently used for the real target binary.
// NON-MATCHING (12 of 19 words): semantics recovered.  It asks
// func_15083E90 for object type 0x12 and, if it gets one, builds a
// two-field record on the stack (the object pointer plus its unk3B
// byte) and hands it to func_15131D4C and then func_151494E0, both
// with 0x43.  arg0 is homed and never used.
//
// The gap is one spilled pointer.  Target computes `&sp20` once, spills
// it to 0x18(sp) and reloads it after the first call; this build
// rematerialises `addiu $a0, $sp, 0x20` after the call instead, which
// is cheaper and drops the store, and every following word shifts by
// one.  Routing both calls through an explicit local (as below) is
// already the form that should force the spill, so this is the
// allocator preferring rematerialisation, not a source shape.
// void func_150717E0(s32 arg0) {
//     struct {
//         void *f0;
//         u8 f4;
//     } sp20;
//     void *p;
//     void *v0;
//
//     v0 = func_15083E90(0x12);
//     if (v0 != 0) {
//         sp20.f0 = v0;
//         sp20.f4 = *(u8 *) ((char *) v0 + 0x3B);
//         p = &sp20;
//         func_15131D4C(p, 0x43);
//         func_151494E0(p, 0x43);
//     }
// }
void func_150717E0(s32 arg0) {
    struct {
        struct127 *ptr;
        u8 id;
    } tmp;
    struct127 *temp_v0;

    temp_v0 = func_15083E90(0x12);
    if (temp_v0 != 0) {
        arg0 = (s32)&tmp;
        tmp.ptr = temp_v0;
        tmp.id = temp_v0->unique_id;
        func_15131D4C(arg0, 0x43);
        func_151494E0(arg0, 0x43);
    }
}
// void func_150717E0(s32 arg0) {
//     struct {
//         struct127 *ptr;
//         u8 id;
//     } tmp;
//     struct127 *temp_v0;
//
//     temp_v0 = func_15083E90(0x12);
//     if (temp_v0 != 0) {
//         tmp.ptr = temp_v0;
//         tmp.id = temp_v0->unique_id;
//         func_15131D4C(&tmp, 0x43);
//         func_151494E0(&tmp, 0x43);
//     }
// }

void func_15071830(s32 arg0) {
    func_150F9BB0(gCurrentObject, 0xFF, 1);
}

void func_15071860(s32 arg0) {
    func_1519072C(gCurrentObject);
}

void func_15071888(s32 arg0) {
    func_151D5714(gCurrentObject, &D_800A1FB0, &D_800A1FBC, D_80088B90, D_80099F30, 0xFF, 1);
}

void func_150718E4(s32 arg0) {
    s32 idx;
    struct {
        union {
            s32 word;
            u8 bytes[4];
        } f0;
        s32 f4;
        f32 f8;
    } local;

    local.f0.word = D_80099BB8;
    if (gCurrentObject->unk1D4 != 0 || (gCurrentObject->unk74 & 0xF) == 0xF) {
        idx = func_150ADA20() & 3;
        func_15143134(&D_800A5480, &local.f4, (local.f0.bytes[idx] << 6) + (s32) gCurrentObject->unk1D4);
        local.f8 = gCurrentObject->unk180 + 20.0f;
        func_151C329C(&local.f4, 0xFF, 1);
    }
}

void func_15071998(s32 arg0) {
    func_150FA520(gCurrentObject, 0, 0xFF, 1);
}

void func_150719CC(s32 arg0) {
    func_150FA520(gCurrentObject, 1, 0xFF, 1);
}

void func_15071A00(s32 arg0) {
    func_150FA520(gCurrentObject, 2, 0xFF, 1);
}

void func_15071A34(s32 arg0) {
    func_151D09A8(gCurrentObject, 0xFF, 1);
}

void func_15071A64(s32 arg0) {
    char buf2[0xC];
    char buf1[0x24];
    struct127 *obj;

    if ((func_150ADA20() & 1) != 0) {
        return;
    }
    obj = gCurrentObject;
    if (obj->unk1D4 == 0) {
        return;
    }
    if ((obj->unk74 & 0xF) == 0xF) {
        return;
    }
    if (gObjects[0].stunned == 0) {
        return;
    }
    if (gObjects[0].health <= 0) {
        return;
    }
    func_1504715C(buf1, obj);
    func_15143134(&D_80099BBC, buf2, (s32) gCurrentObject->unk1D4 + 0x3C0);
    func_151DC484(buf2, buf1, 0, 0xFF, 1);
}
// NON-MATCHING: the C below matches except that the original keeps gCurrentObject in $a1
// instead of $v0 for the first three tests (register allocation only, 4 words).
// void func_15071A64(s32 arg0) {
//     char buf2[0xC];
//     char buf1[0x24];
//
//     if ((func_150ADA20() & 1) != 0) {
//         return;
//     }
//     if (gCurrentObject->unk1D4 == 0) {
//         return;
//     }
//     if ((gCurrentObject->unk74 & 0xF) == 0xF) {
//         return;
//     }
//     if (gObjects[0].stunned == 0) {
//         return;
//     }
//     if (gObjects[0].health <= 0) {
//         return;
//     }
//     func_1504715C(buf1);
//     func_15143134(&D_80099BBC, buf2, (s32) gCurrentObject->unk1D4 + 0x3C0);
//     func_151DC484(buf2, buf1, 0, 0xFF, 1);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15071B18.s")

void func_15071D08(s32 arg0) {
    func_150F2230(gCurrentObject, 0xFF, 1);
}

void func_15071D38(void) {
    void (*func)(s32);

    func = D_80086150[D_800D1580];
    if (func != 0) {
        func(D_800D1580);
    }
}

void func_15071D78(void) {
    struct127 *tmp;
    struct127 *orig;

    tmp = func_150721E8(gCurrentObject);
    if (tmp != NULL) {
        orig = gCurrentObject;
        gCurrentObject = tmp;
        func_15071D38();
        gCurrentObject = orig;
    }
}

void func_15071DC8(void) {
    func_15141A7C(gCurrentObject, D_800D1580);
}

void func_15071DF4(void) {
    func_15192800(gCurrentObject, D_800D1580);
}

void func_15071E20(void) {
    gCurrentObject->unk247 = (s8) D_800D1580;
}

void func_15071E3C(void) {
    gCurrentObject->unk248 = (s8) D_800D1580;
}

void func_15071E58(void) {
    D_800D1878 = D_800D1580 & 0xFF;
    gCurrentObject->unk244 = (D_800D1580 >> 8) & 0xFF;
    func_1505E650(gCurrentObject, gCurrentObject->unk244, 1.2f, 3.0f, D_800D1878, 0.0f, 0);
}

void func_15071ED4(void) {
    func_1505E650(gCurrentObject, 0x59, 1.0f, 3.0f, 0.0f, 0.0f, 0);
}

void func_15071F14(void) {
    func_1505E650(gCurrentObject, 0x24, 1.0f, 3.0f, 0.0f, 0.0f, 0);
}

void func_15071F54(void) {
    func_1507C8E0(gCurrentObject, D_800D1580);
}

void func_15071F80(void) {
    if (D_800C35EA == 1) {
        gCurrentObject->unk138++;
    }
}

void func_15071FB0(void) {
    if (gCurrentObject->unk28 == 0.0f) {
        gCurrentObject->unk10C = (u16)0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15071FDC.s")
// NON-MATCHING: semantics fully recovered and verified via isolated
// harness - unpacks the 3 low bytes of the packed color D_800D1580
// and forwards them (in a non-RGB byte order: bits16-23, bits0-7,
// bits8-15) plus a trailing 0 to func_1506160C(gCurrentObject, ...).
// Frame size and every instruction OFFSET match target exactly
// (17/17 instructions, same shift-into-temp-then-mask-into-call-
// register shape target uses), but two physical register choices
// differ: target keeps D_800D1580's address (v0) and loaded value
// (v1) in separate registers while IDO here always coalesces them
// into one (v0) regardless of declaration order, and correspondingly
// picks t6/t8 for the two shift temporaries where target uses t6/t7 -
// both immune to every variable-ordering variant tried (including
// pre-loading gCurrentObject into its own local first).
// void func_150721A4(void) {
//     s32 v1 = D_800D1580;
//     u8 byte2 = (v1 >> 16) & 0xFF;
//     u8 byte1 = (v1 >> 8) & 0xFF;
//     func_1506160C(gCurrentObject, byte2, v1 & 0xFF, byte1, 0);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_150721A4.s")
// NON-MATCHING: identical instructions, ordering, and size (0x44 bytes) to
// target across every source variation tried (direct global reads, a
// hoisted color local, inline casts, swapped declaration order) - only the
// specific register NUMBERS IDO -O2 picks for the loaded D_800D1580 value
// and the two sra results differ (v0/v1/t0 here vs target's v1/t6/t7).
// void func_150721A4(void) {
//     u8 tmp2 = D_800D1580 >> 8;
//     u8 tmp0 = D_800D1580 >> 16;
//     u8 tmp1 = D_800D1580;
//     func_1506160C(gCurrentObject, tmp0, tmp1, tmp2, 0);
// }

struct127 *func_150721E8(struct127 *arg0) {
    return func_15072208(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15072208.s")

void func_150722F0(void) {
    struct127 *temp_v0 = func_150721E8(gCurrentObject);
    if (temp_v0 != 0) {
        u8 tmp0 = (D_800D1580 >> 8);
        u8 tmp1 = D_800D1580 & 0xFF;
        func_1506160C(temp_v0, 2, tmp0, tmp1, 0);
    }
}
// NON-MATCHING: the C below matches except that the original loads D_800D1580 into $t0
// instead of $v0 (register allocation only, 3 words). Variants with s32 locals,
// inline masks, a u8 prototype for func_1506160C or an early return change the
// size; other orderings of the u8 locals don't move the register.
// void func_150722F0(void) {
//     struct127 *temp_v0 = func_150721E8(gCurrentObject);
//     if (temp_v0 != 0) {
//         u8 tmp0 = D_800D1580 >> 8;
//         u8 tmp1 = D_800D1580;
//         func_1506160C(temp_v0, 2, tmp0, tmp1, 0);
//     }
// }

void func_1507233C(void) {
    gCurrentObject->unk94 = (s32) ~(D_800D1580 | 1);
}

void func_15072360(void) {
    gCurrentObject->unk94 &= ~D_800D1580;
}

void func_15072388(void) {
    gCurrentObject->unk94 |= D_800D1580;
}

void func_150723AC(void) {
    struct127 *temp_v0 = func_15083E90(D_800D1583);
    if (temp_v0 != NULL) {
        func_15060F28(temp_v0, 0);
    }
}

void func_150723E0(void) {
    struct127 *temp_v0 = func_15083E90(D_800D1583);
    if ((temp_v0 != 0) && (temp_v0->unk65 != 0)) {
        func_15060F28(temp_v0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15072420.s")
// NON-MATCHING: full semantics recovered and verified via isolated
// harness - initializes a gObjects slot. Skips entirely if
// D_800BE616==0 and gCurrentObject->unk222 (a byte, doubling as a
// gObjects index) is 0. Otherwise, on gObjects[gCurrentObject->
// unk222] (stride 0x32C, matching struct127's real size), sets
// several constant fields (unk101=4, unk104=0, unk125=0xFF, unk218=0,
// unkE4/unkE6=0, unkEC/unkF0/unkDC/unkE0=1.0f) plus two derived from
// live state (unk65 = gCurrentObjectIndex+1, unk5C = D_800D1580>>16,
// unk232 = (u8) D_800D1580), then calls the still-undocumented (K&R-
// declared here, matching this codebase's convention for calling an
// under-referenced helper faithfully without guessing its body)
// func_151B5BA0 on a SEPARATE gObjects entry - the one at
// gCurrentObjectIndex directly, not the unk222-derived one. Both
// gCurrentObject and gCurrentObjectIndex are genuinely read twice
// (once for the early guard/first use, once again later with no
// intervening write) - reproduced by re-expressing each access as its
// own statement, needing an explicit `volatile` cast on the second
// gCurrentObjectIndex read specifically since otherwise IDO CSEs the
// two reads together (no such trick was needed for gCurrentObject's
// own double-read, which reproduced naturally from two separate
// statements alone).
// 51 vs target's 53 instructions - every field offset, constant, and
// the two double-reads match; the remaining 2-instruction gap is
// this reconstruction being more efficient in ways not yet isolated
// (same class of "IDO finds a shorter form than target used" already
// seen repeatedly this session).
// void func_1507266C(void) {
//     u8 idx;
//     s32 val;
//     char *target;
//
//     if (D_800BE616 == 0 && *((u8 *) gCurrentObject + 0x222) == 0) {
//         return;
//     }
//
//     idx = *((u8 *) gCurrentObject + 0x222);
//     val = D_800D1580;
//     target = (char *) gObjects + idx * 0x32C;
//     *((u8 *) target + 0x65) = gCurrentObjectIndex + 1;
//     *(s32 *) (target + 0x5C) = val >> 16;
//     *((u8 *) target + 0x101) = 4;
//     *((u8 *) target + 0x104) = 0;
//     *((u8 *) target + 0x125) = 0xFF;
//     *(s32 *) (target + 0x218) = 0;
//     *(s16 *) (target + 0xE4) = 0;
//     *(s16 *) (target + 0xE6) = 0;
//     *((u8 *) target + 0x232) = (u8) val;
//     *(f32 *) (target + 0xEC) = 1.0f;
//     *(f32 *) (target + 0xF0) = 1.0f;
//     *(f32 *) (target + 0xDC) = 1.0f;
//     *(f32 *) (target + 0xE0) = 1.0f;
//
//     func_151B5BA0((char *) gObjects + (*(volatile u8 *) &gCurrentObjectIndex) * 0x32C);
// }
void func_151B5BA0(struct127 *arg0, struct127 *arg1);

void func_1507266C(void) {
    struct127 *obj;
    s32 hi;
    u8 lo;

    if ((D_800BE616 != 0) || (gCurrentObject->unk222 != 0)) {
        obj = &gObjects[gCurrentObject->unk222];
        lo = D_800D1580;
        hi = D_800D1580 >> 16;
        obj->unk65 = gCurrentObjectIndex + 1;
        obj->unk5C = hi;
        obj->unk101 = 4;
        obj->stunned = 0;
        obj->immune = 0xFF;
        obj->unk218 = 0;
        obj->unkE4 = 0;
        obj->unkE6 = 0;
        obj->unk232 = lo;
        obj->unkEC = 1.0f;
        obj->unkF0 = 1.0f;
        obj->unkDC = 1.0f;
        obj->unkE0 = 1.0f;
        func_151B5BA0(&gObjects[gCurrentObjectIndex], obj);
    }
}

void func_15072740(void) {
    s32 temp_v0;
    struct127 *temp_v1;

    temp_v0 = D_800D1580 >> 16;
    temp_v1 = &gObjects[gCurrentObject->unk222];
    temp_v1->unk65 = gCurrentObjectIndex + 1;
    temp_v1->unk5C = temp_v0;
    temp_v1->unk101 = 4;
}

void func_150727AC(void) {
    gCurrentObject->animation_speed = D_800D1580 * D_80099F4C;
    gCurrentObject->unk2D0->unk10 = gCurrentObject->animation_speed;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_150727F0.s")

void func_15072918(void) {
    func_15060F28(gCurrentObject, 0);
}

void func_15072940(void) {
    func_15060F28(gCurrentObject, 1);
}

void func_15072968(void) {
    func_1505E650(gCurrentObject, 44, 1.5f, 12.0f, 0.0f, 0.0f, 0);
    gCurrentObject->disable_run = 25;
}

void func_150729B4(void) {
    gCurrentObject->unk2E4 = D_800D1580;
}

void func_150729D0(void) {
    gCurrentObject->unk31C->unk8 = (u16)1;
    func_1507EB4C(gCurrentObject, 21);
    func_1506B82C();
}

void func_15072A14(void) {
    gCurrentObject->unk31C->unk66 = (u16)0;
    func_1507F640();
}

void func_15072A40(void) {
    gCurrentObject->unk31C->unk19B = (u8)0;
    gCurrentObject->unk31C->unk78 = (u8)0;
    func_1507F640();
}

void func_15072A7C(void) {
    if (gCurrentObject->unk31C != 0) {
        gCurrentObject->unk31C->unk1A9++;
        if ((random_u32() & 7) < (u32) gCurrentObject->unk31C->unk1A9) {
            func_1505E650(gCurrentObject, 394, 1.0f, 4.0f, 0.0f, 0.0f, 0);
        }
    }
}

void func_15072AF8(void) {
    func_1505E650(gCurrentObject, (u16) (gCurrentObject->unk84.uh + 1), 1.0f, 6.0f, 0.0f, 0.0f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15072B44.s")
void func_15072DA0(void) {
    gCurrentObject->unk2F8 &= 0xFFF8;
    gCurrentObject->unk2F8 |= D_800D1580;
}

void func_15072DD8(void) {
    func_15083568(gCurrentObject, D_800D1580, 0x3F800000, 0);

    if ((gCurrentObject->unk31C != 0) && (gCurrentObject->unk31C->unk11A == 1)) {
        gCurrentObject->unk31C->unk11A = (u8)2U;
    }
}

void func_15072E38(void) {
    func_150836CC(gCurrentObject, D_800D1580);

    if (gCurrentObject->unk31C != 0) {
        gCurrentObject->unk31C->unk11A = (u8)0;
    }
}

void func_15072E7C(void) {
    gCurrentObject->unk10C = (s16) D_800D1580;
}

void func_15072E98(void) {
    gCurrentObject->unk2D0->unk10 *= D_800D1874;
}

void func_15072EC0(void) {
    struct197 *tmp;

    tmp = gCurrentObject->unk2D0;
    if (tmp->unk10 < D_800D1874) {
        gCurrentObject->unk10C = 0;
    }
}

void func_15072EF4(void) {
    gCurrentObject->stunned = (s8) D_800D1580;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15072F10.s")

void func_15073054(void) {
    gCurrentObject->unk22E = (s16) D_800D1580;
}

void func_15073070(void) {

}

void func_15073078(void) {
    func_1512D748(0, D_800D1580, 1);
}

void func_150730A4(void) {
    gCurrentObject->unk1FF = (u8)3;
    gCurrentObject->unk200 = (s8) D_800D1580;
}

void func_150730D0(void) {
    struct127 *temp_v0;

    if (D_800D1580 == 1) {
        temp_v0 = gCurrentObject;
        temp_v0->unk2F8 |= 0x100;
    } else {
        temp_v0 = gCurrentObject;
        temp_v0->unk2F8 &= 0xFEFF;
      }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15073118.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1507342C.s")

void func_150738E8(void) {
    u8 temp_v0 = (u8)(gCurrentObject->unk13C - 100);

    if (gCurrentObject->unk13C != 0) {
        gCurrentObject->unk13C = 0U;
        gObjects[temp_v0].unkF8 = 0x8200;
        gObjects[temp_v0].unk13D = 0;
        gObjects[temp_v0].unk76 = gCurrentObject->unk7A;
        gObjects[temp_v0].unk65 = 0;
        gObjects[temp_v0].unk232 = 6;
        gObjects[temp_v0].unk218 = 0;
        gObjects[temp_v0].stunned = 0;
        gObjects[temp_v0].unk7A = 0xE000;
        func_1505E650(gCurrentObject, 0x97, 1.0f, 5.0f, 0.0f, 0.0f, 0);
    }
}

void func_150739A4(void) {
    gCurrentObject->unk64 = (s8) D_800D1580;
}

void func_150739C0(void) {
    gCurrentObject->unk64 -= D_800BE9A0;

    if (gCurrentObject->unk64 >= 0) {
        D_800D1880 = 0;
        gCurrentObject->unk138--;
        D_800D1878 = D_800D1580;
    }
}

void func_15073A28(void) {
    gCurrentObject->unk44 = (f32) D_800D1580;
}

// NON-MATCHING: sets gCurrentObject's owned gObjects slot (indexed by
// unk124) up for a "target switch" - clears state, relays through
// func_1505D024, sets a default unk1CC then conditionally overwrites
// it from gCurrentObject's own y_position, marks immune=20, and
// advances the facing angle into unk76.
// void func_15073A50(void) {
//     struct127 *obj;
//     s32 raw;
//
//     obj = &gObjects[gCurrentObject->unk124];
//
//     if (obj->unk65 != 0) {
//         gCurrentObject->unk13C = 0;
//         obj->immune = 0;
//
//         raw = D_800D1580;
//         func_1505D024(obj, *(volatile s32 *) &D_800D1580 & 0xFF00FF, 0, gCurrentObjectIndex);
//
//         obj->unk1CC = D_8009A0D8;
//         if (raw * 2 < 0) {
//             obj->unk1CC = gCurrentObject->y_position;
//         }
//
//         obj->immune = 20;
//         obj->unk76 = gCurrentObject->unk7A + raw;
//     }
// }
// 58 vs target's 58 instructions - exact count match. Getting here
// needed two fixes to the naive translation: forcing D_800D1580's
// genuine double-read (target loads it twice back-to-back, once
// unmasked for later reuse, once for the masked call argument) via a
// volatile access on the second reference, and writing the unk1CC
// assignment as an unconditional default followed by a conditional
// overwrite rather than a clean if/else - target's own compiled form
// unconditionally stores the D_8009A0D8 constant in the branch's
// delay slot regardless of outcome, then conditionally overwrites it,
// which only a literal "default then override" source shape
// reproduces. Remaining gap is consistent register renaming plus an
// 8-byte stack-frame size difference.
void func_15073A50(void) {
    u8 idx;
    s32 raw;

    idx = gCurrentObject->unk124;
    if (gObjects[idx].unk65 != 0) {
        raw = D_800D1580;
        gCurrentObject->unk13C = 0;
        gObjects[idx].immune = 0;
        func_1505D024(&gObjects[idx], D_800D1580 & 0xFF00FF, 0, gCurrentObjectIndex);
        gObjects[idx].unk1CC = D_8009A0D8;
        if (raw * 2 < 0) {
            gObjects[idx].unk1CC = gCurrentObject->y_position;
        }
        gObjects[idx].immune = 20;
        gObjects[idx].unk76 = gCurrentObject->unk7A + raw;
    }
}
struct func_15073B38_s {
    u8 pad0[0xA8];
    f32 unkA8;
    u8 unkAC;
    u8 unkAD;
};

void func_15073B38(void) {
    f32 a;
    f32 b;
    a = D_800D1580 & 0xFFFF;
    ((struct func_15073B38_s *) gCurrentObject->unk31C)->unkA8 = a;
    b = (D_800D1580 >> 16) & 0xFF;
    ((struct func_15073B38_s *) gCurrentObject->unk31C)->unkAC = b;
    ((struct func_15073B38_s *) gCurrentObject->unk31C)->unkAD = (D_800D1580 >> 24) & 0xFF;
}

void func_15073C28(void) {
    func_1507F640();
}

void func_15073C48(void) {

}

// ???
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Adds
// D_800CC2E8[gCurrentObject->unk222] (stride 812, like the
// gObjects-indexing pattern elsewhere) to (f32)D_800D1580, truncates,
// stores to gCurrentObject->unk224. Register allocation differs
// substantially from target throughout.
void func_15073C50(void) {
    gCurrentObject->unk224 = (s16)(*(f32 *)((u8 *)D_800CC2E8 + gCurrentObject->unk222 * 812) + (f32)D_800D1580);
}
// void func_15073C50(void) {
//     u8 idx = *((u8 *) gCurrentObject + 0x222);
//     f32 val = *(f32 *) ((char *) D_800CC2E8 + idx * 812) + (f32) D_800D1580;
//
//     *(s16 *) ((char *) gCurrentObject + 0x224) = (s32) val;
// }

void func_15073CB8(void) {
    struct127 *tmp = func_1505F0AC(0x53);
    if ((tmp != 0) && ((u16)tmp->unk244 == 0x1F)) {
        tmp->unk21C = (u16)0;
    }
}

void func_15073CF4(void) {
    func_15062B1C(gCurrentObject, (f32) D_800D1580);
}


void func_15073D34(void) {
    func_15062B50(gCurrentObject, (f32) D_800D1580);
}

void func_15073D74(void) {
    struct127 *temp_v0;

    temp_v0 = func_15083E90(D_800D1583);
    if (temp_v0 != 0) {
        temp_v0->unk65 = (u8)0;
    }
}

void func_15073DA4(void) {
    s32 tmp;

    if (D_800D1580 != 0) {
        tmp = 18;
    } else {
        tmp = 2;
    }
    func_1506C460(gCurrentObject->unk40, 150.0f, 0.0f, 0.0f, 100, tmp, 60.0f, 0.5f, 0, 0, 1);
}

void func_15073E2C(void) {
    func_1506C460(gCurrentObject->unk40, 80.0f, 0.0f, 0.0f, 100, 11, 40.0f, 0.5f, 0, 14, 1);
}

void func_15073EA4(void) {
    func_1506C460(gCurrentObject->unk40, 60.0f, 0.0f, 0.0f, 100, 12, 40.0f, 0.5f, 0, 14, 1);
}

void func_15073F1C(void) {
    struct126 *temp_v0 = func_1503195C(gCurrentObject, 0x3C, 0);
    if (temp_v0 != NULL) {
        temp_v0->unk38 = 0x960;
    }
}

void func_15073F54(void) {
}

void func_15073F5C(void) {
    gCurrentObject->unk2CB = (s8) D_800D1580;
}

void func_15073F78(void) {
    gCurrentObject->unk10B &= ~D_800D1580;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15073FA0.s")

void func_15074644(void) {
    gCurrentObject->unk31C->unk11A = (s8) D_800D1580;
}

// NON-MATCHING: full semantics recovered and verified via isolated
// harness. Sibling of func_15074644 above (same gCurrentObject->unk31C
// struct126* access) - updates that sub-object's unk94 byte field
// (declared s8 in structs.h, but read/written via u8 casts here since
// target's lbu/sb sequence zero-extends, matching this codebase's
// convention of trusting the actual load width over the struct's
// declared signedness when they disagree). If D_800D1580==1, always
// notifies via func_10011FDC(5) and sets unk94 = D_800D1580.
// Otherwise, compares the CURRENT unk94 against 1: sets unk94 =
// D_800D1580 unconditionally, and only if the byte used to be 1, also
// notifies via func_10011FDC(0) and re-derives sub/unk94 = D_800D1580
// again afterward (both call sites use gCurrentObject->unk31C and
// D_800D1580 re-read fresh post-call, matching this codebase's usual
// "don't trust values across an opaque call" pattern).
// 36 vs target's 35 instructions - every operation, field offset, and
// even the provably-dead duplicate `lbu` (a branch-likely scheduling
// artifact matching the pattern documented elsewhere this project)
// reproduce exactly, once the two branches' final byte-writes were
// restructured to share ONE write statement at the end (mirroring
// target's own shared merge point) instead of each branch writing
// independently. The one remaining gap: target merges the epilogue's
// $ra reload for the "byteVal != 1" early-exit with the main
// post-write exit (both land on the same reload), while this
// reconstruction's early `return;` for that case gets its own
// separate reload - a genuine three-vs-two-exit-point difference that
// didn't resolve with the forms tried.
// void func_15074664(void) {
//     struct126 *sub;
//     s32 flag;
//     u8 byteVal;
//     s32 newVal;
//
//     sub = gCurrentObject->unk31C;
//     if (sub == 0) {
//         return;
//     }
//
//     flag = D_800D1580;
//     if (flag == 1) {
//         func_10011FDC(5);
//         sub = gCurrentObject->unk31C;
//         newVal = D_800D1580;
//     } else {
//         byteVal = *((u8 *) sub + 0x94);
//         *((u8 *) sub + 0x94) = (u8) flag;
//         if (byteVal != 1) {
//             return;
//         }
//         func_10011FDC(0);
//         sub = gCurrentObject->unk31C;
//         newVal = D_800D1580;
//     }
//     *((u8 *) sub + 0x94) = (u8) newVal;
// }
void func_15074664(void) {
    if (gCurrentObject->unk31C != NULL) {
        if (D_800D1580 == 1) {
            func_10011FDC(5);
        } else if ((u8)gCurrentObject->unk31C->unk94 == 1) {
            func_10011FDC(0);
        }
        gCurrentObject->unk31C->unk94 = D_800D1580;
    }
}
s32 func_1517F488(s32, s32, s32, s32, s32, s32); /* extern */

void func_150746F0(void) {
    struct127 *obj;

    obj = NULL;
    if (D_800BE616 != 0) {
        obj = gCurrentObject;
    } else if (gCurrentObject->unk13C != 0) {
        obj = gObjects;
    }
    if (obj != NULL) {
        if (obj->health <= D_800D1580) {
            obj->health = 0;
            gCurrentObject->health = 0;
            if (obj->interaction_state == 1) {
                obj->immune = 0xFF;
                func_1507CD64(obj, 6);
            }
        } else {
            obj->health -= D_800D1580;
            if (obj->unk31C != NULL && obj->camera != NULL && obj->unk31C->pad196[1] != 0) {
                func_1517F488(0xFF, 0, 0, 0xB4, 0x14, obj->camera->unk23D);
            }
        }
    }
}
// ?
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Zeroes
// gObjects[gCurrentObject->unk65 - 1].unk218 and sets its unk232 to the
// low byte of D_800D1580, gated on unk65 != 0. Register allocation and
// instruction ordering differ substantially from target throughout.
void func_150747E4(void) {
    s32 idx;
    struct127 *obj;

    if ((idx = gCurrentObject->unk65) != 0) {
        obj = &gObjects[--idx];
        obj->unk232 = D_800D1580;
        obj->unk218 = NULL;
    }
}
// void func_150747E4(void) {
//     u8 idx;
//     struct127 *obj;
//
//     if (gCurrentObject->unk65 != 0) {
//         idx = gCurrentObject->unk65 - 1;
//         obj = &gObjects[idx];
//         *(s32 *) ((char *) obj + 0x218) = 0;
//         *(u8 *) ((char *) obj + 0x232) = D_800D1580;
//     }
// }

void func_15074840(void) {
    if (gCurrentObject->unk31C != 0) {
        gCurrentObject->unk31C->unk1AA += D_800D1580;
    }
}

void func_15074870(void) {
    gCurrentObject->unk24F = (s8) D_800D1580;
}

// ??
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Looks up a bit
// flag from an array at gCurrentObject+0x2E4 (indexed by a byte of the
// packed D_800D1580 color) XORed with another packed bit, and if set,
// adjusts gCurrentObject->unk138 by the packed color's high byte.
// Register allocation differs substantially from target throughout.
void func_1507488C(void) {
    u8 b2 = D_800D1580 >> 16;
    u8 b1 = D_800D1580 >> 8;
    u8 flag = D_800D1580 & 1;

    if ((&gCurrentObject->unk2E4)[b2] & b1) {
        flag ^= 1;
    }
    if (flag) {
        gCurrentObject->unk138 += (u8)(D_800D1580 >> 24);
    }
}
// void func_1507488C(void) {
//     s32 packed = D_800D1580;
//     u8 byte2 = packed >> 16;
//     u8 byte1 = packed >> 8;
//     s32 bit0 = packed & 1;
//     s32 flag;
//     s32 arrElem = *(s32 *) ((char *) gCurrentObject + 0x2E4 + byte2 * 4);
//
//     if ((arrElem & byte1) != 0) {
//         flag = !bit0;
//     } else {
//         flag = bit0;
//     }
//     if (flag) {
//         *((u8 *) gCurrentObject + 0x138) += (s8) (packed >> 24);
//     }
// }

void func_150748F4(void) {
    D_800CC3D7 = (s8) D_800D1580;
}

void func_1507490C(void) {
    struct127 *tmp;
    u8 temp_v0 = (u8)(gCurrentObject->unk13C - 100);

    if (gCurrentObject->unk13C != 0) {
        tmp = &gObjects[temp_v0 & 0xFF];
        if (gObjects[temp_v0].unk13D >= 0x64) {
            gObjects[temp_v0].unk232 = D_800D1580;
            gObjects[temp_v0].unk218 = 0;
            gObjects[temp_v0].stunned = 0;
        }
    }
}

void func_15074980(void) {
    s32 i;
    f32 threshold;
    struct126 *sub;

    threshold = (f32) (D_800D1580 * 8);
    if (D_8008FD8C > 0) {
        i = 0;
        do {
            if (func_1505A72C(gCurrentObject, &gObjects[i]) < threshold) {
                sub = gObjects[i].unk31C;
                if (sub != 0) {
                    sub->chasing = 0x14;
                }
            }
            i++;
        } while (i < D_8008FD8C);
    }
}

void func_15074A44(void) {
    if (gCurrentObject->unk31C != 0) {
        gCurrentObject->unk31C->unk26 = (s8) D_800D1580;
    }
}

void func_15074A6C(void) {
    if (gCurrentObject->unk13C == 0) {
        gCurrentObject->unk138++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_15074A94.s")
// NON-MATCHING: JUSTREG
// void func_15074A94(void) {
//     f32 phi_f2;
//     f32 temp_f0;
//
//     temp_f0 = func_1505A72C(&gObjects, gCurrentObject);
//
//     if (gCurrentObject->unk148 < D_8009A0E8) {
//         gCurrentObject->unk148 = gCurrentObject->unk154;
//     }
//
//     if (temp_f0 < 200.0f) {
//         phi_f2 = D_8009A0EC;
//     } else {
//         if (D_8009A0F0 < temp_f0) {
//             phi_f2 = gCurrentObject->unk148;
//         } else {
//             f32 tmp = D_8009A0F4;
//             phi_f2 = gCurrentObject->unk148;
//             phi_f2 = phi_f2 - tmp;
//             phi_f2 = phi_f2 * ((temp_f0 - 200.0f) / D_8009A0F8);
//             phi_f2 = phi_f2 + tmp;
//         }
//     }
//     gCurrentObject->unk154 = gCurrentObject->unk158 = phi_f2;
//     gCurrentObject->unk15C = D_8009A0FC;
// }

void func_15074B7C(void) {
    D_800D1880 = 0;
    D_800D1878 = D_800D1580;

    if (D_800D1580 == 0) {
        D_800D1878 = D_8009A100;
        gCurrentObject->unk1FC |= 4;
        gCurrentObject->unk138 = 0;
    }
}

void func_15074BD8(s32 arg0, s32 arg1, s32 arg2) {
}

void func_15074BEC(s32 arg0, s32 arg1, s32 arg2) {
}

void func_15074C00(s32 arg0, struct127 *arg1, s32 arg2) {
    struct199 tmp; // is this actually 2 structs?

    if (((u8)arg1->unk239 & 0x7F) == 5) {
        func_1504715C(&tmp);
        tmp.unk24 = D_800CC2C0;
        tmp.unk28 = D_800CC2C4;
        tmp.unk2C = D_800CC2C8;
        func_150C04C0(&tmp.unk24, &tmp, 0x16, 1, 0xFF, 0);
    }
}

struct func_15074C80_s {
    s32 unk0;
    u8 pad4[0x10];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 pad24[0x18];
    f32 unk3C;
    u8 pad40[0x36];
    u16 unk76;
    u8 pad78[0x152];
    u8 unk1CA;
    u8 pad1CB[0xAD];
    u16 unk278;
};
s32 func_150335C8(void *, void *, s32, s32, s32, s32);
void func_15166118(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_151942E8(void *, void *);
extern f32 D_8009A104;

void func_15074C80(struct func_15074C80_s *arg0, struct func_15074C80_s *arg1) {
    s32 var_a2;

    if (arg0->unk278 == 0x11) {
        func_151942E8(arg0, arg1);
    }
    if (arg0->unk278 == 2 || arg0->unk278 == 0x12 || arg0->unk278 == 3 || arg0->unk278 == 6) {
        if (arg1->unk1CA == 0) {
            if (arg0->unk278 == 2) {
                var_a2 = 0x2A;
            } else if (arg0->unk278 == 0x12) {
                var_a2 = 0x2F;
            } else if (arg0->unk278 == 3) {
                var_a2 = 0x39;
            } else {
                var_a2 = 0x51;
            }
            func_150335C8(arg0, arg1, var_a2, 0xC, 1, 0);
        }
        arg0->unk1CA = 0;
    }
    if (arg1->unk0 == 0x19) {
        func_15166118((s32)(256.0f - (func_150484A0(arg0->unk20, arg0->unk3C) * D_8009A104)), 0xC0 - (arg0->unk76 >> 8), (s32)arg0->unk14, (s32)arg0->unk18, (s32)arg0->unk1C, 0x10, 0x14, 0, 0xFF, 0);
    }
}

void func_15074DEC(struct127 *arg0, s32 arg1, s32 arg2) {
    arg0->unk2E8 = 1;
}

// original name recovered from a debug string it passes to func_1518D1C0
void mvmt_imp_set_up_smoke_15074E04(s32 arg0, s32 arg1, s32 arg2) {
    func_1516FE1C((s32) (arg1 - (s32)&gObjects) / (s32) sizeof(struct127), 0xB4, 0xFF, 0);
    func_1518D1C0(arg1, 0xB, 0, 1, 0xFF, 0, &D_80099C1C);
}

void func_15074E80(struct127 *arg0, struct127 *arg1, s32 arg2) {
    s8 sp1F = 0;
    func_15194794(arg0, arg1, &sp1F);
    if (arg1->interaction_state == 1) {
        arg0->immune = (u8)0xFF;
        arg1->immune = (u8)0xC8;
        D_800D1580 = 0x60000; // 393216
        func_15072740();
    }
}

void func_15074EE8(struct127 *arg0, struct127 *arg1, s32 arg2) {
    if (arg1->interaction_state == 1) {
        arg0->immune = (u8)0xFF;
        arg1->immune = (u8)0xC8;
        D_800D1580 = 0x70000;
        func_15072740();
    }
}

void func_15074F30(struct127 *arg0, struct127 *arg1, s32 arg2) {
    arg0->unk232 = arg1->unk109;
    arg0->unk218 = 0;
}

void func_15074F48(struct127 *arg0, struct127 *arg1, s32 arg2) {
    f32 dx = D_8009A108 - arg0->x_position;
    f32 dz = arg0->z_position - D_8009A10C;

    arg1->unk76 = func_1505A630(dx, dz, 0);
    arg1->xz_velocity = sqrtf(dx * dx + dz * dz) * D_8009A110;
    func_15194408(arg0, arg1);
}

void func_15074FD4(struct127 *arg0, struct127 *arg1, s32 arg2) {
    if (arg1->interaction_state == 1) {
        arg0->immune = (u8)0xFF;
        arg1->immune = (u8)0xC8;
        D_800D1580 = 0x60000;
        if (arg0->id == 0x8E) {
            D_800D1580 = 0x140000;
        }
        func_15072740();
    }
    func_151942B0(arg0, arg1, arg2);
}

void func_15075050(struct127 *arg0, s32 arg1, s32 arg2) {
    arg0->unkB8 = 5.0f;
    if (arg0->xz_velocity > 0.0f) {
        arg0->unkB8 = -5.0f;
    }
    arg0->gravity = 5.0f;
    arg0->y_velocity = 12.0f;
}

void func_150750A4(struct127 *arg0, s32 arg1, s32 arg2) {
    arg0->gravity = 5.0f;
}

void func_150750C4(struct127 *arg0, struct127 *arg1, u8 *arg2) {

    if ((arg1->id  == 0x88) && ((s32) arg0->unk107 < 0x37)) {
        arg0->unk138 += 3;
    }
    func_15194794(arg0, arg1, arg2);
    if (arg1->id != 0x53) {
        func_15145A50(arg1);
        arg1->health = (u8)0;
        func_1507CD64(arg1, 8);
        *arg2 = (u8)39;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_981E0/func_1507515C.s")
