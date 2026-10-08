#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1515FDA0_s {
    u8 pad0[8];
    struct func_1515FDA0_s *next;
    u8 padC[2];
    u8 unkE;
    u8 padF;
    s8 unk10;
};

typedef struct {
    struct func_1515FDA0_s *head;
    u8 pad[0x19C];
} func_1515FDA0_list;

extern func_1515FDA0_list D_800DCF20[];
extern void (*D_8008B0D8[])(struct func_1515FDA0_s *, s32);
extern s32 func_15181CC8(s32);
extern s32 func_1517EF00(s32);

#define STK ((struct func_1515FDA0_s **)D_800DD198)

void func_1515FDA0(s32 arg0) {
    u8 i;
    struct func_1515FDA0_s *obj;
    u8 run;

    for (i = 0; i < 2; ) {
        obj = D_800DCF20[i].head;
        D_800DD190++;
        for (; obj != NULL; obj = STK[D_800DD190]) {
            STK[D_800DD190] = obj->next;
            if (obj->unkE & 4) {
                obj->unkE &= ~4;
                continue;
            }
            if (obj->unk10 == -1) {
                continue;
            }
            run = 1;
            if ((obj->unkE & 2) && D_800C35EA == 1) {
                run = 0;
            }
            if (obj->unkE & 8) {
                if (!func_15181CC8(0) || func_1517EF00(0)) {
                    run = 0;
                }
            }
            if (run) {
                D_8008B0D8[obj->unk10](obj, arg0);
            }
        }
        D_800DD190--;
        i++;
    }
}

struct func_1515FF74_s {
    u8 pad[0xE];
    u8 unkE[8];
};

struct func_1515FF74_s *func_1515FF74(void *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct func_1515FF74_s *ret = func_15167A68(0x34, arg3, arg1 + 0x18, 1, arg2, 1);
    if (ret == 0) {
        return NULL;
    }
    memcpy(&ret->unkE, arg0, 8);
    return ret;
}

extern s32 (*D_8008B0D0[])(struct102 *);

void func_1515FFEC(struct102 *arg0) {
    s32 idx;
    u8 done = 0;

    if (((u8 *)arg0)[0xE] & 1) {
        *(s16 *)((u8 *)arg0 + 0x12) -= D_800BE9E4;
        if (*(s16 *)((u8 *)arg0 + 0x12) < 0) {
            done = 1;
        }
    }
    if (!done) {
        idx = ((s8 *)arg0)[0xF];
        if (idx != -1) {
            if (D_8008B0D0[idx](arg0) == 0) {
                done = 1;
            }
        }
    }
    if (done) {
        func_1516972C(arg0);
    }
}

extern void (*D_8008B0E4[])(void *, s32, u8);

void func_15160090(u8 *arg0, s32 arg1, u8 arg2) {
    void (*fn)(void *, s32, u8) = D_8008B0E4[arg0[0x14]];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

extern s32 D_800A6540;
extern s32 D_800A6548;
extern s32 D_800A657C;
extern s32 D_800A6584;
extern s32 D_800A65B8;
extern s32 D_800A65C0;
extern s32 D_800A65F4;
extern s32 D_800A65FC;
extern s32 D_800A6630;
extern s32 D_800A663C;
extern f32 D_800A6674;
extern f32 D_800A6678;
extern f32 D_800A667C;
extern f32 D_800A6680;

s32 func_151600D8(u8 *arg0) {
    f32 *p;
    s32 i;

    i = 0;
    p = (f32 *)(arg0 + 0x18);
    p[0] = func_151422DC(i++, &D_800A6540, -2000, 2000, 0, &D_800A6548, 0x1C4) * D_800A6674;
    p[1] = func_151422DC(i++, &D_800A657C, -2000, 2000, 0, &D_800A6584, 0x1C9) * D_800A6678;
    p[2] = func_151422DC(i++, &D_800A65B8, 0, 2000, 500, &D_800A65C0, 0x1CE) * D_800A667C;
    p[3] = func_151422DC(i++, &D_800A65F4, 0, 2000, 500, &D_800A65FC, 0x1D3) * D_800A6680;
    ((s32 *)p)[4] = func_151422DC(i, &D_800A6630, 0, 0x10000, 0x10000, &D_800A663C, 0x1D9);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_15160274.s")
