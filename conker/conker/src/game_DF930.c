#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_150B2480(s32 arg0, s32 arg1) {
    return 10;
}

void *func_1514C678(f32, f32, f32, f32, s32, s32, s32, s32, s32, f32, s32, s32);
void *func_151D3FF4();

void func_150B2494(struct127 *arg0, s32 arg1, s32 arg2) {
    struct17 sp3C;

    sp3C.unk0 = arg0->x_position;
    sp3C.unk4 = arg0->unk180;
    sp3C.unk8 = arg0->z_position;
    func_1514C678(sp3C.unk0, sp3C.unk4, sp3C.unk8, 135.0f, 0, 0xFF, (func_150ADA20() % 15U) + 0x1B, 7, 0, 0.0f, 0, 0xFF);
    func_151D5404(&sp3C, 1502.0f, 3000.0f, 0.0003333333333333333f, 0xC, 0xF, 0xFF, 0);
    func_151D3FF4(&sp3C, 0xFF, 0);
}

void func_151429E0(s32, u8 *, u8 *, u8 *);
void *func_15156190(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 D_8009F900;
extern f32 D_8009F904;
extern f32 D_8009F908;
extern f32 D_8009F90C;
extern f32 D_8009F910;
extern f32 D_8009F914;

struct func_150B2570_s {
    f32 pos[3];
    f32 vel[3];
    f32 unk18;
    f32 unk1C;
    u8 col1[4];
    u8 col2[4];
    u8 unk28;
    s16 unk2A;
    s16 unk2C;
    f32 unk30;
    u8 unk34;
    s16 unk36;
    s16 unk38;
};

s32 func_150B2570(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, u8 argE) {
    s32 pad;
    struct func_150B2570_s p;
    s16 sp36;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 temp;

    sp30 = func_151423D8(arg8 - 0x40);
    sp2C = func_151423D8(arg8);
    sp36 = (func_150ADA20() % 21U) - 30;
    sp28 = func_151423D8(sp36 - 0x40);
    temp = func_151423D8(sp36);
    p.pos[0] = arg2;
    p.pos[1] = arg3;
    p.pos[2] = arg4;
    p.vel[0] = 10.0f * temp * sp30;
    p.vel[1] = -10.0f * sp28;
    p.vel[2] = 10.0f * temp * sp2C;
    p.unk18 = (func_150ADA68() * D_8009F900) + D_8009F904;
    p.unk1C = (func_150ADA68() * D_8009F908) + D_8009F90C;
    func_151429E0(8, &p.col1[0], &p.col1[1], &p.col1[2]);
    func_151429E0(8, &p.col2[0], &p.col2[1], &p.col2[2]);
    p.col1[3] = 0xFF;
    p.col2[3] = 0xFF;
    p.unk28 = 9;
    p.unk2A = (func_150ADA20() % 7U) + 0x12;
    p.unk30 = (func_150ADA68() * D_8009F910) + D_8009F914;
    p.unk2C = 0x1601;
    p.unk34 = 0xFF;
    p.unk36 = 8;
    p.unk38 = 0x1F;
    func_15156190(&p, 1, 0, argE, 1);
    return 1;
}
