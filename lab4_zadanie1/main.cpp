#include <iostream>
#include <fstream>
#include <memory>
#include "image.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "line.hpp"

int main() {
    Image img(500, 500);

    img.addElement(std::make_unique<Circle>(
        250.0, 250.0, 100.0,
        "red", "black", 2.0
    ));
    img.addElement(std::make_unique<Rectangle>(
        50.0, 50.0, 150.0, 100.0,
        "blue", "green", 3.0
    ));
    img.addElement(std::make_unique<Line>(
        0.0, 0.0, 500.0, 500.0,
        "black", 4.0
    ));


    std::ofstream file("output.html");
    if (!file) {
        std::cerr << "Error: could not open file for writing\n";
        return 1;
    }


    file << "<!DOCTYPE html>\n";
    file << "<html>\n<head><title>SVG Image</title></head>\n<body>\n";


    file << img.toSVG();

    file << "</body>\n</html>\n";
    file.close();

    std::cout << "SVG image has been written to output.html\n";
    return 0;
}