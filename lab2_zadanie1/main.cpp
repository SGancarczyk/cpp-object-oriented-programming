#include <iostream>
#include "vec_n.hpp"


int main() {
    try {
        vec_n v1({1.0, 2.0, 3.0});
        vec_n v2({4.0, 5.0, 6.0});

        std::cout << "1. ";
        v1.print();
        std::cout << "2. ";
        v2.print();

        vec_n v3 = v1 + v2;
        std::cout << "Sum of vectors: ";
        v3.print();

        double dot = v1 * v2;
        std::cout << "Dot product of v1 and v2: " << dot << std::endl;

        vec_n v4 = v1.scalar_multiply(2.0);
        std::cout << "v1 multiplied by 2: ";
        v4.print();

        int cmp = v1.compare(v2);
        if (cmp == -1)
            std::cout << "v1 is longer than v2\n";
        else if (cmp == 1)
            std::cout << "v1 is shorter than v2\n";
        else
            std::cout << "v1 and v2 have the same length\n";

        std::string filename = "vector.txt";
        v1.saveToFile(filename);
        std::cout << "Saved v1 to file " << filename << std::endl;

        vec_n v5 = vec_n::loadFromFile(filename);
        std::cout << "Loaded vector from file: ";
        v5.print();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}