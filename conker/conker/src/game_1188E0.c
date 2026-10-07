#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150EB430(f32 *arg0, f32 *arg1, s32 arg2) {
    f32 sp1C[3];

    sp1C[0] = arg1[0] + arg0[0];
    sp1C[1] = arg1[1] + arg0[1];
    sp1C[2] = arg1[2] + arg0[2];
    func_150EB484(arg0, sp1C, arg2);
}

struct func_150EB484_s { u8 pad0[0x18]; s32 unk18; u8 pad1C[0x18]; };
extern s32 D_80088AA0[4];
extern s32 D_80088AB0[8];
s32 func_150A34B0();
void func_150A2864(u32, s32);
void func_150EBC80();

int func_150EB484(f32 *arg0, f32 *arg1, s32 arg2) {
    s32 i;
    s32 idx;
    struct127 *sp44;
    s32 off;

    sp44 = func_15083E90(9);
    if (sp44 != NULL) {
        for (i = 0; i < 4; i++) {
            idx = D_80088AA0[i];
            if (func_150A34B0(*(u8 **)&D_800D3098 + (off = idx * 0x34), arg0, arg1, arg2) != 0) {
                func_150A2864(idx, 1);
                sp44->unk2E8 = i + 1;
                func_150EBC80(*(u8 **)&D_800D3098 + (off = idx * 0x34), 0xFF, 1);
                return 1;
            }
        }
        for (i = 0; i < 8; i++) {
            if (func_150A34B0(*(struct func_150EB484_s **)&D_800D3098 + D_80088AB0[i], arg0, arg1, arg2) != 0) {
                return 1;
            }
        }
        return 0;
    }
    if (func_150A34B0(*(struct func_150EB484_s **)&D_800D3098 + 76, arg0, arg1, arg2) != 0) {
        (*(struct func_150EB484_s **)&D_800D3098)[76].unk18 = 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1188E0/func_150EB614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1188E0/func_150EB8C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1188E0/func_150EBC80.s")
