#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150C8350_s {
    u8 pad0[2];
    s8 dir;
    u8 pad3;
    s16 pos;
    s16 vel;
    s16 tgt;
};

#define E(i) (&((struct func_150C8350_s *)D_800BE4E0)[i])

void func_150C8350(void) {
    s32 diff;
    s32 step;
    s32 tgt2;
    s32 i;

    for (i = 0; i < 10; i++) {
        if (E(i)->vel != E(i)->tgt) {
            tgt2 = E(i)->tgt;
            if (E(i)->vel < 0) {
                tgt2 = -E(i)->tgt;
            }
            diff = tgt2 - E(i)->vel;
            step = D_800BE9E4 << 4;
            if (((diff < 0) ? -diff : diff) < step) {
                E(i)->vel = tgt2;
            } else {
                if (diff < 0) {
                    diff = -1;
                } else {
                    diff = 1;
                }
                E(i)->vel += step * diff;
            }
        }
        E(i)->pos += E(i)->vel * E(i)->dir * D_800BE9A0;
        if (E(i)->pos >= 0x500) {
            E(i)->pos -= 0x500;
            E(i)->pos = 0x500 - E(i)->pos;
            E(i)->dir = -E(i)->dir;
            if (E(i)->pos >= 0x500) {
                E(i)->pos = 0x4FF;
            }
        } else if (E(i)->pos < 0) {
            E(i)->pos = -E(i)->pos;
            E(i)->dir = -E(i)->dir;
            if (E(i)->pos < 0) {
                E(i)->pos = 0;
            }
        }
    }
}

void func_150C84F4(s32 arg0) {
    if (arg0 == 0) {
        func_150C8350();
    }
}

void func_150CDB6C(s32);

void func_150C851C(s32 arg0) {
    s32 i;
    u32 range; s32 base;

    if (D_800BE4E0 != 0) {
        func_150CDB6C(arg0);
        range = ((arg0 * 50) >> 8) + 50; base = (arg0 * 300) >> 8;
        for (i = 0; i < 100; i += 10) {
            arg0 = base;
            arg0 += func_150ADA20() % range;
            *(s16 *) (D_800BE4E0 + i + 8) = arg0;
        }
    }
}

struct func_150C8600_s {
    s32 *tbl[2];
};
extern struct func_150C8600_s D_80088810;
s32 func_1510D0EC(s32, void *, s32, s32);

