// The renderer's back on the Vita's GPU directly (sceGxm), in place of vitaGL (included
// by vita_renderer.cpp when CONKER_GXM is set).
//
// vitaGL emulates OpenGL over sceGxm: every draw checks and copies its state, its vertices
// and its uniforms, which on the Vita costs far more than the draw itself (the game makes
// some 250 a frame). Here the lists' draws go straight to sceGxm:
//  - one vertex program; a fragment program per combiner and blend state, patched once;
//  - the vertices and indices copied to a ring in GPU memory, a third of it per frame;
//  - the N64's framebuffers are colour surfaces (textures too) with a depth/stencil
//    surface by size that keeps its contents across scenes (forced load and store);
//  - a scissor smaller than the target is a stencil mask, drawn when it changes;
//  - textures freed once the frames that may read them are on screen.
// The coordinates are GL's: framebuffers' rows go up from the bottom (row 0 is y = -1), so
// their textures are read as the GL version reads them.

namespace gxm {
    struct Block {
        SceUID uid = -1;
        uint8_t* base = nullptr;
        uint32_t size = 0;
    };

    // Memory the GPU reads and writes (CDRAM in 256KB steps, LPDDR in 4KB ones).
    inline Block alloc_mapped(uint32_t type, uint32_t size, const char* name) {
        const uint32_t align = type == SCE_KERNEL_MEMBLOCK_TYPE_USER_CDRAM_RW ? 256 * 1024 : 4096;
        size = (size + align - 1) & ~(align - 1);
        Block b;
        b.uid = sceKernelAllocMemBlock(name, (SceKernelMemBlockType)type, size, nullptr);
        if (b.uid < 0) {
            std::fprintf(stderr, "[gxm] couldn't allocate %u KB for %s: 0x%08X\n", size / 1024, name, (unsigned)b.uid);
            b.uid = -1;
            return b;
        }
        void* base = nullptr;
        sceKernelGetMemBlockBase(b.uid, &base);
        b.base = (uint8_t*)base;
        b.size = size;
        const int r = sceGxmMapMemory(base, size, SCE_GXM_MEMORY_ATTRIB_RW);
        if (r < 0) std::fprintf(stderr, "[gxm] couldn't map %s: 0x%08X\n", name, (unsigned)r);
        return b;
    }

    inline Block alloc_usse(uint32_t size, bool fragment, unsigned int* offset, const char* name) {
        size = (size + 4095) & ~4095u;
        Block b;
        b.uid = sceKernelAllocMemBlock(name, (SceKernelMemBlockType)SCE_KERNEL_MEMBLOCK_TYPE_USER_RW_UNCACHE, size, nullptr);
        if (b.uid < 0) {
            std::fprintf(stderr, "[gxm] couldn't allocate %s: 0x%08X\n", name, (unsigned)b.uid);
            b.uid = -1;
            return b;
        }
        void* base = nullptr;
        sceKernelGetMemBlockBase(b.uid, &base);
        b.base = (uint8_t*)base;
        b.size = size;
        if (fragment) sceGxmMapFragmentUsseMemory(base, size, offset);
        else sceGxmMapVertexUsseMemory(base, size, offset);
        return b;
    }

    // Allocations inside a mapped block.
    class Heap {
    public:
        bool init(uint32_t type, uint32_t size, const char* name) {
            block = alloc_mapped(type, size, name);
            if (block.base == nullptr) return false;
            space = sceClibMspaceCreate(block.base, block.size);
            return space != nullptr;
        }
        void* alloc(uint32_t size, uint32_t align) { return sceClibMspaceMemalign(space, align, size); }
        void free(void* p) { if (p) sceClibMspaceFree(space, p); }
    private:
        Block block;
        SceClibMspace space = nullptr;
    };

    inline uint32_t align_up(uint32_t v, uint32_t a) { return (v + a - 1) & ~(a - 1); }

    // A texture's wrapping, written into its control word as vitaGL does: the API refuses
    // MIRROR on linear textures (SCE_GXM_ERROR_UNSUPPORTED, the texture left clamped: Conker's
    // mirrored walls showed as stretched stripes on a Vita), but the hardware samples it.
    inline void set_addr_modes(SceGxmTexture* texture, SceGxmTextureAddrMode u, SceGxmTextureAddrMode v) {
        uint32_t* control = reinterpret_cast<uint32_t*>(texture);
        control[0] = (control[0] & ~0x1F8u) | (((uint32_t)u << 6) & 0x1C0u) | (((uint32_t)v << 3) & 0x38u);
    }

    SceGxmBlendFactor blend_factor(GLenum f) {
        switch (f) {
            case GL_ZERO: return SCE_GXM_BLEND_FACTOR_ZERO;
            case GL_ONE: return SCE_GXM_BLEND_FACTOR_ONE;
            case GL_SRC_COLOR: return SCE_GXM_BLEND_FACTOR_SRC_COLOR;
            case GL_ONE_MINUS_SRC_COLOR: return SCE_GXM_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
            case GL_SRC_ALPHA: return SCE_GXM_BLEND_FACTOR_SRC_ALPHA;
            case GL_ONE_MINUS_SRC_ALPHA: return SCE_GXM_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
            case GL_DST_COLOR: return SCE_GXM_BLEND_FACTOR_DST_COLOR;
            case GL_ONE_MINUS_DST_COLOR: return SCE_GXM_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
            case GL_DST_ALPHA: return SCE_GXM_BLEND_FACTOR_DST_ALPHA;
            case GL_ONE_MINUS_DST_ALPHA: return SCE_GXM_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
            default: return SCE_GXM_BLEND_FACTOR_ONE;
        }
    }

    SceGxmDepthFunc depth_func(GLenum f) {
        switch (f) {
            case GL_NEVER: return SCE_GXM_DEPTH_FUNC_NEVER;
            case GL_LESS: return SCE_GXM_DEPTH_FUNC_LESS;
            case GL_EQUAL: return SCE_GXM_DEPTH_FUNC_EQUAL;
            case GL_LEQUAL: return SCE_GXM_DEPTH_FUNC_LESS_EQUAL;
            case GL_GREATER: return SCE_GXM_DEPTH_FUNC_GREATER;
            case GL_NOTEQUAL: return SCE_GXM_DEPTH_FUNC_NOT_EQUAL;
            case GL_GEQUAL: return SCE_GXM_DEPTH_FUNC_GREATER_EQUAL;
            default: return SCE_GXM_DEPTH_FUNC_ALWAYS;
        }
    }

    SceGxmTextureAddrMode addr_mode(GLenum wrap) {
        switch (wrap) {
            case GL_REPEAT: return SCE_GXM_TEXTURE_ADDR_REPEAT;
            case GL_MIRRORED_REPEAT: return SCE_GXM_TEXTURE_ADDR_MIRROR;
            default: return SCE_GXM_TEXTURE_ADDR_CLAMP;
        }
    }

    // The shaders, in Cg. The combiners' come from the GLSL the front writes: the same
    // statements, with GLSL's names defined as Cg's.
    const char* const cg_prelude =
        "#define vec2 float2\n"
        "#define vec3 float3\n"
        "#define vec4 float4\n"
        "#define mix lerp\n"
        "#define fract frac\n"
        "#define texture2D tex2D\n";

    const char* const vertex_cg =
        "void main(float4 aPos, float4 aColor, float4 aUV,\n"
        "          out float4 oPos : POSITION, out float4 vColor : TEXCOORD1, out float4 vUV : TEXCOORD0) {\n"
        "  oPos = aPos;\n"
        "  vColor = aColor;\n"
        "  vUV = aUV;\n"
        "}\n";

    const char* const present_cg =
        "uniform sampler2D uTex0;\n"
        "float4 main(float4 vUV : TEXCOORD0) : COLOR {\n"
        "  return float4(tex2D(uTex0, vUV.xy).rgb, 1.0);\n"
        "}\n";

    const char* const copy_cg =
        "uniform sampler2D uTex0;\n"
        "float4 main(float4 vUV : TEXCOORD0) : COLOR {\n"
        "  return tex2D(uTex0, vUV.xy);\n"
        "}\n";

    const char* const ui_cg =
        "uniform sampler2D uTex0;\n"
        "float4 main(float4 vColor : TEXCOORD1, float4 vUV : TEXCOORD0) : COLOR {\n"
        "  return float4(vColor.rgb, vColor.a * tex2D(uTex0, vUV.xy).a);\n"
        "}\n";

    const char* const fill_cg =
        "uniform float4 uFill;\n"
        "float4 main() : COLOR {\n"
        "  return uFill;\n"
        "}\n";

