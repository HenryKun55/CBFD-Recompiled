#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1517B500_s {
    s16 x;
    s16 y;
    s16 z;
    s16 pad6;
    u8 unk8;
    u8 pad9[4];
    s8 unkD;
};

extern u8 D_80095CE1[];
s32 func_151EF610(void);

s32 func_1517B500(struct func_1517B500_s *arg0, s16 *arg1, s32 *arg2, s32 arg3) {
    s32 diff;
    s32 pad;
    s32 r;
    s32 r2;

    *arg2 = (*arg2 * 3) / 2;
    if (*arg2 >= (D_80095CE1[arg0->unk8 * 10] << 8)) {
        *arg2 -= D_80095CE1[arg0->unk8 * 10] << 8;
    }
    arg1[0] = arg0->x;
    arg1[1] = arg0->y;
    arg1[2] = arg0->z;
    diff = 0x29 - arg0->unkD;
    if (diff == 0) {
        arg0->unkD = arg0->unkD - (func_151EF610() % 8) + 4;
    } else if (diff < 0) {
        r = func_151EF610();
        arg0->unkD = arg0->unkD - ((func_151EF610() % -diff) >> 1) - (r % 8) + 4;
    } else {
        r = func_151EF610();
        r2 = (func_151EF610() % diff) >> 1;
        arg0->unkD = arg0->unkD + r2 + (r % 8) - 4;
    }
    arg1[0] = arg0->x;
    arg1[1] = arg0->y;
    arg1[2] = arg0->z;
    return 0;
}

s32 func_1517B6E8(s16 *arg0, s16 *arg1, s32 *arg2, u8 *arg3) {
    s32 temp;

    if (*arg2 >= 0x600) {
        arg1[1] = arg0[1] + (*arg2 >> 6) - 0x18;
        arg1[0] = arg0[0] + (*arg2 >> 8) - 6;
        temp = ((*arg3 << 7) / ((*arg2 >> 6) - 0x17)) >> 4;
        if (temp < *arg3) {
            *arg3 = temp;
        }
        *arg2 = 0x600;
    } else {
        arg1[0] = arg0[0];
        arg1[1] = arg0[1];
    }
    arg1[2] = arg0[2];
    return 0;
}

s32 func_1517B7A8(s16 *arg0, s16 *arg1, s32 *arg2, s32 arg3) {
    if (*arg2 >= 0x300) {
        if (*arg2 > 0x500) {
            *arg2 -= 0x200;
        } else {
            *arg2 = 0x300;
        }
    }
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
    return 0;
}

s32 func_1517B7F8(s16 *arg0, s16 *arg1, s32 *arg2, s32 arg3) {
    u32 t;
    if (*arg2 >= 0xD00) {
        return 1;
    }
    if (*arg2 >= 0x100) {
        t = *arg2 - 0x600;
        t = 0x190000 - t * t;
        arg1[1] = arg0[1] + (s32)t / 0x1E00;
        if (*arg2 >= 0x200) {
            if (*arg2 > 0xA00) {
                *arg2 -= 0x800;
            } else {
                *arg2 = 0x200;
            }
        }
    } else {
        arg1[1] = arg0[1];
    }
    arg1[0] = arg0[0];
    arg1[2] = arg0[2];
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517BBAC.s")

struct func_1517CFC4_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_10006240(s32, s32, u32);
void func_10004074(s32);

void func_1517CFC4(void) {
    s32 i;
    struct func_1517CFC4_s *p;

    for (i = 0, p = (struct func_1517CFC4_s *)&D_800DDA90; i != 15; i++, p++) {
        if (p->unk8 != 0) {
            if ((&D_800DD478)[i * 26] != 0) {
                func_10006240(p->unk8, (&D_800DD478)[i * 26], D_8003809C);
                func_10004074(p->unk8);
            }
            p->unk8 = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D074.s")

struct func_1517D578_s {
    s16 x;
    s16 y;
    s16 z;
    u8 unk6;
    s16 unk8;
    s16 unkA;
    f32 unkC;
};
extern struct func_1517D578_s D_800DDD28[];

void func_1517D578(s16 arg0, s16 arg1, s16 arg2, f32 arg3, s32 arg4, s32 arg5, u8 arg6) {
    s32 n;
    struct func_1517D578_s *temp_v1;

    n = D_8008CEB0;
    if (n < 3) {
        temp_v1 = &D_800DDD28[n];
        temp_v1->x = arg0;
        temp_v1->y = arg1;
        temp_v1->z = arg2;
        temp_v1->unkC = arg3;
        temp_v1->unk8 = arg4;
        temp_v1->unkA = arg5;
        temp_v1->unk6 = arg6;
        D_8008CEB0 = n + 1;
    }
}

void func_1517D5FC(s16 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_1517D578(arg0, arg1, arg2, D_800DBFF0[arg3].unk380, arg4, arg5, D_800DDD1C >> 3);
}

extern s32 D_800DDD58;

struct func_1517D690_s {
    s16 x;
    s16 y;
    s16 z;
    u8 unk6;
    u16 unk8;
    u16 unkA;
    f32 unkC;
};

void *func_1517D074(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, u16 *arg9);

void *func_1517D690(void *arg0, u16 *arg1) {
    s32 sp4C;

    sp4C = D_800DDD58;
    D_800DDD1C += 5;
    if (D_800DDD1C >= 200) {
        D_800DDD1C -= 200;
    }
    while (D_8008CEB0 != 0) {
        D_8008CEB0--;
        if (arg1 != 0) {
            arg0 = func_1517D074(arg0,
                ((struct func_1517D690_s *)D_800DDD28)[D_8008CEB0].x,
                ((struct func_1517D690_s *)D_800DDD28)[D_8008CEB0].y,
                ((struct func_1517D690_s *)D_800DDD28)[D_8008CEB0].z,
                ((struct func_1517D690_s *)D_800DDD28)[D_8008CEB0].unkC,
                ((struct func_1517D690_s *)D_800DDD28)[D_8008CEB0].unk8,
                ((struct func_1517D690_s *)D_800DDD28)[D_8008CEB0].unkA,
                0x10, 0x20,
                arg1 + ((struct func_1517D690_s *)D_800DDD28)[D_8008CEB0].unk6 * 0x280);
        }
    }
    D_800DDD58 = sp4C;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D7B0.s")

struct func_1517DE5C_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 padD[3];
};
extern struct func_1517DE5C_s D_800DDB80[];
void func_1517BBAC(s32, s32, s32, s32, f32, s32, s32, s32);

void func_1517DE5C(void) {
    struct func_1517DE5C_s *p;
    s32 i;

    if (D_800DDD20 != 0) {
        p = D_800DDB80 - 15;
        do {
            p->unkC = 0;
            p++;
        } while (p < D_800DDB80);
        func_1517BBAC(gObjects[0].x_position, gObjects[0].y_position, gObjects[0].z_position, 0x5DC,
                      D_800DBFF0->unk380, D_800DBFF0->unk2F8, D_800DBFF0->unk2FC, D_800DBFF0->unk300);
        for (i = 0; i < 15; i++) {
            if ((&D_800DD478)[i * 26] != 0 && ((struct func_1517DE5C_s *)&D_800DDA90)[i].unkC == 0) {
                (&D_800DD478)[i * 26] = 0;
                ((struct func_1517DE5C_s *)&D_800DDA90)[i].unk8 = 0;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517E05C.s")
