#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_80099A10;
extern f32 D_80099A14;
extern f32 D_80099A18;
extern f32 D_80099A1C;
extern f32 D_80099A20;
extern f32 D_80099A24;

struct func_1506A5F0_s {
    /* 0x00 */ s16 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s16 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ s8 unk54;
    /* 0x55 */ s8 unk55;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
};

void func_151A6F00(struct func_1506A5F0_s *, s32, s32, s32);

void func_1506A5F0(s32 arg0, s32 arg1) {
    struct func_1506A5F0_s sp1C;

    sp1C.unk0 = 3;
    sp1C.unk4 = *(f32 *)(arg0 + 0x14);
    sp1C.unk8 = *(f32 *)(arg0 + 0x18);
    sp1C.unkC = *(f32 *)(arg0 + 0x1C);
    sp1C.unk14 = D_80099A10;
    sp1C.unk20 = D_80099A14;
    sp1C.unk24 = D_80099A18;
    sp1C.unk10 = 0x5A;
    sp1C.unk18 = 0;
    sp1C.unk1A = 0xFF;
    sp1C.unk1C = -0x40;
    sp1C.unk1E = 0x28;
    sp1C.unk30 = 0.0f;
    sp1C.unk34 = 0.0f;
    sp1C.unk38 = 0.0f;
    sp1C.unk54 = 0;
    sp1C.unk55 = 0;
    sp1C.unk56 = 0x32;
    sp1C.unk58 = 0x19;
    sp1C.unk3C = D_80099A1C;
    sp1C.unk40 = D_80099A20;
    sp1C.unk44 = D_80099A24;
    sp1C.unk48 = 0;
    sp1C.unk4C = -4.0f;
    sp1C.unk50 = 8.0f;
    func_151A6F00(&sp1C, 1, 0xFF, 1);
}

void func_1506A6FC(s32 arg0, s32 arg1) {
    func_150E0348(arg0, 0xFF, 1);
}

extern f32 D_800D1560[];
extern u8 D_800D1570[];
void func_151BB61C(s32 arg0, f32 *arg1, void *arg2, s32 arg3, s32 arg4);

