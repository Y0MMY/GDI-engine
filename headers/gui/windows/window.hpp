#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <Windows.h>
#include "../../../headers/stdafx.h"
#include <memory>
class MainWindow
{
private:
    /* data */
    uint16_t windowX; // position window of X
    uint16_t windowY;// position window of Y
    uint16_t windowH;// window width
    uint16_t windowW;// window height
    uint16_t screenWidth; // width of screen (1920)
    uint16_t screenHeight; // height of screen (1080)
    uint16_t windowScale; // scale of window (x/x2)
    HINSTANCE hInstance;
    HWND hWnd;
    RECT windowRect;
    void constructLayout();//preload Metrics func
    void LoadResources(HWND hWnd); // load Resourese files 
    bool running; // is program running
    static LRESULT CALLBACK _WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void paint(HDC hdc);
    typedef enum
    {
        bg,
		childLogo,
    } CachedBitmaps;
    std::shared_ptr<CachedBitmap> cacheLogos[CachedBitmaps::childLogo+1];
public:
    int run();
    MainWindow(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR    lpCmdLine,
	int       nCmdShow);
    ~MainWindow() = default;
};


#endif // __WINDOW_H__