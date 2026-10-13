#!/bin/sh
# Automated benchmark of the Vita build in Vita3K (see vita/src/bench.cpp), as the
# Project IGI port does it: installs vita/build/ConkerVita.vpk into the emulated
# CBFD00064, requests a run through ux0:data/conker/bench.txt, launches Vita3K with
# the PS Vita speed model (444 MHz per thread, 3 cores), waits for bench_result.txt,
# closes that Vita3K instance only, and prints the result.
#
# usage: vita/tools/bench_vita3k.sh [seconds]     (default 60)
# env:   SHOT     capture the Vita3K window every SHOT seconds into $SHOT_DIR
#        SHOT_DIR where the captures go (default vita/build/shots)
#        SCRIPT   input script (see bench.hpp); default: through the intro and the
#                 title menu into a new game
#        MHZ      emulated CPU clock (default 444; 0 = unthrottled)
#        VITA3K   Vita3K binary (default the local source build with the speed model)
#        PROFILE  1: Vita3K's guest sampling profiler, symbolized at the end
#        PROFILE_FROM  seconds after the start the profiled window begins (default 0);
#                 Vita3K rewrites the profile every 5 s
#        TIMEOUT  seconds before giving up (default seconds + 300)
set -u
ROOT=$(cd "$(dirname "$0")/.." && pwd)
SECS=${1:-60}
BUILD=${BUILD:-$ROOT/build}
VITA3K=${VITA3K:-$HOME/Documents/workspace/games/Vita3K/build/macos-ninja/bin/Release/Vita3K.app/Contents/MacOS/Vita3K}
TIMEOUT=${TIMEOUT:-$((SECS + 300))}
UX0="$HOME/Library/Application Support/Vita3K/Vita3K/fs/ux0"
APP="$UX0/app/CBFD00064"
DATA="$UX0/data/conker"
LOG=${TMPDIR:-/tmp}/conker_bench_vita3k.log
# Through the logos and the intro (START skips), then A on the title menu's choices.
SCRIPT=${SCRIPT:-"8:S,12:S,16:S,20:A,24:A,28:A,32:S,36:A,40:A"}

[ -f "$BUILD/ConkerVita.vpk" ] || { echo "no $BUILD/ConkerVita.vpk; build first" >&2; exit 1; }
[ -x "$VITA3K" ] || { echo "no Vita3K at $VITA3K" >&2; exit 1; }
[ -f "$DATA/conker.n64.us.1.0.z64" ] || [ -f "$DATA/baserom.us.z64" ] || { echo "no ROM in $DATA" >&2; exit 1; }
if pgrep -f "Vita3K -r CBFD00064" > /dev/null; then
    echo "a Vita3K instance running CBFD00064 already exists; close it first" >&2
    exit 1
fi

mkdir -p "$APP"
unzip -q -o "$BUILD/ConkerVita.vpk" -d "$APP" || exit 1
# Vita3K does not truncate files the game rewrites: stale tails would stay.
rm -f "$DATA/audio.raw" "$DATA/bench_result.txt" "$DATA/bench_frames.csv" "$DATA/bench_phase.txt" "$DATA/bench_shot_now.txt" "$DATA/log.txt"
echo "$SECS ${SHOT:-0} $SCRIPT" > "$DATA/bench.txt"

PROF_DIR=${TMPDIR:-/tmp}/conker_v3k_profile.$$
if [ "${PROFILE:-0}" = 1 ]; then
    mkdir -p "$PROF_DIR"
    export VITA3K_PROFILE="$PROF_DIR/live.txt"
fi

stop() {
    pkill -9 -f "Vita3K -r CBFD00064" 2>/dev/null
    rm -f "$DATA/bench.txt"
}
trap 'stop; exit 1' INT TERM

if [ "${SHOT:-0}" -gt 0 ]; then
    SHOT_DIR=${SHOT_DIR:-$BUILD/shots}
    mkdir -p "$SHOT_DIR"
    rm -f "$SHOT_DIR"/shot_*.png
    WINID_BIN=${TMPDIR:-/tmp}/conker_window_id
    [ "$WINID_BIN" -nt "$ROOT/tools/window_id.swift" ] || swiftc -O "$ROOT/tools/window_id.swift" -o "$WINID_BIN" || exit 1
fi

# Our ux0, whatever Vita3K's config.yml points at: other ports' sessions share the
# emulator and may set its pref-path to theirs (the local build reads VITA3K_PREF_PATH).
(VITA3K_PREF_PATH="$UX0/../" VITA3K_CPU_MHZ=${MHZ:-444} "$VITA3K" -r CBFD00064 > "$LOG" 2>&1 &)
echo "Vita3K started (CPU ${MHZ:-444} MHz), $SECS s run, waiting (timeout $TIMEOUT s)"
started=0
while [ $started -lt 30 ] && ! pgrep -f "Vita3K -r CBFD00064" > /dev/null; do
    sleep 1
    started=$((started + 1))
done

waited=0
have_start=0
while [ ! -s "$DATA/bench_result.txt" ] && [ $waited -lt "$TIMEOUT" ]; do
    pgrep -f "Vita3K -r CBFD00064" > /dev/null || break
    if [ "${PROFILE:-0}" = 1 ] && [ $have_start = 0 ] && [ $waited -ge "${PROFILE_FROM:-0}" ] && [ -s "$PROF_DIR/live.txt" ]; then
        cp "$PROF_DIR/live.txt" "$PROF_DIR/start.txt"
        have_start=1
    fi
    if [ "${SHOT:-0}" -gt 0 ] && [ -s "$DATA/bench_shot_now.txt" ]; then
        n=$(head -n 1 "$DATA/bench_shot_now.txt")
        rm -f "$DATA/bench_shot_now.txt"
        pid=$(pgrep -f "Vita3K -r CBFD00064" | head -n 1)
        win=$("$WINID_BIN" "$pid" "(CBFD00064)" | head -n 1)
        [ -n "$win" ] && screencapture -x -o -l "$win" "$(printf "%s/shot_%03d.png" "$SHOT_DIR" "$n")"
    fi
    sleep 1
    waited=$((waited + 1))
done
[ "${PROFILE:-0}" = 1 ] && cp "$PROF_DIR/live.txt" "$PROF_DIR/end.txt" 2>/dev/null
sleep 2
stop

if [ ! -s "$DATA/bench_result.txt" ]; then
    echo "no result after $waited s; last lines of ux0:data/conker/log.txt:" >&2
    tail -n 20 "$DATA/log.txt" >&2
    exit 1
fi
cp "$DATA/bench_frames.csv" "$BUILD/bench_frames.csv" 2>/dev/null
cp "$DATA/log.txt" "$BUILD/bench_log.txt" 2>/dev/null
if [ "${PROFILE:-0}" = 1 ] && [ -s "$PROF_DIR/end.txt" ]; then
    [ -f "$PROF_DIR/start.txt" ] || : > "$PROF_DIR/start.txt"
    echo "---- profile (top functions) ----"
    python3 "$HOME/Documents/workspace/games/igi/tools/vita3k_profile_sym.py" "$BUILD/ConkerVita" "$PROF_DIR/start.txt" "$PROF_DIR/end.txt" ${TOP:-40}
fi
[ "${SHOT:-0}" -gt 0 ] && echo "screenshots in $SHOT_DIR"
cat "$DATA/bench_result.txt"
