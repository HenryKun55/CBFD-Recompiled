#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151150B0(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151150BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511515C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151151FC.s")

void func_1511529C(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151152A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151155C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511575C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115F68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511617C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151162D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151163C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511650C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116888.s")

void func_15116924(s32 arg0) {
}

struct func_15116930_s {
    u8 pad0[0x4F];
    u8 unk4F;
    u8 pad50[0x73 - 0x50];
    u8 unk73;
};

void func_15116930(struct func_15116930_s *arg0, void *arg1) {
    if (arg0->unk4F & 4) {
        if (!(arg0->unk73 & 3) && !(arg0->unk73 & 4)) {
            if (*(u8 *)(*(u8 **)((u8 *)arg1 + 0x31C) + 0x57) == 1) {
                arg0->unk73 &= ~3;
                arg0->unk73 |= 2;
            }
        }
    }
}

struct func_15116984_s {
    u8 pad[0x73];
    u8 unk73;
};

void func_151169B4(struct func_15116984_s *arg0);

void func_15116984(struct func_15116984_s *arg0) {
    if (arg0->unk73 & 2) {
        func_151169B4(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151169B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151172D8.s")

f32 func_151172D8(void *arg0, s32 arg1);

void func_151174A0(void *arg0) {
    *(f32 *)((u8 *)arg0 + 8) = func_151172D8(arg0, *(s32 *)((u8 *)arg0 + 8));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151174C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151174F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117518.s")

f32 func_15117518(f32 *arg0, f32 arg1);

void func_15117770(f32 *arg0) {
    *arg0 = func_15117518(arg0, *arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151177C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151179BC.s")

struct func_15117D3C_s {
    u8 pad0[0x3C];
    s32 unk3C;
    u8 pad40[0x4F - 0x40];
    u8 unk4F;
    u8 pad50[0x73 - 0x50];
    u8 unk73;
};

void func_15117D3C(struct func_15117D3C_s *arg0, s32 *arg1) {
    s32 temp = arg0->unk3C & 0xFFFF;

    if (*arg1 == 1) {
        if (arg0->unk4F & 4) {
            if (!(arg0->unk73 & 3) && !(arg0->unk73 & 4)) {
                if (temp == 0 || *(u8 *)(*(u8 **)((u8 *)arg1 + 0x31C) + 0x57) == 1) {
                    arg0->unk73 &= ~3;
                    arg0->unk73 |= 2;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117F3C.s")

void func_1511896C(s32 arg0) {
    func_151189AC(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511898C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151189AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15118F24.s")

struct func_151193AC_s {
    u8 pad[0x73];
    u8 unk73;
};

void func_151193AC(struct func_151193AC_s *arg0, s32 *arg1) {
    if (arg1[0] == 1 && ((u8 *)arg1)[0x65] == 0) {
        if (!(arg0->unk73 & 3) && !(arg0->unk73 & 4)) {
            arg0->unk73 &= ~3;
            arg0->unk73 |= 2;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151193F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151194D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151196D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15119938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15119FC0.s")

s32 func_1511A410(s8 *arg0, s32 *arg1) {
    s32 count;
    s32 sp[2];
    s32 i;

    sp[0] = 0;
    sp[1] = 0;
    count = 0;
    for (i = 0; arg0[i << 3] != -0x21 && count < 2; i++) {
        switch (arg0[i << 3]) {
            case -3:
                sp[count] = i;
                count++;
        }
    }
    *arg1 = sp[1];
    return sp[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A494.s")

void func_15116110(void *arg0);
void func_1511A494(void *arg0, void *arg1, void *arg2);

void func_1511A6FC(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x3C) != 0) {
        func_15116110(arg0);
    }
    func_1511A494(arg0, arg0 + 0x80, arg0 + 0x84);
}

s32 func_15022B08(s32 arg0, s32 arg1);
void func_151162D4(struct131 *arg0);

void func_1511A738(struct131 *arg0) {
    if (D_800C35EA == 1) {
        if (func_15022B08(arg0 - D_800DBEF4, 0)) {
            *(s32 *)((u8 *)arg0 + 0x7C) = 0;
            *(f32 *)((u8 *)arg0 + 0x18) = 0.0f;
        }
    }
    func_151162D4(arg0);
    func_1511A494(arg0, (u8 *)arg0 + 0x80, (u8 *)arg0 + 0x84);
}

struct func_1511A7C0_s {
    u8 pad0[4];
    f32 *unk4;
    u8 pad8[8];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
};

void func_1511A7C0(u8 *arg0) {
    struct func_1511A7C0_s *s = *(struct func_1511A7C0_s **)(arg0 + 0x80);
    s32 i;

    s->unk1E = 1;
    s->unk10 = 0.0f;
    s->unk1C = 0;
    s->unk1D = 7;
    s->unk14 = 260.0f;
    s->unk18 = 100.0f;
    for (i = 0; i < *(u16 *)(arg0 + 0x16); i++) {
        s->unk4[i] = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511AF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B7D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BB04.s")

void func_1511BB04(void *, f32, f32, f32, f32);

struct func_1511BDF4_s {
    u8 pad0[0x3F];
    u8 unk3F;
    u8 pad40[0x40];
    struct127 *unk80;
};

void func_1511BDF4(struct func_1511BDF4_s *arg0) {
    struct127 *obj;

    obj = (arg0->unk80 != NULL) ? arg0->unk80 : func_15083E90(arg0->unk3F);
    if (obj != NULL) {
        func_1511BB04(arg0, obj->x_position, obj->z_position, 1.0f, 1.0f);
    }
}

extern f32 D_800A31E0;

struct func_1511BE5C_s {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[8];
    s16 unk10;
    s16 pad12;
    s16 unk14;
};

void func_1511BE5C(struct func_1511BE5C_s *arg0) {
    arg0->unk4 = func_150484A0(arg0->unk10 - D_800DBFF0->unk2F8, arg0->unk14 - D_800DBFF0->unk300) * D_800A31E0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BEBC.s")

void func_1511C540(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511C548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511C638.s")

extern f32 D_800A31F4;

void func_1511CB2C(s32 arg0, f32 *arg1) {
    *arg1 = D_800A31F4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511CB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DF6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511E780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511EC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511ED84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511EF40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F4D0.s")

struct func_1511F768_s {
    u8 pad0[0x80];
    s32 unk80;
};

void func_1511F768(struct func_1511F768_s *arg0, s32 arg1) {
    if (arg0->unk80 == 0) {
        arg0->unk80 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F92C.s")
