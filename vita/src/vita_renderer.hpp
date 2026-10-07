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
}

#endif
