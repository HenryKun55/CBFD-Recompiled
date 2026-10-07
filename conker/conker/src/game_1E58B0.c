#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E58B0/func_151B8400.s")

typedef struct func_151B85AC_v { f32 x, y, z; } func_151B85AC_v;

struct func_151B85AC_o {
    u8 pad0[0x34];
    func_151B85AC_v rot;
    f32 pos[3];
    f32 vel[3];
    s32 flags;
    u8 pad5C[0x110 - 0x5C];
    u8 *parent;
};

s32 func_151B85AC(struct func_151B85AC_o *arg0) {
    u8 *p = arg0->parent;
    if (p != NULL) {
        arg0->rot = *(func_151B85AC_v *)(p + 0x38);
        arg0->pos[0] += arg0->vel[0] * D_800BE9A4;
        arg0->pos[1] += arg0->vel[1] * D_800BE9A4;
        arg0->pos[2] += arg0->vel[2] * D_800BE9A4;
    } else {
        arg0->flags |= 1;
    }
    return 1;
}

void func_1513FA70(void *arg0, s16 arg1);

void func_151B863C(void *arg0, s16 arg1) {
    func_1513FA70(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E58B0/func_151B8668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E58B0/func_151B86F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E58B0/func_151B8908.s")
