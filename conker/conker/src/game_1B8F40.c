#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BA90.s")

struct func_1518BBF4_node {
    u8 pad0[8];
    struct func_1518BBF4_node *next;
    u8 padC[0x24 - 0xC];
    void *unk24;
    u8 unk28;
};
struct func_1518BBF4_s {
    u8 pad0[0x7C];
    struct func_1518BBF4_node *head;
    u8 pad80[0x1A0 - 0x80];
};
extern struct func_1518BBF4_s D_800DCE50[];
#define STK ((struct func_1518BBF4_node **)D_800DD198)
void func_1518BBF4(u8 *arg0) {
    s32 i;
    struct func_1518BBF4_node *n;
    if (arg0 != NULL) {
        i = 0;
        do {
            D_800DD190++;
            n = D_800DCE50[i].head;
            while (n != NULL) {
                STK[D_800DD190] = n->next;
                n->unk24 = arg0;
                if (arg0 != NULL || arg0[0x3B] == *((u8 *)n + 0x28)) {
                    func_1516972C((struct102 *)n);
                }
                n = STK[D_800DD190];
            }
            D_800DD190--;
            i++;
        lbl:;
        } while (i < 2);
    }
}

struct func_1518BCD0_s {
    u8 pad0[0x10];
    u8 unk10[0x1C];
    s32 unk2C;
    s32 unk30;
};

s32 func_15167A68(s32, s32, s32, s32, s32, s32);

struct func_1518BCD0_s *func_1518BCD0(void *arg0, u8 arg1, s32 arg2) {
    struct func_1518BCD0_s *temp_v0;

    temp_v0 = (struct func_1518BCD0_s *)func_15167A68(0x1F, arg2, 0x44, 1, arg1, 1);
    if (temp_v0 == NULL) {
        return NULL;
    }
    memcpy(temp_v0->unk10, arg0, 0x1C);
    temp_v0->unk2C = func_150ADA20() & 0x1F;
    temp_v0->unk30 = func_150ADA20() & 0x1F;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C0B8.s")

struct func_1518C540_s {
    u8 pad0[0x1B];
    u8 unk1B;
};

s32 func_1518C540(void *arg0) {
    struct func_1518C540_s *p = *(struct func_1518C540_s **)((u8 *)arg0 + 0x98);
    s32 v = *(s16 *)((u8 *)arg0 + 0x1C) * 8;
    u8 b;
    if (v >= 256) {
        v = 255;
    }
    p->unk1B = v;
    b = v;
    if (b < 0) {
        return 0;
    }
    return 1;
}

struct func_1518C57C_s {
    u8 pad0[0x80];
    s32 unk80;
    u8 pad84[0x6];
    s16 unk8A;
    s16 unk8C;
    s16 unk8E;
    s16 unk90;
    s16 unk92;
    s16 unk94;
    s16 unk96;
    s16 unk98;
    u8 pad9A[0x6];
    s8 unkA0;
    s8 unkA1;
    s8 unkA2;
    u8 padA3[0x5];
};

struct func_1518C57C_p {
    f32 x, y, z;
    u8 pad[8];
};

void *func_1516865C();
void *func_15168800();

s32 func_1518C57C(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    struct func_1518C57C_s sp38;
    void *sp34;
    struct func_1518C57C_p *arr;

    sp34 = *(void **)((u8 *)arg0 + 0x98);
    arr = *(struct func_1518C57C_p **)((u8 *)arg0 + 0x94);
    sp38.unk80 = 0;
    sp38.unk8A = 0x100;
    sp38.unk8C = arr[*(s8 *)((u8 *)arg0 + 0x2D)].x;
    sp38.unk8E = arg4;
    sp38.unk90 = arr[*(s8 *)((u8 *)arg0 + 0x2D)].z;
    sp38.unk92 = sp38.unk94 = (u32)func_150ADA20() % 21 + 35;
    sp38.unkA2 = -1;
    sp38.unkA0 = 0x12;
    sp38.unk98 = 0xC;
    sp38.unkA1 = 0;
    sp38.unk96 = arg4;
    func_1516865C(&sp38, 0xFF, 0xFF, 0xFF, 0xFF);
    func_15168800(&sp38, *(u8 *)((u8 *)arg0 + 0xC), *(u8 *)((u8 *)arg0 + 0x1));
    *((u8 *)sp34 + 0x20) = 4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C850.s")
