#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_C4DC0/func_15097910.s")

struct func_150979CC_s {
    u8 unk0[2];
    u8 unk2;
    u8 pad3[0x2D];
};

extern u8 D_800D2100;
extern s32 D_800D3840;
extern void *func_1505EEF4(s32);
extern void func_15053430(void *);

s32 func_150979CC(s32 arg0, s32 *arg1) {
    void *obj;

    obj = func_1505EEF4(arg0);
    if (obj == NULL) {
        return 0;
    }
    if (arg0 < D_800D2100) {
        ((struct func_150979CC_s *)D_800D20FC)[arg0].unk2 = 1;
    }
    if (D_800D3840 == 2) {
        if (arg1[1] == 0) {
            func_15060F28(obj, 0);
        } else {
            func_15053430(obj);
        }
    } else {
        func_15060F28(obj, 0);
    }
    return 999999;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C4DC0/func_15097A8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C4DC0/func_15099C14.s")
