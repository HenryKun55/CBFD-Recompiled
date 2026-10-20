#ifndef __CONKER_AUDIO_HLE_HPP__
#define __CONKER_AUDIO_HLE_HPP__

#include <cstdint>

#include "librecomp/rsp.hpp"

// High-level implementation of Conker's audio microcode (Rare's n_aspMain variant,
// recompiled in RecompiledFuncs/rsp/audio_ucode.cpp): the audio list's commands in plain
// C++, bit-exact with the microcode. It works on the same DMEM as the microcode (the
// task's state, buffers and scratch, at the same addresses), so what it leaves in RDRAM
// and DMEM is what the microcode would leave.
//
// MP3 runs the recompiled microcode's MP3 overlay (conker_audio_ucode1) for that one
// command. Lists the HLE does not cover (cmd 0xE, buffers off the alignment the
// microcode's vector loads assume, ...) run entirely on the recompiled microcode.
RspExitReason conker_audio_hle(uint8_t* rdram, uint32_t ucode_addr);

// For trying the HLE on hardware: runs the task with the HLE, notes what it wrote, puts
// RDRAM and DMEM back, runs the microcode (whose output stays) and compares; differences go
// to stderr. (Tasks with MP3 just run the microcode.)
RspExitReason conker_audio_hle_check(uint8_t* rdram, uint32_t ucode_addr);

namespace conker::audio_hle {
    // Whether conker_audio_hle runs the task in DMEM itself (false: the microcode does).
    bool task_supported(const uint8_t* rdram);
    // After task_supported() returned false: the list's command that was the reason (-1: the list itself).
    int unsupported_command();

    struct Stats {
        uint32_t tasks;          // tasks run by the HLE
        uint32_t fallbacks;      // tasks handed to the recompiled microcode
        uint32_t mp3_commands;   // MP3 commands (run by the microcode's overlay)
        uint32_t commands[16];   // commands run, by number
        uint64_t command_ns[16]; // their time, with AUDIO_HLE_PROFILE defined
        uint32_t checked;        // tasks run by conker_audio_hle_check
        uint32_t check_mismatches;
    };
    const Stats& stats();
    void reset_stats();
}

#endif
