// Comments are made mostly for me; it helps me in studying process
#include <iostream>
#include <ostream>
#include <cmath>
#include <stdexcept>
#include <sstream>

class SparseVec {
private:
    int size;
    double default_value;
    std::unordered_map<size_t, double> data; // Representing Sparse vector as tuple (index, value) if value != 0
public:
    SparseVec(size_t s, double def_val=0.0);
    SparseVec(const SparseVec& v);
    double operator[](std::size_t idx) const;
    class ProxyReference {
        SparseVec& parent;
        std::size_t index;

    public:
        ProxyReference(SparseVec& vec, std::size_t idx) : parent(vec), index(idx) {}

        // Allows us to treat proxy as double
        operator double() const {
            auto it = parent.data.find(index);
            return (it != parent.data.end()) ? it->second : parent.default_value;
        }

        // Allows to asign value, other than default
        ProxyReference& operator=(double value) {
            if (value == parent.default_value) {
                parent.data.erase(index);
            } else {
                parent.data[index] = value;
            }
            return *this;
        }

        // This will allow to do for example: v[1] = v[3]
        ProxyReference& operator=(const ProxyReference& v) {
            return *this = static_cast<double>(v);
        }
    };

    ProxyReference operator[](std::size_t idx);
    SparseVec& operator=(const SparseVec &v);
    SparseVec operator+(const SparseVec &v) const;
    SparseVec operator*(const double &s) const;
    double operator*(const SparseVec &v) const;
    bool is_default(std::size_t idx) const;
    bool is_parallel(const SparseVec &v) const;
    double length(void) const;
    bool operator<(const SparseVec &v) const;
    bool operator>(const SparseVec &v) const;
    bool operator==(const SparseVec &v) const;
    friend std::ostream& operator<<(std::ostream& os, const SparseVec& vec);
    friend std::istream& operator>>(std::istream& is, SparseVec& vec);
};