cmake_minimum_required(VERSION 3.10)
project(SVGRenderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SVG_SOURCES
    circle.cpp
    rectangle.cpp
    line.cpp
    image.cpp
    graphicobject.cpp
)

add_executable(svg_main main.cpp ${SVG_SOURCES})

enable_testing()

find_package(GTest REQUIRED)

add_executable(svg_tests tests.cpp ${SVG_SOURCES})

target_link_libraries(svg_tests GTest::GTest GTest::Main pthread)

add_test(NAME SvgTests COMMAND svg_tests)
