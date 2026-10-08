#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151669A0_s {
    u8 pad0[0x10];
    Mtx mtx[3];
    u8 unkD0;
    u8 padD1;
    s16 unkD2;
    s16 unkD4;
    s16 unkD6;
    f32 unkD8;
};
extern struct func_151669A0_s *func_15167A68(s32, s32, s32, s32, s32, s32);
extern void func_1517E05C(s32, s32, s32);

void func_151669A0(s32 arg0, s32 arg1, s32 arg2, f32 arg3, u8 arg4, s32 arg5) {
    struct func_151669A0_s *p;
    s32 i;
    s32 r;

    p = func_15167A68(0xD, arg5, 0xE0, 1, arg4, 1);
    if (p != NULL) {
        p->unkD0 = 0xA;
        p->unkD2 = arg0;
        p->unkD4 = arg1;
        p->unkD6 = arg2;
        p->unkD8 = arg3;
        r = func_150ADA20() & 0x7F;
        for (i = 0; i < 3; i++) {
            if (arg3 != 1.0f) {
                func_15043D90(&p->mtx[i], 0.0f, r, 0.0f, arg3, arg3, arg3, arg0, arg1, arg2);
            } else {
                func_15043E68(&p->mtx[i], 0.0f, r, 0.0f, arg0, arg1, arg2);
            }
            r += (func_150ADA20() & 0x3F) + 0x5A;
        }
        func_1517E05C(arg0, arg1, arg2);
    }
}

struct func_15166B50_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    u8 pad1C[3];
    u8 unk1F;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    u8 pad30[4];
    s16 unk34;
    u8 pad36[6];
};

struct func_15166B50_p {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[3];
    Mtx mtx[3];
    u8 unkD0;
    u8 padD1[7];
    f32 unkD8;
};

extern s32 D_8008CA4C;
extern void func_150A7960(void *mtx, f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);
extern void *func_15167D84(void *arg0, s32 arg1, s32 arg2, s8 arg3, u8 arg4, s32 arg5);

void func_15166B50(void *arg) {
    f32 mf[4][4];
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    struct func_15166B50_p *arg0;

    arg0 = arg;
    if (--arg0->unkD0 == 5) {
        struct func_15166B50_s sp70;

        sp70.unk0 = D_8008CA4C;
        sp70.unk4 = 0;
        sp70.unk8 = 4;
        sp70.unkC = 0;
        sp70.unk16 = 0;
        sp70.unk18 = 0;
        sp70.unk1A = 0;
        sp70.unk1F = 5;
        sp70.unk20 = 0;
        sp70.unk22 = 0;
        sp70.unk24 = arg0->unkD8 * 4000.0f;
        sp70.unk26 = arg0->unkD8 * 4000.0f;
        sp70.unk28 = 0x200;
        sp70.unk2A = 0;
        sp70.unk2B = 0;
        sp70.unk2C = 0xFF;
        sp70.unk2D = 0xFF;
        sp70.unk2E = 0xFF;
        sp70.unk2F = 0xFF;
        sp70.unk34 = 0;
        for (i = 0; i < 3; i++) {
            guMtxL2F(mf, &arg0->mtx[i]);
            func_150A7960(mf, -400.0f, 10.0f, 0.0f, &x, &y, &z);
            sp70.unkE = (func_150ADA20() & 0x7F) + 0x55;
            sp70.unk10 = x;
            sp70.unk12 = y;
            sp70.unk14 = z;
            func_15167D84(&sp70, 0, 0, -1, arg0->unkC, arg0->unk1);
        }
    } else if (arg0->unkD0 == 0) {
        func_1516972C((struct102 *)arg0);
    }
}

extern Vtx D_8008B3E0[];

Gfx *func_15166D68(Gfx *gdl, struct func_151669A0_s *p, s32 arg2) {
    s32 i;
    s32 t;

    for (i = 0; i < 3; i++) {
        gSPMatrix(gdl++, &p->mtx[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gdl++, D_8008B3E0, 6, 0);
        t = 0x2800 - (p->unkD0 << 12) / 10;
        gSPModifyVertex(gdl++, 0, G_MWO_POINT_ST, (t << 16) + 0x2000);
        gSPModifyVertex(gdl++, 1, G_MWO_POINT_ST, (t << 16) + 0x2000);
        gSPModifyVertex(gdl++, 2, G_MWO_POINT_ST, (t << 16) + 0x2400);
        gSPModifyVertex(gdl++, 3, G_MWO_POINT_ST, ((t + 0x800) << 16) + 0x2000);
        gSPModifyVertex(gdl++, 4, G_MWO_POINT_ST, ((t + 0x800) << 16) + 0x2000);
        gSPModifyVertex(gdl++, 5, G_MWO_POINT_ST, ((t + 0x800) << 16) + 0x2400);
        gSP1Triangle(gdl++, 5, 3, 0, 0);
        gSP1Triangle(gdl++, 2, 5, 0, 0);
        gSP1Triangle(gdl++, 1, 4, 5, 0);
        gSP1Triangle(gdl++, 1, 5, 2, 0);
    }
    return gdl;
}

void *func_15094F70();
extern s32 D_8009054C;
extern s32 D_800DD220;
extern s32 D_800DD224;
extern void *D_800DD228;
extern s32 D_800DD230;

void func_15166F6C(void *arg0, void *arg1, void *arg2, void *arg3) {
    func_15094F70(arg0, D_800DD228 = &D_8009054C, D_800DD220, &D_800DD230, 0, 0, 0, D_800DD224, 3);
}

extern Mtx D_80089470;

Gfx *func_15166FD8(Gfx *gdl, s32 arg1, s32 arg2) {
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gdl;
}
