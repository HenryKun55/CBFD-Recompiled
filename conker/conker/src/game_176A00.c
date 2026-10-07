#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149838.s")

void func_1513F680(struct171 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern f32 D_800A578C;
extern f32 D_800A5790;

struct func_15149A94_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    u8 pad5C[0x70 - 0x5C];
    u8 unk70;
    u8 unk71;
    u8 unk72;
    u8 unk73;
    u8 unk74;
    u8 pad75[0x110 - 0x75];
    f32 unk110[0x12];
    u8 unk158;
};

s32 func_15149A94(struct func_15149A94_s *arg0) {
    s32 ret = 1;
    u8 idx = 13;
    f32 *sub = arg0->unk110;

    if (!(arg0->unk74 & 2)) {
        arg0->unk2C += (sub[2] - arg0->unk2C) * sub[0x11];
        if (sub[2] * D_800A578C < arg0->unk2C) {
            arg0->unk74 |= 2;
        } else {
            ret = 0;
        }
    }
    if (!(arg0->unk74 & 8)) {
        arg0->unk30 += (sub[8] - arg0->unk30) * sub[0x11];
        if (sub[8] * D_800A5790 < arg0->unk30) {
            arg0->unk74 |= 8;
        } else {
            ret = 0;
        }
    }
    if (ret) {
        func_1513F680((struct171 *)arg0, arg0->unk70, idx, arg0->unk72, arg0->unk73);
    }
    if (arg0->unk1C < 5) {
        func_1513F680((struct171 *)arg0, arg0->unk70, arg0->unk158, arg0->unk72, arg0->unk73);
        arg0->unk1C = 100;
        arg0->unk58 &= ~1;
    }
    return 1;
}

struct func_15149BF4_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x150 - 0x34];
    f32 unk150;
};

s32 func_15149BF4(struct func_15149BF4_s *arg0) {
    arg0->unk2C -= arg0->unk2C * arg0->unk150;
    arg0->unk30 -= arg0->unk30 * arg0->unk150;
    if ((arg0->unk2C < 2.0f) || (arg0->unk30 < 2.0f)) {
        return 0;
    }
    return 1;
}

struct func_15149C58_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x38 - 0x34];
    f32 unk38;
    u8 pad3C[0x4C - 0x3C];
    f32 unk4C;
    f32 unk50;
    u8 pad54[0x150 - 0x54];
    f32 unk150;
    u8 pad154[0x15C - 0x154];
    f32 unk15C;
};

s32 func_15149C58(struct func_15149C58_s *arg0) {
    arg0->unk2C -= arg0->unk2C * arg0->unk150;
    arg0->unk30 -= arg0->unk30 * arg0->unk150;
    arg0->unk50 += arg0->unk4C * D_800BE9A4;
    arg0->unk38 += arg0->unk50 * D_800BE9A4;
    if (arg0->unk15C < arg0->unk38) {
        return 0;
    }
    if ((arg0->unk2C < 4.0f) || (arg0->unk30 < 4.0f)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149D18.s")

typedef struct {
    f32 x, y, z;
} func_15149EC4_v3;

struct func_15149EC4_s {
    func_15149EC4_v3 pos;   /* 0x00 */
    u8 pad0C[0x16 - 0x0C];
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    u8 unk30;
    u8 unk31;
};

s32 func_15149EC4(u8 *arg0) {
    struct func_15149EC4_s sp1C;

    sp1C.pos = *(func_15149EC4_v3 *)(arg0 + 0x34);
    sp1C.unk16 = 0;
    sp1C.unk18 = 0;
    sp1C.unk1A = sp1C.unk1C = (func_150ADA20() % 6U) + 8;
    sp1C.unk1E = 0;
    sp1C.unk20 = 0;
    sp1C.unk22 = (func_150ADA20() % 201U) + 100;
    sp1C.unk24 = (func_150ADA20() % 5U) + 3;
    sp1C.unk26 = 600;
    func_151429E0(3, &sp1C.unk28, &sp1C.unk29, &sp1C.unk2A);
    func_151429E0(4, &sp1C.unk2B, &sp1C.unk2C, &sp1C.unk2D);
    sp1C.unk2E = 0xFF;
    sp1C.unk2F = (func_150ADA20() % 65U) + 0x5C;
    sp1C.unk30 = (func_150ADA20() % 3U) + 1;
    sp1C.unk31 = 0;
    func_1518CA80(&sp1C, 1);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A380.s")

struct func_1514A498_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x5C - 0x34];
    u8 unk5C;
    u8 pad5D[0x144 - 0x5D];
    f32 unk144;
    u8 pad148[0x156 - 0x148];
    s16 unk156;
    s16 unk158;
};

s32 func_1514A498(struct func_1514A498_s *arg0) {
    arg0->unk30 -= arg0->unk30 * arg0->unk144;
    arg0->unk2C -= arg0->unk2C * arg0->unk144;
    if (arg0->unk1C < arg0->unk156) {
        arg0->unk5C = arg0->unk1C * arg0->unk158;
    }
    return 1;
}

typedef struct {
    f32 x, y, z;
} func_1514A4EC_vec;

struct func_1514A4EC_s {
    u8 pad0[0x34];
    func_1514A4EC_vec unk34;
    func_1514A4EC_vec unk40;
    u8 pad4C[0x130 - 0x4C];
    f32 unk130;
    f32 unk134;
    f32 unk138;
    f32 unk13C;
    f32 unk140;
};

s32 func_1514A4EC(struct func_1514A4EC_s *arg0) {
    func_1514A4EC_vec *pos = &arg0->unk34;

    arg0->unk40 = *pos;
    arg0->unk130 *= arg0->unk140;
    arg0->unk134 += arg0->unk13C * D_800BE9A4;
    arg0->unk138 *= arg0->unk140;
    pos->x += arg0->unk130 * D_800BE9A4;
    pos->y += arg0->unk134 * D_800BE9A4;
    pos->z += arg0->unk138 * D_800BE9A4;
    return 1;
}

struct func_1514A594_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x54 - 0x4C];
    f32 unk54;
    u8 pad58[0x130 - 0x58];
    f32 unk130;
    f32 unk134;
    f32 unk138;
    f32 unk13C;
    f32 unk140;
};

