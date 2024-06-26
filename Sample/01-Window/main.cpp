#include <iostream>
#include <windows.h>


LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

int main(int args, char* argv[])
{
    WNDCLASSEXA wc{};
    wc.cbSize = sizeof(wc);
    wc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    wc.lpszClassName = "OpenGL Window";
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpfnWndProc = WndProc;
    wc.style = CS_VREDRAW | CS_HREDRAW;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    
    RegisterClassExA(&wc);

    int cx = 1024;
    int cy = 720;
    int x = (GetSystemMetrics(SM_CXSCREEN) - cx) /2;
    int y = (GetSystemMetrics(SM_CYSCREEN) - cy) /2;

    HWND hwnd = CreateWindowExA(NULL, wc.lpszClassName, wc.lpszClassName,
    WS_OVERLAPPEDWINDOW, x, y, cx, cy, nullptr, 0, wc.hInstance, 0);

    
    ShowWindow(hwnd, TRUE);

    MSG msg{};

    while (msg.message != WM_QUIT)
    {
        if(PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)){
            if(msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE){
                PostQuitMessage(0);
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }
    
    return (int)msg.lParam;
}
#if __has_include(<windows.h>)
#define NOMINMAX
#endif
LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    return DefWindowProcA(hwnd, msg, wp, lp);
}