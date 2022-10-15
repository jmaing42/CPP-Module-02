#ifndef EX03_POINT_HPP_INCLUDED
#define EX03_POINT_HPP_INCLUDED

#include "Fixed.hpp"

class Point {
private:
  Fixed x;
  Fixed y;

public:
  Point(Fixed x, Fixed y);
  ~Point();
  Point(const Point &copy);
  Point &operator=(const Point &copy);

  Point operator-(const Point &other) const;
  Fixed getX() const;
  Fixed getY() const;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
