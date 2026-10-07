// The RDP's texture memory: loads from RDRAM into TMEM, and textures decoded from TMEM
// the way the RDP samples them.
//
// TMEM is addressed in 64-bit words. Odd lines of a texture are stored with their
// 32-bit halves swapped (LoadTile does it per row, LoadBlock per word by its dxt
// line counter), and the sampler swaps them back by XOR-ing the address with 4.
// 32-bit textures are split: red and green in the lower 2KB, blue and alpha at the
// same offset in the upper 2KB.

#include <algorithm>
#if defined(__ARM_NEON)
#include <arm_neon.h>
#endif

#define XXH_INLINE_ALL
#include "xxHash/xxhash.h"

#include "n64_gfx.hpp"

namespace n64gfx {
    namespace {
        inline uint32_t bits_per_texel(uint32_t siz) { return 4u << siz; }

        inline uint8_t expand5(uint32_t v) { return (uint8_t)((v << 3) | (v >> 2)); }

        inline uint32_t rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
            return r | (g << 8) | (b << 16) | (a << 24);
        }

        inline uint32_t from_rgba16(uint16_t c) {
            return rgba(expand5((c >> 11) & 0x1F), expand5((c >> 6) & 0x1F), expand5((c >> 1) & 0x1F), (c & 1) ? 255 : 0);
        }

        inline uint32_t from_ia16(uint16_t c) {
            uint32_t i = c >> 8;
            return rgba(i, i, i, c & 0xFF);
        }

