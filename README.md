# PROJECT REMOTE — Nintendo 3DS

A small Nintendo 3DS built-in IR feasibility test. It does not use Wi-Fi or external hardware.

## Build locally

Install devkitPro with the Nintendo 3DS development tools, then from this folder run:

```sh
make
```

The build produces `project_remote.3dsx` in the project root.

## Build with GitHub Actions

The workflow is `.github/workflows/c-cpp.yml`. It uses the official `devkitpro/devkitarm` container, checks that the repository has the expected root-level `Makefile` and `source/main.c`, runs `make clean` and `make`, verifies the `.3dsx`, then uploads it as the `project-remote-3dsx` artifact.

**Important:** extract this ZIP and upload the *contents* of the extracted folder to the top level of your GitHub repository. Do not upload the enclosing folder `PROJECT_REMOTE_GITHUB_READY` as a nested folder. The repository root must directly contain `Makefile`, `source/`, and `.github/`.

Replace the existing `.github/workflows/c-cpp.yml` with the one in this archive. If the repository has any other workflow that runs `./configure`, delete that obsolete workflow; otherwise GitHub may continue running it independently.

## IR compatibility limitation

The documented libctru IRU API exposes IrDA-style data transfers and bitrate control. It does not document a raw consumer-remote carrier-frequency or arbitrary mark/space waveform generator. This test initializes IRU and reads its bitrate; it does not claim to control Samsung TVs, Roku devices, or other consumer remotes.
