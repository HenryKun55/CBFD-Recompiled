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

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
} __osEepStatus_s;

extern u8 __osContLastCmd;
extern s32 __osSiRawStartDma(s32, void *);

s32 __osEepStatus(OSMesgQueue *mq, OSContStatus *data) {
    s32 ret = 0;
    int i;
    u8 *ptr = (u8 *)D_800E0A30.ramarray;
    __osEepStatus_s requestformat;

    for (i = 0; i < 16; i++) {
        D_800E0A30.ramarray[i] = 0;
    }
    D_800E0A30.pifstatus = 1;
    ptr = (u8 *)D_800E0A30.ramarray;
    for (i = 0; i < 4; i++) {
        *ptr++ = 0;
    }
    requestformat.dummy = 0xFF;
    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = 0;
    requestformat.typeh = 0xFF;
    requestformat.typel = 0xFF;
    requestformat.status = 0xFF;
    requestformat.dummy1 = 0xFF;
    *(__osEepStatus_s *)ptr = requestformat;
    ptr += sizeof(__osEepStatus_s);
    *ptr = 0xFE;
    ret = __osSiRawStartDma(1, &D_800E0A30);
    osRecvMesg(mq, NULL, 1);
    __osContLastCmd = 0xFE;
    if (ret != 0) {
        return ret;
    }
    ret = __osSiRawStartDma(0, &D_800E0A30);
    osRecvMesg(mq, NULL, 1);
    if (ret != 0) {
        return ret;
    }
    ptr = (u8 *)&D_800E0A30;
    for (i = 0; i < 4; i++) {
        *ptr++ = 0;
    }
    requestformat = *(__osEepStatus_s *)ptr;
    data->errno = (requestformat.rxsize & 0xC0) >> 4;
    data->type = (requestformat.typel << 8) | requestformat.typeh;
    data->status = requestformat.status;
    return data->errno;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_20A990/func_151DD8C0.s")
