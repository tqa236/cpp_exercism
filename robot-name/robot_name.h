#pragma once
#include <string>

namespace robot_name {
using namespace std;
class robot {
 private:
  string r_name = "Hello";

 public:
  string name() const;
};
}  // namespace robot_name
