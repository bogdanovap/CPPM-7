#include <iostream>

// Предметная область выглядит следующим образом: есть сущность фигура.
// Фигуры бывают двух типов: треугольник и четырёхугольник.
// У фигуры есть количество сторон. Для неизвестной фигуры будем считать это количество равным нулю.
// У треугольника три стороны, у четырёхугольника четыре стороны.
// У любой фигуры мы хотим узнавать количество её сторон,
// но мы не должны быть способны изменить количество сторон для заданной фигуры извне.
//
// Задача: спроектировать и реализовать классы, описывающие предметную область.
// Продемонстрируйте их работу: создайте по одному экземпляру каждого класса
// и выведите информацию о количестве его сторон на консоль.


class CFigure{
public:
    CFigure(int nb_sides=0) {this->nb_sides=nb_sides;};
    int get_sides_number(){return nb_sides;};
protected:
    int nb_sides;
};

class CTriangle : public CFigure{
public:
    CTriangle() : CFigure(3){};
};

class CQuadrilateral :public CFigure{
public:
    CQuadrilateral() : CFigure(4){};
};

int main() {
    auto figure = CFigure();
    auto triangle = CTriangle();
    auto quadrilateral = CQuadrilateral();

    std::cout << "Количество сторон:" << std::endl;
    std::cout << "Фигура: " << figure.get_sides_number() << std::endl;
    std::cout << "Треугольник: " << triangle.get_sides_number() << std::endl;
    std::cout << "Четырёхугольник: " << quadrilateral.get_sides_number() << std::endl;

    return 0;
}
