#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
    public:
        Fixed( void );
        Fixed( int const intValue );
        Fixed( float const floatValue );
        Fixed( const Fixed& other );
        Fixed& operator=( const Fixed& other );
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
        int _raw;
        static const int _numOfFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif /* __FIXED_HPP__ */
