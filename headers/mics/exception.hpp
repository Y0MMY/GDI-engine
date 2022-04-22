#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>

class MyException: public std::exception
{
private:
    std::string msg;
    short code;
public:
    typedef enum
    {
        UNKNOWN_ERROR = 0,
        CREATE_REGISTER_ERROR,
        CREATE_WINDOW_ERROR
    } WindowErrors;
    MyException(std::string msg, short code);
    ~MyException() = default;
    const char* what() const noexcept override;
    const char* codeError() const noexcept;
};




#endif // __EXCEPTION_H__