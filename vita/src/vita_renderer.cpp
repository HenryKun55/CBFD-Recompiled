// The Vita renderer: high-level emulation of Conker's graphics microcode (F3DEX2 with
// Conker's changes, as RT64's and GLideN64's F3DEX2CBFD) and of the RDP, drawn with
// vitaGL.
//
// The RSP part runs on the CPU: vertices are transformed, lit (Conker's own point
// lighting) and clipped there, and triangles go to the GPU in clip space, so the GPU
// does the clipping and perspective. The RDP part maps the colour combiner to
// generated GLSL shaders, the blender to GL blending, and TMEM to decoded textures,
// cached by content.
//
// Each colour image the game draws into gets an offscreen framebuffer at a multiple
// of the N64's resolution; the one the VI shows is drawn to the screen, 4:3 in the
// middle of the Vita's 960x544. Frames the CPU wrote (nothing drawn into them) are
// shown from RDRAM.
//
// The desktop build's hooks put RT64's extended GBI into the display lists
// (host/src/widescreen.cpp, interpolation.cpp): its rectangles are drawn, the rest
// (matrix groups, rect aspect) is skipped.

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#if defined(__ARM_NEON)
#include <arm_neon.h>
#endif
#include <psp2/kernel/cpu.h>
#include <psp2/kernel/sysmem.h>
#include <psp2/kernel/threadmgr.h>
#include <vitashark.h>
#include <cstddef>
#include <psp2/display.h>
#include <psp2/gxm.h>
#include <psp2/kernel/clib.h>
#include <psp2/kernel/sysmem.h>

#include "gl_enums.h"

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/renderer_context.hpp"

#include <filesystem>

#define XXH_INLINE_ALL
#include "xxHash/xxhash.h"

#include "n64_gfx.hpp"
#include "vita_platform.hpp"
#include "vita_renderer.hpp"
#include "bench.hpp"
#include "menu.hpp"
#include "font_atlas.h"
#include "conker.hpp"
#include <psp2/kernel/processmgr.h>

using namespace n64gfx;

void ultramodern_trace(const char* what, uint32_t arg);
extern "C" volatile bool ultramodern_vita_sync_dl;
extern "C" void conker_vita_register_thread(const char* name);

// ---------------------------------------------------------------- list capture
// The game rewrites the next frame's vertices, matrices and lights as soon as it submitted a
// frame (they're single-buffered: the N64's RSP has read them by then, in a few ms). Reading the
// list on the game's thread was correct but cost the game the whole read (15-35 ms a frame).
// Instead, as the game submits it, a quick walk of the list finds the 4 KB pages it reads them
// from (the list itself, vertices, matrices, the movemem data), copies those, and the renderer
// then reads the list on its own core from that copy (textures and images from RDRAM itself).
namespace capture {
    constexpr uint32_t page_shift = 12, pages = (16u << 20) >> page_shift, pool_pages = 1024;
    struct Slot {
        std::vector<uint8_t> pool;            // the copied pages
        const uint8_t* pt[pages] = {};        // page -> copy, biased so that pt[p] + addr reads it
        std::vector<uint16_t> used;
        uint64_t bits[pages / 64] = {};
        bool reads_back = false; // draws into the depth buffer's memory (read back for the CPU)
    };
    Slot slots[2];
    std::atomic<uint32_t> busy{0}; // bit per slot
    SceUID free_sema = -1;
    uint32_t segments[16] = {};     // the walk's own (they change as the lists do)
    uint32_t segments_version = 0;  // bumped when one changes
    uint32_t walked = 0, dl_calls = 0, branches = 0, seg_changes = 0; // debug: the last walk's
    // The sublists and branch targets already walked with the segments as they were (walking a
    // list both ways at each conditional branch went over the same ones thousands of times: up to
    // 170 ms a frame on the Vita as the chainsaw cuts the N64 logo).
    constexpr uint32_t visited_size = 4096;
    uint64_t visited[visited_size];
    uint32_t visited_count = 0;
    bool first_visit(uint32_t pc) {
        const uint64_t key = ((uint64_t)segments_version << 32) | pc | 1ull << 63;
        uint32_t i = (uint32_t)((key * 0x9E3779B97F4A7C15ull) >> 52) & (visited_size - 1);
        for (uint32_t n = 0; n < visited_size; n++, i = (i + 1) & (visited_size - 1)) {
            if (visited[i] == key) return false;
            if (visited[i] == 0) {
                if (visited_count >= visited_size * 3 / 4) return true; // full: walk it again
                visited[i] = key;
                visited_count++;
                return true;
            }
        }
        return true;
    }
    std::atomic<uint64_t> copy_us{0}, wait_us{0}, copied_pages{0};

    inline void mark(Slot& s, uint32_t addr, uint32_t bytes) {
        addr &= 0x00FFFFFF;
        const uint32_t last = std::min<uint32_t>(addr + (bytes ? bytes - 1 : 0), 0x00FFFFFF) >> page_shift;
        for (uint32_t p = addr >> page_shift; p <= last; p++) {
            uint64_t& w = s.bits[p >> 6];
            const uint64_t b = 1ull << (p & 63);
            if (!(w & b)) { w |= b; s.used.push_back((uint16_t)p); }
        }
    }
    inline uint32_t seg(uint32_t addr) {
        return (segments[(addr >> 24) & 0xF] + (addr & 0x00FFFFFF)) & 0x00FFFFFF;
    }

    // The pages a list reads, following it as the renderer will (both ways at a conditional).
    void walk(const uint8_t* rdram, Slot& s, uint32_t start) {
        uint32_t stack[64];
        int depth = 0;
        uint32_t pc = start & 0x00FFFFFF;
        uint32_t half1 = 0;
        uint32_t cimg = ~0u, zimg = ~1u;
        bool cimg_16b = false;
        for (uint32_t guard = 0; guard < 2000000; guard++) {
            walked++;
            mark(s, pc, 8);
            const uint32_t w0 = n64gfx::read32(rdram, pc), w1 = n64gfx::read32(rdram, pc + 4);
            pc += 8;
            switch (w0 >> 24) {
                case 0x01: mark(s, seg(w1), ((w0 >> 12) & 0xFF) * 16); break;                 // G_VTX
                case 0xDA: mark(s, seg(w1), 64); break;                                        // G_MTX
                case 0xDC: mark(s, seg(w1), 256); break;                                       // G_MOVEMEM
                case 0xDB:                                                                     // G_MOVEWORD
                    if (((w0 >> 16) & 0xFF) == 0x06) {
                        segments[((w0 & 0xFFFF) / 4) & 0xF] = w1 & 0x00FFFFFF;
                        segments_version++;
                        seg_changes++;
                    }
                    break;
                case 0xE1: half1 = w1; break;                                                  // G_RDPHALF_1
                // Drawing (not filling: every frame clears its depth buffer so, the color image
                // set to its memory) into the depth buffer's memory: the CPU reads that back.
                case 0xFF:                                                                     // G_SETCIMG
                    cimg = seg(w1);
                    cimg_16b = ((w0 >> 19) & 3) == 2;
                    break;
                case 0xFE:                                                                     // G_SETZIMG
                    zimg = seg(w1);
                    break;
                case 0x05: case 0x06: case 0x07:                                               // triangles
                case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17:
                case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0x1F:
                    if (cimg == zimg && cimg_16b) s.reads_back = true;
                    break;
                case 0x04: {                                                                   // G_BRANCH_Z: both ways
                    const uint32_t target = seg(half1) & 0x00FFFFFF;
                    branches++;
                    if (depth < 64 && first_visit(target)) { stack[depth++] = pc; pc = target; }
                    break;
                }
                case 0xDE: {                                                                   // G_DL
                    const uint32_t target = seg(w1) & 0x00FFFFFF;
                    const bool call = ((w0 >> 16) & 0xFF) == 0;
                    dl_calls++;
                    if (!first_visit(target)) {
                        // Walked already with these segments: a call is done; a branch ends this list.
                        if (call) break;
                        if (depth == 0) return;
                        pc = stack[--depth];
                        break;
                    }
                    if (call) {
                        if (depth >= 64) return;
                        stack[depth++] = pc;
                    }
                    pc = target;
                    break;
                }
                case 0xDF:                                                                     // G_ENDDL
                    if (depth == 0) return;
                    pc = stack[--depth];
                    break;
                case 0xE4: case 0xE5:                                                          // G_TEXRECT(FLIP)
                    if (cimg == zimg && cimg_16b) s.reads_back = true;
                    mark(s, pc, 16); pc += 16;
                    break;
                case 0x64:                                                                     // RT64's extended
                    switch (w0 & 0x00FFFFFF) {
                        case 0x000002:                                                         // G_EX_TEXRECT_V1
                            if (cimg == zimg && cimg_16b) s.reads_back = true;
                            mark(s, pc, 16); pc += 16;
                            break;
                        case 0x000003: mark(s, pc, 8); pc += 8; break;                         // G_EX_FILLRECT_V1
                        case 0x00000C: pc += 8; break;                                         // G_EX_MATRIXGROUP_V1
                        default: break;
                    }
                    break;
                default: break;
            }
        }
    }
}

extern "C" int ultramodern_vita_capture(uint8_t* rdram, const OSTask* task) {
    using namespace capture;
    const uint64_t t0 = sceKernelGetProcessTimeWide();
    if (free_sema < 0) free_sema = sceKernelCreateSema("list_capture", 0, 2, 2, nullptr);
    sceKernelWaitSema(free_sema, 1, nullptr);
    const uint64_t t1 = sceKernelGetProcessTimeWide();
    int index = (busy.load() & 1) ? 1 : 0;
    busy |= 1u << index;
    Slot& s = slots[index];
    if (s.pool.empty()) s.pool.resize((size_t)pool_pages << page_shift);
    std::memset(visited, 0, sizeof(visited));
    visited_count = 0;
    walked = dl_calls = branches = seg_changes = 0;
    s.reads_back = false;
    const uint64_t tw = sceKernelGetProcessTimeWide();
    walk(rdram, s, (uint32_t)task->t.data_ptr);
    const uint64_t tw2 = sceKernelGetProcessTimeWide();
    if (tw2 - tw > 5000) {
        std::fprintf(stderr, "[capture] slow walk: %llu us, %u commands, %u calls, %u branches, %u segment changes, %u pages\n",
            (unsigned long long)(tw2 - tw), walked, dl_calls, branches, seg_changes, (unsigned)s.used.size());
    }
    uint32_t n = 0;
    for (uint16_t p : s.used) {
        if (n >= pool_pages) break; // past the pool: read from RDRAM itself
        uint8_t* dst = s.pool.data() + ((size_t)n << page_shift);
        std::memcpy(dst, rdram + ((size_t)p << page_shift), 1u << page_shift);
        s.pt[p] = dst - ((size_t)p << page_shift);
        n++;
    }
    const uint64_t t2 = sceKernelGetProcessTimeWide();
    wait_us += t1 - t0;
    copy_us += t2 - t1;
    copied_pages += n;
    return index;
}

// Whether the game can be told the RDP is done as soon as its list was captured (it reads the
// copy; see the gfx thread in ultramodern's events.cpp), not once the list was read: not when the
// list draws into the depth buffer's memory, which the CPU reads back after it (the pause menu's
// blur), nor with debug flag 4194304.
extern "C" volatile bool ultramodern_vita_late_dp = false;
extern "C" int ultramodern_vita_capture_early_dp(int index) {
    if (index < 0 || ultramodern_vita_late_dp) return 0;
    return capture::slots[index].reads_back ? 0 : 1;
}

extern "C" void ultramodern_vita_release_capture(int index) {
    using namespace capture;
    if (index < 0) return;
    Slot& s = slots[index];
    for (uint16_t p : s.used) s.pt[p] = nullptr;
    for (uint64_t& w : s.bits) w = 0;
    s.used.clear();
    busy &= ~(1u << index);
    sceKernelSignalSema(free_sema, 1);
}

// The capture the list being read uses (set by the gfx thread around send_dl).
extern "C" { volatile int ultramodern_vita_current_capture = -1; }

// Where the renderer's threads are (conker::vita::renderer_status): the front's stage (0 idle,
// 1 reading a list, 2 showing a frame, 3 waiting to hand a list over), the back's operation
// (its Op, 99 none), whether it compiles a shader or waits for the display, and lists done.
static std::atomic<uint64_t> g_back_busy_total_us{0};
static std::atomic<uint32_t> g_front_stage{0}, g_back_op{99}, g_back_compiling{0}, g_back_waiting{0}, g_back_lists{0}, g_front_lists{0};

namespace {
    // ============================================================ settings
    constexpr int screen_width = 960;
    constexpr int screen_height = 544;
    // The offscreen framebuffers' scale over the N64's resolution (320x240 -> 640x480).
    constexpr int render_scale = 2;

    // ============================================================ math
    struct Mat4 {
        float m[4][4];
    };

    Mat4 identity() {
        Mat4 r{};
        for (int i = 0; i < 4; i++) r.m[i][i] = 1.0f;
        return r;
    }

    // Row vectors, as the N64: v' = v * M; mul(a, b) applies a then b.
    Mat4 mul(const Mat4& a, const Mat4& b) {
        Mat4 r;
#if defined(__ARM_NEON)
        // A row of the result: a's row's elements times b's rows, four at a time.
        const float32x4_t b0 = vld1q_f32(b.m[0]), b1 = vld1q_f32(b.m[1]), b2 = vld1q_f32(b.m[2]), b3 = vld1q_f32(b.m[3]);
        for (int i = 0; i < 4; i++) {
            float32x4_t row = vmulq_n_f32(b0, a.m[i][0]);
            row = vmlaq_n_f32(row, b1, a.m[i][1]);
            row = vmlaq_n_f32(row, b2, a.m[i][2]);
            row = vmlaq_n_f32(row, b3, a.m[i][3]);
            vst1q_f32(r.m[i], row);
        }
#else
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                r.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] + a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j];
            }
        }
#endif
        return r;
    }

    // ============================================================ GBI
    enum : uint8_t {
        G_VTX = 0x01, G_MODIFYVTX = 0x02, G_CULLDL = 0x03, G_BRANCH_Z = 0x04,
        G_TRI1 = 0x05, G_TRI2 = 0x06, G_QUAD = 0x07,
        G_TRI4_FIRST = 0x10, G_TRI4_LAST = 0x1F, // Conker's
        G_RT64_EXTENDED = 0x64,
        G_TEXTURE = 0xD7, G_POPMTX = 0xD8, G_GEOMETRYMODE = 0xD9, G_MTX = 0xDA,
        G_MOVEWORD = 0xDB, G_MOVEMEM = 0xDC, G_LOAD_UCODE = 0xDD, G_DL = 0xDE, G_ENDDL = 0xDF,
        G_SPNOOP = 0xE0, G_RDPHALF_1 = 0xE1, G_SETOTHERMODE_L = 0xE2, G_SETOTHERMODE_H = 0xE3,
        G_TEXRECT = 0xE4, G_TEXRECTFLIP = 0xE5,
        G_SETSCISSOR = 0xED, G_SETPRIMDEPTH = 0xEE, G_RDPSETOTHERMODE = 0xEF,
        G_LOADTLUT = 0xF0, G_RDPHALF_2 = 0xF1, G_SETTILESIZE = 0xF2, G_LOADBLOCK = 0xF3,
        G_LOADTILE = 0xF4, G_SETTILE = 0xF5, G_FILLRECT = 0xF6, G_SETFILLCOLOR = 0xF7,
        G_SETFOGCOLOR = 0xF8, G_SETBLENDCOLOR = 0xF9, G_SETPRIMCOLOR = 0xFA, G_SETENVCOLOR = 0xFB,
        G_SETCOMBINE = 0xFC, G_SETTIMG = 0xFD, G_SETZIMG = 0xFE, G_SETCIMG = 0xFF,
    };

    // Geometry mode (F3DEX2).
    constexpr uint32_t G_ZBUFFER = 0x00000001;
    constexpr uint32_t G_CULL_FRONT = 0x00000200;
    constexpr uint32_t G_CULL_BACK = 0x00000400;
    constexpr uint32_t G_FOG = 0x00010000;
    constexpr uint32_t G_LIGHTING = 0x00020000;
    constexpr uint32_t G_TEXTURE_GEN = 0x00040000;
    constexpr uint32_t G_TEXTURE_GEN_LINEAR = 0x00080000;
    constexpr uint32_t G_SHADING_SMOOTH = 0x00200000;
    constexpr uint32_t G_POINT_LIGHTING = 0x00400000;

    // Move word indices.
    constexpr uint32_t G_MW_NUMLIGHT = 0x02;
    constexpr uint32_t G_MW_SEGMENT = 0x06;
    constexpr uint32_t G_MW_FOG = 0x08;
    constexpr uint32_t G_MW_COORD_MOD_CBFD = 0x10;
    // Move mem indices.
    constexpr uint32_t G_MV_VIEWPORT = 8;
    constexpr uint32_t G_MV_LIGHT = 10;
    constexpr uint32_t G_MV_NORMALES_CBFD = 14;

    // RT64's extended GBI (tools/rt64/include/rt64_extended_gbi.h).
    constexpr uint32_t G_EX_TEXRECT_V1 = 0x02;
    constexpr uint32_t G_EX_FILLRECT_V1 = 0x03;
    constexpr uint32_t G_EX_MATRIXGROUP_V1 = 0x0C;

    constexpr int max_vertices = 64;
    constexpr int max_dl_depth = 32;
    constexpr int max_matrix_depth = 32;

    // ============================================================ RSP state
    // 1 when a float is negative (its sign bit), without a comparison: on the Vita's
    // Cortex-A9 a float compare stalls on moving the VFP flags.
    inline uint32_t negative(float f) {
        uint32_t u;
        std::memcpy(&u, &f, 4);
        return u >> 31;
    }

    struct RspVertex {
        float x, y, z, w;   // clip space, already mapped through the viewport into the framebuffer's
        float ndc_x, ndc_y; // the N64's x/w and y/w, for culling
        float s, t;         // texture coordinates, in texels
        uint8_t r, g, b, a;
        uint8_t clip;       // outcodes
    };

    struct CbfdLight {
        float r = 0, g = 0, b = 0;
        float dir[3] = {};
        float pos[3] = {};
        float ca = 0;
    };

    // ============================================================ GL
    struct GLVertex {
        float x, y, z, w;
        uint8_t color[4];
        float u0, v0, u1, v1;
    };

    struct Framebuffer {
        uint32_t addr = 0;
        uint32_t width = 0, height = 0, siz = SIZ_16b;
        uint32_t fbo = 0, tex = 0; // the GL thread's ids
        // Widescreen: a screen's GL image is wider than the N64's (gl_width, in N64
        // pixels), the N64's 4:3 in its middle (from x = off).
        uint32_t gl_width = 0;
        float off = 0;
        // A copy of the image for loads from it while it's drawn into (GL can't sample
        // the target it draws to): made at the load, as TMEM holds a copy too.
        uint32_t snapshot_fbo = 0, snapshot_tex = 0;
        uint32_t last_drawn = 0; // present counter when last drawn into
        uint32_t last_used = 0;  // ... when last read as a texture or shown
        uint32_t water_draws = 0; // debug (flag 4096): the water's draws since its last clear
        // A sample of the RDRAM under the image when the GPU last drew it: while it's the
        // same, the CPU hasn't written there and the GPU's picture is the image.
        uint32_t rdram_sig = 0;
        uint32_t rows_drawn = 0; // the lowest row the GPU drew (its height may be a guess)
        bool sig_pending = false;
        bool gpu_valid = false;
        bool drawn_this_dl = false;
        // The area the game drew in since the last present (its scissors), in N64 pixels;
        // outside it the image keeps whatever was there.
        float drawn_x0 = 1e9f, drawn_y0 = 1e9f, drawn_x1 = 0, drawn_y1 = 0;
        float shown_x0 = 0, shown_y0 = 0, shown_x1 = 0, shown_y1 = 0;
        // Frame interpolation: the frame the game drew, copied aside (tex then holds the frame
        // drawn between it and the one before), shown a VI after that one.
        uint32_t real_fbo = 0, real_tex = 0;
        bool interp_ready = false; // tex holds an in-between frame not shown yet
        bool showing_real = false; // shown: real_tex
        bool list_presented = false; // its frames were presented by its list, not at the VI
    };

    struct Program {
        uint32_t id = 0; // the GL thread's
        bool uses_t0 = false, uses_t1 = false;
    };

    struct ShaderKey {
        uint32_t cc0, cc1, other;
        bool operator==(const ShaderKey& o) const { return cc0 == o.cc0 && cc1 == o.cc1 && other == o.other; }
    };
    struct ShaderKeyHash {
        size_t operator()(const ShaderKey& k) const {
            return (size_t)(k.cc0 * 0x9E3779B1u) ^ (size_t)(k.cc1 * 0x85EBCA77u) ^ (size_t)(k.other * 0xC2B2AE3Du);
        }
    };

    struct CachedTexture {
        uint32_t tex = 0;
        uint32_t last_used = 0;
        uint32_t bytes = 0; // in video memory
    };

    // The decoded textures by their key: open addressing over a power of two, as an
    // unordered_map's lookup divides by a prime (slow without a divide instruction).
    class TextureCache {
    public:
        TextureCache() { slots.resize(4096); }

        CachedTexture* find(uint64_t key) {
            for (size_t i = index(key);; i = (i + 1) & (slots.size() - 1)) {
                Slot& slot = slots[i];
                if (!slot.used) return nullptr;
                if (slot.key == key) return &slot.value;
            }
        }

        void insert(uint64_t key, const CachedTexture& value) {
            if ((count + 1) * 2 > slots.size()) rebuild(slots.size() * 2, [](const CachedTexture&) { return true; });
            put(key, value);
        }

        size_t size() const { return count; }

        // Keeps the entries keep() wants (rebuilding the table without the others).
        template<typename F> void filter(F keep) { rebuild(slots.size(), keep); }

    private:
        struct Slot {
            uint64_t key = 0;
            CachedTexture value{};
            bool used = false;
        };
        std::vector<Slot> slots;
        size_t count = 0;

        size_t index(uint64_t key) const {
            return (size_t)((key * 0x9E3779B97F4A7C15ull) >> 40) & (slots.size() - 1);
        }
        void put(uint64_t key, const CachedTexture& value) {
            for (size_t i = index(key);; i = (i + 1) & (slots.size() - 1)) {
                Slot& slot = slots[i];
                if (!slot.used) {
                    slot = { key, value, true };
                    count++;
                    return;
                }
                if (slot.key == key) {
                    slot.value = value;
                    return;
                }
            }
        }
        template<typename F> void rebuild(size_t capacity, F keep) {
            std::vector<Slot> old(capacity);
            old.swap(slots);
            count = 0;
            for (const Slot& slot : old) {
                if (slot.used && keep(slot.value)) put(slot.key, slot.value);
            }
        }
    };

    // A tile's texture as bound for drawing.
    struct TileTexture {
        uint32_t tex = 0;
        float width = 1, height = 1;
        float inv_width = 1, inv_height = 1;
        float shift_s = 1, shift_t = 1;
        float uls = 0, ult = 0;
        float offset = 0; // half a texel when filtered
        bool intensity = false; // a framebuffer of 8 bits: its red channel is the texel
        bool wide_fb = false;   // a widened framebuffer (its sides are texels too)
        // What it was made from, to skip the lookup while nothing changed.
        uint32_t generation = ~0u;
        Tile tile{};
        uint32_t tlut = 0, filter = 0;
    };

    // Everything a batch of triangles shares.
    struct DrawState {
        Framebuffer* fb = nullptr;
        Program* program = nullptr;
        uint32_t tex[2] = {0, 0};
        float tex_intensity[2] = {0, 0};
        bool blend = false;
        GLenum blend_src = GL_ONE, blend_dst = GL_ZERO;
        bool color_write = true;
        bool depth_test = false, depth_write = false, decal = false;
        GLenum depth_func = GL_LEQUAL;
        int scissor[4] = {0, 0, 0, 0};
        float prim[4] = {}, env[4] = {}, fog[4] = {}, blendc[4] = {}, fill[4] = {};
        float primlod = 0;
        float convert[2] = {0, 0}; // K4, K5
        // Debugging only (not compared: they're implied by the program and textures).
        uint32_t dbg_cc0 = 0, dbg_cc1 = 0, dbg_omh = 0, dbg_oml = 0, dbg_geo = 0, dbg_tile = 0;
        Tile dbg_t0{};

        bool operator==(const DrawState& o) const {
            return fb == o.fb && program == o.program && tex[0] == o.tex[0] && tex[1] == o.tex[1] &&
                tex_intensity[0] == o.tex_intensity[0] && tex_intensity[1] == o.tex_intensity[1] &&
                blend == o.blend && blend_src == o.blend_src && blend_dst == o.blend_dst &&
                color_write == o.color_write && depth_test == o.depth_test && depth_write == o.depth_write &&
                decal == o.decal && depth_func == o.depth_func &&
                std::memcmp(scissor, o.scissor, sizeof(scissor)) == 0 &&
                std::memcmp(prim, o.prim, sizeof(prim)) == 0 && std::memcmp(env, o.env, sizeof(env)) == 0 &&
                std::memcmp(fog, o.fog, sizeof(fog)) == 0 && std::memcmp(blendc, o.blendc, sizeof(blendc)) == 0 &&
                std::memcmp(fill, o.fill, sizeof(fill)) == 0 && primlod == o.primlod &&
                convert[0] == o.convert[0] && convert[1] == o.convert[1];
        }
    };

    void color_from_word(uint32_t c, float out[4]) {
        out[0] = (float)((c >> 24) & 0xFF) / 255.0f;
        out[1] = (float)((c >> 16) & 0xFF) / 255.0f;
        out[2] = (float)((c >> 8) & 0xFF) / 255.0f;
        out[3] = (float)(c & 0xFF) / 255.0f;
    }

    // ============================================================ combiner -> GLSL
    // Cycle 1 of a 2-cycle mode reads the texels the other way round: its TEXEL0 is
    // the second tile's, as the RDP pipelines them.
    std::string cc_rgb_a(uint32_t v, bool swap) {
        switch (v) {
            case 0: return "comb.rgb";
            case 1: return swap ? "t1.rgb" : "t0.rgb";
            case 2: return swap ? "t0.rgb" : "t1.rgb";
            case 3: return "uPrim.rgb";
            case 4: return "shade.rgb";
            case 5: return "uEnv.rgb";
            case 6: return "vec3(1.0)";
            case 7: return "vec3(noise)";
            default: return "vec3(0.0)";
        }
    }
    std::string cc_rgb_b(uint32_t v, bool swap) {
        switch (v) {
            case 0: return "comb.rgb";
            case 1: return swap ? "t1.rgb" : "t0.rgb";
            case 2: return swap ? "t0.rgb" : "t1.rgb";
            case 3: return "uPrim.rgb";
            case 4: return "shade.rgb";
            case 5: return "uEnv.rgb";
            case 7: return "vec3(uConvert.x)"; // K4
            default: return "vec3(0.0)"; // key centre
        }
    }
    std::string cc_rgb_c(uint32_t v, bool swap) {
        switch (v) {
            case 0: return "comb.rgb";
            case 1: return swap ? "t1.rgb" : "t0.rgb";
            case 2: return swap ? "t0.rgb" : "t1.rgb";
            case 3: return "uPrim.rgb";
            case 4: return "shade.rgb";
            case 5: return "uEnv.rgb";
            case 7: return "vec3(comb.a)";
            case 8: return swap ? "vec3(t1.a)" : "vec3(t0.a)";
            case 9: return swap ? "vec3(t0.a)" : "vec3(t1.a)";
            case 10: return "vec3(uPrim.a)";
            case 11: return "vec3(shade.a)";
            case 12: return "vec3(uEnv.a)";
            case 13: return "vec3(lodfrac)";
            case 14: return "vec3(uPrimLod)";
            case 15: return "vec3(uConvert.y)"; // K5
            default: return "vec3(0.0)"; // key scale
        }
    }
    std::string cc_rgb_d(uint32_t v, bool swap) {
        switch (v) {
            case 0: return "comb.rgb";
            case 1: return swap ? "t1.rgb" : "t0.rgb";
            case 2: return swap ? "t0.rgb" : "t1.rgb";
            case 3: return "uPrim.rgb";
            case 4: return "shade.rgb";
            case 5: return "uEnv.rgb";
            case 6: return "vec3(1.0)";
            default: return "vec3(0.0)";
        }
    }
    std::string cc_alpha_abd(uint32_t v, bool swap) {
        switch (v) {
            case 0: return "comb.a";
            case 1: return swap ? "t1.a" : "t0.a";
            case 2: return swap ? "t0.a" : "t1.a";
            case 3: return "uPrim.a";
            case 4: return "shade.a";
            case 5: return "uEnv.a";
            case 6: return "1.0";
            default: return "0.0";
        }
    }
    std::string cc_alpha_c(uint32_t v, bool swap) {
        switch (v) {
            case 0: return "lodfrac";
            case 1: return swap ? "t1.a" : "t0.a";
            case 2: return swap ? "t0.a" : "t1.a";
            case 3: return "uPrim.a";
            case 4: return "shade.a";
            case 5: return "uEnv.a";
            case 6: return "uPrimLod";
            default: return "0.0";
        }
    }

    struct CombinerCycle {
        uint32_t a, b, c, d;     // RGB
        uint32_t aa, ab, ac, ad; // alpha
    };

    // gDPSetCombine's fields for both cycles.
    void decode_combine(uint32_t w0, uint32_t w1, CombinerCycle cycles[2]) {
        cycles[0].a = (w0 >> 20) & 0xF;
        cycles[0].c = (w0 >> 15) & 0x1F;
        cycles[0].aa = (w0 >> 12) & 0x7;
        cycles[0].ac = (w0 >> 9) & 0x7;
        cycles[1].a = (w0 >> 5) & 0xF;
        cycles[1].c = (w0 >> 0) & 0x1F;
        cycles[0].b = (w1 >> 28) & 0xF;
        cycles[1].b = (w1 >> 24) & 0xF;
        cycles[1].aa = (w1 >> 21) & 0x7;
        cycles[1].ac = (w1 >> 18) & 0x7;
        cycles[0].d = (w1 >> 15) & 0x7;
        cycles[0].ab = (w1 >> 12) & 0x7;
        cycles[0].ad = (w1 >> 9) & 0x7;
        cycles[1].d = (w1 >> 6) & 0x7;
        cycles[1].ab = (w1 >> 3) & 0x7;
        cycles[1].ad = (w1 >> 0) & 0x7;
    }

    bool cycle_uses_texel(const CombinerCycle& c, int texel, bool swap) {
        // RGB inputs naming TEXEL0 are 1 (and 8 for C as alpha), TEXEL1 2 (9).
        int t0 = swap ? 2 : 1;
        int t1 = swap ? 1 : 2;
        int want = texel == 0 ? t0 : t1;
        int want_alpha_c = texel == 0 ? (swap ? 9 : 8) : (swap ? 8 : 9);
        if ((int)c.a == want || (int)c.b == want || (int)c.c == want || (int)c.d == want || (int)c.c == want_alpha_c) return true;
        if ((int)c.aa == want || (int)c.ab == want || (int)c.ac == want || (int)c.ad == want) return true;
        return false;
    }

    std::string cycle_source(const CombinerCycle& c, bool swap) {
        std::string s;
        // RGB: (A - B) * C + D
        std::string rgb;
        if (c.a == c.b && c.a < 8) {
            rgb = cc_rgb_d(c.d, swap);
        }
        else {
            rgb = "(" + cc_rgb_a(c.a, swap) + " - " + cc_rgb_b(c.b, swap) + ") * " + cc_rgb_c(c.c, swap) + " + " + cc_rgb_d(c.d, swap);
        }
        std::string alpha;
        if (c.aa == c.ab) {
            alpha = cc_alpha_abd(c.ad, swap);
        }
        else {
            alpha = "(" + cc_alpha_abd(c.aa, swap) + " - " + cc_alpha_abd(c.ab, swap) + ") * " + cc_alpha_c(c.ac, swap) + " + " + cc_alpha_abd(c.ad, swap);
        }
        s += "  comb = clamp(vec4(" + rgb + ", " + alpha + "), 0.0, 1.0);\n";
        return s;
    }

    // Blender inputs for the shader.
    std::string blender_input(uint32_t p, const std::string& in) {
        switch (p) {
            case 0: return in;
            case 1: return in; // memory: approximated by the input in a first cycle
            case 2: return "uBlend.rgb";
            default: return "uFog.rgb";
        }
    }
    std::string blend_alpha_a(uint32_t a) {
        switch (a) {
            case 0: return "comb.a";
            case 1: return "uFog.a";
            case 2: return "shade.a";
            default: return "0.0";
        }
    }

    // The 'other' word of a shader key.
    enum : uint32_t {
        KEY_CYCLE_MASK = 0x3,           // cycle type
        KEY_ALPHA_MASK_SHIFT = 2,       // 0 none, 1 threshold, 2 coverage (0.5)
        KEY_BLEND_MODE_SHIFT = 4,       // 0 opaque P, 1 full formula in shader, 2 GL blending with A
        KEY_BLENDER_SHIFT = 16,         // other mode L's blender bits (16)
    };
}