    // A combiner's GLSL fragment shader as Cg.
    std::string combiner_cg(const std::string& glsl) {
        std::string out = cg_prelude;
        size_t pos = 0;
        while (pos < glsl.size()) {
            size_t end = glsl.find('\n', pos);
            if (end == std::string::npos) end = glsl.size();
            const std::string line = glsl.substr(pos, end - pos);
            pos = end + 1;
            if (line.rfind("varying ", 0) == 0) continue; // the inputs are main's parameters
            if (line == "void main() {") {
                out += "float4 main(float4 vColor : TEXCOORD1, float4 vUV : TEXCOORD0) : COLOR {\n"
                       "  float4 gl_FragColor = float4(0.0, 0.0, 0.0, 1.0);\n";
                continue;
            }
            out += line;
            out += '\n';
        }
        // The last closing brace ends main: it returns the colour.
        const size_t last = out.rfind('}');
        if (last != std::string::npos) out.insert(last, "  return gl_FragColor;\n");
        return out;
    }

    struct DisplayData {
        void* address;
    };

    void display_callback(const void* data) {
        const DisplayData* d = (const DisplayData*)data;
        SceDisplayFrameBuf fb{};
        fb.size = sizeof(fb);
        fb.base = d->address;
        fb.pitch = screen_width;
        fb.pixelformat = SCE_DISPLAY_PIXELFORMAT_A8B8G8R8;
        fb.width = screen_width;
        fb.height = screen_height;
        sceDisplaySetFrameBuf(&fb, SCE_DISPLAY_SETBUF_NEXTFRAME);
    }

    void* patcher_host_alloc(void*, SceSize size) { return std::malloc(size); }
    void patcher_host_free(void*, void* mem) { std::free(mem); }
}

class GxmBackend {
public:
    // The hand-over uses the kernel's semaphores (a condition variable lost wake-ups).
    GxmBackend() {
        work_sema = sceKernelCreateSema("gxm_work", 0, 0, 64, nullptr);
        slot_sema = sceKernelCreateSema("gxm_slot", 0, 1, 1, nullptr);
        thread = std::thread([this] { run(); });
        while (!ready.load()) {
            sceKernelDelayThread(1000);
        }
    }

    ~GxmBackend() {
        quit = true;
        sceKernelSignalSema(work_sema, 1);
        if (thread.joinable()) thread.join();
        sceKernelDeleteSema(work_sema);
        sceKernelDeleteSema(slot_sema);
    }

    // ---------------------------------------------------- the front's side
    void submit(std::unique_ptr<CommandList> list) {
        ultramodern_trace("submit", (uint32_t)list->cmds.size());
        const uint64_t start = sceKernelGetProcessTimeWide();
        const uint32_t stage = g_front_stage.exchange(3);
        sceKernelWaitSema(slot_sema, 1, nullptr);
        g_front_stage = stage;
        {
            std::lock_guard lock{mutex};
            pending.push_back(std::move(list));
        }
        submitted++;
        sceKernelSignalSema(work_sema, 1);
        wait_us += (uint32_t)(sceKernelGetProcessTimeWide() - start);
        ultramodern_trace("submit end", 0);
    }
    std::atomic<uint32_t> wait_us{0}, busy_us{0};

    std::unique_ptr<CommandList> take_list() {
        std::lock_guard lock{mutex};
        if (!free_lists.empty()) {
            std::unique_ptr<CommandList> l = std::move(free_lists.back());
            free_lists.pop_back();
            return l;
        }
        auto l = std::make_unique<CommandList>();
        l->verts.resize(16384);
        l->vin.resize(16384);
        l->idx.resize(32768);
        l->ctxs.reserve(1024);
        l->uvmaps.reserve(512);
        l->cmds.reserve(2048);
        l->draws.reserve(1024);
        return l;
    }

    void wait_idle() {
        while (done.load() != submitted.load()) {
            sceKernelDelayThread(200);
        }
    }
    std::atomic<uint32_t> running_cmd{0}, running_cmds{0};

    // ---------------------------------------------------- the back's side
    enum Op { OP_DRAW, OP_VERTS, OP_SWITCH, OP_COPY, OP_READ, OP_UPLOAD, OP_CLEAR, OP_PRESENT, OP_PROGRAM, OP_SCISSOR, OP_WAIT, OP_COUNT };
    uint32_t op_n[OP_COUNT] = {};
    uint64_t op_us[OP_COUNT] = {};
    struct OpTimer {
        GxmBackend& b; Op op; uint64_t t0;
        OpTimer(GxmBackend& b, Op op) : b(b), op(op), t0(sceKernelGetProcessTimeWide()) { g_back_op = op; }
        ~OpTimer() { b.op_n[op]++; b.op_us[op] += sceKernelGetProcessTimeWide() - t0; g_back_op = 99; }
    };
    uint32_t lists_run = 0;
    uint32_t fragment_patches = 0;
    void log_ops() {
        static const char* const names[OP_COUNT] = { "draw", "verts", "fb switch", "copy", "read", "upload", "clear", "present", "program", "scissor", "gpu wait" };
        char line[512];
        int n = std::snprintf(line, sizeof(line), "[renderer] GXM ops (30 lists):");
        for (int i = 0; i < OP_COUNT; i++) {
            if (op_n[i] == 0) continue;
            n += std::snprintf(line + n, sizeof(line) - n, " %s %u/%llums", names[i], op_n[i], (unsigned long long)(op_us[i] / 1000));
            if (n >= (int)sizeof(line)) break;
        }
        std::fprintf(stderr, "%s, %u fragment programs patched\n", line, fragment_patches);
        fragment_patches = 0;
        std::memset(op_n, 0, sizeof(op_n));
        std::memset(op_us, 0, sizeof(op_us));
    }

    void debug_finish() { drain(); }

    // Debug (flag 8192): the GPU's own picture of the frame shown, read back once it finished,
    // saved as a thumbnail (a quarter of each side; rows as in memory) in ux0:data/conker/probe.
    uint32_t probes_saved = 0;
    void probe_water(uint32_t tex_id, uint32_t present_number, uint32_t capture) {
        if (tex_id >= textures.size() || !textures[tex_id].valid) return;
        drain();
        const Texture& t = textures[tex_id];
        const uint32_t w = sceGxmTextureGetWidth(&t.tex), h = sceGxmTextureGetHeight(&t.tex);
        const uint32_t stride = gxm::align_up(w, 8);
        const uint32_t* px = (const uint32_t*)t.mem;
        const uint32_t tw = w / 4, th = h / 4;
        static std::vector<uint8_t> rgb;
        rgb.resize((size_t)tw * th * 3);
        for (uint32_t y = 0; y < th; y++) {
            for (uint32_t x = 0; x < tw; x++) {
                const uint32_t c = px[(y * 4) * stride + x * 4];
                uint8_t* o = &rgb[((size_t)y * tw + x) * 3];
                o[0] = c & 0xFF; o[1] = (c >> 8) & 0xFF; o[2] = (c >> 16) & 0xFF;
            }
        }
        char path[96];
        if (capture != 0) {
            // A capture from the Debug page: its own folder.
            std::snprintf(path, sizeof(path), CONKER_VITA_DATA_DIR "/probe/c%02u", capture);
            std::error_code ec;
            std::filesystem::create_directories(path, ec);
            std::snprintf(path, sizeof(path), CONKER_VITA_DATA_DIR "/probe/c%02u/p%05u.ppm", capture, present_number);
        }
        else {
            if (probes_saved == 0) { std::error_code ec; std::filesystem::create_directories(CONKER_VITA_DATA_DIR "/probe", ec); }
            // A ring of the last 600 frames (the ones before quitting are kept).
            std::snprintf(path, sizeof(path), CONKER_VITA_DATA_DIR "/probe/r%03u.ppm", present_number % 600);
        }
        if (FILE* f = std::fopen(path, "wb")) {
            std::fprintf(f, "P6\n# present %u\n%u %u\n255\n", present_number, tw, th);
            std::fwrite(rgb.data(), 1, rgb.size(), f);
            std::fclose(f);
            probes_saved++;
        }
        std::fprintf(stderr, "[probe] present %u tex %u saved\n", present_number, tex_id);
    }

    void log_health() {
        uint32_t live = 0;
        for (const Texture& t : textures) live += t.valid ? 1 : 0;
        std::fprintf(stderr, "[gxm] frames %u submitted, %u shown; %u textures waiting to be freed; %u textures, %u framebuffers; video memory %u KB in use, %u failed allocations\n",
            frames_submitted, frames_shown.load(), (unsigned)deferred.size(), live, (unsigned)std::count_if(fbos.begin(), fbos.end(), [](const Fbo& f) { return f.valid; }),
            heap_used >> 10, alloc_failures);
    }

    void create_texture(uint32_t id) {
        if (id >= textures.size()) textures.resize(id + 256);
    }

