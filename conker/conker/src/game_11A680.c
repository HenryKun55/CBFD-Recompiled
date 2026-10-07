#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 func_15144BC8(f32);

f32 func_150ED1D0(f32 arg0, f32 arg1) {
    f32 d;

    arg0 = func_15144BC8(arg0);
    d = func_15144BC8(func_15144BC8(arg1) - arg0);
    if (d > 180.0f) {
        d = -360.0f + d;
    }
    return d;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED298.s")

void func_150ED578(struct127 *arg0) {
    struct127 *obj;
    struct108 *cam;
    u8 id;

    if ((arg0->unk31C != NULL) && (*(u8 *)((u8 *)arg0->unk31C + 0x84) == 0)) {
        if (D_800BE616 != 0) {
            id = arg0->unk127;
        } else {
            id = arg0->unk124;
        }
        if (*(u16 *)(((s32 **)D_800BE728)[0][id]) & 0x10) {
            obj = &gObjects[id];
            if (*((u8 *)obj->unk31C + 0x197) != 0) {
                cam = obj->camera;
                if (cam != NULL) {
                    arg0->pad2FC[0] |= (1 << cam->unk23D);
                }
            }
        }
    }
}

struct func_150ED638_s {
    u8 pad0[4];
    u8 unk4;
};

extern void func_15062FC0(struct func_150ED638_s *, s32, s32, s32, s32, s32, s32, s32);

void func_150ED638(struct func_150ED638_s *arg0, s32 arg1, s32 arg2) {
    s32 tmp;
    s32 s0;

    arg1 = (arg1 < -45) ? -45 : (arg1 > 45) ? 45 : arg1;
    arg2 = (arg2 < -45) ? -45 : (arg2 > 45) ? 45 : arg2;
    if (arg0->unk4 == 40) {
        s0 = 0x7C;
    } else {
        tmp = arg1;
        arg1 = arg2;
        s0 = 0x1C;
        arg2 = tmp;
    }
    func_15062FC0(arg0, 0, 0, 0x800, 0x800, s0, -arg2 * 7, 0);
    func_15062FC0(arg0, 1, s0, 0x800, 0x800, s0, -arg1 * 7, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED748.s")

struct func_150EEC84_s {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[0xE4 - 6];
    s16 unkE4;
    u8 padE6[0x125 - 0xE6];
    u8 unk125;
    u8 pad126[0x318 - 0x126];
    u8 *unk318;
    u8 *unk31C;
    u8 pad320[0x328 - 0x320];
    u8 unk328;
};
void func_151254F4(void *arg0, s32 arg1);
void func_1517F488(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_150EEC84(struct func_150EEC84_s *arg0) {
    u8 *p;
    u8 *obj;
    s32 idx;

    arg0->unk5 = 3;
    arg0->unkE4 = 0;
    arg0->unk125 = 0xFF;
    arg0->unk328 = 0;
    if (arg0->unk318 != NULL) {
        p = arg0->unk318;
        idx = 0;
        if (p[0x23D] == 3) {
            idx = 1;
        }
        func_151254F4(p, idx);
        arg0->unk31C[0x78] = 0x29;
        *(u16 *)((u8 *)D_800BE748 + idx * 6) &= 0xFFEF;
        obj = (u8 *)&gObjects[idx];
        obj[0x2FC] |= 1 << p[0x23D];
        if (obj[0x10A] != 0) {
            func_1517F488(0xFF, 0, 0, 0xB4, 0x14, p[0x23D]);
            obj[0x10A] = 0;
        }
    }
}

struct func_150EEDA8_s {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[0xE4 - 6];
    s16 unkE4;
    u8 padE6[0x125 - 0xE6];
    u8 unk125;
};
void func_151045E0(struct func_150EEDA8_s *arg0, s32 arg1, f32 arg2);
void *func_15052590();

void func_150EEDA8(struct func_150EEDA8_s *arg0) {
    if (arg0->unk5 != 3) {
        func_151045E0(arg0, 0xF, 250.0f);
        arg0->unk5 = 3;
        arg0->unkE4 = 0;
        arg0->unk125 = 0xFF;
    }
    func_15052590(arg0);
}