namespace {
    // ============================================================ the GL thread
    // The renderer works in two threads. The display list's thread (the front) reads the
    // game's memory, transforms and culls, and works out every draw; it records what GL
    // has to do in a command list, and the game goes on as soon as the list is complete.
    // The GL thread (the back, GlBackend) owns vitaGL and runs the lists, a frame behind
    // at most. GL objects are named by the front with its own ids, which the back maps
    // to GL's.

    // What lighting a vertex needs from the RSP's state at its load (Conker's lights).
    // A point light: its position (clip space), colour, reach, and direction (model space).
    struct PointLight { float x, y, z, r, g, b, ca, dx, dy, dz; };

    struct VertexContext {
        bool lighting, texgen, advanced, point_lighting, directional_too, fog;
        int num_lights;            // the point lights (num_lights - 1) are in a list beside
        uint32_t light_base;       // where, in the command list's lights
        float dir_light[3];        // the directional light (the last), in model space
        float lookat_model[2][3];
        float amb_r, amb_g, amb_b;
        float dir_r, dir_g, dir_b; // the directional light's colour
        float mod8, mod9, mod10, mod12, mod13, mod14;
        float fog_m, fog_o;
        float tex_ss, tex_st;
        bool texgen_linear;
    };

    // A vertex as the front hands it over. Most are raw: their colour, fog and texture
    // coordinates are worked out by the GL thread (lighting is a good part of the work).
    struct VertexIn {
        float x, y, z, w;        // GL's clip space
        float cx, cy, cz;        // raw: the RSP's clip space (point lights, fog)
        float s, t;              // done: texels
        int16_t rs, rt, flag;    // raw: the vertex's texture coordinates and flag
        uint8_t r, g, b, a;      // raw: its colour (or normal); done: the colour
        int8_t n0, n1;           // raw: the advanced lighting's normal x, y
        uint8_t done;            // r, g, b, a and s, t are final
        uint16_t ctx;            // raw: the list's context
        uint16_t uv;             // the list's texture mapping
        uint32_t color_from;     // flat shading: the vertex whose colour it takes (~0: none)
    };

    // How a batch's texels map to its tiles' textures.
    struct UvMap {
        float shift_s[2], shift_t[2], uls[2], ult[2], offset[2], inv_w[2], inv_h[2];
    };

    // Conker's lighting, texture generation and fog of a raw vertex.
    inline void light_vertex(const VertexContext& c, const PointLight* point, const VertexIn& v, uint8_t rgba[4], float& s_out, float& t_out) {
        const float cx = v.cx, cy = v.cy, cz = v.cz, cw = v.w;
        const int16_t flag = v.flag;
        int16_t s = v.rs, t = v.rt;
        uint8_t cr = v.r, cg = v.g, cb = v.b, ca = v.a;

        float normal[3] = {0, 0, 0};
        if (c.lighting || c.texgen) {
            if (c.advanced) {
                normal[0] = (float)v.n0 / 127.0f;
                normal[1] = (float)v.n1 / 127.0f;
                normal[2] = (float)(int8_t)(flag & 0xFF) / 127.0f;
            }
            else {
                normal[0] = (float)(int8_t)cr / 127.0f;
                normal[1] = (float)(int8_t)cg / 127.0f;
                normal[2] = (float)(int8_t)cb / 127.0f;
            }
        }

        // Texture generation first: without the advanced normals it reads the colour,
        // which the lighting then replaces.
        if (c.texgen) {
            float u = std::clamp(normal[0] * c.lookat_model[0][0] + normal[1] * c.lookat_model[0][1] + normal[2] * c.lookat_model[0][2], -1.0f, 1.0f);
            float w = std::clamp(normal[0] * c.lookat_model[1][0] + normal[1] * c.lookat_model[1][1] + normal[2] * c.lookat_model[1][2], -1.0f, 1.0f);
            if (c.texgen_linear) { // rare: left as is
                u = std::acos(-u) * 325.94932f;
                w = std::acos(-w) * 325.94932f;
            }
            else {
                u = (u + 1.0f) * 512.0f;
                w = (w + 1.0f) * 512.0f;
            }
            s = (int16_t)std::clamp(u * 32.0f, -32768.0f, 32767.0f);
            t = (int16_t)std::clamp(w * 32.0f, -32768.0f, 32767.0f);
        }

        if (c.lighting && flag >= 0) {
            // The point lights' positions are in clip space, scaled by the coordinate modifier.
            const float lx = (cx + c.mod8) * c.mod12;
            const float ly = (cy + c.mod9) * c.mod13;
            const float lz = (cz + c.mod10) * c.mod14;
            float r = c.amb_r, g = c.amb_g, b = c.amb_b;
            int l = c.num_lights - 1;
            if (c.advanced && l >= 0) {
                // The last light is directional.
                float intensity = std::min(1.0f, normal[0] * c.dir_light[0] + normal[1] * c.dir_light[1] + normal[2] * c.dir_light[2]);
                if (intensity > 0.0f) {
                    r += c.dir_r * intensity;
                    g += c.dir_g * intensity;
                    b += c.dir_b * intensity;
                }
            }
            // The others are point lights.
            for (l = c.num_lights - 2; l >= 0; l--) {
                const PointLight& light = point[l];
                const float dx = lx - light.x;
                const float dy = ly - light.y;
                const float dz = lz - light.z;
                const float len = (dx * dx + dy * dy + dz * dz) * (2.0f / 65536.0f);
                // min(1, ca / len), without a division when it's 1.
                float intensity = (len <= light.ca) ? 1.0f : light.ca / len;
                if (c.directional_too) {
                    intensity *= std::min(1.0f, normal[0] * light.dx + normal[1] * light.dy + normal[2] * light.dz);
                }
                if (intensity > 0.0f) {
                    r += light.r * intensity;
                    g += light.g * intensity;
                    b += light.b * intensity;
                }
            }
            cr = (uint8_t)(std::min(1.0f, r) * cr);
            cg = (uint8_t)(std::min(1.0f, g) * cg);
            cb = (uint8_t)(std::min(1.0f, b) * cb);
        }

        if (c.fog) {
            float w = std::fabs(cw) < 0.001f ? 0.001f : cw;
            float winv = 1.0f / w;
            if (winv < 0.0f) winv = 32767.0f;
            float f = cz * winv * c.fog_m + c.fog_o;
            ca = (uint8_t)std::clamp(f, 0.0f, 255.0f);
        }

        s_out = (float)s * c.tex_ss;
        t_out = (float)t * c.tex_st;
        rgba[0] = cr; rgba[1] = cg; rgba[2] = cb; rgba[3] = ca;
    }

    // Ids the back creates at start.
    enum : uint32_t { TEX_WHITE = 1, TEX_FONT = 2, TEX_CPU_FRAME = 3, TEX_FIRST_FREE = 16 };

    // A batch of triangles and everything GL needs for it.
    struct DrawCmd {
        uint32_t fbo = 0, fb_w = 0, fb_h = 0; // the target and its size in N64 pixels
        uint32_t program = 0;
        uint32_t tex[2] = {0, 0};
        float tex_intensity[2] = {0, 0};
        bool blend = false;
        GLenum blend_src = GL_ONE, blend_dst = GL_ZERO;
        bool color_write = true;
        bool depth_test = false, depth_write = false, decal = false;
        GLenum depth_func = GL_LEQUAL;
        int scissor[4] = {0, 0, 0, 0};
        float prim[4] = {}, env[4] = {}, fog[4] = {}, blendc[4] = {}, fill[4] = {};
        float primlod = 0;
        float convert[2] = {0, 0};
        uint32_t vbase = 0, ibase = 0, icount = 0; // in the list's vertex and index arrays
        uint32_t vcount = 0;
        bool raw = false; // its vertices are VertexIns to finish (triangles), not GLVertexes (rectangles)
        bool deferred = false; // its triangles are the list's tris[tbase, tbase + tcount)
        uint32_t tbase = 0, tcount = 0;
        bool debug = false; // debug: log its finished vertices
        bool strong_decal = false; // debug (flag 262144): a larger depth bias for decals
    };

    class GxmBackend;
    using Backend = GxmBackend;

    // Deferred geometry: the list reader records the vertices as loaded and the triangles as
    // the vertices they join; the back (on another core) transforms, culls, cuts, lights and
    // batches them (expand_triangles). The reader was the frame's bottleneck on the Vita.
    struct SrcVertex {
        int16_t x, y, z, flag;  // as loaded (model space)
        int16_t s, t;           // texture coordinates as loaded
        uint8_t r, g, b, a;     // colour (or normal)
        int8_t n0, n1;          // the advanced lighting's normal x, y
        uint16_t ctx;           // the list's context
        uint16_t xform;         // the list's transform
        uint16_t done;          // modified (G_MODIFYVTX): r, g, b, a and fs, ft are final
        float fs, ft;
        // Left as it is: load_deferred sets every field, and the list's src grown for each load
        // (resize) was zeroed first, every frame (a good part of the reader's memset time).
        SrcVertex() {}
    };
    // A load's transform: the matrix's rows and the viewport (into the framebuffer's
    // normalised coordinates, x of the 4:3 view in a wider image included).
    struct Xform {
        float row[4][4];
        float vscale[4], vtrans[4];
    };
    // The list's geometry stream, in order: loads into the 64 vertex slots (as the RSP's) and
    // triangles joining slots. The back keeps the slots as the reader did (they stay in its
    // cache: indexing every loaded vertex of the frame didn't, and the Vita's back took twice
    // as long as the reader had).
    struct TriRec {
        uint8_t v[3];           // a triangle's slots; a load: v[0] its first slot
        uint8_t flags;          // TRI_*, or REC_LOAD
        uint16_t uv;            // the list's texture mapping
        uint16_t count;         // a load: how many vertices
        uint32_t src;           // a load: its first vertex in the list's src
        float prim_z;           // with TRI_ZPRIM: the primitive depth (normalised)
    };
    constexpr uint8_t TRI_CULL_FRONT = 1, TRI_CULL_BACK = 2, TRI_FLAT = 4, TRI_ZPRIM = 8, TRI_SKIP = 16, REC_LOAD = 128;

    struct CommandList {
        std::vector<std::function<void(Backend&, CommandList&)>> cmds;
        std::vector<DrawCmd> draws;
        // The frame's vertices and indices (sized as capacity: the front counts what it used).
        std::vector<GLVertex> verts;
        std::vector<VertexIn> vin; // the triangles' vertices, made into verts at the same places
        std::vector<uint16_t> idx;
        std::vector<VertexContext> ctxs;
        std::vector<PointLight> lights; // the contexts' point lights
        std::vector<UvMap> uvmaps;
        std::vector<SrcVertex> src;  // deferred geometry
        std::vector<Xform> xforms;
        std::vector<TriRec> tris;
        std::vector<GLVertex> dverts; // the deferred draws' vertices and indices (the expander's)
        std::vector<uint16_t> didx;
        uint32_t debug_flags = 0;
        uint32_t serial = 0; // which submission (lists are reused)
        size_t verts_used = 0, idx_used = 0;
        void reset() {
            cmds.clear();
            draws.clear();
            ctxs.clear();
            lights.clear();
            uvmaps.clear();
            src.clear();
            xforms.clear();
            tris.clear();
            verts_used = idx_used = 0;
        }
    };

    // A raw or done vertex lit, coloured and mapped onto its textures (not its flat colour).
    inline void finish_one(const CommandList& list, const VertexIn& v, GLVertex& g) {
        g.x = v.x; g.y = v.y; g.z = v.z; g.w = v.w;
        if (g.w > 0.0f) {
            const float lim = g.w * 0.99999f;
            g.z = g.z > lim ? lim : (g.z < -lim ? -lim : g.z);
        }
        float s, t;
        if (v.done) {
            g.color[0] = v.r; g.color[1] = v.g; g.color[2] = v.b; g.color[3] = v.a;
            s = v.s;
            t = v.t;
        }
        else {
            const VertexContext& c = list.ctxs[v.ctx];
            light_vertex(c, list.lights.data() + c.light_base, v, g.color, s, t);
        }
        const UvMap& m = list.uvmaps[v.uv];
        g.u0 = (s * m.shift_s[0] - m.uls[0] + m.offset[0]) * m.inv_w[0];
        g.v0 = (t * m.shift_t[0] - m.ult[0] + m.offset[0]) * m.inv_h[0];
        g.u1 = (s * m.shift_s[1] - m.uls[1] + m.offset[1]) * m.inv_w[1];
        g.v1 = (t * m.shift_t[1] - m.ult[1] + m.offset[1]) * m.inv_h[1];
    }

    // A loaded vertex through its transform: clip space, the framebuffer's, its outcodes.
    struct XfVertex {
        float x, y, z, w;       // through the viewport
        float cx, cy, cz;       // clip space (lighting, fog)
        float ndc_x, ndc_y;     // for culling
        uint32_t clip;
    };

    inline void transform_vertex(const Xform& xf, const SrcVertex& sv, XfVertex& o) {
        const float px = sv.x, py = sv.y, pz = sv.z;
#if defined(__ARM_NEON)
        const float32x4_t clip4 = vmlaq_n_f32(vmlaq_n_f32(vmlaq_n_f32(vld1q_f32(xf.row[3]), vld1q_f32(xf.row[0]), px),
                                                          vld1q_f32(xf.row[1]), py), vld1q_f32(xf.row[2]), pz);
        const float cw = vgetq_lane_f32(clip4, 3);
        vst1_f32(&o.cx, vget_low_f32(clip4));
        o.cz = vgetq_lane_f32(clip4, 2);
        const float32x2_t tiny_w = vdup_n_f32(1e-6f);
        const float32x2_t w2 = vdup_lane_f32(vget_high_f32(clip4), 1);
        const float32x2_t wd = vbsl_f32(vcalt_f32(w2, tiny_w), tiny_w, w2);
        float32x2_t est = vrecpe_f32(wd);
        est = vmul_f32(est, vrecps_f32(wd, est));
        est = vmul_f32(est, vrecps_f32(wd, est));
        vst1_f32(&o.ndc_x, vmul_f32(vget_low_f32(clip4), est));
        const float32x4_t pos = vmlaq_n_f32(vmulq_f32(clip4, vld1q_f32(xf.vscale)), vld1q_f32(xf.vtrans), cw);
        vst1q_f32(&o.x, pos);
        static const uint32_t below_bits[4] = { 1, 4, 16, 0 }, above_bits[4] = { 2, 8, 32, 0 };
        const float32x4_t w4 = vdupq_lane_f32(vget_high_f32(pos), 1);
        const uint32x4_t out = vorrq_u32(vandq_u32(vcltq_f32(pos, vnegq_f32(w4)), vld1q_u32(below_bits)),
                                         vandq_u32(vcgtq_f32(pos, w4), vld1q_u32(above_bits)));
        const uint32x2_t out2 = vorr_u32(vget_low_u32(out), vget_high_u32(out));
        o.clip = vget_lane_u32(vpadd_u32(out2, out2), 0);
#else
        const float cx = px * xf.row[0][0] + py * xf.row[1][0] + pz * xf.row[2][0] + xf.row[3][0];
        const float cy = px * xf.row[0][1] + py * xf.row[1][1] + pz * xf.row[2][1] + xf.row[3][1];
        const float cz = px * xf.row[0][2] + py * xf.row[1][2] + pz * xf.row[2][2] + xf.row[3][2];
        const float cw = px * xf.row[0][3] + py * xf.row[1][3] + pz * xf.row[2][3] + xf.row[3][3];
        o.cx = cx; o.cy = cy; o.cz = cz;
        const float rw = 1.0f / (std::fabs(cw) < 1e-6f ? 1e-6f : cw);
        o.ndc_x = cx * rw; o.ndc_y = cy * rw;
        o.x = cx * xf.vscale[0] + cw * xf.vtrans[0];
        o.y = cy * xf.vscale[1] + cw * xf.vtrans[1];
        o.z = cz * xf.vscale[2] + cw * xf.vtrans[2];
        o.w = cw;
        o.clip = negative(o.x + o.w) | (negative(o.w - o.x) << 1) | (negative(o.y + o.w) << 2) |
                 (negative(o.w - o.y) << 3) | (negative(o.z + o.w) << 4) | (negative(o.w - o.z) << 5);
#endif
    }

    // The vertex a triangle hands the lighting (as the reader made them before).
    inline void deferred_vertex_in(const SrcVertex& sv, const XfVertex& xv, uint16_t uv, bool zprim, float prim_z, VertexIn& in) {
        in.x = xv.x; in.y = xv.y; in.z = zprim ? prim_z * xv.w : xv.z; in.w = xv.w;
        in.cx = xv.cx; in.cy = xv.cy; in.cz = xv.cz;
        in.rs = sv.s; in.rt = sv.t; in.flag = sv.flag;
        in.r = sv.r; in.g = sv.g; in.b = sv.b; in.a = sv.a;
        in.n0 = sv.n0; in.n1 = sv.n1;
        in.done = (uint8_t)sv.done;
        in.s = sv.fs; in.t = sv.ft;
        in.ctx = sv.ctx;
        in.uv = uv;
        in.color_from = ~0u;
    }

    constexpr float deferred_w_cut = 1e-3f; // as the reader's w_cut

    inline VertexIn lerp_in(const VertexIn& a, const VertexIn& b, float t, bool normals) {
        auto lf = [t](float x, float y) { return x + (y - x) * t; };
        auto li = [t](int x, int y) { return (int)std::lround(x + (y - x) * t); };
        VertexIn o = a;
        o.x = lf(a.x, b.x); o.y = lf(a.y, b.y); o.z = lf(a.z, b.z); o.w = lf(a.w, b.w);
        o.cx = lf(a.cx, b.cx); o.cy = lf(a.cy, b.cy); o.cz = lf(a.cz, b.cz);
        o.s = lf(a.s, b.s); o.t = lf(a.t, b.t);
        o.rs = (int16_t)li(a.rs, b.rs); o.rt = (int16_t)li(a.rt, b.rt);
        auto lb = [&](uint8_t x, uint8_t y) {
            return normals ? (uint8_t)(int8_t)li((int8_t)x, (int8_t)y) : (uint8_t)li(x, y);
        };
        o.r = lb(a.r, b.r); o.g = lb(a.g, b.g); o.b = lb(a.b, b.b);
        o.a = (uint8_t)li(a.a, b.a);
        o.n0 = (int8_t)li(a.n0, b.n0); o.n1 = (int8_t)li(a.n1, b.n1);
        o.flag = (int16_t)((a.flag & 0xFF00) | ((uint8_t)(int8_t)li((int8_t)(a.flag & 0xFF), (int8_t)(b.flag & 0xFF))));
        return o;
    }

    // The back's working state for a list's deferred geometry (one back thread): the vertex
    // slots, worked out at each load, and the batch's vertices made from them.
    struct ExpandScratch {
        XfVertex xf[max_vertices];
        uint32_t src[max_vertices];
        uint32_t emit_serial[max_vertices] = {};
        uint16_t emit_index[max_vertices] = {};
        uint32_t serial = 1;
        std::vector<GLVertex> verts;
        std::vector<uint16_t> idx;
        uint32_t list_serial = ~0u;
        size_t nv = 0, ni = 0;
        GLVertex* grow_v(size_t k) {
            if (nv + k > verts.size()) verts.resize(std::max(verts.size() * 2, nv + k + 1024));
            GLVertex* p = &verts[nv];
            nv += k;
            return p;
        }
        uint16_t* grow_i(size_t k) {
            if (ni + k > idx.size()) idx.resize(std::max(idx.size() * 2, ni + k + 3072));
            uint16_t* p = &idx[ni];
            ni += k;
            return p;
        }
    };

    // A draw's stretch of the geometry stream made into its vertices and indices (scratch.verts/
    // idx from 0): the loads worked out into the slots; for each triangle what the reader did
    // before (outcodes, culling, the cut at the camera's plane), then the lighting.
    inline void expand_triangles(const CommandList& list, DrawCmd& d, ExpandScratch& x) {
        if (x.list_serial != list.serial) {
            x.list_serial = list.serial;
            for (uint32_t& v : x.src) v = ~0u;
        }
        // The draw's vertices and indices after the list's earlier ones; indices from its first.
        const size_t vb = x.nv, ib = x.ni;
        struct Done {
            DrawCmd& d; ExpandScratch& x; size_t vb, ib;
            ~Done() {
                d.vbase = (uint32_t)vb; d.vcount = (uint32_t)(x.nv - vb);
                d.ibase = (uint32_t)ib; d.icount = (uint32_t)(x.ni - ib);
            }
        } done{ d, x, vb, ib };
        x.serial++;
        const uint32_t dbg = list.debug_flags;
        const TriRec* recs = list.tris.data() + d.tbase;
        uint32_t last_key = ~0u;
        float last_prim_z = 0.0f;
        for (uint32_t k = 0; k < d.tcount; k++) {
            const TriRec& t = recs[k];
            if (t.flags & REC_LOAD) {
                const uint32_t first = t.v[0];
                for (uint32_t i = 0; i < t.count && first + i < (uint32_t)max_vertices; i++) {
                    const SrcVertex& sv = list.src[t.src + i];
                    transform_vertex(list.xforms[sv.xform], sv, x.xf[first + i]);
                    x.src[first + i] = t.src + i;
                    x.emit_serial[first + i] = 0;
                }
                continue;
            }
            if (t.flags & TRI_SKIP) continue;
            const uint32_t sa = x.src[t.v[0]], sb = x.src[t.v[1]], sc = x.src[t.v[2]];
            if (sa == ~0u || sb == ~0u || sc == ~0u) continue;
            // Vertices are shared by triangles with the same mapping and depth source (the
            // reader's vertex cache started again when they changed).
            const uint32_t key = t.uv | ((uint32_t)(t.flags & TRI_ZPRIM) << 16);
            if (key != last_key || ((t.flags & TRI_ZPRIM) && t.prim_z != last_prim_z)) {
                last_key = key;
                last_prim_z = t.prim_z;
                x.serial++;
            }
            const XfVertex* v[3] = { &x.xf[t.v[0]], &x.xf[t.v[1]], &x.xf[t.v[2]] };
            const uint32_t si[3] = { sa, sb, sc };
            if ((v[0]->clip & v[1]->clip & v[2]->clip) && !(dbg & 1)) {
                continue;
            }
            const uint32_t cull = (dbg & 2) ? 0 : (t.flags & (TRI_CULL_FRONT | TRI_CULL_BACK));
            if (cull) {
                if (cull == (TRI_CULL_FRONT | TRI_CULL_BACK)) continue;
                const float dx1 = v[1]->ndc_x - v[0]->ndc_x, dy1 = v[1]->ndc_y - v[0]->ndc_y;
                const float dx2 = v[2]->ndc_x - v[0]->ndc_x, dy2 = v[2]->ndc_y - v[0]->ndc_y;
                const float cross = dx1 * dy2 - dy1 * dx2;
                uint32_t bits;
                std::memcpy(&bits, &cross, 4);
                const bool zero = (bits << 1) == 0;
                const bool below = ((bits >> 31) ^ negative(v[0]->w) ^ negative(v[1]->w) ^ negative(v[2]->w)) != 0;
                if (zero || (cull == TRI_CULL_FRONT ? !below : below)) continue;
            }
            const bool flat = (t.flags & TRI_FLAT) != 0, zprim = (t.flags & TRI_ZPRIM) != 0;
            const bool cut = (v[0]->w <= deferred_w_cut || v[1]->w <= deferred_w_cut || v[2]->w <= deferred_w_cut) && !(dbg & 16384);
            if (cut) {
                // Cut at the camera's plane to its part in front (a fan of up to four vertices).
                VertexIn tri[3];
                for (int i = 0; i < 3; i++) {
                    deferred_vertex_in(list.src[si[i]], *v[i], t.uv, zprim, t.prim_z, tri[i]);
                }
                bool normals = false;
                if (!tri[0].done) {
                    const VertexContext& c = list.ctxs[tri[0].ctx];
                    normals = (c.lighting || c.texgen) && !c.advanced;
                }
                VertexIn poly[4];
                int n = 0;
                for (int i = 0; i < 3; i++) {
                    const VertexIn& a = tri[i];
                    const VertexIn& b = tri[(i + 1) % 3];
                    const float da = a.w - deferred_w_cut, db = b.w - deferred_w_cut;
                    if (da >= 0.0f) poly[n++] = a;
                    if ((da >= 0.0f) != (db >= 0.0f) && n < 4) poly[n++] = lerp_in(a, b, da / (da - db), normals);
                }
                if (n < 3) continue;
                const uint16_t first = (uint16_t)(x.nv - vb);
                GLVertex* out = x.grow_v(n);
                for (int i = 0; i < n; i++) {
                    if (flat && i == 0) {
                        poly[0].r = tri[0].r; poly[0].g = tri[0].g; poly[0].b = tri[0].b; poly[0].a = tri[0].a;
                    }
                    finish_one(list, poly[i], out[i]);
                    if (flat && i > 0) {
                        out[i].color[0] = out[0].color[0]; out[i].color[1] = out[0].color[1]; out[i].color[2] = out[0].color[2];
                    }
                }
                uint16_t* ix = x.grow_i((uint32_t)(n - 2) * 3);
                for (int i = 1; i + 1 < n; i++) {
                    *ix++ = first;
                    *ix++ = (uint16_t)(first + i);
                    *ix++ = (uint16_t)(first + i + 1);
                }
                continue;
            }
            uint16_t* ix = x.grow_i(3);
            for (int i = 0; i < 3; i++) {
                const uint32_t slot = t.v[i];
                // Flat shading colours a vertex by the triangle: not shared then.
                if (!flat && x.emit_serial[slot] == x.serial) {
                    ix[i] = x.emit_index[slot];
                    continue;
                }
                const uint16_t at = (uint16_t)(x.nv - vb);
                GLVertex& g = *x.grow_v(1);
                VertexIn in;
                deferred_vertex_in(list.src[si[i]], *v[i], t.uv, zprim, t.prim_z, in);
                finish_one(list, in, g);
                if (flat && i > 0) {
                    const GLVertex& f = x.verts[vb + ix[0]];
                    g.color[0] = f.color[0]; g.color[1] = f.color[1]; g.color[2] = f.color[2];
                }
                ix[i] = at;
                if (!flat) {
                    x.emit_serial[slot] = x.serial;
                    x.emit_index[slot] = at;
                }
            }
        }
    }

