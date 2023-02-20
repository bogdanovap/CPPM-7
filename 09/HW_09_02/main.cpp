#include <iostream>
#include "Fraction.h"

int main()
{

    int f1_num, f1_denom, f2_num, f2_denom;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> f1_num;
    std::cout << "Введите знаменатель дроби 1:  ";
    std::cin >> f1_denom;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> f2_num;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> f2_denom;

    Fraction f1(f1_num, f1_denom);
    Fraction f2(f2_num, f2_denom);

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << std::endl;
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << std::endl;

    std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << std::endl;
    std::cout << "Значение дроби 1 " << " = " << f1 << std::endl;
    std::cout << f1 << "-- * " << f2 << " = " << (f1-- * f2) << std::endl;
    std::cout << "Значение дроби 1 " << " = " << f1 << std::endl;

    return 0;
}