#include "../../../headers/gui/windows/window.hpp"
#include "../../../headers/mics/exception.hpp"
#include "../../../headers/mics/BitmapHelper.hpp"
#include "../../../headers/gui/mics/rectCorner.hpp"
#include <gdiplus.h>
using namespace Gdiplus;
MainWindow::MainWindow(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR    lpCmdLine,
	int       nCmdShow) // ctr for main window (using in main.cpp)
{
    constructLayout(); //call preload Metrics func
	this->hInstance = hInstance;
	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW + 6; 
	wc.hInstance = hInstance;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = MainWindow::_WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "WinMainClass";
    
	if (!RegisterClassEx(&wc))
	{
		throw MyException("Error of register Class",MyException::WindowErrors::CREATE_REGISTER_ERROR); // for try / catch (main.cpp)
	}
	hWnd = CreateWindowEx(0,
		wc.lpszClassName,
		"Security of MVO",
		WS_CAPTION | WS_SYSMENU |WS_MINIMIZEBOX,
		//WS_OVERLAPPEDWINDOW,
		windowX, windowY, windowW, windowH,
		nullptr, nullptr, hInstance, nullptr);
        if(!hWnd) throw MyException("Error of create HWND",MyException::WindowErrors::CREATE_WINDOW_ERROR);
		LoadResources(hWnd);
        LONG_PTR val = reinterpret_cast<LONG_PTR>(this);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, val);
        ShowWindow(hWnd, nCmdShow);
	    UpdateWindow(hWnd);
        running = true;
		std::cout<< "W: " << windowW << " H: " << windowH << std::endl;
}
void MainWindow::constructLayout() //preload Metrics func
{
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	windowH = (uint16_t)screenHeight * 0.5;
	if (windowH < 480) windowH = 480;
	windowW = (uint16_t)windowH * (16.0 / 9.0);
	windowScale = (uint16_t)windowH / 1080.0f;
	windowX = (uint16_t)(screenWidth - windowW) * 0.5;
	windowY = (uint16_t)(screenHeight - windowH) * 0.5;
	GetWindowRect(hWnd, &windowRect);
	windowRect.right = windowW;
	windowRect.bottom = windowH;
}

int MainWindow::run(){ // main messages loop
    MSG msg;
    while(running)
    {
        while(GetMessage(&msg,nullptr,0,0)){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}
// A static function that retrieves a pointer to our class and calls the true WndProc callback
LRESULT CALLBACK MainWindow::_WndProc(HWND hWnd2, UINT message, WPARAM wParam, LPARAM lParam) //hook for WndProc
{
	MainWindow *me = (MainWindow *)(GetWindowLongPtr(hWnd2, GWLP_USERDATA));
	if (me){
		return me->WndProc(hWnd2, message, wParam, lParam);}

	return DefWindowProc(hWnd2, message, wParam, lParam);
}
LRESULT CALLBACK MainWindow::WndProc(HWND hWnd2, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
        case WM_LBUTTONDOWN:
		{
			break;
		}
        case WM_DESTROY:
		{
			std::cout<< "App is closing...";
			running = false;
			PostQuitMessage(0);
			break;
		}
        case WM_PAINT:
		{
			hdc = BeginPaint(hWnd2, &ps);
			paint(hdc);
			EndPaint(hWnd2, &ps);
			break;
		}
		
        default:
			return DefWindowProc(hWnd2, message, wParam, lParam);
    }
    return 0;
}
void MainWindow::LoadResources(HWND hWnd)
{
	POINT p;
	p.x = windowRect.right;
	p.y = windowRect.top;
	HDC hdc = GetDC(hWnd);
	Bitmap* bitmap = new Bitmap(L"..\\.\\.\\resoureses\\logo.png");
	cacheLogos[CachedBitmaps::childLogo] = BitmapHelper::createCachedBitmap(bitmap,hdc);
	delete bitmap;
}

void MainWindow::paint(HDC hdc)
{
	std::cout<<"Paint!\n";
    Graphics *gt = new Graphics(hdc);
    gt->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);
	gt->SetCompositingMode(CompositingMode::CompositingModeSourceOver);
	gt->SetPixelOffsetMode(PixelOffsetMode::PixelOffsetModeHighQuality);
	gt->SetInterpolationMode(InterpolationMode::InterpolationModeHighQuality);
	gt->SetCompositingQuality(CompositingQuality::CompositingQualityHighQuality);
	gt->DrawCachedBitmap(cacheLogos[CachedBitmaps::childLogo].get(),20,0);

    delete gt;
}
/*bool Main::restartInAdministratorMode()
{
	// Launch itself as admin
	std::wstring myPath = Helper::getExecutablePath();
	SHELLEXECUTEINFO sei = { sizeof(sei) };
	sei.lpVerb = L"runas";
	sei.lpFile = myPath.c_str();
	sei.lpParameters = L"-ignoreinstances";
	sei.hwnd = NULL;
	sei.nShow = SW_SHOWDEFAULT;

	if (!ShellExecuteEx(&sei))
	{
		return false;
	}
	else
	{
		running = false;
		return true;
	}
}*/