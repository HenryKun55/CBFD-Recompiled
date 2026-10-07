#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 sinf(f32 x) {
    f32 dx, xsq, poly;
    f32 dn;
    s32 n;
    f32 result;
    s32 ix, xpt;

    ix = *(s32 *)&x;
    xpt = (ix >> 22);
    xpt &= 0x1FF;

    if (xpt < 0xFF) {
        dx = x;
        if (xpt >= 0xE6) {
            xsq = dx * dx;
            poly = ((D_80098D90[4] * xsq + D_80098D90[3]) * xsq + D_80098D90[2]) * xsq + D_80098D90[1];
            result = dx + (dx * xsq) * poly;
            return result;
        }
        return x;
    }

    if (xpt < 0x136) {
        dx = x;
        dn = dx * D_80085EB0;
        if (dn >= 0.0f) {
            n = dn + 0.5f;
        } else {
            n = dn - 0.5f;
        }
        dn = n;
        dx -= dn * D_80085EB4;
        dx -= dn * D_80085EB8;
        xsq = dx * dx;
        poly = ((D_80098D90[4] * xsq + D_80098D90[3]) * xsq + D_80098D90[2]) * xsq + D_80098D90[1];
        result = dx + (dx * xsq) * poly;
        if ((n & 1) == 0) {
            return result;
        }
        return -result;
    }

    if (x != x) {
        return D_8002C920;
    }
    return D_80085EBC;
}
