#ifndef __VITA_PLATFORM_HPP__
#define __VITA_PLATFORM_HPP__

#include <cstddef>
#include <cstdint>

// Where the Vita build keeps the ROM, saves and log.
#define CONKER_VITA_DATA_DIR "ux0:data/conker"

namespace conker::vita {
    // Input: the Vita's buttons and sticks as the N64 controller.
    void input_init();
    void poll_input();
    bool get_input(int controller_num, uint16_t* buttons, float* x, float* y);
    void set_rumble(int controller_num, bool on);
    // True while START + SELECT are held (quits the game).
    bool quit_combo_held();

    // Audio: the game's mixed buffers go out through SceAudio at 48 kHz.
    void audio_init();
    void audio_shutdown();
    void queue_samples(int16_t* samples, size_t sample_count);
    size_t get_frames_remaining();
    void set_frequency(uint32_t frequency);

    // Shows a message on screen with the system dialog (blocks until dismissed).
    void show_error(const char* message);
}

#endif
