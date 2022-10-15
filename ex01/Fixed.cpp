#include "Fixed.hpp"

#include <iostream>
#include <ostream>

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed(int value) : value(value * (1 << Fixed::FRACTIONAL_BITS)) {
  std::cout << "Constructor called" << std::endl;
}
Fixed::Fixed(float value) : value(value * (1 << Fixed::FRACTIONAL_BITS)) {
  std::cout << "Constructor called" << std::endl;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &copy) : value(copy.value) {
  std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &copy) {
  this->value = copy.value;
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->value;
}
void Fixed::setRawBits(int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->value = raw;
}
float Fixed::toFloat(void) const {
  return this->value / (float)(1 << Fixed::FRACTIONAL_BITS);
}
int Fixed::toInt(void) const {
  return this->value / (1 << Fixed::FRACTIONAL_BITS);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
