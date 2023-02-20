//
// Created by bogda on 20.02.2023.
//
#include <iostream>
#include "Fraction.h"


int Fraction::get_nod(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}

Fraction::Fraction(int numerator, int denominator)
{
    numerator_ = numerator;
    denominator_ = denominator;
}

void Fraction::reduce_fraction() {
    int nod = get_nod(std::abs(numerator_), std::abs(denominator_));
    numerator_ /= nod;
    denominator_ /= nod;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f){
    out << f.numerator_ << "/" << f.denominator_;
    return out;
}

Fraction Fraction::operator+(const Fraction& rhs) const{
    auto temp = Fraction(numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_, denominator_ * rhs.denominator_);
    temp.reduce_fraction();
    return temp;
}

Fraction Fraction::operator-(const Fraction& rhs) const{
    auto temp = Fraction(numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_, denominator_ * rhs.denominator_);
    temp.reduce_fraction();
    return temp;
}

Fraction Fraction::operator*(const Fraction& rhs) const{
    auto temp = Fraction(numerator_ * rhs.numerator_, denominator_ * rhs.denominator_);
    temp.reduce_fraction();
    return temp;
}

Fraction Fraction::operator/(const Fraction& rhs) const{
    auto temp = Fraction(numerator_ * rhs.denominator_, denominator_ * rhs.numerator_);
    temp.reduce_fraction();
    return temp;
}

Fraction Fraction::operator-() const{
    return Fraction(-numerator_, denominator_);
}

Fraction Fraction::operator++(){
    numerator_ += denominator_;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(){
    numerator_ -= denominator_;
    return *this;
}

Fraction Fraction::operator--(int){
    Fraction temp = *this;
    --(*this);
    return temp;
}

bool Fraction::operator==(const Fraction& rhs) const{
    return numerator_ * rhs.denominator_ ==  denominator_ * rhs.numerator_;
}

bool Fraction::operator!=(const Fraction& rhs) const{
    return !(*this == rhs);
}
bool Fraction::operator<(const Fraction& rhs) const{
    return ((float) numerator_ / (float)denominator_) <  ((float) rhs.numerator_ / (float) rhs.denominator_);
}
bool Fraction::operator>(const Fraction& rhs) const{
    return !(*this < rhs) && !(*this == rhs);
}

bool Fraction::operator<=(const Fraction& rhs) const{
    return (*this < rhs) || (*this == rhs);
}

bool Fraction::operator>=(const Fraction& rhs) const
{
    return !(*this < rhs) || (*this == rhs);
}

