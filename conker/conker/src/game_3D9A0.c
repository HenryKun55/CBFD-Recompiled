#include <ultra64.h>
#include "functions.h"
#include "variables.h"


// NON-MATCHING: mips_to_c reconstruction, hand-typed. Would-be name:
// resetSlotState (resets a small state buffer, clears a resource's default
// value, and clears a status flag - only referenced from the function-
// pointer table in asm/data/2275E0.data.s, exact subsystem unconfirmed).
// Compiles to the same instruction sequence as target except IDO -O2 always
// elides the explicit "v0 = 0" materialization target uses for two of the
// three sb's (uses the zero register directly for all three instead),
// making the reconstruction 4 bytes (1 instruction) short - tried plain
// literals, a shared local, and a chained assignment, all collapse to the
// same (wrong) codegen.
extern u8 D_800D9950[3];
void *func_151149AC();

void func_150104F0(void) {
    D_800D9950[0] = D_800D9950[1] = D_800D9950[2] = 0;
    *(f32 *)((char *) func_151149AC(0xF6) + 0x7C) = 2.0f;
    D_80088980 = 0;
}
// extern u8 D_800D9950[3];
// void *func_151149AC();
//
// void func_150104F0(void) {
//     D_800D9950[1] = 0;
//     D_800D9950[0] = 0;
//     D_800D9950[2] = 0;
//     *(f32 *)((char *) func_151149AC(0xF6) + 0x7C) = 2.0f;
//     D_80088980 = 0;
// }

void func_15010538(struct127 *arg0) {
    struct175 tmp;
    struct37 *temp_v0;

    func_15161E24(arg0, 2, 2, 300, 30, 100, 200, 255, 255, 1);
// FAKEMATCH but works...
dummy_label_927029:
    tmp.unk0 = arg0;
    tmp.unk4 = arg0->unique_id;
    tmp.unk6 = 0;
    tmp.unk8 = 0;
    tmp.unkA = 0;

    temp_v0 = func_15149130(300, -1, 80, -1, 0, 61, 12, 255, 1);
    if (temp_v0 != NULL) {
        memcpy(&temp_v0->unk28, &tmp, 12); // memcpy
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_3D9A0/func_15010600.s")
// NON-MATCHING: addresses are wrong :(
// void func_15010600(void) {
//     s32 i;
//
//     for (i = 0; i < 11; i++) {
//         D_800D9930[i] = D_800D9920[i] = 0;
//     }
// }
