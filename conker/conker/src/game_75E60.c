#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// NON-MATCHING: full semantics recovered and verified via isolated
// harness - a 4-quadrant lookup table (likely a fast sin/cos-style
// function): arg0 is a byte "binary angle" (0-255) split into ranges
// [0,65),[65,129),[129,193),[193,256), each indexing a different
// quarter-wave float table (D_8009A220/A420/A020/A620 respectively)
// with alternating positive/negative offsets and result negation
// (classic quadrant mirroring). Getting the if/else nesting order
// right (each level needed to test the ">=" case first, with the
// smaller-value case as the `else`, to match target's branch-away/
// fall-through layout) got everything else byte-identical, including
// the exact 36-instruction count - the only remaining gap is that
// target computes the two negative-offset addresses as "shift then
// negate" (sll then negu) while `ARRAY[-v0]`-style indexing always
// compiles as "negate then shift" (negu then sll) here, regardless of
// how the negation/subtraction is phrased (tried plain negative
// indexing, an explicit pre-shifted temp, and raw pointer
// subtraction - the last one additionally regressed to a completely
// different lui/addiu/subu address computation instead of the
// negu+lui+addu+lwc1 shape target and the other two approaches share).
// f32 func_150489B0(u8 arg0) {
//     s32 v0;
//     f32 f2;
//
//     if (arg0 >= 0x41) {
//         v0 = arg0;
//         if (v0 >= 0x81) {
//             if (v0 >= 0xC1) {
//                 f2 = D_8009A620[-v0];
//             } else {
//                 f2 = -D_8009A020[v0];
//             }
//         } else {
//             f2 = -D_8009A420[-v0];
//         }
//     } else {
//         f2 = D_8009A220[arg0];
//     }
//     return f2;
// }
f32 func_150489B0(u8 arg0) {
    s32 v0;
    f32 f2;

    if (arg0 >= 0x41) {
        v0 = arg0;
        if (v0 >= 0x81) {
            if (v0 >= 0xC1) {
                f2 = D_8009A220[0x100 - v0];
            } else {
                f2 = -D_8009A220[v0 - 0x80];
            }
        } else {
            f2 = -D_8009A220[0x80 - v0];
        }
    } else {
        f2 = D_8009A220[arg0];
    }
    return f2;
}
// NON-MATCHING: not convinced this is correct
// f32 func_150489B0(u8 arg0) {
//     f32 ret;
//
//     if (arg0 >= 65) {
//         if (arg0 >= 129) {
//             if (arg0 >= 193) {
//                 ret = D_8009A620[-arg0];
//             } else {
//                 ret = -D_8009A020[arg0];
//             }
//         } else {
//             ret = -D_8009A420[-arg0];
//         }
//     } else {
//         ret = D_8009A220[arg0];
//     }
//
//     return ret;
// }

f32 func_15048A40(u8 arg0) {
    return func_150489B0(arg0 - 0x40);
}

f32 func_15048A70(f32 arg0, f32 arg1) {
    f32 tmp = arg0 - arg1;
    if (tmp > 180.0f) {
        arg0 -= 360.0f;
    } else {
        if (tmp <= -180.0f) {
            arg1 -= 360.0f;
        }
    }
    return arg1 - arg0;
}

s32 func_15048AD0(s32 arg0, s32 arg1) {
    s32 temp_v0 = arg0 - arg1;
    if (temp_v0 >= 181) {
        arg0 = arg0 - 360;
    } else {
        if (temp_v0 < -179) {
            arg1 = arg1 - 360;
        }
    }
    return arg1 - arg0;
}
