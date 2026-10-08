#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15016850_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x2B];
};

extern u8 D_800BE590;
extern u16 D_800BE598[];
extern s32 D_800BE5A8[];
extern u8 D_800D2100;

void func_15016850(void) {
    s32 i;
    s32 j;
    s32 found;
    s32 sp50;
    s32 id;

    D_800BE590 = 0;
    sp50 = 0;
    for (i = 0; i < D_800D2100; i++) {
        id = ((struct func_15016850_s *)D_800D20FC)[i].unk4;
        found = 0;
        for (j = 0; j < D_800BE590; j++) {
            if (id == D_800BE598[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            continue;
        }
        if (id < 0xBB) {
            func_1502B7F0(&sp50, 2, 0x12, id);
        }
        if (sp50 != 0) {
            D_800BE5A8[D_800BE590] = sp50;
            D_800BE598[D_800BE590] = id;
            D_800BE590++;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_43D00/func_150169A0.s")

extern u8 D_800D2101;
void *allocate_memory(s32, s32, s32, s32);

struct func_15017114_s {
    s32 unk0;
    s32 unk4;
};

void func_15017114(s32 arg0) {
    s32 n;
    struct func_15017114_s *sp40;
    s32 i;

    sp40 = NULL;
    n = D_800D2100;
    D_800D2104 = allocate_memory(n * sizeof(s32 *), 1, 0, 0);
    *(u8 **)D_800D2108 = allocate_memory(n * sizeof(u8), 1, 0, 0);
    bzero(D_800D2104, n * sizeof(s32 *));
    bzero(*(u8 **)D_800D2108, n * sizeof(u8));
    for (i = 0; i < D_8008FD8C; i++) {
        D_800D2104[i] = (s32)allocate_memory(0x10, 1, 2, 0);
        bzero(D_800D2104[i], 0x10);
        (*(u8 **)D_800D2108)[i] = 2;
    }
    if (func_1502B7F0(&sp40, 2, 0x10, arg0) != 0) {
        for (i = D_800D2101; i < D_800D2100; i++) {
            if (sp40[i - D_800D2101].unk0 != 0) {
                (*(u8 **)D_800D2108)[i] = sp40[i - D_800D2101].unk4;
                D_800D2104[i] = sp40[i - D_800D2101].unk0 + (s32)sp40;
            }
        }
    }
}
