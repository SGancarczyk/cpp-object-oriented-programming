#pragma once  // Protect from multiple include in one file
#include <vector> // Allows changing lenght, without creating new array
#include <iostream>
#include <limits>   // for constructor, allows to set Not a Number
#include <stdexcept> // for exceptions
#include <cmath> // for square root (sqrt)
#include <fstream> // for file load/save

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
    vec_n add(const vec_n& v) const;
    void print() const;
    double operator*(const vec_n& v) const;
    bool is_parallel(const vec_n& v) const;
    int compare(const vec_n& v);
    double get_element(const int elem_no) const;
    double dot_product(const vec_n& v) const;
    void saveToFile(const std::string& filename) const;
    static vec_n loadFromFile(const std::string& filename);

};