#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
    Fixed cross1 = Point::crossProduct2D(a, b, point);
    Fixed cross2 = Point::crossProduct2D(b, c, point);
    Fixed cross3 = Point::crossProduct2D(c, a, point);
    return (cross1 > 0 && cross2 > 0 && cross3 > 0)
        || (cross1 < 0 && cross2 < 0 && cross3 < 0);
}
