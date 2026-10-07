#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_8009FBC0[];
void func_1514C858(f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, f32, s32, s32);
void func_151D3FF4();

void func_150B3AB0(u8 *arg0, volatile u8 arg1) {
    struct {
        f32 x;
        f32 y;
        f32 z;
        s16 pad;
        s16 rot;
    } pos;
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    if (arg0 != NULL) {
        if (*(s32 *)(arg0 + 0x1D4) != 0) {
            func_1512D748(&D_800DBFF0[D_800BE9E8], 6, 1);
            pos.rot = (*(u16 *)(arg0 + 0x7A) >> 8) + 0x40;
            func_15143134(D_8009FBC0, &pos, *(s32 *)(arg0 + 0x1D4) + 0x640);
            func_1514C858(pos.x, pos.y, pos.z, 10.0f, pos.rot, 0, 0xFF, (u32) func_150ADA20() % 31 + 40, 8, 0, 0.0f, 0, arg1);
            local.f0 = 1;
            local.f2 = (func_150ADA20() & 0xF) + 12;
            local.f4 = (func_150ADA20() & 3) + 5;
            local.f6 = -1;
            local.f5 = 1;
            func_151D8868(&local, 0, arg1, 0);
            func_151D3FF4(&pos, arg1, 0);
        }
    }
}

void func_151429E0(s32, u8 *, u8 *, u8 *);
void *func_15156190(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_15156388(void *, s32, s32);
extern f32 D_8009FBCC;
extern f32 D_8009FBD0;
extern f32 D_8009FBD4;
extern f32 D_8009FBD8;
extern f32 D_8009FBDC;
extern f32 D_8009FBE0;

struct func_150B3C0C_s {
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

s32 func_150B3C0C(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, u8 argE) {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 temp;
    struct func_150B3C0C_s p;

    sp6C = func_151423D8(arg9 - 0x40);
    sp68 = func_151423D8(arg9);
    sp64 = func_151423D8(arg8 - 0x40);
    temp = func_151423D8(arg8);
    p.pos[0] = arg2;
    p.pos[1] = arg3;
    p.pos[2] = arg4;
    p.vel[0] = 10.0f * temp * sp6C;
    p.vel[1] = -10.0f * sp64;
    p.vel[2] = 10.0f * temp * sp68;
    p.unk18 = (func_150ADA68() * D_8009FBCC) + D_8009FBD0;
    p.unk1C = (func_150ADA68() * D_8009FBD4) + D_8009FBD8;
    func_151429E0(8, &p.col1[0], &p.col1[1], &p.col1[2]);
    func_151429E0(8, &p.col2[0], &p.col2[1], &p.col2[2]);
    p.col1[3] = 0xFF;
    p.col2[3] = 0xFF;
    p.unk28 = 9;
    p.unk2A = (func_150ADA20() & 0xF) + 0xF;
    p.unk30 = (func_150ADA68() * D_8009FBDC) + D_8009FBE0;
    p.unk2C = 0x1601;
    p.unk34 = 0xFF;
    p.unk36 = 0xA;
    p.unk38 = 0x19;
    func_15156190(&p, 1, 0, argE, 1);
    func_15156388(&p, 1, 0);
    return 1;
}
