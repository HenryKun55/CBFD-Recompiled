#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150CE150_s {
    void *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    u8 unk14;
    u8 pad[0x8F0 - 0x15];
};

struct func_150CE150_h {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    s16 unk4;
    u8 unk6;
};

extern f32 D_800A07FC;
void *func_1515FF74(void *, s32, u8, s32);

s32 func_150CE150(u8 *arg0, s16 arg1, u8 arg2, s32 arg3) {
    struct func_150CE150_h sp910;
    struct func_150CE150_s sp20;
    u8 *ret;

    if (arg0 == NULL) {
        return 0;
    }
    sp20.unk8 = D_800A07FC;
    sp20.unkC = D_800A07FC;
    sp910.unk0 = 1;
    sp910.unk1 = 1;
    sp910.unk2 = 0;
    sp910.unk4 = arg1;
    sp910.unk6 = 2;
    sp20.unk10 = 10000;
    sp20.unk14 = 0;
    sp20.unk0 = arg0;
    sp20.unk4 = arg0[0x3B];
    ret = func_1515FF74(&sp910, 0x8F0, arg2, arg3);
    if (ret != NULL) {
        memcpy(ret + 0x18, &sp20, 0x8F0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FB600/func_150CE200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FB600/func_150CE450.s")

struct func_150CE694_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

struct func_150CE694_t {
    s32 unk0;
    u8 unk4;
};


void func_150CE694(struct102 *arg0, struct func_150CE694_s *arg1, u8 arg2) {
    struct func_150CE694_t *p = (struct func_150CE694_t *) ((char *) arg0 + 0x18);
    s32 temp;

    if (arg2 == 0x2D) {
        if (p->unk0 == arg1->unk0) {
            p->unk0 = arg1->unk4;
            p->unk4 = arg1->unk9;
            goto end;
        }
        if (p->unk0 == arg1->unk4) {
            p->unk0 = arg1->unk0;
            p->unk4 = arg1->unk8;
        }
    end:;
    } else if (arg2 == 0) {
        temp = arg1->unk0;
        if ((temp == p->unk0) || (p->unk4 == *(u8 *) &arg1->unk4)) {
            func_1516972C(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FB600/func_150CE740.s")
