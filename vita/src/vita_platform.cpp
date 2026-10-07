// Vita input and sound for Conker's Bad Fur Day: Recompiled.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <vector>

#include <psp2/kernel/sysmem.h>
#include <psp2/audioout.h>
#include <psp2/ctrl.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/touch.h>
#include <psp2/kernel/processmgr.h>

#include "vita_platform.hpp"
#include "bench.hpp"
#include "controls.hpp"
#include "menu.hpp"

// ---------------------------------------------------------------- input
//
// The Vita's state goes through the remapping (controls.cpp); START + SELECT opens the
// menu (menu.cpp), and while it's open the game sees a released controller.
namespace controls = conker::vita::controls;
namespace menu = conker::vita::menu;

namespace {
    std::mutex input_mutex;
    controls::VitaState state{};
    bool vita_tv = false;
}

void conker::vita::input_init() {
    // Both modes: the Ext functions (for the PlayStation TV) keep their own, and read the
    // sticks as centred without it (on hardware; Vita3K doesn't mind).
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG_WIDE);
    sceCtrlSetSamplingModeExt(SCE_CTRL_MODE_ANALOG_WIDE);
    vita_tv = sceKernelIsPSVitaTV() != 0;
    sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, SCE_TOUCH_SAMPLING_STATE_START);
    sceTouchSetSamplingState(SCE_TOUCH_PORT_BACK, SCE_TOUCH_SAMPLING_STATE_START);
    controls::load();
}

void conker::vita::poll_input() {
    controls::VitaState s{};
    // Ext2 on the PlayStation TV: a DualShock's L1/R1/L3/R3 too.
    if (vita_tv) {
        sceCtrlPeekBufferPositiveExt2(0, &s.pad, 1);
    }
    else {
        sceCtrlPeekBufferPositive(0, &s.pad, 1);
    }
    sceTouchPeek(SCE_TOUCH_PORT_FRONT, &s.front, 1);
    sceTouchPeek(SCE_TOUCH_PORT_BACK, &s.back, 1);
    s.pad.buttons |= conker::vita::bench::scripted_vita_buttons();
    {
        std::lock_guard lock{input_mutex};
        state = s;
    }
    menu::update(s);
}

bool conker::vita::get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;
    if (controller_num != 0) {
        return false;
    }
    controls::VitaState s;
    {
        std::lock_guard lock{input_mutex};
        s = state;
    }
    const bool combo = (s.pad.buttons & (SCE_CTRL_START | SCE_CTRL_SELECT)) == (SCE_CTRL_START | SCE_CTRL_SELECT);
    if (!menu::is_open() && !combo) {
        controls::to_n64(controls::current(), s, buttons, x, y);
    }
    *buttons |= conker::vita::bench::scripted_buttons();
    return true;
}

void conker::vita::set_rumble(int, bool) {}

bool conker::vita::quit_combo_held() {
    return menu::quit_requested();
}

// ---------------------------------------------------------------- audio
//
// The game's audio thread hands over each buffer the microcode mixed and paces
// itself by how much is still queued (osAiGetLength). The buffers are resampled
// from the game's rate to 48 kHz into a ring, which a thread feeds to SceAudio in
// fixed blocks.
namespace {
    constexpr int out_rate = 48000;
    constexpr int out_block = 512; // frames per sceAudioOutOutput call (~10.7 ms)
    // ~340 ms of 48 kHz stereo.
    constexpr size_t ring_frames = 16384;

    std::mutex audio_mutex;
    std::vector<int16_t> ring(ring_frames * 2);
    size_t ring_read = 0;  // in frames
    size_t ring_count = 0; // frames queued
    uint32_t in_rate = 32000;
    // Resampler position between the last input frame and the next, in input frames.
    double resample_phase = 0.0;
    int16_t last_l = 0, last_r = 0;

    int audio_port = -1;
    // The game paces its audio by how much is still queued. That's worked out from the
    // clock rather than from the ring, so the game never waits on the output device: the
    // frames handed over, less those a 48 kHz clock has played since.
    uint64_t frames_given = 0;     // output frames, since the clock started
    uint64_t clock_start_us = 0;
    SceUID audio_thread_id = -1;
    std::atomic<bool> audio_running{false};

