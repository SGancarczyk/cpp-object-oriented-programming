// main.cpp
#include "vec_n.hpp"

int main() {
    vec_n v1(5);  // Specified vector
    vec_n v2({1.0, 2.0, 3.0, 4.0, 5.0});  // Fully specified vector

    try {
        v1.print();
    } catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << std::endl;
    }

    v2.print();

    vec_n v3 = v2 + v2;  // Adding two vectors
    v3.print();

    vec_n v4 = v2.scalar_multiply(2.0);  // Multiplying by a value
    v4.print();

    return 0;
}