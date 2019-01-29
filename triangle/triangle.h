#pragma once

namespace triangle {
  enum flavor {equilateral, isosceles, scalene};
  void check_valid_triangle(double, double, double);
  flavor kind(double, double, double);

}
