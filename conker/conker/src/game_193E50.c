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

#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_15166B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193E50/func_15166D68.s")

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
