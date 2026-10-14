/* PS Vita start-up screen: the port's version and the update check over the boot
 * picture, before the game starts. See vita_bootui.c. */
#ifndef VITA_BOOTUI_H
#define VITA_BOOTUI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Shows sce_sys/pic0.png; returns its display buffer (NULL on failure). */
uint32_t *vita_boot_picture_show(void);

/* framebuffer: the 960x544 ABGR display buffer showing the boot picture. Returns when
 * the game can start (or does not return: an update is being installed). */
void vita_bootui_run(uint32_t *framebuffer);

#ifdef __cplusplus
}
#endif

#endif