    void delete_texture(uint32_t id) {
        if (id >= textures.size() || !textures[id].valid) return;
        free_later(textures[id].mem);
        textures[id] = Texture{};
        invalidate_textures();
    }

    // A texture of decoded texels (RGBA8888).
    void upload_texture(uint32_t id, uint32_t w, uint32_t h, const uint32_t* texels, bool linear, GLenum wrap_s, GLenum wrap_t) {
        OpTimer timer(*this, OP_UPLOAD);
        create_texture(id);
        Texture& t = textures[id];
        if (t.valid) free_later(t.mem);
        t = Texture{};
        const uint32_t stride = gxm::align_up(w, 8);
        uint8_t* mem = (uint8_t*)alloc_gpu(stride * h * 4, 256);
        if (mem == nullptr) return;
        if (stride == w) {
            std::memcpy(mem, texels, (size_t)w * h * 4);
        }
        else {
            for (uint32_t y = 0; y < h; y++) std::memcpy(mem + (size_t)y * stride * 4, texels + (size_t)y * w, (size_t)w * 4);
        }
        sceGxmTextureInitLinear(&t.tex, mem, SCE_GXM_TEXTURE_FORMAT_U8U8U8U8_ABGR, w, h, 0);
        const SceGxmTextureFilter filter = linear ? SCE_GXM_TEXTURE_FILTER_LINEAR : SCE_GXM_TEXTURE_FILTER_POINT;
        sceGxmTextureSetMinFilter(&t.tex, filter);
        sceGxmTextureSetMagFilter(&t.tex, filter);
        gxm::set_addr_modes(&t.tex, gxm::addr_mode(wrap_s), gxm::addr_mode(wrap_t));
        t.mem = mem;
        t.valid = true;
        invalidate_textures();
    }

    // A colour image's texture and framebuffer (its depth/stencil shared by size), cleared.
    void create_framebuffer(uint32_t fbo_id, uint32_t tex_id, uint32_t w, uint32_t h, bool with_depth) {
        const uint32_t pw = w * render_scale, ph = h * render_scale;
        const uint32_t stride = gxm::align_up(pw, 8);
        create_texture(tex_id);
        Texture& t = textures[tex_id];
        if (t.valid) free_later(t.mem);
        t = Texture{};
        uint8_t* mem = (uint8_t*)alloc_gpu(stride * ph * 4, 256);
        if (mem == nullptr) return;
        std::fill((uint32_t*)mem, (uint32_t*)mem + (size_t)stride * ph, 0xFF000000u); // GL's clear: black, alpha 1
        sceGxmTextureInitLinear(&t.tex, mem, SCE_GXM_TEXTURE_FORMAT_U8U8U8U8_ABGR, pw, ph, 0);
        sceGxmTextureSetMinFilter(&t.tex, SCE_GXM_TEXTURE_FILTER_LINEAR);
        sceGxmTextureSetMagFilter(&t.tex, SCE_GXM_TEXTURE_FILTER_LINEAR);
        sceGxmTextureSetUAddrMode(&t.tex, SCE_GXM_TEXTURE_ADDR_CLAMP);
        sceGxmTextureSetVAddrMode(&t.tex, SCE_GXM_TEXTURE_ADDR_CLAMP);
        t.mem = mem;
        t.valid = true;
        invalidate_textures();

        if (fbo_id >= fbos.size()) fbos.resize(fbo_id + 64);
        if (cur_fbo == fbo_id) end_scene();
        Fbo& f = fbos[fbo_id];
        f = Fbo{};
        f.w = pw;
        f.h = ph;
        f.tex = tex_id;
        sceGxmColorSurfaceInit(&f.color, SCE_GXM_COLOR_FORMAT_A8B8G8R8, SCE_GXM_COLOR_SURFACE_LINEAR, SCE_GXM_COLOR_SURFACE_SCALE_NONE,
            SCE_GXM_OUTPUT_REGISTER_SIZE_32BIT, pw, ph, stride, mem);
        f.rt = render_target(pw, ph);
        f.depth = with_depth ? depth_surface(pw, ph) : -1;
        f.valid = f.rt != nullptr;
        // GL's version clears the new image's depth too.
        if (with_depth && f.valid) {
            bind_framebuffer(fbo_id, w, h);
            const int full[4] = { 0, 0, (int)pw, (int)ph };
            set_scissor(full);
            clear_depth();
        }
    }

    void delete_framebuffer(uint32_t fbo_id) {
        if (fbo_id >= fbos.size()) return;
        if (cur_fbo == fbo_id) end_scene();
        fbos[fbo_id] = Fbo{};
    }

    // Starts drawing into a framebuffer (0 is the screen, drawn only by present).
    void bind_framebuffer(uint32_t fbo_id, uint32_t w, uint32_t h) {
        (void)w; (void)h;
        if (in_scene && cur_fbo == fbo_id) return;
        if (fbo_id == 0 || fbo_id >= fbos.size() || !fbos[fbo_id].valid) return;
        OpTimer timer(*this, OP_SWITCH);
        end_scene();
        Fbo& f = fbos[fbo_id];
        const SceGxmDepthStencilSurface* ds = f.depth >= 0 ? &depths[f.depth].surface : nullptr;
        sceGxmBeginScene(ctx, 0, f.rt, nullptr, nullptr, nullptr, &f.color, ds);
        in_scene = true;
        cur_fbo = fbo_id;
        scene_w = f.w;
        scene_h = f.h;
        scene_depth = f.depth;
        begin_scene_state();
        // GL's framebuffers: y = -1 is row 0.
        sceGxmSetViewport(ctx, f.w * 0.5f, f.w * 0.5f, f.h * 0.5f, f.h * 0.5f, 0.5f, 0.5f);
    }

    // GL's scissor (x, y from the bottom left, w, h), in the target's pixels.
    void set_scissor(const int sc[4]) {
        std::memcpy(scissor, sc, sizeof(scissor));
    }

    void clear_color(const float c[4]) {
        if (!in_scene) return;
        OpTimer timer(*this, OP_CLEAR);
        apply_scissor();
        set_depth(SCE_GXM_DEPTH_FUNC_ALWAYS, false, false);
        set_fragment(fill_prog, fill_prog.variant(*this, false, GL_ONE, GL_ZERO, true));
        set_uniforms_fill(c);
        draw_quad(-1, -1, 1, 1, 0.0f);
    }

    void clear_depth() {
        if (!in_scene || scene_depth < 0) return;
        OpTimer timer(*this, OP_CLEAR);
        apply_scissor();
        set_depth(SCE_GXM_DEPTH_FUNC_ALWAYS, true, false);
        set_fragment(fill_prog, fill_prog.variant(*this, false, GL_ONE, GL_ZERO, false));
        static const float zero[4] = { 0, 0, 0, 0 };
        set_uniforms_fill(zero);
        // Depth 1 whatever the quad's: no far plane to clip it.
        sceGxmSetViewport(ctx, scene_w * 0.5f, scene_w * 0.5f, scene_h * 0.5f, scene_h * 0.5f, 1.0f, 0.0f);
        draw_quad(-1, -1, 1, 1, 0.0f);
        sceGxmSetViewport(ctx, scene_w * 0.5f, scene_w * 0.5f, scene_h * 0.5f, scene_h * 0.5f, 0.5f, 0.5f);
    }

    // Copies a texture into another framebuffer's (the snapshot of an image drawn into).
    void copy_texture(uint32_t src_tex, uint32_t dst_fbo, uint32_t dst_tex, uint32_t w, uint32_t h) {
        OpTimer timer(*this, OP_COPY);
        if (dst_fbo >= fbos.size() || !fbos[dst_fbo].valid) {
            create_framebuffer(dst_fbo, dst_tex, w, h, false);
        }
        bind_framebuffer(dst_fbo, w, h);
        if (!in_scene || cur_fbo != dst_fbo) return;
        set_stencil(false);
        set_depth(SCE_GXM_DEPTH_FUNC_ALWAYS, false, false);
        set_fragment(copy_prog, copy_prog.variant(*this, false, GL_ONE, GL_ZERO, true));
        set_texture(copy_prog.unit0, src_tex);
        draw_quad(-1, -1, 1, 1, 0.0f);
    }

    // Reads a framebuffer back (RGBA8888, rows going up as GL's).
    void read_framebuffer(uint32_t fbo_id, uint32_t w, uint32_t h, std::vector<uint32_t>& out) {
        OpTimer timer(*this, OP_READ);
        out.assign((size_t)w * render_scale * h * render_scale, 0);
        if (fbo_id >= fbos.size() || !fbos[fbo_id].valid) return;
        end_scene();
        sceGxmFinish(ctx);
        const Fbo& f = fbos[fbo_id];
        const uint8_t* mem = (const uint8_t*)textures[f.tex].mem;
        const uint32_t stride = gxm::align_up(f.w, 8);
        for (uint32_t y = 0; y < f.h; y++) {
            std::memcpy(&out[(size_t)y * f.w], mem + (size_t)y * stride * 4, (size_t)f.w * 4);
        }
    }

