#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const intValue ) {
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(intValue << _numOfFractionalBits);
}

Fixed::Fixed( float const floatValue ) {
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(floatValue * (1 << _numOfFractionalBits)));
}

Fixed::Fixed( const Fixed& other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=( const Fixed& other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->setRawBits(other.getRawBits());
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return _raw;
}

void Fixed::setRawBits( int const raw ) {
    this->_raw = raw;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(this->getRawBits()) / (1 << _numOfFractionalBits);
}

int Fixed::toInt( void ) const {
    return this->getRawBits() >> _numOfFractionalBits;
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed ) {
    os << fixed.toFloat();
    return os;
}
