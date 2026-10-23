// Shared state of the Vita renderer: the RDP's tiles and TMEM, and the pieces the
// display list interpreter (gbi.cpp) hands to the vitaGL backend (gl_backend.cpp).

#ifndef __N64_GFX_HPP__
#define __N64_GFX_HPP__

#include <cstdint>
#include <cstring>

namespace n64gfx {
    // ------------------------------------------------------------ RDRAM access
    // The runtime keeps RDRAM as native-endian 32-bit words: a byte at N64 address a
    // is at rdram[a ^ 3], a halfword at a ^ 2.
    // The N64's RDRAM is 8MB, but the recompiled game (and its patches) also put data
    // above it: display lists' segmented addresses reach 16MB.
    constexpr uint32_t rdram_size = 16 * 1024 * 1024;
    constexpr uint32_t rdram_mask = rdram_size - 1;

    inline uint32_t read32(const uint8_t* rdram, uint32_t addr) {
        uint32_t v;
        std::memcpy(&v, rdram + (addr & rdram_mask & ~3u), 4);
        return v;
    }
    inline uint16_t read16(const uint8_t* rdram, uint32_t addr) {
        uint16_t v;
        std::memcpy(&v, rdram + ((addr & rdram_mask & ~1u) ^ 2), 2);
        return v;
    }
    inline uint8_t read8(const uint8_t* rdram, uint32_t addr) {
        return rdram[(addr & rdram_mask) ^ 3];
    }

    // ------------------------------------------------------------ RDP formats
    enum Format : uint8_t { FMT_RGBA = 0, FMT_YUV = 1, FMT_CI = 2, FMT_IA = 3, FMT_I = 4 };
    enum Size : uint8_t { SIZ_4b = 0, SIZ_8b = 1, SIZ_16b = 2, SIZ_32b = 3 };

    enum CycleType : uint8_t { CYCLE_1 = 0, CYCLE_2 = 1, CYCLE_COPY = 2, CYCLE_FILL = 3 };

    // Other mode H.
    constexpr uint32_t OMH_CYCLE_SHIFT = 20;
    constexpr uint32_t OMH_TLUT_SHIFT = 14;   // 0 none, 2 RGBA16, 3 IA16
    constexpr uint32_t OMH_FILTER_SHIFT = 12; // 0 point, 2 bilinear, 3 average
    constexpr uint32_t OMH_TEXT_LOD = 1u << 16;
    // Other mode L.
    constexpr uint32_t OML_ALPHA_COMPARE_MASK = 3;     // 1 threshold, 3 dither
    constexpr uint32_t OML_ZS_PRIM = 1u << 2;
    constexpr uint32_t OML_AA_EN = 1u << 3;
    constexpr uint32_t OML_Z_CMP = 1u << 4;
    constexpr uint32_t OML_Z_UPD = 1u << 5;
    constexpr uint32_t OML_IMAGE_READ = 1u << 6;
    constexpr uint32_t OML_CVG_X_ALPHA = 1u << 12;
    constexpr uint32_t OML_ALPHA_CVG_SEL = 1u << 13;
    constexpr uint32_t OML_FORCE_BL = 1u << 14;
    constexpr uint32_t OML_ZMODE_SHIFT = 10; // 0 opaque, 1 interpenetrating, 2 transparent, 3 decal

    struct Tile {
        uint8_t fmt = 0, siz = 0;
        uint16_t line = 0;   // in 64-bit words
        uint16_t tmem = 0;   // in 64-bit words
        uint8_t palette = 0;
        uint8_t cms = 0, cmt = 0;     // bit 0 mirror, bit 1 clamp
        uint8_t masks = 0, maskt = 0;
        uint8_t shifts = 0, shiftt = 0;
        uint16_t uls = 0, ult = 0, lrs = 0, lrt = 0; // 10.2
    };

    // TMEM: 4KB, kept in big-endian byte order (tmem[0] is the first byte), and the
    // palette, which LoadTLUT writes to the upper half (one entry per 64-bit word).
    struct Tmem {
        uint8_t data[4096];
        uint16_t tlut[256];
        // Bumped on every write, so textures decoded from it can be cached.
        uint32_t generation = 0;
        // The palette also sits in the upper half of data (an entry a 64-bit word, four
        // times): copied there only when something reads or writes that half. The
        // entries loaded since the last copy (tlut_dirty_lo > tlut_dirty_hi: none).
        uint32_t tlut_dirty_lo = 256, tlut_dirty_hi = 0;
    };

    // Copies the palette entries loaded since the last time into TMEM's upper half.
    void sync_tlut_mirror(Tmem& tmem);
    // Whether a tile of that height reads TMEM's upper half.
    bool tile_reads_upper(const Tile& tile, uint32_t height);

    struct TextureImage {
        uint32_t addr = 0; // physical
        uint8_t fmt = 0, siz = 0;
        uint16_t width = 0;
    };

    // The RDP's loads into TMEM (tmem.cpp).
    void load_block(Tmem& tmem, const uint8_t* rdram, const TextureImage& img, const Tile& tile,
                    uint32_t uls, uint32_t ult, uint32_t lrs, uint32_t dxt);
    void load_tile(Tmem& tmem, const uint8_t* rdram, const TextureImage& img, const Tile& tile,
                   uint32_t uls, uint32_t ult, uint32_t lrs, uint32_t lrt);
    void load_tlut(Tmem& tmem, const uint8_t* rdram, const TextureImage& img, const Tile& tile,
                   uint32_t uls, uint32_t ult, uint32_t lrs, uint32_t lrt);

    // A tile's texture as the RDP would sample it from TMEM, decoded to RGBA8888.
    // tlut_type: 0 none, 2 RGBA16, 3 IA16.
    void decode_tile(const Tmem& tmem, const Tile& tile, uint32_t width, uint32_t height,
                     uint32_t tlut_type, uint32_t* out);
    // A hash of everything decode_tile reads for this tile and size.
    uint32_t hash_tile(const Tmem& tmem, const Tile& tile, uint32_t width, uint32_t height, uint32_t tlut_type);

    // TMEM's 64-byte blocks, a bit each: those of n words from word on, wrapping in TMEM (split:
    // in each half, the same words in both, as 32-bit texels are).
    uint64_t tmem_blocks(uint32_t word, uint32_t n, bool split);
    // The TMEM words hash_tile reads for this tile and size (the palette apart): n from word,
    // wrapping in TMEM (split: in each half, the same words in both).
    void tile_words(const Tile& tile, uint32_t width, uint32_t height, uint32_t& word, uint32_t& n, bool& split);

    // Decodes an RDRAM framebuffer (16 or 32-bit) to RGBA8888.
    void decode_framebuffer(const uint8_t* rdram, uint32_t addr, uint32_t siz, uint32_t width, uint32_t height, uint32_t* out);
}

#endif
