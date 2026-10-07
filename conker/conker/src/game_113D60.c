#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E68B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6B84.s")

extern f32 D_800A130C;
extern f32 *D_80088A3C;
extern f32 *D_80088A40;

void func_150E6E34(f32 *arg0) {
    f32 *p;
    f32 t;

    if (func_150ADA68() < D_800A130C) {
        p = D_80088A3C;
    } else {
        p = D_80088A40;
    }
    t = func_150ADA68();
    arg0[0] = p[0] + (p[3] - p[0]) * t;
    arg0[1] = p[1] + (p[4] - p[1]) * t;
    arg0[2] = p[2] + (p[5] - p[2]) * t;
}

void func_150E6ED8(s32 arg0) {
    func_1514470C((&D_800D9A20)[func_150ADA20() & 1], arg0);
}

extern f32 *D_80088A44[];

void func_150E6F18(f32 *arg0) {
    f32 *v = D_80088A44[func_150ADA20() % 6U];
    f32 t = func_150ADA68();

    arg0[0] = v[0] + ((v[3] - v[0]) * t);
    arg0[1] = v[1] + ((v[4] - v[1]) * t);
    arg0[2] = v[2] + ((v[5] - v[2]) * t);
}

extern s32 func_1514ECE0();

void func_150E6FAC(f32 *arg0, f32 *arg1) {
    u8 *sp34;

    if (func_1514ECE0(*(void **)((u8 *)arg1 + 0x2F4), 0x16, &sp34) != 0) {
        f32 *v0;
        f32 sp2C;
        s16 sp2A;
        f32 sp24;
        f32 c;

        sp2C = func_150ADA68() * 100.0f + 80.0f;
        sp2A = func_150ADA20() & 0xFF;
        sp24 = func_151423D8(sp2A - 64);
        c = func_151423D8(sp2A);
        v0 = *(f32 **)(sp34 + 0x10);
        arg0[0] = (v0[14] * -80.0f) + arg1[5] + sp24 * sp2C;
        arg0[1] = (v0[15] * -80.0f) + arg1[6] + 100.0f;
        arg0[2] = (v0[16] * -80.0f) + arg1[7] + c * sp2C;
    } else {
        arg0[0] = arg1[5];
        arg0[1] = arg1[6];
        arg0[2] = arg1[7];
    }
}

