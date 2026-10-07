#include <ultra64.h>

#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513B5E0.s")

// NON-MATCHING: 31 of 32 instructions match exactly (including the
// exact stack frame size 0x20 and the exact byte-spill offset 0x1B for
// the flag var across the D_80089C18[idx](arg0) call). The single
// remaining diff is purely cosmetic: target reloads the spilled flag
// via `lbu` (zero-extend) while every C typing tried here (s8, u8,
// explicit (u8) casts at each use, several declaration orders/positions
// among v0/v1/idx) produces `lb` (sign-extend) instead - functionally
// identical since the value is only ever 0 or 1, but not a byte match.
// Declaring the flag `u8` instead of `s8` does NOT fix the reload (still
// picks lb over lbu in this build) and additionally regresses register
// allocation elsewhere (home register becomes $v0 instead of $v1, plus
// an extra `move` and a larger 0x28 frame), so `s8` remains the closer
// match of the two despite still not being byte-perfect.
// void func_1513B798(void *arg0) {
//     s32 v0;
//     s8 v1 = 0;
//     s8 idx;
//
//     if (*(u8 *) ((char *) arg0 + 0x10) & 1) {
//         *(s16 *) ((char *) arg0 + 0x14) -= D_800BE9E4;
//         if (*(s16 *) ((char *) arg0 + 0x14) < 0) {
//             v1 = 1;
//         }
//     }
//     if (v1 == 0) {
//         idx = *(s8 *) ((char *) arg0 + 0x11);
//         if (idx != -1) {
//             v0 = D_80089C18[idx](arg0);
//             if (v0 == 0) {
//                 v1 = 1;
//             }
//         }
//     }
//     if (v1 != 0) {
//         func_1516972C(arg0);
//     }
// }
extern s32 (*D_80089C18[])(void *);

void func_1513B798(void *arg0) {
    s32 v0;
    u8 v1 = 0;
    s8 idx;

    if (*(u8 *) ((char *) arg0 + 0x10) & 1) {
        *(s16 *) ((char *) arg0 + 0x14) -= D_800BE9E4;
        if (*(s16 *) ((char *) arg0 + 0x14) < 0) {
            v1 = 1;
        }
    }
    if (!v1) {
        idx = *(s8 *) ((char *) arg0 + 0x11);
        if (idx != -1) {
            v0 = D_80089C18[idx](arg0);
            if (v0 == 0) {
                v1 = 1;
            }
        }
    }
    if (v1) {
        func_1516972C(arg0);
    }
}
// NON-MATCHING: full semantics recovered and verified via isolated
// harness (correct register roles for s0=arg1/a3=buf were only reached
// after dropping the truly-dead 4th parameter - target never spills it,
// confirming this is really a 3-argument function despite the raw asm
// initially looking like it reassigns $a3), but the final 3-command
// buffer-building tail does not reproduce target's exact register
// choreography: target increments a single register ($a3) in place
// three times and takes snapshot copies ($v1/$a0/$a1) of it before/after
// each increment for the deferred "write word 1 of the previous command"
// pattern, whereas every C phrasing tried here (flat pointer + separate
// += statements, a typed 2-word struct pointer with gfx++, three named
// snapshot locals assigned in the same order as target) gets IDO to
// chain each new position off the PREVIOUS snapshot register instead of
// re-deriving it from the one shared base register - mathematically
// identical addresses, 3 fewer instructions (72 vs target's 75) because
// the extra "v1 = a3" copy and one dead duplicate load target's own
// compiler left in are never reproduced.
// void *func_1513B83C(char *arg0, void *arg1, s16 arg2) {
//     s8 v0;
//     s32 result;
//
//     if (!(*(u8 *) ((char *) arg1 + 0x10) & 2) ||
//         (*(u8 *) ((char *) arg1 + 0x49) & (1 << arg2))) {
//         v0 = *(s8 *) ((char *) arg1 + 0x12);
//     } else {
//         return arg0;
//     }
//     if (v0 != -1) {
//         result = D_80089C28[v0](arg1, arg2);
//         if (result == 0) {
//             return arg0;
//         }
//     }
//     // append 3 command words at arg0; D_800BE9C0 (u8) re-read fresh
//     // each time it's referenced (never cached in a local)
//     *(u32 *) arg0 = 0xDA380003;
//     *(u32 *) (arg0 + 4) = (u32) ((char *) arg1 + (D_800BE9C0 << 6) + 0x78);
//     arg0 += 8;
//     *(u32 *) arg0 = 0xDB060004;
//     *(u32 *) (arg0 + 4) = *(u32 *) ((char *) arg1 + (D_800BE9C0 << 4) + (arg2 << 2) + 0x58);
//     arg0 += 8;
//     *(u32 *) arg0 = 0xDE000000;
//     *(u32 *) (arg0 + 4) = *(u32 *) ((char *) arg1 + 0x54);
//     arg0 += 8;
//     return arg0;
// }
struct func_1513B83C_s {
    u8 pad0[0x10];
    u8 unk10;
    u8 pad11;
    s8 unk12;
    u8 pad13[0x49 - 0x13];
    u8 unk49;
    u8 pad4A[0x54 - 0x4A];
    Gfx *unk54;
    Gfx *unk58[2][4];
    Mtx unk78[2];
};

