#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1509CA10_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};
extern struct func_1509CA10_s D_80087430[];

s32 func_1509CA10(s32 arg0) {
    return D_80087430[arg0].unk0;
}

struct func_1509CA30_s {
    u16 unk0;
    u8 pad2[0x12];
};
extern struct func_1509CA30_s D_80087438[];

u16 func_1509CA30(s32 arg0) {
    return D_80087438[arg0].unk0;
}

struct func_1509CA50_s {
    u16 unk0_hi : 4;
    u16 unk0 : 12;
    u8 pad2[0x12];
};
extern struct func_1509CA50_s D_8008743A[];

s32 func_1509CA50(s32 arg0) {
    return D_8008743A[arg0].unk0;
}

struct func_1509CA78_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};
extern struct func_1509CA78_s D_80087434[];

s32 func_1509CA78(s32 arg0) {
    return D_80087434[arg0].unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CA98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CBD4.s")

void func_1509CC94(void) {
    func_1509CCB4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CCB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CCF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CE64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CF28.s")

extern void *D_800D2FB0;
void func_10004074(void *);

void func_1509D054(void) {
    void *temp;

    if (D_800D2FB0 != NULL) {
        temp = D_800D2FB0;
        func_10004074(temp);
        D_800D2FB0 = NULL;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509DBBC.s")
