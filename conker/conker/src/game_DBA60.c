#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_150AE5B0(struct108 *arg0) {
    if ((D_800D2E4C->unk4 & 0x80) == 0) {
        if (func_1509BE40(0, 0x2000, 0xBB) != -1) {
            if (func_15123934(arg0, arg0->unk2C, 0, arg0->unk134, 8) != 0) {
                arg0->unk84 |= 0x1000000;
                func_151254F4(arg0, D_800CC335 - 1);
            }
        } else if (func_151239CC(arg0, 8) != 0) {
            func_151254F4(arg0, 0);
        }
    }
    arg0->unk84 &= -0x4001;
    if ((D_800D2E4C->unk1 & 4) == 0) {
        if (func_1509BE40(1, 0x2000, 0x95, func_1509BE40(0, 0x2014, 0xB7) | 0x2000) != 0) {
            arg0->unk84 |= 0x1000000;
            if (((arg0->unk2C & 1) != 0) && (func_15123934(arg0, arg0->unk2C, 0, arg0->unk134, 0) != 0)) {
                arg0->unk1B4 = 3;
                arg0->unk84 &= -5;
                func_15124B18(arg0);
            }
        } else if (func_151239CC(arg0, 0) != 0) {
            func_15124B18(arg0);
            arg0->unk84 &= 0xFEFFFFFF;
        }
    }
    if (func_1509BE40(1, 0x4082, 6, 0x9000) != 0) {
        arg0->unk84 |= 0x10000;
    } else {
        arg0->unk84 &= 0xFFFEFFFF;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_DBA60/func_150AE790.s")
// some funky xor going on
#pragma GLOBAL_ASM("asm/nonmatchings/game_DBA60/func_150AEB9C.s")

void func_150AECCC(struct42 *arg0) {
    arg0->unk96 = arg0->unk96 + (arg0->unk94 * D_800BE9E4);
    if (arg0->unk96 >= 0x1401) {
        arg0->unk96 = 0x1400;
    }
    arg0->unk9E = arg0->unk9E - ((s32) arg0->unk96 >> 8);
    arg0->unkA4 = arg0->unkA4 + D_800BE9E4;
    if (arg0->unkA4 >= 0x1A) {
        arg0->unkA4 = 0x19;
    }
}

void func_150AED4C(struct114 *arg0) {
    arg0->unk34 += arg0->unk14 * D_800BE9E4;
    if (arg0->unk2A < arg0->unk34) {
        arg0->unk3A = 70;
        arg0->unk34 = arg0->unk2A;
    }
    arg0->unk36 = arg0->unk34;
}

// NON-MATCHING: mips_to_c reconstruction, hand-typed. Scales arg0->unk1C
// by 8, clamps to 0xFF, and stores it to (*arg0->unk98)+0x1B; the
// clamp-check's else-branch (return 0) is provably unreachable in target
// (it tests a value already masked to a byte against >=0, always true),
// same class of dead-branch issue as func_1506196C above - reproducing it
// explicitly still left register allocation different throughout.
struct func_150AED9C_t { char pad[0x1B]; u8 unk1B; };
struct func_150AED9C_s { char pad[0x1C]; s16 unk1C; char pad2[0x98 - 0x1E]; struct func_150AED9C_t *unk98; };

s32 func_150AED9C(struct func_150AED9C_s *arg0) {
    s32 v;
    struct func_150AED9C_t *t = arg0->unk98;

    v = arg0->unk1C * 8;
    if (v >= 0x100) {
        v = 0xFF;
    }
    t->unk1B = v;
    if ((u8)v < 0) {
        return 0;
    }
    return 1;
}
// s32 func_150AED9C(void *arg0) {
//     s16 unk1C = *(s16 *) ((char *) arg0 + 0x1C);
//     void *unk98 = *(void **) ((char *) arg0 + 0x98);
//     s32 v1 = unk1C * 8;
//     u8 byteVal;
//
//     if (v1 >= 0x100) {
//         v1 = 0xFF;
//     }
//     byteVal = v1;
//     if (byteVal >= 0) {
//         *((u8 *) unk98 + 0x1B) = byteVal;
//     } else {
//         return 0;
//     }
//     return 1;
// }

s32 func_150AEDD8(struct202 *arg0) {
    if (arg0->unk1C < 0x20) {
        arg0->unk28 = arg0->unk1C * 8;
    }
    return 1;
}

// NON-MATCHING: replaces an earlier unverified auto-mips_to_c dump
// (mistyped fields as pointers, guessed a wrong 3-arg call signature
// for func_1516972C) with a hand-verified reconstruction confirmed via
// isolated harness. Semantics: at (char *) arg0 + 0x28 sits a small
// "cfg" record (s32 id at +0, u8 type at +4). If arg2==0x2D, merges
// arg1's own id/type pair into cfg depending on which of arg1's two id
// candidates (+0 or +4) matches cfg's current id. If arg2==0, calls
// func_1516972C(arg0) (single argument only - confirmed by the actual
// raw asm, which sets only $a0 before the jal) when cfg and arg1
// either share an id or share a type byte.
//
// Every branch opcode/operand and the entire byte-masked-arg2 prologue
// (target's genuine `sw a2,0x20(sp)` spill-before-mask, previously
// undocumented as solvable - see func_15134C98/func_1513BA78's still-
// unresolved versions of this exact prologue shape) reproduce exactly
// once arg2 is typed as a bare `u8` parameter instead of `s32` with an
// internal cast. The one remaining gap: for the "arg1 id matches cfg's
// second id candidate" branch, target hoists the epilogue's `lw ra`
// into that branch's own delay slot (since it jumps straight to the
// function's single-exit label, bypassing the other exit's shared
// ra-reload), while every source form tried here (implicit trailing
// fallthrough, explicit early `return;`) puts the actual field store
// in that delay slot instead and leaves the ra-reload for the shared
// exit - a pure delay-slot-scheduling choice, immune to restructuring.
#pragma GLOBAL_ASM("asm/nonmatchings/game_DBA60/func_150AEDF8.s")
// void func_150AEDF8(void *arg0, void *arg1, u8 arg2) {
//     char *cfg;
//
//     cfg = (char *) arg0 + 0x28;
//     if (arg2 == 0x2D) {
//         if (*(s32 *) arg1 == *(s32 *) cfg) {
//             *(s32 *) cfg = *(s32 *) ((char *) arg1 + 4);
//             *(u8 *) (cfg + 4) = *(u8 *) ((char *) arg1 + 9);
//             return;
//         }
//         if (*(s32 *) ((char *) arg1 + 4) == *(s32 *) cfg) {
//             *(s32 *) cfg = *(s32 *) arg1;
//             *(u8 *) (cfg + 4) = *(u8 *) ((char *) arg1 + 8);
//         }
//         return;
//     }
//     if (arg2 == 0) {
//         if (*(s32 *) arg1 == *(s32 *) cfg || *(u8 *) (cfg + 4) == *(u8 *) ((char *) arg1 + 4)) {
//             func_1516972C(arg0);
//         }
//     }
// }