    // The triangles' vertices: lit, coloured and mapped onto their textures.
    inline void finish_vertices(CommandList& list, const DrawCmd& d) {
        GLVertex* out = &list.verts[d.vbase];
        const VertexIn* in = &list.vin[d.vbase];
        for (uint32_t i = 0; i < d.vcount; i++) {
            const VertexIn& v = in[i];
            GLVertex& g = out[i];
            g.x = v.x; g.y = v.y; g.z = v.z; g.w = v.w;
            // The RDP clamps depth to its range; a GPU clips there instead (the Vita's does,
            // Vita3K's doesn't): distant water at the far end of its depth range came and went
            // with the camera's sway. Clamped as the N64 does.
            if (g.w > 0.0f) {
                const float lim = g.w * 0.99999f;
                g.z = g.z > lim ? lim : (g.z < -lim ? -lim : g.z);
            }
            float s, t;
            if (v.done) {
                g.color[0] = v.r; g.color[1] = v.g; g.color[2] = v.b; g.color[3] = v.a;
                s = v.s;
                t = v.t;
            }
            else {
                const VertexContext& c = list.ctxs[v.ctx];
                light_vertex(c, list.lights.data() + c.light_base, v, g.color, s, t);
            }
            if (v.color_from != ~0u) {
                const GLVertex& src = list.verts[v.color_from];
                g.color[0] = src.color[0]; g.color[1] = src.color[1]; g.color[2] = src.color[2];
            }
            const UvMap& m = list.uvmaps[v.uv];
            g.u0 = (s * m.shift_s[0] - m.uls[0] + m.offset[0]) * m.inv_w[0];
            g.v0 = (t * m.shift_t[0] - m.ult[0] + m.offset[0]) * m.inv_h[0];
            g.u1 = (s * m.shift_s[1] - m.uls[1] + m.offset[1]) * m.inv_w[1];
            g.v1 = (t * m.shift_t[1] - m.ult[1] + m.offset[1]) * m.inv_h[1];
        }
    }


    // Debug: a draw's finished vertices, summed up (from the back).
    inline void log_finished(const CommandList& list, const DrawCmd& d) {
        float a0 = 1e9f, a1 = -1e9f, u0 = 1e9f, u1 = -1e9f, v0 = 1e9f, v1 = -1e9f;
        uint32_t r = 0, g = 0, b = 0;
        for (uint32_t i = 0; i < d.vcount; i++) {
            const GLVertex& v = list.verts[d.vbase + i];
            a0 = std::min(a0, (float)v.color[3]); a1 = std::max(a1, (float)v.color[3]);
            u0 = std::min(u0, v.u0); u1 = std::max(u1, v.u0);
            v0 = std::min(v0, v.v0); v1 = std::max(v1, v.v0);
            r += v.color[0]; g += v.color[1]; b += v.color[2];
        }
        const uint32_t n = d.vcount ? d.vcount : 1;
        std::fprintf(stderr, "[back] draw n=%u tex %u,%u alpha[%.0f %.0f] rgb avg(%u %u %u) u[%.3f %.3f] v[%.3f %.3f] prim %.2f env %.2f primlod %.2f\n",
            d.vcount, d.tex[0], d.tex[1], a0, a1, r / n, g / n, b / n, u0, u1, v0, v1, d.prim[3], d.env[3], d.primlod);
    }

#include "gxm_backend.inc"
}

namespace {
    class VitaRenderer : public ultramodern::renderer::RendererContext {
    public:
        explicit VitaRenderer(uint8_t* rdram_) : rdram(rdram_), game_rdram(rdram_) {
            chosen_api = ultramodern::renderer::GraphicsApi::Auto;
            backend = std::make_unique<Backend>();
            list = backend->take_list();
            batch.attach(list.get());
            setup_result = ultramodern::renderer::SetupResult::Success;
            ok = true;
            reset_rsp();
        }

        ~VitaRenderer() override {
            submit();
            backend->wait_idle();
        }

        bool valid() override { return ok; }

        bool update_config(const ultramodern::renderer::GraphicsConfig&, const ultramodern::renderer::GraphicsConfig&) override {
            return true;
        }

        void enable_instant_present() override {}

        void send_dl(const OSTask* task) override {
            // Debug (flag 32768): lists read on the game's thread, as before (ultramodern events.cpp);
            // otherwise from the capture taken as the game submitted it.
            ultramodern_vita_sync_dl = (debug_flags & 32768) != 0;
            ultramodern_vita_late_dp = (debug_flags & 4194304) != 0;
            const int cap = ultramodern_vita_current_capture;
            cap_pt = cap >= 0 ? capture::slots[cap].pt : nullptr;
            struct CapEnd { const uint8_t* const*& p; ~CapEnd() { p = nullptr; } } cap_end{ cap_pt };
            g_front_stage = 1;
            struct StageEnd { ~StageEnd() { g_front_stage = 0; g_front_lists++; } } stage_end;
            // The Debug page's "Capture 5 seconds", once its menu is closed: the GPU's frames as
            // thumbnails (ux0:data/conker/probe/cNN) and two display lists' draws in the log.
            const bool test_capture = (debug_flags & 65536) && dl_count == 1500; // debug: the same, from the flags file
            if (capture_left == 0 && !conker::vita::menu::is_open() && (conker::vita::menu::take_capture_request() || test_capture)) {
                capture_index++;
                capture_left = 150;
                dump_dl = dl_count;
                dump_count = 2;
                std::fprintf(stderr, "[capture] %u starts at present %u, display list %u\n", capture_index, present_count, dl_count);
            }
            struct TraceScope { TraceScope() { ultramodern_trace("send_dl", 0); } ~TraceScope() { ultramodern_trace("send_dl end", 0); } } trace_scope;
            // Conker's microcode starts every task in its basic lighting mode (RT64's reset).
            cbfd_advanced_lighting = false;
            vctx_dirty = true;
            if (dl_count < 5 || dl_count % 120 == 0) {
                std::fprintf(stderr, "[renderer] display list #%u at 0x%08X\n", dl_count, (uint32_t)task->t.data_ptr);
            }
            // Debug (flag 2048): what the game writes in RDRAM while the list is read.
            static std::vector<uint8_t> rdram_before;
            const bool watch = (debug_flags & 2048) != 0 && (dl_count % 10) == 0;
            if (watch) {
                rdram_before.assign(rdram, rdram + 0x800000);
                read_mark.assign(0x800000 / 64, 0);
            }
            watching = watch;
            if (debug_flags & 1024) {
                // Debug: a slow renderer (the Vita's front takes this long; Vita3K's less),
                // to see what the game does meanwhile.
                sceKernelDelayThread(20000);
            }
            struct WatchEnd {
                const uint8_t* rdram; bool on; uint32_t dl; VitaRenderer* self;
                ~WatchEnd() {
                    if (!on) return;
                    uint32_t ranges = 0, bytes = 0, start = ~0u, last = 0;
                    std::string out;
                    for (uint32_t a = 0x80000; a < 0x800000; a += 4) {
                        if (std::memcmp(&rdram_before[a], rdram + a, 4) == 0) continue;
                        bytes += 4;
                        if (start != ~0u && a - last <= 64) { last = a; continue; }
                        if (start != ~0u && ranges < 80) { char b[48]; std::snprintf(b, sizeof(b), " %06X-%06X", start, last + 3); out += b; }
                        if (start != ~0u) ranges++;
                        start = last = a;
                    }
                    if (start != ~0u) { if (ranges < 80) { char b[48]; std::snprintf(b, sizeof(b), " %06X-%06X", start, last + 3); out += b; } ranges++; }
                    std::fprintf(stderr, "[rdram] dl %u: %u bytes written during the list, %u ranges:%s\n", dl, bytes, ranges, out.c_str());
                    // Of those, what the list read.
                    uint32_t hit[16] = {};
                    std::string hits;
                    for (uint32_t a = 0; a < 0x800000; a += 4) {
                        const uint8_t kind = self->read_mark[a >> 6];
                        if (!kind || std::memcmp(&rdram_before[a], rdram + a, 4) == 0) continue;
                        hit[kind & 15] += 4;
                        if (hits.size() < 600) { char b[32]; std::snprintf(b, sizeof(b), " %06X(%u)", a, kind); hits += b; }
                    }
                    std::fprintf(stderr, "[rdram] dl %u read-then-written: list %u, vertices %u, matrices %u, movemem %u bytes;%s\n", dl,
                        hit[1] + hit[3] + hit[5] + hit[9], hit[2] + hit[6] + hit[10], hit[4] + hit[12], hit[8], hits.c_str());
                    self->watching = false;
                }
            } watch_end{ rdram, watch, dl_count, this };
            const uint64_t dl_start = sceKernelGetProcessTimeWide();
            if (fb_trace_at >= 0 && dl_start >= (uint64_t)(fb_trace_at * 1e6)) {
                fb_trace = true;
                fb_trace_at = -1;
            }
            if (dump_at_s >= 0 && dl_start >= (uint64_t)(dump_at_s * 1e6)) {
                dump_dl = dl_count;
                dump_at_s = -1;
                std::fprintf(stderr, "[renderer] dumping display list #%u\n", dl_count);
            }
            update_debug_flags();
            // Debug (flag 2097152): triangles made into vertices here, as before, not on the back.
            deferred_geometry = (debug_flags & 2097152) == 0;
            list->debug_flags = debug_flags;
            // Debug (ux0:data/conker/debug_ab): the triangles' parts' cost without the clock's, the
            // lists going in turn with triangles only culled, prepared up to their draw state, or
            // none (a list each: a short scene gets them all).
            ab_phase = ab_on ? dl_count % 4 : 0;
            if (dumping()) std::fprintf(stderr, "[dl] start %u\n", dl_count);
            // One list in 300 timed by parts (two of them averaged in each [parts] line): the clock
            // costs ~1 us a read on the Vita, so a timed list takes half as long again.
            profiling = (dl_count % (cmd_timing ? 30 : 300)) == 0;
            last_op = -1;
            const bool timing_tail = profiling;
            const uint64_t list_t0 = profiling ? sceKernelGetProcessTimeWide() : 0;
            start_matrices(true);
            run_display_list((uint32_t)task->t.data_ptr & 0x1FFFFFFF);
            // The screen it drew (an in-between frame goes there).
            interp_main = (current_fb != nullptr && current_fb->width >= 256 && current_fb->siz != SIZ_8b) ? current_fb : nullptr;
            if (profiling) {
                part_total_us += sceKernelGetProcessTimeWide() - list_t0;
                profiling = false;
                if (++part_lists == 2) {
                    // Triangles include their textures' preparing (tiles), shown apart too.
                    const double n = (double)part_lists * 1000.0;
                    std::fprintf(stderr, "[parts] list %.1f ms: vertices %.1f, triangles %.1f (tiles %.1f), texture loads %.1f, matrices %.1f, draws out %.1f, other %.1f\n",
                        part_total_us / n, part_us[P_VTX] / n, part_us[P_TRI] / n, part_us[P_TILE] / n, part_us[P_LOAD] / n,
                        part_us[P_MTX] / n, part_us[P_FLUSH] / n,
                        (double)((int64_t)part_total_us - (int64_t)(part_us[P_VTX] + part_us[P_TRI] + part_us[P_LOAD] + part_us[P_MTX] + part_us[P_FLUSH])) / n);
                    {
                        std::string top;
                        for (int k = 0; k < 12; k++) {
                            int best = 0;
                            for (int o = 1; o < 256; o++) if (op_hist[o] > op_hist[best]) best = o;
                            if (!op_hist[best]) break;
                            char b[32]; std::snprintf(b, sizeof(b), " %02X:%u", best, op_hist[best] / (unsigned)part_lists); top += b;
                            op_hist[best] = 0;
                        }
                        for (uint32_t& h : op_hist) h = 0;
                        std::fprintf(stderr, "[parts] commands a list:%s\n", top.c_str());
                    }
                    if (cmd_timing) {
                        if (clock_us < 0.0) {
                            const uint64_t c0 = sceKernelGetProcessTimeWide();
                            for (int i = 0; i < 1000; i++) (void)sceKernelGetProcessTimeWide();
                            clock_us = (sceKernelGetProcessTimeWide() - c0) / 1000.0;
                        }
                        std::string top;
                        double sum = 0.0;
                        for (int o = 0; o < 256; o++) sum += op_us[o] - clock_us * op_n[o];
                        for (int k = 0; k < 16; k++) {
                            int best = -1;
                            double best_us = 0.0;
                            for (int o = 0; o < 256; o++) {
                                const double us = op_us[o] - clock_us * op_n[o];
                                if (op_n[o] && us > best_us) { best = o; best_us = us; }
                            }
                            if (best < 0) break;
                            char b[48];
                            std::snprintf(b, sizeof(b), " %02X:%.2fms/%u", best, best_us / part_lists / 1000.0, op_n[best] / (unsigned)part_lists);
                            top += b;
                            op_n[best] = 0;
                        }
                        std::fprintf(stderr, "[cmdtime] list %.2f ms in commands (clock %.2f us, taken off):%s\n", sum / part_lists / 1000.0, clock_us, top.c_str());
                        std::fprintf(stderr, "[cmdtime] texture block loads %u, distinct %u\n", loads_in_list, (unsigned)seen_loads.size());
                        seen_loads.clear();
                        loads_in_list = 0;
                        for (uint64_t& u : op_us) u = 0;
                        for (uint32_t& n : op_n) n = 0;
                    }
                    part_lists = part_total_us = 0;
                    for (uint64_t& u : part_us) u = 0;
                }
            }
            if (dumping()) std::fprintf(stderr, "[dl] end %u\n", dl_count);
            const uint64_t tail_t0 = timing_tail ? sceKernelGetProcessTimeWide() : 0;
            flush();
            const uint64_t tail_t1 = timing_tail ? sceKernelGetProcessTimeWide() : 0;
            settle_signatures();
            const uint64_t tail_t2 = timing_tail ? sceKernelGetProcessTimeWide() : 0;
            write_back_framebuffers();
            const uint64_t tail_t3 = timing_tail ? sceKernelGetProcessTimeWide() : 0;
            // The GL thread draws it; the game can go on.
            submit();
            if (timing_tail) {
                const uint64_t tail_t4 = sceKernelGetProcessTimeWide();
                std::fprintf(stderr, "[parts] after the list: flush %.1f ms, signatures %.1f, write-back %.1f, submit %.1f; whole send_dl %.1f\n",
                    (tail_t1 - tail_t0) / 1000.0, (tail_t2 - tail_t1) / 1000.0, (tail_t3 - tail_t2) / 1000.0, (tail_t4 - tail_t3) / 1000.0,
                    (tail_t4 - dl_start) / 1000.0);
            }
            const uint32_t dl_us = (uint32_t)(sceKernelGetProcessTimeWide() - dl_start);
            last_list_us = dl_us;
            if (ab_on) {
                ab_us[ab_phase] += dl_us;
                ab_lists[ab_phase]++;
                if (++ab_count % 60 == 0) {
                    std::fprintf(stderr, "[ab] list ms: all %.1f (%u), triangles culled only %.1f (%u), up to their state %.1f (%u), no triangles %.1f (%u)\n",
                        ab_lists[0] ? ab_us[0] / 1000.0 / ab_lists[0] : 0.0, ab_lists[0], ab_lists[1] ? ab_us[1] / 1000.0 / ab_lists[1] : 0.0, ab_lists[1],
                        ab_lists[2] ? ab_us[2] / 1000.0 / ab_lists[2] : 0.0, ab_lists[2], ab_lists[3] ? ab_us[3] / 1000.0 / ab_lists[3] : 0.0, ab_lists[3]);
                    for (int k = 0; k < 4; k++) { ab_us[k] = 0; ab_lists[k] = 0; }
                }
            }
            conker::vita::bench::on_display_list(dl_us, stats.tris);
            if ((dl_count % 300) == 0) {
                enqueue([](Backend& b, CommandList&) { b.log_health(); });
            }
            if ((dl_count % 30) == 0) {
                std::fprintf(stderr, "[renderer] last 30 lists: front waited %u ms, GL thread busy %u ms\n",
                    backend->wait_us.exchange(0) / 1000, backend->busy_us.exchange(0) / 1000);
            }
            if (dl_us > 30000 && (dl_count % 30) == 0) {
                std::fprintf(stderr, "[renderer] slow display list #%u: %u ms (%u programs in %u ms, %u textures in %u ms, %u draws, %u tris)\n",
                    dl_count, dl_us / 1000, stats.programs, stats.program_us / 1000, stats.textures, stats.texture_us / 1000,
                    stats.draws, stats.tris);
            }
            if (dl_count % 60 == 0) {
                std::fprintf(stderr, "[renderer] work: %u vertex loads (%u vertices), %u contexts, %u matrices, %u block loads (%u KB), %u tile loads, %u palettes, %u state changes\n",
                    stats.vtx_loads, stats.vtx_count, stats.ctx_pushes, stats.matrices, stats.block_loads, stats.block_bytes / 1024, stats.tile_loads, stats.tlut_loads, stats.prepares);
            }
            if (dl_count < 5 || dl_count % 60 == 0) {
                std::fprintf(stderr, "[renderer] display list #%u: %u tris (+%u clipped, %u culled, %u without fb), %u rects, %u fills, %u draws, %u verts, cimg 0x%06X w%u\n",
                    dl_count, stats.tris, stats.tris_clipped, stats.tris_culled, stats.tris_nofb, stats.rects, stats.fills, stats.draws, stats.verts, cimg.addr, cimg.width);
            }
            if (debug_flags & 512) {
                std::fprintf(stderr, "[water] dl %u: %u tris (%u clipped, %u culled) sum %.3f; all %u tris\n", dl_count,
                    water_stats.tris, water_stats.clipped, water_stats.culled, water_stats.sum, stats.tris);
                water_stats = {};
            }
            if (debug_flags & 256) {
                // Debug: the GPU finishes each display list before the next starts.
                enqueue([](Backend& b, CommandList&) { b.debug_finish(); });
            }
            stats = {};
            dl_count++;
        }

        void send_dummy_workload(uint32_t) override {}

        void update_screen() override {
            g_front_stage = 2;
            struct StageEnd { ~StageEnd() { g_front_stage = 0; } } stage_end;
            struct TraceScope { TraceScope() { ultramodern_trace("update_screen", 0); } ~TraceScope() { ultramodern_trace("update_screen end", 0); } } trace_scope;
            flush();
            // An in-between frame was shown at the last VI: the game's own now.
            if (real_pending) {
                real_pending = false;
                const uint32_t o = ultramodern::renderer::get_vi_regs()->VI_ORIGIN_REG & 0x00FFFFFF;
                if (o == last_origin) {
                    present();
                    return;
                }
            }
            // Only when there's something new to show: the VI asks every 1/60s, the game
            // draws at 20-30 frames a second.
            // When the VI shows another image (the game swapped buffers). A game drawing
            // into the image shown (no swaps) gets it presented after a few VIs.
            const uint32_t origin = ultramodern::renderer::get_vi_regs()->VI_ORIGIN_REG & 0x00FFFFFF;
            if (origin == last_origin) {
                if (dl_count == last_presented_dl || ++same_origin_vis < 3) {
                    return;
                }
            }
            present_fallback = origin == last_origin;
            same_origin_vis = 0;
            last_origin = origin;
            last_presented_dl = dl_count;
            // An interpolated list's frames went to the display as it was read (both).
            if (!present_fallback) {
                Framebuffer* shown = framebuffer_at(origin);
                if (shown != nullptr && shown->list_presented) {
                    shown->list_presented = false;
                    return;
                }
            }
            present();
        }
        uint32_t same_origin_vis = 0;
        uint32_t capture_index = 0, capture_left = 0; // "Capture 5 seconds": its number, presents to go
        bool present_fallback = false;
        uint32_t last_origin = ~0u;
        uint32_t last_presented_dl = ~0u;

        void shutdown() override {
            flush();
            submit();
            backend->wait_idle();
        }

        uint32_t get_display_framerate() const override { return 60; }
        float get_resolution_scale() const override { return (float)render_scale; }

    private:
        uint8_t* rdram;      // where RDRAM is read: the game's, or the copy of the list being read
        uint8_t* game_rdram; // the game's own (written back to)
        bool ok = false;
        uint32_t dl_count = 0;
        struct {
            uint32_t programs = 0, program_us = 0, textures = 0, texture_us = 0, flush_us = 0;
            uint32_t ctx_pushes = 0, vtx_loads = 0, vtx_count = 0, block_loads = 0, block_bytes = 0, tlut_loads = 0, tile_loads = 0, matrices = 0, prepares = 0;
            uint32_t tris = 0, tris_clipped = 0, tris_culled = 0, tris_nofb = 0, rects = 0, fills = 0, draws = 0, verts = 0;
        } stats;
        uint32_t present_count = 1;

        // -------------------------------------------------------- RSP state
        uint32_t segments[16] = {};
        Mat4 modelview[max_matrix_depth];
        int modelview_depth = 0;
        Mat4 projection = identity();
        Mat4 mvp = identity();
        bool mvp_dirty = true;
        bool vctx_dirty = true; // the vertex context (vctx) needs working out again
        float vscale[3] = {160, 120, 511}, vtrans[3] = {160, 120, 511};
        uint32_t geometry_mode = 0;
        struct {
            bool on = false;
            uint32_t tile = 0, level = 0;
            float scale_s = 1, scale_t = 1;
        } texture;
        int16_t fog_mul = 0, fog_offset = 0;
        RspVertex vertices[max_vertices];
        uint32_t rdp_half1 = 0, rdp_half2 = 0;

        // Conker's microcode.
        bool cbfd_lighting = false, cbfd_texgen = false, cbfd_texgen_linear = false;
        bool cbfd_advanced_lighting = false;
        uint32_t cbfd_normal_base = 0;
        uint32_t cbfd_light_count = 0;
        std::array<CbfdLight, 12> cbfd_lights{};
        float cbfd_coord_mod[20] = {};
        float lookat[2][3] = {{1, 0, 0}, {0, 1, 0}};

        // -------------------------------------------------------- RDP state
        Tmem tmem{};
        Tile tiles[8];
        TextureImage timg{};
        struct {
            uint32_t addr = 0, fmt = 0, siz = SIZ_16b, width = 320;
        } cimg;
        uint32_t zimg_addr = 0;
        uint32_t other_mode_h = 0, other_mode_l = 0;
        uint32_t combine_w0 = 0, combine_w1 = 0;
        uint32_t prim_color = 0, env_color = 0, fog_color = 0, blend_color = 0, fill_color = 0;
        uint32_t prim_lod_frac = 0;
        // gDPSetConvert's K4 and K5 (signed 9-bit), which the combiner can read.
        int32_t convert_k4 = 0, convert_k5 = 0;
        uint16_t prim_depth = 0;
        uint32_t scissor_ulx = 0, scissor_uly = 0, scissor_lrx = 320 * 4, scissor_lry = 240 * 4;

        // -------------------------------------------------------- GL state
        std::unordered_map<uint32_t, Framebuffer> framebuffers;
        Framebuffer* current_fb = nullptr;
        std::unordered_map<ShaderKey, Program, ShaderKeyHash> programs;
        TextureCache texture_cache;
        TileTexture tile_textures[8];
        const uint32_t white_tex = TEX_WHITE;

        // The GL thread, the command list being recorded, and the ids of GL objects.
        std::unique_ptr<Backend> backend;
        std::unique_ptr<CommandList> list;
        uint32_t next_tex_id = TEX_FIRST_FREE, next_fbo_id = 1, next_program_id = 1;
        std::vector<uint32_t> free_tex_ids;

        template <typename F>
        void enqueue(F&& f) {
            list->cmds.emplace_back(std::forward<F>(f));
        }

        void submit() {
            if (list->cmds.empty()) return;
            // The vertices still to finish refer to this list's contexts.
            finish_pending_vertices();
            vctx_index = -1;
            uv_index = -1;
            vertex_cache_serial++;
            list->verts_used = batch.n;
            list->idx_used = batch.ni;
            backend->submit(std::move(list));
            list = backend->take_list();
            list->debug_flags = debug_flags;
            list->serial = ++list_serial;
            batch.attach(list.get());
            // The loaded vertices were the old list's.
            std::fill(std::begin(slot_src), std::end(slot_src), ~0u);
            slot_xformed = 0;
            xform_index = -1;
            tri_base = 0;
            batch_deferred = false;
        }

        uint32_t new_tex_id() {
            if (!free_tex_ids.empty()) {
                const uint32_t id = free_tex_ids.back();
                free_tex_ids.pop_back();
                return id;
            }
            return next_tex_id++;
        }

        // The vertices of the triangles waiting to be drawn, written in place in the
        // command list's arrays (a vector's push_back costs a check and a copy a vertex).
        // Drawn indexed: a vertex the triangles of a batch share goes to GL once. Indices
        // count from the batch's first vertex.
        struct VertexBatch {
            CommandList* l = nullptr;
            size_t n = 0, ni = 0;          // used in the list
            size_t base = 0, ibase = 0;    // where this batch starts
            void attach(CommandList* list) { l = list; n = ni = base = ibase = 0; }
            GLVertex* grow(size_t k) {
                if (n + k > l->verts.size()) l->verts.resize(std::max(l->verts.size() * 2, n + k));
                GLVertex* p = &l->verts[n];
                n += k;
                return p;
            }
            // A triangle's vertex: the GL vertex at the same place is made by the GL thread.
            VertexIn* grow_in(size_t k) {
                if (n + k > l->verts.size()) l->verts.resize(std::max(l->verts.size() * 2, n + k));
                if (n + k > l->vin.size()) l->vin.resize(std::max(l->vin.size() * 2, n + k));
                VertexIn* p = &l->vin[n];
                // The lines a few vertices on, before they're written (the list's arrays are larger
                // than the caches: each new line waited for the memory).
                if (n + k + 8 <= l->vin.size()) __builtin_prefetch(p + 8, 1);
                n += k;
                return p;
            }
            uint16_t* grow_indices(size_t k) {
                if (ni + k > l->idx.size()) l->idx.resize(std::max(l->idx.size() * 2, ni + k));
                uint16_t* p = &l->idx[ni];
                ni += k;
                return p;
            }
            size_t size() const { return n - base; }
            size_t index_count() const { return ni - ibase; }
            bool empty() const { return ni == ibase; }
            void clear() { n = base; ni = ibase; }
            void next() { base = n; ibase = ni; }
            GLVertex& operator[](size_t i) { return l->verts[base + i]; }
        } batch;
        // Where each RSP vertex went in the batch, while vertex_cache_serial is the same:
        // it changes with the batch and with anything that changes what a vertex becomes.
        uint16_t slot_index[max_vertices] = {};
        uint32_t slot_serial[max_vertices] = {};
        uint32_t vertex_cache_serial = 1;
        DrawState batch_state;
        bool state_dirty = true;
        DrawState pending_state;

        // ======================================================== addresses
        // Debug (flag 2048): what the list read, by 64-byte granule (1 list, 2 vertices,
        // 4 matrices, 8 movemem), to match against what the game wrote meanwhile.
        std::vector<uint8_t> read_mark;
        bool watching = false;
        // Debug: the highest addresses the list read above 8 MB, by kind (flag 2048's run).
        uint32_t high_read_max[16] = {}, high_read_min[16] = {};
        inline void mark_read(uint32_t addr, uint32_t bytes, uint8_t kind) {
            if (__builtin_expect(!watching, 1)) return;
            addr &= 0x7FFFFF;
            for (uint32_t g = addr >> 6; g <= ((addr + bytes - 1) >> 6) && g < read_mark.size(); g++) read_mark[g] |= kind;
        }

        // RDRAM as the list reads it: from the capture's copy of a page when there is one.
        const uint8_t* const* cap_pt = nullptr;
        inline const uint8_t* mem(uint32_t addr) const {
            if (cap_pt != nullptr) {
                const uint8_t* b = cap_pt[(addr & rdram_mask) >> capture::page_shift];
                if (b != nullptr) return b;
            }
            return rdram;
        }
        uint32_t m32(uint32_t a) const { return read32(mem(a), a); }
        uint16_t m16(uint32_t a) const { return read16(mem(a), a); }
        uint8_t m8(uint32_t a) const { return read8(mem(a), a); }

        // Where the list's reading goes, timed in one display list in 30 (the clock costs too much
        // to read in every one): vertices, triangles, texture loads, the tiles' textures, the rest.
        enum Part { P_VTX, P_TRI, P_LOAD, P_TILE, P_MTX, P_FLUSH, P_COUNT };
        bool profiling = false;
        uint32_t op_hist[256] = {};
        // Debug (ux0:data/conker/debug_cmdtime): in the timed lists (one in 30 then), the time
        // from each command to the next, by command (G_DL's and the branches' callees count apart),
        // less the clock's own cost (worked out once).
        const bool cmd_timing = [] {
            FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_cmdtime", "r");
            if (f) std::fclose(f);
            return f != nullptr;
        }();
        std::vector<uint64_t> seen_loads; // the timed lists' distinct texture loads
        uint32_t loads_in_list = 0;
        uint64_t op_us[256] = {};
        uint32_t op_n[256] = {};
        int last_op = -1;
        uint64_t last_op_t = 0;
        double clock_us = -1.0;
        uint64_t part_us[P_COUNT] = {}, part_total_us = 0, part_lists = 0;
        struct PartTimer {
            VitaRenderer& r; Part p; uint64_t t0;
            PartTimer(VitaRenderer& r, Part p) : r(r), p(p), t0(r.profiling ? sceKernelGetProcessTimeWide() : 0) {}
            ~PartTimer() { if (r.profiling) r.part_us[p] += sceKernelGetProcessTimeWide() - t0; }
        };

