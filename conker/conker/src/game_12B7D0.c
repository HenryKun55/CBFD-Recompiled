#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12B7D0/func_150FE320.s")

typedef struct { f32 x, y, z; } func_150FE49C_s;
extern u8 D_80088B94;
extern s32 D_800A1FC8;
extern s32 D_800A1FD4;
void func_15145EA4();
void *func_151D3E6C();
void func_151D3F14(void *, u8, s32);
void func_150FE604(void *, void *, u8, s32);
void func_150FE7D4(u8 *);

void func_150FE49C(u8 *arg0, u8 arg1, s32 arg2, func_150FE49C_s *arg3, func_150FE49C_s *arg4) {
    func_150FE49C_s pos;
    func_150FE49C_s rot;
    void *src[2];
    void *dst[2];

    if (arg0 == NULL) {
        return;
    }
    if (*(s32 *)(arg0 + 0x1D4) != 0) {
        src[0] = &D_800A1FC8;
        src[1] = &D_800A1FD4;
        dst[0] = &pos;
        dst[1] = &rot;
        func_15145EA4(src, dst, *(s32 *)(arg0 + 0x1D4) + (D_80088B94 << 6), 2);
    } else {
        pos.x = *(f32 *)(arg0 + 0x14);
        pos.y = *(f32 *)(arg0 + 0x18) + 70.0f;
        pos.z = *(f32 *)(arg0 + 0x1C);
        rot = pos;
    }
    func_151D3E6C(arg0, &pos, &rot, 0x23);
    func_151D3F14(&pos, arg1, arg2);
    func_150FE604(arg0, &pos, arg1, arg2);
    func_150FE7D4(arg0);
    if (arg3 != NULL) {
        *arg3 = pos;
    }
    if (arg4 != NULL) {
        *arg4 = rot;
    }
}

extern s32 D_800A1FE0;
extern f32 D_800A1FF0;
extern f32 D_800A1FF4;
void func_15102B38(void *, u8, void *, void *, f32 *, s32, s32, f32, void *, u8, s32, s32, u8, s32);

void func_150FE604(void *arg0, void *arg1, u8 arg2, s32 arg3) {
    f32 sp60[2];
    u8 mask;
    u8 *p;
    u32 b;
    u32 a;

    if (*(s32 *)((u8 *)arg0 + 0x1D4) != 0 && (*((u8 *)arg0 + 0x74) & 0xF) != 0xF) {
        sp60[1] = func_150ADA68() * (f32)2 + D_800A1FF0;
        sp60[0] = func_150ADA68() * 15.0f + 35.0f;
        if (*(u8 **)((u8 *)arg0 + 0x31C) != NULL && (*(u8 **)((u8 *)arg0 + 0x31C))[0x197] != 0 &&
            *(u8 **)((u8 *)arg0 + 0x318) != NULL) {
            mask = ~(1 << (*(u8 **)((u8 *)arg0 + 0x318))[0x23D]) & 0xFF;
        } else {
            mask = 0xFF;
        }
        a = func_150ADA20();
        b = func_150ADA20();
        func_15102B38(arg0, D_80088B94, &D_800A1FC8, &D_800A1FE0, sp60, a % 3 + 4, b % 56 + 200,
                      func_150ADA68() * D_800A1FF4 + 500.0f, arg1, mask, 0, -1, arg2, arg3);
    }
}

extern u8 D_80088B94;
extern s32 D_800A1FC8;
void *func_151D3E04(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 arg4);

void func_150FE794(void *arg0, void *arg1, s32 arg2) {
    func_151D3E04(arg0, arg2, &D_800A1FC8, D_80088B94, 0.0f);
}

void func_150FE7D4(u8 *arg0) {
    struct {
        u8 f0;
        s16 f2;
        u8 f4;
        u8 f5;
        s8 f6;
    } local;

    if (*(s32 *)(arg0 + 0x318) != 0) {
        local.f0 = 1;
        local.f2 = (u32) func_150ADA20() % 13 + 20;
        local.f5 = 1 << *(u8 *)(*(u8 **)(arg0 + 0x318) + 0x23D);
        func_150ADA20();
        local.f4 = 8;
        local.f6 = -1;
        func_151D8868(&local, 0, 0xFF, 1);
    }
}
