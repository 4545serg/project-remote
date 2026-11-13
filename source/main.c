#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv) {
    (void)argc; (void)argv;
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    consoleInit(GFX_BOTTOM, NULL);

    Result init = IRU_Initialize();
    u8 bitrate = 0;
    Result rate = R_FAILED(init) ? init : IRU_GetBitRate(&bitrate);

    while (aptMainLoop()) {
        hidScanInput();
        u32 down = hidKeysDown();
        consoleClear();
        printf("PROJECT REMOTE\n");
        printf("Built-in IR feasibility test\n\n");
        printf("IRU init: 0x%08lX\n", (unsigned long)init);
        if (R_SUCCEEDED(init)) {
            printf("Bitrate query: 0x%08lX\n", (unsigned long)rate);
            if (R_SUCCEEDED(rate)) printf("Bitrate setting: %u\n", bitrate);
        }
        printf("\nNo Wi-Fi or external hardware.\n");
        printf("This test does not transmit TV commands.\n\n");
        printf("The documented IRU interface is IrDA-SIR data\n");
        printf("transfer, not a documented raw consumer-IR\n");
        printf("carrier / mark-space waveform generator.\n\n");
        printf("Samsung TV and Roku IR compatibility is\n");
        printf("therefore unverified and must not be claimed.\n\n");
        printf("Press B to exit.\n");
        if (down & KEY_B) break;
        gfxFlushBuffers(); gfxSwapBuffers(); gspWaitForVBlank();
    }
    if (R_SUCCEEDED(init)) IRU_Shutdown();
    gfxExit();
    return 0;
}
