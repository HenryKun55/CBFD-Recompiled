cmake_minimum_required(VERSION 3.20)

# PS Vita build of Conker's Bad Fur Day: Recompiled.
#
# RecompiledFuncs/ must exist first (`python3 recomp/recompile.py`, see vita/build_vita.sh),
# and tools/N64ModernRuntime must have recomp/n64modernruntime.patch and
# vita/n64modernruntime-vita.patch applied.
#
#   cmake -S vita -B vita/build -G Ninja -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake
#   cmake --build vita/build
#
# Instead of RT64 (Vulkan/D3D12/Metal) it draws with vitaGL through a small HLE
# renderer for the game's microcode (F3DEX2, Conker's variant), and it has no
# launcher: it boots straight into the game with the ROM at ux0:data/conker/.

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if (DEFINED ENV{VITASDK})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
    else()
        message(FATAL_ERROR "Set VITASDK or pass -DCMAKE_TOOLCHAIN_FILE")
    endif()
endif()

project(ConkerVita C CXX)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Conker's Bad Fur Day")
set(VITA_TITLEID  "CBFD00064")
set(VITA_VERSION  "00.15")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 11)

set(REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(RUNTIME_DIR "${REPO_ROOT}/tools/N64ModernRuntime")
set(HOST_DIR "${REPO_ROOT}/host/src")

# Cortex-A9 with NEON. The recompiled code is mostly 64-bit integer register moves
# and loads/stores into RDRAM, which -O2 handles far better than -O0 or -Os.
set(VITA_ARCH_FLAGS -mcpu=cortex-a9 -mfpu=neon -mfloat-abi=hard -mthumb)
add_compile_options(${VITA_ARCH_FLAGS} -ffunction-sections -fdata-sections)
add_compile_definitions(NDEBUG)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# ---------------------------------------------------------------- the runtime
# POSIX headers newlib lacks (sys/mman.h), for the runtime and its libraries too.
include_directories(BEFORE "${CMAKE_CURRENT_SOURCE_DIR}/src/posix_shim")
add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:SHELL:-include ${CMAKE_CURRENT_SOURCE_DIR}/src/posix_shim/vita_compat.h>")
# fmt's OS layer (files, pipes) uses POSIX calls newlib hides; nothing here needs it.
set(FMT_OS OFF CACHE BOOL "" FORCE)
add_subdirectory("${RUNTIME_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/N64ModernRuntime")
foreach(target ultramodern librecomp)
    target_compile_options(${target} PRIVATE -Wno-psabi)
endforeach()

# ---------------------------------------------------------------- the recompiled game
set(RECOMP_STAMP "${REPO_ROOT}/RecompiledFuncs/inputs.sha256")
if (NOT EXISTS "${RECOMP_STAMP}")
    message(FATAL_ERROR "RecompiledFuncs/ is missing: run `python3 recomp/recompile.py` (vita/build_vita.sh does).")
endif()
file(GLOB RECOMPILED_FUNCS CONFIGURE_DEPENDS "${REPO_ROOT}/RecompiledFuncs/funcs_*.c")
add_library(RecompiledFuncs STATIC ${RECOMPILED_FUNCS} "${REPO_ROOT}/RecompiledFuncs/tlb_pages.c")
target_include_directories(RecompiledFuncs PRIVATE
    "${RUNTIME_DIR}/N64Recomp/include"
    "${REPO_ROOT}/RecompiledFuncs"
)
target_compile_options(RecompiledFuncs PRIVATE
    -include setjmp.h
    -Wno-implicit-function-declaration
    -Wno-unused-label
    -Wno-unused-variable
    -Wno-unused-but-set-variable
    -Wno-int-conversion
    -fno-strict-aliasing
    -w
)

# ---------------------------------------------------------------- the game
add_executable(ConkerVita
    src/main_vita.cpp
    src/vita_platform.cpp
    src/vita_renderer.cpp
    src/tmem.cpp
    src/bench.cpp
    src/controls.cpp
    src/menu.cpp
    "${HOST_DIR}/null_renderer.cpp"
    "${HOST_DIR}/overlays.cpp"
    "${HOST_DIR}/ultra_extras.cpp"
    "${HOST_DIR}/mod_api.cpp"
    "${HOST_DIR}/rom_versions.cpp"
    "${HOST_DIR}/widescreen.cpp"
    "${HOST_DIR}/cutscene_aspect.cpp"
    "${HOST_DIR}/field_of_view.cpp"
    "${HOST_DIR}/interpolation.cpp"
    "${HOST_DIR}/cutscene_skip.cpp"
    "${HOST_DIR}/render_fixes.cpp"
    "${HOST_DIR}/look_aim.cpp"
    src/vita_hooks.cpp
    "${REPO_ROOT}/RecompiledFuncs/rsp/audio_ucode.cpp"
)
# Debugging the audio microcode against a native run (vita/debug).
option(CONKER_RSP_TRACE "Build the traced audio microcode harness" OFF)
if (CONKER_RSP_TRACE)
    target_sources(ConkerVita PRIVATE debug/audio_ucode_traced.cpp debug/rsp_trace.cpp)
    target_compile_definitions(ConkerVita PRIVATE CONKER_RSP_TRACE)
    set_source_files_properties(debug/audio_ucode_traced.cpp PROPERTIES COMPILE_OPTIONS "-w;-fno-strict-aliasing")
endif()

target_include_directories(ConkerVita PRIVATE
    "${HOST_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/sdl_shim"
    "${RUNTIME_DIR}/thirdparty"
    "${RUNTIME_DIR}/N64Recomp/include"
    "${REPO_ROOT}/RecompiledFuncs"
)
# The RSP's vector registers are read through type-punned pointers (rsp_vu.hpp): without
# -fno-strict-aliasing GCC reorders those accesses and the audio comes out as noise.
set_source_files_properties("${REPO_ROOT}/RecompiledFuncs/rsp/audio_ucode.cpp" PROPERTIES COMPILE_OPTIONS "-w;-fno-strict-aliasing")
target_compile_options(ConkerVita PRIVATE -Wno-psabi -g)
# The renderer's per-vertex and per-texel loops: full optimisation, and float maths
# without IEEE corner cases (no NaNs or infinities reach them).
set_source_files_properties(src/vita_renderer.cpp src/tmem.cpp PROPERTIES COMPILE_OPTIONS "-O3;-ffast-math")

# The renderer draws with sceGxm directly (src/gxm_backend.inc); OFF goes through vitaGL.
option(CONKER_GXM "Draw with sceGxm directly instead of vitaGL" ON)
if(CONKER_GXM)
    target_compile_definitions(ConkerVita PRIVATE CONKER_GXM=1)
else()
    target_compile_definitions(ConkerVita PRIVATE CONKER_GXM=0)
endif()

# vitaGL has to be built with STORE_DEPTH_STENCIL=1: the game draws its shadow textures in
# the middle of a frame, and otherwise every switch of render target resets the frame's
# depth buffer (what's drawn after shows through walls). VITAGL_LIBRARY points at it.
set(VITAGL_LIBRARY "${REPO_ROOT}/../vitaGL/libvitaGL.a" CACHE FILEPATH "vitaGL built with STORE_DEPTH_STENCIL=1")
if(NOT EXISTS "${VITAGL_LIBRARY}")
    message(WARNING "${VITAGL_LIBRARY} not found: using the SDK's vitaGL (depth breaks around shadows)")
    set(VITAGL_LIBRARY vitaGL)
else()
    # Its own header (the SDK's is another version's).
    get_filename_component(VITAGL_DIR "${VITAGL_LIBRARY}" DIRECTORY)
    target_include_directories(ConkerVita BEFORE PRIVATE "${VITAGL_DIR}/source")
endif()

target_link_libraries(ConkerVita PRIVATE
    -Wl,--whole-archive RecompiledFuncs -Wl,--no-whole-archive
    librecomp ultramodern
    "${VITAGL_LIBRARY}" vitashark SceShaccCgExt mathneon taihen_stub kubridge_stub
    SceShaccCg_stub SceKernelDmacMgr_stub SceIme_stub
    SceAppMgr_stub SceAppUtil_stub SceAudio_stub SceCtrl_stub SceTouch_stub
    SceCommonDialog_stub SceDisplay_stub SceGxm_stub SceMotion_stub
    ScePower_stub SceSysmodule_stub SceLibKernel_stub SceKernelThreadMgr_stub
    # libstdc++ only sees threads when pthreads' symbols are all linked in (it
    # checks weak references to them): otherwise std::thread throws.
    -Wl,--whole-archive pthread -Wl,--no-whole-archive
    m stdc++
)
target_link_options(ConkerVita PRIVATE -Wl,--gc-sections)

vita_create_self(eboot.bin ConkerVita UNSAFE)
vita_create_vpk(ConkerVita.vpk ${VITA_TITLEID} eboot.bin
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
    FILE sce_sys sce_sys
)
