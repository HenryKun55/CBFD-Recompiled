#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15033FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150341BC.s")

s16 *func_15034340(s16 *arg0, s32 arg1) {
    struct127 *obj = &gObjects[arg1];
    if (obj->unk1D1 != 0) {
        arg0[0] = 6;
        arg0[1] = obj->unk1D1 * 200;
        arg0 += 2;
    }
    return arg0;
}

s16 *func_150343B0(s16 *arg0, s32 arg1) {
    struct127 *obj = &gObjects[arg1];

    if (obj->unk1D1 != 0) {
        arg0[0] = 6;
        arg0[1] = obj->unk1D1 * 200;
        arg0 += 2;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15034420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150344A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_1503453C.s")

void func_150345E4(s32 arg0) {
    if (gObjects[arg0].unk1D4 != NULL) {
        if ((gObjects[arg0].interaction_state == 1) || (gObjects[arg0].unk5 == 7)) {
            func_1503453C(arg0);
        }
        if (gObjects[arg0].interaction_state == 0x22) {
            func_1503453C(arg0);
        }
        switch (gObjects[arg0].id) {
        case 4:
            if (D_800BE616 == 0) {
                func_15036310(0, arg0, 9, 0);
                func_15036310(0, arg0, 4, 0);
            }
            break;
        case 0x70:
            func_15034EB4(&gObjects[arg0], 10, 11);
            break;
        case 0x7B:
            func_150F1A00(&gObjects[arg0]);
            break;
        case 0x60:
            func_150DFDA4(&gObjects[arg0]);
            break;
        }
    }
}

typedef struct func_15034728_m {
    f32 m[4][4];
} func_15034728_m;

struct func_15034728_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x9C - 5];
    u32 unk9C;
    u8 padA0[0x1D4 - 0xA0];
    func_15034728_m *unk1D4;
};

s32 func_1502DB20();

void func_15034728(struct func_15034728_s *arg0) {
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    func_15034728_m *m;

    if (arg0->unk1D4 != NULL && arg0->unk9C != 0) {
        n = func_1502DB20(arg0->unk4) - 1;
        m = arg0->unk1D4;
        i = 31;
        if (n < 31) {
            i = n;
        }
        for (; i >= 0; i--) {
            if (arg0->unk9C & (1 << i)) {
                for (j = 0; j < 3; j++) {
                    for (k = 0; k < 3; k++) {
                        ((f32 (*)[4])(i * 64 + (u32)m))[j][k] = 0.0f;
                    }
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150347E8.s")
