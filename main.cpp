#include <stdio.h>
#include <Windows.h>
#include <GLFW/glfw3.h>

#include "graphicsEngine\graphics_engine.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    printf("Starting application\n");
    HWND hWnd = init_window(hInstance);
    ShowWindow(hWnd, SW_SHOW);

    // messages
    MSG msg;
    while (TRUE)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (msg.message == WM_QUIT)
            {
                break;
            }
        }
        else
        {
            //game code goes here
        }
    }

    printf("Closing application\n");
    return msg.wParam;
}
