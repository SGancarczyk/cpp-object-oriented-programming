#ifndef LINE_HPP
#define LINE_HPP
#include "graphicobject.hpp"
#include "point.hpp"
#include <string>


class Line : public GraphicObject{
private:
    Point<double> start;
    Point<double> end;
public:
    Line(double sx, double sy, double ex, double ey, const std::string& sc, double sw);
    virtual ~Line() = default;
    std::string toSVG() const override;
};
#endif


