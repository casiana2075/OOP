#include <ostream>
#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex Complex::operator-(const Complex& obj) { 
    return Complex( - obj.real(), -obj.imag());
}

Complex& Complex::operator++() {
    ++real_data;
    return *this;
}
Complex Complex::operator++(int) {
    Complex oldValue = *this;
    operator++();
    return oldValue;
}
Complex& Complex::operator--() {
    --real_data;
    return *this;
}
Complex Complex::operator--(int) {
    Complex oldValue = *this;
    operator--();
    return oldValue;
}
Complex operator+(const Complex& l, const Complex& r) {
    double re = l.real() + r.real();
    double im = l.imag() + r.imag();
    Complex result{ re, im };
    return result;
}

Complex operator+(const Complex& l, double r) {
    double re = l.real() + r;
    double im = 0;
    Complex result{ re, im };
    return result;
}

Complex operator+(double l, const Complex& r) {
    double re = l + r.real();
    double im = 0;
    Complex result{ re, im };
    return result;
}

Complex operator*(const Complex& l, const Complex& r) {
    
    double re = l.real()*r.real() - l.imag()*r.imag();
    double im = l.real() * r.imag() + l.imag() * r.real();
    Complex result{ re, im };
    return result;
}

Complex operator*(const Complex& l, double r) {
    double re = l.real() * r;
    double im = 0;
    Complex result{ re, im };
    return result;
}

Complex operator*(double l, const Complex& r) {
    double re = l * r.real();
    double im = 0;
    Complex result{ re, im };
    return result;
}

Complex operator-(const Complex& l, const Complex& r) {
    double re = l.real() - r.real();
    double im = l.imag() - r.imag();
    Complex result{ re, im };
    return result;
}

Complex operator-(const Complex& l, double r) {
    double re = l.real() - r;
    double im = 0;
    Complex result{ re, im };
    return result;
}

Complex operator-(double l, const Complex& r) {
    double re = l - r.real();
    double im = 0;
    Complex result{ re, im };
    return result;
}

bool operator==(const Complex& l, const Complex& r) {
    return (l.real() == r.real() && l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.real() == 0 && complex.imag() == 0)
        out << 0;
    else if (complex.real() != 0 && complex.imag() == 0)
        out << complex.real();
    else if (complex.real() == 0 && complex.imag() != 0)
        out << complex.imag() << "i";
    else
        out << complex.real() << "+" << complex.imag() << "i";
    return out;
}
