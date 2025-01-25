#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _bits(0) {}

Fixed::Fixed(const int intValue) {
    this->setRawBits(intValue << _numOfFractionalBits);
}

Fixed::Fixed(const float floatValue) {
    float shiftedFloatValue = roundf(floatValue * (1 << _numOfFractionalBits));
    this->setRawBits(shiftedFloatValue);
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_bits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void) {}

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

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->getRawBits() * other.getRawBits()) >> _numOfFractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->getRawBits() << _numOfFractionalBits) / other.getRawBits());
    return result;
}

Fixed& Fixed::operator++() {
    ++_bits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++_bits;
    return temp;
}

Fixed& Fixed::operator--() {
    --_bits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --_bits;
    return temp;
}

Fixed Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

Fixed Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
