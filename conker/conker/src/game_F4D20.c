#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_1511650C(s32, s32, s32, f32);

struct func_150C7870_s {
    u8 padA[0xA];
    u8 unkA;
};

void func_150C7870(s32 arg0) {
    if (!(((struct func_150C7870_s *)D_800D2E4C)->unkA & 8)) {
        if (!(D_800DBEF4->unk73 & 4)) {
            func_1511650C(arg0, 1, 0x353, 1000.0f);
        } else {
            func_1511650C(arg0, 1, 0x43, 400.0f);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C78E0.s")

void *func_151150BC();

struct func_150C7930_s {
    u8 pad[0x1E0];
    s32 unk1E0[0x10];
};

void func_150C7930(s32 *arg0) {
    s32 *p = ((struct func_150C7930_s *)D_800DBEF4)->unk1E0;
    arg0[0x3C / 4] = p[0x3C / 4] & 0xFFFF0000;
    func_151150BC();
}

void func_150C7968(u8 *arg0) {
    u8 *t;
    s16 *p;
    s16 v;

    func_15116110(arg0);
    if (!(arg0[0x73] & 4)) {
        t = *(u8 **)(arg0 + 0x7C);
        p = (s16 *)((u8 *)D_800DBEF4 + 0x1E0);
        v = p[0x1E];
        if (t != NULL) {
            t[0x13] = v >> 4;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C79BC.s")

struct func_150C7C90_e {
    s8 unk0;
    u8 pad[7];
};

struct func_150C7C90_r {
    u8 pad[0x12];
    s16 unk12;
};

struct func_150C7C90_s {
    u8 pad0[0x1C];
    struct func_150C7C90_e *unk1C;
    u8 pad20[0x1C];
    s32 unk3C;
    u8 pad40[0x3C];
    s32 unk7C;
};

struct func_150C7C90_r *func_151149AC(u8 arg0);

void func_150C7C90(struct func_150C7C90_s *arg0) {
    s32 angle;
    struct func_150C7C90_e *e;
    s32 i;

    if (arg0->unk7C == 0) {
        e = arg0->unk1C;
        i = 0;
        while ((e + i)->unk0 != -14) {
            i++;
        }
        arg0->unk7C = i;
    }
    e = &arg0->unk1C[arg0->unk7C];
    angle = -0x29D - func_151149AC(arg0->unk3C & 0xFF)->unk12;
    if (arg0->unk3C & 0x8000) {
        angle = 0x344 - angle;
    }
    while (angle < 0) {
        angle += 0x400;
    }
    while (angle >= 0x400) {
        angle -= 0x400;
    }
    *(s32 *)e &= ~0xFFF;
    *(s32 *)e |= angle;
}

struct func_150C7D7C_s {
    u8 pad[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
};

void func_150C7D7C(struct func_150C7D7C_s *arg0) {
    struct127 *o = func_15083E90(0xC);
    arg0->unk10 = o->x_position - 30.0f;
    arg0->unk12 = o->y_position + 50.0f;
    arg0->unk14 = o->z_position + 30.0f;
}
