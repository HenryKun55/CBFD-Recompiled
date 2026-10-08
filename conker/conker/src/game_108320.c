#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DAE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB114.s")

struct func_150DB2D8_s {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0xC0 - 0x4C];
    u8 unkC0[0x40];
    Vtx *unk100[1];
};

Vtx *func_150DB2D8(struct func_150DB2D8_s *arg0, s16 arg1) {
    Vtx *vtx;
    Vtx *ret;
    f32 sx;
    f32 sz;
    u8 flag;

    func_151D5D60(arg0->unk100, arg1, 0x40, &vtx, &flag);
    ret = vtx;
    if (ret != NULL) {
        if (flag) {
            memcpy(arg0->unk100[arg1], arg0->unkC0, 0x40);
            memcpy((u8 *)arg0->unk100[arg1] + 0x40, arg0->unkC0, 0x40);
        }
    } else {
        return NULL;
    }
    sx = arg0->unk2C * arg0->unk40;
    sz = -arg0->unk2C * arg0->unk48;
    vtx[0].v.ob[0] = arg0->unk34 + sx;
    vtx[0].v.ob[1] = arg0->unk38 + arg0->unk30;
    vtx[0].v.ob[2] = arg0->unk3C + sz;
    vtx[0].v.flag = 0;
    vtx[1].v.ob[0] = arg0->unk34 + sx;
    vtx[1].v.ob[1] = arg0->unk38 - arg0->unk30;
    vtx[1].v.ob[2] = arg0->unk3C + sz;
    vtx[1].v.flag = 0;
    vtx[2].v.ob[0] = arg0->unk34 - sx;
    vtx[2].v.ob[1] = arg0->unk38 - arg0->unk30;
    vtx[2].v.ob[2] = arg0->unk3C - sz;
    vtx[2].v.flag = 0;
    vtx[3].v.ob[0] = arg0->unk34 - sx;
    vtx[3].v.ob[1] = arg0->unk38 + arg0->unk30;
    vtx[3].v.ob[2] = arg0->unk3C - sz;
    vtx[3].v.flag = 0;
    return ret;
}

struct func_150DB518_s {
    u8 unk0;
    u8 pad1;
    s16 unk2;
    s16 unk4;
    s16 pad6;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 pad14[0x40 - 0x14];
    s32 unk40;
    u8 unk44;
    u8 unk45;
    u8 pad46[0x58 - 0x46];
};

void func_150DB518(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, u8 arg6, s32 arg7) {
    struct func_150DB518_s sp38;
    void *temp_v0;

    if ((arg0 != 0) && (arg1 != 0) && (arg2 != 0) && (arg3 != 0) && (arg4 != 0) && (arg5 != 0)) {
        sp38.unk0 = 0x17;
        sp38.unkC = 0x243A;
        sp38.unk40 = 0x401;
        sp38.unk44 = 0xFF;
        sp38.unk8 = 0;
        sp38.unk4 = arg5;
        sp38.unk45 = 0xFF;
        sp38.unk12 = 0xC8; sp38.unk11 = 0xC8; sp38.unk10 = 0xC8;
        sp38.unk13 = 0xC8;
        sp38.unk2 = 0x401;
        temp_v0 = func_1513D524((s32)&sp38, 0, 0xA, 0, 8, 0, 0x14, arg6, arg7);
        if (temp_v0 != NULL) {
            *(s32 *)((char *)temp_v0 + 0x110) = arg0;
            *(s32 *)((char *)temp_v0 + 0x114) = arg1;
            *(s32 *)((char *)temp_v0 + 0x118) = arg2;
            *(s32 *)((char *)temp_v0 + 0x11C) = arg4;
            *(s32 *)((char *)temp_v0 + 0x120) = arg3;
        }
    }
}

struct func_150DB630_s {
    u8 pad0[0x5C];
    u8 unk5C;
    u8 pad5D[0x120 - 0x5D];
    f32 *volatile unk120;
};

s32 func_150DB630(struct func_150DB630_s *arg0) {
    f32 temp;

    if (*arg0->unk120 > 255.0f) {
        arg0->unk5C = 255;
    } else if ((temp = *arg0->unk120) < 0.0f) {
        arg0->unk5C = 0;
    } else {
        arg0->unk5C = temp;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB714.s")
