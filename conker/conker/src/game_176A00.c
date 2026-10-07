#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149A94.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149EC4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AF74.s")

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
