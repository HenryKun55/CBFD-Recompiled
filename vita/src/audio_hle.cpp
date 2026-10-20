// High-level implementation of Conker's audio microcode: see audio_hle.hpp.
//
// Written from the microcode's own instructions (RecompiledFuncs/rsp/audio_ucode.cpp, and
// the annotated source of DevOldSchool/conkers-bfd-decomp, src/rsp/asp.s) and the RSP's
// vector unit semantics (librecomp's rsp_vu_impl.hpp). Each command does what the
// microcode does, in the same order where order shows (buffers that overlap, read-ahead
// in the microcode's software-pipelined loops), with the vector unit's arithmetic:
//
//   VMULF   (2ab + 0x8000) >> 16, saturated (only -0x8000 * -0x8000 saturates)
//   VMUDH/VMADH, VMUDN/VMADN, VMUDM/VMADM, VMUDL on a 48-bit accumulator; the
//   "high" results clamp acc >> 16 to 16 bits, the "low" ones give acc's low 16 bits
//   unless acc is outside 32 bits (then 0 or 0xFFFF)
//   VADD/VADDC  saturating add with the carry VADDC leaves (VCO)
//
// DMEM keeps 32-bit words in host order (rsp.hpp): byte a is at dmem[a ^ 3], the
// halfword at an even a at dmem + (a ^ 2). Addresses wrap at 4 KiB like the RSP's.

#include "audio_hle.hpp"

#include <cstdio>
#include <cstring>
#include <vector>
#ifdef AUDIO_HLE_PROFILE
#include <chrono>
#endif

#if (defined(__ARM_NEON) || defined(__ARM_NEON__)) && !defined(AUDIO_HLE_NO_NEON)
#include <arm_neon.h>
#define AUDIO_HLE_NEON 1
#else
#define AUDIO_HLE_NEON 0
#endif

RspExitReason conker_audio_ucode(uint8_t* rdram, uint32_t ucode_addr);
RspExitReason conker_audio_ucode1(uint8_t* rdram, RspContext* ctx);

namespace {
    using conker::audio_hle::Stats;
    Stats hle_stats{};

    typedef int16_t __attribute__((may_alias)) s16a;
    typedef uint32_t __attribute__((may_alias)) u32a;

    // ------------------------------------------------------------------ DMEM access
    inline uint8_t& B(uint32_t a) { return dmem[(a & 0xFFF) ^ 3]; }
    // An even address.
    inline s16a& H(uint32_t a) { return *reinterpret_cast<s16a*>(dmem + ((a & 0xFFF) ^ 2)); }
    // Halfwords from a 4-aligned address, in host order (for whole vectors: see cmd_envmixer).
    inline s16a* hp(uint32_t a) { return reinterpret_cast<s16a*>(dmem + a); }
    // A 4-aligned address.
    inline u32a& W(uint32_t a) { return *reinterpret_cast<u32a*>(dmem + (a & 0xFFC)); }

    // An RDRAM word, as DMA sees it (8 MiB, host-order words).
    inline uint32_t rdram_word(const uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<const u32a*>(rdram + (addr & 0xFFFFFC));
    }

    // RDRAM writes, logged with what they overwrite in the check mode (conker_audio_hle_check).
    struct Undo {
        uint32_t addr;
        uint32_t size;
        uint32_t offset;  // in undo_bytes
    };
    bool logging = false;
    std::vector<Undo> undo_log;
    std::vector<uint8_t> undo_bytes;

    void rdram_write(uint8_t* rdram, uint32_t dmem_addr, uint32_t dram_addr, uint32_t len_minus_1) {
        if (logging) {
            // dma_dmem_to_rdram's whole words, from the 8-byte aligned address.
            const uint32_t addr = dram_addr & 0xFFFFF8;
            const uint32_t size = ((len_minus_1 + 1) + 3) & ~3u;
            undo_log.push_back({addr, size, (uint32_t)undo_bytes.size()});
            undo_bytes.insert(undo_bytes.end(), rdram + addr, rdram + addr + size);
        }
        dma_dmem_to_rdram(rdram, dmem_addr, dram_addr, len_minus_1);
    }

    // ------------------------------------------------------------------ VU arithmetic
    inline int16_t clamp16(int64_t v) {
        return v > 0x7FFF ? 0x7FFF : v < -0x8000 ? -0x8000 : (int16_t)v;
    }
    inline int16_t sat16(int32_t v) {
        return v > 0x7FFF ? 0x7FFF : v < -0x8000 ? -0x8000 : (int16_t)v;
    }
    // VMULF: (2ab + 0x8000) >> 16 is (ab + 0x4000) >> 15; only -0x8000 * -0x8000 saturates.
    inline int16_t mulf(int16_t a, int16_t b) {
        const int32_t r = ((int32_t)a * b + 0x4000) >> 15;
        return r > 0x7FFF ? 0x7FFF : (int16_t)r;
    }
    // VMULF out by 0x7FFF, then VMACF x * g: the mixers' "out = out + x * g". The sum
    // fits 32 bits.
    inline int16_t mix(int16_t out, int16_t x, int16_t g) {
        return sat16((int32_t)((uint32_t)((int32_t)out * 0x7FFF) + (uint32_t)((int32_t)x * g) + 0x4000u) >> 15);
    }
    // VADD (no carry in).
    inline int16_t add_sat(int16_t a, int16_t b) { return sat16((int32_t)a + b); }
    // The accumulator's low slice as VMADN/VMUDN return it (acc sign-extended from 48 bits).
    inline uint16_t acc_low(int64_t acc) {
        if (acc < -(int64_t)0x80000000) return 0;
        if (acc > 0x7FFFFFFF) return 0xFFFF;
        return (uint16_t)acc;
    }
    // The accumulator's middle slice as VMADH/VMADM/VMACF return it.
    inline int16_t acc_mid(int64_t acc) { return clamp16(acc >> 16); }

    // ------------------------------------------------------------------ the task
    struct Task {
        uint8_t* rdram;
        uint32_t gp;   // the list's next command in RDRAM
        int32_t k1;    // the list's bytes left
        int32_t fp;    // the loaded chunk's bytes left
        uint32_t sp;   // the command in DMEM
        // The vector registers v29 and v30 as the microcode leaves them: cmd 0xE stores
        // lanes of them left from earlier commands (to DMEM, and to RDRAM in its state).
        int16_t v29[8];
        int16_t v30[8];
    };

    constexpr uint32_t t8 = 0xFA0;  // the state buffer
    constexpr uint32_t nbytes = 0x170;  // every buffer command's length (184 samples)

    // Reads the next chunk of the list into DMEM 0x2C0 (load_acmd_list).
    void load_list(Task& t) {
        int32_t v1 = t.k1;
        if (v1 - 0x140 > 0) v1 = 0x140;
        t.fp = v1;
        dma_rdram_to_dmem(t.rdram, 0x2C0, t.gp, (uint32_t)(v1 - 1));
        t.sp = 0x2C0;
    }

