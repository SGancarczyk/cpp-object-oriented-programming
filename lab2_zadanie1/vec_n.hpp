#pragma once  // Zabezpiecza przed wielokrotnym dołączaniem pliku
#include <vector>
#include <iostream>
#include <limits>
#include <stdexcept>

class vec_n {
private:
    std::vector<double> elements;
    bool is_defined;
public:
    // Konstruktory
    vec_n(size_t n);
    vec_n(const std::vector<double>& values);

    // Metody
    void is_fully_defined() ;
    double length(void);
    vec_n operator+(const vec_n& v) const;
    vec_n scalar_multiply(double s) const;
    void print() const;
    double operator*(const vec_n& v);
    bool is_parallel(const vec_n& v);
};