s32 func_1514A594(struct func_1514A594_s *arg0) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 x;
    volatile f32 t;

    arg0->unk130 *= arg0->unk140;
    arg0->unk134 += arg0->unk13C * D_800BE9A4;
    arg0->unk138 *= arg0->unk140;
    dx = arg0->unk130 * D_800BE9A4;
    dy = arg0->unk134 * D_800BE9A4;
    dz = arg0->unk138 * D_800BE9A4;
    arg0->unk34 += dx;
    arg0->unk38 += dy;
    arg0->unk3C += dz;
    arg0->unk40 += dx;
    arg0->unk44 += dy;
    arg0->unk48 += dz;
    x = arg0->unk34;
    t = arg0->unk54;
    arg0->unk40 = (f32)x + (arg0->unk40 - x) * t;
    arg0->unk44 = arg0->unk38 + (arg0->unk44 - arg0->unk38) * t;
    arg0->unk48 = arg0->unk3C + (arg0->unk48 - arg0->unk3C) * t;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AD9C.s")

struct func_1514AF74_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x38 - 0x34];
    f32 unk38;
    u8 pad3C[0x4C - 0x3C];
    f32 unk4C;
    f32 unk50;
    u8 pad54[0x150 - 0x54];
    f32 unk150;
};

s32 func_1514AF74(struct func_1514AF74_s *arg0) {
    arg0->unk2C -= arg0->unk2C * arg0->unk150;
    arg0->unk30 -= arg0->unk30 * arg0->unk150;
    arg0->unk38 += arg0->unk50 * D_800BE9A4 + 0.5f * arg0->unk4C * D_800BE9A4 * D_800BE9A4;
    arg0->unk50 += arg0->unk4C * D_800BE9A4;
    if (arg0->unk2C < 10.0f || arg0->unk30 < 10.0f) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514B034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514B364.s")

s32 func_1514B844(void *arg0) {
    s16 temp_v1;
    s32 temp_a0;
    u8 *temp_v0;

    temp_v0 = *(u8 **)((u8 *)arg0 + 0x98);
    temp_v1 = *(s16 *)((u8 *)arg0 + 0x1C);
    if (temp_v1 < 0x10) {
        temp_a0 = temp_v1 * 0x10;
        if (temp_a0 < temp_v0[0x1B]) {
            temp_v0[0x1B] = temp_a0;
        }
    }
    return 1;
}

struct func_1514B87C_s {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    char pad34[0x18];
    f32 unk4C;
};

s32 func_1514B87C(struct func_1514B87C_s *arg0) {
    f32 temp = arg0->unk4C * D_800BE9A4;
    arg0->unk2C += temp;
    arg0->unk30 += temp;
    return 1;
}

struct func_1514B8B0_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x5C - 0x1E];
    u8 unk5C;
};

s32 func_1514B8B0(struct func_1514B8B0_s *arg0) {
    if (arg0->unk1C < 16) {
        if ((arg0->unk1C * 16) < arg0->unk5C) {
            arg0->unk5C = arg0->unk1C * 16;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514B8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514BC08.s")

void func_1514BC08(void *arg0, void *arg1);

void func_1514BE00(u8 *arg0) {
    func_1514BC08(arg0, arg0 + 0x110);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514BE20.s")

struct func_1514BF50_s {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
};

void func_1514BF50(struct func_1514BF50_s *arg0) {
    arg0->unk40 = arg0->unk34;
    arg0->unk44 = arg0->unk38 + 100.0f;
    arg0->unk48 = arg0->unk3C;
}

void func_1514BC08();

void func_1514BF7C(u8 *arg0) {
    func_1514BC08(arg0, arg0 + 0x110);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514BF9C.s")

void func_1514BF9C(void *arg0);
void func_1514BE20(void *arg0);

s32 func_1514C258(void *arg0) {
    func_1514BF9C(arg0);
    func_1514BE20(arg0);
    return 1;
}

s32 func_1514C288(s32 arg0) {
    func_1514BF9C(arg0);
    func_1514BF50(arg0);
    return 1;
}

struct func_1514C2B8_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x58 - 0x1E];
    s32 unk58;
    u8 pad5C[0x71 - 0x5C];
    u8 unk71;
    u8 unk72;
    u8 pad73[0x154 - 0x73];
    f32 unk154;
    u8 pad158[0x160 - 0x158];
    f32 unk160;
    s16 unk164;
};

s32 func_1514C2B8(struct func_1514C2B8_s *arg0) {
    arg0->unk72 = 0;
    arg0->unk71 = 0x24;
    arg0->unk1C = arg0->unk164;
    arg0->unk58 |= 0x08000000;
    arg0->unk154 = arg0->unk160;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C858.s")
