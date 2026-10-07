#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_1516A770(u8 *arg0) {
    s32 n = 1;
    while (*arg0 != 0) {
        if (*arg0 == 0xBD) {
            *arg0 = 0;
            n++;
        }
        arg0++;
    }
    return n;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516A7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516AA70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516B6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516C878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516C934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516CC58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516D0CC.s")

struct func_1516D2E0_s {
    u8 unk0;
    u8 pad1[0xF];
    u8 *unk10;
    u8 pad14;
    u8 unk15;
};

void func_1516D2E0(struct func_1516D2E0_s *arg0) {
    if ((arg0 != NULL) && (arg0->unk0 == 0x51)) {
        arg0->unk10[8] = 0;
        func_1516972C((struct102 *)arg0);
        arg0->unk15 = 0;
    }
}

struct func_1516D328_s2 {
    u32 flags;
    u8 pad4[4];
    u8 unk8;
};

struct func_1516D328_s {
    u8 unk0;
    u8 pad1[0xF];
    struct func_1516D328_s2 *unk10;
    u8 pad14[0xC];
    u8 unk20;
};

void func_1516D328(struct func_1516D328_s *arg0) {
    if ((arg0 != NULL) && (arg0->unk0 == 0x51)) {
        arg0->unk10->flags |= 0x100;
        arg0->unk10->flags &= ~0x400;
        arg0->unk20 = arg0->unk10->unk8;
    }
}

struct func_1516D378_s {
    u8 type;
    u8 pad1[0xF];
    s32 *unk10;
};

struct func_1516D378_s *func_1516D378(struct func_1516D378_s *arg0) {
    if ((arg0 != NULL) && (arg0->type == 0x51)) {
        *arg0->unk10 |= 0x100;
        *arg0->unk10 &= ~0x400;
        return arg0;
    }
    return NULL;
}

struct func_1516D3C4_s {
    u8 type;
    u8 pad[0xF];
    s32 *flags;
};

struct func_1516D3C4_s *func_1516D3C4(struct func_1516D3C4_s *arg0) {
    if (arg0 != NULL && arg0->type == 0x51) {
        *arg0->flags |= 0x500;
        return arg0;
    }
    return NULL;
}
