#include <ultra64.h>

#include "functions.h"
#include "variables.h"



#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513C060.s")

struct func_1513C350_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};
struct func_151400D0_d;
struct func_151400D0_s;
void func_1513FFF4(s16 *arg0, u8 arg1, u8 arg2);
void func_151400D0(struct func_151400D0_d *arg0, struct func_151400D0_s *arg1);
struct210 *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
s32 func_1515D480(s32 arg0);
s32 func_1515D440(void);

struct210 *func_1513C350(struct210 *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, struct167 *arg7, s32 arg8, u8 arg9, s32 argA) {
    struct210 *temp_v0;
    u8 phi_v0;
    s32 i;

    if (arg1 == 0) {
        arg1 = (s32)&D_800A4AA0;
    }
    if (arg0->unk0 & 0x40000) {
        phi_v0 = 0x4A;
    } else {
        phi_v0 = 0x1B;
    }
    temp_v0 = func_15167A68(phi_v0, argA, arg8 + 0xB0, 1, arg9, 1);
    if (temp_v0 == 0) {
        return NULL;
    }
    memcpy(&temp_v0->unk18, arg0, 0x28);
    func_1513FFF4((s16 *)&temp_v0->unk40, temp_v0->unk1E, arg4);
    func_151400D0((struct func_151400D0_d *)&temp_v0->unk40, (struct func_151400D0_s *)arg1);
    temp_v0->unk80 = arg2;
    temp_v0->unk81 = arg3;
    temp_v0->unk84 = arg5;
    temp_v0->unk10 = 1;
    temp_v0->unk14 = 0;
    temp_v0->unkA0 = arg6;
    for (i = 0; i < 4; i++) {
        temp_v0->unk8C[i] = 0;
    }
    temp_v0->unk9C = 0;
    if (arg5) {
        for (i = 0; i <= D_80082FA0; i++) {
            temp_v0->unk8C[i] = func_1515D480(arg5);
        }
        temp_v0->unk9C = func_1515D440();
    }
    if (arg7) {
        *(struct func_1513C350_s *)temp_v0->unkA4 = *(struct func_1513C350_s *)arg7;
    }
    return temp_v0;
}
// NON-MATCHING: JUSTREG: final 3 lines :(
// struct210 *func_1513C350(struct210 *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, struct167 *arg7, s32 arg8, u8 arg9, s32 argA) {
//     struct210 *temp_v0;
//     u8 phi_v0;
//     s32 i;
//
//     if (arg1 == 0) {
//         arg1 = &D_800A4AA0;
//     }
//     if (arg0->unk0 & 0x40000) {
//         phi_v0 = 0x4A;
//     } else {
//         phi_v0 = 0x1B;
//     }
//     temp_v0 = func_15167A68(phi_v0, argA, arg8 + 0xB0, 1, arg9, 1);
//     if (temp_v0 == 0) {
//         return NULL;
//     }
//     memcpy(&temp_v0->unk18.i.unk0, arg0, 0x28); // memcpy
//     func_1513FFF4(&temp_v0->unk40, temp_v0->unk1E, arg4);
//     func_151400D0(&temp_v0->unk40, arg1);
//     temp_v0->unk80 = arg2;
//     temp_v0->unk81 = arg3;
//     temp_v0->unk84 = arg5;
//     temp_v0->unk10 = 1;
//     temp_v0->unk14 = 0;
//     temp_v0->unkA0 = arg6;
//     for (i = 0; i < 4; i++) {
//         temp_v0->unk8C[i] = 0;
//     }
//
//     temp_v0->unk9C = 0;
//     if (arg5) {
//         for (i = 0; i <= D_80082FA0; i++) {
//             temp_v0->unk8C[i] = func_1515D480(arg5);
//         }
//         temp_v0->unk9C = func_1515D440();
//     }
//     if (arg7) {
//         temp_v0->unkA4[0] = arg7->unk0;
//         temp_v0->unkA4[1] = arg7->unk4;
//         temp_v0->unkA4[2] = arg7->unk8;
//     }
//     return temp_v0;
// }

