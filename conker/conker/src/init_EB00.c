#include <ultra64.h>

#include "functions.h"
#include "variables.h"


s32 func_1000EB00(struct04 *arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 arg6, s32 arg7, u16 *arg8) {
    if (arg0->unk24 != 0) {
        arg0->unk24 = 0;
    }
    *arg3 = 64;
    if (D_800CC37D || (*arg2 == 0)) {
        *arg2 = 0;
        *arg8 = 0;
        return 0;
    }
    arg0->unk18 -= D_800BE9E4;
    if (arg0->unk18 > 0) {
        *arg2 = 0;
        *arg8 = 0;
    } else {
        arg0->unk18 = (random_u32() & 0x7F) + 0x80;
        arg0->unk0 = (random_u32() % 3U) + 0x6C;
    }
    return 0;
}

s32 func_1000EBC4(struct00 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0 = arg0->unkC;
    s32 temp_v1 = arg0->unk18;
    temp_v1 -= D_800BE9E4;

    if (temp_v1 <= 0) {
        temp_v0 = temp_v0 - D_800BE9E4 * 1000;
        if (temp_v0 < 0) {
            return 1;
        }
        arg0->unkC = temp_v0;
    }
    arg0->unk18 = temp_v1;
    return 0;
}

s32 func_1000EC24(struct251 *arg0, s32 arg1, s32 *arg2, struct11 *arg3, struct04 *arg4, s32 *arg5, u16 *arg6) {
    s16 temp_v1 = arg0->unk18.h[1];

    if (*arg6 != 0) {
        arg0->unk1C = *arg6;
        arg0->unk0 = 0;
        *arg6 = 0;
    }

    temp_v1 -= D_800BE9E4;

    if (temp_v1 <= 0) {
        if (*arg2 != 0) {
            func_10010F30(arg0->unk1C, *arg2, arg3->unk3, arg4->unk2, *arg5);
        }
        return 1;
    }
    arg0->unk18.w = temp_v1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_1000ECCC.s")
// ? func_1000ECCC(void *arg0, void * arg1, void * arg2, void * arg3, void *arg6) {
//     s16 temp_a1;
//     s32 temp_t4;
//     s32 temp_v1;
//     u16 temp_v0;
//
//     temp_v1 = arg0->unk18;
//     temp_v0 = *arg6;
//     if (temp_v0 != 0) {
//         arg0->unk18 = (s32) ((temp_v0 << 0x10) | (temp_v1 & 0xFFFF));
//         arg0->unk0 = (u16)0;
//         *arg6 = (u16)0U;
//     }
//     temp_a1 = (s16) temp_v1 - *(void *)0x800BE9E4;
//     if ((s32) temp_a1 <= 0) {
//         temp_t4 = arg0->unk18 >> 0x10;
//         *arg6 = (u16) temp_t4;
//         arg0->unk0 = (s16) temp_t4;
//         if (func_10010894(arg0->unk1C, temp_a1, arg6) == 0) {
//             func_10010344(*arg6, arg0->unk1C, arg0->unkC, arg0->unkA, (s32) arg0->unk8);
//         }
//         return 1;
//     }
//     arg0->unk18 = (s32) ((arg0->unk18 & 0xFFFF0000) | temp_a1);
//     return 0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_1000EDA0.s")
struct func_1000EE70_s {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[0x10];
    struct127 *unk18;
    s32 unk1C;
    u8 pad20[4];
    u16 unk24;
};

s32 func_1000EE70(struct func_1000EE70_s *arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 *arg5) {
    struct127 *temp_v1 = arg0->unk18;
    if ((temp_v1 != NULL) && (*arg2 != 0)) {
        u8 id = arg0->unk1C & 0xFF;
        if ((temp_v1->interaction_state != 0) && (id == temp_v1->unique_id)) {
            *arg5 = (((u32)temp_v1->unk184 >> 3) & 0x30) * 2;
            arg0->unk2 = temp_v1->x_position;
            arg0->unk4 = temp_v1->y_position;
            arg0->unk6 = temp_v1->z_position;
            return 0;
        }
        if (func_1000F44C(arg0->unk24) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 func_1000EF40(struct57 *arg0, struct57 *arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, u16 *arg6) {
    if (arg0->unk10 & 0x80) {
        arg0->unk10 = (s32) (arg0->unk10 & -0x81);
    }
    if (*arg2 == 0) {
        if (arg0->unk24 != 0) {
            func_100111C8(arg0->unk24);
            arg0->unk24 = 0;
        }
        *arg6 = 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_1000EFB4.s")
void func_1000F1A8(void) {
    s32 i;

    D_80042760 = 0;
    D_80041FD9 = 1;
    D_80041FD8 = 0;
    bzero(D_800425E0, 0x180);
    for (i = 0; i < 16; i++) {
        D_800425E0[i].unk2 = i + 0x10;
    }
    D_80041F50 = 0;
    func_100176EC();
    D_80041F60 = D_80041F61 = 0;
}

void func_10017780(u8 arg0, u16 arg1);
s32* allocate_memory(s32, s32, s32, s32);
void func_1000F248(s32 arg0) {
    u16 tmp;

    func_1000F1A8();
    if (arg0 == 4) {
        D_80041F54 = 0;
        D_80041F58 = D_8002C3F8; // 0.009999999776482582
    } else {
        D_80041F54 = 23000;
        D_80041F58 = D_8002C3FC; // 0.10000000149011612
    }

    if (arg0 == 0x35) {
        D_80041FD9 = 0;
    } else if (arg0 == 0x36) {
        D_80041FD9 = 0;
    } else if (arg0 == 0x3C) {
        D_80041FD9 = 0;
        D_80041FD8 = 0x3C;
    } else if (arg0 == 0x27) {
        D_80041FD9 = 0;
        D_80041FD8 = 0x28;
    } else if ((arg0 == 0x3A) || (arg0 == 0x40)) {
        D_80041FD9 = 0;
        D_80041FD8 = 0x3C;
    }

    D_80041F5C = allocate_memory(1762, 1, 0, 0);

    bzero(D_80041F5C, 1762);

    if (arg0 == 0x31) {
        D_80041FDC = 14000;
    } else {
        D_80041FDC = 23000;
    }
    func_10011E88(arg0);
    D_80041F60 = D_80041F61 = 0;
    func_10017780(0, D_80041F56);
    func_10017780(1, D_80041F56);
    func_10017780(2, 23000);
    // fakematch
    if (arg0) {}
}

s32 func_1000F3D0( u16 arg0) {
    struct120 *temp_v1;

    temp_v1 = &D_800425E0[arg0 & 0xF];
    if (temp_v1->unk8 != 0) {
        if ((temp_v1->unk0 == arg0) || (arg0 == (arg0 & 0xF))) {
            if (func_100173C4(&temp_v1->unk8) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_1000F44C( u16 arg0) {
    u32 mask;
    struct120 *temp_a1;
    struct31 *temp_a2;

    mask = __osDisableInt();
    temp_a1 = &D_800425E0[arg0 & 0xF];
    temp_a2 = temp_a1->unk8;
    if ((temp_a2 != 0) && (temp_a1->unk0 == arg0) && ((temp_a2->unk53 & 2) != 0)) {
        __osRestoreInt(mask);
        return 1;
    }
    __osRestoreInt(mask);
    return 0;
}

s32 func_1000F4D8(u16 arg0) {
    s32 i;

    arg0 &= 0x7FFF;
    for (i = 0; i < 16; i++) {
        if ((D_800425E0[i].unk8 != 0) && ((D_800425E0[i].unk4 & 0x7FFF) == arg0) && (func_100173C4(&D_800425E0[i].unk8) != 0)) {
            return 1;
        }
    }
    return 0;
}
s32 func_1000F568(s32 arg0, s32 arg1) {
    s32 rem;
    s32 idx;
    u8 *p;
    s32 mask;
    u8 val;
    u8 val2;

    rem = (u32)func_150ADA20() % arg1;
    idx = rem;
    if (arg0 >= 0x6E2) {
        return 1;
    }
    if (arg1 < 2) {
        return arg0;
    }
    p = (u8 *)D_80041F5C + arg0;
    if (D_80041F5C != NULL) {
        val = *p;
        if (arg1 < 8) {
            if (!(val & 0x80) || (mask = (1 << arg1) - 1, !(val & mask))) {
                mask = (1 << arg1) - 1;
                val = 0xFF;
            }
            while (!(val & (1 << idx))) {
                idx = (idx + 1) % arg1;
            }
            val2 = val ^ (1 << idx);
            *p = val2;
            if (!(val2 & mask)) {
                ((u8 *)D_80041F5C)[arg0] = val ^ mask;
            }
        } else {
            *p = rem + 1;
        }
    }
    return arg0 + idx;
}
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_1000F6B8.s")
void func_1000F85C(u16 arg0, s16 arg1, s32 arg2) {
    if (arg0 >= 16) {
        if (func_1000F3D0(arg0) != 0) {
            if (arg1 == 16) {
                f32 sp1C = alCents2Ratio(arg2);
                arg2 = *(s32 *)&sp1C;
            } else if (arg1 == 17) {
                arg1 = 16;
            }
            func_10017714(D_800425E0[arg0 & 0xF].unk8, arg1, arg2);
        }
    }
}
// NON-MATCHING: not even close
// void func_1000F85C(s32 arg0, s16 arg1, s32 arg2) {
//     f32 sp1C;
//     s32 sp18;
//     s16 temp_a1;
//     s16 temp_a1_2;
//     s32 temp_t6;
//     s16 phi_a1;
//
//     temp_t6 = arg0 & 0xFFFF;
//     temp_a1 = arg1;
//     if (temp_t6 >= 16) {
//         sp18 = temp_t6;
//         arg1 = temp_a1;
//         temp_a1_2 = arg1;
//         if (func_1000F3D0(temp_t6) != 0) {
//             if (temp_a1_2 == 16) {
//                 sp18 = sp18;
//                 arg1 = temp_a1_2;
//                 sp1C = alCents2Ratio(arg2, temp_a1_2);
//                 arg2 = (s32) sp1C;
//                 phi_a1 = arg1;
//             } else {
//                 phi_a1 = temp_a1_2;
//                 if (temp_a1_2 == 0x11) {
//                     phi_a1 = (u16)0x10;
//                 }
//             }
//             func_10017714((((sp18 & 0xF) * 0xC) + 0x80040000) - 0x25E8, phi_a1, arg2);
//         }
//     }
// }

void func_1000F91C(u16 arg0, u16 arg1, s16 arg2, u8 arg3, s32 arg4,
                   s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    s32 sp2C;
    u32 volume;

    volume = func_1000F6B8(arg4, arg5, arg6, arg7, &sp2C, (s32) arg8, (s32) arg9);
    func_1000F85C(arg0, 8, (arg1 * volume) >> 0xF);
    func_1000F85C(arg0, 4, sp2C & 0x7F);
    func_1000F85C(arg0, 256, (sp2C & 0x80) | arg3);
    func_1000F85C(arg0, 16, arg2);
}

void func_1000F9D4( u16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u32 tmp;

    func_1000F6B8(-1, arg1, arg2, arg3, &tmp, 32760, 32765);
    func_1000F85C(arg0, 4, tmp & 0x7F);
    func_1000F85C(arg0, 256, tmp & 0x80);
}

#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_1000FA64.s")
struct func_1000FC18_s {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    u8 pad[0x6];
    s32 unk10;
    u8 pad2[0x10];
    u16 unk24;
    u8 pad3[0xA];
};

void func_1000FC18(u16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    s32 i;

    for (i = 0; i < D_80042760; i++) {
        if ((arg0 == ((struct func_1000FC18_s *)D_80041FE0)[i].unk0) &&
            (arg1 == ((struct func_1000FC18_s *)D_80041FE0)[i].unk2) &&
            (arg2 == ((struct func_1000FC18_s *)D_80041FE0)[i].unk4) &&
            (arg3 == ((struct func_1000FC18_s *)D_80041FE0)[i].unk6) &&
            (arg4 == (((struct func_1000FC18_s *)D_80041FE0)[i].unk8 & 0x7FFF))) {
            if (((struct func_1000FC18_s *)D_80041FE0)[i].unk24 != 0) {
                func_100111C8(((struct func_1000FC18_s *)D_80041FE0)[i].unk24);
            }
            ((struct func_1000FC18_s *)D_80041FE0)[i].unk10 |= 0x80;
        }
    }
}
// Stops the sounds placed at a point: for each of the first D_80042760 entries of
// D_80041FE0 whose position (unk14, unk18, unk1C) is (x, y, z), stops the sound it
// is playing (handle unk24, see func_100111C8) and sets its flag 0x80.
void func_1000FD38(s32 x, s32 y, s32 z) {
    s32 i;

    for (i = 0; i < D_80042760; i++) {
        if ((x == D_80041FE0[i].unk14) && (y == D_80041FE0[i].unk18) && (z == D_80041FE0[i].unk1C)) {
            if (D_80041FE0[i].unk24 != 0) {
                func_100111C8(D_80041FE0[i].unk24);
            }
            D_80041FE0[i].unk10 |= 0x80;
        }
    }
}

void func_1000FDF4(u16 arg0) {
    s32 i;

    for (i = 0; i < D_80042760; i++) {
        if (arg0 == D_80041FE0[i].unk24) {
            if (D_80041FE0[i].unk24) {
                func_100111C8(D_80041FE0[i].unk24);
            }
            D_80041FE0[i].unk10 = D_80041FE0[i].unk10 | 0x80;
        }
    }
}
// Stops the sound of entry `index` of an array of positional sound entries (the
// 0x30-byte entries of D_80041FE0; see func_1000FD38), and sets its flag 0x80, if
// the index is below *count. Returns 0 when it did, 1 when the index was out of
// range. Its caller, func_10011624, calls it for an entry when the entry's own
// callback returns non-zero.
s32 func_1000FE88(struct15 *entries, s32 index, s32 *count) {
    if (index < *count) {
        if (entries[index].unk24 != 0) {
            func_100111C8(entries[index].unk24);
        }
        entries[index].unk10 |= 0x80;
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_1000FEF0.s")
// NON-MATCHING: needs a re-work
// s32 func_1000FEF0(u16 arg0, struct127 *arg1, s32 arg2) {
//     s32 i;
//     struct15 *tmp;
//
//     if (arg0 == 0) {
//         // nothing
//     } else {
//         for (i = 0; i < D_80042760; i++) {
//             tmp = &D_80041FE0[i];
//             if ((arg0 == tmp->unk24) &&
//                 (arg1 == tmp->unk18) &&
//                 (arg2 == tmp->unk1C) &&
//                 ((tmp->unk10 & 0x80) == 0)) {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

s32 func_1000FF90(s32 arg0, void *arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < D_80042760; i++) {
        if ((arg0 == D_80041FE0[i].unk14) &&
            ((arg1 == (void *)D_80041FE0[i].unk18) || (arg1 == (void *)-1)) &&
            ((arg2 == D_80041FE0[i].unk1C) || (arg2 == -1)) &&
            ((D_80041FE0[i].unk10 & 0x80) == 0)) {
            return i;
        }
    }
    return -1;
}
void func_1001001C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;

    for (i = 0; i < D_80042760; i++) {
        if ((arg0 == D_80041FE0[i].unk14) && (arg1 == D_80041FE0[i].unk18) && (arg2 == D_80041FE0[i].unk1C)) {
            *(f32 *)&D_80041FE0[i].unk2C = alCents2Ratio(arg4);
            D_80041FE0[i].unkC = arg3;
        }
    }
}
void func_100100E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 i;

    for (i = 0; i < D_80042760; i++) {
        if ((arg0 == D_80041FE0[i].unk14) && (arg1 == D_80041FE0[i].unk18) && (arg2 == D_80041FE0[i].unk1C)) {
            D_80041FE0[i].unk14 = arg3;
            D_80041FE0[i].unk18 = arg4;
            D_80041FE0[i].unk1C = arg5;
        }
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10010154.s")
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10010344.s")
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10010558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10010630.s")
// void func_10010630(u16 arg0, struct127 *arg1, s32 arg2, s16 arg3, u16 arg4) {
//     if (arg1->interaction_state != 0) {
//         if (arg1->camera != 0) {
//             func_10010F30(arg0, arg2 & 0xFFFF, 64, 0, (((u32) arg1->unk184 >> 3) & 0x30) * 2); //
//         } else {
//             func_1000FA64(arg0, arg1->x_position, arg1->y_position, arg1->z_position, arg2, arg4, arg3, (void *)func_1000EE70, arg1, arg1->unique_id, 0, 0);
//         }
//     }
// }

void func_10010720( u16 arg0, struct127 *arg1, s32 arg2, s16 arg3, u16 arg4, s32 arg5) {
    if (arg5 <= 0) {
        func_10010630(arg0, arg1, arg2, arg3, arg4);
    } else {
        func_1000FA64(arg0, (s16) arg1->x_position, (s16) arg1->y_position, (s16) arg1->z_position, arg2, arg4, arg3, func_1000EDA0, arg5, arg1, 0, 0);
    }
}

s32 func_100107F8(struct127 *arg0) {
    if (arg0->interaction_state == 0) {
        return 0;
    } else {
        if (arg0->camera != 0) {
            if (arg0->unk8E != 0) {
                if (func_1000F3D0(arg0->unk8E) != 0) {
                    return 1;
                }
            }
        } else {
            if (func_1000FF90(func_1000EE70, arg0, arg0->unique_id | 0x10000) != -1) {
                return 1;
            }
        }
        arg0->unk8E = 0;
    }
    return 0;
}

s32 func_10010894(struct127 *arg0) {
    if (arg0->camera != 0) {
        if (arg0->unk8C != 0) {
            if (func_1000F3D0(arg0->unk8C) != 0) {
                return 1;
            }
        }
    } else {
        if (func_1000FF90(func_1000EE70, arg0, arg0->unique_id | 0x20000) != -1) {
            return 1;
        }
    }
    arg0->unk8C = 0;
    return 0;
}

void func_1001091C(struct127 *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 == 0) {
        return;
    }
    if (arg0->interaction_state == 0) {
        return;
    }
    if (arg0->camera != 0) {
        if (arg0->unk8E != 0) {
            func_1000F85C(arg0->unk8E, 8, arg1);
        }
    } else {
        temp_v0 = func_1000FF90(func_1000EE70, arg0, arg0->unique_id | 0x10000);
        if (temp_v0 != -1) {
            D_80041FEC[temp_v0][0] = arg1;
        } else {
            arg0->unk8E = 0;
        }
    }
}
// NON-MATCHING: something isnt right...
// void func_1001091C(struct127 *arg0, struct15 *arg1) {
//     s32 temp_v0;
//
//     if ((arg1 != NULL) && (arg0->unk0 != 0)) {
//         if (arg0->camera != 0) {
//             if (arg0->unk8E != 0) {
//                 func_1000F85C(arg0->unk8E, 8, arg1->unk1C); // help
//             }
//         } else {
//             temp_v0 = func_1000FF90(func_1000EE70, arg0, arg0->unique_id | 0x10000);
//             if (temp_v0 != -1) {
//                 D_80041FEC[temp_v0][0] = arg1;
//             } else {
//                 arg0->unk8E = 0;
//             }
//         }
//     }
// }

void func_100109D0(struct127 *arg0) {
    if (arg0->camera) {
        if (arg0->unk8E) {
            func_100111C8(arg0->unk8E);
        }
    } else {
        func_1000FD38(func_1000EE70, arg0, arg0->unique_id | 0x10000);
    }
    arg0->unk8E = 0;
}

void func_10010A3C(struct127 *arg0) {
    if (arg0->camera) {
        if (arg0->unk8C) {
            func_100111C8(arg0->unk8C);
        }
    } else {
        func_1000FD38(func_1000EE70, arg0, arg0->unique_id | 0x20000);
    }
    arg0->unk8C = 0;
}

void func_10010AA8(struct127 *arg0) {
    s32 sp24;
    struct15 *tmp;

    if (arg0->camera != 0) {
        if (arg0->unk8C && func_1000F44C(arg0->unk8C)) {
            func_100111C8(arg0->unk8C);
        }
        if (arg0->unk8E && func_1000F44C(arg0->unk8E)) {
            func_100111C8(arg0->unk8E);
        }
    } else {
        sp24 = func_1000FEF0(arg0->unk8C, arg0, arg0->unique_id);
        if (sp24 != -1) {
            if (func_1000F44C(arg0->unk8C)) {
                func_100111C8(arg0->unk8C);
            }
            tmp = &D_80041FE0[sp24];
            tmp->unk10 |= 0x80;
        }
        sp24 = func_1000FEF0(arg0->unk8E, arg0, arg0->unique_id);
        if (sp24 != -1) {
            if (func_1000F44C(arg0->unk8E)) {
                func_100111C8(arg0->unk8E);
            }
            tmp = &D_80041FE0[sp24];
            tmp->unk10 |= 0x80;
        }
    }
    arg0->unk8C = 0;
    arg0->unk8E = 0;
}

// Starts a sound effect: func_10010BE8(arg0, sound, volume, pan, pitch, flags, D_80041FD9)
// with volume 0..0x7FFF and pan 0..0x7F. The meaning of arg0 (0 from both wrappers
// below) and of D_80041FD9 isn't known yet. Returns a handle for the playing sound
// (see func_100111C8), or 0 when nothing played.
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10010BE8.s")

// Plays a sound effect at a point in the world. func_1000F6B8 turns the point and
// the two distances into an attenuation (full at `near` or closer, fading out to
// `far`) and a pan; the volume is scaled by the attenuation, and if nothing is left
// the sound isn't started and this returns 0. Otherwise it starts the sound with
// func_10010BE8, adding bit 7 of func_1000F6B8's pan result to `flags`.
// Arguments: (arg0, sound, volume, pitch, flags, listener, x, y, z, near, far), where
// listener is passed on to func_1000F6B8 as its first argument (func_1000F9D4 gives
// it -1).
s32 func_10010E78(s32 arg0, s32 sound, u16 volume, s16 pitch, s32 flags, s32 listener, s32 x, s32 y, s32 z,
                  s32 near, s32 far) {
    s32 pan;
    u32 vol;

    vol = func_1000F6B8(listener, x, y, z, &pan, (s16) near, (s16) far);
    vol = (volume * vol) >> 15;
    if (vol != 0) {
        return func_10010BE8((u16) arg0, sound, vol, pan & 0x7F, pitch, (pan & 0x80) | (u8) flags, D_80041FD9);
    }
    return 0;
}

// Plays a sound effect without a position: volume 0..0x7FFF, pan 0..0x7F (the
// middle is 0x40), pitch and flags as func_10010BE8 takes them.
s32 func_10010F30(s32 sound, u16 volume, u8 pan, s16 pitch, u8 flags) {
    return func_10010BE8(0, sound, volume, pan, pitch, flags, D_80041FD9);
}

s32 func_10010E78(s32, s32, u16, s16, s32, s32, s32, s32, s32, s32, s32); /* extern */

// Plays a sound effect at a point in the world (see func_10010E78): its volume is
// full within `near` of the listener and fades out to silence at `far`. For
// example func_15055A2C plays a random one of six sounds at 32700 with a random
// pitch offset of 0-499, near 100 or 1000 and far 3000.
s32 func_10010F88(s32 sound, u16 volume, s16 pitch, u8 flags, s32 listener, s16 x, s16 y, s16 z, s16 near,
                  s16 far) {
    return func_10010E78(0, sound, volume, pitch, (s32) flags, listener, (s32) x, (s32) y, (s32) z, (s32) near,
                         (s32) far);
}
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10010FFC.s")

// Stops a playing sound, given the handle func_10010BE8 returned for it. The
// handle's low 4 bits select one of the 16 sound slots at D_800425E0; the slot is
// only freed (its sound stopped with func_10017594) if it still holds this handle,
// so a handle whose sound has already ended, and whose slot was reused, does nothing.
void func_100111C8(u16 handle) {
    struct120 *slot = &D_800425E0[handle & 0xF];

    if ((slot->unk8 != 0) && (slot->unk0 == handle)) {
        slot->unk0 = 0;
        slot->unk4 = 0;
        func_10017594(slot->unk8);
        slot->unk8 = 0;
    }
}

void func_1001123C( u16 arg0) {
    struct120 *tmp = &D_800425E0[arg0 & 0xF];

    if ((tmp->unk8 != 0) && (tmp->unk0 == arg0)) {
        if (func_100112BC(arg0, 1) == 0) {
            func_10017594(tmp->unk8);
            tmp->unk8 = 0;
        }
    }
}

s32 func_100112BC(s32 arg0, s32 arg1) {
    struct49 *temp_a0;
    s32 temp_v1 = D_80041F50;

    if (temp_v1 < 16) {
        temp_a0 = &D_80041F10[temp_v1];
        temp_a0->unk0 = arg0;
        temp_a0->unk2 = arg1;
        temp_a0->unk3 = arg0 & 0xF;
        D_80041F50 = temp_v1 + 1;
        return 1;
    } else {
        return 0;
    }
}

struct func_10011310_s {
    u16 unk0;
    u8 unk2;
    u8 unk3;
};

void func_10011310(void) {
    s32 i;
    s32 j;
    s32 skip;
    s32 count;
    s32 idx;

    skip = 0;
    j = 0;
    count = D_80041F50;
    for (i = 0; i < (s32)D_80041F50; i++) {
        if (((struct func_10011310_s *)D_80041F10)[i].unk2 > 0) {
            ((struct func_10011310_s *)D_80041F10)[i].unk2--;
        } else {
            idx = ((struct func_10011310_s *)D_80041F10)[i].unk3;
            if (D_800425E0[idx].unk0 == ((struct func_10011310_s *)D_80041F10)[i].unk0) {
                D_800425E0[idx].unk0 = 0;
                D_800425E0[idx].unk4 = 0;
                if (D_800425E0[idx].unk8 != 0) {
                    func_10017594(D_800425E0[idx].unk8);
                }
                D_800425E0[idx].unk8 = 0;
            }
            count--;
            skip = 1;
        }
        if (j != i) {
            ((struct func_10011310_s *)D_80041F10)[j] = ((struct func_10011310_s *)D_80041F10)[i];
        }
        if (skip) {
            j++;
        } else {
            skip = 0;
        }
    }
    D_80041F50 = count;
}

s32 func_1001147C( u16 arg0) {
    struct120 *tmp;

    if (arg0 != 0) {
        tmp = &D_800425E0[arg0 & 0xF];
        if (tmp->unk0 == arg0) {
            return tmp->unk4 & 0x7FFF;
        }
    }
    return -1;
}

s32 func_1000A420(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32 *, s32);

void func_100114D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u32 *arg7, s32 arg8) {
    struct00 *best;
    struct00 *p;
    u32 d;
    u32 i;
    u32 bestd;
    s32 dz;
    s32 sp5C;
    s32 dx;
    s32 dy;

    best = D_80041F68;
    if (D_80082FA0 != 0) {
        bestd = -1U;
        for (i = 0; i <= (u32)D_80082FA0; i++) {
            dx = arg0 - D_80041F68[i].unkC;
            dy = arg1 - D_80041F68[i].unk10;
            dz = arg2 - D_80041F68[i].unk14;
            d = (dx * dx) + (dy * dy) + (dz * dz);
            if (d < bestd) {
                bestd = d;
                best = &D_80041F68[i];
            }
        }
    }
    func_1000A420(arg0 - best->unkC, arg1 - best->unk10, arg2 - best->unk14, best->unk18, arg0 - best->unk0, arg1 - best->unk4, arg2 - best->unk8, arg4, arg5, arg6, &sp5C, arg8);
    *arg7 = (u32) (sp5C * arg3) >> 0xF;
}
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10011624.s")
#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10011BB8.s")

void func_10011E88(s32 arg0) {
}

void func_10011E94(s32 arg0) {
    if (arg0) {
        D_80041F61 = 1;
    } else {
        D_80041F61 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/init_EB00/func_10011EB8.s")
// NON-MATCHING: whats going on here
// u16 func_10011EB8(s32 arg0, s16 *arg1, s32 arg2, s32 arg3) {
//     struct120 *temp_v1_2;
//     s32 temp_v0;
//     s32 temp_a0;
//
//     temp_v0 = func_1510F8CC(arg0);
//     if (arg1 != NULL) {
//         if (D_80082FA0 != 0) {
//             *arg1 = 0x7FFF / (D_80082FA0 + 1);
//         } else {
//             *arg1 = 0x7FFF;
//         }
//     }
//     temp_v1_2 = &D_8002C240[temp_v0 + arg2];
//     temp_a0 = temp_v1_2->unk0;
//     if (temp_v1_2->unk2 >= 2) {
//         temp_a0 = func_1000F568(temp_v0, temp_v1_2->unk2);
//     }
//     return temp_a0;
// }
