#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10E240/func_150E0D90.s")

void *func_151149AC(u8);
extern u8 D_800A0FE0[];

struct func_150E1060_s {
    u8 id;
    void *unk4;
    void *unk8;
    f32 unkC;
};

struct260 *func_150E1060(u8 arg0, u8 arg1, s32 arg2) {
    struct260 *ret;
    struct func_150E1060_s s;

    if (arg0 < 0) {
        return NULL;
    }
    if (arg0 >= 2) {
        return NULL;
    }
    s.id = arg0;
    s.unk4 = func_151149AC(D_800A0FE0[arg0]);
    if (s.unk4 == NULL) {
        return NULL;
    }
    func_1510F800(0);
    s.unk8 = func_1510FD20(*(s16 *)((char *)s.unk4 + 0x10), *(s16 *)((char *)s.unk4 + 0x14));
    s.unkC = 0.0f;
    ret = func_15149130(0x12C, -1, 0x1F, -1, 0, 0x1F, (struct37 *)0x10, arg1, arg2);
    if (ret != NULL) {
        memcpy((char *)ret + 0x28, &s, 0x10);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10E240/func_150E114C.s")
