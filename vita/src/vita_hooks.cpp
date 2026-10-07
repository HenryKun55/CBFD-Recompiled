// The desktop build's mouse camera (host/src/mouse_camera.cpp) reads the mouse and
// SDL's events; the Vita has neither, so its hooks leave the game's own camera be.

#include "recomp.h"

#include "conker.hpp"

bool conker::mouse_camera::stick_turns_camera() {
    return false;
}

bool conker::mouse_camera::normal_camera() {
    return false;
}

extern "C" void conker_mouse_camera_follow(uint8_t*, recomp_context*) {}
extern "C" void conker_mouse_camera_look_mode(uint8_t*, recomp_context*) {}
extern "C" void conker_mouse_camera_collide(uint8_t*, recomp_context*) {}
extern "C" void conker_mouse_camera(uint8_t*, recomp_context*) {}
