#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512A390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512ABF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512AD54.s")

struct func_1512B100_s {
    u8 pad0[0x2C];
    s32 unk2C;
    u8 pad30[0x84 - 0x30];
    s32 unk84;
    u8 pad88[0x23C - 0x88];
    u8 unk23C;
    u8 pad23D[0x5F0 - 0x23D];
    s32 unk5F0;
    u8 pad5F4[4];
    s16 unk5F8;
    u8 pad5FA[2];
    s16 unk5FC;
    s16 unk5FE;
};

void func_1512AD54(struct func_1512B100_s *arg0);

void func_1512B100(struct func_1512B100_s *arg0) {
    if ((arg0->unk2C & ~0x100) && !D_800BEAC0 && !D_800C3671) {
        if ((arg0->unk2C != 0x40) && (arg0->unk84 & 8) && !(arg0->unk84 & 0x200) && !arg0->unk23C &&
            !(arg0->unk5F0 & 0x80) && !(arg0->unk5F0 & 0x40)) {
            func_1512AD54(arg0);
        } else {
            arg0->unk5F8 = 1;
            arg0->unk5FC = 2;
            arg0->unk5FE = 0x3C;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B1B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B53C.s")

struct func_1512B5FC_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    s32 unk4;
    s32 unk8;
};

void func_1512B5FC(struct func_1512B5FC_s *arg0, s32 arg1, s32 arg2) {
    arg0->unk2 = arg0->unk1;
    if (arg0->unk4 < arg1) {
        arg0->unk1 = 0;
    } else {
        arg0->unk1 = 1;
    }
    arg0->unk8 = arg2;
    arg0->unk4 = arg1;
}

struct func_1512B630_s {
    u8 pad0[0x84];
    s32 unk84;
    u8 pad88[0x1B4 - 0x88];
    s16 unk1B4;
    u8 pad1B6[0x23D - 0x1B6];
    u8 unk23D;
};

extern s16 D_800DC204[][4][4];
extern s16 D_800DC206[][4][4];

s32 func_1512B630(struct func_1512B630_s *arg0, struct func_1512B5FC_s *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_v0;

    if (arg5 == 0) {
        var_v0 = D_800DC204[arg0->unk23D][arg0->unk1B4][0];
    } else {
        var_v0 = D_800DC206[arg0->unk23D][arg0->unk1B4][0];
    }
    if (arg0->unk84 & 0x8000) {
        var_v0 = (s16)(var_v0 * 2);
    }
    if ((var_v0 < arg2) && (arg3 < arg4)) {
        arg1->unk0 = 2;
        func_1512B5FC(arg1, arg3, arg2);
        return 1;
    }
    if ((var_v0 < arg2) && (arg4 < arg3)) {
        arg1->unk0 = 1;
        func_1512B5FC(arg1, arg3, arg2);
        return 1;
    }
    arg1->unk1 = 0;
    arg1->unk0 = 0;
    arg1->unk8 = 0xFFFC;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512BB10.s")

struct func_1512C068_s {
    u8 pad0[0x2C];
    s32 unk2C;
    u8 pad30[0x240 - 0x30];
    s32 unk240;
    u8 pad244[0x2BC - 0x244];
    f32 unk2BC;
    f32 unk2C0;
    f32 unk2C4;
    u8 pad2C8[0x2F8 - 0x2C8];
    f32 unk2F8;
    f32 unk2FC;
    f32 unk300;
    u8 pad304[0x370 - 0x304];
    f32 unk370;
    u8 pad374[0x37C - 0x374];
    f32 unk37C;
    f32 unk380;
    f32 unk384;
    u8 pad388[0x390 - 0x388];
    f32 unk390;
    u8 pad394[0x5CC - 0x394];
    f32 unk5CC;
};

void func_15123A54(struct func_1512C068_s *);
void func_1512C150(struct func_1512C068_s *);

void func_1512C068(struct func_1512C068_s *arg0) {
    f32 dx;
    f32 dz;
    f32 sign;

    if (arg0->unk390 < 180.0f) {
        sign = 2.0f;
    } else {
        sign = -2.0f;
    }
    if (arg0->unk2C != 0x80 && arg0->unk2C != 0x40) {
        dx = arg0->unk2F8 - arg0->unk2BC;
        dz = arg0->unk300 - arg0->unk2C4;
        arg0->unk370 = sqrtf(dx * dx + dz * dz);
        if (arg0->unk370 < 42.0f) {
            arg0->unk384 = arg0->unk37C - 45.0f * sign;
            arg0->unk5CC = 0.0f;
            func_15123A54(arg0);
            arg0->unk240 |= 2;
        }
    }
    func_1512C150(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C150.s")

void func_1512C200(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C47C.s")