    // ------------------------------------------------------------------ commands
    // 0x00: in-place gain, x * a clamped, then times b / 65536 (and the microcode counts
    // it twice against the loaded chunk).
    void cmd_gain(uint32_t w0, uint32_t w1) {
        uint32_t at = w0 + 0x500;
        const int16_t a = (int16_t)w1;
        const uint16_t b = (uint16_t)(w1 >> 16);
        for (uint32_t n = 0; n < nbytes; n += 16, at += 16) {
            for (int i = 0; i < 8; i++) {
                const int16_t x = clamp16((int32_t)H(at + 2 * i) * a);
                H(at + 2 * i) = (int16_t)(((int32_t)x * b) >> 16);
            }
        }
    }

    // 0x01: ADPCM decode.
    void cmd_adpcm(Task& t, uint32_t w0, uint32_t w1) {
        const uint32_t flags = w1 >> 28;
        uint32_t in = 0x500 + ((w1 >> 12) & 0xF);
        uint32_t at = (w1 & 0xFFF) + 0x500;
        int32_t count = (w1 >> 16) & 0xFFF;
        const uint32_t state = w0 & 0xFFFFFF;

        int16_t prev6, prev7;
        if (flags & 1) {
            for (int i = 0; i < 16; i++) H(at + 2 * i) = 0;
            prev6 = prev7 = 0;
        } else {
            const uint32_t src = (flags & 2) ? (uint32_t)W(0xFFC) : state;
            dma_rdram_to_dmem(t.rdram, at, src, 0x1F);
            prev6 = H(at + 0x1C);
            prev7 = H(at + 0x1E);
        }
        at += 0x20;

        if (count != 0) {
            // The microcode reads a block's header, data and book before it writes the
            // previous block's samples.
            uint8_t hdr = B(in);
            uint8_t data[8];
            for (int i = 0; i < 8; i++) data[i] = B(in + 1 + i);
            int16_t book0[8], book1[8];
            uint32_t s0 = 0x400 + ((hdr & 0xF) << 5);
            for (int i = 0; i < 8; i++) {
                book0[i] = H(s0 + 2 * i);
                book1[i] = H(s0 + 0x10 + 2 * i);
            }
            do {
                const uint8_t cur_hdr = hdr;
                uint8_t cur[8];
                std::memcpy(cur, data, 8);
                int16_t c0[8], c1[8];
                std::memcpy(c0, book0, sizeof(c0));
                std::memcpy(c1, book1, sizeof(c1));
                in += 9;
                hdr = B(in);
                for (int i = 0; i < 8; i++) data[i] = B(in + 1 + i);
                s0 = 0x400 + ((hdr & 0xF) << 5);
                for (int i = 0; i < 8; i++) {
                    book0[i] = H(s0 + 2 * i);
                    book1[i] = H(s0 + 0x10 + 2 * i);
                }

                // The nibbles, << 12, then scaled: by 2^scale up to 12 (VMUDM by 0x8000 >> (11 - scale)).
                const int32_t s1 = 12 - (cur_hdr >> 4);
                const uint16_t mult = s1 > 0 ? (uint16_t)(0x8000u >> ((uint32_t)(s1 - 1) & 31)) : 0;
                int16_t ins[16];
                for (int i = 0; i < 8; i++) {
                    const int16_t hi = (int16_t)((cur[i] & 0xF0) << 8);
                    const int16_t lo = (int16_t)((cur[i] & 0x0F) << 12);
                    ins[2 * i] = s1 > 0 ? (int16_t)(((int32_t)hi * mult) >> 16) : hi;
                    ins[2 * i + 1] = s1 > 0 ? (int16_t)(((int32_t)lo * mult) >> 16) : lo;
                }
                std::memcpy(t.v30, ins, sizeof(t.v30));
                std::memcpy(t.v29, ins + 8, sizeof(t.v29));
                // out[j] = (c0[j] p6 + c1[j] p7 + sum_k<j c1[j-1-k] x[k] + x[j] << 11) >> 11, the
                // sum wrapping at 32 bits like the accumulator's.
#if AUDIO_HLE_NEON
                {
                    const int16x8_t v0 = vld1q_s16(c0), v1 = vld1q_s16(c1);
                    static const int16_t prefix_data[8] = {0, 0, 0, 0, 0, 0, 0, 1 << 11};
                    const int16x8_t prefix = vld1q_s16(prefix_data);
                    // col[k]: lane k 2048, lanes above it c1 from its start.
                    int16x8_t col[8];
                    col[0] = vextq_s16(prefix, v1, 7);
                    col[1] = vextq_s16(prefix, v1, 6);
                    col[2] = vextq_s16(prefix, v1, 5);
                    col[3] = vextq_s16(prefix, v1, 4);
                    col[4] = vextq_s16(prefix, v1, 3);
                    col[5] = vextq_s16(prefix, v1, 2);
                    col[6] = vextq_s16(prefix, v1, 1);
                    col[7] = prefix;
                    int16x8_t res[2];
                    for (int half = 0; half < 2; half++) {
                        const int16_t* x = ins + 8 * half;
                        int32x4_t lo = vmull_n_s16(vget_low_s16(v0), prev6);
                        int32x4_t hi = vmull_n_s16(vget_high_s16(v0), prev6);
                        lo = vmlal_n_s16(lo, vget_low_s16(v1), prev7);
                        hi = vmlal_n_s16(hi, vget_high_s16(v1), prev7);
                        for (int k = 0; k < 8; k++) {
                            lo = vmlal_n_s16(lo, vget_low_s16(col[k]), x[k]);
                            hi = vmlal_n_s16(hi, vget_high_s16(col[k]), x[k]);
                        }
                        res[half] = vcombine_s16(vqshrn_n_s32(lo, 11), vqshrn_n_s32(hi, 11));
                        prev6 = vgetq_lane_s16(res[half], 6);
                        prev7 = vgetq_lane_s16(res[half], 7);
                    }
                    if (((at & 0xFFF) + 0x20) <= 0x1000) {
                        // Memory order swaps each pair of halfwords.
                        vst1q_s16(hp(at & 0xFFF), vrev32q_s16(res[0]));
                        vst1q_s16(hp((at & 0xFFF) + 16), vrev32q_s16(res[1]));
                    } else {
                        int16_t out[16];
                        vst1q_s16(out, res[0]);
                        vst1q_s16(out + 8, res[1]);
                        for (int i = 0; i < 16; i++) H(at + 2 * i) = out[i];
                    }
                }
#else
                int16_t out[16];
                for (int half = 0; half < 2; half++) {
                    const int16_t* x = ins + 8 * half;
                    for (int j = 0; j < 8; j++) {
                        uint32_t sum = (uint32_t)((int32_t)c0[j] * prev6) + (uint32_t)((int32_t)c1[j] * prev7);
                        for (int k = 0; k < j; k++) sum += (uint32_t)((int32_t)c1[j - 1 - k] * x[k]);
                        sum += (uint32_t)((int32_t)x[j] << 11);
                        out[8 * half + j] = clamp16((int32_t)sum >> 11);
                    }
                    prev6 = out[8 * half + 6];
                    prev7 = out[8 * half + 7];
                }
                for (int i = 0; i < 16; i++) H(at + 2 * i) = out[i];
#endif
                at += 0x20;
                count -= 0x20;
            } while (count > 0);
        }
        rdram_write(t.rdram, at - 0x20, state, 0x1F);
    }

