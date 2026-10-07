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

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CAA04.s")

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
