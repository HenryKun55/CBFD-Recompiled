// PS Vita host for Conker's Bad Fur Day (US), recompiled with N64Recomp.
//
// Boots straight into the game (there's no launcher): the ROM is read from
// ux0:data/conker/baserom.us.z64 the first time and then kept by the runtime with
// the saves in ux0:data/conker/. Everything printed goes to ux0:data/conker/log.txt.
// The menu's Quit game quits.

#include <atomic>
#include <chrono>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <string>
#include <thread>
#include <vector>

#include <psp2/apputil.h>
#include <psp2/kernel/clib.h>
#include <exception>
#include <psp2/kernel/processmgr.h>
#include <psp2/power.h>
#include <psp2/sysmodule.h>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "librecomp/rsp.hpp"
#include "ultramodern/ultramodern.hpp"

#include "conker.hpp"
#include "vita_platform.hpp"
#include "vita_renderer.hpp"
#include "bench.hpp"
#include "audio_hle.hpp"
#include "audio_capture.hpp"
#include "vita_bootui.h"

// Memory: the newlib heap gets most of the app's budget (the ROM, RDRAM and the
// renderer's buffers come from it); every thread gets a generous stack, since the
// recompiled code keeps deep call chains on the host stack.
extern "C" {
    unsigned int _newlib_heap_size_user = 160 * 1024 * 1024;
    unsigned int _pthread_stack_default_user = 1 * 1024 * 1024;
    unsigned int sceUserMainThreadStackSize = 4 * 1024 * 1024;
}

extern "C" void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);
RspExitReason conker_audio_ucode(uint8_t* rdram, uint32_t ucode_addr);

namespace {
    const std::u8string game_id = u8"conker.n64.us.1.0";
    const std::filesystem::path data_dir = CONKER_VITA_DATA_DIR;

    std::atomic<uint32_t> vi_count{0};
    uint8_t* game_rdram = nullptr;
    std::atomic<uint32_t> audio_tasks{0};
    void vi_callback() { ++vi_count; }

    // See host/src/main.cpp: Conker runs with Status.FR set.
    void set_fr_mode(recomp_context* ctx) {
        constexpr uint32_t STATUS_FR = 0x04000000;
        cop0_status_write(ctx, ctx->status_reg | STATUS_FR);
    }

    void on_thread_create(uint8_t*, recomp_context* ctx) {
        set_fr_mode(ctx);
    }

    void on_init(uint8_t* rdram, recomp_context* ctx) {
        game_rdram = rdram;
        set_fr_mode(ctx);
        conker::register_tlb_mapped_code();
        conker::map_tlb_code_pages(rdram);

        constexpr int32_t osCicId = 0x80000310;
        MEM_W(osCicId, 0) = 6105;

        constexpr int32_t osRunningThread = 0x8002BE00;
        ultramodern::set_running_thread_variable(osRunningThread);
    }

