//
// Created by bogda on 09.02.2023.
//
#include <iostream>
#include "CQuadrilateral.h"
#include "CFigureError.h"

CQuadrilateral::CQuadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : CFigure(4) {
    sides[0]=a;
    sides[1]=b;
    sides[2]=c;
    sides[3]=d;
    corners[0]=A;
    corners[1]=B;
    corners[2]=C;
    corners[3]=D;
    sum_corners=360;
    check_corners();
    check_sides();
};
void CQuadrilateral::print_info() {
    std::cout << "Четырёхугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
bool CQuadrilateral::check_corners() {
    if (corners[0] + corners[1] + corners[2] + corners[3] != sum_corners) {
        throw CFigureError("Сумма углов не равна 360!");
    }
    return true;
};
bool CQuadrilateral::check_sides() {
    if (nb_sides!=4) {
        throw CFigureError("Количество сторон не равно 4!");
    }
    return true;
};

// - прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
CRectangle::CRectangle(int a, int b) : CQuadrilateral(a, b, a, b, 90, 90, 90, 90){
    check_sides();
    check_corners();
};
void CRectangle::print_info() {
    std::cout << "Прямоугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
bool CRectangle::check_corners() {
    if (corners[0] != 90 || corners[1] != 90 || corners[2] != 90 || corners[3] != 90) {
        throw CFigureError("Не все углы равны 90!");
    }
    return true;
};
bool CRectangle::check_sides() {
    if (sides[0] != sides[2] || sides[1] != sides[3]) {
        throw CFigureError("Не все стороны попарно равны!");
    }
    return true;
};

// - квадрат (все стороны равны, все углы равны 90);
CSquare::CSquare(int a) : CRectangle(a, a){
    check_sides();
};
void CSquare::print_info()  {
    std::cout << "Квадрат" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
bool CSquare::check_sides() {
    if (sides[0] != sides[1] || sides[1] != sides[2] || sides[2] != sides[3]) {
        throw CFigureError("Не все стороны равны!");
    }
    return true;
};

// - параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
CParallelogram::CParallelogram(int a, int b, int A, int B) : CQuadrilateral(a, b, a, b, A, B, A, B){
    check_corners();
    check_sides();
};
void CParallelogram::print_info() {
    std::cout << "Параллелограмм" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
bool CParallelogram::check_corners() {
    if (corners[0] != corners[2] || corners[1] != corners[3]) {
        throw CFigureError("Не все углы попарно равны!");
    }
    return true;
};
bool CParallelogram::check_sides() {
    if (sides[0] != sides[2] || sides[1] != sides[3]) {
        throw CFigureError("Не все стороны попарно равны!");
    }
    return true;
};

// - ромб (все стороны равны, углы A,C и B,D попарно равны).
CRhombus::CRhombus(int a, int A, int B) : CParallelogram(a, a, A, B){
    check_corners();
    check_sides();
};
void CRhombus::print_info() {
    std::cout << "Ромб" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};
