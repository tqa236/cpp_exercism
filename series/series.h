#pragma once

#include <string>
#include <vector>

namespace series {
using std::string;
using std::vector;

vector<int> digits(string);
vector<vector<int>> slice(string, int);
}  // namespace series
