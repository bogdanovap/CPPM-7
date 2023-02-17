#include <string>

#ifndef HW_06_03_CFIGURE_H
#define HW_06_03_CFIGURE_H

class CFigure{
public:
    CFigure(int nb_sides=0);
    ~CFigure();
    int get_sides_number();
    std::string get_sides();
    std::string get_corners();
    bool check_corners();
    bool check_sides();
    void validate();
    void print_info_base();
    virtual void print_info();
protected:
    void init_arrays(){sides = new int[nb_sides]; corners = new int[nb_sides];};
    int sum_corners;
    int nb_sides;
    int* sides;
    int* corners;
};

#endif //HW_06_03_CFIGURE_H
