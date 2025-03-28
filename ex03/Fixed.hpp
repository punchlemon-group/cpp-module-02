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
        bool operator>( const Fixed& other ) const;
        bool operator<( const Fixed& other ) const;
        bool operator>=( const Fixed& other ) const;
        bool operator<=( const Fixed& other ) const;
        bool operator==( const Fixed& other ) const;
        bool operator!=( const Fixed& other ) const;
        Fixed operator+( const Fixed& other ) const;
        Fixed operator-( const Fixed& other ) const;
        Fixed operator*( const Fixed& other ) const;
        Fixed operator/( const Fixed& other ) const;
        Fixed& operator++();
        Fixed operator++( int );
        Fixed& operator--();
        Fixed operator--( int );
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits(int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        static Fixed max( Fixed& a, Fixed& b );
        static const Fixed max( const Fixed& a, const Fixed& b );
        static Fixed min( Fixed& a, Fixed& b );
        static const Fixed min( const Fixed& a, const Fixed& b );
    private:
        int _raw;
        static const int _numOfFractionalBits = 8;
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif /* __FIXED_HPP__ */
