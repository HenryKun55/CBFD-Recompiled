#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_151DCFD8(s32);

s32 func_151DD3A0(OSMesgQueue *mq, u8 address, u8 *buffer, s32 length) {
    s32 ret = 0;

    while (func_151DCFD8(1)) {
    }
    while (length > 0) {
        ret = osEepromWrite(mq, address, buffer);
        if (ret != 0) {
            return ret;
        }
        length -= 8;
        address++;
        buffer += 8;
    }
    return ret;
}
