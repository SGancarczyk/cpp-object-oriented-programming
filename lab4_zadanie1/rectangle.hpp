#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "graphicobject.hpp"
#include "point.hpp"
#include <string>

class Rectangle : GraphicObject{
private:
    Point<double> topLeft;
    double height;
    double width;
public:
    Rectangle(double x, double y, double h, double w,  const std::string& fc, const std::string& sc, double sw);
    virtual ~Rectangle() = default;
    std::string toSVG() const override;
};
#endif