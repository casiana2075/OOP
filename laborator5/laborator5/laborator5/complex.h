#pragma once

#include <ostream>

// operatori care trebuie implementati:

// total: 18 operatori  

// op+, op-, op* care iau un numar real TREBUIE sa foloseasca respectivii care iau numere complexe
// eg: op+(Complex, double) va apela op+(Complex, Complex)

class Complex {
  private:
    double real_data;
    double imag_data;

  public:
    Complex();
    Complex(double real, double imag);

    // daca numarul are doar o parte reala
    bool is_real() const;

    double real() const;
    double imag() const;
    // absolutul numarului
    double abs() const;
    // conjugatul
    Complex conjugate() const;

    // 6. op() cu semnificatia de mai jos
    Complex& operator()(double real, double imag);

    // 2. op- unar
    Complex operator-(const Complex& obj);

    // 5. op++ prefixat si postfixat si op-- prefixat si postfixat
    Complex& operator++();
    Complex operator++(int);

    Complex& operator--();
    Complex operator--(int);
};

// 1. op+, op-, op*
// care sa accepte doua numere complexe, un numar complex si un numar real, sau un numar real si un numar complex
// (9 in total)

Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l, const Complex& r);

Complex operator*(const Complex& l, const Complex& r);
Complex operator*(const Complex& l, double r);
Complex operator*(double l, const Complex& r);

Complex operator-(const Complex& l, const Complex& r);
Complex operator-(const Complex& l, double r);
Complex operator-(double l, const Complex& r);


// 3. op== si op!=
bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

// 4. op<< de streamuri pentru afisare
std::ostream& operator<<(std::ostream& out, const Complex& complex);


