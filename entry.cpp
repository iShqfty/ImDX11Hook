#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include "render.h"

#define EXIT_KEY VK_END

void MainThread(HMODULE mod) {

    rdr::init();

    while (!GetAsyncKeyState(EXIT_KEY));

    rdr::term();

    FreeLibraryAndExitThread(mod,0);
}

BOOL APIENTRY DllMain( HMODULE mod,
                       DWORD  callrzn,
                       LPVOID lprez
                     )
{
    if (callrzn == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(mod);

        const auto thread = CreateThread(
            nullptr,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread),
            mod,
            0,
            nullptr
        );

        if (thread) CloseHandle(thread);
    }
    return TRUE;
}

