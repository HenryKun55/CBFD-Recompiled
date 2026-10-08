#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct func_15155780_s {
    char pad0[0x10];
    u8 unk10;
    u8 unk11;
    char pad12[2];
    s32 unk14;
    char pad18[0x80];
    f32 unk98;
};

struct func_15155780_s *func_15167A68(s32, s32, s32, s32, s32, s32);
void func_1518C900(s32);

struct func_15155780_s *func_15155780(s32 arg0, s32 arg1) {
    struct func_15155780_s *temp_v0;

    temp_v0 = func_15167A68(0x50, 0, 0xA0, 1, arg1, 1);
    if (temp_v0 == NULL) {
        return temp_v0;
    }
    temp_v0->unk10 = arg0;
    temp_v0->unk11 = 0;
    temp_v0->unk14 = 0;
    temp_v0->unk98 = 0.0f;
    func_1518C900(0xA6);
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_151557FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_1515589C.s")

Gfx *func_15096934(Gfx *gfx);
extern Gfx **D_800E03E0;

struct func_15155CFC_s {
    char pad0[0x10];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    char pad13[5];
    Mtx unk18[2];
    f32 unk98;
};

Gfx *func_15155CFC(Gfx *gfx, struct func_15155CFC_s *arg1, s16 arg2) {
    struct127 *obj;
    u8 type;
    f32 sp5C;
    u8 idx;
    f32 sp54;

    type = arg1->unk11;
    idx = arg1->unk10;
    if ((type == 1) || (type == 3)) {
        obj = &gObjects[idx];
        if (obj->unk31C->unk75 == 5) {
            sp54 = 85.0f;
        } else {
            sp54 = 0.0f;
        }
        sp5C = D_800DBFF0[arg2].unk380;
        gfx = func_15096934(gfx);
        func_15043D90(&arg1->unk18[D_800BE9C0], 0.0f, sp5C, 0.0f, 2.25f, 2.25f, 2.25f,
                      obj->x_position,
                      obj->y_position + 160.0f + sp54 + arg1->unk98 + func_15048A40(arg1->unk12) * 15.0f,
                      obj->z_position);
        gSPMatrix(gfx++, &arg1->unk18[D_800BE9C0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPClearGeometryMode(gfx++, G_ZBUFFER);
        gSPDisplayList(gfx++, *D_800E03E0);
        gSPSetGeometryMode(gfx++, G_ZBUFFER);
    }
    return gfx;
}

void func_1515F10C(void *);
void func_1518CA04(s32);

void func_15155EF8(u8 *arg0) {
    u8 *p = arg0;
    if (*(void **)(p + 0x14) != NULL) {
        func_1515F10C(*(void **)(p + 0x14));
    }
    func_15169804(p);
    func_1518CA04(0xA6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155F3C.s")

struct func_15155F90_s {
    u8 pad[0x11];
    u8 unk11;
};
struct func_15155F90_s *func_15155FD4(u8 arg0);

void func_15155F90(void) {
    struct func_15155F90_s *p = func_15155FD4(gCurrentObjectIndex);
    if (p != NULL) {
        if (p->unk11 == 3) {
            p->unk11 = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155FD4.s")

struct func_15156028_s {
    u8 pad[0x10];
    u8 unk10;
};

void func_15156028(struct func_15156028_s *arg0, struct127 **arg1, u8 arg2) {
    if (arg2 == 0) {
        s32 a = arg1[0] - gObjects;
        if (a >= 0 && a < 25 && a == arg0->unk10) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        s32 a = arg1[0] - gObjects;
        s32 b = arg1[1] - gObjects;
        if (a >= 0 && a < 25 && b >= 0 && b < 25) {
            if (a == arg0->unk10) {
                arg0->unk10 = b;
            } else if (b == arg0->unk10) {
                arg0->unk10 = a;
            }
        }
    }
}
