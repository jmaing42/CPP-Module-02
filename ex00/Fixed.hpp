#ifndef EX00_FIXED_HPP_INCLUDED
#define EX00_FIXED_HPP_INCLUDED

class Fixed {
private:
  static const int FRACTIONAL_BITS;
  int value;

public:
  Fixed(float value = 0);
  ~Fixed();
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &copy);

  int getRawBits(void) const;
  void setRawBits(int raw);
};

#endif
