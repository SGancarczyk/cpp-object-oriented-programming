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
    vec_n(size_t n);
    vec_n(const std::vector<double>& values);
    ~vec_n();


    void is_fully_defined();
    double length(void) const;
    size_t size(void) const;
    vec_n operator+(const vec_n& v) const;
    vec_n scalar_multiply(double s) const;
    void print() const;
    double operator*(const vec_n& v) const;
    bool is_parallel(const vec_n& v) const;
    int compare(const vec_n& v);
    double get_element(const int elem_no) const;
    double dot_product(const vec_n& v) const;
    void saveToFile(const std::string& filename) const;
    static vec_n loadFromFile(const std::string& filename);
    // vec_n add(const vec_n& v) const;  Implemented but put in commment section - i think it isnt important as there is operator+ method

};