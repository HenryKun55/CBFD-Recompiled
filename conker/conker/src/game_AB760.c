#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E5C8.s")

struct func_1507E6B8_s {
    u8 pad0[0x6F];
    u8 unk6F;
    u8 unk70;
    u8 pad71[0x1CA - 0x71];
    u8 unk1CA;
};

extern s32 func_150849A0();

s32 func_1507E6B8(struct func_1507E6B8_s *arg0) {
    s32 temp_v0;
    u8 temp_v1;

    if (arg0->unk1CA == 0) {
        return 0;
    }
    if (arg0->unk6F == arg0->unk70) {
        return 1;
    }
    temp_v0 = func_150849A0(arg0);
    temp_v1 = arg0->unk6F;
    if (temp_v0 == 0) {
        if (temp_v1 == 0x15) {
            return 1;
        }
    } else if (temp_v0 == 0x52) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E7E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E908.s")

extern s32 func_150849A0();

struct func_1507E968_s {
    u8 pad0[4];
    u8 unk4;
};

s32 func_1507E968(struct func_1507E968_s *arg0) {
    s32 t;
    s32 id;
    u8 *p;

    t = arg0->unk4;
    if (t != 0x96) {
        id = func_150849A0(arg0);
    } else {
        id = t;
    }
    if (id == 0xFF) {
        return 0;
    }
    p = (u8 *)D_800D1C90[id];
    if (p != NULL) {
        p -= 8;
        return *(u32 *)(p + 4) / 10;
    }
    return 0;
}

void func_1507E9E8(s32 arg0, s32 arg1) {
}

extern s32 func_150849A0();
extern u8 D_8009D910[];

void *func_1507E9F8(s32 arg0, s32 *arg1) {
    if (func_150849A0(arg0) == 0) {
        if (arg1 != NULL) {
            *arg1 = 5;
        }
        return D_8009D910;
    }
    if (arg1 != NULL) {
        *arg1 = 0;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507EA44.s")

struct func_1507EABC_s {
    u8 pad0[0x6A];
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 pad6E[2];
    u8 unk70;
    u8 unk71;
    u16 unk72;
};

void func_1507E7E4();

void func_1507EABC(struct func_1507EABC_s *arg0) {
    func_1507E7E4(arg0, arg0->unk70, 3, 0xFFFF, 10);
    arg0->unk71 = 0;
    arg0->unk72 = 0;
    if (arg0->unk6C >= 10) {
        arg0->unk6C = 0;
        arg0->unk6A = 0;
    }
    if (arg0->unk6D >= 10) {
        arg0->unk6D = 0;
        arg0->unk6B = 0;
    }
}

void func_1507EB4C(void *arg0, s32 arg1);

void func_1507EB2C(void *arg0) {
    func_1507EB4C(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507EB4C.s")