extern s32 (*D_80089C28[])(struct func_1513B83C_s *, s16);

Gfx *func_1513B83C(Gfx *gdl, struct func_1513B83C_s *arg1, s16 arg2) {
    if ((arg1->unk10 & 2) && !(arg1->unk49 & (1 << arg2))) {
        return gdl;
    }
    if (arg1->unk12 != -1) {
        if (D_80089C28[arg1->unk12](arg1, arg2) == 0) {
            return gdl;
        }
    }
    gSPMatrix(gdl++, &arg1->unk78[D_800BE9C0], 2);
    gSPSegment(gdl++, 1, arg1->unk58[D_800BE9C0][arg2]);
    gSPDisplayList(gdl++, arg1->unk54);
    return gdl;
}

s32 func_1513B968(s32 arg0, s32 arg1) {
    // FIXME: &arg0->unk_120[D_800BE9C0]
    func_150A7B80(arg0 + 120 + (D_800BE9C0 << 6));
    return 1;
}

void func_1513B9A8(struct132 *arg0) {
    func_100043B4(arg0->unk4C, 4);
    func_15169804(arg0);
}

void func_1513B9DC(struct132 *arg0) {
    func_100043B4(arg0->unk4C, 4);
    func_15169824(arg0);
}

void func_1513BA10(struct132 *arg0) {
    D_80089C44[arg0->unk48]();
}

void func_1513BA44(struct132 *arg0) {
    D_80089C54[arg0->unk48]();
}

// NON-MATCHING: another confirmed instance of the "u8 argument masked
// as literally the first 2 instructions" hard pattern (see
// func_1510550C-style cases catalogued this session) - target does
// `andi $t6,$a2,0xff` / `or $a2,$t6,$zero` before even saving $ra,
// immediately after spilling the untouched incoming $a2 to its stack
// home (`sw $a2,0x20($sp)`), then only afterward reads the dispatch
// selector at arg0+0x48. Every C phrasing tried (`arg2 = (u8) arg2;`,
// `arg2 &= 0xFF;`, placed as the very first statement before the
// selector read) gets IDO to both drop the now-apparently-dead
// incoming-arg stack spill and defer the actual mask instruction into
// the first branch's delay slot instead - one instruction later and in
// the wrong position, same gap as every other function in this family.
// void func_1513BA78(void *arg0, void *arg1, s32 arg2) {
//     u8 sel;
//
//     arg2 = (u8) arg2;
//     sel = *(u8 *) ((char *) arg0 + 0x48);
//     if (sel == 1) {
//         func_15109064(arg0, arg1, arg2);
//     } else if (sel == 2) {
//         func_151BA468(arg0, arg1, arg2);
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513BA78.s")

s32 func_1513BAD4(s32 arg0, s32 arg1) {
    return 0;
}

