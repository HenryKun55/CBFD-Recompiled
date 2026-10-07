#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1503F4B0_s {
    u8 pad0[0x3E0];
    void *unk3E0[2];
    void *unk3E8[2];
    s32 unk3F0;
    u8 unk3F4;
    u8 pad3F5;
    u8 unk3F6;
};
void *allocate_memory(s32, s32, s32, s32);
void func_1502D824(struct func_1503F4B0_s *, s32, void *);
void func_150A81D0(void *, void *, struct func_1503F4B0_s *, s32, u8, s16 *, s32, s32);
void func_150A9984(void *, u8);
void func_1507BDB0(struct func_1503F4B0_s *, f32, s32, s32);
void func_10004074(void *);

void func_1503F4B0(struct func_1503F4B0_s *arg0) {
    void *sp44;
    s16 sp40[2];
    void *sp38[2];
    void *temp;

    sp44 = NULL;
    if (arg0->unk3E0[D_800BE9C0] != NULL) {
        sp44 = allocate_memory(0x320, 1, 2, 2);
        func_1502D824(arg0, 0, sp44);
        sp40[0] = 0x1000;
        temp = arg0->unk3E0[D_800BE9C0];
        sp38[0] = arg0->unk3E8[D_800BE9C0];
        func_150A81D0(sp38, temp, arg0, arg0->unk3F0, arg0->unk3F4, sp40, 0, 0);
        func_150A9984(arg0->unk3E8[D_800BE9C0], arg0->unk3F4);
        arg0->unk3F6 = 1;
    }
    func_1507BDB0(arg0, D_800BE9A4, 0, 0);
    if (sp44 != NULL) {
        func_10004074(sp44);
    }
}

void func_1505E0C4(s32, s32, void *, s32, s32, s32, s32, f32, f32, f32, f32, s32);

void func_1503F5B8(u8 *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    func_1505E0C4(0, 0, arg0, 0, arg1, arg2, arg0[0x3F5], arg3, arg4, 0.0f, 0.0f, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6C960/func_1503F62C.s")

void func_1503F7B8(u8 *arg0) {
    func_100043B4(*(void **)(arg0 + 0x3E8), 4);
    func_100043B4(*(void **)(arg0 + 0x3EC), 4);
    func_10004074(arg0);
}