    // 0x02: clear (in 16-byte steps, at least one).
    void cmd_clearbuff(uint32_t w0, uint32_t w1) {
        int32_t n = w1 & 0xFFFF;
        uint32_t a = w0 + 0x500;
        do {
            if ((a & 3) == 0) {
                for (int i = 0; i < 16; i += 4) W(a + i) = 0;
            } else {
                for (int i = 0; i < 16; i++) B(a + i) = 0;
            }
            n -= 16;
            a += 16;
        } while (n > 0);
    }

    // 0x03: envelope mixer, the input (0x500) to dry/wet left/right (0x9E0, 0xB50, 0xCC0, 0xE30).
    const int16_t env_crossfade[8] = {(int16_t)0x999a, (int16_t)0xb334, (int16_t)0xcccd, (int16_t)0xe667, 0x1999, 0x3333, 0x4ccc, 0x6666};
    const uint16_t env_ramp[8] = {0x2000, 0x4000, 0x6000, 0x8000, 0xa000, 0xc000, 0xe000, 0xffff};

    // The buffers' 16-byte steps are 8 lanes; in DMEM's host order a step's halfword k is
    // lane k ^ 1. The envelope's per-lane state is kept in that order too, so a step is
    // just 8 halfwords in memory.
    void cmd_envmixer(Task& t, uint32_t w0, uint32_t w1) {
        const uint32_t state = w1 & 0xFFFFFF;
        const bool init = (w0 >> 16) & 1;
        for (int i = 0; i < 8; i++) t.v30[i] = H(0x90 + 2 * i);
        if (!init) dma_rdram_to_dmem(t.rdram, t8, state, 0x4F);
        int16_t p[8];
        for (int i = 0; i < 8; i++) p[i] = H(t8 + 0x40 + 2 * i);
        // p: 0 left target, 1:2 left rate (per 8 samples), 3 right target, 4:5 right rate,
        // 6 dry level, 7 wet level; bit 0 of 6/7 inverts left/right, bit 1 crossfades the
        // first 8 samples.
        const int16_t sign_l = (p[6] & 1) ? (int16_t)-0x8000 : 0x7FFF;
        const int16_t sign_r = (p[7] & 1) ? (int16_t)-0x8000 : 0x7FFF;
        // Lane state, in memory order (index k is lane k ^ 1).
        alignas(16) int16_t gain_l[8], gain_r[8], vol_l[8], vol_r[8];
        alignas(16) uint16_t frac_l[8], frac_r[8];
        for (int i = 0; i < 8; i++) {
            gain_l[i ^ 1] = mulf((p[6] & 2) ? env_crossfade[i] : 0x7FFF, sign_l);
            gain_r[i ^ 1] = mulf((p[7] & 2) ? env_crossfade[i] : 0x7FFF, sign_r);
        }
        if (init) {
            const int16_t start_l = H(0xFF0), start_r = (int16_t)w0;
            for (int i = 0; i < 8; i++) {
                int64_t acc = ((uint32_t)env_ramp[i] * (uint16_t)p[2]) >> 16;
                acc += (int64_t)((int32_t)env_ramp[i] * p[1]);
                acc += (int64_t)start_l << 16;
                vol_l[i ^ 1] = acc_mid(acc);
                frac_l[i ^ 1] = acc_low(acc);
                acc = ((uint32_t)env_ramp[i] * (uint16_t)p[5]) >> 16;
                acc += (int64_t)((int32_t)env_ramp[i] * p[4]);
                acc += (int64_t)start_r << 16;
                vol_r[i ^ 1] = acc_mid(acc);
                frac_r[i ^ 1] = acc_low(acc);
            }
        } else {
            std::memcpy(vol_l, dmem + t8, 16);
            std::memcpy(frac_l, dmem + t8 + 0x10, 16);
            std::memcpy(vol_r, dmem + t8 + 0x20, 16);
            std::memcpy(frac_r, dmem + t8 + 0x30, 16);
        }
        const bool up_l = p[1] >= 0, up_r = p[4] >= 0;
#if AUDIO_HLE_NEON
        int16x8_t vl = vld1q_s16(vol_l), vr = vld1q_s16(vol_r);
        uint16x8_t fl = vld1q_u16(frac_l), fr = vld1q_u16(frac_r);
        const int16x8_t tgt_l = vdupq_n_s16(p[0]), tgt_r = vdupq_n_s16(p[3]);
        const uint16x8_t rate_lo_l = vdupq_n_u16((uint16_t)p[2]), rate_lo_r = vdupq_n_u16((uint16_t)p[5]);
        const int16x4_t rate_hi_l = vdup_n_s16(p[1]), rate_hi_r = vdup_n_s16(p[4]);
        int16x8_t gl = vld1q_s16(gain_l), gr = vld1q_s16(gain_r);
        // vol + rate_hi + carry, saturated once.
        auto step = [](int16x8_t vol, uint16x8_t& frac, uint16x8_t rate_lo, int16x4_t rate_hi) {
            const uint16x8_t f = vaddq_u16(frac, rate_lo);
            const int16x8_t carry = vreinterpretq_s16_u16(vcltq_u16(f, frac));  // -1 where it carried
            frac = f;
            const int32x4_t lo = vsubq_s32(vaddl_s16(vget_low_s16(vol), rate_hi), vmovl_s16(vget_low_s16(carry)));
            const int32x4_t hi = vsubq_s32(vaddl_s16(vget_high_s16(vol), rate_hi), vmovl_s16(vget_high_s16(carry)));
            return vcombine_s16(vqmovn_s32(lo), vqmovn_s32(hi));
        };
        auto mixv = [](s16a* o, int16x8_t x, int16x8_t g) {
            const int16x8_t ov = vld1q_s16(o);
            int32x4_t lo = vmull_n_s16(vget_low_s16(ov), 0x7FFF);
            int32x4_t hi = vmull_n_s16(vget_high_s16(ov), 0x7FFF);
            lo = vmlal_s16(lo, vget_low_s16(x), vget_low_s16(g));
            hi = vmlal_s16(hi, vget_high_s16(x), vget_high_s16(g));
            vst1q_s16(o, vcombine_s16(vqrshrn_n_s32(lo, 15), vqrshrn_n_s32(hi, 15)));
        };
        int16x8_t last_dry_l = vdupq_n_s16(0);
        for (uint32_t c = 0; c < nbytes / 16; c++) {
            if (c > 0 || !init) {
                vl = step(vl, fl, rate_lo_l, rate_hi_l);
                vr = step(vr, fr, rate_lo_r, rate_hi_r);
            }
            vl = up_l ? vminq_s16(vl, tgt_l) : vmaxq_s16(vl, tgt_l);
            vr = up_r ? vminq_s16(vr, tgt_r) : vmaxq_s16(vr, tgt_r);
            const uint32_t o = 16 * c;
            const int16x8_t in = vld1q_s16(hp(0x500 + o));
            const int16x8_t xl = vqrdmulhq_s16(in, gl), xr = vqrdmulhq_s16(in, gr);
            mixv(hp(0x9E0 + o), xl, vqrdmulhq_n_s16(vl, p[6]));
            mixv(hp(0xCC0 + o), xl, vqrdmulhq_n_s16(vl, p[7]));
            mixv(hp(0xB50 + o), xr, vqrdmulhq_n_s16(vr, p[6]));
            mixv(hp(0xE30 + o), xr, vqrdmulhq_n_s16(vr, p[7]));
            if (c == 0) {
                gl = vdupq_n_s16(sign_l);
                gr = vdupq_n_s16(sign_r);
            }
            if (c + 1 == nbytes / 16) last_dry_l = vld1q_s16(hp(0x9E0 + o));
        }
        vst1q_s16(vol_l, vl);
        vst1q_u16(frac_l, fl);
        vst1q_s16(vol_r, vr);
        vst1q_u16(frac_r, fr);
        alignas(16) int16_t dl[8];
        vst1q_s16(dl, last_dry_l);
        for (int i = 0; i < 8; i++) t.v29[i] = dl[i ^ 1];
#else
        for (uint32_t c = 0; c < nbytes / 16; c++) {
            const uint32_t o = 16 * c;
            const s16a* in = hp(0x500 + o);
            s16a* dry_l = hp(0x9E0 + o);
            s16a* wet_l = hp(0xCC0 + o);
            s16a* dry_r = hp(0xB50 + o);
            s16a* wet_r = hp(0xE30 + o);
            for (int k = 0; k < 8; k++) {
                if (c > 0 || !init) {
                    uint32_t f = (uint32_t)frac_l[k] + (uint16_t)p[2];
                    frac_l[k] = (uint16_t)f;
                    vol_l[k] = sat16((int32_t)vol_l[k] + p[1] + (int32_t)(f >> 16));
                    f = (uint32_t)frac_r[k] + (uint16_t)p[5];
                    frac_r[k] = (uint16_t)f;
                    vol_r[k] = sat16((int32_t)vol_r[k] + p[4] + (int32_t)(f >> 16));
                }
                vol_l[k] = up_l ? (vol_l[k] < p[0] ? vol_l[k] : p[0]) : (vol_l[k] > p[0] ? vol_l[k] : p[0]);
                vol_r[k] = up_r ? (vol_r[k] < p[3] ? vol_r[k] : p[3]) : (vol_r[k] > p[3] ? vol_r[k] : p[3]);
                const int16_t xl = mulf(in[k], c == 0 ? gain_l[k] : sign_l);
                const int16_t xr = mulf(in[k], c == 0 ? gain_r[k] : sign_r);
                dry_l[k] = mix(dry_l[k], xl, mulf(vol_l[k], p[6]));
                wet_l[k] = mix(wet_l[k], xl, mulf(vol_l[k], p[7]));
                dry_r[k] = mix(dry_r[k], xr, mulf(vol_r[k], p[6]));
                wet_r[k] = mix(wet_r[k], xr, mulf(vol_r[k], p[7]));
            }
        }
        for (int i = 0; i < 8; i++) t.v29[i] = H(0x9E0 + nbytes - 16 + 2 * i);
#endif
        std::memcpy(dmem + t8, vol_l, 16);
        std::memcpy(dmem + t8 + 0x10, frac_l, 16);
        std::memcpy(dmem + t8 + 0x20, vol_r, 16);
        std::memcpy(dmem + t8 + 0x30, frac_r, 16);
        rdram_write(t.rdram, t8, state, 0x4F);
    }

