#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <tchar.h>
#include <conio.h>
#include <fstream>
using namespace std;    
class Books
{
private:
    int realeseDate;
    int price;
    std::string author;
    std::string name;
    std::string description;
public:
    int& getDate();
    int& getPrice();
    std::string& getAuthor();
    std::string& getNameBook();
    std::string& getDescription();
    static int booksCount;
    Books() = default;
    Books(std::string author,std::string name,std::string description,int price, int realeseDate);
    ~Books();
    vector<Books> books; 
    // friend std::ostream& operator<< (std::ostream &out, const Books &book);
};



// std::ostream& operator<< (ostream& s,const Books &book){

//     return  
//     (s << "-----------------------\nAuthor: " << book.author <<
//         "Book name: " << book.name <<
//         "Description: " << book.description <<
//         "Price:" << book.price << "P" <<
//         "Realese day: " << book.realeseDate); 
// }

Books::Books(std::string author,std::string name,std::string description,int price, int realeseDate)
{
    ++booksCount;
    this->realeseDate = realeseDate;
    this->price = price;
    this->author = author;
    this->name = name;
    this->description = description;
}

Books::~Books()
{
    --booksCount;
}
int& Books::getDate()
{
    return realeseDate;
}
int& Books::getPrice()
{
    return price;
}
std::string& Books::getAuthor()
{
    return author;
}
std::string& Books::getNameBook()
{
    return name;
}
std::string& Books::getDescription()
{
    return description;
}
//===========================================================================
class FileTXT: public Books
{
private:
    /* data */
public:
    FileTXT(/* args */) = default;
    ~FileTXT();
    void writeTXT(const Books& book);
    void readTXT(Books& book);
};

void FileTXT::writeTXT(const Books& book)
{
    fstream myfile;
    std::string fileName = "../books.txt";
    try
    {
        myfile.open(fileName, fstream::in | fstream::out | fstream::app);
        printf("File has been opened!\n");
        // myfile.write((char*)&book,sizeof(Books));
        myfile._M_write((char*)&book,sizeof(Books));
    }
    catch(const std::ofstream::failure& e)
    {
        std::cerr << e.code() << '\n';
    }
    myfile.close();
}   
void FileTXT::readTXT(Books& book)
{
    ifstream myfile;
    std::string fileName = "../books.txt";
    try
    {
        myfile.open(fileName);
        printf("File has been opened for read!\n");
        // myfile.read((char*)&book,sizeof(Books));
        myfile.readsome((char*)&book,sizeof(Books));
        std::cout << book.getDescription();
    
    }
    catch(const std::ofstream::failure& e)
    {
        std::cerr << e.code() << '\n';
    }
    myfile.close();
}

// FileTXT::FileTXT():Books()
// {
    
// }

FileTXT::~FileTXT()
{
}
//===========================================================================
int Books::booksCount = 0;
int main(int argc, char* argv[]) {
      
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    Books* book = new Books ("AHAHAH","Kak viebat telok","Транхни суку за секунду)",2222222,11111);
    // delete book;
    // books.push_back(*book);
    // std::cout<<books[0].getAuthor() << endl;
    // book = new Books("Sanya Labya","Kak viebat telok","Транхни суку за секунду)",2000,2022);
    // books.push_back(*book);
    // std::cout<<books[1].getAuthor() << endl;
    bool open = true;
    int input;
    FileTXT ft;
    while (open)
    {
        system("cls");
        printf("1) Записать объект класса\n");
        printf("2) Прочитать объект класса\n");
        cin >> input;
        if(input < 1 || input > 2) continue;
        switch (input)
        {
            case 1:
                ft.writeTXT(*book);
                std::cout<<"Объект записан!\n";
                cin.get();
                break;
            case 2:
            {
                Books *b = new Books();
                ft.readTXT(*b);
                std::cout<<b->getAuthor();  
                std::cout<<"\nОбъект прочитан!\n";
                while( _kbhit() /* defined in conio.h */ ) _gettch();
               _gettch();
                delete b;
                break;
            }
            default:
            
                break;
        }
    }
    delete book;
    return 0;
}