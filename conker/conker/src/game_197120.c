#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_197120/func_15169C70.s")

s32 func_1510F8D8(s32, s32, s32, s32);
void func_15167AD8(void *arg0, u8 arg1, s32 arg2);
extern s32 D_8008CADC;
extern f32 D_800A6CC8;

struct func_1516A3F4_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[7];
    s32 unk14;
    u8 pad18[8];
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    u8 pad2C[0xC];
    s16 unk38;
    u8 pad3A;
    u8 unk3B;
};

struct func_1516A3F4_p {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s8 unk12;
    s8 pad13;
    s8 unk14;
    u8 unk15;
    s16 pad16;
};

void func_1516A3F4(struct func_1516A3F4_s *arg0) {
    s32 h;
    s32 limit;
    u8 b;
    s16 sz;
    struct func_1516A3F4_p p;
    f32 scale;

    h = arg0->unk14;
    limit = arg0->unk22 + arg0->unk2A;
    if (h >= limit) {
        func_1510F800(0);
        h = arg0->unk14 = func_1510F8D8(arg0->unk20, arg0->unk22, arg0->unk24, 0);
    }
    if (h >= limit) {
        arg0->unk38 = 0;
        if ((limit - h) < 50) {
            p.unk0 = D_8008CADC;
            p.unk4 = 0;
            p.unk6 = 0x100;
            p.unk8 = arg0->unk20;
            p.unkA = arg0->unk14 + 10;
            p.unkC = arg0->unk24;
            b = arg0->unk3B;
            p.unk12 = 0;
            sz = ((b << 12) / 5100) + 0xCC;
            p.unkE = sz;
            p.unk10 = sz;
            p.unk15 = b;
            p.unk14 = 3;
            func_15167AD8(&p, arg0->unkC, arg0->unk1);
        }
    } else {
        scale = D_800A6CC8;
        arg0->unk26 = arg0->unk26 * scale;
        arg0->unk28 = arg0->unk28 * scale;
    }
}

void func_15171D4C(f32, f32, f32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);

struct func_1516A538_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[7];
    s16 unk14;
    s16 pad16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 pad1E[7];
    u8 unk25;
};

void func_1516A538(struct func_1516A538_s *arg0) {
    u32 sp4C;
    s32 sp48;
    s32 sp44;

    if (arg0->unk14 >= 0x300) {
        sp48 = func_150ADA20() % 3U;
        sp44 = arg0->unk25;
        sp4C = func_150ADA20() % 360U;
        func_15171D4C((f32) arg0->unk18, (f32) (arg0->unk1A - 0xA), (f32) arg0->unk1C, 0x64, 0, sp48 + 0x20,
                      (f32) sp4C, 0, ((sp44 * 0x19) / 255) + 0x19, 0, 0x100, 0,
                      arg0->unkC, arg0->unk1);
    }
}

struct func_1516A648_s {
    u8 pad0[0xE];
    s16 x;
    s16 y;
    s16 z;
    u8 pad14[4];
    s16 vy;
    u8 pad1A[5];
    u8 alpha;
    u8 pad20[4];
    u8 fadeIn;
    u8 pad25[7];
    u8 hiY;
    u8 loY;
};

void func_1516F864(struct func_1516A648_s *);
s32 func_1510F8D8(s32, s32, s32, s32);
void func_1516F94C(struct func_1516A648_s *, s32);

s32 func_1516A648(struct func_1516A648_s *arg0) {
    s32 alpha = arg0->alpha;
    s32 h;

    if (arg0->fadeIn) {
        if (alpha != 0xFF) {
            alpha += D_800BE9E4 * 16;
            if (alpha >= 0x100) {
                alpha = 0xFF;
            }
            arg0->alpha = alpha;
        }
    } else if (alpha) {
        alpha -= D_800BE9E4 * 4;
        if (alpha < 0) {
            alpha = 0;
        }
        arg0->alpha = alpha;
    }
    if (arg0->fadeIn == 0 && alpha == 0) {
        return 1;
    }
    arg0->vy -= 300;
    func_1516F864(arg0);
    h = func_1510F8D8(arg0->x, arg0->y, arg0->z, 0) + 10;
    arg0->hiY = h >> 8;
    arg0->loY = h & 0xFF;
    if (arg0->y < h) {
        arg0->y = h;
        arg0->vy = arg0->vy * -0.5f;
        func_1516F94C(arg0, 0xE6);
    }
    return 0;
}
