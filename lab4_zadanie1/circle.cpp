#include "circle.hpp"
#include <sstream>

Circle::Circle(double cx, double cy, double r, const std::string& fc, const std::string& sc, double sw)
    : center(cx, cy), radius(r), GraphicObject(fc, sc, sw) {}


std::string Circle::toSVG()const {
    std::ostringstream oss;
    oss << "<circle "
        << "cx=\"" << center.getX() << "\" "
        << "cy=\"" << center.getY() << "\" "
        << "r=\"" << radius << "\" "
        << "fill=\"" << fillColor << "\" "
        << "stroke=\"" << strokeColor << "\" "
        << "stroke-width=\"" << strokeWidth << "\" "
        << "/>\n";
    return oss.str();
}