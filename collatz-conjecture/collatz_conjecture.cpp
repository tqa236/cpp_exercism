#include "collatz_conjecture.h"
#include <stdexcept>

using std::domain_error;
namespace collatz_conjecture {
int steps(int number) {
  if (number <= 0) throw domain_error("Non-positive side is illegal.");
  if (number == 1) return 0;
  if (number % 2 == 0) return steps(number / 2) + 1;
  return steps(3 * number + 1) + 1;
}
}  // namespace collatz_conjecture