    int audio_thread(SceSize, void*) {
        static int16_t block[out_block * 2];
        while (audio_running.load()) {
            {
                std::lock_guard lock{audio_mutex};
                size_t frames = std::min<size_t>(ring_count, out_block);
                for (size_t i = 0; i < frames; i++) {
                    size_t idx = (ring_read + i) % ring_frames;
                    block[i * 2 + 0] = ring[idx * 2 + 0];
                    block[i * 2 + 1] = ring[idx * 2 + 1];
                }
                // An underrun plays silence for the rest of the block.
                if (frames < (size_t)out_block) {
                    std::memset(&block[frames * 2], 0, (out_block - frames) * 2 * sizeof(int16_t));
                }
                ring_read = (ring_read + frames) % ring_frames;
                ring_count -= frames;
            }
            // Blocks until the hardware takes the block, which paces this thread.
            sceAudioOutOutput(audio_port, block);
        }
        return 0;
    }
}

void conker::vita::audio_init() {
    audio_port = sceAudioOutOpenPort(SCE_AUDIO_OUT_PORT_TYPE_BGM, out_block, out_rate, SCE_AUDIO_OUT_MODE_STEREO);
    if (audio_port < 0) {
        std::fprintf(stderr, "[audio] sceAudioOutOpenPort failed: 0x%08X\n", audio_port);
        return;
    }
    int volume[2] = { SCE_AUDIO_VOLUME_0DB, SCE_AUDIO_VOLUME_0DB };
    sceAudioOutSetVolume(audio_port, (SceAudioOutChannelFlag)(SCE_AUDIO_VOLUME_FLAG_L_CH | SCE_AUDIO_VOLUME_FLAG_R_CH), volume);
    std::fprintf(stderr, "[audio] port %d\n", audio_port);
    audio_running = true;
    // A high priority, on core 0 with the system's audio work, away from the game's threads.
    // Above the game's threads, but not starving them if the output doesn't block.
    audio_thread_id = sceKernelCreateThread("conker_audio", audio_thread, 0x10000100 - 8, 0x10000, 0, 0, nullptr);
    if (audio_thread_id >= 0) {
        sceKernelStartThread(audio_thread_id, 0, nullptr);
    }
}

void conker::vita::audio_shutdown() {
    if (audio_thread_id >= 0) {
        audio_running = false;
        sceKernelWaitThreadEnd(audio_thread_id, nullptr, nullptr);
        sceKernelDeleteThread(audio_thread_id);
        audio_thread_id = -1;
    }
    if (audio_port >= 0) {
        sceAudioOutReleasePort(audio_port);
        audio_port = -1;
    }
}

void conker::vita::set_frequency(uint32_t frequency) {
    std::fprintf(stderr, "[audio] frequency %u\n", frequency);
    std::lock_guard lock{audio_mutex};
    if (frequency > 0) {
        in_rate = frequency;
    }
    resample_phase = 0.0;
}

namespace {
    // Debugging: ux0:data/conker/debug_record_audio makes the game's audio (as handed
    // over, at its own rate) go to audio.raw too.
    FILE* audio_record = [] {
        if (FILE* f = std::fopen(CONKER_VITA_DATA_DIR "/debug_record_audio", "r")) {
            std::fclose(f);
            return std::fopen(CONKER_VITA_DATA_DIR "/audio.raw", "wb");
        }
        return (FILE*)nullptr;
    }();
}

void conker::vita::queue_samples(int16_t* samples, size_t sample_count) {
    std::lock_guard lock{audio_mutex};
    if (audio_record != nullptr) {
        for (size_t i = 0; i + 1 < sample_count; i += 2) {
            const int16_t lr[2] = { samples[i + 1], samples[i] };
            std::fwrite(lr, sizeof(lr), 1, audio_record);
        }
    }
    const double step = (double)in_rate / (double)out_rate;
    const size_t in_frames = sample_count / 2;
    // Linear interpolation between the previous frame and the current one. RDRAM is
    // kept as native-endian 32-bit words, so each frame's samples read back swapped:
    // [i * 2 + 1] is the left channel and [i * 2] the right.
    for (size_t i = 0; i < in_frames; i++) {
        int16_t l = samples[i * 2 + 1];
        int16_t r = samples[i * 2 + 0];
        while (resample_phase < 1.0) {
            frames_given++;
            if (ring_count >= ring_frames) {
                // Full: drop the rest rather than overwrite what's playing.
                last_l = l;
                last_r = r;
                return;
            }
            float t = (float)resample_phase;
            size_t idx = (ring_read + ring_count) % ring_frames;
            ring[idx * 2 + 0] = (int16_t)(last_l + (l - last_l) * t);
            ring[idx * 2 + 1] = (int16_t)(last_r + (r - last_r) * t);
            ring_count++;
            resample_phase += step;
        }
        resample_phase -= 1.0;
        last_l = l;
        last_r = r;
    }
}

