#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_1507EB80(u8 *buf, s32 *len, u8 c) {
    if (*len + 1 < 40) {
        buf[*len] = c;
        *len = *len + 1;
    }
}

extern u8 *D_80086C24[];
extern u8 D_8009BBF0[];

void func_1507EBB8(u8 *buf, s32 *len, s32 idx) {
    u8 *src = D_80086C24[idx];
    s32 n = D_8009BBF0[idx];

    if (*len + n < 40) {
        bcopy(src, buf + *len, n);
        *len += n;
    }
}

s32 func_1507EC38(u8 *src, s32 srcLen, u8 *out, s32 *outLen, u8 *excl) {
    s32 ret;
    s32 i;
    s32 j;
    s32 found;
    s32 count;
    u8 buf[5];
    s32 n;

    ret = 0;
    *outLen = 0;
    for (i = 0; i < srcLen; i++) {
        found = 0;
        for (j = 0; j < *outLen; j++) {
            if (out[j] == src[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            for (j = 0; j < 5; j++) {
                if (excl[j] == src[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                out[*outLen] = src[i];
                *outLen = *outLen + 1;
            }
        }
    }
    if (*outLen == 0) {
        count = 0;
        for (i = 0; i < 5; i++) {
            if (excl[i] != 0) {
                for (j = 0; j < srcLen; j++) {
                    if (excl[i] == src[j]) {
                        buf[count++] = excl[i];
                        break;
                    }
                }
            }
        }
        if (count == 0) {
            out[0] = 0;
            *outLen = 1;
        } else {
            n = count >> 1;
            if (n == 0) {
                n = 1;
            }
            for (; n != 0; n--) {
                out[*outLen] = buf[count - 1];
                count--;
                *outLen = *outLen + 1;
            }
            ret = 1;
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EE58.s")

void func_1507EEB8(u8 arg0, u8 *arg1) {
    s32 i;
    for (i = 4; i > 0; i--) {
        arg1[i] = arg1[i - 1];
    }
    arg1[0] = arg0;
}

void func_1507EEF4(void) {
    u8 *p = (u8 *)gCurrentObject->unk31C + 0x58;

    if (p[0xC] == 0) {
        p[0xC] = 1;
        p[0xD] = 0;
    } else if (p[0xC] == 1) {
        func_150ADA20();
        if (p[0xD] >= 3) {
            p[0xC] = 2;
            p[0xD] = 0;
        }
    } else {
        if (p[0xD] >= (func_150ADA20() & 3) + 8) {
            p[0xC] = 1;
            p[0xD] = 0;
        }
    }
}

void func_1507EFA0(s32 arg0, u8 *arg1) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        if (arg0 == arg1[i]) {
            arg1[i] = 0;
            return;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EFD0.s")

extern u8 *D_80086BA0[];

s32 func_1507F454(void) {
    u8 *p = (u8 *)gCurrentObject->unk31C + 0x58;
    u8 c;

    if (p[4] == 0) {
        return 1;
    }
    p[5]++;
    c = *(p[5] + D_80086BA0[p[4]]);
    if (c == 0) {
        p[4] = 0;
        p[5] = 0;
        return 1;
    }
    return 0;
}

s32 func_1507F4C0(s32 arg0) {
    u32 ret;
    u32 base;
    u32 range;

    if (arg0 == 0) {
        base = 180;
        range = 60;
    } else if (D_800BE9F0 == 0x31) {
        return 0;
    } else if (arg0 == 1) {
        base = 60;
        range = 60;
    } else {
        base = 0;
        range = 30;
    }
    ret = (func_150ADA20() % range) + base;
    return ret;
}

extern u8 D_800B85A4[][0x32C];

void func_1507F54C(struct127 *arg0) {
    s32 anim;

    if (arg0->unk13C >= 100) {
        switch (D_800B85A4[arg0->unk13C][0]) {
        case 0x57:
            anim = 0x115;
            break;
        case 0x8C:
            anim = 0x1A5;
            break;
        case 0xA8:
        case 0xA9:
            anim = 0x1AF;
            break;
        case 0x89:
        case 0xBA:
            anim = 0x1FA;
            break;
        default:
            anim = 0xD8;
            break;
        }
        func_1505E650(arg0, anim, 1.0f, 4.0f, 0.0f, 0.0f, 0);
    } else {
        func_1505E650(arg0, 0xF, 1.0f, 3.0f, 0.0f, 0.0f, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FC2C.s")

void func_1507FC2C(struct127 *arg0);
void func_1507FF94(struct127 *arg0);

struct func_1507FEA0_s {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    u8 unk4;
    u8 unk5;
    u8 pad6[6];
    u8 unkC;
    u8 unkD;
};

void func_1507FEA0(struct127 *arg0) {
    struct func_1507FEA0_s *p;
    s32 t;
    s32 lim;

    if (arg0->unk31C != NULL && arg0->unk127 != 0xFF) {
        p = (struct func_1507FEA0_s *)((u8 *)arg0->unk31C + 0x58);
        if (((u8 *)arg0)[0x13A] != 0) {
            ((u8 *)arg0)[0x13A]--;
        }
        if (p->unk0 == 1 && D_800C35EA != 1) {
            lim = 0xFFFF - D_800BE9E4;
            if (p->unk2 < lim) {
                p->unk2 += D_800BE9E4;
            }
        } else {
            p->unk2 = 0;
            p->unk4 = 0;
            p->unk5 = 0;
            p->unkC = 0;
            p->unkD = 0;
        }
        t = *(s16 *)((u8 *)arg0->unk31C + 0x66);
        if (t != 0) {
            if (D_800BE9E4 < t) {
                *(s16 *)((u8 *)arg0->unk31C + 0x66) = t - D_800BE9E4;
            } else {
                func_1507FF94(arg0);
                *(s16 *)((u8 *)arg0->unk31C + 0x66) = 0;
            }
        }
        func_1507FC2C(arg0);
    }
}

struct func_1507FF94_s {
    struct127 *ptr;
    u8 id;
};

void func_1507FF94(struct127 *arg0) {
    struct func_1507FF94_s tmp;

    tmp.ptr = arg0;
    tmp.id = arg0->unique_id;
    // reusing the parameter as an integer-cast pointer makes IDO spill
    // &tmp across the first call instead of rematerialising it
    arg0 = (struct127 *)(s32)&tmp;
    func_15191B8C(arg0, 0xD);
    func_151494E0(arg0, 0xD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FFD8.s")
