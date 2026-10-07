#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_1502FE10.s")

struct func_1502FFD8_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[2];
    u8 unk4;
    u8 pad5[3];
    u8 unk8;
    u8 unk9;
    u8 padA[0xA];
    s32 unk14;
    s32 pad18[3];
    s32 unk24;
    void *unk28;
    void *unk2C;
    s32 unk30;
    s32 pad34[5];
    s32 unk48;
};

extern void *allocate_memory(s32, s32, s32, s32);
extern void func_10004074(void *);
extern s32 func_1502FE10(u8, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern s32 func_1503F62C(u8, s8, s32 *, s32 *, s32 *, s32 *, s32 *);

s32 func_1502FFD8(struct func_1502FFD8_s *arg0, u8 *arg1) {
    s32 sp3C;
    s32 tmp;
    s32 size;

    if (arg0->unk24 == 0) {
    if (((s8 *)&arg0->unk14)[3] == -1) {
        if (func_1502FE10(arg0->unk1, &arg0->unk24, &arg0->unk14, &sp3C, &arg0->unk30, 0, 0)) {
            return 1;
        }
    } else {
        if (func_1503F62C(arg0->unk1, ((s8 *)&arg0->unk14)[3], &arg0->unk24, &arg0->unk14, &sp3C, &arg0->unk30, &arg0->unk48)) {
            return 1;
        }
    }
    tmp = arg1[0x66] & 0xC;
    size = arg0->unk24 - sp3C;
    if (!(arg0->unk4 & 0x10) && tmp == 8 && arg0->unk30 != 0) {
        arg0->unk28 = allocate_memory(size, 1, 2, 2);
        if (arg0->unk28 == NULL) {
            return 1;
        }
        arg0->unk2C = allocate_memory(size, 1, 2, 2);
        if (arg0->unk2C == NULL) {
            func_10004074(arg0->unk28);
            arg0->unk28 = NULL;
            return 1;
        }
        bcopy((void *)sp3C, arg0->unk28, size);
        bcopy((void *)sp3C, arg0->unk2C, size);
        arg0->unk8 = 1;
    } else {
        arg0->unk28 = (void *)sp3C;
        arg0->unk2C = (void *)sp3C;
    }
    arg0->unk9 = 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030158.s")

s32 func_15030310(void *arg0, s32 arg1, s32 arg2);

void func_150302F0(void *arg0, s32 arg1) {
    func_15030310(arg0, arg1, 0xFF);
}

struct func_15030310_s {
    u8 unk0;
    u8 pad1[5];
    u8 unk6;
    u8 pad7[0x54 - 7];
    struct func_15030310_s *next;
};

struct func_15030310_arg_s {
    u8 pad0[0x3B];
    u8 unk3B;
};

void func_15030158();

s32 func_15030310(void *arg0, s32 arg1, s32 arg2) {
    struct func_15030310_s *next;
    struct func_15030310_s *p;
    s32 ret;

    if (((struct func_15030310_arg_s *)arg0)->unk3B == 0) {
        return 0;
    }
    ret = 0;
    p = (struct func_15030310_s *)D_800C3EE0;
    while (p != NULL) {
        next = p->next;
        if (p->unk0 == ((struct func_15030310_arg_s *)arg0)->unk3B && p->unk6 == arg1) {
            if (arg2 != 0xFF && arg2 != 0) {
                arg2--;
                p = next;
                continue;
            } else {
                ret = 1;
                func_15030158(p, 0);
                if (arg2 == 0) {
                    break;
                }
            }
        }
        p = next;
    }
    return ret;
}

struct func_150303E4_s {
    u8 unk0;
    u8 pad1[0x53];
    struct func_150303E4_s *unk54;
};

struct func_150303E4_arg_s {
    u8 pad0[0x3B];
    u8 unk3B;
};

void func_15030158(struct func_150303E4_s *arg0, s32 arg1);

s32 func_150303E4(struct func_150303E4_arg_s *arg0) {
    struct func_150303E4_s *var_a0;
    struct func_150303E4_s *next;
    s32 found;

    if (arg0->unk3B == 0) {
        return 0;
    }
    found = 0;
    var_a0 = (struct func_150303E4_s *)D_800C3EE0;
    while (var_a0 != NULL) {
        next = var_a0->unk54;
        if (var_a0->unk0 == arg0->unk3B) {
            found = 1;
            func_15030158(var_a0, 0);
        }
        var_a0 = next;
    }
    return found;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030AF4.s")

struct func_15030D54_s {
    u8 pad0[0x34];
    void *unk34;
    u8 pad38[0xC];
    f32 *unk44;
};

void func_15030D54(struct func_15030D54_s *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    arg0->unk44 = (f32 *)allocate_memory(0x18, 1, 0, 2);
    if (arg0->unk44 != NULL) {
        arg0->unk44[0] = arg1;
        arg0->unk44[1] = arg2;
        arg0->unk44[2] = arg3;
        arg0->unk44[3] = arg4;
        arg0->unk44[4] = arg5;
        arg0->unk44[5] = arg6;
        if (arg0->unk34 == NULL) {
            arg0->unk34 = (void *)allocate_memory(0x80, 1, 2, 2);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030E08.s")

struct func_15030F94_s {
    u8 unk0;
    u8 pad1[2];
    u8 unk3;
    u8 pad4[0x50];
    struct func_15030F94_s *unk54;
};

struct func_15030F94_arg_s {
    u8 pad0[0x3B];
    u8 unk3B;
    u8 pad3C[0x1D4 - 0x3C];
    s32 unk1D4;
};

s32 func_150311C4(s32 arg0, struct func_15030F94_s *arg1, struct func_15030F94_arg_s *arg2, s32 arg3, s32 arg4);

s32 func_15030F94(s32 arg0, struct func_15030F94_arg_s *arg1, s32 arg2, s32 arg3) {
    struct func_15030F94_s *var_s0;
    struct func_15030F94_s *next;

    if (arg1 == NULL || arg1->unk1D4 == 0 || arg1->unk3B == 0) {
        return arg0;
    }
    var_s0 = (struct func_15030F94_s *)D_800C3EE0;
    while (var_s0 != NULL) {
        next = var_s0->unk54;
        if (var_s0->unk0 != arg1->unk3B || var_s0->unk3 == 0) {
            var_s0 = next;
            continue;
        }
        arg0 = func_150311C4(arg0, var_s0, arg1, arg2, arg3);
        var_s0 = next;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150311C4.s")

void func_1503192C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct126 *temp_v0 = func_1503195C(arg0, arg1, arg3);
    if (temp_v0 != NULL) {
        temp_v0->pad0[3] = arg2;
    }
}

struct func_1503195C_s {
    u8 unk0;
    u8 pad1[5];
    u8 unk6;
    u8 pad7[0x4D];
    struct func_1503195C_s *unk54;
};

struct126 *func_1503195C(u8 *arg0, s32 arg1, s32 arg2) {
    struct func_1503195C_s *p;
    struct func_1503195C_s *next;
    s32 v = arg0[0x3B];

    if (v == 0) {
        return NULL;
    }
    p = (struct func_1503195C_s *)D_800C3EE0;
    while (p != NULL) {
        next = p->unk54;
        if (v == p->unk0) {
            if (arg1 == p->unk6) {
                if (arg2 != 0) {
                    arg2--;
                    p = next;
                    continue;
                }
                return (struct126 *)p;
            }
        }
        p = next;
    }
    return NULL;
}

struct func_150319CC_s {
    u8 unk0;
    u8 pad1[5];
    u8 unk6;
    u8 pad7[0x4D];
    struct func_150319CC_s *next;
};

struct func_150319CC_a1 {
    u8 pad0[0x3B];
    u8 unk3B;
};

struct func_150319CC_s *func_150319CC(s32 arg0, struct func_150319CC_a1 *arg1) {
    struct func_150319CC_s *var_v1;
    struct func_150319CC_s *next;

    if (arg1 != NULL) {
        var_v1 = (struct func_150319CC_s *)D_800C3EE0;
        while (var_v1 != NULL) {
            next = var_v1->next;
            if (var_v1->unk0 != arg1->unk3B) {
            } else if (arg0 == var_v1->unk6) {
                return var_v1;
            }
            var_v1 = next;
        }
    }
    var_v1 = (struct func_150319CC_s *)D_800C3EE0;
    while (var_v1 != NULL) {
        next = var_v1->next;
        if (arg0 == var_v1->unk6) {
            return var_v1;
        }
        var_v1 = next;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031C14.s")

struct func_15031E2C_s {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[0x38 - 0x1A];
    s32 unk38;
};
extern s32 D_800902BC[];

s32 func_15031E2C(struct func_15031E2C_s *arg0, s32 arg1) {
    s32 i = arg0->unk38;
    if (i >= 3) {
        i = 5 - i;
    }
    arg0->unk18 = D_800902BC[i];
    arg0->unk38++;
    if (arg0->unk38 >= 6) {
        arg0->unk38 = 0;
    }
    return 0;
}

extern f32 D_800970DC;

s32 func_15031E7C(void *arg0, void *arg1) {
    void *obj;
    Gfx *gfx;
    f32 dist;
    f32 alpha;
    s32 i;
    s32 n;

    obj = *(void **)((char *)arg1 + 0x2D0);
    if (obj == NULL) {
        return 0;
    }
    gfx = **(void ***)((char *)arg0 + 0x24);
    if (gfx == NULL) {
        return 0;
    }
    if (*(u16 *)((char *)arg1 + 0x84) == 0x55) {
        alpha = 1.0f;
    } else if (*(u16 *)((char *)arg1 + 0x84) == 0x56) {
        alpha = 0.0f;
    } else {
        dist = *(f32 *)((char *)obj + 8);
        if ((dist >= 0.0f) && (dist <= 120.0f)) {
            alpha = dist * D_800970DC;
            alpha = 1.0f - alpha;
        } else {
            alpha = 0.0f;
        }
    }
    i = 0;
    n = 4;
    do {
        n--;
        while (*(s8 *)&gfx[i] != -0xE) {
            i++;
        }
        if (n != 0) {
            i++;
        }
    } while (n != 0);
    gfx[i].words.w0 = ((s32)((25.0f * alpha) + 2.0f) & 0xFFF) | 0xF2002000;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031FC8.s")

struct func_150331B8_s {
    u8 pad0[0x8];
    f32 unk8;
    u8 padC[0x18 - 0xC];
    f32 unk18;
};

struct func_150331B8_a1 {
    u8 pad0[0x2D0];
    struct func_150331B8_s *unk2D0;
    u8 pad2D4[0x2E4 - 0x2D4];
    s32 unk2E4;
};

void func_1503F5B8(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, s32 arg5);

s32 func_150331B8(void *arg0, struct func_150331B8_a1 *arg1) {
    struct func_150331B8_s *v0 = arg1->unk2D0;
    struct func_150331B8_s *s0 = *(struct func_150331B8_s **)((u8 *)arg0 + 0x48);
    s32 a2;

    if (s0 == NULL) {
        return 0;
    }
    a2 = arg1->unk2E4 & 0xFF;
    if (a2 != 0xFF) {
        func_1503F5B8(s0, 0, a2, 1.0f, 0.0f, 1);
    }
    if (v0 != NULL) {
        (*(struct func_150331B8_s **)((u8 *)arg0 + 0x48))->unk8 = v0->unk8;
        s0 = *(struct func_150331B8_s **)((u8 *)arg0 + 0x48);
        if (s0->unk8 >= s0->unk18) {
            s0->unk8 = s0->unk18 - 1.0f;
        }
    }
    return 0;
}

struct func_1503327C_s {
    u8 pad0[4];
    u16 unk4;
    u8 pad6[2];
    f32 unk8;
    u8 padC[0xC];
    f32 unk18;
};

void func_1503F5B8(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, s32 arg5);

s32 func_1503327C(void *arg0, s32 arg1) {
    struct func_1503327C_s *s;

    s = *(struct func_1503327C_s **)((u8 *)arg0 + 0x48);
    if (s == NULL) {
        return 0;
    }
    if ((s->unk4 & 0x8000) != 0x8000) {
        func_1503F5B8(s, 0, 0, 1.0f, 0.0f, 1);
        s = *(struct func_1503327C_s **)((u8 *)arg0 + 0x48);
    }
    if (s->unk8 >= s->unk18 - 1.0f) {
        return 1;
    }
    return 0;
}

struct func_15033328_a0 {
    u8 pad0[0x38];
    s32 unk38;
};
struct func_15033328_s {
    u8 pad0[0xAD];
    u8 unkAD;
    u8 padAE[0x118 - 0xAE];
    f32 unk118;
    u8 pad11C[0x180 - 0x11C];
    f32 unk180;
};

s32 func_15033328(struct func_15033328_a0 *arg0, struct func_15033328_s *arg1) {
    if (D_800C35EA == 1) {
        return 0;
    }
    if (arg1->unkAD == 0 && arg1->unk118 < arg1->unk180) {
        if (D_800BE9E4 < arg0->unk38) {
            arg0->unk38 -= D_800BE9E4;
            return 0;
        }
        return 1;
    }
    arg0->unk38 = 30;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150333A8.s")

struct func_15033440_s {
    u8 pad0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x22 - 0x3];
    s16 unk22;
};

s32 func_15033440(struct func_15033440_s *arg0, u8 *arg1) {
    switch (arg0->unk1) {
    case 0x27:
    case 0x35:
        if (arg1[5] == 5) {
            arg0->unk2 = 0;
            arg0->unk22 += D_800BE9E4 * 0xAAA;
        }
        break;
    case 0x29:
        if (arg1[5] == 5) {
            arg0->unk2 = 0;
        }
        break;
    }
    return 0;
}

struct func_150334B8_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0x24 - 0x2];
    Gfx **unk24;
};

s32 func_150334B8(struct func_150334B8_s *arg0, s32 arg1) {
    Gfx *gfx = NULL;
    s32 n = 0;
    s32 dx = 0;
    s32 i;
    s32 w0, w1;
    s32 w, h, nx, ny;

    if (arg0->unk1 == 0x37) {
        gfx = *arg0->unk24;
        n = 4;
        dx = -100;
    }
    if (gfx != NULL) {
        i = 0;
        while (n != 0) {
            n--;
            while (*(s8 *)&gfx[i] != -14) {
                i++;
            }
            if (n != 0) {
                i++;
            }
        }
        w0 = gfx[i].words.w0;
        w1 = gfx[i].words.w1;
        w = ((w1 >> 12) & 0xFFF) + 2;
        nx = ((w0 >> 12) & 0xFFF) + dx;
        h = (w1 & 0xFFF) + 2;
        ny = w0 & 0xFFF;
        if (nx >= w) {
            nx -= w;
        }
        if (nx < 0) {
            nx += w;
        }
        if (ny >= h) {
            ny -= h;
        }
        if (ny < 0) {
            ny += h;
        }
        gfx[i].words.w0 = 0xF2000000 | ((nx & 0xFFF) << 12) | (ny & 0xFFF);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150335C8.s")

struct func_1503378C_s { u8 pad0; u8 unk1; };
struct func_1503378C_t { u8 pad0[0x84]; u16 unk84; };

s32 func_1503378C(struct func_1503378C_s *arg0, struct func_1503378C_t *arg1) {
    u16 v = arg1->unk84;
    if (arg0->unk1 == 0x11) {
        if (v == 0x3E || v == 0x3D || v == 0x41 || v == 0xD9 || v == 0x138 || v == 0x139) {
            return 0;
        }
    }
    return 1;
}

extern s32 D_800902FC[];

struct func_150337E4_s {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[0x38 - 0x1A];
    s32 unk38;
    s32 unk3C;
};

s32 func_150337E4(struct func_150337E4_s *arg0, s32 arg1) {
    arg0->unk38 += D_800BE9E4;
    if (arg0->unk38 >= 0x10) {
        arg0->unk38 = 0;
        arg0->unk3C ^= 1;
    }
    arg0->unk18 = D_800902FC[arg0->unk3C];
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150339C8.s")

struct func_15033AD8_s {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct func_15033AD8_t {
    u8 pad0[0x38];
    s32 unk38;
    s32 unk3C;
};

s32 func_15033BDC();

s32 func_15033AD8(struct func_15033AD8_t *arg0, struct func_15033AD8_s *arg1) {
    if (D_800BE616) {
        func_1508B20C(arg1->unk14, arg1->unk18, arg1->unk1C, 900.0f);
    }
    if (arg0->unk38 == 0) {
        if (arg0->unk3C < 30) {
            arg0->unk3C += D_800BE9E4;
        } else {
            arg0->unk3C = func_1000FA64(0x513, arg1->unk14, arg1->unk18, arg1->unk1C, 0x7D00, 1000, 500, (s32)func_15033BDC, (s32)arg0, (s32)arg1, 0, 0);
            arg0->unk38 = 0x513;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033BDC.s")

struct func_15033E00_s {
    u8 pad0[5];
    u8 unk5;
};

s32 func_15033E00(s32 arg0, struct func_15033E00_s *arg1) {
    if (arg1->unk5 == 3) {
        return 1;
    }
    return 0;
}

struct func_15033E28_s {
    u8 unk0;
    u8 pad1[0x3A];
    u8 unk3B;
    u8 pad3C[0x18];
    struct func_15033E28_s *unk54;
};

s32 func_15033E28(struct func_15033E28_s *arg0, struct func_15033E28_s **arg1) {
    struct func_15033E28_s *var_a0;
    struct func_15033E28_s *next;
    s32 count = 0;

    if (D_800C3EE0 == 0) {
        return 0;
    }
    var_a0 = (struct func_15033E28_s *)D_800C3EE0;
    while (var_a0 != NULL) {
        next = var_a0->unk54;
        if (var_a0->unk0 == arg0->unk3B) {
            arg1[count++] = var_a0;
        }
        var_a0 = next;
    }
    return count;
}

struct func_15033E84_s {
    u8 unk0;
    u8 pad1[0x53];
    struct func_15033E84_s *unk54;
};

struct func_15033E84_s *func_15033E84(u8 *arg0) {
    struct func_15033E84_s *var_v1;
    struct func_15033E84_s *next;

    var_v1 = (struct func_15033E84_s *)D_800C3EE0;
    while (var_v1 != NULL) {
        next = var_v1->unk54;
        if ((arg0[0x3B] ^ var_v1->unk0) == 0) {
            return var_v1;
        }
        var_v1 = next;
    }
    return NULL;
}

struct func_15033EC4_s {
    u8 unk0;
    u8 pad1[0x53];
    struct func_15033EC4_s *unk54;
};

void func_15033EC4(s32 arg0, s32 arg1) {
    struct func_15033EC4_s *var_v0;
    struct func_15033EC4_s *next;

    var_v0 = (struct func_15033EC4_s *)D_800C3EE0;
    while (var_v0 != NULL) {
        next = var_v0->unk54;
        if (arg0 == var_v0->unk0) {
            var_v0->unk0 = arg1;
        } else if (arg1 == var_v0->unk0) {
            var_v0->unk0 = arg0;
        }
        var_v0 = next;
    }
}

s32 func_15033F0C(s32 arg0, struct struct127 *arg1) {
    struct126 *tmp;

    if (D_800C35EA == 1) {
        return 0;
    }
    tmp = arg1->unk31C;
    if ((tmp != NULL) && (tmp->unk78 != 9) && (tmp->unk11A != 3)) {
        tmp->unk11A = 0;
        return 1;
    }
    return 0;
}

s32 func_15033F70(s32 arg0, struct struct127 *arg1) {
    struct126 *tmp;

    if (D_800C35EA == 1) {
        return 0;
    }
    tmp = arg1->unk31C;
    if ((tmp != NULL) && (tmp->unk78 != 12) && (tmp->unk78 != 22) && (tmp->unk11A != 3)) {
        tmp->unk11A = 0;
        return 1;
    }
    return 0;
}
