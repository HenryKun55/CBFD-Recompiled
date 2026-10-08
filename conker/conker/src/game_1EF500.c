#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C229C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2AD0.s")

struct func_151C2E4C_s {
    s32 unk0;
    u8 unk4;
};

s32 func_151C2E4C(struct func_151C2E4C_s *a0, struct func_151C2E4C_s *a1) {
    if (a0 == a1) {
        return 0;
    }
    if (a0->unk0 == 0) {
        return 0;
    }
    if (a0->unk4 == 0xFF) {
        return 0;
    }
    return 1;
}

struct func_151C2E94_s {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x127 - 5];
    u8 unk127;
};

s32 func_151C2E94(struct func_151C2E94_s *arg0, struct func_151C2E94_s *arg1) {
    if (arg0 == arg1) {
        return 0;
    }
    if (arg0->unk0 == 0) {
        return 0;
    }
    if (arg0->unk4 == 0xFF) {
        return 0;
    }
    if (arg0->unk127 == 0xFF) {
        return 0;
    }
    return 1;
}

struct func_151C2EF0_s {
    u8 pad0[1];
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x170 - 0xD];
    u8 unk170[0x44];
    s32 unk1B4;
};
void func_151D4DAC(s32, s32, s32, s32, s32, s32, void *, s32, s32);

void func_151C2EF0(s32 arg0, s32 arg1, struct func_151C2EF0_s *arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_151D4DAC(arg0, arg1, arg3, arg4, arg5, arg2->unk1B4, arg2->unk170, arg2->unkC, arg2->unk1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C329C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C36D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C3B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C436C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C43E0.s")

void func_151C4510(f32 *arg0, f32 *arg1, f32 arg2) {
    arg0[13] += arg1[1] * arg2;
    arg0[14] += arg1[2] * arg2;
    arg0[15] += arg1[3] * arg2;
}

extern void (*D_8008FBD0[])(s32);

struct func_151C455C_s {
    u8 unk0;
    u8 pad1[0x2F];
    u8 unk30[0x54];
    struct131 *unk84;
    u8 pad88[4];
    f32 unk8C;
    u8 pad90[0xC];
    s8 unk9C;
};

s32 func_151C455C(s32 arg0, struct func_151C455C_s *arg1, f32 arg2) {
    s32 ret = 1;

    arg1->unk8C -= arg2;
    if (arg1->unk8C <= 0.0f) {
        if (D_800E0940 != NULL && (arg1->unk0 & 1) && arg1->unk84 != NULL) {
            ((void (*)(void *, s32))D_800E0940)(arg1->unk30, arg1->unk84 - D_800DBEF4);
        }
        if (arg1->unk0 & 2) {
            if (arg1->unk9C != -1) {
                D_8008FBD0[arg1->unk9C](arg0);
            }
        }
        ret = 0;
    }
    return ret;
}

extern f32 D_800AAA80;
extern f32 D_800AAA84;
void *memcpy(void *, const void *, u32);

struct func_151C4644_s {
    s16 *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
};

struct func_151C4644_t {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x2C - 0xD];
    s32 unk2C;
};

struct func_151C4644_p {
    f32 v[17];
};

void func_151C4644(u8 *arg0) {
    struct func_151C4644_s *s;
    struct func_151C4644_p p;
    u8 *ret;

    s = (struct func_151C4644_s *)(arg0 + 0x28);
    ((struct func_151C4644_t *)arg0)->unk2C -= D_800BE9E4;
    if (((struct func_151C4644_t *)arg0)->unk2C < 0) {
        p.v[0] = s->unk1C;
        p.v[1] = s->unk20;
        p.v[2] = func_150ADA68() * s->unk24;
        p.v[3] = func_150ADA68() * s->unk24;
        p.v[4] = func_150ADA68() * D_800AAA80;
        p.v[5] = func_150ADA68() * D_800AAA84;
        p.v[6] = s->unk28;
        p.v[7] = s->unk28;
        p.v[8] = 0.0f;
        p.v[9] = func_150ADA68() * s->unk18 + s->unk14;
        p.v[10] = 0.0f;
        p.v[11] = s->unk0[0];
        p.v[12] = s->unk0[1];
        p.v[13] = s->unk0[2];
        p.v[14] = s->unk2C;
        p.v[15] = s->unk30;
        p.v[16] = s->unk34;
        ret = (u8 *)func_15149130((func_150ADA20() % (u32)(s->unk12 + 1)) + s->unk10, -1, 0x2B, -1, 1, 0, (struct37 *)0x44,
                                  ((struct func_151C4644_t *)arg0)->unkC, ((struct func_151C4644_t *)arg0)->unk1);
        if (ret != NULL) {
            memcpy(ret + 0x28, &p, 0x44);
        }
        s->unk4 = (func_150ADA20() % (u32)(s->unkC + 1)) + s->unk8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4B0C.s")
