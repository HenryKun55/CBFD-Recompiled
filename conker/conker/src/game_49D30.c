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

extern s32 D_800C3640[];
extern u16 *D_800C35D8[];
extern u16 *D_800C35C8[];
extern u16 *D_800C35D0[];
extern u8 *D_800C3688[][30];
extern u8 *D_800C3778[][30];

struct func_1501CE54_s {
    u8 pad0[0x6];
    s16 unk6;
    u8 pad8[0x2];
    s16 unkA;
    u8 padC[0x6];
    s16 unk12;
};

void func_1501CE54(s32 arg0) {
    s32 found;
    s32 i;
    u16 *p;
    s32 idx;
    s32 v;

    D_800C3640[arg0] = 0;
    if (D_800C363A[arg0] == 0) {
        return;
    }
    p = D_800C35D8[arg0];
    if (p[0] >= 4) {
        v = ((struct func_1501CE54_s *)D_800C3688[arg0][0])->unk12;
        if (v != -9999) {
            D_800C3640[arg0] = v;
            return;
        }
    }
    found = 0;
    for (i = 0; i < D_800C363A[arg0]; i++) {
        if (D_800C35C8[arg0][i] != 0 && p[i] != 0) {
            if (D_800C3640[arg0] < ((struct func_1501CE54_s *)D_800C3688[arg0][i])->unkA) {
                D_800C3640[arg0] = ((struct func_1501CE54_s *)D_800C3688[arg0][i])->unkA;
                found = 1;
            }
        }
    }
    if (!found) {
        for (i = 0; i < D_800C363A[arg0]; i++) {
            if (D_800C35C8[arg0][i] != 0) {
                idx = D_800C35D0[arg0][i];
                if (idx != 0) {
                    v = *(s16 *)(D_800C3778[arg0][i] + idx * 8 - 2);
                    if (D_800C3640[arg0] < v) {
                        D_800C3640[arg0] = v;
                    }
                }
            }
        }
    }
}

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

extern s8 D_8008FD84;
extern u8 D_800C35E8[];
extern u8 D_800C3C9C;
extern u8 D_800D2E40;
extern u8 D_800C3C99;
extern s32 D_800C35B0[];
extern s32 D_800C3640[];

s32 func_1501E05C(s32 arg0) {
    if (D_800BE9F0 == 0x1D) {
        if (D_8008FD84) {
            D_8008FD84 = 0;
            return 1;
        }
        if (D_800C35E8[0] != 5) {
            return 0;
        }
    }
    if (D_800BE9F0 == 0x21) {
        if ((D_800BE710[0] & 0x1000) && D_8000030C == 1 && D_800C35B0[0] >= 0x12D) {
            return 1;
        }
        return 0;
    }
    if ((D_800BE710[0] & 0x20) && !D_800C3C9C) {
        if (D_800D2E40) {
            return 1;
        }
        if (func_1501D2C4(D_800BE9F0, D_800C35E8[arg0]) && (D_800C3C99 || D_800C35B0[arg0] + 30 < D_800C3640[arg0])) {
            return 1;
        }
    }
    return 0;
}

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

extern u8 D_800C3A58;
extern s32 D_800C35B8[];
extern u8 D_800C35C0[];
extern u16 D_800C3C8E;
void func_1501E1B4(void);
s32 func_151F2CDC(void);
void func_15080228(void);

void func_1501E400(s32 arg0) {
    if (D_800C3A58 != 0) {
        D_800C3A58--;
    }
    D_800C35B8[arg0] = D_800C35B0[arg0];
    if ((&D_800C35EA)[arg0] == 1) {
        func_1501E1B4();
        if (arg0 != 0 || D_800BEAC0 == 0) {
            D_800C35B0[arg0] += D_800BEA08;
        }
        if (D_800C35C0[arg0] == 0 && D_800C3C8E == D_800C35B8[arg0] && D_800C3C8E != D_800C35B0[arg0]) {
            D_800C35B8[arg0] = -1;
        }
        if (func_151F2CDC() == 1) {
            func_15080228();
        }
        if (D_800C35B0[arg0] >= D_800C3640[arg0]) {
            D_800C35B0[arg0] = D_800C3640[arg0];
        }
    }
}

struct func_1501E540_s { s32 unk0; void *unk4; u8 pad8[0x30]; void *unk38; s32 unk3C; };
struct func_1501FE68_s;
extern struct func_1501FE68_s *D_800C3A50[];
extern u16 *D_800C35C8[];
extern u16 *D_800C35D0[];
extern u16 *D_800C35D8[];
extern void *D_800C35E0[];
extern void *D_800C3D50;
extern void *D_800C3668[];

