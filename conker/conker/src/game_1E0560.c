#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151B30B0_s {
    u8 pad0[0x10];
    u8 unk10;
    u8 pad11[0x38 - 0x11];
    f32 unk38;
    u8 pad3C[0x138 - 0x3C];
    f32 unk138;
    s32 unk13C;
    u8 unk140[0x10];
};

extern void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern f32 D_800AA390;

struct func_151B30B0_s *func_151B30B0(void *arg0, f32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct func_151B30B0_s *v;
    f32 f;
    f32 t;

    v = func_15167A68(0x33, arg4, arg2 + 0x150, 1, arg3, 1);
    if (v == NULL) {
        return NULL;
    }
    memcpy(&v->unk10, arg0, 0x38);
    f = v->unk38;
    v->unk10 |= 0xE;
    t = (f * f) / D_800AA390;
    v->unk138 = t + t;
    v->unk13C = f * arg1 * 4096.0f;
    bzero(v->unk140, 0x10);
    return v;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B32C8.s")

struct func_151B3A34_s {
    u8 pad0[0x44];
    u8 unk44;
};

extern void (*D_8008FB68[])(struct func_151B3A34_s *, s32, u8);

void func_151B3A34(struct func_151B3A34_s *arg0, s32 arg1, u8 arg2) {
    void (*func)(struct func_151B3A34_s *, s32, u8) = D_8008FB68[arg0->unk44];

    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3CF0.s")

extern f32 D_800AA3AC;

struct func_151B3F28_s2 {
    s32 unk0;
    u8 pad4[0x10];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x1B];
    u8 unk3B;
};

struct func_151B3F28_s3 {
    struct func_151B3F28_s2 *ptr;
    u8 unk4;
};

struct func_151B3F28_s {
    u8 pad0[0x10];
    u8 unk10;
    u8 pad11[0x150 - 0x11];
    struct func_151B3F28_s3 unk150;
};

s32 func_151B3F28(struct func_151B3F28_s *arg0, f32 *arg1, u8 arg2) {
    s32 ret = 1;
    struct func_151B3F28_s3 *s;

    if (arg2) {
        s = &arg0->unk150;
        if (s->ptr->unk0 != 0 && s->ptr->unk3B == s->unk4) {
            arg1[0] = s->ptr->unk14;
            arg1[1] = s->ptr->unk18;
            arg1[2] = s->ptr->unk1C;
            arg0->unk10 &= ~4;
        } else {
            s32 pad; // block-scoped local (needed for -g3 delay-slot layout)

            ret = 0;
            arg0->unk10 |= 0xC;
        }
    } else {
        arg1[0] = 0.0f;
        arg1[1] = D_800AA3AC;
        arg1[2] = 0.0f;
        arg0->unk10 &= ~8;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B42A4.s")

struct func_151B47D8_obj {
    void *unk0;
    u8 pad4[0x3B - 4];
    u8 unk3B;
    u8 pad3C[0x1D4 - 0x3C];
    u8 *unk1D4;
};

struct func_151B47D8_s {
    struct func_151B47D8_obj *unk0;
    u8 unk4;
    u8 unk5;
    u8 pad6[2];
    u8 unk8[0xC];
    struct func_151B47D8_obj *unk14;
    u8 unk18;
    u8 unk19;
    u8 pad1A[2];
    u8 unk1C[0xC];
};

struct func_151B47D8_a {
    u8 pad[0x10];
    u8 unk10;
};

s32 func_151B47D8(struct func_151B47D8_a *arg0, struct func_151B47D8_s *arg1, s32 arg2, u8 arg3) {
    struct func_151B47D8_obj *a = arg1->unk0;
    struct func_151B47D8_obj *b = arg1->unk14;

    if (a->unk1D4 == NULL || b->unk1D4 == NULL) {
        arg0->unk10 |= 0xC;
        return 1;
    }
    if (a->unk0 == NULL || a->unk3B != arg1->unk4 || b->unk0 == NULL || b->unk3B != arg1->unk18) {
        return 0;
    }
    arg0->unk10 &= ~(arg3 ? 4 : 8);
    func_15143134(arg3 ? arg1->unk8 : arg1->unk1C, arg2,
                  arg3 ? a->unk1D4 + (arg1->unk5 << 6) : b->unk1D4 + (arg1->unk19 << 6));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B48DC.s")

s32 func_151B498C(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6, s32 *arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB, u8 *argC, u8 *argD) {
    *arg1 = 0x220005;
    *arg2 = 0x40600;
    *arg3 = 0xFF;
    *arg4 = 0xFF;
    *arg5 = 0xFF;
    *arg6 = 0xFF;
    *arg7 = 0xFF;
    *arg8 = 0xFF;
    *arg9 = 0xFF;
    *argA = 0xFF;
    *argB = 0;
    *argC = 5;
    *argD = 0x2B;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4B78.s")

void *func_151D5E30();
extern void (*D_8008FB70[])(void *);

void func_151B4C1C(u8 *arg0) {
    func_151D5E30(arg0 + 0x140, arg0);
    if (D_8008FB70[arg0[0x44]] != NULL) {
        D_8008FB70[arg0[0x44]](arg0);
    }
}

void func_151B4C6C(s32 arg0) {
    func_151B4C1C(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4C98.s")
