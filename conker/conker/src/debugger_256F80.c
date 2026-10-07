#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// The debugger's own blocking controller read, polling instead of using libultra's
// message queues. If the last PIF command wasn't a read, it packs one
// (func_160018BC, libultra's __osPackReadData), writes the PIF RAM
// (func_160019A8(1, ...), with __osSiRawStartDma's arguments: 1 = write, 0 = read)
// and waits 200000 count ticks (about 4 ms). Then it fills the 16-word PIF RAM
// buffer with 0xFF, clears its last word (pifstatus, D_80042A4C), starts the read,
// records the read as the last command, and waits 800000 ticks for it to finish.
// Returns the read's result. func_160016F4 only returns its argument: the wait
// loops call it so they aren't optimised away.
// NON-MATCHING: the C below differs only in the order of the two address loads
// before the fill loop (the original loads the end, &__osContPifRam[16], first).
// Indexed and for loops are further off; pointer loops with the end in a variable,
// in the condition or reversed all give the same two-instruction difference.
// (Tested with `extern u32 __osContPifRam[16];` and separate state/end variables
// for the two waits.)
// s32 func_16001700(void) {
//     s32 result;
//     u32 *word;
//     s32 state;
//     u32 end;
//
//     if (__osContLastCmd != 1) {
//         func_160018BC();
//         func_160019A8(1, __osContPifRam);
//         state = 0;
//         end = osGetCount() + 200000;
//         if (osGetCount() < end) {
//             do {
//                 state = func_160016F4(state);
//             } while (osGetCount() < end);
//         }
//         func_160016F4(state);
//     }
//     word = __osContPifRam;
//     do {
//         *word++ = 0xFF;
//     } while (word < &__osContPifRam[16]);
//     D_80042A4C = 0;
//     result = func_160019A8(0, __osContPifRam);
//     __osContLastCmd = 1;
//     state = 0;
//     end = osGetCount() + 800000;
//     if (osGetCount() < end) {
//         do {
//             state = func_160016F4(state);
//         } while (osGetCount() < end);
//     }
//     func_160016F4(state);
//     return result;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/debugger_256F80/func_16001700.s")
extern u32 __osContPifRam[];
extern u8 __osMaxControllers;

struct func_16001830_s {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 button;
    s8 stick_x;
    s8 stick_y;
};

void func_16001830(OSContPad *data) {
    u8 *ptr = (u8 *)__osContPifRam;
    struct func_16001830_s readformat;
    s32 i;

    for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(struct func_16001830_s), data++) {
        readformat = *(struct func_16001830_s *)ptr;
        data->errno = (readformat.rxsize & 0xC0) >> 4;
        if (data->errno == 0) {
            data->button = readformat.button;
            data->stick_x = readformat.stick_x;
            data->stick_y = readformat.stick_y;
        }
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/debugger_256F80/func_160018BC.s")

// another __osSiDeviceBusy function
s32 func_16001984()
{
    register u32 stat = IO_READ(SI_STATUS_REG);
    if (stat & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY))
        return 1;
    return 0;
}

// very similar to __osSiRawStartDma
s32 func_160019A8(s32 direction, void *dramAddr) {
    if ((s32)dramAddr & 3) { // what is this checking?
        return -1;
    }
    if (func_16001984()) {
        return -1;
    }

    if (direction == OS_WRITE) {
        osWritebackDCache(dramAddr, 64);
    }

    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));

    if (direction == OS_READ) {
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, 0x1FC007C0);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, 0x1FC007C0);
    }
    if (direction == OS_READ) {
        osInvalDCache(dramAddr, 64);
    }

    return 0;
}

void func_16001A64(void) {
}

s32 func_16001A6C(f32 arg0) {
    s32 tmp = *(s32*) &arg0;

    if ((tmp * 2) == 0) {
        return 0;
    }
    tmp = (tmp & 0x7F800000) >> 0x17;
    if ((tmp <= 0) || (tmp >= 255)) {
        return 1;
    }
    return 0;
}
