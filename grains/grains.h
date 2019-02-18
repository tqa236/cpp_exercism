#pragma once
#include <cmath>
#include <cstdint>

namespace grains {
using std::pow;
constexpr uint64_t square(const int number) {
  return (uint64_t)1 << (number - 1);
}
constexpr uint64_t total() { return (uint64_t)pow(2, 64) - 1; }
}  // namespace grains
