#ifndef __CONKER_VITA_BENCH_HPP__
#define __CONKER_VITA_BENCH_HPP__

#include <cstdint>

// Automated benchmark for the Vita build (vita/tools/bench_vita3k.sh), requested through
// ux0:data/conker/bench.txt:
//   <seconds> <shot every N s> <input script>
// The input script is a comma-separated list of "<time s>:<buttons>" presses, held for
// a quarter of a second (buttons as letters: A B Z S(tart) L R U D (d-pad) and
// u d l r (C-buttons); a press "-" is just a mark). The measured run starts at boot and
// lasts <seconds>; then the per-second results go to bench_result.txt and the per-frame
// times to bench_frames.csv, and the game quits.
namespace conker::vita::bench {
    void init();
    bool active();
    // Buttons the script holds now (N64 bits), to OR into the controller.
    uint16_t scripted_buttons();
    // Vita buttons the script holds now ("<time>:@<buttons>": X O T Q S E U D L R l r).
    uint32_t scripted_vita_buttons();
    // The left stick the script tilts now ("<time>:~<x>/<y>/<seconds>", 0..255, 128 centred).
    bool scripted_stick(uint8_t* lx, uint8_t* ly);
    // From the gfx thread: a display list took this long to render.
    void on_display_list(uint32_t render_us, uint32_t tris);
    // From the gfx thread: a frame went to the screen.
    void on_present();
    // From the main thread's loop: writes the results and quits when the time is up.
    void update();
    // From the RSP task thread: an audio task took this long.
    void on_audio_task(uint32_t us);
}

#endif
