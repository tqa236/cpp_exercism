#include "collatz_conjecture.h"
#include <stdexcept>

int collatz_conjecture::steps(int number) {
  if (number <= 0) throw std::domain_error("Non-positive side is illegal.");
  if (number == 1) return 0;
  if (number % 2 == 0) return steps(number / 2) + 1;
  return steps(3 * number + 1) + 1;
}
