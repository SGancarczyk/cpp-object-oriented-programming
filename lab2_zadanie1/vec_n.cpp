// vec_n.cpp
#include "vec_n.hpp"

// Constructor initializing a vector with default values
vec_n::vec_n(size_t n) : elements(n, std::numeric_limits<double>::quiet_NaN()), is_defined(false) {}

// Constructor initializing a vector with given values
vec_n::vec_n(const std::vector<double>& values) : elements(values), is_defined(true) {}

// Checking if a vector is fully defined
void vec_n::is_fully_defined() {
    for (double val : elements) {
        if (std::isnan(val)) {
            is_defined = false;
            return;  // No need to continue checking once NaN is found
        }
    }
    is_defined = true;  // Set to true if no NaN found
}

// Returns vector size
size_t vec_n::size(void) const {
    return elements.size();
}

// Vector addition operator
vec_n vec_n::operator+(const vec_n& v) const {
    if (elements.size() != v.size()) {
        throw std::invalid_argument("Vectors have different sizes!");
    }
    else if (!is_defined || !v.is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); i++) {
        result[i] = elements[i] + v.elements[i];
    }
    return vec_n(result);
}

// Multiplying a vector by a scalar (returns new vector)
vec_n vec_n::scalar_multiply(double s) const {
    if (!is_defined) {
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
double vec_n::operator*(const vec_n& v) const {
    if (elements.size() != v.size()) {
        throw std::invalid_argument("Vectors have different sizes!");
    }
    if (!is_defined || !v.is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }
    double result = 0;
    for (size_t i = 0; i < elements.size(); i++) {
        result += elements[i] * v.elements[i];
    }
    return result;
}

// Checks if two vectors are parallel
bool vec_n::is_parallel(const vec_n& v) const { // first const guarantees that given vector wont change, second that method wont change/affect objecti
    if (elements.size() != v.size()) {
        throw std::invalid_argument("Vectors have different sizes!");
    }
    if (!is_defined || !v.is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }

    // Check if the vectors are scalar multiples of each other
    double ratio = elements[0] / v.elements[0];
    for (size_t i = 1; i < elements.size(); i++) {
        if (v.elements[i] == 0 || elements[i] / v.elements[i] != ratio) {
            return false;
        }
    }
    return true;
}


vec_n vec_n::add(const vec_n& v) const{
    if (elements.size() != v.size()) {
        throw std::invalid_argument("Vectors have different sizes!");
    }
    if (!is_defined || !v.is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); i++) {
        result[i] = elements[i] + v.elements[i];
    }
    return result;
}

double vec_n::length(void) const{
    if (!is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }
    double sum_of_squares;
    sum_of_squares = 0;
    for (size_t i = 0; i < elements.size(); i++){
        sum_of_squares += (elements[i] * elements[i]);
    }
    return sqrt(sum_of_squares);
}

int vec_n::compare(const vec_n& v){
    if (!is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }
    if (length() > v.length()){
        return -1;
    }
    else if(length() < v.length()){
        return 1;
    }
    return 0;
}

double vec_n::get_element(const int elem_no) const{
    if (!is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }
    if (elem_no > size() - 1){
        throw std::out_of_range("No such dimension in this vector");
    }
    return elements[elem_no];
}

double vec_n::dot_product(const vec_n& v) const{
    if (elements.size() != v.size()) {
        throw std::invalid_argument("Vectors have different sizes!");
    }
    if (!is_defined || !v.is_defined) {
        throw std::invalid_argument("One of the vectors isn't fully defined.");
    }
    double d_product;
    d_product = 0;
    for (size_t i = 0; i < elements.size(); i++){
        d_product += elements[i] * v.elements[i];
    }
    return d_product;
}

void vec_n::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Could not open file for writing.");
    }
    for (double val : elements) {
        outFile << val << " ";
    }
    outFile.close();
}

vec_n vec_n::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Could not open file for reading.");
    }
    std::vector<double> values;
    double val;
    while (inFile >> val) {
        values.push_back(val);
    }
    inFile.close();
    return vec_n(values);
}