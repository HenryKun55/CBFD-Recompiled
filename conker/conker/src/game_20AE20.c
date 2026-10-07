#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151DD970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151DD9E4.s")

s32 func_151DDB94(s32 arg0) {
    return ~arg0;
}

extern u8 D_8008FDA4;
extern u8 D_800D2E40;
void func_151E557C(void);
void func_1501C730(s32, s32, s32, s32, s32);
void func_1000F1A8(void);
void func_1000E934(void);

void func_151DDBA0(void) {
    D_800D2E40 = 0;
    func_1501C730(6, 0x1D, 0, 0, 1);
    D_800E0B94 = 3;
    D_8008FDA4 = 0;
    D_800BEAC1 = 0;
    func_151E557C();
    func_1000F1A8();
    func_1000E934();
    D_8008FD8C = 1;
    D_8008FD90 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151DDC20.s")

void func_151E530C();
extern s32 D_800E0A90;
extern s16 D_800E0B9A;
extern u8 D_8008FE28;
extern u8 D_800E0B96;

void func_151DE6D4(void) {
    func_151E530C();
    gObjects[0].unk25C |= 0x200;
    gObjects[0].y_position = 1000.0f;
    if (D_80000300 == 0) {
        D_800E0A90 = 0;
    }
    if ((D_800E0A90 > 330) && (D_800E0B9A & 0x8000)) {
        if (D_800E0A90 < 480) {
            D_800E0A90 = 480;
        }
        if ((D_800E0A90 > 600) && (D_800E0A90 < 720)) {
            D_800E0A90 = 720;
        }
    }
    if (D_800E0A90 > 840) {
        D_8008FE28 = 2;
        D_800E0B94 = 1;
        D_800D2E40 = 0;
        func_1501C730(6, 0x21, 0, 0, 1);
        D_800E0B96 = 0xFF;
    }
}

extern s32 D_800E0A90;
extern u8 D_800E0B97;
extern u8 D_800E0B98;
extern u8 D_800E0A8C;
extern u8 D_8008FE28;
void func_151DE85C(void);

void func_151DE7D4(void) {
    D_800E0A90 = 0;
    D_800E0B97 = 0;
    D_800E0B98 = 0;
    D_800E0A8C = 0;
    D_8008FE28 = 2;
    func_151DE85C();
}

extern s8 D_8008FE30;
extern u8 D_8008FD74;
extern u8 D_800E0B96;

void func_151DE81C(void) {
    D_8008FD74 = 4;
    D_800E0B96 = 0;
    if (D_8008FE30 == 0) {
        func_1500764C();
    }
}

extern u8 D_8008FD80;
struct func_151DE85C_s {
    u8 pad0[0x2B];
    s8 unk2B;
    s8 unk2C;
    u8 pad2D[0x3E - 0x2D];
    u8 unk3E;
};
extern struct func_151DE85C_s *gGameState;

void func_151DE85C(void) {
    D_800D2E40 = 0;
    func_1501C730(6, 0x1D, 0, 0, 1);
    D_800E0B94 = 3;
    D_8008FD80 = 1;
    D_8008FE28 = 2;
    D_8008FDA4 = 0;
    gGameState->unk3E = 0;
    gGameState->unk2B = 5;
    gGameState->unk2C = gGameState->unk2B;
}

void func_151DE8E8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151DE8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151DF1BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151DF574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151DFF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E0424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E09DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E0B70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E1214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E1744.s")

extern u8 D_8008FD80;
void func_151E530C();
void func_151E43DC();

void func_151E2284(void) {
    D_8008FD80 = 3;
    func_151E530C();
    func_151E43DC();
    D_8008FD80 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E22BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E2404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E24F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E2834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E30C4.s")

extern s8 D_800D23A8;
extern u8 D_800E0B99;
extern s8 D_800E0BB1;
void func_151E7EF8(void);

void func_151E327C(void) {
    D_80087260 = 3;
    if (D_800E9D00 & 0x200) {
        D_80087260 = 0x33;
    }
    D_80087270[0] = 0;
    D_8008FD8C = 1;
    D_8008FD90 = 1;
    *(s8 *)&D_8008FD94 = 1;
    D_8008FDBC = 0;
    D_800BE618 = 1;
    D_800D23A8 = 0;
    D_800E0B94 = 0;
    D_800D2E40 = 0;
    func_1501C730(6, (s8)D_800BE3DF, D_800BE3E0, 0, 1);
    D_800E0B99 = 1;
    D_800E0BB1 = 1;
    func_151E7EF8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E3344.s")

extern s16 D_800E0B9A;
extern void (*D_800E0A88)(void);
extern u8 D_8008FD74;
s32 func_151F2CDC();
void func_151F2D6C(s32, s32);
void func_151E2834(void);

void func_151E4264(void) {
    if (D_8008FD80) {
        D_8008FD80 = 0;
        return;
    }
    func_151E530C();
    if ((D_800E0B9A != 0) || (D_800C35EA != 1)) {
        if (D_800C35EA == 1) {
            if (func_151F2CDC() == 1) {
                func_151F2D6C(0, 0x2DE0);
            }
        }
        D_800E0B94 = 7;
        D_800E0A88 = func_151E2834;
        D_8008FD74 = 8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E4314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E43DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E4BD8.s")

void func_151E4DC4(void) {
    D_800E0B94 = 10;
}

extern s16 D_800E0B9A;

void func_151E4DD8(void) {
    if (D_800E0B9A & 0x8020) {
        D_800E0B94 = 4;
    }
}

extern s16 D_8008FDCC;
extern u8 D_8008FDA4;
extern u8 D_8008FD80;
extern u8 D_800D2E40;
void func_151E557C(void);
void func_1501C730(s32, s32, s32, s32, s32);

void func_151E4E00(void) {
    D_8008FDCC = 0;
    func_151E557C();
    D_800E0B94 = 3;
    D_8008FDA4 = 0;
    D_8008FD80 = 0;
    D_800D2E40 = 0;
    func_1501C730(6, 0x1D, 0, 0, 1);
}

extern void (*D_800E0A88)(void);
void func_151E55A8();

void func_151E4E64(void) {
    func_151E530C();
    func_151E55A8();
    if (D_800E0A90 > 1200) {
        D_800E0B9A |= 0x8000;
    }
    if (D_800E0B9A != 0) {
        D_800E0B94 = 7;
        D_800E0A88 = func_151E4E00;
        D_8008FD74 = 8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E4EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E5034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E50C8.s")

extern u8 D_800E0BDC;
extern u16 D_800BE930;
extern void (*D_8008FDEC[])(void);
extern u8 D_800E0B95;
void func_151E6964(s32);

void func_151E51EC(void) {
    u8 prev;

    prev = D_800E0B94;
    D_8003C8E0 = 0x8000000;
    D_800E0BDC = 0xFF;
    func_15042D78(0x81);
    D_800E0B9A = D_800BE930;
    if (*(s8 *)&D_8008FE28 != 0) {
        *(s8 *)&D_8008FE28 = *(s8 *)&D_8008FE28 - 1;
        D_800E0B9A = 0;
    }
    if (D_800E0B94 == 0) {
        func_151E6964(2);
    } else if (D_800E0B94 == 8) {
        func_151E6964(4);
    } else {
        func_151E6964(1);
    }
    D_8008FDEC[D_800E0B94]();
    if (D_800E0B94 != 7) {
        D_800E0A90 += D_800BE9E4;
        if (D_800E0B94 != prev) {
            D_800E0B95 = prev;
            D_800E0A90 = 0;
        }
    }
    D_8003C8E0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E530C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E53E8.s")

extern u8 D_80084060[];

void func_151E557C(void) {
    D_80084060[0] = 0;
    D_80084060[1] = 1;
    D_80084060[2] = 2;
    D_80084060[3] = 3;
}

extern u8 D_800E0B98;
extern u8 D_800E0B97;

void func_151E55A8(void) {
    s32 delta;
    s32 val;

    if (D_800E0B98 == 0) {
        delta = D_800BE9E4 * 8;
    } else {
        delta = -D_800BE9E4 * 8;
    }
    val = D_800E0B97;
    val += delta;
    if (val >= 256) {
        val = 0x1FE - val;
        D_800E0B98 ^= 1;
    } else if (val < 0) {
        val = -val;
        D_800E0B98 ^= 1;
    }
    D_800E0B97 = val;
}

extern u8 D_800E0A8C;

void func_151E562C(void) {
    if (D_800E0A8C != 0) {
        D_800E0A8C = 0;
    }
}

extern s8 D_8008FDC8;

s32 func_151E564C(void) {
    return D_8008FDC8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E565C.s")

extern s8 D_800E0C00[];

s32 func_151E5F64(s32 arg0) {
    s32 v;
    if (D_800BE616 || D_800E0B94) {
        v = D_800E0C00[arg0];
        if (v < 0) {
            v = 0;
        }
        return v;
    }
    return arg0;
}

extern s8 D_800E0BEB;

s8 func_151E5FAC(void) {
    if (D_800E0BEB) {
        if (D_8008FD8C >= 5) {
            return D_8008FD90;
        }
        return D_8008FD8C;
    }
    return D_8008FD90;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E5FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E6964.s")

extern s8 D_800E0BD3;
extern s32 D_800E0BD4;
extern s32 D_8008FDD8;

void func_151E6BFC(void) {
    D_800E0BD3 = 0;
    D_800E0BD4 = 0;
    D_8008FDD8 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E6C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E7DC0.s")

extern s8 D_800E0BE9;

void func_151E7E9C(void) {
    if (D_800E0BE9 == 2) {
        func_10017870(1);
    } else if (D_800E0BE9 == 0) {
        func_10017870(2);
    } else {
        func_10017870(4);
    }
}

void func_151DDC20();

void func_151E7EF8(void) {
    u32 *p;
    u32 *end;
    u32 sum;

    func_151E7E9C();
    p = (u32 *)func_151DDC20;
    end = (u32 *)func_151DE7D4;
    sum = 0;
    while (p < end) {
        sum += *p++;
    }
    if (sum != 0xBFC924E3) {
        *(u32 *)osSpTaskLoad = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E7F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E81EC.s")

extern s16 D_800E0A80;
s32 func_1517EFDC(void);

void func_151E8214(void) {
    if (D_800E0B94 != 8) {
        if (func_1517EFDC() == 0) {
            D_800E0A90 = 0;
        }
        if (D_800E0A90 > 160) {
            D_8008FDCC = 0;
            D_800E0B94 = 8;
            D_8008FD8C = 1;
            D_8008FD90 = 1;
            D_8008FDA4 = 0;
            D_800E0A80 = -2;
            D_800E0A90 = 0;
            D_800D2E43 = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E82B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20AE20/func_151E83E8.s")