        inline uint32_t from_tlut(uint16_t entry, uint32_t tlut_type) {
            return tlut_type == 3 ? from_ia16(entry) : from_rgba16(entry);
        }
    }

    void sync_tlut_mirror(Tmem& tmem) {
        for (uint32_t i = tmem.tlut_dirty_lo; i <= tmem.tlut_dirty_hi && i < 256; i++) {
            const uint32_t e = __builtin_bswap16(tmem.tlut[i]);
            const uint32_t pair = e | (e << 16);
            uint8_t* word = &tmem.data[(256 + i) * 8];
            std::memcpy(word, &pair, 4);
            std::memcpy(word + 4, &pair, 4);
        }
        tmem.tlut_dirty_lo = 256;
        tmem.tlut_dirty_hi = 0;
    }

    bool tile_reads_upper(const Tile& tile, uint32_t height) {
        if (tile.siz == SIZ_32b) return true;
        const uint32_t start = (tile.tmem * 8) & 0xFFF;
        return start + std::max<uint32_t>(height, 1) * tile.line * 8 > 0x800 || start >= 0x800;
    }

    namespace {
        // A load writing TMEM's upper half goes after the palette copied there.
        inline void before_write(Tmem& tmem, uint32_t start, uint32_t bytes, bool both_halves) {
            if (tmem.tlut_dirty_lo <= tmem.tlut_dirty_hi && (both_halves || (start & 0xFFF) + bytes > 0x800 || (start & 0xFFF) >= 0x800)) {
                sync_tlut_mirror(tmem);
            }
        }
    }

    void load_block(Tmem& tmem, const uint8_t* rdram, const TextureImage& img, const Tile& tile,
                    uint32_t uls, uint32_t ult, uint32_t lrs, uint32_t dxt) {
        const uint32_t texels = std::min<uint32_t>(lrs - uls + 1, 2048);
        const uint32_t bpt = bits_per_texel(img.siz);
        before_write(tmem, tile.tmem * 8, img.siz == SIZ_32b ? texels * 2 : ((texels * bpt + 63) / 64) * 8, img.siz == SIZ_32b);
        const uint32_t src = img.addr + ((ult * img.width + uls) * bpt) / 8;
        tmem.generation++;

        if (img.siz == SIZ_32b) {
            const uint32_t base16 = tile.tmem * 4;
            // Red and green to the lower half, blue and alpha to the upper (as bytes in
            // TMEM's order: a 16-bit store of the byte-swapped pair).
            auto put = [&](uint32_t a16, uint32_t c) { // c = RRGGBBAA
                a16 &= 0x3FF;
                const uint16_t rg = __builtin_bswap16((uint16_t)(c >> 16));
                const uint16_t ba = __builtin_bswap16((uint16_t)c);
                std::memcpy(&tmem.data[a16 * 2], &rg, 2);
                std::memcpy(&tmem.data[(a16 | 0x400) * 2], &ba, 2);
            };
            uint32_t k = 0;
            for (uint32_t word = 0; k + 1 < texels; word++, k += 2) { // a 64-bit source word: two texels
                const uint32_t swap = (((word * dxt) >> 11) & 1) ? 2 : 0;
                // Both texels at once: byte-swapped, each is 0xAABBGGRR, its red and green
                // the low half (bytes RR GG in TMEM), blue and alpha the high one.
                const uint32_t c0 = __builtin_bswap32(read32(rdram, src + k * 4));
                const uint32_t c1 = __builtin_bswap32(read32(rdram, src + k * 4 + 4));
                const uint32_t rg = (c0 & 0xFFFF) | (c1 << 16), ba = (c0 >> 16) | (c1 & 0xFFFF0000);
                const uint32_t a16 = ((base16 + k) ^ swap) & 0x3FF; // even: the pair stays together
                std::memcpy(&tmem.data[a16 * 2], &rg, 4);
                std::memcpy(&tmem.data[(a16 | 0x400) * 2], &ba, 4);
            }
            if (k < texels) {
                const uint32_t swap = ((((k / 2) * dxt) >> 11) & 1) ? 2 : 0;
                put((base16 + k) ^ swap, read32(rdram, src + k * 4));
            }
            return;
        }

        const uint32_t words = (texels * bpt + 63) / 64;
        uint32_t dst = tile.tmem * 8;
        if ((src & 3) == 0) {
            // RDRAM holds big-endian words in host order: a byte swap per word. The
            // words go in runs of a line (dxt counts the lines), odd lines with their
            // halves swapped.
            auto copy_word = [&](uint32_t i, bool odd) {
                const uint32_t a = __builtin_bswap32(read32(rdram, src + i * 8));
                const uint32_t b = __builtin_bswap32(read32(rdram, src + i * 8 + 4));
                const uint32_t d = (dst + i * 8) & 0xFFF;
                std::memcpy(&tmem.data[d + (odd ? 4 : 0)], &a, 4);
                std::memcpy(&tmem.data[d + (odd ? 0 : 4)], &b, 4);
            };
            uint32_t i = 0;
            // Where each line ends (i * dxt reaching (row + 1) * 2048), without a division
            // a line: (row + 1) * 2048 = q * dxt + r, stepped by 2048 = step_q * dxt + step_r.
            const uint32_t step_q = dxt ? 2048 / dxt : 0, step_r = dxt ? 2048 % dxt : 0;
            uint32_t q = step_q, r = step_r, row = 0;
            while (i < words) {
                const bool odd = row & 1;
                // The first word of the next line: the smallest i with i * dxt >= (row + 1) * 2048.
                const uint32_t end = dxt ? std::min(words, q + (r != 0 ? 1u : 0u)) : words;
                row++;
                q += step_q;
                r += step_r;
                if (r >= dxt) {
                    r -= dxt;
                    q++;
                }
#if defined(__ARM_NEON)
                // Two words at a time, while neither RDRAM nor TMEM wraps.
                while (i + 2 <= end && ((dst + i * 8) & 0xFFF) + 16 <= 0x1000 &&
                       ((src + i * 8) & rdram_mask) + 16 <= rdram_size) {
                    uint8x16_t v = vrev32q_u8(vld1q_u8(rdram + ((src + i * 8) & rdram_mask)));
                    if (odd) v = vreinterpretq_u8_u32(vrev64q_u32(vreinterpretq_u32_u8(v)));
                    vst1q_u8(&tmem.data[(dst + i * 8) & 0xFFF], v);
                    i += 2;
                }
#endif
                for (; i < end; i++) {
                    copy_word(i, odd);
                }
            }
            return;
        }
        for (uint32_t i = 0; i < words; i++) {
            const bool odd = ((i * dxt) >> 11) & 1;
            const uint32_t s = src + i * 8;
            for (uint32_t b = 0; b < 8; b++) {
                uint32_t d = dst + i * 8 + b;
                if (odd) d ^= 4;
                tmem.data[d & 0xFFF] = read8(rdram, s + b);
            }
        }
    }

    void load_tile(Tmem& tmem, const uint8_t* rdram, const TextureImage& img, const Tile& tile,
                   uint32_t uls, uint32_t ult, uint32_t lrs, uint32_t lrt) {
        const uint32_t x0 = uls >> 2, y0 = ult >> 2;
        const uint32_t x1 = lrs >> 2, y1 = lrt >> 2;
        if (x1 < x0 || y1 < y0) {
            return;
        }
        const uint32_t w = x1 - x0 + 1, h = y1 - y0 + 1;
        const uint32_t bpt = bits_per_texel(img.siz);
        before_write(tmem, tile.tmem * 8, h * tile.line * 8, img.siz == SIZ_32b);
        tmem.generation++;

        if (img.siz == SIZ_32b) {
            const uint32_t base16 = tile.tmem * 4, line16 = tile.line * 4;
            for (uint32_t y = 0; y < h; y++) {
                for (uint32_t x = 0; x < w; x++) {
                    uint32_t a16 = base16 + y * line16 + x;
                    if (y & 1) a16 ^= 2;
                    a16 &= 0x3FF;
                    const uint32_t c = read32(rdram, img.addr + ((y0 + y) * img.width + (x0 + x)) * 4);
                    tmem.data[a16 * 2 + 0] = (uint8_t)(c >> 24);
                    tmem.data[a16 * 2 + 1] = (uint8_t)(c >> 16);
                    tmem.data[(a16 | 0x400) * 2 + 0] = (uint8_t)(c >> 8);
                    tmem.data[(a16 | 0x400) * 2 + 1] = (uint8_t)c;
                }
            }
            return;
        }

        const uint32_t row_bytes = (w * bpt + 7) / 8;
        const uint32_t line_bytes = tile.line * 8;
        const uint32_t base = tile.tmem * 8;
        for (uint32_t y = 0; y < h; y++) {
            const uint32_t s = img.addr + (((y0 + y) * img.width + x0) * bpt) / 8;
            const uint32_t d0 = base + y * line_bytes;
            if ((s & 3) == 0 && (d0 & 3) == 0 && (row_bytes & 3) == 0) {
                // Whole words: swapped from RDRAM's host order; odd rows swap halves (^4).
                const uint32_t words = (row_bytes + 3) / 4;
                for (uint32_t i = 0; i < words; i++) {
                    const uint32_t v = __builtin_bswap32(read32(rdram, s + i * 4));
                    uint32_t d = d0 + i * 4;
                    if (y & 1) d ^= 4;
                    std::memcpy(&tmem.data[d & 0xFFF], &v, 4);
                }
                continue;
            }
            for (uint32_t b = 0; b < row_bytes; b++) {
                uint32_t d = base + y * line_bytes + b;
                if (y & 1) d ^= 4;
                tmem.data[d & 0xFFF] = read8(rdram, s + b);
            }
        }
    }

    void load_tlut(Tmem& tmem, const uint8_t* rdram, const TextureImage& img, const Tile& tile,
                   uint32_t uls, uint32_t ult, uint32_t lrs, uint32_t lrt) {
        const uint32_t x0 = uls >> 2, x1 = lrs >> 2, y0 = ult >> 2;
        if (x1 < x0) {
            return;
        }
        const uint32_t count = std::min<uint32_t>(x1 - x0 + 1, 256);
        const uint32_t src = img.addr + (y0 * img.width + x0) * 2;
        const uint32_t first = (tile.tmem - 256) & 0xFF;
        uint32_t i = 0;
        if ((src & 3) == 0) {
#if defined(__ARM_NEON)
            // Eight entries at a time, while neither the palette nor RDRAM wraps.
            for (; i + 8 <= count && first + i + 8 <= 256 && ((src + i * 2) & rdram_mask) + 16 <= rdram_size; i += 8) {
                const uint16x8_t v = vld1q_u16(reinterpret_cast<const uint16_t*>(rdram + ((src + i * 2) & rdram_mask)));
                vst1q_u16(&tmem.tlut[first + i], vrev32q_u16(v));
            }
#endif
            // Two entries a word (RDRAM's words are in host order: the first is the high half).
            for (; i + 1 < count; i += 2) {
                const uint32_t w = read32(rdram, src + i * 2);
                tmem.tlut[(first + i) & 0xFF] = (uint16_t)(w >> 16);
                tmem.tlut[(first + i + 1) & 0xFF] = (uint16_t)w;
            }
        }
        for (; i < count; i++) {
            tmem.tlut[(first + i) & 0xFF] = read16(rdram, src + i * 2);
        }
        // The RDP keeps the palette in TMEM's upper half, an entry per 64-bit word in all
        // four of its 16-bit lanes; textures can read it there too (Conker's light cones
        // take a 32-bit texture's blue and alpha from it). Copied there when needed.
        if (tile.tmem >= 256 && first + count <= 256) {
            tmem.tlut_dirty_lo = std::min(tmem.tlut_dirty_lo, first);
            tmem.tlut_dirty_hi = std::max(tmem.tlut_dirty_hi, first + count - 1);
        }
        else {
            for (uint32_t k = 0; k < count; k++) {
                const uint32_t e = __builtin_bswap16(tmem.tlut[(first + k) & 0xFF]);
                const uint32_t pair = e | (e << 16);
                uint8_t* word = &tmem.data[((tile.tmem + k) & 0x1FF) * 8];
                std::memcpy(word, &pair, 4);
                std::memcpy(word + 4, &pair, 4);
            }
        }
        tmem.generation++;
    }

    namespace {
        // The byte at a texel row's offset, with the odd-line swap.
        inline uint8_t tmem_byte(const Tmem& tmem, uint32_t base, uint32_t line_bytes, uint32_t x_byte, uint32_t y) {
            uint32_t a = base + y * line_bytes + x_byte;
            if (y & 1) a ^= 4;
            return tmem.data[a & 0xFFF];
        }
    }

    void decode_tile(const Tmem& tmem, const Tile& tile, uint32_t width, uint32_t height,
                     uint32_t tlut_type, uint32_t* out) {
        const uint32_t base = tile.tmem * 8;
        const uint32_t line_bytes = tile.line * 8;
        const bool use_tlut = tlut_type >= 2 && (tile.siz == SIZ_4b || tile.siz == SIZ_8b);

        if (tile.siz == SIZ_32b) {
            const uint32_t base16 = tile.tmem * 4, line16 = tile.line * 4;
            for (uint32_t y = 0; y < height; y++) {
                for (uint32_t x = 0; x < width; x++) {
                    uint32_t a16 = base16 + y * line16 + x;
                    if (y & 1) a16 ^= 2;
                    a16 &= 0x3FF;
                    const uint8_t* rg = &tmem.data[a16 * 2];
                    const uint8_t* ba = &tmem.data[(a16 | 0x400) * 2];
                    *out++ = rgba(rg[0], rg[1], ba[0], ba[1]);
                }
            }
            return;
        }

        for (uint32_t y = 0; y < height; y++) {
            for (uint32_t x = 0; x < width; x++) {
                uint32_t c = 0;
                switch (tile.siz) {
                    case SIZ_4b: {
                        const uint8_t byte = tmem_byte(tmem, base, line_bytes, x >> 1, y);
                        const uint32_t v = (x & 1) ? (byte & 0xF) : (byte >> 4);
                        if (use_tlut) {
                            c = from_tlut(tmem.tlut[((tile.palette << 4) | v) & 0xFF], tlut_type);
                        }
                        else if (tile.fmt == FMT_IA) {
                            const uint32_t i = ((v >> 1) * 255) / 7;
                            c = rgba(i, i, i, (v & 1) ? 255 : 0);
                        }
                        else {
                            const uint32_t i = v * 17;
                            c = rgba(i, i, i, i);
                        }
                        break;
                    }
                    case SIZ_8b: {
                        const uint8_t v = tmem_byte(tmem, base, line_bytes, x, y);
                        if (use_tlut) {
                            c = from_tlut(tmem.tlut[v], tlut_type);
                        }
                        else if (tile.fmt == FMT_IA) {
                            const uint32_t i = (v >> 4) * 17;
                            c = rgba(i, i, i, (v & 0xF) * 17);
                        }
                        else {
                            c = rgba(v, v, v, v);
                        }
                        break;
                    }
                    case SIZ_16b: {
                        const uint16_t v = (uint16_t)((tmem_byte(tmem, base, line_bytes, x * 2, y) << 8) |
                                                      tmem_byte(tmem, base, line_bytes, x * 2 + 1, y));
                        if (tile.fmt == FMT_IA) {
                            c = from_ia16(v);
                        }
                        else if (tile.fmt == FMT_I) {
                            const uint32_t i = v >> 8;
                            c = rgba(i, i, i, i);
                        }
                        else {
                            c = from_rgba16(v);
                        }
                        break;
                    }
                }
                *out++ = c;
            }
        }
    }

    uint32_t hash_tile(const Tmem& tmem, const Tile& tile, uint32_t width, uint32_t height, uint32_t tlut_type) {
        XXH32_state_t state;
        XXH32_reset(&state, 0);
        const uint32_t params[8] = {
            tile.fmt, tile.siz, tile.line, tile.tmem, tile.palette, width, height, tlut_type
        };
        XXH32_update(&state, params, sizeof(params));

        // The rows the texture reads: from its start, height lines (TMEM wraps).
        const uint32_t row_bytes = (tile.siz == SIZ_32b) ? width * 2 : (width * (4u << tile.siz) + 7) / 8;
        uint32_t span = (height > 0 ? (height - 1) : 0) * tile.line * 8 + ((row_bytes + 7) & ~7u);
        const uint32_t half = (tile.siz == SIZ_32b) ? 2048 : 4096;
        span = std::min(span, half);
        const uint32_t start = (tile.siz == SIZ_32b) ? ((tile.tmem * 8) & 0x7FF) : ((tile.tmem * 8) & 0xFFF);
        auto add_range = [&](uint32_t offset) {
            const uint32_t first = std::min(span, half - (start & (half - 1)));
            XXH32_update(&state, &tmem.data[offset + (start & (half - 1))], first);
            if (span > first) {
                XXH32_update(&state, &tmem.data[offset], span - first);
            }
        };
        if (tile.siz == SIZ_32b) {
            add_range(0);
            add_range(2048);
        }
        else {
            add_range(0);
        }

        if (tlut_type >= 2 && tile.siz == SIZ_4b) {
            XXH32_update(&state, &tmem.tlut[(tile.palette << 4) & 0xFF], 16 * sizeof(uint16_t));
        }
        else if (tlut_type >= 2 && tile.siz == SIZ_8b) {
            XXH32_update(&state, tmem.tlut, sizeof(tmem.tlut));
        }
        return XXH32_digest(&state);
    }

    void decode_framebuffer(const uint8_t* rdram, uint32_t addr, uint32_t siz, uint32_t width, uint32_t height, uint32_t* out) {
        if (siz == SIZ_32b) {
            for (uint32_t i = 0; i < width * height; i++) {
                const uint32_t c = read32(rdram, addr + i * 4);
                *out++ = rgba(c >> 24, (c >> 16) & 0xFF, (c >> 8) & 0xFF, 255);
            }
        }
        else {
            for (uint32_t i = 0; i < width * height; i++) {
                const uint32_t c = from_rgba16(read16(rdram, addr + i * 2));
                *out++ = c | 0xFF000000u;
            }
        }
    }
}
