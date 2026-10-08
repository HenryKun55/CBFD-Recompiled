#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s16 func_15063390(struct127 *arg0) {
    return func_1505A630(gObjects[arg0->unk222].x_position - arg0->x_position,
                         arg0->z_position - gObjects[arg0->unk222].z_position, 0);
}

void func_15063404(struct127 *arg0) {
    struct127 *obj = &gObjects[arg0 - gObjects];

    obj->unk31C->unk78 = 9;
    func_15083568(arg0, 0x1D, 0x3F800000, 0);
    func_15083568(arg0, 0x1E, 0x3F800000, 0);
    arg0->disable_jump = 20;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
    *(s16 *)((u8 *)obj->unk31C + 0x24) = 60;
    obj->unk31C->unk11A = 2;
    func_1505E650(arg0, 0x7F, 1.0f, 0.0f, 0.0f, 0.0f, 0);
}

void func_150634E4(struct127 *arg0) {
    gObjects[arg0 - gObjects].unk31C->unk78 = 0;
    gObjects[arg0 - gObjects].unk31C->unk11A = 0;
    func_150836CC(arg0, 0x1D);
    func_150836CC(arg0, 0x1E);
    arg0->disable_jump = 0;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
}

void func_15063570(struct127 *arg0) {
    gObjects[arg0 - gObjects].unk31C->unk78 = 0x3B;
    gObjects[arg0 - gObjects].unk31C->unk11A = 2;
    func_15083568(arg0, 0x89, 0x3F800000, 0);
    arg0->disable_jump = 0x14;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
    func_1505E650(arg0, 0x221, 1.0f, 0.0f, 0.0f, 0.0f, 0);
}

void func_15081690(void *, s32, s32, s32, f32, f32, f32, void *, f32, s32, s32, s32, s32, s32, s32);
void func_150636A4(void *);

