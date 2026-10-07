// Automated benchmark (see bench.hpp).

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <vector>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include "ultramodern/ultramodern.hpp"

#include "bench.hpp"
#include "vita_platform.hpp"

namespace {
    struct Press {
        double time;
        uint16_t buttons;
        uint32_t vita = 0; // Vita buttons ("@..."), before the remapping
    };

    bool enabled = false;
    double duration_s = 0;
    double shot_every_s = 0;
    std::vector<Press> script;
    uint64_t start_us = 0;
    bool finished = false;

    std::mutex mutex;
    struct Second {
        uint32_t frames = 0;        // display lists rendered
        uint32_t presents = 0;
        uint64_t render_us = 0;     // time spent rendering display lists
        uint32_t render_max_us = 0;
        uint64_t tris = 0;
        uint32_t audio_tasks = 0;
        uint64_t audio_us = 0;
    };
    std::vector<Second> seconds;
    struct Frame {
        double t;
        uint32_t render_us, tris;
    };
    std::vector<Frame> frames;
    double next_shot = 0;

    uint64_t now_us() { return sceKernelGetProcessTimeWide(); }
    double elapsed() { return (double)(now_us() - start_us) / 1e6; }

    Second& current_second() {
        size_t i = (size_t)std::max(0.0, elapsed());
        if (seconds.size() <= i) seconds.resize(i + 1);
        return seconds[i];
    }

    uint16_t parse_buttons(const std::string& s) {
        uint16_t b = 0;
        for (char c : s) {
            switch (c) {
                case 'A': b |= 0x8000; break;
                case 'B': b |= 0x4000; break;
                case 'Z': b |= 0x2000; break;
                case 'S': b |= 0x1000; break;
                case 'U': b |= 0x0800; break;
                case 'D': b |= 0x0400; break;
                case 'L': b |= 0x0020; break;
                case 'R': b |= 0x0010; break;
                case 'u': b |= 0x0008; break;
                case 'd': b |= 0x0004; break;
                case 'l': b |= 0x0002; break;
                case 'r': b |= 0x0001; break;
                default: break;
            }
        }
        return b;
    }

    void write_phase(const char* text) {
        if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/bench_phase.txt", "w")) {
            std::fprintf(f, "%s\n", text);
            std::fclose(f);
        }
    }
}

void conker::vita::bench::init() {
    FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/bench.txt", "r");
    if (f == nullptr) {
        return;
    }
    char line[2048] = {};
    std::fgets(line, sizeof(line), f);
    std::fclose(f);
    char script_text[1800] = {};
    if (std::sscanf(line, "%lf %lf %1799s", &duration_s, &shot_every_s, script_text) < 1 || duration_s <= 0) {
        return;
    }
    std::string text = script_text;
    size_t pos = 0;
    while (pos < text.size()) {
        size_t end = text.find(',', pos);
        if (end == std::string::npos) end = text.size();
        std::string item = text.substr(pos, end - pos);
        size_t colon = item.find(':');
        if (colon != std::string::npos) {
            const std::string what = item.substr(colon + 1);
            const double t = std::atof(item.substr(0, colon).c_str());
            if (!what.empty() && what[0] == '@') {
                uint32_t v = 0;
                for (char c : what.substr(1)) {
                    switch (c) {
                        case 'X': v |= SCE_CTRL_CROSS; break;
                        case 'O': v |= SCE_CTRL_CIRCLE; break;
                        case 'T': v |= SCE_CTRL_TRIANGLE; break;
                        case 'Q': v |= SCE_CTRL_SQUARE; break;
                        case 'S': v |= SCE_CTRL_START; break;
                        case 'E': v |= SCE_CTRL_SELECT; break;
                        case 'U': v |= SCE_CTRL_UP; break;
                        case 'D': v |= SCE_CTRL_DOWN; break;
                        case 'L': v |= SCE_CTRL_LEFT; break;
                        case 'R': v |= SCE_CTRL_RIGHT; break;
                        case 'l': v |= SCE_CTRL_LTRIGGER; break;
                        case 'r': v |= SCE_CTRL_RTRIGGER; break;
                    }
                }
                script.push_back({ t, 0, v });
            }
            else {
                script.push_back({ t, parse_buttons(what) });
            }
        }
        pos = end + 1;
    }
    enabled = true;
    start_us = now_us();
    next_shot = shot_every_s;
    write_phase("running");
    std::fprintf(stderr, "[bench] %.0f s, shot every %.0f s, %u scripted presses\n", duration_s, shot_every_s, (unsigned)script.size());
}

