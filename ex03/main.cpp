#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

static void test(float ax, float ay, float bx, float by, float cx, float cy,
                 float px, float py) {
  const Point a((Fixed(ax)), Fixed(ay));
  const Point b((Fixed(bx)), Fixed(by));
  const Point c((Fixed(cx)), Fixed(cy));
  const Point p((Fixed(px)), Fixed(py));

  std::cout << bsp(a, b, c, p) << std::endl;
  std::cout << bsp(a, c, b, p) << std::endl;
  std::cout << bsp(b, a, c, p) << std::endl;
  std::cout << bsp(b, c, a, p) << std::endl;
  std::cout << bsp(c, a, b, p) << std::endl;
  std::cout << bsp(c, b, a, p) << std::endl;
}

int main(void) {
  test(0, 0, 1, 0, 0, 1, 0.42f, 0.42f);
  test(0, 0, 1, 0, 0, 1, 0.42f, 42);
  test(42, 42, 42, 44, 44, 42, 42.42f, 42.42f);
  test(42, 42, 42, 44, 44, 42, 4.2f, 42.42f);
}
