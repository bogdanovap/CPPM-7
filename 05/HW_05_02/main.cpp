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
    ~CFigure() {delete [] sides; delete [] corners;};
    int get_sides_number(){return nb_sides;};
    std::string get_sides() {
        std::string res = "Стороны";
        for (int i=0;i<nb_sides;i++){
            res += " ";
            res.push_back(char(97+i));
            res += "=" + std::to_string(sides[i]);
        }
        return res;
    }
    std::string get_corners() {
        std::string res = "Углы";
        for (int i=0;i<nb_sides;i++){
            res += " ";
            res.push_back(char(97+i));
            res += "=" + std::to_string(corners[i]);
        }
        return res;
    };
    void print_info_base() {
        if (nb_sides==0) return;
        std::cout << get_sides() << std::endl;
        std::cout << get_corners() << std::endl;
    };
    virtual void print_info() {
        std::cout << "Фигура" << std::endl;
        print_info_base();
        std::cout << std::endl;
    };
protected:
    void init_arrays(){sides = new int[nb_sides]; corners = new int[nb_sides];};
    int nb_sides;
    int* sides;
    int* corners;
};

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
    void print_info() override {
        std::cout << "Треугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};

//прямоугольный треугольник (угол C всегда равен 90);
class CSquareTriangle : public CTriangle{
public:
    CSquareTriangle(int a, int b, int c, int A, int B) : CTriangle(a,b,c,A,B,90) {};
    void print_info() override {
        std::cout << "Прямоугольный треугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};

// равнобедренный треугольник (стороны a и c равны, углы A и C равны);
class CIsoscelesTriangle : public CTriangle{
public:
    CIsoscelesTriangle(int a, int b, int A, int B) : CTriangle(a,b,a,A,B,A) {};
    void print_info() override {
        std::cout << "Равнобедренный треугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};

// равносторонний треугольник (все стороны равны, все углы равны 60);
class CEquilateralTriangle : public CTriangle{
public:
    CEquilateralTriangle(int a) : CTriangle(a,a,a,60,60,60) {};
    void print_info() override {
        std::cout << "Равносторонний треугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
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
    void print_info() override {
        std::cout << "Четырёхугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};

// - прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
class CRectangle : public CQuadrilateral {
public:
    CRectangle(int a, int b) : CQuadrilateral(a, b, a, b, 90, 90, 90, 90){};
    void print_info() override {
        std::cout << "Прямоугольник" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};

// - квадрат (все стороны равны, все углы равны 90);
class CSquare : public CRectangle {
public:
    CSquare(int a) : CRectangle(a, a){};
    void print_info() override {
        std::cout << "Квадрат" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};

// - параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
class CParallelogram : public CQuadrilateral {
public:
    CParallelogram(int a, int b, int A, int B) : CQuadrilateral(a, b, a, b, A, B, A, B){};
    void print_info() override {
        std::cout << "Параллелограмм" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};

// - ромб (все стороны равны, углы A,C и B,D попарно равны).
class CRhombus : public CQuadrilateral {
public:
    CRhombus(int a, int A, int B) : CQuadrilateral(a, a, a, a, A, B, A, B){};
    void print_info() override {
        std::cout << "Ромб" << std::endl;
        CFigure::print_info_base();
        std::cout << std::endl;
    };
};


void print_info(CFigure *figure){
    figure->print_info();
}

int main() {
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
