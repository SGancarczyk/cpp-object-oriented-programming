#include "line.hpp"
#include "sstream"

Line::Line(double sx, double sy, double ex, double ey, const std::string& fc, const std::string& sc, double sw)
    : start(sx, sy), end(ex, ey), GraphicObject(fc, sc, sw) {}

std::string Line::toSVG() const{
    std::ostringstream oss;
    oss << "<line "
        << "x1=\"" << start.getX() << "\" "
        << "y1=\"" << start.getY() << "\" "
        << "x2=\"" << end.getX() << "\" "
        << "y2=\"" << end.getY() << "\" "
        << "stroke=\"" << strokeColor << "\" "
        << "stroke-width=\"" << strokeWidth << "\" "
        << "/>\n";
    return oss.str();

}