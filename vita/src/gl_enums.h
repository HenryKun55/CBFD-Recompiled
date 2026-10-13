// The OpenGL names the renderer still describes blending, depth tests and texture wrapping with
// (its front states draws as GL would; the sceGxm back maps them): the values from GL's headers,
// without vitaGL.
#ifndef __CONKER_GL_ENUMS_H__
#define __CONKER_GL_ENUMS_H__

#include <cstdint>

typedef uint32_t GLenum;

#define GL_ZERO                 0
#define GL_ONE                  1
#define GL_SRC_COLOR            0x0300
#define GL_ONE_MINUS_SRC_COLOR  0x0301
#define GL_SRC_ALPHA            0x0302
#define GL_ONE_MINUS_SRC_ALPHA  0x0303
#define GL_DST_ALPHA            0x0304
#define GL_ONE_MINUS_DST_ALPHA  0x0305
#define GL_DST_COLOR            0x0306
#define GL_ONE_MINUS_DST_COLOR  0x0307

#define GL_NEVER                0x0200
#define GL_LESS                 0x0201
#define GL_EQUAL                0x0202
#define GL_LEQUAL               0x0203
#define GL_GREATER              0x0204
#define GL_NOTEQUAL             0x0205
#define GL_GEQUAL               0x0206
#define GL_ALWAYS               0x0207

#define GL_REPEAT               0x2901
#define GL_CLAMP_TO_EDGE        0x812F
#define GL_MIRRORED_REPEAT      0x8370

#endif
