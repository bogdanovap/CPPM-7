//
// Created by bogda on 09.02.2023.
//
#include <iostream>
#include "CQuadrilateral.h"

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
};
void CQuadrilateral::print_info() {
    std::cout << "Четырёхугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};

// - прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
CRectangle::CRectangle(int a, int b) : CQuadrilateral(a, b, a, b, 90, 90, 90, 90){};
void CRectangle::print_info() {
    std::cout << "Прямоугольник" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};

// - квадрат (все стороны равны, все углы равны 90);
CSquare::CSquare(int a) : CRectangle(a, a){};
void CSquare::print_info()  {
    std::cout << "Квадрат" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};

// - параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
CParallelogram::CParallelogram(int a, int b, int A, int B) : CQuadrilateral(a, b, a, b, A, B, A, B){};
void CParallelogram::print_info() {
    std::cout << "Параллелограмм" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};

// - ромб (все стороны равны, углы A,C и B,D попарно равны).
CRhombus::CRhombus(int a, int A, int B) : CQuadrilateral(a, a, a, a, A, B, A, B){};
void CRhombus::print_info() {
    std::cout << "Ромб" << std::endl;
    CFigure::print_info_base();
    std::cout << std::endl;
};