#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_20A990/osEepromRead.s")

typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} __osPackEepReadData_PifRam;

typedef struct {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 address;
    u8 data[8];
} __osPackEepReadData_Fmt;

extern __osPackEepReadData_PifRam D_800E0A30;

void __osPackEepReadData(u8 address, u8 *buffer) {
    u8 *ptr = (u8 *)&D_800E0A30.ramarray;
    __osPackEepReadData_Fmt eepromformat;
    int i;

    D_800E0A30.pifstatus = 1;

    eepromformat.txsize = 10;
    eepromformat.rxsize = 1;
    eepromformat.cmd = 5;
    eepromformat.address = address;
    for (i = 0; i < 8; i++) {
        eepromformat.data[i] = *buffer++;
    }

    for (i = 0; i < 4; i++) {
        *ptr++ = 0;
    }

    *(__osPackEepReadData_Fmt *)(ptr) = eepromformat;
    ptr += sizeof(__osPackEepReadData_Fmt);
    ptr[0] = 0xFE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20A990/__osEepStatus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_20A990/func_151DD8C0.s")
