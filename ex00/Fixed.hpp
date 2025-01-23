#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int bits);
    private:
        int _bits;
        static const int _fractionalBits = 8;
};

#endif /* __FIXED_HPP__ */
