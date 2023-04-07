#include "Fixed.hpp"

#include <ostream>

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed(int value) : value(value * (1 << Fixed::FRACTIONAL_BITS)) {}
Fixed::Fixed(float value) : value(value * (1 << Fixed::FRACTIONAL_BITS)) {}
Fixed::~Fixed() {}
Fixed::Fixed(const Fixed &copy) : value(copy.value) {}
Fixed &Fixed::operator=(const Fixed &copy) {
  this->value = copy.value;
  return *this;
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
  if (lhs < rhs) {
    return lhs;
  } else {
    return rhs;
  }
}
const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
  if (lhs < rhs) {
    return lhs;
  } else {
    return rhs;
  }
}
Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
  if (lhs > rhs) {
    return lhs;
  } else {
    return rhs;
  }
}
const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) {
  if (lhs > rhs) {
    return lhs;
  } else {
    return rhs;
  }
}

bool Fixed::operator==(const Fixed &other) const {
  return this->value == other.value;
}
bool Fixed::operator!=(const Fixed &other) const {
  return this->value != other.value;
}
bool Fixed::operator<(const Fixed &other) const {
  return this->value < other.value;
}
bool Fixed::operator<=(const Fixed &other) const {
  return this->value <= other.value;
}
bool Fixed::operator>(const Fixed &other) const {
  return this->value > other.value;
}
bool Fixed::operator>=(const Fixed &other) const {
  return this->value >= other.value;
}
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result(0);
  result.value = this->value + other.value;
  return result;
}
Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result(0);
  result.value = this->value - other.value;
  return result;
}
Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result(0);
  result.value = (this->value * other.value) >> Fixed::FRACTIONAL_BITS;
  return result;
}
Fixed Fixed::operator/(const Fixed &other) const {
  Fixed result(0);
  result.value =
      (((static_cast<long long>(this->value)) << Fixed::FRACTIONAL_BITS) /
       static_cast<long long>(other.value));
  return result;
}
Fixed &Fixed::operator++() {
  this->value++;
  return *this;
}
Fixed &Fixed::operator--() {
  this->value--;
  return *this;
}
Fixed Fixed::operator++(int zero) {
  (void)zero;
  Fixed copy = *this;
  ++*this;
  return copy;
}
Fixed Fixed::operator--(int zero) {
  (void)zero;
  Fixed copy = *this;
  --*this;
  return copy;
}

int Fixed::getRawBits(void) const { return this->value; }
void Fixed::setRawBits(int raw) { this->value = raw; }
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
