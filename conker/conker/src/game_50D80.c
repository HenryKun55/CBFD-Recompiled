#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150238D0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150238D8.s")

typedef struct func_15023BB0_s {
    s8 b0;
    u8 b1;
    s16 h2;
    s8 b4;
    s8 b5;
    s16 pad6;
} func_15023BB0_s;

extern s32 D_800C3640[];
extern u16 *D_800C35D8[];
extern u8 *D_800C3688[][30];

s32 func_15023BB0(u32 arg0, s32 arg1, s32 arg2, func_15023BB0_s **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    func_15023BB0_s *p;
    s32 val;
    s32 b1;

    if (D_800C3688[arg10][arg2] != NULL) {
        val = ((func_15023BB0_s *)D_800C3688[arg10][arg2])->h2;
        for (p = (func_15023BB0_s *)D_800C3688[arg10][arg2] + 4; (u32)(p - (func_15023BB0_s *)D_800C3688[arg10][arg2]) < D_800C35D8[arg10][arg2]; p++) {
            b1 = p->b1;
            if (b1 == 0 && p->b0 == 0) {
                val = p->h2;
                continue;
            }
            if ((arg0 < (u32)p) && (arg1 == p->b0)
                && ((arg4 == 0) || ((arg4 == 1) && (arg5 == p->h2)))
                && ((arg6 == 0) || ((arg6 == 1) && (arg7 == p->b4)))
                && ((arg8 == 0) || ((arg8 == 1) && (arg9 == p->b5)))) {
                *arg3 = p;
                return val;
            }
            while (b1 == 0) {
                if (p->b0 == 0) {
                    val = p->h2;
                    break;
                }
                p++;
                if ((u32)(p - (func_15023BB0_s *)D_800C3688[arg10][arg2]) >= D_800C35D8[arg10][arg2]) {
                    b1 = p->b1;
                    break;
                }
                if ((arg0 < (u32)p) && (arg1 == p->b0)
                    && ((arg4 == 0) || ((arg4 == 1) && (arg5 == p->h2)))
                    && ((arg6 == 0) || ((arg6 == 1) && (arg7 == p->b4)))
                    && ((arg8 == 0) || ((arg8 == 1) && (arg9 == p->b5)))) {
                    *arg3 = p;
                    return val;
                }
                b1 = p->b1;
            }
            val += b1;
        }
    }
    *arg3 = NULL;
    return D_800C3640[arg10];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15023DE0.s")

struct func_15024130_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 pad9;
    u16 unkA;
};
extern struct func_15024130_s *D_800C3D50;
void func_1502A8A0();

void func_15024130(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        func_1502A8A0(D_800C3D50[i].unk0, D_800C3D50[i].unk8, D_800C3D50[i].unkA, D_800C3D50[i].unk4, arg1);
    }
}

extern u16 D_800C3C9A;

void func_150241B4(struct func_15024130_s *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 i;
    s32 idx;

    if (*arg1 >= D_800C3C9A) {
        func_15024130(*arg1, arg6);
        *arg1 = 0;
        return;
    }
    idx = *arg1;
    for (i = 0; i < *arg1; i++) {
        if (arg0[i].unk4 >= arg5) {
            idx = i;
            break;
        }
    }
    for (i = *arg1 - 1; i >= idx; i--) {
        arg0[i + 1] = arg0[i];
    }
    arg0[idx].unk0 = arg2;
    arg0[idx].unk8 = arg3;
    arg0[idx].unkA = arg4;
    arg0[idx].unk4 = arg5;
    *arg1 += 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150242F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502460C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150265CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15029BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502A8A0.s")
