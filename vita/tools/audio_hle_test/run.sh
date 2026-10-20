#!/bin/sh
# Builds the HLE audio host test (audio_hle_test.cpp) and runs it on captured tasks.
#
# usage: vita/tools/audio_hle_test/run.sh <capture dir or task files...> [-- test options]
#   capture dir: ux0:data/conker/audiocap (from debug_capture_audio, see vita/src/audio_capture.hpp)
#   test options: --reps N (timing repetitions, default 20), --fuzz N (random lists),
#                 --seed S, --verbose
# env: CXX (default c++), OUT (build dir, default $TMPDIR/audio_hle_test),
#      HLE_FLAGS (e.g. -DAUDIO_HLE_PROFILE: time per command)
set -eu
HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/../../.." && pwd)
RT="$ROOT/tools/N64ModernRuntime"
OUT=${OUT:-${TMPDIR:-/tmp}/audio_hle_test}
CXX=${CXX:-c++}
mkdir -p "$OUT"
INC="-I$RT/librecomp/include -I$RT/librecomp/include/librecomp -I$RT/N64Recomp/include -I$RT/ultramodern/include -I$RT/thirdparty/sse2neon -I$RT/thirdparty -I$ROOT/vita/src"
FLAGS="-std=c++20 -O2 -g -w -fno-strict-aliasing"
# The recompiled microcode is large: build it once.
if [ ! -f "$OUT/audio_ucode.o" ] || [ "$ROOT/RecompiledFuncs/rsp/audio_ucode.cpp" -nt "$OUT/audio_ucode.o" ]; then
    $CXX $FLAGS $INC -c "$ROOT/RecompiledFuncs/rsp/audio_ucode.cpp" -o "$OUT/audio_ucode.o"
fi
$CXX $FLAGS $INC -c "$RT/librecomp/src/rsp.cpp" -o "$OUT/rsp.o"
$CXX $FLAGS ${HLE_FLAGS:-} $INC -c "$ROOT/vita/src/audio_hle.cpp" -o "$OUT/audio_hle.o"
$CXX $FLAGS $INC "$HERE/audio_hle_test.cpp" "$OUT/audio_hle.o" "$OUT/audio_ucode.o" "$OUT/rsp.o" -o "$OUT/audio_hle_test"

FILES=""
while [ $# -gt 0 ] && [ "$1" != "--" ]; do
    if [ -d "$1" ]; then FILES="$FILES $(ls "$1"/task_*.bin | tr '\n' ' ')"; else FILES="$FILES $1"; fi
    shift
done
[ $# -gt 0 ] && shift
exec "$OUT/audio_hle_test" "$@" $FILES
