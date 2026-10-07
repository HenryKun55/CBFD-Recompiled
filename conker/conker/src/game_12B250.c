#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FDDA0.s")

extern u8 D_80088B80;
typedef struct { f32 x, y, z; } func_150FDF38_v;
struct func_150FDF38_s {
    u8 pad0[0x14];
    func_150FDF38_v pos;
    u8 pad20[0x1D4 - 0x20];
    u8 *unk1D4;
};
extern s32 D_800A1F70;
extern s32 D_800A1F88;

extern void func_15145EA4(void *, void *, void *, s32);
extern void func_151D3E6C(struct func_150FDF38_s *, func_150FDF38_v *, func_150FDF38_v *, s32);
extern void func_151D3F14(func_150FDF38_v *, u8, s32);
extern void func_150FE0B8(struct func_150FDF38_s *, func_150FDF38_v *, u8, s32);
extern void func_150FE288(struct func_150FDF38_s *);

void func_150FDF38(struct func_150FDF38_s *arg0, u8 arg1, s32 arg2, func_150FDF38_v *arg3, func_150FDF38_v *arg4) {
    func_150FDF38_v sp44;
    func_150FDF38_v sp38;
    void *sp30[2];
    void *sp28[2];

    if (arg0 != NULL) {
        if (arg0->unk1D4 != NULL) {
            sp30[0] = &D_800A1F70;
            sp30[1] = &D_800A1F88;
            sp28[0] = &sp44;
            sp28[1] = &sp38;
            func_15145EA4(sp30, sp28, arg0->unk1D4 + (D_80088B80 << 6), 2);
        } else {
            sp44.x = arg0->pos.x;
            sp44.y = arg0->pos.y + 56.0f;
            sp44.z = arg0->pos.z;
            sp38 = sp44;
        }
        func_151D3E6C(arg0, &sp44, &sp38, (D_800BE9F0 == 0x2B) ? 40 : 30);
        func_151D3F14(&sp44, arg1, arg2);
        func_150FE0B8(arg0, &sp44, arg1, arg2);
        func_150FE288(arg0);
        if (arg3 != NULL) {
            *arg3 = sp44;
        }
        if (arg4 != NULL) {
            *arg4 = sp38;
        }
    }
}

extern s32 D_800A1F7C;
extern f32 D_800A1F9C;
extern f32 D_800A1FA0;
extern f32 D_800A1FA4;
void func_15102B38(struct func_150FDF38_s *, u8, s32 *, s32 *, f32 *, s32, s32, f32, func_150FDF38_v *, u8, s32, s32, u8, s32);

void func_150FE0B8(struct func_150FDF38_s *arg0, func_150FDF38_v *arg1, u8 arg2, s32 arg3) {
    f32 sp60[2];
    u8 sp5F;
    s32 pad;
    u32 sp54;
    u32 sp50;
    u8 *temp_v0;

    if (arg0->unk1D4 != NULL && (*((u8 *)arg0 + 0x74) & 0xF) != 0xF) {
        sp60[1] = (func_150ADA68() * 1.5f) + 2.0f;
        sp60[0] = (func_150ADA68() * D_800A1F9C) + D_800A1FA0;
        if ((temp_v0 = *(u8 **)((u8 *)arg0 + 0x31C)) != NULL && temp_v0[0x197] != 0
            && (temp_v0 = *(u8 **)((u8 *)arg0 + 0x318)) != NULL) {
            sp5F = ~(1 << temp_v0[0x23D]) & 0xFF;
        } else {
            sp5F = 0xFF;
        }
        sp50 = func_150ADA20();
        sp54 = func_150ADA20();
        func_15102B38(arg0, D_80088B80, &D_800A1F70, &D_800A1F7C, sp60, (sp50 % 5) + 6, (sp54 % 101) + 0x9B,
                      (func_150ADA68() * 199.0f) + D_800A1FA4, arg1, sp5F, 0, -1, arg2, arg3);
    }
}

extern u8 D_80088B80;
extern s32 D_800A1F70;
void func_151D3E04(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 arg4);

void func_150FE248(void *arg0, s32 arg1, s32 arg2) {
    func_151D3E04(arg0, arg2, &D_800A1F70, D_80088B80, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FE288.s")
