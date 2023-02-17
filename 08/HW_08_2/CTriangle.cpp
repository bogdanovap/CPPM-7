#include <iostream>
#include "CTriangle.h"
#include "CFigureError.h"

CTriangle::CTriangle(int a, int b, int c, int A, int B, int C) : CFigure(3) {
        sides[0]=a;
        sides[1]=b;
        sides[2]=c;
        corners[0]=A;
        corners[1]=B;
        corners[2]=C;
        sum_corners=180;
        check_corners();
        check_sides();
    };

bool CTriangle::check_corners() {
    if (corners[0] + corners[1] + corners[2] != sum_corners) {
        throw CFigureError("Сумма углов не равна 180");
    }
    return true;
}
bool CTriangle::check_sides() {
    if (nb_sides!=3) {
        throw CFigureError("Количество сторон не равно 3");
    }
    return true;
}

void CTriangle::print_info() {
        std::cout << "Треугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };

//прямоугольный треугольник (угол C всегда равен 90);
CSquareTriangle::CSquareTriangle(int a, int b, int c, int A, int B) : CTriangle(a,b,c,A,B,80) {
    check_corners();
};
void CSquareTriangle::print_info() {
    std::cout << "Прямоугольный треугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
bool CSquareTriangle::check_corners() {
    if (corners[2] != 90) {
        throw CFigureError("Угол C не равен 90");
    }
    return true;
};

// равнобедренный треугольник (стороны a и c равны, углы A и C равны);
CIsoscelesTriangle::CIsoscelesTriangle(int a, int b, int A, int B) : CTriangle(a,b,a,A,B,A) {
    check_sides();
    check_corners();
};
void CIsoscelesTriangle::print_info() {
    std::cout << "Равнобедренный треугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
bool CIsoscelesTriangle::check_corners() {
    if (corners[0] != corners[2]) {
        throw CFigureError("Углы A и C не равны");
    }
    return true;
};
bool CIsoscelesTriangle::check_sides() {
    if (sides[0] != sides[2]) {
        throw CFigureError("Стороны a и c не равны");
    }
    return true;
};

// равносторонний треугольник (все стороны равны, все углы равны 60);
CEquilateralTriangle::CEquilateralTriangle(int a) : CTriangle(a,a,a,60,60,60) {
    check_sides();
    check_corners();
};
void CEquilateralTriangle::print_info() {
    std::cout << "Равносторонний треугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
bool CEquilateralTriangle::check_corners() {
    if (corners[0] != 60 || corners[1] != 60 || corners[2] != 60) {
        throw CFigureError("Углы не равны 60");
    }
    return true;
};
bool CEquilateralTriangle::check_sides() {
    if (sides[0] != sides[1] || sides[0] != sides[2] || sides[1] != sides[2]) {
        throw CFigureError("Стороны не равны");
    }
    return true;
};