#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DE5A0/func_150B10F0.s")

s32 func_1502178C(struct127 *, s32, s32);
s32 func_150535F4(struct127 *);
void func_15056B08(struct127 *);
extern f32 D_8009F8BC;
extern f32 D_8009F8C0;

void func_150B12FC(struct127 *arg0) {
    s16 pad;
    s16 old;
    f32 diff;

    old = *(s16 *)&arg0->unk76;
    arg0->unk80 = 10;
l0:
    func_15058EA4(arg0, ((s16 *)D_800D2104[arg0->unk13F])[1], 1.0f, ((s16 *)D_800D2104[arg0->unk13F])[1], D_8009F8BC, 12.0f, -16.0f);
    func_15056B08(arg0);
    old -= arg0->unk76;
    diff = (s16)(old * 6) * 0.00390625f - arg0->unkC4;
    if (diff > 6.0f) {
        diff = 6.0f;
    } else if (diff < -6.0f) {
        diff = -6.0f;
    }
    arg0->unk148 += (diff - arg0->unk148) * D_8009F8C0;
    arg0->unkC4 += arg0->unk148;
lbl:
    arg0->unk40 = (s16)(arg0->unk7A + 0x4000) * 0.005493164f;
    func_15059140(arg0);
    if (func_150535F4(arg0) == 0) {
        func_1502178C(arg0, 0, -1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DE5A0/func_150B1484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DE5A0/func_150B17DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DE5A0/func_150B19E0.s")
