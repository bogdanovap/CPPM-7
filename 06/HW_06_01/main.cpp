#include <iostream>
#include <string>

#include "calculator.h"

using namespace std;

int main() {
    int number_1, number_2, operation;
    string operations[5] = {" плюс "," минус "," умножить на "," разделить на "," в степени "};

    cout << "Введите первое число: ";
    cin >> number_1;

    cout << "Введите второе число: ";
    cin >> number_2;

    cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    cin >> operation;

    int result_value = 0;
    auto result = calculate(number_1, number_2, operation, result_value);
    if (result) {
        cout << number_1 << operations[operation - 1] << number_2 << " = " << result_value << endl;
    }

    return 0;
}
