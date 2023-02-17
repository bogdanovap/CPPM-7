//В этом задании вы запретите создавать экземпляры классов геометрических фигур с неправильными данными.
//
//Создайте собственный класс исключения для ошибки создания геометрической фигуры.
// Подумайте, от какого типа его унаследовать, и не забудьте поместить новый класс в отдельную пару файлов.
//
//Возьмите иерархию классов из предыдущего задания.
// Теперь при создании экземпляров классов вам нужно проверять аргументы, которые поступают на вход конструктору.
// Если аргументы не соответствуют ограничениям, объект не должен быть создан,
// на консоль должно быть выведено соответствующее сообщение.
// Причина ошибки должна быть сформулирована на уровне конструктора и выведена на экран при обработке ошибок.
//
//Ограничения:
// - треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
// - прямоугольный треугольник (угол C всегда равен 90);
// - равнобедренный треугольник (стороны a и c равны, углы A и C равны);
// - равносторонний треугольник (все стороны равны, все углы равны 60);

// - четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
// - прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
// - квадрат (все стороны равны, все углы равны 90);
// - параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
// - ромб (все стороны равны, углы A,C и B,D попарно равны).

//Для проверки попробуйте создать разные геометрические фигуры — правильные и неправильные.
// В случае успешного создания выводите на экран сообщение об успешном создании и параметры фигуры.
// В случае, если создание не удалось, выведите причину ошибки.


#include <iostream>

#include "CFigure.h"
#include "CTriangle.h"
#include "CQuadrilateral.h"
#include "CFigureError.h"


void print_info(CFigure *figure){
    figure->print_info();
}

int main() {

    try{
        auto triangle = CTriangle(10,20,30,50,60, 70);
        print_info(&triangle);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        auto square_triangle = CSquareTriangle(10,20,50,45,55);
        print_info(&square_triangle);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        auto isosceles = CIsoscelesTriangle(10,20,50,60);
        print_info(&isosceles);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        auto equilateral = CEquilateralTriangle(30);
        print_info(&equilateral);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }


    try{
        auto quadrilateral = CQuadrilateral(10, 20, 30, 40, 50 ,60, 70, 80);
        print_info(&quadrilateral);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }


    try{
        auto rectangle = CRectangle(10, 20);
        print_info(&rectangle);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        auto square = CSquare(20);
        print_info(&square);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        auto parallelogram = CParallelogram(20, 30, 30, 40);
        print_info(&parallelogram);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        auto rhombus = CRhombus(30, 30, 150);
        print_info(&rhombus);
    } catch (CFigureError &e){
        std::cout << "Ошибка создания фигуры: ";
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
