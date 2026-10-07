#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A0700;
extern f32 D_800A0704;
extern f32 D_800A0708;
extern f32 D_800A070C;

void func_150CCD90(f32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 temp_f0;
    f32 temp_f0_2;

    if (arg0 > 0.0f) {
        *arg1 = 255.0f;
        *arg2 = 255.0f;
        *arg3 = 255.0f;
        return;
    }
    if (D_800A0700 < arg0) {
        temp_f0 = -arg0 * D_800A0704;
        *arg1 = 255.0f - (temp_f0 * 83.0f);
        *arg2 = 255.0f - (temp_f0 * 113.0f);
        *arg3 = 255.0f - (temp_f0 * 173.0f);
        return;
    }
    temp_f0_2 = -(arg0 + D_800A0708) * D_800A070C;
    *arg1 = 172.0f - (temp_f0_2 * 50.0f);
    *arg2 = 142.0f - (temp_f0_2 * 42.0f);
    *arg3 = 82.0f - (temp_f0_2 * -1.0f);
}
