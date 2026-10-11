#pragma once

#include <cstdint>

namespace grains {
constexpr std::uint64_t square(const int number) {
  return std::uint64_t{1} << (number - 1);
}
constexpr std::uint64_t total() { return ~std::uint64_t{0}; }
}  // namespace grains
