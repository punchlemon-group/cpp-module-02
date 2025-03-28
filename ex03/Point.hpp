#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>
#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point( float const x, float const y );
        Point( const Point& other );
        Point& operator=( const Point& other );
        ~Point();
        const Fixed& getX( void ) const;
        const Fixed& getY( void ) const;
        static const Fixed vectorXFromPoints( const Point& o, const Point& a );
        static const Fixed vectorYFromPoints( const Point& o, const Point& a );
        static const Fixed crossProduct2D( const Point& a, const Point& b, const Point& o );
    private:
        const Fixed _x;
        const Fixed _y;
};

std::ostream& operator<<( std::ostream& os, const Point& point );

#endif /* __POINT_HPP__ */
