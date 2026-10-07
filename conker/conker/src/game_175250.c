#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct func_15147DA0_s {
    s32 w[8];
} func_15147DA0_s;

void *func_15147A80();

void *func_15147DA0(s32 *arg0, void *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, func_15147DA0_s *arg11, s32 arg12, u8 arg13, s32 arg14) {
    void *temp_v0;
    u8 *temp_a0;

    arg0[4] = 1;
    temp_v0 = func_15147A80(arg0, arg2 + 0x48, 0x14, 1, 0, 1, arg9, arg10, arg12, arg13, arg14);
    if (temp_v0 == NULL) {
        return NULL;
    }
    temp_a0 = *(u8 **)((u8 *)temp_v0 + 0x98);
    memcpy(temp_a0, arg1, 0x20);
    temp_a0[0x20] = arg3;
    temp_a0[0x21] = arg4;
    temp_a0[0x22] = arg5;
    temp_a0[0x23] = arg6;
    temp_a0[0x24] = arg7;
    temp_a0[0x25] = arg8;
    *(func_15147DA0_s *)(temp_a0 + 0x28) = *arg11;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15147EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_1514803C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_151488C4.s")

struct func_15148AF4_e {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u8 pad10[4];
};
struct func_15148AF4_v {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    f32 unk10;
};
struct func_15148AF4_s {
    u8 pad0[0x25];
    u8 unk25;
    u8 pad26[7];
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x94 - 0x2F];
    struct func_15148AF4_e *unk94;
    struct func_15148AF4_v *unk98;
};

s32 func_15148AF4(struct func_15148AF4_s *arg0) {
    struct func_15148AF4_e *arr = arg0->unk94;
    struct func_15148AF4_v *v = arg0->unk98;
    s32 i = arg0->unk2E;

    do {
        i--;
        if (i < 0) {
            i = arg0->unk25 - 1;
        }
        arr[i].w -= v->unk10 * D_800BE9A4;
        arr[i].x += v->unk4 * D_800BE9A4;
        arr[i].y += arr[i].w * D_800BE9A4;
        arr[i].z += v->unkC * D_800BE9A4;
    } while (i != arg0->unk2D);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148BA4.s")

struct func_15148DE0_e { u8 pad0[0x10]; u16 unk10; u8 pad12[2]; };
struct func_15148DE0_s {
    u8 pad0[0x25];
    u8 unk25;
    u8 pad26[6];
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x94 - 0x2F];
    struct func_15148DE0_e *unk94;
    u8 *unk98;
};

s32 func_15148DE0(struct func_15148DE0_s *arg0) {
    u8 *flags;
    struct func_15148DE0_e *ents;
    s32 i;
    u16 step;
    u16 v;

    if (arg0->unk2C >= 3) {
        arg0->unk2C--;
        ents = arg0->unk94;
        flags = arg0->unk98;
        i = arg0->unk2D;
        step = 0x1000 / arg0->unk2C;
        v = (flags[0x18] & 0x20) ? 0x1000 : 0;
        arg0->unk2E--;
        if (arg0->unk2E < 0) {
            arg0->unk2E = arg0->unk25 - 1;
        }
        while (i != arg0->unk2E) {
            ents[i].unk10 = v;
            if (flags[0x18] & 0x20) {
                v -= step;
            } else {
                v += step;
            }
            i++;
            if (i == arg0->unk25) {
                i = 0;
            }
        }
        return 1;
    }
    return 0;
}

struct func_15148EF8_s {
    u8 pad0[0x98];
    u8 *unk98;
};

s32 func_15148EF8(struct func_15148EF8_s *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_v1 = arg0->unk98;

    temp_v1[0x20] = 4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148F1C.s")

struct func_151490C8_s { u8 pad[0x1B]; u8 unk1B; };
s32 func_151490C8(u8 *arg0) {
    struct func_151490C8_s *temp_v0 = *(struct func_151490C8_s **)(arg0 + 0x98);
    s32 v = *(s16 *)(arg0 + 0x1C) * 8;
    u8 b;
    if (v >= 0x100) {
        v = 0xFF;
    }
    temp_v0->unk1B = b = v;
    if (b < 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15149104.s")
