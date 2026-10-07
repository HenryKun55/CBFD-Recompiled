#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s16 func_15063390(struct127 *arg0) {
    return func_1505A630(gObjects[arg0->unk222].x_position - arg0->x_position,
                         arg0->z_position - gObjects[arg0->unk222].z_position, 0);
}

void func_15063404(struct127 *arg0) {
    struct127 *obj = &gObjects[arg0 - gObjects];

    obj->unk31C->unk78 = 9;
    func_15083568(arg0, 0x1D, 0x3F800000, 0);
    func_15083568(arg0, 0x1E, 0x3F800000, 0);
    arg0->disable_jump = 20;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
    *(s16 *)((u8 *)obj->unk31C + 0x24) = 60;
    obj->unk31C->unk11A = 2;
    func_1505E650(arg0, 0x7F, 1.0f, 0.0f, 0.0f, 0.0f, 0);
}

void func_150634E4(struct127 *arg0) {
    gObjects[arg0 - gObjects].unk31C->unk78 = 0;
    gObjects[arg0 - gObjects].unk31C->unk11A = 0;
    func_150836CC(arg0, 0x1D);
    func_150836CC(arg0, 0x1E);
    arg0->disable_jump = 0;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
}

void func_15063570(struct127 *arg0) {
    gObjects[arg0 - gObjects].unk31C->unk78 = 0x3B;
    gObjects[arg0 - gObjects].unk31C->unk11A = 2;
    func_15083568(arg0, 0x89, 0x3F800000, 0);
    arg0->disable_jump = 0x14;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
    func_1505E650(arg0, 0x221, 1.0f, 0.0f, 0.0f, 0.0f, 0);
}

void func_15081690(void *, s32, s32, s32, f32, f32, f32, void *, f32, s32, s32, s32, s32, s32, s32);
void func_150636A4(void *);

void func_15063628(void *arg0, f32 arg1) {
    char *temp_v0 = *(char **)((char *)arg0 + 0x31C);

    func_15081690(arg0, *(s32 *)(temp_v0 + 0x13C), *(s32 *)(temp_v0 + 0x140), *(s32 *)(temp_v0 + 0x144),
                  *(f32 *)(temp_v0 + 0x130), *(f32 *)(temp_v0 + 0x134), *(f32 *)(temp_v0 + 0x138),
                  temp_v0 + 0xB0, arg1, 0, 0, 0, -1, 0, 0);
    func_150636A4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636F0.s")

extern s16 D_800CC2B2;
s16 func_15063390(struct struct127 *arg0);

s16 func_150639BC(struct struct127 *arg0) {
    D_800CC2B2 = (arg0->unk7A - arg0->unk31C->unk12) - func_15063390(arg0);
    if (D_800CC2B2 > 0x3E80) {
        D_800CC2B2 = 0x3E80;
    }
    if (D_800CC2B2 < -0x3E80) {
        D_800CC2B2 = -0x3E80;
    }
    return D_800CC2B2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063C60.s")

s32 func_15063E84(struct struct127 *arg0, u16 arg1, u16 arg2, s32 arg3, s32 arg4) {
    if ((arg4 & 0x4000) && (0.0f == arg0->unk28) && (arg0->y_velocity <= 0.0f) &&
        (*(u8 *)&arg0->unk31C->unk95 == 0) && (arg0->unk84.uh != arg1) &&
        ((arg0->unk31C->unk11A == 0) || (arg0->unk31C->unk11A == 2)) && (arg0->unk31C->unk27 == 0)) {
        if (arg3 && arg0->disable_jump) {
            return 999;
        }
        if (arg2 & 1) {
            arg0->disable_jump = 20;
        }
        if (arg3) {
            if (arg0->unk31C->unk11A == 2) {
                return 999;
            }
            arg0->unk31C->unk11A = 1;
        } else {
            arg0->unk31C->unk11A = 3;
        }
        arg0->unk31C->unk78 = arg3;
        arg0->disable_run = 0xFF;
        arg0->unk83 = 0xFF;
        return arg1;
    }
    return 999;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063FA0.s")

s32 func_1505DADC(struct127 *, u16 *, s32, s32, s32);

s32 func_150641D8(struct127 *arg0, u16 arg1, u16 arg2, u16 arg3) {
    u16 ret = arg1;
    s32 a;
    u16 sp26 = 0;

    if (func_150ADA20() & 1) {
        ret = arg2;
    }
    if (arg0->unk84.uh == arg1 || arg0->unk84.uh == arg2) {
        if (arg0->unk107 < 40) {
            return 999;
        }
        ret = arg3;
    }
    if (arg0->unk84.uh == arg3) {
        ret = 999;
    }
    if (func_1505DADC(arg0, &sp26, 0, 0xFE, 0x40) != 0xFF) {
        arg0->unk76 = sp26;
    }
    arg0->unk83 = 0xFF;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150642AC.s")

void func_150649A0(s32 arg0, s32 arg1) {
    struct197 *a = gObjects[arg1].unk2D0;
    struct197 *b = gObjects[arg0].unk2D0;

    if ((a != NULL) && (b != NULL)) {
        a->unk8 = b->unk8;
        if (a->unk18 <= a->unk8) {
            a->unk8 = a->unk18 - 1.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15065A5C.s")
