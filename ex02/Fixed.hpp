#ifndef EX02_FIXED_HPP_INCLUDED
#define EX02_FIXED_HPP_INCLUDED

#include <ostream>

class Fixed {
private:
  static const int FRACTIONAL_BITS;
  int value;

public:
  Fixed(int value = 0);
  Fixed(float value);
  ~Fixed();
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &copy);

  static Fixed &min(Fixed &lhs, Fixed &rhs);
  static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
  static Fixed &max(Fixed &lhs, Fixed &rhs);
  static const Fixed &max(const Fixed &lhs, const Fixed &rhs);

  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int zero);
  Fixed operator--(int zero);

  int getRawBits(void) const;
  void setRawBits(int raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &dt);

#endif
