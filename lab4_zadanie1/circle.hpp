#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "point.hpp"
#include "graphicobject.hpp"
#include <string>


class Circle : public GraphicObject{
private:
    Point<double> center;
    double radius;
public:
    Circle(double cx, double cy, double r, const std::string& fc, const std::string& sc, double sw);
    virtual ~Circle() = default;
    std::string toSVG() const override;
};
#endif