void func_150E70CC(f32 *arg0, f32 *arg1) {
    arg0[0] = arg1[5];
    arg0[1] = arg1[6];
    arg0[2] = arg1[7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E70EC.s")

extern f32 D_800A1324;
extern f32 D_800A1328;
extern f32 D_800A132C;
extern f32 D_800A1330;
extern f32 D_800A1334;
extern f32 D_800A1338;
extern f32 D_800A133C;

void func_150E71E4(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    arg3[0] = func_150484A0(arg2[0], arg2[2]);
    arg3[2] = D_800A1324;
    arg3[4] = func_150ADA68() * D_800A1328;
    arg3[6] = func_150ADA68() * D_800A132C;
    arg3[1] = D_800A1330;
    arg3[3] = D_800A1334;
    arg3[5] = func_150ADA68() * D_800A1338;
    arg3[7] = func_150ADA68() * D_800A133C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7290.s")

struct func_150E75A0_b { u8 v; };
extern struct func_150E75A0_b D_80088A64;

struct func_150E75A0_v {
    s32 a;
    s32 b;
};

struct func_150E75A0_s {
    struct func_150E75A0_v pos;
    f32 x8;
    f32 xC;
    u8 x10;
    s16 x12;
    s16 x14;
    s16 x16;
    s16 x18;
    u8 x1A;
    u8 x1B;
    u8 x1C;
    u8 x1D;
    u8 x1E;
    u8 x1F;
    u8 x20;
    u8 x21;
    u8 x22;
    u8 x23;
    s32 x24;
    s32 x28;
    s32 x2C;
    s32 x30;
    s32 x34;
    s32 x38;
    s32 x3C;
    u8 x40;
    u8 x41;
    u8 pad[0x18];
};

void func_150E75A0(struct func_150E75A0_v *arg0, f32 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, s16 arg7, s32 arg8, s32 arg9, u8 arg10, s32 arg11) {
    struct func_150E75A0_s sp2C;
    struct func_150E75A0_b sp28;

    sp28 = D_80088A64;
    sp2C.pos = *arg0;
    sp2C.x8 = arg1;
    sp2C.xC = arg1;
    sp2C.x10 = sp28.v;
    sp2C.x12 = arg2;
    sp2C.x14 = arg3 | 0x40;
    sp2C.x16 = arg6;
    sp2C.x18 = arg7;
    sp2C.x1A = 4;
    sp2C.x1B = 0xFF;
    sp2C.x1C = 0xE6;
    sp2C.x1D = 0xBE;
    sp2C.x1E = arg4;
    sp2C.x1F = 0xFF;
    sp2C.x20 = 0xFF;
    sp2C.x21 = 0xFF;
    sp2C.x22 = 0xFF;
    sp2C.x23 = arg5;
    sp2C.x24 = 1;
    sp2C.x28 = 0;
    sp2C.x2C = 0;
    sp2C.x40 = 0;
    sp2C.x41 = 0xA;
    sp2C.x30 = 7;
    sp2C.x34 = 0x3C;
    sp2C.x38 = 0x80;
    sp2C.x3C = 0x20;
    func_1515548C(&sp2C, 0, arg8, arg9, 0, arg10, arg11);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E76D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E81A8.s")

struct func_150E83AC_s {
    f32 x, y, z;
};

void func_150E83AC(struct func_150E83AC_s *arg0, s16 arg1, u8 arg2, s32 arg3) {
    struct {
        struct func_150E83AC_s v;
        f32 w;
    } sp40;
    struct260 *temp_v0;

    sp40.v = *arg0;
    sp40.w = 0.0f;
    temp_v0 = func_15149130((arg1 == -1) ? 300 : arg1, -1, 0x28, -1, (arg1 == -1) ? 0 : 1, 0, (struct37 *) 0x10, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((u8 *) temp_v0 + 0x28, &sp40, 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8470.s")

void func_15131828();

s32 func_150E8824(u8 *arg0, void *arg1) {
    func_15131828(arg0, arg0 + 0xAC, arg0 + 0xA8, arg0 + 0xAA);
    return 1;
}

void func_150E8854(void) {
    struct260 *result;
    f32 sp30;

    sp30 = 10.0f;
    result = func_15149130(300, -1, 0x35, -1, 0, 0, (struct37 *) 4, 0xFF, 1);
    if (result != 0) {
        memcpy((char *) result + 0x28, &sp30, 4);
    }
}

extern f32 D_800A1378;
void func_150E8930();

void func_150E88C0(u8 *arg0) {
    *(f32 *)(arg0 + 0x28) -= D_800BE9A4;
    if (*(f32 *)(arg0 + 0x28) < 0.0f) {
        *(f32 *)(arg0 + 0x28) = (func_150ADA68() * D_800A1378) + 201.0f;
        func_150E8930(arg0);
    }
}

struct func_150E8930_s {
    s32 a;
    s32 b;
};
extern struct func_150E8930_s D_80088A80;
extern u8 D_800BE9EB;
void func_15164F0C();
void func_150E8A80(void);
void func_150E90DC(void);

void func_150E8930(void) {
    struct func_150E8930_s sp30;
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    sp30 = D_80088A80;
    func_15169260(&sp30, 2, 0, 0x1B);
    func_15164F0C(0, D_800BE9EB, 0, 0xFF, 1);
    local.f0 = 1;
    local.f2 = (u32) func_150ADA20() % 21 + 20;
    local.f5 = 1;
    local.f4 = (u32) func_150ADA20() % 6 + 3;
    local.f6 = -1;
    func_151D8868(&local, 0, 0xFF, 1);
    if (D_800DCDC4) {
        func_150E8A80();
    }
    if (D_800DCDC4) {
        func_150E90DC();
    }
    func_10010F30(0x4C8, 0x7FFF, 0x40, 0x200 - (func_150ADA20() & 0x400), 0);
    func_10010F30(0x4CD, 0x5DC0, 0x40, 0x200 - (func_150ADA20() & 0x400), 0);
}

extern f32 D_800A137C;
extern f32 D_800A1380;

void func_150E8A80(void) {
    struct260 *result;
    f32 sp38[3];

    sp38[0] = D_800A137C;
    sp38[1] = D_800A1380;
    sp38[2] = 0.0f;
    result = func_15149130((func_150ADA20() % 41U) + 0x1E, -1, 0x33, -1, 1, 0, (struct37 *) 0xC, 0xFF, 1);
    if (result != 0) {
        memcpy((char *) result + 0x28, sp38, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8D5C.s")

extern f32 D_800A13B0;
extern f32 D_800A13B4;

void func_150E90DC(void) {
    struct260 *result;
    f32 sp38[3];

    sp38[0] = D_800A13B0;
    sp38[1] = D_800A13B4;
    sp38[2] = 0.0f;
    result = func_15149130((func_150ADA20() % 26U) + 5, -1, 0x36, -1, 1, 0, (struct37 *) 0xC, 0xFF, 1);
    if (result != 0) {
        memcpy((char *) result + 0x28, sp38, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E9178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E93DC.s")

struct func_150E971C_s {
    s32 unk0;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
};

void func_151337C0(void *arg0);

s32 func_150E971C(u8 *arg0) {
    u8 *temp_v1;
    struct func_150E971C_s sp54;
    f32 temp_f2;

    func_151337C0(arg0);
    temp_v1 = arg0 + 0x170;
    if (*(f32 *)(arg0 + 0x3C) < *(f32 *)(arg0 + 0x170)) {
        if ((*(s32 *)(temp_v1 + 4) & 0x1F) == 0xA) {
            temp_f2 = func_150ADA68() * 20.0f + 20.0f;
            sp54.unk6 = 0xB;
            sp54.unk0 = 0x9701;
            sp54.unk4 = 0x64;
            sp54.unk7 = 0;
            sp54.unk8 = 0;
            sp54.unkC = 0;
            sp54.unk10 = 0xFF;
            sp54.unk11 = 0xFF;
            sp54.unk12 = 0xFF;
            sp54.unk13 = 0xFF;
            sp54.unk14 = 0xFF;
            sp54.unk15 = 0xFF;
            sp54.unk18 = 0x3B0003;
            sp54.unk16 = 0;
            sp54.unk17 = 7;
            sp54.unk22 = 0x14;
            sp54.unk24 = 0xC;
            func_1513C73C((s32)&sp54, 0, 0, (s32)(temp_v1 + 8), *(f32 *)(arg0 + 0x38),
                          *(f32 *)temp_v1 + 5.0f, *(f32 *)(arg0 + 0x40), temp_f2, temp_f2,
                          func_150ADA20() & 0xFF, 0, 0, arg0[0xC], arg0[1]);
        }
        return 0;
    }
    return 1;
}
