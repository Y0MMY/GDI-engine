#include "../../headers/mics/exception.hpp"

MyException::MyException(std::string msg, short code):std::exception()
{
    this->msg = msg;
    this->code = code;
}
const char* MyException::what() const noexcept
{
        return msg.c_str();
}
const char* MyException::codeError() const noexcept{
    switch(code)
    {
        case 0:
            return "Code: 0 (Unknown error)";
        break;
        case 1:
            return "Code: 1 (CREATE_REGISTER_ERROR)";
        break;
        case 2:
            return "Code: 2 (CREATE_WINDOW_ERROR)";
        break;
    }
    return "-1";
}