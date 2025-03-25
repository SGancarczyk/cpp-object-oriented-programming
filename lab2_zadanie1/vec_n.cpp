// vec_n.cpp
#include "vec_n.hpp"

// Constructor initializing a vector with default values
vec_n::vec_n(size_t n) : elements(n, std::numeric_limits<double>::quiet_NaN()), is_defined(false) {}

// Constructor initializing a vector with given values
vec_n::vec_n(const std::vector<double>& values) : elements(values), is_defined(true) {}

// Checking if a vector is fully defined
void vec_n::is_fully_defined()  {
    for (double val : elements) {
        if (std::isnan(val)) {
            is_defined = false;
            break;
        }
    }
    is_defined = true;
}

// Returns vector size
double vec_n::length(void){
    double result = 0;
    for(int i=0; i < elements.size(); i++){
        result += (elements[i]*elements[i]);
    }
}

// Two vector addition operator
vec_n vec_n::operator+(const vec_n& v) const {  // Using operator overload to allow operations on class objects
    if (elements.size() != v.size()) {
        throw std::invalid_argument("Vectors have different sizes!");
    }
    else if (!is_defined){
        throw std::invalid_argument("Vector isn't fully defined.");
    }
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); i++) {  // Using size_t as elements.size() also returns size_t
        result[i] = elements[i] + v.elements[i];
    }
    return vec_n(result);
}

// Multiplaying a vector by a scalar (returns new vector)
vec_n vec_n::scalar_multiply(double s) const {
    if (!is_defined){
        throw std::invalid_argument("Vector isn't fully defined.");
    }
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); i++) {
        result[i] = elements[i] * s;
    }
    return vec_n(result);
}

// Displaying vector
void vec_n::print() const {
    if (!is_defined) {
        throw std::invalid_argument("Vector isn't fully defined.");
    }
    std::cout << "Wektor: ";
    for (double val : elements) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Returns the dot product of two vectors
double vec_n::operator*(const vec_n& v){
    if (!is_defined) {
        throw std::invalid_argument("Vector isn't fully defined.");
    }


}

bool is_parallel(const vec_n& v){
    if (!is_defined){
        throw std::invalid_argument("Vector isn't fully defined.");
    }

}