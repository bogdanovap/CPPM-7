#include <iostream>
#include "library\library.h"

int main() {
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;

    CGreeter greeter;

    std::cout << greeter.greet(name) << std::endl;

    return 0;
}
