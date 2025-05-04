#include "image.hpp"
#include <sstream>

Image::Image(int w, int h) : width(w), height(h) {}

void Image::addElement(std::unique_ptr<GraphicObject> element) {
    elements.push_back(std::move(element)); // przenosimy własność do wektora
}

std::string Image::toSVG() const {
    std::ostringstream oss;
    oss << "<svg width=\"" << width
        << "\" height=\"" << height
        << "\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    for (const auto& elem : elements) {
        oss << elem->toSVG();
    }
    oss << "</svg>\n";
    return oss.str();
}