size_t conker::vita::get_frames_remaining() {
    std::lock_guard lock{audio_mutex};
    const uint64_t now = sceKernelGetProcessTimeWide();
    if (clock_start_us == 0) {
        clock_start_us = now;
    }
    uint64_t played = (now - clock_start_us) * out_rate / 1000000;
    if (played > frames_given) {
        // Starved (loading, a slow frame): the clock restarts from what was given.
        clock_start_us = now - frames_given * 1000000 / out_rate;
        played = frames_given;
    }
    const uint64_t pending = frames_given - played;
    // In the game's rate. As on the desktop build, leave one of the game's buffers
    // out: AI_LEN only counts what's left of the one playing.
    size_t queued = (size_t)((double)pending * in_rate / out_rate);
    constexpr size_t one_buffer = 736;
    return queued > one_buffer ? queued - one_buffer : 0;
}

// ---------------------------------------------------------------- errors
#include <psp2/common_dialog.h>
#include <psp2/message_dialog.h>
#include <vitaGL.h>

// Before the game starts there's no renderer yet: bring vitaGL up just to show the
// system's message dialog over a black screen.
void conker::vita::show_error(const char* message) {
    vglInit(0);
    SceMsgDialogUserMessageParam user{};
    user.buttonType = SCE_MSG_DIALOG_BUTTON_TYPE_OK;
    user.msg = (const SceChar8*)message;
    SceMsgDialogParam param;
    sceMsgDialogParamInit(&param);
    param.mode = SCE_MSG_DIALOG_MODE_USER_MSG;
    param.userMsgParam = &user;
    if (sceMsgDialogInit(&param) < 0) {
        return;
    }
    while (sceMsgDialogGetStatus() != SCE_COMMON_DIALOG_STATUS_FINISHED) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        vglSwapBuffers(GL_TRUE);
    }
    sceMsgDialogTerm();
}

// ---------------------------------------------------------------- POSIX shims (posix_shim/sys/mman.h)
#include <malloc.h>
#include <sys/mman.h>

extern "C" void* mmap(void*, size_t length, int, int flags, int, off_t) {
    if (!(flags & MAP_ANON)) {
        return MAP_FAILED;
    }
    void* p = memalign(4096, length);
    if (p == nullptr) {
        return MAP_FAILED;
    }
    std::memset(p, 0, length);
    return p;
}

extern "C" int munmap(void* addr, size_t) {
    free(addr);
    return 0;
}

extern "C" int mprotect(void*, size_t, int) {
    return 0;
}

extern "C" int getpagesize(void) {
    return 4096;
}

// Mods' native libraries (.so) can't be loaded on the Vita.
extern "C" void* dlopen(const char*, int) { return nullptr; }
extern "C" void* dlsym(void*, const char*) { return nullptr; }
extern "C" int dlclose(void*) { return 0; }
extern "C" char* dlerror(void) { return (char*)"dynamic libraries aren't supported"; }

// The runtime starts a thread from a global constructor (librecomp's ModContext):
// bring pthreads up before any of them run.
extern "C" int pthread_init(void);
__attribute__((constructor(101))) static void conker_vita_early_pthread_init() {
    pthread_init();
}

extern "C" int posix_memalign(void** memptr, size_t alignment, size_t size) {
    void* p = memalign(alignment < sizeof(void*) ? sizeof(void*) : alignment, size);
    if (p == nullptr) {
        return 12; // ENOMEM
    }
    *memptr = p;
    return 0;
}
