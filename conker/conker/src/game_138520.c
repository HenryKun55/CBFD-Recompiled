#include <ultra64.h>

#include "functions.h"
#include "variables.h"

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B32C.s")

void func_1510B128(s32, f32, f32, f32, f32);

void func_1510B3B0(void) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (D_800D9AC0[i].unk0 != -1.0f) {
            func_1510B128(i, D_800D9AC0[i].unk4, D_800D9AC0[i].unk8, D_800D9AC0[i].unk0, 0.0f);
            D_800D9AC0[i].unk0 = -1.0f;
        }
    }
    D_800D9AF0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B51C.s")

// Builds camera arg0's perspective matrix (float at +0xBC) and converts it
// into the fixed-point Mtx for the current frame buffer (+0x100 + D_800BE9C0 * 0x40).
void func_1510B5F8(s32 arg0, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    guPerspectiveF((void *)((char *)D_800BE628 + arg0 * 0x180 + 0xBC), perspNorm, fovy, aspect, near, far, scale);
    guMtxF2L((void *)((char *)D_800BE628 + arg0 * 0x180 + 0xBC),
             (Mtx *)((char *)D_800BE628 + arg0 * 0x180 + D_800BE9C0 * 0x40 + 0x100));
}

extern f32 D_800D9C10[][4][4];
void func_150A7A48(void *, void *, void *);
void func_1501B22C(s32);

struct func_1510B690_s {
    u8 pad0[0x100];
    Mtx mtx[2];
};

void func_1510B690(void) {
    s16 i;
    f32 mf[4][4];

    for (i = 0; i <= D_80082FA0; i++) {
        guMtxL2F(mf, &((struct func_1510B690_s *) D_800BE628)[i].mtx[D_800BE9C0]);
        guMtxL2F(D_800D9C10[i], &((Mtx **) &D_800DC2A0)[D_800BE9C0][i]);
        func_150A7A48(D_800D9C10[i], mf, ((f32 (*)[4][4]) D_800D9D10)[i]);
        func_1501B22C(i);
    }
}

extern Mtx D_80089470;

struct func_1510B7B4_s {
    u8 pad0[0xB8];
    u16 unkB8;
    u8 padBA[0x100 - 0xBA];
    Mtx mtx[2];
};

Gfx *func_1510B7B4(Gfx *gdl, s32 arg1) {
    gDPPipeSync(gdl++);
    gDPSetBlendColor(gdl++, 0, 0, 0, 1);
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPPerspNormalize(gdl++, ((struct func_1510B7B4_s *) D_800BE628)[arg1].unkB8);
    gSPClipRatio(gdl++, FRUSTRATIO_3);
    gSPClearGeometryMode(gdl++, 0x100000);
    gSPMatrix(gdl++, &((struct func_1510B7B4_s *) D_800BE628)[arg1].mtx[D_800BE9C0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, &((Mtx **) &D_800DC2A0)[D_800BE9C0][arg1], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gDPSetOtherMode(gdl++, 0xEF082C3F & 0xFFFFFF, 0x552230);
    return gdl;
}

// Sets the view-space x and y scales that the clip-space culls (func_1510AEE0,
// func_150A6210, func_150A5378, func_150A50C0) multiply a point's x and y by
// before comparing them with its depth: it is inside the view while
// |x| * cullScaleX_800D35E0 <= depth, and likewise for y (cullScaleY_800D35E4).
// camera->baseCullScaleX/Y are the scales at the camera's base fields of view;
// zooming (fovX/fovY differing from baseFovX/baseFovY) shifts them linearly.
// cameraIndex is the camera's index in D_800BE628 (0x180-byte cameras). The PC
// port hooks its return to widen the x scale for widescreen
// (host/src/widescreen.cpp).
void updateCullScales_1510B958(s32 cameraIndex) {
    struct259 *camera = (struct259 *) D_800BE628 + cameraIndex;

    cullScaleX_800D35E0 = ((camera->fovX / camera->baseFovX) - 1.0f) * -1.0f + camera->baseCullScaleX;
    cullScaleY_800D35E4 = ((camera->fovY / camera->baseFovY) - 1.0f) * -1.0f + camera->baseCullScaleY;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510BF60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510C4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510C8A8.s")
