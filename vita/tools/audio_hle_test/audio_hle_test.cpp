// Host test for the HLE audio microcode (vita/src/audio_hle.cpp): runs captured audio
// tasks (vita/src/audio_capture.cpp: audiocap/task_*.bin) through both the recompiled
// microcode (RecompiledFuncs/rsp/audio_ucode.cpp) and the HLE, and compares RDRAM and
// DMEM afterwards byte for byte; then times both. --fuzz also runs random command lists
// (built on a captured task's DMEM and RDRAM) through both.
//
// usage: audio_hle_test [--reps N] [--fuzz N] [--seed S] [--verbose] task.bin...

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>
#include <string>
#include <vector>

#include "librecomp/rsp.hpp"
#include "audio_hle.hpp"

RspExitReason conker_audio_ucode(uint8_t* rdram, uint32_t ucode_addr);

namespace {
    constexpr size_t captured_rdram = 8 * 1024 * 1024;
    constexpr size_t rdram_size = 16 * 1024 * 1024;  // DMA addresses are 24-bit

    struct Task {
        std::string name;
        uint32_t ucode_addr = 0;
        uint32_t index = 0;
        uint64_t after_hash = 0;
        bool has_hash = false;
        std::vector<uint8_t> dmem0;
        std::vector<uint8_t> rdram0;
    };

    uint64_t fnv1a(const uint8_t* data, size_t size) {
        uint64_t h = 0xcbf29ce484222325ull;
        for (size_t i = 0; i < size; i++) {
            h ^= data[i];
            h *= 0x100000001b3ull;
        }
        return h;
    }

    bool load_task(const char* path, Task& t) {
        FILE* f = std::fopen(path, "rb");
        if (!f) return false;
        uint32_t header[4];
        t.dmem0.resize(0x1000);
        t.rdram0.assign(rdram_size, 0);
        bool ok = std::fread(header, sizeof(header), 1, f) == 1 && header[0] == 0x50414341u &&
                  std::fread(t.dmem0.data(), 1, 0x1000, f) == 0x1000 &&
                  std::fread(t.rdram0.data(), 1, captured_rdram, f) == captured_rdram;
        t.has_hash = ok && std::fread(&t.after_hash, sizeof(t.after_hash), 1, f) == 1;
        std::fclose(f);
        t.name = path;
        t.ucode_addr = header[2];
        t.index = header[3];
        return ok;
    }

    uint32_t dmem_word(const std::vector<uint8_t>& d, uint32_t a) {
        uint32_t w;
        std::memcpy(&w, d.data() + a, 4);
        return w;
    }
    uint32_t rdram_word(const std::vector<uint8_t>& r, uint32_t a) {
        uint32_t w;
        std::memcpy(&w, r.data() + (a & 0xFFFFFC), 4);
        return w;
    }

    // The list's command counts.
    void count_commands(const Task& t, int counts[16]) {
        std::memset(counts, 0, 16 * sizeof(int));
        const uint32_t ptr = dmem_word(t.dmem0, 0xFF0) & 0xFFFFFF, size = dmem_word(t.dmem0, 0xFF4);
        for (uint32_t i = 0; i + 8 <= size && i < 0x10000; i += 8) counts[(rdram_word(t.rdram0, ptr + i) >> 24) & 0xF]++;
    }

    struct Result {
        bool rdram_same, dmem_same, exit_same;
        int exit_ref, exit_hle;
        size_t rdram_diffs;
        uint32_t first_rdram_diff;
        int dmem_diffs;
        uint32_t first_dmem_diff;
    };

    // Runs t (with dmem0/rdram0) through both; ref and hle get each side's RDRAM after.
    Result compare(const Task& t, std::vector<uint8_t>& ref, std::vector<uint8_t>& hle, uint8_t* dmem_ref, uint8_t* dmem_hle) {
        ref = t.rdram0;
        std::memcpy(dmem, t.dmem0.data(), 0x1000);
        const RspExitReason r1 = conker_audio_ucode(ref.data(), t.ucode_addr);
        std::memcpy(dmem_ref, dmem, 0x1000);
        hle = t.rdram0;
        std::memcpy(dmem, t.dmem0.data(), 0x1000);
        const RspExitReason r2 = conker_audio_hle(hle.data(), t.ucode_addr);
        std::memcpy(dmem_hle, dmem, 0x1000);
        Result res{};
        res.exit_same = r1 == r2;
        res.exit_ref = (int)r1;
        res.exit_hle = (int)r2;
        res.rdram_same = std::memcmp(ref.data(), hle.data(), rdram_size) == 0;
        if (!res.rdram_same) {
            for (size_t i = 0; i < rdram_size; i++) {
                if (ref[i] != hle[i]) {
                    if (res.rdram_diffs++ == 0) res.first_rdram_diff = (uint32_t)(i ^ 3);
                }
            }
        }
        res.dmem_same = std::memcmp(dmem_ref, dmem_hle, 0x1000) == 0;
        for (int i = 0; i < 0x1000; i++) {
            if (dmem_ref[i] != dmem_hle[i] && res.dmem_diffs++ == 0) res.first_dmem_diff = (uint32_t)(i ^ 3);
        }
        return res;
    }

