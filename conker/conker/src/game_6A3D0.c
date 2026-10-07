#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503CF20.s")

void func_1503D438(s32 *arg0, s32 arg1);

void func_1503D368(s8 *arg0, s32 arg1) {
    s32 i;

    if (arg0 != NULL) {
        for (i = 0; arg0[i << 3] != -0x21; i++) {
            switch (arg0[i << 3]) {
            case 1:
                func_1503D438((s32 *)&arg0[(i << 3) + 4], arg1);
                break;
            case -0x24:
                if ((u8)arg0[(i << 3) + 3] == 0xE) {
                    func_1503D438((s32 *)&arg0[(i << 3) + 4], arg1);
                }
                break;
            }
        }
    }
}

void func_1503D438(s32 *arg0, s32 arg1) {
    if (*arg0 != 0) {
        if ((*arg0 & 0xF000000) == 0) {
            *arg0 += arg1;
        }
    }
}

void func_1503D45C(s32 *arg0, s32 arg1) {
    while (*arg0 != 0) {
        *arg0 += arg1;
        arg0 += 2;
    }
}

struct func_1503D484_s {
    u16 id;
    s32 ptr;
};

void func_1503D484(struct func_1503D484_s *arg0, s32 arg1) {
    struct func_1503D484_s *base = arg0;

    while (arg0->id != 999) {
        if (arg0->ptr != 0) {
            func_1503D438(&arg0->ptr, (s32)base);
        }
        arg0++;
    }
    D_800C5A90[arg1] = arg0 - base;
}

extern u8 *D_80084410[];
extern u8 D_80098888[];

void func_1503D510(s32 arg0) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < D_80098888[i]; j++) {
            if (arg0 == D_80084410[i][j]) {
                for (k = 0; k < D_80098888[i]; k++) {
                    D_800D1588[D_80084410[i][k]] = D_800D1588[arg0];
                    D_800C5A90[D_80084410[i][k]] = ((u16 *)D_800C5A90)[arg0];
                }
                return;
            }
        }
    }
}

extern u8 *D_80084410[];
extern u8 D_80098888[];

s32 func_1503D5F0(s32 arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < D_80098888[i]; j++) {
            if (arg0 == D_80084410[i][j]) {
                return D_80084410[i][0];
            }
        }
    }
    return arg0;
}

extern s32 func_1502B5C8();
void func_1503D510(s32);

struct func_1503D660_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

s32 func_1503D660(s32 arg0, struct func_1503D660_s *h) {
    s32 sp34;
    struct func_1503D660_s **p;

    p = (struct func_1503D660_s **)&D_800D1588[arg0];
    if (*p != 0) {
        return 0;
    }
    h = (struct func_1503D660_s *)func_1502B5C8(&sp34, 2, 15, func_1503D5F0(arg0));
    if (h == NULL) {
        *p = NULL;
        D_800C5A90[arg0] = 0;
        func_1503D510(arg0);
        return 4;
    }
    *p = h;
    if (h->unk0 != 0) {
        (*p)->unk0 += (s32)*p;
        func_1503D45C((*p)->unk0, (s32)(*p + 1));
    }
    if ((*p)->unk4 != 0) {
        (*p)->unk4 += (s32)*p;
    }
    if ((*p)->unk8 != 0) {
        (*p)->unk8 += (s32)*p;
    }
    *p = *p + 1;
    func_1503D484(*p, arg0);
    func_1503D510(arg0);
    return 0;
}

void *func_1502B6BC();

s32 func_1503D774(s32 arg0, s32 arg1) {
    s32 sp2C;
    void **temp;

    if (D_800D1C90[arg0] != NULL) {
        return 0;
    }
    temp = func_1502B6BC(&sp2C, 2, 0, 2, 0x11, arg0);
    if (temp == NULL) {
        D_800D1C90[arg0] = NULL;
        return 2;
    } else {
        D_800D1C90[arg0] = (struct124 *)temp;
        D_800D1C90[arg0] = *temp;
    }
    return 0;
}

struct func_1503D804_s {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
};

struct func_1503D804_d {
    s16 unk0;
    s16 unk2;
};

extern s32 *D_800C4020[];
void *allocate_memory(s32, s32, s32, s32);

