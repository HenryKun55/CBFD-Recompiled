#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150C66F0_s {
    u8 pad0[0x6C];
    u8 *unk6C;
};

void *func_150C6D90(struct func_150C66F0_s *arg0);

void func_150C66F0(struct func_150C66F0_s *arg0) {
    if (*(s32 *)&arg0->unk6C != 0) {
        u8 *p = arg0->unk6C + 0xB0;
        p[4] = 1;
    } else {
        arg0->unk6C = func_150C6D90(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C673C.s")

typedef struct func_150C682C_sub { u8 pad[0x14]; s32 unk14; } func_150C682C_sub;
struct func_150C682C_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0xB0 - 0x1C];
    struct { u8 pad[0x58]; func_150C682C_sub sub; } *unkB0;
};
void func_1513F6C0(void *arg0, u8 arg1, u8 arg2);

s32 func_150C682C(struct func_150C682C_s *arg0) {
    func_150C682C_sub *s = &arg0->unkB0->sub;
    s->unk14 = 0;
    arg0->unkB0 = NULL;
    arg0->unk18 |= 2;
    func_1513F6C0(arg0, 0, 0);
    return 0;
}

struct func_150C6870_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x70 - 0x1C];
    u8 *unk70;
};

u8 *func_150C68C4(s32);

void func_150C6870(struct func_150C6870_s *arg0) {
    s32 temp = arg0->unk18;
    if (*(s32 *)&arg0->unk70 != 0) {
        u8 *p = arg0->unk70 + 0x58;
        p[4] = 1;
    } else {
        arg0->unk70 = func_150C68C4(temp);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C68C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6A08.s")

s32 func_150C6D1C(u8 *arg0) {
    s32 ret = 1;
    if (arg0[0x5C] == 0) {
        ret = 0;
    }
    arg0[0x5C] = 0;
    return ret;
}

struct func_150C6D40_s {
    u8 pad0[0x58];
    struct func_150C6D40_s *unk58;
};

void func_150C6D40(struct func_150C6D40_s *arg0) {
    s32 *p = (s32 *)((u8 *)arg0->unk58 + 0x58);
    p[6] = 0;
    func_151346EC(arg0);
}

struct func_150C6D68_s {
    u8 pad0[0x58];
    struct func_150C6D68_s *unk58;
};
void func_1513470C(struct func_150C6D68_s *arg0);

void func_150C6D68(struct func_150C6D68_s *arg0) {
    struct func_150C6D68_s *temp = (struct func_150C6D68_s *)&arg0->unk58->unk58;
    *(s32 *)((u8 *)temp + 0x18) = 0;
    func_1513470C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6D90.s")
