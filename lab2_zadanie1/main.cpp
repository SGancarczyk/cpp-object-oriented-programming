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

    // Save vector to file
    v2.saveToFile("vector.txt");
    std::cout << "Vector saved to file." << std::endl;

    // Load vector from file
    vec_n v5 = vec_n::loadFromFile("vector.txt");
    std::cout << "Vector loaded from file: ";
    v5.print();

    return 0;
}
