#include <ultra64.h>

#include "functions.h"
#include "variables.h"

#include "macros.h"

void func_1502AAF0(void) {
}

void func_1502AAF8(s32 arg0) {
}

typedef struct {
    s32 a;
    s32 b;
} func_1502AB04_pair;

struct func_1502AB04_s {
    s32 x;
    s32 y;
    func_1502AB04_pair z;
};

extern struct func_1502AB04_s D_800C3D68[16];

void func_1502AB04(s32 n, func_1502AB04_pair *src, s32 arg2, s32 arg3) {
    u32 i;
    s32 m = n;

    if (m != 0) {
        bcopy(&D_800C3D68[m], &D_800C3D68[0], (16 - m) * sizeof(struct func_1502AB04_s));
    }
    for (i = 16U - m; i < 16; i++) {
        D_800C3D68[i].z = *src++;
        D_800C3D68[i].y = arg2;
        D_800C3D68[i].x = arg3;
        arg3 += 8;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502AC88.s")
// NON-MATCHING: 70 vs target's 71 instructions. Target keeps the loop's
// base pointer in a callee-saved $s2 (extra save/restore pair) and caches
// arg2<<3 back to its own stack slot after the func_10004514 call, where
// this reconstruction keeps the base pointer in a temp register and never
// needs to re-derive arg2<<3; also a stable beqz-vs-blez branch-type
// difference on the initial zero-trip-count guard for the loop IDO
// generates from the single `for` loop below (both correct, no reachable
// source phrasing changed it). Semantics confirmed identical.
struct func_1502AF04_s {
    s32 a;
    s32 b;
};

void *func_1502AF04(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 addr;
    s32 dst;
    s32 i;
    struct func_1502AF04_s *p;

    arg2 <<= 3;
    addr = arg0 + arg2;
    dst = (arg1 + 8) & ~0xF;
    func_10004514(addr & ~0xF, dst, ((addr & 0xE) + (arg3 << 3) + 0xF) & ~0xF, 1);
    p = (struct func_1502AF04_s *)(((arg1 + 8) & ~0xF) + (addr & 0xF));
    for (i = 0; i != arg3; i++) {
        p[i].a += arg0;
    }
    return (void *)(((arg1 + 8) & ~0xF) + (addr & 0xF));
}
// void *func_1502AF04(void *arg0, void *arg1, s32 arg2, s32 arg3) {
//     void *base;
//     void *p;
//     s32 i;
//
//     base = (void *) (((s32) arg0 + (arg2 << 3)) & ~0xF);
//     p = (void *) ((((s32) arg1 + 8) & ~0xF) + (((s32) arg0 + (arg2 << 3)) & 0xF));
//
//     func_10004514(base,
//                   (void *) (((s32) arg1 + 8) & ~0xF),
//                   ((((s32) arg0 + (arg2 << 3)) & 0xE) + (arg3 << 3) + 0xF) & ~0xF,
//                   1);
//
//     for (i = 0; i < arg3; i++) {
//         *(s32 *) ((char *) p + i * 8) += (s32) arg0;
//     }
//
//     return p;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B020.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B110.s")
// Loads data from the ROM into `dest` and returns its size. The low 28 bits of
// sizeAndFlags are the size, rounded up to an even number of bytes and capped at
// maxSize when that's given (non-zero). If its flags (bits 28-30) are 1, the data
// is compressed: it is read into a temporary buffer, decompressed into `dest`
// (func_10006240, with the work area D_8003809C, as the boot code does for the game
// code), and the buffer freed. The first word of compressed data holds its
// decompressed size (bit 31 aside); if the decompressor produced a different size,
// the error code 0x0C000036 goes in D_8003C8E0 and func_150AD770 is called. Returns
// 0 if the buffer couldn't be allocated. The DMA (func_10004514) always moves a
// multiple of 16 bytes.
u32 func_1502B224(s32 romAddr, s32 *dest, s32 sizeAndFlags, u32 maxSize) {
    s32 *buffer;
    u32 size;

    size = ((sizeAndFlags & 0x0FFFFFFF) + 1) & ~1;
    if ((maxSize != 0) && (maxSize < size)) {
        size = maxSize;
    }
    if ((sizeAndFlags & 0x70000000) == 0x10000000) {
        s32 expectedSize;

        buffer = allocate_memory(size, 1, 2, 2);
        if (buffer == NULL) {
            return 0;
        }
        func_10004514(romAddr, buffer, (size + 0xF) & ~0xF, 1);
        expectedSize = *buffer & 0x7FFFFFFF;
        if ((size = func_10006240(buffer, dest, D_8003809C)) != expectedSize) {
            D_8003C8E0 = 0x0C000036;
            func_150AD770();
        }
        func_10004074(buffer);
    } else {
        func_10004514(romAddr, dest, (size + 0xF) & ~0xF, 1);
    }
    return size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B350.s")
struct func_1502B4A8_s {
    s32 offset;
    u32 flags;
};

s32 func_1502B4A8(struct func_1502B4A8_s *arg0, s32 arg1) {
    s32 i;

    if (arg1 == 0) {
        while ((arg0[arg1++].flags & 0x80000000) == 0) {
        }
    }
    for (i = 0; i < arg1; i++) {
        arg0[i].flags &= 0x0FFFFFFF;
        if ((arg0[i].offset == -1) || (arg0[i].flags == 0)) {
            arg0[i].offset = 0;
        } else {
            arg0[i].offset += (s32) arg0;
        }
    }
    return arg1;
}
#include <stdarg.h>
extern u8 D_AB1950;
s32 func_1502AC88(s32 offset, s32 arg, s32 *out);
s32 func_1502B350(s32 offset, s32 arg, s32 *out);

s32 func_1502B5C8(s32 *status, s32 count, ...) {
    va_list args;
    s32 offset;
    s32 arg;
    s32 sp40;
    s32 *p;
    s32 sp38;
    s32 ret;

    p = &sp40;
    if (status != NULL) {
        p = status;
    }
    *p = 1;
    offset = (s32) &D_AB1950;
    va_start(args, count);
    for (; count != 0; count--) {
        arg = va_arg(args, s32);
        if (*p != 0) {
            offset += func_1502AC88(offset, arg, &sp38);
        }
        *p = sp38 & 0xFFFFFFF;
    }
    if (*p != 0) {
        ret = func_1502B350(offset, sp38, p);
    } else {
        ret = 0;
    }
    return ret;
}
#include <stdarg.h>
extern u8 D_AB1950;
s32 func_1502AC88(s32 offset, s32 arg, s32 *out);
s32 func_1502B350(s32 offset, s32 arg, s32 *out);

s32 func_1502B6BC(s32 *status, s32 arg1, s32 *outCount, s32 count, ...) {
    va_list args;
    s32 offset;
    s32 sp44;
    s32 arg;
    s32 *p;
    s32 sp38;
    s32 ret;

    p = &sp44;
    if (status != NULL) {
        p = status;
    }
    *p = 1;
    offset = (s32) &D_AB1950;
    va_start(args, count);
    for (; count != 0; count--) {
        arg = va_arg(args, s32);
        if (*p != 0) {
            offset += func_1502AC88(offset, arg, &sp38);
        }
        *p = sp38 & 0xFFFFFFF;
    }
    if (*p != 0) {
        ret = func_1502B350(offset, sp38, p);
        if (*p != 0 && ret != 0) {
            arg1 = func_1502B4A8((struct func_1502B4A8_s *) ret, arg1);
        } else {
            arg1 = 0;
        }
        if (outCount != NULL) {
            *outCount = arg1;
        }
    } else {
        ret = 0;
    }
    return ret;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B7F0.s")
// void func_1502B7F0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
//     s32 sp38;
//     s32 sp34;
//     s32 temp_s1;
//     s32 offset;
//     s32 i;
//
//     sp38 = 1;
//     offset = &D_00AB1950; // 0xAB1950 - assets offsets table
//     temp_s1 = &arg2;
//
//     i = arg1;
//     if (i != 0) {
//         do {
//             temp_s1 = ALIGN4(temp_s1);
//             if (sp38 != 0) {
//                 offset += func_1502AC88(offset, temp_s1, &sp34);
//             }
//             sp38 = sp34 & 0xFFFFFFF;
//             temp_s1 += 1;
//         } while (i-- != 0);
//     }
//
//     if (sp38 != 0) {
//         *arg0 = func_1502B350(offset, sp34, &sp38);
//     } else {
//         *arg0 = 0;
//     }
// }

#include <stdarg.h>
extern u8 D_AB1950;
s32 func_1502AC88(s32 offset, s32 arg, s32 *out);

u32 func_1502B8E0(s32 *dest, u32 maxSize, s32 count, ...) {
    va_list args;
    s32 more;
    s32 offset;
    s32 arg;
    s32 sp34;

    more = 1;
    offset = (s32) &D_AB1950;
    va_start(args, count);
    for (; count != 0; count--) {
        arg = va_arg(args, s32);
        if (more != 0) {
            offset += func_1502AC88(offset, arg, &sp34);
        }
        more = sp34 & 0xFFFFFFF;
    }
    if (more != 0) {
        more = func_1502B224(offset, dest, sp34, maxSize);
    }
    return more;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B9B4.s")
// NON-MATCHING: maybe 50% there?
// s32 func_1502B9B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
//
//     s32 stack2[2];
//     s32 stack1[2];
//     s32 stack0[5];
//
//     s32 more;
//     s32 offset;
//     s32 *tmp;
//     s32 i;
//
//     more = 1;
//     offset = &D_00AB1950;
//     tmp = &arg1;
//
//     for (i = arg0; i != 0; i--) {
//         tmp = ALIGN4(tmp) + 4;
//         if (more != 0) {
//             offset += func_1502AC88(offset, tmp - 4, &stack0);
//         }
//         more = *stack0 & 0xFFFFFFF;
//     }
//
//     if (more != 0) {
//         more = ALIGN2(stack0[0] & 0xFFFFFFF);
//         if ((*stack0 & 0x70000000) == 0x10000000) {
//             if (((s32) &stack1 & 8) != 0) {
//                 *stack1 = &stack2;
//             }
//             func_10004514(offset, stack1, 0x10, 1); // decompress?
//             more = *stack1;
//         }
//     }
//
//     return more;
// }
