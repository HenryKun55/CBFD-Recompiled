#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_15042D50(void) {
    D_800CBD64 = 0;
    func_15043384(0);
}

void func_15042D78( u8 arg0) {
    D_800CBD74 = arg0;
}

void func_15042D94(s32 arg0, s32 arg1, u8 arg2, s32 arg3, ...) {
    char *va;
    s32 buf[16];
    s32 i;

    D_800CBD74 = arg2;
    D_800CBD70 = arg0;
    D_800CBD72 = arg1;
    va = (char *) &arg3 + sizeof(arg3);
    for (i = 0; i < 16; i++) {
        va = (char *) (((int) va + 3) & ~3) + 4;
        buf[i] = *(s32 *) (va - 4);
    }
    func_15042ECC(arg3, buf);
}
void func_15042E3C(s32 arg0, ...) {
    char *va = (char *) &arg0 + sizeof(arg0);
    s32 buf[16];
    s32 i;

    for (i = 0; i < 16; i++) {
        va = (char *) (((int) va + 3) & ~3) + 4;
        buf[i] = *(s32 *) (va - 4);
    }
    func_15042ECC(arg0, buf);
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_70200/func_15042ECC.s")

void func_150432BC(f32 arg0) {
    D_800CBD80 = arg0;
}

void func_150432CC(s32 arg0, s32 arg1) {
    D_800CBD74 = D_800CBD74 | 1;
    D_800CBD74 = D_800CBD74;
    D_800CBD7C = arg1;
    D_800CBD78 = arg0;
}

void func_150432FC( s16 arg0, s16 arg1) {
    D_800CBD70 = arg0;
    D_800CBD72 = arg1;
}

void func_1504332C( u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_800CBD60 = arg0;
    D_800CBD61 = arg1;
    D_800CBD62 = arg2;
    D_800CBD63 = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_70200/func_15043384.s")

void func_15043A00(struct105 *arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        arg0->unk0 = arg1; // are these structs?
        arg0->unk4 = arg2;
        arg0->unkC = 0;
        arg0->unk8 = 0;
    }
}

// NON-MATCHING: semantics fully recovered and verified via isolated
// harness - a wrapping ring-buffer copy: repeatedly memcpy()s from a
// growing source pointer into arg0 at a position that wraps back to 0
// once it reaches the buffer size arg1, until the requested length
// (arg4, a 5th argument passed on the stack per o32 ABI) is exhausted;
// returns the final wrapped position. The loop body's control flow,
// every arithmetic operation, and the memcpy call all match target's
// shape exactly, but IDO consistently swaps which two callee-saved
// registers ($s3/$s4) hold the buffer-size vs. source-pointer locals
// regardless of declaration/usage order tried, and schedules the
// initial argument-to-register copies and callee-saved spills in a
// different order than target - a register-allocation/scheduling
// near-miss, not a semantic one.
// s32 func_15043A20(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
//     char *src = arg3;
//     void *dest = arg0;
//     s32 pos = arg2;
//     s32 remaining = arg4;
//     s32 chunk;
//
//     if (remaining != 0) {
//         do {
//             if (pos + remaining <= arg1) {
//                 chunk = remaining;
//             } else {
//                 chunk = arg1 - pos;
//             }
//             memcpy((char *) dest + pos, src, chunk);
//             pos += chunk;
//             if (pos >= arg1) {
//                 pos = 0;
//             }
//             src += chunk;
//             remaining -= chunk;
//         } while (remaining != 0);
//     }
//     return pos;
// }
s32 func_15043A20(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    s32 chunk;

    while (arg4 != 0) {
        if (arg1 < arg2 + arg4) {
            chunk = arg1 - arg2;
        } else {
            chunk = arg4;
        }
        memcpy((char *) arg0 + arg2, arg3, chunk);
        arg2 += chunk;
        arg3 = (char *) arg3 + chunk;
        arg4 -= chunk;
        if (arg2 >= arg1) {
            arg2 = 0;
        }
    }
    return arg2;
}
// NON-MATCHING: the read-side mirror of func_15043A20's ring-buffer
// copy loop (same wrap-at-arg1 logic, but here arg0 is the wrapping
// SOURCE and arg3 is the growing linear DESTINATION - i.e. this reads
// out of the ring buffer instead of writing into it). Semantics fully
// verified via isolated harness; hits the exact same near-miss gap
// already documented on func_15043A20 in this file: the initial
// zero-length check tests the freshly-loaded stack value instead of
// the register the loop condition actually lives in afterward (one
// extra `move`), and IDO's callee-saved register spill/assign order in
// the prologue doesn't match target's even though the FINAL register
// contents for bufSize/dest/ringBuf (s3/s4/s5) already agree exactly -
// 43 instructions vs target's 42, immune to every declaration-order
// variant tried (same conclusion reached on the write-side sibling).
// s32 func_15043AC8(void *arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4) {
//     s32 pos = arg2;
//     s32 remaining = arg4;
//     void *ringBuf = arg0;
//     s32 chunk;
//
//     if (remaining != 0) {
//         do {
//             if (pos + remaining <= arg1) {
//                 chunk = remaining;
//             } else {
//                 chunk = arg1 - pos;
//             }
//             memcpy(arg3, (char *) ringBuf + pos, chunk);
//             pos += chunk;
//             if (pos >= arg1) {
//                 pos = 0;
//             }
//             arg3 += chunk;
//             remaining -= chunk;
//         } while (remaining != 0);
//     }
//     return pos;
// }
s32 func_15043AC8(void *arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4) {
    s32 chunk;

    while (arg4 != 0) {
        if (arg2 + arg4 > arg1) {
            chunk = arg1 - arg2;
        } else {
            chunk = arg4;
        }
        memcpy(arg3, (char *) arg0 + arg2, chunk);
        arg2 += chunk;
        arg3 += chunk;
        arg4 -= chunk;
        if (arg2 >= arg1) {
            arg2 = 0;
        }
    }
    return arg2;
}

s32 func_15043B70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v0;

    if (arg3 != 0) {
        do {
            v0 = (arg1 < arg2 + arg3) ? arg1 - arg2 : arg3;
            arg2 += v0;
            if (arg2 >= arg1) {
                arg2 = 0;
            }
            arg3 -= v0;
        } while (arg3 != 0);
    }
    return arg2;
}
// NON-MATCHING: semantics fully recovered and verified via isolated
// harness - "enqueue a length-prefixed message into the ring buffer"
// built on func_15043A20: rejects a zero-length or NULL-data message,
// rounds (size+4) up to a multiple of 4 for word alignment, checks
// whether that much room exists between the write cursor (arg0->unkC)
// and the read cursor (arg0->unk8) - handling the wrapped vs
// not-wrapped cases separately - then writes a 4-byte
// (roundedSize-4) length header followed by the payload itself, each
// via its own func_15043A20 call, and stores the new write cursor.
// 60 of 59 target instructions, with the same branch-likely shapes
// and the same dead delay-slot duplicate load target has; the one
// remaining gap is that target spills the incoming size argument
// ($a2) to its ABI stack home and reloads it from there for the
// zero-length check, while every C phrasing tried keeps it in a
// register directly instead - the same "eager incoming-arg spill"
// pattern already seen elsewhere in this project, not reproducible
// from C source alone.
// s32 func_15043BB8(void *arg0, void *arg1, s32 arg2) {
//     s32 roundedSize;
//     s32 writePos;
//     s32 readPos;
//     s32 newPos;
//
//     if (arg2 == 0) {
//         return 0;
//     }
//     if (arg1 == NULL) {
//         return 0;
//     }
//
//     roundedSize = (arg2 + 4 + 3) & ~3;
//
//     writePos = *(s32 *) ((char *) arg0 + 0xC);
//     readPos = *(s32 *) ((char *) arg0 + 8);
//     if (writePos < readPos) {
//         if (writePos + roundedSize >= readPos) {
//             return 1;
//         }
//     } else {
//         if (writePos + roundedSize - *(s32 *) ((char *) arg0 + 4) >= readPos) {
//             return 1;
//         }
//     }
//
//     roundedSize -= 4;
//     newPos = func_15043A20(*(void **) arg0, *(s32 *) ((char *) arg0 + 4), writePos, &roundedSize, 4);
//     newPos = func_15043A20(*(void **) arg0, *(s32 *) ((char *) arg0 + 4), newPos, arg1, roundedSize);
//     *(s32 *) ((char *) arg0 + 0xC) = newPos;
//     return 0;
// }
s32 func_15043BB8(void *arg0, void *arg1, s32 arg2) {
    s32 writePos;
    s32 readPos;
    s32 newPos;

    if (arg2 != 0 && arg1 != NULL) {
        arg2 += 4;
        arg2 = (arg2 + 3) & ~3;

        writePos = *(s32 *) ((char *) arg0 + 0xC);
        readPos = *(s32 *) ((char *) arg0 + 8);
        if (writePos < readPos) {
            if (writePos + arg2 >= readPos) {
                return 1;
            }
        } else {
            if (writePos + arg2 - *(s32 *) ((char *) arg0 + 4) >= readPos) {
                return 1;
            }
        }

        arg2 -= 4;
        newPos = func_15043A20(*(void **) arg0, *(s32 *) ((char *) arg0 + 4), writePos, &arg2, 4);
        newPos = func_15043A20(*(void **) arg0, *(s32 *) ((char *) arg0 + 4), newPos, arg1, arg2);
        *(s32 *) ((char *) arg0 + 0xC) = newPos;
    }
    return 0;
}

s32 func_15043CA4(void *arg0, char *arg1, s32 arg2) {
    s32 pos;
    s32 msgLen;

    msgLen = 0;
    if (*(s32 *) ((char *) arg0 + 8) == *(s32 *) ((char *) arg0 + 0xC)) {
        return 0;
    }

    pos = func_15043AC8(*(void **) arg0, *(s32 *) ((char *) arg0 + 4), *(s32 *) ((char *) arg0 + 8), &msgLen, 4);
    if (arg2 < msgLen) {
        arg2 -= 1;
        pos = func_15043AC8(*(void **) arg0, *(s32 *) ((char *) arg0 + 4), pos, arg1, arg2);
        arg1[arg2] = 0;
        pos = func_15043B70(*(s32 *) arg0, *(s32 *) ((char *) arg0 + 4), pos, msgLen - arg2);
    } else {
        if (msgLen != 0) {
            pos = func_15043AC8(*(void **) arg0, *(s32 *) ((char *) arg0 + 4), pos, arg1, msgLen);
        }
    }

    *(s32 *) ((char *) arg0 + 8) = pos;
    return msgLen;
}
