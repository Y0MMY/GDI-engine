#ifndef __VIRTUALCLASS_H__
#define __VIRTUALCLASS_H__
#include <iostream>
class virtualDOCK //purely virtual class for all *.* docks
{
private:
    /* data */
public:
    virtualDOCK(/* args */) = default;
    ~virtualDOCK() = default;
    virtual uint16_t& getID(void) = 0; //unsigned 16b int (0..65.535)
    virtual bool is_empety(void) const = 0;
};


#endif // __VIRTUALCLASS_H__