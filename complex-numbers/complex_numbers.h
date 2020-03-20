#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
struct Complex {
 private:
  double real_;
  double imaginary_;

 public:
  Complex(double, double);
  double real();
  double imaginary();
};

}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
