#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_15103800(void) {
    bzero(D_800D9AB0, 8); // bzero
}

void func_15103828(void) {
    u16 temp_v1;
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (D_800D9AB0[i]) {
            if (D_800D9AB0[i] > D_800BE9E4)
            {
                D_800D9AB0[i] -= D_800BE9E4;
            } else {
              D_800D9AB0[i] = 0;
            }
        }
    }
}

// need to figure out the structs
#pragma GLOBAL_ASM("asm/nonmatchings/game_130CB0/func_15103910.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_130CB0/func_15103AA0.s")
void *func_1505EEF4(s32);
void func_15103910();
void func_15103AA0();

void func_15103C14(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    u8 *obj;
    s32 sp48;

    sp48 = 0;
    if ((D_800D9AB0[arg3] == 0) || (arg0 == 0x58D)) {
        obj = func_1505EEF4(arg1);
        if ((obj != NULL) && (func_10010894(obj) == 0)) {
            if (arg2 != 0) {
                if (arg4 != 0) {
                    arg0 += (func_150ADA20() % arg2) * 2;
                } else {
                    arg0 += func_150ADA20() % arg2;
                }
            }
            if (*(s32 *)(obj + 0x318) != 0) {
                sp48 = 1;
            } else if (arg4 != 0) {
                arg0 += 1;
            }
            if (sp48 != 0) {
                func_1000FA64(arg0, *(f32 *)(obj + 0x14), *(f32 *)(obj + 0x18), *(f32 *)(obj + 0x1C), 0x7530, 0x7FFF, 0x7FFE, (s32) func_15103910, 0x14, (s32) obj, 0x100, 0);
            } else {
                func_1000FA64(arg0, *(f32 *)(obj + 0x14), *(f32 *)(obj + 0x18), *(f32 *)(obj + 0x1C), 0x7FBC, 0x7FFF, 0x7FFE, (s32) func_15103AA0, (arg4 << 0xF) | 0x14, (s32) obj, 0x100, 0);
            }
            D_800D9AB0[arg3] = 0x258;
        }
    }
}
