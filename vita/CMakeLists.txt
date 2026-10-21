cmake_minimum_required(VERSION 3.20)

# PS Vita build of Conker's Bad Fur Day: Recompiled.
#
# RecompiledFuncs/ must exist first (`python3 recomp/recompile.py`), and the submodules must
# have the port's changes (vita/submodule-patches/apply.sh). See the README's "PS Vita port".
#
#   cmake -S vita -B vita/build -G Ninja -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake
#   cmake --build vita/build
#
# Instead of RT64 (Vulkan/D3D12/Metal) it draws with sceGxm through a small HLE
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
# The port's version: the one place it is set (see RELEASE.md). Releases are tagged
# v<this> on HenryKun55/conker-vita, and the game offers a release only when its version
# is higher, so raise it for every release. major.minor.patch, minor and patch one digit
# each (param.sfo's APP_VER is NN.NN: 1.0.0 is 01.00).
set(CONKER_PORT_VERSION "1.2.0")
set(CONKER_UPDATE_REPO "HenryKun55/conker-vita" CACHE STRING "GitHub owner/repo the update check reads")
if(NOT CONKER_PORT_VERSION MATCHES "^([0-9]+)\\.([0-9])\\.([0-9])$")
    message(FATAL_ERROR "CONKER_PORT_VERSION must be major.minor.patch with one-digit minor and patch")
endif()
math(EXPR CONKER_VERSION_MAJOR "${CMAKE_MATCH_1}")
if(CONKER_VERSION_MAJOR LESS 10)
    set(CONKER_VERSION_MAJOR "0${CONKER_VERSION_MAJOR}")
endif()
set(VITA_VERSION "${CONKER_VERSION_MAJOR}.${CMAKE_MATCH_2}${CMAKE_MATCH_3}")

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
    src/audio_hle.cpp
    src/audio_capture.cpp
    src/controls.cpp
    src/menu.cpp
    src/button_icons.cpp
    src/button_art.cpp
    src/vita_update.c
    src/vita_bootui.c
    "${HOST_DIR}/null_renderer.cpp"
    "${HOST_DIR}/overlays.cpp"
    "${HOST_DIR}/ultra_extras.cpp"
    "${HOST_DIR}/mod_api.cpp"
    "${HOST_DIR}/rom_versions.cpp"
    "${HOST_DIR}/widescreen.cpp"
    "${HOST_DIR}/cutscene_aspect.cpp"
    "${HOST_DIR}/field_of_view.cpp"
    "${HOST_DIR}/interpolation.cpp"
    "${HOST_DIR}/extras.cpp"
    "${HOST_DIR}/cutscene_skip.cpp"
    "${HOST_DIR}/text_translation.cpp"
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
target_compile_definitions(ConkerVita PRIVATE CONKER_PORT_VERSION="${CONKER_PORT_VERSION}"
    CONKER_UPDATE_REPO="${CONKER_UPDATE_REPO}")
# The renderer's per-vertex and per-texel loops: full optimisation, and float maths
# without IEEE corner cases (no NaNs or infinities reach them).
set_source_files_properties(src/vita_renderer.cpp PROPERTIES COMPILE_OPTIONS "-O3;-ffast-math")
set_source_files_properties(src/tmem.cpp PROPERTIES COMPILE_OPTIONS "-O3;-ffast-math")
# The HLE audio microcode (bit-exact integer maths: no -ffast-math needed or wanted).
set_source_files_properties(src/audio_hle.cpp PROPERTIES COMPILE_OPTIONS "-O3;-fno-strict-aliasing")

# The renderer draws with sceGxm directly (src/gxm_backend.inc). vitaGL (the SDK's) is only
# used to show the startup error dialog, before there is a renderer.
target_link_libraries(ConkerVita PRIVATE
    -Wl,--whole-archive RecompiledFuncs -Wl,--no-whole-archive
    librecomp ultramodern
    vitaGL vitashark SceShaccCgExt mathneon taihen_stub kubridge_stub
    # The update check (src/vita_update.c): HTTPS to GitHub.
    curl ssl crypto zstd png z SceNet_stub SceNetCtl_stub SceIofilemgr_stub
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

# The boot screen's fonts (Oswald, SIL Open Font License).
find_package(Python3 REQUIRED COMPONENTS Interpreter)
set(BOOT_FONTS "${CMAKE_CURRENT_BINARY_DIR}/vita_font")
execute_process(
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/tools/make_vita_boot_font.py" "${BOOT_FONTS}"
    RESULT_VARIABLE BOOT_FONT_RESULT)
if(NOT BOOT_FONT_RESULT EQUAL 0)
    message(FATAL_ERROR "tools/make_vita_boot_font.py failed (it needs Pillow: pip install Pillow)")
endif()
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/tools/make_vita_boot_font.py" "${CMAKE_CURRENT_SOURCE_DIR}/fonts/Oswald.ttf")

# updater.bin: puts a downloaded release in place of the game's files (updater/). A
# separate program, so the game is closed while its files are replaced; unsafe, as only
# unsafe homebrew may write to ux0:app.
add_executable(conker_updater updater/updater.c updater/debugScreen.c)
target_compile_options(conker_updater PRIVATE -Wall -Wextra)
target_link_libraries(conker_updater PRIVATE png z m
    SceDisplay_stub SceCtrl_stub SceAppMgr_stub ScePower_stub SceLibKernel_stub
    SceKernelThreadMgr_stub SceIofilemgr_stub SceProcessmgr_stub)
vita_create_self(updater.bin conker_updater UNSAFE)
# Every language's translation (vita/translation/<language>.txt and <language>_ui.txt).
file(GLOB TRANSLATION_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/translation
     ${CMAKE_CURRENT_SOURCE_DIR}/translation/*.txt)
list(FILTER TRANSLATION_SOURCES EXCLUDE REGEX "^en_reference")
set(TRANSLATION_FILES "")
foreach(f ${TRANSLATION_SOURCES})
    list(APPEND TRANSLATION_FILES FILE ${CMAKE_CURRENT_SOURCE_DIR}/translation/${f} translation/${f})
endforeach()
vita_create_vpk(ConkerVita.vpk ${VITA_TITLEID} eboot.bin
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
    FILE sce_sys sce_sys
    ${TRANSLATION_FILES}
    FILE "${CMAKE_CURRENT_BINARY_DIR}/updater.bin.out" updater.bin
    # CA certificates for the update check's HTTPS (curl.se/ca, MPL 2.0)
    FILE updater/cacert.pem cacert.pem
    FILE "${BOOT_FONTS}/boot.font" font/boot.font
    FILE "${BOOT_FONTS}/boot_small.font" font/boot_small.font
    FILE fonts/OFL.txt font/Oswald-OFL.txt
)
