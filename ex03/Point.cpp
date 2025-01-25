#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        // this->setX(other.getX());
        // this->setY(other.getY());
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(x=" << point.getX() << ", y=" << point.getY() << ")";
    return os;
}

Point::~Point() {}

const Fixed& Point::getX() const {
    return _x;
}

const Fixed& Point::getY() const {
    return _y;
}

const Fixed Point::vectorXFromPoints(const Point& o, const Point& a) {
    return o.getX() - a.getX();
}

const Fixed Point::vectorYFromPoints(const Point& o, const Point& a) {
    return o.getY() - a.getY();
}

const Fixed Point::crossProduct2D(const Point& a, const Point& b, const Point& o) {
    return vectorXFromPoints(o, a) * vectorYFromPoints(o, b) - vectorXFromPoints(o, b) * vectorYFromPoints(o, a);
}
