#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// need to figure out D_800D2460
// NON-MATCHING: mips_to_c reconstruction, hand-typed. Zeroes two flag
// bytes and offset 0xD of D_800D2460[2..5] (each a 16-byte element),
// plus D_800D24C0. Target computes the D_800D2460[2] element address via
// a runtime shift-and-add (idx=2 held in a register, shifted by 4, added
// to the array base) rather than folding the constant index into each
// store's displacement - tried an explicit `idx` local to force that,
// but IDO still folded everything into direct combined offsets instead.
void func_1508F060(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_800D2460[i][0xD] = 0;
    }
    D_800D24C0 = 0;
}
// void func_1508F060(void) {
//     D_800D246D = 0;
//     D_800D247D = 0;
//     D_800D2460[3][0xD] = 0;
//     D_800D2460[4][0xD] = 0;
//     D_800D2460[5][0xD] = 0;
//     D_800D2460[2][0xD] = 0;
//     D_800D24C0 = 0;
// }

void func_1508F0A4(void) {
    func_1508F0D4();
    func_1508F9F4();
    func_1509093C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_1508F0D4.s")

void func_1508F7BC(void) {
    f32 sp48[4][4];
    f32 sp44;
    struct256 *temp_v0;

    D_800D2456 -= 1;
    D_800D2890.unk0 = (u32) (random_u32() % 5U);
    D_800D2890.unk8 = sqrtf(25.0f - (D_800D2890.unk0 * D_800D2890.unk0));
    temp_v0 = allocate_memory(sizeof(*temp_v0), 1, 1, 0);
    temp_v0->unk80 = D_800D245C;
    D_800D245C = temp_v0;
    guMtxL2F(&sp48, (D_800D2456 << 7) + ((D_800BE9C0 ^ 1) << 6) + &D_800D2590);
    func_1503E5F8(&sp48, &temp_v0->unk84, &temp_v0->unk88, &temp_v0->unk8C, &temp_v0->unk9C, &temp_v0->unkA0, &temp_v0->unkA4, &sp44, &sp44, &sp44);

    temp_v0->unk90 = (u32)((random_u32() & 0xF) + 10);
    temp_v0->unk94 = (u32)((random_u32() & 0x1F) + 20);
    temp_v0->unk98 = 0.0f;
    temp_v0->unkA8 = (u32)(random_u32() & 0xF);
    temp_v0->unkAC = (u32)(random_u32() & 0xF);
    temp_v0->unkB0 = (u32)(random_u32() & 0xF);
    temp_v0->unkB4 = 120;
}

void func_1508F9C4(void) {
    D_800D2410[D_800D2456++] = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_1508F9F4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_1508FD38.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_150900F0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_15090630.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_1509093C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_150911F4.s")

extern u8 D_D16[];
s32 func_1510D0EC(s32, void *, s32, s32);

Gfx *func_15091534(Gfx *arg0, s32 arg1, u8 *arg2) {
    s32 temp_v0;

    *arg2 = 0;
    temp_v0 = func_1510D0EC(arg1 + (s32)D_D16, 0, 3, 0);
    if (temp_v0 != 0x80000000) {
        gDPSetTextureImage(arg0++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, temp_v0);
        gDPSetTile(arg0++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
        gDPLoadSync(arg0++);
        gDPLoadBlock(arg0++, G_TX_LOADTILE, 0, 0, 1023, 0);
        gDPPipeSync(arg0++);
        gDPSetTile(arg0++, G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
        gDPSetTileSize(arg0++, G_TX_RENDERTILE, 0, 0, 63 << 2, 63 << 2);
        gDPSetTextureImage(arg0++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, temp_v0 + 0x800);
        gDPLoadSync(arg0++);
        gDPLoadTLUTCmd(arg0++, 6, 15);
        gDPSetOtherMode(arg0++, 0xEF00AC3F & 0xFFFFFF, 0x504244);
        *arg2 = 1;
    }
    return arg0;
}
// NON-MATCHING: needs some love
// Gfx* func_15091534(Gfx* arg0, struct257 *arg1, u8 *arg2) {
//     u32 temp_v0;
//
//     *arg2 = 0;
//     // get address for texture?
//     temp_v0 = func_1510D0EC(&arg1->unkD16, 0, 3, 0);;
//     // tmp = arg0;
//     if (temp_v0 != 0x80000000) {
//       // FD50000012345678
//       gDPSetTextureImage(arg0++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, temp_v0);
//       // F550000007098260
//       gDPSetTile(arg0++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
//       // E600000000000000
//       gDPLoadSync(arg0++);
//       // F3000000073FF000
//       gDPLoadBlock(arg0++, G_TX_LOADTILE, 0, 0, 1023, 0);
//       // E700000000000000
//       gDPPipeSync(arg0++);
//       // F540080000098260
//       gDPSetTile(arg0++, G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
//       // F2000000000FC0FC
//       // FIXME: what are these macros
//       // gDPSetTileSize(arg0++, G_TX_RENDERTILE, 0, 0, qu102(63), qu102(63));
//       gDPSetTileSize(arg0++, G_TX_RENDERTILE, 0, 0, 63, 63);
//       // FD10000012345678
//       gDPSetTextureImage(arg0++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, temp_v0 + 2048);
//       // E600000000000000
//       gDPLoadSync(arg0++);
//       // F00000000603C000
//       gDPLoadTLUTCmd(arg0++, 6, 15);
//       // EF00AC3F00504244
//       gDPSetOtherMode(arg0++, G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE | 0x0000000F, G_AC_NONE | G_ZS_PRIM | G_RM_XLU_SURF | G_RM_XLU_SURF2);
//
//       *arg2 = (u8)1;
//     }
//     return arg0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_150916B4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_150918EC.s")

void func_15093818(s32 arg0) {
    if ((arg0 != 0) && (D_800D2458 == 0)) {
        D_800D2458 = 1;
        func_15093878();
        return;
    }
    if ((arg0 == 0) && (D_800D2458 != 0)) {
        D_800D2458 = 0;
    }
}

void func_15093878(void) {
    D_800D2448 = func_1518C900(0xBA);
    D_800D244C = allocate_memory(0x80, 1, 1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_150938BC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_BC510/func_15093B58.s")
