#include "SparseVec.hpp"

SparseVec::SparseVec(std::size_t s, double def_val)
    : size(s), default_value(def_val) {}

SparseVec::SparseVec(const SparseVec& v)
    : data(v.data), size(v.size), default_value(v.default_value) {}

SparseVec& SparseVec::operator=(const SparseVec& v) {
    if (this != &v) {
        data = v.data;
        size = v.size;
        default_value = v.default_value;
    }
    return *this;
}

double SparseVec::operator[](std::size_t idx) const {
    if (idx >= size)
        throw std::out_of_range("Index out of bounds");
    auto it = data.find(idx);
    return (it != data.end()) ? it->second : default_value;
}

SparseVec::ProxyReference SparseVec::operator[](std::size_t idx) {
    if (idx >= size)
        throw std::out_of_range("Index out of bounds");
    return ProxyReference(*this, idx); // in fact i return double, as operator is defined in header
}

SparseVec SparseVec::operator+(const SparseVec& v) const {
    if (size != v.size || default_value != v.default_value)
        throw std::invalid_argument("Vectors incompatible");

    SparseVec result(size, default_value);
    result.data = data;

    for (const auto& [idx, val] : v.data) {
        result.data[idx] += val;
        if (result.data[idx] == default_value)
            result.data.erase(idx);
    }
    return result;
}

SparseVec SparseVec::operator*(const double& s) const {
    SparseVec result(size, default_value * s);
    for (const auto& [idx, val] : data) {
        double prod = val * s;
        if (prod != result.default_value)
            result.data[idx] = prod;
    }
    return result;
}

double SparseVec::operator*(const SparseVec& v) const {
    if (size != v.size)
        throw std::invalid_argument("Vectors incompatible");

    double dot_product = 0.0;
    for (const auto& [idx, val] : data) {
        dot_product += val * v[idx];
    }
    for (const auto& [idx, val] : v.data) {
        if (data.find(idx) == data.end())
            dot_product += val * default_value;
    }
    dot_product += default_value * v.default_value * (size - data.size() - v.data.size()
        + std::count_if(v.data.begin(), v.data.end(), [&](auto& p) { return data.find(p.first) != data.end(); }));

    return dot_product;
}

bool SparseVec::is_default(std::size_t idx) const {
    if (idx >= size)
        throw std::out_of_range("Index out of bounds");
    return data.find(idx) == data.end();
}

bool SparseVec::is_parallel(const SparseVec& v) const {
    if (size != v.size)
        throw std::invalid_argument("Vectors incompatible");

    double ratio = NAN;
    for (std::size_t i = 0; i < size; ++i) {
        double a = (*this)[i]; // using operator[], defnied before to avoid problems with indexing
        double b = v[i];
        if (b == 0 && a == 0) continue;
        if (b == 0 || a == 0) return false;
        double current = a / b;
        if (std::isnan(ratio))
            ratio = current;
        else if (std::abs(ratio - current) > 1e-9) // 1e-9 is acceptable inacuracy
            return false;
    }
    return true;
}

double SparseVec::length() const {
    double sum = 0.0;
    for (std::size_t i = 0; i < size; ++i) {
        double val = (*this)[i];
        sum += val * val;
    }
    return std::sqrt(sum);
}

bool SparseVec::operator<(const SparseVec& v) const {
    return length() < v.length();
}

bool SparseVec::operator>(const SparseVec& v) const {
    return length() > v.length();
}

bool SparseVec::operator==(const SparseVec& v) const {
    return std::abs(length() - v.length()) < 1e-9; // same as before, 1e-9 is acceptable measurement deviation
}

std::ostream& operator<<(std::ostream& os, const SparseVec& vec) {
    os << vec.size << " " << vec.default_value << " ";
    os << vec.data.size() << " ";
    for (const auto& [idx, val] : vec.data) {
        os << idx << " " << val << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, SparseVec& vec) {
    vec.data.clear();
    std::size_t dim, count;
    double def_val;
    is >> dim >> def_val >> count;
    vec.size = dim;
    vec.default_value = def_val;

    for (std::size_t i = 0; i < count; ++i) {
        std::size_t idx;
        double val;
        is >> idx >> val;
        if (idx >= dim)
            throw std::invalid_argument("Invalid index in input");
        vec.data[idx] = val;
    }
    return is;
}
