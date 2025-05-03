#ifndef GRAPHICOBJECT_HPP
#define GRAPHICOBJECT_HPP
#include <string>


class GraphicObject{
protected:
    std::string fillColor;
    std::string strokeColor;
    double strokeWidth;
public:
    GraphicObject(const std::string& fc, const std::string& sc, double sw);
    virtual ~GraphicObject() = default;
    virtual std::string toSVG() const = 0;
};
#endif