#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800D2DC0[];

void func_15096970(void) {
    bzero(D_800D2DC0, 0x6C);
    D_800D2DB4 = 0;
}

struct func_150969A0_s {
    u8 unk0;
    u8 pad[0x23];
};

s32 func_150969A0(s32 arg0) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        if (((struct func_150969A0_s *)D_800D2DC0)[i].unk0 != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15096A68.s")

s32 func_15096A68(s32 arg0);

void func_15096D08(void) {
    s32 i;

    if (D_800C35EA != 1) {
        for (i = 0; i != 3; i++) {
            if (D_800D2DC0[i * 0x24] != 0) {
                if (func_15096A68(i) != 0) {
                    return;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15096D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_1509759C.s")

extern s32 D_800D2E30[];

void func_15097798(s32 arg0) {
    struct108 *p;
    f32 sp20[3];
    s32 pad[2];

    p = &D_800DBFF0[arg0];
    if (D_800D2DB4 != 0) {
        func_15048F90(&p->unk2A4, &p->unk2F8, sp20);
        func_1504917C(sp20, sp20);
        p->unk2A4 += sp20[0] * -2.5f * D_800D2E30[arg0];
        p->unk2A8 += sp20[1] * -2.0f * D_800D2E30[arg0];
        *(f32 *)&p->unk2AC += sp20[2] * -2.5f * D_800D2E30[arg0];
        p->unk2F8 += sp20[0] * -2.5f * D_800D2E30[arg0];
        p->unk2FC += sp20[1] * -2.0f * D_800D2E30[arg0];
        p->unk300 += sp20[2] * -2.5f * D_800D2E30[arg0];
    }
}
