#include <iostream>
#include "CCounter.h"

using namespace std;

CCounter::CCounter() {this->counter_value = 1;};
CCounter::CCounter(int initial) {this->counter_value = initial;};

void CCounter::increase(){
    counter_value++;
}

void CCounter::decrease(){
    counter_value--;
}

int CCounter::current(){
    return counter_value;
}

bool CCounter::execute_command(char command) {
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