    // The audio microcode: the HLE (audio_hle.cpp; bit-exact with the recompiled microcode over
    // 5000 tasks in check mode on a Vita, about 3.7x less CPU). debug_audio_hle holds 0 for the
    // recompiled microcode, 1 (or nothing) for the HLE, 2 for both, compared, with the
    // microcode's output used (differences go to the log).
    int audio_hle_mode = [] {
        int n = 1;
        if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_audio_hle", "r")) {
            if (std::fscanf(f, "%d", &n) != 1) n = 1;
            std::fclose(f);
        }
        return n;
    }();

    // Debugging: debug_dump_audio_task holds N: the N-th audio task's DMEM and RDRAM go
    // to files before it runs, and RDRAM after.
    int dump_audio_task = [] {
        int n = -1;
        if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_dump_audio_task", "r")) {
            if (std::fscanf(f, "%d", &n) != 1) n = -1;
            std::fclose(f);
        }
        return n;
    }();

    void dump_file(const char* name, const void* data, size_t size) {
        std::string path = std::string(CONKER_VITA_DATA_DIR "/") + name;
        if (FILE* f = std::fopen(path.c_str(), "wb")) {
            std::fwrite(data, 1, size, f);
            std::fclose(f);
        }
    }

    RspExitReason timed_audio_ucode(uint8_t* rdram, uint32_t ucode_addr) {
        const uint64_t start = sceKernelGetProcessTimeWide();
        static int task_number = 0;
        const bool dump = task_number++ == dump_audio_task;
        if (dump) {
            dump_file("task_dmem.bin", ::dmem, 0x1000);
            dump_file("task_rdram_before.bin", rdram, 8 * 1024 * 1024);
            char info[64];
            int len = std::snprintf(info, sizeof(info), "%08X\n", ucode_addr);
            dump_file("task_info.txt", info, (size_t)len);
        }
        conker::vita::audio_capture::before_task(rdram, ucode_addr);
        RspExitReason r = audio_hle_mode == 1 ? conker_audio_hle(rdram, ucode_addr)
                        : audio_hle_mode == 2 ? conker_audio_hle_check(rdram, ucode_addr)
                        : conker_audio_ucode(rdram, ucode_addr);
        conker::vita::audio_capture::after_task(rdram);
        if (dump) {
            dump_file("task_rdram_after.bin", rdram, 8 * 1024 * 1024);
            std::fprintf(stderr, "[vita] dumped audio task %d\n", task_number - 1);
        }
        conker::vita::bench::on_audio_task((uint32_t)(sceKernelGetProcessTimeWide() - start));
        return r;
    }

    RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
        if (task->t.type == M_AUDTASK) {
            ++audio_tasks;
            return timed_audio_ucode;
        }
        std::fprintf(stderr, "[vita] no RSP microcode for task type %u\n", (unsigned)task->t.type);
        return nullptr;
    }

    ultramodern::renderer::WindowHandle create_window(void*) {
        return ultramodern::renderer::WindowHandle{};
    }


    // Runs on the main thread (librecomp's loop): watches for the quit combo.
    void update_gfx(void*) {
        static auto last = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        if (now - last > std::chrono::seconds(3)) {
            last = now;
            int32_t running_id = -1, running_state = -1, running_pri = -1;
            if (game_rdram != nullptr) {
                const uint32_t t = *(uint32_t*)(game_rdram + 0x2BE00);
                if ((t & 0xFF800000u) == 0x80000000u) {
                    const uint32_t off = t & 0x7FFFFF;
                    running_pri = *(int32_t*)(game_rdram + off + 4);
                    running_state = *(uint16_t*)(game_rdram + ((off + 0x10) ^ 2));
                    running_id = *(int32_t*)(game_rdram + off + 0x14);
                }
            }
            if (game_rdram != nullptr) {
                auto b = [](uint32_t a) { return (unsigned)game_rdram[(a & 0x7FFFFF) ^ 3]; };
                auto w = [](uint32_t a) { return *(uint32_t*)(game_rdram + (a & 0x7FFFFF)); };
                std::fprintf(stderr, "[vita] sched: A580=%u A581=%u A582=%u A583=%u A584=%u AC6C=%u AC5C=%u B238=%u B239=%u B23A=%u task=%08X\n",
                    b(0x8003A580), b(0x8003A581), b(0x8003A582), b(0x8003A583), b(0x8003A584), b(0x8002AC6C), b(0x8002AC5C),
                    b(0x8003B238), b(0x8003B239), b(0x8003B23A), w(0x8002AC50));
            }
            std::fprintf(stderr, "[vita] heartbeat: %u VIs, %u audio tasks, %u audio frames queued, running thread %d (pri %d, state %d)\n",
                vi_count.load(), audio_tasks.load(), (unsigned)conker::vita::get_frames_remaining(), running_id, running_pri, running_state);
            char renderer_line[160];
            conker::vita::renderer_status(renderer_line, sizeof(renderer_line));
            std::fprintf(stderr, "[vita] renderer: %s\n", renderer_line);
        }
        conker::vita::poll_input();
        conker::vita::bench::update();
        if (conker::vita::quit_combo_held()) {
            ultramodern::quit();
        }
    }

    void message_box(const char* msg) {
        std::fprintf(stderr, "[vita] %s\n", msg);
    }

    void redirect_output() {
        std::filesystem::path log_path = data_dir / "log.txt";
        // Truncated once, then both streams append, so neither overwrites the other.
        if (FILE* f = std::fopen(log_path.c_str(), "w")) {
            std::fclose(f);
        }
        FILE* out = std::freopen(log_path.c_str(), "a", stdout);
        int out_errno = errno;
        FILE* err = std::freopen(log_path.c_str(), "a", stderr);
        std::fprintf(stderr, "[vita] stdout redirect %s (errno %d), stderr %s\n", out ? "ok" : "failed", out_errno, err ? "ok" : "failed");
        std::setvbuf(stdout, nullptr, _IONBF, 0);
        std::setvbuf(stderr, nullptr, _IONBF, 0);
    }

    // The ROM, if one was dropped into the data folder. Several names are accepted.
    std::filesystem::path find_rom() {
        static const char* names[] = { "baserom.us.z64", "conker.z64", "Conker's Bad Fur Day (USA).z64", "rom.z64" };
        for (const char* name : names) {
            std::error_code ec;
            std::filesystem::path p = data_dir / name;
            if (std::filesystem::is_regular_file(p, ec)) {
                return p;
            }
        }
        return {};
    }
}

