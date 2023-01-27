#include <iostream>
#include <string>

using namespace std;

//Создайте структуру для хранения информации о банковском счёте. Она должна хранить
// номер счёта (целое число),
// имя владельца (строка) и
// количество денег на счету (дробное число).
struct AccountStruct {
    int number;
    string holder_name;
    double balance;
};

//Создайте функцию для изменения баланса счёта.
//Функция должна принимать экземпляр структуры банковского счёта и новую сумму.
double balance_update (AccountStruct &account, double balance_new){
    account.balance = balance_new;
    return account.balance;
}

//Попросите пользователя
// заполнить поля экземпляра структуры,
// сообщить новый баланс счёта и
// выведите обновлённый экземпляр структуры на консоль.

int main() {
    AccountStruct account;
    cout << "Введите номер счёта: ";
    cin >> account.number;
    cout << "Введите имя владельца: ";
    cin >> account.holder_name;
    cout << "Введите баланс: ";
    cin >> account.balance;

    double balance_new = 0;;
    cout << "Введите новый баланс: ";
    cin >> balance_new;
    balance_update(account, balance_new);

    //Ваш счёт: Андрей, 123456789, 6000
    cout << "Ваш счёт: " << account.holder_name << ", " << account.number << ", " << account.balance << endl;

    return 0;
}