        uint32_t segmented(uint32_t addr) const {
            return (segments[(addr >> 24) & 0xF] + (addr & 0x00FFFFFF)) & 0x00FFFFFF;
        }

        void reset_rsp() {
            modelview[0] = identity();
            modelview_depth = 0;
            projection = identity();
            mvp_dirty = true;
            for (Tile& t : tiles) t = Tile{};
        }

        // ======================================================== display list
        void run_display_list(uint32_t start) {
            uint32_t stack[max_dl_depth];
            int depth = 0;
            uint32_t pc = start & rdram_mask;
            // A runaway list (bad pointer) stops after this many commands.
            // What changes how vertices are lit or textured: the next vertex load works the
            // context out again (otherwise loads in a row share it), and the pending ones are
            // finished with the context they had.
            static constexpr auto context_ops = [] {
                std::array<bool, 256> t{};
                for (uint8_t op : { G_MTX, G_POPMTX, G_MOVEWORD, G_MOVEMEM, G_GEOMETRYMODE, G_TEXTURE, G_LOAD_UCODE, G_RT64_EXTENDED }) {
                    t[op] = true;
                }
                return t;
            }();
            // The page the commands are read from, looked up again only when they leave it.
            uint32_t cmd_page = ~0u;
            const uint8_t* cmd_mem = nullptr;
            for (uint32_t guard = 0; guard < 2000000; guard++) {
                if ((pc >> capture::page_shift) != cmd_page) {
                    cmd_page = pc >> capture::page_shift;
                    cmd_mem = mem(pc);
                }
                // The list's next lines asked for ahead (past the page it's harmless: a prefetch
                // never faults).
                __builtin_prefetch(cmd_mem + ((pc + 256) & rdram_mask));
                const uint32_t w0 = read32(cmd_mem, pc); // the command's 8 bytes are in one page
                const uint32_t w1 = read32(cmd_mem, pc + 4);
                mark_read(pc, 8, 1);
                pc += 8;
                const uint8_t op = w0 >> 24;
                if (__builtin_expect(profiling, 0)) {
                    op_hist[op]++;
                    if (cmd_timing) {
                        const uint64_t now = sceKernelGetProcessTimeWide();
                        if (last_op >= 0) { op_us[last_op] += now - last_op_t; op_n[last_op]++; }
                        last_op = op;
                        last_op_t = now;
                    }
                }
                if (context_ops[op]) {
                    vctx_dirty = true;
                    if (pending_vertices) {
                        pin_vertex_context();
                    }
                }
                else if (op == G_MODIFYVTX && pending_vertices) {
                    finish_pending_vertices();
                }
                switch (op) {
                    case 0x00: break; // G_NOOP
                    case G_VTX: {
                        const uint32_t count = (w0 >> 12) & 0xFF;
                        const int32_t dst = (int32_t)((w0 >> 1) & 0x7F) - (int32_t)count;
                        mark_read(segmented(w1), count * 16, 2);
                        load_vertices(segmented(w1), count, dst);
                        break;
                    }
                    case G_MODIFYVTX:
                        if (deferred_geometry) modify_deferred(w0, w1);
                        else modify_vertex(w0, w1);
                        break;
                    case G_CULLDL:
                        if (dumping()) std::fprintf(stderr, "[culldl] pc 0x%06X v%u-%u cull=%d\n", (pc - 8) & rdram_mask, (w0 & 0xFFFF) / 2, (w1 & 0xFFFF) / 2, (int)cull_dl((w0 & 0xFFFF) / 2, (w1 & 0xFFFF) / 2));
                        if (cull_dl((w0 & 0xFFFF) / 2, (w1 & 0xFFFF) / 2)) {
                            if (depth == 0) return;
                            pc = stack[--depth];
                        }
                        break;
                    case G_BRANCH_Z: {
                        // Branches when the vertex is nearer than the value (in screen depth,
                        // 0-1023, as 16.16) or behind the camera (as RT64 does).
                        const uint32_t vtx = ((w0 >> 1) & 0x7FF) % max_vertices;
                        if (deferred_geometry) xform_slot(vtx);
                        const RspVertex& v = vertices[vtx];
                        bool take = v.w <= 0.0f;
                        if (!take) {
                            const float screen_z = (v.z / v.w + 1.0f) * 0.5f * 1023.0f;
                            take = screen_z < (float)w1 / 65536.0f;
                        }
                        if (dumping()) std::fprintf(stderr, "[branchz] pc 0x%06X w0 %08X w1 %08X -> 0x%06X v%u take=%d\n", (pc - 8) & rdram_mask, w0, w1, segmented(rdp_half1) & rdram_mask, vtx, (int)take);
                        if (take) {
                            pc = segmented(rdp_half1) & rdram_mask;
                        }
                        break;
                    }
                    case G_TRI1:
                        triangle(((w0 >> 16) & 0xFF) / 2, ((w0 >> 8) & 0xFF) / 2, (w0 & 0xFF) / 2);
                        break;
                    case G_TRI2:
                    case G_QUAD:
                        triangle(((w0 >> 16) & 0xFF) / 2, ((w0 >> 8) & 0xFF) / 2, (w0 & 0xFF) / 2);
                        triangle(((w1 >> 16) & 0xFF) / 2, ((w1 >> 8) & 0xFF) / 2, (w1 & 0xFF) / 2);
                        break;
                    case G_RT64_EXTENDED:
                        pc = extended_command(w0, w1, pc);
                        break;
                    case G_TEXTURE: {
                        texture.on = ((w0 >> 1) & 0x7F) != 0;
                        texture.tile = (w0 >> 8) & 0x7;
                        texture.level = (w0 >> 11) & 0x7;
                        texture.scale_s = (float)(w1 >> 16) / 65536.0f;
                        texture.scale_t = (float)(w1 & 0xFFFF) / 65536.0f;
                        state_dirty = true;
                        break;
                    }
                    case G_POPMTX: {
                        int count = (int)(w1 / 64);
                        modelview_depth = std::max(0, modelview_depth - count);
                        mvp_dirty = true;
                        break;
                    }
                    case G_GEOMETRYMODE: set_geometry_mode(w0, w1); break;
                    case G_MTX: load_matrix(w0, w1); break;
                    case G_MOVEWORD: move_word(w0, w1); break;
                    case G_MOVEMEM: move_mem(w0, w1); break;
                    case G_LOAD_UCODE:
                        // Conker's microcode reuses it to switch to its advanced lighting.
                        cbfd_advanced_lighting = true;
                        break;
                    case G_DL:
                        if (((w0 >> 16) & 0xFF) == 0) {
                            if (depth >= max_dl_depth) {
                                std::fprintf(stderr, "[renderer] display list stack overflow\n");
                                return;
                            }
                            stack[depth++] = pc;
                        }
                        pc = segmented(w1) & rdram_mask;
                        break;
                    case G_ENDDL:
                        if (depth == 0) return;
                        pc = stack[--depth];
                        break;
                    case G_SPNOOP: break; // also RT64's hooks
                    case G_RDPHALF_1: rdp_half1 = w1; break;
                    case G_RDPHALF_2: rdp_half2 = w1; break;
                    case G_SETOTHERMODE_L:
                    case G_SETOTHERMODE_H: {
                        const uint32_t len = (w0 & 0xFF) + 1;
                        const uint32_t shift = 32 - ((w0 >> 8) & 0xFF) - len;
                        const uint32_t mask = (len >= 32 ? 0xFFFFFFFFu : ((1u << len) - 1)) << shift;
                        uint32_t& mode = (op == G_SETOTHERMODE_L) ? other_mode_l : other_mode_h;
                        mode = (mode & ~mask) | (w1 & mask);
                        state_dirty = true;
                        break;
                    }
                    case G_TEXRECT:
                    case G_TEXRECTFLIP: {
                        // The coordinates follow in RDPHALF_1 and RDPHALF_2.
                        const uint32_t h1 = m32(pc + 4);
                        const uint32_t h2 = m32(pc + 12);
                        pc += 16;
                        const int32_t lrx = (w0 >> 12) & 0xFFF, lry = w0 & 0xFFF;
                        const int32_t ulx = (w1 >> 12) & 0xFFF, uly = w1 & 0xFFF;
                        texture_rectangle((w1 >> 24) & 7, ulx, uly, lrx, lry,
                            (int16_t)(h1 >> 16), (int16_t)(h1 & 0xFFFF), (int16_t)(h2 >> 16), (int16_t)(h2 & 0xFFFF),
                            op == G_TEXRECTFLIP);
                        break;
                    }
                    case 0xE6: case 0xE7: case 0xE8: case 0xE9: // syncs
                    case 0xEA: case 0xEB:                        // keys
                        break;
                    case 0xEC: { // G_SETCONVERT
                        auto sext9 = [](uint32_t v) { return (int32_t)((v & 0x1FF) ^ 0x100) - 0x100; };
                        convert_k4 = sext9(w1 >> 9);
                        convert_k5 = sext9(w1);
                        state_dirty = true;
                        break;
                    }
                    case G_SETSCISSOR:
                        scissor_ulx = (w0 >> 12) & 0xFFF;
                        scissor_uly = w0 & 0xFFF;
                        scissor_lrx = (w1 >> 12) & 0xFFF;
                        scissor_lry = w1 & 0xFFF;
                        state_dirty = true;
                        break;
                    case G_SETPRIMDEPTH: prim_depth = (uint16_t)(w1 >> 16); vertex_cache_serial++; break;
                    case G_RDPSETOTHERMODE:
                        other_mode_h = w0 & 0x00FFFFFF;
                        other_mode_l = w1;
                        state_dirty = true;
                        break;
                    case G_LOADTLUT: {
                        PartTimer part_timer(*this, P_LOAD);
                        const Tile& t = tiles[(w1 >> 24) & 7];
                        load_tlut(tmem, rdram, timg, t, (w0 >> 12) & 0xFFF, w0 & 0xFFF, (w1 >> 12) & 0xFFF, w1 & 0xFFF);
                        stats.tlut_loads++;
                        state_dirty = true;
                        break;
                    }
                    case G_SETTILESIZE: {
                        Tile& t = tiles[(w1 >> 24) & 7];
                        t.uls = (w0 >> 12) & 0xFFF;
                        t.ult = w0 & 0xFFF;
                        t.lrs = (w1 >> 12) & 0xFFF;
                        t.lrt = w1 & 0xFFF;
                        state_dirty = true;
                        break;
                    }
                    case G_LOADBLOCK: {
                        PartTimer part_timer(*this, P_LOAD);
                        if (__builtin_expect((debug_flags & 1048576) != 0, 0)) break; // debug: no texture loads
                        const Tile& t = tiles[(w1 >> 24) & 7];
                        load_block(tmem, rdram, timg, t, (w0 >> 12) & 0xFFF, w0 & 0xFFF, (w1 >> 12) & 0xFFF, w1 & 0xFFF);
                        if (__builtin_expect(profiling && cmd_timing, 0)) {
                            const uint64_t key = ((uint64_t)timg.addr << 32) ^ ((uint64_t)w0 << 7) ^ w1 ^ ((uint64_t)t.tmem << 50);
                            if (!std::count(seen_loads.begin(), seen_loads.end(), key)) seen_loads.push_back(key);
                            loads_in_list++;
                        }
                        stats.block_loads++;
                        stats.block_bytes += ((((w1 >> 12) & 0xFFF) - ((w0 >> 12) & 0xFFF) + 1) * (4u << timg.siz)) / 8;
                        note_tmem_load(t, (w0 >> 12) & 0xFFF, w0 & 0xFFF, true);
                        state_dirty = true;
                        break;
                    }
                    case G_LOADTILE: {
                        const Tile& t = tiles[(w1 >> 24) & 7];
                        load_tile(tmem, rdram, timg, t, (w0 >> 12) & 0xFFF, w0 & 0xFFF, (w1 >> 12) & 0xFFF, w1 & 0xFFF);
                        stats.tile_loads++;
                        note_tmem_load(t, (w0 >> 12) & 0xFFF, w0 & 0xFFF, false);
                        state_dirty = true;
                        break;
                    }
                    case G_SETTILE: {
                        Tile& t = tiles[(w1 >> 24) & 7];
                        t.fmt = (w0 >> 21) & 7;
                        t.siz = (w0 >> 19) & 3;
                        t.line = (w0 >> 9) & 0x1FF;
                        t.tmem = w0 & 0x1FF;
                        t.palette = (w1 >> 20) & 0xF;
                        t.cmt = (w1 >> 18) & 3;
                        t.maskt = (w1 >> 14) & 0xF;
                        t.shiftt = (w1 >> 10) & 0xF;
                        t.cms = (w1 >> 8) & 3;
                        t.masks = (w1 >> 4) & 0xF;
                        t.shifts = w1 & 0xF;
                        state_dirty = true;
                        break;
                    }
                    case G_FILLRECT: {
                        const int32_t lrx = (w0 >> 12) & 0xFFF, lry = w0 & 0xFFF;
                        const int32_t ulx = (w1 >> 12) & 0xFFF, uly = w1 & 0xFFF;
                        fill_rectangle(ulx, uly, lrx, lry);
                        break;
                    }
                    case G_SETFILLCOLOR: fill_color = w1; state_dirty = true; break;
                    case G_SETFOGCOLOR: fog_color = w1; state_dirty = true; break;
                    case G_SETBLENDCOLOR: blend_color = w1; state_dirty = true; break;
                    case G_SETPRIMCOLOR: prim_color = w1; prim_lod_frac = w0 & 0xFF; state_dirty = true; break;
                    case G_SETENVCOLOR: env_color = w1; state_dirty = true; break;
                    case G_SETCOMBINE: combine_w0 = w0 & 0x00FFFFFF; combine_w1 = w1; state_dirty = true; break;
                    case G_SETTIMG:
                        if (dumping()) std::fprintf(stderr, "[timg] addr 0x%06X fmt %u siz %u width %u\n", segmented(w1), (w0 >> 21) & 7, (w0 >> 19) & 3, (w0 & 0xFFF) + 1);
                        timg.fmt = (w0 >> 21) & 7;
                        timg.siz = (w0 >> 19) & 3;
                        timg.width = (w0 & 0xFFF) + 1;
                        timg.addr = segmented(w1);
                        break;
                    case G_SETZIMG: zimg_addr = segmented(w1); break;
                    case G_SETCIMG:
                        set_color_image((w0 >> 21) & 7, (w0 >> 19) & 3, (w0 & 0xFFF) + 1, segmented(w1));
                        break;
                    default:
                        if (op >= G_TRI4_FIRST && op <= G_TRI4_LAST) {
                            tri4(w0, w1);
                        }
                        break;
                }
            }
            std::fprintf(stderr, "[renderer] display list didn't end\n");
        }

        // RT64's extended commands the desktop build's hooks write. Returns the next pc.
        uint32_t extended_command(uint32_t w0, uint32_t w1, uint32_t pc) {
            switch (w0 & 0x00FFFFFF) {
                case G_EX_TEXRECT_V1: {
                    const uint32_t c1w0 = m32(pc), c1w1 = m32(pc + 4);
                    const uint32_t c2w0 = m32(pc + 8), c2w1 = m32(pc + 12);
                    texture_rectangle(w1 & 7,
                        (int16_t)(c1w0 >> 16), (int16_t)(c1w0 & 0xFFFF), (int16_t)(c1w1 >> 16), (int16_t)(c1w1 & 0xFFFF),
                        (int16_t)(c2w0 >> 16), (int16_t)(c2w0 & 0xFFFF), (int16_t)(c2w1 >> 16), (int16_t)(c2w1 & 0xFFFF), false);
                    return pc + 16;
                }
                case G_EX_FILLRECT_V1: {
                    const uint32_t c1w0 = m32(pc), c1w1 = m32(pc + 4);
                    fill_rectangle((int16_t)(c1w0 >> 16), (int16_t)(c1w0 & 0xFFFF), (int16_t)(c1w1 >> 16), (int16_t)(c1w1 & 0xFFFF));
                    return pc + 8;
                }
                case G_EX_MATRIXGROUP_V1:
                    // An object's commands: its matrices pair with its own last frame's.
                    if (group_depth < max_groups) {
                        group_ids[group_depth] = w1;
                        group_counts[group_depth] = 0;
                        group_loads[group_depth] = 0;
                    }
                    group_depth++;
                    return pc + 8;
                case 0x00000D: // G_EX_POPMATRIXGROUP_V1
                    group_depth = std::max(0, group_depth - (int)std::max<uint32_t>(w1, 1));
                    return pc;
                default:
                    // G_EX_POPMATRIXGROUP_V1, G_EX_SETRECTASPECT_V1 and others of one command.
                    return pc;
            }
        }

