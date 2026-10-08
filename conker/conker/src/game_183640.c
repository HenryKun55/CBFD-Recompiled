#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156190.s")

void *func_15156190(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4);

void *func_15156388(void *arg0, u8 arg1, s32 arg2) {
    return func_15156190(arg0, arg1, arg2, 0xFF, 0);
}

struct func_151563B8_s {
    u8 pad0[0x10];
    f32 pos[3];   /* 0x10 */
    f32 vel[3];   /* 0x1C */
    f32 b[3];     /* 0x28 */
    f32 bv[3];    /* 0x34 */
    u8 flags;     /* 0x40 */
    u8 pad41;
    s16 timer;    /* 0x42 */
    u8 pad44[8];
    u8 unk4C;     /* 0x4C */
    u8 pad4D;
    s16 unk4E;    /* 0x4E */
    s16 unk50;    /* 0x50 */
};

void func_151563B8(struct func_151563B8_s *arg0) {
    s32 done = 0;
    s32 t;
    s16 v;

    if (arg0->flags & 1) {
        arg0->timer -= D_800BE9E4;
        if (arg0->timer < 0) {
            done = 1;
        }
    }
    if (!done) {
        arg0->pos[0] += arg0->vel[0] * D_800BE9A4;
        arg0->pos[1] += arg0->vel[1] * D_800BE9A4;
        arg0->pos[2] += arg0->vel[2] * D_800BE9A4;
        arg0->b[0] += arg0->bv[0] * D_800BE9A4;
        arg0->b[1] += arg0->bv[1] * D_800BE9A4;
        arg0->b[2] += arg0->bv[2] * D_800BE9A4;
        if (arg0->flags & 8) {
            v = arg0->timer;
            if (v < arg0->unk4E) {
                t = v * arg0->unk50;
                t = (s16)t;
                if (t < arg0->unk4C) {
                    arg0->unk4C = t;
                }
            }
        }
    }
    if (done) {
        func_1516972C((struct102 *)arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151564F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151568F8.s")

typedef struct {
    s16 base;
    s16 range;
    s16 timer;
} func_15156B54_t;

struct func_15156B54_s {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1B];
    func_15156B54_t t;
};

typedef struct {
    f32 x, y, z;
    s32 pad;
} func_15156B54_v;

extern func_15156B54_v D_800DCA30[][10];
void func_15156D24(func_15156B54_v *, u8);
struct225 *func_151602C0();

void func_15156B54(struct func_15156B54_s *arg0) {
    u32 j;
    u32 i;
    func_15156B54_t *t;
    Header header;
    Header2 header2;

    arg0->t.timer -= D_800BE9E4;
    if (arg0->t.timer < 0) {
        i = func_150ADA20() % 3U;
        j = func_150ADA20() % 10U;
        if (D_800DCA30[i][j].x != 0.0f && D_800DCA30[i][j].y != 0.0f && D_800DCA30[i][j].z != 0.0f) {
            func_15156D24(&D_800DCA30[i][j], arg0->unkC);
            header.unk0 = 3;
            header.unk1 = -1;
            header.unk2 = func_150ADA20() % 11U + 5;
            header.unk4 = 0;
            header2.unk0 = D_800DCA30[i][j].x;
            header2.unk4 = D_800DCA30[i][j].y;
            header2.unk8 = D_800DCA30[i][j].z;
            func_151602C0(&header, &header2, func_150ADA20() % 156U + 100, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, arg0->unkC, arg0->unk1);
        }
        t = &arg0->t;
        t->timer = t->base + func_150ADA20() % (u32)(t->range + 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156D24.s")

void *func_151D5E30();

void func_15156F94(void *arg0) {
    func_151D5E30((char *)arg0 + 0x88, arg0);
}

void func_15156FB8(s32 arg0) {
    func_15156F94(arg0);
    func_15169804(arg0);
}

void func_15156FE4(s32 arg0) {
    func_15156F94(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157010.s")

struct func_151571C4_s {
    u8 pad0[0x104];
    s32 unk104[4];
    s32 unk114;
};

void func_151571C4(void *arg0) {
    s32 i;

    for (i = 0; i <= D_80082FA0; i++) {
        if (((struct func_151571C4_s *)arg0)->unk104[i]) {
            func_100043B4(((struct func_151571C4_s *)arg0)->unk104[i], 4);
        }
    }
    if (((struct func_151571C4_s *)arg0)->unk114 != 0) {
        func_100043B4(((struct func_151571C4_s *)arg0)->unk114, 4);
    }
}

void func_151571C4(void *arg0);
void func_1518CA04(s32 arg0);
void func_1503F7B8(s32 arg0);

struct func_15157248_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x68 - 0x1C];
    s32 unk68;
};

void func_15157248(struct func_15157248_s *arg0) {
    func_151571C4(arg0);
    func_1518CA04(arg0->unk18);
    func_1503F7B8(arg0->unk68);
    func_15169804(arg0);
}

struct func_1515728C_s {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x68 - 0x1C];
    s32 unk68;
};

void func_1515728C(struct func_1515728C_s *arg0) {
    func_151571C4(arg0);
    func_1518CA04(arg0->unk18);
    func_1503F7B8(arg0->unk68);
    func_15169824(arg0);
}

struct func_151572D0_s {
    u8 pad0[0x10];
    u8 unk10;
    s8 unk11;
    s8 unk12;
    u8 pad13[0x16 - 0x13];
    s16 unk16;
    u8 pad18[0x43 - 0x18];
    u8 unk43;
    u8 pad44[0x64 - 0x44];
    s16 unk64;
    s16 unk66;
    s32 unk68;
};

extern s32 (*D_8008AD90[])(struct func_151572D0_s *);
extern s32 (*D_8008ADA0[])(struct func_151572D0_s *);
void func_1503F4B0(s32);

void func_151572D0(struct func_151572D0_s *arg0) {
    s32 tmp;
    u8 done = 0;
    if (arg0->unk10 & 1) {
        arg0->unk16 -= D_800BE9E4;
        if (arg0->unk16 < 0) {
            done = 1;
        }
    }
    if (!done) {
        tmp = arg0->unk11;
        if (tmp != -1) {
            if (D_8008AD90[tmp](arg0) == 0) {
                done = 1;
            }
        }
        tmp = arg0->unk12;
        if (tmp != -1) {
            if (D_8008ADA0[tmp](arg0) == 0) {
                done = 1;
            }
        }
    }
    if (!done) {
        func_1503F4B0(arg0->unk68);
    }
    if (!done && (arg0->unk10 & 0x20) && arg0->unk16 < arg0->unk64) {
        tmp = arg0->unk16 * arg0->unk66;
        if (tmp < arg0->unk43) {
            arg0->unk43 = tmp;
        }
    }
    if (done) {
        func_1516972C((struct102 *)arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157420.s")

struct func_15157860_s {
    u8 pad0[0x7C];
    f32 mtx[2][4][4];
};

s32 func_15157860(struct func_15157860_s *arg0) {
    guMtxIdentF(arg0->mtx[D_800BE9C0]);
    return 1;
}

void *func_15157010(void *, s32, f32, s32, s32, void *, s32, s32);

void *func_15157898(void *arg0, void *arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5, u8 *arg6, u8 arg7, s32 arg8) {
    u8 *temp_v0;

    temp_v0 = func_15157010(arg0, arg2, arg3, arg4, arg5, arg6 + 0x38, arg7, arg8);
    if (temp_v0 == NULL) {
        return NULL;
    }
    memcpy(temp_v0 + 0x120, arg1, 0x38);
    return temp_v0;
}

typedef struct {
    f32 x, y, z;
    f32 scale;
} func_15157918_rs;

struct func_15157918_s {
    u8 pad0[0x54];
    f32 pos[3];      /* 0x54 */
    u8 pad60[0x1C];
    f32 mtx[2][4][4]; /* 0x7C */
    u8 padFC[0x24];
    func_15157918_rs r; /* 0x120 */
};

s32 func_15157918(struct func_15157918_s *arg0) {
    func_15157918_rs *r = &arg0->r;

    func_150A8050(arg0->mtx[D_800BE9C0], r->x, r->y, r->z);
    arg0->mtx[D_800BE9C0][3][0] = arg0->pos[0];
    arg0->mtx[D_800BE9C0][3][1] = arg0->pos[1];
    arg0->mtx[D_800BE9C0][3][2] = arg0->pos[2];
    arg0->mtx[D_800BE9C0][0][0] *= r->scale;
    arg0->mtx[D_800BE9C0][0][1] *= r->scale;
    arg0->mtx[D_800BE9C0][0][2] *= r->scale;
    arg0->mtx[D_800BE9C0][1][0] *= r->scale;
    arg0->mtx[D_800BE9C0][1][1] *= r->scale;
    arg0->mtx[D_800BE9C0][1][2] *= r->scale;
    arg0->mtx[D_800BE9C0][2][0] *= r->scale;
    arg0->mtx[D_800BE9C0][2][1] *= r->scale;
    arg0->mtx[D_800BE9C0][2][2] *= r->scale;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157AA8.s")

void func_15157D88(u8 *arg0, void *arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x4C, arg0 + 0x50, arg0);
}

s32 func_15157DC8(u8 *arg0) {
    func_15157DEC(arg0, arg0 + 0x120);
    return 1;
}

struct func_15157DEC_s {
    u8 pad0[0x54];
    f32 pos[3];          /* 0x54 */
    u8 pad60[0x1C];
    f32 mf[2][4][4];     /* 0x7C */
};

int func_15157DEC(struct func_15157DEC_s *arg0, f32 *arg1) {
    func_150A8050(arg0->mf[D_800BE9C0], arg1[0], arg1[1], arg1[2]);
    arg0->mf[D_800BE9C0][3][0] = arg0->pos[0];
    arg0->mf[D_800BE9C0][3][1] = arg0->pos[1];
    arg0->mf[D_800BE9C0][3][2] = arg0->pos[2];
    arg0->mf[D_800BE9C0][0][0] *= arg1[3];
    arg0->mf[D_800BE9C0][0][1] *= arg1[3];
    arg0->mf[D_800BE9C0][0][2] *= arg1[3];
    arg0->mf[D_800BE9C0][1][0] *= arg1[4];
    arg0->mf[D_800BE9C0][1][1] *= arg1[4];
    arg0->mf[D_800BE9C0][1][2] *= arg1[4];
    arg0->mf[D_800BE9C0][2][0] *= arg1[3];
    arg0->mf[D_800BE9C0][2][1] *= arg1[3];
    arg0->mf[D_800BE9C0][2][2] *= arg1[3];
}

extern Mtx D_80089470;

Gfx *func_15157F80(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    gSPMatrix(gdl++, &D_80089470, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gdl++, (Mtx *)D_800DCC10 + arg2, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    *arg4 = 1;
    return gdl;
}

Gfx *func_15157FE8(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3) {
    gSPMatrix(gdl++, (u8 *)D_800BE628 + arg2 * 0x180 + (D_800BE9C0 << 6) + 0x100, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, (Mtx *)((struct10 **)&D_800DC2A0)[D_800BE9C0] + arg2, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    return gdl;
}

extern u8 D_800A6060[];

void func_15158078(s32 arg0, u8 arg1) {
    func_15169260(D_800A6060, 3, arg0, arg1);
}
