#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int bits);
        float toFloat() const;
        int toInt() const;
        static Fixed max(Fixed& a, Fixed& b);
        static const Fixed max(const Fixed& a, const Fixed& b);
        static Fixed min(Fixed& a, Fixed& b);
        static const Fixed min(const Fixed& a, const Fixed& b);
    private:
        int _bits;
        static const int _numOfFractionalBits = 8;
};

#endif /* __FIXED_HPP__ */
