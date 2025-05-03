#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <vector>
#include <string>
#include <memory>
#include "graphicobject.hpp"


class Image {
private:
    std::vector<std::unique_ptr<GraphicObject>> elements;
    int width;
    int height;
public:
    Image(int w, int h);
    void addElement(std::unique_ptr<GraphicObject> element);
    std::string toSVG() const;
};
#endif