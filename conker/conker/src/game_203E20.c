#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151D6970(s32 arg0, s32 arg1) {
    if ((D_800BE9F0 == 0x32) || (D_800BE9F0 == 0x33)) {
        func_150D6730(arg0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D69B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D6BFC.s")

extern f32 func_15144AA8(s32);
extern f32 D_800AB278;

struct func_151D6E60_s1 {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct func_151D6E60_s {
    u8 pad0[0x4C];
    struct func_151D6E60_s1 *unk4C;
    u8 pad50[0x2C];
    f32 unk7C[2][4][4];
};

s32 func_151D6E60(struct func_151D6E60_s *arg0) {
    f32 scale;

    func_150A8050(arg0->unk7C[D_800BE9C0], 0.0f, func_15144AA8(0) + 25.0f, 0.0f);
    scale = D_800AB278;
    arg0->unk7C[D_800BE9C0][3][0] = arg0->unk4C->unk14;
    arg0->unk7C[D_800BE9C0][3][1] = arg0->unk4C->unk18 + 120.0f;
    arg0->unk7C[D_800BE9C0][3][2] = arg0->unk4C->unk1C;
    arg0->unk7C[D_800BE9C0][0][0] *= scale;
    arg0->unk7C[D_800BE9C0][0][1] *= scale;
    arg0->unk7C[D_800BE9C0][0][2] *= scale;
    arg0->unk7C[D_800BE9C0][1][0] *= scale;
    arg0->unk7C[D_800BE9C0][1][1] *= scale;
    arg0->unk7C[D_800BE9C0][1][2] *= scale;
    arg0->unk7C[D_800BE9C0][2][0] *= scale;
    arg0->unk7C[D_800BE9C0][2][1] *= scale;
    arg0->unk7C[D_800BE9C0][2][2] *= scale;
    return 1;
}

struct func_151D7000_s2 {
    s32 unk0;
    u8 pad4[0x37];
    u8 unk3B;
};
struct func_151D7000_s1 {
    struct func_151D7000_s2 *unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    s16 unkC;
    s16 unkE;
};
extern u8 D_800AB254[];
void func_15042E3C(void *arg0, ...);

s32 func_151D7000(s32 arg0) {
    s32 pad;
    struct func_151D7000_s1 *temp_v1;
    struct func_151D7000_s2 *temp_a2;
    s16 var_v0;
    s16 temp_a0;

    temp_v1 = *(struct func_151D7000_s1 **)(arg0 + 0x48);
    temp_a2 = temp_v1->unk0;

    if ((temp_a2->unk0 == 0) || (temp_a2->unk3B != temp_v1->unk4)) {
        return 0;
    }
    temp_a0 = *(s16 *)(arg0 + 0xE);
    if (temp_a0 < temp_v1->unkC) {
        var_v0 = temp_a0 * temp_v1->unkE;
        if (var_v0 < 0) {
            var_v0 = 0;
        }
    } else {
        var_v0 = 0xFF;
    }
    func_150432CC(temp_a2, 0x109);
    func_1504332C(0x32, 0x7D, 0x1C, var_v0);
    func_15042D78(0x81);
    func_15042E3C(D_800AB254, temp_v1->unk8);
}

void func_151D70CC(u8 *arg0, void *arg1, u8 arg2) {
    u8 *temp = *(u8 **)(arg0 + 0x48);
    func_15169850(arg1, arg2, temp, temp + 4, arg0);
}

extern u8 D_80083740[];
extern u8 D_800838C0[];
Gfx *func_15133EEC(Gfx *arg0, s32 arg1, s32 arg2, s32 arg3);

Gfx *func_151D710C(Gfx *arg0, u8 *arg1, s32 arg2, s32 arg3, u8 *arg4) {
    if (arg1[0x43] < 0xFF) {
        gSPSegment(arg0++, 0x08, D_80083740);
    } else {
        gSPSegment(arg0++, 0x08, D_800838C0);
    }
    arg0 = func_15133EEC(arg0, 0xC3, 6, 3);
    arg0 = func_15133EEC(arg0, 0xC3, 7, 3);
    *arg4 = 1;
    return arg0;
}
