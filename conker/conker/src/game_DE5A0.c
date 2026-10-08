#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DE5A0/func_150B10F0.s")

s32 func_1502178C(struct127 *, s32, s32);
s32 func_150535F4(struct127 *);
void func_15056B08(struct127 *);
extern f32 D_8009F8BC;
extern f32 D_8009F8C0;

void func_150B12FC(struct127 *arg0) {
    s16 pad;
    s16 old;
    f32 diff;

    old = *(s16 *)&arg0->unk76;
    arg0->unk80 = 10;
l0:
    func_15058EA4(arg0, ((s16 *)D_800D2104[arg0->unk13F])[1], 1.0f, ((s16 *)D_800D2104[arg0->unk13F])[1], D_8009F8BC, 12.0f, -16.0f);
    func_15056B08(arg0);
    old -= arg0->unk76;
    diff = (s16)(old * 6) * 0.00390625f - arg0->unkC4;
    if (diff > 6.0f) {
        diff = 6.0f;
    } else if (diff < -6.0f) {
        diff = -6.0f;
    }
    arg0->unk148 += (diff - arg0->unk148) * D_8009F8C0;
    arg0->unkC4 += arg0->unk148;
lbl:
    arg0->unk40 = (s16)(arg0->unk7A + 0x4000) * 0.005493164f;
    func_15059140(arg0);
    if (func_150535F4(arg0) == 0) {
        func_1502178C(arg0, 0, -1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DE5A0/func_150B1484.s")

s32 func_1505A770(struct127 *);
struct127 *func_1505EEB0(s32, s32 *);
extern f32 D_8009F8C4;
extern f32 D_8009F8C8;

void func_150B17DC(struct127 *arg0) {
    s32 sp3C;
    f32 t;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    struct127 *obj;

    obj = func_1505EEB0(10, &sp3C);
    func_15056B08(arg0);
    if (arg0->unk1E5 == 2) {
        arg0->x_position = obj->x_position;
        arg0->z_position = obj->z_position;
        arg0->y_position = obj->y_position + ((s32)arg0->unk21C / 5 + 160.0f);
        arg0->y_velocity = 0.0f;
        arg0->gravity = D_8009F8C4;
        arg0->unk7E = 0;
    } else {
        t = arg0->unk7E;
        t *= D_8009F8C8;
        obj->unkB8 = func_150AD78C(t) * 6.0f;
        func_1505A770(arg0);
        obj->y_position = arg0->y_position - 170.0f;
        obj->unk13C = gCurrentObjectIndex + 100;
        func_1505A184(obj->unk7A, obj->unkB8 * -7.0f, 0.0f, &sp34, &sp30, &sp2C);
        obj->x_position = arg0->x_position + sp34;
        obj->z_position = arg0->z_position + sp30;
        obj->unk7A += D_800BE9A0 << 8;
        arg0->unk7E += D_800BE9A0;
        obj->in_water = 0;
        obj->xz_velocity = 0.0f;
        obj->unk16C = 0.0f;
        obj->unk170 = 0.0f;
    }
    arg0->unk7A = func_1505A630(gObjects->x_position - arg0->x_position, arg0->z_position - gObjects->z_position, 0);
    arg0->unk40 = (s16)(arg0->unk7A + 0x4000) * 0.005493164f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DE5A0/func_150B19E0.s")
