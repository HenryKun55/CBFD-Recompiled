#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void *func_1515C2F0(void *arg0, void *arg1, void *arg2, void *arg3, u8 arg4, s32 arg5) {
    void *v1;

    *(s32 *) ((char *) arg0 + 0x10) = 10;
    v1 = func_15147A80(arg0, (char *) arg1 + 0x40, 0x10, 8, 8, 8, 0, 0, arg3, arg4, arg5);
    if (v1 == 0) {
        return 0;
    }
    memcpy(*(void **) ((char *) v1 + 0x98), arg2, 0x3C);
    return v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1897A0/func_1515C388.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1897A0/func_1515C534.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1897A0/func_1515C6F4.s")
// NON-MATCHING: register-allocation gap only, logic is byte-verified correct.
// The reconstruction below produces every instruction target has EXCEPT
// that computing "temp_t1 = temp_v1 + arg0->unk2E * 0x10" once and reusing
// it for the 3 s32 field stores forces IDO to allocate that address into
// $a1 (clobbering the arg1 parameter register), requiring a spurious
// "move $a2, $a1" at function entry not present in target. Target instead
// keeps arg1 in $a1 for the whole function and reaches the 3 stores via
// $at (used twice, back-to-back, as a throwaway reload target) plus one
// normal temp register - a specific IDO register-pressure choice that
// could not be reproduced by varying cast forms, declaration order, or
// whether the address is named vs recomputed per-store. See func_1515D030
// (the matching pop counterpart to this push) for the struct-offset style
// used here.
#pragma GLOBAL_ASM("asm/nonmatchings/game_1897A0/func_1515CF9C.s")
// s32 func_1515CF9C(void *arg0, void *arg1) {
//     s32 temp_v1;
//     s8 temp_v0;
//     void *temp_t1;
//
//     temp_v0 = arg0->unk2C;
//     if ((s32) temp_v0 < (arg0->unk25 - 1)) {
//         temp_v1 = arg0->unk94;
//         arg0->unk2C = (s8) (temp_v0 + 1);
//         temp_t1 = temp_v1 + (arg0->unk2E * 0x10);
//         temp_t1->unk0 = (s32) arg0->unk10;
//         temp_t1->unk4 = (s32) arg0->unk14;
//         temp_t1->unk8 = (s32) arg0->unk18;
//         (temp_v1 + (arg0->unk2E * 0x10))->unkC = (f32) arg1->unk8;
//         arg0->unk2E = (s8) (arg0->unk2E + 1);
//         if (arg0->unk25 == arg0->unk2E) {
//             arg0->unk2E = (u8)0;
//         }
//     } else {
//         arg1->unk39 = (u8)-1;
//     }
//     return 1;
// }

s32 func_1515D030(void *arg0, void *arg1) {
    s8 v0;
    s32 v1 = 1;

    v0 = *(s8 *) ((char *) arg0 + 0x2C);
    if (v0 >= 3) {
        *(s8 *) ((char *) arg0 + 0x2C) = v0 - 1;
        *(s8 *) ((char *) arg0 + 0x2E) = *(s8 *) ((char *) arg0 + 0x2E) - 1;
        if (*(s8 *) ((char *) arg0 + 0x2E) < 0) {
            *(s8 *) ((char *) arg0 + 0x2E) = *(u8 *) ((char *) arg0 + 0x25) - 1;
        }
    } else {
        v1 = 0;
    }
    return v1;
}

// NON-MATCHING: register-choice gap only in the dead-branch prologue.
// The reconstruction below reproduces target's full instruction count,
// stack layout (sp30/sp34/sp38/sp3C at the same offsets, 0x40 frame),
// branch structure (including the always-false "temp_v0 < 0" dead branch
// from the unsigned-byte-load-then-signed-compare pattern - see
// func_1506196C/func_1513532C/func_150770E4 for the same hard category),
// and the shared-merge tail (no early "return 0" duplicate-epilogue; the
// null check is written as "if (ptr) memcpy(...); return ptr;" so IDO
// reuses the same v1-carries-0-through-delay-slot merge target does).
// The one remaining gap: target computes the raw arg0->unk18 load into
// $t7 and the masked comparison value into $v0 (reusing $t8 for the later
// arg0 reload), while this reconstruction gets the same 5 instructions
// with the same opcodes/immediates but $v0/$v1/$t7 chosen instead of
// $t7/$v0/$t8 - not reproducible via struct-vs-raw-pointer field access,
// OR-operand order, or union-based byte/word aliasing for sp38.
struct func_1515D088_s {
    void *ptr;
    f32 f;
    u8 b;
};

void *func_1515D088(void *arg0) {
    void *ret;
    struct func_1515D088_s s;
    s32 t;

    t = (s.b = *(s32 *) ((char *) arg0 + 0x18));
    if (t < 0 || t >= 2) {
        return 0;
    }
    s.ptr = arg0;
    s.f = 0.0f;
    ret = func_151491F4(0x12C, -1, 0x11, 0, 0xD, 0xC, 0xFF, 1);
    if (ret) {
        memcpy((char *) ret + 0x28, &s, 0xC);
    }
    return ret;
}
// s32 func_1515D088(void *arg0) {
//     s32 sp3C;
//     s8 sp38;
//     f32 sp34;
//     void *sp30;
//     s32 temp_t7;
//     s32 temp_v0;
//     void * temp_v0_2;
//     s32 phi_v1;
//
//     temp_t7 = arg0->unk18;
//     temp_v0 = temp_t7 & 0xFF;
//     sp38 = (s8) temp_t7;
//     if ((temp_v0 < 0) || (temp_v0 >= 2)) {
//         return 0;
//     }
//     sp30 = arg0;
//     sp34 = 0.0f;
//     temp_v0_2 = func_151491F4(0x12C, -1, 0x11, 0, 0xD, 0xC, 0xFF, 1);
//     phi_v1 = &temp_v0_2;
//     if (temp_v0_2 != 0) {
//         sp3C = temp_v0_2;
//         memcpy(temp_v0_2->unk28, &sp30, 0xC); // memcpy
//         phi_v1 = sp3C;
//     }
//     return phi_v1;
// }

// fat struct
#pragma GLOBAL_ASM("asm/nonmatchings/game_1897A0/func_1515D130.s")
