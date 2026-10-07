#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void *allocate_memory(s32, s32, s32, s32);
extern f32 D_80098250;

struct func_15036C70_s {
    u8 pad[0x324];
    f32 *unk324;
};

void func_15036C70(struct func_15036C70_s *arg0) {
    s32 i;
    f32 v;

    arg0->unk324 = allocate_memory(0x48, 1, 0, 0);
    bzero(arg0->unk324, 0x48);
    v = D_80098250;
    for (i = 0; i < 3; i++) {
        arg0->unk324[i] = v;
        arg0->unk324[i + 3] = v;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15036CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15036F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15037698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15037880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_150379DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_150380C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15038468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15038620.s")

struct func_15039A54_s {
    u8 pad[0x18];
};
extern struct func_15039A54_s D_80098068[];

struct func_15039A54_s *func_15039A54(s32 arg0, s32 arg1) {
    return &D_80098068[arg1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15039A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15039CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15039ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503A08C.s")

struct func_1503A60C_s {
    u8 pad0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
};

void func_1503A60C(void) {
    struct func_1503A60C_s *tmp = (struct func_1503A60C_s *)((u8 *)gObjects[gCurrentObjectIndex].unk1D4 + 0x40);
    tmp->unk30 = *(f32 *)&gObjects[gCurrentObjectIndex].pad174;
    tmp->unk34 = gObjects[gCurrentObjectIndex].y_position;
    tmp->unk38 = *(f32 *)&gObjects[gCurrentObjectIndex].pad178;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503A678.s")

extern u8 D_800C3FFA;
void func_15036F34(void);
void func_1503A678(void);

void func_1503A7F0(void) {
    s32 tmp = D_800C3FFA;
    D_800C3FFA = 0;
    func_15036F34();
    D_800C3FFA = tmp;
    func_1503A678();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503A830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503B708.s")
