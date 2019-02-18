#pragma once
#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace grade_school {
using std::map;
using std::string;
using std::vector;

struct school {
 private:
  map<int, vector<string>> class_roster;

 public:
  map<int, vector<string>> roster();
  void add(string, int);
  vector<string> grade(int) const;
};
}  // namespace grade_school
