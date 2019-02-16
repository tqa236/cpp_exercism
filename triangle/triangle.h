#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle {
enum flavor { equilateral, isosceles, scalene };
flavor kind(double const, double const, double const);

}  // namespace triangle

#endif
