#ifndef HW_06_03_CTRIANGLE_H
#define HW_06_03_CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure{
public:
    CTriangle(int a, int b, int c, int A, int B, int C);
    void print_info() override;
    bool check_corners();
    bool check_sides();
};

//прямоугольный треугольник (угол C всегда равен 90);
class CSquareTriangle : public CTriangle{
public:
    CSquareTriangle(int a, int b, int c, int A, int B);
    void print_info() override;
    bool check_corners();
};

// равнобедренный треугольник (стороны a и c равны, углы A и C равны);
class CIsoscelesTriangle : public CTriangle{
public:
    CIsoscelesTriangle(int a, int b, int A, int B);
    void print_info() override;
    bool check_corners();
    bool check_sides();
};

// равносторонний треугольник (все стороны равны, все углы равны 60);
class CEquilateralTriangle : public CTriangle{
public:
    CEquilateralTriangle(int a);
    void print_info() override;
    bool check_corners();
    bool check_sides();
};


#endif //HW_06_03_CTRIANGLE_H
