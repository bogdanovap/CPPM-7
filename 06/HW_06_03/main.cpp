#include <iostream>

#include "CFigure.h"
#include "CTriangle.h"
#include "CQuadrilateral.h"


void print_info(CFigure *figure){
    figure->print_info();
}

int main() {
    auto figure = CFigure();
    print_info(&figure);

    auto triangle = CTriangle(10,20,30,50,60, 70);
    print_info(&triangle);

    auto square_triangle = CSquareTriangle(10,20,30,50,60);
    print_info(&square_triangle);

    auto isosceles = CIsoscelesTriangle(10,20,50,60);
    print_info(&isosceles);

    auto equilateral = CEquilateralTriangle(30);
    print_info(&equilateral);

    auto quadrilateral = CQuadrilateral(10, 20, 30, 40, 50 ,60, 70, 80);
    print_info(&quadrilateral);

    auto rectangle = CRectangle(10, 20);
    print_info(&rectangle);

    auto square = CSquare(20);
    print_info(&square);

    auto parallelogram = CParallelogram(20, 30, 30, 40);
    print_info(&parallelogram);

    auto rhombus = CRhombus(30, 30, 40);
    print_info(&rhombus);

    return 0;
}
