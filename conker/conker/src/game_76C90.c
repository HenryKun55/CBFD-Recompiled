#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_150497E0(f32 *arg0, s32 arg1, f32 arg2) {
    f32 a;
    f32 c;
    f32 b;
    f32 ret;

    a = -0.5f * arg0[arg1 + 0] + 1.5f * arg0[arg1 + 1] + -1.5f * arg0[arg1 + 2] + 0.5f * arg0[arg1 + 3];
    b = arg0[arg1 + 0] + -2.5f * arg0[arg1 + 1] + 2.0f * arg0[arg1 + 2] + -0.5f * arg0[arg1 + 3];
    c = -0.5f * arg0[arg1 + 0] + 0.5f * arg0[arg1 + 2];
    ret = ((a * arg2 + b) * arg2 + c) * arg2;
    ret += arg0[arg1 + 1];
    return ret;
}

f32 func_150498A4(f32 *arg0, s32 arg1, f32 arg2, f32 *arg3) {
    f32 b;
    f32 c;
    f32 ret;
    f32 a;

    a = -0.5f * arg0[arg1 + 0] + 1.5f * arg0[arg1 + 1] + -1.5f * arg0[arg1 + 2] + 0.5f * arg0[arg1 + 3];
    b = arg0[arg1 + 0] + -2.5f * arg0[arg1 + 1] + 2.0f * arg0[arg1 + 2] + -0.5f * arg0[arg1 + 3];
    c = -0.5f * arg0[arg1 + 0] + 0.5f * arg0[arg1 + 2];
    ret = arg0[arg1 + 1];
    *arg3 = (a * 3.0f * arg2 + 2.0f * b) * arg2 + c;
    ret = ((a * arg2 + b) * arg2 + c) * arg2 + ret;
    return ret;
}
