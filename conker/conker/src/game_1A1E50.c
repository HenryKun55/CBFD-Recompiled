#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151749A0(s32 arg0, s32 arg1) {
    D_800DD406 += D_800BE9E4;
    if (arg0 < D_800DD406) {
        D_800DD405++;
        if (D_800DD405 >= arg1) {
            D_800DD405 = 0;
        }
        D_800DD406 = 0;
    }
}

extern void (*D_8008CD04[])(s32);
extern u16 D_800CBD4E;
void func_15195FF0(s32, s32);
void func_1510C8A8(void);
void func_1517DE5C(void);
void func_151880C0(void);

void func_151749F8(s32 arg0, s32 arg1) {
    u8 temp_v0;

    func_15165F70();
    func_15195FF0(D_800B0E00[0], D_800B0E00[1]);
    func_1510C8A8();
    temp_v0 = D_800B0DF0->unkB;
    if (temp_v0 != 0) {
        D_8008CD04[temp_v0](arg1);
    }
    if (D_800BE616 == 0) {
        func_1517DE5C();
        func_151880C0();
    }
    D_800CBD4E += D_800BE9E4 << 6;
}

extern Mtx D_80089470;
extern Gfx *(*D_8008CD74[])(Gfx *, s32);

Gfx *func_15174AA4(Gfx *gdl, s32 arg1, s32 arg2) {
    gDPPipeSync(gdl++);
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (D_800B0DF0->unkC != 0) {
        gdl = D_8008CD74[D_800B0DF0->unkC](gdl, arg2);
    }
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gdl;
}

extern Mtx D_80089470;
extern Gfx *(*D_8008CD7C[])(Gfx *, s32);

Gfx *func_15174B48(Gfx *gdl, s32 arg1, s32 arg2) {
    gDPPipeSync(gdl++);
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (D_800B0DF0->unkD) {
        gdl = D_8008CD7C[D_800B0DF0->unkD](gdl, arg2);
    }
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gdl;
}
