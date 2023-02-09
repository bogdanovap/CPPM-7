#include <iostream>
#include "CCounter.h"

using namespace std;


int main() {
    std::string set_start_number;

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> set_start_number;

    int start_number = 1;
    if (set_start_number=="да"){
        cout << "Введите начальное значение счётчика: ";
        cin >> start_number;
    }

    auto counter = CCounter(start_number);

    char command;
    while (true) {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> command;
        if (!counter.execute_command(command)) break;
    }

    cout << "До свидания!" << endl;

    return 0;
}
