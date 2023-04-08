#include "Point.hpp"

static bool dir(const Point &a, const Point &b) {
  const Fixed ax = a.getX();
  const Fixed ay = a.getY();
  const Fixed bx = b.getX();
  const Fixed by = b.getY();

  return ax * by - ay * bx < 0;
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  const Point PA = a - point;
  const Point PB = b - point;
  const Point PC = c - point;
  const bool APB = dir(PA, PB);
  const bool BPC = dir(PB, PC);
  const bool CPA = dir(PC, PA);
  return APB == BPC && BPC == CPA;
}
