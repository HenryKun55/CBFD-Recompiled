#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5370.s")

void func_150C5430(void) {
    func_15169804();
}

void func_150C5450(void) {
    func_15169824();
}

extern void (*D_800887B8[])(void *);

void func_150C5470(u8 *arg0) {
    s32 idx = arg0[0x38];

    if (idx < 0) {
        idx = 0;
    } else if (idx >= 2) {
        idx = 0;
    }
    D_800887B8[idx](arg0);
}

extern void (*D_800887C0[])(void);

void func_150C54C0(u8 *arg0) {
    s32 idx = arg0[0x38];

    if (idx < 0) {
        idx = 0;
    } else if (idx >= 2) {
        idx = 0;
    }
    D_800887C0[idx]();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C553C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C56A4.s")

struct func_150C5B88_inner {
    s32 unk0;
    u8 pad4[0x10];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct func_150C5B88_s {
    u8 pad0[0x24];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 pad30[0xC8 - 0x30];
    struct func_150C5B88_inner *unkC8;
};

s32 func_150C5B88(struct func_150C5B88_s *arg0) {
    struct func_150C5B88_inner **p = &arg0->unkC8;
    if ((*p)->unk0 == 0) {
        return 0;
    }
    arg0->unk24 = (*p)->unk14;
    arg0->unk28 = (*p)->unk18;
    arg0->unk2C = (*p)->unk1C;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5BD4.s")

void func_150C5C74(struct127 *arg0) {
    func_1514D3B0(arg0, 0x15, 1, 0);
}

void func_150C5C9C(struct127 *arg0) {
    func_1514D3B0(arg0, 0x15, 2, 0);
}

struct func_150C5CC4_s {
    u8 pad[0x38];
    u8 unk38;
};
typedef void (*func_150C5CC4_fn)(struct func_150C5CC4_s *, s32, u8);
extern func_150C5CC4_fn D_800887C8[];

void func_150C5CC4(struct func_150C5CC4_s *arg0, s32 arg1, u8 arg2) {
    func_150C5CC4_fn fn = D_800887C8[arg0->unk38];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5D0C.s")
