#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) : _bits(0) {
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return _bits;
}

void Fixed::setRawBits(int bits) {
    this->_bits = bits;
    std::cout << "setRawBits member function called" << std::endl;
}