    // A combiner's program, from its (GLSL) fragment shader.
    void create_program(uint32_t id, const std::string& fs) {
        OpTimer timer(*this, OP_PROGRAM);
        if (id >= programs.size()) programs.resize(id + 64);
        programs[id] = Program{};
        load_program(programs[id], gxm::combiner_cg(fs));
    }

    void draw(CommandList& list, const DrawCmd& d) {
        OpTimer timer(*this, OP_DRAW);
        if (d.raw) {
            OpTimer verts_timer(*this, OP_VERTS);
            finish_vertices(list, d);
        }
        if (d.debug) log_finished(list, d);
        bind_framebuffer(d.fbo, d.fb_w, d.fb_h);
        if (!in_scene || cur_fbo != d.fbo || d.program >= programs.size()) { dropped[0]++; return; }
        Program& p = programs[d.program];
        if (!p.valid || d.icount == 0) { dropped[p.valid ? 3 : 1]++; return; }
        // The data first: making room may wait for the GPU and start the scene again.
        GLVertex* v = (GLVertex*)ring_alloc(d.vcount * sizeof(GLVertex), 16);
        uint16_t* ix = (uint16_t*)ring_alloc(d.icount * 2, 16);
        if (v == nullptr || ix == nullptr || !in_scene) { dropped[2]++; return; }
        std::memcpy(v, &list.verts[d.vbase], d.vcount * sizeof(GLVertex));
        std::memcpy(ix, &list.idx[d.ibase], d.icount * 2);

        set_scissor(d.scissor);
        apply_scissor();
        // Depth is written with GL's test on only: an always-passing test writes it.
        set_depth(d.depth_test ? gxm::depth_func(d.depth_func) : SCE_GXM_DEPTH_FUNC_ALWAYS, d.depth_write, d.decal ? (d.strong_decal ? 2 : 1) : 0);
        set_fragment(p, p.variant(*this, d.blend, d.blend_src, d.blend_dst, d.color_write));
        set_uniforms(p, d);
        set_texture(p.unit0, d.tex[0]);
        set_texture(p.unit1, d.tex[1]);
        sceGxmSetVertexStream(ctx, 0, v);
        sceGxmDraw(ctx, SCE_GXM_PRIMITIVE_TRIANGLES, SCE_GXM_INDEX_FORMAT_U16, ix, d.icount);
    }

