#include <gtest/gtest.h>
#include "circle.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "image.hpp"


TEST(CircleTest, ToSVG) {
    Circle c(100.0, 100.0, 50.0, "red", "blue", 2.0);
    std::string expected = "<circle cx=\"100\" cy=\"100\" r=\"50\" fill=\"red\" stroke=\"blue\" stroke-width=\"2\" />\n";
    EXPECT_EQ(c.toSVG(), expected);
}


TEST(RectangleTest, ToSVG) {
    Rectangle r(10.0, 20.0, 30.0, 40.0, "green", "black", 1.5);
    std::string expected = "<rect x=\"10\" y=\"20\" width=\"40\" height=\"30\" fill=\"green\" stroke=\"black\" stroke-width=\"1.5\" />\n";
    EXPECT_EQ(r.toSVG(), expected);
}


TEST(LineTest, ToSVG) {
    Line l(0.0, 0.0, 100.0, 100.0, "black", 2.0);
    std::string expected = "<line x1=\"0\" y1=\"0\" x2=\"100\" y2=\"100\" stroke=\"black\" stroke-width=\"2\" />\n";
    EXPECT_EQ(l.toSVG(), expected);
}


TEST(ImageTest, ToSVGContainsChildElements) {
    Image img(200, 200);
    img.addElement(std::make_unique<Circle>(50, 50, 25, "yellow", "black", 1.0));
    std::string svg = img.toSVG();

    EXPECT_TRUE(svg.find("<svg width=\"200\" height=\"200\"") != std::string::npos);
    EXPECT_TRUE(svg.find("<circle") != std::string::npos);
    EXPECT_TRUE(svg.find("</svg>") != std::string::npos);
}


TEST(PolymorphismTest, CircleViaPointer) {
    GraphicObject* obj = new Circle(10, 10, 5, "blue", "black", 1);
    std::string expected = "<circle cx=\"10\" cy=\"10\" r=\"5\" fill=\"blue\" stroke=\"black\" stroke-width=\"1\" />\n";
    EXPECT_EQ(obj->toSVG(), expected);
    delete obj;
}

TEST(PolymorphismTest, RectangleViaPointer) {
    GraphicObject* obj = new Rectangle(1, 2, 3, 4, "red", "green", 0.5);
    std::string expected = "<rect x=\"1\" y=\"2\" width=\"4\" height=\"3\" fill=\"red\" stroke=\"green\" stroke-width=\"0.5\" />\n";
    EXPECT_EQ(obj->toSVG(), expected);
    delete obj;
}

TEST(PolymorphismTest, LineViaPointer) {
    GraphicObject* obj = new Line(0, 0, 10, 10, "purple", 3.5);
    std::string expected = "<line x1=\"0\" y1=\"0\" x2=\"10\" y2=\"10\" stroke=\"purple\" stroke-width=\"3.5\" />\n";
    EXPECT_EQ(obj->toSVG(), expected);
    delete obj;
}
