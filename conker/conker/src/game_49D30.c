#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501C880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CC3C.s")

extern u8 D_800C363A[];
extern u8 *D_800C3960[][30];

void func_1501CDC0(s32 arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < D_800C363A[arg0]; i++) {
        for (j = 0; j < 16; j++) {
            D_800C3960[arg0][i][j] = 0xFF;
        }
    }
}

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

extern void *D_800C3668[];
void *func_1502B6BC();

void *func_1501D1D4(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp34;
    s32 sp30;
    void *temp_v0;

    temp_v0 = func_1502B6BC(&sp30, 0, &sp34, 3, 6, arg0, arg1);
    if (temp_v0 != NULL) {
        D_800C3668[arg2] = temp_v0;
    } else {
        D_800C3668[arg2] = NULL;
    }
    return temp_v0;
}

void func_1501D258(s32 arg0, s32 arg1) {
    if (D_800C3670 == 0) {
        D_800C3A60[arg0] |= (s64)1 << arg1;
    }
}

s32 func_1501D2C4(s32 arg0, s32 arg1) {
    if (D_800C3670 != 0) {
        return 1;
    }
    if (D_800C3A60[arg0] & (1LL << arg1)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DAAC.s")

extern s32 D_800C3640[];
extern s32 D_800C35B0[];
s32 func_150229E4(struct127 *);
void func_1502178C(struct127 *, s32, s32);
void func_1501E81C(s32, s32);
void func_150242F8(s32, s32);
void func_1501EC38(s32);
void func_15020EC4(s32);

void func_1501DE18(s32 arg0) {
    s32 i;
    struct127 *obj;
    D_800C35B0[arg0] = D_800C3640[arg0] + D_800BEA08;
    func_150242F8(1, 0);
    func_1501EC38(0);
    func_150242F8(0, 0);
    func_15020EC4(0);
    for (i = 0, obj = gObjects; i < 25; i++, obj++) {
        if (obj->interaction_state == 0) continue;
        gCurrentObjectIndex = i;
        if (func_150229E4(obj) == 0) continue;
        func_1502178C(obj, arg0, -1);
    }
    func_1501E81C(1, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E1B4.s")

extern u8 D_800C3C8C;
extern s32 D_800C35B0[];
extern s32 D_800C3640[];
void func_1501E81C(s32, s32);
void func_1501E400(s32);
void func_150242F8(s32, s32);
void func_1501EC38(s32);
void func_15020EC4(s32);

void func_1501E2F8(s32 arg0) {
    if ((&D_800C35EA)[arg0] == 1) {
        if (D_800C35B0[arg0] >= D_800C3640[arg0]) {
            if (D_800C3C8C == 0) {
                func_1501E81C(0, arg0);
                if ((&D_800C35EA)[arg0] == 1) {
                    func_1501E400(0);
                    func_150242F8(1, 0);
                    func_1501EC38(0);
                    func_150242F8(0, 0);
                    func_15020EC4(0);
                    func_1501E2F8(0);
                }
            } else {
                D_800C3C8C = 2;
            }
        }
    }
}

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

extern u8 D_800C3518[][25];

void func_1502225C(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < D_800C3510[arg1]; i++) {
        if (arg0 == D_800C3518[arg1][i]) {
            return;
        }
    }
    D_800C3518[arg1][D_800C3510[arg1]] = arg0;
    D_800C3510[arg1]++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150222E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022528.s")

extern u8 D_800C3550[][30];

void func_15022640(s32 arg0, s32 arg1) {
    s32 i = 0;
    u8 *count = &D_800C354A[arg1];
    s32 n = *count;
    s32 m = n;
    for (; i < m; i++) {
        if (arg0 == D_800C3550[arg1][i]) {
            return;
        }
    }
    D_800C3550[arg1][n] = arg0;
    *count = n + 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150226BC.s")

extern u8 D_800C363A[];

void func_15022754(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800C363A[arg0]; i++) {
        func_150226BC(i, arg0);
    }
}

extern u8 D_800C354A[];
extern u8 D_800C3550[][30];
void *func_151149AC();

void func_150227BC(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800C354A[arg0]; i++) {
        *((u8 *)func_151149AC(D_800C3550[arg0][i]) + 0x6E) = 1;
    }
}

void func_15022398(s32, s32);
void func_150222E0(s32, s32);

void func_15022848(s32 arg0) {
    s32 i;

    if ((&D_800C35EA)[arg0] == 1) {
        D_800C3638 = 0;
        for (i = 0; i < D_800C363A[arg0]; i++) {
            func_15022398(i, arg0);
            func_150222E0(i, arg0);
        }
        D_800C3638 = 1;
    }
}

void func_150228E4(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800C3510[arg0]; i++) {
        if (gObjects[D_800C3518[arg0][i]].interaction_state != 0) {
            func_15060F28(&gObjects[D_800C3518[arg0][i]], 0);
        }
    }
}

void func_15022998(s32 *arg0) {
    s32 tmp = *arg0;
    if (tmp == 27 || tmp == 4) {
        if (D_80086014[tmp] != NULL) {
            D_80086014[tmp](arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150229E4.s")

struct func_15022B08_s {
    u8 unk0[2];
    u8 unk2;
    u8 unk3[5];
};

extern u16 *D_800C35C8[];
extern struct func_15022B08_s *D_800C35F0[];
extern u8 D_800C363A[];

s32 func_15022B08(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < D_800C363A[arg1]; i++) {
        if (D_800C35C8[arg1][i] != 0) {
            if (D_800C35F0[arg1][i].unk2 == D_800DBEF4[arg0].pad70[2]) {
                return 1;
            }
        }
    }
    return 0;
}

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
