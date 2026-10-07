// Declarations newlib hides in strict C/C++ modes (or lacks), for the runtime's
// third-party headers (sse2neon). Defined in vita_platform.cpp.
#ifndef CONKER_VITA_COMPAT_H
#define CONKER_VITA_COMPAT_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
int posix_memalign(void** memptr, size_t alignment, size_t size);
#ifdef __cplusplus
}
#endif
#endif
