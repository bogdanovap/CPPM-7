#include <iostream>
#include <string>

using namespace std;

//Создайте функцию int function(std::string str, int forbidden_length).
// Эта функция должна возвращать длину переданной строки, если эта длина не равна значению переданного параметра forbidden_length.
// В противном случае она должна выбрасывать исключение bad_length.
//
//Для проверки функции организуйте работу с пользователем.
// В начале задайте запретную длину, а затем считывайте пользовательские строки и выводите их длину до тех пор,
// пока пользователь не введёт строку запретной длины. После этого сообщите ему, что он ввёл строку запретной длины,
// и завершите программу

class bad_length : public exception {
public:
    bad_length(const char* message) {this->message = message;}
    const char* what() const noexcept override {
        return message;
    }
private:
    const char* message;
};

int function(string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length("Вы ввели слово запретной длины!");
    }
    return str.length();
}

int main() {
    int forbidden_length, len;
    string str;
    cout << "Введите запретную длину слова: ";
    cin >> forbidden_length;

    while (true) {
        cout << "Введите слово: ";
        cin >> str;
        try {
            len = function(str, forbidden_length);
            cout << "Длина слова: " << len << endl;
        } catch (const bad_length& e) {
            // слово запретной длины (собственное исключение)
            cout << e.what() << endl;
            break;
        } catch (const exception& e) {
            // неизвестная ошибка
            cout << e.what() << endl;
            break;
        }
    }
    cout << "До свидания!" << endl;
    return 0;
}