    // ---------------------------------------------------------------- fuzzing
    // A random list on a captured task: random buffers and parameters, the commands Conker
    // uses with the addresses its lists use (and some that are not), and RDRAM state areas.
    struct Fuzzer {
        std::mt19937 rng;
        explicit Fuzzer(uint32_t seed) : rng(seed) {}
        uint32_t u32() { return rng(); }
        uint32_t below(uint32_t n) { return rng() % n; }
        bool chance(int pct) { return (int)below(100) < pct; }

        void put_rdram_word(std::vector<uint8_t>& r, uint32_t a, uint32_t w) { std::memcpy(r.data() + a, &w, 4); }
        void put_dmem_word(std::vector<uint8_t>& d, uint32_t a, uint32_t w) { std::memcpy(d.data() + a, &w, 4); }

        // The base task's MP3ADDY + MP3 pairs.
        std::vector<std::pair<std::pair<uint32_t, uint32_t>, std::pair<uint32_t, uint32_t>>> mp3;

        Task make(const Task& base) {
            Task t = base;
            mp3.clear();
            {
                const uint32_t ptr = dmem_word(base.dmem0, 0xFF0) & 0xFFFFFF, size = dmem_word(base.dmem0, 0xFF4);
                for (uint32_t i = 8; i < size && i < 0x10000; i += 8) {
                    const uint32_t w0 = rdram_word(base.rdram0, ptr + i);
                    if ((w0 >> 24) == 7 && (rdram_word(base.rdram0, ptr + i - 8) >> 24) == 8) {
                        mp3.push_back({{rdram_word(base.rdram0, ptr + i - 8), rdram_word(base.rdram0, ptr + i - 4)},
                                       {w0, rdram_word(base.rdram0, ptr + i + 4)}});
                    }
                }
            }
            t.name = "fuzz";
            // Random audio data in DMEM's buffers, state and scratch (not the tables).
            for (uint32_t a = 0x400; a < 0xFC0; a += 4) put_dmem_word(t.dmem0, a, u32());
            if (chance(50)) {  // quiet samples, as games mostly have
                for (uint32_t a = 0x500; a < 0xFA0; a += 4) {
                    uint32_t w = u32() & 0x0FFF0FFF;
                    put_dmem_word(t.dmem0, a, w);
                }
            }
            // The list and the state areas in RDRAM, past the game's (top 1 MiB of 8).
            const uint32_t list = 0x700000, states = 0x710000, samples = 0x720000;
            for (uint32_t a = states; a < states + 0x20000; a += 4) put_rdram_word(t.rdram0, a, below(4) ? (u32() & 0x3FFF3FFF) : u32());
            const int ncmds = 1 + (int)below(120);
            uint32_t at = list;
            auto state = [&]() { return states + below(0x1000) * 16; };
            for (int i = 0; i < ncmds; i++) {
                uint32_t w0 = 0, w1 = 0;
                const int pick = (int)below(18);
                const uint32_t buf = 0x0 + below(0xAA0 / 16) * 16;  // relative to 0x500
                // Any DMEM address the microcode can DMA to (one with 0x1000 set would go to IMEM).
                // Odd addresses too, but writes stay off the list and the tables (below 0x500).
                auto any_addr = [&]() { return below(0xA80); };
                auto dma_buf = [&]() { return chance(98) ? buf : any_addr(); };
                switch (pick) {
                    case 0:  // ADPCM
                        w0 = (1u << 24) | state();
                    {
                        const uint32_t count = below(0x500) & ~0x1Fu;
                        uint32_t out = dma_buf();
                        while (out + 0x520 + count > 0x1000) out = below(0x400) & ~0xFu;
                        w1 = (below(4) << 28) | (count << 16) | (below(16) << 12) | out;
                    }
                        break;
                    case 1:  // CLEARBUFF
                        w0 = (2u << 24) | (chance(98) ? buf : any_addr());
                        w1 = below(0x400);
                        if ((w0 & 0xFFFF) + 0x500 + w1 + 16 > 0x1000) w1 = 0x10;
                        break;
                    case 2: case 3:  // ENVMIXER
                        w0 = (3u << 24) | (below(2) << 16) | (u32() & 0xFFFF);
                        w1 = state();
                        break;
                    case 4:  // LOADBUFF
                        w0 = (4u << 24) | ((below(0x400) & ~7u) << 12) | dma_buf();
                        if ((w0 & 0xFFFF) + 0x500 + ((w0 >> 12) & 0xFFF) > 0x1000) w0 = (w0 & ~0xFFF000u) | (0x10u << 12);
                        w1 = samples + below(0x8000) * 8;
                        break;
                    case 5: case 6: {  // RESAMPLE
                        const uint32_t in = chance(98) ? (buf & ~0xFu) + 8 : 8 + below(0xA00);
                        w0 = (5u << 24) | state();
                        w1 = (below(4) << 30) | ((u32() & 0xFFFF) << 14) | ((in & 0xFFF) << 2) | below(4);
                        if (chance(50)) w1 = (w1 & ~(0xFFFFu << 14)) | (below(0x10000) << 14);
                        break;
                    }
                    case 7:  // SAVEBUFF
                        w0 = (6u << 24) | ((below(0x400) & ~7u) << 12) | dma_buf();
                        w1 = samples + 0x40000 + below(0x8000) * 8;
                        break;
                    case 8: {  // SETVOL
                        const uint32_t flags = below(8);
                        w0 = (9u << 24) | (flags << 16) | (u32() & 0xFFFF);
                        w1 = u32();
                        if (chance(50)) w1 = (w1 & 0xFFFF) | ((u32() & 0x3F) << 16);
                        break;
                    }
                    case 9:  // DMEMMOVE
                        w0 = (0xAu << 24) | (chance(97) ? buf : any_addr());
                        w1 = ((chance(97) ? buf : any_addr()) << 16) | below(0x400);
                        if ((w1 >> 16) + 0x500 + (w1 & 0xFFFF) + 16 > 0x1000) w1 = (w1 & 0xFFFF0000u) | 0x10;
                        break;
                    case 10:  // MIXER
                        w0 = (0xCu << 24) | (u32() & 0xFFFF);
                        w1 = ((chance(99) ? buf : any_addr()) << 16) | (chance(99) ? (chance(20) ? ((buf + 16) & 0xFFFF) : buf) : any_addr());
                        if ((w1 & 0xFFFF) + 0x500 + 0x170 > 0x1000) w1 = (w1 & 0xFFFF0000u) | 0x100;
                        break;
                    case 11:  // INTERLEAVE
                        w0 = 0xDu << 24;
                        break;
                    case 12:  // SETLOOP
                        w0 = 0xFu << 24;
                        w1 = state();
                        break;
                    case 13:  // gain (cmd 0)
                        w0 = (0u << 24) | (chance(99) ? buf : any_addr());
                        if ((w0 & 0xFFFF) + 0x500 + 0x170 > 0x1000) w0 = 0x100;
                        w1 = u32();
                        break;
                    case 14:  // LOADADPCM
                        w0 = (0xBu << 24) | (below(0x100) & ~7u);
                        w1 = samples + below(0x8000) * 8;
                        if (chance(30)) {  // a filter table: zero first word or not, zero second or not
                            const uint32_t src = samples + below(0x8000) * 8;
                            put_rdram_word(t.rdram0, src, chance(50) ? 0 : u32());
                            put_rdram_word(t.rdram0, src + 4, chance(30) ? 0 : (u32() & 0x7FFF7FFF));
                            w0 = (0xBu << 24) | 0x20;
                            w1 = src;
                        }
                        break;
                    case 15: case 16: {  // 0xE: either variant (whichever DMEM 0x400 picks)
                        uint32_t low = chance(30) ? 0 : chance(97) ? buf : any_addr();
                        if (low + 0x500 + 0x170 + 16 > 0x1000) low = 0x100;
                        w0 = (0xEu << 24) | (below(2) << 16) | low;
                        w1 = (below(2) << 24) | state();
                        break;
                    }
                    case 17:  // MP3, when the base task has one
                        if (!mp3.empty()) {
                            const auto& m = mp3[below((uint32_t)mp3.size())];
                            put_rdram_word(t.rdram0, at, m.first.first);
                            put_rdram_word(t.rdram0, at + 4, m.first.second);
                            at += 8;
                            i++;
                            w0 = m.second.first;
                            w1 = m.second.second;
                        } else {
                            w0 = 0xDu << 24;
                        }
                        break;
                }
                put_rdram_word(t.rdram0, at, w0);
                put_rdram_word(t.rdram0, at + 4, w1);
                at += 8;
            }
            for (uint32_t a = samples; a < samples + 0x40000; a += 4) put_rdram_word(t.rdram0, a, u32());
            put_dmem_word(t.dmem0, 0xFF0, 0x80000000u | list);
            put_dmem_word(t.dmem0, 0xFF4, at - list);
            return t;
        }
    };

