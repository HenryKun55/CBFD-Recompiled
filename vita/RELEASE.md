# Vita releases and the in-game updater

The Vita build checks for a newer release of the port at start-up and can install
it by itself. This page is how releases have to be made for that to work, and how
the pieces fit together.

## Where releases live

- A **public** GitHub repository that holds only releases (no game data, ever):
  `HenryKun55/conker-vita` by default. The CMake cache variable `CONKER_UPDATE_REPO`
  (`owner/repo`) changes it: `-DCONKER_UPDATE_REPO=someone/something`.
- The game reads `https://api.github.com/repos/<CONKER_UPDATE_REPO>/releases/latest`:
  only the release GitHub marks as **Latest** counts. Drafts and pre-releases are
  never offered.

## The version

- `CONKER_PORT_VERSION` in `vita/CMakeLists.txt` is the one place the version is set
  (`major.minor.patch`; minor and patch are one digit each, because the Vita's
  `param.sfo` APP_VER is `NN.NN`: 0.1.0 is `00.10`, 1.2.3 is `01.23`).
- It is compiled into the game (the boot screen shows it in the bottom right
  corner and in the update panel). It is not on the LiveArea: an update made from
  the game doesn't replace sce_sys, so it would go stale.
- The update check offers a release only when its version is **higher** than the
  one running, so raise `CONKER_PORT_VERSION` for every release.

## Cutting a release

1. Raise `CONKER_PORT_VERSION` in `vita/CMakeLists.txt`, commit.
2. Build the Vita package:

   ```sh
   cmake -S vita -B vita/build -G Ninja -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake
   cmake --build vita/build
   ```

3. Tag the commit `v<version>` (for example `v0.2.0`) and push the tag to the
   source repository if you publish it there.
4. On `HenryKun55/conker-vita`, create a release:
   - **tag**: `v<version>`, exactly (`v0.2.0`). The game takes the version from the
     tag: the leading `v` is dropped, anything after a `-` is ignored.
   - **asset**: `vita/build/ConkerVita.vpk`, uploaded with the name **`conker.vpk`**
     (that exact, lower-case name; it is the only asset the updater looks at).
   - not a draft, not a pre-release, marked as the latest release.
5. Done: Vitas with an older version offer the update at their next start.

GitHub publishes each asset's size and SHA-256 in the release JSON
(`size`, `digest`); the game checks both on the downloaded file before anything is
installed.

## What happens on the Vita

1. `vita/src/vita_bootui.c` (from `main` in `vita/src/main_vita.cpp`, before the renderer and the game
   start; not during a bench run) draws the version over the boot picture and, unless `conker.cfg` has
   `update_check=0`, starts the check (`vita/src/vita_update.c`) on its own
   thread. Without Wi-Fi it fails at once and the game starts; when GitHub has
   not answered within 3 seconds the game starts too. A failed check (no
   internet, GitHub unreachable, no release yet) is only logged, never shown.
2. A newer release: the panel offers it (X: install, O: skip). X downloads
   `conker.vpk` to `ux0:data/conker/update/conker.vpk` (free space checked first, size and
   SHA-256 checked after), writes `ux0:data/conker/update/plan.txt` and starts
   `app0:updater.bin` with `sceAppMgrLoadExec`.
3. `updater.bin` (`vita/updater/updater.c`) unpacks the .vpk into
   `ux0:data/conker/update/pkg` (zip CRCs checked), checks that its `param.sfo` is
   CBFD00064, unmounts `app0:`, checks that every file can be replaced, then
   replaces the files in `ux0:app/CBFD00064` (eboot.bin last). `sce_sys` is left as
   installed (the system holds it), so a release that changes the LiveArea art
   only shows it when installed with VitaShell. It writes
   `ux0:data/conker/update/result.txt` and starts the new game.
4. At its next start the game shows the result once on the boot screen
   ("Version X is installed", or the failure and the log path).

Everything is logged to `ux0:data/conker/update/update.log`. `conker.cfg`, saves and
the game files under `ux0:data/conker` are never touched. A failure before step 3
changes nothing; a failure while files are replaced says so and asks for the .vpk
to be installed again with VitaShell.

The vpk carries, besides `eboot.bin` and `sce_sys`: `updater.bin`,
`cacert.pem` (CA certificates for HTTPS, from curl.se/ca, MPL 2.0) and the boot
screen fonts in `font/` (Oswald, SIL Open Font License).

## Testing without GitHub

`update_url=<url>` in `ux0:data/conker/conker.cfg` makes the game read the release JSON
from that URL instead of the GitHub API (plain `http://` works). Serve a JSON
shaped like GitHub's from a local server:

```json
{
  "tag_name": "v9.9.9",
  "assets": [
    {
      "name": "conker.vpk",
      "size": 12345678,
      "digest": "sha256:<sha256 of the file>",
      "browser_download_url": "http://192.168.1.10:8000/conker.vpk"
    }
  ]
}
```

`size` must be the file's exact size; `digest` may be left out (then only the size
is checked). `update_auto=1` (testing only) installs a found release without
waiting for X. Remove both afterwards.

In Vita3K the whole flow works against such a local server (check, download,
updater.bin, relaunch, result). HTTPS to GitHub does not: Vita3K's network layer
makes curl treat `api.github.com` as an IP address and the certificate check
fails (logged, the game starts as usual); on hardware the same code (from the
OpenMoHAA port) reaches GitHub.
