#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
class Complex {
 private:
  double real_;
  double imaginary_;

 public:
  double real();
  double imaginary();
};

}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
