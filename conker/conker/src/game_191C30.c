#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15164780_s {
    u8 pad0[0x10];
    u8 unk10[0x38];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
};

struct func_15164780_s *func_15167A68(s32, s32, s32, s32, s32, s32);

struct func_15164780_s *func_15164780(u8 *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct func_15164780_s *v;
    struct108 *s = &D_800DBFF0[arg0[6]];
    u8 *q;

    if (s->unk3D0 != NULL) {
        q = *(u8 **)((u8 *)s->unk3D0 + 0x31C);
        if (q != NULL && q[0x198] != 0) {
            return NULL;
        }
    }
    v = func_15167A68(0x39, arg3, arg1 + 0x68, 1, arg2, 1);
    if (v == NULL) {
        return NULL;
    }
    memcpy(v->unk10, arg0, 0x38);
    v->unk60 = 1;
    v->unk61 = 1;
    v->unk62 = 1;
    v->unk63 = 1;
    v->unk64 = 1;
    v->unk65 = 1;
    v->unk48 = 0.0f;
    v->unk4C = 0.0f;
    v->unk50 = 0.0f;
    v->unk54 = 0.0f;
    v->unk58 = 0.0f;
    v->unk5C = 0.0f;
    return v;
}

void func_15164888(u8 *arg0) {
    arg0[0x10] |= 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_1516489C.s")

extern u8 D_800DCDE0[];

void func_15164EE4(void) {
    bzero(D_800DCDE0, 0x60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15165628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_151658DC.s")

struct func_15165B80_s {
    u8 pad[0x108];
    u8 unk108[0xC];
    s32 unk114;
    s32 unk118;
    f32 unk11C;
};

void func_15165BB0(struct func_15165B80_s *, void *, s32, s32, f32);

void func_15165B80(struct func_15165B80_s *arg0) {
    func_15165BB0(arg0, arg0->unk108, arg0->unk114, arg0->unk118, arg0->unk11C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15165BB0.s")
