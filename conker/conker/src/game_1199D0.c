#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150EC520_s {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

void func_151432BC(void *, f32 *, f32 *, f32 *, f32 *);
s32 func_151464B8(void *);
extern f32 D_800A1570;
extern f32 D_800A1574;

void func_150EC520(u8 *arg0) {
    struct260 *ret;
    struct func_150EC520_s s;
    f32 sp68;
    f32 *p;

    if (func_151464B8(*(void **)(arg0 + 0x30)) != 0) {
        return;
    }
    p = (f32 *)(arg0 + 0x28);
    p[3] += (D_800A1570 + func_150ADA68() * D_800A1574) * p[1] * D_800BE9A4;
    if (p[3] > 1.0f) {
        s.w = 0.0f;
        do {
            func_151432BC(*(void **)p, &s.x, &s.z, &sp68, &s.y);
            ret = func_15149130((func_150ADA20() % 131U) + 0x50, -1, 0x5A, -1, 1, 0, (struct37 *)0x10, arg0[0xC], arg0[1]);
            if (ret != NULL) {
                memcpy((char *)ret + 0x28, &s, 0x10);
            }
            p[3] -= 1.0f;
        } while (p[3] > 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECA68.s")

void func_150ECB4C(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

struct func_150ECB8C_s {
    s32 unk0;
    u8 pad4[0x3B - 4];
    u8 unk3B;
};
struct func_150ECB8C_t {
    struct func_150ECB8C_s *p;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
};
void func_1502EA98();

void func_150ECB8C(u8 *arg0) {
    struct func_150ECB8C_t *v = (struct func_150ECB8C_t *)(arg0 + 0x28);
    struct func_150ECB8C_s *p = v->p;

    if ((p->unk0 == 0) || (p->unk3B != v->unk4)) {
        *(s16 *)(arg0 + 0xE) = -1;
        return;
    }
    func_1502EA98(p, v->unk5, v->unk6, v->unk7, v->unk8, 0, v->unk9);
}

void func_151C9AC0(void *, u8, s32);
void func_150ECA68(void *, s32, s32, s32, s32, s32, s32, u8, s32);

void func_150ECC00(void *arg0, u8 arg1, s32 arg2) {
    func_151C9AC0(arg0, arg1, arg2);
    func_150ECA68(arg0, 0, 0xFF, 0, 0xFF, 4, -1, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECC70.s")