    double now_us() {
        return std::chrono::duration<double, std::micro>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }
}

int main(int argc, char** argv) {
    int reps = 20, fuzz = 0, only_case = -1;
    uint32_t seed = 1;
    bool verbose = false;
    std::vector<const char*> paths;
    for (int i = 1; i < argc; i++) {
        if (!std::strcmp(argv[i], "--reps") && i + 1 < argc) reps = std::atoi(argv[++i]);
        else if (!std::strcmp(argv[i], "--fuzz") && i + 1 < argc) fuzz = std::atoi(argv[++i]);
        else if (!std::strcmp(argv[i], "--seed") && i + 1 < argc) seed = (uint32_t)std::atoi(argv[++i]);
        else if (!std::strcmp(argv[i], "--verbose")) verbose = true;
        else if (!std::strcmp(argv[i], "--case") && i + 1 < argc) only_case = std::atoi(argv[++i]);
        else paths.push_back(argv[i]);
    }
    if (paths.empty()) {
        std::fprintf(stderr, "usage: %s [--reps N] [--fuzz N] [--seed S] [--verbose] task.bin...\n", argv[0]);
        return 2;
    }
    recomp::rsp::constants_init();

    static const char* names[16] = {"GAIN", "ADPCM", "CLEARBUFF", "ENVMIXER", "LOADBUFF", "RESAMPLE", "SAVEBUFF", "MP3",
                                    "MP3ADDY", "SETVOL", "DMEMMOVE", "LOADADPCM", "MIXER", "INTERLEAVE", "POLEF(0xE)", "SETLOOP"};
    std::vector<Task> tasks;
    int total_counts[16] = {};
    int tasks_with[16] = {};
    for (const char* p : paths) {
        Task t;
        if (!load_task(p, t)) {
            std::fprintf(stderr, "can't read %s\n", p);
            continue;
        }
        int c[16];
        count_commands(t, c);
        for (int i = 0; i < 16; i++) {
            total_counts[i] += c[i];
            if (c[i]) tasks_with[i]++;
        }
        tasks.push_back(std::move(t));
    }
    std::printf("%zu tasks\ncommands (total, tasks using it):\n", tasks.size());
    for (int i = 0; i < 16; i++) {
        if (total_counts[i]) std::printf("  %X %-11s %7d %5d\n", i, names[i], total_counts[i], tasks_with[i]);
    }

    std::vector<uint8_t> ref, hle;
    uint8_t dref[0x1000], dhle[0x1000];
    int exact = 0, fallback = 0, failed = 0, hash_mismatch = 0, dmem_only = 0;
    for (const Task& t : tasks) {
        std::memcpy(dmem, t.dmem0.data(), 0x1000);
        const bool supported = conker::audio_hle::task_supported(t.rdram0.data());
        const Result r = compare(t, ref, hle, dref, dhle);
        if (!supported) fallback++;
        if (t.has_hash && fnv1a(ref.data(), captured_rdram) != t.after_hash) hash_mismatch++;
        const bool ok = r.rdram_same && r.exit_same;
        if (ok) exact++; else failed++;
        if (ok && !r.dmem_same) dmem_only++;
        if (!ok || !r.dmem_same || !supported || verbose) {
            int c[16];
            count_commands(t, c);
            if (!supported) {
                const int n = conker::audio_hle::unsupported_command();
                const uint32_t ptr = dmem_word(t.dmem0, 0xFF0) & 0xFFFFFF;
                std::printf("  fallback at command %d: %08X %08X\n", n, n >= 0 ? rdram_word(t.rdram0, ptr + 8 * n) : 0,
                            n >= 0 ? rdram_word(t.rdram0, ptr + 8 * n + 4) : 0);
            }
            std::printf("%s (task %u)%s: RDRAM %s", t.name.c_str(), t.index, supported ? "" : " [microcode fallback]",
                        r.rdram_same ? "same" : "DIFFERS");
            if (!r.rdram_same) std::printf(" (%zu bytes, first at 0x%06X)", r.rdram_diffs, r.first_rdram_diff);
            std::printf(", DMEM %s", r.dmem_same ? "same" : "differs");
            if (!r.dmem_same) std::printf(" (%d bytes, first at 0x%03X)", r.dmem_diffs, r.first_dmem_diff);
            if (!r.exit_same) std::printf(", exit differs");
            std::printf("; cmds");
            for (int i = 0; i < 16; i++) if (c[i]) std::printf(" %X:%d", i, c[i]);
            std::printf("\n");
        }
    }
    std::printf("captured tasks: %d bit-exact, %d differ (%d run by the microcode fallback; %d same RDRAM but other DMEM)\n",
                exact, failed, fallback, dmem_only);
    if (hash_mismatch) std::printf("(%d tasks' RDRAM after differs from the capture's hash of it: the game's threads write RDRAM while a task runs)\n", hash_mismatch);

    // The hardware check mode (conker_audio_hle_check) must leave what the microcode leaves.
    {
        int check_same = 0;
        for (const Task& t : tasks) {
            Result r = compare(t, ref, hle, dref, dhle);
            (void)r;
            hle = t.rdram0;
            std::memcpy(dmem, t.dmem0.data(), 0x1000);
            conker_audio_hle_check(hle.data(), t.ucode_addr);
            if (std::memcmp(ref.data(), hle.data(), rdram_size) == 0 && std::memcmp(dmem, dref, 0x1000) == 0) check_same++;
        }
        const auto& st = conker::audio_hle::stats();
        std::printf("check mode: %d of %zu tasks leave the microcode's RDRAM and DMEM; %u checked, %u differences found\n",
                    check_same, tasks.size(), st.checked, st.check_mismatches);
    }

    if (fuzz > 0 && !tasks.empty()) {
        Fuzzer fz(seed);
        int fexact = 0, ffail = 0, ffallback = 0, why[17] = {};
        for (int i = 0; i < fuzz; i++) {
            const Task t = fz.make(tasks[i % tasks.size()]);
            if (only_case >= 0 && i != only_case) continue;
            if (only_case >= 0) {
                const uint32_t size = dmem_word(t.dmem0, 0xFF4);
                for (uint32_t n = 0; n < size; n += 8)
                    std::printf("  %3u: %08X %08X\n", n / 8, rdram_word(t.rdram0, 0x700000 + n), rdram_word(t.rdram0, 0x700000 + n + 4));
            }
            std::memcpy(dmem, t.dmem0.data(), 0x1000);
            const bool supported = conker::audio_hle::task_supported(t.rdram0.data());
            if (!supported) {
                ffallback++;
                const int n = conker::audio_hle::unsupported_command();
                why[n >= 0 ? (rdram_word(t.rdram0, 0x700000 + 8 * n) >> 24) & 0xF : 16]++;
            }
            const Result r = compare(t, ref, hle, dref, dhle);
            if (r.rdram_same && r.exit_same && r.dmem_same) {
                fexact++;
                continue;
            }
            ffail++;
            if (ffail <= 10) {
                std::printf("fuzz %d: RDRAM %s (%zu bytes, first 0x%06X), DMEM %s (%d bytes, first 0x%03X)%s\n", i,
                            r.rdram_same ? "same" : "DIFFERS", r.rdram_diffs, r.first_rdram_diff, r.dmem_same ? "same" : "differs",
                            r.dmem_diffs, r.first_dmem_diff, r.exit_same ? "" : ", exit differs");
                if (!r.exit_same) std::printf("  exit: microcode %d, HLE %d\n", r.exit_ref, r.exit_hle);
                // Find the first command after which DMEM differs.
                const uint32_t size = dmem_word(t.dmem0, 0xFF4);
                for (uint32_t n = 8; n <= size; n += 8) {
                    Task u = t;
                    std::memcpy(u.dmem0.data() + 0xFF4, &n, 4);
                    const Result rr = compare(u, ref, hle, dref, dhle);
                    if (!(rr.rdram_same && rr.dmem_same)) {
                        const uint32_t w0 = rdram_word(t.rdram0, 0x700000 + n - 8), w1 = rdram_word(t.rdram0, 0x700000 + n - 4);
                        std::printf("  first differs after command %u: %08X %08X (%s); DMEM first at 0x%03X, RDRAM first at 0x%06X\n",
                                    n / 8 - 1, w0, w1, names[(w0 >> 24) & 0xF], rr.first_dmem_diff, rr.first_rdram_diff);
                        if (verbose) {
                            // DMEM before that command (the prefix before it, through the microcode).
                            Task v = t;
                            const uint32_t m = n - 8;
                            std::memcpy(v.dmem0.data() + 0xFF4, &m, 4);
                            std::vector<uint8_t> r2;
                            if (m) { r2 = v.rdram0; std::memcpy(dmem, v.dmem0.data(), 0x1000); conker_audio_ucode(r2.data(), v.ucode_addr); }
                            else std::memcpy(dmem, v.dmem0.data(), 0x1000);
                            auto h = [](const uint8_t* d, uint32_t a) { uint16_t x; std::memcpy(&x, d + (a ^ 2), 2); return x; };
                            std::printf("  before: DMEM 0x400:");
                            for (int k = 0; k < 24; k++) std::printf(" %04X", h(dmem, 0x400 + 2 * k));
                            std::printf("\n  after, microcode / HLE, around the first DMEM difference:\n");
                            const uint32_t a0 = rr.first_dmem_diff & ~0xFu;
                            for (uint32_t a = a0 >= 0x10 ? a0 - 0x10 : 0; a < a0 + 0x20 && a < 0x1000; a += 16) {
                                std::printf("  %03X:", a);
                                for (int k = 0; k < 8; k++) std::printf(" %04X", h(dref, a + 2 * k));
                                std::printf("  |");
                                for (int k = 0; k < 8; k++) std::printf(" %04X", h(dhle, a + 2 * k));
                                std::printf("\n");
                            }
                        }
                        break;
                    }
                }
            }
        }
        std::printf("fuzz: %d lists, %d exact (RDRAM and DMEM), %d differ, %d run by the fallback\n", fuzz, fexact, ffail, ffallback);
        if (ffallback) {
            std::printf("  fallbacks by command:");
            for (int k = 0; k < 17; k++) if (why[k]) std::printf(" %s:%d", k < 16 ? names[k] : "list", why[k]);
            std::printf("\n");
        }
    }

    conker::audio_hle::reset_stats();
    // Timing: each task repeatedly from its DMEM (RDRAM keeps evolving, as in the game).
    if (reps > 0 && !tasks.empty()) {
        double t_ref = 0, t_hle = 0;
        for (const Task& t : tasks) {
            ref = t.rdram0;
            hle = t.rdram0;
            for (int i = 0; i < reps; i++) {
                std::memcpy(dmem, t.dmem0.data(), 0x1000);
                double a = now_us();
                conker_audio_ucode(ref.data(), t.ucode_addr);
                t_ref += now_us() - a;
                std::memcpy(dmem, t.dmem0.data(), 0x1000);
                a = now_us();
                conker_audio_hle(hle.data(), t.ucode_addr);
                t_hle += now_us() - a;
            }
        }
        const double n = (double)tasks.size() * reps;
        std::printf("time per task: microcode %.1f us, HLE %.1f us (%.2fx)\n", t_ref / n, t_hle / n, t_ref / t_hle);
    }
    const auto& st = conker::audio_hle::stats();
    uint64_t total_ns = 0;
    for (int i = 0; i < 16; i++) total_ns += st.command_ns[i];
    if (total_ns) {
        std::printf("HLE time by command (AUDIO_HLE_PROFILE):\n");
        for (int i = 0; i < 16; i++) {
            if (st.commands[i]) std::printf("  %-11s %8u runs %8.3f us each %5.1f%%\n", names[i], st.commands[i],
                                            st.command_ns[i] / 1000.0 / st.commands[i], 100.0 * st.command_ns[i] / total_ns);
        }
    }
    return failed ? 1 : 0;
}
