#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800CBD9C;

void func_15044370(void) {
    D_800CBD9C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504452C.s")

void func_15044658(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044660.s")

struct func_150448D0_s {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
    s32 unk18;
    s32 unk1C;
};

struct func_150448D0_s *func_15044964(s32, s32, s32, s32, s32, s32, s32, s32);

struct func_150448D0_s *func_150448D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    struct func_150448D0_s *temp_v0;

    temp_v0 = func_15044964(0x20, 1, arg0, arg1, arg2, 0, 0, 0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    temp_v0->unk10 = arg3;
    temp_v0->unk12 = arg4;
    temp_v0->unk14 = arg5;
    temp_v0->unk16 = arg6;
    temp_v0->unk18 = arg7;
    temp_v0->unk1C = arg8;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044A28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044B78.s")

struct func_15044CE4_s {
    u8 pad0[6];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[2];
    s16 *unk18;
    s16 *unk1C;
};

void func_15044CE4(struct func_15044CE4_s *arg0) {
    s16 temp;
    arg0->unk6 = arg0->unk18[0];
    arg0->unk8 = arg0->unk18[1];
    arg0->unkA = arg0->unk18[2];
    temp = arg0->unk1C[0] / 32;
    arg0->unk10 = temp;
    arg0->unk12 = temp;
    arg0->unk14 = temp;
    func_15044B78(arg0);
}

void func_1505D1C4(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6, s32 arg7);

s32 func_15044D40(s16 *arg0) {
    func_1505D1C4(arg0[3], arg0[4], arg0[5], arg0[8], 0xFF, 0, 0, 0);
    return 0;
}

void func_15044DA0(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0)) {
        func_1505D024(gObjects, 5, gObjects[0].unk7A, -1);
    }
}

void func_15044DE8(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0) && (D_800C35EA != 1)) {
        func_1505D024(&gObjects[0], 4, gObjects[0].unk7A, -1);
    }
}

void func_15044E40(void) {
    if ((gObjects[0].stunned == 0) && (gObjects[0].immune == 0)) {
        func_1505D024(gObjects, 0x40, gObjects[0].unk7A, -1);
    }
}

void func_15044E88(void) {
    if ((gObjects->stunned == 0) && (gObjects->immune == 0)) {
        func_1505D024(gObjects, 1, gObjects->unk7A, -1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150450CC.s")

s32 func_1504530C(s32 arg0, s32 arg1, s32 arg2) {
    switch (func_150470B0(arg0, arg1, arg2)) {
    case 0:
        return func_15044ED0(arg0, arg1, arg2);
    case 1:
        return 0;
    case 2:
        return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504554C.s")

s32 func_150A6500(s16 arg0, s16 arg1, s32 arg2, u16 arg3);

void func_15045714(f32 *arg0, u16 arg1, s32 *arg2, s32 arg3) {
    func_1510F800(2);
    *arg2 = func_150A6500(arg0[0], arg0[2], arg3, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045780.s")

u8 func_15047004(void *arg0, f32 arg1, f32 *arg2);
u8 func_15045780(void *arg0, u16 arg1, f32 arg2, f32 *arg3);

u8 func_15045800(void *arg0, u16 arg1, f32 arg2, f32 *arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_15045780(arg0, arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150461D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150466F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504697C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046D00.s")

u8 func_15047004(void *arg0, f32 arg1, f32 *arg2);
u8 func_15046D00(void *arg0, u16 arg1, f32 arg2, f32 *arg3);

u8 func_15046F84(void *arg0, u16 arg1, f32 arg2, f32 *arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_15046D00(arg0, arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    }
}

s32 func_150A3FC4(f32, f32, s32, f32 *, f32 *);

u8 func_15047004(void *arg0, f32 arg1, f32 *arg2) {
    f32 sp24;

    if ((((u8 *)arg2)[0x1C] & 4) && func_150A3FC4(((f32 *)arg0)[0], ((f32 *)arg0)[2], 0, arg2 + 1, &sp24)) {
        if (arg1 <= sp24 && sp24 <= ((f32 *)arg0)[1]) {
            arg2[0] = sp24;
            ((u8 *)arg2)[0x1C] |= 2;
            return 2;
        }
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150470B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504715C.s")

struct func_150472C0_s18 { s16 v[9]; };
struct func_150472C0_dst {
    f32 unk0;
    struct func_150472C0_s18 unk4;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    s32 unk20;
};
struct func_150472C0_src {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10[0x34];
    struct func_150472C0_s18 unk44;
    u8 pad56[3];
    u8 unk59;
    s32 unk5C;
    s32 unk60;
};

void func_150472C0(struct func_150472C0_dst *arg0, struct func_150472C0_src *arg1) {
    arg0->unk0 = arg1->unkC;
    arg0->unk4 = arg1->unk44;
    arg0->unk18 = arg1->unk60;
    arg0->unk1C = ((arg1->unk59 == 1) ? 1 : 0) | ((arg1->unk59 == 1) ? 2 : 0) | ((arg1->unk59 == 1) ? 4 : 0);
    arg0->unk1D = (arg1->unk59 == 1) ? 1 : 0;
    arg0->unk20 = arg1->unk5C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047390.s")

void func_15047390(float mf[4][4], float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp);

void func_15047688(Mtx *m, float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp) {
    float mf[4][4];

    func_15047390(mf, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp);
    guMtxF2L(mf, m);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047B80.s")
