#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150C5DC0(s32 arg0) {
    if (*(s32 *)(arg0 + 0x58) != 0) {
        u8 *temp_v0 = *(u8 **)(arg0 + 0x58) + 0xB0;
        temp_v0[4] = 1;
    } else {
        *(s32 *)(arg0 + 0x58) = func_150C6460();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5E0C.s")

struct func_150C5EFC_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0xB0 - 0x1C];
    u8 *unkB0;
};

s32 func_1513F6C0(void *, s32, s32);

s32 func_150C5EFC(struct func_150C5EFC_s *arg0) {
    s32 *temp_v0;

    *(temp_v0 = (s32 *)(arg0->unkB0 + 0x58)) = 0;
    arg0->unkB0 = NULL;
    arg0->unk18 |= 2;
    func_1513F6C0(arg0, 0, 0);
    return 0;
}

struct func_150C5F40_inner {
    s32 unk0;
    u8 unk4;
};

struct func_150C5F40_obj {
    u8 pad0[0x58];
    struct func_150C5F40_inner unk58;
};

struct func_150C5F40_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x5C - 0x1C];
    s32 unk5C;
};

s32 func_150C5F94(s32);

void func_150C5F40(struct func_150C5F40_s *arg0) {
    s32 tmp = arg0->unk18;
    if (*(volatile s32 *)&arg0->unk5C != 0) {
        struct func_150C5F40_inner *p = &((struct func_150C5F40_obj *)arg0->unk5C)->unk58;
        p->unk4 = 1;
    } else {
        arg0->unk5C = func_150C5F94(tmp);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C60D8.s")

s32 func_150C63EC(u8 *arg0) {
    s32 ret = 1;
    if (arg0[0x5C] == 0) {
        ret = 0;
    }
    arg0[0x5C] = 0;
    return ret;
}

void func_151346EC(s32 arg0);

void func_150C6410(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *)(*(s32 *)(arg0 + 0x58) + 0x58);
    temp_v0[1] = 0;
    func_151346EC(arg0);
}

struct func_150C6438_sub {
    s32 unk0;
    s32 unk4;
};

struct func_150C6438_s {
    u8 pad0[0x58];
    struct func_150C6438_s *unk58;
};

void func_150C6438(struct func_150C6438_s *arg0) {
    struct func_150C6438_sub *s = (struct func_150C6438_sub *)((u8 *)arg0->unk58 + 0x58);
    s->unk4 = 0;
    func_1513470C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C6460.s")
