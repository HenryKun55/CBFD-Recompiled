#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_1504A2B0(f32);
f32 func_1504A620(f32);

f32 func_1504A400(f32 x, f32 y) {
    f32 r;

    if (x != 0.0f && y == 0.0f) {
        return 1.0f;
    }
    if (x == 0.0f) {
        return 0.0f;
    }
    if ((x == 0.0f && y == 0.0f) || (x < 0.0f && y != (s32)y)) {
        return 0.0f;
    }
    if (y != (s32)y) {
        x = func_1504A2B0(func_1504A620(x) * y);
    } else if (y > 0.0f) {
        r = x;
        y--;
        while (y--) {
            x *= r;
        }
    } else {
        r = 1.0f;
        while (y++) {
            r /= x;
        }
        x = r;
    }
    return x;
}