Gfx *func_150C8600(Gfx *gfx) {
    s32 i;
    s32 sp58[3];
    s32 v;
    struct func_150C8600_s sp4C;

    sp4C = D_80088810;
    for (i = 0; i < 10; i++) {
        v = *(s16 *)((u8 *)D_800BE4E0 + i * 10 + 4) >> 8;
        if (v < 0) {
            v = 0;
        } else if (v > 4) {
            v = 4;
        }
        if (*(u8 *)((u8 *)D_800BE4E0 + i * 10) >= 2) {
            *(u8 *)((u8 *)D_800BE4E0 + i * 10) = 0;
        }
        v = func_1510D0EC(sp4C.tbl[*(u8 *)((u8 *)D_800BE4E0 + i * 10)][v], sp58, 3, 0);
        gSPSegment(gfx++, i + 1, v);
    }
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C88D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C99B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C9BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C9DC4.s")

struct func_150CA07C_s {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
};

s32 func_150CA07C(struct func_150CA07C_s *arg0) {
    arg0->unk38 += arg0->unk44 * D_800BE9A4;
    arg0->unk3C += (arg0->unk48 * D_800BE9A4) + (arg0->unk5C * D_800BE9A4 * D_800BE9A4 * 0.5f);
    arg0->unk40 += arg0->unk4C * D_800BE9A4;
    arg0->unk48 += arg0->unk5C * D_800BE9A4;
    arg0->unk20 += arg0->unk50 * D_800BE9A4;
    arg0->unk24 += arg0->unk54 * D_800BE9A4;
    arg0->unk28 += arg0->unk58 * D_800BE9A4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CA150.s")

void func_1514C678(f32, f32, f32, f32, s32, s32, s32, s32, s32, f32, s32, s32);

void func_150CA930(f32 *arg0) {
    s16 sp3E;

    sp3E = (func_150ADA20() % 21U) + 10;
    func_1514C678(arg0[0], arg0[1], arg0[2], (func_150ADA68() * 59.0f) + 170.0f, 0, 0xFF, sp3E, 0x13, 0, 0.0f, 0, 0xFF);
}

struct func_150CA9D0_s {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150CA9D0(struct func_150CA9D0_s *arg0) {
    if (arg0->unk1C < 0x20) {
        if ((arg0->unk1C * 8) < arg0->unk28) {
            arg0->unk28 = arg0->unk1C * 8;
        }
    }
    return 1;
}

struct func_150CAA04_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    u8 pad3C[0x48 - 0x3C];
    f32 unk48[3];
    f32 unk54;
    s32 unk58;
    u8 pad5C[4];
    u8 unk60;
    u8 unk61;
    u8 unk62;
    s8 unk63;
    u8 pad64[0x74 - 0x64];
};

void *func_15130374(struct func_150CAA04_s *, s32, s32, u8, s32);
void func_15143794(s16, s16, f32, f32 *);
void *memcpy(void *, const void *, u32);
extern f32 D_800A05AC;
extern f32 D_800A05B0;
extern f32 D_800A05B4;
extern f32 D_800A05B8;

s32 func_150CAA04(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8,
                  s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, u8 argE) {
    struct func_150CAA04_s sp34;
    f32 temp_f2;
    f32 sp2C;
    void *temp_v0;
    u32 sp24;

    sp34.unk1D = 0x29;
    sp34.unk8 = 0xE03;
    sp34.unk0 = 0x200005;
    sp34.unk4 = 0;
    sp34.unkA = (func_150ADA20() % 26U) + 0x19;
    sp34.unkC = 0;
    sp34.unk10 = 0;
    sp34.unk18 = 0xB0;
    sp34.unk19 = 0xA0;
    sp34.unk1A = 0x2A;
    sp34.unk14 = 0x40;
    sp34.unk15 = 0xB;
    sp34.unk16 = 0x6A;
    sp34.unk17 = 0xFF;
    sp34.unk1B = (func_150ADA20() % 156U) + 0x64;
    sp34.unk1C = 0xFF;
    sp34.unk60 = 3;
    sp34.unk61 = 3;
    temp_f2 = (func_150ADA68() * D_800A05AC) + 800.0f;
    sp34.unk30 = arg2;
    sp34.unk34 = arg3;
    sp34.unk38 = arg4;
    sp34.unk28 = temp_f2;
    sp34.unk2C = temp_f2;
    sp24 = func_150ADA20();
    func_15143794(arg8, (sp24 % 12U) - 0x15, ((func_150ADA68() * 300.0f) + 498.0f) * D_800A05B0, sp34.unk48);
    sp34.unk58 = 0xE05;
    sp34.unk54 = 0.0f;
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x40;
    }
    if (func_150ADA20() & 1) {
        sp34.unk58 |= 0x80;
    }
    sp34.unk62 = 9;
    sp34.unk63 = -1;
    sp34.unk1E = 0x19;
    sp34.unk20 = 0xA;
    sp34.unk22 = 0x20;
    sp34.unk24 = D_800A05B4;
    sp2C = D_800A05B8;
    temp_v0 = func_15130374(&sp34, 1, 4, argE, 1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0xA8, &sp2C, 4);
    }
    return 1;
}

struct func_150CAC28_s {
    u8 pad0[0x58];
    f32 unk58;
    u8 pad5C[4];
    f32 unk60;
    u8 pad64[0xA8 - 0x64];
    f32 unkA8;
};

s32 func_150CAC28(struct func_150CAC28_s *arg0, s32 arg1) {
    s32 i;
    f32 *p = &arg0->unkA8;

    for (i = D_800BE9E4; i != 0; i--) {
        arg0->unk58 *= *p;
        arg0->unk60 *= *p;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CADD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CB008.s")
