#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15189900_s {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 pad30[0x30];
    s16 unk60;
    f32 unk64;
    f32 unk68;
    s32 unk6C;
    u8 unk70;
};
void *func_15167A68(s32, s32, s32, s32, s32, s32);

void func_15189900(void *arg0, u8 arg1) {
    struct func_15189900_s *obj;
    f32 f;
    u8 v;

    obj = func_15167A68(0x1A, 1, 0x78, 1, 0xFF, 1);
    if (obj != NULL) {
        memcpy((u8 *)obj + 0x10, arg0, 0x50);
        func_1510F800(0);
        obj->unk6C = (s32)func_1510FD20((s32)(obj->unk18 + obj->unk24 * 0.5f), (s32)(obj->unk20 + obj->unk2C * 0.5f));
        v = arg1 ? 1 : 0;
        f = obj->unk28;
        obj->unk70 = v;
        obj->unk60 = 0;
        obj->unk64 = 0.0f;
        if (f < 0.0f) {
            obj->unk68 = obj->unk1C + f;
        } else {
            obj->unk68 = obj->unk1C;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B6DB0/func_15189A00.s")

extern f64 D_800A73A8;
extern f32 D_800A73B0;
s32 func_151D8E20();

struct func_15189EBC_s {
    f32 x, y, z;
    s32 unk_C[2];
};

s32 func_15189EBC(u8 *arg0) {
    u8 temp_a0;
    f32 temp_f10;
    u8 *temp_s1;
    struct func_15189EBC_s *temp_v0;
    f32 sp34[3];

    temp_v0 = *(struct func_15189EBC_s **)(arg0 + 0x94);
    temp_s1 = *(u8 **)(arg0 + 0x98);
    if (temp_v0[*(s8 *)(arg0 + 0x2D)].y < *(f32 *)(temp_s1 + 0x48)) {
        if (func_150ADA68() < D_800A73A8) {
            sp34[0] = temp_v0[*(s8 *)(arg0 + 0x2D)].x;
            sp34[1] = *(f32 *)(temp_s1 + 0x48);
            sp34[2] = temp_v0[*(s8 *)(arg0 + 0x2D)].z;
            temp_a0 = func_151D8E20();
            func_151DBCBC(temp_a0, *(f32 *)(temp_s1 + 0) * 6.0f, *(u8 *)(temp_s1 + 0x1B), 0, sp34, *(u8 *)(arg0 + 0xC), *(u8 *)(arg0 + 1));
        }
        *(u8 *)(temp_s1 + 0x20) = 4;
        *(f32 *)(temp_s1 + 0x48) = D_800A73B0;
    }
    return 1;
}

s32 func_15189FD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 1;
}
