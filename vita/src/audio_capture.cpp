// Captures audio tasks for the HLE audio test (see audio_capture.hpp).

#include "audio_capture.hpp"

#include <cstdio>
#include <cstring>
#include <string>

#include "librecomp/rsp.hpp"
#include "vita_platform.hpp"

#ifdef __vita__
#include <psp2/io/stat.h>
#else
#include <sys/stat.h>
#endif

namespace {
    constexpr uint32_t rdram_size = 8 * 1024 * 1024;
    constexpr int num_cmds = 16;

    bool enabled = false;
    int max_dumps = 0;
    int stride = 1;
    int dumps = 0;
    int task_index = 0;
    int dumped_with[num_cmds] = {};
    bool dumping = false;
    FILE* dump_file = nullptr;
    FILE* summary = nullptr;

    const char* dir() { return CONKER_VITA_DATA_DIR "/audiocap"; }

    uint32_t dmem_word(uint32_t addr) { return *reinterpret_cast<const uint32_t*>(dmem + addr); }
    uint32_t rdram_word(const uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<const uint32_t*>(rdram + (addr & 0x7FFFFC));
    }

    uint64_t fnv1a(const uint8_t* data, size_t size) {
        uint64_t h = 0xcbf29ce484222325ull;
        for (size_t i = 0; i < size; i++) {
            h ^= data[i];
            h *= 0x100000001b3ull;
        }
        return h;
    }
}

namespace conker::vita::audio_capture {
    bool init() {
        FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_capture_audio", "r");
        if (!f) return false;
        if (std::fscanf(f, "%d %d", &max_dumps, &stride) < 1) max_dumps = 64;
        std::fclose(f);
        if (stride < 1) stride = 1;
#ifdef __vita__
        sceIoMkdir(dir(), 0777);
#else
        mkdir(dir(), 0777);
#endif
        summary = std::fopen((std::string(dir()) + "/summary.txt").c_str(), "w");
        enabled = true;
        std::fprintf(stderr, "[vita] capturing audio tasks: %d dumps, stride %d\n", max_dumps, stride);
        return true;
    }

    bool active() { return enabled; }

    void before_task(const uint8_t* rdram, uint32_t ucode_addr) {
        if (!enabled) return;
        const int index = task_index++;
        // The task's command list (OSTask.data_ptr / data_size at DMEM 0xFF0 / 0xFF4).
        const uint32_t data_ptr = dmem_word(0xFF0) & 0xFFFFFF;
        const uint32_t data_size = dmem_word(0xFF4);
        int counts[num_cmds] = {};
        for (uint32_t i = 0; i + 8 <= data_size && i < 0x10000; i += 8) {
            counts[(rdram_word(rdram, data_ptr + i) >> 24) & 0xF]++;
        }
        bool want = dumps < max_dumps && (index % stride) == 0;
        for (int c = 0; c < num_cmds && dumps < max_dumps; c++) {
            if (counts[c] && dumped_with[c] < 4) want = true;
        }
        if (summary) {
            std::fprintf(summary, "%d %u", index, data_size / 8);
            for (int c = 0; c < num_cmds; c++) std::fprintf(summary, " %d", counts[c]);
            std::fprintf(summary, "%s\n", want ? " dumped" : "");
            std::fflush(summary);
        }
        dumping = false;
        if (!want) return;
        char path[128];
        std::snprintf(path, sizeof(path), "%s/task_%06d.bin", dir(), index);
        dump_file = std::fopen(path, "wb");
        if (!dump_file) return;
        for (int c = 0; c < num_cmds; c++) {
            if (counts[c]) dumped_with[c]++;
        }
        dumps++;
        dumping = true;
        const uint32_t header[4] = {0x50414341u /* "ACAP" */, 1, ucode_addr, (uint32_t)index};
        std::fwrite(header, sizeof(header), 1, dump_file);
        std::fwrite(dmem, 1, 0x1000, dump_file);
        std::fwrite(rdram, 1, rdram_size, dump_file);
    }

    void after_task(const uint8_t* rdram) {
        if (!enabled || !dumping) return;
        dumping = false;
        const uint64_t h = fnv1a(rdram, rdram_size);
        std::fwrite(&h, sizeof(h), 1, dump_file);
        std::fclose(dump_file);
        dump_file = nullptr;
    }
}
