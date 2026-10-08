#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void *D_800D2C20;
void func_1509499C(s32 arg0, s16 **arg1);
void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);

void func_150948C0(s32 arg0, f32 (*arg1)[3]) {
    s16 *sp50[16];
    s32 i;

    func_1509499C(arg0, sp50);
    for (i = 0; i < 16; i++) {
        if (sp50[i] != NULL) {
            func_150A7960(D_800D2C20, sp50[i][0], sp50[i][1], sp50[i][2], &arg1[i][0], &arg1[i][1], &arg1[i][2]);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509499C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094AB8.s")

extern Mtx D_800D2CA8[];
void func_150A7A48(f32 a[4][4], f32 b[4][4], Mtx *c);

struct func_15094EA0_s {
    u8 pad0[0x100];
    Mtx unk100[2];
};

void func_15094EA0(s32 arg0) {
    f32 sp58[4][4];
    f32 sp18[4][4];

    guMtxL2F(sp58, &((Mtx **)&D_800DC2A0)[D_800BE9C0][arg0]);
    guMtxL2F(sp18, &((struct func_15094EA0_s *)D_800BE628)[arg0].unk100[D_800BE9C0]);
    func_150A7A48(sp58, sp18, &D_800D2CA8[arg0]);
}

extern Gfx D_800873D0[];
extern s32 D_800D2CA0;

Gfx *func_15094F40(Gfx *gdl) {
    gSPDisplayList(gdl++, D_800873D0);
    D_800D2CA0 = 0;
    return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094FE8.s")

struct func_15095060_s {
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
};
struct func_15095060_src {
    u32 unk0;
    u8 unk4;
    u8 pad5;
    u16 unk6;
    u16 unk8;
    u8 unkA;
    u8 unkB;
};
extern struct func_15095060_s D_800D2C90;

void func_15095060(struct func_15095060_src *arg0, s32 arg1, void *arg2) {
    u32 temp_v0;

    if (arg2 != NULL) {
        *(struct func_15095060_s **)((char *)arg2 + 0x10) = &D_800D2C90;
    }
    temp_v0 = arg0->unk0;
    if (temp_v0 < 0x10000000U) {
        D_800D2C90.unk0 = temp_v0;
    } else {
        D_800D2C90.unk0 = ((u32 *)temp_v0)[arg1 >> 8];
    }
    D_800D2C90.unk4 = arg0->unk6;
    D_800D2C90.unk6 = arg0->unk8;
    D_800D2C90.unk8 = arg0->unkA;
    D_800D2C90.unk9 = arg0->unkB;
    D_800D2C90.unkA = arg0->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150950D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509563C.s")

s32 func_1509563C(f32 x, f32 y, f32 z, f32 *a, f32 *b, f32 *c, f32 *d, f32 e);
void func_15095A90(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);

struct func_15095760_s {
    u8 pad0[0x40];
    Vp vp[2];
    u8 pad60[0x120];
};

Gfx *func_15095760(Gfx *gfx, s16 *pos) {
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    if (func_1509563C(pos[0], pos[1], pos[2], &sp44, &sp40, &sp3C, &sp38, 4000.0f) == 0) {
        return gfx;
    }
    gDPPipeSync(gfx++);
    gDPSetPrimDepth(gfx++, (s32)(((sp3C / sp38) * ((struct func_15095760_s *)D_800BE628)[D_80082FA4].vp[D_800BE9C0].vp.vscale[2]
                         + ((struct func_15095760_s *)D_800BE628)[D_80082FA4].vp[D_800BE9C0].vp.vtrans[2]) * 32.0f), 0);
    func_15095A90((s32)gfx, (s32)pos, sp44, sp40, sp38, 1, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150958B0.s")

void func_15095A90(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);

void func_15095A48(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    func_15095A90(arg0, arg1, arg2, arg3, 4096.0f, 0, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095A90.s")

extern f32 D_800D2C70;
extern f32 D_800D2C74;
extern f32 D_800D2C78;
extern f32 D_800D2C7C;
extern f32 D_800D2C80;
extern f32 D_800D2C84;
extern f32 D_800D2C88;

struct func_15095B08_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x14C];
};

struct func_15095B08_img {
    u8 pad0[4];
    u16 w;
    u16 h;
};

struct func_15095B08_obj {
    u8 pad0[6];
    s16 w;
    s16 h;
    u8 padA[6];
    struct func_15095B08_img *img;
};

void func_15095B08(struct func_15095B08_obj *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 *arg5) {
    struct func_15095B08_s *cam;
    f32 sx;
    f32 sy;
    f32 inv;
    f32 w;
    f32 h;

    *arg5 = 0;
    if (arg0->w != 0 && arg0->h != 0) {
        sx = arg0->w;
        sy = arg0->h;
        sx *= D_800380A0;
        sy *= D_800380A4;
        if (arg4 != 0) {
            cam = &((struct func_15095B08_s *)D_800BE628)[D_80082FA4];
            sx *= cam->unk1C;
            sy *= cam->unk20;
        } else {
            cam = &((struct func_15095B08_s *)D_800BE628)[D_80082FA4];
            sx *= cam->unk14;
            sy *= cam->unk18;
        }
        inv = 1.0f / arg3;
        w = (u32)arg0->img->w * sx * inv;
        h = (u32)arg0->img->h * sy * inv;
        arg1 -= w * 0.5f;
        arg2 -= h * 0.5f;
        if (cam->unk2C <= arg1 + w && arg1 < cam->unk30 && cam->unk24 <= arg2 + h && arg2 < cam->unk28) {
            *arg5 = 1;
        }
        D_800D2C70 = sx;
        D_800D2C74 = sy;
        D_800D2C78 = arg1;
        D_800D2C7C = arg2;
        D_800D2C80 = arg3;
        D_800D2C84 = w;
        D_800D2C88 = h;
    }
}

void *func_15095D34(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);

void func_15095D0C(void *arg0, void *arg1) {
    func_15095D34(arg0, arg1, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509629C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15096934.s")
