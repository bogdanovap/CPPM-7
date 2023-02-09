#include <iostream>
#include <cmath>

bool calculate(int number_1, int number_2, int operation, int &res) {
    res = 0;
    switch (operation) {
        case 1:
            // 1 - сложение,
            res = number_1 + number_2;
            break;
        case 2:
            // 2 вычитание,
            res = number_1 - number_2;
            break;
        case 3:
            // 3 - умножение,
            res = number_1 * number_2;
            break;
        case 4:
            // 4 - деление,
            if (number_2==0) {
                std::cout << "Деление на 0" << std::endl;
                return false;
            }
            res = number_1 / number_2;
            break;
        case 5:
            // 5 - возведение в степень
            res = pow(number_1, number_2);
            break;
        default:
            std::cout << "Операция не найдена" << std::endl;
            return false;
    }
    return true;
}