#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150825C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_1508295C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150829D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15082A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150832AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150836CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150837D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150838EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150839B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083FB0.s")

struct127 *func_1505EEF4(s32 arg0);

s32 func_15084000(s32 arg0) {
    struct127 *obj = func_1505EEF4(arg0);
    if (obj != NULL) {
        return obj - gObjects;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084044.s")

void func_150843AC(u8 *arg0, s32 arg1);

void func_1508434C(u8 *arg0) {
    s32 n;
    s32 i;

    n = arg0[0x2C9];
    if (n == 0) {
        n = 1;
    }
    for (i = 0; i < n; i++) {
        func_150843AC(arg0, i);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150843AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084558.s")

struct func_150849A0_s {
    u8 pad0[0x1C9];
    u8 unk1C9;
    u8 pad1CA[0x2C4 - 0x1CA];
    u8 *unk2C4;
};

u8 func_150849A0(struct func_150849A0_s *arg0) {
    if (arg0->unk1C9 != 0) {
        return arg0->unk2C4[arg0->unk1C9 - 1];
    }
    return arg0->unk2C4[0];
}

struct func_150849CC_s {
    u8 pad0[0x1C9];
    u8 unk1C9;
    u8 pad1CA[0x2C4 - 0x1CA];
    u8 *unk2C4;
    u8 unk2C8;
};

u8 func_150849CC(struct func_150849CC_s *arg0, s32 *arg1) {
    s32 idx;

    if (arg0->unk1C9 != 0) {
        idx = arg0->unk1C9 - 1;
    } else if (arg0->unk2C8 != 0) {
        idx = arg0->unk2C8 - 1;
    } else {
        idx = 0;
    }
    if (arg1 != NULL) {
        *arg1 = idx;
    }
    return arg0->unk2C4[idx];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084C30.s")

extern u8 D_800BE590;
extern u16 D_800BE598[];

s32 func_15084CB0(s32 arg0) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < D_800BE590; i++) {
        if (arg0 == D_800BE598[i]) {
            ret = i;
            break;
        }
    }
    return ret;
}
