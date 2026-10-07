#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15104520(struct108 *arg0) {
    f32 temp_f0;

    if ((arg0->unk6FC != 0) || (arg0->unk6C8 == 0)) {
        arg0->unk348 = 117.0f;
        arg0->unk34C = 117.0f;
        arg0->unk374 = 370.0f;
        arg0->unk190 = 77.0f;
    }
    if ((arg0->unk3D0->xz_velocity < 50.0f) && (arg0->unk3E8 == 0)) {
        temp_f0 = arg0->unk374;
        if ((0.5f * temp_f0) < (*(f32 *)arg0->pad370 - temp_f0)) {
            func_15128774(arg0, arg0->unk3D0);
        }
    }
}
