#include "headers/mics/Books.hpp"
#include "headers/mics/FileTXT.hpp"
#include "headers/mics/exception.hpp"
#include "headers/mics/virtualClass.hpp"
#include "headers/gui/windows/window.hpp"

using namespace std;    
ULONG_PTR gdiplusToken; // for shutting down gdi+


void shutdown()
{
	// Exit
	GdiplusShutdown(gdiplusToken);
}
//===========================================================================

//===========================================================================
int Books::booksCount = 0;
bool startup()
{
    

	return true;
}
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR    lpCmdLine,
	int       nCmdShow)
{
	// Check if user wants to uninstall
	// if (strcmp(lpCmdLine, "-uninstall") == 0)
	// {
	// 	Patcher::uninstallFiles(Helper::getExecutableDirectory());
	// 	return 0;
	// }

	// Init GDI+
	
 	CoInitialize(NULL);
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);  
	// __argc / __argv
	if (strcmp(lpCmdLine, "-ignoreinstances") == 0 || startup())
	{
		std::cout << "\nFoleder: " << __argv[0] << endl;
		try
		{
			MainWindow* main = new MainWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
			main->run();
            shutdown();
            delete main;
		}
		catch (const MyException& ex)
		{
			std::string errorMsg = ex.what();
			MessageBoxA(NULL, errorMsg.c_str(), ex.codeError(), 0);
		}
	}
    shutdown();
	return 0;
}
