#include "etl.h"

using std::map;
using std::vector;

map<char, int> etl::transform(map<int, vector<char>> old) {
  map<char, int> expected;
  for (auto const& x : old) {
    for (auto const& y : x.second) {
      expected[tolower(y)] = x.first;
    }
  }
  return expected;
}
