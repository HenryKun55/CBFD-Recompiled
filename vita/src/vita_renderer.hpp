#ifndef __VITA_RENDERER_HPP__
#define __VITA_RENDERER_HPP__

#include <cstdint>
#include <memory>

#include "ultramodern/renderer_context.hpp"

namespace conker::vita {
    // The game's renderer on the Vita: a high-level emulation of the game's graphics
    // microcode (F3DEX2 with Conker's changes) and of the RDP, drawn with vitaGL.
    std::unique_ptr<ultramodern::renderer::RendererContext> create_renderer(
        uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);
    // Where the renderer's threads are now (for the heartbeat log: finding a freeze).
    void renderer_status(char* out, unsigned size);
    // The drawing thread's busy time since the last call, ms.
    unsigned renderer_back_busy_ms();
    // The game thread's time copying RDRAM for the renderer since the last call, us.
    unsigned long long renderer_snapshot_us();
    // ... its waits for a free capture, us, and the pages it copied.
    unsigned long long renderer_capture_wait_us();
    unsigned long long renderer_capture_pages();
}

#endif
