#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_151732E0_s {
    u16 unk0;
    u16 unk2;
    u8 pad4[0x36];
    s16 unk3A;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    u8 unk42;
    u8 unk43;
    u8 unk44;
    u8 unk45;
    s8 unk46;
};
struct func_151732E0_d {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
};
extern struct func_151732E0_d D_8008CC70;
extern s8 D_800DD2E0;
void func_151733E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_151732E0(s32 arg0) {
    s32 a = 0;
    s32 b = 0;

    if (((struct func_151732E0_s *)D_800B0DF0)->unk3C == ((struct func_151732E0_s *)D_800B0DF0)->unk40 && ((struct func_151732E0_s *)D_800B0DF0)->unk3C == 0) {
        ((struct func_151732E0_s *)D_800B0DF0)->unk40 = 100;
    }
    D_8008CC70.unk0 = ((struct func_151732E0_s *)D_800B0DF0)->unk42;
    D_8008CC70.unk1 = ((struct func_151732E0_s *)D_800B0DF0)->unk43;
    D_8008CC70.unk2 = ((struct func_151732E0_s *)D_800B0DF0)->unk44;
    D_8008CC70.unk3 = ((struct func_151732E0_s *)D_800B0DF0)->unk45;
    D_8008CC70.unk4 = ((struct func_151732E0_s *)D_800B0DF0)->unk3A;
    D_8008CC70.unk6 = ((struct func_151732E0_s *)D_800B0DF0)->unk3C;
    D_8008CC70.unk8 = ((struct func_151732E0_s *)D_800B0DF0)->unk3E;
    D_8008CC70.unkA = ((struct func_151732E0_s *)D_800B0DF0)->unk40;
    D_8008CC70.unkC = ((struct func_151732E0_s *)D_800B0DF0)->unk2;
    D_8008CC70.unkE = ((struct func_151732E0_s *)D_800B0DF0)->unk0;
    if (((struct func_151732E0_s *)D_800B0DF0)->unk46 != -1) {
        D_800DD2E0 = 1;
        a = b = ((struct func_151732E0_s *)D_800B0DF0)->unk46;
        func_151733E4(a, b, arg0, 0, -1);
    } else {
        D_800DD2E0 = 0;
        func_151733E4(a, b, arg0, 0, -1);
    }
}

s32 func_151733D8(s32 arg0, void *arg1) {
    if (1) {
        return arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0790/func_151733E4.s")

struct func_151738C4_s {
    u8 r;
    u8 g;
    u8 b;
};
extern struct func_151738C4_s D_800DBEA8;
extern struct func_151738C4_s D_800DD2E4;
void func_151733E4(s32, s32, s32, s32, s32);

void func_151738C4(s32 arg0) {
    if ((s8)D_800B0DF0->unk46 == -1) {
        if (D_800DBFF0->unk5F0 & 1) {
            func_151733E4(6, 6, arg0, 0, -1);
            D_800DBEA8.r = D_800DD2E4.r;
            D_800DBEA8.g = D_800DD2E4.g;
            D_800DBEA8.b = D_800DD2E4.b;
        } else {
            func_151733E4(0, 0, arg0, 0, -1);
            D_800DBEA8.r = D_800B0DF0->unk5;
            D_800DBEA8.g = D_800B0DF0->unk6;
            D_800DBEA8.b = D_800B0DF0->unk7;
        }
    }
}

s32 func_15173994(s32 arg0) {
    return (s8)D_800B0DF0->unk46;
}
