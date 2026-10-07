#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10DD20/func_150E0870.s")

void func_1502178C(struct127 *, s32, s32);
s32 func_150535F4(struct127 *);
void func_15056B08(struct127 *);
void func_150585F0(struct127 *, f32);
void func_150599C8(struct127 *, s32, u16);
extern u16 D_800CC346;

void func_150E0BE0(struct127 *arg0) {
    arg0->unkB0 = 0xF;
    arg0->unk80 = 0xA;
    if (arg0->unk87 != 0) {
        if (arg0->unk83 < 100) {
            arg0->unk83 += D_800BE9A0;
        }
        if (arg0->unk83 >= 5) {
            if (arg0->unk251 != 3) {
                arg0->unk78 = D_800CC346;
                arg0->unk218 = NULL;
                arg0->unk232 = 4;
                if (arg0->unk251 == 2) {
                    arg0->unk232 = 2;
                }
            }
        }
    } else {
        if (arg0->unk83 >= 61) {
            D_800D1580 = 0xFF020133;
            gCurrentObject = gObjects;
            func_1506E8D8();
            gCurrentObject = arg0;
        }
        arg0->unk83 = 0;
    }
    if (arg0->unk232 == 4) {
        if (arg0->unk83 == 0) {
            arg0->unk78 = arg0->unk76;
        }
        func_150599C8(arg0, 3, arg0->unk78);
    }
    arg0->unk87 = 0;
    if (arg0->stunned == 0) {
        func_15056B08(arg0);
    } else {
        func_150585F0(arg0, 0.05f);
    }
    arg0->unk40 = (s16)(arg0->unk7A + 0x4000) * 0.005493164f;
    func_15059140(arg0);
    *(f32 *)&arg0->padBC = arg0->x_position - arg0->old_x_position;
    arg0->unk148 = arg0->z_position - arg0->old_z_position;
    if (func_150535F4(arg0) == 0) {
        func_1502178C(arg0, 0, -1);
    }
}
