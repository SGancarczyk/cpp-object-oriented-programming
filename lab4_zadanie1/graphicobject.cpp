#include "graphicobject.hpp"

GraphicObject::GraphicObject(const std::string& fc, const std::string& sc, double sw)
   :   fillColor(fc), strokeColor(sc), strokeWidth(sw) {}