    // 0x04 / 0x06: DMA a buffer in / out.
    void cmd_loadbuff(Task& t, uint32_t w0, uint32_t w1) {
        const uint32_t len = (w0 >> 12) & 0xFFF;
        if (len == 0) return;
        dma_rdram_to_dmem(t.rdram, w0 + 0x500, w1 & 0xFFFFFF, len - 1);
    }
    void cmd_savebuff(Task& t, uint32_t w0, uint32_t w1) {
        const uint32_t len = (w0 >> 12) & 0xFFF;
        if (len == 0) return;
        rdram_write(t.rdram, w0 + 0x500, w1 & 0xFFFFFF, len - 1);
    }

    // 0x05: resample (4-tap filter, the table at DMEM 0xC0) to 0x500 or 0x670.
    void cmd_resample(Task& t, uint32_t w0, uint32_t w1) {
        const uint32_t state = w0 & 0xFFFFFF;
        const uint32_t s4 = (w1 >> 2) + 0x4F8;  // the input, less the 4 samples kept
        const uint32_t pitch = (w1 >> 14) & 0xFFFF;
        const uint32_t out = (w1 & 3) ? 0x670 : 0x500;
        for (int i = 0; i < 8; i++) {
            t.v30[i] = H(0x60 + 2 * i);
            t.v29[i] = (int16_t)(H(0x70 + 2 * i) ^ H(0x70 + 2 * (i | 1)));
        }
        int16_t keep[4] = {0, 0, 0, 0};
        uint32_t pos = 0;
        if ((w1 >> 30) == 0) {
            dma_rdram_to_dmem(t.rdram, t8, state, 0xF);
            for (int i = 0; i < 4; i++) keep[i] = H(t8 + 2 * i);
            pos = (uint16_t)H(t8 + 8);
        }
        for (int i = 0; i < 4; i++) H(s4 + 2 * i) = keep[i];
        const uint32_t step = pitch * 2;
        // The microcode keeps each step's 8 input and table addresses in DMEM, 0xFB0 and
        // 0xFC0, and two bytes of its fractions at 0xFA8: an input near the end of DMEM
        // reads them.
        B(t8 + 8) = (uint8_t)(pos + 3 * step);
        B(t8 + 9) = (uint8_t)((pos + 4 * step) >> 8);
        auto addresses = [&](uint32_t p) {
            for (int i = 0; i < 8; i++, p += step) {
                H(0xFB0 + 2 * i) = (int16_t)(s4 + 2 * (p >> 16));
                H(0xFC0 + 2 * i) = (int16_t)(0xC0 + ((p & 0xFFFF) >> 10) * 8);
            }
        };
        // Inputs that stay below the microcode's scratch (and don't wrap) never see it.
        const uint32_t last = (pos + step * (nbytes / 2 + 7)) >> 16;
        const bool plain = (s4 & 0xFFF) + 2 * last + 8 <= t8;
        for (uint32_t c = 0; c < nbytes / 16; c++) {
            if (!plain) addresses(pos);
            // Each output: sat(sat(x0 c0 + x1 c1) + sat(x2 c2 + x3 c3)), VMULF products.
            alignas(16) int16_t x[4][8], cf[4][8];
            for (int i = 0; i < 8; i++) {
                const uint32_t in = s4 + 2 * (pos >> 16);
                const s16a* cp = hp(0xC0 + ((pos & 0xFFFF) >> 10) * 8);  // memory order: c1 c0 c3 c2
                if (plain) {
                    const uint32_t a = in & 0xFFF;
                    x[0][i] = *hp(a ^ 2);
                    x[1][i] = *hp((a + 2) ^ 2);
                    x[2][i] = *hp((a + 4) ^ 2);
                    x[3][i] = *hp((a + 6) ^ 2);
                } else {
                    x[0][i] = H(in);
                    x[1][i] = H(in + 2);
                    x[2][i] = H(in + 4);
                    x[3][i] = H(in + 6);
                }
                cf[0][i] = cp[1];
                cf[1][i] = cp[0];
                cf[2][i] = cp[3];
                cf[3][i] = cp[2];
                pos += step;
            }
            s16a* op = hp(out + 16 * c);
#if AUDIO_HLE_NEON
            const int16x8_t a = vqaddq_s16(vqrdmulhq_s16(vld1q_s16(x[0]), vld1q_s16(cf[0])), vqrdmulhq_s16(vld1q_s16(x[1]), vld1q_s16(cf[1])));
            const int16x8_t b = vqaddq_s16(vqrdmulhq_s16(vld1q_s16(x[2]), vld1q_s16(cf[2])), vqrdmulhq_s16(vld1q_s16(x[3]), vld1q_s16(cf[3])));
            vst1q_s16(op, vrev32q_s16(vqaddq_s16(a, b)));
#else
            for (int i = 0; i < 8; i++) {
                const int16_t a = add_sat(mulf(x[0][i], cf[0][i]), mulf(x[1][i], cf[1][i]));
                const int16_t b = add_sat(mulf(x[2][i], cf[2][i]), mulf(x[3][i], cf[3][i]));
                op[i ^ 1] = add_sat(a, b);
            }
#endif
        }
        // The state: the 4 samples at the next position, and its fraction.
        addresses(pos);
        const uint32_t in = s4 + 2 * (pos >> 16);
        int16_t next[4];
        for (int i = 0; i < 4; i++) next[i] = H(in + 2 * i);
        H(t8 + 8) = (int16_t)(pos & 0xFFFF);
        for (int i = 0; i < 4; i++) H(t8 + 2 * i) = next[i];
        rdram_write(t.rdram, t8, state, 0xF);
    }

