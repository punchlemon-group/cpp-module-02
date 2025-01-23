#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed& operator=(const Fixed& other);
        int getRawBits() const;
    private:
        int _value;
};

#endif /* __FIXED_HPP__ */
