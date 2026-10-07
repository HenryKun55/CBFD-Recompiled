#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3480.s")

struct func_151D3D50_v {
    f32 x, y, z;
};

struct func_151D3D50_w {
    s16 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_151D3D50_s {
    u8 pad0[0x20];
    struct func_151D3D50_v pos;
    u8 pad2C[0x50 - 0x2C];
    struct func_151D3D50_v base;
    u8 pad5C[0x170 - 0x5C];
    struct func_151D3D50_w w;
};

s32 func_151D3D50(struct func_151D3D50_s *arg0) {
    struct func_151D3D50_w *w = &arg0->w;

    if (w->unk0 > 0) {
        w->unk4 += w->unk8 * D_800BE9A4;
        w->unk4 = func_15144B68(w->unk4);
        arg0->pos.y = sinf(w->unk4) * w->unkC + arg0->base.y;
        w->unk0 -= D_800BE9E4;
    } else {
        arg0->pos = arg0->base;
    }
    return 1;
}

struct func_151D3E04_s {
    u8 pad0[0x14];
    f32 x;
    f32 y;
    f32 z;
    u8 pad20[0x1D4 - 0x20];
    u8 *unk1D4;
};

void func_151D3E04(struct func_151D3E04_s *arg0, f32 *arg1, s32 arg2, u8 arg3, f32 arg4) {
    if (arg0->unk1D4 != NULL) {
        func_15143134(arg2, arg1, arg0->unk1D4 + (arg3 << 6));
    } else {
        arg1[0] = arg0->x;
        arg1[1] = arg0->y + arg4;
        arg1[2] = arg0->z;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3E6C.s")

struct225 *func_151602C0();

void func_151D3F14(f32 *arg0, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = (func_150ADA20() % 3U) + 4;
    header.unk4 = 0;
    header2.unk0 = arg0[0];
    header2.unk4 = arg0[1];
    header2.unk8 = arg0[2];
    func_151602C0(&header, &header2, (func_150ADA20() % 13U) + 20, 0xFF, 0xE8, 0xAB, 0xFF, 0, 0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D40D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D42E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4408.s")

struct func_151D4668_s {
    void *ptr;
    u8 val;
};

void func_151D4668(void *arg0) {
    struct func_151D4668_s sp18;

    sp18.ptr = arg0;
    sp18.val = *((u8 *)arg0 + 0x3B);
    func_151494E0(&sp18, 0x3C);
}

struct func_151D469C_s {
    u8 *ptr;
    u8 unk4;
    s16 unk6;
    u8 unk8;
    f32 unkC;
    u8 unk10;
    u8 pad11[3];
    u8 unk14[0xC];
};

extern void (*D_8008FC70[])(u8 *, s16, void *);
void *memcpy(void *dst, const void *src, size_t size);

void func_151D469C(u8 *arg0, u8 arg1, s16 arg2, u8 arg3, s32 arg4) {
    struct func_151D469C_s sp38;
    struct260 *temp;

    sp38.ptr = arg0;
    sp38.unk4 = arg0[0x3B];
    sp38.unk8 = arg1;
    sp38.unk6 = -1;
    sp38.unkC = 0.0f;
    sp38.unk10 = 0;
    if (arg1 == 6) {
        sp38.unk6 = 0x82;
    }
    if (*(s32 *)(arg0 + 0x1D4) != 0) {
        if ((arg0[0x74] & 0xF) != 0xF) {
            D_8008FC70[arg1](arg0, sp38.unk6, sp38.unk14);
            sp38.unk10 |= 1;
        }
    }
    temp = func_15149130(arg2, -1, 0x41, -1, 1, 0x35, (struct37 *)0x20, arg3, arg4);
    if (temp != NULL) {
        memcpy((u8 *)temp + 0x28, &sp38, 0x20);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4794.s")

struct func_151D4C38_s {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x10 - 0x5];
    u8 unk10;
};

void func_151D4C38(u8 *arg0, struct func_151D4C38_s *arg1, u8 arg2) {
    struct func_151D4C38_s *p = (struct func_151D4C38_s *)(arg0 + 0x28);

    if (arg2 == 0x3C) {
        if (arg1->unk0 == p->unk0 || arg1->unk4 == p->unk4) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 4) {
        if (arg1->unk0 == p->unk0 || arg1->unk4 == p->unk4) {
            u8 *flags = &p->unk10;
            *flags &= ~1;
        }
    } else {
        func_15149514((s32)arg1, arg2, (s32)p, (s32)&p->unk4, (s32)arg0);
    }
}

struct func_151D4D04_s {
    u8 pad0[0x58];
    u8 unk58[0x50];
    s16 unkA8;
    s16 unkAA;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
};

void func_15131828(struct func_151D4D04_s *, s32 *, s16 *, s16 *);
void func_15131958(u8 *, s32);

s32 func_151D4D04(struct func_151D4D04_s *arg0, s32 arg1) {
    s16 *temp = &arg0->unkA8;
    func_15131828(arg0, &arg0->unkAC, temp, &arg0->unkAA);
    func_15131958(arg0->unk58, ((s32 *)temp)[3]);
    return 1;
}

void func_151D4D58(s32 arg0) {
    func_151D469C(arg0, 0, 0x50, 0xFF, 1);
    func_151D469C(arg0, 1, 0x50, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4DAC.s")

struct func_151D5148_s {
    u8  pad0[0x24];
    s16 unk24;
    u8  pad26[0x1AA - 0x26];
    s16 unk1AA;
};

void func_151D5148(struct127 *arg0) {
    if (((struct func_151D5148_s *)arg0->unk31C)->unk24 > 0) {
        ((struct func_151D5148_s *)arg0->unk31C)->unk24--;
    }
    arg0->unk31C->unk1AA++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5174.s")

struct func_151D5334_s {
    vertex pos;
    f32 x;
    f32 y;
    f32 z;
};

void func_15164F0C(u8, u8, s32, u8, s32);

void func_151D5334(vertex *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5, s32 arg6) {
    s32 i;
    struct func_151D5334_s sp3C;

    sp3C.pos = *arg0;
    sp3C.x = arg1;
    sp3C.y = arg2;
    sp3C.z = arg3;
    for (i = 0; i < D_80082FA0 + 1; i++) {
        func_15164F0C(arg4, i, (s32)&sp3C, arg5, arg6);
    }
}

typedef struct {
    f32 x, y, z;
} func_151D5404_vec;

struct func_151D5404_s {
    u8 unk0;
    s16 unk2;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    func_151D5404_vec unk8;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 unk20;
    u8 pad21[7];
};

void func_151D5404(void *arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7) {
    struct func_151D5404_s sp30;
    s32 i;
    void *ret;

    sp30.unk8 = *(func_151D5404_vec *)arg0;
    sp30.unk14 = arg1;
    sp30.unk18 = arg2;
    sp30.unk1C = arg3;
    sp30.unk0 = 1;
    sp30.unk2 = (func_150ADA20() % (u32)(arg5 + 1)) + arg4;
    sp30.unk4 = 0;
    sp30.unk6 = 0;
    for (i = 0; i < D_80082FA0 + 1; i++) {
        sp30.unk5 = 1 << i;
        sp30.unk20 = i;
        ret = func_151D8868(&sp30, 0x1C, 0xFF, 0);
        if (ret != NULL) {
            memcpy((u8 *)ret + 0x18, &sp30.unk8, 0x1C);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5514.s")

void func_151D5514(s32 arg0, u8 arg1, s32 arg2);
void func_151D3FF4(s32 arg0, u8 arg1, s32 arg2);
void func_151541B8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, s32 arg6);

void func_151D5648(s32 arg0, u8 arg1, s32 arg2) {
    func_151D5514(arg0, arg1, arg2);
    func_151D3FF4(arg0, arg1, arg2);
    func_151541B8(arg0, (func_150ADA68() * 4.0f) + 12.0f, 1.6409999f, (u32)((u32)func_150ADA20() % 56 + 200), 0.0f, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D57F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5B6C.s")

void *allocate_memory(s32 size, s32 arg1, s32 arg2, s32 arg3);

void func_151D5D60(s32 *arg0, s16 arg1, s32 arg2, s32 *arg3, u8 *arg4) {
    u8 sp27;

    if (arg4 == NULL) {
        arg4 = &sp27;
    }
    *arg4 = 0;
    if (arg0[arg1] == 0) {
        arg0[arg1] = (s32)allocate_memory(arg2 * 2, 1, 2, 1);
        if (arg0[arg1] == 0) {
            *arg3 = 0;
            return;
        }
        *arg4 = 1;
    }
    *arg3 = arg0[arg1] + (D_800BE9C0 ? 0 : arg2);
}

void func_151D5E30(s32 *arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        if (arg0[i] != 0) {
            func_100043B4(arg0[i], 3);
        }
    }
}
