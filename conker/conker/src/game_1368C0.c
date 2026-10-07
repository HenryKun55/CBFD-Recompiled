#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15109410_s {
    u8 *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
    s8 unk10;
    s8 unk11;
};

struct260 *func_15109410(u8 *arg0, s16 arg1, s8 arg2, s8 arg3, f32 arg4, s32 arg5, u8 arg6, s32 arg7) {
    struct260 *temp_v0;
    struct func_15109410_s tmp;
    s16 id;
    u8 flag;

    if (arg0 == NULL) {
        return NULL;
    }
    flag = 0;
    if (arg1 < 0) {
        id = 300;
    } else {
        flag = 1;
        id = arg1;
    }
    tmp.unk8 = 0.0f;
    tmp.unkC = arg4;
    tmp.unk10 = arg2;
    tmp.unk11 = arg3;
    tmp.unk0 = arg0;
    tmp.unk4 = arg0[0x3B];
    temp_v0 = func_15149130(id, -1, 0x1A, -1, flag, 0x1A, (struct37 *)(arg5 + 0x14), arg6, arg7);
    if (temp_v0 != NULL) {
        memcpy((char *)temp_v0 + 0x28, &tmp, 0x14);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_151094FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109C20.s")

struct func_15109ED4_s {
    void *unk0;
    f32 unk4;
    f32 unk8;
    s8 unkC;
    s8 unkD;
};

struct260 *func_15109ED4(void *arg0, s16 arg1, s8 arg2, s8 arg3, f32 arg4, s32 arg5, u8 arg6, s32 arg7) {
    struct260 *temp_v0;
    struct func_15109ED4_s sp34;
    s16 id;
    u8 flag;

    if (arg0 == NULL) {
        return NULL;
    }
    flag = 0;
    if (arg1 < 0) {
        id = 300;
    } else {
        flag = 1;
        id = arg1;
    }
    sp34.unk4 = 0.0f;
    sp34.unk8 = arg4;
    sp34.unkC = arg2;
    sp34.unkD = arg3;
    sp34.unk0 = arg0;
    temp_v0 = func_15149130(id, -1, 0x1B, -1, flag, 0x1B, (struct37 *)(arg5 + 0x10), arg6, arg7);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp34, 16);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109FB8.s")

extern f32 D_800A2684;
extern f32 D_800A2688;
struct func_1510A344_s {
    void *unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

struct260 *func_1510A344(u8 *arg0, s16 arg1, u8 arg2, s32 arg3) {
    struct260 *temp_v0;
    struct func_1510A344_s sp30;

    if (arg0 == NULL) {
        return NULL;
    }
    sp30.unk0 = arg0;
    sp30.unk4 = arg0[0x3B];
    sp30.unk8 = 0.0f;
    sp30.unkC = D_800A2684;
    sp30.unk10 = D_800A2688;
    temp_v0 = func_15149130(arg1, -1, 0x1C, -1, 1, 0x1C, (struct37 *)0x14, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp30, 0x14);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A40C.s")

struct func_1510A870_s { s32 a; u8 b; };
struct func_1510A870_t { s32 x; s32 y; u8 c; u8 d; };

void func_1510A870(u8 *arg0, struct func_1510A870_t *arg1, u8 arg2) {
    struct func_1510A870_s *p = (struct func_1510A870_s *)(arg0 + 0x28);
    s32 x;

    if (arg2 == 0x2D) {
        x = arg1->x;
        if (x == p->a) {
            p->a = arg1->y;
            p->b = arg1->d;
        } else if (p->a == arg1->y) {
            p->a = x;
            p->b = arg1->c;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A8CC.s")
