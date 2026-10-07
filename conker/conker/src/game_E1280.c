#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15147D64(void *arg0, u8 arg1);

void func_150B3DD0(void) {
    u8 sp24[4];

    func_15147D64(NULL, 5);
    sp24[0] = 0;
    func_151494E0((s32)sp24, 0x18);
    sp24[0] = 2;
    func_151494E0((s32)sp24, 0x18);
    sp24[0] = 4;
    func_151494E0((s32)sp24, 0x18);
    sp24[0] = 1;
    func_151494E0((s32)sp24, 0x18);
    sp24[0] = 3;
    func_151494E0((s32)sp24, 0x18);
    sp24[0] = 5;
    func_151494E0((s32)sp24, 0x18);
}

void func_1000FC18(s32, s16, s16, s16, s32);
void func_151478F4(void *);

void func_150B3E74(void *arg0) {
    func_1000FC18(0x221, (s16)*(f32 *)((char *)arg0 + 0x10), (s16)*(f32 *)((char *)arg0 + 0x14), (s16)*(f32 *)((char *)arg0 + 0x18), 0xFA0);
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3EE8.s")

typedef struct { f32 x, y, z; } func_150B3F5C_v;
struct func_150B3F5C_a {
    func_150B3F5C_v pos;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    s32 unk18;
};
struct func_150B3F5C_b {
    u8 unk0[0x40];
    f32 unk40;
    f32 unk44;
    u8 unk48;
    f32 unk4C;
    u8 unk50;
    f32 unk54;
};

extern void *func_15147A80();

void *func_150B3F5C(u8 *arg0, func_150B3F5C_v *arg1, s16 arg2) {
    struct func_150B3F5C_a a;
    struct func_150B3F5C_b b;
    void *ret;

    memcpy(&b, arg0, 0x40);
    b.unk48 = 0;
    b.unk44 = 0.0f;
    a.unk15 = arg2;
    a.unkE = 2;
    a.unkC = 500;
    b.unk4C = *(f32 *)(arg0 + 0x18) + *(f32 *)(arg0 + 0x14);
    b.unk50 = 0;
    b.unk54 = 0.0f;
    b.unk40 = b.unk4C;
    a.pos = *arg1;
    a.unk10 = 9;
    ret = func_15147A80(&a, 0x58, 0x24, 7, 7, 7, 0, 0, 0, 0xFF, 1);
    if (ret != NULL) {
        func_1000FA64(0x221, arg1->x, arg1->y, arg1->z, 0x61A8, 0xFA0, 0x258, func_1000EF40, 0, 0, 8, func_150ADA20() & 0x40);
        memcpy(*(void **)((u8 *)ret + 0x98), &b, 0x58);
    }
    return ret;
}

typedef struct { f32 x, y, z; } func_150B40E8_v3;

struct func_150B40E8_e {
    func_150B40E8_v3 pos;
    f32 vx, vy, vz;
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
};

struct func_150B40E8_b {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10[0xC];
    u8 unk1C;
    u8 pad1D[0xB];
    f32 unk28;
};

struct func_150B40E8_s {
    u8 pad0[0x25];
    u8 unk25;
    u8 pad26[6];
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 pad2F[0x25];
    func_150B40E8_v3 unk54;
    u8 pad60[0x34];
    struct func_150B40E8_e *unk94;
    struct func_150B40E8_b *unk98;
};

s32 func_150B40E8(struct func_150B40E8_s *arg0) {
    struct func_150B40E8_b *b = arg0->unk98;
    struct func_150B40E8_e *arr = arg0->unk94;
    s32 i;
    s32 flag;

    if (arg0->unk2C < 2 && (b->unk1C & 1)) {
        return 0;
    }
    i = arg0->unk2E;
    while (i != arg0->unk2D) {
        i--;
        flag = 0;
        if (i < 0) {
            i = arg0->unk25 - 1;
        }
        arr[i].unk1C = 0xFF;
        arr[i].unk1E -= D_800BE9E4;
        if (arr[i].unk1E < 0) {
            flag = 1;
        }
        arr[i].vy += b->unkC * D_800BE9A4;
        arr[i].pos.x += arr[i].vx * D_800BE9A4;
        arr[i].pos.y += arr[i].vy * D_800BE9A4;
        arr[i].pos.z += arr[i].vz * D_800BE9A4;
        arr[i].unk18 += b->unk28 * D_800BE9A4;
        if (flag) {
            while (i != arg0->unk2D) {
                arg0->unk2D++;
                if (arg0->unk2D == arg0->unk25) {
                    arg0->unk2D = 0;
                }
                arg0->unk2C--;
            }
        }
    }
    if (arg0->unk2C > 0) {
        arg0->unk54 = arr[arg0->unk2D].pos;
    } else {
        arg0->unk54.x = 0.0f;
        arg0->unk54.y = 0.0f;
        arg0->unk54.z = 0.0f;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4710.s")

struct func_150B5060_s {
    u8 pad0[0x1C];
    u8 unk1C;
    u8 pad1D;
    u16 unk1E;
    u8 pad20[0x10];
    u8 unk30;
    u8 pad31[0x98 - 0x31];
    struct func_150B5060_s *unk98;
};

void func_150B5060(struct func_150B5060_s *arg0) {
    arg0->unk30 = 0;
    arg0->unk1E &= ~2;
    arg0->unk98->unk1C |= 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B5088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B538C.s")
