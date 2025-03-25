#pragma once  // Protect from multiple include in one file
#include <vector> // Allows changing lenght, without creating new array
#include <iostream>
#include <limits>   // for constructor, allows to set Not a Number
#include <stdexcept> // for exceptions
#include <cmath> // for square root (sqrt)

class vec_n {
private:
    std::vector<double> elements;
    bool is_defined;
public:
    // Konstruktory
    vec_n(size_t n);
    vec_n(const std::vector<double>& values);

    // Metody
    void is_fully_defined();
    double length(void) const;
    size_t size(void) const;
    vec_n operator+(const vec_n& v) const;
    vec_n scalar_multiply(double s) const;
    void print() const;
    double operator*(const vec_n& v) const;
    bool is_parallel(const vec_n& v) const;
};