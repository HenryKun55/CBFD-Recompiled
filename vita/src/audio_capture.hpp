#ifndef __CONKER_VITA_AUDIO_CAPTURE_HPP__
#define __CONKER_VITA_AUDIO_CAPTURE_HPP__

#include <cstdint>

// Debugging: captures audio tasks as test inputs for vita/tools/audio_hle_test.
//
// ux0:data/conker/debug_capture_audio holds "<max dumps> <stride>": every <stride>-th
// audio task, and any task using a command fewer than 4 dumped tasks used so far, goes
// to ux0:data/conker/audiocap/task_NNNNNN.bin (the DMEM and 8 MiB of RDRAM before the
// task, plus a hash of RDRAM after it) until <max dumps> are written. Every task's command
// counts go to audiocap/summary.txt.
namespace conker::vita::audio_capture {
    // Reads the flag file; false (and the hooks do nothing) when there is none.
    bool init();
    bool active();
    // Around the task's microcode (DMEM holds the task already).
    void before_task(const uint8_t* rdram, uint32_t ucode_addr);
    void after_task(const uint8_t* rdram);
}

#endif
