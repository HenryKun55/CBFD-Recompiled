#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150C09B0(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x20, arg0 + 0x24, arg0);
}

void func_150C09F0(s32 arg0) {
    func_150C0A48(arg0);
    func_15169804(arg0);
}

void func_150C0A1C(s32 arg0) {
    func_150C0A48(arg0);
    func_15169824(arg0);
}

struct func_150C0A48_s {
    void *unk0;
    s16 unk4;
};

int func_150C0A48(s32 arg0) {
    s32 i;

    i = *(s16 *)(arg0 + 0x44);
    while (i != -1) {
        func_1516972C((struct102 *)(*(struct func_150C0A48_s **)(arg0 + 0x40))[i].unk0);
        i = (*(struct func_150C0A48_s **)(arg0 + 0x40))[i].unk4;
    }
}

struct func_150C0AC0_s {
    s32 unk0;
    s16 unk4;
    s16 unk6;
};

void *func_15167A68(s32, s32, s32, s32, u8, s32);
void *memcpy(void *, const void *, u32);

void *func_150C0AC0(u8 *arg0, u8 arg1, s32 arg2) {
    u8 *r;
    s32 size;
    s16 i;

    size = *(s16 *)(arg0 + 0x14) * 8 + 0x48;
    if (!(arg0[0x18] & 2)) {
        if (*(s32 **)(arg0 + 8) == NULL) {
            return NULL;
        }
        if (**(s32 **)(arg0 + 8) == 0) {
            return NULL;
        }
    }
    r = func_15167A68(0x25, arg2, size, 1, arg1, 1);
    if (r == NULL) {
        return NULL;
    }
    memcpy(r + 0x18, arg0, 0x1C);
    *(u8 **)(r + 0x40) = r + 0x48;
    if (arg0[0x18] & 2) {
        *(f32 *)(r + 0x34) = *(f32 *)(*(u8 **)(r + 0x18) + 0);
        *(f32 *)(r + 0x38) = *(f32 *)(*(u8 **)(r + 0x18) + 8);
    } else {
        *(f32 *)(r + 0x34) = *(f32 *)(*(u8 **)(r + 0x20) + 0x14);
        *(f32 *)(r + 0x38) = *(f32 *)(*(u8 **)(r + 0x20) + 0x1C);
    }
    *(f32 *)(r + 0x3C) = 0.0f;
    *(s16 *)(r + 0x44) = -1;
    *(s16 *)(r + 0x46) = 0;
    for (i = 0; i < *(s16 *)(arg0 + 0x14) - 1; i++) {
        (*(struct func_150C0AC0_s **)(r + 0x40))[i].unk4 = i + 1;
    }
    (*(struct func_150C0AC0_s **)(r + 0x40))[*(s16 *)(arg0 + 0x14) - 1].unk4 = -1;
    *(s32 *)(r + 0x10) = 1;
    *(s32 *)(r + 0x14) = 0;
    return r;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C1198.s")
