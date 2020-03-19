#if !defined(SERIES_H)
#define SERIES_H

#include <string>
#include <vector>

namespace series {
using namespace std;
vector<int> digits(string);
vector<vector<int>> slice(string, int);
}  // namespace series

#endif
