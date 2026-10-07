#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081C20.s")

void func_15081E0C(struct127 *arg0, u16 arg1, u8 arg2) {
    if (D_800BE616 == 0) {
        if (arg0->health != 0) {
            arg0->health = 7;
        }
        if ((arg2 == 0) || (arg1 != 10)) {
            func_1507DF10(arg0, arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150825C0.s")

extern u8 D_800D2100;
extern u8 D_800D2101;
void func_150825C0(s32, s32);

void func_1508295C(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 start;
    s32 end;

    if (arg2) {
        start = 0;
        end = D_800D2101;
    } else {
        start = D_800D2101;
        end = D_800D2100;
    }
    for (i = start; i < end; i++) {
        func_150825C0(i, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150829D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15082A44.s")

struct func_150832AC_s {
    u8 pad0[0x127];
    u8 unk127;
    u8 pad128[0x144 - 0x128];
    u8 *unk144;
    u8 pad148[0x300 - 0x148];
    u8 unk300;
    u8 unk301;
    u8 pad302[2];
    s32 unk304[4];
    s32 unk314;
};

s32 func_1515D480(s32);
s32 func_1515D440(void);

void func_150832AC(struct func_150832AC_s *arg0) {
    s32 i;
    s32 var_s3;
    u8 temp;
    u8 *p;

    p = arg0->unk144;
    if (p != NULL) {
        temp = p[0x2F];
        if (temp == 0) {
            if (arg0->unk127 == 0) {
                var_s3 = 5;
            } else {
                var_s3 = 3;
            }
        } else {
            var_s3 = temp;
        }
        for (i = 0; i <= D_80082FA0; i++) {
            arg0->unk304[i] = func_1515D480(var_s3);
        }
        if (arg0->unk304[i - 1] != 0) {
            arg0->unk301 = var_s3;
        }
        arg0->unk314 = func_1515D440();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083568.s")

struct func_150836CC_e { u8 unk0; u8 pad1[2]; u8 unk3; u8 pad4[0xC]; };
struct func_150836CC_s { struct func_150836CC_e *entries; u8 count; u8 pad5[3]; };
extern struct func_150836CC_s D_80086CC4[];
void func_150302F0(struct127 *arg0, s32 arg1);

void func_150836CC(struct127 *arg0, s32 arg1) {
    struct func_150836CC_s *s;
    struct func_150836CC_e *e;
    s32 i;
    struct127 *obj;

    func_150302F0(arg0, arg1);
    arg1--;
    s = &D_80086CC4[arg1];
    e = s->entries;
    for (i = 0; i < s->count; i++) {
        if (e[i].unk3 == 0) {
            obj = func_1505F0AC(e[i].unk0);
            if (obj != NULL) {
                if (obj->unk65 == (arg0 - gObjects) + 1) {
                    func_15060F28(obj, 0);
                }
            }
        }
    }
}

s32 func_1502B020(s32, s32, s32, s32);
s32 func_15084D00(u8 *);

struct func_150837D4_s {
    u8 pad0[6];
    s16 unk6;
    u8 pad8[0xA];
    u8 unk12;
};

void func_150837D4(s32 arg0, s32 arg1, s32 arg2) {
    struct127 *obj;
    struct func_150837D4_s *q;

    obj = &gObjects[arg0];
    obj->id = arg1;
    if (arg1 == 0xFF) {
        obj->unkE4 = 0;
        obj->unkE6 = 0;
        obj->unkE8 = 0;
        obj->unkD2 = 0x46;
        obj->unkD4 = 0x46;
        obj->unkD6 = 0;
        *(s16 *)&obj->pad160 = 0;
        *(f32 *)&obj->padC8 = 0.0f;
    } else {
        *(f32 *)&obj->padC8 = ((struct func_150837D4_s *)D_800D1C90[arg1])->unk6;
        func_15062BDC(obj, obj->xz_scale, obj->y_scale);
        q = (struct func_150837D4_s *)D_800D1C90[arg1];
        obj->unk5 = q->unk12;
    }
    obj->unk6 = func_15084D00((u8 *)obj);
    if ((u16)D_800C5A90[obj->unk6] != 0) {
        obj->pad58 = func_1502B020(0, 2, 2, obj->unk6);
    }
}

struct func_150838EC_s {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x2D0 - 5];
    s32 unk2D0;
};

s32 func_150838EC(struct func_150838EC_s *arg0, u16 arg1, s32 arg2, f32 arg3) {
    if (D_800D1588[arg0->unk4] == 0) {
        return 0;
    }
    if ((u16)D_800C5A90[arg0->unk4] == 0) {
        return 0;
    }
    arg0->unk2D0 = allocate_memory(0x3E0, 1, 2, 0);
    if (arg0->unk2D0 == 0) {
        return 1;
    }
    bzero(arg0->unk2D0, 0x40);
    func_1505E650(arg0, arg1, arg3, 0.0f, 0.0f, 0.0f, arg2);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150839B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083AC8.s")

struct func_15083DA0_s {
    u8 pad0[0x28];
    u8 unk28;
    u8 pad29[0x7];
};
extern u8 D_800D2100;

s32 func_15083DA0(void) {
    s32 i;
    s32 count = 1;

    for (i = 0; i < D_800D2100; i++) {
        if (count == ((struct func_15083DA0_s *)D_800D20FC)[i].unk28) {
            count++;
            i = 0;
        }
    }
    if (count >= 0x100) {
        count = 0xFF;
    }
    return count;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083FB0.s")

struct127 *func_1505EEF4(s32 arg0);

s32 func_15084000(s32 arg0) {
    struct127 *obj = func_1505EEF4(arg0);
    if (obj != NULL) {
        return obj - gObjects;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084044.s")

void func_150843AC(u8 *arg0, s32 arg1);

void func_1508434C(u8 *arg0) {
    s32 n;
    s32 i;

    n = arg0[0x2C9];
    if (n == 0) {
        n = 1;
    }
    for (i = 0; i < n; i++) {
        func_150843AC(arg0, i);
    }
}

struct func_150843AC_s {
    u8 pad0[0x28C];
    s32 unk28C[4][2];
    u8 pad2AC[0x2C4 - 0x2AC];
    u8 *unk2C4;
};

void func_150843AC(u8 *arg0, s32 arg1) {
    s32 i;
    u8 idx;
    s32 p;

    if ((((struct func_150843AC_s *)arg0)->unk28C[arg1][0] != 0) || (((struct func_150843AC_s *)arg0)->unk28C[arg1][1] != 0)) {
        idx = ((struct func_150843AC_s *)arg0)->unk2C4[arg1];
        for (i = 0; i < 2; i++) {
            p = ((struct func_150843AC_s *)arg0)->unk28C[arg1][i];
            if (p == 0) {
                continue;
            }
            if (p != (&D_800D19A0)[idx]) {
                func_100043B4((void *)p, 3);
            } else {
                ((u8 *)D_800D1F80)[idx]--;
            }
            ((struct func_150843AC_s *)arg0)->unk28C[arg1][i] = 0;
        }
    }
}

extern u8 *D_80086CAC[];
void func_1503D774(s32 arg0, s32 arg1);
void func_1503D660(s32 arg0, s32 arg1);

void func_15084488(u8 *arg0, s32 arg1, s32 arg2) {
    s32 idx;
    u8 *p;
    u8 *ptr;
    s32 n;
    s32 i;

    idx = arg0[4];
    if (idx != 0xFF) {
        func_1503D774(idx, arg2);
        p = (u8 *)D_800D1C90[idx];
        ptr = arg0 + 4;
        n = p[4];
        if (n == 0) {
            n = 1;
        } else {
            ptr = D_80086CAC[p[5]];
        }
        n += p[0x38];
        for (i = 0; i < n; i++) {
            func_1503D774(ptr[i], arg2);
            func_1503D660(ptr[i], arg2);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084558.s")

struct func_150849A0_s {
    u8 pad0[0x1C9];
    u8 unk1C9;
    u8 pad1CA[0x2C4 - 0x1CA];
    u8 *unk2C4;
};

u8 func_150849A0(struct func_150849A0_s *arg0) {
    if (arg0->unk1C9 != 0) {
        return arg0->unk2C4[arg0->unk1C9 - 1];
    }
    return arg0->unk2C4[0];
}

struct func_150849CC_s {
    u8 pad0[0x1C9];
    u8 unk1C9;
    u8 pad1CA[0x2C4 - 0x1CA];
    u8 *unk2C4;
    u8 unk2C8;
};

u8 func_150849CC(struct func_150849CC_s *arg0, s32 *arg1) {
    s32 idx;

    if (arg0->unk1C9 != 0) {
        idx = arg0->unk1C9 - 1;
    } else if (arg0->unk2C8 != 0) {
        idx = arg0->unk2C8 - 1;
    } else {
        idx = 0;
    }
    if (arg1 != NULL) {
        *arg1 = idx;
    }
    return arg0->unk2C4[idx];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084A18.s")

struct func_15084C30_s {
    u8 pad0[8];
    f32 unk8;
    u8 padC[0x18 - 0xC];
    f32 unk18;
};

void func_15084C30(u8 *arg0) {
    struct func_15084C30_s *temp;
    f32 f;

    if (arg0[4] == 0x94) {
        temp = *(struct func_15084C30_s **)(arg0 + 0x2D0);
        f = (u32)func_150ADA20() % (s32)temp->unk18;
        temp->unk8 = f;
    }
}

extern u8 D_800BE590;
extern u16 D_800BE598[];

s32 func_15084CB0(s32 arg0) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < D_800BE590; i++) {
        if (arg0 == D_800BE598[i]) {
            ret = i;
            break;
        }
    }
    return ret;
}
