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
// int main(int argc, char* argv[]) {
      
//     setlocale(LC_ALL, "Russian");
//     SetConsoleCP(1251);
//     SetConsoleOutputCP(1251); 
//     Books *tempbook = new Books();
//     // delete book;
//     // books.push_back(*book);
//     // std::cout<<books[0].getAuthor() << endl;
//     // book = new Books("Sanya Labya","Kak viebat telok","������� ���� �� �������)",2000,2022);
//     // books.push_back(*book);
//     // std::cout<<books[1].getAuthor() << endl;
//     bool open = true;
//     int input;
//     FileTXT ft;
//     while (open)
//     {
//         system("cls");
//         printf("1) �������� ������ ������\n");
//         printf("2) ��������� ������ ������\n");
//         printf("3) ������� ������\n");
//         cin >> input;
//         if(input < 1 || input > 3) continue;
//         switch (input)
//         {
//             case 1: 
//             {
//                 string name,author,desc;
//                 int price,date;
//                 cout << "������� ������!\n";
//                 cin >> author;
//                 cout << "������� �������� �����!\n";
//                 cin >> name;
//                 cout << "������� ��������!\n";
//                 cin >> desc;
//                 cout << "������� ���������!\n";
//                 cin >> price;
//                 cout << "������� ��� �������!\n";
//                 cin >> date;
//                 tempbook = new Books(author,name,desc,price,date);
//                 ft.writeTXT(*tempbook,"../data");
//                 std::cout<<"������ �������!\n";
//                 while( _kbhit() /* defined in conio.h */ ) _gettch();   _gettch();  
//                 break;
//             }
//             case 2:
//             {
//                 ft.readTXT(*tempbook,"../data");
//                 std::cout<<"\n������ ��������!\n";
//                 while( _kbhit() /* defined in conio.h */ ) _gettch();   _gettch();  
//                 break;
//             }
//             case 3:
//             {
//                 if(tempbook->is_empety()) std::cout<<"������� �������� ������!\n";
//                 for(int i = 0; i <  tempbook->booksVector.size(); i++)
//                     std::cout << i+1 << " - " << tempbook->booksVector[i].getAuthor() << "\n";
//                 int r ;
//                 cin >> r;
//                 // if(!isdigit(r)) cout<<"Down?";
//                 if(r < 0 || r > tempbook->booksVector.size()) 
//                 {
//                     cout<<"��� ������ ������!";
//                     Sleep(500);
//                     continue;
//                 }
//                 printf("\n%d)�����: %s - %s, ���������� � %d ����. ������� ��������: %s. ���������: %d",
//                     r,
//                     tempbook->booksVector.at(r-1).getAuthor(),
//                     tempbook->booksVector.at(r-1).getNameBook(),
//                     tempbook->booksVector.at(r-1).getDate(),
//                     tempbook->booksVector.at(r-1).getDescription(),
//                     tempbook->booksVector.at(r-1).getPrice()
//                 );
//                 while( _kbhit() /* defined in conio.h */ ) _gettch();   _gettch();  
//             }
//             default:
            
//                 break;
//         }
//     }
//     delete tempbook;
//     return 0;
// }
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
