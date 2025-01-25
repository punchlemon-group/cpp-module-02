#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>
#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point& other);
        friend std::ostream& operator<<(std::ostream& os, const Point& point);
        ~Point();
        const Fixed& getX() const;
        const Fixed& getY() const;
        static const Fixed vectorXFromPoints(const Point& o, const Point& a);
        static const Fixed vectorYFromPoints(const Point& o, const Point& a);
        static const Fixed crossProduct2D(const Point& a, const Point& b, const Point& o);
    private:
        const Fixed _x;
        const Fixed _y;
};

#endif /* __POINT_HPP__ */
