#include <iostream>


class SparseVec {
private:
    int dimension;
    double default_value;
    std::unordered_map<size_t, double> elements;
public:
    SparseVec(size_t s, double def_val=0.0);
};