#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15100600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101148.s")

struct func_151011E8_s {
    u8 pad0[0x124];
    u8 *unk124;
};

void func_151011E8(struct func_151011E8_s *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *)(arg0->unk124 + 0x110);
    temp_v0[10] = 0;
    func_1513CA6C(arg0);
}

struct func_15101210_s {
    u8 pad0[0x28];
    s32 unk28;
};

void func_15101210(u8 *arg0) {
    struct func_15101210_s *tmp = (struct func_15101210_s *)(*(u8 **)(arg0 + 0x124) + 0x110);
    tmp->unk28 = 0;
    func_1513CAA0();
}

void func_15101238(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *)(*(s32 *)(arg0 + 0x18) + 0x110);
    temp_v0[0xB] = 0;
    func_151617C4(arg0);
}

struct func_15101260_s {
    u8 pad0[0x18];
    u8 *unk18;
};

void func_151617E4(struct func_15101260_s *arg0);

void func_15101260(struct func_15101260_s *arg0) {
    u8 *tmp = arg0->unk18 + 0x110;
    *(s32 *)(tmp + 0x2C) = 0;
    func_151617E4(arg0);
}

void func_1513173C(void *arg0);

void func_15101288(void *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *)(*(s32 *)((u8 *)arg0 + 0xD0) + 0x110);
    temp_v0[9] = 0;
    func_1513173C(arg0);
}

struct func_151012B0_s {
    u8 pad0[0xD0];
    u8 *unkD0;
};

void func_1513175C(struct func_151012B0_s *);

void func_151012B0(struct func_151012B0_s *arg0) {
    s32 *temp = (s32 *)(arg0->unkD0 + 0x110);
    temp[9] = 0;
    func_1513175C(arg0);
}

void func_151012D8(u8 *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *)(*(u8 **)(arg0 + 0x170) + 0x110);
    temp_v0[12] = 0;
    func_151411A4(arg0);
}

struct func_15101300_s {
    u8 pad[0x170];
    u8 *unk170;
};

void func_15101300(struct func_15101300_s *arg0) {
    s32 *temp_v0 = (s32 *)(arg0->unk170 + 0x110);
    temp_v0[12] = 0;
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151019C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151022AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151025F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151026BC.s")

struct func_151027E8_s {
    void *unk0;
    u8 unk4;
};

void func_151027E8(void *arg0) {
    struct func_151027E8_s sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = *((u8 *)arg0 + 0x3B);
    func_151403A8(&sp18, 0x1A);
}

struct func_1510281C_s {
    u8 pad0[0xD0];
    u8 *unkD0;
    u8 unkD4;
};

s32 func_1510281C(struct func_1510281C_s *arg0, s16 arg1) {
    u8 *temp_v0 = arg0->unkD0 + 0x110;

    if ((arg1 == temp_v0[0x22]) && ((*(u8 **)temp_v0 == NULL) || ((*(u8 **)(*(u8 **)temp_v0 + 0x31C))[0x197] != 0))) {
        return 0;
    }
    if (!(arg0->unkD4 & 1)) {
        return 0;
    }
    return 1;
}

s32 func_15102884(u8 *arg0, s32 arg1) {
    if (!(arg0[0xAC] & 1)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151028AC.s")
