#include <iostream>

using namespace std;


class Counter{
private:
    int counter_value;

public:
    Counter() {this->counter_value = 1;};
    Counter(int initial) {this->counter_value = initial;};

    bool execute_command(char command);

    void increase(){
        counter_value++;
    }
    void decrease(){
        counter_value--;
    }
    int current(){
        return counter_value;
    }

};

bool Counter::execute_command(char command) {
    switch(command){
        case '+':
            increase();
            break;
        case '-':
            decrease();
            break;
        case '=':
            cout << current() << endl;
            break;
        case 'x':
            return false;
        default:
            cout << "unknown command" << endl;
            return true;
    }
    return true;
}

int main() {
    std::string set_start_number;

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> set_start_number;

    int start_number = 1;
    if (set_start_number=="да"){
        cout << "Введите начальное значение счётчика: ";
        cin >> start_number;
    }

    auto counter = Counter(start_number);

    char command;
    while (true) {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> command;
        if (!counter.execute_command(command)) break;
    }

    cout << "До свидания!" << endl;

    return 0;
}