void func_1506A724(s32 arg0, s32 arg1) {
    func_151BB61C(arg0, D_800D1560, D_800D1570, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A760.s")

void func_151D3480(f32 *arg0, f32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_1506A79C(s32 arg0, s32 arg1) {
    f32 sp2C[3];
    f32 sp20[3];

    sp2C[0] = ((f32 *)arg0)[5];
    sp2C[1] = ((f32 *)arg0)[6];
    sp2C[2] = ((f32 *)arg0)[7];
    sp20[0] = ((f32 *)D_800D1570)[0] - D_800D1560[0];
    sp20[1] = ((f32 *)D_800D1570)[1] - D_800D1560[1];
    sp20[2] = ((f32 *)D_800D1570)[2] - D_800D1560[2];
    func_151D3480(sp2C, sp20, 0, 0, 0xFF, 1);
}

void func_1506A83C(s32 arg0, s32 arg1) {
    func_151BC104(arg0, 0xFF, 1);
}

struct225 *func_151602C0(Header *header, Header2 *header2, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 offset, s32 arg9, s32 argA);
extern f32 D_80099A28;

struct func_1506A864_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_1506A864(struct func_1506A864_s *arg0, s32 arg1) {
    struct225 *temp_v0;
    Header header;
    f32 tmp[4];
    Header2 header2;

    header2.unk0 = arg0->unk14;
    header2.unk4 = arg0->unk18 + 50.0f;
    header2.unk8 = arg0->unk1C;
    tmp[0] = 0.0f;
    tmp[2] = 0.0f;
    header.unk0 = 2;
    header.unk1 = 0xF;
    header.unk2 = 300;
    header.unk4 = 5;
    tmp[1] = 80.0f;
    tmp[3] = D_80099A28;
    temp_v0 = func_151602C0(&header, &header2, 0, 0xFF, 0xFF, 0x5A, 0xFF, 0, sizeof(tmp), 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->unk18, tmp, sizeof(tmp));
    }
}

void func_151D3480(f32 *arg0, f32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_1506A968(u8 *arg0, s32 arg1) {
    f32 sp2C[3];
    f32 sp20[3];

    sp2C[0] = *(f32 *)(arg0 + 0x14);
    sp2C[1] = *(f32 *)(arg0 + 0x18);
    sp2C[2] = *(f32 *)(arg0 + 0x1C);
    sp20[0] = ((f32 *)D_800D1570)[0] - D_800D1560[0];
    sp20[1] = ((f32 *)D_800D1570)[1] - D_800D1560[1];
    sp20[2] = ((f32 *)D_800D1570)[2] - D_800D1560[2];
    func_151D3480(sp2C, sp20, 0, 1, 0xFF, 1);
}

void func_151B7144(s32, s32, s32);
void func_151B6320(s32, s32, s32);

void func_1506AA08(s32 arg0, s32 arg1) {
    func_151B7144(arg0, 0xFF, 1);
    func_151B6320(arg0, 0xFF, 1);
}

typedef struct {
    s32 unk0;
    s32 unk4;
} func_1506AA48_vec;

struct func_1506AA48_s {
    u8 *unk0;
    u8 unk4;
    func_1506AA48_vec unk8;
};

void func_1506AA48(u8 *arg0, func_1506AA48_vec *arg1) {
    struct260 *temp_v0;
    struct func_1506AA48_s tmp;

    tmp.unk0 = arg0;
    tmp.unk4 = arg0[0x3B];
    tmp.unk8 = *arg1;
    temp_v0 = func_15149130(0xA, 7, 0x23, -1, 1, 0x21, 0x10, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((char *) temp_v0 + 0x28, &tmp, 0x10);
    }
}

extern s32 D_800CC260;
void func_15137610(struct127 *arg0, f32 *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5);

void func_1506AAE0(s32 arg0, s32 arg1) {
    s32 var_s0;
    struct127 *var_s1;

    var_s0 = D_800CC260;
    var_s1 = gObjects;
    while (var_s0 != 0) {
        if (var_s0 & 1) {
            func_15137610(var_s1, D_800D1560, D_800D1570, 0, 0xFF, 1);
        }
        var_s0 >>= 1;
        var_s1++;
    }
}

void func_15103E40(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_1506AB7C(s32 arg0, s32 *arg1) {
    func_15103E40(arg0, arg1[0], &arg1[1], 1, arg1[4], 0xFF, 1);
}

void func_15103E40(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_1506ABC4(s32 arg0, s32 *arg1) {
    func_15103E40(arg0, arg1[0], &arg1[1], 2, arg1[4], 0xFF, 1);
}

struct func_1506AC0C_s {
    void *ptr;
    u8 b;
};

void func_1506AC0C(void *arg0, void *arg1) {
    struct func_1506AC0C_s sp20;

    sp20.ptr = arg0;
    sp20.b = *((u8 *)arg0 + 0x3B);
    func_151B7328(&sp20, 0, 8, 0xFF, 1);
}

void func_1506AC58(s32 arg0, s32 arg1) {
    func_151CEAAC(arg0, 0, 1, 0xFF, 1);
}

extern void (*D_80086110[])(void *, void *);
extern f32 D_800CC254;
extern f32 D_800CC258;
extern f32 D_800CC25C;

void func_1506AC8C(void *arg0, s32 arg1, void *arg2) {
    void (*func)(void *, void *);

    if ((arg1 >= 0) && (arg1 < 15)) {
        D_800D1560[0] = *(f32 *)((u8 *)arg0 + 0x2C);
        D_800D1560[1] = *(f32 *)((u8 *)arg0 + 0x30);
        D_800D1560[2] = *(f32 *)((u8 *)arg0 + 0x34);
        ((f32 *)D_800D1570)[0] = D_800CC254;
        ((f32 *)D_800D1570)[1] = D_800CC258;
        ((f32 *)D_800D1570)[2] = D_800CC25C;
        func = D_80086110[arg1];
        if (func != NULL) {
            func(arg0, arg2);
        }
    }
}
