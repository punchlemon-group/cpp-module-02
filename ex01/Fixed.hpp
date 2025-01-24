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
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int bits);
        float toFloat() const;
        int toInt() const;
        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
    private:
        int _bits;
        static const int _numOfFractionalBits = 8;
};

#endif /* __FIXED_HPP__ */
