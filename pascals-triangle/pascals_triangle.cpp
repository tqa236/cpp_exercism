#include "pascals_triangle.h"

#include <algorithm>
#include <functional>

std::vector<std::vector<int>> pascals_triangle::generate_rows(int num_row) {
  std::vector<std::vector<int>> rows;
  if (num_row == 0) {
    return rows;
  }
  std::vector<int> row = {1};
  rows.push_back(row);
  for (int i = 2; i <= num_row; i++) {
    row.push_back(0);
    std::vector<int> row_rev(row);
    std::reverse(row_rev.begin(), row_rev.end());
    std::transform(row.begin(), row.end(), row_rev.begin(), row.begin(),
                   std::plus<int>());
    rows.push_back(row);
  }
  return rows;
}
