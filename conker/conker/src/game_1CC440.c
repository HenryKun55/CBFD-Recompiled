#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519EF90.s")

struct func_1519F108_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_1519F108(void *arg0) {
    struct func_1519F108_s *p;
    u8 **q;

    q = *(u8 ***)((u8 *)arg0 + 0x98);
    if (*q != NULL) {
        p = (struct func_1519F108_s *)(*q + 0x58);
        if (*(s32 *)((u8 *)arg0 + 0x20) == 6) {
            p->unk0 = 0;
        }
        if (*(s32 *)((u8 *)arg0 + 0x20) == 7) {
            p->unk8 = 0;
        }
    }
    func_151478F4(arg0);
}

void func_15147928(void *arg0);

void func_1519F168(void *arg0) {
    s32 *v;
    s32 *p;

    v = *(s32 **)((u8 *)arg0 + 0x98);
    if (*v != 0) {
        p = (s32 *)(*v + 0x58);
        if (*(s32 *)((u8 *)arg0 + 0x20) == 6) {
            p[0] = 0;
        }
        if (*(s32 *)((u8 *)arg0 + 0x20) == 7) {
            p[2] = 0;
        }
    }
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F1C8.s")

struct func_1519F3B8_s {
    void *a;
    s32 b;
    void *c;
    s32 d;
};

void *func_1519F1C8(void *arg0, s32 arg1);

void func_1519F3B8(void *arg0) {
    struct func_1519F3B8_s *s;

    s = (struct func_1519F3B8_s *)((u8 *)arg0 + 0x58);
    s->a = func_1519F1C8(arg0, 6);
    s->b = 0;
    s->c = func_1519F1C8(arg0, 7);
    s->d = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F400.s")

struct func_1519F48C_s {
    struct func_1519F48C_s *unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    u8 padC[0x58 - 0xC];
};

void func_1519F48C(u8 *arg0) {
    struct func_1519F48C_s *temp_v0;
    struct func_1519F48C_s *temp_a1;

    temp_v0 = *(struct func_1519F48C_s **)(arg0 + 0x98);
    if (temp_v0->unk0 != NULL) {
        temp_a1 = temp_v0->unk0;
        temp_a1++;
        if (*(s32 *)(arg0 + 0x20) == 6) {
            temp_a1->unk0 = NULL;
        }
        if (*(s32 *)(arg0 + 0x20) == 7) {
            temp_a1->unk8 = 0;
        }
        temp_v0->unk0 = NULL;
    }
    *(u8 *)(arg0 + 0x30) = 0;
    *(u16 *)(arg0 + 0x1E) &= ~2;
    temp_v0->unk4 |= 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519FE6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A084C.s")

void func_151A0928(u8 *arg0) {
    s32 *p = (s32 *)(*(u8 **)(arg0 + 0x28) + 0x58);
    if (arg0[0x2C] == 6) {
        p[1] = 0;
    } else {
        p[3] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A09B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1010.s")

void func_151A11CC(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A11E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A175C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A18DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A24A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A25E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A26EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2AD4.s")

void func_151A2B84(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5) {
    f32 t = 1.0f - arg4;
    arg5[0] = arg0[0] * t;
    arg5[1] = arg0[1] * t;
    arg5[2] = arg0[2] * t;
}

void func_15143794(s16 arg0, s16 arg1, f32 arg2, void *arg3);

void func_151A2BD0(s32 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, void *arg5) {
    func_15143794(arg1, arg2, (1.0f - arg4) * arg3, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A3150.s")
