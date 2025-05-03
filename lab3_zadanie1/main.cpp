#include <iostream>
#include <algorithm>
#include <sstream>
#include "SparseVec.hpp"

int main() {
    SparseVec v(5, 0.0);
    v[1] = 3.14;
    v[3] = 2.71;

    std::cout << "Original vector:\n" << v << "\n";

    std::stringstream ss;
    ss << v;

    SparseVec w(0, 0.0);
    ss >> w;

    std::cout << "Loaded vector:\n" << w << "\n";

    double dot_product = v * w;
    std::cout << "Dot Product v * w = " << dot_product << "\n";


    std::vector<SparseVec> Vectors;

    SparseVec a(3, 0.0), b(3, 9.0), c(3, 0.0);
    a[0] = 3.0; // len = 3
    b[0] = 4.5; b[1] = 3.0; // len = 5
    c[0] = 1.0; // len = 1

    Vectors.push_back(a);
    Vectors.push_back(b);
    Vectors.push_back(c);

    std::sort(Vectors.begin(), Vectors.end());

    std::cout << "Vectors sorted ascending, by length:\n";
    for (const auto& w : Vectors) {
        std::cout << "length = " << w.length() << ", contains: " << w << "\n";
    }

    return 0;
}
