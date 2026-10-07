#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150D82B0(s32 arg0) {
}

extern s32 D_80090298[];
extern f32 D_800A0B10;

struct func_150D82BC_s {
    s32 w0;
    s32 w1;
};

s32 func_150D82BC(void *arg0, void *arg1) {
    f32 *temp_v0;
    struct func_150D82BC_s *gfx;
    s32 i;
    s32 s;
    f32 t;
    s32 w0;

    temp_v0 = *(f32 **)((char *)arg1 + 0x2D0);
    if (temp_v0 == NULL) {
        return 0;
    }
    *(s16 *)((char *)arg0 + 0x18) = D_80090298[6];
    if (*(u16 *)((char *)arg1 + 0x84) == 13) {
        t = temp_v0[2];
        if ((t >= 23.0f) && (t <= 40.0f)) {
            *(s16 *)((char *)arg0 + 0x18) = D_80090298[7];
            gfx = **(struct func_150D82BC_s ***)((char *)arg0 + 0x24);
            t = temp_v0[2] - 23.0f;
            t *= D_800A0B10;
            for (i = 0; *(s8 *)&gfx[i] != -14; i++) {
            }
            w0 = gfx[i].w0;
            s = (70.0f * t) + 2.0f;
            if (s < 0) {
                s += (w0 >> 12) & 0xFFF;
            }
            gfx[i].w0 = ((s & 0xFFF) << 12) | 0xF2000000 | 2;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D83D8.s")

s16 *func_150D8590(s16 *arg0, s32 arg1) {
    arg0[0] = 0x42;
    arg0[1] = 0;
    return arg0 + 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D85AC.s")

struct func_150D88AC_s {
    char pad0[0x14];
    u8 *unk14;
    u8 *unk18;
};

s32 func_150D88AC(struct func_150D88AC_s *arg0) {
    if (arg0->unk18[0x6F] != 0) {
        arg0->unk14[9] = 0;
    } else {
        arg0->unk14[9] = 1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D88E0.s")

s32 func_150D8A20(s32 arg0, s32 arg1) {
    return 8;
}

struct func_150D8A34_s {
    char pad0[0x180];
    f32 unk180;
    char pad184[0x1D4 - 0x184];
    s32 unk1D4;
};

extern f32 D_800A0B30;
extern f32 D_800A0B34;
void func_150D88E0(f32 *arg0, struct func_150D8A34_s *arg1, u8 arg2);
void func_151875E0(f32, f32, f32, s32, s32, s32, f32, f32);
void func_15165F80(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_150D8A34(struct func_150D8A34_s *arg0, s32 arg1, s32 arg2) {
    f32 sp34[3];

    if (arg0->unk1D4 != 0) {
        func_150D88E0(sp34, arg0, arg1);
        func_151875E0(sp34[0], sp34[1], sp34[2], 0x1E, 0xF, 7, D_800A0B30, D_800A0B34);
        func_15165F80(-1, sp34[0], arg0->unk180 + 4.0f, sp34[2], 4, 0x32, 0, 0xFF, 0);
    }
}