        // ======================================================== matrices
        Mat4 read_matrix(uint32_t addr) const {
            Mat4 r;
            if (addr & 3) {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        const uint32_t off = (uint32_t)(i * 8 + j * 2);
                        const int16_t hi = (int16_t)m16(addr + off);
                        const uint16_t lo = m16(addr + 32 + off);
                        r.m[i][j] = (float)(((int32_t)hi << 16) | lo) * (1.0f / 65536.0f);
                    }
                }
                return r;
            }
#if defined(__ARM_NEON)
            if ((addr & 0xFFF) <= 0xFC0) {
                // Its 64 bytes in one page: the integer halves (8 words, two elements each),
                // then the fractions, joined and converted as 16.16 fixed point, four at a time.
                const uint8_t* const b = mem(addr) + (addr & rdram_mask);
                for (int i = 0; i < 4; i++) {
                    const uint32x2_t hi = vld1_u32(reinterpret_cast<const uint32_t*>(b + i * 8));
                    const uint32x2_t lo = vld1_u32(reinterpret_cast<const uint32_t*>(b + 32 + i * 8));
                    // Element 2k: hi's high half and lo's high half; element 2k+1: the low halves.
                    const uint32x2_t even = vorr_u32(vand_u32(hi, vdup_n_u32(0xFFFF0000u)), vshr_n_u32(lo, 16));
                    const uint32x2_t odd = vorr_u32(vshl_n_u32(hi, 16), vand_u32(lo, vdup_n_u32(0xFFFFu)));
                    const uint32x2x2_t z = vzip_u32(even, odd);
                    const int32x4_t fixed = vreinterpretq_s32_u32(vcombine_u32(z.val[0], z.val[1]));
                    vst1q_f32(r.m[i], vcvtq_n_f32_s32(fixed, 16));
                }
                return r;
            }
#endif
            // Two elements a word: the integer halves, then the fractions.
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j += 2) {
                    const uint32_t off = (uint32_t)(i * 8 + j * 2);
                    const uint32_t hi = m32(addr + off);
                    const uint32_t lo = m32(addr + 32 + off);
                    r.m[i][j] = (float)(int32_t)((hi & 0xFFFF0000u) | (lo >> 16)) * (1.0f / 65536.0f);
                    r.m[i][j + 1] = (float)(int32_t)((hi << 16) | (lo & 0xFFFFu)) * (1.0f / 65536.0f);
                }
            }
            return r;
        }

        // ======================================================== frame interpolation
        // A frame drawn between each two of the game's (30 a second, the VI 60): the list just
        // read is read again with each matrix halfway from its last frame's, and that frame
        // shown at the VI the game shows its own, its own a VI later (vita_interpolation, the
        // menu's "Frame rate"). Matrices pair by the object they're drawn for (the matrix
        // groups host/src/interpolation.cpp puts around each object) and their order in it;
        // the rest (the camera's) by their order in the list. A matrix far from its pair (a cut,
        // a teleport) isn't moved. Only where there's time for it: a list read in under
        // interp_budget_us (the second reading takes as long; the Vita's busiest scenes don't
        // have it), and not for lists the CPU reads back from.
        bool interp_pass = false;
        float interp_t = 0.5f;
        static constexpr uint32_t interp_budget_us = 12000;
        static constexpr int max_groups = 16;
        uint32_t group_ids[max_groups] = {}, group_counts[max_groups] = {}, group_loads[max_groups] = {};
        int group_depth = 0;
        uint32_t loose_count = 0;
        struct MtxSlot { uint64_t key; uint32_t stamp; uint32_t index; };
        static constexpr uint32_t mtx_slots = 8192;
        std::vector<MtxSlot> mtx_table[2] = { std::vector<MtxSlot>(mtx_slots, MtxSlot{ 0, 0, 0 }),
                                              std::vector<MtxSlot>(mtx_slots, MtxSlot{ 0, 0, 0 }) };
        std::vector<Mat4> mtx_values[2];
        uint32_t mtx_stamp[2] = { 1, 1 };
        int mtx_cur = 0; // this list's; the other holds the last list's
        // An object's vertex loads (the game bends its joints on the CPU), paired the same way:
        // the n-th load in the object, the same count. Positions as loaded (model space).
        struct VtxSlot { uint64_t key; uint32_t stamp; uint32_t offset, count; };
        static constexpr uint32_t vtx_slots = 8192;
        std::vector<VtxSlot> vtx_table[2] = { std::vector<VtxSlot>(vtx_slots, VtxSlot{ 0, 0, 0, 0 }),
                                              std::vector<VtxSlot>(vtx_slots, VtxSlot{ 0, 0, 0, 0 }) };
        std::vector<int16_t> vtx_pos[2]; // x, y, z each
        uint32_t interp_vtx_moved = 0, interp_vtx_kept = 0;
        // The key of a load in an object (0: not in one).
        uint64_t vertex_load_key(uint32_t count) {
            if (group_depth <= 0) return 0;
            const int d = std::min(group_depth, max_groups) - 1;
            return ((uint64_t)group_ids[d] << 32) | ((uint64_t)(group_loads[d]++) << 8) | (count & 0xFF) | (1ull << 31);
        }
        // Records a load's positions (the real reading) or moves them halfway from the last
        // frame's (the in-between one).
        void interpolate_vertices(uint64_t key, SrcVertex* v, uint32_t count) {
            if (key == 0 || count == 0) return;
            const uint32_t slot0 = (uint32_t)((key * 0x9E3779B97F4A7C15ull) >> 51) & (vtx_slots - 1);
            if (!interp_pass) {
                const int c = mtx_cur;
                for (uint32_t n = 0, i = slot0; n < vtx_slots; n++, i = (i + 1) & (vtx_slots - 1)) {
                    VtxSlot& slot = vtx_table[c][i];
                    if (slot.stamp != mtx_stamp[c] || slot.key == key) {
                        slot.key = key;
                        slot.stamp = mtx_stamp[c];
                        slot.offset = (uint32_t)vtx_pos[c].size();
                        slot.count = count;
                        for (uint32_t k = 0; k < count; k++) {
                            vtx_pos[c].push_back(v[k].x);
                            vtx_pos[c].push_back(v[k].y);
                            vtx_pos[c].push_back(v[k].z);
                        }
                        return;
                    }
                }
                return;
            }
            const int p = mtx_cur ^ 1;
            for (uint32_t n = 0, i = slot0; n < vtx_slots; n++, i = (i + 1) & (vtx_slots - 1)) {
                const VtxSlot& slot = vtx_table[p][i];
                if (slot.stamp != mtx_stamp[p]) return;
                if (slot.key != key) continue;
                if (slot.count != count) return;
                const int16_t* last = &vtx_pos[p][slot.offset];
                // A load whose vertices jumped (another shape in the same place) is left.
                for (uint32_t k = 0; k < count * 3; k++) {
                    const int16_t cur = k % 3 == 0 ? v[k / 3].x : k % 3 == 1 ? v[k / 3].y : v[k / 3].z;
                    if (std::abs((int)cur - (int)last[k]) > 2048) {
                        interp_vtx_kept++;
                        return;
                    }
                }
                for (uint32_t k = 0; k < count; k++) {
                    v[k].x = (int16_t)(last[k * 3 + 0] + (int)std::lround((v[k].x - last[k * 3 + 0]) * interp_t));
                    v[k].y = (int16_t)(last[k * 3 + 1] + (int)std::lround((v[k].y - last[k * 3 + 1]) * interp_t));
                    v[k].z = (int16_t)(last[k * 3 + 2] + (int)std::lround((v[k].z - last[k * 3 + 2]) * interp_t));
                }
                interp_vtx_moved++;
                return;
            }
        }
        Framebuffer* interp_main = nullptr; // the screen the last list drew
        uint32_t last_list_us = ~0u;
        bool real_pending = false;
        uint32_t interp_frames = 0, interp_lerped = 0, interp_jumped = 0, interp_skipped = 0;

        uint64_t matrix_key(uint32_t params) {
            if (group_depth > 0) {
                const int d = std::min(group_depth, max_groups) - 1;
                return ((uint64_t)group_ids[d] << 32) | ((uint64_t)(group_counts[d]++) << 4) | params;
            }
            return (0xFFFFFFFFull << 32) | ((uint64_t)(loose_count++) << 4) | params;
        }
        static uint32_t mtx_slot(uint64_t key) { return (uint32_t)((key * 0x9E3779B97F4A7C15ull) >> 51) & (mtx_slots - 1); }
        void record_matrix(uint64_t key, const Mat4& m) {
            std::vector<MtxSlot>& t = mtx_table[mtx_cur];
            for (uint32_t n = 0, i = mtx_slot(key); n < mtx_slots; n++, i = (i + 1) & (mtx_slots - 1)) {
                MtxSlot& slot = t[i];
                if (slot.stamp != mtx_stamp[mtx_cur] || slot.key == key) {
                    slot.key = key;
                    slot.stamp = mtx_stamp[mtx_cur];
                    slot.index = (uint32_t)mtx_values[mtx_cur].size();
                    mtx_values[mtx_cur].push_back(m);
                    return;
                }
            }
        }
        const Mat4* last_matrix(uint64_t key) const {
            const int p = mtx_cur ^ 1;
            const std::vector<MtxSlot>& t = mtx_table[p];
            for (uint32_t n = 0, i = mtx_slot(key); n < mtx_slots; n++, i = (i + 1) & (mtx_slots - 1)) {
                const MtxSlot& slot = t[i];
                if (slot.stamp != mtx_stamp[p]) return nullptr;
                if (slot.key == key) return &mtx_values[p][slot.index];
            }
            return nullptr;
        }
        // Near enough to move between: the rotation and scale rows within a fraction of
        // their size, the translation within a step (a camera cut or a teleport is not).
        static bool matrices_close(const Mat4& a, const Mat4& b) {
            float big = 1e-3f, diff = 0.0f;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    big = std::max(big, std::fabs(b.m[i][j]));
                    diff = std::max(diff, std::fabs(a.m[i][j] - b.m[i][j]));
                }
            }
            if (diff > 0.6f * big) return false;
            float t = 0.0f, d = 0.0f;
            for (int j = 0; j < 3; j++) {
                t += std::fabs(a.m[3][j]) + std::fabs(b.m[3][j]);
                d += std::fabs(a.m[3][j] - b.m[3][j]);
            }
            return d <= 0.35f * t + 64.0f;
        }
        void start_matrices(bool real) {
            group_depth = 0;
            loose_count = 0;
            if (real) {
                mtx_cur ^= 1;
                mtx_stamp[mtx_cur]++;
                mtx_values[mtx_cur].clear();
                vtx_pos[mtx_cur].clear();
            }
        }

    public:
        // The in-between frame for the list just read (the gfx thread, the list's capture held).
        void interp_dl(const OSTask* task) {
            Framebuffer* fb = interp_main;
            if (!conker::vita_interpolation() || fb == nullptr || mtx_values[mtx_cur ^ 1].empty() ||
                last_list_us > interp_budget_us || conker::vita::menu::is_open()) {
                if (fb != nullptr && conker::vita_interpolation()) interp_skipped++;
                return;
            }
            const int cap = ultramodern_vita_current_capture;
            cap_pt = cap >= 0 ? capture::slots[cap].pt : nullptr;
            struct CapEnd { const uint8_t* const*& p; ~CapEnd() { p = nullptr; } } cap_end{ cap_pt };
            ultramodern_trace("interp", 0);
            if (fb->real_tex == 0) {
                fb->real_tex = new_tex_id();
                fb->real_fbo = next_fbo_id++;
            }
            enqueue([src = fb->tex, fbo = fb->real_fbo, tex = fb->real_tex, w = fb->gl_width, h = fb->height](Backend& b, CommandList&) {
                b.copy_texture(src, fbo, tex, w, h);
            });
            interp_pass = true;
            start_matrices(false);
            cbfd_advanced_lighting = false;
            vctx_dirty = true;
            profiling = false;
            list->debug_flags = debug_flags;
            run_display_list((uint32_t)task->t.data_ptr & 0x1FFFFFFF);
            flush();
            for (auto& [base, f] : framebuffers) f.drawn_this_dl = false;
            submit();
            interp_pass = false;
            fb->interp_ready = true;
            fb->showing_real = false;
            stats = {};
            // Both frames to the display now, in turn: the display shows each for a VI (gxm
            // display_callback waits for one). Presented at the VIs instead, they went late
            // whenever this thread was still reading at one (the frame rate swaying round 60
            // showed as a judder).
            present(fb);
            present(fb);
            real_pending = false;
            fb->list_presented = true;
            if (++interp_frames % 300 == 0) {
                std::fprintf(stderr, "[interp] %u frames: matrices moved %u, left (far) %u; vertex loads moved %u, left %u; lists without one %u\n",
                    interp_frames, interp_lerped, interp_jumped, interp_vtx_moved, interp_vtx_kept, interp_skipped);
                interp_lerped = interp_jumped = interp_skipped = interp_vtx_moved = interp_vtx_kept = 0;
            }
        }
    private:

        void load_matrix(uint32_t w0, uint32_t w1) {
            PartTimer part_timer(*this, P_MTX);
            const uint32_t params = (w0 & 0xFF) ^ 1; // F3DEX2 inverts G_MTX_PUSH
            const bool push = params & 1, load = params & 2, proj = params & 4;
            mark_read(segmented(w1), 64, 4);
            Mat4 m = read_matrix(segmented(w1));
            stats.matrices++;
            const uint64_t key = matrix_key(params & 7);
            if (interp_pass) {
                if (const Mat4* last = last_matrix(key)) {
                    if (matrices_close(*last, m)) {
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 4; j++) m.m[i][j] = last->m[i][j] + (m.m[i][j] - last->m[i][j]) * interp_t;
                        }
                        interp_lerped++;
                    }
                    else {
                        interp_jumped++;
                    }
                }
            }
            else {
                record_matrix(key, m);
            }
            if (proj) {
                projection = load ? m : mul(m, projection);
            }
            else {
                if (push && modelview_depth < max_matrix_depth - 1) {
                    modelview[modelview_depth + 1] = modelview[modelview_depth];
                    modelview_depth++;
                }
                modelview[modelview_depth] = load ? m : mul(m, modelview[modelview_depth]);
            }
            mvp_dirty = true;
        }

        uint32_t mvp_serial = 0; // bumped when mvp is worked out again
        const Mat4& current_mvp() {
            if (mvp_dirty) {
                mvp = mul(modelview[modelview_depth], projection);
                mvp_dirty = false;
                mvp_serial++;
            }
            return mvp;
        }

        // ======================================================== words and memory
        void move_word(uint32_t w0, uint32_t w1) {
            const uint32_t index = (w0 >> 16) & 0xFF;
            const uint32_t offset = w0 & 0xFFFF;
            switch (index) {
                case G_MW_NUMLIGHT:
                    cbfd_light_count = w1 / 48;
                    break;
                case G_MW_SEGMENT:
                    segments[(offset / 4) & 0xF] = w1 & 0x00FFFFFF;
                    break;
                case G_MW_FOG:
                    fog_mul = (int16_t)(w1 >> 16);
                    fog_offset = (int16_t)(w1 & 0xFFFF);
                    break;
                case G_MW_COORD_MOD_CBFD:
                    set_coord_mod(w0, w1);
                    break;
                default:
                    break;
            }
        }

        void move_mem(uint32_t w0, uint32_t w1) {
            const uint32_t index = w0 & 0xFF;
            const uint32_t addr = segmented(w1);
            mark_read(addr, ((w0 >> 16) & 0xFF) / 8 * 8 + 8, 8);
            switch (index) {
                case G_MV_VIEWPORT:
                    // x and y are in 10.2; z isn't.
                    for (int i = 0; i < 3; i++) {
                        const float div = i < 2 ? 4.0f : 1.0f;
                        vscale[i] = (float)(int16_t)m16(addr + i * 2) / div;
                        vtrans[i] = (float)(int16_t)m16(addr + 8 + i * 2) / div;
                    }
                    break;
                case G_MV_LIGHT: {
                    const uint32_t offset = (w0 >> 5) & 0x3FFF;
                    const uint32_t n = offset / 48;
                    if (n < 2) {
                        set_lookat(n, addr);
                    }
                    else {
                        set_cbfd_light(n - 2, addr);
                    }
                    break;
                }
                case G_MV_NORMALES_CBFD:
                    cbfd_normal_base = addr;
                    break;
                default:
                    break;
            }
        }

        void set_lookat(uint32_t n, uint32_t addr) {
            float x = (float)(int8_t)m8(addr + 8);
            float y = (float)(int8_t)m8(addr + 9);
            float z = (float)(int8_t)m8(addr + 10);
            float len = std::sqrt(x * x + y * y + z * z);
            if (len > 0.0f) {
                x /= len; y /= len; z /= len;
            }
            lookat[n][0] = x;
            lookat[n][1] = y;
            lookat[n][2] = z;
        }

        void set_cbfd_light(uint32_t index, uint32_t addr) {
            if (index >= cbfd_lights.size()) {
                return;
            }
            CbfdLight& l = cbfd_lights[index];
            l.r = m8(addr + 0) / 255.0f;
            l.g = m8(addr + 1) / 255.0f;
            l.b = m8(addr + 2) / 255.0f;
            float dx = (float)(int8_t)m8(addr + 8);
            float dy = (float)(int8_t)m8(addr + 9);
            float dz = (float)(int8_t)m8(addr + 10);
            float len = std::sqrt(dx * dx + dy * dy + dz * dz);
            if (len > 0.0f) {
                dx /= len; dy /= len; dz /= len;
            }
            l.dir[0] = dx; l.dir[1] = dy; l.dir[2] = dz;
            l.pos[0] = (float)(int16_t)m16(addr + 32);
            l.pos[1] = (float)(int16_t)m16(addr + 34);
            l.pos[2] = (float)(int16_t)m16(addr + 36);
            l.ca = m8(addr + 12) / 16.0f;
        }

        void set_coord_mod(uint32_t w0, uint32_t w1) {
            if ((w0 & 8) != 0) {
                return;
            }
            const uint32_t idx = (w0 >> 1) & 3;
            const uint32_t pos = w0 & 0x30;
            float* mod = cbfd_coord_mod;
            if (pos == 0x00) {
                mod[0 + idx] = (float)(int16_t)(w1 >> 16);
                mod[1 + idx] = (float)(int16_t)(w1 & 0xFFFF);
            }
            else if (pos == 0x10) {
                mod[4 + idx] = (float)(w1 >> 16) / 65536.0f;
                mod[5 + idx] = (float)(w1 & 0xFFFF) / 65536.0f;
                mod[12 + idx] = mod[0 + idx] + mod[4 + idx];
                mod[13 + idx] = mod[1 + idx] + mod[5 + idx];
            }
            else if (pos == 0x20) {
                mod[8 + idx] = (float)(int16_t)(w1 >> 16);
                mod[9 + idx] = (float)(int16_t)(w1 & 0xFFFF);
            }
        }

        // Conker's: G_LIGHTING and G_TEXTURE_GEN are kept aside, as RT64 does.
        void set_geometry_mode(uint32_t w0, uint32_t w1) {
            const uint32_t off_mask = w0 & 0x00FFFFFF;
            const uint32_t previous = geometry_mode | (cbfd_lighting ? G_LIGHTING : 0) |
                (cbfd_texgen ? G_TEXTURE_GEN : 0) | (cbfd_texgen_linear ? G_TEXTURE_GEN_LINEAR : 0);
            const uint32_t requested = (previous & off_mask) | w1;
            cbfd_lighting = (requested & G_LIGHTING) != 0;
            cbfd_texgen = (requested & G_TEXTURE_GEN) != 0;
            cbfd_texgen_linear = (requested & G_TEXTURE_GEN_LINEAR) != 0;
            geometry_mode = requested & ~(G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
            state_dirty = true;
        }

        // ======================================================== vertices
        // Vertex loads work in two steps. The position (all culling needs) is computed at
        // the load; the colour, lighting, fog and texture coordinates only when a drawn
        // triangle uses the vertex: most loaded vertices end up off screen or back facing.
        // What that second step reads is captured here, and anything that would change it
        // (matrices, lights, geometry mode...) finishes the pending vertices first.
        VertexContext vctx;
        PointLight vctx_lights[12]; // its point lights
        // Each loaded vertex's context: the current one (vctx, copied into the list when a
        // vertex of it is drawn) or one already in the list.
        static constexpr uint16_t ctx_current = 0xFFFF;
        uint16_t slot_ctx[max_vertices] = {};
        int32_t vctx_index = -1; // vctx's place in the list, -1 if not copied there yet
        uint32_t normal_base_at_load = 0;

        uint16_t current_ctx_index() {
            if (vctx_index < 0) {
                vctx.light_base = (uint32_t)list->lights.size();
                if (vctx.num_lights > 1) {
                    list->lights.insert(list->lights.end(), vctx_lights, vctx_lights + (vctx.num_lights - 1));
                }
                list->ctxs.push_back(vctx);
                stats.ctx_pushes++;
                vctx_index = (int32_t)list->ctxs.size() - 1;
            }
            return (uint16_t)vctx_index;
        }

        // Before the state the context comes from changes: the vertices loaded with the
        // current one keep it.
        void pin_vertex_context() {
            if (current_ctx_slots == 0) return;
            const uint16_t index = current_ctx_index();
            uint64_t p = current_ctx_slots;
            while (p) {
                const uint32_t i = (uint32_t)__builtin_ctzll(p);
                p &= p - 1;
                slot_ctx[i] = index;
            }
            current_ctx_slots = 0;
        }
        uint64_t current_ctx_slots = 0; // the slots whose context is vctx

        // The advanced lighting's normal of a vertex (x, y), read when it's drawn.
        void read_normal(uint32_t slot, int8_t out[2]) const {
            const uint32_t na = slot_normal_addr[slot];
            if (na == ~0u) {
                out[0] = out[1] = 0;
                return;
            }
            out[0] = (int8_t)m8(na);
            out[1] = (int8_t)m8(na + 1);
        }
        uint32_t slot_normal_addr[max_vertices] = {};

        struct RawVertex {
            float cx, cy, cz;
            int16_t s, t, flag;
            uint8_t r, g, b, a;
        };
        RawVertex raw_vertices[max_vertices];
        uint64_t pending_vertices = 0; // a bit per vertex still to finish
        static_assert(max_vertices <= 64);

        __attribute__((noinline)) void load_vertices(uint32_t addr, uint32_t count, int32_t dst) {
            PartTimer part_timer(*this, P_VTX);
            if (dst < 0 || dst + (int32_t)count > max_vertices) {
                return;
            }
            stats.vtx_loads++;
            stats.vtx_count += count;
            const Mat4& m = current_mvp();
            const Mat4& mv = modelview[modelview_depth];
            const float fb_w = current_fb ? (float)current_fb->gl_width : (float)cimg.width;
            const float fb_h = current_fb ? (float)current_fb->height : (float)cimg.width * 0.75f;
            const float half_w = fb_w * 0.5f, half_h = fb_h * 0.5f;
            const float x_off = current_fb ? current_fb->off : 0.0f; // the 4:3 view in a wider image

            // Conker's lighting needs the directional lights in model space. Worked out again only
            // when a command changed what goes into it (most loads in a row share it: in the
            // intro's bar, 1400 loads a frame, each normalising up to 12 lights before).
            VertexContext& c = vctx;
            if (vctx_dirty) {
            vctx_dirty = false;
            c.num_lights = (int)std::min<uint32_t>(cbfd_light_count, (uint32_t)cbfd_lights.size() - 1);
            c.lighting = cbfd_lighting;
            c.texgen = cbfd_lighting && cbfd_texgen;
            c.texgen_linear = cbfd_texgen_linear;
            auto to_model = [&](const float d[3], float out[3]) {
                float x = mv.m[0][0] * d[0] + mv.m[0][1] * d[1] + mv.m[0][2] * d[2];
                float y = mv.m[1][0] * d[0] + mv.m[1][1] * d[1] + mv.m[1][2] * d[2];
                float z = mv.m[2][0] * d[0] + mv.m[2][1] * d[1] + mv.m[2][2] * d[2];
                const float len2 = x * x + y * y + z * z;
                if (len2 > 0.0f) {
                    // 1/length: NEON's estimate and two refining steps, not a square root and three
                    // divisions (each stalls the Cortex-A9 for tens of cycles; this runs for every
                    // light after every matrix).
#if defined(__ARM_NEON)
                    const float32x2_t l2 = vdup_n_f32(len2);
                    float32x2_t r = vrsqrte_f32(l2);
                    r = vmul_f32(r, vrsqrts_f32(vmul_f32(l2, r), r));
                    r = vmul_f32(r, vrsqrts_f32(vmul_f32(l2, r), r));
                    const float inv = vget_lane_f32(r, 0);
#else
                    const float inv = 1.0f / std::sqrt(len2);
#endif
                    out[0] = x * inv; out[1] = y * inv; out[2] = z * inv;
                }
                else {
                    out[0] = out[1] = out[2] = 0.0f;
                }
            };
            float light_dirs[12][3];
            if (c.lighting) {
                for (int l = 0; l < c.num_lights; l++) {
                    to_model(cbfd_lights[l].dir, light_dirs[l]);
                }
                if (c.num_lights > 0) {
                    std::memcpy(c.dir_light, light_dirs[c.num_lights - 1], sizeof(c.dir_light));
                }
            }
            if (c.texgen) {
                to_model(lookat[0], c.lookat_model[0]);
                to_model(lookat[1], c.lookat_model[1]);
            }
            c.point_lighting = (geometry_mode & G_POINT_LIGHTING) != 0;
            c.advanced = cbfd_advanced_lighting;
            c.directional_too = c.advanced && c.point_lighting;
            c.fog = (geometry_mode & G_FOG) != 0;
            c.fog_m = (float)fog_mul;
            c.fog_o = (float)fog_offset;
            c.tex_ss = texture.scale_s / 32.0f;
            c.tex_st = texture.scale_t / 32.0f;
            vctx_index = -1;
            normal_base_at_load = cbfd_normal_base;
            for (int l = 0; l < c.num_lights - 1; l++) {
                const CbfdLight& cl = cbfd_lights[l];
                vctx_lights[l] = { cl.pos[0], cl.pos[1], cl.pos[2], cl.r, cl.g, cl.b, cl.ca,
                                   c.lighting ? light_dirs[l][0] : 0.0f, c.lighting ? light_dirs[l][1] : 0.0f, c.lighting ? light_dirs[l][2] : 0.0f };
            }
            const int amb = std::max(c.num_lights, 0);
            c.amb_r = cbfd_lights[amb].r;
            c.amb_g = cbfd_lights[amb].g;
            c.amb_b = cbfd_lights[amb].b;
            const int dir = std::max(c.num_lights - 1, 0);
            c.dir_r = cbfd_lights[dir].r;
            c.dir_g = cbfd_lights[dir].g;
            c.dir_b = cbfd_lights[dir].b;
            const float* mod = cbfd_coord_mod;
            c.mod8 = mod[8]; c.mod9 = mod[9]; c.mod10 = mod[10];
            c.mod12 = mod[12]; c.mod13 = mod[13]; c.mod14 = mod[14];
            }

            const float sx = vscale[0] / half_w, tx = (vtrans[0] + x_off) / half_w - 1.0f;
            const float sy = vscale[1] / half_h, ty = 1.0f - vtrans[1] / half_h;
            // The depth the RDP stores is the viewport's: screen z = z/w * scale + translate,
            // 0..1023. Games give groups of objects different depth ranges this way (the bar's
            // inside behind its outside), so it goes to GL as that, mapped onto -1..1.
            const float sz = 2.0f * vscale[2] / 1023.0f, tz = 2.0f * vtrans[2] / 1023.0f - 1.0f;
#if defined(__ARM_NEON)
            // The matrix's rows and the viewport in NEON registers: a vertex is three
            // multiply-adds to clip space and one more through the viewport.
            const float32x4_t row0 = vld1q_f32(m.m[0]), row1 = vld1q_f32(m.m[1]);
            const float32x4_t row2 = vld1q_f32(m.m[2]), row3 = vld1q_f32(m.m[3]);
            const float vp_scale[4] = { sx, sy, sz, 1.0f }, vp_trans[4] = { tx, ty, tz, 0.0f };
            const float32x4_t vscale4 = vld1q_f32(vp_scale), vtrans4 = vld1q_f32(vp_trans);
#endif
            if (deferred_geometry) {
                load_deferred(addr, count, dst, m, sx, tx, sy, ty, sz, tz, c);
                return;
            }

            if (count > 0) {
                const uint64_t loaded = (count >= 64 ? ~0ull : ((1ull << count) - 1)) << dst;
                pending_vertices |= loaded;
                current_ctx_slots |= loaded;
            }
#if defined(__ARM_NEON)
            // The outcodes' bits: x, y, z below -w (left, bottom, near) and above w.
            const uint32_t below_bits[4] = { 1, 4, 16, 0 }, above_bits[4] = { 2, 8, 32, 0 };
            const uint32x4_t below4 = vld1q_u32(below_bits), above4 = vld1q_u32(above_bits);
            const float32x2_t tiny_w = vdup_n_f32(1e-6f);
#endif
            // The vertices' memory asked for at once (the game has just written it, so it isn't in
            // the cache; read in turn, each line waited for the memory on the Vita).
            for (uint32_t a = addr & ~31u; a < addr + count * 16; a += 32) {
                __builtin_prefetch(mem(a) + (a & rdram_mask));
            }
            // So are the advanced lighting's normals (two bytes a vertex), read as the triangles go.
            if (c.advanced && (c.lighting || c.texgen) && count > 0) {
                const uint32_t n0 = normal_base_at_load + ((uint32_t)dst << 1);
                for (uint32_t a = n0 & ~31u; a < n0 + count * 2; a += 32) {
                    __builtin_prefetch(mem(a) + (a & rdram_mask));
                }
            }
            uint32_t vtx_page = ~0u;
            const uint8_t* vtx_mem = nullptr;
            for (uint32_t i = 0; i < count; i++) {
                const uint32_t va = addr + i * 16;
                // The vertex's 16 bytes: in one page (looked up when the vertices reach it) unless
                // it straddles two.
                if ((va >> capture::page_shift) != vtx_page) {
                    vtx_page = va >> capture::page_shift;
                    vtx_mem = mem(va);
                }
                const uint8_t* const vb = (va & 0xFFF) <= 0xFF0 ? vtx_mem : nullptr;
                const uint32_t w_xy = vb ? read32(vb, va) : m32(va);
                const uint32_t w_zf = vb ? read32(vb, va + 4) : m32(va + 4);
                const uint32_t w_st = vb ? read32(vb, va + 8) : m32(va + 8);
                const uint32_t w_c = vb ? read32(vb, va + 12) : m32(va + 12);
                const float px = (float)(int16_t)(w_xy >> 16);
                const float py = (float)(int16_t)(w_xy & 0xFFFF);
                const float pz = (float)(int16_t)(w_zf >> 16);

                // Clip space.
#if defined(__ARM_NEON)
                const float32x4_t clip4 = vmlaq_n_f32(vmlaq_n_f32(vmlaq_n_f32(row3, row0, px), row1, py), row2, pz);
                float clip_xyzw[4];
                vst1q_f32(clip_xyzw, clip4);
                const float cx = clip_xyzw[0], cy = clip_xyzw[1], cz = clip_xyzw[2], cw = clip_xyzw[3];
#else
                const float cx = px * m.m[0][0] + py * m.m[1][0] + pz * m.m[2][0] + m.m[3][0];
                const float cy = px * m.m[0][1] + py * m.m[1][1] + pz * m.m[2][1] + m.m[3][1];
                const float cz = px * m.m[0][2] + py * m.m[1][2] + pz * m.m[2][2] + m.m[3][2];
                const float cw = px * m.m[0][3] + py * m.m[1][3] + pz * m.m[2][3] + m.m[3][3];
#endif

                const uint32_t vindex = (uint32_t)dst + i;
                RawVertex& r = raw_vertices[vindex];
                r.cx = cx; r.cy = cy; r.cz = cz;
                r.flag = (int16_t)(w_zf & 0xFFFF);
                r.s = (int16_t)(w_st >> 16);
                r.t = (int16_t)(w_st & 0xFFFF);
                r.r = w_c >> 24; r.g = (w_c >> 16) & 0xFF; r.b = (w_c >> 8) & 0xFF; r.a = w_c & 0xFF;
                slot_normal_addr[vindex] = (c.advanced && (c.lighting || c.texgen)) ? normal_base_at_load + (vindex << 1) : ~0u;
                slot_ctx[vindex] = ctx_current;
                slot_serial[vindex] = 0;

                RspVertex& v = vertices[vindex];
#if defined(__ARM_NEON)
                // All in NEON registers: on the Cortex-A9 a value moved from them to the core's
                // (each compare's flags, each outcode bit) stalls the pipeline.
                // 1/w for the culling's normalised coordinates: NEON's estimate and two refining
                // steps (a division costs far more; culling needs no more precision).
                const float32x2_t w2 = vdup_lane_f32(vget_high_f32(clip4), 1);
                const float32x2_t wd = vbsl_f32(vcalt_f32(w2, tiny_w), tiny_w, w2);
                float32x2_t est = vrecpe_f32(wd);
                est = vmul_f32(est, vrecps_f32(wd, est));
                est = vmul_f32(est, vrecps_f32(wd, est));
                vst1_f32(&v.ndc_x, vmul_f32(vget_low_f32(clip4), est));
                // Through the viewport, into the framebuffer's normalised coordinates
                // (top of the N64's screen at +1).
                const float32x4_t pos = vmlaq_n_f32(vmulq_f32(clip4, vscale4), vtrans4, cw);
                vst1q_f32(&v.x, pos);
                // Outside a plane when x + w < 0 (left), w - x < 0 (right)...
                const float32x4_t w4 = vdupq_lane_f32(vget_high_f32(pos), 1);
                const uint32x4_t out = vorrq_u32(vandq_u32(vcltq_f32(pos, vnegq_f32(w4)), below4),
                                                 vandq_u32(vcgtq_f32(pos, w4), above4));
                const uint32x2_t out2 = vorr_u32(vget_low_u32(out), vget_high_u32(out));
                v.clip = (uint8_t)vget_lane_u32(vpadd_u32(out2, out2), 0);
#else
                const float wd = std::fabs(cw) < 1e-6f ? 1e-6f : cw;
                const float rw = 1.0f / wd;
                v.ndc_x = cx * rw;
                v.ndc_y = cy * rw;
                v.x = cx * sx + cw * tx;
                v.y = cy * sy + cw * ty;
                v.z = cz * sz + cw * tz;
                v.w = cw;
                v.clip = (uint8_t)(negative(v.x + v.w) | (negative(v.w - v.x) << 1) |
                                   (negative(v.y + v.w) << 2) | (negative(v.w - v.y) << 3) |
                                   (negative(v.z + v.w) << 4) | (negative(v.w - v.z) << 5));
#endif
            }
        }

        // ======================================================== deferred geometry
        bool deferred_geometry = true;
        uint32_t list_serial = 0;
        uint32_t slot_src[max_vertices] = { // each vertex slot's vertex in the list's src (~0: none)
            ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u,
            ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u,
            ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u,
            ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u, ~0u };
        uint64_t slot_xformed = 0;         // the slots whose vertices[] were worked out (lazily)
        int32_t xform_index = -1;          // the list's transform loads use, while the same
        uint32_t xform_mvp_serial = 0;
        float last_vp[6] = {};
        size_t tri_base = 0;               // where the batch's triangles start in the list's tris
        bool batch_deferred = false;

        // The vertices as loaded, with the transform and context they're drawn with.
        void load_deferred(uint32_t addr, uint32_t count, int32_t dst, const Mat4& m, float sx, float tx,
                           float sy, float ty, float sz, float tz, const VertexContext& c) {
            // A new transform when the matrix was worked out again or the viewport changed.
            if (xform_index < 0 || xform_mvp_serial != mvp_serial || last_vp[0] != sx || last_vp[1] != tx ||
                last_vp[2] != sy || last_vp[3] != ty || last_vp[4] != sz || last_vp[5] != tz) {
                Xform& xf = list->xforms.emplace_back();
                std::memcpy(xf.row, m.m, sizeof(xf.row));
                xf.vscale[0] = sx; xf.vscale[1] = sy; xf.vscale[2] = sz; xf.vscale[3] = 1.0f;
                xf.vtrans[0] = tx; xf.vtrans[1] = ty; xf.vtrans[2] = tz; xf.vtrans[3] = 0.0f;
                xform_index = (int32_t)list->xforms.size() - 1;
                xform_mvp_serial = mvp_serial;
                last_vp[0] = sx; last_vp[1] = tx; last_vp[2] = sy; last_vp[3] = ty; last_vp[4] = sz; last_vp[5] = tz;
            }
            const uint16_t ctx = current_ctx_index();
            const bool normals = c.advanced && (c.lighting || c.texgen);
            // The game has just written them: asked for at once (each line read in turn waited for
            // the memory on the Vita), the normals too.
            for (uint32_t a = addr & ~31u; a < addr + count * 16; a += 32) {
                __builtin_prefetch(mem(a) + (a & rdram_mask));
            }
            const uint32_t n0 = normal_base_at_load + ((uint32_t)dst << 1);
            if (normals) {
                for (uint32_t a = n0 & ~31u; a < n0 + count * 2; a += 32) {
                    __builtin_prefetch(mem(a) + (a & rdram_mask));
                }
            }
            const size_t base = list->src.size();
            list->src.resize(base + count);
            SrcVertex* out = list->src.data() + base;
            uint32_t vtx_page = ~0u, nrm_page = ~0u;
            const uint8_t* vtx_mem = nullptr;
            const uint8_t* nrm_mem = nullptr;
            for (uint32_t i = 0; i < count; i++) {
                const uint32_t va = addr + i * 16;
                if ((va >> capture::page_shift) != vtx_page) {
                    vtx_page = va >> capture::page_shift;
                    vtx_mem = mem(va);
                }
                const uint8_t* const vb = (va & 0xFFF) <= 0xFF0 ? vtx_mem : nullptr;
                const uint32_t w_xy = vb ? read32(vb, va) : m32(va);
                const uint32_t w_zf = vb ? read32(vb, va + 4) : m32(va + 4);
                const uint32_t w_st = vb ? read32(vb, va + 8) : m32(va + 8);
                const uint32_t w_c = vb ? read32(vb, va + 12) : m32(va + 12);
                SrcVertex& sv = out[i];
                sv.x = (int16_t)(w_xy >> 16);
                sv.y = (int16_t)(w_xy & 0xFFFF);
                sv.z = (int16_t)(w_zf >> 16);
                sv.flag = (int16_t)(w_zf & 0xFFFF);
                sv.s = (int16_t)(w_st >> 16);
                sv.t = (int16_t)(w_st & 0xFFFF);
                sv.r = w_c >> 24; sv.g = (w_c >> 16) & 0xFF; sv.b = (w_c >> 8) & 0xFF; sv.a = w_c & 0xFF;
                const uint32_t vindex = (uint32_t)dst + i;
                if (normals) {
                    const uint32_t na = n0 + i * 2;
                    if ((na >> capture::page_shift) != nrm_page) {
                        nrm_page = na >> capture::page_shift;
                        nrm_mem = mem(na);
                    }
                    sv.n0 = (int8_t)read8(nrm_mem, na);
                    sv.n1 = (int8_t)read8(nrm_mem, na + 1);
                }
                else {
                    sv.n0 = sv.n1 = 0;
                }
                sv.ctx = ctx;
                sv.xform = (uint16_t)xform_index;
                sv.done = 0;
                sv.fs = sv.ft = 0.0f;
                slot_src[vindex] = (uint32_t)(base + i);
            }
            interpolate_vertices(vertex_load_key(count), out, count);
            if (count > 0) {
                slot_xformed &= ~((count >= 64 ? ~0ull : ((1ull << count) - 1)) << dst);
                record_load((uint32_t)dst, count, (uint32_t)base);
            }
        }

        void record_load(uint32_t first, uint32_t count, uint32_t src_base) {
            TriRec& r = list->tris.emplace_back();
            r.v[0] = (uint8_t)first; r.v[1] = r.v[2] = 0;
            r.flags = REC_LOAD;
            r.uv = 0;
            r.count = (uint16_t)count;
            r.src = src_base;
            r.prim_z = 0.0f;
        }

        // A slot's vertex worked out here (G_CULLDL, G_BRANCH_Z read them).
        void xform_slot(uint32_t slot) {
            if (slot >= max_vertices || (slot_xformed >> slot & 1) || slot_src[slot] == ~0u) return;
            slot_xformed |= 1ull << slot;
            const SrcVertex& sv = list->src[slot_src[slot]];
            XfVertex xv;
            transform_vertex(list->xforms[sv.xform], sv, xv);
            RspVertex& v = vertices[slot];
            v.x = xv.x; v.y = xv.y; v.z = xv.z; v.w = xv.w;
            v.ndc_x = xv.ndc_x; v.ndc_y = xv.ndc_y;
            v.clip = (uint8_t)xv.clip;
        }

        // G_MODIFYVTX: the vertex lit here, changed, and recorded again as final.
        void modify_deferred(uint32_t w0, uint32_t w1) {
            const uint32_t where = (w0 >> 16) & 0xFF;
            const uint32_t index = (w0 & 0xFFFF) / 2;
            if (index >= max_vertices || slot_src[index] == ~0u || (where != 0x10 && where != 0x14)) {
                return;
            }
            SrcVertex sv = list->src[slot_src[index]];
            if (!sv.done) {
                XfVertex xv;
                transform_vertex(list->xforms[sv.xform], sv, xv);
                VertexIn in;
                deferred_vertex_in(sv, xv, 0, false, 0.0f, in);
                const VertexContext& vc = list->ctxs[sv.ctx];
                uint8_t rgba[4];
                float s_out, t_out;
                light_vertex(vc, list->lights.data() + vc.light_base, in, rgba, s_out, t_out);
                sv.r = rgba[0]; sv.g = rgba[1]; sv.b = rgba[2]; sv.a = rgba[3];
                sv.fs = s_out; sv.ft = t_out;
                sv.done = 1;
            }
            if (where == 0x10) {
                sv.r = w1 >> 24; sv.g = (w1 >> 16) & 0xFF; sv.b = (w1 >> 8) & 0xFF; sv.a = w1 & 0xFF;
            }
            else {
                sv.fs = (float)(int16_t)(w1 >> 16) / 32.0f;
                sv.ft = (float)(int16_t)(w1 & 0xFFFF) / 32.0f;
            }
            list->src.push_back(sv);
            slot_src[index] = (uint32_t)list->src.size() - 1;
            record_load(index, 1, slot_src[index]);
        }

        // A triangle as the vertices it joins; the back culls and draws it.
        void triangle_deferred(uint32_t ia, uint32_t ib, uint32_t ic) {
            const uint32_t a = slot_src[ia], b = slot_src[ib], c = slot_src[ic];
            if (a == ~0u || b == ~0u || c == ~0u) {
                return;
            }
            if (__builtin_expect((debug_flags & 524288) != 0 || ab_phase == 3 || ab_phase == 1, 0)) return;
            if (!prepare_draw(false)) {
                stats.tris_nofb++;
                return;
            }
            if (__builtin_expect(ab_phase == 2, 0)) return;
            if (!batch_deferred && !batch.empty()) {
                flush(); // rectangles before
            }
            if (list->tris.size() - tri_base >= 16000) {
                flush(); // at most 4 vertices a triangle: a draw's indices stay 16-bit
            }
            batch_deferred = true;
            const TileTexture& tt0 = tile_textures[texture.tile & 7];
            const TileTexture& tt1 = tile_textures[(texture.tile + 1) & 7];
            TriRec& t = list->tris.emplace_back();
            t.v[0] = (uint8_t)ia; t.v[1] = (uint8_t)ib; t.v[2] = (uint8_t)ic;
            t.uv = current_uv_index(tt0, tt1);
            t.count = 0;
            t.src = 0;
            uint8_t f = 0;
            if (geometry_mode & G_CULL_FRONT) f |= TRI_CULL_FRONT;
            if (geometry_mode & G_CULL_BACK) f |= TRI_CULL_BACK;
            if ((geometry_mode & G_SHADING_SMOOTH) == 0) f |= TRI_FLAT;
            t.prim_z = 0.0f;
            if (other_mode_l & OML_ZS_PRIM) {
                f |= TRI_ZPRIM;
                t.prim_z = prim_depth_ndc();
            }
            t.flags = f;
            stats.tris++;
        }

        // A raw vertex as the GL thread would get it.
        VertexIn raw_vertex_in(uint32_t vindex) const {
            const RawVertex& rv = raw_vertices[vindex];
            const RspVertex& v = vertices[vindex];
            VertexIn in;
            in.x = v.x; in.y = v.y; in.z = v.z; in.w = v.w;
            in.cx = rv.cx; in.cy = rv.cy; in.cz = rv.cz;
            in.s = in.t = 0;
            in.rs = rv.s; in.rt = rv.t; in.flag = rv.flag;
            in.r = rv.r; in.g = rv.g; in.b = rv.b; in.a = rv.a;
            int8_t n[2];
            read_normal(vindex, n);
            in.n0 = n[0];
            in.n1 = n[1];
            in.done = 0;
            in.ctx = 0;
            in.uv = 0;
            in.color_from = ~0u;
            return in;
        }

        // Works a vertex's colour and texture coordinates out here (for G_MODIFYVTX, and
        // before a list goes: the contexts are the list's).
        void finish_vertex(uint32_t vindex) {
            pending_vertices &= ~(1ull << vindex);
            current_ctx_slots &= ~(1ull << vindex);
            const bool current = slot_ctx[vindex] == ctx_current;
            const VertexContext& c = current ? vctx : list->ctxs[slot_ctx[vindex]];
            const PointLight* lights = current ? vctx_lights : list->lights.data() + c.light_base;
            RspVertex& v = vertices[vindex];
            uint8_t rgba[4];
            light_vertex(c, lights, raw_vertex_in(vindex), rgba, v.s, v.t);
            v.r = rgba[0]; v.g = rgba[1]; v.b = rgba[2]; v.a = rgba[3];
        }

        void finish_pending_vertices() {
            while (pending_vertices) {
                finish_vertex((uint32_t)__builtin_ctzll(pending_vertices));
            }
        }

        void modify_vertex(uint32_t w0, uint32_t w1) {
            const uint32_t where = (w0 >> 16) & 0xFF;
            const uint32_t index = (w0 & 0xFFFF) / 2;
            if (index >= max_vertices) {
                return;
            }
            RspVertex& v = vertices[index];
            slot_serial[index] = 0;
            switch (where) {
                case 0x10: // RGBA
                    v.r = w1 >> 24; v.g = (w1 >> 16) & 0xFF; v.b = (w1 >> 8) & 0xFF; v.a = w1 & 0xFF;
                    break;
                case 0x14: // ST
                    v.s = (float)(int16_t)(w1 >> 16) / 32.0f;
                    v.t = (float)(int16_t)(w1 & 0xFFFF) / 32.0f;
                    break;
                default:
                    break;
            }
        }

        bool cull_dl(uint32_t first, uint32_t last) {
            if (first >= max_vertices || last >= max_vertices || last < first) {
                return false;
            }
            if (deferred_geometry) {
                for (uint32_t i = first; i <= last; i++) xform_slot(i);
            }
            uint8_t common = 0x3F;
            for (uint32_t i = first; i <= last; i++) {
                common &= vertices[i].clip;
            }
            return common != 0;
        }

        // ======================================================== triangles
        void tri4(uint32_t w0, uint32_t w1) {
            auto field = [](uint32_t w, uint32_t shift, uint32_t bits) { return (w >> shift) & ((1u << bits) - 1); };
            const uint32_t v[12] = {
                field(w0, 23, 5), field(w0, 18, 5), (field(w0, 15, 3) << 2) | field(w1, 30, 2),
                field(w0, 10, 5), field(w0, 5, 5), field(w0, 0, 5),
                field(w1, 25, 5), field(w1, 20, 5), field(w1, 15, 5),
                field(w1, 10, 5), field(w1, 5, 5), field(w1, 0, 5),
            };
            for (int t = 0; t < 4; t++) {
                const uint32_t a = v[t * 3 + 0], b = v[t * 3 + 1], c = v[t * 3 + 2];
                // Unused slots repeat an index.
                if (a != b && b != c && a != c) {
                    triangle(a, b, c);
                }
            }
        }

        struct { uint32_t tris = 0, clipped = 0, culled = 0; float sum = 0; } water_stats;

        // A triangle: most (over half, in the intro's bar) are outside the view or facing away,
        // turned down here inline; the rest drawn by triangle_draw.
        inline __attribute__((always_inline)) void triangle(uint32_t ia, uint32_t ib, uint32_t ic) {
            if (__builtin_expect(ia >= max_vertices || ib >= max_vertices || ic >= max_vertices, 0)) {
                return;
            }
            if (deferred_geometry) {
                triangle_deferred(ia, ib, ic);
                return;
            }
            if ((vertices[ia].clip & vertices[ib].clip & vertices[ic].clip) && !(debug_flags & 1)) {
                stats.tris_clipped++;
                return;
            }
            // Debug (flag 524288): triangles not drawn (what they cost, against the frame's time).
            if (__builtin_expect((debug_flags & 524288) != 0 || ab_phase == 3, 0)) return;
            triangle_draw(ia, ib, ic);
        }

        __attribute__((noinline)) void triangle_draw(uint32_t ia, uint32_t ib, uint32_t ic) {
            PartTimer part_timer(*this, P_TRI);
            const RspVertex* v[3] = { &vertices[ia], &vertices[ib], &vertices[ic] };
            // Debug (flag 512): the water's triangles (its combiner) in each display list.
            const bool water = __builtin_expect((debug_flags & 512) != 0, 0) && combine_w0 == 0x26A004;
            if (water) {
                water_stats.tris++;
                water_stats.sum += v[0]->ndc_x + v[1]->ndc_y + v[2]->w * 0.001f;
            }
            const uint32_t cull = (debug_flags & 2) ? 0 : geometry_mode & (G_CULL_FRONT | G_CULL_BACK);
            if (cull) {
                if (cull == (G_CULL_FRONT | G_CULL_BACK)) {
                    return;
                }
                const float dx1 = v[1]->ndc_x - v[0]->ndc_x, dy1 = v[1]->ndc_y - v[0]->ndc_y;
                const float dx2 = v[2]->ndc_x - v[0]->ndc_x, dy2 = v[2]->ndc_y - v[0]->ndc_y;
                const float cross = dx1 * dy2 - dy1 * dx2;
                // Its sign and whether it's 0 from its bits (a float compare's flags stall the
                // Cortex-A9), the sign flipped by an odd number of vertices behind the camera.
                uint32_t bits;
                std::memcpy(&bits, &cross, 4);
                const bool zero = (bits << 1) == 0;
                const bool below = ((bits >> 31) ^ negative(v[0]->w) ^ negative(v[1]->w) ^ negative(v[2]->w)) != 0;
                // N64 front faces wind counter-clockwise in normalised coordinates (y up).
                if (zero || (cull == G_CULL_FRONT ? !below : below)) {
                    stats.tris_culled++;
                    if (water) water_stats.culled++;
                    return;
                }
            }

            if (__builtin_expect(ab_phase == 1, 0)) return;
            if (!prepare_draw(false)) {
                stats.tris_nofb++;
                return;
            }
            if (__builtin_expect(ab_phase == 2, 0)) return;
            stats.tris++;
            const bool flat = (geometry_mode & G_SHADING_SMOOTH) == 0;
            const bool zprim = (other_mode_l & OML_ZS_PRIM) != 0;
            const float prim_z = zprim ? prim_depth_ndc() : 0.0f;
            const TileTexture& tt0 = tile_textures[texture.tile & 7];
            const TileTexture& tt1 = tile_textures[(texture.tile + 1) & 7];
            if (batch.size() + 3 > 65535) {
                flush();
            }
            // Triangles and rectangles' vertices differ: a batch has one kind.
            if (!batch_raw && !batch.empty()) {
                flush();
            }
            const uint32_t slots[3] = { ia, ib, ic };
            const uint16_t uv = current_uv_index(tt0, tt1);
            batch_raw = true;
            // A vertex behind the camera (w <= 0): cut the triangle at the camera's plane, so the GPU
            // never gets one (the Vita's GPU dropped such triangles: rivers running under the
            // camera vanished in most frames; Vita3K draws them). Only there: Conker's microcode
            // doesn't clip at the near plane (the RDP clamps the depth of what's nearer, done in
            // finish_vertices), and cutting there holed the N64 logo as the camera went inside it.
            // Debug flag 16384: uncut.
            if ((at_most_w_cut(v[0]->w) | at_most_w_cut(v[1]->w) | at_most_w_cut(v[2]->w)) && !(debug_flags & 16384)) {
                clipped_triangle(v, slots, uv, flat, zprim, prim_z);
                return;
            }
            uint16_t* ix = batch.grow_indices(3);
            uint32_t first_vertex = ~0u;
            for (int i = 0; i < 3; i++) {
                const uint32_t slot = slots[i];
                // Flat shading colours a vertex by the triangle: not shared then.
                if (!flat && slot_serial[slot] == vertex_cache_serial) {
                    ix[i] = slot_index[slot];
                    continue;
                }
                const uint16_t at = (uint16_t)batch.size();
                ix[i] = at;
                if (!flat) {
                    slot_index[slot] = at;
                    slot_serial[slot] = vertex_cache_serial;
                }
                const RspVertex& rv = *v[i];
                VertexIn& in = *batch.grow_in(1);
                if (pending_vertices & (1ull << slot)) {
                    const RawVertex& raw = raw_vertices[slot];
                    in.cx = raw.cx; in.cy = raw.cy; in.cz = raw.cz;
                    in.rs = raw.s; in.rt = raw.t; in.flag = raw.flag;
                    in.r = raw.r; in.g = raw.g; in.b = raw.b; in.a = raw.a;
                    int8_t n[2];
                    read_normal(slot, n);
                    in.n0 = n[0];
                    in.n1 = n[1];
                    in.done = 0;
                    in.ctx = slot_ctx[slot] == ctx_current ? current_ctx_index() : slot_ctx[slot];
                }
                else {
                    in.r = rv.r; in.g = rv.g; in.b = rv.b; in.a = rv.a;
                    in.s = rv.s; in.t = rv.t;
                    in.done = 1;
                }
                in.x = rv.x;
                in.y = rv.y;
                in.z = zprim ? prim_z * rv.w : rv.z;
                in.w = rv.w;
                in.uv = uv;
                // Flat shading: the triangle's first vertex's colour.
                in.color_from = (flat && i > 0) ? first_vertex : ~0u;
                if (i == 0) first_vertex = (uint32_t)(batch.base + at);
            }
        }

        static constexpr float w_cut = 1e-3f; // where triangles through the camera's plane are cut
        // w <= w_cut, compared as integers: a float compare's flags stall the Cortex-A9's pipeline
        // until the VFP is done. For a positive bound, floats order as their bits do as signed
        // integers (negative ones are negative integers, below it too).
        static bool at_most_w_cut(float w) {
            int32_t a, b;
            const float bound = w_cut;
            std::memcpy(&a, &w, 4);
            std::memcpy(&b, &bound, 4);
            return a <= b;
        }

        // A triangle vertex as the GL thread gets it (raw: lit and mapped there).
        void make_vertex_in(VertexIn& in, uint32_t slot, const RspVertex& rv, uint16_t uv, bool zprim, float prim_z) {
            if (pending_vertices & (1ull << slot)) {
                const RawVertex& raw = raw_vertices[slot];
                in.cx = raw.cx; in.cy = raw.cy; in.cz = raw.cz;
                in.rs = raw.s; in.rt = raw.t; in.flag = raw.flag;
                in.r = raw.r; in.g = raw.g; in.b = raw.b; in.a = raw.a;
                int8_t n[2];
                read_normal(slot, n);
                in.n0 = n[0];
                in.n1 = n[1];
                in.done = 0;
                in.ctx = slot_ctx[slot] == ctx_current ? current_ctx_index() : slot_ctx[slot];
            }
            else {
                in.r = rv.r; in.g = rv.g; in.b = rv.b; in.a = rv.a;
                in.s = rv.s; in.t = rv.t;
                in.done = 1;
            }
            in.x = rv.x;
            in.y = rv.y;
            in.z = zprim ? prim_z * rv.w : rv.z;
            in.w = rv.w;
            in.uv = uv;
            in.color_from = ~0u;
        }

        // A point along an edge, t of the way from a to b (clip space is linear in it).
        static VertexIn lerp_vertex(const VertexIn& a, const VertexIn& b, float t, bool normals) {
            auto lf = [t](float x, float y) { return x + (y - x) * t; };
            auto li = [t](int x, int y) { return (int)std::lround(x + (y - x) * t); };
            VertexIn o = a;
            o.x = lf(a.x, b.x); o.y = lf(a.y, b.y); o.z = lf(a.z, b.z); o.w = lf(a.w, b.w);
            o.cx = lf(a.cx, b.cx); o.cy = lf(a.cy, b.cy); o.cz = lf(a.cz, b.cz);
            o.s = lf(a.s, b.s); o.t = lf(a.t, b.t);
            o.rs = (int16_t)li(a.rs, b.rs); o.rt = (int16_t)li(a.rt, b.rt);
            // Colours, or normals as signed bytes (lit without the advanced normals): each byte
            // in its own sense.
            const bool signed_bytes = normals;
            auto lb = [&](uint8_t x, uint8_t y) {
                return signed_bytes ? (uint8_t)(int8_t)li((int8_t)x, (int8_t)y) : (uint8_t)li(x, y);
            };
            o.r = lb(a.r, b.r); o.g = lb(a.g, b.g); o.b = lb(a.b, b.b);
            o.a = (uint8_t)li(a.a, b.a);
            o.n0 = (int8_t)li(a.n0, b.n0); o.n1 = (int8_t)li(a.n1, b.n1);
            o.flag = (int16_t)((a.flag & 0xFF00) | ((uint8_t)(int8_t)li((int8_t)(a.flag & 0xFF), (int8_t)(b.flag & 0xFF))));
            return o;
        }

        // A triangle through the near plane, cut to its part in front (a polygon of up to
        // four vertices, drawn as a fan).
        void clipped_triangle(const RspVertex* const v[3], const uint32_t slots[3], uint16_t uv, bool flat, bool zprim, float prim_z) {
            VertexIn tri[3];
            for (int i = 0; i < 3; i++) {
                make_vertex_in(tri[i], slots[i], *v[i], uv, zprim, prim_z);
            }
            // Raw vertices carry normals in r, g, b when lit (or texture-generated) without
            // the advanced lighting's own normals; otherwise colours.
            bool normals = false;
            if (!tri[0].done) {
                const VertexContext& c = tri[0].ctx < list->ctxs.size() ? list->ctxs[tri[0].ctx] : vctx;
                normals = (c.lighting || c.texgen) && !c.advanced;
            }
            // In front of the camera (w > 0), a little in.
            auto dist = [](const VertexIn& p) { return p.w - w_cut; };
            VertexIn poly[4];
            int n = 0;
            for (int i = 0; i < 3; i++) {
                const VertexIn& a = tri[i];
                const VertexIn& b = tri[(i + 1) % 3];
                const float da = dist(a), db = dist(b);
                if (da >= 0.0f) poly[n++] = a;
                if ((da >= 0.0f) != (db >= 0.0f) && n < 4) {
                    poly[n++] = lerp_vertex(a, b, da / (da - db), normals);
                }
            }
            if (n < 3) {
                stats.tris_clipped++;
                return;
            }
            if (batch.size() + 4 > 65535) {
                flush();
                batch_raw = true;
            }
            const uint16_t first = (uint16_t)batch.size();
            VertexIn* out = batch.grow_in(n);
            for (int i = 0; i < n; i++) {
                out[i] = poly[i];
                // Flat shading: every piece takes the first vertex's colour.
                out[i].color_from = flat && i > 0 ? (uint32_t)(batch.base + first) : ~0u;
            }
            if (flat) {
                out[0].r = tri[0].r; out[0].g = tri[0].g; out[0].b = tri[0].b; out[0].a = tri[0].a;
            }
            uint16_t* ix = batch.grow_indices((uint32_t)(n - 2) * 3);
            for (int i = 1; i + 1 < n; i++) {
                *ix++ = first;
                *ix++ = (uint16_t)(first + i);
                *ix++ = (uint16_t)(first + i + 1);
            }
        }

        // The texture mapping of the tiles a triangle reads, in the list (a new one when
        // it changed).
        int32_t uv_index = -1;
        UvMap last_uv{};
        bool uv_dirty = true; // the tiles' textures may have changed since the last check
        uint16_t current_uv_index(const TileTexture& t0, const TileTexture& t1) {
            if (uv_index >= 0 && !uv_dirty) {
                return (uint16_t)uv_index;
            }
            UvMap m;
            const TileTexture* tt[2] = { &t0, &t1 };
            for (int i = 0; i < 2; i++) {
                m.shift_s[i] = tt[i]->shift_s;
                m.shift_t[i] = tt[i]->shift_t;
                m.uls[i] = tt[i]->uls;
                m.ult[i] = tt[i]->ult;
                m.offset[i] = tt[i]->offset;
                m.inv_w[i] = tt[i]->inv_width;
                m.inv_h[i] = tt[i]->inv_height;
            }
            if (uv_index < 0 || (uv_dirty && std::memcmp(&m, &last_uv, sizeof(m)) != 0)) {
                list->uvmaps.push_back(m);
                uv_index = (int32_t)list->uvmaps.size() - 1;
                last_uv = m;
            }
            uv_dirty = false;
            return (uint16_t)uv_index;
        }
        bool batch_raw = false;

        float prim_depth_ndc() const {
            // The primitive depth is the screen z (0..1023) times 32: the same scale the
            // vertices' depth goes to GL in.
            const float zs = (float)(prim_depth & 0x7FFF) / 32.0f;
            return std::clamp(zs / 1023.0f * 2.0f - 1.0f, -1.0f, 1.0f);
        }

        // ======================================================== rectangles
        void quad(float x0, float y0, float x1, float y1, float z,
                  float s0, float t0, float s1, float t1, bool flip, const uint8_t color[4]) {
            if (current_fb == nullptr) {
                return;
            }
            const float w = (float)current_fb->gl_width, h = (float)current_fb->height;
            const float off = current_fb->off;
            // A fill across the whole frame covers a widened one too; the rest stays in the 4:3.
            if (full_width_fill && x0 <= 4.0f && x1 >= current_fb->width - 4.0f) {
                x0 = -off;
                x1 = current_fb->width + off;
            }
            const float nx0 = (x0 + off) / w * 2.0f - 1.0f, nx1 = (x1 + off) / w * 2.0f - 1.0f;
            const float ny0 = 1.0f - y0 / h * 2.0f, ny1 = 1.0f - y1 / h * 2.0f;
            const TileTexture* tt[2] = { &tile_textures[rect_tile & 7], &tile_textures[(rect_tile + 1) & 7] };
            auto uv = [&](const TileTexture& t, float s, float tc, float& u, float& v) {
                u = (s * t.shift_s - t.uls + t.offset) / t.width;
                v = (tc * t.shift_t - t.ult + t.offset) / t.height;
            };
            const float xs[4] = { nx0, nx1, nx0, nx1 };
            const float ys[4] = { ny0, ny0, ny1, ny1 };
            // Corners: upper left, upper right, lower left, lower right.
            float ss[4], ts[4];
            if (!flip) {
                ss[0] = s0; ts[0] = t0; ss[1] = s1; ts[1] = t0; ss[2] = s0; ts[2] = t1; ss[3] = s1; ts[3] = t1;
            }
            else {
                ss[0] = s0; ts[0] = t0; ss[1] = s0; ts[1] = t1; ss[2] = s1; ts[2] = t0; ss[3] = s1; ts[3] = t1;
            }
            GLVertex corners[4];
            for (int i = 0; i < 4; i++) {
                GLVertex& g = corners[i];
                g.x = xs[i]; g.y = ys[i]; g.z = z; g.w = 1.0f;
                std::memcpy(g.color, color, 4);
                uv(*tt[0], ss[i], ts[i], g.u0, g.v0);
                uv(*tt[1], ss[i], ts[i], g.u1, g.v1);
            }
            if (batch.size() + 4 > 65535 || batch_raw || batch_deferred) {
                flush();
            }
            const uint16_t base = (uint16_t)batch.size();
            std::memcpy(batch.grow(4), corners, sizeof(corners));
            static const uint16_t order[6] = { 0, 1, 2, 2, 1, 3 };
            uint16_t* ix = batch.grow_indices(6);
            for (int i = 0; i < 6; i++) {
                ix[i] = base + order[i];
            }
        }

        uint32_t rect_tile = 0;
        bool full_width_fill = false;

        // Coordinates in 10.2, texture coordinates in s10.5 and s5.10.
        void texture_rectangle(uint32_t tile, int32_t ulx, int32_t uly, int32_t lrx, int32_t lry,
                               int32_t s, int32_t t, int32_t dsdx, int32_t dtdy, bool flip) {
            if (dumping()) {
                std::fprintf(stderr, "[texrect] cimg 0x%06X w%u tile %u timg 0x%06X rect (%.2f,%.2f)-(%.2f,%.2f) st (%d,%d) d(%d,%d) cycle %u\n",
                    cimg.addr, cimg.width, tile, timg.addr, ulx / 4.0, uly / 4.0, lrx / 4.0, lry / 4.0, s, t, dsdx, dtdy, (other_mode_h >> OMH_CYCLE_SHIFT) & 3);
            }
            const uint32_t cycle = (other_mode_h >> OMH_CYCLE_SHIFT) & 3;
            float x0 = ulx / 4.0f, y0 = uly / 4.0f, x1 = lrx / 4.0f, y1 = lry / 4.0f;
            float sx = dsdx / 1024.0f, ty = dtdy / 1024.0f;
            if (cycle == CYCLE_COPY) {
                // Copy mode draws 4 texels a cycle, and its rectangles include the lower right edge.
                sx /= 4.0f;
                x1 += 1.0f;
                y1 += 1.0f;
            }
            else if (cycle == CYCLE_FILL) {
                x1 += 1.0f;
                y1 += 1.0f;
            }
            if (x1 <= x0 || y1 <= y0) {
                return;
            }
            if (rect_tile != tile) {
                rect_tile = tile;
                state_dirty = true;
            }
            if (!prepare_draw(true)) {
                return;
            }
            float s0 = s / 32.0f;
            const float t0 = t / 32.0f;
            float s1, t1;
            if (!flip) {
                s1 = s0 + (x1 - x0) * sx;
                t1 = t0 + (y1 - y0) * ty;
            }
            else {
                s1 = s0 + (y1 - y0) * sx;
                t1 = t0 + (x1 - x0) * ty;
            }
            const float z = (other_mode_l & OML_ZS_PRIM) ? prim_depth_ndc() : -1.0f;
            stats.rects++;
            // A copy of a widened frame reaching the 4:3 one's sides (the game's blur and
            // distortion effects) reaches the widened one's, its texels with it.
            // (It copies it in strips: those at the edges reach the widened sides.)
            if (!flip && current_fb != nullptr && current_fb->off > 0.0f && tile_textures[rect_tile & 7].wide_fb && x1 > x0) {
                const float rate = (s1 - s0) / (x1 - x0);
                if (x0 <= 4.0f) {
                    const float nx0 = -current_fb->off;
                    s0 += (nx0 - x0) * rate;
                    x0 = nx0;
                }
                if (x1 >= current_fb->width - 4.0f) {
                    const float nx1 = current_fb->width + current_fb->off;
                    s1 += (nx1 - x1) * rate;
                    x1 = nx1;
                }
            }
            static const uint8_t white[4] = { 255, 255, 255, 255 };
            quad(x0, y0, x1, y1, z, s0, t0, s1, t1, flip, white);
        }

        void fill_rectangle(int32_t ulx, int32_t uly, int32_t lrx, int32_t lry) {
            if (dumping()) {
                std::fprintf(stderr, "[fill] cimg 0x%06X w%u rect (%d,%d)-(%d,%d) color %08X cycle %u\n", cimg.addr, cimg.width,
                    ulx / 4, uly / 4, lrx / 4, lry / 4, fill_color, (other_mode_h >> OMH_CYCLE_SHIFT) & 3);
            }
            if ((debug_flags & 4096) && current_fb != nullptr && cimg.addr != zimg_addr && (lrx - ulx) >= 200 * 4) {
                current_fb->water_draws = 0;
            }
            const uint32_t cycle = (other_mode_h >> OMH_CYCLE_SHIFT) & 3;
            float x0 = ulx / 4.0f, y0 = uly / 4.0f, x1 = lrx / 4.0f, y1 = lry / 4.0f;
            if (cycle == CYCLE_FILL || cycle == CYCLE_COPY) {
                x1 = (float)(lrx >> 2) + 1.0f;
                y1 = (float)(lry >> 2) + 1.0f;
                x0 = (float)(ulx >> 2);
                y0 = (float)(uly >> 2);
            }
            if (x1 <= x0 || y1 <= y0) {
                return;
            }

            // A fill of the depth buffer clears it. vitaGL keeps a depth buffer per
            // framebuffer, so it's cleared for every one of that size the game draws to.
            if (cimg.addr == zimg_addr) {
                flush();
                get_framebuffer(zimg_addr, cimg.width, SIZ_16b);
                for (auto& [base, fb] : framebuffers) {
                    if (fb.width == cimg.width && fb.siz == SIZ_16b) {
                        std::array<int, 4> sc;
                        scissor_rect(&fb, x0, y0, x1, y1, sc.data());
                        enqueue([fbo = fb.fbo, w = fb.gl_width, h = fb.height, sc](Backend& b, CommandList&) {
                            b.bind_framebuffer(fbo, w, h);
                            b.set_scissor(sc.data());
                            b.clear_depth();
                        });
                    }
                }
                return;
            }
            if (current_fb == nullptr) {
                return;
            }

            if (cycle == CYCLE_FILL) {
                flush();
                float c[4];
                if (cimg.siz == SIZ_32b) {
                    color_from_word(fill_color, c);
                }
                else {
                    const uint16_t p = (uint16_t)(fill_color >> 16);
                    c[0] = ((p >> 11) & 0x1F) / 31.0f;
                    c[1] = ((p >> 6) & 0x1F) / 31.0f;
                    c[2] = ((p >> 1) & 0x1F) / 31.0f;
                    c[3] = 1.0f;
                }
                std::array<int, 4> sc;
                scissor_rect(current_fb, x0, y0, x1, y1, sc.data());
                std::array<float, 4> color = { c[0], c[1], c[2], c[3] };
                enqueue([fbo = current_fb->fbo, w = current_fb->gl_width, h = current_fb->height, sc, color](Backend& b, CommandList&) {
                    b.bind_framebuffer(fbo, w, h);
                    b.set_scissor(sc.data());
                    b.clear_color(color.data());
                });
                current_fb->sig_pending = true;
                mark_drawn(current_fb, sc.data());
                stats.fills++;
                current_fb->last_drawn = present_count;
                return;
            }

            if (rect_tile != texture.tile) {
                rect_tile = texture.tile;
                state_dirty = true;
            }
            if (!prepare_draw(true)) {
                return;
            }
            const float z = (other_mode_l & OML_ZS_PRIM) ? prim_depth_ndc() : -1.0f;
            static const uint8_t black[4] = { 0, 0, 0, 0 };
            full_width_fill = true;
            quad(x0, y0, x1, y1, z, 0, 0, 0, 0, false, black);
            full_width_fill = false;
        }

        // The scissor of a clear of a rectangle (N64 pixels), within the game's scissor:
        // GL's, in the framebuffer's pixels from the bottom.
        void scissor_rect(const Framebuffer* fb, float x0, float y0, float x1, float y1, int out[4]) const {
            x0 = std::max(x0, scissor_ulx / 4.0f);
            y0 = std::max(y0, scissor_uly / 4.0f);
            x1 = std::min(x1, scissor_lrx / 4.0f);
            y1 = std::min(y1, scissor_lry / 4.0f);
            // Across the frame: across a widened one too.
            if (x0 <= 4.0f && x1 >= fb->width - 4.0f) {
                x0 = -fb->off;
                x1 = fb->width + fb->off;
            }
            out[0] = (int)((x0 + fb->off) * render_scale);
            out[1] = (int)((fb->height - y1) * render_scale);
            out[2] = std::max((int)((x1 - x0) * render_scale), 0);
            out[3] = std::max((int)((y1 - y0) * render_scale), 0);
        }

        // ======================================================== colour images
        bool fb_trace = false;
        // debug_fb_trace holds "t<seconds>": the tracing starts then.
        double fb_trace_at = [] {
            double t = -1;
            if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_fb_trace", "r")) {
                char text[32] = {};
                if (std::fscanf(f, "%31s", text) == 1 && text[0] == 't') t = std::atof(text + 1);
                std::fclose(f);
            }
            return t;
        }();
        uint32_t fb_trace_count = 0;

        void set_color_image(uint32_t fmt, uint32_t siz, uint32_t width, uint32_t addr) {
            flush();
            if (fb_trace && fb_trace_count < 5000 && addr != cimg.addr) {
                std::fprintf(stderr, "[fbtrace] dl %u cimg 0x%06X fmt %u siz %u w %u\n", dl_count, addr, fmt, siz, width);
                fb_trace_count++;
            }
            if (dumping()) {
                std::fprintf(stderr, "[cimg] addr 0x%06X fmt %u siz %u width %u (zimg 0x%06X) scissor (%u,%u)-(%u,%u)\n", addr, fmt, siz, width, zimg_addr,
                    scissor_ulx / 4, scissor_uly / 4, scissor_lrx / 4, scissor_lry / 4);
            }
            cimg.addr = addr;
            cimg.fmt = fmt;
            cimg.siz = siz;
            cimg.width = width;
            // Only RGBA images wide enough to be a screen are drawn: the small ones the
            // game makes (copies of depth samples read back by the CPU) aren't.
            // 8-bit images are drawn too: the game renders characters' shadows into one and
            // uses it as a texture.
            const bool drawable = (fmt == FMT_RGBA && (siz == SIZ_16b || siz == SIZ_32b) && width >= 64) ||
                ((fmt == FMT_I || fmt == FMT_CI) && siz == SIZ_8b && width >= 8 && width <= 256);
            // The depth buffer's memory too: the pause menu copies the frame there (fills
            // of it while it's the depth buffer are depth clears, in fill_rectangle).
            if (drawable) {
                current_fb = get_framebuffer(addr, width, siz);
            }
            else {
                current_fb = nullptr;
            }
            state_dirty = true;
        }

        Framebuffer* get_framebuffer(uint32_t addr, uint32_t width, uint32_t siz) {
            // Screens (not the small images the game renders effects into) widen.
            const bool screen = (siz == SIZ_16b || siz == SIZ_32b) && width >= 256;
            const float ratio = screen ? conker::vita_widescreen_ratio() : 1.0f;
            const uint32_t gl_width = std::max<uint32_t>(width, (uint32_t)std::lround(width * ratio / 2.0f) * 2);
            auto it = framebuffers.find(addr);
            if (it != framebuffers.end() && it->second.width == width && it->second.gl_width == gl_width) {
                it->second.last_used = present_count; // also an image only filled (the depth buffer's)
                return &it->second;
            }
            if (it != framebuffers.end()) {
                release_framebuffer(it->second);
                framebuffers.erase(it);
            }
            Framebuffer fb;
            fb.addr = addr;
            fb.width = width;
            // A screen is 4:3; the small images the game draws (shadows) are square.
            fb.height = (siz == SIZ_8b || width <= 128) ? width : (width * 3) / 4;
            fb.siz = siz;
            fb.gl_width = gl_width;
            fb.off = (gl_width - width) * 0.5f;
            fb.last_used = present_count;
            fb.tex = new_tex_id();
            fb.fbo = next_fbo_id++;
            enqueue([fbo = fb.fbo, tex = fb.tex, w = fb.gl_width, h = fb.height](Backend& b, CommandList&) {
                b.create_framebuffer(fbo, tex, w, h, true);
            });
            std::fprintf(stderr, "[renderer] framebuffer 0x%06X %ux%u (GL %u wide)\n", addr, fb.width, fb.height, fb.gl_width);
            auto [inserted, _] = framebuffers.emplace(addr, fb);
            return &inserted->second;
        }

        // Frees a framebuffer's GL objects and forgets what points at it (the caller erases it).
        void release_framebuffer(Framebuffer& fb) {
            const Framebuffer old = fb;
            enqueue([old](Backend& b, CommandList&) {
                b.delete_framebuffer(old.fbo);
                b.delete_texture(old.tex);
                if (old.snapshot_tex) {
                    b.delete_framebuffer(old.snapshot_fbo);
                    b.delete_texture(old.snapshot_tex);
                }
            });
            free_tex_ids.push_back(old.tex);
            if (old.snapshot_tex) free_tex_ids.push_back(old.snapshot_tex);
            if (old.real_tex) {
                enqueue([fbo = old.real_fbo, tex = old.real_tex](Backend& b, CommandList&) {
                    b.delete_framebuffer(fbo);
                    b.delete_texture(tex);
                });
                free_tex_ids.push_back(old.real_tex);
            }
            if (interp_main == &fb) interp_main = nullptr;
            if (current_fb == &fb) current_fb = nullptr;
            if (batch_state.fb == &fb) batch_state.fb = nullptr;
            for (FbLoad& l : fb_loads) {
                if (l.fb == &fb) l = FbLoad{};
            }
            // Tiles may still name its texture.
            for (TileTexture& tt : tile_textures) {
                tt.generation = ~0u;
            }
            state_dirty = true;
        }

        // Framebuffers the game stopped using (another area's, a cutscene's): each holds a
        // texture (and maybe a snapshot) in video memory, and every area change left more
        // behind until textures failed to load (black) and the game crashed.
        void evict_framebuffers(const Framebuffer* shown) {
            constexpr uint32_t max_idle = 600; // presents (20 s at 30 frames a second)
            for (auto it = framebuffers.begin(); it != framebuffers.end();) {
                Framebuffer& fb = it->second;
                const uint32_t used = std::max(fb.last_drawn, fb.last_used);
                if (&fb != shown && &fb != current_fb && present_count - used > max_idle) {
                    std::fprintf(stderr, "[renderer] freeing framebuffer 0x%06X %ux%u (idle %u presents)\n",
                        fb.addr, fb.width, fb.height, present_count - used);
                    release_framebuffer(fb);
                    it = framebuffers.erase(it);
                }
                else {
                    ++it;
                }
            }
        }

        // ======================================================== framebuffer textures
        // A load into TMEM from a framebuffer the GPU drew: what's in TMEM is only in the
        // GL texture, so tiles reading it sample that instead.
        struct FbLoad {
            bool valid = false;
            uint32_t tmem = 0;     // TMEM word address loaded to
            Framebuffer* fb = nullptr;
            int32_t x0 = 0, y0 = 0; // the framebuffer pixel at the start of the load
            uint32_t generation = 0;
            uint32_t tex = 0;      // the texture to sample (the image's, or its snapshot)
        };
        std::array<FbLoad, 8> fb_loads{};

        uint32_t rdram_signature(const Framebuffer& fb) const {
            const uint32_t bpp = fb.siz == SIZ_32b ? 4 : fb.siz == SIZ_16b ? 2 : 1;
            const uint32_t rows = fb.rows_drawn ? fb.rows_drawn : fb.height;
            const uint32_t bytes = fb.width * rows * bpp;
            uint32_t h = 0x811C9DC5u;
            // Every 64th byte: enough to see the CPU writing over it.
            for (uint32_t o = 0; o + 4 <= bytes; o += 64) {
                h = (h ^ read32(rdram, fb.addr + o)) * 0x01000193u;
            }
            return h;
        }

        // Takes the signatures of the images the GPU drew since the last call.
        void settle_signatures() {
            for (auto& [base, fb] : framebuffers) {
                if (fb.sig_pending) {
                    fb.rdram_sig = rdram_signature(fb);
                    fb.sig_pending = false;
                    fb.gpu_valid = true;
                }
            }
        }

        // The image an address is in: the one starting closest below it (they can sit end
        // to end, and their heights are guesses).
        Framebuffer* framebuffer_containing(uint32_t addr) {
            Framebuffer* best = nullptr;
            for (auto& [base, fb] : framebuffers) {
                const uint32_t bpp = fb.siz == SIZ_32b ? 4 : fb.siz == SIZ_16b ? 2 : 1;
                // Only the rows the GPU drew: the game's depth probes set a whole screen's
                // width on a few pixels' worth of memory, and the textures right after them
                // were taken for the probe's image (black, model to model as the camera turned).
                const uint32_t rows = std::min(fb.rows_drawn, fb.height);
                if (rows == 0 || addr < base || addr >= base + fb.width * rows * bpp) continue;
                if (best == nullptr || base > best->addr) best = &fb;
            }
            return best;
        }

        Framebuffer* drawn_framebuffer_at(uint32_t addr) {
            Framebuffer* fb = framebuffer_containing(addr);
            if (fb == nullptr) return nullptr;
            if (fb->sig_pending) return fb; // being drawn in this display list
            // Only one drawn lately: the GPU's drawing never reaches RDRAM, so memory an image
            // once used and the game filled with textures since keeps its signature, and every
            // texture loaded from there came out as that old (black) image: models and windmill
            // sails black in some sessions, whichever addresses a cutscene had drawn to.
            if (present_count - fb->last_drawn > 4) {
                fb->gpu_valid = false;
                return nullptr;
            }
            if (fb->gpu_valid && rdram_signature(*fb) == fb->rdram_sig) return fb;
            fb->gpu_valid = false;
            return nullptr;
        }

        bool note_tmem_load(const Tile& t, uint32_t uls, uint32_t ult, bool block) {
            // Loads overwrite what an earlier framebuffer load put at the same place.
            for (FbLoad& l : fb_loads) {
                if (l.valid && l.tmem == t.tmem) l.valid = false;
            }
            Framebuffer* fb = drawn_framebuffer_at(timg.addr);
            if (fb_trace && fb_trace_count < 5000) {
                for (auto& [base, f] : framebuffers) {
                    const uint32_t bpp = f.siz == SIZ_32b ? 4 : f.siz == SIZ_16b ? 2 : 1;
                    if (timg.addr >= base && timg.addr < base + f.width * f.height * bpp) {
                        std::fprintf(stderr, "[fbtex] dl %u load from 0x%06X in fb 0x%06X: %s (valid %d pending %d drawn %u)\n", dl_count, timg.addr, base,
                            fb ? "gpu" : "rdram", f.gpu_valid, f.sig_pending, f.last_drawn);
                        fb_trace_count++;
                    }
                }
            }
            if (fb == nullptr) {
                return false;
            }
            // Pixels flushed so far are what the load sees.
            flush();
            fb->last_used = present_count;
            const uint32_t bpp = fb->siz == SIZ_32b ? 4 : fb->siz == SIZ_16b ? 2 : 1;
            const uint32_t pixel = (timg.addr - fb->addr) / bpp;
            int32_t x0 = (int32_t)(pixel % fb->width), y0 = (int32_t)(pixel / fb->width);
            if (!block) {
                // LoadTile's rectangle is in the image's own texels (timg.width wide).
                const uint32_t tbpp = (4u << timg.siz) / 8;
                const uint32_t img_w_pixels = tbpp ? (timg.width * tbpp) / bpp : fb->width;
                (void)img_w_pixels;
                x0 += (int32_t)((uls >> 2) * (tbpp ? tbpp : 1) / bpp);
                y0 += (int32_t)(ult >> 2);
            }
            const uint32_t tex = fb == current_fb ? snapshot(fb) : fb->tex;
            for (FbLoad& l : fb_loads) {
                if (!l.valid) {
                    l = FbLoad{ true, t.tmem, fb, x0, y0, tmem.generation, tex };
                    return true;
                }
            }
            fb_loads[0] = FbLoad{ true, t.tmem, fb, x0, y0, tmem.generation, tex };
            return true;
        }

        // Copies a framebuffer's image to its snapshot texture (on the GPU) and returns it.
        uint32_t snapshot(Framebuffer* fb) {
            if (fb->snapshot_tex == 0) {
                fb->snapshot_tex = new_tex_id();
                fb->snapshot_fbo = next_fbo_id++;
            }
            enqueue([src = fb->tex, fbo = fb->snapshot_fbo, tex = fb->snapshot_tex, w = fb->gl_width, h = fb->height](Backend& b, CommandList&) {
                b.copy_texture(src, fbo, tex, w, h);
            });
            return fb->snapshot_tex;
        }

        // The tile reads a framebuffer: bind its texture, its coordinates mapped onto it.
        bool framebuffer_tile(TileTexture& tt, const Tile& tile) {
            for (const FbLoad& l : fb_loads) {
                if (!l.valid || l.tmem != tile.tmem || l.fb == nullptr) continue;
                const Framebuffer* fb = l.fb;
                const float w = (float)fb->gl_width, h = (float)fb->height;
                tt.tex = l.tex ? l.tex : fb->tex;
                tt.width = w;
                tt.inv_width = 1.0f / w;
                tt.uls = tile.uls / 4.0f - (float)l.x0 - fb->off;
                // GL's rows go up: v = 1 - y / h.
                tt.height = -h;
                tt.inv_height = -1.0f / h;
                tt.ult = tile.ult / 4.0f - (float)l.y0 + h;
                tt.offset = 0.5f;
                tt.intensity = fb->siz == SIZ_8b;
                tt.wide_fb = fb->gl_width > fb->width;
                return true;
            }
            return false;
        }

        // ======================================================== textures
        // Binds the texture tile index would sample, or white when texturing is off.
        void update_tile_texture(uint32_t index) {
            PartTimer part_timer(*this, P_TILE);
            TileTexture& tt = tile_textures[index];
            const Tile& tile = tiles[index];
            const uint32_t tlut = (other_mode_h >> OMH_TLUT_SHIFT) & 3;
            const uint32_t filter = (other_mode_h >> OMH_FILTER_SHIFT) & 3;
            if (tt.generation == tmem.generation && std::memcmp(&tt.tile, &tile, sizeof(Tile)) == 0 &&
                tt.tlut == tlut && tt.filter == filter) {
                return;
            }
            tt.generation = tmem.generation;
            tt.tile = tile;
            tt.tlut = tlut;
            tt.filter = filter;
            tt.intensity = false;
            tt.wide_fb = false;

            uint32_t tile_w = (((uint32_t)tile.lrs >> 2) - ((uint32_t)tile.uls >> 2) + 1) & 0x3FF;
            uint32_t tile_h = (((uint32_t)tile.lrt >> 2) - ((uint32_t)tile.ult >> 2) + 1) & 0x3FF;
            if (tile_w == 0) tile_w = 1;
            if (tile_h == 0) tile_h = 1;
            uint32_t w = tile_w, h = tile_h;
            GLenum wrap_s = GL_CLAMP_TO_EDGE, wrap_t = GL_CLAMP_TO_EDGE;
            if (tile.masks) {
                const uint32_t mw = 1u << std::min<uint32_t>(tile.masks, 10);
                if (!(tile.cms & 2) || tile_w > mw) {
                    w = mw;
                    wrap_s = (tile.cms & 1) ? GL_MIRRORED_REPEAT : GL_REPEAT;
                }
            }
            if (tile.maskt) {
                const uint32_t mh = 1u << std::min<uint32_t>(tile.maskt, 10);
                if (!(tile.cmt & 2) || tile_h > mh) {
                    h = mh;
                    wrap_t = (tile.cmt & 1) ? GL_MIRRORED_REPEAT : GL_REPEAT;
                }
            }
            w = std::min<uint32_t>(w, 1024);
            h = std::min<uint32_t>(h, 1024);

            auto shift_factor = [](uint32_t shift) {
                if (shift == 0) return 1.0f;
                if (shift <= 10) return 1.0f / (float)(1u << shift);
                return (float)(1u << (16 - shift));
            };
            tt.shift_s = shift_factor(tile.shifts);
            tt.shift_t = shift_factor(tile.shiftt);
            if (framebuffer_tile(tt, tile)) {
                return;
            }
            tt.uls = tile.uls / 4.0f;
            tt.ult = tile.ult / 4.0f;
            tt.width = (float)w;
            tt.height = (float)h;
            tt.inv_width = 1.0f / (float)w;
            tt.inv_height = 1.0f / (float)h;
            const bool linear = filter == 2 || filter == 3;
            tt.offset = linear ? 0.5f : 0.0f;

            if (tmem.tlut_dirty_lo <= tmem.tlut_dirty_hi && tile_reads_upper(tile, h)) {
                sync_tlut_mirror(tmem);
            }
            const uint32_t hash = hash_tile(tmem, tile, w, h, tlut);
            const uint64_t key = ((uint64_t)hash << 32) ^ ((uint64_t)w << 20) ^ ((uint64_t)h << 8) ^
                ((uint64_t)(wrap_s == GL_REPEAT ? 1 : wrap_s == GL_MIRRORED_REPEAT ? 2 : 0) << 4) ^
                ((uint64_t)(wrap_t == GL_REPEAT ? 1 : wrap_t == GL_MIRRORED_REPEAT ? 2 : 0) << 6) ^ (linear ? 1 : 0);
            if (CachedTexture* cached = texture_cache.find(key)) {
                cached->last_used = present_count;
                tt.tex = cached->tex;
                if (dumping()) {
                    std::vector<uint32_t> check((size_t)w * h);
                    decode_tile(tmem, tile, w, h, tlut, check.data());
                    uint32_t opaque = 0, clear = 0;
                    for (uint32_t c : check) { const uint32_t a = c >> 24; opaque += a == 255; clear += a == 0; }
                    std::fprintf(stderr, "[tex] hit id=%u hash=%08X fmt%u siz%u %ux%u tlut%u pal%u tmem%u alpha: %u opaque %u clear of %u\n",
                        cached->tex, hash, tile.fmt, tile.siz, w, h, tlut, tile.palette, tile.tmem, opaque, clear, w * h);
                }
                return;
            }
            const uint64_t tex_start = sceKernelGetProcessTimeWide();
            std::vector<uint32_t> texels((size_t)w * h);
            decode_tile(tmem, tile, w, h, tlut, texels.data());
            // Decoded here (TMEM is the front's), uploaded by the GL thread.
            const uint32_t tex = new_tex_id();
            if (dumping()) {
                uint32_t opaque = 0, clear = 0;
                for (uint32_t c : texels) { const uint32_t a = c >> 24; opaque += a == 255; clear += a == 0; }
                std::fprintf(stderr, "[tex] new id=%u hash=%08X fmt%u siz%u %ux%u tlut%u pal%u tmem%u alpha: %u opaque %u clear of %u\n",
                    tex, hash, tile.fmt, tile.siz, w, h, tlut, tile.palette, tile.tmem, opaque, clear, w * h);
            }
            enqueue([tex, w, h, texels = std::move(texels), linear, wrap_s, wrap_t](Backend& b, CommandList&) {
                b.upload_texture(tex, w, h, texels.data(), linear, wrap_s, wrap_t);
            });
            const uint32_t bytes = ((w + 7) & ~7u) * h * 4;
            texture_cache.insert(key, CachedTexture{ tex, present_count, bytes });
            texture_bytes += bytes;
            tt.tex = tex;
            if (dump_textures && dumped_textures < 600) {
                char path[160];
                std::snprintf(path, sizeof(path), CONKER_VITA_DATA_DIR "/tex/gl%04u_f%u_s%u_%ux%u_tlut%u.ppm", tex, tile.fmt, tile.siz, w, h, tlut);
                if (FILE* f = std::fopen(path, "wb")) {
                    std::fprintf(f, "P6\n%u %u\n255\n", w, h * 2);
                    for (uint32_t i = 0; i < w * h; i++) std::fwrite(&texels[i], 1, 3, f);
                    for (uint32_t i = 0; i < w * h; i++) { uint8_t a = texels[i] >> 24; uint8_t g[3] = {a, a, a}; std::fwrite(g, 1, 3, f); }
                    std::fclose(f);
                }
                dumped_textures++;
            }
            stats.textures++;
            stats.texture_us += (uint32_t)(sceKernelGetProcessTimeWide() - tex_start);
        }

        // The decoded textures' video memory: past this, the ones unused for a while go
        // (with the framebuffers, it must fit the back's heap, 96 MB at most).
        static constexpr uint32_t texture_budget = 40u << 20;
        uint32_t texture_bytes = 0;
        uint32_t last_evict = 0;

        void evict_textures() {
            if (texture_cache.size() < 2048 && texture_bytes < texture_budget) {
                return;
            }
            // Over the budget with everything in use: not again for a second.
            if (present_count - last_evict < 30) {
                return;
            }
            last_evict = present_count;
            const size_t before = texture_cache.size();
            const uint32_t bytes_before = texture_bytes;
            texture_cache.filter([this](const CachedTexture& t) {
                if (present_count - t.last_used <= 120) return true;
                enqueue([tex = t.tex](Backend& b, CommandList&) { b.delete_texture(tex); });
                free_tex_ids.push_back(t.tex);
                texture_bytes -= t.bytes;
                return false;
            });
            if (before != texture_cache.size()) std::fprintf(stderr, "[renderer] freed %u textures (%u KB); %u left (%u KB)\n",
                (unsigned)(before - texture_cache.size()), (bytes_before - texture_bytes) >> 10,
                (unsigned)texture_cache.size(), texture_bytes >> 10);
            // Tiles may still name deleted textures.
            for (TileTexture& tt : tile_textures) {
                tt.generation = ~0u;
            }
        }

        // ======================================================== shaders
        bool dump_textures = [] {
            if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_dump_textures", "r")) {
                std::fclose(f);
                std::filesystem::create_directories(CONKER_VITA_DATA_DIR "/tex");
                return true;
            }
            return false;
        }();
        uint32_t dumped_textures = 0;
        // debug_flags: 1 no clip rejection, 2 no culling, 4 no depth test; the output of
        // the combiner's draws: 32 the first texture only, 64 the shade only, 128 without
        // the blender; 256 the GPU finishes each display list. From the file debug_flags
        // and the menu's Debug page.
        uint32_t file_debug_flags = [] {
            uint32_t n = 0;
            if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_flags", "r")) {
                if (std::fscanf(f, "%u", &n) != 1) n = 0;
                std::fclose(f);
            }
            return n;
        }();
        // debug_dump_dl holds the number of a display list whose draws are logged.
        // "t<seconds>": the first display list after that many seconds of running. A second
        // number logs that many display lists from there.
        double dump_at_s = -1;
        uint32_t dump_count = 1;
        uint32_t dump_dl = [this] {
            uint32_t n = ~0u;
            if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_dump_dl", "r")) {
                char text[32] = {};
                if (std::fscanf(f, "%31s", text) == 1) {
                    if (text[0] == 't') dump_at_s = std::atof(text + 1);
                    else n = (uint32_t)std::atoi(text);
                }
                if (std::fscanf(f, "%u", &dump_count) != 1 || dump_count == 0) dump_count = 1;
                std::fclose(f);
            }
            return n;
        }();
        bool dumping() const { return dump_dl != ~0u && dl_count - dump_dl < dump_count; }

        uint32_t debug_flags = file_debug_flags;
        // Programs made with other flags: kept (draw states point at them), not used.
        std::vector<std::unordered_map<ShaderKey, Program, ShaderKeyHash>> retired_programs;

        const bool ab_on = [] {
            FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_ab", "r");
            if (f) std::fclose(f);
            return f != nullptr;
        }();
        uint32_t ab_phase = 0, ab_count = 0, ab_lists[4] = {};
        uint64_t ab_us[4] = {};

        void update_debug_flags() {
            const uint32_t flags = file_debug_flags | conker::vita::menu::debug_flags();
            if (flags == debug_flags) return;
            std::fprintf(stderr, "[renderer] debug flags %u\n", flags);
            debug_flags = flags;
            retired_programs.push_back(std::move(programs));
            programs = {};
            last_program = nullptr;
            last_program_key = ShaderKey{ ~0u, ~0u, ~0u };
            state_dirty = true;
        }

        ShaderKey last_program_key{ ~0u, ~0u, ~0u };
        Program* last_program = nullptr;

        Program* get_program(const ShaderKey& key) {
            // Most draws keep the last program: no lookup (its hashing divides).
            if (last_program != nullptr && key == last_program_key) {
                return last_program;
            }
            last_program = find_program(key);
            last_program_key = key;
            return last_program;
        }

        Program* find_program(const ShaderKey& key) {
            auto it = programs.find(key);
            if (it != programs.end()) {
                return &it->second;
            }
            const uint64_t compile_start = sceKernelGetProcessTimeWide();
            Program p;
            const uint32_t cycle = key.other & KEY_CYCLE_MASK;
            const uint32_t alpha_mode = (key.other >> KEY_ALPHA_MASK_SHIFT) & 3;
            const uint32_t blend_mode = (key.other >> KEY_BLEND_MODE_SHIFT) & 3;
            const uint32_t blender = key.other >> KEY_BLENDER_SHIFT;
            std::string fs =
                "uniform sampler2D uTex0;\n"
                "uniform sampler2D uTex1;\n"
                "uniform vec4 uPrim;\n"
                "uniform vec4 uEnv;\n"
                "uniform vec4 uFog;\n"
                "uniform vec4 uBlend;\n"
                "uniform vec4 uFill;\n"
                "uniform float uPrimLod;\n"
                "uniform vec2 uConvert;\n"
                "uniform vec2 uTexI;\n"
                "varying vec4 vColor;\n"
                "varying vec4 vUV;\n"
                "void main() {\n";
            if (cycle == CYCLE_FILL) {
                fs += "  gl_FragColor = uFill;\n}\n";
            }
            else if (cycle == CYCLE_COPY) {
                p.uses_t0 = true;
                fs += "  vec4 t0 = texture2D(uTex0, vUV.xy);\n";
                if (alpha_mode != 0) {
                    fs += "  if (t0.a < 0.5) discard;\n";
                }
                fs += "  gl_FragColor = t0;\n}\n";
            }
            else {
                CombinerCycle cycles[2];
                decode_combine(key.cc0, key.cc1, cycles);
                const bool two = cycle == CYCLE_2;
                // One cycle uses the second cycle's settings.
                const CombinerCycle& first = two ? cycles[0] : cycles[1];
                p.uses_t0 = (debug_flags & 32) || cycle_uses_texel(first, 0, false) || (two && cycle_uses_texel(cycles[1], 0, !(debug_flags & 16)));
                p.uses_t1 = cycle_uses_texel(first, 1, false) || (two && cycle_uses_texel(cycles[1], 1, !(debug_flags & 16)));
                fs += p.uses_t0 ? "  vec4 t0 = texture2D(uTex0, vUV.xy);\n  t0 = mix(t0, t0.rrrr, uTexI.x);\n" : "  vec4 t0 = vec4(1.0);\n";
                fs += p.uses_t1 ? "  vec4 t1 = texture2D(uTex1, vUV.zw);\n  t1 = mix(t1, t1.rrrr, uTexI.y);\n" : "  vec4 t1 = vec4(1.0);\n";
                fs += "  vec4 shade = vColor;\n"
                      "  float lodfrac = 0.0;\n"
                      "  float noise = fract(sin(dot(vUV.xy + shade.rg, vec2(12.9898, 78.233))) * 43758.5453);\n"
                      "  vec4 comb = vec4(0.0);\n";
                const bool swap_second = !(debug_flags & 16);
                fs += cycle_source(first, false);
                if (two) {
                    fs += cycle_source(cycles[1], swap_second);
                }
                // Alpha compare.
                if (alpha_mode == 1) {
                    fs += "  if (comb.a < max(uBlend.a, 0.0039)) discard;\n";
                }
                else if (alpha_mode == 2) {
                    fs += "  if (comb.a < 0.5) discard;\n";
                }
                else if (alpha_mode == 3) {
                    fs += "  if (comb.a < 0.125) discard;\n";
                }
                // Blender: the first cycle of a 2-cycle mode (fog, mostly) runs here.
                std::string color = "comb.rgb";
                const uint32_t p0 = (blender >> 14) & 3, a0 = (blender >> 10) & 3, m0 = (blender >> 6) & 3, b0 = (blender >> 2) & 3;
                const uint32_t p1 = (blender >> 12) & 3, a1 = (blender >> 8) & 3, m1 = (blender >> 4) & 3, b1 = blender & 3;
                auto formula = [&](uint32_t pp, uint32_t aa, uint32_t mm, uint32_t bb, const std::string& in) {
                    std::string av = blend_alpha_a(aa);
                    std::string bv = bb == 0 ? "(1.0 - " + av + ")" : bb == 1 ? "(1.0 - " + av + ")" : bb == 2 ? "1.0" : "0.0";
                    return "(" + blender_input(pp, in) + " * " + av + " + " + blender_input(mm, in) + " * " + bv + ")";
                };
                if (two) {
                    fs += "  vec3 blended = " + formula(p0, a0, m0, b0, "comb.rgb") + ";\n";
                    color = "blended";
                }
                // The last cycle.
                const uint32_t pl = two ? p1 : p0, al = two ? a1 : a0, ml = two ? m1 : m0, bl = two ? b1 : b0;
                if (blend_mode == 1) {
                    fs += "  gl_FragColor = vec4(" + formula(pl, al, ml, bl, color) + ", comb.a);\n";
                }
                else if (blend_mode == 2) {
                    // GL blends: the colour is P, its alpha A.
                    fs += "  gl_FragColor = vec4(" + blender_input(pl, color) + ", " + blend_alpha_a(al) + ");\n";
                }
                else {
                    fs += "  gl_FragColor = vec4(" + blender_input(pl, color) + ", comb.a);\n";
                }
                if (debug_flags & 32) fs += "  gl_FragColor = vec4(t0.rgb, 1.0);\n";
                else if (debug_flags & 64) fs += "  gl_FragColor = vec4(shade.rgb, 1.0);\n";
                else if (debug_flags & 128) fs += "  gl_FragColor = comb;\n";
                fs += "}\n";
            }

#if defined(CONKER_DEBUG_FLAT)
            fs = "varying vec4 vColor;\nvarying vec4 vUV;\nvoid main() { gl_FragColor = vec4(1.0, vColor.g * 0.5, vUV.x, 1.0); }\n";
#endif
            // Compiled (or loaded from the cache) by the GL thread.
            p.id = next_program_id++;
            enqueue([id = p.id, fs = std::move(fs)](Backend& b, CommandList&) { b.create_program(id, fs); });
            stats.programs++;
            stats.program_us += (uint32_t)(sceKernelGetProcessTimeWide() - compile_start);
            auto [inserted, _] = programs.emplace(key, p);
            return &inserted->second;
        }

        // ======================================================== draw state
        // Works the state out for a draw (a rectangle if rect), flushing the batch when
        // it changed. False if there's nothing to draw into.
        bool prepare_draw(bool rect) {
            if (current_fb == nullptr) {
                return false;
            }
            if (!state_dirty && rect == last_was_rect) {
                return true;
            }
            last_was_rect = rect;
            state_dirty = false;
            stats.prepares++;
            vertex_cache_serial++;
            uv_dirty = true;

            DrawState s;
            s.fb = current_fb;
            const uint32_t cycle = (other_mode_h >> OMH_CYCLE_SHIFT) & 3;
            const uint32_t blender = other_mode_l >> 16;
            const bool force_bl = (other_mode_l & OML_FORCE_BL) != 0;

            // Alpha compare.
            // ALPHA_CVG_SEL makes the alpha the pixel's coverage: without blending, a pixel
            // with none isn't written (cut-out textures, such as faces' layers). With
            // CVG_X_ALPHA it's alpha times the edge coverage, as for leaves.
            uint32_t alpha_mode = 0;
            if ((other_mode_l & OML_ALPHA_COMPARE_MASK) == 1) {
                alpha_mode = 1;
            }
            else if ((other_mode_l & OML_ALPHA_CVG_SEL) && !force_bl) {
                // Coverage as the alpha: only times the alpha (CVG_X_ALPHA) can a pixel lose
                // its coverage (RT64's RasterPS). On its own the combiner's alpha plays no part:
                // the water's is its fog, and discarding by it made rivers vanish as the camera
                // moved.
                alpha_mode = (other_mode_l & OML_CVG_X_ALPHA) ? 2 : 0;
            }
            else if ((other_mode_l & OML_CVG_X_ALPHA) && !force_bl) {
                // The coverage times the alpha: under 1/8 nothing is covered, nothing
                // written (the iris that closes the intro's scenes is drawn so).
                alpha_mode = 3;
            }

            // Blending, from the last cycle's formula.
            const bool two = cycle == CYCLE_2;
            const uint32_t pl = two ? (blender >> 12) & 3 : (blender >> 14) & 3;
            const uint32_t al = two ? (blender >> 8) & 3 : (blender >> 10) & 3;
            const uint32_t ml = two ? (blender >> 4) & 3 : (blender >> 6) & 3;
            const uint32_t bl = two ? blender & 3 : (blender >> 2) & 3;
            uint32_t blend_mode = 0;
            if (cycle == CYCLE_1 || cycle == CYCLE_2) {
                if (force_bl) {
                    if (ml == 1 && pl != 1) {
                        blend_mode = 2;
                        s.blend = true;
                        s.blend_src = GL_SRC_ALPHA;
                        s.blend_dst = (bl == 2) ? GL_ONE : (bl == 3) ? GL_ZERO : GL_ONE_MINUS_SRC_ALPHA;
                        if (al == 3 && bl == 2) {
                            // P * 0 + memory: the colour stays as it is.
                            s.color_write = false;
                        }
                    }
                    else if (pl == 1 && ml != 1) {
                        // Memory first: blend the other way round.
                        blend_mode = 2;
                        s.blend = true;
                        s.blend_src = GL_ONE_MINUS_SRC_ALPHA;
                        s.blend_dst = GL_SRC_ALPHA;
                    }
                    else if (pl != 1 && ml != 1) {
                        blend_mode = 1;
                    }
                }
            }

            ShaderKey key;
            if (cycle == CYCLE_COPY || cycle == CYCLE_FILL) {
                key = { 0, 0, cycle | ((other_mode_l & OML_ALPHA_COMPARE_MASK) ? (1u << KEY_ALPHA_MASK_SHIFT) : 0) };
                s.blend = false;
            }
            else {
                key = { combine_w0, combine_w1, cycle | (alpha_mode << KEY_ALPHA_MASK_SHIFT) |
                    (blend_mode << KEY_BLEND_MODE_SHIFT) | (blender << KEY_BLENDER_SHIFT) };
            }
            s.program = get_program(key);

            // Textures: the texture command's tile for triangles, the rectangle's own.
            const uint32_t base_tile = rect ? rect_tile : texture.tile;
            const bool texturing = rect || texture.on;
            for (int i = 0; i < 2; i++) {
                const bool used = i == 0 ? s.program->uses_t0 : s.program->uses_t1;
                const uint32_t index = (base_tile + i) & 7;
                if (used && texturing) {
                    update_tile_texture(index);
                    s.tex[i] = tile_textures[index].tex;
                    s.tex_intensity[i] = tile_textures[index].intensity ? 1.0f : 0.0f;
                }
                else {
                    s.tex[i] = white_tex;
                }
            }

            // Depth.
            const bool zbuffer = rect || (geometry_mode & G_ZBUFFER);
            s.depth_test = zbuffer && (other_mode_l & OML_Z_CMP) && cycle != CYCLE_COPY && cycle != CYCLE_FILL;
            s.depth_write = zbuffer && (other_mode_l & OML_Z_UPD) && cycle != CYCLE_COPY && cycle != CYCLE_FILL;
            s.decal = ((other_mode_l >> OML_ZMODE_SHIFT) & 3) == 3;
            s.depth_func = GL_LEQUAL;

            // Scissor, in the framebuffer's pixels (GL's origin is at the bottom).
            // A scissor across the frame widens with it (as RT64's); others stay in the 4:3.
            int sx0, sx1;
            if (scissor_ulx <= 16 && scissor_lrx >= (current_fb->width - 4) * 4) {
                sx0 = 0;
                sx1 = (int)(current_fb->gl_width * render_scale);
            }
            else {
                sx0 = (int)((scissor_ulx / 4.0f + current_fb->off) * render_scale);
                sx1 = (int)((scissor_lrx / 4.0f + current_fb->off) * render_scale);
            }
            const int sy0 = (int)(scissor_uly * render_scale / 4), sy1 = (int)(scissor_lry * render_scale / 4);
            const int fb_h = (int)(current_fb->height * render_scale);
            s.scissor[0] = std::max(sx0, 0);
            s.scissor[1] = std::max(fb_h - sy1, 0);
            s.scissor[2] = std::max(sx1 - sx0, 0);
            s.scissor[3] = std::max(sy1 - sy0, 0);

            color_from_word(prim_color, s.prim);
            color_from_word(env_color, s.env);
            color_from_word(fog_color, s.fog);
            color_from_word(blend_color, s.blendc);
            color_from_word(fill_color, s.fill);
            s.primlod = prim_lod_frac / 255.0f;
            s.convert[0] = convert_k4 / 255.0f;
            s.convert[1] = convert_k5 / 255.0f;

            s.dbg_cc0 = combine_w0; s.dbg_cc1 = combine_w1; s.dbg_omh = other_mode_h; s.dbg_oml = other_mode_l;
            s.dbg_geo = geometry_mode | (cbfd_lighting ? G_LIGHTING : 0) | (cbfd_texgen ? G_TEXTURE_GEN : 0);
            s.dbg_tile = base_tile;
            s.dbg_t0 = tiles[base_tile & 7];
            if (!(s == batch_state)) {
                flush();
            }
            batch_state = s;
            return true;
        }
        bool last_was_rect = false;

        void flush() {
            const bool deferred_tris = batch_deferred && list->tris.size() > tri_base;
            if (batch.empty() && !deferred_tris) {
                batch_deferred = false;
                return;
            }
            PartTimer part_timer(*this, P_FLUSH);
            const DrawState& s = batch_state;
            if (s.fb == nullptr || s.program == nullptr) {
                batch.clear();
                drop_deferred();
                vertex_cache_serial++;
                return;
            }
            s.fb->last_drawn = present_count;
            s.fb->sig_pending = true;
            s.fb->drawn_this_dl = true;
            if (!interp_pass) {
                s.fb->interp_ready = false;
                s.fb->showing_real = false;
            }
            if ((debug_flags & 4096) && s.dbg_cc0 == 0x26A004 && s.blend) s.fb->water_draws++;
            mark_drawn(s.fb, s.scissor);

            // Debug (flag 131072): no projected shadows (combiner FFE9FF), to tell them apart.
            if ((debug_flags & 131072) && s.dbg_cc0 == 0xFFE9FF) {
                batch.clear();
                drop_deferred();
                vertex_cache_serial++;
                return;
            }
            DrawCmd& d = list->draws.emplace_back();
            d.fbo = s.fb->fbo;
            d.fb_w = s.fb->gl_width;
            d.fb_h = s.fb->height;
            d.program = s.program->id;
            d.tex[0] = s.tex[0];
            d.tex[1] = s.tex[1];
            d.tex_intensity[0] = s.tex_intensity[0];
            d.tex_intensity[1] = s.tex_intensity[1];
            d.blend = s.blend;
            d.blend_src = s.blend_src;
            d.blend_dst = s.blend_dst;
            d.color_write = s.color_write;
            d.depth_test = s.depth_test;
            d.depth_write = s.depth_write;
#if defined(CONKER_DEBUG_FLAT)
            d.depth_test = false;
            d.depth_write = false;
#endif
            if (debug_flags & 4) {
                d.depth_test = false;
                d.depth_write = false;
            }
            d.decal = s.decal;
            d.strong_decal = (debug_flags & 262144) != 0;
            d.depth_func = s.depth_func;
            std::memcpy(d.scissor, s.scissor, sizeof(d.scissor));
            std::memcpy(d.prim, s.prim, sizeof(d.prim));
            std::memcpy(d.env, s.env, sizeof(d.env));
            std::memcpy(d.fog, s.fog, sizeof(d.fog));
            std::memcpy(d.blendc, s.blendc, sizeof(d.blendc));
            std::memcpy(d.fill, s.fill, sizeof(d.fill));
            d.primlod = s.primlod;
            d.convert[0] = s.convert[0];
            d.convert[1] = s.convert[1];
            d.vbase = (uint32_t)batch.base;
            d.ibase = (uint32_t)batch.ibase;
            d.icount = (uint32_t)batch.index_count();
            d.vcount = (uint32_t)batch.size();
            d.raw = batch_raw;
            d.debug = dumping();
            if (deferred_tris) {
                d.deferred = true;
                d.tbase = (uint32_t)tri_base;
                d.tcount = (uint32_t)(list->tris.size() - tri_base);
                d.vbase = d.ibase = d.icount = d.vcount = 0;
                tri_base = list->tris.size();
            }
            const uint32_t draw_index = (uint32_t)list->draws.size() - 1;
            enqueue([draw_index](Backend& b, CommandList& l) { b.draw(l, l.draws[draw_index]); });

            if (dumping() && !deferred_tris) {
                GLVertex v{};
                if (batch_raw) {
                    const VertexIn& in = list->vin[batch.base];
                    v.x = in.x; v.y = in.y; v.z = in.z; v.w = in.w;
                    v.color[0] = in.r; v.color[1] = in.g; v.color[2] = in.b; v.color[3] = in.a;
                }
                else {
                    v = batch[0];
                }
                std::fprintf(stderr, "[draw] sc(%d %d %d %d) n=%u cc=%06X:%08X omh=%06X oml=%08X geo=%06X tile=%u t0=%u t1=%u blend=%d(%X,%X) depth=%d/%d prim=%.2f,%.2f,%.2f,%.2f env=%.2f,%.2f,%.2f,%.2f v0 pos(%.2f %.2f %.2f %.2f) col(%u %u %u %u) uv(%.3f %.3f | %.3f %.3f)\n",
                    s.scissor[0], s.scissor[1], s.scissor[2], s.scissor[3], (unsigned)batch.size(), s.dbg_cc0, s.dbg_cc1, s.dbg_omh, s.dbg_oml, s.dbg_geo, s.dbg_tile,
                    s.tex[0], s.tex[1], s.blend, s.blend_src, s.blend_dst, s.depth_test, s.depth_write, s.prim[0], s.prim[1], s.prim[2], s.prim[3], s.env[0], s.env[1], s.env[2], s.env[3],
                    v.x, v.y, v.z, v.w, v.color[0], v.color[1], v.color[2], v.color[3], v.u0, v.v0, v.u1, v.v1);
                if (batch_raw) {
                    float x0 = 1e9f, x1 = -1e9f, y0 = 1e9f, y1 = -1e9f, wmin = 1e9f;
                    for (size_t k = 0; k < batch.size(); k++) {
                        const VertexIn& in = list->vin[batch.base + k];
                        const float iw = std::fabs(in.w) > 1e-6f ? 1.0f / in.w : 0.0f;
                        x0 = std::min(x0, in.x * iw); x1 = std::max(x1, in.x * iw);
                        y0 = std::min(y0, in.y * iw); y1 = std::max(y1, in.y * iw);
                        wmin = std::min(wmin, in.w);
                    }
                    std::fprintf(stderr, "        ndc x[%.2f %.2f] y[%.2f %.2f] wmin %.2f icount %u\n", x0, x1, y0, y1, wmin, (unsigned)batch.index_count());
                }
                const Tile& t = s.dbg_t0;
                std::fprintf(stderr, "        tile%u fmt%u siz%u line%u tmem%u pal%u cms%u masks%u shifts%u cmt%u maskt%u shiftt%u ul(%u,%u) lr(%u,%u) scale(%.3f %.3f)\n",
                    s.dbg_tile & 7, t.fmt, t.siz, t.line, t.tmem, t.palette, t.cms, t.masks, t.shifts, t.cmt, t.maskt, t.shiftt, t.uls, t.ult, t.lrs, t.lrt, texture.scale_s, texture.scale_t);
            }
            stats.draws++;
            stats.verts += batch.size();
            batch.next();
            batch_raw = false;
            batch_deferred = false;
            vertex_cache_serial++;
        }

        void drop_deferred() {
            // Its triangles not drawn; its loads still go into the slots.
            for (size_t i = tri_base; i < list->tris.size(); i++) {
                if (!(list->tris[i].flags & REC_LOAD)) list->tris[i].flags |= TRI_SKIP;
            }
            batch_deferred = false;
        }

        // The pause menu copies the frame into the depth buffer's memory and then blurs that
        // copy with the CPU: what the GPU drew there has to be in RDRAM for it. (Read back
        // after the display list; vitaGL's read back works on the Vita, not in Vita3K.)
        void write_back_framebuffers() {
            for (auto& [base, fb] : framebuffers) {
                const bool wanted = fb.drawn_this_dl && base == zimg_addr && fb.siz == SIZ_16b;
                fb.drawn_this_dl = false;
                if (!wanted) continue;
                // The GL thread reads it back once it has drawn it: the front waits for that.
                enqueue([this, fbo = fb.fbo, w = fb.gl_width, h = fb.height](Backend& b, CommandList&) {
                    b.read_framebuffer(fbo, w, h, writeback_buffer);
                });
                submit();
                backend->wait_idle();
                const int w = (int)fb.gl_width * render_scale, h = (int)fb.height * render_scale;
                const int x_off = (int)(fb.off * render_scale);
                const uint32_t rows = fb.rows_drawn ? fb.rows_drawn : fb.height;
                for (uint32_t y = 0; y < rows; y++) {
                    // GL's rows go up.
                    const uint32_t* src = &writeback_buffer[(size_t)(h - 1 - (int)(y * render_scale)) * w];
                    for (uint32_t x = 0; x < fb.width; x++) {
                        const uint32_t c = src[x_off + x * render_scale];
                        const uint16_t p = (uint16_t)((((c >> 3) & 0x1F) << 11) | (((c >> 11) & 0x1F) << 6) | (((c >> 19) & 0x1F) << 1) | 1);
                        const uint32_t addr = base + (y * fb.width + x) * 2;
                        std::memcpy(game_rdram + ((addr & rdram_mask) ^ 2), &p, 2);
                        if (rdram != game_rdram) std::memcpy(rdram + ((addr & rdram_mask) ^ 2), &p, 2);
                    }
                }
                // RDRAM now holds the picture: the signature follows it.
                fb.rdram_sig = rdram_signature(fb);
                fb.gpu_valid = true;
            }
        }
        std::vector<uint32_t> writeback_buffer;

        void mark_drawn(Framebuffer* fb, const int sc[4]) {
            const float x0 = sc[0] / (float)render_scale, x1 = (sc[0] + sc[2]) / (float)render_scale;
            const float y1 = fb->height - sc[1] / (float)render_scale, y0 = y1 - sc[3] / (float)render_scale;
            fb->drawn_x0 = std::min(fb->drawn_x0, x0);
            fb->drawn_x1 = std::max(fb->drawn_x1, x1);
            fb->drawn_y0 = std::min(fb->drawn_y0, y0);
            fb->drawn_y1 = std::max(fb->drawn_y1, y1);
            fb->rows_drawn = std::max(fb->rows_drawn, std::min(fb->height, (uint32_t)std::ceil(y1)));
        }

        // ======================================================== the menu
        // The menu's triangles, in screen coordinates (empty when it's closed).
        std::vector<GLVertex> menu_vertices() {
            const std::vector<conker::vita::menu::Item> items = conker::vita::menu::draw_list();
            std::vector<GLVertex> v;
            if (items.empty()) {
                return v;
            }
            v.reserve(4096);
            auto to_ndc_x = [](float x) { return x / screen_width * 2.0f - 1.0f; };
            auto to_ndc_y = [](float y) { return 1.0f - y / screen_height * 2.0f; };
            auto quad = [&](float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1, uint32_t c) {
                const uint8_t col[4] = { (uint8_t)(c >> 24), (uint8_t)(c >> 16), (uint8_t)(c >> 8), (uint8_t)c };
                const GLVertex a{ to_ndc_x(x0), to_ndc_y(y0), 0, 1, {col[0], col[1], col[2], col[3]}, u0, v0, 0, 0 };
                const GLVertex b{ to_ndc_x(x1), to_ndc_y(y0), 0, 1, {col[0], col[1], col[2], col[3]}, u1, v0, 0, 0 };
                const GLVertex cc{ to_ndc_x(x0), to_ndc_y(y1), 0, 1, {col[0], col[1], col[2], col[3]}, u0, v1, 0, 0 };
                const GLVertex d{ to_ndc_x(x1), to_ndc_y(y1), 0, 1, {col[0], col[1], col[2], col[3]}, u1, v1, 0, 0 };
                v.push_back(a); v.push_back(b); v.push_back(cc);
                v.push_back(cc); v.push_back(b); v.push_back(d);
            };
            // The solid cell (127) for rectangles.
            const float solid_u = ((127 - 32) % font_cols * font_cell_w + font_cell_w * 0.5f) / font_atlas_width;
            const float solid_v = ((127 - 32) / font_cols * font_cell_h + font_cell_h * 0.5f) / font_atlas_height;
            for (const auto& it : items) {
                if (it.kind == conker::vita::menu::Item::Rect) {
                    quad(it.x, it.y, it.x + it.w, it.y + it.h, solid_u, solid_v, solid_u, solid_v, it.color);
                    continue;
                }
                const float scale = it.w;
                float x = it.x;
                for (char ch : it.text) {
                    const int c = (unsigned char)ch;
                    if (c < 32 || c > 126) continue;
                    const int i = c - 32;
                    const float cu = (float)(i % font_cols * font_cell_w), cv = (float)(i / font_cols * font_cell_h);
                    quad(x, it.y, x + font_cell_w * scale, it.y + font_cell_h * scale,
                         cu / font_atlas_width, cv / font_atlas_height,
                         (cu + font_cell_w) / font_atlas_width, (cv + font_cell_h) / font_atlas_height, it.color);
                    x += font_advance[i] * scale;
                }
            }
            return v;
        }

        // ======================================================== presenting
        // The framebuffer the VI shows: the one starting at or just before its origin.
        Framebuffer* framebuffer_at(uint32_t origin) {
            Framebuffer* shown = nullptr;
            for (auto& [addr, fb] : framebuffers) {
                const uint32_t size = fb.width * fb.height * (fb.siz == SIZ_32b ? 4 : 2);
                if (origin >= addr && origin < addr + size) {
                    if (shown == nullptr || addr > shown->addr) {
                        shown = &fb;
                    }
                }
            }
            return shown;
        }

        // Shows the framebuffer the VI points at (or force, an interpolated list's screen).
        void present(Framebuffer* force = nullptr) {
            const ultramodern::renderer::ViRegs* vi = ultramodern::renderer::get_vi_regs();
            const uint32_t origin = vi->VI_ORIGIN_REG & 0x00FFFFFF;
            const uint32_t vi_width = vi->VI_WIDTH_REG & 0xFFF;
            Framebuffer* shown = force != nullptr ? force : framebuffer_at(origin);

            uint32_t source_tex = 0;
            float u1 = 1.0f, v0 = 0.0f, v1 = 1.0f;
            float u0 = 0.0f;
            std::shared_ptr<std::vector<uint32_t>> cpu_frame;
            uint32_t cpu_w = 0, cpu_h = 0;
            if (shown != nullptr) {
                shown->last_used = present_count;
            }
            if (shown != nullptr && present_count - shown->last_drawn <= 3) {
                source_tex = shown->showing_real && shown->real_tex ? shown->real_tex : shown->tex;
                if (shown->interp_ready) {
                    // The in-between frame first, the game's own (copied aside) at the next VI.
                    source_tex = shown->tex;
                    shown->interp_ready = false;
                    shown->showing_real = true;
                    real_pending = true;
                }
                // Only what the game drew this frame (its scissor), as RT64 shows it.
                if (shown->drawn_x1 > shown->drawn_x0 && shown->drawn_y1 > shown->drawn_y0) {
                    shown->shown_x0 = shown->drawn_x0; shown->shown_x1 = shown->drawn_x1;
                    shown->shown_y0 = shown->drawn_y0; shown->shown_y1 = shown->drawn_y1;
                }
                // A cutscene in 4:3: the N64's frame in the middle of the widened image (the
                // game's cameras draw 2 pixels short of its sides, black on the N64), black
                // bars beside it. Characters wait for their cue just past its edges.
                if (shown->gl_width > shown->width && conker::cutscene_aspect::pillarbox_now()) {
                    shown->shown_x0 = std::max(shown->shown_x0, shown->off + 2.0f);
                    shown->shown_x1 = std::min(shown->shown_x1, shown->off + shown->width - 2.0f);
                }
                if (shown->shown_x1 > shown->shown_x0) {
                    // Half a texel in from the edges: the filtering mustn't reach outside.
                    const float W = (float)shown->gl_width, H = (float)shown->height;
                    const float hx = 0.5f / (W * render_scale), hy = 0.5f / (H * render_scale);
                    u0 = shown->shown_x0 / W + hx;
                    u1 = shown->shown_x1 / W - hx;
                    v1 = 1.0f - shown->shown_y0 / H - hy;
                    v0 = 1.0f - shown->shown_y1 / H + hy;
                }
                shown->drawn_x0 = shown->drawn_y0 = 1e9f;
                shown->drawn_x1 = shown->drawn_y1 = 0;
            }
            else if (origin != 0 && vi_width >= 64 && vi_width <= 640) {
                // Nothing drawn there: the CPU wrote it (decoded now: RDRAM changes).
                cpu_w = vi_width;
                cpu_h = std::min<uint32_t>((cpu_w * 3) / 4, 480);
                const uint32_t siz = ((vi->VI_STATUS_REG & 3) == 3) ? SIZ_32b : SIZ_16b;
                cpu_frame = std::make_shared<std::vector<uint32_t>>((size_t)cpu_w * cpu_h);
                decode_framebuffer(rdram, origin, siz, cpu_w, cpu_h, cpu_frame->data());
                source_tex = TEX_CPU_FRAME;
                // Rows go down in RDRAM: flip.
                v0 = 1.0f;
                v1 = 0.0f;
            }

            if (dumping() || (dump_dl != ~0u && dl_count - dump_dl < dump_count + 2)) {
                std::fprintf(stderr, "[present] dl %u origin 0x%06X shown 0x%06X last_drawn %u present %u\n", dl_count, origin,
                    shown ? shown->addr : 0, shown ? shown->last_drawn : 0, present_count);
            }
            if (((debug_flags & 8192) || capture_left > 0) && shown != nullptr) {
                enqueue([tex = shown->tex, n = present_count, c = capture_left > 0 ? capture_index : 0u](Backend& b, CommandList&) {
                    b.probe_water(tex, n, c);
                });
            }
            if (capture_left > 0 && --capture_left == 0) {
                std::fprintf(stderr, "[capture] %u ends at present %u\n", capture_index, present_count);
            }
            if (debug_flags & 4096) {
                std::fprintf(stderr, "[showfb] present %u dl %u origin 0x%06X shown 0x%06X water %u last_drawn %u %s%s\n", present_count, dl_count,
                    origin, shown ? shown->addr : 0, shown ? shown->water_draws : 0, shown ? shown->last_drawn : 0,
                    present_fallback ? "fallback" : "swap", source_tex == TEX_CPU_FRAME ? " CPU" : "");
            }
            const std::array<float, 4> uv = { u0, v0, u1, v1 };
            // The shown part's width on the screen: 4:3, or wider when the image is.
            float aspect = 4.0f / 3.0f;
            if (shown != nullptr && (source_tex == shown->tex || source_tex == shown->real_tex) && shown->shown_x1 > shown->shown_x0 && shown->shown_y1 > shown->shown_y0) {
                aspect = (shown->shown_x1 - shown->shown_x0) / (shown->shown_y1 - shown->shown_y0) * (4.0f / 3.0f) /
                    ((float)shown->width / (float)shown->height);
            }
            enqueue([source_tex, uv, cpu_frame, cpu_w, cpu_h, aspect, menu = menu_vertices()](Backend& b, CommandList&) {
                b.present(source_tex, uv.data(), cpu_frame.get(), cpu_w, cpu_h, aspect, menu);
            });
            submit();
            conker::vita::bench::on_present();
            if (present_count < 5 || present_count % 120 == 0) {
                std::fprintf(stderr, "[renderer] present #%u origin 0x%06X width %u %s\n", present_count, origin, vi_width,
                    shown ? "gpu" : (source_tex ? "cpu" : "none"));
            }
            present_count++;
            evict_textures();
            evict_framebuffers(shown);
        }
    };
}

