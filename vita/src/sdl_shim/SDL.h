// The few SDL calls host/src's shared files make (debug switches and the window's
// size), for the Vita build, which doesn't use SDL: no window, so no widescreen.
#ifndef CONKER_VITA_SDL_SHIM_H
#define CONKER_VITA_SDL_SHIM_H

#include <stdlib.h>

typedef struct SDL_Window SDL_Window;

static inline const char* SDL_getenv(const char* name) { return getenv(name); }

static inline void SDL_GetWindowSize(SDL_Window*, int* w, int* h) {
    if (w) *w = 0;
    if (h) *h = 0;
}

#endif
