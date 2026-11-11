#include <whb/log.h>
#include <whb/log_console.h>
#include <coreinit/foreground.h>
#include <proc_ui/procui.h>
#include <vpad/input.h>
#include <unistd.h>

int main(int argc, char **argv) {
    WHBLogConsoleInit();
    WHBLogConsoleDraw();
    WHBLogPrintf("Capibara Royale Final");
    WHBLogPrintf("Texturas Ultra 12000 manchas + 500 flores");
    WHBLogPrintf("Version que abre - La Pintada, Colombia");
    WHBLogPrintf("");
    WHBLogPrintf("Juego en: sd:/wiiu/apps/CapibaraRoyale/index.html");
    WHBLogPrintf("Abre navegador Wii U -> file:///wiiu/apps/CapibaraRoyale/index.html");
    WHBLogPrintf("");
    WHBLogPrintf("Controles: Stick mover, B rodar 5m, ZR disparar, X recargar, A agarrar");
    WHBLogPrintf("HOME para salir");
    ProcUIInit(&OSSavesDone_ReadyToRelease);
    VPADStatus vpad; int err;
    while(ProcUIProcessMessages(true) != PROCUI_STATUS_EXITING) {
        VPADRead(VPAD_CHAN_0, &vpad, 1, &err);
        if(vpad.hold & VPAD_BUTTON_HOME) break;
        usleep(10000);
    }
    WHBLogConsoleShutdown();
    ProcUIShutdown();
    return 0;
}