void func_1501E540(s32 arg0) {
    void **sp3C;
    u16 *count;
    s32 i;

    sp3C = &D_800C3668[arg0];
    if (*sp3C != NULL) {
        count = *(u16 **)*sp3C;
        for (i = 0; i < *count; i++) {
            if (D_800C35C8[arg0][i] != 0) {
                func_10004074(((struct func_1501E540_s *)D_800C3A50[arg0])[i].unk4);
                func_10004074(((struct func_1501E540_s *)D_800C3A50[arg0])[i].unk38);
            }
        }
        func_10004074(D_800C3A50[arg0]);
        D_800C3A50[arg0] = NULL;
        func_10004074((&D_800C3958)[arg0]);
        (&D_800C3958)[arg0] = NULL;
        for (i = 0; i < *count; i++) {
            func_10004074(D_800C3960[arg0][i]);
            D_800C3960[arg0][i] = NULL;
        }
        func_10004074(D_800C35C8[arg0]);
        func_10004074(D_800C35D0[arg0]);
        func_10004074(D_800C35D8[arg0]);
        func_10004074(D_800C35E0[arg0]);
        D_800C35C8[arg0] = NULL;
        D_800C35D0[arg0] = NULL;
        D_800C35D8[arg0] = NULL;
        D_800C35E0[arg0] = NULL;
        func_10004074(D_800C3D50);
        D_800C3D50 = NULL;
        func_10004074(*sp3C);
        *sp3C = NULL;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501EA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501EC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501F72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501FC8C.s")

extern u16 *D_800C35C8[];
struct func_1501FE68_s { f32 unk0; u8 pad[0x3C]; };
extern struct func_1501FE68_s *D_800C3A50[];
extern u8 *D_800C3868[][30];
extern f32 D_800969D8;
extern f32 D_800969DC;
void func_1501F72C(s32, f32, f32 *, s32, s32 *);
void func_1501FFE8(f32 *, u8 *, s32, s32);

void func_1501FE68(s32 arg0, f32 arg1, f32 *arg2, s32 arg3) {
    f32 x;
    f32 sp6C[6];
    f32 y;
    f32 t;
    s32 sp60;
    f32 sp30[12];

    if (D_800C35C8[arg3][arg0] >= 2) {
        if (arg1 > 100.0f) {
            arg1 = 100.0f;
        }
        if (arg1 < 0.0f) {
            arg1 = 0.0f;
        }
        t = D_800C3A50[arg3][arg0].unk0 * arg1 * D_800969D8;
        func_1501F72C(arg0, t, sp6C, arg3, &sp60);
        if (*(u16 *)(D_800C3868[arg3][arg0] + sp60 * 8 + 6) == 0) {
            x = sp6C[0] - sp6C[3];
            y = sp6C[2] - sp6C[5];
        } else {
            func_1501FFE8(sp30, D_800C3868[arg3][arg0], sp60, D_800C35C8[arg3][arg0]);
            x = sp30[6] - sp30[3];
            y = sp30[8] - sp30[5];
        }
        *arg2 = func_150484A0(x, y) * D_800969DC;
    }
}

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

struct func_15022398_s {
    u16 unk0;
    u8 unk2;
    u8 unk3[5];
};

struct func_15022398_d {
    u8 unk0[0x30];
};

struct func_15022B08_s;
extern u16 *D_800C35C8[];
extern struct func_15022B08_s *D_800C35F0[];
extern u8 D_800D2100;
extern struct127 *func_1505EEF4(s32);
extern void func_15082A44(struct258 *, s32, s32, s32, s32);

void func_15022398(s32 arg0, s32 arg1) {
    struct127 *obj;
    s32 id;
    s32 type;

    if (D_800C35C8[arg1][arg0] != 0) {
        if (((struct func_15022398_s *)D_800C35F0[arg1])[arg0].unk0 == 2) {
            type = ((struct func_15022398_s *)D_800C35F0[arg1])[arg0].unk2;
            id = func_15083E0C((u8)type);
            if (id != -1) {
                obj = func_1505EEF4(id);
                if (obj != NULL) {
                    if (obj->unk5 == 3) {
                        if (D_800C35F0 != &D_800C35F0[arg1]) {
                            obj->unk5 = 4;
                        } else {
                            obj->unk5 = 0;
                        }
                    }
                    if (type == 1) {
                        obj->unkF4 &= ~0x2A;
                    }
                } else if (id < D_800D2100) {
                    func_15082A44((struct258 *)(id + (struct func_15022398_d *)D_800D20FC), id, 0, arg1, 0);
                    obj = func_1505EEF4(id);
                    if (obj != NULL) {
                        func_1505E650(obj, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1);
                        func_1502225C(obj - gObjects, arg1);
                    }
                }
            }
        }
    }
}

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

struct func_15023264_s {
    u16 unk0;
    u8 unk2[6];
};

extern u8 D_800C363A[];
extern u8 *D_800C3688[][30];
s32 func_15023BB0(u32 arg0, s32 arg1, s32 arg2, void **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10);

s32 func_15023264(s32 arg0, s32 arg1) {
    s32 i;
    s32 best;
    s32 result;
    s32 d;
    s16 *sp6C;
    s32 pad[2];

    result = -1;
    best = 99999;
    for (i = 0; i < D_800C363A[arg0]; i++) {
        if (D_800C3688[arg0][i] != NULL) {
            sp6C = NULL;
            d = func_15023BB0((u32)(D_800C3688[arg0][i] + 0x18), 3, i, (void **)&sp6C, 0, 0, 0, 0, 0, 0, arg0);
            if (sp6C != NULL && d < best) {
                best = d;
                result = sp6C[1];
            }
        }
    }
    if (result == -1) {
        result = 0;
        for (i = 0; i < D_800C363A[arg0]; i++) {
            if (((struct func_15023264_s *)D_800C35F0[arg0])[i].unk0 == 1) {
                result = i;
                break;
            }
        }
    }
    return result;
}

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

struct func_15023440_s *func_150234A4(s32 arg0, s32 arg1) {
    s32 i;
    struct func_15023440_s *found;
    struct func_15023440_s *empty;
    arg0++;
    found = NULL;
    empty = NULL;
    for (i = 0; i < 3; i++) {
        if (arg0 == ((struct func_15023440_s *)D_800C3CA0 + i)->unk0) {
            if (arg1 && ((struct func_15023440_s *)D_800C3CA0 + i)->unkC) {
                empty = (struct func_15023440_s *)D_800C3CA0;
                func_15023440(empty, 1);
            } else {
                found = ((struct func_15023440_s *)D_800C3CA0 + i);
            }
            break;
        }
        if (((struct func_15023440_s *)D_800C3CA0 + i)->unk0 == 0) {
            empty = ((struct func_15023440_s *)D_800C3CA0 + i);
            if (arg1 && ((struct func_15023440_s *)D_800C3CA0 + i)->unkC) {
                func_15023440(((struct func_15023440_s *)D_800C3CA0 + i), 1);
            }
            break;
        }
    }
    if (i == 3) {
        empty = (struct func_15023440_s *)D_800C3CA0;
        func_15023440(empty, 1);
    }
    if (found) {
        return found;
    }
    if (empty) {
        empty->unk0 = arg0;
    }
    return empty;
}

void func_1507F640(void);
void func_1508F060(void);
extern f32 D_80096A1C;
extern u8 D_800C35AA;

void func_150235DC(s32 arg0) {
    struct127 *obj;

    gObjects[0].unk25C &= ~0x200;
    if (D_800C35AA == 0) {
        obj = func_15083E90(1);
        if (obj != NULL) {
            gCurrentObjectIndex = obj - gObjects;
            obj->xz_velocity = 0.0f;
            if (obj->unk31C != NULL) {
                *(f32 *)obj->unk31C = 0.0f;
            }
            *(f32 *)&obj->pad54 = 0.0f;
            obj->unkCC = 0;
            obj->unkD0 = 0;
            if ((D_80096A1C != obj->unk118) && (obj->y_position < obj->unk118)) {
                obj->in_water = 1;
                obj->y_velocity = 0.0f;
                obj->gravity = 0.0f;
                if (((obj->unk118 - 50.0f) < obj->unk1A6) || (obj->unk31C->pad17[9] & 1)) {
                    obj->unkB2 = 0;
                    func_1508F060();
                }
            } else {
                obj->in_water = 0;
                obj->unkB2 = 0;
                obj->y_velocity = -4.0f;
                obj->unk1CC = obj->y_position = obj->unk180;
                obj->gravity = 5.0f;
            }
            obj->unk81 = 0;
            obj->unk83 = 0;
            obj->disable_run = 0;
            obj->disable_jump = 0;
            obj->stunned = 0;
            obj->unk28 = obj->y_position - obj->unk180;
            gCurrentObject = obj;
            func_1507F640();
            obj->unk31C->pad17[0xC] = 0;
            *(volatile s8 *)&obj->unk287 = 0;
            obj->unk276 = 0;
            obj->unk282 = 0;
            obj->unk278 = 0;
            *(s8 *)&obj->unk284 = *(s8 *)&obj->unk285 = *(s8 *)&obj->unk286 = *(s8 *)&obj->unk287;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1502378C.s")