    // 0x09: envelope parameters, to DMEM 0xFE0.. (and 0xFF0, the left start).
    void cmd_setvol(uint32_t w0, uint32_t w1) {
        const uint32_t flags = w0 >> 16;
        const int16_t a = (int16_t)w0, b = (int16_t)(w1 >> 16), c = (int16_t)w1;
        if (flags & 4) {
            if (flags & 2) {
                H(t8 + 0x50) = a;
                H(t8 + 0x4C) = b;
                H(t8 + 0x4E) = c;
            }
            H(t8 + 0x46) = a;
            H(t8 + 0x48) = b;
            H(t8 + 0x4A) = c;
        }
        H(t8 + 0x40) = a;
        H(t8 + 0x42) = b;
        H(t8 + 0x44) = c;
    }

    // 0x0A: move in 16-byte steps (at least one).
    void cmd_dmemmove(uint32_t w0, uint32_t w1) {
        int32_t n = w1 & 0xFFFF;
        uint32_t src = w0 + 0x500;
        uint32_t dst = (w1 >> 16) + 0x500;
        do {
            if (((src | dst) & 3) == 0) {
                uint32_t tmp[4];
                for (int i = 0; i < 4; i++) tmp[i] = W(src + 4 * i);
                for (int i = 0; i < 4; i++) W(dst + 4 * i) = tmp[i];
            } else {
                uint8_t tmp[16];
                for (int i = 0; i < 16; i++) tmp[i] = B(src + i);
                for (int i = 0; i < 16; i++) B(dst + i) = tmp[i];
            }
            n -= 16;
            src += 16;
            dst += 16;
        } while (n > 0);
    }

    // 0x0C: out += in * gain.
    void cmd_mixer(Task& t, uint32_t w0, uint32_t w1) {
        const int16_t gain = (int16_t)w0;
        t.v30[0] = gain;
        uint32_t o = (w1 + 0x500) & 0xFFF;
        uint32_t in = ((w1 >> 16) + 0x500) & 0xFFF;
        if (o + nbytes <= 0x1000 && in + nbytes <= 0x1000 && in != ((o - 16) & 0xFFF)) {
            // Same order as the microcode's (whole vectors, no wrap, and not the one overlap
            // its read-ahead shows): elementwise in memory order.
            s16a* op = hp(o);
            const s16a* ip = hp(in);
#if AUDIO_HLE_NEON
            for (uint32_t k = 0; k < nbytes / 2; k += 8) {
                const int16x8_t ov = vld1q_s16(op + k), x = vld1q_s16(ip + k);
                int32x4_t lo = vmull_n_s16(vget_low_s16(ov), 0x7FFF);
                int32x4_t hi = vmull_n_s16(vget_high_s16(ov), 0x7FFF);
                lo = vmlal_n_s16(lo, vget_low_s16(x), gain);
                hi = vmlal_n_s16(hi, vget_high_s16(x), gain);
                vst1q_s16(op + k, vcombine_s16(vqrshrn_n_s32(lo, 15), vqrshrn_n_s32(hi, 15)));
            }
#else
            for (uint32_t k = 0; k < nbytes / 2; k++) op[k] = mix(op[k], ip[k], gain);
#endif
            for (int i = 0; i < 8; i++) t.v29[i] = H(in + nbytes + 2 * i);
            return;
        }
        // The microcode reads the next step's input before it writes this step's output:
        // that shows when the input is the output less 16 bytes.
        int16_t next_o[8], next_in[8];
        for (int i = 0; i < 8; i++) {
            next_o[i] = H(o + 2 * i);
            next_in[i] = H(in + 2 * i);
        }
        for (uint32_t n = 0; n < nbytes; n += 16) {
            int16_t res[8];
            for (int i = 0; i < 8; i++) res[i] = mix(next_o[i], next_in[i], gain);
            o += 16;
            in += 16;
            for (int i = 0; i < 8; i++) {
                next_o[i] = H(o + 2 * i);
                next_in[i] = H(in + 2 * i);
            }
            for (int i = 0; i < 8; i++) H(o - 16 + 2 * i) = res[i];
        }
        std::memcpy(t.v29, next_in, sizeof(t.v29));
    }

    // 0x0D: interleave 0x9E0 and 0xB50 to 0x500.
    void cmd_interleave() {
        for (uint32_t n = 0; n < nbytes; n += 16) {
            int16_t l[8], r[8];
            for (int i = 0; i < 8; i++) {
                l[i] = H(0x9E0 + n + 2 * i);
                r[i] = H(0xB50 + n + 2 * i);
            }
            for (int i = 0; i < 8; i++) {
                H(0x500 + 2 * n + 4 * i) = l[i];
                H(0x500 + 2 * n + 4 * i + 2) = r[i];
            }
        }
    }

