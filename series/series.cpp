#include "series.h"

#include <stdexcept>

std::vector<int> series::digits(std::string number) {
  std::vector<int> digits;
  for (unsigned int i = 0; i < number.size(); ++i) {
    digits.push_back(number[i] - '0');
  }
  return digits;
}

std::vector<std::vector<int>> series::slice(std::string number, int length) {
  if (number.size() < (unsigned int)length) {
    throw std::domain_error("This number is not long enough.");
  }
  std::vector<int> digits = series::digits(number);
  std::vector<std::vector<int>> subset;
  for (unsigned int i = 0; i < number.size() - length + 1; i = i + 1) {
    subset.push_back(
        std::vector<int>(digits.begin() + i, digits.begin() + i + length));
  }
  return subset;
}
