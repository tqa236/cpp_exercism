#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace grade_school {
struct school {
 private:
  map<int, vector<string> > class_roster;

 public:
  map<int, vector<string> > roster();
  void add(string, int);
  vector<string> grade(int) const;
};
}  // namespace grade_school
