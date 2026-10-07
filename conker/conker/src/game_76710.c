#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// wtf?
struct func_15049260_s {
    s32 w[9];
};

void func_150AAD98(struct func_15049260_s);

void func_15049260(struct func_15049260_s arg0) {
    func_150AAD98(arg0);
}

void func_150492CC(f32 arg0, f32 arg1, f32 arg2) {
    D_800CC220 = arg0;
    D_800CC224 = arg1;
    D_800CC228 = arg2;
    D_800CC22C = arg0 / 2;
    D_800CC230 = arg1 / 2;
    D_800CC234 = arg2 / 2;

    if (arg0 == 0.0f) {
        arg0 = D_80099080;
    }

    D_800CC238 = arg1 / arg0;
    D_800CC23C = arg2 / arg0;
}

// too many temp vars
// NON-MATCHING: full semantics recovered and verified via isolated
// harness - computes a plane equation (normal + D constant) from
// three 3D points via cross product: given P0=(arg0,arg1,arg2),
// P1=(arg3,arg4,arg5), P2=(arg6,arg7,arg8), cross = (P0-P1)x(P0-P2),
// writes cross.xyz to D_800CC210/214/218 and dot(cross,P0) to
// D_800CC21C. All 9 args arrive via $a0-$a3 plus 5 stack words (not
// $f12/$f14), confirming the real source used old-style/untyped
// parameter passing for the floats - reproduced here by declaring the
// params `s32` and reinterpret-casting each with `*(f32 *) &argN`
// (an actual K&R old-style parameter-list definition hits a hard cfe
// expansion-limit error in this IDO build with 9 parameters, so this
// is the safe equivalent). 58 vs target's 57 instructions: content,
// operand order and every cross/dot term match exactly; the sole gap
// is that this reconstruction's compile keeps arg0/arg1 in $f-regs
// via two `mtc1` register-to-register moves (since they're each used
// twice) where target always round-trips through memory (`lwc1`) for
// every value, never `mtc1` - tried hoisting all 9 reinterpreted
// values into named locals up front and marking the cast volatile,
// both made it worse (39+ and pointer-indirect addressing
// respectively), so this is the closest form found.
// void func_15049350(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
//     f32 x1, y1, z1;
//     f32 x2, y2, z2;
//     f32 cx, cy, cz;
//
//     x1 = *(f32 *) &arg0 - *(f32 *) &arg3;
//     y1 = *(f32 *) &arg1 - *(f32 *) &arg4;
//     z1 = *(f32 *) &arg2 - *(f32 *) &arg5;
//     x2 = *(f32 *) &arg0 - *(f32 *) &arg6;
//     y2 = *(f32 *) &arg1 - *(f32 *) &arg7;
//     z2 = *(f32 *) &arg2 - *(f32 *) &arg8;
//
//     cx = y1 * z2 - z1 * y2;
//     D_800CC210 = cx;
//     cy = -x1 * z2 + z1 * x2;
//     D_800CC214 = cy;
//     cz = x1 * y2 - y1 * x2;
//     D_800CC218 = cz;
//     D_800CC21C = cx * *(f32 *) &arg0 + cy * *(f32 *) &arg1 + cz * *(f32 *) &arg2;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_76710/func_15049350.s")
