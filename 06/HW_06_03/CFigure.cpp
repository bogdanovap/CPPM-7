#include <iostream>

#include "CFigure.h"


CFigure::CFigure(int nb_sides) {this->nb_sides=nb_sides; init_arrays();  sum_corners=0;};
CFigure::~CFigure() {delete [] sides; delete [] corners;};

int CFigure::get_sides_number(){return nb_sides;};

std::string CFigure::get_sides() {
    std::string res = "Стороны";
    for (int i=0;i<nb_sides;i++){
        res += " ";
        res.push_back(char(97+i));
        res += "=" + std::to_string(sides[i]);
    }
    return res;
}

std::string CFigure::get_corners() {
    std::string res = "Углы";
    for (int i=0;i<nb_sides;i++){
        res += " ";
        res.push_back(char(97+i));
        res += "=" + std::to_string(corners[i]);
    }
    return res;
};

bool CFigure::check_corners() {
    int sum=0;
    for (int i=0;i<nb_sides;i++) sum += corners[i];
    return (sum == sum_corners);
}

void CFigure::validate() {
    if (!check_corners()) {
        std::cout << "Неправильная" << std::endl;
        return;
    };
    std::cout << "Правильная" << std::endl;
};

void CFigure::print_info_base() {
    validate();
    std::cout << "Количество сторон: " << nb_sides << std::endl;
    if (nb_sides==0) return;
    std::cout << get_sides() << std::endl;
    std::cout << get_corners() << std::endl;
};

void CFigure::print_info() {
    std::cout << "Фигура" << std::endl;
    print_info_base();
    std::cout << std::endl;
};

