#include <iostream>

//У вас появляется информация о длине сторон и углах ваших фигур,
// а также несколько более конкретных фигур.
// Теперь в треугольнике вы должны хранить информацию о длине всех его трёх сторон (a, b, c) и
// значениях его трёх углов (A, B, C).
// В четырёхугольнике вы храните информацию о длине его четырёх сторон (a, b, c, d) и
// значениях его четырёх углов (A, B, C, D).
//
// Также у вас появляются более конкретные фигуры://
// - прямоугольный треугольник (угол C всегда равен 90);
// - равнобедренный треугольник (стороны a и c равны, углы A и C равны);
// - равносторонний треугольник (все стороны равны, все углы равны 60);
// - прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
// - квадрат (все стороны равны, все углы равны 90);
// - параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
// - ромб (все стороны равны, углы A,C и B,D попарно равны).
//
// Вы должны иметь возможность узнать у каждой фигуры длины её сторон и значения её углов,
// но извне вы не должны быть способны изменить длины сторон и углы.
//
// Не должно быть возможности создать фигуры, не удовлетворяющие перечисленным условиям.
// Например, нельзя создать квадрат с разными углами. Геометрические соотношения проверять не нужно.
// Например, сумма углов в треугольнике может быть не равна 180.
//
// Задача: спроектировать и реализовать классы, описывающие предметную область.
// Продемонстрируйте их работу: создайте по одному экземпляру каждой фигуры
// и выведите на экран информацию о длинах её сторон и величине её углов.
// Значения используйте произвольные.
//
// Инициализацию длин сторон и величин углов нужно выполнить с помощью вызова базовых конструкторов.
//
// Для вывода информации о фигуре создайте функцию print_info,
// которая будет принимать в качестве аргумента указатель на базовый класс фигуры.


class CFigure{
public:
    CFigure(int nb_sides=0) {this->nb_sides=nb_sides; init_arrays();};
    int get_sides_number(){return nb_sides;};
    void print_info();
protected:
    void init_arrays(){sides = new int[nb_sides]; corners = new int[nb_sides];};
    int nb_sides;
    int* sides;
    int* corners;
};

void CFigure::print_info() {
    if (nb_sides==0) return;
    std::cout << "Стороны:";
    for (int i=0;i<nb_sides;i++){
        std::cout << " " << char(97+i) << "=" << sides[i];
    }
    std::cout << std::endl;
    std::cout << "Углы:";
    for (int i=0;i<nb_sides;i++){
        std::cout << " " << char(65+i) << "=" << corners[i];
    }
    std::cout << std::endl;
}

class CTriangle : public CFigure{
public:
    CTriangle(int a, int b, int c, int A, int B, int C) : CFigure(3) {
        sides[0]=a;
        sides[1]=b;
        sides[2]=c;
        corners[0]=A;
        corners[1]=B;
        corners[2]=C;
    };
};

//прямоугольный треугольник (угол C всегда равен 90);
class CSquareTriangle : public CTriangle{
public:
    CSquareTriangle(int a, int b, int c, int A, int B) : CTriangle(a,b,c,A,B,90) {};
};

// равнобедренный треугольник (стороны a и c равны, углы A и C равны);
class CIsoscelesTriangle : public CTriangle{
public:
    CIsoscelesTriangle(int a, int b, int A, int B) : CTriangle(a,b,a,A,B,A) {};
};

// равносторонний треугольник (все стороны равны, все углы равны 60);
class CEquilateralTriangle : public CTriangle{
public:
    CEquilateralTriangle(int a) : CTriangle(a,a,a,60,60,60) {};
};


class CQuadrilateral : public CFigure{
public:
    CQuadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : CFigure(4) {
        sides[0]=a;
        sides[1]=b;
        sides[2]=c;
        sides[3]=d;
        corners[0]=A;
        corners[1]=B;
        corners[2]=C;
        corners[3]=D;
    };
};

// - прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
class CRectangle : public CQuadrilateral {
public:
    CRectangle(int a, int b) : CQuadrilateral(a, b, a, b, 90, 90, 90, 90){};
};

// - квадрат (все стороны равны, все углы равны 90);
class CSquare : public CRectangle {
public:
    CSquare(int a) : CRectangle(a, a){};
};

// - параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
class CParallelogram : public CQuadrilateral {
public:
    CParallelogram(int a, int b, int A, int B) : CQuadrilateral(a, b, a, b, A, B, A, B){};
};

// - ромб (все стороны равны, углы A,C и B,D попарно равны).
class CRhombus : public CQuadrilateral {
public:
    CRhombus(int a, int A, int B) : CQuadrilateral(a, a, a, a, A, B, A, B){};
};



int main() {
    std::cout << "Треугольник:" << std::endl;
    auto triangle = CTriangle(10,20,30,50,60, 70);
    triangle.print_info();
    std::cout << std::endl;

    std::cout << "Прямоугольный треугольник:" << std::endl;
    auto square_triangle = CSquareTriangle(10,20,30,50,60);
    square_triangle.print_info();
    std::cout << std::endl;

    std::cout << "Равнобедренный треугольник:" << std::endl;
    auto isosceles = CIsoscelesTriangle(10,20,50,60);
    isosceles.print_info();
    std::cout << std::endl;

    std::cout << "Равносторонний треугольник:" << std::endl;
    auto equilateral = CEquilateralTriangle(30);
    equilateral.print_info();
    std::cout << std::endl;

    std::cout << "Четырёхугольник:" << std::endl;
    auto quadrilateral = CQuadrilateral(10, 20, 30, 40, 50 ,60, 70, 80);
    quadrilateral.print_info();
    std::cout << std::endl;

    std::cout << "Прямоугольник:" << std::endl;
    auto rectangle = CRectangle(10, 20);
    rectangle.print_info();
    std::cout << std::endl;

    std::cout << "Квадрат:" << std::endl;
    auto square = CSquare(20);
    square.print_info();
    std::cout << std::endl;

    std::cout << "Параллелограмм:" << std::endl;
    auto parallelogram = CParallelogram(20, 30, 30, 40);
    parallelogram.print_info();
    std::cout << std::endl;

    std::cout << "Ромб:" << std::endl;
    auto rhombus = CRhombus(30, 30, 40);
    rhombus.print_info();
    std::cout << std::endl;

    return 0;
}