ultramodern::input::connected_device_info_t conker::get_connected_device_info(int controller_num) {
    if (controller_num == 0) {
        return { ultramodern::input::Device::Controller, ultramodern::input::Pak::None };
    }
    return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
}

const char* conker::rom_error_text(recomp::RomValidationError error) {
    switch (error) {
        case recomp::RomValidationError::FailedToOpen:
            return "The file couldn't be opened.";
        case recomp::RomValidationError::NotARom:
            return "The file isn't an N64 ROM.";
        case recomp::RomValidationError::IncorrectRom:
            return "This isn't the US version of Conker's Bad Fur Day, the only one supported.";
        case recomp::RomValidationError::IncorrectVersion:
            return "This is Conker's Bad Fur Day, but not the US version.";
        default:
            return "The ROM couldn't be loaded.";
    }
}

namespace {
    // Uncaught exceptions: say which, where the log (and the emulator's) shows it.
    void on_terminate() {
        const char* what = "unknown";
        if (std::exception_ptr current = std::current_exception()) {
            try {
                std::rethrow_exception(current);
            }
            catch (const std::exception& e) {
                what = e.what();
                sceClibPrintf("[vita] uncaught exception: %s\n", what);
                std::fprintf(stderr, "[vita] uncaught exception: %s\n", what);
            }
            catch (...) {
                sceClibPrintf("[vita] uncaught exception\n");
            }
        }
        std::abort();
    }
}

namespace {
    thread_local int tls_probe = 0;
}

#if defined(CONKER_RSP_TRACE)
RspExitReason traced_audio_ucode(uint8_t* rdram, uint32_t ucode_addr);
void rsp_trace_write(const char* path);

// Runs the dumped audio task (debug_dump_audio_task) with the traced microcode.
static bool run_rsp_harness() {
    FILE* flag = std::fopen(CONKER_VITA_DATA_DIR "/debug_rsp_harness", "r");
    if (!flag) return false;
    std::fclose(flag);
    auto load = [](const char* name, void* out, size_t size) {
        std::string path = std::string(CONKER_VITA_DATA_DIR "/") + name;
        FILE* f = std::fopen(path.c_str(), "rb");
        if (f) { std::fread(out, 1, size, f); std::fclose(f); }
    };
    uint8_t* rdram = (uint8_t*)calloc(64, 1024 * 1024);
    load("task_rdram_before.bin", rdram, 8 * 1024 * 1024);
    load("task_dmem.bin", dmem, 0x1000);
    uint32_t ucode = 0;
    if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/task_info.txt", "r")) { std::fscanf(f, "%x", &ucode); std::fclose(f); }
    recomp::rsp::constants_init();
    RspExitReason r = traced_audio_ucode(rdram, ucode);
    rsp_trace_write(CONKER_VITA_DATA_DIR "/rsp_trace_vita.bin");
    if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/task_rdram_harness.bin", "wb")) { std::fwrite(rdram, 1, 8 * 1024 * 1024, f); std::fclose(f); }
    std::fprintf(stderr, "[vita] rsp harness done: exit %d\n", (int)r);
    return true;
}
#endif

