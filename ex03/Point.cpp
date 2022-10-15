#include "Point.hpp"

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}
Point::~Point() {}
Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}
Point &Point::operator=(const Point &copy) {
  this->x = copy.x;
  this->y = copy.y;
  return *this;
}

Point Point::operator-(const Point &other) const {
  return Point(this->x - other.x, this->y - other.y);
}
Fixed Point::getX() const { return this->x; }
Fixed Point::getY() const { return this->y; }