struct210 *func_1513C4EC(s32 arg0, s32 arg1, u8 arg2, u8 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, s32 argC, s32 argD, u8 argE, s32 argF) {
    s32 temp_v0;
    struct17 tmp;

    tmp.unk0 = arg4;
    tmp.unk4 = arg5;
    tmp.unk8 = arg6;
    temp_v0 = func_1513C350(arg0, arg1, arg2, arg3, argA, argB, argC, &tmp, argD, argE, argF);
    if (temp_v0 == 0) {
        return 0;
    }
    func_1513E13C(temp_v0, arg4, arg5, arg6, arg7, arg8, arg9);
    return temp_v0;
}

struct210 *func_1513C5B0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, u8 argC, s32 argD) {
    s32 tmp = func_1513C350(arg0, arg1, arg2, arg3, argA, 0, 0, 0, argB, argC, argD);
    if (tmp == 0) {
        return 0;
    }
    func_1513E13C(tmp, arg4, arg5, arg6, arg7, arg8, arg9);
    return tmp;
}

struct210 *func_1513C650(s32 arg0, u8 arg1, u8 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, s32 argC, s32 argD, u8 argE, s32 argF) {
    s32 temp_v0;
    struct17 tmp;

    tmp.unk0 = arg4;
    tmp.unk4 = arg5;
    tmp.unk8 = arg6;

    temp_v0 = func_1513C350(arg0, 0, arg1, arg2, argA, argB, argC, &tmp, argD, argE, argF);
    if (temp_v0 == 0) {
        return 0;
    }

    if (func_1513E2AC(temp_v0, 0, arg3, arg4, arg5, arg6, arg7, arg8, arg9) == 0) {
        func_1516972C(temp_v0);
        return 0;
    }
    return temp_v0;
}

struct210 *func_1513C73C(s32 arg0, u8 arg1, u8 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, u8 argC, s32 argD) {
    s32 tmp = func_1513C350(arg0, 0, arg1, arg2, argA, 0, 0, 0, argB, argC, argD);
    if (tmp == 0) {
        return 0;
    }

    if (func_1513E2AC(tmp, 0, arg3, arg4, arg5, arg6, arg7, arg8, arg9) == 0) {
        func_1516972C(tmp);
        return 0;
    }
    return tmp;
}

struct210 *func_1513C804(s32 arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, u8 argA, u8 argB, s32 argC, u8 argD, s32 argE) {
    s32 tmp = func_1513C350(arg0, 0, arg2, arg3, argB, 0, 0, 0, argC, argD, argE);
    if (tmp == 0) {
        return 0;
    }
    if (func_1513E2AC(tmp, 0, arg4, arg5, arg6, arg7, arg8, arg9, argA) == 0) {
        func_1516972C(tmp);
        return 0;
    }
    return tmp;
}

void func_1513C8D4(struct210 *arg0) {
    func_1513C92C(arg0);
    func_15169804(arg0);
}

void func_1513C900(struct210 *arg0) {
    func_1513C92C(arg0);
    func_15169824(arg0);
}

void func_1513C92C(struct210 *arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (arg0->unk8C[i]) {
            func_100043B4(arg0->unk8C[i], 4);
        }
    }
    if (arg0->unk9C != 0) {
        func_100043B4(arg0->unk9C, 4);
    }
}

void func_1513C9B0(struct210 *arg0) {
    s32 idx;
    if ((arg0->unk18.i.unk0 & 0x1000) != 0) {
        idx = arg0->unk1F;
    } else {
        idx = 0;
    }
    D_80089EE8[idx]();
}

void func_1513C9FC(struct210 *arg0) {
    s32 idx;
    if ((arg0->unk18.i.unk0 & 0x1000) != 0) {
        idx = arg0->unk1F;
    } else {
        idx = 0;
    }
    D_80089EF0[idx]();
}

void func_1513CA48(struct210 *arg0) {
    func_151D5E30(&arg0->unk100);
}

