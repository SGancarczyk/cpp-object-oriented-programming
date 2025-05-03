#include "rectangle.hpp"
#include <sstream>


Rectangle::Rectangle(double x, double y, double h, double w,  const std::string& fc, const std::string& sc, double sw)
    :   GraphicObject(fc, sc, sw), topLeft(x, y), height(h), width(w) {}

std::string Rectangle::toSVG() const{
    std::ostringstream oss;
    oss << "<rect "
        << "x=\"" << topLeft.getX() << "\" "
        << "y=\"" << topLeft.getY() << "\" "
        << "width=\"" << width << "\" "
        << "height=\"" << height << "\" "
        << "fill=\"" << fillColor << "\" "
        << "stroke=\"" << strokeColor << "\" "
        << "stroke-width=\"" << strokeWidth << "\" "
        << "/>\n";
    return oss.str();
}