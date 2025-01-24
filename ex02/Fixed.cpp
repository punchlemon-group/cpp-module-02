#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _bits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(intValue << _numOfFractionalBits);
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    float shiftedFloatValue = roundf(floatValue * (1 << _numOfFractionalBits));
    this->setRawBits(shiftedFloatValue);
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_bits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _bits;
}

void Fixed::setRawBits(int bits) {
    this->_bits = bits;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->getRawBits()) / (1 << _numOfFractionalBits);
}

int Fixed::toInt() const {
    return this->getRawBits() >> _numOfFractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