    // 0x0E with DMEM 0x400 not zero: an in-place biquad on w0 + 0x500, with T the halfwords
    // at DMEM 0x400: f = T00 x + T02 x[-1] + T00 x[-2], y = f + 2 T10 y[-1] + 2 T12 y[-2]
    // (VMULF products, saturating sums). With T02 and T04 zero the microcode only writes
    // its state (and 16 bytes before the buffer), from registers left by earlier commands.
    void cmd_biquad(Task& t, uint32_t w0, uint32_t w1) {
        const uint32_t base = w0 + 0x500;
        const bool init = (w0 >> 16) & 1;
        const uint32_t s2 = ((uint32_t)(uint16_t)H(0x402) << 16) | (uint16_t)H(0x404);
        const int16_t t00 = H(0x400), t02 = H(0x402), t10 = H(0x410), t12 = H(0x412);
        int16_t st[4] = {0, 0, 0, 0};
        if (!init) {
            dma_rdram_to_dmem(t.rdram, t8, w1, 7);
            for (int i = 0; i < 4; i++) st[i] = H(t8 + 2 * i);
        }
        if (s2 == 0) {
            for (int i = 0; i < 8; i++) t.v30[i] = H(base + 2 * i);
            t.v29[7] = st[3];
            H(t8) = st[0];
            H(t8 + 2) = st[1];
            H(t8 + 4) = t.v29[6];
            H(t8 + 6) = t.v29[7];
            for (int i = 0; i < 8; i++) H(base - 16 + 2 * i) = t.v29[i];
            rdram_write(t.rdram, t8, w1, 7);
            return;
        }
        int16_t x2 = st[0], x1 = st[1], y2 = st[2], y1 = st[3];
        int16_t y[8];
        for (uint32_t n = 0; n < nbytes; n += 16) {
            for (int i = 0; i < 8; i++) {
                const int16_t x = H(base + n + 2 * i);
                const int16_t f = add_sat(add_sat(mulf(t00, x), mulf(t02, x1)), mulf(t00, x2));
                const int16_t a = add_sat(add_sat(mulf(t12, y2), mulf(t12, y2)), f);
                y[i] = add_sat(a, add_sat(mulf(t10, y1), mulf(t10, y1)));
                x2 = x1;
                x1 = x;
                y2 = y1;
                y1 = y[i];
            }
            // The microcode stores each step's output during the next step (the last one
            // after its state).
            if (n + 16 < nbytes) for (int i = 0; i < 8; i++) H(base + n + 2 * i) = y[i];
        }
        std::memcpy(t.v29, y, sizeof(t.v29));
        // It reads the vector after the buffer too.
        for (int i = 0; i < 8; i++) t.v30[i] = mulf(H(base + nbytes + 2 * i), t00);
        H(t8) = x2;
        H(t8 + 2) = x1;
        H(t8 + 4) = y2;
        H(t8 + 6) = y1;
        for (int i = 0; i < 8; i++) H(base + nbytes - 16 + 2 * i) = y[i];
        rdram_write(t.rdram, t8, w1, 7);
    }

    // 0x0E with DMEM 0x400 zero (the variant Conker's lists use): an in-place IIR filter
    // on 0x500 or 0x670, out[i] = (c[i] y[-1] + sum c'[i-1-j] x[j] + gain x[i]) >> 14, with
    // c the 8 coefficients at DMEM 0x410 and c' them times gain * 4 / 65536 (left at 0x410).
    void cmd_filter(Task& t, uint32_t w0, uint32_t w1) {
        const uint32_t base = (w1 >> 24) ? 0x670 : 0x500;
        const uint32_t state = w1 & 0xFFFFFF;
        const int16_t gain = (int16_t)w0;
        const uint16_t scale = (uint16_t)(w0 << 2);
        const bool init = ((w0 << 2) >> 16) & 1;
        int16_t c[8], cs[8];
        for (int i = 0; i < 8; i++) {
            c[i] = H(0x410 + 2 * i);
            cs[i] = (int16_t)(((int32_t)c[i] * scale) >> 16);
        }
        for (int i = 0; i < 8; i++) H(0x410 + 2 * i) = cs[i];
        int16_t y[8];
        if (init) {
            for (int i = 0; i < 8; i++) y[i] = 0;
        } else {
            dma_rdram_to_dmem(t.rdram, t8, state, 7);
            for (int i = 0; i < 4; i++) y[i] = t.v30[i];
            for (int i = 0; i < 4; i++) y[4 + i] = H(t8 + 2 * i);
        }
        // The microcode's first store is its v30 as it starts, before the buffer.
        for (int i = 0; i < 8; i++) H(base - 16 + 2 * i) = y[i];
#if AUDIO_HLE_NEON
        {
            // Lane i: c[i] y7 + sum_j<i cs[i-1-j] x[j] + gain x[i], as columns (see cmd_adpcm).
            const int16x8_t vc = vld1q_s16(c), vcs = vld1q_s16(cs);
            const int16_t prefix_data[8] = {0, 0, 0, 0, 0, 0, 0, gain};
            const int16x8_t prefix = vld1q_s16(prefix_data);
            int16x8_t col[8];
            col[0] = vextq_s16(prefix, vcs, 7);
            col[1] = vextq_s16(prefix, vcs, 6);
            col[2] = vextq_s16(prefix, vcs, 5);
            col[3] = vextq_s16(prefix, vcs, 4);
            col[4] = vextq_s16(prefix, vcs, 3);
            col[5] = vextq_s16(prefix, vcs, 2);
            col[6] = vextq_s16(prefix, vcs, 1);
            col[7] = prefix;
            int16_t y7 = y[7];
            int16x8_t res = vdupq_n_s16(0), low = vdupq_n_s16(0);
            for (uint32_t n = 0; n < nbytes; n += 16) {
                const int16x8_t xv = vrev32q_s16(vld1q_s16(hp(base + n)));  // fixed 0x500 / 0x670
                alignas(16) int16_t x[8];
                vst1q_s16(x, xv);
                int32x4_t lo = vmull_n_s16(vget_low_s16(vc), y7);
                int32x4_t hi = vmull_n_s16(vget_high_s16(vc), y7);
                for (int k = 0; k < 8; k++) {
                    lo = vmlal_n_s16(lo, vget_low_s16(col[k]), x[k]);
                    hi = vmlal_n_s16(hi, vget_high_s16(col[k]), x[k]);
                }
                res = vcombine_s16(vqshrn_n_s32(lo, 14), vqshrn_n_s32(hi, 14));
                low = vcombine_s16(vmovn_s32(lo), vmovn_s32(hi));
                y7 = vgetq_lane_s16(res, 7);
                vst1q_s16(hp(base + n), vrev32q_s16(res));
            }
            vst1q_s16(y, res);
            vst1q_s16(t.v29, low);
        }
#else
        for (uint32_t n = 0; n < nbytes; n += 16) {
            int16_t x[8];
            for (int i = 0; i < 8; i++) x[i] = H(base + n + 2 * i);
            const int32_t y7 = y[7];
            for (int i = 0; i < 8; i++) {
                uint32_t sum = (uint32_t)(c[i] * y7) + (uint32_t)((int32_t)x[i] * gain);
                for (int j = 0; j < i; j++) sum += (uint32_t)((int32_t)cs[i - 1 - j] * x[j]);
                y[i] = clamp16((int32_t)sum >> 14);
                t.v29[i] = (int16_t)sum;
            }
            for (int i = 0; i < 8; i++) H(base + n + 2 * i) = y[i];
        }
#endif
        std::memcpy(t.v30, y, sizeof(t.v30));
        rdram_write(t.rdram, base + nbytes - 8, state, 7);
    }