void func_1513CA6C(struct210 *arg0) {
    func_1513CA48(arg0);
    func_1513CAD4(arg0);
    func_15169804(arg0);
}

void func_1513CAA0(struct210 *arg0) {
    func_1513CA48(arg0);
    func_1513CAD4(arg0);
    func_15169824(arg0);
}

void func_1513CAD4(struct210 *arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (arg0->unkA4[i]) {
            func_100043B4(arg0->unkA4[i], 4);
        }
    }
    if (arg0->unkB4 != 0) {
        func_100043B4(arg0->unkB4, 4);
    }
}

// is this really struct210?
void func_1513CB58(struct210 *arg0) {
    s32 idx;
    if ((arg0->unk58 & 0x400000) != 0) {
        idx = arg0->unk18.b.unk1; //unk19;
    } else {
        idx = 0;
    }
    D_80089EF8[idx]();
}

void func_1513CBA4(struct210 *arg0) {
    s32 idx;
    if ((arg0->unk58 & 0x400000) != 0) {
        idx = arg0->unk18.b.unk1; //unk19;
    } else {
        idx = 0;
    }
    D_80089F2C[idx]();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513CBF0.s")

void func_1513CF9C(s32 arg0, s32 arg1, u8 arg2) {
    D_80089F60[0](arg0, arg1, arg2);
}

void func_1513CFD0(s32 arg0, s32 arg1, s32 arg2) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513CFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513D2F0.s")

void *func_1513D4B8(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, s32 arg7, u8 arg8, s32 arg9) {
    return func_1513D2F0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, 0, 0, arg7, arg8, arg9);
}

void *func_1513D524(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6, u8 arg7, s32 arg8) {
    return func_1513D2F0(arg0, &D_800A4AA0, arg1, arg2, arg3, arg4, arg5, 0, 0, arg6, arg7, arg8);
}

s32 func_1513D594(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, f32 arg7, f32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, u8 argD, s32 argE, u8 argF, s32 arg10) {
    struct210 *temp_v0;

    if (arg1 == 0) {
        arg1 = &D_800A4AA0;
    }
    temp_v0 = func_1513D2F0(arg0, arg1, arg2, arg3, arg4, 0xC, arg5, argB, argC, argE + 0x18, argF, arg10);
    if ((temp_v0 != 0) && (func_1513D6FC(&temp_v0->unk110, arg6, arg7, arg8, arg9, argA, argD) == 0)) {
        func_1516972C(temp_v0);
        return 0;
    }
    return temp_v0;
}

