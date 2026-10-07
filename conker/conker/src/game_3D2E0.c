#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1500FE30_s {
    s8 unk0;
    s8 pad1;
    s8 unk2;
    s8 pad3;
    u16 unk4;
    s16 unk6;
    s16 unk8;
};
void *allocate_memory(s32, s32, s32, s32);
void func_150C851C(s32);

void func_1500FE30(void) {
    s32 i;

    D_800BE4E0 = (s32) allocate_memory(100, 1, 0, 0);
    bzero((void *) D_800BE4E0, 100);
    for (i = 0; i < 10; i++) {
        ((struct func_1500FE30_s *) D_800BE4E0)[i].unk0 = i / 5;
        ((struct func_1500FE30_s *) D_800BE4E0)[i].unk2 = -1;
        ((struct func_1500FE30_s *) D_800BE4E0)[i].unk4 = func_150ADA20() % 5U;
    }
    func_150C851C(100);
    for (i = 0; i < 10; i++) {
        ((struct func_1500FE30_s *) D_800BE4E0)[i].unk6 = ((struct func_1500FE30_s *) D_800BE4E0)[i].unk8;
    }
}

void *func_1510C4AC();
extern s32 D_800917B8;

void func_1500FF9C(void) {
    func_1510C4AC(D_800917B8, 0, 0xAD, 0x75);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_3D2E0/func_1500FFCC.s")
