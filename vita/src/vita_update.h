/* PS Vita: checks GitHub for a newer release of the port, downloads its .vpk and hands
 * over to updater.bin (vita/updater) to install it. See vita_update.c; the
 * start-up screen that drives it is vita_bootui.c. */
#ifndef VITA_UPDATE_H
#define VITA_UPDATE_H

typedef enum {
    VU_IDLE,        /* nothing checked yet */
    VU_CHECKING,    /* asking GitHub for the latest release */
    VU_UPTODATE,    /* this is the latest version */
    VU_AVAILABLE,   /* a newer version can be installed */
    VU_DOWNLOADING, /* downloading the .vpk */
    VU_READY,       /* downloaded and verified: VitaUpdate_Launch() installs it */
    VU_ERROR        /* VitaUpdate_Error() says what went wrong */
} vitaUpdateState_t;

/* Starts a check in the background. release_url: where the release JSON is read from
 * (the GitHub API's "latest release" when NULL or empty; update_url= in conker.cfg, for
 * testing against a local server). */
void VitaUpdate_Check(const char *release_url);
/* Downloads the version found by the check, then goes to VU_READY. */
void VitaUpdate_Download(void);
/* Stops a download. */
void VitaUpdate_Cancel(void);
/* 1 when the game may install an update: HENkaku's "Enable Unsafe Homebrew" is on
 * (updater.bin needs it to write ux0:app and the game to start it). */
int VitaUpdate_CanInstall(void);
/* Replaces the game with updater.bin, which installs the download. Returns only on error. */
void VitaUpdate_Launch(void);

vitaUpdateState_t VitaUpdate_State(void);
const char *VitaUpdate_CurrentVersion(void);
const char *VitaUpdate_NewVersion(void);
/* Downloaded and total bytes of the current download. */
void VitaUpdate_Progress(long long *done, long long *total);
/* What went wrong: an English sentence and the technical detail. */
const char *VitaUpdate_Error(void);
const char *VitaUpdate_ErrorDetail(void);

/* What updater.bin reported after the last install, read (and removed) once at start-up:
 * 1 on success, -1 on failure (with the message in error/detail), 0 if none. */
int VitaUpdate_TakeInstallResult(char *version, int version_size, char *error, int error_size, char *detail,
                                 int detail_size);

#endif
