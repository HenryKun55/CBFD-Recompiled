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

extern s16 D_800E0A80;
extern s32 D_800E0A90;

s32 func_151EB96C(s32 arg0) {
    s16 alpha;
    s16 i;
    u32 spacing;
    s32 count;
    s32 x;
    s32 x0;
    u8 a;
    u8 *str;

    if (D_800E0A80 < 0) {
        return arg0;
    }
    if (D_800E0A90 < 0x168) {
        alpha = D_800E0A90 << 2;
        if (alpha > 0xFF) {
            alpha = 0xFF;
        }
    } else {
        alpha = 0x1A9 - D_800E0A90;
        alpha <<= 2;
        if (alpha < 0) {
            alpha = 0;
        }
        if (alpha > 0xFF) {
            alpha = 0xFF;
        }
    }
    i = D_800E0A80;
    count = 0;
    a = alpha;
    while (*((u8 **)D_800E0BD8)[i] != '*') {
        i++;
        count++;
    }
    if (count >= 0xE) {
        spacing = 0xB;
    } else {
        spacing = 0x11;
    }
    func_1504332C(0xFF, 0, 0, a);
    i = D_800E0A80;
    x = (s32)(0xD0 - count * spacing) >> 1;
    x0 = x;
    while (*(str = ((u8 **)D_800E0BD8)[i]) != '*') {
        func_15042D94(0x94, x, 1, str);
        func_1504332C(0xFF, 0xFF, 0xFF, a);
        if (x == x0) {
            x += 0xC;
        }
        i++;
        x += spacing;
    }
    return arg0;
}

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

extern Gfx D_80090028[];
extern u8 D_800E0B97;
extern u8 D_800E0B96;
extern s32 D_800E0A74;
extern u8 D_800917F8[];
extern u8 D_80091804[];
extern u8 D_80091810[];
Gfx *func_151ED430(Gfx *gfx, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, s32 arg7);
Gfx *func_15096934(Gfx *gfx);

Gfx *func_151EC1F0(Gfx *gfx) {
    s32 alpha;

    if (D_800BE9F0 == 0x21) {
        return gfx;
    }
    gSPDisplayList(gfx++, D_80090028);
    alpha = D_800E0A90;
    if (D_800E0A90 > 0x12C) {
        alpha = 0x1AC - alpha;
        alpha *= 2;
        if (alpha < 0) {
            alpha = 0;
        }
    } else {
        alpha = D_800E0A90 * 8;
        if (alpha >= 0x100) {
            alpha = 0xFF;
        }
    }
    if (alpha) {
        gDPSetEnvColor(gfx++, 0xFF, 0xFF, 0xFF, alpha);
        gfx = func_151ED430(gfx, D_800917F8, 0x92, 0x63, 5, 6, 1.0f, 0);
    }
    gDPSetEnvColor(gfx++, 0xFF, 0xFF, 0xFF, 0xFF);
    gfx = func_151ED430(gfx, D_80091804, 0x92, 0xCB, 5, 2, 1.0f, 0);
    gDPSetCombine(gfx++, 0xFFD3FF, 0xFFA6FF7F);
    gDPSetEnvColor(gfx++, 0x20, 0xFF, 0x20, D_800E0B97);
    gfx = func_151ED430(gfx, D_80091810, 0x92, 0xCB, 5, 2, 1.0f, 0);
    gfx = func_15096934(gfx);
    alpha = 0x1EA - D_800E0A74;
    if (alpha < 0) {
        alpha = 0;
    } else {
        alpha *= 16;
        if (alpha >= 0x100) {
            alpha = 0xFF;
        }
    }
    alpha = 0xFF - alpha;
    D_800E0B96 = alpha;
    return gfx;
}

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

void *allocate_memory(s32, s32, s32, s32);
s32 *func_1502B6BC(s32, u32, s32, s32, s32, s32);
void func_1510CE60(s32, s32, s32, s32, s32 *);
struct func_151EDF4C_s {
    Gfx *dl;
    s32 *raw;
    s32 unk8;
};
extern struct func_151EDF4C_s *D_80090138;
extern u8 *D_800E0C7C;
extern s8 D_800E0C80;
extern s8 D_800E0C81;
extern s8 D_800E0C82;
extern s8 D_800E0C83;
extern s8 D_800E0C84;

void func_151EDF4C(void) {
    s32 i;
    s32 j;
    s32 *raw;
    volatile Gfx *gfx;
    u32 op;
    Vtx *v;
    s32 pad[2];

    D_80090138 = NULL;
    D_800E0C7C = allocate_memory(0x1A8, 1, 0, 0);
    if (D_800E0C7C == NULL) {
        return;
    }
    D_80090138 = (struct func_151EDF4C_s *)(D_800E0C7C + 0x40);
    for (i = 0x1C5, j = 0; i != 0x1E3; i++, j++) {
        raw = func_1502B6BC(0, 1, 0, 2, 9, i);
        D_80090138[j].raw = raw;
        D_80090138[j].dl = (Gfx *)*raw;
        func_1510CE60((s32)D_80090138[j].dl, 0, 1, 0x3E, &D_80090138[j].unk8);
        gfx = D_80090138[j].dl;
        do {
            op = (gfx->words.w0 >> 24) & 0xFF;
            if (op == 1) {
                gfx->words.w1 += (u32)raw;
                v = (Vtx *)(gfx->words.w1 | 0x80000000);
                v->v.cn[0] = 0;
                v->v.cn[1] = 0;
                v->v.cn[2] = 0;
                v->v.cn[3] = 0xFF;
                v++;
                v->v.cn[0] = 0;
                v->v.cn[1] = 0;
                v->v.cn[2] = 0;
                v->v.cn[3] = 0xFF;
            }
            if (op == 0xFC) {
                gfx->words.w0 = 0xFC127E05;
                gfx->words.w1 = 0xFFFFF3F8;
            }
            if (op == 0xEF) {
                gfx->words.w0 |= 0x100000;
                ((Gfx *)gfx)->words.w1 = 0x0F0A4000;
            }
            gfx++;
        } while (op != 0xDF);
    }
    D_800E0C80 = 0;
    D_800E0C81 = 0;
    D_800E0C82 = 0;
    D_800E0C83 = 0;
    D_800E0C7C[0] = 0;
    D_800E0C7C[0x20] = 0;
    D_800E0C84 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EE184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EEBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EEFF0.s")
