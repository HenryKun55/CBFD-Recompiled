#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15192920_s {
    void *unk0;
    u8 unk4;
    f32 unk8;
};

void func_15192920(void *arg0) {
    struct260 *temp_v0;

    if ((s32)arg0 != 0) {
        struct func_15192920_s sp28;
        sp28.unk0 = (void *)arg0;
        sp28.unk4 = *((u8 *)arg0 + 0x3B);
        sp28.unk8 = 0.0f;
        temp_v0 = func_151491F4(0x23, -1, 0x14, 1, 0x10, (struct37 *)0xC, 0xFF, 1);
        if (temp_v0 != NULL) {
            memcpy((u8 *)temp_v0 + 0x28, &sp28, 0xC);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_151929A4.s")

struct func_15192D48_s {
    void *unk0;
    u8 unk4;
    f32 unk8;
};

struct260 *func_15192D48(void *arg0, s16 arg1, u8 arg2, s32 arg3) {
    struct260 *temp_v0;
    struct func_15192D48_s sp28;

    if (arg0 == NULL) {
        return NULL;
    }
    sp28.unk0 = arg0;
    sp28.unk4 = *((u8 *)arg0 + 0x3B);
    sp28.unk8 = 0.0f;
    temp_v0 = func_151491F4(arg1, -1, 0x18, 1, 0x16, (struct37 *)0xC, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp28, 0xC);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_15192DF0.s")

struct func_15193234_s {
    s32 unk0;
    u8 unk4;
};

struct func_15193234_msg {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void func_15193234(u8 *arg0, struct func_15193234_msg *arg1, u8 arg2) {
    struct func_15193234_s *p = (struct func_15193234_s *)(arg0 + 0x28);
    s32 id;

    if (arg2 == 0x2D) {
        if (p->unk0 == arg1->unk0) {
            p->unk0 = arg1->unk4;
            p->unk4 = arg1->unk9;
        } else if (p->unk0 == arg1->unk4) {
            p->unk0 = arg1->unk0;
            p->unk4 = arg1->unk8;
        }
        goto end;
    end:;
    } else if (arg2 == 0) {
        id = arg1->unk0;
        if (id == p->unk0 || p->unk4 == *((u8 *)arg1 + 4)) {
            func_1516972C((struct102 *)arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFDD0/func_151932E0.s")
