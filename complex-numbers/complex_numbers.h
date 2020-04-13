#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
class Complex {
 private:
  double real_;
  double imag_;

 public:
  Complex(double, double);
  double real() const;
  double imag() const;
  double abs() const;
  Complex operator+(Complex const&) const;
  Complex operator-(Complex const&) const;
  Complex operator*(Complex const&) const;
  Complex operator/(Complex const&) const;
  Complex conj() const;
  Complex exp() const;
};

}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
