#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800D1928;
extern s32 D_800D192C;
extern s32 D_800D1930;

void func_15080200(void) {
    s32 *a = &D_800D192C;
    s32 *b = &D_800D1928;

    *a = 0;
    *b = 0;
    D_800D1930 = 0;
    if (a == b) {
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD6B0/func_15080228.s")

struct func_15080348_s {
    u8 pad0[0x134];
    u8 unk134;
    u8 unk135;
    u8 pad136[0x1FF - 0x136];
    u8 unk1FF;
};

extern s32 D_800427F0;
extern s32 D_8009BD10[];
extern s32 func_151EF610(void);

void func_15080348(struct func_15080348_s *arg0) {
    s32 i;
    s32 v;

    v = D_800D1928;
    if (v != 0) {
        if (arg0 != NULL) {
            if (v == 1) {
                if (D_800427F0 < 1000) {
                    arg0->unk1FF = 0;
                } else {
                    arg0->unk1FF = 1;
                }
            } else {
                i = D_800D192C;
                if (D_800427F0 > 1000) {
                    v = arg0->unk135;
                    v -= D_800BE9E4;
                    if (v < 0) {
                        i++;
                        if (i >= 5) {
                            i = 0;
                        }
                        arg0->unk134 = D_8009BD10[i];
                        arg0->unk135 = (func_151EF610() % 7) + 4;
                        D_800D192C = i;
                    }
                }
            }
            D_800427F0 = 0;
        }
    }
}

struct func_15080430_s {
    u8 pad0[0x72];
    u16 unk72;
    u8 pad74[0x1FF - 0x74];
    u8 unk1FF;
};

s32 func_1507E968(struct func_15080430_s *arg0, s32 arg1, s32 arg2);
void func_1507E500(struct func_15080430_s *arg0, s32 arg1, s32 arg2);

void func_15080430(struct func_15080430_s *arg0, s32 arg1, s32 arg2) {
    s32 temp;

    if (arg0 != NULL) {
        if (func_1507E968(arg0, arg1, arg2) > 0) {
            if (arg1 == 0) {
                D_800D1928 = 0;
                arg0->unk72 = 20;
                func_1507E500(arg0, 0, 10);
                return;
            }
            arg0->unk72 = 0xFFFE;
            if (arg1 == 1) {
                D_800D1928 = 2;
                return;
            }
            if (arg2 != 0) {
                if (arg2 > 20) {
                    arg2 = 20;
                }
                if (arg2 <= 0) {
                    arg2 = 1;
                }
            }
            func_1507E500(arg0, arg1, arg2);
            return;
        }
        temp = arg1 != 0;
        D_800D1928 = temp;
        if (temp == 0) {
            arg0->unk1FF = 0;
        }
    }
}
