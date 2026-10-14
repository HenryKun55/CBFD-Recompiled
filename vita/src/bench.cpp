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
#include <psp2/kernel/threadmgr.h>

#include "ultramodern/ultramodern.hpp"

#include "bench.hpp"
#include "vita_platform.hpp"
#include "vita_renderer.hpp"

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

    // Always on (outside the benchmark too): a line a second in the log while playing.
    std::atomic<uint32_t> live_frames{0}, live_presents{0}, live_render_max{0}, live_audio_tasks{0};
    std::atomic<uint64_t> live_render_us{0}, live_tris{0}, live_audio_us{0};
    uint64_t live_next_us = 0;
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
    live_frames++;
    live_render_us += render_us;
    live_tris += tris;
    uint32_t m = live_render_max.load();
    while (render_us > m && !live_render_max.compare_exchange_weak(m, render_us)) {}
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
    live_presents++;
    if (!enabled || finished) return;
    std::lock_guard lock{mutex};
    current_second().presents++;
}

void conker::vita::bench::on_audio_task(uint32_t us) {
    live_audio_tasks++;
    live_audio_us += us;
    if (!enabled || finished) return;
    std::lock_guard lock{mutex};
    Second& s = current_second();
    s.audio_tasks++;
    s.audio_us += us;
}

// Every thread's CPU time (the kernel's run clocks, nothing timed in the code): the [cpu] line
// each second, ms used in that second, to see which one keeps the frames from 30 a second.
void ultramodern_trace_dump_recent(uint64_t us);

namespace {
    struct ThreadEntry { SceUID uid; char name[28]; uint64_t last; };
    std::mutex threads_mutex;
    std::vector<ThreadEntry> threads_seen;

    void log_threads() {
        std::lock_guard lock{threads_mutex};
        std::string line;
        for (ThreadEntry& t : threads_seen) {
            SceKernelThreadInfo info{};
            info.size = sizeof(info);
            if (sceKernelGetThreadInfo(t.uid, &info) < 0) continue;
            const uint64_t clocks = (uint64_t)info.runClocks;
            const uint64_t d = clocks - t.last;
            t.last = clocks;
            if (d < 500) continue;
            char b[64];
            std::snprintf(b, sizeof(b), " %s %.0f", t.name, d / 1000.0);
            line += b;
        }
        std::fprintf(stderr, "[cpu] ms this second:%s\n", line.c_str());
    }
}

extern "C" void conker_vita_register_thread(const char* name) {
    std::lock_guard lock{threads_mutex};
    ThreadEntry t{};
    t.uid = sceKernelGetThreadId();
    std::snprintf(t.name, sizeof(t.name), "%s", name);
    for (char& c : t.name) if (c == ' ') c = '_';
    threads_seen.push_back(t);
}

void conker::vita::bench::update() {
    const uint64_t now = now_us();
    if (live_next_us == 0) live_next_us = now + 1000000;
    if (now >= live_next_us) {
        // The game's frames (display lists) this second, the renderer's front (reading them,
        // on the game's thread) average and worst, its back (drawing), and the audio's time.
        const uint32_t f = live_frames.exchange(0), p = live_presents.exchange(0);
        const uint64_t r = live_render_us.exchange(0), tr = live_tris.exchange(0), au = live_audio_us.exchange(0);
        const uint32_t rmax = live_render_max.exchange(0), at = live_audio_tasks.exchange(0);
        std::fprintf(stderr, "[perf] t=%llu fps=%u presents=%u front_ms avg=%.1f max=%.1f back_busy_ms=%u audio_ms=%.0f (%u tasks) tris=%llu copy_ms=%.2f wait_ms=%.2f pages=%llu\n",
            (unsigned long long)(now / 1000000), f, p, f ? r / 1000.0 / f : 0.0, rmax / 1000.0,
            conker::vita::renderer_back_busy_ms(), au / 1000.0, at, (unsigned long long)(f ? tr / f : 0),
            f ? conker::vita::renderer_snapshot_us() / 1000.0 / f : 0.0,
            f ? conker::vita::renderer_capture_wait_us() / 1000.0 / f : 0.0,
            (unsigned long long)(f ? conker::vita::renderer_capture_pages() / f : 0));
        log_threads();
        // Debug: a timeline of the game's waits and the RCP's events, once, after three heavy
        // seconds (the rain outside the bar).
        static int heavy_seconds = 0;
        static bool dumped = false;
        heavy_seconds = (f && tr / f > 9000) ? heavy_seconds + 1 : 0;
        if (heavy_seconds == 3 && !dumped) {
            dumped = true;
            ultramodern_trace_dump_recent(1500000);
        }
        live_next_us += 1000000;
        if (now > live_next_us + 5000000) live_next_us = now + 1000000;
    }
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