void func_15063628(void *arg0, f32 arg1) {
    char *temp_v0 = *(char **)((char *)arg0 + 0x31C);

    func_15081690(arg0, *(s32 *)(temp_v0 + 0x13C), *(s32 *)(temp_v0 + 0x140), *(s32 *)(temp_v0 + 0x144),
                  *(f32 *)(temp_v0 + 0x130), *(f32 *)(temp_v0 + 0x134), *(f32 *)(temp_v0 + 0x138),
                  temp_v0 + 0xB0, arg1, 0, 0, 0, -1, 0, 0);
    func_150636A4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636F0.s")

extern s16 D_800CC2B2;
s16 func_15063390(struct struct127 *arg0);

s16 func_150639BC(struct struct127 *arg0) {
    D_800CC2B2 = (arg0->unk7A - arg0->unk31C->unk12) - func_15063390(arg0);
    if (D_800CC2B2 > 0x3E80) {
        D_800CC2B2 = 0x3E80;
    }
    if (D_800CC2B2 < -0x3E80) {
        D_800CC2B2 = -0x3E80;
    }
    return D_800CC2B2;
}

extern f32 D_800CC2B4;

s32 func_15063A38(struct127 *arg0, s32 arg1, s32 arg2) {
    if (arg1 & arg2) {
        D_800CC2B2 = ((s8 *)D_800CC284)[2] * 200;
        if (arg0->unk31C->unk84) {
            D_800CC2B2 = func_150639BC(arg0);
        }
        D_800CC2B4 = 12.0f;
        D_800CC2B2 = arg0->unk31C->unk12 + (D_800CC2B2 * D_800CC264) / 2000;
        if (D_800CC2B2 < -9000) {
            arg0->unk76 = arg0->unk7A = arg0->unk7A - D_800CC2B2 - 9000;
            D_800CC2B2 = -9000;
        }
        if (D_800CC2B2 > 9000) {
            arg0->unk76 = arg0->unk7A = arg0->unk7A - D_800CC2B2 + 9000;
            D_800CC2B2 = 9000;
        }
        arg0->unk31C->unk12 = D_800CC2B2;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063C60.s")

s32 func_15063E84(struct struct127 *arg0, u16 arg1, u16 arg2, s32 arg3, s32 arg4) {
    if ((arg4 & 0x4000) && (0.0f == arg0->unk28) && (arg0->y_velocity <= 0.0f) &&
        (*(u8 *)&arg0->unk31C->unk95 == 0) && (arg0->unk84.uh != arg1) &&
        ((arg0->unk31C->unk11A == 0) || (arg0->unk31C->unk11A == 2)) && (arg0->unk31C->unk27 == 0)) {
        if (arg3 && arg0->disable_jump) {
            return 999;
        }
        if (arg2 & 1) {
            arg0->disable_jump = 20;
        }
        if (arg3) {
            if (arg0->unk31C->unk11A == 2) {
                return 999;
            }
            arg0->unk31C->unk11A = 1;
        } else {
            arg0->unk31C->unk11A = 3;
        }
        arg0->unk31C->unk78 = arg3;
        arg0->disable_run = 0xFF;
        arg0->unk83 = 0xFF;
        return arg1;
    }
    return 999;
}

extern f32 D_80099790;
extern f32 D_80099794;
extern f32 D_80099798;
extern f32 D_8009979C;

struct func_15063FA0_s {
    u8 pad0[0xB8];
    f32 unkB8;
    f32 unkBC;
    f32 unkC0;
    u8 padC4[0x109 - 0xC4];
    u8 unk109;
    u8 pad10A[0x13C - 0x10A];
    f32 unk13C;
    f32 unk140;
    f32 unk144;
    u8 pad148[0x16C - 0x148];
    f32 unk16C;
    f32 unk170;
};

void func_15063FA0(struct127 *arg0, s32 arg1) {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 dist;
    f32 pos[3];
    f32 off[2];
    f32 dy;
    f32 dz;
    f32 a;
    f32 xr;
    f32 yr;
    f32 dx;
    struct func_15063FA0_s *s;
    f32 dz2;
    f32 dy2;

    dist = 300.0f;
    dy = 0.0f;
    dz = 0.0f;
    switch (arg1) {
    case 2:
        dz = 27.0f;
        break;
    case 3:
    case 6:
        dy = -11.0f;
        dist = 500.0f;
        break;
    }
    a = ((struct func_15063FA0_s *)arg0->unk31C)->unk16C * D_80099790;
    off[0] = sinf(a) * dz;
    off[1] = cosf(a) * dz;
    pos[0] = ((struct func_15063FA0_s *)arg0->unk31C)->unk13C + off[0];
    pos[1] = ((struct func_15063FA0_s *)arg0->unk31C)->unk140 + dy;
    pos[2] = ((struct func_15063FA0_s *)arg0->unk31C)->unk144 + off[1];
    s = (struct func_15063FA0_s *)arg0->unk31C;
    if (s->unk109 == 0) {
        xr = -s->unk170;
        yr = s->unk16C + 90.0f;
    } else {
        dx = s->unkB8 - pos[0];
        dy2 = s->unkBC - pos[1];
        dz2 = s->unkC0 - pos[2];
        xr = func_150484A0(dy2, sqrtf(dx * dx + dz2 * dz2)) * D_80099794;
        yr = func_150484A0(dx, dz2) * D_80099798;
    }
    func_1505A184((s16)(xr * D_8009979C) & 0xFFFF, dist, 0.0f, &sp84, &sp80, &sp7C);
    sp80 = -sp80;
    func_1506C460(yr, sp84, sp80, 0.0f, 100, arg1, 0.0f, 0.5f, (s32)pos, 1, 1);
}

s32 func_1505DADC(struct127 *, u16 *, s32, s32, s32);

s32 func_150641D8(struct127 *arg0, u16 arg1, u16 arg2, u16 arg3) {
    u16 ret = arg1;
    s32 a;
    u16 sp26 = 0;

    if (func_150ADA20() & 1) {
        ret = arg2;
    }
    if (arg0->unk84.uh == arg1 || arg0->unk84.uh == arg2) {
        if (arg0->unk107 < 40) {
            return 999;
        }
        ret = arg3;
    }
    if (arg0->unk84.uh == arg3) {
        ret = 999;
    }
    if (func_1505DADC(arg0, &sp26, 0, 0xFE, 0x40) != 0xFF) {
        arg0->unk76 = sp26;
    }
    arg0->unk83 = 0xFF;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150642AC.s")

void func_150649A0(s32 arg0, s32 arg1) {
    struct197 *a = gObjects[arg1].unk2D0;
    struct197 *b = gObjects[arg0].unk2D0;

    if ((a != NULL) && (b != NULL)) {
        a->unk8 = b->unk8;
        if (a->unk18 <= a->unk8) {
            a->unk8 = a->unk18 - 1.0f;
        }
    }
}

void func_15064A14(struct127 *arg0) {
    struct127 *obj = &gObjects[arg0->unk65 - 1];
    s32 flag;
    s32 snd = 0xF;

    if (obj->id == 0xC) {
        snd = 0x5A;
        if (obj->unk84.uh == 0xC) {
            snd = 0x5B;
        } else if (obj->unk84.uh == 0xD) {
            snd = 0x5C;
        }
    } else if (obj->id == 0x53) {
        snd = 0x8C;
        if (obj->unk84.uh == 0xB) {
            snd = 0xA2;
        } else if (obj->unk84.uh == 0xD) {
            snd = 0xA3;
        }
    } else if (obj->id == 0x21) {
        snd = 0x169;
    } else if (obj->id == 0x8A) {
        if (arg0->unk31C != NULL && *((u8 *)arg0->unk31C + 0x1B2) != 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        if (obj->unk232 == 4) {
            if (flag) {
                snd = 0x350;
            } else {
                snd = 0x1A4;
            }
        } else if (flag) {
            snd = 0x34F;
        } else {
            snd = 0x1A1;
        }
    }
    func_1505E650(arg0, snd, 1.0f, 6.0f, 0.0f, 0.0f, 0);
    func_150649A0(arg0->unk65 - 1, gCurrentObjectIndex);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15065A5C.s")