// NON-MATCHING: full field-level semantics recovered and verified via
// isolated harness - builds a 0x39-byte config buffer (individually
// typed/valued fields at every offset) plus a separate 5-float source
// array, passes the buffer to func_1513B5E0(buf, 1, 0x14, 0xFF, 1) (a
// 5-arg call - the 5th argument is what the raw asm's mysterious
// `sw $t9, 0x10($sp)` turned out to be: the o32 ABI's stack slot for a
// 5th call argument, not a separate local), then either calls
// func_1516972C() or memcpys the float array into the returned
// pointer's (unk50 + 0xF8) location depending on that returned
// pointer's own unk50 field. Total frame size (0x78), field values,
// field types/widths, and every constant-load/store instruction's
// program ORDER all match exactly (including the odd non-sequential
// float-store order 0,1,3,4,2 that only two separate scalar-like writes
// in that literal order reproduce). The one remaining gap: every local
// layout tried lands the returned-pointer spill-across-calls slot at a
// different stack address than target's (target keeps it at the very
// top of the frame, 0x74; every C structure tried here places it lower,
// pushing the two data blocks 4 bytes higher than target throughout).
// void *func_1513BAE8(void) {
//     u8 st[0x39];
//     f32 farr[5];
//     s32 t1;
//     void *v0;
//
//     st[1] = 2;
//     st[2] = 5;
//     *(s16 *) (st + 4) = 0x12C;
//     *(s32 *) (st + 0x30) = 9;
//
//     farr[0] = 0.0f;
//     farr[1] = 0.0f;
//     farr[3] = 0.0f;
//     farr[4] = 0.0f;
//     farr[2] = 0.0f;
//     st[0] = 0;
//     *(s32 *) (st + 0x34) = 0x1AE;
//     *(s32 *) (st + 8) = 1;
//     *(s32 *) (st + 0xC) = 0x220205;
//     *(s32 *) (st + 0x10) = 0x40600;
//     st[0x24] = 0;
//     st[0x25] = 0;
//     *(s32 *) (st + 0x14) = 1;
//     *(s32 *) (st + 0x18) = 0x36;
//     *(s32 *) (st + 0x1C) = 0x80;
//     *(s32 *) (st + 0x20) = 0x20;
//     st[0x38] = 3;
//
//     v0 = func_1513B5E0(st, 1, 0x14, 0xFF, 1);
//     if (v0 != NULL) {
//         t1 = *(s32 *) ((char *) v0 + 0x50);
//         if (t1 == 0x1180) {
//             memcpy((char *) v0 + t1 + 0xF8, farr, 0x14);
//         } else {
//             func_1516972C();
//         }
//     }
//     return v0;
// }
struct func_1513BAE8_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    s16 unk4;
    s16 pad6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 unk24;
    u8 unk25;
    u8 pad26[0xA];
    s32 unk30;
    s32 unk34;
    u8 unk38;
};
struct func_1513BAE8_t {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[0xA4];
    u8 unkF8[1];
};
extern void *func_1513B5E0(struct func_1513BAE8_s *, s32, s32, s32, s32);
extern void *memcpy(void *, const void *, unsigned int);

void *func_1513BAE8(void) {
    void *v0;
    struct func_1513BAE8_s st;
    f32 farr[5];

    st.unk1 = 2;
    st.unk2 = 5;
    st.unk4 = 0x12C;
    st.unk30 = 9;
    farr[0] = 0.0f;
    farr[1] = 0.0f;
    farr[3] = 0.0f;
    farr[4] = 0.0f;
    farr[2] = 0.0f;
    st.unk0 = 0;
    st.unk34 = 0x1AE;
    st.unk8 = 1;
    st.unkC = 0x220205;
    st.unk10 = 0x40600;
    st.unk24 = 0;
    st.unk25 = 0;
    st.unk14 = 1;
    st.unk18 = 0x36;
    st.unk1C = 0x80;
    st.unk20 = 0x20;
    st.unk38 = 3;
    v0 = func_1513B5E0(&st, 1, 0x14, 0xFF, 1);
    if (v0 != NULL) {
        if (*(s32 *)((u8 *)v0 + 0x50) != 0x1180) {
            func_1516972C(v0);
        } else {
            memcpy(&((struct func_1513BAE8_t *)v0)->unkF8[((struct func_1513BAE8_t *)v0)->unk50], farr, 0x14);
        }
    }
    return v0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513BBFC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513BEB0.s")
