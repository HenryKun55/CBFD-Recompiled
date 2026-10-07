#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_A9260/func_1507BDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9260/func_1507C22C.s")

struct func_1507C324_s {
    u8 pad0[8];
    f32 unk8;
    u8 padC[0xC];
    f32 unk18;
};

void func_1507C324(u8 *arg0, u8 *arg1) {
    struct func_1507C324_s *a = *(struct func_1507C324_s **)(arg0 + 0x2D0);
    struct func_1507C324_s *b = *(struct func_1507C324_s **)(arg1 + 0x2D0);
    f32 tmp;

    if (a != NULL && b != NULL) {
        a->unk8 = b->unk8;
        tmp = a->unk18 - 1.0f;
        if (tmp <= a->unk8) {
            a->unk8 = tmp;
        }
    }
}

void func_1507C370(void) {
    struct127 *obj = gObjects;
    s32 i;

    for (i = 0; i < D_8008FD8C; i++, obj++) {
        if (obj->unk31C != NULL) {
            func_1507C3E0(obj, (u8 *)obj->unk31C + 0x114, (u8 *)obj->unk31C + 0x116, (u8 *)obj->unk31C + 0x118);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9260/func_1507C3E0.s")
