#include "pascals_triangle.h"
#include <algorithm>
#include <functional>

using std::plus;
using std::reverse;
using std::transform;

vector<vector<int>> pascals_triangle::generate_rows(int num_row) {
  vector<vector<int>> rows;
  if (num_row == 0) {
    return rows;
  }
  vector<int> row = {1};
  rows.push_back(row);
  for (int i = 2; i <= num_row; i++) {
    row.push_back(0);
    vector<int> row_rev(row);
    reverse(row_rev.begin(), row_rev.end());
    transform(row.begin(), row.end(), row_rev.begin(), row.begin(),
              plus<int>());
    rows.push_back(row);
  }
  return rows;
}
