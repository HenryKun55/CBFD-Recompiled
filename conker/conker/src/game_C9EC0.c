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

s32 func_1509CA98(s32 arg0) {
    s32 i = 0;

    while (i < 204) {
        if (D_80087430[i].unk0 != 0 && arg0 == (D_80087430[i].unk4 & 0x1FFFFFFF) + 1) {
            return i;
        }
        i++;
    }
    return 204;
}

s32 func_1509CB68(void) {
    s32 i;
    s32 count = 0;

    for (i = 0; i < 204; i++) {
        if (D_80087430[i].unk0 != 0) {
            count++;
        }
    }
    return count;
}

struct func_1509CBD4_s {
    u16 *unk0;
    u8 pad4[0x10];
};
extern struct func_1509CBD4_s D_8008743C[];

s32 func_1509CBD4(s32 arg0) {
    u16 *p = D_8008743C[arg0].unk0;
    s32 i;
    s32 v;

    for (i = 0; p[i] != 0xFFFF; i++) {
        v = func_1509CBD4(p[i]);
        if (!(((u8 *) D_800D2E4C)[p[i] >> 3] & (1 << (p[i] & 7))) || !v) {
            return 0;
        }
    }
    return 1;
}

void func_1509CC94(void) {
    func_1509CCB4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CCB4.s")

struct func_1509CCF4_s {
    u16 *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};
extern struct func_1509CCF4_s D_80087440[];

s32 func_1509CCF4(s32 arg0) {
    u16 *list = D_80087440[arg0].unk0;
    s32 count = 0;

    while (*list != 0xFFFF) {
        ((u8 *)D_800D2E4C)[*list >> 3] |= 1 << (*list & 7);
        if ((*(u8 (*)[])&D_800D2E70)[*list] != 3) {
            (*(u8 (*)[])&D_800D2E70)[*list] = 3;
            func_1509CCB4(*list);
            count++;
        }
        list++;
    }
    return count;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CDDC.s")

void func_1509CE64(u16 *arg0, void (*arg1)(s32)) {
    u16 *p;

    for (p = arg0; *p != 0xFFFF; p++) {
        arg1(*p);
        ((u8 *)&D_800D2E70)[*p] = 3;
        ((u8 *)D_800D2E4C)[*p >> 3] |= 1 << (*p & 7);
    }
}

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

struct func_1509D08C_s {
    s16 *unk0;
    s32 unk4;
    s16 *unk8;
    u32 unkC;
};
struct func_1509D08C_e {
    struct func_1509D08C_s *unk0;
    s32 unk4;
};
struct func_1509D08C_h {
    s32 unk0;
    s32 unk4;
    struct func_1509D08C_e unk8[1];
};

s32 func_1509D08C(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    struct func_1509D08C_h *base;
    u32 i;

    base = D_800D2FB0;
    if (base == NULL) {
        if (arg2 != NULL) {
            *arg2 = 0xBF;
        }
        if (arg3 != NULL) {
            *arg3 = 0;
        }
        return 0;
    }
    if (base->unk8[arg1].unk0 == NULL) {
        if (arg2 != NULL) {
            *arg2 = 0xBF;
        }
        if (arg3 != NULL) {
            *arg3 = 0;
        }
        return 0;
    }
    if (arg2 != NULL) {
        *arg2 = *base->unk8[arg1].unk0->unk8;
    }
    if (arg3 != NULL) {
        *arg3 = *base->unk8[arg1].unk0->unk0;
    }
    for (i = 0; i < base->unk8[arg1].unk0->unkC; i++) {
        if (!(((u8 *)D_800D2E4C)[base->unk8[arg1].unk0->unk8[i] >> 3] & (1 << (base->unk8[arg1].unk0->unk8[i] & 7)))) {
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509DBBC.s")
