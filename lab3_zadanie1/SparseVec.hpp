#include <iostream>
#include <ostream>

class SparseVec {
private:
    int dimension;
    double default_value;
    std::unordered_map<size_t, double> elements;
public:
    SparseVec(size_t s, double def_val=0.0);
    const SparseVec& operator[](std::size_t idx) const;
    SparseVec& operator=(const SparseVec &v) const;
    SparseVec& operator+(const SparseVec &v) const;
    SparseVec& operator*(const double &s) const;
    double operator*(const SparseVec &v) const;
    bool is_default(std::size_t idx) const;
    bool is_parallel(const SparseVec &v) const;
    double length(void) const;
    bool operator<(const SparseVec &v) const;
    bool operator>(const SparseVec &v) const;
    bool operator==(const SparseVec &v) const;
    friend std::ostream& operator<<(std::ostream& os, const SparseVec& vec);
    friend std::istream& operator>>(std::ostream& is, SparseVec& vec);

};