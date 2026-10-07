#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800E0A20;
extern u8 D_800E0A24;
extern s32 D_800E0A28;
extern s32 D_800E0A2C;
extern OSTimer D_80042A58;
extern OSMesgQueue __osEepromTimerQ;
extern OSMesg D_80042A90;
s32 func_151DCFD8(s32);

void func_151DCEF0(s32 arg0, u8 arg1, s32 arg2, s32 arg3) {
    while (func_151DCFD8(1) != 0) {
    }
    D_800E0A20 = arg0;
    D_800E0A24 = arg1;
    D_800E0A28 = arg2;
    D_800E0A2C = arg3;
    osSetTimer(&D_80042A58, (u64)(12000 * D_8002BD10) / 1000000, 0, &__osEepromTimerQ, &D_80042A90);
}

s32 func_151DCFD8(s32 arg0) {
    if (D_800E0A20 == 0) {
        return 0;
    }
    if (osRecvMesg(&__osEepromTimerQ, NULL, arg0) != -1) {
        if (D_800E0A2C <= 0) {
            D_800E0A20 = 0;
            D_800E0A2C = 0;
            return 0;
        }
        if (osEepromRead((OSMesgQueue *)D_800E0A20, D_800E0A24, (u8 *)D_800E0A28) != 0) {
            D_800E0A20 = 0;
            D_800E0A2C = 0;
            return 0;
        }
        D_800E0A2C -= 8;
        D_800E0A24++;
        D_800E0A28 += 8;
        osSetTimer(&D_80042A58, (u64)(12000 * D_8002BD10) / 1000000, 0, &__osEepromTimerQ, &D_80042A90);
        return 1;
    }
    return 0;
}
