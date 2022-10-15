#include "Fixed.hpp"

#include <iostream>

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed(float value) : value(value * (1 << FRACTIONAL_BITS)) {
  std::cout << "Constructor called";
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