void *func_1513D668(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, f32 arg7, f32 arg8, s32 arg9, s32 argA, u8 argB, s32 argC, u8 argD, s32 argE) {
    return (void *) func_1513D594(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, 0, 0, argB, argC, argD, argE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513D6FC.s")
// s32 func_1513D6FC(struct211 *arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, u8 arg6) {
//     f32 spBC;
//     f32 spB8;
//     f32 spB4;
//     s32 spB0;
//     f32 spAC;
//     s32 spA8;
//     f32 spA4;
//     s32 spA0;
//     s32 sp9C;
//     s32 sp98;
//     s32 sp94;
//     s32 sp90;
//     f32 sp8C;
//     f32 sp88;
//     f32 sp84;
//     s32 sp80;
//     f32 sp7C;
//     f32 sp78;
//     f32 sp74;
//     f32 sp70;
//     f32 sp6C;
//     f32 sp68;
//     f32 sp64;
//     f32 sp60;
//     s32 sp5C;
//     s32 sp58;
//     s32 sp54; // ?
//     s32 sp50; // ?
//     s32 sp4C; // ?
//     s32 sp48; // ?
//     s32 sp44; // ?
//     s32 sp40; // ?
//     s32 sp3C; // ?
//     s32 sp38; // ?
//     s32 sp34; // ?
//     s32 sp30; // ?
//     f32 sp2C;
//     f32 sp28;
//     f32 sp24;
//
//     f32 temp_f0;
//     f32 temp_f16;
//     f32 temp_f18;
//     f32 phi_f12;
//     f32 phi_f14;
//     f32 phi_f12_2;
//
//     if (arg6 != 0) {
//         spB4 = func_151423D8(arg1 - 64);
//         temp_f0 = func_151423D8(arg1);
//         spAC = arg2 * temp_f0;
//         spA4 = arg3 * temp_f0;
//         if (func_1510E388(arg4, arg5, &spBC, &spB8) == 0) {
//             return 0;
//         }
//         temp_f18 = spA4 * spB8;
//         sp2C = fabsf(spA4);
//         temp_f16 = arg3 * spB4;
//         sp28 = sqrtf((spA4 * spA4) + (temp_f18 * temp_f18));
//         if (temp_f16 != 0.0f) {
//             sp8C = temp_f16 * spBC;
//             sp88 = fabsf(temp_f16) / sqrtf((temp_f16 * temp_f16) + (sp8C * sp8C));
//         } else {
//             sp8C = 0.0f;
//             sp88 = 0.0f;
//         }
//         if (spA4 != 0.0f) {
//             sp84 = temp_f18;
//             phi_f12 = sp2C / sp28;
//         } else {
//             sp84 = 0.0f;
//             phi_f12 = 0.0f;
//         }
//         arg0->unk0 = sp88 * temp_f16;
//         arg0->unk8 = phi_f12 * spA4;
//         arg0->unk4 = (sp88 * sp8C) + (phi_f12 * sp84) + 0.5f;
//         temp_f18 = -(arg2 * spB4);
//         temp_f16 = temp_f18 * spB8;
//         sp28 = fabsf(temp_f18);
//         sp2C = temp_f16;
//         sp24 = sqrtf((temp_f18 * temp_f18) + (temp_f16 * temp_f16));
//         if (spAC != 0.0f) {
//             temp_f0 = spAC * spBC;
//             sp8C = temp_f0;
//             phi_f14 = fabsf(spAC) / sqrtf((spAC * spAC) + (temp_f0 * temp_f0));
//         } else {
//             sp8C = 0.0f;
//             sp88 = 0.0f;
//             phi_f14 = 0.0f;
//         }
//         if (temp_f18 != 0.0f) {
//             sp84 = sp2C;
//             phi_f12_2 = sp28 / sp24;
//         } else {
//             sp84 = 0.0f;
//             phi_f12_2 = 0.0f;
//         }
//         arg0->unkC = phi_f14 * spAC;
//         arg0->unk14 = phi_f12_2 * temp_f18;
//         arg0->unk10 = (phi_f14 * sp8C) + (phi_f12_2 * sp84) + 0.5f;
//     } else {
//         sp7C = func_151423D8(arg1 - 64);
//         sp78 = func_151423D8(arg1);
//         if (func_15144E80(arg5, &sp6C, &sp60, &sp54) == 0) {
//             return 0;
//         }
//         if (func_15145128(&sp6C, &sp6C, &sp50, &sp4C) == 0) {
//             return 0;
//         }
//         if (func_15145128(&sp60, &sp60, &sp50, &sp4C) == 0) {
//             return 0;
//         }
//         temp_f0 = arg2 * sp78;
//         temp_f18 = arg2 * sp7C;
//         arg0->unk0 = (temp_f0 * sp6C) + (temp_f18 * sp60);
//         arg0->unk4 = (temp_f0 * sp70) + (temp_f18 * sp64);
//         arg0->unk8 = (temp_f0 * sp74) + (temp_f18 * sp68);
//         temp_f0 = -arg3 * sp7C;
//         temp_f18 = arg3 * sp78;
//         arg0->unkC = (temp_f0 * sp6C) + (temp_f18 * sp60);
//         arg0->unk10 = (temp_f0 * sp70) + (temp_f18 * sp64);
//         arg0->unk14 = (temp_f0 * sp74) + (temp_f18 * sp68);
//     }
//     return 1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513DB00.s")

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513DF9C.s")

void func_1513E070(s32 arg0, s32 arg1, s32 arg2) {
}

void func_1513E084(struct210 *arg0, struct212 *arg1, u8 arg2) {
    struct212 *temp_v0 = &arg0->unk110;
    if (arg2 == 0x1A) {
        if ((temp_v0->unk0 == arg1->unk0) || (temp_v0->unk4.b.unk0 == arg1->unk4.b.unk0)) {
            func_1516972C(arg0);
        }
    } else {
        temp_v0 = &arg0->unk110;
        if (arg2 == 0x2D) {
            if (temp_v0->unk0 == arg1->unk0) {
                temp_v0->unk0 = arg1->unk4.i.unk0;
                temp_v0->unk4.b.unk0 = arg1->unk9;
            } else if (temp_v0->unk0 == arg1->unk4.i.unk0) {
                temp_v0->unk0 = arg1->unk0;
                temp_v0->unk4.b.unk0 = arg1->unk8;
            }
        }
    }
}

void func_1513E134(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513E13C.s")
// void func_1513E13C(struct210 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6) {
//     f32 sp48;
//     f32 sp30;
//     f32 sp1C;
//
//     f32 temp_f0;
//     f32 temp_f12;
//     f32 temp_f14;
//     f32 temp_f16;
//     f32 temp_f18;
//     f32 temp_f2;
//     s32 temp_f10;
//
//     sp48 = func_151423D8((arg6 - 0x40));
//     temp_f0 = func_151423D8(arg6);
//     temp_f12 = arg5 * sp48;
//     temp_f14 = arg4 * temp_f0;
//     temp_f18 = arg1 + temp_f14;
//     arg0->unk40 = temp_f18 - temp_f12;
//     temp_f10 = arg2;
//     arg0->unk42 = temp_f10;
//     temp_f16 = arg5 * temp_f0;
//     temp_f2 = arg4 * sp48;
//     sp1C = arg3 + temp_f16;
//     sp30 = arg1 - temp_f14;
//     arg0->unk44 = sp1C + temp_f2;
//     arg0->unk52 = temp_f10;
//     arg0->unk50 = sp30 - temp_f12;
//     arg0->unk54 = sp1C - temp_f2;
//     arg0->unk62 = temp_f10;
//     arg0->unk60 = sp30 + temp_f12;
//     arg0->unk72 = temp_f10;
//     arg0->unk70 = temp_f18 + temp_f12;
//     sp30 = arg3 - temp_f16;
//     arg0->unk64 = sp30 - temp_f2;
//     arg0->unk74 = sp30 + temp_f2;
// }

void func_1513E2A4(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513E2AC.s")

struct func_1513E6E8_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    s32 unk58;
    u8 pad5C;
    u8 unk5D;
    u8 pad5E[0x110 - 0x5E];
    struct func_1513E6E8_sub {
        f32 unk0;
        f32 unk4;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        f32 unk24;
        f32 unk28;
        f32 unk2C;
    } unk110;
};

s32 func_1513E6E8(struct func_1513E6E8_s *arg0) {
    struct func_1513E6E8_sub *v;
    v = &arg0->unk110;
    if (arg0->unk58 & 0x20) {
        v->unkC += v->unk2C * D_800BE9A4;
    }
    v = &arg0->unk110;
    if (arg0->unk58 & 0x40) {
        arg0->unk34 += v->unk8 * D_800BE9A4;
        arg0->unk38 += v->unkC * D_800BE9A4;
        arg0->unk3C += v->unk10 * D_800BE9A4;
    }
    v = &arg0->unk110;
    if (arg0->unk58 & 0x80) {
        arg0->unk40 += v->unk14 * D_800BE9A4;
        arg0->unk44 += v->unk18 * D_800BE9A4;
        arg0->unk48 += v->unk1C * D_800BE9A4;
    }
    v = &arg0->unk110;
    if (arg0->unk58 & 0x100) {
        arg0->unk4C += v->unk20 * D_800BE9A4;
        arg0->unk50 += v->unk24 * D_800BE9A4;
        arg0->unk54 += v->unk28 * D_800BE9A4;
    }
    arg0->unk5D = 0xFF;
    return 1;
}
// s32 func_1513E6E8(void *arg0) {
//     void *temp_v0;
//     void *temp_v0_2;
//     void *temp_v0_3;
//     void *temp_v0_4;
//     s32 phi_v1;
//     s32 phi_v1_2;
//
//     if ((arg0->unk58 & 0x20) != 0) {
//         temp_v0 = arg0->unk110;
//         temp_v0->unkC = (f32) (temp_v0->unkC + (temp_v0->unk2C * D_800BE9A4));
//     }
//     phi_v1 = arg0->unk58;
//     if ((arg0->unk58 & 0x40) != 0) {
//         temp_v0_2 = arg0->unk110;
//         arg0->unk34 = (f32) (arg0->unk34 + (temp_v0_2->unk8 * D_800BE9A4));
//         arg0->unk38 = (f32) (arg0->unk38 + (temp_v0_2->unkC * D_800BE9A4));
//         arg0->unk3C = (f32) (arg0->unk3C + (temp_v0_2->unk10 * D_800BE9A4));
//         phi_v1 = arg0->unk58;
//     }
//     temp_v0_3 = arg0->unk110;
//     phi_v1_2 = phi_v1;
//     if ((phi_v1 & 0x80) != 0) {
//         arg0->unk40 = (f32) (arg0->unk40 + (temp_v0_3->unk14 * D_800BE9A4));
//         arg0->unk44 = (f32) (arg0->unk44 + (temp_v0_3->unk18 * D_800BE9A4));
//         arg0->unk48 = (f32) (arg0->unk48 + (temp_v0_3->unk1C * D_800BE9A4));
//         phi_v1_2 = arg0->unk58;
//     }
//     temp_v0_4 = arg0->unk110;
//     if ((phi_v1_2 & 0x100) != 0) {
//         arg0->unk4C = (f32) (arg0->unk4C + (temp_v0_4->unk20 * D_800BE9A4));
//         arg0->unk50 = (f32) (arg0->unk50 + (temp_v0_4->unk24 * D_800BE9A4));
//         arg0->unk54 = (f32) (arg0->unk54 + (temp_v0_4->unk28 * D_800BE9A4));
//     }
//     arg0->unk5D = (u8)0xFF;
//     return 1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513E83C.s")

// ???
#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513EAD8.s")

void func_1513EDB4(s32 arg0, s16 arg1) {
    func_1513EAD8(arg0, 0, arg1);
}

s32 func_1513EDE4(s32 arg0, s16 arg1) {
    return func_1513EAD8(arg0, 1, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513EE14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513F114.s")

void func_1513F4B0(struct210 *arg0, s16 arg1) {
    func_15140410(arg0, &arg0->unk110, &arg0->unk11C, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513F4E4.s")

void func_1513F680(struct171 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    arg0->unk70 = arg1;
    arg0->unk71 = arg2;
    arg0->unk72 = arg3;
    arg0->unk73 = arg4;
}

void func_1513F6C0(struct210 *arg0, u8 arg1, u8 arg2) {
    arg0->unk80 = arg1;
    arg0->unk81 = arg2;
}

s32 func_1513F6E8(struct210 *arg0) {
    arg0->unk2C += arg0->unk128 * D_800BE9A4;
    arg0->unk30 += arg0->unk128 * D_800BE9A4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513F728.s")

void func_1513FA2C(void *arg0, s16 arg1) {
    f32 sp18[2];

    sp18[0] = 1.0f;
    sp18[1] = 1.0f;
    func_1513FAB4(arg0, 0, sp18, arg1);
}

void func_1513FA70(void *arg0, s16 arg1) {
    f32 sp18[2];

    sp18[0] = 1.0f;
    sp18[1] = 1.0f;
    func_1513FAB4(arg0, 1, sp18, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_1513FAB4.s")

// NON-MATCHING: 50 vs target's 55 instructions - five fewer (smarter
// than target). Writes 8 halfwords into arg0 based on two independent
// bits of arg2, each pair complementary (one field gets the computed
// value when the bit is set, its partner gets it when the bit is
// clear, matching target's identical write-order and per-branch
// value selection exactly). D_80090B60[arg1] (12-byte stride, u16
// fields at +6/+8) supplies the two base magnitudes, each read once,
// decremented, then left-shifted by 6 and split between the four
// field pairs by the arg2 bit tests. The whole gap traces to one
// thing: target holds arg0 in a callee-saved $s0 (with its own
// 8-byte frame just to spill/restore it), while this reconstruction
// keeps it in $a0 directly - there being no call and no other
// register pressure in this leaf function to give IDO a reason to
// promote it to a saved register, this near-miss shape looks
// structural rather than reachable from source phrasing.
typedef struct {
    u8 pad0[6];
    u16 unk6;
    u16 unk8;
    u8 padA[2];
} func_1513FFF4_s;
extern func_1513FFF4_s D_80090B60[];

void func_1513FFF4(s16 *arg0, u8 arg1, u8 arg2) {
    func_1513FFF4_s *e;
    u16 w;
    u16 h;

    if (arg1 != 0xFF) {
        e = &D_80090B60[arg1];
        w = e->unk6 - 1;
        h = e->unk8 - 1;
        arg0[4] = arg0[0x1C] = (arg2 & 1) ? (w << 6) : 0;
        arg0[0xC] = arg0[0x14] = (arg2 & 1) ? 0 : (w << 6);
        arg0[5] = arg0[0xD] = (arg2 & 2) ? (h << 6) : 0;
        arg0[0x15] = arg0[0x1D] = (arg2 & 2) ? 0 : (h << 6);
    }
}
// extern s32 D_80090B60;
//
// void func_1513FFF4(void *arg0, u8 arg1, u8 arg2) {
//     char *entry;
//     u16 v1;
//     u16 a0local;
//     s32 v0;
//
//     if (arg1 != 0xFF) {
//         entry = (char *) &D_80090B60;
//         entry = entry + arg1 * 12;
//         v1 = (u16) (*(u16 *) (entry + 6) - 1);
//         a0local = (u16) (*(u16 *) (entry + 8) - 1);
//
//         v0 = (arg2 & 1) ? (v1 << 6) : 0;
//         *(s16 *) ((char *) arg0 + 0x38) = v0;
//         *(s16 *) ((char *) arg0 + 0x8) = v0;
//
//         v0 = (arg2 & 1) ? 0 : (v1 << 6);
//         *(s16 *) ((char *) arg0 + 0x28) = v0;
//         *(s16 *) ((char *) arg0 + 0x18) = v0;
//
//         v0 = (arg2 & 2) ? (a0local << 6) : 0;
//         *(s16 *) ((char *) arg0 + 0x1A) = v0;
//         *(s16 *) ((char *) arg0 + 0xA) = v0;
//
//         v0 = (arg2 & 2) ? 0 : (a0local << 6);
//         *(s16 *) ((char *) arg0 + 0x3A) = v0;
//         *(s16 *) ((char *) arg0 + 0x2A) = v0;
//     }
// }

// NON-MATCHING: full semantics recovered and verified via isolated
// harness - a pure leaf struct-repack function, no calls/globals/
// control flow at all. Unpacks 4 repeating 10-byte source records
// (arg1+0x0, +0xA, +0x14, +0x1E) into 4 corresponding 16-byte
// destination records (arg0+0x6, +0x16, +0x26, +0x36). Each record:
// reads a u16 "wide" field and writes it to the record's first 2
// dest bytes, then writes 4 s16 source fields truncated to bytes at
// dest+6..+9 - but the u16 write gets immediately overwritten with a
// hardcoded 0 right after (a genuine straight-line dead write with no
// control flow involved at all, reproduced verbatim since target
// itself contains it - not a branch-likely artifact this time, just
// how the original source evidently read-then-discarded that field).
// 46 vs target's 48 instructions - the field mapping, byte offsets
// and the dead-write pattern all match exactly for all 4 records;
// the only difference is target's raw asm explicitly adjusts a0/a1 by
// constants (+0x30/+0x1E) via two real `addiu` instructions before
// using small relative offsets, while every C form tried here -
// direct absolute-offset casts, and explicitly introducing adjusted
// pointer locals matching that exact structure - gets IDO to fold the
// constant pointer arithmetic away entirely, which is strictly fewer
// instructions for identical behavior.
// void func_151400D0(void *arg0, void *arg1) {
//     u16 first;
//     char *d2;
//     char *s2;
//
//     first = *(u16 *) ((char *) arg1 + 0x8);
//     d2 = (char *) arg0 + 0x30;
//     s2 = (char *) arg1 + 0x1E;
//
//     *(u16 *) (d2 + -0x2a) = first;
//     *(s8 *) (d2 + -0x24) = (s8) *(s16 *) (s2 + -0x1e);
//     *(s8 *) (d2 + -0x23) = (s8) *(s16 *) (s2 + -0x1c);
//     *(s8 *) (d2 + -0x22) = (s8) *(s16 *) (s2 + -0x1a);
//     *(u16 *) (d2 + -0x2a) = 0;
//     *(s8 *) (d2 + -0x21) = (s8) *(s16 *) (s2 + -0x18);
//
//     *(u16 *) (d2 + -0x1a) = *(u16 *) (s2 + -0xc);
//     *(s8 *) (d2 + -0x14) = (s8) *(s16 *) (s2 + -0x14);
//     *(s8 *) (d2 + -0x13) = (s8) *(s16 *) (s2 + -0x12);
//     *(s8 *) (d2 + -0x12) = (s8) *(s16 *) (s2 + -0x10);
//     *(u16 *) (d2 + -0x1a) = 0;
//     *(s8 *) (d2 + -0x11) = (s8) *(s16 *) (s2 + -0xe);
//
//     *(u16 *) (d2 + -0xa) = *(u16 *) (s2 + -0x2);
//     *(s8 *) (d2 + -0x4) = (s8) *(s16 *) (s2 + -0xa);
//     *(s8 *) (d2 + -0x3) = (s8) *(s16 *) (s2 + -0x8);
//     *(s8 *) (d2 + -0x2) = (s8) *(s16 *) (s2 + -0x6);
//     *(u16 *) (d2 + -0xa) = 0;
//     *(s8 *) (d2 + -0x1) = (s8) *(s16 *) (s2 + -0x4);
//
//     *(u16 *) (d2 + 0x6) = *(u16 *) (s2 + 0x8);
//     *(s8 *) (d2 + 0xc) = (s8) *(s16 *) (s2 + 0x0);
//     *(s8 *) (d2 + 0xd) = (s8) *(s16 *) (s2 + 0x2);
//     *(s8 *) (d2 + 0xe) = (s8) *(s16 *) (s2 + 0x4);
//     *(u16 *) (d2 + 0x6) = 0;
//     *(s8 *) (d2 + 0xf) = (s8) *(s16 *) (s2 + 0x6);
// }
struct func_151400D0_s {
    s16 v[4];
    u16 w;
};
struct func_151400D0_d {
    u8 pad0[6];
    u16 w;
    u8 pad8[4];
    s8 b[4];
};
void func_151400D0(struct func_151400D0_d *arg0, struct func_151400D0_s *arg1) {
    s32 i;

    for (i = 0; i < 4; i++) {
        arg0->w = arg1->w;
        arg0->b[0] = arg1->v[0];
        arg0->b[1] = arg1->v[1];
        arg0->b[2] = arg1->v[2];
        arg0->b[3] = arg1->v[3];
        arg0->w = 0;
        arg0++;
        arg1++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_15140190.s")

void func_151403A8(s32 arg0, u8 arg1) {
    func_15169260(&D_800A5168, 4, arg0, arg1);
}

void func_151403DC(s32 arg0, u8 arg1) {
    func_15169260(&D_800A5178, 3, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_15140410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_169510/func_151406AC.s")
