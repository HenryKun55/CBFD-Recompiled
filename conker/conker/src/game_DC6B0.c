#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF200.s")

void func_151CF898(void *arg0, f32 arg1, f32 arg2);

void func_150AF2E0(void *arg0, s16 *arg1) {
    func_151CF898(arg0, arg1[4] + arg1[1], arg1[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF328.s")

void *func_15131828();
void *func_15131958();

s32 func_150AF6E4(u8 *arg0, s32 arg1) {
    u8 *temp_a2;

    temp_a2 = arg0 + 0xA8;
    func_15131828(arg0, arg0 + 0xAC, temp_a2, arg0 + 0xAA);
    func_15131958(arg0 + 0x58, *(s32 *)(temp_a2 + 0xC));
    return 1;
}

struct func_150AF738_s {
    u8 unk0;
    s8 unk1;
    u8 unk2;
    u8 pad3;
    s16 unk4;
    u8 unk6;
};

void *func_1515FF74(void *, s32, u8, s32);

void func_150AF738(s16 arg0, u8 arg1, s32 arg2) {
    struct func_150AF738_s sp18;

    sp18.unk0 = 1;
    sp18.unk1 = -1;
    sp18.unk2 = 2;
    sp18.unk6 = 0;
    sp18.unk4 = arg0;
    func_1515FF74(&sp18, 0, arg1, arg2);
}

void func_150B1DB0(u8 *arg0, u8 *arg1);

void func_150AF790(s32 arg0, u8 *arg1) {
    func_150B1DB0(arg1, arg1 + 0x1ECC0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF7C4.s")

struct func_150AFBF4_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

s32 func_150AFBF4(u8 *arg0) {
    struct func_150AFBF4_s *temp_v1;

    *(f32 *)(arg0 + 0x78) += *(f32 *)(arg0 + 0x7C) * D_800BE9A4;
    temp_v1 = (struct func_150AFBF4_s *)(arg0 + 0x70);
    temp_v1->unk8 = func_15144B68(*(f32 *)(arg0 + 0x78));
    *(f32 *)(arg0 + 0x10) = (sinf(temp_v1->unk8) * temp_v1->unk4) + temp_v1->unk0;
    return 1;
}

void *func_1516D99C();

void func_150AFC68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    func_1516D99C(1, 0, 0, 0xD, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0, 0xFF, 0, 1, 0, 0, 0, 0, 0xAA, 0xAA, 0xAA, 0xAA, arg2, arg3, 0, arg0, 0xF0, 0x50, 0x50, 1, 4, 0, 1, 0, 0, 0, arg1, 0, arg4, arg5);
}

struct func_150AFDB0_s {
    u8 pad0[8];
    struct func_150AFDB0_s *unk8;
    u8 padC[0x3F - 0xC];
    u8 unk3F;
};
extern struct func_150AFDB0_s *D_800DCE94;

void func_150AFDB0(void) {
    struct func_150AFDB0_s *obj;

    obj = D_800DCE94;
    D_800DD190++;
    while (obj != NULL) {
        ((struct func_150AFDB0_s **)D_800DD198)[D_800DD190] = obj->unk8;
        if (obj->unk3F == gCurrentObjectIndex) {
            func_1516972C((struct102 *)obj);
        }
        obj = ((struct func_150AFDB0_s **)D_800DD198)[D_800DD190];
    }
    D_800DD190--;
}

void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);
void func_150E1AB0(s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
void func_150E2DB4(void *arg0, u8 arg1, s16 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, s16 arg10, s16 arg11, u16 arg12, u8 arg13);

void func_150AFE64(s32 arg0) {
    f32 ax, ay, az;
    f32 bx, by, bz;
    s32 idx;
    u8 *mtx;

    if (gCurrentObject->unk1D4 != NULL) {
        if (arg0 == 0) {
            idx = 3;
        } else {
            idx = 2;
        }
        mtx = (u8 *)gCurrentObject->unk1D4 + (idx << 6);
        ax = 0.0f;
        ay = 0.0f;
        az = -20.0f;
        func_150A7960(mtx, 0.0f, 0.0f, -20.0f, &ax, &ay, &az);
        bx = 0.0f;
        by = 0.0f;
        bz = -150.0f;
        func_150A7960(mtx, 0.0f, 0.0f, -150.0f, &bx, &by, &bz);
        func_150E1AB0(0, ax, ay, az, bx, by, bz, 40.0f, 0.0f, 2.0f, 120.0f, 60, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        func_150E2DB4(gCurrentObject, gCurrentObject->unique_id, idx, -1, 0.0f, 0.0f, -39.0f, 0.0f, 0.0f, -150.0f, 3, 0xFF, 4, 0);
    }
}

void func_15179008(s32);
void func_150AF200(s32, s32);

void func_150B003C(s32 arg0) {
    if (D_800BE9F0 == 6) {
        func_15179008(0);
        func_150AF200(0xE2, 0xE1);
    } else {
        func_150AF200(0xDF, 0xDE);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0094.s")

struct func_150B02C0_s {
    u8 pad0[0x170];
    union {
        s32 w;
        struct102 *p;
    } unk170;
};

void func_150B02C0(struct func_150B02C0_s *arg0) {
    if (arg0->unk170.w != 0) {
        func_1516972C(arg0->unk170.p);
    }
}

void func_150B02F0(s32 arg0) {
    func_150B02C0(arg0);
    func_15132570(arg0);
}

void func_150B031C(s32 arg0) {
    func_150B02C0(arg0);
    func_1513259C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0348.s")

struct func_150B060C_s {
    f32 unk0;
    f32 unk4;
    s16 *unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

void *func_151149AC(u8);

s32 func_150B060C(u8 arg0, struct func_150B060C_s *arg1) {
    s16 *temp_v1;

    arg1->unk8 = func_151149AC(arg0);
    if (arg1->unk8 == NULL) {
        return 0;
    }
    arg1->unk0 = -150.0f;
    arg1->unk4 = 4.5f;
    temp_v1 = arg1->unk8;
    arg1->unkC = temp_v1[8];
    arg1->unk10 = temp_v1[9];
    arg1->unk14 = temp_v1[10];
    return 1;
}
