//
// Created by bogda on 09.02.2023.
//

#ifndef HW_06_02_CCOUNTER_H
#define HW_06_02_CCOUNTER_H

class CCounter{
private:
    int counter_value;

public:
    CCounter();
    CCounter(int initial);

    void increase();
    void decrease();
    int current();

    bool execute_command(char command);

};

#endif //HW_06_02_CCOUNTER_H
