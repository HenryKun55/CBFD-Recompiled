// The Vita has no mmap: the few users in the runtime (sljit's executable memory for
// mods' code, which isn't supported on the Vita, and page protection for patching
// functions) get plain allocations and no-op protection (vita_platform.cpp).
#ifndef CONKER_VITA_SYS_MMAN_H
#define CONKER_VITA_SYS_MMAN_H

#include <stddef.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PROT_NONE  0x0
#define PROT_READ  0x1
#define PROT_WRITE 0x2
#define PROT_EXEC  0x4

#define MAP_SHARED    0x01
#define MAP_PRIVATE   0x02
#define MAP_FIXED     0x10
#define MAP_ANON      0x20
#define MAP_ANONYMOUS MAP_ANON
#define MAP_FAILED    ((void*)-1)

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void* addr, size_t length);
int mprotect(void* addr, size_t length, int prot);
// newlib only declares it for BSD sources.
int getpagesize(void);

#ifdef __cplusplus
}
#endif

#endif