    // 0x07: MP3, by the recompiled microcode's overlay 1, entered as cmd_MP3 would after
    // its DMA of the overlay; it returns when it reloads overlay 0 (reload_overlay_0).
    RspExitReason cmd_mp3(Task& t, uint32_t w0, uint32_t w1) {
        RspContext ctx{};
        ctx.r1 = (uint32_t)(int32_t)H(0xE);  // overlay 1's IMEM address
        ctx.r2 = W(0x8);                      // and DRAM address
        ctx.r3 = (uint32_t)(int32_t)H(0xC);  // and length - 1
        ctx.r24 = t8;
        ctx.r25 = w1;
        ctx.r26 = w0;
        ctx.r27 = (uint32_t)t.k1;
        ctx.r28 = t.gp;
        ctx.r29 = t.sp;
        ctx.r30 = (uint32_t)t.fp;
        ctx.r31 = 0x1224;  // cmd_MP3's return from dma_read
        ctx.dma_mem_address = ctx.r1;
        ctx.dma_dram_address = ctx.r2;
        ctx.jump_target = 0x1224;
        ctx.resume_address = 0x1194;  // dma_read's jr $ra, from its delay slot
        ctx.resume_delay = true;
#ifdef AUDIO_HLE_MP3_GARBAGE  // test: the overlay must not read other registers left by earlier commands
        {
            static uint32_t seed = 12345;
            uint8_t* p = reinterpret_cast<uint8_t*>(&ctx.rsp.vpu);
            for (size_t k = 0; k < sizeof(ctx.rsp.vpu.r); k++) { seed = seed * 1103515245 + 12345; p[k] = (uint8_t)(seed >> 16); }
        }
#endif
        for (int i = 0; i < 8; i++) {
            ctx.rsp.vpu.r[29].s16(i) = t.v29[i];
            ctx.rsp.vpu.r[30].s16(i) = t.v30[i];
        }
        const RspExitReason r = conker_audio_ucode1(t.rdram, &ctx);
        if (r != RspExitReason::SwapOverlay) return r;
        for (int i = 0; i < 8; i++) {
            t.v29[i] = ctx.rsp.vpu.r[29].s16(i);
            t.v30[i] = ctx.rsp.vpu.r[30].s16(i);
        }
        // The rest of reload_overlay_0: overlay 0's data back to DMEM 0x10.
        dma_rdram_to_dmem(t.rdram, 0x10, W(0xFF8) + 0x10, 0x2AF);
        t.k1 = (int32_t)ctx.r27;
        t.gp = ctx.r28;
        t.sp = ctx.r29;
        t.fp = (int32_t)ctx.r30;
        return RspExitReason::Invalid;  // continue
    }
}

namespace {
    // Whether [a, a + len) and [b, b + n) (DMEM addresses, wrapping) overlap.
    bool overlaps(uint32_t a, uint32_t len, uint32_t b, uint32_t n) {
        if (len >= 0x1000 || n >= 0x1000) return true;
        return ((b - a) & 0xFFF) < len || ((a - b) & 0xFFF) < n;
    }
}

namespace conker::audio_hle {
    namespace {
        int unsupported_at = -1;
        bool unsupported(uint32_t offset) {
            unsupported_at = (int)(offset / 8);
            return false;
        }
    }
    int unsupported_command() { return unsupported_at; }

    bool task_supported(const uint8_t* rdram) {
        unsupported_at = -1;
        const uint32_t data_ptr = W(0xFF0);
        const uint32_t data_size = W(0xFF4);
        if ((data_ptr & 7) != 0 || (data_size & 7) != 0 || (int32_t)data_size <= 0) return false;
        // cmd 0xE has two variants, chosen by the word at DMEM 0x400 (the ADPCM table's
        // start), and one works in place on any buffer, so it needs whole vectors. Follow
        // what the list leaves at 0x400 to know which one can run.
        enum { zero, nonzero, unknown } table = W(0x400) == 0 ? zero : nonzero;
        for (uint32_t i = 0; i < data_size; i += 8) {
            const uint32_t w0 = rdram_word(rdram, data_ptr + i);
            const uint32_t w1 = rdram_word(rdram, data_ptr + i + 4);
            uint32_t wr_addr = 0, wr_len = 0;  // what the command writes in DMEM, for the table word
            switch ((w0 >> 24) & 0x7F) {
                case 0x0:  // in-place gain: whole vectors
                    if (((w0 + 0x500) & 15) != 0) return unsupported(i);
                    wr_addr = w0 + 0x500;
                    wr_len = nbytes;
                    break;
                case 0x1: {  // ADPCM: whole vectors out (and its state's DMA not to IMEM)
                    if ((((w1 & 0xFFF) + 0x500) & 0x100F) != 0) return unsupported(i);
                    wr_addr = (w1 & 0xFFF) + 0x500;
                    wr_len = 0x20 + ((((w1 >> 16) & 0xFFF) + 0x1F) & ~0x1Fu);
                    break;
                }
                case 0x2:
                    wr_addr = w0 + 0x500;
                    wr_len = 16 * ((w1 & 0xFFFF) > 16 ? ((w1 & 0xFFFF) + 15) / 16 : 1);
                    break;
                case 0x4:  // a DMA to IMEM would swap overlays
                    if (((w0 >> 12) & 0xFFF) != 0 && ((w0 + 0x500) & 0x1000) != 0) return unsupported(i);
                    wr_addr = w0 + 0x500;
                    wr_len = (w0 >> 12) & 0xFFF;
                    break;
                case 0x6:
                    if (((w0 >> 12) & 0xFFF) != 0 && ((w0 + 0x500) & 0x1000) != 0) return unsupported(i);
                    break;
                case 0x5:  // resample: halfword input
                    if (((w1 >> 2) & 1) != 0) return unsupported(i);
                    wr_addr = (w1 >> 2) + 0x4F8;
                    wr_len = 8;
                    break;
                case 0x7:  // MP3 leaves its own tables in DMEM
                    table = unknown;
                    break;
                case 0xA:
                    wr_addr = (w1 >> 16) + 0x500;
                    wr_len = 16 * ((w1 & 0xFFFF) > 16 ? ((w1 & 0xFFFF) + 15) / 16 : 1);
                    break;
                case 0xB: {
                    const uint32_t len = w0 & 0xFFFF;
                    if (len > 0x400) return unsupported(i);
                    if (len >= 4) table = rdram_word(rdram, w1 & 0xFFFFF8) == 0 ? zero : nonzero;
                    else if (len > 0) table = unknown;
                    if (len > 4) {
                        wr_addr = 0x404;  // past the word just followed
                        wr_len = len - 4;
                    }
                    break;
                }
                case 0xC:  // mixer: whole vectors
                    if (((w1 + 0x500) & 15) != 0 || (((w1 >> 16) + 0x500) & 15) != 0) return unsupported(i);
                    wr_addr = w1 + 0x500;
                    wr_len = nbytes;
                    break;
                case 0xE:  // the variant for a nonzero table word works in place at w0 + 0x500
                    if (table != zero && ((w0 + 0x500) & 15) != 0) return unsupported(i);
                    if (table != zero) {
                        wr_addr = w0 + 0x500 - 16;
                        wr_len = nbytes + 16;
                    }
                    break;
                case 0x3: case 0x8: case 0x9: case 0xD: case 0xF:
                    break;
                default:  // beyond the dispatch table
                    return unsupported(i);
            }
            if (wr_len) {
                // The HLE has the microcode's tables and dispatch (DMEM below 0x2C0) and
                // the task's words it keeps (0xFF0..) as they are: a list that writes them
                // runs on the microcode.
                if (overlaps(wr_addr & 0xFFF, wr_len, 0, 0x2C0) || overlaps(wr_addr & 0xFFF, wr_len, 0xFF0, 0x10)) return unsupported(i);
                if (overlaps(wr_addr & 0xFFF, wr_len, 0x400, 4)) table = unknown;
            }
        }
        return true;
    }

