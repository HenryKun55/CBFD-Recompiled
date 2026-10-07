#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_150121C0_s {
    f32 unk0[20];
    s32 unk50;
    s16 unk54;
    s16 unk56;
    u8 unk58;
    void *unk5C;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    s32 unk6C;
    u8 unk70;
    s16 unk72;
    s16 unk74;
};

struct func_150121C0_r {
    u8 pad0[0x90];
    Mtx unk90[2];
    u8 pad110[0x60];
    s32 unk170;
};

void *func_15132A4C(void *, s32, s32, s32, s32, s32);
extern Mtx D_80089470;

void func_150121C0(s32 arg0) {
    static const f32 pos[3] = { -21.0f, 1631.0f, -1535.0f };
    struct func_150121C0_r *ret;
    u8 i;
    struct func_150121C0_s s;
    s32 sp34;

    s.unk0[0] = 1.0f;
    s.unk0[1] = 1.0f;
    s.unk0[2] = 1.0f;
    s.unk0[3] = 1.0f;
    s.unk0[4] = 0.0f;
    s.unk0[5] = 0.0f;
    s.unk0[6] = 0.0f;
    s.unk0[7] = 1.0f;
    s.unk0[8] = 1.0f;
    s.unk0[9] = 1.0f;
    s.unk0[10] = 0.0f;
    s.unk0[11] = 0.0f;
    s.unk0[12] = 0.0f;
    s.unk0[13] = 0.0f;
    s.unk0[14] = 0.0f;
    s.unk0[15] = 0.0f;
    s.unk0[16] = 0.0f;
    s.unk0[17] = 0.0f;
    s.unk0[18] = 0.0f;
    s.unk0[19] = 0.0f;
    s.unk50 = 0xC0500;
    s.unk54 = 0x12C;
    s.unk56 = 0x21;
    sp34 = arg0;
    s.unk58 = 0;
    func_1510F800(0);
    s.unk5C = func_1510FD20((s32)pos[0], (s32)pos[2]);
    s.unk60 = 0xFF;
    s.unk61 = 0;
    s.unk62 = 6;
    s.unk63 = 0;
    s.unk64 = 0;
    s.unk65 = 0;
    s.unk66 = 0;
    s.unk67 = 0;
    s.unk68 = 3;
    s.unk6A = 0;
    s.unk6C = 0;
    s.unk70 = 0;
    s.unk72 = 1;
    s.unk74 = 0xFF;
    ret = func_15132A4C(&s, 0, 0, 4, 0xFF, 1);
    if (ret != NULL) {
        memcpy(&ret->unk170, &sp34, 4);
        for (i = 0; i < 2; i++) {
            memcpy(&ret->unk90[i], &D_80089470, 0x40);
        }
    }
}
