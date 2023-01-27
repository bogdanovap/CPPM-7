#include <iostream>

using namespace std;

enum class MonthEnum : int {
    january = 1,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december,
};

int main() {
    int month_number = 0;
    while (true) {
        cout << "Введите номер месяца: ";
        cin >> month_number;
        if (month_number == 0) {
            break;
        }
        auto month = static_cast<MonthEnum>(month_number);
        switch(month) {
            case MonthEnum::january:
                cout << "Январь" << endl;
                break;
            case MonthEnum::february:
                cout << "Февраль" << endl;
                break;
            case MonthEnum::march:
                cout << "Март" << endl;
                break;
            case MonthEnum::april:
                cout << "Апрель" << endl;
                break;
            case MonthEnum::may:
                cout << "Май" << endl;
                break;
            case MonthEnum::june:
                cout << "Июнь" << endl;
                break;
            case MonthEnum::july:
                cout << "Июль" << endl;
                break;
            case MonthEnum::august:
                cout << "Август" << endl;
                break;
            case MonthEnum::september:
                cout << "Сентябрь" << endl;
                break;
            case MonthEnum::october:
                cout << "Октябрь" << endl;
                break;
            case MonthEnum::november:
                cout << "Ноябрь" << endl;
                break;
            case MonthEnum::december:
                cout << "Декабрь" << endl;
                break;
            default:
                cout << "Не правильный номер!" << endl;
        }
    }
    cout << "До свидания" << endl;

    return 0;
}
