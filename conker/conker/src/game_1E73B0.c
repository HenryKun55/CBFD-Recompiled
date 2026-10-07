#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151B9F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BBA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BBEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BBFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC370.s")

struct func_151BC580_s {
    char pad0[0x40];
    s32 *unk40;
};

s32 func_151BC580(struct func_151BC580_s *arg0) {
    s32 *temp_v0 = arg0->unk40;

    if (*temp_v0 == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC5A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BCA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD21C.s")

struct func_151BD2BC_s2 {
    s32 unk0;
    u8 pad4[0x37];
    u8 unk3B;
};

struct func_151BD2BC_s {
    u8 pad0[0x28];
    struct func_151BD2BC_s2 *unk28;
    u8 unk2C;
};

s32 func_151BD2BC(struct func_151BD2BC_s *arg0) {
    struct func_151BD2BC_s2 *temp = arg0->unk28;

    if (temp->unk0 == 0) {
        return 0;
    }
    if (temp->unk3B != arg0->unk2C) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD2F8.s")

struct func_151BD42C_s {
    u8 pad[0x80];
    s16 unk80;
};

s32 func_151BD42C(struct func_151BD42C_s *arg0) {
    arg0->unk80 = 0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD43C.s")

extern f32 D_800AA860;
extern f32 D_800AA864;

struct func_151BD750_s {
    u8 pad0[0x80];
    s16 unk80;
};

f32 func_151BD750(struct func_151BD750_s *arg0) {
    f32 ret;

    ret = (f32)arg0->unk80 * 2 * D_800AA860 + D_800AA864;
    arg0->unk80 += D_800BE9E4;
    return ret;
}

struct func_151BD79C_s {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x14 - 0x5];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_1513170C(void *arg0);

void func_151BD79C(void *arg0) {
    struct func_151BD79C_s *temp_v0 = *(struct func_151BD79C_s **)((u8 *)arg0 + 0xB0);

    if (temp_v0->unk0 != 0 && temp_v0->unk4 != 0xFF) {
        *(f32 *)((u8 *)arg0 + 0x4C) = temp_v0->unk14;
        *(f32 *)((u8 *)arg0 + 0x50) = temp_v0->unk18;
        *(f32 *)((u8 *)arg0 + 0x54) = temp_v0->unk1C;
    }
    func_1513170C(arg0);
}

struct func_151BD7F4_s {
    u8 *ptr;
    u8 id;
};

void func_151BD7F4(u8 *arg0) {
    struct func_151BD7F4_s sp18;

    sp18.ptr = arg0;
    sp18.id = arg0[0x3B];
    func_151494E0(&sp18, 0x3B);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BDD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE138.s")

void func_151BE1B8(s32 arg0) {
    func_151BE138(arg0);
    func_1514933C(arg0);
}

void func_151BE1E4(s32 arg0) {
    func_151BE138(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE558.s")

void func_151BE604(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x110, arg0 + 0x114, arg0);
}

struct func_151BE644_s {
    s32 unk0;
    s32 unk4;
    s32 unk8[1];
};

struct func_151BE644_t {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[0x4A];
    u8 *unk50;
};

void func_151BE644(u8 *arg0) {
    struct func_151BE644_t *temp = (struct func_151BE644_t *)(arg0 + 0x110);
    struct func_151BE644_s *p;

    if (temp->unk50 != NULL) {
        p = (struct func_151BE644_s *)(temp->unk50 + 0x28);
        p->unk8[temp->unk5] = 0;
    }
}

void func_151BE674(s32 arg0) {
    func_151BE644(arg0);
    func_1513CA6C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE6CC.s")

void func_151BE788(s32 arg0, s32 arg1, s32 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x180, arg0 + 0x184, arg0);
}

struct func_151BE7C8_s {
    u8 pad0[0x10];
    s32 unk10[1];
};

struct func_151BE7C8_t {
    u8 pad0[8];
    u8 *unk8;
    u8 unkC;
};

void func_151BE7C8(u8 *arg0) {
    struct func_151BE7C8_t *temp = (struct func_151BE7C8_t *)(arg0 + 0x170);
    struct func_151BE7C8_s *s;

    if (temp->unk8 != NULL) {
        s = (struct func_151BE7C8_s *)(temp->unk8 + 0x28);
        s->unk10[temp->unkC] = 0;
    }
}

void func_151BE7F8(s32 arg0) {
    func_151BE7C8(arg0);
    func_151411A4(arg0);
}

void func_151BE824(s32 arg0) {
    func_151BE7C8(arg0);
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BEB20.s")

s32 func_151BEC94(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    *arg4 = 1;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BECB8.s")

struct func_151BEE94_s {
    void *unk0;
    u8 unk4;
    u8 pad5[0x127 - 5];
    u8 unk127;
};

s32 func_151BEE94(struct func_151BEE94_s *arg0) {
    if (arg0->unk127 == 0xFF) {
        return 0;
    }
    if (arg0->unk0 == NULL) {
        return 0;
    }
    if (arg0->unk4 == 0xFF) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BEEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF0C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BFB2C.s")

void func_151BFB2C(s32 arg0);

void func_151BFBA4(s32 arg0) {
    func_151BFB2C(arg0);
    func_1514933C(arg0);
}

void func_151BFBD0(s32 arg0) {
    func_151BFB2C(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BFBFC.s")
