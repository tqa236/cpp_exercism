#include "series.h"

#include <stdexcept>

std::vector<int> series::digits(std::string number) {
  std::vector<int> digits;
  for (unsigned int i = 0; i < number.size(); ++i) {
    digits.push_back(number[i] - '0');
  }
  return digits;
}

std::vector<std::string> series::slice(std::string number, int length) {
  if (length <= 0 || number.empty() ||
      number.size() < static_cast<std::size_t>(length)) {
    throw std::domain_error("This number is not long enough.");
  }

  std::vector<std::string> slices;
  const auto slice_length = static_cast<std::size_t>(length);
  for (std::size_t start = 0; start <= number.size() - slice_length; ++start) {
    slices.push_back(number.substr(start, slice_length));
  }
  return slices;
}
