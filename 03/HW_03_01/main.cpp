#include <iostream>

using namespace std;

class Calculator{
private:
    double num1;
    double num2;

public:
    Calculator() {num1 = num2 = 1;}
    // метод должен возвращать результат сложения num1 и num2
    double add() {
        return num1 + num2;
    }
    // метод должен возвращать результат вычитания num2 из num1
    double subtract_1_2() {
        return num1 - num2;
    }
    //метод должен возвращать результат вычитания num1 из num2
    double subtract_2_1() {
        return num2 - num1;
    }

    // метод должен возвращать результат перемножения num1 и num2
    double multiply(){
        return num1 * num2;
    }

    // метод должен возвращать результат деления num1 на num2
    double divide_1_2() {
        if (num2!=0) return num1/num2;
        cout << "Division by zero!" << endl;
        return 0;
    }
    //метод должен возвращать результат деления num2 на num1
    double divide_2_1() {
        if (num1!=0) return num2/num1;
        cout << "Division by zero!" << endl;
        return 0;
    }

    // метод должен установить значение поля num1 равное значению аргумента num1
    // в случае, если значение аргумента не равно 0.
    // Возвращает true, если установка произошла успешно, в обратном случае false
    bool set_num1(double num1=0){
        if (num1 == 0) {
            cout << "Не верный ввод!" << endl;
            return false;
        }
        this->num1 = num1;
        return true;
    }
    // метод должен установить значение поля num2 равное значению аргумента num2
    // в случае, если значение аргумента не равно 0.
    // Возвращает true, если установка произошла успешно, в обратном случае false
    bool set_num2(double num2=0){
        if (num2 == 0)  {
            cout << "Не верный ввод!" << endl;
            return false;
        }
        this->num2 = num2;
        return true;
    }

};

int main() {
    Calculator calc = Calculator();

    double num = 0;
    while (true) {
        cout << "Введите num1: ";
        cin >> num;
        if (calc.set_num1(num)) break;
    }
    while (true) {
        cout << "Введите num2: ";
        cin >> num;
        if (calc.set_num2(num)) break;
    }

//    num1 + num2 = 9
    cout << "num1 + num2 = " << calc.add() << endl;
//    num1 - num2 = -3
    cout << "num1 - num2 = " << calc.subtract_1_2() << endl;
//    num2 - num1 = 3
    cout << "num2 - num1 = " << calc.subtract_2_1() << endl;
//    num1 * num2 = 18
    cout << "num1 * num2 = " << calc.multiply() << endl;
//    num1 / num2 = 0.5
    cout << "num1 / num2 = " << calc.divide_1_2() << endl;
//    num2 / num1 = 2
    cout << "num2 / num1 = " << calc.divide_2_1() << endl;

    return 0;
}
