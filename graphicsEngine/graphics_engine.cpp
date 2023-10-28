#include "graphics_engine.h"

#include <stdio.h>
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

HWND init_window(HINSTANCE hInstance)
{
    const auto pClassName = "Theme Park Designer";

    // register window class
    WNDCLASSEX wc;
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
    RECT wr = {0, 0, 500, 400};    // set the size, but not the position
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);    // adjust the size

    HWND hWnd = CreateWindowEx(
        0, pClassName,
        "Theme Park Designer",
        WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU,
        200, 200,
        wr.right - wr.left,
        wr.bottom - wr.top,
        nullptr, nullptr, hInstance, nullptr
    );
    return hWnd;
}