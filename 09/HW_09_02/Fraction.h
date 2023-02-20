//
// Created by bogda on 20.02.2023.
//

#ifndef HW_09_02_FRACTION_H
#define HW_09_02_FRACTION_H


class Fraction {
private:
    int numerator_;
    int denominator_;
    int get_nod(int a, int b);
public:
    Fraction(int numerator, int denominator);
    void reduce_fraction();

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);

    Fraction operator+(const Fraction& rhs) const;
    Fraction operator-(const Fraction& rhs) const;
    Fraction operator*(const Fraction& rhs) const;
    Fraction operator/(const Fraction& rhs) const;
    Fraction operator-() const;
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);

    bool operator==(const Fraction& rhs) const;
    bool operator!=(const Fraction& rhs) const;
    bool operator<(const Fraction& rhs) const;
    bool operator>(const Fraction& rhs) const;
    bool operator<=(const Fraction& rhs) const;
    bool operator>=(const Fraction& rhs) const;

};


#endif //HW_09_02_FRACTION_H
