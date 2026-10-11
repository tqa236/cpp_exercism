#include "etl.h"

#include <algorithm>
#include <cctype>

using std::map;
using std::vector;

map<char, int> etl::transform(map<int, vector<char>> old) {
  map<char, int> expected;
  for (auto const& x : old) {
    for (auto const& y : x.second) {
      expected[static_cast<char>(
          std::tolower(static_cast<unsigned char>(y)))] = x.first;
    }
  }
  return expected;
}
