#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_16000000(void) {
    func_160012B0(278, D_160046AC);
}

s32 func_16000028(void) {
    if (D_16003890 & 0xC000) {
        D_16003AF4 = 1;
        return 3;
    }
    return 0;
}

void func_16000058(void) {
    s32 i;
    s32 phi_s2;

    func_16001338(255, 255, 255);
    func_160012B0(44, D_160046D0); // "MAIN MENU"
    phi_s2 = 108;
    for(i = 0; i < 2; i++) {
        if (D_16003B1C == i) {
            func_16001338(255, 0, 0);     // red
        } else {
            func_16001338(255, 255, 255); // white
        }
        func_160012B0(phi_s2, D_16003B20[i]);
        phi_s2 += 32;
    }
    if (D_16003B1C == 2) {
        func_16001338(255, 0, 0);     // red
    } else {
        func_16001338(255, 255, 255); // white
    }
    if (D_16003AF0 != 0) {
        if ((D_1600389C->unk120 == 32) && (D_160038A4 == 0)) {
            func_160012B0(phi_s2, D_160046DC);
        } else if (D_16003AF0 != 0) {
            func_160012B0(phi_s2, D_160046E8);
        }
    } else {
        func_160012B0(phi_s2, D_160046F4); // "RETRY CODE"
    }
    func_16001338(255, 255, 255);
    func_160012B0(611, D_16004700); // "Version"
    func_16001044(619, 1, 163);
    func_160012B0(643, D_16004708); // "Built"
    func_160012B0(651, D_16004710); // "Dec 19 2000"
    func_160012B0(663, D_1600471C); // "09:57:42"
}

s32 func_16000224(void) {
    s32 res = 0;

    if (D_16003890 & 0x40000) { // D_JPAD is 0x0400
        D_16003B1C -= 1;
        res = 1;
    }
    if (D_16003890 & 0x80000) { // U_JPAD is 0x0800
        D_16003B1C += 1;
        res = 1;
    }
    if (D_16003B1C >= 3) {
        D_16003B1C = 0;
    }
    if (D_16003B1C < 0) {
        D_16003B1C = 2;
    }
    if (D_16003890 & A_BUTTON) {
        switch(D_16003B1C) {
            case 0:
                res = 3;
                D_16003AF4 = 2;
                break;
            case 1:
                res = 3;
                D_16003AF4 = 3;
                break;
            case 2:
                res = 4;
                break;
        }
    }
    return res;
}

void func_16000304(void) {
}

void func_1600030C(void) {
}

void func_16000314(void) {
    switch(D_16003B28) {
        case 0:
            func_16000424(D_1600389C);
            func_160006CC(D_1600389C);
            break;
        case 1:
        case 2:
            func_16000590(D_1600389C);
            break;
    }
}

s32 func_16000384(void) {
    s32 res = 0;

    if (D_16003890 & (R_CBUTTONS | D_CBUTTONS)) {
        D_16003B28 += 1;
        if (D_16003B28 >= 3) {
            D_16003B28 = 0;
        }
        return 3;
    }
    if (D_16003890 & (L_CBUTTONS | U_CBUTTONS)) {
        D_16003B28 -= 1;
        if (D_16003B28 < 0) {
            D_16003B28 = 2;
        }
        return 3;
    }
    if (D_16003890 & B_BUTTON) {
        D_16003AF4 = 1;
        res = 3;
    }
    return res;
}

