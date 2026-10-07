#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_1512E4B0_s {
    u8 pad0[0x23D];
    u8 unk23D;
    u8 pad23E[0x2BC - 0x23E];
    f32 unk2BC;
    f32 unk2C0;
    f32 unk2C4;
    u8 pad2C8[0x2F8 - 0x2C8];
    f32 unk2F8;
    f32 unk2FC;
    f32 unk300;
};
extern f32 D_800A3730;

void func_1512E4B0(struct func_1512E4B0_s *arg0) {
    s32 i;
    struct127 *obj;
    s16 angle;
    f32 a;

    i = 0;
    if (arg0->unk23D == 3) {
        i = 1;
    }
    obj = &gObjects[i];
    arg0->unk2BC = obj->x_position;
    arg0->unk2C0 = obj->y_position + 150.0f;
    arg0->unk2C4 = obj->z_position;
    angle = -*(s16 *)&obj->unk2E4;
    angle = angle + obj->unk40 * 10.0f;
    a = angle * D_800A3730 / 1800.0f;
    arg0->unk2F8 = arg0->unk2BC - sinf(a) * 60.0f;
    arg0->unk2FC = arg0->unk2C0;
    arg0->unk300 = arg0->unk2C4 - cosf(a) * 60.0f;
}
