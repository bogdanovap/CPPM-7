#include <iostream>
#include "CLeaver//library.h"

int main() {
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;

    CLeaver leaver;
    std::cout << leaver.leave(name) << std::endl;

    return 0;
}
