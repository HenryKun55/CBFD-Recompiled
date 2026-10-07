#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1510E670_s {
    s32 unk0;
    s32 *unk4;
    s32 unk8;
    s32 unkC;
};

void func_150AD8B0(void *arg0, void *arg1, void *arg2);

s32 func_1510E670(s32 arg0) {
    s32 *tri = ((struct func_1510E670_s *)&D_800D3300)[arg0].unk4;
    s32 base = ((struct func_1510E670_s *)&D_800D3300)[arg0].unk8;
    s16 *v0;
    s16 *v1;
    s16 *v2;
    f32 a[3];
    f32 b[3];
    f32 c[3];
    f32 y;

    if (tri != NULL) {
        v0 = (s16 *)(tri[0] + base);
        v1 = (s16 *)(tri[1] + base);
        v2 = (s16 *)(tri[2] + base);
        a[0] = v1[0] - v0[0];
        a[1] = v1[1] - v0[1];
        a[2] = v1[2] - v0[2];
        b[0] = v2[0] - v0[0];
        b[1] = v2[1] - v0[1];
        b[2] = v2[2] - v0[2];
        func_150AD8B0(a, b, c);
        y = c[1];
        if (y < 0.0f) {
            return 0;
        }
        return 1;
    }
    return 0;
}

void func_1510E950(s32 **arg0, void *arg1, void *arg2, f32 *arg3, f32 *arg4, s32 *arg5, s16 *arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11, void *arg12, f32 arg13, f32 arg14, s32 arg15);

void func_1510E7A4(s32 **arg0, void *arg1, f32 *arg2, f32 *arg3, s32 *arg4, s16 *arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, u16 arg10, void *arg11, f32 arg12, f32 arg13) {
    func_1510E950(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, 0);
}

extern f32 D_800A2D50;
extern f32 D_800A2D54;

void func_1510E82C(s32 **arg0, void *arg1, f32 *arg2, f32 *arg3, s32 *arg4, s16 *arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, u16 arg10, void *arg11) {
    func_1510E950(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, D_800A2D50, D_800A2D54, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510E8BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510E950.s")

extern s32 D_800D3830;
extern f32 D_800A2D98;
void func_150A64C8(s16 arg0, s16 arg1, s32 *arg2, s32 arg3);
void func_150A44F0(s32 arg0, s32 *arg1, s32 arg2);
s32 func_150A43E0(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);

f32 func_1510F648(f32 arg0, f32 arg1, f32 arg2) {
    f32 ret;
    s32 sp28;
    s32 x;

    func_1510F800(2);
    x = arg0;
    func_150A64C8(x, (s32)arg2, &sp28, (s32)arg1);
    func_150A44F0(sp28, &D_800D3830, 0);
    if (func_150A43E0(x, (s32)arg2, sp28, &D_800D3830)) {
        ret = (s32)D_800D3300 * 0.00390625f;
    } else {
        ret = D_800A2D98;
    }
    return ret;
}

typedef struct func_1510F720_s {
    s32 pad0;
    s16 next;
    u16 radius;
    s16 x;
    s16 z;
    s16 skip;
} func_1510F720_s;

extern void *D_800DBE48;

#define F720_ABS(x) (((x) < 0) ? -(x) : (x))

s32 func_1510F720(s32 arg0, s32 arg1, s32 arg2, void **arg3) {
    func_1510F720_s *node;
    s32 count;
    s32 off;

    node = D_800DBE48;
    count = 0;
    while (node != NULL) {
        if (F720_ABS(node->x - arg0) < arg2 + node->radius &&
            F720_ABS(node->z - arg1) < arg2 + node->radius) {
            if (node->skip != 0) {
                off = node->skip;
            } else {
                *arg3++ = node;
                count++;
                off = node->next;
            }
        } else {
            off = node->next;
        }
        if (off != 0) {
            node = (func_1510F720_s *)((char *)node + off);
        } else {
            node = NULL;
        }
    }
    return count;
}

void func_1510F800(void) {
    func_150A49F4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510F820.s")

s32 func_1510F8CC(s32 arg0) {
    return arg0 & 0x1F;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510F8D8.s")

extern s32 D_800DBDC0;
extern s32 D_800DBDC4;
extern s32 D_800DBDC8;
extern f32 D_800DBDCC;
extern f32 D_800DBDD0;
s32 func_1510FE30(s32);
void func_150A6760(s32);
void func_150F33F8(s32);

void func_1510FC34(s32 arg0) {
    s32 x;
    s32 z;
    s32 tmp;
    s16 *ptr;

    D_800DBDC0 = arg0;
    x = D_800DBFF0[arg0].unk2F8;
    z = D_800DBFF0[arg0].unk300;
    D_800DBDCC = x;
    D_800DBDD0 = z;
    tmp = (s32)func_1510FD20(x, z);
    D_800DBDC8 = tmp;
    tmp = func_1510FE30(tmp);
    D_800DBDC4 = tmp;
    ptr = &((s16 *)&D_800DBE30)[arg0];
    if (tmp != *ptr) {
        *ptr = tmp;
        func_150A6760(arg0);
    }
    if (D_800BE9F0 == 0x3C) {
        func_150F33F8(arg0);
    }
}

struct func_1510FD20_s {
    u8 pad0[4];
    s16 next;
    u16 radius;
    s16 x;
    s16 y;
    s16 child;
};

extern void *D_800DBE48;

#define ABS(x) ((x) < 0 ? -(x) : (x))

void *func_1510FD20(s32 arg0, s32 arg1) {
    struct func_1510FD20_s *p = D_800DBE48;

    while (p != NULL) {
        if (p->child != 0) {
            if (ABS(arg0 - p->x) <= p->radius && ABS(arg1 - p->y) <= p->radius) {
                p = (struct func_1510FD20_s *)((char *)p + p->child);
            } else if (p->next != 0) {
                p = (struct func_1510FD20_s *)((char *)p + p->next);
            } else {
                p = NULL;
            }
        } else {
            if (ABS(arg0 - p->x) <= p->radius && ABS(arg1 - p->y) <= p->radius) {
                return p;
            }
            if (p->next != 0) {
                p = (struct func_1510FD20_s *)((char *)p + p->next);
            } else {
                p = NULL;
            }
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510FE30.s")
