#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151D26C0_s {
    u8 pad0[0xE];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
};

extern struct func_151D26C0_s *func_15167A68(s32, s32, s32, s32, s32, s32);

void func_151D26C0(s16 arg0) {
    struct func_151D26C0_s *p = func_15167A68(0x3C, 1, 0x18, 0, 0xFF, 1);
    p->unk14 = 0;
    p->unk12 = 0;
    p->unkE = 0;
    p->unk16 = 1;
    p->unk10 = arg0;
}

struct func_151D2718_s {
    u8 pad0[8];
    struct func_151D2718_s *next;
    u8 padC[4];
    s16 id;
    u8 pad12[4];
    s8 state;
};
extern struct func_151D2718_s *D_800DD0E0;

void func_151D2718(s16 arg0) {
    struct func_151D2718_s *var_v0;

    for (var_v0 = D_800DD0E0; var_v0 != NULL; var_v0 = var_v0->next) {
        if (arg0 == var_v0->id) {
            var_v0->state = -2;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D275C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D2830.s")