    // The frame to the screen: a texture (0: none) at its aspect in the middle, the menu over it.
    void present(uint32_t source_tex, const float uv[4], const std::vector<uint32_t>* cpu_frame, uint32_t cpu_w, uint32_t cpu_h,
                 float aspect, const std::vector<GLVertex>& menu) {
        OpTimer timer(*this, OP_PRESENT);
        if (cpu_frame != nullptr) {
            upload_texture(TEX_CPU_FRAME, cpu_w, cpu_h, cpu_frame->data(), true, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
        }
        end_scene();
        const uint32_t back = (shown_buffer + 1) % display_buffers;
        sceGxmBeginScene(ctx, 0, display_rt, nullptr, nullptr, display_sync[back], &display_surface[back], &display_depth);
        in_scene = true;
        cur_fbo = 0;
        scene_w = screen_width;
        scene_h = screen_height;
        scene_depth = -1;
        begin_scene_state();
        // The screen's row 0 is its top.
        sceGxmSetViewport(ctx, screen_width * 0.5f, screen_width * 0.5f, screen_height * 0.5f, -screen_height * 0.5f, 0.5f, 0.5f);
        set_stencil(false);
        set_depth(SCE_GXM_DEPTH_FUNC_ALWAYS, false, false);

        static const float black[4] = { 0, 0, 0, 1 };
        set_fragment(fill_prog, fill_prog.variant(*this, false, GL_ONE, GL_ZERO, true));
        set_uniforms_fill(black);
        draw_quad(-1, -1, 1, 1, 0.0f);

        if (source_tex != 0) {
            const float target_w = std::min((float)screen_width, (float)screen_height * aspect);
            const float x0 = -target_w / screen_width, x1 = target_w / screen_width;
            const float u0 = uv[0], v0 = uv[1], u1 = uv[2], v1 = uv[3];
            const GLVertex quad[4] = {
                { x0, 1.0f, 0, 1, {255, 255, 255, 255}, u0, v1, 0, 0 },
                { x1, 1.0f, 0, 1, {255, 255, 255, 255}, u1, v1, 0, 0 },
                { x0, -1.0f, 0, 1, {255, 255, 255, 255}, u0, v0, 0, 0 },
                { x1, -1.0f, 0, 1, {255, 255, 255, 255}, u1, v0, 0, 0 },
            };
            set_fragment(present_prog, present_prog.variant(*this, false, GL_ONE, GL_ZERO, true));
            set_texture(present_prog.unit0, source_tex);
            draw_strip(quad, 4);
        }
        if (!menu.empty()) {
            set_fragment(ui_prog, ui_prog.variant(*this, true, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, true));
            set_texture(ui_prog.unit0, TEX_FONT);
            GLVertex* v = (GLVertex*)ring_alloc(menu.size() * sizeof(GLVertex), 16);
            if (v != nullptr && menu.size() <= 65535) {
                std::memcpy(v, menu.data(), menu.size() * sizeof(GLVertex));
                sceGxmSetVertexStream(ctx, 0, v);
                sceGxmDraw(ctx, SCE_GXM_PRIMITIVE_TRIANGLES, SCE_GXM_INDEX_FORMAT_U16, sequence, (unsigned)menu.size());
            }
        }
        sceGxmEndScene(ctx, nullptr, nullptr);
        in_scene = false;
        cur_fbo = ~0u;
        sceGxmPadHeartbeat(&display_surface[back], display_sync[back]);
        gxm::DisplayData data{ display_mem[back].base };
        sceGxmDisplayQueueAddEntry(display_sync[shown_buffer], display_sync[back], &data);
        shown_buffer = back;
        if (++presents_logged % 60 == 0 && (dropped[0] | dropped[1] | dropped[2] | drains)) {
            std::fprintf(stderr, "[gxm] dropped draws: %u no scene, %u no program, %u no memory, %u empty; %u drains\n",
                dropped[0], dropped[1], dropped[2], dropped[3], drains);
            dropped[0] = dropped[1] = dropped[2] = dropped[3] = drains = 0;
        }
        next_frame();
    }

private:
    struct Texture {
        SceGxmTexture tex{};
        void* mem = nullptr;
        bool valid = false;
    };
    struct Fbo {
        bool valid = false;
        uint32_t w = 0, h = 0; // in pixels
        uint32_t tex = 0;
        SceGxmColorSurface color{};
        SceGxmRenderTarget* rt = nullptr;
        int depth = -1;
    };
    struct DepthSurface {
        uint32_t w = 0, h = 0;
        SceGxmDepthStencilSurface surface{};
        int marked[4] = { -1, -1, -1, -1 }; // the scissor its stencil holds
    };
    struct RenderTarget {
        uint32_t w = 0, h = 0;
        SceGxmRenderTarget* rt = nullptr;
    };
    struct Program {
        bool valid = false;
        SceGxmProgram* gxp = nullptr;
        SceGxmShaderPatcherId id = nullptr;
        bool has_uniforms = false;
        const SceGxmProgramParameter* u_prim = nullptr, *u_env = nullptr, *u_fog = nullptr, *u_blend = nullptr;
        const SceGxmProgramParameter* u_fill = nullptr, *u_primlod = nullptr, *u_convert = nullptr, *u_texi = nullptr;
        int unit0 = -1, unit1 = -1;
        std::unordered_map<uint32_t, SceGxmFragmentProgram*> variants;

        // The fragment program for a blend state (patched the first time).
        SceGxmFragmentProgram* variant(GxmBackend& b, bool blend, GLenum src, GLenum dst, bool color_write) {
            const uint32_t key = (blend ? 1u : 0u) | ((uint32_t)gxm::blend_factor(src) << 1) | ((uint32_t)gxm::blend_factor(dst) << 5) | (color_write ? 0x200u : 0u);
            auto it = variants.find(key);
            if (it != variants.end()) return it->second;
            SceGxmBlendInfo info{};
            info.colorMask = color_write ? SCE_GXM_COLOR_MASK_ALL : SCE_GXM_COLOR_MASK_NONE;
            info.colorFunc = blend ? SCE_GXM_BLEND_FUNC_ADD : SCE_GXM_BLEND_FUNC_NONE;
            info.alphaFunc = blend ? SCE_GXM_BLEND_FUNC_ADD : SCE_GXM_BLEND_FUNC_NONE;
            info.colorSrc = blend ? gxm::blend_factor(src) : SCE_GXM_BLEND_FACTOR_ONE;
            info.colorDst = blend ? gxm::blend_factor(dst) : SCE_GXM_BLEND_FACTOR_ZERO;
            info.alphaSrc = info.colorSrc;
            info.alphaDst = info.colorDst;
            const bool plain = !blend && color_write;
            SceGxmFragmentProgram* fp = nullptr;
            const int r = sceGxmShaderPatcherCreateFragmentProgram(b.patcher, id, SCE_GXM_OUTPUT_REGISTER_FORMAT_UCHAR4,
                SCE_GXM_MULTISAMPLE_NONE, plain ? nullptr : &info, b.vertex_gxp, &fp);
            if (r < 0) std::fprintf(stderr, "[gxm] fragment program patch failed: 0x%08X\n", (unsigned)r);
            b.fragment_patches++;
            variants.emplace(key, fp);
            return fp;
        }
    };

    std::thread thread;
    std::mutex mutex;
    SceUID work_sema = -1, slot_sema = -1;
    std::atomic<bool> ready{false}, quit{false};
    std::deque<std::unique_ptr<CommandList>> pending;
    std::vector<std::unique_ptr<CommandList>> free_lists;
    std::atomic<uint64_t> submitted{0}, done{0};

    // sceGxm
    SceGxmContext* ctx = nullptr;
    SceGxmShaderPatcher* patcher = nullptr;
    gxm::Heap heap; // textures, framebuffers, depth surfaces (CDRAM)
    SceGxmProgram* vertex_gxp = nullptr;
    SceGxmShaderPatcherId vertex_id = nullptr;
    SceGxmVertexProgram* vertex_program = nullptr;
    Program present_prog, copy_prog, ui_prog, fill_prog;
    uint16_t* sequence = nullptr; // 0, 1, 2... (quads and lists of triangles)

    static constexpr uint32_t display_buffers = 3;
    gxm::Block display_mem[display_buffers];
    SceGxmColorSurface display_surface[display_buffers]{};
    SceGxmSyncObject* display_sync[display_buffers]{};
    SceGxmDepthStencilSurface display_depth{};
    SceGxmRenderTarget* display_rt = nullptr;
    uint32_t shown_buffer = 0;
    // Debug: draws skipped (no scene, no program, no memory, no indices), GPU drains.
    uint32_t dropped[4] = {}, drains = 0, presents_logged = 0;

    // The frames' vertices and indices: a third of a ring each, reused once that frame is shown.
    static constexpr uint32_t ring_parts = 3;
    static constexpr uint32_t ring_part_size = 4 * 1024 * 1024;
    gxm::Block ring;
    uint32_t ring_used = 0;
    uint32_t frames_submitted = 0; // the frame being built is this one
    static std::atomic<uint32_t> frames_shown;
    std::vector<std::pair<uint32_t, void*>> deferred; // memory to free once its frame is shown

    std::vector<Texture> textures;
    std::vector<Fbo> fbos;
    std::vector<DepthSurface> depths;
    std::vector<RenderTarget> render_targets;
    std::vector<Program> programs;

    // The scene being drawn.
    bool in_scene = false;
    uint32_t cur_fbo = ~0u;
    uint32_t scene_w = 0, scene_h = 0;
    int scene_depth = -1;
    int scissor[4] = { 0, 0, 0, 0 };

    // What the context has, to skip repeated calls (forgotten at each scene).
    struct {
        const SceGxmFragmentProgram* fragment = nullptr;
        const Program* program = nullptr;
        bool uniforms = false;
        float prim[4], env[4], fog[4], blend[4], fill[4], primlod, convert[2], texi[2];
        const SceGxmTexture* tex[4] = {};
        int depth_func = -1, depth_write = -1, bias = -1, stencil = -1;
    } st;

    static void display_callback_counted(const void* data) {
        gxm::display_callback(data);
        frames_shown++;
    }

    void begin_scene_state() {
        st.fragment = nullptr;
        st.program = nullptr;
        st.uniforms = false;
        for (auto& t : st.tex) t = nullptr;
        st.depth_func = st.depth_write = st.bias = st.stencil = -1;
        sceGxmSetVertexProgram(ctx, vertex_program);
        sceGxmSetRegionClip(ctx, SCE_GXM_REGION_CLIP_OUTSIDE, 0, 0, scene_w - 1, scene_h - 1);
        sceGxmSetFrontStencilRef(ctx, 1);
    }

    void end_scene() {
        if (!in_scene) return;
        sceGxmEndScene(ctx, nullptr, nullptr);
        in_scene = false;
        cur_fbo = ~0u;
    }

    void invalidate_textures() {
        for (auto& t : st.tex) t = nullptr;
    }

    // ------------------------------------------------ memory
    void free_later(void* mem) {
        if (mem != nullptr) deferred.emplace_back(frames_submitted, mem);
    }

    void free_shown() {
        const uint32_t shown = frames_shown.load();
        size_t keep = 0;
        for (size_t i = 0; i < deferred.size(); i++) {
            if ((int32_t)(shown - (deferred[i].first + 1)) >= 0) free_gpu(deferred[i].second);
            else deferred[keep++] = deferred[i];
        }
        deferred.resize(keep);
    }

    // Waits for the GPU to finish everything (the scene being drawn goes on afterwards).
    void drain() {
        OpTimer timer(*this, OP_WAIT);
        drains++;
        g_back_waiting = 2;
        struct WaitEnd { ~WaitEnd() { g_back_waiting = 0; } } wait_end;
        const uint32_t fbo = cur_fbo;
        const bool reopen = in_scene && fbo != 0;
        end_scene();
        sceGxmFinish(ctx);
        for (auto& d : deferred) free_gpu(d.second);
        deferred.clear();
        ring_used = 0;
        if (reopen) bind_framebuffer(fbo, 0, 0);
    }

    // Video memory in use (for the health log), and allocations that failed.
    uint32_t heap_used = 0, alloc_failures = 0;
    std::unordered_map<void*, uint32_t> sizes;

    void free_gpu(void* p) {
        auto it = sizes.find(p);
        if (it != sizes.end()) {
            heap_used -= it->second;
            sizes.erase(it);
        }
        heap.free(p);
    }

    void* alloc_gpu(uint32_t size, uint32_t align) {
        void* p = heap.alloc(size, align);
        if (p == nullptr) {
            free_shown();
            p = heap.alloc(size, align);
        }
        if (p == nullptr) {
            drain();
            p = heap.alloc(size, align);
        }
        if (p == nullptr) {
            std::fprintf(stderr, "[gxm] out of GPU memory (%u KB)\n", size / 1024);
            alloc_failures++;
        }
        else {
            heap_used += size;
            sizes[p] = size;
        }
        return p;
    }

    void* ring_alloc(uint32_t size, uint32_t align) {
        ring_used = gxm::align_up(ring_used, align);
        if (ring_used + size > ring_part_size) {
            // A frame bigger than its part: wait for the GPU, then start the part again.
            drain();
            if (size > ring_part_size) return nullptr;
        }
        uint8_t* p = ring.base + (frames_submitted % ring_parts) * ring_part_size + ring_used;
        ring_used += size;
        return p;
    }

    // After a frame went to the screen: the next part of the ring, once the frame that
    // last used it is shown.
    void next_frame() {
        frames_submitted++;
        ring_used = 0;
        {
            OpTimer timer(*this, OP_WAIT);
            g_back_waiting = 1;
            while ((int32_t)(frames_shown.load() - (frames_submitted - (ring_parts - 1))) < 0) {
                sceKernelDelayThread(100);
            }
            g_back_waiting = 0;
        }
        free_shown();
    }

    // ------------------------------------------------ surfaces
    SceGxmRenderTarget* render_target(uint32_t w, uint32_t h) {
        for (const RenderTarget& r : render_targets) {
            if (r.w == w && r.h == h) return r.rt;
        }
        SceGxmRenderTargetParams p{};
        p.flags = 0;
        p.width = (uint16_t)w;
        p.height = (uint16_t)h;
        p.scenesPerFrame = 8;
        p.multisampleMode = SCE_GXM_MULTISAMPLE_NONE;
        p.multisampleLocations = 0;
        p.driverMemBlock = -1;
        RenderTarget r;
        r.w = w;
        r.h = h;
        const int res = sceGxmCreateRenderTarget(&p, &r.rt);
        if (res < 0) {
            std::fprintf(stderr, "[gxm] render target %ux%u failed: 0x%08X\n", w, h, (unsigned)res);
            return nullptr;
        }
        render_targets.push_back(r);
        return r.rt;
    }

    // A depth/stencil surface by size, kept across scenes (as vitaGL's STORE_DEPTH_STENCIL).
    int depth_surface(uint32_t w, uint32_t h) {
        for (size_t i = 0; i < depths.size(); i++) {
            if (depths[i].w == w && depths[i].h == h) return (int)i;
        }
        const uint32_t dw = gxm::align_up(w, SCE_GXM_TILE_SIZEX), dh = gxm::align_up(h, SCE_GXM_TILE_SIZEY);
        void* depth = alloc_gpu(dw * dh * 4, 4096);
        void* stencil = alloc_gpu(dw * dh, 4096);
        if (depth == nullptr || stencil == nullptr) return -1;
        // The depth's mask-update bit set: nothing is masked out.
        std::memset(depth, 0x80, (size_t)dw * dh * 4);
        std::memset(stencil, 0, (size_t)dw * dh);
        DepthSurface d;
        d.w = w;
        d.h = h;
        sceGxmDepthStencilSurfaceInit(&d.surface, SCE_GXM_DEPTH_STENCIL_FORMAT_DF32M_S8, SCE_GXM_DEPTH_STENCIL_SURFACE_LINEAR, dw, depth, stencil);
        sceGxmDepthStencilSurfaceSetForceLoadMode(&d.surface, SCE_GXM_DEPTH_STENCIL_FORCE_LOAD_ENABLED);
        sceGxmDepthStencilSurfaceSetForceStoreMode(&d.surface, SCE_GXM_DEPTH_STENCIL_FORCE_STORE_ENABLED);
        depths.push_back(d);
        return (int)depths.size() - 1;
    }

    // ------------------------------------------------ state
    void set_fragment(const Program& p, SceGxmFragmentProgram* fp) {
        if (fp == nullptr) return;
        if (st.fragment != fp) {
            sceGxmSetFragmentProgram(ctx, fp);
            st.fragment = fp;
            st.uniforms = false;
        }
        if (st.program != &p) {
            st.program = &p;
            st.uniforms = false; // another program's layout
        }
    }

    void set_uniforms(const Program& p, const DrawCmd& d) {
        if (!p.has_uniforms) return;
        if (st.uniforms && std::memcmp(st.prim, d.prim, 16) == 0 && std::memcmp(st.env, d.env, 16) == 0 &&
            std::memcmp(st.fog, d.fog, 16) == 0 && std::memcmp(st.blend, d.blendc, 16) == 0 &&
            std::memcmp(st.fill, d.fill, 16) == 0 && st.primlod == d.primlod &&
            std::memcmp(st.convert, d.convert, 8) == 0 && std::memcmp(st.texi, d.tex_intensity, 8) == 0) {
            return;
        }
        void* buf = nullptr;
        sceGxmReserveFragmentDefaultUniformBuffer(ctx, &buf);
        if (p.u_prim) sceGxmSetUniformDataF(buf, p.u_prim, 0, 4, d.prim);
        if (p.u_env) sceGxmSetUniformDataF(buf, p.u_env, 0, 4, d.env);
        if (p.u_fog) sceGxmSetUniformDataF(buf, p.u_fog, 0, 4, d.fog);
        if (p.u_blend) sceGxmSetUniformDataF(buf, p.u_blend, 0, 4, d.blendc);
        if (p.u_fill) sceGxmSetUniformDataF(buf, p.u_fill, 0, 4, d.fill);
        if (p.u_primlod) sceGxmSetUniformDataF(buf, p.u_primlod, 0, 1, &d.primlod);
        if (p.u_convert) sceGxmSetUniformDataF(buf, p.u_convert, 0, 2, d.convert);
        if (p.u_texi) sceGxmSetUniformDataF(buf, p.u_texi, 0, 2, d.tex_intensity);
        std::memcpy(st.prim, d.prim, 16);
        std::memcpy(st.env, d.env, 16);
        std::memcpy(st.fog, d.fog, 16);
        std::memcpy(st.blend, d.blendc, 16);
        std::memcpy(st.fill, d.fill, 16);
        st.primlod = d.primlod;
        std::memcpy(st.convert, d.convert, 8);
        std::memcpy(st.texi, d.tex_intensity, 8);
        st.uniforms = true;
    }

    void set_uniforms_fill(const float c[4]) {
        void* buf = nullptr;
        sceGxmReserveFragmentDefaultUniformBuffer(ctx, &buf);
        if (fill_prog.u_fill) sceGxmSetUniformDataF(buf, fill_prog.u_fill, 0, 4, c);
        st.uniforms = false;
    }

    void set_texture(int unit, uint32_t id) {
        if (unit < 0 || unit >= 4) return;
        if (id >= textures.size() || !textures[id].valid) id = TEX_WHITE;
        const SceGxmTexture* t = &textures[id].tex;
        if (st.tex[unit] != t) {
            sceGxmSetFragmentTexture(ctx, (unsigned)unit, t);
            st.tex[unit] = t;
        }
    }

    void set_depth(SceGxmDepthFunc func, bool write, int bias) {
        if (st.depth_func != (int)func) {
            sceGxmSetFrontDepthFunc(ctx, func);
            st.depth_func = (int)func;
        }
        if (st.depth_write != (int)write) {
            sceGxmSetFrontDepthWriteEnable(ctx, write ? SCE_GXM_DEPTH_WRITE_ENABLED : SCE_GXM_DEPTH_WRITE_DISABLED);
            st.depth_write = write;
        }
        if (st.bias != (int)bias) {
            // As glPolygonOffset(-1, -2): decals in front of what they lie on (2: a debug
            // switch's larger bias).
            sceGxmSetFrontDepthBias(ctx, bias == 2 ? -8 : bias ? -1 : 0, bias == 2 ? -64 : bias ? -2 : 0);
            st.bias = bias;
        }
    }

    // Draws only where the stencil holds 1 (the scissor), or everywhere.
    void set_stencil(bool masked) {
        if (st.stencil == (int)masked) return;
        sceGxmSetFrontStencilFunc(ctx, masked ? SCE_GXM_STENCIL_FUNC_EQUAL : SCE_GXM_STENCIL_FUNC_ALWAYS,
            SCE_GXM_STENCIL_OP_KEEP, SCE_GXM_STENCIL_OP_KEEP, SCE_GXM_STENCIL_OP_KEEP, 0xFF, 0x00);
        st.stencil = masked;
    }

    // The scissor: none when it covers the target; otherwise the stencil marks it (redrawn
    // when it changed, the surface keeping it across scenes).
    void apply_scissor() {
        const int x0 = std::max(scissor[0], 0), y0 = std::max(scissor[1], 0);
        const int x1 = std::min(scissor[0] + scissor[2], (int)scene_w), y1 = std::min(scissor[1] + scissor[3], (int)scene_h);
        const bool full = x0 <= 0 && y0 <= 0 && x1 >= (int)scene_w && y1 >= (int)scene_h;
        if (full || scene_depth < 0) {
            set_stencil(false);
            return;
        }
        DepthSurface& ds = depths[scene_depth];
        const int rect[4] = { x0, y0, x1, y1 };
        if (std::memcmp(ds.marked, rect, sizeof(rect)) != 0) {
            op_n[OP_SCISSOR]++;
            const SceGxmFragmentProgram* fp_before = st.fragment;
            (void)fp_before;
            set_depth(SCE_GXM_DEPTH_FUNC_ALWAYS, false, false);
            set_fragment(fill_prog, fill_prog.variant(*this, false, GL_ONE, GL_ZERO, false));
            static const float zero[4] = { 0, 0, 0, 0 };
            set_uniforms_fill(zero);
            // Everything to 0, then the rectangle to 1.
            sceGxmSetFrontStencilFunc(ctx, SCE_GXM_STENCIL_FUNC_ALWAYS, SCE_GXM_STENCIL_OP_REPLACE, SCE_GXM_STENCIL_OP_REPLACE,
                SCE_GXM_STENCIL_OP_REPLACE, 0xFF, 0xFF);
            sceGxmSetFrontStencilRef(ctx, 0);
            draw_quad(-1, -1, 1, 1, 0.0f);
            sceGxmSetFrontStencilRef(ctx, 1);
            const float nx0 = 2.0f * x0 / scene_w - 1.0f, ny0 = 2.0f * y0 / scene_h - 1.0f;
            const float nx1 = 2.0f * x1 / scene_w - 1.0f, ny1 = 2.0f * y1 / scene_h - 1.0f;
            draw_quad(nx0, ny0, nx1, ny1, 0.0f);
            std::memcpy(ds.marked, rect, sizeof(rect));
            st.stencil = -1;
        }
        set_stencil(true);
    }

    // A rectangle in normalised coordinates at a depth (-1..1), with the state as set.
    void draw_quad(float x0, float y0, float x1, float y1, float z) {
        const GLVertex quad[4] = {
            { x0, y0, z, 1, {255, 255, 255, 255}, 0, 0, 0, 0 },
            { x1, y0, z, 1, {255, 255, 255, 255}, 1, 0, 0, 0 },
            { x0, y1, z, 1, {255, 255, 255, 255}, 0, 1, 0, 0 },
            { x1, y1, z, 1, {255, 255, 255, 255}, 1, 1, 0, 0 },
        };
        draw_strip(quad, 4);
    }

    void draw_strip(const GLVertex* verts, uint32_t count) {
        GLVertex* v = (GLVertex*)ring_alloc(count * sizeof(GLVertex), 16);
        if (v == nullptr) return;
        std::memcpy(v, verts, count * sizeof(GLVertex));
        sceGxmSetVertexStream(ctx, 0, v);
        sceGxmDraw(ctx, SCE_GXM_PRIMITIVE_TRIANGLE_STRIP, SCE_GXM_INDEX_FORMAT_U16, sequence, count);
    }

    // ------------------------------------------------ programs
    // Compiled (once: kept on the memory card by the source's hash) and registered.
    SceGxmProgram* compile(const std::string& source, bool fragment) {
        const uint64_t hash = XXH3_64bits(source.data(), source.size());
        char path[160];
        std::snprintf(path, sizeof(path), CONKER_VITA_DATA_DIR "/gxm_shader_cache/%016llx.gxp", (unsigned long long)hash);
        if (FILE* f = std::fopen(path, "rb")) {
            std::fseek(f, 0, SEEK_END);
            const long size = std::ftell(f);
            std::fseek(f, 0, SEEK_SET);
            SceGxmProgram* gxp = nullptr;
            if (size > 0 && size < (1 << 20)) {
                gxp = (SceGxmProgram*)std::malloc((size_t)size);
                if (std::fread(gxp, 1, (size_t)size, f) != (size_t)size || sceGxmProgramCheck(gxp) < 0) {
                    std::free(gxp);
                    gxp = nullptr;
                }
            }
            std::fclose(f);
            if (gxp) return gxp;
        }
        // In: the source's length; out: the program's.
        uint32_t size = (uint32_t)source.size();
        g_back_compiling = 1;
        struct CompileEnd { ~CompileEnd() { g_back_compiling = 0; } } compile_end;
        SceGxmProgram* out = shark_compile_shader_extended(source.c_str(), &size, fragment ? SHARK_FRAGMENT_SHADER : SHARK_VERTEX_SHADER,
            SHARK_OPT_FAST, SHARK_ENABLE, SHARK_DISABLE, SHARK_ENABLE);
        if (out == nullptr || size == 0) {
            std::fprintf(stderr, "[gxm] shader compile failed:\n%s\n", source.c_str());
            shark_clear_output();
            return nullptr;
        }
        SceGxmProgram* gxp = (SceGxmProgram*)std::malloc(size);
        std::memcpy(gxp, out, size);
        shark_clear_output();
        std::filesystem::create_directories(CONKER_VITA_DATA_DIR "/gxm_shader_cache");
        if (FILE* f = std::fopen(path, "wb")) {
            std::fwrite(gxp, 1, size, f);
            std::fclose(f);
        }
        std::fprintf(stderr, "[gxm] shader compiled (%s, %u bytes)\n", fragment ? "fragment" : "vertex", size);
        return gxp;
    }

    bool load_program(Program& p, const std::string& cg) {
        p.gxp = compile(cg, true);
        if (p.gxp == nullptr) return false;
        if (sceGxmShaderPatcherRegisterProgram(patcher, p.gxp, &p.id) < 0) return false;
        auto find = [&](const char* name) { return sceGxmProgramFindParameterByName(p.gxp, name); };
        p.u_prim = find("uPrim");
        p.u_env = find("uEnv");
        p.u_fog = find("uFog");
        p.u_blend = find("uBlend");
        p.u_fill = find("uFill");
        p.u_primlod = find("uPrimLod");
        p.u_convert = find("uConvert");
        p.u_texi = find("uTexI");
        if (const SceGxmProgramParameter* t = find("uTex0")) p.unit0 = (int)sceGxmProgramParameterGetResourceIndex(t);
        if (const SceGxmProgramParameter* t = find("uTex1")) p.unit1 = (int)sceGxmProgramParameterGetResourceIndex(t);
        p.has_uniforms = sceGxmProgramGetDefaultUniformBufferSize(p.gxp) > 0;
        p.valid = true;
        return true;
    }

    // ------------------------------------------------ the thread
    void run() {
        sceKernelChangeThreadCpuAffinityMask(sceKernelGetThreadId(), SCE_KERNEL_CPU_MASK_USER_0 | SCE_KERNEL_CPU_MASK_USER_2);
        init();
        ready = true;
        for (;;) {
            sceKernelWaitSema(work_sema, 1, nullptr);
            std::unique_ptr<CommandList> list;
            {
                std::lock_guard lock{mutex};
                if (pending.empty()) {
                    if (quit) return;
                    continue;
                }
                list = std::move(pending.front());
                pending.pop_front();
            }
            sceKernelSignalSema(slot_sema, 1);
            const uint64_t start = sceKernelGetProcessTimeWide();
            ultramodern_trace("gl list", (uint32_t)list->cmds.size());
            running_cmds = (uint32_t)list->cmds.size();
            for (uint32_t i = 0; i < list->cmds.size(); i++) {
                running_cmd = i;
                list->cmds[i](*this, *list);
            }
            busy_us += (uint32_t)(sceKernelGetProcessTimeWide() - start);
            if (++lists_run % 30 == 0) log_ops();
            ultramodern_trace("gl list end", 0);
            // The vertices went to the ring: the list can be filled again at once.
            list->reset();
            {
                std::lock_guard lock{mutex};
                free_lists.push_back(std::move(list));
            }
            done++;
            g_back_lists++;
        }
    }

    void init() {
        // The shader compiler first: libshacccg makes its heap from the free memory, which
        // the GPU's blocks below would leave too small (every compile then fails).
        // Its memory from a block of its own (as vitaGL gives it): from newlib's heap every
        // compile fails with an internal error.
        {
            static SceClibMspace shark_space = nullptr;
            const SceUID block = sceKernelAllocMemBlock("shark_heap", (SceKernelMemBlockType)SCE_KERNEL_MEMBLOCK_TYPE_USER_RW, 16 << 20, nullptr);
            void* base = nullptr;
            if (block >= 0 && sceKernelGetMemBlockBase(block, &base) >= 0) shark_space = sceClibMspaceCreate(base, 16 << 20);
            if (shark_space) {
                shark_set_allocators([](size_t size) { return sceClibMspaceMalloc(shark_space, size); },
                                     [](void* p) { sceClibMspaceFree(shark_space, p); });
            }
        }
        if (shark_init(nullptr) < 0 && shark_init("ur0:data/external/libshacccg.suprx") < 0) {
            std::fprintf(stderr, "[gxm] no runtime shader compiler (libshacccg.suprx)\n");
        }
        shark_install_log_cb([](const char* msg, shark_log_level level, int line) {
            std::fprintf(stderr, "[gxm] shader compiler (%d) line %d: %s\n", (int)level, line, msg);
        });
        shark_set_warnings_level(SHARK_WARN_LOW);
        SceKernelFreeMemorySizeInfo mem{};
        mem.size = sizeof(mem);
        sceKernelGetFreeMemorySize(&mem);
        std::fprintf(stderr, "[renderer] free memory: main %u KB, cdram %u KB, phycont %u KB\n",
            mem.size_user / 1024, mem.size_cdram / 1024, mem.size_phycont / 1024);

        SceGxmInitializeParams ip{};
        ip.flags = 0;
        ip.displayQueueMaxPendingCount = display_buffers - 1;
        ip.displayQueueCallback = &display_callback_counted;
        ip.displayQueueCallbackDataSize = sizeof(gxm::DisplayData);
        ip.parameterBufferSize = SCE_GXM_DEFAULT_PARAMETER_BUFFER_SIZE;
        int r = sceGxmInitialize(&ip);
        if (r < 0) std::fprintf(stderr, "[gxm] sceGxmInitialize: 0x%08X\n", (unsigned)r);

        // The context and its rings.
        const uint32_t lp = SCE_KERNEL_MEMBLOCK_TYPE_USER_RW_UNCACHE;
        gxm::Block vdm = gxm::alloc_mapped(lp, SCE_GXM_DEFAULT_VDM_RING_BUFFER_SIZE, "gxm_vdm");
        gxm::Block vring = gxm::alloc_mapped(lp, 2 * SCE_GXM_DEFAULT_VERTEX_RING_BUFFER_SIZE, "gxm_vertex_ring");
        gxm::Block fring = gxm::alloc_mapped(lp, 2 * SCE_GXM_DEFAULT_FRAGMENT_RING_BUFFER_SIZE, "gxm_fragment_ring");
        unsigned int fusse_offset = 0;
        gxm::Block fusse = gxm::alloc_usse(SCE_GXM_DEFAULT_FRAGMENT_USSE_RING_BUFFER_SIZE, true, &fusse_offset, "gxm_fragment_usse_ring");
        SceGxmContextParams cp{};
        cp.hostMem = std::malloc(SCE_GXM_MINIMUM_CONTEXT_HOST_MEM_SIZE);
        cp.hostMemSize = SCE_GXM_MINIMUM_CONTEXT_HOST_MEM_SIZE;
        cp.vdmRingBufferMem = vdm.base;
        cp.vdmRingBufferMemSize = vdm.size;
        cp.vertexRingBufferMem = vring.base;
        cp.vertexRingBufferMemSize = vring.size;
        cp.fragmentRingBufferMem = fring.base;
        cp.fragmentRingBufferMemSize = fring.size;
        cp.fragmentUsseRingBufferMem = fusse.base;
        cp.fragmentUsseRingBufferMemSize = fusse.size;
        cp.fragmentUsseRingBufferOffset = fusse_offset;
        r = sceGxmCreateContext(&cp, &ctx);
        if (r < 0) std::fprintf(stderr, "[gxm] sceGxmCreateContext: 0x%08X\n", (unsigned)r);

        // The shader patcher.
        gxm::Block pbuf = gxm::alloc_mapped(lp, 1024 * 1024, "gxm_patcher_buffer");
        unsigned int pv_offset = 0, pf_offset = 0;
        gxm::Block pvusse = gxm::alloc_usse(256 * 1024, false, &pv_offset, "gxm_patcher_vertex_usse");
        gxm::Block pfusse = gxm::alloc_usse(1024 * 1024, true, &pf_offset, "gxm_patcher_fragment_usse");
        SceGxmShaderPatcherParams pp{};
        pp.hostAllocCallback = &gxm::patcher_host_alloc;
        pp.hostFreeCallback = &gxm::patcher_host_free;
        pp.bufferMem = pbuf.base;
        pp.bufferMemSize = pbuf.size;
        pp.vertexUsseMem = pvusse.base;
        pp.vertexUsseMemSize = pvusse.size;
        pp.vertexUsseOffset = pv_offset;
        pp.fragmentUsseMem = pfusse.base;
        pp.fragmentUsseMemSize = pfusse.size;
        pp.fragmentUsseOffset = pf_offset;
        r = sceGxmShaderPatcherCreate(&pp, &patcher);
        if (r < 0) std::fprintf(stderr, "[gxm] sceGxmShaderPatcherCreate: 0x%08X\n", (unsigned)r);

        // Memory: textures and surfaces in CDRAM, the frames' vertices in LPDDR.
        // The screen's buffers first: the heap then takes what's left of CDRAM, less room
        // for what the driver allocates itself (render targets). On a Vita the heap took
        // the buffers' room and the screen stayed black (Vita3K has more to spare).
        const uint32_t display_bytes = gxm::align_up(screen_width * screen_height * 4, 256 * 1024);
        for (uint32_t i = 0; i < display_buffers; i++) {
            display_mem[i] = gxm::alloc_mapped(SCE_KERNEL_MEMBLOCK_TYPE_USER_CDRAM_RW, display_bytes, "gxm_display");
            if (display_mem[i].base == nullptr) {
                // No CDRAM left: the screen in main memory (slower, but it shows).
                display_mem[i] = gxm::alloc_mapped(lp, display_bytes, "gxm_display_ram");
            }
            std::memset(display_mem[i].base, 0, display_mem[i].size);
            sceGxmColorSurfaceInit(&display_surface[i], SCE_GXM_COLOR_FORMAT_A8B8G8R8, SCE_GXM_COLOR_SURFACE_LINEAR,
                SCE_GXM_COLOR_SURFACE_SCALE_NONE, SCE_GXM_OUTPUT_REGISTER_SIZE_32BIT, screen_width, screen_height, screen_width,
                display_mem[i].base);
            sceGxmSyncObjectCreate(&display_sync[i]);
        }
        SceKernelFreeMemorySizeInfo left{};
        left.size = sizeof(left);
        sceKernelGetFreeMemorySize(&left);
        const uint32_t margin = 16u << 20;
        uint32_t heap_bytes = left.size_cdram > margin + (16u << 20)
            ? std::min<uint32_t>(96u << 20, (left.size_cdram - margin) & ~((256u << 10) - 1)) : (16u << 20);
        // Smaller if CDRAM won't give that much in one block.
        while (!heap.init(SCE_KERNEL_MEMBLOCK_TYPE_USER_CDRAM_RW, heap_bytes, "gxm_heap")) {
            std::fprintf(stderr, "[gxm] no CDRAM heap of %u KB\n", heap_bytes >> 10);
            if (heap_bytes <= (24u << 20)) break;
            heap_bytes -= 8u << 20;
        }
        std::fprintf(stderr, "[gxm] CDRAM free after the screen %u KB: heap %u KB\n", left.size_cdram >> 10, heap_bytes >> 10);
        ring = gxm::alloc_mapped(lp, ring_parts * ring_part_size, "gxm_frame_ring");
        gxm::Block seq = gxm::alloc_mapped(lp, 65536 * 2, "gxm_sequence");
        sequence = (uint16_t*)seq.base;
        for (uint32_t i = 0; i < 65536; i++) sequence[i] = (uint16_t)i;

        {
            const uint32_t dw = gxm::align_up(screen_width, SCE_GXM_TILE_SIZEX), dh = gxm::align_up(screen_height, SCE_GXM_TILE_SIZEY);
            void* depth = alloc_gpu(dw * dh * 4, 4096);
            sceGxmDepthStencilSurfaceInit(&display_depth, SCE_GXM_DEPTH_STENCIL_FORMAT_DF32, SCE_GXM_DEPTH_STENCIL_SURFACE_LINEAR, dw, depth, nullptr);
        }
        display_rt = render_target(screen_width, screen_height);

        vertex_gxp = compile(gxm::vertex_cg, false);
        if (vertex_gxp) {
            sceGxmShaderPatcherRegisterProgram(patcher, vertex_gxp, &vertex_id);
            auto reg = [&](const char* name) {
                const SceGxmProgramParameter* p = sceGxmProgramFindParameterByName(vertex_gxp, name);
                return p ? (uint16_t)sceGxmProgramParameterGetResourceIndex(p) : (uint16_t)0;
            };
            SceGxmVertexAttribute attrs[3];
            attrs[0] = { 0, (uint16_t)offsetof(GLVertex, x), SCE_GXM_ATTRIBUTE_FORMAT_F32, 4, reg("aPos") };
            attrs[1] = { 0, (uint16_t)offsetof(GLVertex, color), SCE_GXM_ATTRIBUTE_FORMAT_U8N, 4, reg("aColor") };
            attrs[2] = { 0, (uint16_t)offsetof(GLVertex, u0), SCE_GXM_ATTRIBUTE_FORMAT_F32, 4, reg("aUV") };
            SceGxmVertexStream stream{ (uint16_t)sizeof(GLVertex), SCE_GXM_INDEX_SOURCE_INDEX_16BIT };
            r = sceGxmShaderPatcherCreateVertexProgram(patcher, vertex_id, attrs, 3, &stream, 1, &vertex_program);
            if (r < 0) std::fprintf(stderr, "[gxm] vertex program: 0x%08X\n", (unsigned)r);
        }
        load_program(present_prog, gxm::present_cg);
        load_program(copy_prog, gxm::copy_cg);
        load_program(ui_prog, gxm::ui_cg);
        load_program(fill_prog, gxm::fill_cg);

        // The menu's font (alpha only, white), white texels, the CPU's frame.
        {
            std::vector<uint32_t> rgba(font_atlas_width * font_atlas_height);
            for (size_t i = 0; i < rgba.size(); i++) rgba[i] = 0x00FFFFFFu | ((uint32_t)font_atlas[i] << 24);
            upload_texture(TEX_FONT, font_atlas_width, font_atlas_height, rgba.data(), true, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
        }
        const uint32_t white[4] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
        upload_texture(TEX_WHITE, 2, 2, white, false, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
        upload_texture(TEX_CPU_FRAME, 2, 2, white, true, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);

        // A first, black frame.
        const float uv[4] = { 0, 0, 1, 1 };
        present(0, uv, nullptr, 0, 0, 4.0f / 3.0f, {});
        std::fprintf(stderr, "[renderer] sceGxm ready (heap %u MB)\n", heap_bytes >> 20);
    }
};

std::atomic<uint32_t> GxmBackend::frames_shown{0};