// Runs the dumped audio task (debug_dump_audio_task) with the microcode as built, for
// comparing its output (task_rdram_native.bin) with the task's (task_rdram_after.bin).
static bool run_rsp_native() {
    FILE* flag = std::fopen(CONKER_VITA_DATA_DIR "/debug_rsp_native", "r");
    if (!flag) return false;
    std::fclose(flag);
    auto load = [](const char* name, void* out, size_t size) {
        std::string path = std::string(CONKER_VITA_DATA_DIR "/") + name;
        FILE* f = std::fopen(path.c_str(), "rb");
        if (f) { std::fread(out, 1, size, f); std::fclose(f); }
    };
    uint8_t* rdram = (uint8_t*)calloc(64, 1024 * 1024);
    load("task_rdram_before.bin", rdram, 8 * 1024 * 1024);
    load("task_dmem.bin", dmem, 0x1000);
    uint32_t ucode = 0;
    if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/task_info.txt", "r")) { std::fscanf(f, "%x", &ucode); std::fclose(f); }
    recomp::rsp::constants_init();
    const uint64_t t0 = sceKernelGetProcessTimeWide();
    RspExitReason r = conker_audio_ucode(rdram, ucode);
    const uint64_t t1 = sceKernelGetProcessTimeWide();
    std::remove(CONKER_VITA_DATA_DIR "/task_rdram_native.bin");
    if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/task_rdram_native.bin", "wb")) { std::fwrite(rdram, 1, 8 * 1024 * 1024, f); std::fclose(f); }
    std::fprintf(stderr, "[vita] rsp native run done: exit %d, %llu us\n", (int)r, (unsigned long long)(t1 - t0));
    return true;
}

extern "C" volatile bool ultramodern_vita_double_draw;
extern "C" volatile bool ultramodern_vita_late_signal;

int main(int argc, char** argv) {
    std::set_terminate(on_terminate);
    sceClibPrintf("[vita] main\n");
    // Run the CPU, bus and GPU at their highest clocks: the recompiled game and the
    // RSP audio microcode need every cycle of the Cortex-A9.
    scePowerSetArmClockFrequency(444);
    scePowerSetBusClockFrequency(222);
    scePowerSetGpuClockFrequency(222);
    scePowerSetGpuXbarClockFrequency(166);

    SceAppUtilInitParam init_param{};
    SceAppUtilBootParam boot_param{};
    sceAppUtilInit(&init_param, &boot_param);

    std::error_code ec;
    std::filesystem::create_directories(data_dir, ec);
    sceClibPrintf("[vita] data dir: %s\n", ec ? ec.message().c_str() : "ok");
    redirect_output();
    std::fprintf(stderr, "[vita] Conker's Bad Fur Day: Recompiled, PS Vita build, version " CONKER_PORT_VERSION "\n");
    {
        tls_probe = 1;
        void* main_addr = &tls_probe;
        void* other_addr = nullptr;
        int other_value = -1;
        std::thread probe([&] { other_addr = &tls_probe; other_value = tls_probe; });
        probe.join();
        std::fprintf(stderr, "[vita] TLS check: main %p, other thread %p (value there %d)\n", main_addr, other_addr, other_value);
    }

    {
        extern bool ultramodern_early_rsp_completion;
        if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_no_early_rsp", "r")) {
            std::fclose(f);
            ultramodern_early_rsp_completion = false;
            std::fprintf(stderr, "[vita] RSP tasks complete when they end (debug)\n");
        }
    }
    {
        if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_double_draw", "r")) {
            std::fclose(f);
            ultramodern_vita_double_draw = true;
            std::fprintf(stderr, "[vita] every display list drawn twice (debug: the load of 60 fps)\n");
        }
    }
    if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_late_signal", "r")) {
        std::fclose(f);
        ultramodern_vita_late_signal = true;
        std::fprintf(stderr, "[vita] the game hears a list is done when it's read (debug)\n");
    }
    conker::vita::bench::init();
    // The boot picture with the port's version, and the check for a newer release
    // (vita_bootui.c), before the renderer takes the screen. Not during a bench run.
    if (uint32_t* boot_fb = vita_boot_picture_show(); boot_fb && !conker::vita::bench::active()) {
        vita_bootui_run(boot_fb);
    }
    if (run_rsp_native()) {
        sceKernelExitProcess(0);
        return 0;
    }
