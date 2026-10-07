#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern Gfx *(*D_8008FFF4[])();
extern u8 D_800BE740;
extern s8 D_800E0BD3;
extern void *D_800E0BD8;
void func_15042D94(s32 arg0, s32 arg1, u8 arg2, s32 arg3, ...);
Gfx *func_151ED1E0(Gfx *gfx);

Gfx *func_151E84B0(Gfx *gfx) {
    s32 idx = 0;
    Gfx *(*fn)();

    D_8003C8E0 = 0x09000001;
    gfx = func_151ED1E0(gfx);
    fn = D_8008FFF4[D_800E0B94];
    if (fn != NULL) {
        gfx = fn(gfx);
    }
    if (D_80000300) {
        if (D_800BE616 && D_8008FD90 >= 2) {
            if (!(D_800BE740 & 0xF)) {
                if (D_800E0BD3 == 1) {
                    idx = 0x33;
                } else if (D_800E0BD3 == 2) {
                    idx = 0x16;
                }
            }
        } else if (!(D_800BE740 & 1)) {
            if (D_800E0BD3 == 1) {
                idx = 0x32;
            } else if (D_800E0BD3 == 2) {
                idx = 0x15;
            }
        }
    }
    if (idx) {
        func_1504332C(0xFF, 0xFF, 0xFF, 0xFF);
        func_15042D94(0x94, 0xC8, 0x81, ((s32 *)D_800E0BD8)[idx]);
    }
    D_8003C8E0 = 0;
    return gfx;
}

extern Gfx *(*D_8008FFC0[])();
extern s32 D_80090058;
extern s16 D_800E0C78;
extern s32 D_800BEBA4;
extern Gfx *D_800BE9C8[];

Gfx *func_151E8620(Gfx *gfx) {
    Gfx *(*fn)();
    Gfx *orig = gfx;

    D_8003C8E0 = 0x09000000;
    fn = D_8008FFC0[D_800E0B94];
    if (fn != NULL) {
        gfx = fn(gfx, fn);
    }
    if (D_800E0B94) {
        D_80090058 = 0;
        D_800E0C78 = 0;
    }
    D_8003C8E0 = 0;
    if ((gfx - D_800BE9C8[D_800BE9C0]) > D_800BEBA4 ? 1 : 0) {
        return orig;
    } else {
        return gfx;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E86E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E89A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E966C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E9D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EA15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EADFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EB06C.s")

extern s16 D_8008FDCC;
s32 func_151EA15C(s32, s32, s32, s32);

s32 func_151EB930(s32 arg0) {
    if (D_8008FDCC != 0) {
        arg0 = func_151EA15C(arg0, 0x6A, D_8008FDCC, 0);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EB96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EBB50.s")

extern s32 D_800E0A90;
extern void *D_800E0BD8;
void func_15042D94(s32 arg0, s32 arg1, u8 arg2, s32 arg3, ...);

s32 func_151EC178(s32 arg0) {
    s32 temp;

    temp = D_800E0A90 - 0x5DC;
    if (D_800E0A90 > 0x5DC) {
        temp *= 8;
        if (temp >= 0x100) {
            temp = 0xFF;
        }
        func_1504332C(0xFF, 0xFF, 0xFF, temp);
        func_15042D94(0xDC, 0x130, 1, *(s32 *)((char *)D_800E0BD8 + 0x1D0));
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EC1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EC3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EC648.s")

extern Gfx D_80090028[];
extern u8 D_800E0B97;
extern u8 D_8009181C[];
extern u8 D_80091828[];
Gfx *func_151ED430(Gfx *gfx, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, s32 arg7);
Gfx *func_15096934(Gfx *gfx);

Gfx *func_151ED09C(Gfx *gfx) {
    s32 alpha;

    gSPDisplayList(gfx++, D_80090028);
    alpha = D_800E0A90 * 4;
    if (alpha >= 0x100) {
        alpha = 0xFF;
    }
    gDPSetEnvColor(gfx++, 0xFF, 0xFF, 0xFF, alpha);
    gfx = func_151ED430(gfx, D_8009181C, 0x92, 0x6C, 8, 3, 1.0f, 0);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, TEXEL0, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, TEXEL0, 0);
    gDPSetEnvColor(gfx++, 0xFF, 0x80, 0x20, (D_800E0B97 * (alpha + 1)) >> 8);
    gfx = func_151ED430(gfx, D_80091828, 0x92, 0x6C, 8, 3, 1.0f, 0);
    return func_15096934(gfx);
}

extern u8 D_800E0B96;
Gfx *func_1501A6CC(Gfx *arg0, s32 a, s32 b, s32 c, s32 d);

Gfx *func_151ED1E0(Gfx *gfx) {
    if (D_800E0B96 == 0) {
        return gfx;
    }
    gDPPipeSync(gfx++);
    gDPSetOtherMode(gfx++, 0xEF082C3F & 0xFFFFFF, 0x504340);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT);
    gDPSetEnvColor(gfx++, 0, 0, 0, D_800E0B96);
    return func_1501A6CC(gfx, 0, 0, D_800BE620, D_800BE624);
}

extern u8 D_8009DEB0[];
extern u8 D_8009DEB4[];
extern u8 D_8009DEB8[];
extern u8 D_8009DEBC[];

struct func_151ED29C_s {
    u8 pad0[6];
    u16 width;
    u16 height;
    u8 fmt;
    u8 siz;
};

Gfx *func_151ED29C(Gfx *gfx, struct func_151ED29C_s *tex, s32 *size) {
    s32 i;
    s32 masks;
    s32 maskt;
    s32 fmt;
    s32 len;

    len = D_8009DEB0[tex->siz] + tex->width * tex->height;
    len >>= D_8009DEB4[tex->siz];
    *size = len;
    for (masks = 1, i = 2; i < tex->width; i *= 2) {
        masks++;
    }
    for (maskt = 1, i = 2; i < tex->height; i *= 2) {
        maskt++;
    }
    fmt = tex->fmt;
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, D_8009DEBC[tex->siz], 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPSetTile(gfx++, fmt, tex->siz, ((D_8009DEB8[tex->siz] * tex->width) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
               G_TX_CLAMP, maskt, 0, G_TX_CLAMP, masks, 0);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (tex->width - 1) << G_TEXTURE_IMAGE_FRAC, (tex->height - 1) << G_TEXTURE_IMAGE_FRAC);
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151ED430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151ED90C.s")

struct func_151EDB58_s {
    u8 pad0[4];
    void *unk4[4];
    u8 unk14;
    u8 pad15[0xF];
    s32 unk24;
};
void func_1503F7B8(s32);

void func_151EDB58(struct func_151EDB58_s *arg0) {
    s32 i;

    if (arg0 != NULL) {
        func_1503F7B8(arg0->unk24);
        func_100043B4(arg0, 4);
        for (i = 0; i < arg0->unk14; i++) {
            func_100043B4(arg0->unk4[i], 4);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EDBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EDF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EE184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EEBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EEFF0.s")
