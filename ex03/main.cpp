#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main() {
    const Point a;
    const Point b(-4.66, 0.86);
    const Point c(3.94, 2.8);
    const Point point(-4.38, 1.44);

    std::cout << std::endl
        << "a is " << a << std::endl
        << "b is " << b << std::endl
        << "c is " << c << std::endl << std::endl;

    std::cout << "point is " << point << std::endl << std::endl;

    std::cout << "The point is ";
    if (bsp(a, b, c, point)) {
        std::cout << "in";
    } else {
        std::cout << "out";
    }
    std::cout << "side the triangle" << std::endl << std::endl;
    return 0;
}
