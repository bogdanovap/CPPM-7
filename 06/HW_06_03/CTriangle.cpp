#include <iostream>
#include "CTriangle.h"

CTriangle::CTriangle(int a, int b, int c, int A, int B, int C) : CFigure(3) {
        sides[0]=a;
        sides[1]=b;
        sides[2]=c;
        corners[0]=A;
        corners[1]=B;
        corners[2]=C;
        sum_corners=180;
    };
void CTriangle::print_info() {
        std::cout << "Треугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };

//прямоугольный треугольник (угол C всегда равен 90);
CSquareTriangle::CSquareTriangle(int a, int b, int c, int A, int B) : CTriangle(a,b,c,A,B,90) {};
void CSquareTriangle::print_info() {
    std::cout << "Прямоугольный треугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};

// равнобедренный треугольник (стороны a и c равны, углы A и C равны);
CIsoscelesTriangle::CIsoscelesTriangle(int a, int b, int A, int B) : CTriangle(a,b,a,A,B,A) {};
void CIsoscelesTriangle::print_info() {
    std::cout << "Равнобедренный треугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};

// равносторонний треугольник (все стороны равны, все углы равны 60);
CEquilateralTriangle::CEquilateralTriangle(int a) : CTriangle(a,a,a,60,60,60) {};
void CEquilateralTriangle::print_info() {
    std::cout << "Равносторонний треугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};