// The gfx thread's call for an in-between frame (ultramodern events.cpp), after a list was read.
extern "C" void (*ultramodern_vita_interp_hook)(void* renderer, const OSTask* task);

std::unique_ptr<ultramodern::renderer::RendererContext> conker::vita::create_renderer(
    uint8_t* rdram, ultramodern::renderer::WindowHandle, bool) {
    ultramodern_vita_interp_hook = [](void* r, const OSTask* task) { static_cast<VitaRenderer*>(r)->interp_dl(task); };
    return std::make_unique<VitaRenderer>(rdram);
}

void conker::vita::renderer_status(char* out, unsigned size) {
    std::snprintf(out, size, "front stage %u (lists %u), back op %u compiling %u waiting %u (lists %u)",
        g_front_stage.load(), g_front_lists.load(), g_back_op.load(), g_back_compiling.load(), g_back_waiting.load(), g_back_lists.load());
}

unsigned conker::vita::renderer_back_busy_ms() {
    return (unsigned)(g_back_busy_total_us.exchange(0) / 1000);
}

unsigned long long conker::vita::renderer_snapshot_us() {
    return capture::copy_us.exchange(0);
}

unsigned long long conker::vita::renderer_capture_wait_us() {
    return capture::wait_us.exchange(0);
}

unsigned long long conker::vita::renderer_capture_pages() {
    return capture::copied_pages.exchange(0);
}
