#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BB760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BBB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BC488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BCBBC.s")

extern f32 D_8009FEF8;

struct func_150BCFB8_s {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x3C - 0x18];
    f32 unk3C;
    u8 pad40[4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[4];
    s32 unk60;
};

s32 func_150BCFB8(struct func_150BCFB8_s *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    f32 temp_f2;

    arg0->unk3C = arg0->unk10 * D_8009FEF8 + arg4;
    if (arg0->unk48 > -2.0f) {
        arg0->unk44 = 0.0f;
        arg0->unk60 &= ~0x6F;
        arg0->unk48 = 0.0f;
        arg0->unk4C = 0.0f;
    } else {
        temp_f2 = arg0->unk14;
        arg0->unk44 *= temp_f2;
        arg0->unk48 = -arg0->unk48 * temp_f2;
        arg0->unk4C *= temp_f2;
        arg0->unk50 *= temp_f2;
        arg0->unk54 *= temp_f2;
        arg0->unk58 *= temp_f2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BD070.s")

struct func_150BD740_s {
    u8 pad0[0x1D4];
    void *unk1D4;
};

extern f32 D_8009FF40[4][3];
extern f32 D_8009FF70[4][3];
extern f32 D_8009FFA0[4][3];
void func_1514C470(f32, f32, f32, f32, f32, f32, f32, s32, s32, f32, f32 *, u8);

void func_150BD740(struct func_150BD740_s *arg0, u8 arg1, s32 arg2) {
    f32 a[4][3];
    f32 b[4][3];
    f32 c[4][3];
    f32 pad;
    f32 d2[3];
    f32 d1[3];
    f32 pad2[4];
    s32 i;

    if (arg0 != NULL && arg0->unk1D4 != NULL) {
        for (i = 0; i < 4; i++) {
            func_15143134(D_8009FF40[i], a[i], arg0->unk1D4);
            func_15143134(D_8009FF70[i], b[i], arg0->unk1D4);
            func_15143134(D_8009FFA0[i], c[i], arg0->unk1D4);
        }
        d1[0] = c[2][0] - b[2][0];
        d1[1] = c[2][1] - b[2][1];
        d1[2] = c[2][2] - b[2][2];
        func_1514C470(a[2][0], a[2][1], a[2][2], a[3][0], a[3][1], a[3][2],
                      func_150ADA68() * 6.0f + 14.0f, 13, 0, 0.0f, d1, arg1);
        d2[0] = c[3][0] - b[3][0];
        d2[1] = c[3][1] - b[3][1];
        d2[2] = c[3][2] - b[3][2];
        func_1514C470(a[3][0], a[3][1], a[3][2], a[0][0], a[0][1], a[0][2],
                      func_150ADA68() * 6.0f + 14.0f, 13, 0, 0.0f, d2, arg1);
    }
}

struct func_150BD954_s {
    f32 pos[3];
    s16 unk0C;
    s16 unk0E;
    s32 unk10;
    u8 pad14;
    u8 unk15;
    u8 pad16[10];
};

struct func_150BD954_s2 {
    f32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s32 unk1C;
};

struct func_150BD954_s3 {
    s32 w[9];
};

extern f32 D_8009FFD0;
extern f32 D_8009FFD4;
extern f32 D_8009FFD8;
extern f32 D_8009FFDC;
extern f32 D_8009FFE0;
extern f32 D_8009FFE4;
void *func_15147DA0(s32 *arg0, void *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, struct func_150BD954_s3 *arg11, s32 arg12, u8 arg13, s32 arg14);

s32 func_150BD954(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, f32 *arg13, u8 arg14) {
    struct func_150BD954_s s1;
    struct func_150BD954_s2 s2;
    struct func_150BD954_s3 s3;
    f32 t;

    s3.w[0] = 0;
    s3.w[1] = 1;
    s3.w[2] = 0x160600;
    s3.w[3] = 3;
    s3.w[4] = 0x10;
    s3.w[5] = 0x80;
    s3.w[6] = 0x20;
    ((u8 *)&s3.w[7])[0] = 0;
    ((u8 *)&s3.w[7])[1] = 9;
    s1.unk10 = 1;
    s1.unk0E = 1;
    s1.pos[0] = arg2;
    s1.pos[1] = arg3;
    s2.unk14 = arg3;
    s2.unk19 = 9;
    s2.unk1A = 0xFF;
    s2.unk18 = 8;
    s1.pos[2] = arg4;
    t = (func_150ADA68() * 127.0f + 85.0f) * D_8009FFD0;
    s2.unk04 = arg13[0] * t;
    s2.unk08 = arg13[1] * t;
    s2.unk0C = arg13[2] * t;
    s2.unk1B = func_150ADA20() % 86U + 180;
    s1.unk15 = (func_150ADA20() & 3) + 3;
    s1.unk0C = func_150ADA20() % 31U + 39;
    s2.unk00 = (func_150ADA68() * D_8009FFD4 + D_8009FFD8) * D_8009FFDC;
    s2.unk10 = (func_150ADA68() * 356.0f + D_8009FFE0) * D_8009FFE4;
    func_15147DA0((s32 *)&s1, &s2, NULL, 1, 0xB, 0, 0, 0, 0, 0, 0, &s3, 0, arg14, 1);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BDB3C.s")
