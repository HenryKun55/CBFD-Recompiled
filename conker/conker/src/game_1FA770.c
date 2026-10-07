#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD2C0.s")

void func_151CD35C(s32 arg0) {
    s32 sp1C;

    if ((arg0 >= 0) && (arg0 < 4)) {
        sp1C = arg0;
        func_151494E0((s32)&sp1C, 0x17);
    }
}

void func_151CD394(s32 arg0) {
    s32 sp1C;

    if (arg0 >= 0 && arg0 < 4) {
        sp1C = arg0;
        func_151494E0((s32)&sp1C, 0x18);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CDB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CDE20.s")

struct func_151CE47C_s {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
};

void func_151CE47C(struct func_151CE47C_s *arg0) {
    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    arg0->unk1E |= 8;
}

void func_151CE49C(s32 arg0) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0x98);
    sp1C = *(s32 *)(temp_v0 + 0x48);
    func_151494E0((s32)&sp1C, 0x23);
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEAAC.s")

struct func_151CEC10_s {
    f32 x, y, z;
};

struct func_151CEC10_b {
    u8 pad[0x40];
    struct func_151CEC10_s pos;
};

s32 func_151CEC10(struct func_151CEC10_s *out, f32 *a1, struct func_151CEC10_b *a2) {
    if (a2 != NULL) {
        *out = a2->pos;
    } else {
        out->x = a1[5];
        out->y = a1[6];
        out->z = a1[7];
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF380.s")

void func_151CF844(u8 *arg0, void *arg1, u8 arg2) {
    s32 *temp = *(s32 **)(arg0 + 0x98);

    if (*temp != 0) {
        func_15169850(arg1, arg2, temp, temp + 1, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CFA4C.s")

void func_151D0024(struct127 *arg0) {
    struct {
        struct127 *ptr;
        u8 id;
    } tmp;

    tmp.ptr = arg0;
    tmp.id = arg0->unique_id;
    func_151494E0(&tmp, 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D0058.s")

struct func_151D0128_t { u8 pad[0x84]; u16 unk84; };
struct func_151D0128_s {
    u8 pad0[0xE];
    s16 unkE;
    u8 pad10[0x18];
    struct func_151D0128_t *unk28;
    u8 pad2C[2];
    u16 unk2E;
};

void func_151D0128(struct func_151D0128_s *arg0) {
    struct func_151D0128_t *temp = arg0->unk28;

    if (arg0->unk2E != temp->unk84) {
        arg0->unkE = -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D014C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D08F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D09A8.s")

void func_151D0ED8(s32 arg0) {
    s32 temp = arg0;
    if (*(s32 *)(temp + 0xA8) != 0) {
        func_1516972C(*(struct102 **)(temp + 0xA8));
    }
}

void func_151D0F08(s32 arg0) {
    func_151D0ED8(arg0);
    func_1513173C(arg0);
}

void func_151D0F34(s32 arg0) {
    func_151D0ED8(arg0);
    func_1513175C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D0F60.s")

s32 func_151D1074(u8 *arg0, f32 *arg1) {
    arg1[0] = *(f32 *)(arg0 + 0x14);
    arg1[1] = *(f32 *)(arg0 + 0x180) + 8.0f;
    arg1[2] = *(f32 *)(arg0 + 0x1C);
    return 1;
}

void func_151D10A4(s32 arg0, s32 arg1) {
    func_151D10E4(arg0, arg1, 0);
}

void func_151D10C4(void *arg0, s32 arg1) {
    func_151D10E4(arg0, arg1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D10E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1138.s")

void func_151D1328(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_151D1368(void) {
    func_151D13E0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D13B4.s")

struct func_151D13E0_s {
    u8 pad0[0x1C];
    u16 unk1C;
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    s32 *unk98;
};

struct func_151D13E0_t {
    s32 unk0;
    s32 unk4;
    struct func_151D13E0_s *unk8;
};
int func_151D13E0(s32 arg0) {
    struct func_151D13E0_t *s;
    s32 *p;

    s = (struct func_151D13E0_t *)(arg0 + 0x28);
    if (s->unk8 != NULL) {
        p = s->unk8->unk98;
        s->unk8->unk30 = 0;
        s->unk8->unk1E &= ~2;
        s->unk8->unk1E |= 8;
        s->unk8->unk1E |= 1;
        s->unk8->unk1C = 0x28;
        *p = 0;
        s->unk8 = NULL;
    }
    if (*(s32 *)(arg0 + 0x30) != 0) {
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D15D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D197C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1C98.s")

void func_151D223C(s32 *arg0) {
    s32 **temp_v0 = (s32 **)arg0[0x98 / 4];
    s32 *temp_v1 = *temp_v0;
    if (temp_v1 != NULL) {
        temp_v1[0x30 / 4] = 0;
    }
}

void func_151D2258(s32 arg0) {
    func_151D223C(arg0);
    func_151478F4(arg0);
}

void func_151D223C();
void *func_15147928();

void func_151D2284(void *arg0) {
    func_151D223C(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D22B0.s")
