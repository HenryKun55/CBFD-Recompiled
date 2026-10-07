#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_15016500(void) {
    D_800D1940 = (u8)0;
    D_800D1941 = (u8)0;
    D_800D1944 = 0;
    D_800D1948 = 0;
    D_800D194C = 0;
    D_800D1950 = 0;
    bzero(D_800D1958, 48); // bzero
    D_800D1988 = 0.0f;
    D_800D198C = 0.0f;
    D_800D1990 = 0.0f;
    D_800D1994 = (u8)0;
    D_800D1995 = (u8)0;
    D_800D1998 = 0;
}

// grim looking loop
extern u8 D_800BE580[];
s32 func_1502B020(s32 *, s32, s32, u8, s32);

void func_15016588(void) {
    s32 idx;
    s32 i;

    bzero(D_800BE580, 8);
    idx = -1;
    for (i = 0; i < 0x43; i++) {
        s32 bit;
        s32 sp40;
        if ((i & 7) == 0) {
            bit = 1;
            idx++;
        } else {
            bit <<= 1;
        }
        func_1502B020(&sp40, 3, 0x1A, D_800BEAAB, i);
        if (sp40 != 0) {
            D_800BE580[idx] |= bit;
        }
    }
}
