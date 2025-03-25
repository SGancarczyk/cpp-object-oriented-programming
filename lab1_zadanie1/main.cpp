#include "Date.hpp"

int main() {
    try {
        Date newdate(15, Month::March, 2024);
        std::cout << "Data: " << newdate.getDate() << std::endl;

        newdate.setDay(27);
        newdate.setMonth(Month::April);
        newdate.setYear(2023);

        std::cout << "Data: " << newdate.getDate() << std::endl;

        // Przykłady obsługi wyjątków
        try {
            Date d1(15, Month::March, 2023);
            d1.setDay(32);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            Date d1(31, Month::March, 2023);
            d1.setMonth(Month::February);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            Date d1(15, Month::March, 2023);
            d1.setYear(0);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << std::endl;
    }

    return 0;
}