s32 func_1503D804(s32 arg0) {
    s32 count;
    s32 idx;
    struct func_1503D804_s *src;
    struct func_1503D804_d *dst;
    s32 i;

    idx = -1;
    if (arg0 == 0x24) {
        count = 0x5E;
        idx = 0;
    } else {
        count = 0;
    }
    if (count == 0) {
        return 0;
    }
    if (D_800C6360[arg0] != 0) {
        return 0;
    }
    src = (struct func_1503D804_s *)(&D_800D19A0)[arg0];
    if (idx != -1) {
        src += D_800C4020[arg0][idx];
    }
    D_800C6360[arg0] = (s32)allocate_memory(count * 4, 1, 0, 2);
    if (D_800C6360[arg0] == 0) {
        return 1;
    }
    dst = (struct func_1503D804_d *)D_800C6360[arg0];
    for (i = 0; i < count; i++) {
        dst[i].unk0 = src[i].unk8;
        dst[i].unk2 = src[i].unkA;
    }
    return 0;
}

struct func_1503D984_s {
    u32 word;
    s32 unk4;
};

extern struct func_1503D984_s **D_800C4488[];
extern s16 D_800C5918[];

void func_1503D984(s32 arg0) {
    s32 count = 0;
    s32 i;
    s32 j;
    struct func_1503D984_s *b;
    s32 t;

    for (i = 0; i < 1; i++) {
        b = D_800C4488[arg0][i];
        for (j = 0; (t = (s8)(b[j].word >> 24)) != -0x21; j++) {
            if (t == 5) {
                count += 1;
            } else if (t == 6) {
                count += 2;
            } else if ((t >> 4) == 1) {
                count += 4;
            }
        }
    }
    D_800C5918[arg0] = count;
}

struct func_1503DA3C_s {
    u8 pad[0x30];
    u8 *data;
    u32 count;
};

u8 func_1503DA3C(s32 arg0, s32 arg1) {
    s32 p;
    struct func_1503DA3C_s *s;
    u8 ret;

    p = (&D_800D19A0)[arg0];
    s = (struct func_1503DA3C_s *)(p - 0x38);
    if (p == 0) {
        return 0xFF;
    }
    if (s->count < (u32)(arg1 + 1)) {
        return 0xFF;
    }
    ret = (s->data != NULL) ? s->data[arg1] : 0xFF;
    return ret;
}

struct func_1503DA9C_s {
    u8 pad0[0xAC];
    u8 unkAC;
    u8 padAD[0x144 - 0xAD];
    s32 *unk144;
};

extern s32 func_1503CF20(s32, s32, s32 *, s32, s32);
extern s32 func_150028BC(s32);
extern s32 func_1503DC3C(s32);
extern void func_1510CE60(s32, s32, s32, s32, s32 *);
extern s32 func_15084044(struct func_1503DA9C_s *, s32);
struct func_1503DD1C_s;
extern struct func_1503DD1C_s *D_800C5338[];
extern u16 D_800C5628[];
extern u16 D_800C4778[];

s32 func_1503DA9C(struct func_1503DA9C_s *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *s0;
    s32 pad;
    s32 ret;
    s32 i;

    s0 = arg0->unk144;
    if ((&D_800D19A0)[arg1] == 0) {
        ret = func_1503CF20(arg1, 0, s0, arg3, arg0->unkAC);
    } else {
        ret = 0;
        if (((s0 != NULL && (s0[6] & 0x4000)) || (arg0->unkAC & 1)) && D_800C5C08[arg1] == 0) {
            func_150028BC(arg1);
        }
        if (arg3 != 0) {
            if (D_800C5628[arg1] != 0 && *(u32 *)D_800C5338[arg1] < 0x10000000U) {
                ret = func_1503DC3C(arg1);
                for (i = 0; i < D_800C4778[arg1]; i++) {
                    func_1510CE60((s32)D_800C4488[arg1][i], 0, 0, 0x3E, 0);
                }
            }
        }
    }
    if (ret == 0) {
        ret = func_15084044(arg0, arg2);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DC3C.s")

struct func_1503DD1C_s {
    s32 unk0;
    u32 unk4;
    s32 unk8;
};

extern u16 D_800C5628[];
extern struct func_1503DD1C_s *D_800C5338[];
extern void func_1510D7AC(s32);

void func_1503DD1C(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800C5628[arg0]; i++) {
        if (D_800C5338[arg0][i].unk0 != 0x80000000 && D_800C5338[arg0][i].unk0 != D_800C5338[arg0][i].unk4) {
            func_1510D7AC(D_800C5338[arg0][i].unk4);
        }
    }
}
