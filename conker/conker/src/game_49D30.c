#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501C880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CE54.s")

extern u16 *D_800C35D8[];
extern u8 D_800C363A[];

s32 func_1501CFF8(s32 arg0) {
    s32 sum = 0;
    s32 i;
    u16 *p;

    for (i = 0; i < D_800C363A[arg0]; i++) {
        sum += D_800C35D8[arg0][i];
    }
    return sum;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D1D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DE18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E1B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501EA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501EC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501F72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501FC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501FE68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501FFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15020388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15020878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15020EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1502178C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15021DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022024.s")

extern s16 D_800C358C[3];
extern f32 D_800C3594;

void func_15022190(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    D_800C3594 = arg3;
    D_800C358C[0] = arg0;
    D_800C358C[1] = arg1;
    D_800C358C[2] = arg2;
    D_800C3663 = 1;
}

extern s16 D_800C3598[];
extern f32 D_800C35A0;

void func_150221E8(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    D_800C35A0 = arg3;
    D_800C3598[0] = arg0;
    D_800C3598[1] = arg1;
    D_800C3598[2] = arg2;
}

extern u8 D_800C3510[];

void func_15022234(s32 arg0) {
    D_800C3510[arg0] = 0;
}

extern u8 D_800C354A[];

void func_15022248(s32 arg0) {
    D_800C354A[arg0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1502225C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150222E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150226BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150227BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150228E4.s")

void func_15022998(s32 *arg0) {
    s32 tmp = *arg0;
    if (tmp == 27 || tmp == 4) {
        if (D_80086014[tmp] != NULL) {
            D_80086014[tmp](arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150229E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15023264.s")

void func_150233BC(void) {
    bzero(D_800C3CA0, sizeof(D_800C3CA0));
}

extern void *func_1516D2E0();
extern struct163 D_800C3D48[];

void func_150233E4(void) {
    struct163 *var_s0;
    struct163 *end;

    var_s0 = D_800C3CA0; end = D_800C3D48;
    do {
        if (*(s16 *)var_s0 != 0) {
            func_1516D2E0(*(void **)((u8 *)var_s0 + 0x34));
            *(void **)((u8 *)var_s0 + 0x34) = 0;
            *(s16 *)var_s0 = 0;
        }
        var_s0++;
    } while (var_s0 != end);
}

struct func_15023440_s {
    s16 unk0;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x27];
    void *unk34;
};

void func_15023440(struct func_15023440_s *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_1516D2E0(arg0->unk34);
        arg0->unk34 = NULL;
    } else if (arg0->unkC != 0) {
        func_1516D328(arg0->unk34);
    } else {
        arg0->unk34 = NULL;
    }
    arg0->unk0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150234A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150235DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1502378C.s")