void func_16000424(struct118 *arg0) {
    // TODO is this a RGB struct?
    u32 tmp0;
    u32 tmp1;
    s32 pad;

    func_16001338(255, 255, 255);
    func_160012B0(35, D_16004728);     // "Pc"
    func_16001044(43, 0, arg0->unk11C);
    func_160012B0(67, D_1600472C);     // "Cause"
    func_16001044(75, 0, arg0->unk120);
    func_16001338(128, 128, 255);
    tmp0 = arg0->unk120;
    tmp1 = (tmp0 >> 2) & 0xF;

    func_160012B0(107, D_16003848[tmp1]);
    if (tmp1 == 11) {
        func_16001044(111, 1, (tmp0 >> 28) & 3);
    }
    func_16001338(255, 255, 255);
    func_160012B0(131, D_16004734);      // "Sr"
    func_16001044(139, 0, arg0->unk118);
    func_160012B0(163, D_16004738);      // "Badvadr"
    func_16001044(171, 0, arg0->unk124);
    func_160012B0(195, D_16004740);      // "Thread"
    func_16001044(203, 1, arg0->unk14);
    if (D_160038A4 != 0) {
        func_160012B0(52, D_16004748);   // "Lockup_Now"
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/debugger/debugger/func_16000590.s")

struct func_160006CC_s {
    u8 c[4];
};
typedef struct {
    u8 ch;
    u8 ch2;
    u8 idx;
} func_160006CC_e;
extern struct func_160006CC_s D_16003B48;
extern func_160006CC_e D_160037F0[];

int func_160006CC(struct118 *arg0) {
    struct func_160006CC_s buf;
    func_160006CC_e *p;
    s32 pos;
    s32 idx;

    buf = D_16003B48;
    pos = 0x123;
    p = D_160037F0;
    func_16001338(0xC0, 0xC0, 0xFF);
    do {
        buf.c[0] = p->ch;
        buf.c[1] = p->ch2;
        func_160012B0(pos, &buf);
        pos += 3;
        idx = p->idx;
        func_16001044(pos, 0, ((s32 *)arg0)[idx + 1]);
        pos += 0xD;
        p++;
    } while (p->ch != 0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/debugger/debugger/func_1600078C.s")
// NON-MATCHING: close but still some stuff to figure out
// void func_1600078C(void) {
//     s32 temp_s0;
//     u8 range_prefix;
//     u32 temp_s2;
//     s32 temp_s5;
//     s32 phi_s1;
//     u32 *phi_s2;
//     u32 phi_s5;
//     s32 i;
//
//     temp_s0 = D_1600389C->unkF4;
//     func_16001338(0, 255, 0); // green
//     func_160012B0(11, &D_160047B0);
//     temp_s2 = (D_16003B4C * 4) + temp_s0;
//     if (((temp_s2 & 3) == 0) && (temp_s2 >= 0x80000000U) && (temp_s2 < 0x80800001U)) {
//         if (D_16003B4C == 0) {
//             func_16001338(255, 0, 0); // red
//             phi_s5 = &D_8002D4B0;
//         } else {
//             temp_s5 = &D_8002D4B0 - 0x2B50; // 11088 ?
//             if ((temp_s2 >= temp_s5) && (temp_s2 < (temp_s5 + 0x400))) {
//                 func_16001338(128, 128, 255); // purple
//                 phi_s5 = temp_s5;
//             } else if ((temp_s2 >= (u32) &D_8002D8B0) && (temp_s2 < ((u32)&D_8002D8B0 + 0x4000))) {
//                 func_16001338(255, 128, 128); // light red
//                 phi_s5 = temp_s5;
//             } else {
//                 func_16001338(255, 255, 255);
//                 phi_s5 = temp_s5;
//             }
//         }
//         phi_s1 = 97; // "a"
//         phi_s2 = temp_s2;
//         for (i = 0; i < 22; i++) {
//             func_16001044(phi_s1, 0, phi_s2);
//             func_160012B0(phi_s1 + 8, &D_160047BC);
//             range_prefix = (*phi_s2 >> 24);
//             if (range_prefix == 0x80) {                   // 0x80000000
//                 func_16001338(128, 128, 255);
//             } else if (range_prefix == 0x15) {            // 0x15000000
//                 func_16001338(255, 0, 0);
//             } else if (range_prefix == 0x16) {            // 0x16000000
//                 func_16001338(128, 255, 128);
//             } else if (range_prefix == 0x10) {            // 0x10000000
//                 func_16001338(255, 0, 0);
//             } else {
//                 func_16001338(255, 255, 255);
//             }
//             func_16001044(phi_s1 + 0xC, 0, *phi_s2);
//             func_160012B0(phi_s1 + 0x16, &D_160047C0);
//             func_16001338(255, 255, 255);
//             func_16001044(phi_s1 + 0x16, 1, *phi_s2);
//             if (((u32) phi_s2 >= phi_s5) && ((u32) phi_s2 < (phi_s5 + 0x400))) {
//                 func_16001338(128, 128, 0xFF);
//             } else if (((u32) phi_s2 >= (u32) &D_8002D8B0) && ((u32) phi_s2 < ((u32)&D_8002D8B0 + 0x4000))) {
//                 func_16001338(255, 128, 128);
//             } else {
//                 func_16001338(255, 255, 255);
//             }
//             phi_s1 += 0x20;
//             phi_s2 += 4;
//         }
//     }
// }

s32 func_16000A5C(void) {
    s32 res = 0;

    if ((D_160036F3 >= 41) || (D_16003890 & U_CBUTTONS)) {
        D_16003B4C -= 1;
        if (D_16003B4C < 0) {
            D_16003B4C = 0;
        } else {
            res = 3;
        }
    } else if ((D_160036F3 < -40) || (D_16003890 & D_CBUTTONS)) {
        D_16003B4C += 1;
        if (D_16003B4C >= 201) {
            D_16003B4C = 200;
        }
        res = 3;
    }
    if ((D_16003890 & B_BUTTON)) {
        D_16003AF4 = 1;
        res = 3;
    }
    return res;
}

// called from func_10007DAC
#pragma GLOBAL_ASM("asm/nonmatchings/debugger/debugger/func_16000B14.s")
void func_16000F8C(s32 arg0, f32 arg1) {
    f32 f;
    u8 buf[44];
    u32 e;

    if ((arg0 >= (D_160038A0 << 5)) && (arg0 < 833)) {
        f = arg1;
        e = (*(u32 *)&f & 0x7F800000) >> 23;
        if ((e == 0 || e >= 255) && (e = *(u32 *)&f << 1) != 0) {
            func_160012B0(arg0, D_160047D0);
            return;
        }
        func_16001B34(buf, D_160047D4, D_160047DC, D_160047E0, (f64)arg1);
        func_160012B0(arg0, buf);
    }
}
// NON-MATCHING: lots to figure out
// void func_16000F8C(s32 arg0, f32 arg1) {
//     struct165 tmp;
//     s32 temp_v1;
//     u32 temp_t9;
//
//     if ((arg0 >= (D_160038A0 << 5)) && (arg0 < 833)) {
//         tmp.unk18 = arg1;
//         temp_v1 = *(s32*)&tmp.unk18;
//         temp_t9 = (u32) (temp_v1 & 0x7F800000) >> 0x17;
//         if ((temp_t9 == 0) || (temp_t9 >= 0x255U)) {
//             if ((temp_v1 * 2) != 0) {
//                 func_160012B0(arg1, &D_160047D0); // arg0,
//                 return;
//             }
//         }
//         func_16001B34(&arg0, &tmp.unk0, &D_160047D4, &D_160047DC, &D_160047E0); // , (f64) arg1
//         func_160012B0(arg0, &tmp.unk0);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/debugger/debugger/func_16001044.s")

void func_160012B0(s32 arg0, u8 *arg1) {
    if (arg1 && (arg0 >= (D_160038A0 << 5)) && (arg0 < 833)) {
        s32 fb = func_1600160C();
        while (*arg1 != 0) {
            fb = func_160014F0(fb, *arg1 & 0xFF);
            *arg1++;
        }
    }
}
// convert rgb to rgba16
void func_16001338(arg0, arg1, arg2) u8 arg0; u8 arg1; u8 arg2; {
    D_1600388C = ((arg0 & 0xF8) << 8) | ((arg1 & 0xF8) << 3) | ((arg2 & 0xF8) >> 2) | 1;
}

void func_16001390(x0, y0, x1, y1) s16 x0; s16 y0; s16 x1; s16 y1; {
    u16 *p;
    s32 i;

    if ((x1 < x0) || (y1 < y0)) {
        return;
    }
    if ((x0 < 0) || (y0 < 0)) {
        return;
    }
    x1++;
    y1++;
    p = (u16 *)func_1600160C(0);
    p += x0 + y0 * D_160038A8;
    x1 -= x0;
    y1 -= y0;
    while (y1 > 0) {
        for (i = x1; i > 0; i--) {
            *p++ = D_1600388C;
        }
        y1--;
        p += D_160038A8 - x1;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/debugger/debugger/func_160014F0.s")

// splat into framebuffer
int func_1600160C(arg0) int arg0; {
    u32 y = arg0 & 0xFFE0;

    if (D_160038A8 != 0x124) {
        y = ((s32)y >> 2) + y;
    }
    y = ((s32)y >> 2) * (D_160038A8 << 1);
    y += (arg0 & 0x1F) * 16;
    y += D_160038A8 * 4;
    y += 16;
    return D_8002AAE8[D_16003888] + y;
}

// contains delay slot
void func_16001678(void) {
    u32 *fb = (u32 *)D_8002AAE8[D_16003888];
    u32 h;
    u32 *end;

    if (D_160038A8 == 292) {
        h = 215;
    } else {
        h = 264;
    }
    end = fb + (D_160038A8 >> 1) * h;
    while (fb < end) {
        fb[0] = 0x10001;
        fb[1] = 0x10001;
        fb[2] = 0x10001;
        fb[3] = 0x10001;
        fb += 4;
    }
}

s32 func_160016F4(s32 arg0) {
    return arg0;
}