    const Stats& stats() { return hle_stats; }
    void reset_stats() { hle_stats = Stats{}; }
}

RspExitReason conker_audio_hle_check(uint8_t* rdram, uint32_t ucode_addr) {
    // Tasks with MP3 write RDRAM from the microcode's overlay too: not logged, so not checked.
    bool mp3 = false;
    const uint32_t data_ptr = W(0xFF0), data_size = W(0xFF4);
    for (uint32_t i = 0; i < data_size && i < 0x10000; i += 8) {
        if (((rdram_word(rdram, data_ptr + i) >> 24) & 0x7F) == 0x7) mp3 = true;
    }
    if (mp3 || !conker::audio_hle::task_supported(rdram)) return conker_audio_ucode(rdram, ucode_addr);

    static uint8_t dmem_before[0x1000], dmem_hle[0x1000];
    std::memcpy(dmem_before, dmem, 0x1000);
    undo_log.clear();
    undo_bytes.clear();
    logging = true;
    const RspExitReason r_hle = conker_audio_hle(rdram, ucode_addr);
    logging = false;
    std::memcpy(dmem_hle, dmem, 0x1000);
    // What the HLE wrote, then RDRAM back as it was.
    std::vector<uint8_t> written;
    for (const Undo& u : undo_log) written.insert(written.end(), rdram + u.addr, rdram + u.addr + u.size);
    for (size_t i = undo_log.size(); i-- > 0;) {
        const Undo& u = undo_log[i];
        std::memcpy(rdram + u.addr, undo_bytes.data() + u.offset, u.size);
    }
    std::memcpy(dmem, dmem_before, 0x1000);
    const RspExitReason r = conker_audio_ucode(rdram, ucode_addr);

    bool same = r == r_hle && std::memcmp(dmem, dmem_hle, 0x1000) == 0;
    uint32_t bad_addr = 0;
    size_t off = 0;
    for (const Undo& u : undo_log) {
        if (same && std::memcmp(rdram + u.addr, written.data() + off, u.size) != 0) {
            same = false;
            bad_addr = u.addr;
        }
        off += u.size;
    }
    hle_stats.checked++;
    if (!same) {
        hle_stats.check_mismatches++;
        if (hle_stats.check_mismatches <= 20) {
            std::fprintf(stderr, "[audio hle] check: task %u differs from the microcode (RDRAM 0x%06X)\n",
                         hle_stats.checked - 1, bad_addr);
        }
    }
    if (hle_stats.checked % 1000 == 0) {
        std::fprintf(stderr, "[audio hle] check: %u tasks, %u differ\n", hle_stats.checked, hle_stats.check_mismatches);
    }
    return r;
}

RspExitReason conker_audio_hle(uint8_t* rdram, uint32_t ucode_addr) {
    if (!conker::audio_hle::task_supported(rdram)) {
        hle_stats.fallbacks++;
        return conker_audio_ucode(rdram, ucode_addr);
    }
    hle_stats.tasks++;

    // The microcode's entry: overlay addresses made absolute, ucode_data kept at 0xFF8.
    Task t{};
    t.rdram = rdram;
    t.gp = W(0xFF0);
    t.k1 = (int32_t)W(0xFF4);
    const uint32_t ucode = W(0xFD0);
    W(0x0) = W(0x0) + ucode;
    W(0x8) = W(0x8) + ucode;
    W(0xFF8) = W(0xFD8);
    load_list(t);

    for (;;) {
        const uint32_t w0 = W(t.sp), w1 = W(t.sp + 4);
        t.gp += 8;
        t.k1 -= 8;
        const uint32_t cmd = (w0 >> 24) & 0x7F;
        hle_stats.commands[cmd & 0xF]++;
#ifdef AUDIO_HLE_PROFILE
        const auto prof_start = std::chrono::steady_clock::now();
#endif
        switch (cmd) {
            case 0x0: cmd_gain(w0, w1); t.fp -= 8; break;
            case 0x1: cmd_adpcm(t, w0, w1); break;
            case 0x2: cmd_clearbuff(w0, w1); break;
            case 0x3: cmd_envmixer(t, w0, w1); break;
            case 0x4: cmd_loadbuff(t, w0, w1); break;
            case 0x5: cmd_resample(t, w0, w1); break;
            case 0x6: cmd_savebuff(t, w0, w1); break;
            case 0x7: {
                hle_stats.mp3_commands++;
                const RspExitReason r = cmd_mp3(t, w0, w1);
                if (r != RspExitReason::Invalid) return r;
                break;
            }
            case 0x8: W(0xFF4) = w1 & 0xFFFFFF; break;  // MP3ADDY
            case 0x9: cmd_setvol(w0, w1); break;
            case 0xA: cmd_dmemmove(w0, w1); break;
            case 0xB: dma_rdram_to_dmem(rdram, 0x400, w1 & 0xFFFFFF, (w0 & 0xFFFF) - 1); break;  // LOADADPCM
            case 0xC: cmd_mixer(t, w0, w1); break;
            case 0xD: cmd_interleave(); break;
            case 0xE:
                if (W(0x400) == 0) cmd_filter(t, w0, w1);
                else cmd_biquad(t, w0, w1);
                break;
            case 0xF: W(0xFFC) = w1 & 0xFFFFFF; break;  // SETLOOP
            default:  // task_supported() keeps these out
                return RspExitReason::Unsupported;
        }
#ifdef AUDIO_HLE_PROFILE
        hle_stats.command_ns[cmd & 0xF] += (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - prof_start).count();
#endif
        // next_cmd
        t.fp -= 8;
        if (t.fp > 0) {
            t.sp += 8;
            continue;
        }
        if (t.k1 <= 0) break;
        load_list(t);
    }
    return RspExitReason::Broke;
}