bool conker::vita::bench::active() {
    return enabled;
}

uint16_t conker::vita::bench::scripted_buttons() {
    if (!enabled) return 0;
    const double t = elapsed();
    uint16_t b = 0;
    for (const Press& p : script) {
        if (t >= p.time && t < p.time + 0.25) b |= p.buttons;
    }
    return b;
}

uint32_t conker::vita::bench::scripted_vita_buttons() {
    if (!enabled) return 0;
    const double t = elapsed();
    uint32_t b = 0;
    for (const Press& p : script) {
        if (t >= p.time && t < p.time + 0.25) b |= p.vita;
    }
    return b;
}

void conker::vita::bench::on_display_list(uint32_t render_us, uint32_t tris) {
    if (!enabled || finished) return;
    std::lock_guard lock{mutex};
    Second& s = current_second();
    s.frames++;
    s.render_us += render_us;
    s.render_max_us = std::max(s.render_max_us, render_us);
    s.tris += tris;
    frames.push_back({ elapsed(), render_us, tris });
}

void conker::vita::bench::on_present() {
    if (!enabled || finished) return;
    std::lock_guard lock{mutex};
    current_second().presents++;
}

void conker::vita::bench::on_audio_task(uint32_t us) {
    if (!enabled || finished) return;
    std::lock_guard lock{mutex};
    Second& s = current_second();
    s.audio_tasks++;
    s.audio_us += us;
}

void conker::vita::bench::update() {
    if (!enabled || finished) return;
    const double t = elapsed();
    if (shot_every_s > 0 && t >= next_shot) {
        // The script captures the window when it sees this.
        if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/bench_shot_now.txt", "w")) {
            std::fprintf(f, "%d\n", (int)t);
            std::fclose(f);
        }
        next_shot += shot_every_s;
    }
    if (t < duration_s) return;
    finished = true;

    std::lock_guard lock{mutex};
    if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/bench_frames.csv", "w")) {
        std::fprintf(f, "t,render_us,tris\n");
        for (const Frame& fr : frames) std::fprintf(f, "%.3f,%u,%u\n", fr.t, fr.render_us, fr.tris);
        std::fclose(f);
    }
    if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/bench_result.txt", "w")) {
        std::fprintf(f, "second  game_fps  presents  render_ms_avg  render_ms_max  tris/frame  audio_tasks  audio_ms\n");
        uint64_t total_frames = 0;
        for (size_t i = 0; i < seconds.size(); i++) {
            const Second& s = seconds[i];
            total_frames += s.frames;
            std::fprintf(f, "%6u  %8u  %8u  %13.2f  %13.2f  %10u  %11u  %8.1f\n", (unsigned)i, s.frames, s.presents,
                s.frames ? s.render_us / 1000.0 / s.frames : 0.0, s.render_max_us / 1000.0,
                s.frames ? (unsigned)(s.tris / s.frames) : 0u, s.audio_tasks, s.audio_us / 1000.0);
        }
        std::fprintf(f, "total: %llu frames in %.1f s = %.2f fps\n", (unsigned long long)total_frames, t, total_frames / t);
        std::fclose(f);
    }
    write_phase("done");
    std::fprintf(stderr, "[bench] done\n");
    ultramodern::quit();
}
