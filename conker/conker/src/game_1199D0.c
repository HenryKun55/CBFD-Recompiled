#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC520.s")

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