#if defined(CONKER_RSP_TRACE)
    if (run_rsp_harness()) {
        sceKernelExitProcess(0);
        return 0;
    }
#endif
    conker::vita::input_init();
    conker::vita::audio_capture::init();
    if (audio_hle_mode) std::fprintf(stderr, "[vita] audio: %s\n", audio_hle_mode == 2 ? "HLE checked against the microcode" : "HLE");
    conker::vita::audio_init();

    recomp::register_config_path(data_dir);

    recomp::GameEntry game{};
    game.rom_hash = conker::roms::us_rom_hash;
    game.accept_rom = conker::roms::accept;
    game.internal_name = "CONKER BFD";
    game.display_name = "Conker's Bad Fur Day";
    game.game_id = game_id;
    game.mod_game_id = "conker";
    game.save_type = recomp::SaveType::Eep16k;
    game.is_enabled = true;
    // Only mods' hooks need the decompressed code, and the Vita build has no code mods:
    // skip the 64MB copy of the ROM the runtime would make for them.
    game.has_compressed_code = false;
    game.decompression_routine = nullptr;
    game.entrypoint_address = (gpr)(int32_t)0x80001000u;
    game.entrypoint = recomp_entrypoint;
    game.on_init_callback = on_init;
    game.thread_create_callback = on_thread_create;
    recomp::register_game(game);

    conker::register_overlays();
    conker::register_mod_exports();

    // The runtime keeps its own copy of the ROM (conker.n64.us.1.0.z64) in the data
    // folder. Until it has one, a ROM dropped into the folder is validated and stored.
    recomp::check_all_stored_roms();
    if (!recomp::is_rom_valid(game_id)) {
        std::filesystem::path rom_path = find_rom();
        if (rom_path.empty()) {
            const char* msg = "No ROM found.\n\nCopy your US Conker's Bad Fur Day ROM (.z64) to\n"
                CONKER_VITA_DATA_DIR "/baserom.us.z64\nand start the game again.";
            std::fprintf(stderr, "[vita] %s\n", msg);
            conker::vita::show_error(msg);
            sceKernelExitProcess(0);
            return EXIT_FAILURE;
        }
        std::fprintf(stderr, "[vita] importing %s\n", rom_path.c_str());
        recomp::RomValidationError result = recomp::select_rom(rom_path, game_id);
        if (result != recomp::RomValidationError::Good) {
            std::string msg = std::string(rom_path.c_str()) + ":\n" + conker::rom_error_text(result);
            std::fprintf(stderr, "[vita] %s\n", msg.c_str());
            conker::vita::show_error(msg.c_str());
            sceKernelExitProcess(0);
            return EXIT_FAILURE;
        }
        recomp::check_all_stored_roms();
    }

    std::vector<char*> runtime_argv{ argv[0], (char*)"--game", (char*)"conker" };

    recomp::Configuration cfg{};
    cfg.argc = (int)runtime_argv.size();
    cfg.argv = runtime_argv.data();
    cfg.project_version = recomp::Version{ 1, 1, 0 };
    cfg.rsp_callbacks.get_rsp_microcode = get_rsp_microcode;
    cfg.audio_callbacks = { conker::vita::queue_samples, conker::vita::get_frames_remaining, conker::vita::set_frequency };
    cfg.renderer_callbacks.create_render_context = conker::vita::create_renderer;
    cfg.input_callbacks = { conker::vita::poll_input, conker::vita::get_input, conker::vita::set_rumble, conker::get_connected_device_info };
    cfg.gfx_callbacks = { nullptr, create_window, update_gfx };
    cfg.events_callbacks = { vi_callback, nullptr };
    cfg.error_handling_callbacks = { message_box };

    recomp::start(cfg);

    conker::vita::audio_shutdown();
    std::fprintf(stderr, "[vita] exited\n");
    sceKernelExitProcess(0);
    return EXIT_SUCCESS;
}
