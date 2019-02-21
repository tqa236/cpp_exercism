#pragma once
#include <algorithm>
#include <map>
#include <vector>

namespace etl {
using std::map;
using std::vector;

map<char, int> transform(map<int, vector<char>>);
}  // namespace etl
