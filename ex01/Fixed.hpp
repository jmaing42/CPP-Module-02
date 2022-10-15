#ifndef EX01_FIXED_HPP_INCLUDED
#define EX01_FIXED_HPP_INCLUDED

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

  int getRawBits(void) const;
  void setRawBits(int raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &dt);

#endif
