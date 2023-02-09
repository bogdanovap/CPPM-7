//
// Created by bogda on 09.02.2023.
//

#ifndef HW_06_03_CQUADRILATERAL_H
#define HW_06_03_CQUADRILATERAL_H

#include "CFigure.h"

class CQuadrilateral : public CFigure{
public:
    CQuadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    void print_info() override;
};

// - прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
class CRectangle : public CQuadrilateral {
public:
    CRectangle(int a, int b);
    void print_info() override;
};

// - квадрат (все стороны равны, все углы равны 90);
class CSquare : public CRectangle {
public:
    CSquare(int a);
    void print_info() override;
};

// - параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
class CParallelogram : public CQuadrilateral {
public:
    CParallelogram(int a, int b, int A, int B);
    void print_info() override;
};

// - ромб (все стороны равны, углы A,C и B,D попарно равны).
class CRhombus : public CQuadrilateral {
public:
    CRhombus(int a, int A, int B);
    void print_info() override;
};


#endif //HW_06_03_CQUADRILATERAL_H
