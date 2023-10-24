#include <iostream>
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    const auto pClassName = "Theme Park Designer";

    // register window class
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;

    RegisterClassEx(&wc);

    // create window instance
    HWND hWnd = CreateWindowEx(
        0, pClassName,
        "Theme Park Designer",
        WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU,
        200, 200,
        1280, 720,
        nullptr, nullptr, hInstance, nullptr
    );

    ShowWindow(hWnd, SW_SHOW);

    // messages
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if (gResult == -1)
    {
        return -1;
    }

    return msg.wParam;
}