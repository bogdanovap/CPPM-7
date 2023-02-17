#include <iostream>

#ifndef HW_08_2_CFIGUREERROR_H
#define HW_08_2_CFIGUREERROR_H

class CFigureError : public std::domain_error{
public:
    CFigureError(const char* message);

};

#endif //HW_08_2_CFIGUREERROR_H
