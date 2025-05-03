#ifndef POINT_HPP
#define POINT_HPP


template<typename T>
class Point {
private:
    T x, y;
public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    T getX() const {return x;}
    T getY() const {return y;}

    void setX(T val) {x = val;}
    void setY(T val) {y = val;}
};
#endif