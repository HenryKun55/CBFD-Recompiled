#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15105CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_1510608C.s")

void *func_151061E0(u8 *arg0) {
    return arg0 + 0x88;
}

struct func_151061EC_s {
    u8 pad0[0x48];
    s32 unk48;
    u8 pad4C[0x88 - 0x4C];
    u8 unk88[1][0x34];
};

void *func_151061EC(struct func_151061EC_s *arg0) {
    s32 idx = arg0->unk48;
    return &arg0->unk88[idx];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106214.s")

f32 func_151064B4(f32 arg0) {
    f32 temp = 1.0f - arg0;
    return temp * temp * temp;
}

f32 func_151064DC(f32 t) {
    f32 u = 1.0f - t;
    return 3.0f * t * u * u;
}

f32 func_15106510(f32 arg0) {
    return 3.0f * arg0 * arg0 * (1.0f - arg0);
}

f32 func_15106540(f32 x) {
    return x * x * x;
}

f32 func_15106558(f32 arg0) {
    f32 t = 1.0f - arg0;
    return -3.0f * t * t;
}

f32 func_15106584(f32 arg0) {
    return ((9.0f * arg0 * arg0) - (12.0f * arg0)) + 3.0f;
}

f32 func_151065BC(f32 arg0) {
    return (-9.0f * arg0 * arg0) + (6.0f * arg0);
}

f32 func_151065EC(f32 arg0) {
    return 3.0f * arg0 * arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151067B8.s")

extern void (*D_80088C18[])(s32);
void func_151D5E30(void *);

void func_15106E78(s32 arg0) {
    void (*f)(s32) = D_80088C18[((u8 *)arg0)[0x5C]];

    if (f != NULL) {
        f(arg0);
    }
    if (*(struct102 **)(arg0 + 0x6C) != NULL) {
        func_1516972C(*(struct102 **)(arg0 + 0x6C));
    }
    if (*(struct102 **)(arg0 + 0x70) != NULL) {
        func_1516972C(*(struct102 **)(arg0 + 0x70));
    }
    func_151D5E30((void *)(arg0 + 0x74));
}

void func_15106E78(s32 arg0);
void func_15169804(s32 arg0);

void func_15106EF8(s32 arg0) {
    func_15106E78(arg0);
    func_15169804(arg0);
}

void func_15106F24(s32 arg0) {
    func_15106E78(arg0);
    func_15169824(arg0);
}

extern void (*D_80088C28[])(u8 *, s32, u8);

void func_15106F50(u8 *arg0, s32 arg1, u8 arg2) {
    void (*func)(u8 *, s32, u8) = D_80088C28[arg0[0x5C]];

    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151070F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151072BC.s")

struct func_15107604_s { u8 pad[0x28]; s32 unk28[3]; };
void func_15107604(s32 arg0) {
    struct func_15107604_s **pp = *(struct func_15107604_s ***)(arg0 + 0x60);
    s32 *p = (*pp)->unk28;
    p[2] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_1510761C.s")

void func_1510761C(void *arg0);

void func_1510764C(void *arg0) {
    func_1510761C(arg0);
    func_1514933C(arg0);
}

void func_15107678(s32 arg0) {
    func_1510761C(arg0);
    func_15149368(arg0);
}

struct func_151076A4_s {
    u8 pad[0x68];
    volatile u8 unk68;
};

extern void (*D_80088C38[])(struct func_151076A4_s *, s32, u8);

void func_151076A4(struct func_151076A4_s *arg0, s32 arg1, u8 arg2) {
    if (D_80088C38[arg0->unk68] != NULL) {
        D_80088C38[arg0->unk68](arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107700.s")

struct func_151078E4_s {
    u8 pad0[0x60];
    u8 *unk60;
};

void func_151078E4(struct func_151078E4_s *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0->unk60, arg0->unk60 + 4, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107E48.s")

void func_15107F54(struct127 *arg0, u8 arg1, s32 arg2, s32 arg3) {
    func_15143134(arg2, arg3, (s32) arg0->unk1D4 + (arg1 << 6));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107F98.s")
