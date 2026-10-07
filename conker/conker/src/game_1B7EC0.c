#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7EC0/func_1518AA10.s")

struct func_1518AADC_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    u8 unk24;
};

void *func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);

struct func_1518AADC_s *func_1518AADC(s32 arg0, s16 arg1, u8 arg2) {
    struct func_1518AADC_s *v1;

    v1 = func_15167A68(0x1D, 0, 0x28, 1, 0xFF, 1);
    if (v1 == NULL) {
        return NULL;
    }
    v1->unk1C = 0;
    v1->unk18 = arg0;
    v1->unk22 = arg1;
    v1->unk20 = arg1;
    v1->unk10 = 0;
    v1->unk14 = 0;
    v1->unk24 = arg2;
    return v1;
}

struct func_1518AB60_s {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
};

struct func_1518AB60_s *func_1518AB60(s32 arg0, u8 arg1) {
    struct func_1518AB60_s *ret = (struct func_1518AB60_s *) func_15167A68(0x1E, 0, 0x20, 1, 0xFF, 1);
    if (ret == NULL) {
        return NULL;
    }
    ret->unk10 = arg0; ret->unk1C = arg1; ret->unk18 = 0; ret->unk14 = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7EC0/func_1518ABD0.s")
