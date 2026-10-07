#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_1502FE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_1502FFD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030158.s")

s32 func_15030310(void *arg0, s32 arg1, s32 arg2);

void func_150302F0(void *arg0, s32 arg1) {
    func_15030310(arg0, arg1, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030310.s")

struct func_150303E4_s {
    u8 unk0;
    u8 pad1[0x53];
    struct func_150303E4_s *unk54;
};

struct func_150303E4_arg_s {
    u8 pad0[0x3B];
    u8 unk3B;
};

void func_15030158(struct func_150303E4_s *arg0, s32 arg1);

s32 func_150303E4(struct func_150303E4_arg_s *arg0) {
    struct func_150303E4_s *var_a0;
    struct func_150303E4_s *next;
    s32 found;

    if (arg0->unk3B == 0) {
        return 0;
    }
    found = 0;
    var_a0 = (struct func_150303E4_s *)D_800C3EE0;
    while (var_a0 != NULL) {
        next = var_a0->unk54;
        if (var_a0->unk0 == arg0->unk3B) {
            found = 1;
            func_15030158(var_a0, 0);
        }
        var_a0 = next;
    }
    return found;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150311C4.s")

void func_1503192C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct126 *temp_v0 = func_1503195C(arg0, arg1, arg3);
    if (temp_v0 != NULL) {
        temp_v0->pad0[3] = arg2;
    }
}

struct func_1503195C_s {
    u8 unk0;
    u8 pad1[5];
    u8 unk6;
    u8 pad7[0x4D];
    struct func_1503195C_s *unk54;
};

struct126 *func_1503195C(u8 *arg0, s32 arg1, s32 arg2) {
    struct func_1503195C_s *p;
    struct func_1503195C_s *next;
    s32 v = arg0[0x3B];

    if (v == 0) {
        return NULL;
    }
    p = (struct func_1503195C_s *)D_800C3EE0;
    while (p != NULL) {
        next = p->unk54;
        if (v == p->unk0) {
            if (arg1 == p->unk6) {
                if (arg2 != 0) {
                    arg2--;
                    p = next;
                    continue;
                }
                return (struct126 *)p;
            }
        }
        p = next;
    }
    return NULL;
}

struct func_150319CC_s {
    u8 unk0;
    u8 pad1[5];
    u8 unk6;
    u8 pad7[0x4D];
    struct func_150319CC_s *next;
};

struct func_150319CC_a1 {
    u8 pad0[0x3B];
    u8 unk3B;
};

struct func_150319CC_s *func_150319CC(s32 arg0, struct func_150319CC_a1 *arg1) {
    struct func_150319CC_s *var_v1;
    struct func_150319CC_s *next;

    if (arg1 != NULL) {
        var_v1 = (struct func_150319CC_s *)D_800C3EE0;
        while (var_v1 != NULL) {
            next = var_v1->next;
            if (var_v1->unk0 != arg1->unk3B) {
            } else if (arg0 == var_v1->unk6) {
                return var_v1;
            }
            var_v1 = next;
        }
    }
    var_v1 = (struct func_150319CC_s *)D_800C3EE0;
    while (var_v1 != NULL) {
        next = var_v1->next;
        if (arg0 == var_v1->unk6) {
            return var_v1;
        }
        var_v1 = next;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031C14.s")

struct func_15031E2C_s {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[0x38 - 0x1A];
    s32 unk38;
};
extern s32 D_800902BC[];

s32 func_15031E2C(struct func_15031E2C_s *arg0, s32 arg1) {
    s32 i = arg0->unk38;
    if (i >= 3) {
        i = 5 - i;
    }
    arg0->unk18 = D_800902BC[i];
    arg0->unk38++;
    if (arg0->unk38 >= 6) {
        arg0->unk38 = 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150331B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_1503327C.s")

struct func_15033328_a0 {
    u8 pad0[0x38];
    s32 unk38;
};
struct func_15033328_s {
    u8 pad0[0xAD];
    u8 unkAD;
    u8 padAE[0x118 - 0xAE];
    f32 unk118;
    u8 pad11C[0x180 - 0x11C];
    f32 unk180;
};

s32 func_15033328(struct func_15033328_a0 *arg0, struct func_15033328_s *arg1) {
    if (D_800C35EA == 1) {
        return 0;
    }
    if (arg1->unkAD == 0 && arg1->unk118 < arg1->unk180) {
        if (D_800BE9E4 < arg0->unk38) {
            arg0->unk38 -= D_800BE9E4;
            return 0;
        }
        return 1;
    }
    arg0->unk38 = 30;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150333A8.s")

struct func_15033440_s {
    u8 pad0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x22 - 0x3];
    s16 unk22;
};

s32 func_15033440(struct func_15033440_s *arg0, u8 *arg1) {
    switch (arg0->unk1) {
    case 0x27:
    case 0x35:
        if (arg1[5] == 5) {
            arg0->unk2 = 0;
            arg0->unk22 += D_800BE9E4 * 0xAAA;
        }
        break;
    case 0x29:
        if (arg1[5] == 5) {
            arg0->unk2 = 0;
        }
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150334B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150335C8.s")

struct func_1503378C_s { u8 pad0; u8 unk1; };
struct func_1503378C_t { u8 pad0[0x84]; u16 unk84; };

s32 func_1503378C(struct func_1503378C_s *arg0, struct func_1503378C_t *arg1) {
    u16 v = arg1->unk84;
    if (arg0->unk1 == 0x11) {
        if (v == 0x3E || v == 0x3D || v == 0x41 || v == 0xD9 || v == 0x138 || v == 0x139) {
            return 0;
        }
    }
    return 1;
}

extern s32 D_800902FC[];

struct func_150337E4_s {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[0x38 - 0x1A];
    s32 unk38;
    s32 unk3C;
};

s32 func_150337E4(struct func_150337E4_s *arg0, s32 arg1) {
    arg0->unk38 += D_800BE9E4;
    if (arg0->unk38 >= 0x10) {
        arg0->unk38 = 0;
        arg0->unk3C ^= 1;
    }
    arg0->unk18 = D_800902FC[arg0->unk3C];
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150339C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033AD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033BDC.s")

struct func_15033E00_s {
    u8 pad0[5];
    u8 unk5;
};

s32 func_15033E00(s32 arg0, struct func_15033E00_s *arg1) {
    if (arg1->unk5 == 3) {
        return 1;
    }
    return 0;
}

struct func_15033E28_s {
    u8 unk0;
    u8 pad1[0x3A];
    u8 unk3B;
    u8 pad3C[0x18];
    struct func_15033E28_s *unk54;
};

s32 func_15033E28(struct func_15033E28_s *arg0, struct func_15033E28_s **arg1) {
    struct func_15033E28_s *var_a0;
    struct func_15033E28_s *next;
    s32 count = 0;

    if (D_800C3EE0 == 0) {
        return 0;
    }
    var_a0 = (struct func_15033E28_s *)D_800C3EE0;
    while (var_a0 != NULL) {
        next = var_a0->unk54;
        if (var_a0->unk0 == arg0->unk3B) {
            arg1[count++] = var_a0;
        }
        var_a0 = next;
    }
    return count;
}

struct func_15033E84_s {
    u8 unk0;
    u8 pad1[0x53];
    struct func_15033E84_s *unk54;
};

struct func_15033E84_s *func_15033E84(u8 *arg0) {
    struct func_15033E84_s *var_v1;
    struct func_15033E84_s *next;

    var_v1 = (struct func_15033E84_s *)D_800C3EE0;
    while (var_v1 != NULL) {
        next = var_v1->unk54;
        if ((arg0[0x3B] ^ var_v1->unk0) == 0) {
            return var_v1;
        }
        var_v1 = next;
    }
    return NULL;
}

struct func_15033EC4_s {
    u8 unk0;
    u8 pad1[0x53];
    struct func_15033EC4_s *unk54;
};

void func_15033EC4(s32 arg0, s32 arg1) {
    struct func_15033EC4_s *var_v0;
    struct func_15033EC4_s *next;

    var_v0 = (struct func_15033EC4_s *)D_800C3EE0;
    while (var_v0 != NULL) {
        next = var_v0->unk54;
        if (arg0 == var_v0->unk0) {
            var_v0->unk0 = arg1;
        } else if (arg1 == var_v0->unk0) {
            var_v0->unk0 = arg0;
        }
        var_v0 = next;
    }
}

s32 func_15033F0C(s32 arg0, struct struct127 *arg1) {
    struct126 *tmp;

    if (D_800C35EA == 1) {
        return 0;
    }
    tmp = arg1->unk31C;
    if ((tmp != NULL) && (tmp->unk78 != 9) && (tmp->unk11A != 3)) {
        tmp->unk11A = 0;
        return 1;
    }
    return 0;
}

s32 func_15033F70(s32 arg0, struct struct127 *arg1) {
    struct126 *tmp;

    if (D_800C35EA == 1) {
        return 0;
    }
    tmp = arg1->unk31C;
    if ((tmp != NULL) && (tmp->unk78 != 12) && (tmp->unk78 != 22) && (tmp->unk11A != 3)) {
        tmp->unk11A = 0;
        return 1;
    }
    return 0;
}
