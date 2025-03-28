#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed {
    public:
        Fixed( void );
        Fixed( const Fixed& other );
        Fixed& operator=( const Fixed& other );
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int _raw;
        static const int _fractionalBits = 8;
};

#endif /* __FIXED_HPP__ */
